/*
 * FILENAME: LTC29_driver.h
 *
 * DESCRIPTION: Header for the LTC2917HMS-B1#PBF watchdog / voltage supervisor driver.
 *
 * AUTHORS:
 *  - Sanjana RoyChowdhury (sanjana.roy@umsats.ca)
 *
 * CREATED ON: May 16, 2023
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef HARDWARE_PERIPHERALS_INC_LTC29_DRIVER_H_
#define HARDWARE_PERIPHERALS_INC_LTC29_DRIVER_H_

//###############################################################################################
//Include Directives
//###############################################################################################
#include "stm32l4xx_hal.h"

//###############################################################################################
//Defines
//###############################################################################################
#define LTC2917_RST_GPIO_Port GPIOA
#define LTC2917_RST_Pin GPIO_PIN_0

#define LTC2917_WDI_GPIO_Port GPIOA
#define LTC2917_WDI_Pin GPIO_PIN_1

//###############################################################################################
//Function Prototypes
//###############################################################################################

void LTC2917_Init();


void LTC2917_Manual_Reset();


void LTC2917_WDI_Toggle();


#endif /* HARDWARE_PERIPHERALS_INC_LTC29_DRIVER_H_ */