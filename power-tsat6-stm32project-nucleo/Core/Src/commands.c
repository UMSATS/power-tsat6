/**
  ******************************************************************************
  * @file           : commands.c
  * @brief          : handler functions for commands
  ******************************************************************************
  
  ****************************************************************************** **/
 /*
 * FILENAME: commands.c
 *
 * DESCRIPTION: handles commands that come from CDH
 *
 * AUTHORS:
 *  - Sanjana RoyChowdhury (sanjana.roy@umsats.ca)
 *  - Eran Efron (eran.efron@umsats.ca)
 *
 * CREATED ON: May 16, 2023
 */
//###############################################################################################
//Include Directives
//###############################################################################################
#include "commands.h"

/**
 * @brief handles reset command
 * 
 */
void handleReset(void)
{
  // Send the ACK message immediately before resetting the power
  CANMessage_t package;
  package.priority = 0b0000000;
  packageTemp.SenderID = SOURCE_ID;
  packageTemp.DestinationID = 0x1; // cdh destination

  package.command = 0x01; // ACK command code 
  package.data = 0xC0; // Response command code 


  CAN_Transmit_Message(package);

  // Reset the STM32 here 
  LTC2917_Manual_Reset(); 
}

/**
 * @brief handles pld on command
 * 
 */
void handlePLDOn(void)
{
  TPS22810_EnablePayloadPower();
  CANMessage_t package;
  package.priority = 0b0000001;
  packageTemp.SenderID = SOURCE_ID;
  packageTemp.DestinationID = 0x1; // cdh destination

  package.command = 0x01; // ACK (byte 0)
  package.data = 0xC1; // (byte 1)

  CAN_Transmit_Message(package);
}

/**
 * @brief handles pld off command
 * 
 */
void handlePLDOff(void)
{
  TPS22810_DisablePayloadPower();
  CANMessage_t package;
  package.priority = 0b0000000;
  packageTemp.SenderID = SOURCE_ID;
  packageTemp.DestinationID = 0x1; // cdh destination

  package.command = 0x01; // ACK (byte 0)
  package.data = 0xC2; // (byte 1)


  CAN_Transmit_Message(package);
}

/**
 * @brief handles adcs on command
 * 
 */
void handleADCSOn(void)
{
  TPS22810_EnableADCSPower();
  CANMessage_t package;
  package.priority = 0b0000001;
  packageTemp.SenderID = SOURCE_ID;
  packageTemp.DestinationID = 0x1; // cdh destination

  package.command = 0x01; // ACK (byte 0)
  package.data = 0xC3; // (byte 1)

  CAN_Transmit_Message(package);
}

/**
 * @brief handles adcs off command
 * 
 */
void handleADCSOff(void)
{
  TPS22810_DisableADCSPower();
  CANMessage_t package;
  package.priority = 0b0000000;
  packageTemp.SenderID = SOURCE_ID;
  packageTemp.DestinationID = 0x1; // cdh destination

  package.command = 0x01; // ACK (byte 0)
  package.data = 0xC4; // (byte 1)

  CAN_Transmit_Message(package);
}

/**
 * @brief handles battery access on command
 * 
 */
void handleBatteryAccessOn(void)
{
  TPS22810_EnableBatPower();
  CANMessage_t package;
  package.priority = 0b0000001;
  packageTemp.SenderID = SOURCE_ID;
  packageTemp.DestinationID = 0x1; // cdh destination

  package.command = 0x01; // ACK (byte 0)
  package.data = 0xC5; // (byte 1)

  CAN_Transmit_Message(package);
}

/**
 * @brief handles battery access off command
 * 
 */
void handleBatteryAccessOff(void)
{
  TPS22810_DisableBatPower();
  CANMessage_t package;
  package.priority = 0b0000000;
  packageTemp.SenderID = SOURCE_ID;
  packageTemp.DestinationID = 0x1; // cdh destination

  package.command = 0x01; // ACK (byte 0)
  package.data = 0xC6; // (byte 1)


  CAN_Transmit_Message(package);
}

/**
 * @brief handles the battery heater on command
 * 
 */
void handleBatteryHeaterOn(void)
{
  LTC1154_HEATER_ON();
  CANMessage_t package;
  package.priority = 0b0000011;
  packageTemp.SenderID = SOURCE_ID;
  packageTemp.DestinationID = 0x1; // cdh destination

  package.command = 0x01; // ACK (byte 0)
  package.data = 0xC7; // (byte 1)


  CAN_Transmit_Message(package);
}

/**
 * @brief handles the battery heater off command
 * 
 */

void handleBatteryHeaterOff(void)
{ 
  LTC1154_HEATER_OFF();
  CANMessage_t package;
  package.priority = 0b0000001;
  packageTemp.SenderID = SOURCE_ID;
  packageTemp.DestinationID = 0x1; // cdh destination

  package.command = 0x01; // ACK (byte 0)
  package.data = 0xC8; // (byte 1)

  CAN_Transmit_Message(package);

}


/**
 * @brief handles the check dcdc converter status command
 * 
 */
handleCheckDCDCCOnverterStatus(void)
{
  uint32_t status = checkPGood();
  CANMessage_t package;//ack to carry dcdc status
  package.priority = 0b0000111;//priority of the original command (replace with an enum for readability?)
  packageTemp.SenderID = SOURCE_ID;
  packageTemp.DestinationID = 0x1; // cdh destination

  package.command = 0x01;//ACK -> replace with enum for readability (byte 0)
  package.data[0] = 0xC9;
  for (int i = 0; i < sizeof(status); ++i) {
    package.data[i + 1] = (status >> (8 * i)) & 0xFF;


  CAN_Transmit_Message(package);
}