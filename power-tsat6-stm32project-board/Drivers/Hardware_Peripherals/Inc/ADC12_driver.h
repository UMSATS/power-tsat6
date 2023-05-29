/*
 * FILENAME: ADC12_driver.h
 *
 * DESCRIPTION: Header for the ADC128S102 analog to digital coverter driver.
 *
 * AUTHORS:
 *  - Sanjana RoyChowdhury (sanjana.roy@umsats.ca)
 *
 * CREATED ON: May 22, 2023
 */

#ifndef HARDWARE_PERIPHERALS_INC_ADC12_DRIVER_H_
#define HARDWARE_PERIPHERALS_INC_ADC12_DRIVER_H_

//###############################################################################################
//Include Directives
//###############################################################################################
#include <stdint.h>
#include <stddef.h>
#include "stm32l4xx_hal.h"

//###############################################################################################
// Defines
//###############################################################################################

// ADC 1 
#define ADC1_GPIO_PORT  GPIOA
#define ADC1_DIN_PIN    ADC1_Din_Pin
#define ADC1_DOUT_PIN   ADC1_Dout_Pin
#define ADC1_CS_PIN     ADC1_CS_Pin
#define ADC1_SCLK_PIN   ADC1_CLCK_Pin

// ADC 2 
#define ADC2_GPIO_D_PORT  GPIOC
#define ADC2_GPIO_C_PORT  GPIOB
#define ADC2_DIN_PIN    ADC2_Din_Pin
#define ADC2_DOUT_PIN   ADC2_Dout_Pin
#define ADC2_CS_PIN     ADC2_CS_Pin
#define ADC2_SCLK_PIN   ADC2_CLCK_Pin

// ADC 3 
#define ADC3_GPIO_CS_PORT  GPIOB
#define ADC3_GPIO_PORT  GPIOC
#define ADC3_DIN_PIN    ADC3_Din_Pin
#define ADC3_DOUT_PIN   ADC3_Dout_Pin
#define ADC3_CS_PIN     ADC3_CS_Pin
#define ADC3_SCLK_PIN   ADC3_CLCK_Pin

// Current Sensors
#define SHUNT_RESISTOR1   0.02f
#define SHUNT_RESISTOR2   0.02f
#define SHUNT_RESISTOR3   0.02f
#define SHUNT_RESISTOR4   0.01f
#define SHUNT_RESISTOR5   0.03f
#define SHUNT_RESISTOR6   0.03f
#define SHUNT_RESISTOR7   0.015f
#define SHUNT_RESISTOR8   0.015f
#define CURRENT_SENSOR_ID_1 0x8  //U8
#define CURRENT_SENSOR_ID_2 0x10 //U10
#define CURRENT_SENSOR_ID_3 0x12 //U12
#define CURRENT_SENSOR_ID_4 0x11 //U11
#define CURRENT_SENSOR_ID_5 0x13 //U13
#define CURRENT_SENSOR_ID_6 0x14 //U14
#define CURRENT_SENSOR_ID_7 0x15 //U15 
#define CURRENT_SENSOR_ID_8 0x16 //U16 


//###############################################################################################
// Enumeration
//###############################################################################################

typedef enum {
	ADC12_HAL_OK 		= HAL_OK,
	ADC12_HAL_ERROR 	= HAL_ERROR,
	ADC12_HAL_BUSY 	    = HAL_BUSY,
	ADC12_HAL_TIMEOUT 	= HAL_TIMEOUT
} ADC12_StatusTypeDef;

//###############################################################################################
//Prototypes
//###############################################################################################


/*
 * FUNCTION: ADC1_Select
 *
 * DESCRIPTION: Selects ADC A.
 */

void ADC1_Select(void);

/*
 * FUNCTION: ADC1_Deselect
 *
 * DESCRIPTION: Deselects ADC A.
 */

void ADC1_Deselect(void);


/*
 * FUNCTION: ADC1_ClockHigh
 *
 * DESCRIPTION: Sets ADC A clock to high.
 */

void ADC1_ClockHigh(void);


/*
 * FUNCTION: ADC1_ClockLow
 *
 * DESCRIPTION: Sets ADC A clock to low.
 */

void ADC1_ClockLow(void);


