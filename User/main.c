#include "stm32f10x.h"             
#include "delay.h"
#include "gpio.h"
#include "usart.h"
#include <stdio.h>
#include "xun8.h"


int main(void){
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	delay_init();
	GPIO_Config();
	USART1_Config();
	xun8_Init();
	
	
  while (1)
  {
	if (mode == 0)               
  {
		if (GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_1))
				GPIO_ResetBits(GPIOB, GPIO_Pin_1);
		else
				GPIO_SetBits(GPIOB, GPIO_Pin_1);
		delay_ms(50);
		}
	  if (mode == 1)               
	{
			if (GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_1))
					GPIO_ResetBits(GPIOB, GPIO_Pin_1);
			else
					GPIO_SetBits(GPIOB, GPIO_Pin_1);
			delay_ms(200);
	}


    }
		
		
}	




