/*
 * FILENAME: commands.h
 *
 * DESCRIPTION: Handlers for different commands from CDH
 * AUTHORS:
 *  - Eran Efron (eran.efron@umsats.ca)
 *
 * CREATED ON: May 25, 2023
 */

//###############################################################################################
//Include Directives
//###############################################################################################
#include "ADC12_driver.h"
#include "LT365_driver.h"
#include "LTC11_driver.h"
#include "LTC29_driver.h"
#include "LTC41_driver.h"
#include "LTC364_driver.h"
#include "TPS_driver.h"
#include "can.h"

//###############################################################################################
//Function Declarations
//###############################################################################################
/**
 * @brief handles reset command
 * 
 */
void handleReset(void);

/**
 * @brief handles pld on command
 * 
 */
void handlePLDOn(void);

/**
 * @brief handles pld off command
 * 
 */
void handlePLDOff(void);

/**
 * @brief handles adcs on command
 * 
 */
void handleADCSOn(void);

/**
 * @brief handles adcs off command
 * 
 */
void handleADCSOff(void);

/**
 * @brief handles battery access on command
 * 
 */
void handleBatteryAccessOn(void);

/**
 * @brief handles battery access off command
 * 
 */
void handleBatteryAccessOff(void);

/**
 * @brief handles the battery heater on command
 * 
 */
void handleBatteryHeaterOn(void);

/**
 * @brief handles the battery heater off command
 * 
 */

void handleBatteryHeaterOff(void);


/**
 * @brief handles the check dcdc converter status command
 * 
 */
handleCheckDCDCCOnverterStatus(void);