/*
 * FUNCTION: ADC3_ReadValues
 *
 * DESCRIPTION: Reads values through MISO pin on ADC A, interacting through SPI communication interface. 
 * 
 * PARAMETERS:
 * values: 16 bit array where ADC values read will be stored.
 * numValues: number of ADC values to be read.
 * 
 */

ADC12_StatusTypeDef ADC1_ReadValues(uint16_t* values, size_t numValues);


/*
 * FUNCTION: ADC2_Select
 *
 * DESCRIPTION: Selects ADC B.
 */

void ADC2_Select(void);

/*
 * FUNCTION: ADC2_Deselect
 *
 * DESCRIPTION: Deselects ADC B.
 */

void ADC2_Deselect(void);


/*
 * FUNCTION: ADC2_ClockHigh
 *
 * DESCRIPTION: Sets ADC B clock to high.
 */


void ADC2_ClockHigh(void);


/*
 * FUNCTION: ADC2_ClockLow
 *
 * DESCRIPTION: Sets ADC B clock to low.
 */

void ADC2_ClockLow(void);


/*
 * FUNCTION: ADC3_ReadValues
 *
 * DESCRIPTION: Reads values through MISO pin on ADC B, interacting through SPI communication interface. 
 * 
 * PARAMETERS:
 * values: 16 bit array where ADC values read will be stored.
 * numValues: number of ADC values to be read.
 * 
 */

ADC12_StatusTypeDef ADC2_ReadValues(uint16_t* values, size_t numValues);

/*
 * FUNCTION: ADC3_Select
 *
 * DESCRIPTION: Selects ADC C.
 */

void ADC3_Select(void);


/*
 * FUNCTION: ADC3_Deselect
 *
 * DESCRIPTION: Deselects ADC C.
 */

void ADC3_Deselect(void);

/*
 * FUNCTION: ADC3_ClockHigh
 *
 * DESCRIPTION: Sets ADC C clock to high.
 */

void ADC3_ClockHigh(void);

/*
 * FUNCTION: ADC3_ClockHigh
 *
 * DESCRIPTION: Sets ADC C clock to high.
 */

void ADC3_ClockLow(void);

/*
 * FUNCTION: ADC3_ReadValues
 *
 * DESCRIPTION: Reads values through MISO pin on ADC C, interacting through SPI communication interface. 
 * 
 * PARAMETERS:
 * values: 16 bit array where ADC values read will be stored.
 * numValues: number of ADC values to be read.
 * 
 */

ADC12_StatusTypeDef ADC3_ReadValues(uint16_t* values, size_t numValues);

/*
 * FUNCTION: ADC3_ReadValue_BatteryTemp
 *
 * DESCRIPTION: Reads Battery Temperature through channel 7 on ADC C.
 */


uint16_t ADC3_ReadValue_BatteryTemp();

/*
 * FUNCTION: ADC_Vout_Reading1
 *
 * DESCRIPTION: Reads output voltage from current sensor U8.
 */

uint8_t ADC_Vout_Reading1();

/*
 * FUNCTION: ADC_Vout_Reading2
 *
 * DESCRIPTION: Reads output voltage from current sensor U10.
 */

uint8_t ADC_Vout_Reading2();

/*
 * FUNCTION: ADC_Vout_Reading3
 *
 * DESCRIPTION: Reads output voltage from current sensor U12.
 */

uint8_t ADC_Vout_Reading3();

/*
 * FUNCTION: ADC_Vout_Reading4
 *
 * DESCRIPTION: Reads output voltage from current sensor U11.
 */

uint8_t ADC_Vout_Reading4();

/*
 * FUNCTION: ADC_Vout_Reading5
 *
 * DESCRIPTION: Reads output voltage from current sensor U13.
 */

uint8_t ADC_Vout_Reading5();

/*
 * FUNCTION: ADC_Vout_Reading6
 *
 * DESCRIPTION: Reads output voltage from current sensor U14.
 */

uint8_t ADC_Vout_Reading6();

/*
 * FUNCTION: ADC_Vout_Reading7
 *
 * DESCRIPTION: Reads output voltage from current sensor U15.
 */

uint8_t ADC_Vout_Reading7();

/*
 * FUNCTION: ADC_Vout_Reading8
 *
 * DESCRIPTION: Reads output voltage from current sensor U16.
 */

uint8_t ADC_Vout_Reading8();


#endif /* HARDWARE_PERIPHERALS_INC_ADC12_DRIVER_H_ */
