/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define RET_POWER_C_Pin GPIO_PIN_2
#define RET_POWER_C_GPIO_Port GPIOE
#define POWER_I_Pin GPIO_PIN_3
#define POWER_I_GPIO_Port GPIOE
#define sx126X_rxen_Pin GPIO_PIN_4
#define sx126X_rxen_GPIO_Port GPIOE
#define RADIO_BUSY_Pin GPIO_PIN_5
#define RADIO_BUSY_GPIO_Port GPIOE
#define RADIO_RESET_Pin GPIO_PIN_6
#define RADIO_RESET_GPIO_Port GPIOE
#define sx126x_MISO_Pin GPIO_PIN_2
#define sx126x_MISO_GPIO_Port GPIOC
#define sx126x_MOSI_Pin GPIO_PIN_3
#define sx126x_MOSI_GPIO_Port GPIOC
#define RADIO_DIO1_Pin GPIO_PIN_0
#define RADIO_DIO1_GPIO_Port GPIOA
#define RADIO_DIO1_EXTI_IRQn EXTI0_IRQn
#define BT_AD_Pin GPIO_PIN_1
#define BT_AD_GPIO_Port GPIOA
#define sx126x_txen_Pin GPIO_PIN_2
#define sx126x_txen_GPIO_Port GPIOA
#define sx126x_dio2_Pin GPIO_PIN_3
#define sx126x_dio2_GPIO_Port GPIOA
#define F_CS_Pin GPIO_PIN_4
#define F_CS_GPIO_Port GPIOA
#define F_SCK_Pin GPIO_PIN_5
#define F_SCK_GPIO_Port GPIOA
#define F_SO_Pin GPIO_PIN_6
#define F_SO_GPIO_Port GPIOA
#define F_SI_Pin GPIO_PIN_7
#define F_SI_GPIO_Port GPIOA
#define sx126x_SCK_Pin GPIO_PIN_10
#define sx126x_SCK_GPIO_Port GPIOB
#define RADIO_NSS_Pin GPIO_PIN_12
#define RADIO_NSS_GPIO_Port GPIOB
#define w12_Pin GPIO_PIN_14
#define w12_GPIO_Port GPIOB
#define L_RS_Pin GPIO_PIN_11
#define L_RS_GPIO_Port GPIOD
#define L_REST_Pin GPIO_PIN_12
#define L_REST_GPIO_Port GPIOD
#define wbd_Pin GPIO_PIN_8
#define wbd_GPIO_Port GPIOC
#define T_DP_Pin GPIO_PIN_11
#define T_DP_GPIO_Port GPIOA
#define L_RD_Pin GPIO_PIN_4
#define L_RD_GPIO_Port GPIOD
#define L_WR_Pin GPIO_PIN_5
#define L_WR_GPIO_Port GPIOD
#define L_CS_Pin GPIO_PIN_7
#define L_CS_GPIO_Port GPIOD
#define T_CLK_Pin GPIO_PIN_3
#define T_CLK_GPIO_Port GPIOB
#define T_DIO_Pin GPIO_PIN_4
#define T_DIO_GPIO_Port GPIOB
#define DS1302_CLK_Pin GPIO_PIN_5
#define DS1302_CLK_GPIO_Port GPIOB
#define DS1302_DATA_Pin GPIO_PIN_6
#define DS1302_DATA_GPIO_Port GPIOB
#define DS1302_RST_Pin GPIO_PIN_7
#define DS1302_RST_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
