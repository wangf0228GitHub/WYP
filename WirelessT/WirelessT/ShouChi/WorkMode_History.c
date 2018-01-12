#include "HardwareProfile.h"
#include <stdio.h>
const unsigned char HistoryXY[3][2]=
{
	48,184,
	60,184,
	72,184
};
unsigned char bLook;
void hinit(void)
{
	unsigned char x;
	Display_ShowPic(6);	
	FRAM_HistoryGetPageSensorData();
	x=sprintf(DisplayLine,"%s",SensorDataInfo.InstallPosition);
	Display_ShowTxt(0x01,57,62,DisplayLine,x);
	sprintf(DisplayLine,"%03u",History_SensorIndex+1);
	Display_ShowTxt(0x01,200,62,DisplayLine,3);
	Display_ShowHistory();	
}
void WorkMode_HistoryInit(unsigned char hID)
{
	unsigned char i;
	unsigned int y;
	WorkMode=WorkMode_History;
	if(hID<100)
	{
		bLook=1;
		History_SensorIndex=hID;
		History_Page=0;
		FRAM_GetSensorDataInfo(History_SensorIndex);
		hinit();
	}
	else
	{
		bLook=0;
		Display_ShowPic(5);
		SetIndex=2;
		FrashTick=SystemTick;
		Display_SetTxtColor(1);
		gFlags.bFrashShow=1;
		sprintf(DisplayLine,"%03u",History_SensorIndex);
		Display_ShowTxt(0x02,HistoryXY[0][0],HistoryXY[0][1],DisplayLine,3);
		for(i=0;i<3;i++)
			SetNum[i]=DisplayLine[i];		
	}	
}
void WorkMode_HistoryProc(void)
{
	unsigned char keynum,x,retry,sss;
	unsigned char TxTick,tx[4];
	if(bLook==1)
	{
		if(KeyPollCheck()==1)
		{
			if(KeyValue.u16==Key_Up)
			{
				if(History_Page==0)
					History_Page=History_curPageCount-1;
				else
					History_Page--;
				hinit();
			}
			else if(KeyValue.u16==Key_Down)
			{
				History_Page++;
				if(History_Page>=History_curPageCount)
					History_Page=0;
				hinit();
			}
			else if(KeyValue.u16==Key_ESC)
			{
				WorkMode_HistoryInit(0xff);
			}
			else
			{
				CommonKeyFun();
			}
		}
	}
	else
	{
		if(GetDeltaTick(FrashTick)>4)
		{
			gFlags.bFrashShow=!gFlags.bFrashShow;
			FrashTick=SystemTick;
			if(gFlags.bFrashShow)
				DisplayLine[0]=SetNum[SetIndex];
			else
				DisplayLine[0]=' ';
			Display_ShowTxt(0x02,HistoryXY[SetIndex][0],HistoryXY[SetIndex][1],DisplayLine,1); 
		}
		if(KeyPollCheck()==1)
		{			
			if(KeyValue.u16==Key_ENT)
			{			
				x=(SetNum[0]-'0')*100+(SetNum[1]-'0')*10+(SetNum[2]-'0');
				if(x>100 || x==0)
				{
					Display_SetTxtColor(3);
					Display_ShowTxt(0x02,HistoryXY[0][0],HistoryXY[0][1],SetNum,3);
					Display_SetTxtColor(1);
				}
				else
				{					
					WorkMode_HistoryInit(x-1);
				}
			}
			else if(KeyValue.u16==Key_Left)
			{
				Display_ShowTxt(0x02,HistoryXY[SetIndex][0],HistoryXY[SetIndex][1],&SetNum[SetIndex],1); 
				if(SetIndex==0)
					SetIndex=1;
				else
					SetIndex--;
			}	
			else if(KeyValue.u16==Key_Right)
			{
				Display_ShowTxt(0x02,HistoryXY[SetIndex][0],HistoryXY[SetIndex][1],&SetNum[SetIndex],1); 
				if(SetIndex==2)
					SetIndex=0;
				else
					SetIndex++;
			}
			else
			{
				keynum=GetKeyNum();
				if(keynum!=0xff)//是数字
				{
					gFlags.bFrashShow=0;
					FrashTick=SystemTick-10;
					SetNum[SetIndex]=keynum+'0';  
					Display_ShowTxt(0x02,HistoryXY[SetIndex][0],HistoryXY[SetIndex][1],&SetNum[SetIndex],1); 
// 					if(SetIndex==1)
// 						SetIndex=0;
// 					else
// 						SetIndex++;
				}
				else
				{
					CommonKeyFun();
				}
			}
		}
	}
// 	if(GetDeltaTick(FrashTick)>4)
// 	{
// 		gFlags.bFrashShow=!gFlags.bFrashShow;
// 		FrashTick=SystemTick;
// 		if(gFlags.bFrashShow)
// 			DisplayLine[0]=SetNum[SetIndex];
// 		else
// 			DisplayLine[0]=' ';
// 		Display_ShowTxt(0x02,HistoryXY[SetIndex][0],HistoryXY[SetIndex][1],DisplayLine,1); 	
// 	}
// 	if(KeyPollCheck()==1)
// 	{			
// 		if(KeyValue.u16==Key_ENT)
// 		{			
// 			ROMParams.HistoryTimeSpan=(SetNum[0]-'0')*10+(SetNum[1]-'0');
// 			FRAM_SaveROMParams();
// 			Display_ShowPic(12);
// 			SettingTick=SystemTick;
// 			while(1)
// 			{
// 				if(GetDeltaTick(SettingTick)>30)
// 				{
// 					WorkMode_SettingInit();
// 					return;
// 				}
// 			}
// 		}
// 		else if(KeyValue.u16==Key_Left)
// 		{
// 			Display_ShowTxt(0x02,HistoryXY[SetIndex][0],HistoryXY[SetIndex][1],&SetNum[SetIndex],1); 
// 			if(SetIndex==0)
// 				SetIndex=1;
// 			else
// 				SetIndex--;
// 		}	
// 		else if(KeyValue.u16==Key_Right)
// 		{
// 			Display_ShowTxt(0x02,HistoryXY[SetIndex][0],HistoryXY[SetIndex][1],&SetNum[SetIndex],1); 
// 			if(SetIndex==1)
// 				SetIndex=0;
// 			else
// 				SetIndex++;
// 		}
// 		else
// 		{
// 			keynum=GetKeyNum();
// 			if(keynum!=0xff)//是数字
// 			{
// 				gFlags.bFrashShow=0;
// 				FrashTick=SystemTick-10;
// 				SetNum[SetIndex]=keynum+'0';  
// 				Display_ShowTxt(0x02,HistoryXY[SetIndex][0],HistoryXY[SetIndex][1],&SetNum[SetIndex],1); 
// 				if(SetIndex==1)
// 					SetIndex=0;
// 				else
// 					SetIndex++;
// 			}
// 			else
// 			{
// 				CommonKeyFun();
// 			}
// 		}
// 	}	
}
