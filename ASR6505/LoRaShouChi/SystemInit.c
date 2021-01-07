#include "HardwareProfile.h"
#include "LoraProc.h"
#include "TMRList.h"
#include "FRAM.h"
#include "DS1302.h"
#include "CP1616_Client.h"
void MCUInit(void)
{
	CFG->GCR |= CFG_GCR_SWD;//禁止调试
	disableInterrupts();
	CLK_SYSCLKDivConfig(CLK_SYSCLKDiv_1);//16MHz

	CLK_PeripheralClockConfig(CLK_Peripheral_TIM4, ENABLE);//延时用定时器
	/************************************************************************/
	/* 串口1                                                                */
	/************************************************************************/
	CLK_PeripheralClockConfig(CLK_Peripheral_USART3, ENABLE);
	GPIO_ExternalPullUpConfig(GPIOG, GPIO_Pin_1, ENABLE);
	GPIO_ExternalPullUpConfig(GPIOG, GPIO_Pin_0, ENABLE);
	USART_Init(USART3,
		(uint32_t)115200,
		USART_WordLength_8b,
		USART_StopBits_1,
		USART_Parity_No,
		(USART_Mode_TypeDef)(USART_Mode_Tx | USART_Mode_Rx));
	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
	/* Enable USART */
	USART_Cmd(USART3, ENABLE);
	/************************************************************************/
	/* 定时器队列初始化                                                      */
	/************************************************************************/
	TmrListInit();
	CLK_PeripheralClockConfig(CLK_Peripheral_TIM3, ENABLE);/*0.008ms*/
	TIM3_TimeBaseInit(TIM3_Prescaler_128, TIM3_CounterMode_Up, 1250);/*10ms*/
	TIM3_ITConfig(TIM3_IT_Update, ENABLE);
	TIM3_ARRPreloadConfig(ENABLE);
	TIM3_SetCounter(0);
	TIM3_Cmd(ENABLE);

	/************************************************************************/
	/* GPIO 初始化	                                                        */
	/************************************************************************/
	GPIO_Init(DS1302_DATA_GPIO_Port, DS1302_DATA_Pin, GPIO_Mode_Out_PP_Low_Slow);
	GPIO_Init(DS1302_CLK_GPIO_Port, DS1302_CLK_Pin, GPIO_Mode_Out_PP_Low_Slow);
	GPIO_Init(DS1302_RST_GPIO_Port, DS1302_RST_Pin, GPIO_Mode_Out_PP_Low_Slow);
}
void SystemInit(void)
{
	MCUInit();	
	LoRaProc_Init();
	FRAM_Init();
	DS1302_Init();
	DS1302_Switch(1);
	DS1302_SetHour24(1);
	DS1302_GetTime();

	CP1616_Client_Init();
	CP1616_Client_Addr = 0x0001;
	//SpiInit(&SX126x.Spi, RADIO_SPI_ID, RADIO_MOSI, RADIO_MISO, RADIO_SCLK, NC/*RADIO_NSS*/);
}


