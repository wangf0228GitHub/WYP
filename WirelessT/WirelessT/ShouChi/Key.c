#include "HardwareProfile.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"


unsigned char KeyPollCheck(void)
{
	unsigned char i,x,key;
	for(i=0;i<8;i++)
	{
		x=0x01<<i;
		x=~x;
		LATD=x;
		KeyValue.u8H=i+1;
		KeyCheck_ReadKey(key);	
		if(key==NoKey)
		{
			//OldKey=0xffff;
			continue;
		}
		__delay_ms(20);
		KeyCheck_ReadKey(x);	
		if(x!=key)
		{
			continue;
		}
		KeyValue.u8L=x;
		if(KeyValue.u16==OldKey)//之前已经按过按键了，属于重复触发
		{
			if(!gFlags.bReKey)//不允许重复触发
				return 0;

			if(SystemTick-KeyTick>KeyCheck_ReKeyTick)//允许重复触发的需间隔600ms
			{
				KeyTick=SystemTick;
				KeyTimes++;
				return 1;
			}
			else
			{		
				return 0;
			}			
		}
		else
		{
			KeyTick=SystemTick;
			OldKey=KeyValue.u16;
			KeyTimes=0;
			gFlags.bReKey=0;

			/************************************************************************/
			/* 处理显示                                                             */
			/************************************************************************/
			SleepTick=SystemTick;
			if(gFlags.bSleep)//已经关屏了
			{
				Display_BK(0xff);
				gFlags.bSleep=0;
				gFlags.bSleep1=0;
				Display_BK(80);
				return 0;
			}
			if(gFlags.bSleep1)//屏暗了
			{
				Display_BK(80);
			}
			gFlags.bSleep=0;
			gFlags.bSleep1=0;
			return 1;
		}		
	}
	OldKey=0xffff;
	gFlags.bReKey=0;
	return 0;
}
unsigned char GetKeyNum(void)
{
	if(KeyValue.u16==Key_1)
		return 1;
	else if(KeyValue.u16==Key_2)
		return 2;
	else if(KeyValue.u16==Key_3)
		return 3;
	else if(KeyValue.u16==Key_4)
		return 4;
	else if(KeyValue.u16==Key_5)
		return 5;
	else if(KeyValue.u16==Key_6)
		return 6;
	else if(KeyValue.u16==Key_7)
		return 7;
	else if(KeyValue.u16==Key_8)
		return 8;
	else if(KeyValue.u16==Key_9)
		return 9;
	else if(KeyValue.u16==Key_0)
		return 0;
	else 
		return 0xff;
// 	switch(KeyValue.u16)
// 	{
// 	case Key_0:
// 		return 0;
// 	case Key_1:
// 		return 1;
// 	case Key_2:
// 		return 2;
// 	case Key_3:
// 		return 3;
// 	case Key_4:
// 		return 4;
// 	case Key_5:
// 		return 5;
// 	case Key_6:
// 		return 6;
// 	case Key_7:
// 		return 7;
// 	case Key_8:
// 		return 8;
// 	case Key_9:
// 		return 9;
// 	default:
// 		return 0xff;
// 	}
}

void CommonKeyFun(void)
{
	if(KeyValue.u16==Key_FastLeft)
	{
		WorkMode_AnalyzeInit();
	}
	else if(KeyValue.u16==Key_FastRight)
	{
		WorkMode_RealTimeInit();
	}
	else if(KeyValue.u16==Key_Main_1 || KeyValue.u16==Key_Main_2 || KeyValue.u16==Key_Main_3)
	{
		WorkMode=WorkMode_Main;
		Display_ShowPic(1);
	}
	else if(KeyValue.u16==Key_ESC)
	{
		if(WorkMode==WorkMode_Setting)
		{
			if(SetMode==SetMode_Main)
			{
				WorkMode=WorkMode_Main;
				Display_ShowPic(1);
			}
			else
			{
				WorkMode_SettingInit();
			}
		}
		else
		{
			WorkMode=WorkMode_Main;
			Display_ShowPic(1);
		}
	}
}
