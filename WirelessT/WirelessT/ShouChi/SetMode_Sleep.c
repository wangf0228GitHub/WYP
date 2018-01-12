#include "HardwareProfile.h"
#include <stdio.h>
const unsigned char SleepXY[2][2]=
{
	80,130,
	92,130,
};
void SetMode_SleepInit(void)
{
	unsigned char i,x,t1,t2;
	unsigned int y;
	SetMode=SetMode_Sleep;
	Display_ShowPic(10);
	Display_SetTxtColor(1);

	SetIndex=0;
	FrashTick=SystemTick;
	gFlags.bFrashShow=1;
	sprintf(DisplayLine,"%02u",ROMParams.SleepTimeSpan);
	Display_ShowTxt(0x02,SleepXY[0][0],SleepXY[0][1],DisplayLine,2);
	for(i=0;i<2;i++)
		SetNum[i]=DisplayLine[i];
}
void SetMode_SleepProc(void)
{
	unsigned char keynum,x,retry,sss;
	unsigned char TxTick,tx[4];
	if(GetDeltaTick(FrashTick)>4)
	{
		gFlags.bFrashShow=!gFlags.bFrashShow;
		FrashTick=SystemTick;
		if(gFlags.bFrashShow)
			DisplayLine[0]=SetNum[SetIndex];
		else
			DisplayLine[0]=' ';
		Display_ShowTxt(0x02,SleepXY[SetIndex][0],SleepXY[SetIndex][1],DisplayLine,1); 	
	}
	if(KeyPollCheck()==1)
	{			
		if(KeyValue.u16==Key_ENT)
		{			
			ROMParams.SleepTimeSpan=(SetNum[0]-'0')*10+(SetNum[1]-'0');
			FRAM_SaveROMParams();
			Display_ShowPic(12);
			SettingTick=SystemTick;
			while(1)
			{
				if(GetDeltaTick(SettingTick)>30)
				{
					WorkMode_SettingInit();
					return;
				}
			}
		}
		else if(KeyValue.u16==Key_Left)
		{
			Display_ShowTxt(0x02,SleepXY[SetIndex][0],SleepXY[SetIndex][1],&SetNum[SetIndex],1); 
			if(SetIndex==0)
				SetIndex=1;
			else
				SetIndex--;
		}	
		else if(KeyValue.u16==Key_Right)
		{
			Display_ShowTxt(0x02,SleepXY[SetIndex][0],SleepXY[SetIndex][1],&SetNum[SetIndex],1); 
			if(SetIndex==1)
				SetIndex=0;
			else
				SetIndex++;
		}
		else
		{
			keynum=GetKeyNum();
			if(keynum!=0xff)//ÊÇÊý×Ö
			{
				gFlags.bFrashShow=0;
				FrashTick=SystemTick-10;
				SetNum[SetIndex]=keynum+'0';  
				Display_ShowTxt(0x02,SleepXY[SetIndex][0],SleepXY[SetIndex][1],&SetNum[SetIndex],1); 
				if(SetIndex==1)
					SetIndex=0;
				else
					SetIndex++;
			}
			else
			{
				CommonKeyFun();
			}
		}
	}	
}
