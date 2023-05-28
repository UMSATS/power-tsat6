/**
  ******************************************************************************
  * @file           : ADC128S102_driver.c
  * @brief          : Program for Analog to digital converter
  ******************************************************************************
  
  ****************************************************************************** **/
 /*
 * FILENAME: ADC128S102_driver.c
 *
 * DESCRIPTION: Driver for Analog to digital converter
 *
 * AUTHORS:
 *  - Sanjana RoyChowdhury (sanjana.roy@umsats.ca)
 *
 * CREATED ON: May 16, 2023
 */
//###############################################################################################
//Include Directives
//###############################################################################################
#include "stm32l4xx_hal.h"
#include "ADC12_driver.h"
//###############################################################################################
//Driver Functions
//###############################################################################################

// ADC 1

// ADC12_StatusTypeDef ADC_SPI_Configuration1() {

//     // Configure SPI settings (e.g., clock frequency, data format, etc.)
//     SPI1_Configuration();

//     // Set the CS pin to low initially
//     ADC1_Deselect();

//     return ADC12_HAL_OK;
// }


void ADC1_Select() {
    // set CS pin to high
    HAL_GPIO_WritePin(ADC1_GPIO_PORT, ADC1_CS_PIN, GPIO_PIN_SET);
}

void ADC1_Deselect() {
    // set CS pin to low
    HAL_GPIO_WritePin(ADC1_GPIO_PORT, ADC1_CS_PIN, GPIO_PIN_RESET);
}


void ADC1_ClockHigh() {
    // Set SCLK pin to high
    HAL_GPIO_WritePin(ADC1_GPIO_PORT, ADC1_SCLK_PIN, GPIO_PIN_SET);
}

void ADC1_ClockLow() {
    // Set SCLK pin to low
    HAL_GPIO_WritePin(ADC1_GPIO_PORT, ADC1_SCLK_PIN, GPIO_PIN_RESET);
}


// ADC12_StatusTypeDef ADC_SPI_Transmit_Message(uint8_t * data, size_t numToSend){
// 	return HAL_SPI_Transmit(&hspi, data, numToSend, HAL_MAX_DELAY);
// }


// ADC12_StatusTypeDef ADC_SPI_Receive_Message(uint8_t * data, size_t numToReceive){
	
// 	return HAL_SPI_Receive(&hspi, data, numToReceive, HAL_MAX_DELAY);
// }


ADC12_StatusTypeDef ADC1_ReadValues(uint16_t* values, size_t numValues) {

    size_t numToReceive = numValues * sizeof(uint16_t);

    // Select the ADC
    ADC1_Select();

    // Perform SPI communication with ADC128S102
    for (size_t i = 0; i < numToReceive; ++i) {
        uint8_t transmittedData1 = 0xFF;  // dummy
        uint8_t recievedData1 = 0;

        // clock in data bit by bit
        for (int bit = 7; bit >= 0; --bit) {
            // Set the DIN pin 
            HAL_GPIO_WritePin(ADC1_GPIO_PORT, ADC1_DIN_PIN, (transmittedData1 >> bit) & 0x01);

            // Clock high
            ADC1_ClockHigh();

            // Shift in received data bit
            recievedData1 = (recievedData1 << 1) | HAL_GPIO_ReadPin(ADC1_GPIO_PORT, ADC1_DOUT_PIN);

            // Clock low
            ADC1_ClockLow();
        }

        // Store received data
        ((uint8_t*)values)[i] = recievedData1;
    }

    // Deselect the ADC
    ADC1_Deselect();

    return ADC12_HAL_OK;
}


// // ADC 2
// ADC12_StatusTypeDef ADC_SPI_Configuration2() {
//     // Configure SPI settings (e.g., clock frequency, data format, etc.)
//     SPI2_Configuration();

//     // Set the CS pin to low initially
//     ADC2_Deselect();

//     return ADC12_HAL_OK;
// }

void ADC2_Select() {
    // Set CS pin to low
    HAL_GPIO_WritePin(ADC2_GPIO_C_PORT, ADC2_CS_PIN, GPIO_PIN_SET);
}

void ADC2_Deselect() {
    // Set CS pin to high
    HAL_GPIO_WritePin(ADC2_GPIO_C_PORT, ADC2_CS_PIN, GPIO_PIN_RESET);
}


