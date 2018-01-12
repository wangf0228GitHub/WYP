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
#include "smartconfig.h"
#include "TypeDefine.h"
#include "Display.h"

// Select smartconfig method.
#define USE_ESPTOUCH 1
//#define USE_AIRKISS 1


static unsigned char bSC=0;

// void ICACHE_FLASH_ATTR smartlink_Finish(void)
// {
// 	os_timer_disarm(&work_timer);
// 	os_timer_setfn(&work_timer, (os_timer_func_t *)user_workProc, NULL);
// 	os_timer_arm(&work_timer, 1000, 1);
// }

LOCAL os_timer_t smartlink_timer;

LOCAL void ICACHE_FLASH_ATTR smartlink_done(sc_status status, void *pdata)
{
	switch (status)
	{
	case SC_STATUS_WAIT:
		os_printf("SC_STATUS_WAIT\n");
		break;
	case SC_STATUS_FIND_CHANNEL:
		os_printf("SC_STATUS_FIND_CHANNEL\n");
		break;
	case SC_STATUS_GETTING_SSID_PSWD:
		os_printf("SC_STATUS_GETTING_SSID_PSWD\n");
		sc_type *type = pdata;
		if (*type == SC_TYPE_ESPTOUCH)
		{
			os_printf("SC_TYPE:SC_TYPE_ESPTOUCH\n");
		}
		else
		{
			os_printf("SC_TYPE:SC_TYPE_AIRKISS\n");
		}
		break;
	case SC_STATUS_LINK:
		os_printf("SC_STATUS_LINK\n");
		struct station_config *sta_conf = pdata;

		wifi_station_set_config(sta_conf);
		wifi_station_disconnect();
		wifi_station_connect();
		break;
	case SC_STATUS_LINK_OVER:
		os_printf("SC_STATUS_LINK_OVER\n");

		if (pdata != NULL)
		{
			uint8 phone_ip[4] = {0};

			os_memcpy(phone_ip, (uint8 *)pdata, 4);
			os_printf("Phone ip: %d.%d.%d.%d\n", phone_ip[0], phone_ip[1], phone_ip[2], phone_ip[3]);
		}
		else
		{
			os_printf("Unkown IP\n");
		}
		smartconfig_stop();
		os_timer_disarm(&smartlink_timer);
		wifi_station_disconnect();
		wifi_station_set_auto_connect(0);
		wifi_set_opmode(STATION_MODE);
		SetWififlg(1);	
		system_restart();
// 		SETFLG(flg_bWifi);
// 		_S10;
// 		LCDShow();
// 		errDST=0;
// 		SETFLG(flg_FisrtUp);
// 		os_timer_disarm(&DS18B20_worktimer);
// 		os_timer_setfn(&DS18B20_worktimer, (os_timer_func_t *)DS18B20_Convert_cb, NULL);
// 		os_timer_arm(&DS18B20_worktimer, 2000, 0);
// 		SETFLG(flg_bNeedTx);
// 
// 		os_printf("Working\n");
// 		bSC=1;
// 		smartlink_Finish();
		break;
	}

}

void ICACHE_FLASH_ATTR smartlink_start(void)
{
	wifi_set_opmode(STATION_MODE);
	smartconfig_set_type(SC_TYPE_ESPTOUCH_AIRKISS);
#if defined(USE_ESPTOUCH)
	// USE ESPTOUCH
	smartconfig_start(smartlink_done, 255);
#endif

#if defined(USE_AIRKISS)
	// USE AIRKISS
	smartconfig_start(smartlink_done, 255);
#endif
}

void ICACHE_FLASH_ATTR smartlink_stop(void)
{

#if defined(USE_ESPTOUCH)
	// USE ESPTOUCH
	smartconfig_stop();
#endif

#if defined(USE_AIRKISS)
	// USE AIRKISS
	smartconfig_stop();
#endif
}

void ICACHE_FLASH_ATTR smartlink_check(void)
{
	static uint8 count = 0;
	uint8 status;
	os_timer_disarm(&smartlink_timer);
	_S07_;
	LCDShow();
	sensor_data.workTick++;
	if((sensor_data.workTick%FLASHTemp)==0 || (sensor_data.workTick>=ESPWorkTick))
	{
		//os_printf("Working123:%d\n",sensor_data.workTick);
		errDST=0;
		bDS18B20=1;
		os_timer_disarm(&DS18B20_worktimer);
		os_timer_setfn(&DS18B20_worktimer, (os_timer_func_t *)DS18B20_Convert_cb, NULL);
		DS18B20_Convert_cb(NULL);
	}
	status = wifi_station_get_connect_status();
	//os_printf("Check Wi-Fi link status %d\r\n",status);
	if (STATION_IDLE == status)
	{
//		os_printf("STATION_IDLE\r\n");
// 		smartlink_stop();
// 		smartlink_start();
// 		return;
	}
	else if (STATION_WRONG_PASSWORD == status)
	{
		os_printf("STATION_WRONG_PASSWORD\r\n");
// 		smartlink_stop();
// 		smartlink_start();
// 		return;
	}
	else if (STATION_NO_AP_FOUND == status)
	{
		os_printf("STATION_NO_AP_FOUND\r\n");
// 		smartlink_stop();
// 		smartlink_start();
// 		return;
	}
	else if (STATION_CONNECT_FAIL == status)
	{
		os_printf("STATION_CONNECT_FAIL\r\n");
// 		smartlink_stop();
// 		smartlink_start();
// 		return;
	}
	else if (STATION_GOT_IP == status)
	{
		// 连接成功
		os_printf("STATION_LINK_OK\r\n");
// 		if(bSC==0)//未配置连接
// 		{
// 			wifi_station_disconnect();
// 			smartlink_stop();
// 			smartlink_start();
// 		}
// 		else
// 		{
// 			smartlink_Finish();
// 		}
		return;
	}

	// STATION_CONNECTING
// 	count++;
// 	if (count >= 30)
// 	{
// 		//os_printf("STATION_CONNECT_TIME_OUT\r\n");
// 		smartlink_stop();
// 		smartlink_start();
// 		count = 0;
// 		//return;
// 	}

	os_timer_disarm(&smartlink_timer);
	os_timer_setfn(&smartlink_timer, (os_timer_func_t *)smartlink_check, 1);
	os_timer_arm(&smartlink_timer, 1000, 0);
}

void ICACHE_FLASH_ATTR smartlink_init(void)
{
	bSC=false;
	os_timer_disarm(&smartlink_timer);
	os_timer_setfn(&smartlink_timer, (os_timer_func_t *)smartlink_check, 1);
	os_timer_arm(&smartlink_timer, 1000, 0);
	smartlink_start();
}

/**************
smartlink结果
***************
Check Wi-Fi link status
STATION_IDLE
f 0, scandone
f 0, scandone
SC_STATUS_FIND_CHANNEL

TYPE: ESPTOUCH V2.4
T|PHONE MAC: a0 86 c6 96 95 2d
T|AP MAC   : 0 22 aa a5 67 88
SC_STATUS_GETTING_SSID_PSWD
SC_TYPE:SC_TYPE_ESPTOUCH
T|SCAN SSID: Test_1
T|pswd: 1234567890.
T|ssid: Test_1
T|bssid: 00 22 aa a5 67 88
SC_STATUS_LINK
f 0, scandone
add 0
aid 4
pm open phy_2,type:2 0 0
cnt

connected with Test_1, channel 2
dhcp client start...
ip:192.168.1.11,mask:255.255.255.0,gw:192.168.1.1
SC_STATUS_LINK_OVER
Phone ip: 192.168.1.32
*/


