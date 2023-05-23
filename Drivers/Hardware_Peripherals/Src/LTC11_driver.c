/**
  ******************************************************************************
  * @file           : LTC11_driver.c
  * @brief          : Program for High Side Mosfet Driver
  * 
  ******************************************************************************
   not a real driver
  ****************************************************************************** **/
/*
 * FILENAME: LTC29_driver.c
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

// void LTC1154_Heater_Init(void)
// {
//   // Initialization for the Battery Heater mosfet driver 
//     GPIO_InitTypeDef GPIO_InitStruct = {0};
//     GPIO_InitStruct.Pin = LTC1154_HEATER_ENABLE_PIN | LTC1154_HEATER_STATUS_PIN | LTC1154_HEATER_IN_PIN;
//     GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
//     HAL_GPIO_Init(LTC1154_HEATER_GPIO_Port, &GPIO_InitStruct);
// }

GPIO_PinState LTC1154_Heater_GetStatus(void)
{
      // Read the status pin and return state (high or low)
    return HAL_GPIO_ReadPin(LTC1154_HEATER_GPIO_Port, LTC1154_HEATER_STATUS_PIN);
}

void LTC1154_Heater_SetEnable(GPIO_PinState state)
{
      // Set the state of the enable pin
    HAL_GPIO_WritePin(LTC1154_HEATER_GPIO_Port, LTC1154_HEATER_ENABLE_PIN, state);
}

void LTC1154_Heater_SetIn(GPIO_PinState state)
{
    // Set the state of the in pin
    HAL_GPIO_WritePin(LTC1154_HEATER_GPIO_Port, LTC1154_HEATER_IN_PIN, state);
}


//Mosfet Driver 2



// void LTC1154_BATV_1_Init(void)
// {
//   // Initialization for the first BATV NESS mosfet driver 
//     GPIO_InitTypeDef GPIO_InitStruct = {0};
//     GPIO_InitStruct.Pin = LTC1154_BATV_1_ENABLE_PIN | LTC1154_BATV_1_STATUS_PIN | LTC1154_BATV_1_IN_PIN;
//     GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
//     HAL_GPIO_Init(LTC1154_BATV_1_GPIO_Port, &GPIO_InitStruct);
// }

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


// void LTC1154_BATV_2_Init(void)
// {
//   // Initialization for the second BATV NESS mosfet driver 
//     GPIO_InitTypeDef GPIO_InitStruct = {0};
//     GPIO_InitStruct.Pin = LTC1154_BATV_2_ENABLE_PIN | LTC1154_BATV_2_STATUS_PIN | LTC1154_BATV_2_IN_PIN;
//     GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
//     HAL_GPIO_Init(LTC1154_BATV_2_GPIO_Port, &GPIO_InitStruct);
// }

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



