#include "Variables.h"

_GFlags gFlags;
_PickDatas PickDatas;
_ROMParams ROMParams;

_SensorData SensorData4Save;
_SensorData SensorData4Get;
_SensorDataInfo SensorDataInfo;


uint8_t KeyValue;
/************************************************************************/
/* 历史数据查询                                                         */
/************************************************************************/
_SensorData SensorData4ShowList[History_PageSize];
uint8_t History_SensorIndex;
uint8_t History_ListCount;
uint8_t History_curPageCount;
uint8_t History_Page;


