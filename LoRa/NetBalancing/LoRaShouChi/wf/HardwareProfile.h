#ifndef __HardwareProfile_H__
#define __HardwareProfile_H__

#include "gpio.h"

#define Verify_Sum
#include "Verify.h"

#include "Key.h"
#include "Variables.h"
#define SystemSleep_TMRNUM	3
/************************************************************************/
/* ds1302                                                               */
/************************************************************************/
#define DS1302_CLK_Low() HAL_GPIO_WritePin(DS1302_CLK_GPIO_Port,DS1302_CLK_Pin,GPIO_PIN_RESET)
#define DS1302_CLK_High() HAL_GPIO_WritePin(DS1302_CLK_GPIO_Port,DS1302_CLK_Pin,GPIO_PIN_SET)

#define DS1302_CE_Low() HAL_GPIO_WritePin(DS1302_RST_GPIO_Port,DS1302_RST_Pin,GPIO_PIN_RESET)
#define DS1302_CE_High() HAL_GPIO_WritePin(DS1302_RST_GPIO_Port,DS1302_RST_Pin,GPIO_PIN_SET)

#define DS1302_DATA_Low() HAL_GPIO_WritePin(DS1302_DATA_GPIO_Port,DS1302_DATA_Pin,GPIO_PIN_RESET)
#define DS1302_DATA_High() HAL_GPIO_WritePin(DS1302_DATA_GPIO_Port,DS1302_DATA_Pin,GPIO_PIN_SET)

#define DS1302_DATA_Read() HAL_GPIO_ReadPin(DS1302_DATA_GPIO_Port,DS1302_DATA_Pin)

#define DS1302_DATA_SetInput() GPIO_InitTypeDef GPIO_InitStruct_Out;  \
	GPIO_InitStruct_Out.Pin = DS1302_DATA_Pin;  \
	GPIO_InitStruct_Out.Mode = GPIO_MODE_OUTPUT_PP;  \
	GPIO_InitStruct_Out.Pull = GPIO_NOPULL;  \
	GPIO_InitStruct_Out.Speed = GPIO_SPEED_FREQ_HIGH;  \
	HAL_GPIO_Init(DS1302_DATA_GPIO_Port, &GPIO_InitStruct_Out);	

#define DS1302_DATA_SetOutput() GPIO_InitTypeDef GPIO_InitStruct_In;  \
	GPIO_InitStruct_In.Pin = DS1302_DATA_Pin;  \
	GPIO_InitStruct_In.Mode = GPIO_MODE_INPUT;  \
	GPIO_InitStruct_In.Pull = GPIO_NOPULL;  \
	HAL_GPIO_Init(DS1302_DATA_GPIO_Port, &GPIO_InitStruct_In);



#include "FRAM.h"

#include "wfSys.h"
#define __delay_us(n) wfDelay_us(n)
#define DelayMs(n) HAL_Delay(n)
#define disableInterrupts() __disable_irq()
#define enableInterrupts() __enable_irq()

#define CP1616_Client_AddrLen 2
#define CP1616_Client_DataBufLen 2

#define CP1616_Client_NeedCheckVerify
#include "usart.h"
#define CP1616_Client_TxProc(List,Index) HAL_UART_Transmit(&huart1,List,Index,1000)
#define CP1616_Client_VerifyProc(pBuf,len) GetVerify_Sum(pBuf,len)
#define CP1616_Client_RxList_LenMax 100
#define CP1616_Client_TxList_LenMax 100

#define LCD_BG_ON() 


#define SimI2C_Delay_Ex
#define SimI2C_Delay() wfDelay_ms(1);


#define SIMI2C_SCL_Low() HAL_GPIO_WritePin(T_CLK_GPIO_Port,T_CLK_Pin,GPIO_PIN_RESET)
#define SIMI2C_SCL_High() HAL_GPIO_WritePin(T_CLK_GPIO_Port,T_CLK_Pin,GPIO_PIN_SET)

#define SIMI2C_SDA_Low() HAL_GPIO_WritePin(T_DIO_GPIO_Port,T_DIO_Pin,GPIO_PIN_RESET)
#define SIMI2C_SDA_High() HAL_GPIO_WritePin(T_DIO_GPIO_Port,T_DIO_Pin,GPIO_PIN_SET)

#define SIMI2C_SDA_Read() HAL_GPIO_ReadPin(T_DIO_GPIO_Port,T_DIO_Pin)

#define SIMI2C_SDA_OUT() GPIO_InitTypeDef GPIO_InitStruct_Out;  \
	GPIO_InitStruct_Out.Pin = T_DIO_Pin;  \
	GPIO_InitStruct_Out.Mode = GPIO_MODE_OUTPUT_PP;  \
	GPIO_InitStruct_Out.Pull = GPIO_PULLUP;  \
	GPIO_InitStruct_Out.Speed = GPIO_SPEED_FREQ_MEDIUM;  \
	HAL_GPIO_Init(T_DIO_GPIO_Port, &GPIO_InitStruct_Out);	

#define SIMI2C_SDA_IN() GPIO_InitTypeDef GPIO_InitStruct_In;  \
	GPIO_InitStruct_In.Pin = T_DIO_Pin;  \
	GPIO_InitStruct_In.Mode = GPIO_MODE_INPUT;  \
	GPIO_InitStruct_In.Pull = GPIO_PULLUP;  \
	HAL_GPIO_Init(T_DIO_GPIO_Port, &GPIO_InitStruct_In);
#endif
