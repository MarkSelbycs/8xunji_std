#include "stm32f10x.h"             
#include "delay.h"
#include "gpio.h"

int main(void){
	delay_init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	GPIO_Config();
	
	
  while (1)
  {
		if(GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_1))
			GPIO_ResetBits(GPIOB,GPIO_Pin_1);
		else
			GPIO_SetBits(GPIOB,GPIO_Pin_1);
		delay_ms(50); 
		}				





}




