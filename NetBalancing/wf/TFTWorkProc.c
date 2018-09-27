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
	uint8_t t1,t2;
	t1=(PickDatas.SensorData&0x0fff)>>4;
	t2=PickDatas.SensorData&0x000f;
	if(PickDatas.StateBits.bTemperature)//温度
	{
		FRAM_GetSensorDataInfo(PickDatas.index);
		sprintf(rData,"%u;%03u;%02u:%02u:%02u;%u.%u;%s",
			rtDataIndex,PickDatas.index,
			RTCData.hour,RTCData.minute,RTCData.second,
			t1,DS18X20_ToDecicel[t2],
			SensorDataInfo.InstallPosition);
		//2实时列表
		Record_Add(2,cID_Record,rData);
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
