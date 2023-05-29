/*
 * FILENAME: LTC365_driver.c
 *
 * DESCRIPTION: Driver for the Power Tracking 2A Battery Charger.
 *
 * AUTHORS:
 *  - Eran Efron (eran.efron@umsats.ca)
 * 
 *
 * CREATED ON: May 15, 2023
 */

 //###############################################################################################
//Include Directives
//###############################################################################################
#include "LT365_driver.h"


//###############################################################################################
//Driver Functions
//###############################################################################################

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
  ****************************************************************************** **/
