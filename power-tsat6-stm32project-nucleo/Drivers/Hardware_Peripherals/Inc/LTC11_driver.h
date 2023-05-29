/*
 * FILENAME: LTC11_driver.h
 *
 * DESCRIPTION: Header file for the LTC1154HS8#PBF high side micropower MOSFET drivers.
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

// definitions for BATV mosfet driver
#define LTC1154_BATV_1_GPIO_Port       GPIOB
#define LTC1154_BATV_1_ENABLE_PIN      BatV1_EN_Pin
#define LTC1154_BATV_1_STATUS_PIN      BatV1_Status_Pin
#define LTC1154_BATV_1_IN_PIN          BatV1_In_Pin

//###############################################################################################
//Prototypes
//###############################################################################################


/*
 * FUNCTION: LTC1154_HEATER_GetStatus
 *
 * DESCRIPTION: Reads and returns state of battery heater. 
 */

GPIO_PinState LTC1154_HEATER_GetStatus(void);


/*
 * FUNCTION: LTC1154_HEATER_SetEnable
 *
 * DESCRIPTION: Controls the functionality of the Battery heater.
 * 
 * PARAMETERS:
 * state: state (high or low) of battery heater.
 */

void LTC1154_HEATER_SetEnable(GPIO_PinState state);


/*
 * FUNCTION: LTC1154_HEATER_SetIn
 *
 * DESCRIPTION: Controls the switching operation of the battery heater (conducting or non conducting).
 * 
 * PARAMETERS:
 * state: state (high or low) of battery heater.
 */

void LTC1154_HEATER_SetIn(GPIO_PinState state);


/*
 * FUNCTION: LTC1154_HEATER_ON
 *
 * DESCRIPTION: Turn battery heater on.
 */

void LTC1154_HEATER_ON(void);


/*
 * FUNCTION: LTC1154_Heater_OFF
 *
 * DESCRIPTION: Turn battery heater off.
 */

void LTC1154_Heater_OFF(void);



/*
 * FUNCTION: LTC1154_BATV_1_GetStatus
 *
 * DESCRIPTION: Reads and returns state of battery voltage . 
 */

GPIO_PinState LTC1154_BATV_1_GetStatus(void);


/*
 * FUNCTION: LTC1154_BATV_1_SetEnable
 *
 * DESCRIPTION: Controls the functionality of the Battery voltage.
 * 
 * PARAMETERS:
 * state: state (high or low) of battery voltage.
 */


void LTC1154_BATV_1_SetEnable(GPIO_PinState state);


/*
 * FUNCTION: LTC1154_BATV_1_SetIn
 *
 * DESCRIPTION: Controls the switching operation of the battery voltage (conducting or non conducting).
 * 
 * PARAMETERS:
 * state: state (high or low) of battery voltage.
 */

void LTC1154_BATV_1_SetIn(GPIO_PinState state);


/*
 * FUNCTION: EnableBatPower
 *
 * DESCRIPTION: Enable power to Battery module. 
 *
 */


void EnableBatPower(void);

/*
 * FUNCTION: DisableBatPower
 *
 * DESCRIPTION: Disable power to Battery module. 
 *
 */

void DisableBatPower(void);

#endif /* HARDWARE_PERIPHERALS_INC_LTC11_DRIVER_H_ */



