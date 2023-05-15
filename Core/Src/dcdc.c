/*
 * FILENAME: dcdc.c
 *
 * DESCRIPTION: Functions to check DC to DC converter operations
 *
 * Link to Documentation: 
 *
 * AUTHORS:
 *  - Eran Efron (eran.efron@umsats.ca)
 *
 * CREATED ON: May 15, 2023
 */

//###############################################################################################
// Include Directives
//###############################################################################################
#include <stdio.h>
#include "dcdc.h"

int checkPGood()
{
    DCDC_StatusTypeDef operation_status;
    return HAL_GPIO_ReadPin(operation_status, pgood);
}

int checkRun()
{

}