/*
 * FILENAME: LTC364_driver.h
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

#ifndef HARDWARE_PERIPHERALS_INC_DCDC_DRIVER_H_
#define HARDWARE_PERIPHERALS_INC_DCDC_DRIVER_H_

//###############################################################################################
// Include Directives
//###############################################################################################
#include "stm32l4xx_hal.h"

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
    W25N_HAL_OK                     = HAL_OK,      //0x00
    W25N_HAL_ERROR                  = HAL_ERROR,   //0x01
    W25N_HAL_BUSY                   = HAL_BUSY,    //0x02
    W25N_HAL_TIMEOUT                = HAL_TIMEOUT, //0x03
    W25N_READY                      = 0x04,
    W25N_HANGING                    = 0x05,
    W25N_LUT_HAS_ROOM               = 0x06,
    W25N_LUT_FULL                   = 0x07,
    W25N_ECC_CORRECTION_UNNECESSARY = 0x08,
    W25N_ECC_CORRECTION_OK          = 0x09,
    W25N_ECC_CORRECTION_ERROR       = 0x0A,
    W25N_PROGRAM_OK                 = 0x0B,
    W25N_PROGRAM_ERROR              = 0x0C,
    W25N_ERASE_OK                   = 0x0D,
    W25N_ERASE_ERROR                = 0x0E
} DCDC_StatusTypeDef;

//###############################################################################################
//Public Driver Function Prototypes
//###############################################################################################
/*
 * FUNCTION: checkPGood
 *
 * DESCRIPTION: Check that the voltage at the PGOOD pin indicates normal operation
 */
int checkPGood();

/*
 * FUNCTION: checkRun
 *
 * DESCRIPTION: set the run pin to high when the application code demands
 */
void setRun(GPIO_PinState state);

#endif /* HARDWARE_PERIPHERALS_INC_DCDC_DRIVER_H_ */