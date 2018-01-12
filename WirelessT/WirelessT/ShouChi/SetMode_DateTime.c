#include "HardwareProfile.h"
#include <stdio.h>
const unsigned char DateTimeXY[12][2]=
{
	35,100,
	47,100,
	
	110,100,
	122,100,

	170,100,
	182,100,

	40,180,
	52,180,

	115,180,
	127,180,

	180,180,
	192,180,
};
void SetMode_DateTimeInit(void)
{
	unsigned char i,x,t1,t2;
	unsigned int y;
	SetMode=SetMode_DateTime;
	NoWirelessRxTick=SystemTick;
	Display_ShowPic(7);
	Display_SetTxtColor(1);
	DS1302_GetTime();
	DS1302_Convert2Char();

	SetIndex=0;
	//SetRow=0;
	FrashTick=SystemTick;
	gFlags.bFrashShow=1;

	sprintf(DisplayLine,"%02u",DS1302_Time.Year);
	Display_ShowTxt(0x02,DateTimeXY[0][0],DateTimeXY[0][1],DisplayLine,2);
	for(i=0;i<2;i++)
		SetNum[i]=DisplayLine[i];

	sprintf(DisplayLine,"%02u",DS1302_Time.Month);
	Display_ShowTxt(0x02,DateTimeXY[2][0],DateTimeXY[2][1],DisplayLine,2);
	for(i=0;i<2;i++)
		SetNum[i+2]=DisplayLine[i];

	sprintf(DisplayLine,"%02u",DS1302_Time.Day);
	Display_ShowTxt(0x02,DateTimeXY[4][0],DateTimeXY[4][1],DisplayLine,2);
	for(i=0;i<2;i++)
		SetNum[i+4]=DisplayLine[i];

	sprintf(DisplayLine,"%02u",DS1302_Time.Hour);
	Display_ShowTxt(0x02,DateTimeXY[6][0],DateTimeXY[6][1],DisplayLine,2);
	for(i=0;i<2;i++)
		SetNum[i+6]=DisplayLine[i];

	sprintf(DisplayLine,"%02u",DS1302_Time.Minute);
	Display_ShowTxt(0x02,DateTimeXY[8][0],DateTimeXY[8][1],DisplayLine,2);
	for(i=0;i<2;i++)
		SetNum[i+8]=DisplayLine[i];

	sprintf(DisplayLine,"%02u",DS1302_Time.Second);
	Display_ShowTxt(0x02,DateTimeXY[10][0],DateTimeXY[10][1],DisplayLine,2);
	for(i=0;i<2;i++)
		SetNum[i+10]=DisplayLine[i];
}
void SetMode_DateTimeProc(void)
{
 	unsigned char keynum,bCheck;
	if(GetDeltaTick(FrashTick)>4)
	{
		gFlags.bFrashShow=!gFlags.bFrashShow;
		FrashTick=SystemTick;
		if(gFlags.bFrashShow)
			DisplayLine[0]=SetNum[SetIndex];
		else
			DisplayLine[0]=' ';
		Display_ShowTxt(0x02,DateTimeXY[SetIndex][0],DateTimeXY[SetIndex][1],DisplayLine,1); 	
	}
	if(KeyPollCheck()==1)
	{			
		if(KeyValue.u16==Key_ENT)
		{
			bCheck=1;
			DS1302_Time.Year=(SetNum[0]-'0')*10+(SetNum[1]-'0');
			DS1302_Time.Month=(SetNum[2]-'0')*10+(SetNum[3]-'0');
			DS1302_Time.Day=(SetNum[4]-'0')*10+(SetNum[5]-'0');
			DS1302_Time.Hour=(SetNum[6]-'0')*10+(SetNum[7]-'0');
			DS1302_Time.Minute=(SetNum[8]-'0')*10+(SetNum[9]-'0');
			DS1302_Time.Second=(SetNum[10]-'0')*10+(SetNum[11]-'0');
			Display_SetTxtColor(3);
			if(DS1302_Time.Month>12 || DS1302_Time.Month==0)
			{
				bCheck=0;
				Display_ShowTxt(0x02,DateTimeXY[2][0],DateTimeXY[2][1],&SetNum[2],2);
			}
			if(DS1302_Time.Day>31 || DS1302_Time.Day==0)
			{
				bCheck=0;
				Display_ShowTxt(0x02,DateTimeXY[4][0],DateTimeXY[4][1],&SetNum[4],2);
			}
			if(DS1302_Time.Hour>23)
			{
				bCheck=0;
				Display_ShowTxt(0x02,DateTimeXY[6][0],DateTimeXY[6][1],&SetNum[6],2);
			}
			if(DS1302_Time.Minute>59)
			{
				bCheck=0;
				Display_ShowTxt(0x02,DateTimeXY[8][0],DateTimeXY[8][1],&SetNum[8],2);
			}
			if(DS1302_Time.Second>59)
			{
				bCheck=0;
				Display_ShowTxt(0x02,DateTimeXY[10][0],DateTimeXY[10][1],&SetNum[10],2);
			}
			Display_SetTxtColor(1);
			if(bCheck!=0)
			{
				DS1302_Time.Year=CHAR2BCD(DS1302_Time.Year);
				DS1302_Time.Month=CHAR2BCD(DS1302_Time.Month);
				DS1302_Time.Day=CHAR2BCD(DS1302_Time.Day);
				DS1302_Time.Hour=CHAR2BCD(DS1302_Time.Hour);
				DS1302_Time.Minute=CHAR2BCD(DS1302_Time.Minute);
				DS1302_Time.Second=CHAR2BCD(DS1302_Time.Second);
				DS1302_SetTime();
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
		}
		else if(KeyValue.u16==Key_Left)
		{
			Display_ShowTxt(0x02,DateTimeXY[SetIndex][0],DateTimeXY[SetIndex][1],&SetNum[SetIndex],1); 
			if(SetIndex==0)
				SetIndex=11;
			else
				SetIndex--;
		}	
		else if(KeyValue.u16==Key_Right)
		{
			Display_ShowTxt(0x02,DateTimeXY[SetIndex][0],DateTimeXY[SetIndex][1],&SetNum[SetIndex],1); 
			if(SetIndex==11)
				SetIndex=0;
			else
				SetIndex++;
		}
		else if(KeyValue.u16==Key_TAB || KeyValue.u16==Key_Down)
		{
			Display_ShowTxt(0x02,DateTimeXY[SetIndex][0],DateTimeXY[SetIndex][1],&SetNum[SetIndex],1); 
			SetIndex=SetIndex+2;
			if(SetIndex>11)
				SetIndex=SetIndex-12;
		}
		else if(KeyValue.u16==Key_Up)
		{
			Display_ShowTxt(0x02,DateTimeXY[SetIndex][0],DateTimeXY[SetIndex][1],&SetNum[SetIndex],1); 
			if(SetIndex<2)
				SetIndex=SetIndex+10;
			else
				SetIndex=SetIndex-2;
		}
		else
		{
			keynum=GetKeyNum();
			if(keynum!=0xff)//ÊÇÊý×Ö
			{
				gFlags.bFrashShow=0;
				FrashTick=SystemTick-10;
				SetNum[SetIndex]=keynum+'0';  
				Display_ShowTxt(0x02,DateTimeXY[SetIndex][0],DateTimeXY[SetIndex][1],&SetNum[SetIndex],1); 
				if(SetIndex==11)
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
