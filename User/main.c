#include "stm32f10x.h"             
#include "delay.h"

volatile uint32_t test_cnt=0;
int main(void){
	delay_init();

  while (1)
  {
	delay_ms(1000);
	test_cnt++;

	}
}







