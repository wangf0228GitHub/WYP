#ifndef __WirelessProc_h__
#define __WirelessProc_h__

#include "main.h"
#include "Si4463_Conf.h"
#include "PickParamDefine.h"

extern uint8_t Si4463Temp[10];
extern unsigned char WirelessRxList[64];
extern unsigned char WirelessRxCount;
extern uint32_t NoWirelessRxTick;
extern _PickDatas PickDatas;
#define WirelessOff() Si4463_SDN_High()
#define RSSI_SAMPLES 10
unsigned char Si4432_RSSI (void);
void Wireless_RxInit(void);
//void Wireless_WithShouChi(void);
unsigned char Wireless_RxProc(void);
unsigned char Wireless_TxProc(unsigned char Command,const unsigned char* pTx,unsigned char TxCount);
void Wireless_RxINTProc(void);
#endif // __WirelessProc_h__
