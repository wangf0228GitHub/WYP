/******************************************************************************
 * Copyright 2013-2014 Espressif Systems (Wuxi)
 *
 * FileName: user_esp_platform.c
 *
 * Description: The client mode configration.
 *              Check your hardware connection with the host while use this mode.
 *
 * Modification history:
 *     2014/5/09, v1.0 create this file.
*******************************************************************************/
#include "ets_sys.h"
#include "os_type.h"
#include "mem.h"
#include "osapi.h"
#include "user_interface.h"

#include "espconn.h"
#include "TypeDefine.h"
#include "Display.h"
#include "DS18B20.h"


#define ESP_DOMAIN_PORT 12128
#define ESP_DOMAIN      "www.wlwdjcy.com"
#define ESP_DBG os_printf

#define IDLen 15
#define HEADLen 7
#define TYPEIndex 5
#define DATAIndex 26
uint8 myID[48];
ip_addr_t esp_server_ip;
char TxBuf[1024];
unsigned int TxLen=0;
LOCAL struct espconn user_conn;
LOCAL struct _esp_tcp user_tcp;
os_timer_t esp_client_timer;
LOCAL unsigned char espDNSRetry=0;
LOCAL unsigned char espConnectRetry=0;
LOCAL unsigned char espSendRetry=0;
LOCAL unsigned char espRecvRetry=0;

SENSOR_DATA_RTC_MEM sensor_data ;
LOCAL unsigned char WaitWifi=0;

void ICACHE_FLASH_ATTR user_esp_platform_connect(void);
void ICACHE_FLASH_ATTR user_esp_platform_start(void);
void ICACHE_FLASH_ATTR user_esp_platform_CheckWifi_cb(void *timer_arg)
{
	unsigned char status;
	os_timer_disarm(&esp_client_timer);
	status = wifi_station_get_connect_status();
	if(status!=STATION_GOT_IP)
	{
		WaitWifi++;
		if(WaitWifi>5)
		{
		 	os_printf("Cann't connect to wifi\n");
			ErrState=WifiErr;
			CLEARFLG(flg_FisrtUp);
			CLEARFLG(flg_bNotify);
			_S05;
			_S06;
			LcdDisplay_Err();
			bSendding=0;
			GotoSleep();
		}
		else
		{
		 	os_printf("wait wifi\n");
		 	os_timer_arm(&esp_client_timer, 1000, 0);
		}
	}
	else
	{
		os_printf("connect to wifi\n");
		user_esp_platform_start();
	}
}
//开始连接wifi，并启动定时检查wifi是否连接成功
void ICACHE_FLASH_ATTR user_esp_platform_workProc(void *timer_arg)
{	
	os_printf("start user_esp_platform_workProc\n");	
	CLEARFLG(flg_bNeedTx);
	if(GETFLG(flg_bWifi)==bTrue)
	{	
		if(wifi_station_connect())
		{
			WaitWifi=0;
			os_timer_disarm(&esp_client_timer);
			os_timer_setfn(&esp_client_timer, (os_timer_func_t *)user_esp_platform_CheckWifi_cb, NULL);
			os_timer_arm(&esp_client_timer, 1000, 0);
		}
		else
		{
			os_printf("wifi_station_connect error\r\n");
			bSendding=0;
			GotoSleep();
		} 		
	}
	else
	{
		os_printf("no wifi config\r\n");
		bSendding=0;
		GotoSleep();
	}	
}

//重新连接服务器
//与服务器断开会调用
LOCAL void ICACHE_FLASH_ATTR user_esp_platform_reconnect(struct espconn *pespconn)
{
    ESP_DBG("user_esp_platform_reconnect\n");

    user_esp_platform_connect();
}

