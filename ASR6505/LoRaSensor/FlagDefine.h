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
		unsigned bWaitOut : 1;
		unsigned bT1 : 1;
		unsigned bSet : 1;
	};
	uint8_t AllFlag;
} _GFlags;        // general flags

#define ROMCount 6
#define ROMVerifySumOffset 1
#define ROMParamStartAddr FLASH_DATA_EEPROM_START_PHYSICAL_ADDRESS
typedef union
{
	struct
	{
		uint8_t sum;//校验和
		union
		{
			struct
			{
				unsigned bWinter : 1;//冬夏
			};
			uint8_t AllFlag;
		} SystemState;
		uint8_t MyAddr;
		uint8_t WirelessPowerLevel;
		uint8_t WirelessParamIndex;
		uint8_t PickCycle;//7
	};
	uint8_t All[ROMCount];
} _ROMParams;        // general flags
#endif
