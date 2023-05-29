/*
 * FILENAME: LTC365_driver.h
 *
 * DESCRIPTION: Header file for Driver for the Power Tracking 2A Battery Charger.
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
 typedef enum 
{
    TRACKER_HAL_OK = HAL_OK, //0x00
    TRACKER_HAL_ERROR = HAL_ERROR, //0x01
    TRACKER_HAL_BUSY = HAL_BUSY, //0x02
    TRACKER_HAL_TIMEOUT = HAL_TIMEOUT, //0x03
    TRACKER_READY = 0x04,
    TRACKER_HANGING = 0x05,
    TRACKER_LUT_HAS_ROOM = 0x06,
    TRACKER_LUT_FULL = 0x07,
    TRACKER_ECC_CORRECTION_UNNECESSARY = 0x08,
    TRACKER_ECC_CORRECTION_OK = 0x09,
    TRACKER_ECC_CORRECTION_ERROR = 0x0A,
    TRACKER_PROGRAM_OK = 0x0B,
    TRACKER_PROGRAM_ERROR = 0x0C,
    TRACKER_ERASE_OK = 0x0D,
    TRACKER_ERASE_ERROR = 0x0E
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