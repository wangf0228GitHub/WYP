#ifndef __PickParamDefine_h__
#define __PickParamDefine_h__
#include <stdint.h>
typedef union   
{
	struct
	{
		unsigned bMove:1;//�ƶ�
		unsigned bLowPower:1;//�͵�
		unsigned bBreak:1;//����
	};
	unsigned char AllFlag;
} _ModelState; 

#ifdef TXTEST
#define  PACKET_LENGTH    10
#else
#define  PACKET_LENGTH    5
#endif

#define SetFreq 3

typedef union   
{
	struct
	{
		unsigned char index;
		uint16_t T1;
		_ModelState StateBits;
		unsigned char sum;
	};
	unsigned char All[PACKET_LENGTH];
} _PickDatas;        // general flags 
#endif
