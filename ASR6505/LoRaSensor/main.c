#include "HardwareProfile.h"
#include "TMRList.h"
#include "radio.h"
#include "LoraProc.h"
#include "eeprom.h"
#include "DS18x20.h"
#include "wfDefine.h"
#include <stdlib.h>
void SystemInit(void);
void Wait4Setting(void);
void LowPowerDelayS(uint8_t Ns);
int main( void )
{
	halt();
	SystemInit();
	Wait4Setting();
	RadioSetChannel(RFChannel[ROMParams.WirelessParamIndex+1]);
	RadioSleep();
	switch (SystemState)
	{
	case 0://该启动采集温度了
		PickDatas.StateBits.bMove = bDeviceMove();
		while (CLK_GetFlagStatus(CLK_FLAG_HSIRDY) == RESET);//等待时钟稳定
		if (DS18X20_StartMeas() == DS18X20_ERROR)//18b20无法复位
		{
			PickDatas.T1 = 0xffff;
			ErrT++;
			if (ErrT > ErrT_Max)
			{
				ErrT = 100;
				PickDatas.StateBits.bBreak = 1;
				SystemState = 2;//发送
			}
		}
		else
		{
			ErrT = 0;
			SystemState = 1;
			LowPowerDelayS(1);//1s			
		}
		break;
	case 1://该采集温度了
		while (CLK_GetFlagStatus(CLK_FLAG_HSIRDY) == RESET);//等待时钟稳定
		DS18b20Retry = 3;
		PickDatas.T1 = 0xffff;
		PickDatas.StateBits.bBreak = 1;
		while (DS18b20Retry != 0)
		{
			DS18b20Retry--;
			if (DS18X20_ReadMeas(1) == DS18X20_ERROR)//读数错误
			{
				continue;
			}
			else
			{
				ErrT = 0;
				PickDatas.StateBits.bBreak = 0;
				PickDatas.T1 = MAKE_SHORT(DS18X20_Scratchpad[1], DS18X20_Scratchpad[0]);
				break;
			}
		}
		if (PickDatas.StateBits.bBreak)
		{
			PickDatas.StateBits.bBreak = 0;
			ErrT++;
			if (ErrT > ErrT_Max)
			{
				ErrT = 100;
				PickDatas.T1 = 0xffff;
				PickDatas.StateBits.bBreak = 1;
			}
		}
		SystemState = 2;//发送
		break;
	case 2://发送	
		RadioStandby();
		PickDatas.sum = GetVerify_Sum(PickDatas.All, PACKET_LENGTH - 1);
		TxRetry = 3;
		while (TxRetry!=0)
		{
			radioStates = Wait4RadioEvent;
			RadioSend(PickDatas.All, PACKET_LENGTH);//发送完成休眠
			while (true)
			{
				wfi();
				if (radioStates != Wait4RadioEvent)
					break;
			}
			if (radioStates == RadioStates_TxDone)
			{
				break;
			}
			TxRetry--;
		}
		RadioSleep();
		SystemState = 0;
		PickGap = 30 + (rand() % 60);
		//__delay_20ms(200);
		LowPowerDelayS(PickGap);
		//GotoSleep_Minute(ROMParams.PickCycle);//10m
		// 				n=rand()%1200;
		// 				n=n<<2;
		// 				GotoSleep(n);
		break;
	default:
		break;
	}
	return 0;
}
void Wait4Setting(void)
{	
	while(true)
	{
		RadioRx(1000);
		radioStates = Wait4RadioEvent;
		while (true)
		{			
			wfi();
			if (radioStates != Wait4RadioEvent)
				break;
		}
		switch (radioStates)
		{
		case RadioStates_RxTimeout:
			return;
		case RadioStates_RxDone:
			PickDatas.All[0] = LoRaRxList[0];//
			PickDatas.All[1] = 0;//tx[1];	
			PickDatas.All[2] = 'o';
			PickDatas.All[3] = 'k';
			PickDatas.sum = GetVerify_Sum(PickDatas.All, PACKET_LENGTH - 1);
			ROMParams.MyAddr = LoRaRxList[0];
			ROMParams.WirelessParamIndex = 0;//tx[1];
			SaveRomData();
			if (GetRomData() != 0)
			{
				RadioSend(PickDatas.All, PACKET_LENGTH);
				radioStates = Wait4RadioEvent;
				while (radioStates == Wait4RadioEvent);
				if (radioStates == RadioStates_TxDone)
					return;
				else
					break;//发送失败了，再次进入接收
			}
		default:
			return;
		}
	}
}
void LowPowerDelayS(uint8_t Ns)
{
	uint16_t rtcwakeup;
#ifdef Debug 
	__delay_20ms(5);
#else
	rtcwakeup = Ns * 150;
	RTC_SetWakeUpCounter(rtcwakeup);
	RTC_WakeUpCmd(ENABLE);
	halt();
	while (RTC_WakeUpCmd(DISABLE) == ERROR);
#endif

}