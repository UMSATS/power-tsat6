/*
 * FILENAME: LTC41_driver.c
 *
 * DESCRIPTION: Driver for the LTC4150MS coulomb counter.
 *
 * AUTHORS:
 *  - Sanjana RoyChowdhury (sanjana.roy@umsats.ca)
 *  - Eran Efron (eran.efron@umsats.ca)
 *
 * CREATED ON: May 2, 2023
 */
//###############################################################################################
//Include Directives
//###############################################################################################
#include "stm32l4xx_hal.h"
#include "stm32l452xx.h"
#include "LTC41_driver.h"

//###############################################################################################
//Driver Functions
//###############################################################################################
uint8_t ltc41InterruptFlag = 0; 

void LTC4150IMS_Init(void)
{
    LTC4150IMS_DisableShutdown(); 

    HAL_NVIC_SetPriority(EXTI0_IRQn , 0, 0);
    HAL_NVIC_EnableIRQ(EXTI0_IRQn);  
    charge = 12060;
}


void LTC4150IMS_Clear(void)
{
    HAL_GPIO_WritePin(LTC4150IMS_GPIO_SC_Port, LTC4150IMS_CLR_PIN, GPIO_PIN_RESET);

    HAL_GPIO_WritePin(LTC4150IMS_GPIO_SC_Port, LTC4150IMS_CLR_PIN, GPIO_PIN_SET);
}


void LTC4150IMS_SetPolarity(uint8_t polarity)
{
    if (polarity)
    {
        HAL_GPIO_WritePin(LTC4150IMS_GPIO_PI_Port, LTC4150IMS_POL_PIN, GPIO_PIN_SET);
    }
    else
    {
        HAL_GPIO_WritePin(LTC4150IMS_GPIO_PI_Port, LTC4150IMS_POL_PIN, GPIO_PIN_RESET);
    }
}



void LTC4150IMS_EnableShutdown(void)
{
    HAL_GPIO_WritePin(LTC4150IMS_GPIO_SC_Port, LTC4150IMS_SHDN_PIN, GPIO_PIN_RESET);
}



void LTC4150IMS_DisableShutdown(void)
{
    HAL_GPIO_WritePin(LTC4150IMS_GPIO_SC_Port, LTC4150IMS_SHDN_PIN, GPIO_PIN_SET);
}

void LTC4150IMS_INT_IRQHandler(void)
{

  HAL_GPIO_WritePin(LTC4150IMS_GPIO_SC_Port, LTC4150IMS_CLR_PIN, GPIO_PIN_RESET);

  HAL_Delay(1);

  ltc41InterruptFlag = 1;

}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if (GPIO_Pin == LTC4150IMS_INT_PIN)
  {  
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
      HAL_GPIO_WritePin(LTC4150IMS_GPIO_SC_Port, LTC4150IMS_CLR_PIN, GPIO_PIN_SET);

  }
}



 
