#include "HardwareProfile.h"
#include "LoraProc.h"
#include "TMRList.h"
#include "eeprom.h"
void LoRaTest(void);
void MCUInit(void)
{
	CFG->GCR |= CFG_GCR_SWD;//禁止调试
	disableInterrupts();
	CLK_SYSCLKDivConfig(CLK_SYSCLKDiv_1);//16MHz

	CLK_PeripheralClockConfig(CLK_Peripheral_TIM4, ENABLE);//延时用定时器
	/************************************************************************/
	/* 低功耗处理                                                           */
	/************************************************************************/
	PWR_FastWakeUpCmd(ENABLE);
	PWR_UltraLowPowerCmd(ENABLE);
	CLK_RTCClockConfig(CLK_RTCCLKSource_LSI, CLK_RTCCLKDiv_16);
	CLK_PeripheralClockConfig(CLK_Peripheral_RTC, ENABLE);
	RTC_ITConfig(RTC_IT_WUT, ENABLE);
	RTC_WakeUpClockConfig(RTC_WakeUpClock_RTCCLK_Div16);//Prec1*Prec2/fLSI	16*16/38000
	/************************************************************************/
	/* GPIO 初始化	                                                        */
	/************************************************************************/
	GPIO_Init(DS18B20_GPIO_Port, DS18B20_Pin, GPIO_Mode_In_FL_No_IT);
	GPIO_Init(Move_GPIO_Port, Move_Pin, GPIO_Mode_In_FL_No_IT);
	enableInterrupts();
}
void InitVariable(void)
{
	gFlags.AllFlag = 0;
	//	SystemTick=0;
	PickDatas.T1 = 0xffff;

	if (GetRomData() == 0)
	{
		ROMParams.MyAddr = 0x01;
		ROMParams.WirelessPowerLevel = 4;
		ROMParams.WirelessParamIndex = 0;
		//
		ROMParams.SystemState.bWinter = 1;
		ROMParams.PickCycle = 1;
		SaveRomData();
	}
	PickDatas.index = ROMParams.MyAddr;
	SystemState = 0;
}
void SystemInit(void)
{
	MCUInit();	
	InitVariable();
	TmrListInit();
	LoRaTest();	
	LoRaProc_Init();
	//SpiInit(&SX126x.Spi, RADIO_SPI_ID, RADIO_MOSI, RADIO_MISO, RADIO_SCLK, NC/*RADIO_NSS*/);
}


