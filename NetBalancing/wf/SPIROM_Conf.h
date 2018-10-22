#ifndef __SPIROM_Conf_h__
#define __SPIROM_Conf_h__

#include "gpio.h"
#include "SimSPI.h"


#define SPIROM_CS_Low() HAL_GPIO_WritePin(FM25V10_CS_GPIO_Port,FM25V10_CS_Pin,GPIO_PIN_RESET)
#define SPIROM_CS_High() HAL_GPIO_WritePin(FM25V10_CS_GPIO_Port,FM25V10_CS_Pin,GPIO_PIN_SET)

#define SPIROM_Addr24
#define SPIROM_SPIProc(x) SimSPI2_Proc(x);     

#endif


