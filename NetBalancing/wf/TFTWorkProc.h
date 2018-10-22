#ifndef __TFTWorkProc_H__
#define __TFTWorkProc_H__

#include "main.h"
#include "TypeDefine.h"

#define ItemCountOfBarCharts 20
#define ItemCountOfRecord 10

typedef union   
{
	struct
	{	
		uint32_t bWaitReset:1;//判断当前是否为主动复位
		uint32_t bWaitRTC:1;//判断是否接收的触屏的RTC数据
		uint32_t bWaitControlValue:1;//判断是否接收到指定控件的值

	};
	uint32_t AllFlag;
} _TFTWaitCommandFlags;        // general flags

extern _TFTWaitCommandFlags TFTWaitCommandFlags;

typedef union   
{
	struct
	{		
		uint32_t bRxReset:1;//判断是否复位完成
		uint32_t bRxRTC:1;//判断是否接收的触屏的RTC数据
		uint32_t bRxControlValue:1;//判断是否接收到指定控件的值
	};
	uint32_t AllFlag;
} _TFTNotifyCommandFlags;        // general flags

extern _TFTNotifyCommandFlags TFTNotifyCommandFlags; 

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
	unsigned char All[7];
} _RTCData; 
extern _RTCData RTCData;
//对话框自动跳转回的屏幕id
extern uint32_t autoReturnSID;

void ShouYe_ButtonProc(uint16_t control_id);
uint32_t JumpButtonProc(uint16_t control_id);
void ReadRTC(void);
uint32_t ReadTextbox(unsigned char sID,unsigned char cID);
void ShowFailDialog(uint32_t returnSID,uint8_t* str);
void ShowSuccessDialog(uint32_t returnSID);
void ResetTFT(void);
void TFTRxCheck(void);
void myRecordClear(unsigned char sID,unsigned char cID,unsigned char count);
/************************************************************************/
/* 通用控件ID                                                           */
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

#define cID_btConfirm 40

#define cID_Record 199
#define cID_Icon_Battery 200
#define cID_Timer 201
#define cID_Bar1 60
#define cID_Bar1Text 80
#define cID_Bar1Text_1 40
#define cID_PageNum 197

#define sID_Success 28
#define sID_Fail 29

#endif
