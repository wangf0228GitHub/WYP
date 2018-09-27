#ifndef __SIM800CProc_h__
#define __SIM800CProc_h__

#include "main.h"
#include "ATCommand.h"

extern uint8_t ErrState;
extern uint8_t txChar;
enum {NoErr=0,Miss900a,MissAT,MissSimCard,MissNet,ErrMSG,ErrCSQ,	
	MissAT_CPMS,MissAT_CMGR,MissAT_CMGDA,MissAT_ATH,MissAT_ATE1,MissAT_CNMI
	,MissAT_CMGF,MissAT_CSQ,MissAT_COPS,MissAT_COLP,MissAT_CLCC,MissPower,
	MissAT_CIPCLOSE,MissAT_CIPSHUT,MissAT_CGCLASS,MissAT_CGDCONT,MissAT_CGATT,
	MissAT_CIPCSGP,MissAT_CSTT,MissAT_CIICR,MissAT_CIFSR,MissAT_CIPSTART,
	MissAT_CIPSEND,MissAT_SendData,MissAT_NoServerData,MissAT_ErrServerData,MissAT_ServerClose};
uint8_t SIM800C_PowerON(void);
uint8_t SIM800C_PowerDown(void);
#endif // __WirelessProc_h__
