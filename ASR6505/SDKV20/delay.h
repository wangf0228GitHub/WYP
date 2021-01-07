#ifndef __DELAY_H__
#define __DELAY_H__
#include "HardwareProfile.h"
/*! 
 * Blocking delay of "s" seconds
 */
void Delay( float s );

/*! 
 * Blocking delay of "ms" milliseconds
 *  π”√TIM4
 */
void DelayMs( uint32_t ms );

void DelayCycle(uint32_t nCount);
#endif // __DELAY_H__

