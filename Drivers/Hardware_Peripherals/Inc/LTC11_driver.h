/*
 * FILENAME: LTC11_driver.h
 *
 * DESCRIPTION: Header for the LTC1154HS8#PBF high side micropower MOSFET drivers.
 *
 * AUTHORS:
 *  - Sanjana RoyChowdhury (sanjana.roy@umsats.ca)
 *
 * CREATED ON: May 16, 2023
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef HARDWARE_PERIPHERALS_INC_LTC11_DRIVER_H_
#define HARDWARE_PERIPHERALS_INC_LTC11_DRIVER_H_

//###############################################################################################
//Include Directives
//###############################################################################################
#include "stm32l4xx_hal.h"

//###############################################################################################
//Defines
//###############################################################################################

// definitions for battery heater mosfet driver 
#define LTC1154_HEATER_GPIO_Port      GPIOB
#define LTC1154_HEATER_GPIO_S_Port    Heat_Status_GPIO_Port
#define LTC1154_HEATER_ENABLE_PIN     Heat_EN_Pin
#define LTC1154_HEATER_STATUS_PIN     Heat_Status_Pin
#define LTC1154_HEATER_IN_PIN         Heat_In_Pin

// definitions for BATV NESS mosfet drivers
#define LTC1154_BATV_1_GPIO_Port       GPIOB
#define LTC1154_BATV_1_ENABLE_PIN      BatV1_EN_Pin
#define LTC1154_BATV_1_STATUS_PIN      BatV1_Status_Pin
#define LTC1154_BATV_1_IN_PIN          BatV1_In_Pin

#define LTC1154_BATV_2_GPIO_Port       GPIOB
#define LTC1154_BATV_2_ENABLE_PIN      BatV2_EN_Pin
#define LTC1154_BATV_2_STATUS_PIN      BatV2_Status_Pin
#define LTC1154_BATV_2_IN_PIN          BatV2_In_Pin



//###############################################################################################
//Prototypes
//###############################################################################################

// prototypes for battery heater mosfet driver 
//void LTC1154_HEATER_Init(void);

GPIO_PinState LTC1154_HEATER_GetStatus(void);

void LTC1154_HEATER_SetEnable(GPIO_PinState state);

void LTC1154_HEATER_SetIn(GPIO_PinState state);



// prototypes for BATV NESS mosfet driver 1

//void LTC1154_BATV_1_Init(void);

GPIO_PinState LTC1154_BATV_1_GetStatus(void);

void LTC1154_BATV_1_SetEnable(GPIO_PinState state);

void LTC1154_BATV_1_SetIn(GPIO_PinState state);


// prototypes for BATV NESS mosfet driver 2

//void LTC1154_BATV_2_Init(void);

GPIO_PinState LTC1154_BATV_2_GetStatus(void);

void LTC1154_BATV_2_SetEnable(GPIO_PinState state);

void LTC1154_BATV_2_SetIn(GPIO_PinState state);

#endif /* HARDWARE_PERIPHERALS_INC_LTC11_DRIVER_H_ */



