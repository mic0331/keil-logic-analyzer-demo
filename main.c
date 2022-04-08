#include "stm32f4xx_hal.h"              // Keil::Device:STM32Cube HAL:Common

uint32_t freq = 0;
volatile uint32_t counter = 0;

extern void SystemClock_Config(void);

int main()
{
	int i = 0;
	
	HAL_Init();
	SystemClock_Config();
	freq = HAL_RCC_GetHCLKFreq();
	
	while(1)
	{
		counter++;
		if(counter == 100) 
			counter = 0;
		for(i=0;i<3000;i++)
		{
			__asm__("nop");
		}
	}
}

void SysTick_Handler(void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}
