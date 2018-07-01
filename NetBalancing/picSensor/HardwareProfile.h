#ifndef __HardwareProfile_h__
#define __HardwareProfile_h__

//#define Debug
#define WTSSSTX

//#define RXTEST
//#define TXTEST

#include <htc.h>
#define _XTAL_FREQ 4000000
#include "TypeDefine.h"
#include "PickParamDefine.h"
#include "FlagDefine.h"
#include "afx.h"
#include "Verify.h"
//#include "WirelessParam.h"




#define Sleep_1m 3840//38400
#define Sleep_1s  64

#define Si4463_SDN_DIR	TRISC4
#define Si4463_NIRQ_DIR TRISB1
#define Si4463_NSEL_DIR	TRISB2
#define Si4463_SCL_DIR	TRISB3
#define Si4463_SDI_DIR	TRISB4
#define Si4463_SDO_DIR	TRISB5

#define Si4463_SDN_W	LATC4
#define Si4463_NIRQ_R	RB1
#define Si4463_NSEL_W	LATB2
#define Si4463_SCL_W	LATB3  
#define Si4463_SDI_W	LATB4	//芯片的输入
#define Si4463_SDO_R	RB5 //芯片的输出

#define SimSPI
#define SimSPI_SPI0
#define SimSPI_SCL_DIR Si4463_SCL_DIR
#define SimSPI_SDI_DIR Si4463_SDO_DIR
#define SimSPI_SDO_DIR Si4463_SDI_DIR

#define SimSPI_SCL_W Si4463_SCL_W
#define SimSPI_SDI_R Si4463_SDO_R
#define SimSPI_SDO_W Si4463_SDI_W
#include "SimSPI.h"

#define Si4463_SPIInit() SimSPI_Init()
#define Si4463_SPIProc(x) SimSPI_Proc(x)
#include "Si4463.h"
#include "WirelessProc.h"

#define ONEWIRE_PIN_DIR	TRISA0
#define ONEWIRE_PIN_W 	LATA0
#define ONEWIRE_PIN_R 	RA0
#define OneWire_ReadDelayOffSet 4
#include "OneWire.h"
#include "DS18x20.h"

#define MovePIN_R RC5
#define MovePIN_DIR TRISC5


#define MissWirelessTimes_Max 5
#define Wireless_RSSI 105

GFlags gFlags;
unsigned char TxTick;
//unsigned int SystemTick;
unsigned char DS18b20Retry;
unsigned char BattV;
unsigned char Wait4TMR2;
unsigned char test;
unsigned char ItStatus1,ItStatus2;
_PickDatas PickDatas;
unsigned char SystemState;
#define ErrT_Max 3
unsigned char ErrT;
//ROM数据
unsigned char GetRomData(void);
void SaveRomData(void);

void InitSystem(void);
void DelayS(unsigned char ns);
void wf_flash_write(const unsigned char * source, unsigned int length, far unsigned char * dest);
#endif
