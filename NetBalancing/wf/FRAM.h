#ifndef __FRAM_h__
#define __FRAM_h__

#include "main.h"

extern _SensorDataInfo SensorDataInfo;

void FRAM_SaveROMParams(void);
void FRAM_GetROMParams(void);
void FRAM_InitSensorData(uint8_t s,uint8_t e);
void FRAM_SaveSensorData(void);
void FRAM_GetSensorDataInfo(uint8_t index);
void FRAM_GetSensorData(uint8_t index,uint8_t* pBuf);
void FRAM_SaveSensorAddr(uint8_t index,uint8_t* pBuff,uint8_t Count);
void FRAM_HistoryGetPageSensorData();
#endif


