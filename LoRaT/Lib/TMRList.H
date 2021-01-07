/*
*********************************************************************************************************
*                                  Embedded Systems Building Blocks
*                               Complete and Ready-to-Use Modules in C
*
*                                             Timer Manager
*
*                            (c) Copyright 1999, Jean J. Labrosse, Weston, FL
*                                           All Rights Reserved
*
* Filename   : TMR.H
* Programmer : Jean J. Labrosse
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                               CONSTANTS
*********************************************************************************************************
*/

#ifndef  CFG_H

#define  TMR_DLY_TICKS       (65535)


#define  TMR_MAX_TMR          5


#endif

#ifdef  TMR_GLOBALS
#define TMR_EXT
#else
#define TMR_EXT  extern
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
    void    (*TmrFnct)(void);                  /* Function to execute when timer times out           */
} TMR;

/*
*********************************************************************************************************
*                                          GLOBAL VARIABLES
*********************************************************************************************************
*/

TMR_EXT  TMR       TmrTbl[TMR_MAX_TMR];          /* Table of timers managed by this module             */

/*
*********************************************************************************************************
*                                          FUNCTION PROTOTYPES
*********************************************************************************************************
*/

void  TmrCfgFnct(uint8_t n, void (*fnct)(void));
uint32_t  TmrChk(uint8_t n);



void  TmrInit(void);

void  TmrReset(uint8_t n);

void  TmrSetTime(uint8_t n, uint32_t ten_ms);
void  TmrStart(uint8_t n);
void  TmrStop(uint8_t n);
void  TmrTask(void);
