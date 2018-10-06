#ifndef __PickParamDefine_h__
#define __PickParamDefine_h__
typedef union   
{
	struct
	{
		unsigned bMove:1;//移动
		unsigned bLowPower:1;//低电
		unsigned bBreak:1;//故障
		unsigned bTemperature:1;//是否为温度传感器
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
		_ModelState StateBits;
		uint16_t SensorData;
		unsigned char sum;
	};
	unsigned char All[PACKET_LENGTH];
} _WirelessPacket;        // general flags 
#endif
