#include "Sx1262Proc.h"
#include "sx126x.h"
#include "delay.h"
#include "radio.h"
/*!
* Antenna switch GPIO pins objects
*/
uint8_t gPaOptSetting = 0;

extern void RadioOnDioIrq(void);
uint8_t SpiInOut(uint8_t outData)
{
	uint8_t rxData = 0;
	/* Loop while DR register in not emplty */
	while (SPI_GetFlagStatus(RADIO_SPI_ID, SPI_FLAG_TXE) == RESET);
	/* Send byte through the SPI peripheral */
	SPI_SendData(RADIO_SPI_ID, outData);
	/* Wait to receive a byte */
	while (SPI_GetFlagStatus(RADIO_SPI_ID, SPI_FLAG_RXNE) == RESET);
	/* Return the byte read from the SPI bus */
	rxData = SPI_ReceiveData(RADIO_SPI_ID);
	return(rxData);
}
void SX126xIoInit(void)
{
	GPIO_Init(RADIO_RESET_GPIO_Port, RADIO_RESET_Pin, GPIO_Mode_Out_PP_High_Slow);
	GPIO_Init(RADIO_NSS_GPIO_Port, RADIO_NSS_Pin, GPIO_Mode_Out_PP_High_Slow);
	GPIO_Init(RADIO_BUSY_GPIO_Port, RADIO_BUSY_Pin, GPIO_Mode_In_FL_No_IT);
	GPIO_Init(RADIO_AntPow_GPIO_Port, RADIO_AntPow_Pin, GPIO_Mode_Out_PP_High_Slow);
	GPIO_Init(RADIO_DIO1_GPIO_Port, RADIO_DIO1_Pin, GPIO_Mode_In_PU_IT);
	EXTI_SetPinSensitivity(EXTI_Pin_2, EXTI_Trigger_Rising);

	CLK_PeripheralClockConfig(CLK_Peripheral_SPI2, ENABLE);
	GPIO_ExternalPullUpConfig(RADIO_SCLK_GPIO_Port, RADIO_MOSI_Pin | RADIO_MISO_Pin | RADIO_SCLK_Pin, DISABLE);
	SYSCFG_REMAPPinConfig(REMAP_Pin_SPI2Full, ENABLE);
	SPI_Init(RADIO_SPI_ID, SPI_FirstBit_MSB, SPI_BaudRatePrescaler_32, SPI_Mode_Master,
		SPI_CPOL_Low, SPI_CPHA_1Edge, SPI_Direction_2Lines_FullDuplex,
		SPI_NSS_Soft, 0x07);
	SPI_Cmd(RADIO_SPI_ID, ENABLE);
	//SX126xIoIrqInit(RadioOnDioIrq);
}

// void SX126xIoIrqInit(DioIrqHandler dioIrq)
// {
// 	GpioSetInterrupt(&SX126x.DIO1, IRQ_RISING_EDGE, IRQ_HIGH_PRIORITY, dioIrq);
// }

void SX126xIoDeInit(void)
{
// 	GpioInit(&SX126x.Spi.Nss, RADIO_NSS, PIN_OUTPUT, PIN_PUSH_PULL, PIN_PULL_UP, 1);
// 	GpioInit(&SX126x.BUSY, RADIO_BUSY, PIN_INPUT, PIN_PUSH_PULL, PIN_PULL_UP, 1);
// 	GpioInit(&SX126x.DIO1, RADIO_DIO_1, PIN_OUTPUT, PIN_PUSH_PULL, PIN_NO_PULL, 0);
}

uint32_t SX126xGetBoardTcxoWakeupTime(void)
{
	return BOARD_TCXO_WAKEUP_TIME;
}

void SX126xReset(void)
{
	DelayMs(20);
	GPIO_WriteBit(RADIO_RESET_GPIO_Port, RADIO_RESET_Pin, RESET);
	DelayMs(40);
	GPIO_WriteBit(RADIO_RESET_GPIO_Port, RADIO_RESET_Pin, SET);
	DelayMs(20);
}

void SX126xWaitOnBusy(void)
{
	//   printf("SX126X is busy!\r\n");
	while (GPIO_ReadInputDataBit(RADIO_BUSY_GPIO_Port, RADIO_BUSY_Pin) != RESET);
	//    printf("SX126X is  not busy !\r\n");
}

void SX126xWakeup(void)
{
	disableInterrupts();
	GPIO_WriteBit(RADIO_NSS_GPIO_Port, RADIO_NSS_Pin, RESET);
	SpiInOut(RADIO_GET_STATUS);
	SpiInOut(0x00);
	GPIO_WriteBit(RADIO_NSS_GPIO_Port, RADIO_NSS_Pin, SET);
	// Wait for chip to be ready.
	SX126xWaitOnBusy();
	enableInterrupts();
}

