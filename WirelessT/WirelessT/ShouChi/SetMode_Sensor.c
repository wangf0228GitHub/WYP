#include "HardwareProfile.h"
#include <stdio.h>
const unsigned char SensorXY[5][2]=
{
	124,115,
	136,115,
	148,115,

	130,155,
	142,155,
};
//#define NoSenserFreq
unsigned char sensorID=1;
unsigned char sensorFreq=0;
unsigned char bSensorSetting;
void SetMode_SensorInit(void)
{
	unsigned char i,x,t1,t2;
	unsigned int y;
	SetMode=SetMode_Sensor;
	NoWirelessRxTick=SystemTick;
	Display_ShowPic(11);
	Display_SetTxtColor(1);

	SetIndex=2;
	FrashTick=SystemTick;
	gFlags.bFrashShow=1;
	bSensorSetting=0;
	sprintf(DisplayLine,"%03u",sensorID);
	Display_ShowTxt(0x02,SensorXY[0][0],SensorXY[0][1],DisplayLine,3);
	for(i=0;i<3;i++)
		SetNum[i]=DisplayLine[i];

	sprintf(DisplayLine,"%02u",sensorFreq);
	Display_ShowTxt(0x02,SensorXY[3][0],SensorXY[3][1],DisplayLine,2);
	for(i=0;i<2;i++)
		SetNum[i+3]=DisplayLine[i];
}
void SetMode_SensorProc(void)
{
	unsigned char keynum,bCheck,sss,tx[10],retry,TxTick,sum;
	if(bSensorSetting==0)
	{
		if(GetDeltaTick(FrashTick)>4)
		{
			gFlags.bFrashShow=!gFlags.bFrashShow;
			FrashTick=SystemTick;
			if(gFlags.bFrashShow)
				DisplayLine[0]=SetNum[SetIndex];
			else
				DisplayLine[0]=' ';
			Display_ShowTxt(0x02,SensorXY[SetIndex][0],SensorXY[SetIndex][1],DisplayLine,1); 
		}
		if(KeyPollCheck()==1)
		{			
			if(KeyValue.u16==Key_ENT)
			{
				sensorID=(SetNum[0]-'0')*100+(SetNum[1]-'0')*10+(SetNum[2]-'0');	
				bCheck=1;
				Display_SetTxtColor(3);				
				if(sensorID>100 || sensorID==0 || SetNum[0]>'1')
				{					
					Display_ShowTxt(0x02,SensorXY[0][0],SensorXY[0][1],SetNum,3);
					bCheck=0;
				}				
// 				if(sensorFreq>15)
// 				{
// 					sensorFreq=0;
// 				}
				Display_SetTxtColor(1);
				if(bCheck==1)
				{
					bSensorSetting=1;
					Display_ShowTxt(0x02,SensorXY[SetIndex][0],SensorXY[SetIndex][1],&SetNum[SetIndex],1); 
				}
			}
			else if(KeyValue.u16==Key_Left)
			{
				Display_ShowTxt(0x02,SensorXY[SetIndex][0],SensorXY[SetIndex][1],&SetNum[SetIndex],1); 
				if(SetIndex==0)
					SetIndex=4;
				else
					SetIndex--;
			}	
			else if(KeyValue.u16==Key_Right)
			{
				Display_ShowTxt(0x02,SensorXY[SetIndex][0],SensorXY[SetIndex][1],&SetNum[SetIndex],1); 
				if(SetIndex==4)
					SetIndex=0;
				else
					SetIndex++;
			}
			else if(KeyValue.u16==Key_TAB || KeyValue.u16==Key_Down || KeyValue.u16==Key_Up)
			{
				Display_ShowTxt(0x02,SensorXY[SetIndex][0],SensorXY[SetIndex][1],&SetNum[SetIndex],1); 
				if(SetIndex>2)
					SetIndex=2;
				else
					SetIndex=4;
			}
			else
			{
				keynum=GetKeyNum();
				if(keynum!=0xff)//ÊÇÊý×Ö
				{
					gFlags.bFrashShow=0;
					FrashTick=SystemTick-10;
					SetNum[SetIndex]=keynum+'0';  
					Display_ShowTxt(0x02,SensorXY[SetIndex][0],SensorXY[SetIndex][1],&SetNum[SetIndex],1);
				}
				else
				{
					CommonKeyFun();
				}
			}
		}
	}
	else
	{	
		Wireless_SetInit();
		sss=10;
		sprintf(DisplayLine,"123:%2u",sss);
		Display_ShowTxt(1,20,200,DisplayLine,6);
		SettingTick=SystemTick;
		tx[0]=sensorID;
		tx[1]=0;//sensorFreq;
		while(1)
		{			
			retry=5;
			while(retry!=0)
			{
				retry--;				
				Si4463_SEND_PACKET(tx,PACKET_LENGTH,SetFreq,0x00);
				TxTick=20;
				while(TxTick!=0)
				{				
					if(Si4463_NIRQ_R==0)
					{
						Si4463_INT_STATUS(Si4463Temp);
						if((Si4463Temp[3] & ( 1<<5 ))!=0)
							break;
					}
					__delay_ms(20);
					TxTick--;
				}
				if(TxTick!=0)
					break;
				else
					Wireless_SetInit();
			}
			Si4463_FIFO_INFO(Si4463Temp);
			Si4463_INT_STATUS(Si4463Temp);
			Si4463_PART_INFO(Si4463Temp);
			Si4463_START_RX(SetFreq,0x00,PACKET_LENGTH,0x08,0x08,0x08);
			TxTick=50;
			while(TxTick!=0)
			{				
				if(Si4463_NIRQ_R==0)
				{
					Si4463_INT_STATUS(Si4463Temp);
					if((Si4463Temp[3] & ( 1<<4 ))!=0)
					{
						Si4463_READ_PACKET(Si4463Temp);
						if(Si4463Temp[0]==sensorID)
						{
							sum=GetVerify_Sum(Si4463Temp,PACKET_LENGTH-1);
							if(sum==Si4463Temp[PACKET_LENGTH-1])
							{
								if(Si4463Temp[0]==sensorID && Si4463Temp[2]=='o' && Si4463Temp[3]=='k')// && Si4463Temp[1]==sensorFreq)
								{
									Display_ShowPic(12);
									//Display_ShowTxt(1,0,0,"OK",2);
									break;
								}
							}		
						}				
						Si4463_FIFO_INFO(Si4463Temp);
					}
				}
				__delay_ms(20);
				TxTick--;
			}
			if(TxTick!=0)
				break;
			if(GetDeltaTick(SettingTick)>9)
			{
				SettingTick=SystemTick;
				sss--;
				if(sss==0)
				{
					//Display_ShowTxt(1,0,0,"Fail",4);
					Display_ShowPic(13);
					break;
				}
				sprintf(DisplayLine,"123:%2u",sss);
				Display_ShowTxt(1,20,200,DisplayLine,6);
			}
		}
		SettingTick=SystemTick;
		while(1)
		{
			if(GetDeltaTick(SettingTick)>30)
			{
				SetMode_SensorInit();
				break;
			}
		}
	}
}