void ADC2_ClockHigh() {
    // Set SCLK pin to high
    HAL_GPIO_WritePin(ADC2_GPIO_C_PORT, ADC2_SCLK_PIN, GPIO_PIN_SET);
}

void ADC2_ClockLow() {
    // Set SCLK pin to low
    HAL_GPIO_WritePin(ADC2_GPIO_C_PORT, ADC2_SCLK_PIN, GPIO_PIN_RESET);
}

ADC12_StatusTypeDef ADC2_ReadValues(uint16_t* values, size_t numValues) {
    size_t numToReceive = numValues * sizeof(uint16_t);

    // Select the ADC
    ADC2_Select();


    // Perform SPI communication with ADC128S102
    for (size_t i = 0; i < numToReceive; ++i) {
        uint8_t transmittedData2 = 0xFF;
        uint8_t recievedData2 = 0;

        // clock in data bit by bit
        for (int bit = 7; bit >= 0; --bit) {
            // Set the DIN pin 
            HAL_GPIO_WritePin(ADC2_GPIO_D_PORT, ADC2_DIN_PIN, (transmittedData2 >> bit) & 0x01);

            // Clock high
            ADC2_ClockHigh();

            // Shift in received data bit
            recievedData2 = (recievedData2 << 1) | HAL_GPIO_ReadPin(ADC2_GPIO_D_PORT, ADC2_DOUT_PIN);

            // Clock low
            ADC2_ClockLow();
        }

        // Store received data
        ((uint8_t*)values)[i] = recievedData2;
    }

    // Deselect the ADC
    ADC2_Deselect();

    return ADC12_HAL_OK;
}



// // ADC 3

// ADC12_StatusTypeDef ADC_SPI_Configuration3() {
//     // Configure SPI settings (e.g., clock frequency, data format, etc.)
//     SPI3_Configuration();

//     // Set the CS pin to low initially
//     ADC3_Deselect();

//     return ADC12_HAL_OK;
// }

void ADC3_Select() {
    // Set CS pin to low
    HAL_GPIO_WritePin(ADC3_GPIO_CS_PORT, ADC3_CS_PIN, GPIO_PIN_SET);
}

void ADC3_Deselect() {
    // Set CS pin to high
    HAL_GPIO_WritePin(ADC3_GPIO_CS_PORT, ADC3_CS_PIN, GPIO_PIN_RESET);
}

void ADC3_ClockHigh() {
    // Set SCLK pin to high
    HAL_GPIO_WritePin(ADC3_GPIO_PORT, ADC3_SCLK_PIN, GPIO_PIN_SET);
}

void ADC3_ClockLow() {
    // Set SCLK pin to low
    HAL_GPIO_WritePin(ADC3_GPIO_PORT, ADC3_SCLK_PIN, GPIO_PIN_RESET);
}

uint16_t ADC3_ReadValue_BatteryTemp() {
    // Select input channel IN7
    uint8_t transmittedData3 = 0x1C;  // 0b00011100

    // Select the ADC
    ADC3_Select();

    // Perform SPI communication with ADC128S102
    uint16_t receivedData3 = 0;
    for (int bit = 7; bit >= 0; --bit) {
        // Set the DIN pin
        HAL_GPIO_WritePin(ADC3_GPIO_PORT, ADC3_DIN_PIN, (transmittedData3 >> bit) & 0x01);

        // Clock high
        ADC3_ClockHigh();

        // Shift in received data bit
        receivedData3 = (receivedData3 << 1) | HAL_GPIO_ReadPin(ADC3_GPIO_PORT, ADC3_DOUT_PIN);

        // Clock low
        ADC3_ClockLow();
    }

    // Perform another 8-bit read to get the LSB
    uint8_t receivedData4 = 0;
    for (int bit = 7; bit >= 0; --bit) {
        // Set the DIN pin
        HAL_GPIO_WritePin(ADC3_GPIO_PORT, ADC3_DIN_PIN, 0x00);

        // Clock high
        ADC3_ClockHigh();

        // Shift in received data bit
        receivedData4 = (receivedData4 << 1) | HAL_GPIO_ReadPin(ADC3_GPIO_PORT, ADC3_DOUT_PIN);

        // Clock low
        ADC3_ClockLow();
    }

    // Combine the MSB and LSB to form the 16-bit value
    uint16_t value = (receivedData3 << 8) | receivedData4;

    // Deselect the ADC
    ADC3_Deselect();

    return value;
}




