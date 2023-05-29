/*
 * FILENAME: LTC41_driver.h
 *
 * DESCRIPTION: Header file for the LTC4150MS culomb counter.
 *
 * AUTHORS:
 *  - Sanjana RoyChowdhury (sanjana.roy@umsats.ca)
 * 
 *
 * CREATED ON: May 2, 2023
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef HARDWARE_PERIPHERALS_INC_LTC41_DRIVER_H_
#define HARDWARE_PERIPHERALS_INC_LTC41_DRIVER_H_


//###############################################################################################
//Include Directives
//###############################################################################################
#include "stm32l4xx_hal.h"

//###############################################################################################
//Defines and Global Variables 
//###############################################################################################

#define LTC4150IMS_INT_PIN CC_Int_Pin
#define LTC4150IMS_GPIO_SC_Port GPIOC
#define LTC4150IMS_GPIO_PI_Port GPIOA
#define LTC4150IMS_POL_PIN CC_Pol_Pin
#define LTC4150IMS_CLR_PIN CC_CLR_Pin
#define LTC4150IMS_SHDN_PIN CC_SHDN_Pin
#define SHUNT_RESISTOR_VALUE 10000.0f 
#define ADC_RESOLUTION 3.3f 
#define ADC_MAX_VALUE 4096 
#define VOLT_FREQ_GAIN 32.55f 
#define R_SENSE 0.01f
#define CHARGE_MEM_LOCATION 0x0801FC00

extern uint8_t ltc41InterruptFlag;
extern uint32_t charge;

//###############################################################################################
//Prototypes
//###############################################################################################

/*
 * FUNCTION: LTC4150IMS_Init
 *
 * DESCRIPTION: Initializes the Culomb counter by configuring the interupt pin and setting a capacity charge.
 */

void LTC4150IMS_Init(void);

/*
 * FUNCTION: LTC4150IMS_Clear
 *
 * DESCRIPTION: Set the CLR pin low for 1us to reset Interrupt then set the CLR pin high.
 */


void LTC4150IMS_Clear(void);

/*
 * FUNCTION: LTC4150IMS_SetPolarity
 *
 * DESCRIPTION: Sets the polarity of the Culomb counter to high or low. 
 * 
 * PARAMETERS:
 *  polarity: polarity of charge. 
 */

void LTC4150IMS_SetPolarity(uint8_t polarity);

/*
 * FUNCTION: LTC4150IMS_EnableShutdown
 *
 * DESCRIPTION: Shutdown all power to culomb counter. 
 */

void LTC4150IMS_EnableShutdown(void);

/*
 * FUNCTION: LTC4150IMS_DisableShutdown
 *
 * DESCRIPTION: DIsable Shutdown temporarily. 
 */

void LTC4150IMS_DisableShutdown(void);

/*
 * FUNCTION: LTC4150IMS_INT_IRQHandler
 *
 * DESCRIPTION: Clears Interrupt by generating a low pulse on the CLR pin.
 */

void LTC4150IMS_INT_IRQHandler(void);

/*
 * FUNCTION: HAL_GPIO_EXTI_Callback
 *
 * DESCRIPTION: Takes place when interrupt is called. Calculates change in battery charge and determines if there was a battery charge loss or gain.
 */

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);



#endif /* HARDWARE_PERIPHERALS_INC_LTC41_DRIVER_H_ */