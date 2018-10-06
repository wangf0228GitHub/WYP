#ifndef __TFTWorkProc_H__
#define __TFTWorkProc_H__

#include "main.h"
#include "TypeDefine.h"


typedef union   
{
	struct
	{
		uint8_t year;
		uint8_t month;
		uint8_t week;
		uint8_t day;
		uint8_t hour;
		uint8_t minute;
		uint8_t second;
	};
	unsigned char All[6];
} _RTCData; 
extern _RTCData RTCData;

void ShouYe_ButtonProc(uint16_t control_id);
uint32_t JumpButtonProc(uint16_t control_id);
void TFT_NewSensorDataProc(void);
void ReadRTC(void);
/************************************************************************/
/* Í¨ÓÃ¿Ø¼þID                                                           */
/************************************************************************/
#define cID_btReturn 1
#define cID_btList 2
#define cID_btCurve 3
#define cID_btRealTime 4
#define cID_btHistoryData 5
#define cID_btAnalysisDiagnosis 6
#define cID_btIntervalAnalysis 7
#define cID_btSetting 8
#define cID_btForward 9
#define cID_btBackward 10
#define cID_btHelp 11

#define cID_btSwitchSensor 12


#define cID_Record 199
#define cID_Icon_Battery 200
#define cID_Bar1 15

#endif
