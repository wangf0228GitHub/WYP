#ifndef Sx1262Proc_h__
#define Sx1262Proc_h__

#include "HardwareProfile.h"

typedef enum
{
	Wait4RadioEvent,
	RadioStates_RxDone,
	RadioStates_RxTimeout,
	RadioStates_RxError,
	RadioStates_TxDone,
	RadioStates_TxTimeout
}_RadioStates_t;
extern volatile _RadioStates_t radioStates;
#define LoRaRxBufSize 64 
extern uint16_t LoRaRxCount;
extern uint8_t LoRaRxList[LoRaRxBufSize];
extern int8_t RssiValue;
extern int8_t SnrValue;
//extern volatile bool PacketReceived;

#define CAD_TIMER_TIMEOUT       200        //Define de CAD timer's timeout here

void LoRaProc_Init(void);
#endif // Sx1262Proc_h__
