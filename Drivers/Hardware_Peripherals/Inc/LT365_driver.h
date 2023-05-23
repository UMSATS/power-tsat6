/**
  ******************************************************************************
  * @file           : LT365_driver.h
  * @brief          : Program for Power tracking to battery charger
  * 
  ******************************************************************************
   not a real driver
  ****************************************************************************** **/
// Include Directives
//###############################################################################################
#include "stm32l4xx_hal.h"

//###############################################################################################
// Public Define Directives
//###############################################################################################
#define XPos MPPT_X_POS_SHDN_Pin
#define XNeg MPPT_X_NEG_SHDN_Pin
#define YPos MPPT_Y_POS_SHDN_Pin
#define YNeg MPPT_Y_NEG_SHDN_Pin

//###############################################################################################
// Public Type Definitions
//###############################################################################################
 typedef enum //alter when implementing error handling (NOTE: change to tracker instead of W25N)
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
} Tracker_StatusTypeDef;

//###############################################################################################
//Public Driver Function Prototypes
//###############################################################################################
/*
 * FUNCTION: toggleXNeg
 *
 * DESCRIPTION: Turn the device corresponding to x negative on or off
 */
 void toggleXNeg(GPIO_PinState state);
 /*
 * FUNCTION: toggleXPos
 *
 * DESCRIPTION: Turn the device corresponding to x positive on or off
 */
 void toggleXPos(GPIO_PinState state);
 /*
 * FUNCTION: toggleYNeg
 *
 * DESCRIPTION: Turn the device corresponding to y negative on or off
 */
 void toggleYNeg(GPIO_PinState state);
 /*
 * FUNCTION: toggleYPos
 *
 * DESCRIPTION: Turn the device corresponding to y positive on or off
 */
 void toggleYPos(GPIO_PinState state);