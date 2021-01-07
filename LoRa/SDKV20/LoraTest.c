#include "HardwareProfile.h"
#include "radio.h"
#include <string.h>
#include "Sx1262Proc.h"
#define LoRaTest_RxList_SIZE 64 

#ifdef RXTEST
static RadioEvents_t LoRaTest_RadioEvents;
volatile RadioStatus_t sx126xstate;
uint8_t LoRaTest_RxList[LoRaTest_RxList_SIZE];
uint8_t LoRaTest_RxCount;
int8_t LoRaTest_RssiValue = 0;
int8_t LoRaTest_SnrValue = 0;
void LoRaTest_RxDone(uint8_t* payload, uint16_t size, int16_t rssi, int8_t snr)
{
	sx126xstate = SX126xGetStatus();
	//	MainLoopCNT = 0;
	//RadioStandby();
	LoRaTest_RxCount = size;
	memcpy(LoRaTest_RxList, payload, size);
	LoRaTest_RssiValue = rssi;
	LoRaTest_SnrValue = snr;	
}
void LoRaTest_RxTest(void)
{
	SX126xIoInit();
	LoRaTest_RadioEvents.RxDone = LoRaTest_RxDone;
	RadioInit(&LoRaTest_RadioEvents);
	RadioSetChannel(RFChannel[0]);
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
	RadioRx(0);
	while (true)
	{
	}
}
#endif
#ifdef TXTEST
static RadioEvents_t LoRaTest_RadioEvents;
volatile RadioStatus_t sx126xstate;
void LoRaTest_TxTimeout(void)
{
	sx126xstate = SX126xGetStatus();
	//	MainLoopCNT = 0;
// 	RadioStandby();
// 	LoRaTest_RxCount = size;
// 	memcpy(LoRaTest_RxList, payload, size);
// 	LoRaTest_RssiValue = rssi;
// 	LoRaTest_SnrValue = snr;
}
void LoRaTest_TxTest(void)
{
	uint8_t i;
	uint8_t buffer[10];
	for (i = 0; i < 10; i++) 
	{ 
		buffer[i] = i; 
	}
	SX126xIoInit();
	LoRaTest_RadioEvents.TxTimeout = LoRaTest_TxTimeout;
	RadioInit(&LoRaTest_RadioEvents);
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
							//LoRa : [1:4 / 5, 2 : 4 / 6, 3 : 4 / 7, 4 : 4 / 8]
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
	while (true)
	{
		RadioSend(buffer, 10);
		DelayMs(1000);
	}
}
#endif
#ifdef RXTXTEST
static RadioEvents_t LoRaTest_RadioEvents;
volatile RadioStatus_t sx126xstate;
uint8_t LoRaTest_RxList[LoRaTest_RxList_SIZE];
uint8_t LoRaTest_RxCount;
int8_t LoRaTest_RssiValue = 0;
int8_t LoRaTest_SnrValue = 0;
uint8_t LoRaTest_bRx;
void LoRaTest_RxDone(uint8_t* payload, uint16_t size, int16_t rssi, int8_t snr)
{
	sx126xstate = SX126xGetStatus();
	//	MainLoopCNT = 0;
	//RadioStandby();
	LoRaTest_RxCount = size;
	memcpy(LoRaTest_RxList, payload, size);
	LoRaTest_RssiValue = rssi;
	LoRaTest_SnrValue = snr;
	LoRaTest_bRx = true;
}
void LoRaTest_TxDone(void)
{
	sx126xstate = SX126xGetStatus();
	RadioRx(0);
	//	MainLoopCNT = 0;
	// 	RadioStandby();
	// 	LoRaTest_RxCount = size;
	// 	memcpy(LoRaTest_RxList, payload, size);
	// 	LoRaTest_RssiValue = rssi;
	// 	LoRaTest_SnrValue = snr;
}
void LoRaTest_TxTimeout(void)
{
	sx126xstate = SX126xGetStatus();
	RadioRx(0);
	//	MainLoopCNT = 0;
	// 	RadioStandby();
	// 	LoRaTest_RxCount = size;
	// 	memcpy(LoRaTest_RxList, payload, size);
	// 	LoRaTest_RssiValue = rssi;
	// 	LoRaTest_SnrValue = snr;
}
void LoRaTest_RxTxTest(void)
{
	SX126xIoInit();
	LoRaTest_RadioEvents.RxDone = LoRaTest_RxDone;
	LoRaTest_RadioEvents.TxDone = LoRaTest_TxDone;
	LoRaTest_RadioEvents.TxTimeout = LoRaTest_TxTimeout;
	RadioInit(&LoRaTest_RadioEvents);
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
						 //LoRa : [1:4 / 5, 2 : 4 / 6, 3 : 4 / 7, 4 : 4 / 8]
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
		false //rxContinuous Sets the reception in continuous mode
			 //[false:single mode, true : continuous mode]
	);	
	RadioRx(0);
	LoRaTest_bRx = false;
	while (true)
	{
		if (LoRaTest_bRx)
		{
			LoRaTest_bRx = false;
			RadioSend(LoRaTest_RxList, LoRaTest_RxCount);
		}
	}
}
#endif

