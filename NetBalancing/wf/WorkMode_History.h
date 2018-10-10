#ifndef __WorkMode_History_H__
#define __WorkMode_History_H__

#include "main.h"
#include "TypeDefine.h"
#define History_PageSize 10
#define History_PageCount 21
#define SensorDataMaxCount 210

extern uint32_t History_TSensorIndex;
extern uint32_t History_PSensorIndex;
extern uint32_t History_TSensorDataItemCount;
extern uint32_t History_PSensorDataItemCount;
extern uint32_t History_TPageOfBarCharts;
extern uint32_t History_PPageOfBarCharts;
extern uint32_t History_TPageCountOfBarCharts;
extern uint32_t History_PPageCountOfBarCharts;

void HistoryModeInit(void);
void History_TBarChartsSwitchPage(uint16_t cID);
#endif
