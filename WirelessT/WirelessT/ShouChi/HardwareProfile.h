#ifndef __HardwareProfile_h__
#define __HardwareProfile_h__

//#define Proteus

//#define TXTEST

#include <htc.h>
#define _XTAL_FREQ 16000000
#include "afx.h"
#include "TypeDefine.h"
#include "Verify.h"
#include "FlagDefine.h"
#include "CharTimeOP.h"


#define NewON_W LATE5
#define NewOFF_R RE4

#define NewON_DIR TRISE5
#define NewOFF_DIR TRISE4


#define Uart_Uart1
#define Uart1_TRMT TRMT
#define Uart1_TXREG TXREG1
#define Uart_Uart2
#define Uart2_TRMT TRMT2
#define Uart2_TXREG TXREG2
#include "Uart.h"
 
#include "PickParamDefine.h"
#include "WirelessParam.h"
#define Si4463_SDN_DIR	TRISB1
#define Si4463_NIRQ_DIR TRISB0
#define Si4463_NSEL_DIR	TRISB5
#define Si4463_SCL_DIR	TRISB4
#define Si4463_SDI_DIR	TRISB2
#define Si4463_SDO_DIR	TRISB3
 
#define Si4463_SDN_W	LATB1
#define Si4463_NIRQ_R	RB0
#define Si4463_NSEL_W	LATB5
#define Si4463_SCL_W	LATB4   
#define Si4463_SDI_W	LATB2	//芯片的输入
#define Si4463_SDO_R	RB3 //芯片的输出

#define SimSPI
#define SimSPI_SPI0
#define SimSPI_SCL_DIR Si4463_SCL_DIR
#define SimSPI_SDI_DIR Si4463_SDO_DIR
#define SimSPI_SDO_DIR Si4463_SDI_DIR

#define SimSPI_SCL_W Si4463_SCL_W
#define SimSPI_SDI_R Si4463_SDO_R
#define SimSPI_SDO_W Si4463_SDI_W

#define SimSPI2
#define SimSPI2_SPI0
#define SimSPI2_SCL_DIR TRISF2
#define SimSPI2_SDI_DIR TRISF4
#define SimSPI2_SDO_DIR TRISF3

#define SimSPI2_SCL_W LATF2
#define SimSPI2_SDI_R RF4
#define SimSPI2_SDO_W LATF3
#include "SimSPI.h"

 
#define Si4463_SPIInit() SimSPI_Init()
#define Si4463_SPIProc(x) SimSPI_Proc(x)
#include "Si4463.h"

#define SPIROM_CS_DIR TRISF5
#define SPIROM_W_DIR TRISF7
#define SPIROM_HOLD_DIR TRISF1

#define SPIROM_CS_W LATF5
#define SPIROM_W_W LATF7
#define SPIROM_HOLD_W LATF1

#define SPIROM_SPIInit() SimSPI2_Init()
#define SPIROM_SPIProc(x) SimSPI2_Proc(x)
#define SPIROM_Addr24
#ifdef Proteus
#define SPIROM_PageRollover 0x000000ff
#define SPIROM_NeedWIP
#endif
#include "SPIROM.h"

#define DS18X20_EEPROMSUPPORT
#define DS18B20
#define ONEWIRE_PIN_DIR	TRISC3
#define ONEWIRE_PIN_W 	LATC3
#define ONEWIRE_PIN_R 	RC3
#include "OneWire.h"
#include "DS18x20.h"
//#include "WirelessProc.h"

//#include "Key.h"

#define DS1302_DATA_IO	TRISC1
#define DS1302_CLK_IO	TRISC0
#define DS1302_CE_IO	TRISA4

#define DS1302_DATA_W	LATC1
#define DS1302_DATA_R	RC1
#define DS1302_CLK_W	LATC0	
#define DS1302_CE_W		LATA4
#include "DS1302.h"

#define SetRx_CP1616_Client_Ex
#define SetTx_CP1616_Client_Ex
#define SetRx_CP1616_Client() NOP()
#define SetTx_CP1616_Client() NOP()

#define CP1616_Client_TxByteWithVerify_Ex
#define CP1616_Client_TxByteWithVerify(x) Uart2_VerifySumAddTxByte(x)
#define CP1616_Client_TxByte(x) Uart2_PutChar(x)
#include "CP1616_Client.h"

GFlags gFlags;
unsigned char SystemMode;
unsigned int KeyTick;
unsigned int SleepTick;
//unsigned int Sleep1Tick;
unsigned int PowerOffTick;
unsigned int SystemTick;
unsigned int AnalyzeTick;
unsigned int FlashTick;
unsigned int LCDCKTick;
unsigned int SleepTick;
unsigned int ADTick;
unsigned int ADValue;
unsigned int NoWirelessRxTick;
unsigned char DisplayIndex;
unsigned char gTest;
unsigned char SetIndex;
unsigned char SetNum[20];
_PickDatas PickDatas;
_SensorData SensorData4Save;
_SensorData SensorData4Get;
unsigned char SensorDataSecond;
_SensorDataInfo SensorDataInfo;
unsigned char WorkMode;
unsigned char SetMode;
enum {WorkMode_Main=0,WorkMode_Analyze,WorkMode_RealTime,WorkMode_History,WorkMode_Setting,WorkMode_WithPC};
enum {SetMode_Main=0,SetMode_DateTime,SetMode_Freq,SetMode_ShowGap,SetMode_Sleep,SetMode_Sensor};
/************************************************************************/
/* 历史数据查询                                                         */
/************************************************************************/
#define History_PageSize 10
#define History_PageCount 21
#define SensorDataMaxCount 210
_SensorData SensorData4ShowList[History_PageSize];
unsigned char History_SensorIndex;
unsigned char History_ListCount;
unsigned char History_curPageCount;
unsigned char History_Page;

