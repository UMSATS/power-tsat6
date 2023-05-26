/**
  ******************************************************************************
  * @file           : LTC41_driver.c
  * @brief          : Program for Coulomb Counter
  ******************************************************************************
  not a real driver
  ****************************************************************************** **/
 /*
 * FILENAME: LTC41_driver.c
 *
 * DESCRIPTION: Driver for the LTC4150MS coulomb counter.
 *
 * AUTHORS:
 *  - Sanjana RoyChowdhury (sanjana.roy@umsats.ca)
 *
 * CREATED ON: May 2nd, 2023
 */

//###############################################################################################
//Include Directives
//###############################################################################################
#include "stm32l4xx_hal.h"
#include "LTC41_driver.h"

//global variables
uint8_t ltc41InterruptFlag = 0; 


//###############################################################################################
//Driver Functions
//###############################################################################################

void LTC4150IMS_Init(void)
{
    
    LTC4150IMS_DisableShutdown(); 


    // Configure the interrupt for the INT pin
    HAL_NVIC_SetPriority(EXTI0_IRQn , 0, 0);
    HAL_NVIC_EnableIRQ(EXTI0_IRQn);  //replace interupt line with correct for microcontroller
    charge = 12060;//Capacity of the battery
}


float LTC4150IMS_GetCurrent(void)
{
    // Read the voltage across the shunt resistor using ADC
    uint16_t adcValue = HAL_ADC_GetValue(&hadc1); // replace with adc peripheral (need to initialize in STM)

    //get voltage
    float voltage = (float)adcValue * ADC_RESOLUTION / ADC_MAX_VALUE;

    // get current
    float current = voltage / SHUNT_RESISTOR_VALUE;

    // Return current in mA
    return current * 1000.0f;
}



void LTC4150IMS_Clear(void)
{
    // Set the CLR pin low for 1us to reset INT
    HAL_GPIO_WritePin(LTC4150IMS_GPIO_SC_Port, LTC4150IMS_CLR_PIN, GPIO_PIN_RESET);

    // Set the CLR pin high again
    HAL_GPIO_WritePin(LTC4150IMS_GPIO_SC_Port, LTC4150IMS_CLR_PIN, GPIO_PIN_SET);
}


void LTC4150IMS_SetPolarity(uint8_t polarity)
{
    if (polarity)
    {
        // Set the polarity pin high 
        HAL_GPIO_WritePin(LTC4150IMS_GPIO_PI_Port, LTC4150IMS_POL_PIN, GPIO_PIN_SET);
    }
    else
    {
        // Set the polarity pin low 
        HAL_GPIO_WritePin(LTC4150IMS_GPIO_PI_Port, LTC4150IMS_POL_PIN, GPIO_PIN_RESET);
    }
}



void LTC4150IMS_EnableShutdown(void)
{
    // Set the SHDN pin low 
    HAL_GPIO_WritePin(LTC4150IMS_GPIO_SC_Port, LTC4150IMS_SHDN_PIN, GPIO_PIN_RESET);
}



void LTC4150IMS_DisableShutdown(void)
{
    // Set the SHDN pin high 
    HAL_GPIO_WritePin(LTC4150IMS_GPIO_SC_Port, LTC4150IMS_SHDN_PIN, GPIO_PIN_SET);
}

// note to self:  when initializing in main.c need to set flag to 0 
void LTC4150IMS_INT_IRQHandler(void)
{

  // Clear the interrupt by generating a low pulse on the CLR pin
  HAL_GPIO_WritePin(LTC4150IMS_GPIO_PI_Port, LTC4150IMS_CLR_PIN, GPIO_PIN_RESET);

  // Delay for 1 microsecond
  HAL_Delay(1);

  // Set interrupt flag
  ltc41InterruptFlag = 1;

}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if (GPIO_Pin == LTC4150IMS_INT_PIN)
  {  
      // interrupt handling code ....
      DCDC_StatusTypeDef operation_status;
      float chargeChange = 1/(VOLT_FREQ_GAIN*R_SENSE);//change in charge in coulombs
      GPIO_PinState polarity = HAL_GPIO_ReadPin(operation_status, LTC4150IMS_POL_PIN);
      if(polarity == GPIO_PIN_SET)
      {
        charge += chargeChange;
      }
      else if(polarity == GPIO_PIN_RESET)
      {
        charge -= chargeChange;
      }
      HAL_GPIO_WritePin(LTC4150IMS_GPIO_PI_Port, LTC4150IMS_CLR_PIN, GPIO_PIN_SET);

  }
}



 
