#ifndef __FRAM_h__
#define __FRAM_h__

#include "main.h"
//系统参数
extern _ROMParams ROMParams;
//FRAM_GetSensorDataInfo读出的传感器数据存储状态
extern _SensorDataInfo SensorDataInfo;

#define IsLatestSensorDataInvalid() (LatestSensorData.Month==0xff)
#define IsLatestSensorDataValid() (LatestSensorData.Month!=0xff)
//FRAM_GetSensorDataInfo读出的传感器最新一组数据
extern _SensorData LatestSensorData;

extern uint32_t TminAddr1,TminAddr2,TmaxAddr1,TmaxAddr2;
extern uint32_t PminAddr1,PminAddr2,PmaxAddr1,PmaxAddr2;

//温度传感器按编号地址数组
extern _SensorAddrInfo TSensorAddrList[SensorDataItemCount];
//压力传感器按编号地址数组
extern _SensorAddrInfo PSensorAddrList[SensorDataItemCount];
//温度传感器按地址排序后数组
extern _SensorAddrSortingInfo TSensorAddrSortingList[SensorDataItemCount];
//压力传感器按地址排序后数组
extern _SensorAddrSortingInfo PSensorAddrSortingList[SensorDataItemCount];
//实际温度传感器数量
extern uint8_t realTSensorCount;
//实际压力传感器数量
extern uint8_t realPSensorCount;
//温度传感器按地址排序后数组总长度
extern uint8_t TSensorAddrSortingListCount;
//压力传感器按地址排序后数组总长度
extern uint8_t PSensorAddrSortingListCount;

//栋总数
uint8_t TAddr1ListCount;
//栋总数
uint8_t PAddr1ListCount;
//栋列表
uint8_t TAddr1List[SensorDataItemCount];
//栋列表
uint8_t PAddr1List[SensorDataItemCount];

void FRAM_SaveROMParams(void);
void FRAM_GetROMParams(void);
void FRAM_InitSensorData(uint8_t startIndex,uint8_t endIndex);
void FRAM_InitSensorAddrInfo(void);


void FRAM_GetLatestSensorData(uint8_t bT,uint8_t index);//获取传感器最新数据
void FRAM_GetSensorDataInfo(uint8_t bT,uint8_t index);
void FRAM_SaveSensorAddr(void);
#endif


