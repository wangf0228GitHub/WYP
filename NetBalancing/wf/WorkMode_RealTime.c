#include "WorkMode_RealTime.h"
#include "..\VisualTFT\hmi_driver.h"
#include "..\WirelessProc.h"
#include "FRAM.h"
#include "TFTWorkProc.h"
#include "SPIROM.h"

uint32_t realtimeTDataIndex;
uint32_t realtimePDataIndex;
uint32_t realtimeTPageOfBarCharts;
uint32_t realtimePPageOfBarCharts;
uint32_t realtimeTPageCountOfBarCharts;
uint32_t realtimePPageCountOfBarCharts;
_SensorData SensorData4Save;
void WorkMode_RealTimeInit(void)
{
	Wireless_RxInit();	
}

void RealTime_TBarChartsSwitchPage(uint16_t cID)
{
	uint32_t addr,i,sortIndex,t;
	_SensorDataInfo sdInfo;
	_SensorData sd;
	if(cID==cID_btForward)
	{
		if(realtimeTPageOfBarCharts==realtimeTPageCountOfBarCharts)
			realtimeTPageOfBarCharts=0;
		else
			realtimeTPageOfBarCharts++;
	}
	else
	{
		if(realtimeTPageOfBarCharts==0)
			realtimeTPageOfBarCharts=realtimeTPageCountOfBarCharts;
		else
			realtimeTPageOfBarCharts--;
	}
	sortIndex=realtimeTPageOfBarCharts*SensorCountOfBarCharts;
	for(i=0;i<SensorCountOfBarCharts;i++,sortIndex++)
	{
		if(sortIndex>=TSensorAddrSortingListCount)
		{
			SetProgressValue(4,cID_Bar1+i,0);
		}
		else
		{
			addr=TSensorAddrSortingList[sortIndex].SensorIndex*640+128;
			SPIROM_ReadArray(addr,sdInfo.All,SensorDataInfoCount);
			addr=addr+8+sdInfo.curDataSaveIndex*6;
			SPIROM_ReadArray(addr,sd.All,6);
			t=sd.SensorData;
			t=t+0x08;
			t=t>>4;
			SetProgressValue(4,cID_Bar1+i,t);
		}
	}
	
}
void WorkMode_RealTimeProc(void)
{
	ReadRTC();
	SensorData4Save.Month=RTCData.month;
	SensorData4Save.Day=RTCData.day;
	SensorData4Save.Hour=RTCData.hour;
	SensorData4Save.Minute=RTCData.minute;
	SensorData4Save.SensorData=WirelessPacket.SensorData;
	if(WirelessPacket.StateBits.bTemperature)//ÎÂ¶È´«¸ÐÆ÷
	{
		realtimeTDataIndex++;
	}
	else
	{
		realtimePDataIndex++;
	}
	TFT_NewSensorDataProc();
}