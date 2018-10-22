#ifndef __WorkMode_DataAnalysis_H__
#define __WorkMode_DataAnalysis_H__

#include "main.h"
#include "TypeDefine.h"

//温度间隔分析总页数
extern uint32_t DataAnalysis_DA_TPageCountOfRecord;
//温度间隔分析的当前页号
extern uint32_t DataAnalysis_DA_TPageIndexOfRecord;
//温度间隔分析中数据表格控件中条目的序号
//extern uint32_t IntervalAnalysis_TRecordIndex;
void DataAnalysisModeInit( void );
void DataAnalysis_DA_TRecordSwitchPage(uint16_t cID);
void DataAnalysis_DA_TBarChartsSwitchPage(uint16_t cID);
void DataAnalysis_DY_TRecordSwitchPage(uint16_t cID);
void DataAnalysis_DY_TBarChartsSwitchPage(uint16_t cID);
#endif