void SX126xWriteCommand(RadioCommands_t command, uint8_t *buffer, uint16_t size)
{
	uint16_t i;
	SX126xCheckDeviceReady();
	GPIO_WriteBit(RADIO_NSS_GPIO_Port, RADIO_NSS_Pin, RESET);
	SpiInOut((uint8_t)command);
	for (i = 0; i < size; i++)
	{
		SpiInOut(buffer[i]);
	}
	GPIO_WriteBit(RADIO_NSS_GPIO_Port, RADIO_NSS_Pin, SET);
	if (command != RADIO_SET_SLEEP)
	{
		SX126xWaitOnBusy();
	}
}

void SX126xReadCommand(RadioCommands_t command, uint8_t *buffer, uint16_t size)
{
	uint16_t i;
	SX126xCheckDeviceReady();

	GPIO_WriteBit(RADIO_NSS_GPIO_Port, RADIO_NSS_Pin,RESET);

	SpiInOut((uint8_t)command);
	SpiInOut(0x00);
	for (i = 0; i < size; i++)
	{
		buffer[i] = SpiInOut(0);
	}
	GPIO_WriteBit(RADIO_NSS_GPIO_Port, RADIO_NSS_Pin, SET);
	SX126xWaitOnBusy();
}

void SX126xWriteRegisters(uint16_t address, uint8_t *buffer, uint16_t size)
{
	uint16_t i;
	SX126xCheckDeviceReady();
	GPIO_WriteBit(RADIO_NSS_GPIO_Port, RADIO_NSS_Pin, RESET);
	SpiInOut(RADIO_WRITE_REGISTER);
	SpiInOut((address & 0xFF00) >> 8);
	SpiInOut(address & 0x00FF);
	for (i = 0; i < size; i++)
	{
		SpiInOut(buffer[i]);
	}
	GPIO_WriteBit(RADIO_NSS_GPIO_Port, RADIO_NSS_Pin, SET);
	SX126xWaitOnBusy();
}

void SX126xWriteRegister(uint16_t address, uint8_t value)
{
	SX126xWriteRegisters(address, &value, 1);
}

void SX126xReadRegisters(uint16_t address, uint8_t *buffer, uint16_t size)
{
	uint16_t i;
	SX126xCheckDeviceReady();
	GPIO_WriteBit(RADIO_NSS_GPIO_Port, RADIO_NSS_Pin, RESET);
	SpiInOut(RADIO_READ_REGISTER);
	SpiInOut((address & 0xFF00) >> 8);
	SpiInOut(address & 0x00FF);
	SpiInOut(0);
	for (i = 0; i < size; i++)
	{
		buffer[i] = SpiInOut(0);
	}
	GPIO_WriteBit(RADIO_NSS_GPIO_Port, RADIO_NSS_Pin, SET);
	SX126xWaitOnBusy();
}

uint8_t SX126xReadRegister(uint16_t address)
{
	uint8_t data;
	SX126xReadRegisters(address, &data, 1);
	return data;
}

void SX126xWriteBuffer(uint8_t offset, uint8_t *buffer, uint8_t size)
{
	uint16_t i;
	SX126xCheckDeviceReady();
	GPIO_WriteBit(RADIO_NSS_GPIO_Port, RADIO_NSS_Pin, RESET);
	SpiInOut(RADIO_WRITE_BUFFER);
	SpiInOut(offset);
	for (i = 0; i < size; i++)
	{
		SpiInOut(buffer[i]);
	}
	GPIO_WriteBit(RADIO_NSS_GPIO_Port, RADIO_NSS_Pin, SET);
	SX126xWaitOnBusy();
}

void SX126xReadBuffer(uint8_t offset, uint8_t *buffer, uint8_t size)
{
	uint16_t i;
	SX126xCheckDeviceReady();
	GPIO_WriteBit(RADIO_NSS_GPIO_Port, RADIO_NSS_Pin, RESET);

	SpiInOut(RADIO_READ_BUFFER);
	SpiInOut(offset);
	SpiInOut(0);
	for (i = 0; i < size; i++)
	{
		buffer[i] = SpiInOut(0);
	}
	GPIO_WriteBit(RADIO_NSS_GPIO_Port, RADIO_NSS_Pin, SET);
	SX126xWaitOnBusy();
}

void SX126xSetRfTxPower(int8_t power)
{
	SX126xSetTxParams(power, RADIO_RAMP_40_US);
}

uint8_t SX126xGetPaSelect(uint32_t channel)
{
	return SX1262;
}

void SX126xAntSwOn(void)
{
	GPIO_WriteBit(RADIO_AntPow_GPIO_Port, RADIO_AntPow_Pin, RESET);
}

void SX126xAntSwOff(void)
{
	GPIO_WriteBit(RADIO_AntPow_GPIO_Port, RADIO_AntPow_Pin, SET);
}

bool SX126xCheckRfFrequency(uint32_t frequency)
{
	// Implement check. Currently all frequencies are supported
	return true;
}

uint8_t SX126xGetPaOpt()
{
	return gPaOptSetting;
}

void SX126xSetPaOpt(uint8_t opt)
{
	if (opt>3) 
		return;
	gPaOptSetting = opt;
}
