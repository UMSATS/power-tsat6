/*
 * FILENAME: spi_config.h
 *
 * DESCRIPTION: Header for Spi configurations for ADC driver
 *
 * AUTHORS:
 *  - Sanjana RoyChowdhury (sanjana.roy@umsats.ca)
 *
 * CREATED ON: May 22, 2023
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef HARDWARE_PERIPHERALS_INC_SPI_CONFIG_H_
#define HARDWARE_PERIPHERALS_INC_SPI_CONFIG_H_

//###############################################################################################
//Include Directives
//###############################################################################################
#include "stm32l4xx_hal.h"

//###############################################################################################
//Handles and Enumeration
//###############################################################################################

extern SPI_HandleTypeDef hspi1;
extern SPI_HandleTypeDef hspi2;
extern SPI_HandleTypeDef hspi3;

typedef enum {
	ADC12_HAL_OK 		= HAL_OK,
	ADC12_HAL_ERROR 	= HAL_ERROR,
	ADC12_HAL_BUSY 	    = HAL_BUSY,
	ADC12_HAL_TIMEOUT 	= HAL_TIMEOUT
} ADC12_StatusTypeDef;


//###############################################################################################
//Prototypes
//###############################################################################################

void SPI1_Configuration();
void SPI2_Configuration();
void SPI3_Configuration();

#endif /* HARDWARE_PERIPHERALS_INC_SPI_CONFIG_H_ */
