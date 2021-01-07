#include "LoraProc.h"
#include "Sx1262Proc.h"
#include "radio.h"
#include <string.h>
#include "TMRList.h"
volatile _RadioStates_t radioStates;
uint16_t LoRaRxCount = LoRaRxBufSize;
uint8_t LoRaRxList[LoRaRxBufSize];
int8_t RssiValue = 0;
int8_t SnrValue = 0;
//volatile bool PacketReceived = false;
static RadioEvents_t RadioEvents;


void OnTxDone(void)
{
	radioStates = RadioStates_TxDone;
}

void OnRxDone(uint8_t* payload, uint16_t size, int16_t rssi, int8_t snr)
{
	radioStates = RadioStates_RxDone;
//	MainLoopCNT = 0;
//	RadioStandby();
	LoRaRxCount = size;
	memcpy(LoRaRxList, payload, LoRaRxCount);
	RssiValue = rssi;
	SnrValue = snr;
//	PacketReceived = true;
// 	RssiMoy = (((RssiMoy * RxCorrectCnt) + RssiValue) / (RxCorrectCnt + 1));
// 	SnrMoy = (((SnrMoy * RxCorrectCnt) + SnrValue) / (RxCorrectCnt + 1));
//	State = RX;
}

void OnTxTimeout(void)
{
	radioStates = RadioStates_TxTimeout;
//	MainLoopCNT = 0;
//	printf("TX Time out :\r\n");
//	RadioStandby();
}
void OnRxTimeout(void)
{
//	MainLoopCNT = 0;
//	RadioStandby();
	radioStates = RadioStates_RxTimeout;
#if(FULL_DBG)
	printf(".OnRxTimeout!\r\n");
#endif
	//SX126xConfigureRxDuty(Rx_Duration, Sleep_Duration);
}

void OnRxError(void)
{
	radioStates = RadioStates_RxError;
//	MainLoopCNT = 0;
//	RadioStandby();
}
void LoRaProc_Init(void)
{
	SX126xIoInit();
	RadioEvents.TxDone = OnTxDone;
	RadioEvents.RxDone = OnRxDone;
	RadioEvents.TxTimeout = OnTxTimeout;
	RadioEvents.RxTimeout = OnRxTimeout;
	RadioEvents.RxError = OnRxError;
	//App timmer used to check the RX's end
	// 	TimerInit(&RxAppTimeoutTimer, RxTimeoutTimerIrq);
	// 	TimerSetValue(&RxAppTimeoutTimer, RX_TIMER_TIMEOUT);
	RadioInit(&RadioEvents);
	RadioSetChannel(RFChannel[0]);

	RadioSetTxConfig(
		MODEM_LORA,//Radio modem to be used [0: FSK, 1: LoRa]
		TX_OUTPUT_POWER,//Sets the output power [dBm]
		0, //Sets the frequency deviation (FSK only)  *FSK : [Hz]	* LoRa : 0
		LORA_BANDWIDTH,//Sets the bandwidth (LoRa only) *FSK : 0	*LoRa: [0:125 kHz, 1 : 250 kHz,2 : 500 kHz, 3 : Reserved]
		LORA_SPREADING_FACTOR,	//Sets the Datarate
								//FSK : 600..300000 bits / s
								// LoRa : [6:64, 7 : 128, 8 : 256, 9 : 512,10 : 1024, 11 : 2048, 12 : 4096  chips]
		LORA_CODINGRATE, //Sets the coding rate (LoRa only)
						 //FSK : N / A(set to 0)
						 //LoRa : [1: 4 / 5, 2 : 4 / 6, 3 : 4 / 7, 4 : 4 / 8]
		LORA_PREAMBLE_LENGTH_TX, //Sets the preamble length
								 //FSK : Number of bytes
								 //LoRa : Length in symbols(the hardware adds 4 more symbols)
		LORA_FIX_LENGTH_PAYLOAD_ON, //Fixed length packets [0: variable, 1: fixed]
		true,	//Enables disables the CRC [0: OFF, 1: ON]
		0,	//Enables disables the intra-packet frequency hopping
			//FSK : N / A(set to 0)
			//LoRa : [0:OFF, 1 : ON]
		0,	//Number of symbols between each hop
			//FSK : N / A(set to 0)
			//LoRa : Number of symbols
		LORA_IQ_INVERSION_ON,	//Inverts IQ signals (LoRa only)
								//FSK : N / A(set to 0)
								//LoRa : [0:not inverted, 1 : inverted]
		1500	//Transmission timeout [ms]
	);


	RadioSetRxConfig(MODEM_LORA, //modem        Radio modem to be used[0:FSK, 1 : LoRa]
		LORA_BANDWIDTH, // bandwidth    Sets the bandwidth		
						//FSK : >= 2600 and <= 250000 Hz
						//LoRa : [0:125 kHz, 1 : 250 kHz,2 : 500 kHz, 3 : Reserved]
		LORA_SPREADING_FACTOR, //datarate     Sets the datarate
								//FSK : 600..300000 bits / s
								//LoRa : [6:64, 7 : 128, 8 : 256, 9 : 512,10 : 1024, 11 : 2048, 12 : 4096  chips]
		LORA_CODINGRATE, // coderate     Sets the coding rate (LoRa only)
						//FSK : N / A(set to 0)
						//LoRa : [1:4 / 5, 2 : 4 / 6, 3 : 4 / 7, 4 : 4 / 8]
		0,	//bandwidthAfc Sets the AFC Bandwidth(FSK only)
			//FSK : >= 2600 and <= 250000 Hz
			//LoRa : N / A(set to 0)
		LORA_PREAMBLE_LENGTH_RX, //preambleLen  Sets the Preamble length
								//FSK : Number of bytes
								//LoRa : Length in symbols(the hardware adds 4 more symbols)
		LORA_SYMBOL_TIMEOUT,  // symbTimeout  Sets the RxSingle timeout value
								//FSK : timeout in number of bytes
								//LoRa : timeout in symbols
		LORA_FIX_LENGTH_PAYLOAD_ON, // fixLen Fixed length packets [0: variable, 1: fixed]
		0, // payloadLen   Sets payload length when fixed length is used
		true, // crcOn        Enables/Disables the CRC [0: OFF, 1: ON]
		0, // freqHopOn    Enables disables the intra-packet frequency hopping
			//FSK : N / A(set to 0)
			//LoRa : [0:OFF, 1 : ON]
		0, //hopPeriod    Number of symbols between each hop
			//FSK : N / A(set to 0)
			//LoRa : Number of symbols
		LORA_IQ_INVERSION_ON, //iqInverted   Inverts IQ signals(LoRa only)
								//FSK : N / A(set to 0)
								//LoRa : [0:not inverted, 1 : inverted]
		true //rxContinuous Sets the reception in continuous mode
				//[false:single mode, true : continuous mode]
	);
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
