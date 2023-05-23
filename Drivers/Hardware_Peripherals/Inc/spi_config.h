#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

#include "stm32l4xx_hal.h"

extern SPI_HandleTypeDef hspi1;
extern SPI_HandleTypeDef hspi2;
extern SPI_HandleTypeDef hspi3;

typedef enum {
	ADC12_HAL_OK 		= HAL_OK,
	ADC12_HAL_ERROR 	= HAL_ERROR,
	ADC12_HAL_BUSY 	    = HAL_BUSY,
	ADC12_HAL_TIMEOUT 	= HAL_TIMEOUT
} ADC12_StatusTypeDef;


void SPI1_Configuration();
void SPI2_Configuration();
void SPI3_Configuration();

#endif /* SPI_CONFIG_H_ */
