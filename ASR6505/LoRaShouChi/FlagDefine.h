#ifndef   __FlagDefine_h__
#define   __FlagDefine_h__
#include <stdint.h>
/************************************************************************/
/* 第一个为最低位                                                       */
/************************************************************************/
typedef union   
{
	struct
	{		
		unsigned bReKey:1;
		unsigned bShowLoop:1;
		unsigned bNewT:1;
		unsigned bUseFram:1;
		unsigned bINT:1;
		unsigned bFrashShow:1;
		unsigned bWaitShow:1;
		unsigned bSleep:1;
		unsigned bSleep1:1;
	};
	unsigned int AllFlag;
} GFlags;        // general flags

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
// 	 		unsigned char AllFlag;
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


// 
// #define ROMCount 9
// volatile const unsigned char RomParamAddr[1024] @ 0x7400;
// typedef union   
// {
// 	struct
// 	{
// 		unsigned char sum;
// 		union   
// 		{
// 			struct
// 			{
// 				unsigned :1;
// 				unsigned :1;
// 				unsigned bWinter:1;//冬夏
// 			};
// 			unsigned char AllFlag;
// 		} SystemState;
// 		unsigned char WirelessParamIndex;		
// 		unsigned char UnitAddr;//单元地址
// 		unsigned char RoomControlData[5];
// 	};
// 	unsigned char All[ROMCount];
// } _ROMParams;        // general flags
#endif
