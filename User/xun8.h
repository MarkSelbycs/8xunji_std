#ifndef ___XUN8_H
#define ___XUN8_H

#include "stm32f10x.h" 

#define OUT1_0 GPIO_ResetBits(GPIOA, GPIO_Pin_15)
#define OUT2_0 GPIO_ResetBits(GPIOB, GPIO_Pin_3)
#define OUT3_0 GPIO_ResetBits(GPIOB, GPIO_Pin_4)
#define OUT4_0 GPIO_ResetBits(GPIOB, GPIO_Pin_5)
#define OUT5_0 GPIO_ResetBits(GPIOB, GPIO_Pin_6)
#define OUT6_0 GPIO_ResetBits(GPIOB, GPIO_Pin_7)
#define OUT7_0 GPIO_ResetBits(GPIOB, GPIO_Pin_8)
#define OUT8_0 GPIO_ResetBits(GPIOB, GPIO_Pin_9)

#define OUT1_1   GPIO_SetBits(GPIOA, GPIO_Pin_15)
#define OUT2_1   GPIO_SetBits(GPIOB, GPIO_Pin_3)
#define OUT3_1   GPIO_SetBits(GPIOB, GPIO_Pin_4)
#define OUT4_1   GPIO_SetBits(GPIOB, GPIO_Pin_5)
#define OUT5_1   GPIO_SetBits(GPIOB, GPIO_Pin_6)
#define OUT6_1   GPIO_SetBits(GPIOB, GPIO_Pin_7)
#define OUT7_1   GPIO_SetBits(GPIOB, GPIO_Pin_8)
#define OUT8_1   GPIO_SetBits(GPIOB, GPIO_Pin_9)


extern volatile uint16_t ADC_value[8]; 
extern volatile uint16_t ADC_setvalue[8]; 
extern volatile int			 mode;
extern volatile uint8_t	 rx; 

void xun8_Init(void);       
void xun8_UpdateOutputs(void); 
void xun8_KeyAction(void); 


#endif
