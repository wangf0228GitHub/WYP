#include "TFTWorkProc.h"
#include "..\VisualTFT\hmi_driver.h"
#include "..\WirelessProc.h"
#include "FlagDefine.h"
#include "DS18x20.h"
#include "FRAM.h"
#include "WorkMode_RealTime.h"

_RTCData RTCData;
uint32_t WaitTFTTick;
void ReadRTC(void)
{
	uint32_t retry=3;
	while(retry!=0)
	{
		gFlags.bRxRTC=0;
		GetRTC();
		WaitTFTTick=HAL_GetTick();
		while(1)
		{
			if(GetDeltaTick(WaitTFTTick)>1000)
				break;
			if(gFlags.bRxRTC)
				return;
		}
	}
}
void TFT_NewSensorDataProc(void)
{		
	uint8_t rData[50];
	uint8_t t1,t2,x1,x2,x,i;	
	if(WirelessPacket.StateBits.bTemperature)//温度
	{	
		t1=(WirelessPacket.SensorData&0x0fff)>>4;
		t2=WirelessPacket.SensorData&0x000f;
		//2实时列表	
		sprintf(rData,"%u;%03u;%02u:%02u:%02u;%u.%u;%u-%u",
			realtimeTDataIndex,WirelessPacket.index,
			RTCData.hour,RTCData.minute,RTCData.second,
			t1,DS18X20_ToDecicel[t2],
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
			if(t2>8)
				t1++;
			SetProgressValue(4,cID_Bar1+x2,t1);
		}
	}
	else
	{
		//等待补充：压力数据的换算方式
		//3实时压力
		sprintf(rData,"%u;%03u;%02u:%02u:%02u;%u.%u;%u-%u",
			realtimePDataIndex,WirelessPacket.index,
			RTCData.hour,RTCData.minute,RTCData.second,
			t1,DS18X20_ToDecicel[t2],
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
			if(t2>8)
				t1++;
			SetProgressValue(4,cID_Bar1+x2,t1);
		}
	}
}
uint32_t JumpButtonProc(uint16_t control_id)
{
	switch(control_id)
	{
	case 1://返回
		WirelessOff();
		break;
	case 4://实时数据
		SetScreen(2);//切换显示到实时数据采集页面
		Wireless_RxInit();//启动接收
		Record_Clear(2,cID_Record);
		break;
	case 5://历史数据
		WirelessOff();
		break;
	case 6://分析诊断
		WirelessOff();
		break;
	case 7://间隔分析
		WirelessOff();
		break;
	case 8://系统设置
		WirelessOff();
		break;
	case 11://操作说明
		WirelessOff();
		break;
	default:
		return 0;
	}
	return 1;
}
