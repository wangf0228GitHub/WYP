#include "TFTWorkProc.h"
#include "..\VisualTFT\hmi_driver.h"
#include "..\WirelessProc.h"
#include "FlagDefine.h"
#include "DS18x20.h"
#include "FRAM.h"
#include "WorkMode_RealTime.h"
#include "cmd_process.h"

uint32_t autoReturnSID;
_RTCData RTCData;
uint32_t WaitTFTTick;
_TFTNotifyCommandFlags TFTNotifyCommandFlags; 
_TFTWaitCommandFlags TFTWaitCommandFlags;
uint32_t ReadTextbox(unsigned char sID,unsigned char cID)
{
	uint32_t retry=3;
	uint8_t i;
	while(retry!=0)
	{
		TFTWaitCommandFlags.bWaitControlValue=1;
		TFTNotifyCommandFlags.bRxControlValue=0;
		waitSID=sID;
		waitCID=cID;
		GetControlValue(sID,cID);
		WaitTFTTick=HAL_GetTick();
		while(1)
		{
			if(GetDeltaTick(WaitTFTTick)>1000)
				break;
			if(TFTNotifyCommandFlags.bRxControlValue)
			{
					return 1;
			}
		}
	}
	return 0;
}

void ReadRTC(void)
{
	uint32_t retry=3;
	while(retry!=0)
	{
		TFTWaitCommandFlags.bWaitRTC=1;
		TFTNotifyCommandFlags.bRxRTC=0;
		GetRTC();
		WaitTFTTick=HAL_GetTick();
		while(1)
		{
			if(GetDeltaTick(WaitTFTTick)>1000)
				break;
			if(TFTNotifyCommandFlags.bRxRTC)
				return;
		}
	}
}
void ShowFailDialog(uint32_t returnSID,uint8_t* str)
{
	autoReturnSID=returnSID;
	SeTimer(sID_Fail,cID_Timer,5);
	StartTimer(sID_Fail,cID_Timer);
	SetTextValue(sID_Fail,50,str);
	SetScreen(sID_Fail);
}
void ShowSuccessDialog(uint32_t returnSID)
{
	autoReturnSID=returnSID;
	SeTimer(sID_Success,cID_Timer,5);
	StartTimer(sID_Success,cID_Timer);
	SetScreen(sID_Success);
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
