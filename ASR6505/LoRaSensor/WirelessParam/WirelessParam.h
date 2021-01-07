#ifndef __WirelessParam_h__
#define __WirelessParam_h__

#include <stdint.h>
typedef union
{
	struct
	{
		unsigned bMove : 1;//移动
		unsigned bLowPower : 1;//低电
		unsigned bBreak : 1;//故障
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


					 /*!
					 * Defines the time required for the TCXO to wakeup [ms].
					 */
#define BOARD_TCXO_WAKEUP_TIME  5

#define RX_TIMEOUT_TMRNUM	0
#define TX_TIMEOUT_TMRNUM	1
#define CAD_TIMEOUT_TMRNUM	2


#define TX_OUTPUT_POWER                             22        // dBm
#define USE_MODEM_LORA                              1




#define LORA_BANDWIDTH                              0           // [0: 125 kHz,
					 //  1: 250 kHz,
					 //  2: 500 kHz,
					 //  3: Reserved]
					 //较高的扩展因子提供更好的接收机灵敏度，但代价是较长的传输时间
#define LORA_SPREADING_FACTOR                       12          // [SF7..SF12]
#define LORA_CODINGRATE                             1           // [1: 4/5,
					 //  2: 4/6,
					 //  3: 4/7,
					 //  4: 4/8]
#define LORA_PREAMBLE_LENGTH_TX                     50           // Same for Tx
#define LORA_PREAMBLE_LENGTH_RX                     250         // Same for Rx
#define LORA_SYMBOL_TIMEOUT                         0           // Symbols
#define LORA_FIX_LENGTH_PAYLOAD_ON                  true
#define LORA_IQ_INVERSION_ON                        false


#define RFChannelCount 6
extern const uint32_t RFChannel[RFChannelCount];

#endif // WirelessParam_h__
