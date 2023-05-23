/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32l4xx_hal.h"

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
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define PGOOD_Pin GPIO_PIN_0
#define PGOOD_GPIO_Port GPIOC
#define RUN_Pin GPIO_PIN_1
#define RUN_GPIO_Port GPIOC
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define LD4_Pin GPIO_PIN_5
#define LD4_GPIO_Port GPIOA
#define MPPT_Y_POS_SHDN_Pin GPIO_PIN_4
#define MPPT_Y_POS_SHDN_GPIO_Port GPIOC
#define MPPT_Y_NEG_SHDN_Pin GPIO_PIN_5
#define MPPT_Y_NEG_SHDN_GPIO_Port GPIOC
#define MPPT_X_POS_SHDN_Pin GPIO_PIN_0
#define MPPT_X_POS_SHDN_GPIO_Port GPIOB
#define MPPT_X_NEG_SHDN_Pin GPIO_PIN_1
#define MPPT_X_NEG_SHDN_GPIO_Port GPIOB
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
#define TPS22810_GPIO_Port                     GPIOB
#define TPS22810_PAYLOAD_PWR_EN_PIN            GPIO_PIN_11
#define TPS22810_ADCS_PWR_EN_PIN               GPIO_PIN_12
#define TPS22810_BAT_PWR_EN_PIN                GPIO_PIN_13
#define LTC4150IMS_INT_PIN GPIO_PIN_11
#define LTC4150IMS_GPIO_Port GPIOC
#define LTC4150IMS_POL_PIN GPIO_PIN_12
#define LTC4150IMS_CLR_PIN GPIO_PIN_14
#define LTC4150IMS_SHDN_PIN GPIO_PIN_15
#define LTC2917_GPIO_Port GPIOA
#define LTC2917_RST_Pin GPIO_PIN_0
#define LTC2917_WDI_Pin GPIO_PIN_1
#define LTC1154_HEATER_GPIO_Port      GPIOA
#define LTC1154_HEATER_ENABLE_PIN     GPIO_PIN_4
#define LTC1154_HEATER_STATUS_PIN     GPIO_PIN_10
#define LTC1154_HEATER_IN_PIN         GPIO_PIN_11
#define LTC1154_BATV_1_GPIO_Port      GPIOB
#define LTC1154_BATV_1_ENABLE_PIN     GPIO_PIN_2
#define LTC1154_BATV_1_STATUS_PIN     GPIO_PIN_4
#define LTC1154_BATV_1_IN_PIN         GPIO_PIN_10
#define LTC1154_BATV_2_GPIO_Port      GPIOC
#define LTC1154_BATV_2_ENABLE_PIN     GPIO_PIN_2
#define LTC1154_BATV_2_STATUS_PIN     GPIO_PIN_3
#define LTC1154_BATV_2_IN_PIN         GPIO_PIN_10
#define ADC1_GPIO_PORT  GPIOA
#define ADC1_DIN_PIN    GPIO_PIN_6
#define ADC1_DOUT_PIN   GPIO_PIN_7
#define ADC1_CS_PIN     GPIO_PIN_8
#define ADC1_SCLK_PIN   GPIO_PIN_9
#define ADC2_GPIO_PORT  GPIOB
#define ADC2_DIN_PIN    GPIO_PIN_6
#define ADC2_DOUT_PIN   GPIO_PIN_7
#define ADC2_CS_PIN     GPIO_PIN_8
#define ADC2_SCLK_PIN   GPIO_PIN_9
#define ADC3_GPIO_PORT  GPIOC
#define ADC3_DIN_PIN    GPIO_PIN_6
#define ADC3_DOUT_PIN   GPIO_PIN_7
#define ADC3_CS_PIN     GPIO_PIN_8
#define ADC3_SCLK_PIN   GPIO_PIN_9







/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
