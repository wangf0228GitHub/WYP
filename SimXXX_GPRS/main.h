#ifndef __main_h__
#define __main_h__

//#define Proteus

//#define NoScreen

//#define InSimulation

//#define Test_4M


#include <htc.h>
#include <stdint.h>
#define _XTAL_FREQ 4000000
#include "TypeDefine.h"
#include "FlagDefine.h"
#define WFRomOperation

#define Verify_CRC8
#define Verify_Sum
#include "Verify.h"
#include "afx.h"

#define T1CYCLE_4M 15536 //100ms

#define LED1_DIR TRISA4
#define LED1_W LATA4

#define LED2_DIR TRISA3
#define LED2_W LATA3

#ifdef InSimulation
#define TestMode_DIR TRISB3
#define TestMode_R RB3
#define TestMode_WPUB WPUB3
#else
#define TestMode_DIR TRISB7
#define TestMode_R RB7
#define TestMode_WPUB WPUB7
#endif


#define ONEWIRE_PIN_DIR	TRISB1
#define ONEWIRE_PIN_W 	LATB1
#define ONEWIRE_PIN_R 	RB1
#define OneWire_ReadDelayOffSet 9
#include "OneWire.h"
#include "DS18x20.h"


#ifdef oldSim900A
#define isPowerON 1
#define isPowerOFF 0
#else
#define isPowerON 0
#define isPowerOFF 1
#endif 


/************************************************************************/
/* TCN75                                                                */
/************************************************************************/
#define SimI2C
#define SimI2C_CLK_IO TRISD7
#define SimI2C_CLK_W LATD7

#define SimI2C_DATA_IO TRISD6
#define SimI2C_DATA_W LATD6
#define SimI2C_DATA_R RD6
#include "SimI2C.h"
#include "TCN75.h"

#define TCN75_INT_IO TRISB0
#define TCN75_INT_R RB0


#include "Display.h"

#define POWER_ON_IO TRISD5
#define POWER_ON_W LATD5
#define STATUS_IO TRISD4
#define STATUS_R RD4
#define KeyNotify_R RB2
#define KeyNotify_IO TRISB2
//#define KeyTest_R RB3

#define Uart_Uart1
#define Uart_TRMT TRMT
#define Uart_TXREG TXREG
#include "Uart.h"
#define ATCommand_MaxRX 100
#define ATCommand_WaitClientInterval_Ex
#define ATCommand_WaitClientInterval() __delay_20ms(100);
#include "ATCommand.h"

#define CallTimeOut 200
unsigned char TListIndex;

_TList TList;
char ICCID[21];
unsigned char TxErrDataIndex;
#define MaxTxErrTimes 10
#define TxErrDataPtr 16
unsigned char TxTemperature[4];
unsigned int SystemTick;
unsigned int MeasurementTick;
unsigned int NeedMeasurementTick;
unsigned int RunTick;

unsigned char CSQ;
u16_wf CurTemp;
_GFlags gFlags;
unsigned char ErrState;
enum {NoErr=0,MissT,Miss900a,MissAT,MissSimCard,MissNet,ErrMSG,ErrCSQ,	
	MissAT_CPMS,MissAT_CMGR,MissAT_CMGDA,MissAT_ATH,MissAT_ATE1,MissAT_CNMI
	,MissAT_CMGF,MissAT_CSQ,MissAT_COPS,MissAT_COLP,MissAT_CLCC,MissPower,
	MissAT_CIPCLOSE,MissAT_CIPSHUT,MissAT_CGCLASS,MissAT_CGDCONT,MissAT_CGATT,
	MissAT_CIPCSGP,MissAT_CSTT,MissAT_CIICR,MissAT_CIFSR,MissAT_CIPSTART,
	MissAT_CIPSEND,MissAT_SendData,MissAT_NoServerData,MissAT_ErrServerData,MissAT_ServerClose};
void InitSystem( void );
unsigned char PowerON(void);
unsigned char PowerDown(void);
void CallProc(void);
void CallSend(void);
void ReadTData(void);
void InitGPRS(void);
unsigned char InteractServer();
void MakeTxTemperature(u16_wf T);
// void CallTestProc(void);
// void CallTestSend(void);
void TestProc(void);
#endif
