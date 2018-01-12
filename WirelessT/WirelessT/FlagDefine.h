#ifndef   __FlagDefine_h__
#define   __FlagDefine_h__
/************************************************************************/
/* 第一个为最低位                                                       */
/************************************************************************/
typedef union   
{
	struct
	{		
		unsigned bWaitOut:1;
		unsigned bT1:1;	
		unsigned bSet:1;
	};
	unsigned char AllFlag;
} GFlags;        // general flags

#define ROMCount 6
volatile const unsigned char RomParamAddr[1024] @ 0x7400;
typedef union   
{
	struct
	{
		unsigned char sum;//校验和
 		union   
 		{
 			struct
 			{
 				unsigned bWinter:1;//冬夏
 			};
 			unsigned char AllFlag;
 		} SystemState;
		unsigned char MyAddr;
		unsigned char WirelessPowerLevel;
		unsigned char WirelessParamIndex;		
		unsigned char PickCycle;//7
	};
	unsigned char All[ROMCount];
} _ROMParams;        // general flags

_ROMParams ROMParams;
#endif