#ifdef TXRXTEST
static RadioEvents_t LoRaTest_RadioEvents;
volatile RadioStatus_t sx126xstate;
uint8_t LoRaTest_RxList[LoRaTest_RxList_SIZE];
uint8_t LoRaTest_RxCount;
int8_t LoRaTest_RssiValue = 0;
int8_t LoRaTest_SnrValue = 0;
uint8_t LoRaTest_bRx;
void LoRaTest_RxTimeout(void)
{
	sx126xstate = SX126xGetStatus();
	LoRaTest_bRx = true;
}
void LoRaTest_RxDone(uint8_t* payload, uint16_t size, int16_t rssi, int8_t snr)
{
	sx126xstate = SX126xGetStatus();
	//	MainLoopCNT = 0;
	//RadioStandby();
	LoRaTest_RxCount = size;
	memcpy(LoRaTest_RxList, payload, size);
	LoRaTest_RssiValue = rssi;
	LoRaTest_SnrValue = snr;
	LoRaTest_bRx = true;
}
void LoRaTest_TxDone(void)
{
	sx126xstate = SX126xGetStatus();
	RadioRx(100);
	//	MainLoopCNT = 0;
	// 	RadioStandby();
	// 	LoRaTest_RxCount = size;
	// 	memcpy(LoRaTest_RxList, payload, size);
	// 	LoRaTest_RssiValue = rssi;
	// 	LoRaTest_SnrValue = snr;
}
void LoRaTest_TxTimeout(void)
{
	sx126xstate = SX126xGetStatus();
	LoRaTest_bRx = true;
	//	MainLoopCNT = 0;
	// 	RadioStandby();
	// 	LoRaTest_RxCount = size;
	// 	memcpy(LoRaTest_RxList, payload, size);
	// 	LoRaTest_RssiValue = rssi;
	// 	LoRaTest_SnrValue = snr;
}
void LoRaTest_TxRxTest(void)
{
	uint8_t i;
	uint8_t buffer[10];
	for (i = 0; i < 10; i++)
	{
		buffer[i] = i;
	}
	SX126xIoInit();
	LoRaTest_RadioEvents.RxDone = LoRaTest_RxDone;
	LoRaTest_RadioEvents.RxTimeout = LoRaTest_RxTimeout;
	LoRaTest_RadioEvents.TxDone = LoRaTest_TxDone;
	LoRaTest_RadioEvents.TxTimeout = LoRaTest_TxTimeout;
	RadioInit(&LoRaTest_RadioEvents);
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
						 //LoRa : [1:4 / 5, 2 : 4 / 6, 3 : 4 / 7, 4 : 4 / 8]
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
		false //rxContinuous Sets the reception in continuous mode
			  //[false:single mode, true : continuous mode]
	);	
	LoRaTest_bRx = false;
	while (true)
	{
		RadioSend(buffer, 10);
		while (LoRaTest_bRx == false);
		LoRaTest_bRx = false;
	}
}
#endif

void LoRaTest(void)
{
#ifdef RXTEST
	LoRaTest_RxTest();
#endif
#ifdef TXTEST
	LoRaTest_TxTest();
#endif
#ifdef RXTXTEST
	LoRaTest_RxTxTest();
#endif
#ifdef TXRXTEST
	LoRaTest_TxRxTest();
#endif
}