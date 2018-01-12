#ifndef   __FlagDefine_h__
#define   __FlagDefine_h__
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
	 	unsigned char sum;
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
		unsigned int DeviceID;
	 	unsigned char WirelessParamIndex;		
	 	unsigned int TimeSpan1;
		unsigned int TimeSpan2;
		unsigned int TimeSpan3;
		unsigned int TimeSpan4;
		unsigned int SleepTimeSpan;
	};
	unsigned char All[ROMParamsCount];
} _ROMParams;        // general flags

typedef union   
{
	struct
	{
		unsigned char Month;	
		unsigned char Day;
		unsigned char Hour;
		unsigned char Minute;
		uint TData;
	};
	unsigned char All[6];
} _SensorData; 

#define SensorDataInfoCount 24
typedef union   
{
	struct
	{
		char InstallPosition[21];
		unsigned char LastState;	
		unsigned char bLoop;
		unsigned char curIndex;
	};
	unsigned char All[SensorDataInfoCount];
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
	unsigned char All[SensorDataListCount];
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
