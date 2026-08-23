#include "main.h"

void SystemClockConfig(void);

int main(void)
{
  HAL_Init();
  SystemClockConfig();

  // Enabling the clock for port B
  __HAL_GPIOB_CLK_ENABLE();

  // Empty GPIO_InitTypeDef struct
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  
  // Setting PIN 2 in it
  GPIO_InitStruct.Pin = GPIO_PIN_2;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

  // Initializing pin 2
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  while(1)
  {
    // Toggle the pin -
    HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_2);
    // Delay 
    HAL_Delay (3000);
  }
    
}
 
.....  