ADC12_StatusTypeDef ADC3_ReadValues(uint16_t* values, size_t numValues) {
    size_t numToReceive = numValues * sizeof(uint16_t);

    // Select the ADC
    ADC3_Select();

    // Perform SPI communication with ADC128S102
    for (size_t i = 0; i < numToReceive; ++i) {
        uint8_t transmittedData3 = 0xFF;  // dummy
        uint8_t receivedData3 = 0;

        // Clock in data bit by bit
        for (int bit = 7; bit >= 0; --bit) {
            // Set the DIN pin
            HAL_GPIO_WritePin(ADC3_GPIO_PORT, ADC3_DIN_PIN, (transmittedData3 >> bit) & 0x01);

            // Clock high
            ADC3_ClockHigh();

            // Shift in received data bit
            receivedData3 = (receivedData3 << 1) | HAL_GPIO_ReadPin(ADC3_GPIO_PORT, ADC3_DOUT_PIN);

            // Clock low
            ADC3_ClockLow();
        }

    // Store received data
    ((uint8_t*)values)[i] = receivedData3;
}


    // Deselect the ADC
    ADC3_Deselect();

    return ADC12_HAL_OK;
}

// VOUT READINGS 
  // need to make changes based on which ADC and channel
uint8_t ADC_Vout_Reading1() {  
    // Select input channel for VOUT
    uint8_t transmittedData3 = 0x08;  // depends on input channel

    // Select the ADC
    ADC2_Select();

    // Perform SPI communication with ADC128S102
    uint8_t receivedData3 = 0;
    for (int bit = 7; bit >= 0; --bit) {
        // Set the DIN pin
        HAL_GPIO_WritePin(ADC2_GPIO_D_PORT, ADC2_DIN_PIN, (transmittedData3 >> bit) & 0x01);

        // Clock high
        ADC2_ClockHigh();

        // Shift in received data bit
        receivedData3 = (receivedData3 << 1) | HAL_GPIO_ReadPin(ADC2_GPIO_D_PORT, ADC2_DOUT_PIN);

        // Clock low
        ADC2_ClockLow();
    }

    // Deselect the ADC
    ADC2_Deselect();

    return receivedData3;
}


uint8_t ADC_Vout_Reading2() {  
    // Select input channel for VOUT
    uint8_t transmittedData3 = 0x10;  // depends on input channel

    // Select the ADC
    ADC1_Select();

    // Perform SPI communication with ADC128S102
    uint8_t receivedData3 = 0;
    for (int bit = 7; bit >= 0; --bit) {
        // Set the DIN pin
        HAL_GPIO_WritePin(ADC1_GPIO_PORT, ADC1_DIN_PIN, (transmittedData3 >> bit) & 0x01);

        // Clock high
        ADC1_ClockHigh();

        // Shift in received data bit
        receivedData3 = (receivedData3 << 1) | HAL_GPIO_ReadPin(ADC1_GPIO_PORT, ADC1_DOUT_PIN);

        // Clock low
        ADC1_ClockLow();
    }

    // Deselect the ADC
    ADC1_Deselect();

    return receivedData3;
}


uint8_t ADC_Vout_Reading3() {  
    // Select input channel for VOUT
    uint8_t transmittedData3 = 0x0C;  // depends on input channel

    // Select the ADC
    ADC3_Select();

    // Perform SPI communication with ADC128S102
    uint8_t receivedData3 = 0;
    for (int bit = 7; bit >= 0; --bit) {
        // Set the DIN pin
        HAL_GPIO_WritePin(ADC3_GPIO_PORT, ADC3_DIN_PIN, (transmittedData3 >> bit) & 0x01);

        // Clock high
        ADC3_ClockHigh();

        // Shift in received data bit
        receivedData3 = (receivedData3 << 1) | HAL_GPIO_ReadPin(ADC3_GPIO_PORT, ADC3_DOUT_PIN);

        // Clock low
        ADC3_ClockLow();
    }

    // Deselect the ADC
    ADC3_Deselect();

    return receivedData3;
}


