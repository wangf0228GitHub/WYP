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

#define RF_FREQUENCY                                475500000 // Hz
#define TX_OUTPUT_POWER                             22        // dBm
#define USE_MODEM_LORA                              1

#define LORA_BANDWIDTH                              0           // [0: 125 kHz,
//  1: 250 kHz,
//  2: 500 kHz,
//  3: Reserved]
#define LORA_SPREADING_FACTOR                       12          // [SF7..SF12]
#define LORA_CODINGRATE                             1           // [1: 4/5,
//  2: 4/6,
//  3: 4/7,
//  4: 4/8]
#define LORA_PREAMBLE_LENGTH_TX                     4           // Same for Tx
#define LORA_PREAMBLE_LENGTH_RX                     250         // Same for Rx
#define LORA_SYMBOL_TIMEOUT                         0           // Symbols
#define LORA_FIX_LENGTH_PAYLOAD_ON                  false
#define LORA_IQ_INVERSION_ON                        false

#define RX_TIMEOUT_VALUE                            1900
#define CAD_TIMER_TIMEOUT       200        //Define de CAD timer's timeout here


//CAD parameters
#define CAD_SYMBOL_NUM          LORA_CAD_04_SYMBOL
#define CAD_DET_PEAK            28
#define CAD_DET_MIN             10
#define CAD_TIMEOUT_MS          2000
#define NB_TRY                  1

#define RxDutyCycle_Enable  1
#define Rx_Duration	   (uint32_t) 200000/15.625
#define Sleep_Duration (uint32_t)7800000/15.625

extern volatile States_t State;

#define BUFFER_SIZE 64 
extern uint16_t BufferSize;
extern uint8_t Buffer[BUFFER_SIZE];
extern int8_t RssiValue;
extern int8_t SnrValue;
extern bool PacketReceived;
void Sx1262_Init(void);
#endif // Sx1262Proc_h__
