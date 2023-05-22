/*
 * FILENAME: LTC41_driver.h
 *
 * DESCRIPTION: Header for the LTC4150MS culomb counter.
 *
 * AUTHORS:
 *  - Sanjana RoyChowdhury (sanjana.roy@umsats.ca)
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
//Defines
//###############################################################################################

// Pin definitions
#define LTC4150IMS_INT_PIN GPIO_PIN_5
#define LTC4150IMS_GPIO_Port GPIOA
#define LTC4150IMS_POL_PIN GPIO_PIN_6
#define LTC4150IMS_CLR_PIN GPIO_PIN_7
#define LTC4150IMS_SHDN_PIN GPIO_PIN_8

//global variable
extern uint8_t ltc41InterruptFlag;

// Shunt resistor value in ohms
#define SHUNT_RESISTOR_VALUE 10000.0f // 10k resistor 

// ADC parameters
#define ADC_RESOLUTION 3.3f // ADC reference voltage 
#define ADC_MAX_VALUE 4096 // Max ADC value 



//###############################################################################################
//Prototypes
//###############################################################################################

void LTC4150IMS_Init(void);


float LTC4150IMS_GetCurrent(void);


void LTC4150IMS_Clear(void);


void LTC4150IMS_SetPolarity(uint8_t polarity);

void LTC4150IMS_EnableShutdown(void);


void LTC4150IMS_DisableShutdown(void);


void LTC4150IMS_INT_IRQHandler(void);


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);



#endif /* HARDWARE_PERIPHERALS_INC_LTC41_DRIVER_H_ */