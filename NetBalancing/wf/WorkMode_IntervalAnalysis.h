#ifndef __WorkMode_IntervalAnalysis_H__
#define __WorkMode_IntervalAnalysis_H__

#include "main.h"
#include "TypeDefine.h"

//温度间隔分析总页数
extern uint32_t IntervalAnalysis_TPageCount;
//温度间隔分析的当前页号
extern uint32_t IntervalAnalysis_TPageIndex;
//温度间隔分析中数据表格控件中条目的序号
//extern uint32_t IntervalAnalysis_TRecordIndex;
void IntervalAnalysisModeInit(void);
void IntervalAnalysis_TBarChartsSwitchPage(uint16_t cID);
#endif
