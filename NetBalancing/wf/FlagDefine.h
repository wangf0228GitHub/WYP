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
		unsigned bRxRTC:1;//判断是否接收的触屏的RTC数据
		unsigned bNewSensorData:1;//是否收到了新的传感器数据
	};
	uint32_t AllFlag;
} _gFlags;        // general flags

typedef union   
{
	struct
	{
		uint8_t Month;	
		uint8_t Day;
		uint8_t Hour;
		uint8_t Minute;
		uint16_t SensorData;
	};
	uint8_t All[6];
} _SensorData; 

#define ROMParamsAddr 0
#define ROMParamsCount 16
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
		uint8_t  WirelessParamIndex;
		uint16_t DeviceID;				
		uint16_t TimeSpan1;
		uint16_t TimeSpan2;
		uint16_t TimeSpan3;
		uint16_t TimeSpan4;
		uint16_t SleepTimeSpan;
		uint16_t bak;
	};
	uint8_t All[ROMParamsCount];
} _ROMParams;        // general flags

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
// volatile const uint8_t RomParamAddr[1024] @ 0x7400;
// typedef union   
// {
// 	struct
// 	{
// 		uint8_t sum;
// 		union   
// 		{
// 			struct
// 			{
// 				unsigned :1;
// 				unsigned :1;
// 				unsigned bWinter:1;//冬夏
// 			};
// 			uint8_t AllFlag;
// 		} SystemState;
// 		uint8_t WirelessParamIndex;		
// 		uint8_t UnitAddr;//单元地址
// 		uint8_t RoomControlData[5];
// 	};
// 	uint8_t All[ROMCount];
// } _ROMParams;        // general flags
#endif
