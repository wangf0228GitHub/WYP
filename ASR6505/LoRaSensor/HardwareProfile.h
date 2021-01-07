#ifndef __HardwareProfile_H__
#define __HardwareProfile_H__

#include "stm8l15x_conf.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "FlagDefine.h"
#include "WirelessParam\WirelessParam.h"
#include "Variables.h"
#define Verify_CRC8
#define Verify_Sum
#include "Verify.h"
#include "delay.h"
#define __delay_us(n) DelayCycle(10*n)

#define DS18B20_Pin GPIO_Pin_5
#define DS18B20_GPIO_Port GPIOD

#define ONEWIRE_IOWork_Ex
#define ONEWIRE_SETLOW() GPIO_Init(DS18B20_GPIO_Port,DS18B20_Pin,GPIO_Mode_Out_OD_Low_Slow) //输出，且拉低
#define ONEWIRE_GETIN() GPIO_ReadInputDataBit(DS18B20_GPIO_Port,DS18B20_Pin) //读io
#define ONEWIRE_SETHIGH() GPIO_Init(DS18B20_GPIO_Port,DS18B20_Pin,GPIO_Mode_In_FL_No_IT) //输入即可

#define OneWire_ReadDelayOffSet 4

#define OneWire_Delay_us(x) __delay_us(x);


#define Move_Pin GPIO_Pin_5
#define Move_GPIO_Port GPIOD
#define bDeviceMove() (GPIO_ReadInputDataBit(Move_GPIO_Port,Move_Pin)==RESET)
//#define RXTEST
// #define TXTEST
// #define RXTXTEST
// #define TXRXTEST



/************************************************************************/
/* 硬件IO定义	                                                        */
/************************************************************************/

#endif
