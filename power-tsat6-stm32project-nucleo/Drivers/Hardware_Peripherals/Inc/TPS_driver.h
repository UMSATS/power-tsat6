/*
 * FILENAME: TPS_driver.h
 *
 * DESCRIPTION: Header file for the TPS22810TDBVRQ1 load switch driver.
 *
 * AUTHORS:
 *  - Sanjana RoyChowdhury (sanjana.roy@umsats.ca)
 *
 * CREATED ON: May 16, 2023
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef HARDWARE_PERIPHERALS_INC_TPS_DRIVER_H_
#define HARDWARE_PERIPHERALS_INC_TPS_DRIVER_H_

//###############################################################################################
//Include Directives
//###############################################################################################
#include "stm32l4xx_hal.h"

//###############################################################################################
//Defines
//###############################################################################################

#define TPS22810_GPIO_Port                     GPIOA
#define TPS22810_PAYLOAD_PWR_EN_PIN            Payload_PWR_Pin
#define TPS22810_ADCS_PWR_EN_PIN               ADCS_PWR_Pin
#define TPS22810_BAT_PWR_EN_PIN                Battery_PWR_Pin

//###############################################################################################
//Prototypes
//###############################################################################################

/*
 * FUNCTION: TPS22810_Init
 *
 * DESCRIPTION: Initialize the load switches by enabling power to subsystems. 
 *
 */

void TPS22810_Init(void);

/*
 * FUNCTION: TPS22810_EnablePayloadPower
 *
 * DESCRIPTION: Enable power to payload subsystem. 
 *
 */


void TPS22810_EnablePayloadPower(void);

/*
 * FUNCTION: TPS22810_DisablePayloadPower
 *
 * DESCRIPTION: Disable power to payload subsystem. 
 *
 */

void TPS22810_DisablePayloadPower(void);

/*
 * FUNCTION: TPS22810_EnableADCSPower
 *
 * DESCRIPTION: Enable power to ADCS subsystem. 
 *
 */


void TPS22810_EnableADCSPower(void);

/*
 * FUNCTION: TPS22810_DisableADCSPower
 *
 * DESCRIPTION: Disable power to ADCS subsystem. 
 *
 */


void TPS22810_DisableADCSPower(void);





#endif /* HARDWARE_PERIPHERALS_INC_TPS_DRIVER_H_ */

