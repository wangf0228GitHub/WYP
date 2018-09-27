#ifndef __WorkMode_History_H__
#define __WorkMode_History_H__

#include "main.h"
#include "TypeDefine.h"
#define History_PageSize 10
#define History_PageCount 21
#define SensorDataMaxCount 210

extern _SensorData SensorData4ShowList[History_PageSize];
extern uint8_t History_SensorIndex;
extern uint8_t History_ListCount;
extern uint8_t History_curPageCount;
extern uint8_t History_Page;
#endif