unsigned char Si4463Temp[10];
unsigned char DisplayLine[31];
unsigned int FrashTick;
unsigned char WirelessParamIndex;
unsigned int ROMSleepTick;
_ROMParams ROMParams;

#define pWithFloorData 6

#define MaxWithFloorRx 30
unsigned char WithFloorRxList[MaxWithFloorRx];
unsigned char WithFloorNeedRxCount;
unsigned char WithFloorRxCount;
unsigned int WaitWithFloorTick;
unsigned int SettingTick;
unsigned char TxRand;
#define MAXWITHPCRX 300
unsigned char WithPCRxList[MAXWITHPCRX];
unsigned int WithPCRxCount;


/************************************************************************/
/* 显示临时                                                             */
/************************************************************************/
unsigned char DisplayString[14][30];
unsigned char DisplayRow;
unsigned char AnalyzePage;

void DisplayInit( void );
void Display_Clear(void);
void Display_ShowRealTemp(void);
void Display_ShowPic(unsigned char index);
void Display_ShowAnalyzeTemp(void);
void Display_SetTxtColor(unsigned char index);
void Display_ShowHistory(void);
void Display_ShowTxt(unsigned char font,unsigned char x,unsigned int y,char* pBuffer,unsigned int len);
void Display_BK(unsigned char level);
void Display_ConPC(void);
void Display_ShowBatt(void);
/************************************************************************/
/* 按键                                                                 */
/************************************************************************/
#define L1_R RE0
#define L2_R RE1
#define L3_R RE2
#define L4_R RE3
#define NoKey 0x0f

#define Key_Main_1 0x070e
#define Key_Main_2 0x060e
#define Key_Main_3 0x050e
#define Key_FastLeft 0x080e
#define Key_FastRight 0x040e

#define Key_ESC 0x080b
#define Key_Up 0x080d
#define Key_TAB 0x070d
#define Key_ENT 0x0807

#define Key_Left 0x070b
#define Key_Down 0x050d
#define Key_Right 0x060d
#define Key_Back 0x0707

#define Key_1 0x060b
#define Key_2 0x040d
#define Key_3 0x0607

#define Key_4 0x050b
#define Key_5 0x030d
#define Key_6 0x0507

#define Key_7 0x040b
#define Key_8 0x010d
#define Key_9 0x0407

#define Key_Start 0x030b
#define Key_0 0x020d
#define Key_Sharp 0x0307

#define Key_Power 0x020b
#define Key_Windows 0x010b
#define Key_Shift 0x0107
#define Key_Fn 0x0207
#ifndef Proteus
	#define KeyCheck_ReadKey(key) key=PORTE&0x0f
#else

	#define KeyCheck_ReadKey(key) key=PORTE&0xf0;key=key>>4
#endif
unsigned int OldKey;
uint KeyValue;
unsigned char KeyTimes;
#define KeyCheck_ReKeyTick 5
unsigned char KeyPollCheck(void);
unsigned char GetKeyNum(void);

void CommonKeyFun(void);

void Wireless_RxInit(void);
void Wireless_SetInit(void);

void FRAM_SaveROMParams(void);
void FRAM_GetROMParams(void);
void FRAM_InitSensorData(unsigned char s,unsigned char e);
void FRAM_SaveSensorData(void);
void FRAM_GetSensorDataInfo(unsigned char index);
void FRAM_GetSensorData(unsigned char index,unsigned char* pBuf);
void FRAM_SaveSensorAddr(unsigned char index,unsigned char* pBuff,unsigned char Count);
void FRAM_HistoryGetPageSensorData();


void WorkMode_MainProc(void);
void WorkMode_AnalyzeInit(void);
void WorkMode_AnalyzeProc(void);
void WorkMode_RealTimeInit(void);
void WorkMode_RealTimeProc(void);

void WorkMode_SettingInit(void);
void WorkMode_SettingProc(void);

void WorkMode_HistoryInit(unsigned char hID);
void WorkMode_HistoryProc(void);


void SetMode_SensorInit(void);
void SetMode_SensorProc(void);
void SetMode_SleepInit(void);
void SetMode_SleepProc(void);
void SetMode_DateTimeInit(void);
void SetMode_DateTimeProc(void);

void SetMode_ShowGapInit(void);
void SetMode_ShowGapProc(void);
void ProcCommandFromPC( void );
#endif
