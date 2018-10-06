#ifndef __FRAM_h__
#define __FRAM_h__

#include "main.h"
extern _ROMParams ROMParams;
extern _SensorDataInfo SensorDataInfo;
extern _SensorAddrInfo TSensorAddrList[SensorDataItemCount];
extern _SensorAddrInfo PSensorAddrList[SensorDataItemCount];
extern _SensorAddrSortingInfo TSensorAddrSortingList[SensorDataItemCount];
extern _SensorAddrSortingInfo PSensorAddrSortingList[SensorDataItemCount];
extern uint8_t realTSensorCount;
extern uint8_t realPSensorCount;
extern uint8_t TSensorAddrSortingListCount;
extern uint8_t PSensorAddrSortingListCount;
void FRAM_SaveROMParams(void);
void FRAM_GetROMParams(void);
void FRAM_InitSensorData(uint8_t startIndex,uint8_t endIndex);
void FRAM_InitSensorAddrInfo(void);
void FRAM_SaveSensorData(void);
void FRAM_GetSensorDataInfo(uint8_t index);
void FRAM_GetSensorData(uint8_t index,uint8_t* pBuf);
void FRAM_SaveSensorAddr(uint8_t index,uint8_t* pBuff,uint8_t Count);
void FRAM_HistoryGetPageSensorData();
#endif


