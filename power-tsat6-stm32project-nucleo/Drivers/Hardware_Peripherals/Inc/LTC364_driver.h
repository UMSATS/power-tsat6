/*
 * FILENAME: LTC364_driver.h
 *
 * DESCRIPTION: Header file  for Functions to check DC to DC converter operations
 * 
 * AUTHORS:
 *  - Eran Efron (eran.efron@umsats.ca)
 *  - Sanjana RoyChowdhury (sanjana.roy@umsats.ca)
 *
 * CREATED ON: May 15, 2023
 */

#ifndef HARDWARE_PERIPHERALS_INC_DCDC_DRIVER_H_
#define HARDWARE_PERIPHERALS_INC_DCDC_DRIVER_H_

//###############################################################################################
// Include Directives
//###############################################################################################
#include "stm32l4xx_hal.h"
#include <stdint.h>

//###############################################################################################
// Public Define Directives
//###############################################################################################
#define pgood           PGOOD_Pin
#define run             RUN_Pin

//###############################################################################################
// Public Type Definitions
//###############################################################################################
typedef enum //alter when implementing error handling
{
    DCDC_HAL_OK = HAL_OK,           //0x00
    DCDC_HAL_ERROR = HAL_ERROR,     //0x01
    DCDC_HAL_BUSY = HAL_BUSY,       //0x02
    DCDC_HAL_TIMEOUT = HAL_TIMEOUT, //0x03
    DCDC_READY = 0x04,
    DCDC_HANGING = 0x05,
    DCDC_LUT_HAS_ROOM = 0x06,
    DCDC_LUT_FULL = 0x07,
    DCDC_ECC_CORRECTION_UNNECESSARY = 0x08,
    DCDC_ECC_CORRECTION_OK = 0x09,
    DCDC_ECC_CORRECTION_ERROR = 0x0A,
    DCDC_PROGRAM_OK = 0x0B,
    DCDC_PROGRAM_ERROR = 0x0C,
    DCDC_ERASE_OK = 0x0D,
    DCDC_ERASE_ERROR = 0x0E
} DCDC_StatusTypeDef;

//###############################################################################################
//Public Driver Function Prototypes
//###############################################################################################
/*
 * FUNCTION: checkPGood
 *
 * DESCRIPTION: Check that the voltage at the PGOOD pin indicates normal operation.
 */
uint8_t checkPGood();

/*
 * FUNCTION: checkRun
 *
 * DESCRIPTION: Set the run pin to high when the application code demands.
 */
void setRun(GPIO_PinState state);

#endif /* HARDWARE_PERIPHERALS_INC_DCDC_DRIVER_H_ */