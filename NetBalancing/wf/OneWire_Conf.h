#ifndef __OneWire_Conf_h__
#define __OneWire_Conf_h__

#include "gpio.h"
#include "wfSys.h"

#define ONEWIRE_IOWork_Ex

#define ONEWIRE_SETLOW() DS18B20_SetLow() //输出，且拉低
#define ONEWIRE_GETIN() HAL_GPIO_ReadPin(DS18B20_GPIO_Port,DS18B20_Pin) //读io
#define ONEWIRE_SETHIGH() DS18B20_SetHigh() //输入即可

#define OneWire_ReadDelayOffSet 4

#define OneWire_Delay_us(x) wfDelay_us(x);

#endif


