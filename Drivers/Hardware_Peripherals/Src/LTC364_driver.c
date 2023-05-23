/**
  ******************************************************************************
  * @file           : LT364_driver.c
  * @brief          : Program for DC DC convertor
  * 
  ******************************************************************************
   not a real driver
  ****************************************************************************** **/

//###############################################################################################
// Include Directives
//###############################################################################################
#include <stdio.h>
#include "LTC364_driver.h"

int checkPGood()
{
    DCDC_StatusTypeDef operation_status;
    return HAL_GPIO_ReadPin(operation_status, pgood);
}

void setRun(GPIO_PinState state)
{
  DCDC_StatusTypeDef operation_status;
  HAL_GPIO_WritePin(operation_status, run, state);
}

