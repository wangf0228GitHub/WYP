#ifndef   __Variables_h__
#define   __Variables_h__

#include "HardwareProfile.h"

typedef union
{
	struct
	{
		unsigned bReKey : 1;
		unsigned bShowLoop : 1;
		unsigned bNewT : 1;
		unsigned bUseFram : 1;
		unsigned bINT : 1;
		unsigned bFrashShow : 1;
		unsigned bWaitShow : 1;
		unsigned bSleep : 1;
		unsigned bSleep1 : 1;
	};
	uint32_t AllFlag;
} _GFlags;        // general flags
extern _GFlags gFlags;
#define ROMParamsAddr 0
#define ROMParamsCount 14
typedef union
{
	struct
	{
		uint8_t sum;
		// 	 	union   
		// 	 	{
		// 	 		struct
		// 	 		{
		// 	 			unsigned :1;
		// 	 			unsigned :1;
		// 	 			unsigned bWinter:1;//冬夏
		// 	 		};
		// 	 		uint8_t AllFlag;
		// 	 	} SystemState;
		uint16_t DeviceID;
		uint8_t WirelessParamIndex;
		uint16_t TimeSpan1;
		uint16_t TimeSpan2;
		uint16_t TimeSpan3;
		uint16_t TimeSpan4;
		uint16_t SleepTimeSpan;
	};
	uint8_t All[ROMParamsCount];
} _ROMParams;        // general flags

typedef union
{
	struct
	{
		uint8_t Month;
		uint8_t Day;
		uint8_t Hour;
		uint8_t Minute;
		uint16_t TData;
	};
	uint8_t All[6];
} _SensorData;

#define SensorDataInfoCount 24
typedef union
{
	struct
	{
		char InstallPosition[21];
		uint8_t LastState;
		uint8_t bLoop;
		uint8_t curIndex;
	};
	uint8_t All[SensorDataInfoCount];
} _SensorDataInfo;

#define Sensor1DataAddr 0x00000020   //32
#define SensorDataListCount 0x00000505   //1285
#define SensorDataCount 210
typedef union
{
	struct
	{
		_SensorDataInfo SensorDataInfo;
		_SensorData SensorData[SensorDataCount];
	};
	uint8_t All[SensorDataListCount];
} _SensorDataList;

#define  PACKET_LENGTH    5
typedef union
{
	struct
	{
		uint8_t index;
		uint8_t TL;
		uint8_t TH;
		uint8_t StateBits;
		uint8_t sum;
	};
	uint8_t All[PACKET_LENGTH];
} _PickDatas;        // general flags 

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

extern uint8_t KeyValue;
#endif
