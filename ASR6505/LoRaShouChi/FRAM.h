#ifndef FRAM_h__
#define FRAM_h__

#include "HardwareProfile.h"
#define SimSPI
#define SimSPI_SPI0
#define SIMSPI_SCL_Low() GPIO_WriteBit(F_SCK_GPIO_Port,F_SCK_Pin,RESET)
#define SIMSPI_SCL_High() GPIO_WriteBit(F_SCK_GPIO_Port,F_SCK_Pin,SET)

#define SIMSPI_SDO_Low() GPIO_WriteBit(F_MISO_GPIO_Port,F_MISO_Pin,RESET)
#define SIMSPI_SDO_High() GPIO_WriteBit(F_MISO_GPIO_Port,F_MISO_Pin,SET)

#define SIMSPI_SDI_Read() (uint8_t)(GPIO_ReadInputDataBit(F_MOSI_GPIO_Port,F_MOSI_Pin))
#include "SimSPI.h"
#define SPIROM_SPIProc(x) SimSPI_Proc(x)
#define SPIROM_Addr24

#define SPIROM_CS_Low() GPIO_WriteBit(F_CS_GPIO_Port,F_CS_Pin,RESET)
#define SPIROM_CS_High() GPIO_WriteBit(F_CS_GPIO_Port,F_CS_Pin,SET)
#include "SPIROM.h"
void FRAM_Init(void);
void FRAM_SaveROMParams(void);
void FRAM_GetROMParams(void);
void FRAM_InitSensorData(unsigned char s, unsigned char e);
void FRAM_SaveSensorData(void);
void FRAM_GetSensorDataInfo(unsigned char index);
void FRAM_SaveSensorAddr(unsigned char index, unsigned char* pBuff, unsigned char Count);
void FRAM_GetSensorData(unsigned char index, unsigned char* pBuf);
void FRAM_HistoryGetPageSensorData();
#endif // FRAM_h__
