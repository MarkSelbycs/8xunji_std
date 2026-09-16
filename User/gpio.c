#include "stm32f10x.h"                  // Device header
#include "gpio.h"

void GPIO_Config(){
	
	GPIO_InitTypeDef GPIO_Initstructure;
	EXTI_InitTypeDef EXTI_Initstructure;
	NVIC_InitTypeDef NVIC_Initstructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|
												RCC_APB2Periph_GPIOB|
												RCC_APB2Periph_AFIO
												,ENABLE);
	
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
	GPIO_ResetBits(GPIOA, GPIO_Pin_15);
	GPIO_ResetBits(GPIOB, GPIO_Pin_1 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 |
                          GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9);
	
	GPIO_Initstructure.GPIO_Pin=GPIO_Pin_0;
	GPIO_Initstructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Init(GPIOB,&GPIO_Initstructure);
	
	GPIO_Initstructure.GPIO_Pin= GPIO_Pin_1 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 |
                                    GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_Initstructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Initstructure.GPIO_Speed=GPIO_Speed_2MHz;
	GPIO_Init(GPIOB,&GPIO_Initstructure);
	
	
	GPIO_Initstructure.GPIO_Pin=GPIO_Pin_15;
	GPIO_Init(GPIOA,&GPIO_Initstructure);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource0);
	EXTI_Initstructure.EXTI_Line=EXTI_Line0;
	EXTI_Initstructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_Initstructure.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_Initstructure.EXTI_LineCmd=ENABLE;
	EXTI_Init(&EXTI_Initstructure);
	
	NVIC_Initstructure.NVIC_IRQChannel=EXTI0_IRQn;
	NVIC_Initstructure.NVIC_IRQChannelPreemptionPriority=0;
	NVIC_Initstructure.NVIC_IRQChannelSubPriority=0;
	NVIC_Initstructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_Initstructure);
	
	
	
	
	
}

