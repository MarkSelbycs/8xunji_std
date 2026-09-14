#include "stm32f10x.h"                  // Device header
#include "delay.h"

volatile uint32_t sys_ms=0;

void delay_init(void)
{
	SysTick_Config(SystemCoreClock/1000);//8000000/1000=8000

}


void delay_ms(uint32_t ms){
	
	uint32_t start=sys_ms;
	while((sys_ms-start)<ms);
}