//服务器断开连接后的回调处理
//已经完成发送了的则断开wifi连接，休眠
//否则重新连接服务器，共重试5次
LOCAL void ICACHE_FLASH_ATTR user_esp_platform_discon_cb(void *arg)
{
	struct espconn *pespconn = arg;
	struct ip_info ipconfig;
	if(bSendding==0)
	{
		wifi_station_disconnect();
		GotoSleep();
	}
	else
	{		
		ESP_DBG("user_esp_platform_discon_cb\n");
		espConnectRetry++;
		if (espConnectRetry == 5) 
		{
			ESP_DBG("discon is 5,fail!!!\n"); 
			ErrState=DisConnect;
			LcdDisplay_Err();
			bSendding=0;
			wifi_station_disconnect();
			GotoSleep();
		}
		else if (pespconn == NULL) 
		{
			ESP_DBG("pespconn is null by discon\n");
			ErrState=DisConnect1;
			LcdDisplay_Err();
			bSendding=0;
			wifi_station_disconnect();
			GotoSleep();
		}
		else
		{
			pespconn->proto.tcp->local_port = espconn_port();
			user_esp_platform_reconnect(pespconn);
		}
	}
}
//主动与服务器断开连接
//与服务器完成交互将调用
//发送超时或接收超时会调用
LOCAL void ICACHE_FLASH_ATTR user_esp_platform_discon(struct espconn *pespconn)
{
    ESP_DBG("user_esp_platform_discon\n");
    espconn_disconnect(pespconn);
}
//用于处理发送超时的回调
//发送超时后将主动与服务器断开连接，并重连
LOCAL void ICACHE_FLASH_ATTR user_esp_platform_SendOut_cb(void *arg)
{
	struct espconn *pespconn = arg;
	ESP_DBG("user_esp_platform_SendOut\n");
	user_esp_platform_discon(pespconn);
}
//用于处理接收超时的回调
//接收超时后将主动与服务器断开连接，并重连
LOCAL void ICACHE_FLASH_ATTR user_esp_platform_RecvOut_cb(void *arg)
{
	struct espconn *pespconn = arg;
	ESP_DBG("user_esp_platform_RecvOut\n");
	user_esp_platform_discon(pespconn);
}
//发送完成的回调，将启动接收超时定时器,3s超时
LOCAL void ICACHE_FLASH_ATTR user_esp_platform_sent_cb(void *arg)
{
    struct espconn *pespconn = arg;
	os_timer_disarm(&esp_client_timer);
	os_timer_setfn(&esp_client_timer, (os_timer_func_t *)user_esp_platform_RecvOut_cb, pespconn);
	os_timer_arm(&esp_client_timer, 3000, 0);
    ESP_DBG("user_esp_platform_sent_cb\n");
}
//向服务器发送数据
//对温度数据进行打包整理
//并启动发送超时定时器，3s超时
LOCAL void ICACHE_FLASH_ATTR user_esp_platform_sent(struct espconn *pespconn)
{
	unsigned int i,j,cnt,dataIndex;
	os_printf("Sendding\r\n");
	spi_flash_read(0x10000, (uint32 *)myID, 48);
	myID[47]='\0';
	if(GETFLG(flg_FisrtUp)==bTrue)
	{
		//@#pt#1#550055005500109#10#
		os_memcpy(TxBuf,"@#pt#1#",7);
		i=0;
		dataIndex=7;
		while(myID[i]!='\0')
		{
			TxBuf[dataIndex++]=myID[i++];
		}
		TxBuf[dataIndex++]='#';
		TxBuf[dataIndex++]='1';
		TxBuf[dataIndex++]='0';
		TxBuf[dataIndex++]='#';
		_S05;
		_S06;
		MakeTxTemperature(sensor_data.DST_H,sensor_data.DST_L);
		for(i=0;i<4;i++)
		{
			TxBuf[dataIndex+i]=TxTemperature[i];
		}
		TxBuf[dataIndex+4]='#';
		TxBuf[dataIndex+5]='@';
		TxBuf[dataIndex+6]='\0';
		//cnt=DATAIndex+4;
	}
	else if(GETFLG(flg_bNotify)==bTrue)
	{
		//os_memcpy(TxBuf,"@#pt#3#550055005500109#10#",26);
		os_memcpy(TxBuf,"@#pt#3#",7);
		i=0;
		dataIndex=7;
		while(myID[i]!='\0')
		{
			TxBuf[dataIndex++]=myID[i++];
		}
		TxBuf[dataIndex++]='#';
		TxBuf[dataIndex++]='1';
		TxBuf[dataIndex++]='0';
		TxBuf[dataIndex++]='#';
		MakeTxTemperature(sensor_data.DST_H,sensor_data.DST_L);
		for(i=0;i<4;i++)
		{
			TxBuf[dataIndex+i]=TxTemperature[i];
		}
		TxBuf[dataIndex+4]='#';
		TxBuf[dataIndex+5]='@';
		TxBuf[dataIndex+6]='\0';
		//cnt=DATAIndex+4;
	}
	else
	{
		//os_memcpy(TxBuf,"@#pt#2#550055005500109#10#",26);
		os_memcpy(TxBuf,"@#pt#2#",7);
		i=0;
		dataIndex=7;
		while(myID[i]!='\0')
		{
			TxBuf[dataIndex++]=myID[i++];
		}
		TxBuf[dataIndex++]='#';
		TxBuf[dataIndex++]='1';
		TxBuf[dataIndex++]='0';
		TxBuf[dataIndex++]='#';
		if(GETFLG(flg_bFull)==bTrue)
		{
			cnt=dataIndex;
			for(i=sensor_data.cnt;i<SENSOR_DATA_MAX;i+=2)
			{
				MakeTxTemperature(sensor_data.data[i],sensor_data.data[i+1]);
				for(j=0;j<4;j++)
				{
					TxBuf[cnt+j]=TxTemperature[j];
				}
				TxBuf[cnt+4]='|';
				cnt=cnt+5;				
			}
			for(i=0;i<sensor_data.cnt;i+=2)
			{
				MakeTxTemperature(sensor_data.data[i],sensor_data.data[i+1]);
				for(j=0;j<4;j++)
				{
					TxBuf[cnt+j]=TxTemperature[j];
				}
				TxBuf[cnt+4]='|';
				cnt=cnt+5;				
			}
			TxBuf[cnt-1]='#';
			TxBuf[cnt]='@';
			TxBuf[cnt+1]='\0';
		}
		else
		{
			cnt=dataIndex;
			for(i=0;i<sensor_data.cnt;i+=2)
			{
				MakeTxTemperature(sensor_data.data[i],sensor_data.data[i+1]);
				for(j=0;j<4;j++)
				{
					TxBuf[cnt+j]=TxTemperature[j];
				}
				TxBuf[cnt+4]='|';
				cnt=cnt+5;				
			}
			TxBuf[cnt-1]='#';
			TxBuf[cnt]='@';
			TxBuf[cnt+1]='\0';
		}
	}
	ESP_DBG(TxBuf);
	espconn_sent(pespconn, TxBuf,cnt+2);
	os_timer_disarm(&esp_client_timer);
	os_timer_setfn(&esp_client_timer, (os_timer_func_t *)user_esp_platform_SendOut_cb, pespconn);
	os_timer_arm(&esp_client_timer, 3000, 0);
}
//接收回调
//收到正确回复后将完成此次交互，主动断开与服务器连接
//否则断开，重试
LOCAL void ICACHE_FLASH_ATTR user_esp_platform_recv_cb(void *arg, char *pusrdata, unsigned short length)
{
	struct espconn *pespconn = (struct espconn *)arg;
	os_timer_disarm(&esp_client_timer);
    ESP_DBG("user_esp_platform_recv_cb %s\n", pusrdata);
	char* pChar=(char *)os_strstr(pusrdata,"#KO$1$OK#");
	if(pChar==NULL)
	{
		user_esp_platform_discon(pespconn);
	}
	else
	{		
		ESP_DBG("user_esp_platform_finish !!!\n");
		if((GETFLG(flg_bNotify)==bTrue) || (GETFLG(flg_FisrtUp)==bTrue))
		{

		}
		else
		{
			sensor_data.cnt=0;
			CLEARFLG(flg_bFull);
		}
		bSendding=0;
		user_esp_platform_discon(pespconn);
	}
}
//与服务器异常断开的回调
LOCAL void ICACHE_FLASH_ATTR user_esp_platform_recon_cb(void *arg, sint8 err)
{
    struct espconn *pespconn = (struct espconn *)arg;

    ESP_DBG("user_esp_platform_recon_cb\n");
	espConnectRetry++;
	if (espConnectRetry == 5) 
	{
		ESP_DBG("dns error\n"); 
		ErrState=ReConnect;
		LcdDisplay_Err();
		bSendding=0;
		wifi_station_disconnect();
		GotoSleep();
	}
	else
	{
		os_timer_disarm(&esp_client_timer);
		os_timer_setfn(&esp_client_timer, (os_timer_func_t *)user_esp_platform_reconnect, pespconn);
		os_timer_arm(&esp_client_timer, 1000, 0);
	}
}

