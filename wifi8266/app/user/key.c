/******************************************************************************
 * Copyright 2013-2014 Espressif Systems (Wuxi)
 *
 * FileName: key.c
 *
 * Description: key driver, now can use different gpio and install different function
 *
 * Modification history:
 *     2014/5/1, v1.0 create this file.
*******************************************************************************/
#include "ets_sys.h"
#include "os_type.h"
#include "osapi.h"
#include "mem.h"
#include "gpio.h"
#include "user_interface.h"
#include "TypeDefine.h"
#include "Display.h"


os_timer_t k1_3sTimer;
os_timer_t k2_3sTimer;
os_timer_t KeyCheckTimer;
unsigned char bk1=0;
unsigned char bk2=0;
unsigned char bk1Proc=0;
unsigned char bk2Proc=0;
void ICACHE_FLASH_ATTR	k1_3sTimer_cb(void *timer_arg)
{
	S01;
	S03;
	_S07;
	S10;
	LCDShow();
	bk1Proc=1;
	os_timer_disarm(&k1_3sTimer);
	os_timer_disarm(&KeyCheckTimer);
	CLEARFLG(flg_bWifi);
	SetWififlg(0);	
	//sensor_data.workTick=ESPWorkTick;
	wifi_station_disconnect();
	wifi_station_set_auto_connect(0);
	wifi_set_opmode(STATION_MODE);
//	system_restart();
	system_deep_sleep_set_option(1);
	system_rtc_mem_write(SENSOR_DATA_MEM_ADDR, &sensor_data, sizeof(SENSOR_DATA_RTC_MEM));
// 	CLEARFLG(flg_bWifi);
	system_deep_sleep(1000);

// 	smartlink_init();
}
void ICACHE_FLASH_ATTR	k2_3sTimer_cb(void *timer_arg)
{
	S01;
	S03;
	_S07;
	S05;
	S06;
	LCDShow();
	bk2Proc=1;
	os_timer_disarm(&k2_3sTimer);
	SETFLG(flg_bNotify);
	SETFLG(flg_bNeedTx);
	CLEARFLG(flg_bErrShow);
	errDST=0;
	bDS18B20=1;
	os_timer_disarm(&DS18B20_worktimer);
	os_timer_setfn(&DS18B20_worktimer, (os_timer_func_t *)DS18B20_Convert_cb, NULL);
	DS18B20_Convert_cb(NULL);
}
void ICACHE_FLASH_ATTR	key_check(void *timer_arg)
{
	unsigned char k1=GPIO_INPUT_GET(4);
	unsigned char k2=GPIO_INPUT_GET(5);	
	os_timer_disarm(&KeyCheckTimer);
	if(k1==0 || k2==0)
	{
		bKey=1;
		os_timer_arm(&KeyCheckTimer, 20, 0);
		if(k1==0)
		{
			if(bk1==0 && bk1Proc==0)//首次发现按键
			{
				bk1=1;
				os_timer_arm(&k1_3sTimer, 5000, 0);
			}
		}
		else
		{
			bk1=0;
			os_timer_disarm(&k1_3sTimer);
		}
		if(k2==0)
		{
			if(bk2==0 && bk2Proc==0)//首次发现按键
			{
				bk2=1;
				os_timer_arm(&k2_3sTimer, 5000, 0);
			}
		}
		else
		{
			bk2=0;
			os_timer_disarm(&k2_3sTimer);
		}
	}
	else
	{
		bKey=0;
		GotoSleep();
	}	
}

void ICACHE_FLASH_ATTR key_init(void)
{
	//PIN_FUNC_SELECT(PERIPHS_IO_MUX_GPIO0_U, FUNC_GPIO0);
	PIN_FUNC_SELECT(PERIPHS_IO_MUX_GPIO2_U, FUNC_GPIO2);
	PIN_FUNC_SELECT(PERIPHS_IO_MUX_GPIO4_U, FUNC_GPIO4);
	PIN_FUNC_SELECT(PERIPHS_IO_MUX_GPIO5_U, FUNC_GPIO5);
	//PIN_FUNC_SELECT(PERIPHS_IO_MUX_SD_DATA2_U, FUNC_GPIO9);
	//PIN_FUNC_SELECT(PERIPHS_IO_MUX_SD_DATA3_U, FUNC_GPIO10);
	PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTDI_U, FUNC_GPIO12);
	PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTCK_U, FUNC_GPIO13);
	PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTMS_U, FUNC_GPIO14);
	//PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTDO_U, FUNC_GPIO15);
	gpio_output_set(0, 0, 0, BIT4|BIT5|BIT2);//输入使能
	os_timer_disarm(&KeyCheckTimer);
	os_timer_disarm(&k1_3sTimer);
	os_timer_disarm(&k2_3sTimer);
	os_timer_setfn(&KeyCheckTimer, (os_timer_func_t *)key_check, NULL);
	os_timer_setfn(&k1_3sTimer, (os_timer_func_t *)k1_3sTimer_cb, NULL);
	os_timer_setfn(&k2_3sTimer, (os_timer_func_t *)k2_3sTimer_cb, NULL);
	bk1=0;
	bk2=0;
	bk1Proc=0;
	bk2Proc=0;
}


