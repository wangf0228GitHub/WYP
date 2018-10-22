/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2018 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H__
#define __MAIN_H__

/* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */
#include "stm32f1xx_hal.h"
#include "FlagDefine.h"
/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define DS18B20_Pin GPIO_PIN_13
#define DS18B20_GPIO_Port GPIOC
#define RUN_LED_C_Pin GPIO_PIN_1
#define RUN_LED_C_GPIO_Port GPIOC
#define BUTTON_Pin GPIO_PIN_2
#define BUTTON_GPIO_Port GPIOC
#define STATUS2MCU_Pin GPIO_PIN_3
#define STATUS2MCU_GPIO_Port GPIOC
#define RF_IRQ_Pin GPIO_PIN_0
#define RF_IRQ_GPIO_Port GPIOA
#define RF_IRQ_EXTI_IRQn EXTI0_IRQn
#define GSM_PWR_Pin GPIO_PIN_1
#define GSM_PWR_GPIO_Port GPIOA
#define RET_POWER_C_Pin GPIO_PIN_4
#define RET_POWER_C_GPIO_Port GPIOA
#define BT_AD_Pin GPIO_PIN_5
#define BT_AD_GPIO_Port GPIOA
#define POWER_I_Pin GPIO_PIN_6
#define POWER_I_GPIO_Port GPIOA
#define RF_SCLK_Pin GPIO_PIN_13
#define RF_SCLK_GPIO_Port GPIOB
#define RF_MISO_Pin GPIO_PIN_14
#define RF_MISO_GPIO_Port GPIOB
#define RF_MOSI_Pin GPIO_PIN_15
#define RF_MOSI_GPIO_Port GPIOB
#define RF_SDN_Pin GPIO_PIN_6
#define RF_SDN_GPIO_Port GPIOC
#define RF_CSN_Pin GPIO_PIN_7
#define RF_CSN_GPIO_Port GPIOC
#define FM25V10_CS_Pin GPIO_PIN_8
#define FM25V10_CS_GPIO_Port GPIOC
#define FM25V10_SCLK_Pin GPIO_PIN_9
#define FM25V10_SCLK_GPIO_Port GPIOC
#define FM25V10_MOSI_Pin GPIO_PIN_8
#define FM25V10_MOSI_GPIO_Port GPIOA
#define TFTBusy_Pin GPIO_PIN_11
#define TFTBusy_GPIO_Port GPIOA
#define FM25V10_MISO_Pin GPIO_PIN_12
#define FM25V10_MISO_GPIO_Port GPIOA

/* ########################## Assert Selection ############################## */
/**
  * @brief Uncomment the line below to expanse the "assert_param" macro in the 
  *        HAL drivers code
  */
/* #define USE_FULL_ASSERT    1U */

/* USER CODE BEGIN Private defines */
#define Verify_Sum
#define Verify_CRC8
#define TemperatureSensor 1
#define PressureSensor 0
#define bRFIRQ() (HAL_GPIO_ReadPin(RF_IRQ_GPIO_Port,RF_IRQ_Pin)==GPIO_PIN_RESET)
extern _gFlags gFlags;
/* USER CODE END Private defines */

#ifdef __cplusplus
 extern "C" {
#endif
void _Error_Handler(char *, int);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)
#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
