#include "stm32f10x.h"             
#include "delay.h"
#include "gpio.h"
#include "usart.h"
#include <stdio.h>
#include "xun8.h"
#include "adc.h"
#include "dma.h"
#include "tim.h"


int main(void){
	
	delay_init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	
	GPIO_Config();
	DMA1_Config();
	ADC1_Config();
	TIM2_Config();
	USART1_Config();
	TIM3_Config();
	xun8_Init();
	
	
  while (1)
  {
		if(mode==0){GPIOB->ODR ^=GPIO_Pin_1;delay_ms(50);}
		if(mode==0){GPIOB->ODR ^=GPIO_Pin_1;delay_ms(50);}
	


   }
		
}	




