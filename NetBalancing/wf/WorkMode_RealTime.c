#include "WorkMode_RealTime.h"
#include "..\VisualTFT\hmi_driver.h"
#include "..\WirelessProc.h"
#include "FRAM.h"
#include "TFTWorkProc.h"
#include "SPIROM.h"
#include "DS18x20.h"

uint32_t realtimeTDataIndex;
uint32_t realtimePDataIndex;
uint32_t realtimeTPageOfBarCharts;
uint32_t realtimePPageOfBarCharts;
uint32_t realtimeTPageCountOfBarCharts;
uint32_t realtimePPageCountOfBarCharts;
_SensorData SensorData4Save;
//s2-s1
uint32_t GetDeltaTime_Minutes(_SensorData s1,_SensorData s2)
{
	uint32_t ret=0,t1,t2;
	if(s1.Month!=s2.Month)
		return 0xffff;
	t1=s1.Day*24*60+s1.Hour*60+s1.Minute;
	t2=s2.Day*24*60+s2.Hour*60+s2.Minute;
	//t2-t1
	if(t2<t1)
		return 0xffff;
	ret=t2-t1;
	return ret;
}

void WorkMode_RealTimeInit(void)
{
	Wireless_RxInit();	
}

void RealTime_TBarChartsSwitchPage(uint16_t cID)
{
	char str[50];
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
	sprintf(str,"共%u页，第%u页",realtimeTPageCountOfBarCharts,realtimeTPageOfBarCharts+1);
	SetTextValue(5,52,str);
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
	uint8_t rData[50];
	uint8_t t1,t2,x1,x2,x,i,timeInterval;	
	uint32_t addr;
// 	_SensorData sd;
// 	_SensorDataInfo sdInfo;
	ReadRTC();
	SensorData4Save.Month=RTCData.month;
	SensorData4Save.Day=RTCData.day;
	SensorData4Save.Hour=RTCData.hour;
	SensorData4Save.Minute=RTCData.minute;
	SensorData4Save.SensorData=WirelessPacket.SensorData;
	//存储实时数据，若间隔小于2分钟，则不增加，直接替换最后一个
	FRAM_GetSensorDataInfo(TemperatureSensor,WirelessPacket.index-1);
	SensorDataInfo.LastState=WirelessPacket.StateBits.AllFlag;
	if(SensorDataInfo.curDataSaveIndex==0xff)//第一次存储
	{
		SensorDataInfo.curDataSaveIndex=0;
		SensorDataInfo.bLoop=0;
	}
	else//再次存储，则判断存储间隔
	{
		FRAM_GetLatestSensorData(TemperatureSensor,WirelessPacket.index-1);
		timeInterval=GetDeltaTime_Minutes(LatestSensorData,SensorData4Save);
		if(timeInterval>2)//新的存储
		{
			SensorDataInfo.curDataSaveIndex++;
			if(SensorDataInfo.curDataSaveIndex>=SensorDataItemCount)
			{
				SensorDataInfo.bLoop=1;
				SensorDataInfo.curDataSaveIndex=0;
			}
		}
	}
	addr=TSensor1DataAddr+(uint32_t)(WirelessPacket.index-1)*SensorDataListCount;
	SPIROM_WriteArray(addr,SensorDataInfo.All,SensorDataInfoCount);
	addr=TSensor1DataAddr+(uint32_t)(WirelessPacket.index-1)*SensorDataListCount+SensorDataInfoCount+SensorDataInfo.curDataSaveIndex*6;
	SPIROM_WriteArray(addr,SensorData4Save.All,6);
	//处理界面显示
	if(WirelessPacket.StateBits.bTemperature)//温度传感器
	{
		realtimeTDataIndex++;
	}
	else
	{
		realtimePDataIndex++;
	}	
	if(WirelessPacket.StateBits.bTemperature)//温度
	{	
		t1=(WirelessPacket.SensorData&0x0fff)>>4;
		t2=DS18X20_ToDecicel[WirelessPacket.SensorData&0x000f];
		//2实时列表	
		sprintf((char *)rData,"%u;%03u;%02u:%02u:%02u;%u.%u;%u-%u",
			realtimeTDataIndex,WirelessPacket.index,
			RTCData.hour,RTCData.minute,RTCData.second,
			t1,t2,
			SensorDataInfo.Addr1,SensorDataInfo.Addr2);		
		Record_Add(2,cID_Record,rData);
		//4实时温度柱形图
		x=0xff;
		for(i=0;i<TSensorAddrSortingListCount;i++)
		{
			if(TSensorAddrSortingList[i].SensorIndex==WirelessPacket.index)
			{
				x=i;
				break;
			}
		}
		if(x==0xff)//没找到，无法后序处理
			return;
		x1=realtimeTPageOfBarCharts*SensorCountOfBarCharts;
		x2=x1+SensorCountOfBarCharts;
		if((x1<=x) && (x<x2))//在当前显示的页面中
		{
			x2=x-x1;//剩余的数量，即柱形的索引
			if(t2>4)
				t1++;
			SetProgressValue(4,cID_Bar1+x2,t1);
		}
	}
	else
	{
		//等待补充：压力数据的换算方式
		//3实时压力
		sprintf((char *)rData,"%u;%03u;%02u:%02u:%02u;%u.%u;%u-%u",
			realtimePDataIndex,WirelessPacket.index,
			RTCData.hour,RTCData.minute,RTCData.second,
			t1,t2,
			SensorDataInfo.Addr1,SensorDataInfo.Addr2);		
		Record_Add(3,cID_Record,rData);
		//5实时压力柱形图
		x=0xff;
		for(i=0;i<PSensorAddrSortingListCount;i++)
		{
			if(PSensorAddrSortingList[i].SensorIndex==WirelessPacket.index)
			{
				x=i;
				break;
			}
		}
		if(x==0xff)//没找到，无法后序处理
			return;
		x1=realtimePPageOfBarCharts*SensorCountOfBarCharts;
		x2=x1+SensorCountOfBarCharts;
		if((x1<=x) && (x<x2))//在当前显示的页面中
		{
			x2=x-x1;//剩余的数量，即柱形的索引
			if(t2>4)
				t1++;
			SetProgressValue(4,cID_Bar1+x2,t1);
		}
	}
}