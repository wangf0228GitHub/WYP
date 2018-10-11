#ifndef __Si4463_Conf_h__
#define __Si4463_Conf_h__

#include "gpio.h"
#include "wfSys.h"
#include "SimSPI.h"
#include "PickParamDefine.h"


#define Si4463_NSEL_Low() HAL_GPIO_WritePin(RF_CSN_GPIO_Port,RF_CSN_Pin,GPIO_PIN_RESET)
#define Si4463_NSEL_High() HAL_GPIO_WritePin(RF_CSN_GPIO_Port,RF_CSN_Pin,GPIO_PIN_SET)

#define Si4463_SDN_Low() HAL_GPIO_WritePin(RF_SDN_GPIO_Port,RF_SDN_Pin,GPIO_PIN_RESET)
#define Si4463_SDN_High() HAL_GPIO_WritePin(RF_SDN_GPIO_Port,RF_SDN_Pin,GPIO_PIN_SET)

#define Si4463_SPIInit() SimSPI_Init()
#define Si4463_SPIProc(x) SimSPI_Proc(x)


#endif


