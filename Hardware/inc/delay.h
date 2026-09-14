#ifndef __DELAY_H
#define __DELAY_H

#include "stm32f10x.h"    

extern volatile uint32_t sys_ms;

void delay_init(void);
void delay_ms(uint32_t ms);

#endif



