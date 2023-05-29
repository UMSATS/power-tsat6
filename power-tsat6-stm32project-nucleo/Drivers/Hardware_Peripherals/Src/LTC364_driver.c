/*
 * FILENAME: LTC364_driver.c
 *
 * DESCRIPTION: Driver for the DCDC converter.
 *
 * AUTHORS:
 *  - Eran Efron (eran.efron@umsats.ca)
 * 
 *
 * CREATED ON: May 15, 2023
 */
//###############################################################################################
// Include Directives
//###############################################################################################
#include <stdio.h>
#include "LTC364_driver.h"

//###############################################################################################
//Driver Functions
//###############################################################################################

uint8_t checkPGood()
{
    DCDC_StatusTypeDef operation_status;
    return HAL_GPIO_ReadPin(operation_status, pgood);
}

void setRun(GPIO_PinState state)
{
  DCDC_StatusTypeDef operation_status;
  HAL_GPIO_WritePin(operation_status, run, state);
}

