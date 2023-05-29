/*
 * FILENAME: commands.c
 *
 * DESCRIPTION: Handles commands that come from CDH subsystem to Power subsystem.
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

//###############################################################################################
// Handler Functions 
//###############################################################################################
void handleReset(void)
{
  CANMessage_t package;
  package.priority = 0b0000000;
  package.SenderID = SOURCE_ID;
  package.DestinationID = 0x1; 
  package.command = 0x01; 
  package.data[0] = 0xC0; 
  CAN_Transmit_Message(package);

  LTC2917_Manual_Reset(); 
}


void handlePLDOn(void)
{
  TPS22810_EnablePayloadPower();
  CANMessage_t package;
  package.priority = 0b0000001;
  package.SenderID = SOURCE_ID;
  package.DestinationID = 0x1; 
  package.command = 0x01; 
  package.data[0] = 0xC1; 

  CAN_Transmit_Message(package);
}


void handlePLDOff(void)
{
  TPS22810_DisablePayloadPower();
  CANMessage_t package;
  package.priority = 0b0000000;
  package.SenderID = SOURCE_ID;
  package.DestinationID = 0x1; 

  package.command = 0x01; 
  package.data[0] = 0xC2; 


  CAN_Transmit_Message(package);
}


void handleADCSOn(void)
{
  TPS22810_EnableADCSPower();
  CANMessage_t package;
  package.priority = 0b0000001;
  package.SenderID = SOURCE_ID;
  package.DestinationID = 0x1; 

  package.command = 0x01; 
  package.data[0] = 0xC3; 

  CAN_Transmit_Message(package);
}


void handleADCSOff(void)
{
  TPS22810_DisableADCSPower();
  CANMessage_t package;
  package.priority = 0b0000000;
  package.SenderID = SOURCE_ID;
  package.DestinationID = 0x1; 

  package.command = 0x01; 
  package.data[0] = 0xC4; 

  CAN_Transmit_Message(package);
}


void handleBatteryAccessOn(void)
{
  EnableBatPower();
  CANMessage_t package;
  package.priority = 0b0000001;
  package.SenderID = SOURCE_ID;
  package.DestinationID = 0x1; 

  package.command = 0x01; 
  package.data[0] = 0xC5; 

  CAN_Transmit_Message(package);
}


void handleBatteryAccessOff(void)
{
  DisableBatPower();
  CANMessage_t package;
  package.priority = 0b0000000;
  package.SenderID = SOURCE_ID;
  package.DestinationID = 0x1; 

  package.command = 0x01; 
  package.data[0] = 0xC6; 


  CAN_Transmit_Message(package);
}


void handleBatteryHeaterOn(void)
{
  LTC1154_HEATER_ON();
  CANMessage_t package;
  package.priority = 0b0000011;
  package.SenderID = SOURCE_ID;
  package.DestinationID = 0x1; 

  package.command = 0x01; 
  package.data[0] = 0xC7; 


  CAN_Transmit_Message(package);
}


void handleBatteryHeaterOff(void)
{ 
  LTC1154_HEATER_OFF();
  CANMessage_t package;
  package.priority = 0b0000001;
  package.SenderID = SOURCE_ID;
  package.DestinationID = 0x1; 

  package.command = 0x01; 
  package.data[0] = 0xC8; 

  CAN_Transmit_Message(package);

}


handleCheckDCDCCOnverterStatus(void)
{
  uint8_t status = checkPGood();
  CANMessage_t package;
  package.priority = 0b0000111;
  package.SenderID = SOURCE_ID;
  package.DestinationID = 0x1; 

  package.command = 0x01;
  package.data[0] = 0xC9;
  package.data[1] = status;

  CAN_Transmit_Message(package);
}