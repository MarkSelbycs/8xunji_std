#include "stm32f10x.h"             
#include "delay.h"
#include "gpio.h"
#include "usart.h"
#include <stdio.h>


int main(void){
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	delay_init();
	GPIO_Config();
	USART1_Config();
	printf("Steps5 usart ok\r\n");
	
	
  while (1)
  {
		if(GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_1))
			GPIO_ResetBits(GPIOB,GPIO_Pin_1);
		else
			GPIO_SetBits(GPIOB,GPIO_Pin_1);
		delay_ms(50); 
		printf("usart ok\r\n");
		}				





}




