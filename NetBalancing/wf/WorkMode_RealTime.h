#ifndef __WorkMode_RealTime_H__
#define __WorkMode_RealTime_H__

#include "main.h"
#include "TypeDefine.h"

#define SensorCountOfBarCharts 20

extern uint32_t realtimeTDataIndex;
extern uint32_t realtimePDataIndex;

extern uint32_t realtimeTPageOfBarCharts;
extern uint32_t realtimePPageOfBarCharts;
extern uint32_t realtimeTPageCountOfBarCharts;
extern uint32_t realtimePPageCountOfBarCharts;
extern _SensorData SensorData4Save;
void RealTime_TBarChartsSwitchPage(uint16_t cID);
void WorkMode_RealTimeProc(void);
#endif
