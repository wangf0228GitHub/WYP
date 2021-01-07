#ifndef __HardwareProfile_H__
#define __HardwareProfile_H__

#include "stm8l15x_conf.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "FlagDefine.h"
#include "PickParamDefine.h"
#include "Variables.h"
#define Verify_Sum
#include "Verify.h"
#include "delay.h"
#define __delay_us(n) DelayCycle(10)
#include "FRAM.h"

#define CP1616_Client_AddrLen 2
#define CP1616_Client_DataBufLen 2

#define CP1616_Client_NeedCheckVerify
#define CP1616_Client_Tx_OneByOne
#define CP1616_Client_TxByteWithVerify(x) USART_SendData8(USART3,x);sum=(uint8_t)(sum+x)
#define CP1616_Client_TxByte(x) USART_SendData8(USART3,x)
#define CP1616_Client_VerifyProc(pBuf,len) GetVerify_Sum(pBuf,len)
#define CP1616_Client_RxList_LenMax 100

/*!
* Defines the time required for the TCXO to wakeup [ms].
*/
#define BOARD_TCXO_WAKEUP_TIME  5

#define RX_TIMEOUT_TMRNUM	0
#define TX_TIMEOUT_TMRNUM	1
#define CAD_TIMEOUT_TMRNUM	2
#define SystemSleep_TMRNUM	3

#define RF_FREQUENCY                                475500000 // Hz
#define TX_OUTPUT_POWER                             22        // dBm
#define USE_MODEM_LORA                              1




#define LORA_BANDWIDTH                              0           // [0: 125 kHz,
//  1: 250 kHz,
//  2: 500 kHz,
//  3: Reserved]
#define LORA_SPREADING_FACTOR                       12          // [SF7..SF12]
#define LORA_CODINGRATE                             1           // [1: 4/5,
//  2: 4/6,
//  3: 4/7,
//  4: 4/8]
#define LORA_PREAMBLE_LENGTH_TX                     4           // Same for Tx
#define LORA_PREAMBLE_LENGTH_RX                     250         // Same for Rx
#define LORA_SYMBOL_TIMEOUT                         0           // Symbols
#define LORA_FIX_LENGTH_PAYLOAD_ON                  false
#define LORA_IQ_INVERSION_ON                        false


/************************************************************************/
/* Ó²¼þIO¶¨Òå	                                                        */
/************************************************************************/
#define F_MOSI_Pin GPIO_Pin_4
#define F_MOSI_GPIO_Port GPIOF

#define F_WP_Pin GPIO_Pin_5
#define F_WP_GPIO_Port GPIOF

#define F_MISO_Pin GPIO_Pin_6
#define F_MISO_GPIO_Port GPIOF

#define F_CS_Pin GPIO_Pin_7
#define F_CS_GPIO_Port GPIOF

#define F_SCK_Pin GPIO_Pin_7
#define F_SCK_GPIO_Port GPIOB

#define DB0_Pin GPIO_Pin_7
#define DB0_GPIO_Port GPIOC

#define DB1_Pin GPIO_Pin_7
#define DB1_GPIO_Port GPIOE

#define DB2_Pin GPIO_Pin_6
#define DB2_GPIO_Port GPIOE

#define DB3_Pin GPIO_Pin_4
#define DB3_GPIO_Port GPIOC

#define DB4_Pin GPIO_Pin_3
#define DB4_GPIO_Port GPIOC

#define DB5_Pin GPIO_Pin_1
#define DB5_GPIO_Port GPIOC

#define DB6_Pin GPIO_Pin_0
#define DB6_GPIO_Port GPIOC

#define DB7_Pin GPIO_Pin_7
#define DB7_GPIO_Port GPIOG

#define DB8_Pin GPIO_Pin_6
#define DB8_GPIO_Port GPIOD

#define DB9_Pin GPIO_Pin_5
#define DB9_GPIO_Port GPIOD

