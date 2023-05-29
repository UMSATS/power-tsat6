/*
 * FILENAME: LTC11_driver.c
 *
 * DESCRIPTION: Driver for the LTC1154HS8#PBF high side micropower MOSFET Drivers.
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
#include "LTC11_driver.h"

//###############################################################################################
//Driver Functions
//###############################################################################################

//Mosfet Driver 1 

GPIO_PinState LTC1154_Heater_GetStatus(void)
{
    return HAL_GPIO_ReadPin(LTC1154_HEATER_GPIO_S_Port, LTC1154_HEATER_STATUS_PIN);
}

void LTC1154_Heater_SetEnable(GPIO_PinState state)
{
    HAL_GPIO_WritePin(LTC1154_HEATER_GPIO_Port, LTC1154_HEATER_ENABLE_PIN, state);
}

void LTC1154_Heater_SetIn(GPIO_PinState state)
{
    HAL_GPIO_WritePin(LTC1154_HEATER_GPIO_Port, LTC1154_HEATER_IN_PIN, state);
}

void LTC1154_HEATER_ON(void)
{
    HAL_GPIO_WritePin(LTC1154_HEATER_GPIO_Port, LTC1154_HEATER_ENABLE_PIN, GPIO_PIN_SET);
}

void LTC1154_HEATER_OFF(void)
{
    HAL_GPIO_WritePin(LTC1154_HEATER_GPIO_Port, LTC1154_HEATER_ENABLE_PIN, GPIO_PIN_RESET);
}


//Mosfet Driver 2


GPIO_PinState LTC1154_BATV_1_GetStatus(void)
{
  
    return HAL_GPIO_ReadPin(LTC1154_BATV_1_GPIO_Port, LTC1154_BATV_1_STATUS_PIN);
}

void LTC1154_BATV_1_SetEnable(GPIO_PinState state)
{
    HAL_GPIO_WritePin(LTC1154_BATV_1_GPIO_Port, LTC1154_BATV_1_ENABLE_PIN, state);
}

void LTC1154_BATV_1_SetIn(GPIO_PinState state)
{
    HAL_GPIO_WritePin(LTC1154_BATV_1_GPIO_Port, LTC1154_BATV_1_IN_PIN, state);
}


//Mosfet Driver 3


GPIO_PinState LTC1154_BATV_2_GetStatus(void)
{
    return HAL_GPIO_ReadPin(LTC1154_BATV_2_GPIO_Port, LTC1154_BATV_2_STATUS_PIN);
}

void LTC1154_BATV_2_SetEnable(GPIO_PinState state)
{
    HAL_GPIO_WritePin(LTC1154_BATV_2_GPIO_Port, LTC1154_BATV_2_ENABLE_PIN, state);
}

void LTC1154_BATV_2_SetIn(GPIO_PinState state)
{
    HAL_GPIO_WritePin(LTC1154_BATV_2_GPIO_Port, LTC1154_BATV_2_IN_PIN, state);
}



