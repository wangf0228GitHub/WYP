#ifndef __RADIOWork_H__
#define __RADIOWork_H__

#include <stdint.h>
#include "sx1276_LoRa.h"
#include "sx1276_LoRa_Conf.h"

typedef enum
{
	RF_IDLE,
	RF_BUSY,
	RF_RX_DONE,
	RF_RX_TIMEOUT,
	RF_TX_DONE,
	RF_TX_TIMEOUT,
	RF_LEN_ERROR,
	RF_CHANNEL_EMPTY,
	RF_CHANNEL_ACTIVITY_DETECTED,
}tRFProcessReturnCodes;
#endif // __RADIO_H__
