/*
 * FILENAME: ADC128S102_driver.c
 *
 * DESCRIPTION: Driver for Analog to digital converter.
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

void ADC1_Select() {
    HAL_GPIO_WritePin(ADC1_GPIO_PORT, ADC1_CS_PIN, GPIO_PIN_SET);
}

void ADC1_Deselect() {
    HAL_GPIO_WritePin(ADC1_GPIO_PORT, ADC1_CS_PIN, GPIO_PIN_RESET);
}


void ADC1_ClockHigh() {
    HAL_GPIO_WritePin(ADC1_GPIO_PORT, ADC1_SCLK_PIN, GPIO_PIN_SET);
}

void ADC1_ClockLow() {
    HAL_GPIO_WritePin(ADC1_GPIO_PORT, ADC1_SCLK_PIN, GPIO_PIN_RESET);
}


ADC12_StatusTypeDef ADC1_ReadValues(uint16_t* values, size_t numValues) {

    size_t numToReceive = numValues * sizeof(uint16_t);

    ADC1_Select();

    for (size_t i = 0; i < numToReceive; ++i) {
        uint8_t transmittedData1 = 0xFF;  // dummy
        uint8_t recievedData1 = 0;

        for (int bit = 7; bit >= 0; --bit) {
            HAL_GPIO_WritePin(ADC1_GPIO_PORT, ADC1_DIN_PIN, (transmittedData1 >> bit) & 0x01);

            ADC1_ClockHigh();

            recievedData1 = (recievedData1 << 1) | HAL_GPIO_ReadPin(ADC1_GPIO_PORT, ADC1_DOUT_PIN);

            ADC1_ClockLow();
        }

        ((uint8_t*)values)[i] = recievedData1;
    }

    ADC1_Deselect();

    return ADC12_HAL_OK;
}


// ADC 2


void ADC2_Select() {
    HAL_GPIO_WritePin(ADC2_GPIO_C_PORT, ADC2_CS_PIN, GPIO_PIN_SET);
}

void ADC2_Deselect() {
    HAL_GPIO_WritePin(ADC2_GPIO_C_PORT, ADC2_CS_PIN, GPIO_PIN_RESET);
}


void ADC2_ClockHigh() {
    HAL_GPIO_WritePin(ADC2_GPIO_C_PORT, ADC2_SCLK_PIN, GPIO_PIN_SET);
}

void ADC2_ClockLow() {
    HAL_GPIO_WritePin(ADC2_GPIO_C_PORT, ADC2_SCLK_PIN, GPIO_PIN_RESET);
}

ADC12_StatusTypeDef ADC2_ReadValues(uint16_t* values, size_t numValues) {
    size_t numToReceive = numValues * sizeof(uint16_t);

    ADC2_Select();


    for (size_t i = 0; i < numToReceive; ++i) {
        uint8_t transmittedData2 = 0xFF;
        uint8_t recievedData2 = 0;

        for (int bit = 7; bit >= 0; --bit) {
            HAL_GPIO_WritePin(ADC2_GPIO_D_PORT, ADC2_DIN_PIN, (transmittedData2 >> bit) & 0x01);

            ADC2_ClockHigh();

            recievedData2 = (recievedData2 << 1) | HAL_GPIO_ReadPin(ADC2_GPIO_D_PORT, ADC2_DOUT_PIN);

]            ADC2_ClockLow();
        }

        ((uint8_t*)values)[i] = recievedData2;
    }

    ADC2_Deselect();

    return ADC12_HAL_OK;
}



// ADC 3

void ADC3_Select() {
    HAL_GPIO_WritePin(ADC3_GPIO_CS_PORT, ADC3_CS_PIN, GPIO_PIN_SET);
}

void ADC3_Deselect() {
    HAL_GPIO_WritePin(ADC3_GPIO_CS_PORT, ADC3_CS_PIN, GPIO_PIN_RESET);
}

void ADC3_ClockHigh() {
    HAL_GPIO_WritePin(ADC3_GPIO_PORT, ADC3_SCLK_PIN, GPIO_PIN_SET);
}

void ADC3_ClockLow() {
    HAL_GPIO_WritePin(ADC3_GPIO_PORT, ADC3_SCLK_PIN, GPIO_PIN_RESET);
}

uint16_t ADC3_ReadValue_BatteryTemp() {
    uint8_t transmittedData3 = 0x1C;  // 0b00011100

    ADC3_Select();

    uint16_t receivedData3 = 0;
    for (int bit = 7; bit >= 0; --bit) {
        HAL_GPIO_WritePin(ADC3_GPIO_PORT, ADC3_DIN_PIN, (transmittedData3 >> bit) & 0x01);

        ADC3_ClockHigh();

        receivedData3 = (receivedData3 << 1) | HAL_GPIO_ReadPin(ADC3_GPIO_PORT, ADC3_DOUT_PIN);

        ADC3_ClockLow();
    }

    uint8_t receivedData4 = 0;
    for (int bit = 7; bit >= 0; --bit) {
        HAL_GPIO_WritePin(ADC3_GPIO_PORT, ADC3_DIN_PIN, 0x00);

        ADC3_ClockHigh();

        receivedData4 = (receivedData4 << 1) | HAL_GPIO_ReadPin(ADC3_GPIO_PORT, ADC3_DOUT_PIN);

        ADC3_ClockLow();
    }

    uint16_t value = (receivedData3 << 8) | receivedData4;

    ADC3_Deselect();

    return value;
}


ADC12_StatusTypeDef ADC3_ReadValues(uint16_t* values, size_t numValues) {
    size_t numToReceive = numValues * sizeof(uint16_t);

    ADC3_Select();

    for (size_t i = 0; i < numToReceive; ++i) {
        uint8_t transmittedData3 = 0xFF;  // dummy
        uint8_t receivedData3 = 0;

        for (int bit = 7; bit >= 0; --bit) {
            HAL_GPIO_WritePin(ADC3_GPIO_PORT, ADC3_DIN_PIN, (transmittedData3 >> bit) & 0x01);

            ADC3_ClockHigh();

            receivedData3 = (receivedData3 << 1) | HAL_GPIO_ReadPin(ADC3_GPIO_PORT, ADC3_DOUT_PIN);

            ADC3_ClockLow();
        }

    ((uint8_t*)values)[i] = receivedData3;
}


    ADC3_Deselect();

    return ADC12_HAL_OK;
}

// VOUT READINGS 

uint8_t ADC_Vout_Reading1() {  
    uint8_t transmittedData3 = 0x08;  

    ADC2_Select();

    uint8_t receivedData3 = 0;
    for (int bit = 7; bit >= 0; --bit) {
        HAL_GPIO_WritePin(ADC2_GPIO_D_PORT, ADC2_DIN_PIN, (transmittedData3 >> bit) & 0x01);

        ADC2_ClockHigh();

        receivedData3 = (receivedData3 << 1) | HAL_GPIO_ReadPin(ADC2_GPIO_D_PORT, ADC2_DOUT_PIN);

        ADC2_ClockLow();
    }

    ADC2_Deselect();

    return receivedData3;
}

uint8_t ADC_Vout_Reading2() {
    uint8_t transmittedData3 = 0x10;

    ADC1_Select();

    uint8_t receivedData3 = 0;
    for (int bit = 7; bit >= 0; --bit) {

        HAL_GPIO_WritePin(ADC1_GPIO_PORT, ADC1_DIN_PIN, (transmittedData3 >> bit) & 0x01);

        ADC1_ClockHigh();

        receivedData3 = (receivedData3 << 1) | HAL_GPIO_ReadPin(ADC1_GPIO_PORT, ADC1_DOUT_PIN);

        ADC1_ClockLow();
    }

    ADC1_Deselect();

    return receivedData3;
}

uint8_t ADC_Vout_Reading3() {
    uint8_t transmittedData3 = 0x0C;

    ADC3_Select();

    uint8_t receivedData3 = 0;
    for (int bit = 7; bit >= 0; --bit) {

        HAL_GPIO_WritePin(ADC3_GPIO_PORT, ADC3_DIN_PIN, (transmittedData3 >> bit) & 0x01);

        ADC3_ClockHigh();

        receivedData3 = (receivedData3 << 1) | HAL_GPIO_ReadPin(ADC3_GPIO_PORT, ADC3_DOUT_PIN);

        ADC3_ClockLow();
    }

    ADC3_Deselect();

    return receivedData3;
}

uint8_t ADC_Vout_Reading4() {
    uint8_t transmittedData3 = 0x04;

    ADC2_Select();

    uint8_t receivedData3 = 0;
    for (int bit = 7; bit >= 0; --bit) {

        HAL_GPIO_WritePin(ADC2_GPIO_D_PORT, ADC2_DIN_PIN, (transmittedData3 >> bit) & 0x01);

        ADC3_ClockHigh();

        receivedData3 = (receivedData3 << 1) | HAL_GPIO_ReadPin(ADC2_GPIO_D_PORT, ADC2_DOUT_PIN);

        ADC2_ClockLow();
    }

    ADC2_Deselect();

    return receivedData3;
}



uint8_t ADC_Vout_Reading5() {  
    uint8_t transmittedData3 = 0x1C;  

    ADC1_Select();

    uint8_t receivedData3 = 0;
    for (int bit = 7; bit >= 0; --bit) {
        HAL_GPIO_WritePin(ADC1_GPIO_PORT, ADC1_DIN_PIN, (transmittedData3 >> bit) & 0x01);

        ADC3_ClockHigh();

        receivedData3 = (receivedData3 << 1) | HAL_GPIO_ReadPin(ADC1_GPIO_PORT, ADC1_DOUT_PIN);

        ADC1_ClockLow();
    }

    ADC1_Deselect();

    return receivedData3;
}


uint8_t ADC_Vout_Reading6() {  
    uint8_t transmittedData3 = 0x00;  

    ADC2_Select();

    uint8_t receivedData3 = 0;
    for (int bit = 7; bit >= 0; --bit) {
        HAL_GPIO_WritePin(ADC2_GPIO_D_PORT, ADC2_DIN_PIN, (transmittedData3 >> bit) & 0x01);

        ADC2_ClockHigh();

        receivedData3 = (receivedData3 << 1) | HAL_GPIO_ReadPin(ADC2_GPIO_PORT, ADC2_DOUT_PIN);

        ADC3_ClockLow();
    }

    ADC3_Deselect();

    return receivedData3;
}

uint8_t ADC_Vout_Reading7() {  
    uint8_t transmittedData3 = 0x18;  

    ADC3_Select();

    uint8_t receivedData3 = 0;
    for (int bit = 7; bit >= 0; --bit) {
        HAL_GPIO_WritePin(ADC3_GPIO_PORT, ADC3_DIN_PIN, (transmittedData3 >> bit) & 0x01);

        ADC3_ClockHigh();

        receivedData3 = (receivedData3 << 1) | HAL_GPIO_ReadPin(ADC3_GPIO_PORT, ADC3_DOUT_PIN);

        ADC3_ClockLow();
    }

    ADC3_Deselect();

    return receivedData3;
}


uint8_t ADC_Vout_Reading8() {  
    uint8_t transmittedData3 = 0x1C; 

    ADC2_Select();

    uint8_t receivedData3 = 0;
    for (int bit = 7; bit >= 0; --bit) {
        HAL_GPIO_WritePin(ADC2_GPIO_D_PORT, ADC2_DIN_PIN, (transmittedData3 >> bit) & 0x01);

        ADC3_ClockHigh();

        receivedData3 = (receivedData3 << 1) | HAL_GPIO_ReadPin(ADC2_GPIO_D_PORT, ADC2_DOUT_PIN);

        ADC2_ClockLow();
    }

    ADC2_Deselect();

    return receivedData3;
}





