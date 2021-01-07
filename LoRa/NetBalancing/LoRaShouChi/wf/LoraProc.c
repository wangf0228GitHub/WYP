#include "LoraProc.h"
#include "Sx1262Proc.h"
#include "radio.h"
#include <string.h>
#include "TMRList.h"
volatile States_t State = LOWPOWER;
uint16_t BufferSize = BUFFER_SIZE;
uint8_t Buffer[BUFFER_SIZE];
int8_t RssiValue = 0;
int8_t SnrValue = 0;
bool PacketReceived = false;
static RadioEvents_t RadioEvents;


void OnTxDone(void)
{
//	MainLoopCNT = 0;
	RadioStandby();
#ifdef RxDutyCycle_Enable
	State = LOWPOWER;
	printf("OnTxDone and Reset_RXDuty!\r\n");
	SX126xConfigureRxDuty(Rx_Duration, Sleep_Duration);

#else	
	State = LOWPOWER;
#endif // RxDutyCycle_Enable
}

void OnRxDone(uint8_t* payload, uint16_t size, int16_t rssi, int8_t snr)
{
//	MainLoopCNT = 0;
	RadioStandby();
	BufferSize = size;
	memcpy(Buffer, payload, BufferSize);
	RssiValue = rssi;
	SnrValue = snr;
	PacketReceived = true;
// 	RssiMoy = (((RssiMoy * RxCorrectCnt) + RssiValue) / (RxCorrectCnt + 1));
// 	SnrMoy = (((SnrMoy * RxCorrectCnt) + SnrValue) / (RxCorrectCnt + 1));
	State = RX;
}

void OnTxTimeout(void)
{
//	MainLoopCNT = 0;
//	printf("TX Time out :\r\n");
	RadioStandby();
	State = TX_TIMEOUT;
}
void OnRxTimeout(void)
{
//	MainLoopCNT = 0;
	RadioStandby();
	State = RX_TIMEOUT;
#if(FULL_DBG)
	printf(".OnRxTimeout!\r\n");
#endif
	//SX126xConfigureRxDuty(Rx_Duration, Sleep_Duration);
}

void OnRxError(void)
{
//	MainLoopCNT = 0;
	RadioStandby();
	State = RX_ERROR;
}

void OnCadDone(bool channelActivityDetected)
{
//	MainLoopCNT = 0;
	RadioStandby();
// 
// 	if (channelActivityDetected == true)/*检测CAD定时器结束并且成功检测到CAD信号*/
// 	{
// 		CadRx = CAD_SUCCESS;
// 	}
// 	else/*定时器结束没有检测到CAD信号*/
// 	{
// 		CadRx = CAD_FAIL;
// 	}
	State = RX;
}
static void CADTimeoutTimeoutIrq(void)/*CAD定时器回调函数*/
{
//	MainLoopCNT = 0;
#if(FULL_DBG)
	printf("CADTimeoutTimeoutIrq!\r\n");
#endif
	TmrStop(CAD_TIMEOUT_TMRNUM);
	RadioStandby();
	State = START_CAD;
}
void LoRaProc_Init(void)
{
	SX126xIoInit();
	RadioEvents.TxDone = OnTxDone;
	RadioEvents.RxDone = OnRxDone;
	RadioEvents.TxTimeout = OnTxTimeout;
	RadioEvents.RxTimeout = OnRxTimeout;
	RadioEvents.RxError = OnRxError;
	RadioEvents.CadDone = OnCadDone;

	TmrCfgFnct(CAD_TIMEOUT_TMRNUM, CADTimeoutTimeoutIrq);
	TmrSetTime(CAD_TIMEOUT_TMRNUM, CAD_TIMER_TIMEOUT);


	//App timmer used to check the RX's end
	// 	TimerInit(&RxAppTimeoutTimer, RxTimeoutTimerIrq);
	// 	TimerSetValue(&RxAppTimeoutTimer, RX_TIMER_TIMEOUT);


	RadioInit(&RadioEvents);
	RadioSetChannel(RF_FREQUENCY);

	RadioSetTxConfig(MODEM_LORA, TX_OUTPUT_POWER, 0, LORA_BANDWIDTH,
		LORA_SPREADING_FACTOR, LORA_CODINGRATE,
		LORA_PREAMBLE_LENGTH_TX, LORA_FIX_LENGTH_PAYLOAD_ON,
		true, 0, 0, LORA_IQ_INVERSION_ON, 1500);


	RadioSetRxConfig(MODEM_LORA, LORA_BANDWIDTH, LORA_SPREADING_FACTOR,
		LORA_CODINGRATE, 0, LORA_PREAMBLE_LENGTH_RX,
		LORA_SYMBOL_TIMEOUT, LORA_FIX_LENGTH_PAYLOAD_ON,
		0, true, 0, 0, LORA_IQ_INVERSION_ON, true);
	RadioStandby();
// 
// #ifdef RxDutyCycle_Enable
// 	printf("\r\n=================================\r\n");
// 	printf("SX126X RxDutyCycle Performance starts\r\n");
// 	printf("=====================================\r\n\r\n");
// 	Radio.Standby();
// 	SX126xConfigureRxDuty(Rx_Duration, Sleep_Duration);
// 
// 
// 
// #else	
// 	printf("\r\n=============================\r\n");
// 	printf("SX126X Cad Performance starts\r\n");
// 	printf("=============================\r\n\r\n");
// #if(RX_FW == 1)
// 	SX126xConfigureCad(CAD_SYMBOL_NUM, CAD_DET_PEAK, CAD_DET_MIN, CAD_TIMEOUT_MS);      // Configure the CAD
// 																						//	Radio.StartCad();                                                                  // do the config and lunch first CAD
// #if(FULL_DBG)
// 	printf("CAD\r\n");
// #endif
// #endif // RxDutyCycle_Enable
// #endif
}
