 /*
 * FILENAME: LTC29_driver.c
 *
 * DESCRIPTION: Driver for the LTC2917HMS-B1#PBF watchdog / voltage supervisor.
 *
 * AUTHORS:
 *  - Sanjana RoyChowdhury (sanjana.roy@umsats.ca)
 *
 * CREATED ON: May 16, 2023
 */
//###############################################################################################
//Include Directives
//###############################################################################################
#include "stm32l4xx_hal.h"
#include "LTC29_driver.h"

//###############################################################################################
//Driver Functions
//###############################################################################################

void LTC2917_Init()
{
    HAL_GPIO_WritePin(LTC2917_GPIO_Port, LTC2917_RST_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LTC2917_GPIO_Port, LTC2917_WDI_Pin, GPIO_PIN_RESET);
}

void LTC2917_Manual_Reset()
{
    HAL_GPIO_WritePin(LTC2917_GPIO_Port, LTC2917_RST_Pin, GPIO_PIN_RESET);
}

void LTC2917_WDI_Toggle()
{
    HAL_GPIO_TogglePin(LTC2917_GPIO_Port, LTC2917_WDI_Pin);
}