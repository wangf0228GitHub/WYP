#ifndef   __Variables_h__
#define   __Variables_h__

#include "HardwareProfile.h"

extern _PickDatas PickDatas;
extern _ROMParams ROMParams;
extern _SensorData SensorData4Save;
extern _SensorData SensorData4Get;
extern _SensorDataInfo SensorDataInfo;

#define History_PageSize 10
#define History_PageCount 21
#define SensorDataMaxCount 210
/************************************************************************/
/* 历史数据查询                                                         */
/************************************************************************/
extern _SensorData SensorData4ShowList[History_PageSize];
extern uint8_t History_SensorIndex;
extern uint8_t History_ListCount;
extern uint8_t History_curPageCount;
extern uint8_t History_Page;
#endif
