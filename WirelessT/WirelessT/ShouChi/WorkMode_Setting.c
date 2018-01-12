#include "HardwareProfile.h"
#include <stdio.h>
void WorkMode_SettingInit(void)
{
	unsigned char i,x,t1,t2;
	unsigned int y;
	WorkMode=WorkMode_Setting;
	AnalyzePage=0;
	NoWirelessRxTick=SystemTick;
	Display_ShowPic(2);
	Display_SetTxtColor(1);
	SetMode=SetMode_Main;
}
void WorkMode_SettingProc(void)
{
	unsigned char keynum;
	switch(SetMode)
	{
	case SetMode_Main:
		if(KeyPollCheck()==1)
		{			
			keynum=GetKeyNum();
			if(keynum!=0xff)
			{
				switch(keynum)
				{
				case 1:
					SetMode_DateTimeInit();
					break;
				case 2:				
					break;
				case 3:
					SetMode_ShowGapInit();
					break;
				case 4:
					SetMode_SleepInit();
					break;
				case 5:
					SetMode_SensorInit();
					break;
				}
			}
			else
			{
				CommonKeyFun();
			}
		}
		break;
	case SetMode_DateTime:
		SetMode_DateTimeProc();
		break;
	case SetMode_ShowGap:
		SetMode_ShowGapProc();
		break;
	case SetMode_Sleep:
		SetMode_SleepProc();
		break;
	case SetMode_Sensor:
		SetMode_SensorProc();
		break;
	}	
}
