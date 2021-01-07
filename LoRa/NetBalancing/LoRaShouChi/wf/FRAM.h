#ifndef FRAM_h__
#define FRAM_h__

#include "HardwareProfile.h"

uint8_t SPI_Proc(uint8_t outData);
#define SPIROM_SPIProc(x) SPI_Proc(x)
#define SPIROM_Addr24
#define SPIROM_CS_Low() HAL_GPIO_WritePin(F_CS_GPIO_Port,F_CS_Pin,GPIO_PIN_RESET)
#define SPIROM_CS_High() HAL_GPIO_WritePin(F_CS_GPIO_Port,F_CS_Pin,GPIO_PIN_SET)
#include "SPIROM.h"

void FRAM_Init(void);
void FRAM_SaveROMParams(void);
void FRAM_GetROMParams(void);
void FRAM_InitSensorData(uint8_t s, uint8_t e);
void FRAM_SaveSensorData(void);
void FRAM_GetSensorDataInfo(uint8_t index);
void FRAM_SaveSensorAddr(uint8_t index, uint8_t* pBuff, uint8_t Count);
void FRAM_GetSensorData(uint8_t index, uint8_t* pBuf);
void FRAM_HistoryGetPageSensorData();
#endif // FRAM_h__