#define DB10_Pin GPIO_Pin_4
#define DB10_GPIO_Port GPIOD

#define DB11_Pin GPIO_Pin_3
#define DB11_GPIO_Port GPIOF

#define DB12_Pin GPIO_Pin_2
#define DB12_GPIO_Port GPIOF

#define DB13_Pin GPIO_Pin_0
#define DB13_GPIO_Port GPIOF

#define DB14_Pin GPIO_Pin_1
#define DB14_GPIO_Port GPIOF

#define DB15_Pin GPIO_Pin_4
#define DB15_GPIO_Port GPIOE

#define L_REST_Pin GPIO_Pin_5
#define L_REST_GPIO_Port GPIOE

#define L_CS_Pin GPIO_Pin_4
#define L_CS_GPIO_Port GPIOA

#define L_WR_Pin GPIO_Pin_5
#define L_WR_GPIO_Port GPIOA

#define L_RS_Pin GPIO_Pin_6
#define L_RS_GPIO_Port GPIOA

#define L_RD_Pin GPIO_Pin_3
#define L_RD_GPIO_Port GPIOE

#define BLACK_Pin GPIO_Pin_4
#define BLACK_GPIO_Port GPIOB
#define LCD_LED_On() GPIO_WriteBit(BLACK_GPIO_Port,BLACK_Pin,RESET)
#define LCD_LED_Off() GPIO_WriteBit(BLACK_GPIO_Port,BLACK_Pin,SET)


#define T_DP_Pin GPIO_Pin_0
#define T_DP_GPIO_Port GPIOD

#define T_CLK_Pin GPIO_Pin_1
#define T_CLK_GPIO_Port GPIOD

#define T_DIO_Pin GPIO_Pin_2
#define T_DIO_GPIO_Port GPIOD
/************************************************************************/
/* DS1302                                                               */
/************************************************************************/
#define DS1302_RST_Pin GPIO_Pin_3
#define DS1302_RST_GPIO_Port GPIOD

#define DS1302_DATA_Pin GPIO_Pin_4
#define DS1302_DATA_GPIO_Port GPIOH

#define DS1302_CLK_Pin GPIO_Pin_5
#define DS1302_CLK_GPIO_Port GPIOH

#define DS1302_CLK_Low() GPIO_WriteBit(DS1302_CLK_GPIO_Port,DS1302_CLK_Pin,RESET)
#define DS1302_CLK_High() GPIO_WriteBit(DS1302_CLK_GPIO_Port,DS1302_CLK_Pin,SET)

#define DS1302_CE_Low() GPIO_WriteBit(DS1302_RST_GPIO_Port,DS1302_RST_Pin,RESET)
#define DS1302_CE_High() GPIO_WriteBit(DS1302_RST_GPIO_Port,DS1302_RST_Pin,SET)

#define DS1302_DATA_Low() GPIO_WriteBit(DS1302_DATA_GPIO_Port,DS1302_DATA_Pin,RESET)
#define DS1302_DATA_High() GPIO_WriteBit(DS1302_DATA_GPIO_Port,DS1302_DATA_Pin,SET)

#define DS1302_DATA_Read() GPIO_ReadInputDataBit(DS1302_DATA_GPIO_Port,DS1302_DATA_Pin)
#define DS1302_DATA_SetInput() GPIO_Init(DS1302_DATA_GPIO_Port,DS1302_DATA_Pin,GPIO_Mode_In_PU_No_IT)
#define DS1302_DATA_SetOutput() GPIO_Init(DS1302_DATA_GPIO_Port,DS1302_DATA_Pin,GPIO_Mode_Out_PP_Low_Slow)

#define RET_POWER_Pin GPIO_Pin_5
#define RET_POWER_GPIO_Port GPIOB

#define KEY_AN_Pin GPIO_Pin_6
#define KEN_AN_GPIO_Port GPIOB





#endif
