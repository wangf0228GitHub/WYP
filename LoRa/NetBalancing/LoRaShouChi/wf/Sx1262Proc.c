#include "Sx1262Proc.h"
#include "gpio.h"
#include "spi.h"
#include "sx126x.h"
/*!
* Antenna switch GPIO pins objects
*/
uint8_t gPaOptSetting = 0;

void SX126xIoInit(void)
{
	//SX126xIoIrqInit(RadioOnDioIrq);
}


void SX126xIoDeInit(void)
{

}

uint32_t SX126xGetBoardTcxoWakeupTime(void)
{
	return BOARD_TCXO_WAKEUP_TIME;
}

void SX126xReset(void)
{
	HAL_Delay(20);
	HAL_GPIO_WritePin(RADIO_RESET_GPIO_Port, RADIO_RESET_Pin, GPIO_PIN_RESET);
	HAL_Delay(40);
	HAL_GPIO_WritePin(RADIO_RESET_GPIO_Port, RADIO_RESET_Pin, GPIO_PIN_SET);
	HAL_Delay(20);
}

void SX126xWaitOnBusy(void)
{
	//   printf("SX126X is busy!\r\n");
	while (HAL_GPIO_ReadPin(RADIO_BUSY_GPIO_Port, RADIO_BUSY_Pin) != GPIO_PIN_RESET);
	//    printf("SX126X is  not busy !\r\n");
}

void SX126xWakeup(void)
{
	uint8_t tx[2];
	__disable_irq();
	HAL_GPIO_WritePin(RADIO_NSS_GPIO_Port, RADIO_NSS_Pin, GPIO_PIN_RESET);
	tx[0] = RADIO_GET_STATUS;
	tx[1] = 0x00;
	HAL_SPI_Transmit(&hspi2, tx, 2, 1000);
	HAL_GPIO_WritePin(RADIO_NSS_GPIO_Port, RADIO_NSS_Pin, GPIO_PIN_SET);
	// Wait for chip to be ready.
	SX126xWaitOnBusy();
	__enable_irq();
}

void SX126xWriteCommand(RadioCommands_t command, uint8_t *buffer, uint16_t size)
{
	SX126xCheckDeviceReady();
	HAL_GPIO_WritePin(RADIO_NSS_GPIO_Port, RADIO_NSS_Pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi2, &command, 1, 1000);
	HAL_SPI_Transmit(&hspi2, buffer, size, 1000);
	HAL_GPIO_WritePin(RADIO_NSS_GPIO_Port, RADIO_NSS_Pin, GPIO_PIN_SET);
	if (command != RADIO_SET_SLEEP)
	{
		SX126xWaitOnBusy();
	}
}

void SX126xReadCommand(RadioCommands_t command, uint8_t *buffer, uint16_t size)
{
	uint8_t tx[2];
	SX126xCheckDeviceReady();
	tx[0] = command;
	tx[1] = 0x00;
	HAL_GPIO_WritePin(RADIO_NSS_GPIO_Port, RADIO_NSS_Pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi2,tx, 2, 1000);
	HAL_SPI_TransmitReceive(&hspi2, buffer,buffer, size, 1000);
	HAL_GPIO_WritePin(RADIO_NSS_GPIO_Port, RADIO_NSS_Pin, GPIO_PIN_SET);
	SX126xWaitOnBusy();
}

void SX126xWriteRegisters(uint16_t address, uint8_t *buffer, uint16_t size)
{
	uint8_t tx[3];
	SX126xCheckDeviceReady();
	HAL_GPIO_WritePin(RADIO_NSS_GPIO_Port, RADIO_NSS_Pin, GPIO_PIN_RESET);
	tx[0]=RADIO_WRITE_REGISTER;
	tx[1]=((address & 0xFF00) >> 8);
	tx[2]=(address & 0x00FF);
	HAL_SPI_Transmit(&hspi2, tx, 3, 1000);
	HAL_SPI_Transmit(&hspi2, buffer, size, 1000);
	HAL_GPIO_WritePin(RADIO_NSS_GPIO_Port, RADIO_NSS_Pin, GPIO_PIN_SET);
	SX126xWaitOnBusy();
}

void SX126xWriteRegister(uint16_t address, uint8_t value)
{
	SX126xWriteRegisters(address, &value, 1);
}

void SX126xReadRegisters(uint16_t address, uint8_t *buffer, uint16_t size)
{
	uint8_t tx[4];
	SX126xCheckDeviceReady();
	HAL_GPIO_WritePin(RADIO_NSS_GPIO_Port, RADIO_NSS_Pin, GPIO_PIN_RESET);
	tx[0] = RADIO_READ_REGISTER;
	tx[1] = ((address & 0xFF00) >> 8);
	tx[2] = (address & 0x00FF);
	tx[3] = 0;
	HAL_SPI_TransmitReceive(&hspi2, buffer, buffer, size, 1000);
	HAL_GPIO_WritePin(RADIO_NSS_GPIO_Port, RADIO_NSS_Pin, GPIO_PIN_SET);
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
	uint8_t tx[2];
	SX126xCheckDeviceReady();
	HAL_GPIO_WritePin(RADIO_NSS_GPIO_Port, RADIO_NSS_Pin, GPIO_PIN_RESET);
	tx[0]=RADIO_WRITE_BUFFER;
	tx[1]=offset;
	HAL_SPI_Transmit(&hspi2, tx, 2, 1000);
	HAL_SPI_Transmit(&hspi2, buffer, size, 1000);
	HAL_GPIO_WritePin(RADIO_NSS_GPIO_Port, RADIO_NSS_Pin, GPIO_PIN_SET);
	SX126xWaitOnBusy();
}

void SX126xReadBuffer(uint8_t offset, uint8_t *buffer, uint8_t size)
{
	uint8_t tx[3];
	SX126xCheckDeviceReady();
	HAL_GPIO_WritePin(RADIO_NSS_GPIO_Port, RADIO_NSS_Pin, GPIO_PIN_RESET);

	tx[0]=RADIO_READ_BUFFER;
	tx[1]=offset;
	tx[2]=0;
	HAL_SPI_Transmit(&hspi2, tx, 3, 1000);
	HAL_SPI_TransmitReceive(&hspi2, buffer, buffer,size, 1000);
	HAL_GPIO_WritePin(RADIO_NSS_GPIO_Port, RADIO_NSS_Pin, GPIO_PIN_SET);
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
	
}

void SX126xAntSwOff(void)
{
	
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
