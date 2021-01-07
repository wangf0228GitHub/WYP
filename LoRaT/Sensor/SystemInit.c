#include "HardwareProfile.h"
#include "stm8l15x_gpio.h"
#include "stm8l15x_clk.h"
#include "stm8l15x_usart.h"
static bool McuInitialized = false;
void SystemInit(void)
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

	SX126xIoInit();
	SpiInit(&SX126x.Spi, RADIO_SPI_ID, RADIO_MOSI, RADIO_MISO, RADIO_SCLK, NC/*RADIO_NSS*/);
}