//成功连接服务器后的回调
//启动发送数据流程
LOCAL void ICACHE_FLASH_ATTR user_esp_platform_connect_cb(void *arg)
{
    struct espconn *pespconn = arg;
    ESP_DBG("user_esp_platform_connect_cb\n");
    espconn_regist_recvcb(pespconn, user_esp_platform_recv_cb);
    espconn_regist_sentcb(pespconn, user_esp_platform_sent_cb);
    user_esp_platform_sent(pespconn);
}
//dns 解析回调函数
//若未解析成功，则重试
LOCAL void ICACHE_FLASH_ATTR user_esp_platform_dns_found(const char *name, ip_addr_t *ipaddr, void *arg)
{
    struct espconn *pespconn = (struct espconn *)arg;

    if (ipaddr == NULL) 
	{
        ESP_DBG("user_esp_platform_dns_found NULL\n");

        if (++espDNSRetry == 5)
		{
              ESP_DBG("dns error\n"); 
			  ErrState=MissDNS;
			  LcdDisplay_Err();
			  bSendding=0;
			  wifi_station_disconnect();
			  GotoSleep();
        }
        return;
    }

    ESP_DBG("user_esp_platform_dns_found %d.%d.%d.%d\n",
            *((uint8 *)&ipaddr->addr), *((uint8 *)&ipaddr->addr + 1),
            *((uint8 *)&ipaddr->addr + 2), *((uint8 *)&ipaddr->addr + 3));

	if (esp_server_ip.addr == 0 && ipaddr->addr != 0) 
	{
		os_timer_disarm(&esp_client_timer);
		esp_server_ip.addr = ipaddr->addr;
		os_memcpy(pespconn->proto.tcp->remote_ip, &ipaddr->addr, 4);
 
		pespconn->proto.tcp->local_port = espconn_port();
 
		pespconn->proto.tcp->remote_port = 12129;
		espconn_regist_connectcb(pespconn, user_esp_platform_connect_cb);
		espconn_regist_disconcb(pespconn, user_esp_platform_discon_cb);
		espconn_regist_reconcb(pespconn, user_esp_platform_recon_cb);
		//user_esp_platform_connect(pespconn);			
		if(espconn_connect(pespconn)==0)//成功调用连接函数，等待回调函数工作
		{
			ESP_DBG("user_esp_platform_connect\n");
		}
		else
		{
			ESP_DBG("user_esp_platform_connect err\n");
			ErrState=ErrConnect;
			LcdDisplay_Err();
			bSendding=0;
			wifi_station_disconnect();
			GotoSleep();
		}
	}
	else
	{
		ESP_DBG("user_esp_platform_iperr\n");
		ErrState=ErrIP;
		LcdDisplay_Err();
		bSendding=0;
		wifi_station_disconnect();
		GotoSleep();
	}
}
//定时重试dns解析
LOCAL void ICACHE_FLASH_ATTR user_esp_platform_dns_check_cb(void *arg)
{
    struct espconn *pespconn = arg;

    ESP_DBG("user_esp_platform_dns_check_cb\n");

    espconn_gethostbyname(pespconn, ESP_DOMAIN, &esp_server_ip, user_esp_platform_dns_found);

    os_timer_arm(&esp_client_timer, 1000, 0);
}

//发起服务器连接
void ICACHE_FLASH_ATTR user_esp_platform_connect(void)
{
	struct ip_info ipconfig;
	user_conn.proto.tcp = &user_tcp;
	user_conn.type = ESPCONN_TCP;
	user_conn.state = ESPCONN_NONE;

	esp_server_ip.addr = 0;
	espDNSRetry=0;
	espconn_gethostbyname(&user_conn, ESP_DOMAIN, &esp_server_ip, user_esp_platform_dns_found);

	os_timer_disarm(&esp_client_timer);
	os_timer_setfn(&esp_client_timer, (os_timer_func_t *)user_esp_platform_dns_check_cb, &user_conn);
	os_timer_arm(&esp_client_timer, 1000, 0);

}
//与服务器交互的启动函数
//初始化重试变量
void ICACHE_FLASH_ATTR user_esp_platform_start(void)
{	
	espConnectRetry=0;
	espSendRetry=0;
	espRecvRetry=0;
	ErrState=NoErr;
	user_esp_platform_connect();
}

