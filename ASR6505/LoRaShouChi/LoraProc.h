#ifndef Sx1262Proc_h__
#define Sx1262Proc_h__

#include "HardwareProfile.h"

typedef enum
{
	LOWPOWER,
	RX,
	RX_TIMEOUT,
	RX_ERROR,
	TX,
	TX_TIMEOUT,
	START_CAD,
}States_t;
extern volatile States_t State;
#define BUFFER_SIZE 64 
extern uint16_t BufferSize;
extern uint8_t Buffer[BUFFER_SIZE];
extern int8_t RssiValue;
extern int8_t SnrValue;
extern bool PacketReceived;

#define CAD_TIMER_TIMEOUT       200        //Define de CAD timer's timeout here

void LoRaProc_Init(void);
#endif // Sx1262Proc_h__
