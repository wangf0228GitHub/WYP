#ifndef __PickParamDefine_h__
#define __PickParamDefine_h__
typedef union   
{
	struct
	{
		uint8_t bMove:1;//移动
		uint8_t bLowPower:1;//低电
		uint8_t bBreak:1;//故障
		uint8_t bTemperature:1;//是否为温度传感器
	};
	uint8_t AllFlag;
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
		uint8_t index;		
		_ModelState StateBits;
		uint16_t SensorData;
		uint8_t sum;
	};
	uint8_t All[PACKET_LENGTH];
} _WirelessPacket;        // general flags 

#endif
