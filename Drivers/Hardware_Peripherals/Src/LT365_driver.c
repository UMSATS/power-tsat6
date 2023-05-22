/**
  ******************************************************************************
  * @file           : LT365_driver.c
  * @brief          : Program for Power tracking to battery charger
  * 
  ******************************************************************************
   not a real driver
  ****************************************************************************** **/
#include "LT365_driver.h"
 //change state for each pin? send both pin and state (sanitation?)? 

 void  void toggleXNeg(GPIO_PinState state)
{
  DCDC_StatusTypeDef operation_status;
  HAL_GPIO_WritePin(operation_status, XNeg, state);
}
void toggleXPos(GPIO_PinState state)
{
  DCDC_StatusTypeDef operation_status;
  HAL_GPIO_WritePin(operation_status, XPos, state);
}
void toggleYNeg(GPIO_PinState state)
{
  DCDC_StatusTypeDef operation_status;
  HAL_GPIO_WritePin(operation_status, YNeg, state);
}
void toggleYPos(GPIO_PinState state)
{
  DCDC_StatusTypeDef operation_status;
  HAL_GPIO_WritePin(operation_status, YPos, state);
}
