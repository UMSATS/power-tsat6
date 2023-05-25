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

#ifdef __cplusplus"
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"
#include "commands.h"
#include "can_message_queue.h"

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
#define ADC2_Dout_Pin GPIO_PIN_2
#define ADC2_Dout_GPIO_Port GPIOC
#define ADC2_Din_Pin GPIO_PIN_3
#define ADC2_Din_GPIO_Port GPIOC
#define ADC1_CS_Pin GPIO_PIN_0
#define ADC1_CS_GPIO_Port GPIOA
#define ADC1_CLCK_Pin GPIO_PIN_1
#define ADC1_CLCK_GPIO_Port GPIOA
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define LD4_Pin GPIO_PIN_5
#define LD4_GPIO_Port GPIOA
#define ADC1_Dout_Pin GPIO_PIN_6
#define ADC1_Dout_GPIO_Port GPIOA
#define ADC1_Din_Pin GPIO_PIN_7
#define ADC1_Din_GPIO_Port GPIOA
#define MPPT_Y_POS_SHDN_Pin GPIO_PIN_4
#define MPPT_Y_POS_SHDN_GPIO_Port GPIOC
#define MPPT_Y_NEG_SHDN_Pin GPIO_PIN_5
#define MPPT_Y_NEG_SHDN_GPIO_Port GPIOC
#define MPPT_X_POS_SHDN_Pin GPIO_PIN_0
#define MPPT_X_POS_SHDN_GPIO_Port GPIOB
#define MPPT_X_NEG_SHDN_Pin GPIO_PIN_1
#define MPPT_X_NEG_SHDN_GPIO_Port GPIOB
#define ADC2_CS_Pin GPIO_PIN_2
#define ADC2_CS_GPIO_Port GPIOB
#define ADC2_CLCK_Pin GPIO_PIN_10
#define ADC2_CLCK_GPIO_Port GPIOB
#define ADC3_CS_Pin GPIO_PIN_15
#define ADC3_CS_GPIO_Port GPIOB
#define WD_RST_Pin GPIO_PIN_6
#define WD_RST_GPIO_Port GPIOC
#define WD_WDI_Pin GPIO_PIN_7
#define WD_WDI_GPIO_Port GPIOC
#define CC_SHDN_Pin GPIO_PIN_8
#define CC_SHDN_GPIO_Port GPIOC
#define CC_CLR_Pin GPIO_PIN_9
#define CC_CLR_GPIO_Port GPIOC
#define CC_Pol_Pin GPIO_PIN_8
#define CC_Pol_GPIO_Port GPIOA
#define CC_Int_Pin GPIO_PIN_9
#define CC_Int_GPIO_Port GPIOA
#define Battery_PWR_Pin GPIO_PIN_10
#define Battery_PWR_GPIO_Port GPIOA
#define ADCS_PWR_Pin GPIO_PIN_11
#define ADCS_PWR_GPIO_Port GPIOA
#define Payload_PWR_Pin GPIO_PIN_12
#define Payload_PWR_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define BatV2_Status_Pin GPIO_PIN_15
#define BatV2_Status_GPIO_Port GPIOA
#define ADC3_CLCK_Pin GPIO_PIN_10
#define ADC3_CLCK_GPIO_Port GPIOC
#define ADC3_Dout_Pin GPIO_PIN_11
#define ADC3_Dout_GPIO_Port GPIOC
#define ADC3_Din_Pin GPIO_PIN_12
#define ADC3_Din_GPIO_Port GPIOC
#define BatV2_In_Pin GPIO_PIN_2
#define BatV2_In_GPIO_Port GPIOD
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
#define BatV2_EN_Pin GPIO_PIN_4
#define BatV2_EN_GPIO_Port GPIOB
#define BatV1_Status_Pin GPIO_PIN_5
#define BatV1_Status_GPIO_Port GPIOB
#define BatV1_In_Pin GPIO_PIN_6
#define BatV1_In_GPIO_Port GPIOB
#define BatV1_EN_Pin GPIO_PIN_7
#define BatV1_EN_GPIO_Port GPIOB
#define Heat_Status_Pin GPIO_PIN_3
#define Heat_Status_GPIO_Port GPIOH
#define Heat_In_Pin GPIO_PIN_8
#define Heat_In_GPIO_Port GPIOB
#define Heat_EN_Pin GPIO_PIN_9
#define Heat_EN_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
