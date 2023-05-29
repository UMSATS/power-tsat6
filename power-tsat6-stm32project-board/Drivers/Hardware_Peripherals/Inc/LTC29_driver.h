/*
 * FILENAME: LTC29_driver.h
 *
 * DESCRIPTION: Header file for the LTC2917HMS-B1#PBF watchdog / voltage supervisor driver.
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
#define LTC2917_GPIO_Port GPIOC
#define LTC2917_RST_Pin WD_RST_Pin
#define LTC2917_WDI_Pin WD_WDI_Pin

//###############################################################################################
//Prototypes
//###############################################################################################


/*
 * FUNCTION: LTC4150IMS_Init
 *
 * DESCRIPTION: Initializes the Voltage supervisor.
 */


void LTC2917_Init();


/*
 * FUNCTION: LTC2917_Manual_Reset
 *
 * DESCRIPTION: Manually resets the Power subsystem Microcontroler. 
 */

void LTC2917_Manual_Reset();

/*
 * FUNCTION: LTC2917_Manual_Reset
 *
 * DESCRIPTION: Can be used to refresh the watchdog timer before reaching a timeout condition.
 */

void LTC2917_WDI_Toggle();


#endif /* HARDWARE_PERIPHERALS_INC_LTC29_DRIVER_H_ */