#ifndef TMRList_h__
#define TMRList_h__

#include "HardwareProfile.h"
#include <stdbool.h>

#ifndef  CFG_TMRList
#define  TMR_DLY_TICKS       (65535)
#define  TMR_MAX_TMR          5
#endif

/*
*********************************************************************************************************
*                                             DATA TYPES
*********************************************************************************************************
*/

typedef struct tmr {                             /* TIMER DATA STRUCTURE                               */
	bool   TmrEn;                                /* Flag indicating whether timer is enabled           */
	uint32_t    TmrCtr;                            /* Current value of timer (counting down)             */
	uint32_t    TmrInit;                           /* Initial value of timer (i.e. when timer is set)    */
	void(*TmrFnct)(void);                  /* Function to execute when timer times out           */
} TMR;

/*
*********************************************************************************************************
*                                          GLOBAL VARIABLES
*********************************************************************************************************
*/

extern TMR TmrTbl[TMR_MAX_TMR];          /* Table of timers managed by this module             */

/*
*********************************************************************************************************
*                                          FUNCTION PROTOTYPES
*********************************************************************************************************
*/

void  TmrCfgFnct(uint8_t n, void(*fnct)(void));
uint32_t  TmrChk(uint8_t n);
void  TmrListInit(void);
void  TmrReset(uint8_t n);
void  TmrSetTime(uint8_t n, uint32_t N10ms);
void  TmrStart(uint8_t n);
void  TmrStop(uint8_t n);
void  TmrTask(void);


#endif // TMRList_h__
