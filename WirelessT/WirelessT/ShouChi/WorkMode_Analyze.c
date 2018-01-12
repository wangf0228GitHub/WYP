#include "HardwareProfile.h"
#include <stdio.h>
#include "ZiMo.h"
void ShowAnalyzeData(void);
void WorkMode_AnalyzeInit(void)
{
	unsigned char i,x,t1,t2;
	unsigned int y;
	WorkMode=WorkMode_Analyze;
	AnalyzePage=0;
	NoWirelessRxTick=SystemTick;
	Display_ShowPic(4);
	Display_SetTxtColor(1);
	AnalyzeTick=SystemTick-700;
	ShowAnalyzeData();
#ifndef Proteus
	Wireless_RxInit();	
#endif
	DisplayRow=0;
}
void WorkMode_AnalyzeProc(void)
{
	unsigned char keynum,x,t1,t2;
	unsigned char i;
	unsigned int mGap,y;
	_SystemCharTime ds,de,ds1;
	if(gFlags.bNewT)
	{
		x=(PickDatas.index-1)/10;
		if(x==AnalyzePage)//在当前页
		{
			DisplayRow=(PickDatas.index-1)%10;
			Display_ShowAnalyzeTemp();
			for(i=0;i<6;i++)
				SensorData4ShowList[DisplayRow].All[i]=SensorData4Save.All[i];
		}
		gFlags.bNewT=0;
	}
	if(GetDeltaTick(AnalyzeTick)>600)
	{
		AnalyzeTick=SystemTick;
		DS1302_GetTime();
		DS1302_Convert2Char();
		de.Year=DS1302_Time.Year;
		de.Month=DS1302_Time.Month;
		de.Day=DS1302_Time.Day;
		de.Hour=DS1302_Time.Hour;
		de.Minute=DS1302_Time.Minute;
		ds.Year=DS1302_Time.Year;
		if(ds.Year!=0)
			ds1.Year=DS1302_Time.Year-1;
		for(i=0;i<10;i++)
		{
			if(SensorData4ShowList[i].Month!=0xff)//没有数据
			{
				ds.Month=SensorData4ShowList[i].Month;
				ds.Day=SensorData4ShowList[i].Day;
				ds.Hour=SensorData4ShowList[i].Hour;
				ds.Minute=SensorData4ShowList[i].Minute;
				mGap=GetMinutesGap(ds,de);
				if(mGap==0xffff)
				{
					ds1.Month=SensorData4ShowList[i].Month;
					ds1.Day=SensorData4ShowList[i].Day;
					ds1.Hour=SensorData4ShowList[i].Hour;
					ds1.Minute=SensorData4ShowList[i].Minute;
					mGap=GetMinutesGap(ds1,de);
				}
				if(mGap!=0xffff)
				{
					if(mGap<ROMParams.TimeSpan1)//最新数据
					{
						if(ROMParams.TimeSpan1!=0xffff)
							Display_SetTxtColor(1);					
					}
					else if(mGap<ROMParams.TimeSpan2)//次近数据
					{
						if(ROMParams.TimeSpan2!=0xffff)
							Display_SetTxtColor(2);
					}
					else if(mGap<ROMParams.TimeSpan3)//稍远数据
					{
						if(ROMParams.TimeSpan2!=0xffff)
							Display_SetTxtColor(3);
					}
					else//无效
					{
						if(ROMParams.TimeSpan1!=0xffff || ROMParams.TimeSpan2!=0xffff || ROMParams.TimeSpan3!=0xffff)
							Display_SetTxtColor(4);
					}					
				}
				else
				{
					Display_SetTxtColor(4);
				}
				t1=(SensorData4ShowList[i].TData.u16&0x0fff)>>4;
				t2=SensorData4ShowList[i].TData.u16&0x000f;
				sprintf(DisplayLine,AnalyzeString,t1,DS18X20_ToDecicel[t2]);
				y=i*21;
				y=y+90;
				Display_ShowTxt(1,200,y,DisplayLine,5);
			}
		}
		Display_SetTxtColor(1);	
	}
 	if(KeyPollCheck()==1)
 	{			
 		if(KeyValue.u16==Key_Down)
		{			
			AnalyzePage++;
			if(AnalyzePage>=10)
			{
				AnalyzePage=0;
			}
			AnalyzeTick=SystemTick-700;
			ShowAnalyzeData();
		}
		else if(KeyValue.u16==Key_Up)
		{	
			if(AnalyzePage==0)
			{
				AnalyzePage=9;
			}
			else
			{
				AnalyzePage--;
			}
			AnalyzeTick=SystemTick-700;
			ShowAnalyzeData();
		}
		else
		{
			CommonKeyFun();
		}
// 		keynum=GetKeyNum();
//  		switch(keynum)
//  		{
//  		case 1://分析诊断
//  			break;
//  		case 2://实时采集
//  			break;
//  		case 3://历史数据
//  			break;
//  		case 4://系统设置
//  			break;
//  		}
 	}
}
void ShowAnalyzeData(void)
{
	unsigned char i,j,x,t1,t2;
	unsigned int y;			
	// 			Display_ShowPic(4);
	//			Display_SetTxtColor(1);	
	Display_SetTxtColor(1);
	x=(AnalyzePage+1)*10;
	gFlags.bINT=0;
	gFlags.bUseFram=1;
	for(i=AnalyzePage*10,j=0;i<x;i++,j++)
	{
		y=j*21;
		y=y+90;
		FRAM_GetSensorDataInfo(i);
		FRAM_GetSensorData(i,SensorData4ShowList[j].All);
		sprintf(DisplayLine,"%-20s%03u       ",SensorDataInfo.InstallPosition,i+1);
// 		if(SensorData4ShowList[j].All[0]==0xff)//没有数据
// 		{
// 			sprintf(DisplayLine,"%-20s%03u       ",SensorDataInfo.InstallPosition,i+1);
// 			
// 		}
// 		else
// 		{
// 			t1=(SensorData4ShowList[j].TData.u16&0x0fff)>>4;
// 			t2=SensorData4ShowList[j].TData.u16&0x000f;
// 			sprintf(DisplayLine,"%-20s%03u  %2u.%u ",SensorDataInfo.InstallPosition,i+1,t1,DS18X20_ToDecicel[t2]);
// 		}
		Display_ShowTxt(1,0,y,DisplayLine,30);
		if(gFlags.bINT)
		{
			i=AnalyzePage*10;
			j=0;
			gFlags.bINT=0;
		}
	}
}
