#include "WorkMode_IntervalAnalysis.h"
#include "FRAM.h"
#include "TFTWorkProc.h"
#include "DS18x20.h"
#include "hmi_driver.h"
#include "WorkMode_RealTime.h"


uint32_t IntervalAnalysis_TPageCount;
uint32_t IntervalAnalysis_TPageIndex;
_SensorData curSD;
void IntervalAnalysisModeInit( void )
{
	uint32_t i,addr,deltaMimutes;
	uint8_t t1,t2;
	char str[50];
	//获取当前时间
	ReadRTC();
	curSD.Month=RTCData.month;
	curSD.Day=RTCData.day;
	curSD.Minute=RTCData.minute;
	curSD.Hour=RTCData.hour;

	IntervalAnalysis_TPageCount=TSensorAddrSortingListCount/10;
	if(TSensorAddrSortingListCount%10!=0)
		IntervalAnalysis_TPageCount++;
	IntervalAnalysis_TPageIndex=0;
	sprintf(str,"共%u页，第%u页\0",IntervalAnalysis_TPageCount,IntervalAnalysis_TPageIndex+1);
	SetTextValue(19,cID_PageNum,str);
	myRecordClear(19,cID_Record,20);
	//温度传感器
	for(i=0;i<10;i++)
	{
		if(i>=TSensorAddrSortingListCount)
			break;
		FRAM_GetLatestSensorData(TemperatureSensor,TSensorAddrSortingList[i].SensorIndex);	
		if(IsLatestSensorDataValid())
		{
			t1=(LatestSensorData.SensorData&0x0fff)>>4;
			t2=DS18X20_ToDecicel[LatestSensorData.SensorData&0x000f];
			sprintf(str,"%u;%03u;%02u-%02u %02u:%02u;%u.%u;%u-%u;\0",
				i+1,TSensorAddrSortingList[i].SensorIndex+1,
				LatestSensorData.Month,LatestSensorData.Day,LatestSensorData.Hour,LatestSensorData.Minute,
				t1,t2,
				TSensorAddrSortingList[i].Addr1,TSensorAddrSortingList[i].Addr2);	
			//判断条目颜色
			deltaMimutes=GetDeltaTime_Minutes(LatestSensorData,curSD);
			if(deltaMimutes<ROMParams.TimeSpan1)
				SetControlBackColor(19,60+i,0x07E0);
			else if(deltaMimutes<ROMParams.TimeSpan2)
				SetControlBackColor(19,60+i,0xFFE0);
			else if(deltaMimutes<ROMParams.TimeSpan3)
				SetControlBackColor(19,60+i,0xF800);
			else
				SetControlBackColor(19,60+i,0x8410);
		}
		else
		{
			sprintf(str,"%u;%03u;xx-xx xx:xx;xx.x;%u-%u;\0",
				i+1,TSensorAddrSortingList[i].SensorIndex+1,				
				TSensorAddrSortingList[i].Addr1,TSensorAddrSortingList[i].Addr2);	
			SetControlBackColor(19,60+i,0x8410);
		}
		//2实时列表				
		Record_Add(19,cID_Record,str);
		
	}
	SetScreen(19);
}
void IntervalAnalysis_TRecordSwitchPage(uint16_t cID)
{
	uint32_t i,addr,deltaMimutes,itemIndex;
	uint8_t t1,t2;
	char str[50];
	if(IntervalAnalysis_TPageCount<2)
		return;
	if(cID==cID_btBackward)
	{
		IntervalAnalysis_TPageIndex++;
		if(IntervalAnalysis_TPageIndex==IntervalAnalysis_TPageCount)
			IntervalAnalysis_TPageIndex=0;
	}
	else
	{
		if(IntervalAnalysis_TPageIndex==0)
			IntervalAnalysis_TPageIndex=IntervalAnalysis_TPageCount-1;
		else
			IntervalAnalysis_TPageIndex--;
	}
	sprintf(str,"共%u页，第%u页\0",IntervalAnalysis_TPageCount,IntervalAnalysis_TPageIndex+1);
	SetTextValue(19,cID_PageNum,str);
	myRecordClear(19,cID_Record,20);	
	for(itemIndex=0,i=IntervalAnalysis_TPageIndex*10;i<((IntervalAnalysis_TPageIndex+1)*10);i++,itemIndex++)
	{
		if(i>=TSensorAddrSortingListCount)
		{
			SetControlBackColor(19,60+itemIndex,0x8410);
			continue;
		}
		FRAM_GetLatestSensorData(TemperatureSensor,TSensorAddrSortingList[i].SensorIndex);
		if(IsLatestSensorDataValid())
		{
			t1=(LatestSensorData.SensorData&0x0fff)>>4;
			t2=DS18X20_ToDecicel[LatestSensorData.SensorData&0x000f];
			sprintf(str,"%u;%03u;%02u-%02u %02u:%02u;%u.%u;%u-%u;\0",
				i+1,TSensorAddrSortingList[i].SensorIndex+1,
				LatestSensorData.Month,LatestSensorData.Day,LatestSensorData.Hour,LatestSensorData.Minute,
				t1,t2,
				TSensorAddrSortingList[i].Addr1,TSensorAddrSortingList[i].Addr2);	
			//判断条目颜色
			deltaMimutes=GetDeltaTime_Minutes(LatestSensorData,curSD);
			if(deltaMimutes<ROMParams.TimeSpan1)
				SetControlBackColor(19,60+itemIndex,0x07E0);
			else if(deltaMimutes<ROMParams.TimeSpan2)
				SetControlBackColor(19,60+itemIndex,0xFFE0);
			else if(deltaMimutes<ROMParams.TimeSpan3)
				SetControlBackColor(19,60+itemIndex,0xF800);
			else
				SetControlBackColor(19,60+itemIndex,0x8410);
		}
		else
		{
			sprintf(str,"%u;%03u;xx-xx xx:xx;xx.x;%u-%u;\0",
				i+1,TSensorAddrSortingList[i].SensorIndex+1,				
				TSensorAddrSortingList[i].Addr1,TSensorAddrSortingList[i].Addr2);	
			SetControlBackColor(19,60+itemIndex,0x8410);
		}
		Record_Add(19,cID_Record,(uint8_t*)str);		
	}
}