uint8_t ADC_Vout_Reading4() {  
    // Select input channel for VOUT
    uint8_t transmittedData3 = 0x04;  // depends on input channel

    // Select the ADC
    ADC2_Select();

    // Perform SPI communication with ADC128S102
    uint8_t receivedData3 = 0;
    for (int bit = 7; bit >= 0; --bit) {
        // Set the DIN pin
        HAL_GPIO_WritePin(ADC2_GPIO_D_PORT, ADC2_DIN_PIN, (transmittedData3 >> bit) & 0x01);

        // Clock high
        ADC3_ClockHigh();

        // Shift in received data bit
        receivedData3 = (receivedData3 << 1) | HAL_GPIO_ReadPin(ADC2_GPIO_D_PORT, ADC2_DOUT_PIN);

        // Clock low
        ADC2_ClockLow();
    }

    // Deselect the ADC
    ADC2_Deselect();

    return receivedData3;
}


uint8_t ADC_Vout_Reading5() {  
    // Select input channel for VOUT
    uint8_t transmittedData3 = 0x1C;  // 0b00011100

    // Select the ADC
    ADC1_Select();

    // Perform SPI communication with ADC128S102
    uint8_t receivedData3 = 0;
    for (int bit = 7; bit >= 0; --bit) {
        // Set the DIN pin
        HAL_GPIO_WritePin(ADC1_GPIO_PORT, ADC1_DIN_PIN, (transmittedData3 >> bit) & 0x01);

        // Clock high
        ADC3_ClockHigh();

        // Shift in received data bit
        receivedData3 = (receivedData3 << 1) | HAL_GPIO_ReadPin(ADC1_GPIO_PORT, ADC1_DOUT_PIN);

        // Clock low
        ADC1_ClockLow();
    }

    // Deselect the ADC
    ADC1_Deselect();

    return receivedData3;
}


uint8_t ADC_Vout_Reading6() {  
    // Select input channel for VOUT
    uint8_t transmittedData3 = 0x00;  // depends on input channel

    // Select the ADC
    ADC2_Select();

    // Perform SPI communication with ADC128S102
    uint8_t receivedData3 = 0;
    for (int bit = 7; bit >= 0; --bit) {
        // Set the DIN pin
        HAL_GPIO_WritePin(ADC2_GPIO_D_PORT, ADC2_DIN_PIN, (transmittedData3 >> bit) & 0x01);

        // Clock high
        ADC2_ClockHigh();

        // Shift in received data bit
        receivedData3 = (receivedData3 << 1) | HAL_GPIO_ReadPin(ADC2_GPIO_PORT, ADC2_DOUT_PIN);

        // Clock low
        ADC3_ClockLow();
    }

    // Deselect the ADC
    ADC3_Deselect();

    return receivedData3;
}

uint8_t ADC_Vout_Reading7() {  
    // Select input channel for VOUT
    uint8_t transmittedData3 = 0x18;  // depends on input channel

    // Select the ADC
    ADC3_Select();

    // Perform SPI communication with ADC128S102
    uint8_t receivedData3 = 0;
    for (int bit = 7; bit >= 0; --bit) {
        // Set the DIN pin
        HAL_GPIO_WritePin(ADC3_GPIO_PORT, ADC3_DIN_PIN, (transmittedData3 >> bit) & 0x01);

        // Clock high
        ADC3_ClockHigh();

        // Shift in received data bit
        receivedData3 = (receivedData3 << 1) | HAL_GPIO_ReadPin(ADC3_GPIO_PORT, ADC3_DOUT_PIN);

        // Clock low
        ADC3_ClockLow();
    }

    // Deselect the ADC
    ADC3_Deselect();

    return receivedData3;
}


uint8_t ADC_Vout_Reading8() {  
    // Select input channel for VOUT
    uint8_t transmittedData3 = 0x1C;  // 0b00011100

    // Select the ADC
    ADC2_Select();

    // Perform SPI communication with ADC128S102
    uint8_t receivedData3 = 0;
    for (int bit = 7; bit >= 0; --bit) {
        // Set the DIN pin
        HAL_GPIO_WritePin(ADC2_GPIO_D_PORT, ADC2_DIN_PIN, (transmittedData3 >> bit) & 0x01);

        // Clock high
        ADC3_ClockHigh();

        // Shift in received data bit
        receivedData3 = (receivedData3 << 1) | HAL_GPIO_ReadPin(ADC2_GPIO_D_PORT, ADC2_DOUT_PIN);

        // Clock low
        ADC2_ClockLow();
    }

    // Deselect the ADC
    ADC2_Deselect();

    return receivedData3;
}





