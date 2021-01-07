/*
*********************************************************************************************************
*                                  Embedded Systems Building Blocks
*                               Complete and Ready-to-Use Modules in C
*
*                                            Timer Manager
*
*                           (c) Copyright 1999, Jean J. Labrosse, Weston, FL
*                                          All Rights Reserved
*
* Filename   : TMR.C
* Programmer : Jean J. Labrosse
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                           INCLUDE FILES
*********************************************************************************************************
*/

#define  TMR_GLOBALS
#include "board.h"

/*
*********************************************************************************************************
*                                          LOCAL VARIABLES
*********************************************************************************************************
*/



/*
*********************************************************************************************************
*                                      LOCAL FUNCTION PROTOTYPES
*********************************************************************************************************
*/

void        TmrTask(void);

/*$PAGE*/
/*
*********************************************************************************************************
*                                   CONFIGURE TIMER TIMEOUT FUNCTION
*
* Description : Set the user defined function when the timer expires.
* Arguments   : n         is the timer number 0..TMR_MAX_TMR-1
*               fnct      is a pointer to a function that will be executed when the timer expires
*               arg       is a pointer to an argument that is passed to 'fnct'
* Returns     : None.
*********************************************************************************************************
*/

void  TmrCfgFnct (uint8_t n, void (*fnct)(void))
{
    TMR *ptmr;


    if (n < TMR_MAX_TMR) {
        ptmr             = &TmrTbl[n];
        BoardDisableIrq();
        ptmr->TmrFnct    = fnct;                 /* Store pointer to user function into timer          */
 //       ptmr->TmrFnctArg = arg;                  /* Store user's function arguments pointer            */
        BoardEnableIrq();
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                             CHECK TIMER
*
* Description : This function checks to see if a timer has expired
* Arguments   : n      is the timer to check
* Returns     : 0      if the timer has expired
*               TmrCtr the remaining time before the timer expires in 1/10 second
*********************************************************************************************************
*/

uint32_t  TmrChk (uint8_t n)
{
    uint32_t val;


    val = 0;
    if (n < TMR_MAX_TMR) {
        BoardDisableIrq();
        val = TmrTbl[n].TmrCtr;
        BoardEnableIrq();
    }
    return (val);
}



/*$PAGE*/
/*
*********************************************************************************************************
*                                     TIMER MANAGER INITIALIZATION
*
* Description : This function initializes the timer manager module.
* Arguments   : None
* Returns     : None.
*********************************************************************************************************
*/

void  TmrInit (void)
{
    uint8_t  i;
    TMR   *ptmr;


    ptmr = &TmrTbl[0];
    for (i = 0; i < TMR_MAX_TMR; i++) {          /* Clear and disable all timers                       */
        ptmr->TmrEn   = false;
        ptmr->TmrCtr  = 0;
        ptmr->TmrInit = 0;
        ptmr->TmrFnct = NULL;
        ptmr++;
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                             RESET TIMER
*
* Description : This function reloads a timer with its initial value
* Arguments   : n         is the timer to reset
* Returns     : None.
*********************************************************************************************************
*/

void  TmrReset (uint8_t n)
{
    TMR *ptmr;


    if (n < TMR_MAX_TMR) {
        ptmr         = &TmrTbl[n];
        BoardDisableIrq();
        ptmr->TmrCtr = ptmr->TmrInit;       /* Reload the counter                                      */
        BoardEnableIrq();
    }
}


/*$PAGE*/
/*
*********************************************************************************************************
*                               SET TIMER (SPECIFYING TENTHS OF SECOND)
*
* Description : Set the timer with the specified number of 1/10 seconds.
* Arguments   : n         is the timer number 0..TMR_MAX_TMR-1
*               tenths    is the number of 1/10 second to load into the timer
* Returns     : None.
*********************************************************************************************************
*/

void  TmrSetTime (uint8_t n, uint32_t ten_ms)
{
    TMR *ptmr;


    if (n < TMR_MAX_TMR) {
        ptmr          = &TmrTbl[n];
        BoardDisableIrq();
        ptmr->TmrInit = ten_ms;
        ptmr->TmrCtr  = ten_ms;
        BoardEnableIrq();
    }
}


/*$PAGE*/
/*
*********************************************************************************************************
*                                             START TIMER
*
* Description : This function start a timer
* Arguments   : n         is the timer to start
* Returns     : None.
*********************************************************************************************************
*/

void  TmrStart (uint8_t n)
{
    if (n < TMR_MAX_TMR) {
        BoardDisableIrq();
        TmrTbl[n].TmrEn = true;
        if (TmrTbl[n].TmrInit != 0)
        {
            TmrTbl[n].TmrCtr = TmrTbl[n].TmrInit;
        }
        BoardEnableIrq();
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                             STOP TIMER
*
* Description : This function stops a timer
* Arguments   : n         is the timer to stop
* Returns     : None.
*********************************************************************************************************
*/

void  TmrStop (uint8_t n)
{
    if (n < TMR_MAX_TMR) {
        BoardDisableIrq();
        TmrTbl[n].TmrEn = false;
        BoardEnableIrq();
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                          TIMER MANAGER TASK
*
* Description : This task is created by TmrInit() and is responsible for updating the timers.
*               TmrTask() executes every 1/10 of a second.
* Arguments   : None.
* Returns     : None.
* Note(s)     : 1) The function to execute when a timer times out is executed outside the critical
*                  section.
*********************************************************************************************************
*/

void  TmrTask (void)
{
    TMR    *ptmr;
    uint8_t   i;
    void  (*pfnct)(void);                           /* Function to execute when timer times out      */

    

    pfnct = (void (*)(void))0;                      /* Start off with no function to execute         */
    ptmr = &TmrTbl[0];                                /* Point at beginning of timer table             */

                                
    for (i = 0; i < TMR_MAX_TMR; i++) {
//        BoardDisableIrq();
        if (ptmr->TmrEn == true) {                /* Decrement timer only if it is enabled         */
            if (ptmr->TmrCtr > 0) {
                ptmr->TmrCtr--;
                if (ptmr->TmrCtr == 0) {               /* See if timer expired                     */
                    ptmr->TmrEn = false;               /* Yes, stop timer                          */
                    pfnct       = ptmr->TmrFnct;       /* Get pointer to function to execute ...   */

                }
            }
        }
//        BoardEnableIrq();
        if (pfnct != (void (*)(void))0) {       /* See if we need to execute function for ...    */
            (*pfnct)();                       /* ... timed out timer.                          */
            pfnct = (void (*)(void))0;
        }
        ptmr++;
    }
}
