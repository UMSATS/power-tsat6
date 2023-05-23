
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

#define TPS22810_GPIO_Port                     GPIOE
#define TPS22810_PAYLOAD_PWR_EN_PIN            GPIO_PIN_0

//#define TPS22810_GPIO_Port                     GPIOE
#define TPS22810_ADCS_PWR_EN_PIN               GPIO_PIN_1

//#define TPS22810_GPIO_Port                     GPIOE
#define TPS22810_BAT_PWR_EN_PIN                GPIO_PIN_2


//###############################################################################################
//Prototypes
//###############################################################################################

void TPS22810_Init(void);

// prototypes for Payload power 

void TPS22810_EnablePayloadPower(void);


void TPS22810_DisablePayloadPower(void);


// prototypes for ADCS power 
void TPS22810_EnableADCSPower(void);


void TPS22810_DisableADCSPower(void);


//prototypes for Battery power 
void TPS22810_EnableBatPower(void);


void TPS22810_DisableBatPower(void);



#endif /* HARDWARE_PERIPHERALS_INC_TPS_DRIVER_H_ */

