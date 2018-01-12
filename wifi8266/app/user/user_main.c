/******************************************************************************
 * Copyright 2013-2014 Espressif Systems (Wuxi)
 *
 * FileName: user_main.c
 *
 * Description: entry file of user application
 *
 * Modification history:
 *     2014/1/1, v1.0 create this file.
*******************************************************************************/
#include "ets_sys.h"
#include "osapi.h"

#include "user_interface.h"

#include "..\..\include\gpio.h"

#include "..\..\include\espconn.h"
#include "TypeDefine.h"
#include "Display.h"
#include "DS18B20.h"

#define errDST_Max 5

struct esp_platform_saved_param esp_param;

os_timer_t DS18B20_worktimer;
os_timer_t TickTimer;
unsigned char errDST=0;
unsigned char bDS18B20=0;
unsigned char bSendding=0;
unsigned char bKey=0;
void ICACHE_FLASH_ATTR DS18B20_Read_cb(void *timer_arg);
extern void user_esp_platform_workProc(void *timer_arg);
void ICACHE_FLASH_ATTR SaveT(void)
{
	if(GETFLG(flg_bNotify)==bTrue)
		return;
	sensor_data.workTick=0;
	sensor_data.data[sensor_data.cnt++]=sensor_data.DST_H;
	sensor_data.data[sensor_data.cnt++]=sensor_data.DST_L;
	os_printf("save t is %d\n",sensor_data.cnt/2);
	if(sensor_data.cnt>=SENSOR_DATA_MAX)
	{
 		sensor_data.cnt=0;
 		SETFLG(flg_bFull);
	}
	if((sensor_data.cnt%SENSOR_DATA_TxMax)==0 || (GETFLG(flg_FisrtUp)==bTrue))//达到启动数量，开始发送
	{
 		SETFLG(flg_bNeedTx);					
	}
}
void ICACHE_FLASH_ATTR TickTimer_cb(void *timer_arg)
{
	sensor_data.workTick++;
}
void ICACHE_FLASH_ATTR DS18B20_Convert_cb(void *timer_arg)
{
// 	char ssid[32] = "Pic238Hou";
// 
// 	char password[64] = "1Q2W3E4R";
// 
// 	struct station_config stationConf;
// 
// 	stationConf.bssid_set = 0; //need not check MAC address of AP
// 
// 	os_memcpy(&stationConf.ssid,ssid, 32);
// 
// 	os_memcpy(&stationConf.password, password, 64);
// 	if(GETFLG(flg_FisrtUp))
// 	{
// 		os_printf("wifi config\n");
// 		wifi_station_set_config(&stationConf);
// 		wifi_station_set_auto_connect(0);
// 		SETFLG(flg_bWifi);
// 		_S10;
// 		LCDShow();
// 	}
	os_timer_disarm(&DS18B20_worktimer);
	if(DS18B20_Convert()==DS18X20_OK)
	{
 		errDST=0;
 		os_timer_setfn(&DS18B20_worktimer, (os_timer_func_t *)DS18B20_Read_cb, NULL);
 		os_timer_arm(&DS18B20_worktimer, 1000, 0);
	}
	else
	{
 		errDST++;
 		sensor_data.DST_H=0xf0;
 		sensor_data.DST_L=0x00;
 		if(errDST>errDST_Max)
 		{
 			LcdDisplay_CurTemp();
 			if((sensor_data.workTick>=ESPWorkTick) || (GETFLG(flg_FisrtUp)==bTrue))
 			{				
 				SaveT();
 			}
 			bDS18B20=0;
 			GotoSleep();
 		}	
 		else
 			os_timer_arm(&DS18B20_worktimer, 1000, 0);
 		os_printf("Reset 18b20 Error\n");
	}
}
void ICACHE_FLASH_ATTR DS18B20_Read_cb(void *timer_arg)
{
	unsigned char temp1;
	unsigned char temp2;	
	os_timer_disarm(&DS18B20_worktimer);
	if(DS18B20_ReadFlash()==DS18X20_OK)
	{
 		temp2=sensor_data.DST_L&0x0f;
 		temp1=(sensor_data.DST_L>>4)|(sensor_data.DST_H<<4);
 		os_printf("当前温度：%d.%d ℃\r\n",temp1,temp2);
 		LcdDisplay_CurTemp();
 		if((sensor_data.workTick>=ESPWorkTick) || (GETFLG(flg_FisrtUp)==bTrue))
 		{
 			SaveT();
 		}
 		bDS18B20=0;		
 		GotoSleep();
	}
	else
	{
 		errDST++;
 		sensor_data.DST_H=0xf0;
 		sensor_data.DST_L=0x00;
 		if(errDST>errDST_Max)
 		{
 			LcdDisplay_CurTemp();
 			if(sensor_data.workTick>=ESPWorkTick)
 			{				
 				SaveT();
 			}
 			bDS18B20=0;
 			GotoSleep();
 		}	
 		else
 		{
 			os_timer_setfn(&DS18B20_worktimer, (os_timer_func_t *)DS18B20_Convert_cb, NULL);
 			os_timer_arm(&DS18B20_worktimer, 1000, 0);
 		}
 		os_printf("Read 18b20 Error\n");
	}
}
void user_rf_pre_init(void)
{	
	if(GETFLG(flg_bWifi)==bFasle)//第一次上电
	{
		system_phy_set_rfoption(1);
	}
}
/******************************************************************************
 * FunctionName : user_init
 * Description  : entry of user application, init user function here
 * Parameters   : none
 * Returns      : none
*******************************************************************************/
void user_init(void)
{
	char buf[64] = {0};
	char* pChar;
	unsigned int i;
	uart_div_modify(0, 80*1000000 / 115200);
	//system_uart_de_swap();	
	struct rst_info *rtc_info = system_get_rst_info();	
	if(rtc_info->reason!=REASON_DEEP_SLEEP_AWAKE)//第一次上电
	{
		os_printf("reset reason: %x\n", rtc_info->reason);
		wifi_station_set_auto_connect(0);
		wifi_set_opmode(STATION_MODE);
		//system_phy_set_powerup_option(2);
		os_sprintf(buf, "compile time:%s %s", __DATE__, __TIME__);

		os_printf("\n system init ok, %s\n", buf);

		os_printf("\nSDK version:%s\n", system_get_sdk_version());
		
		if (rtc_info->reason == REASON_WDT_RST ||
			rtc_info->reason == REASON_EXCEPTION_RST ||
			rtc_info->reason == REASON_SOFT_WDT_RST) 
		{
			if (rtc_info->reason == REASON_EXCEPTION_RST) 
			{
				os_printf("Fatal exception (%d):\n", rtc_info->exccause);
			}
			os_printf("epc1=0x%08x, epc2=0x%08x, epc3=0x%08x, excvaddr=0x%08x, depc=0x%08x\n",
				rtc_info->epc1, rtc_info->epc2, rtc_info->epc3, rtc_info->excvaddr, rtc_info->depc);
		}
 		key_init();
 		//user_esp_platform_Init();
 		Display_Init();
 		LcdDisplayAll(0);
 		for(i=0;i<8;i++)
 			sensor_data.DisplayReg[i]=0x00;
 		DS18B20_init();
 		InitFlashData();
 		sensor_data.cnt=0;
 		sensor_data.workTick=0;
 		sensor_data.flg=esp_param.flg;
		os_printf("flg:%d\n",sensor_data.flg);
 		if(GETFLG(flg_bWifi)==bFasle)
 		{
 			S10;
			S01;
			S03;
			sensor_data.workTick=ESPWorkTick;
			smartlink_init();			
 		}
		else
		{
			errDST=0;
			SETFLG(flg_FisrtUp);
			os_timer_disarm(&DS18B20_worktimer);
			os_timer_setfn(&DS18B20_worktimer, (os_timer_func_t *)DS18B20_Convert_cb, NULL);
			os_timer_arm(&DS18B20_worktimer, 2000, 0);
			SETFLG(flg_bNeedTx);

			os_printf("Working\n");
		}
	}
	else
	{
 		system_rtc_mem_read( SENSOR_DATA_MEM_ADDR, &sensor_data, sizeof(SENSOR_DATA_RTC_MEM) ); 
		if(GETFLG(flg_bWifi)==bTrue)
		{
			key_init();
			HT162X_Init(); 		
			bSendding=0;
			bDS18B20=0;
			bKey=0;
			sensor_data.workTick++;
			//os_printf("Working:%d\n",sensor_data.workTick);
			if(GETFLG(flg_bErrShow)==bTrue)
			{
				sensor_data.ErrTick++;
				if(sensor_data.ErrTick>ShowErrTime)
				{
					CLEARFLG(flg_bErrShow);
					os_printf("clear error\n");
				}
			}
			os_timer_disarm(&TickTimer);
			os_timer_setfn(&TickTimer, (os_timer_func_t *)TickTimer_cb, NULL);
			os_timer_arm(&TickTimer, 1000, 1);
			if(GETFLG(flg_bNeedTx))
			{
				S01;
				S03;
				_S07;
				LCDShow();
				bSendding=1;
				os_timer_disarm(&esp_client_timer);
				os_timer_setfn(&esp_client_timer, (os_timer_func_t *)user_esp_platform_workProc, NULL);
				os_timer_arm(&esp_client_timer, 1000, 1);
			}
			else
			{
				_S07_;
				LCDShow();
				if((sensor_data.workTick%FLASHTemp)==0 || (sensor_data.workTick>=ESPWorkTick))
				{
					//os_printf("Working123:%d\n",sensor_data.workTick);
					errDST=0;
					bDS18B20=1;
					os_timer_disarm(&DS18B20_worktimer);
					os_timer_setfn(&DS18B20_worktimer, (os_timer_func_t *)DS18B20_Convert_cb, NULL);
					DS18B20_Convert_cb(NULL);
				}
				key_check(NULL);
			}
		}
		else
		{
			system_restart();
		}
		
	}
}


