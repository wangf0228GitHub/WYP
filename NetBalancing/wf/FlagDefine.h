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
#define ROMParamsCount 36
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
		char InstallArea[20];//安装的小区
	};
	uint8_t All[ROMParamsCount];
} _ROMParams;        // general flags

#define SensorDataInfoCount 8
typedef union   
{
	struct
	{
		uint8_t Addr1;
		uint8_t Addr2;
		uint8_t LastState;	
		uint8_t bLoop;
		uint8_t curDataSaveIndex;
		uint8_t bak1;
		uint8_t bak2;
		uint8_t bak3;
	};
	uint8_t All[SensorDataInfoCount];
} _SensorDataInfo; 

#define TSensor1DataAddr 0x00000080   
#define PSensor1DataAddr 0x0000fb00   
#define SensorDataListCount 0x00000280   //1285
#define SensorDataItemCount 100
typedef union   
{
	struct
	{
		_SensorDataInfo SensorDataInfo;
		_SensorData SensorData[SensorDataItemCount];
	};
	uint8_t All[SensorDataListCount];
} _SensorDataList; 

typedef union   
{
	struct
	{
		uint8_t Addr1;
		uint8_t Addr2;
		uint8_t bak1;
		uint8_t bak2;
	};
	uint8_t All[4];
} _SensorAddrInfo;

typedef union   
{
	struct
	{
		uint8_t SensorIndex;
		uint8_t Addr1;
		uint8_t Addr2;		
		uint8_t bak1;
	};
	uint8_t All[SensorDataInfoCount];
} _SensorAddrSortingInfo;

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
