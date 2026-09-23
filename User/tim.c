#include "tim.h"

void TIM2_Config(void)
{
	TIM_TimeBaseInitTypeDef TIM_InitStructure;
	NVIC_InitTypeDef        NVIC_InitStruct;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	
	TIM_InitStructure.TIM_Prescaler					=64-1;
	TIM_InitStructure.TIM_CounterMode				=TIM_CounterMode_Up;
	TIM_InitStructure.TIM_Period						=10000-1;
	TIM_InitStructure.TIM_ClockDivision			=TIM_CKD_DIV1;
	TIM_InitStructure.TIM_RepetitionCounter	=0;
	TIM_TimeBaseInit(TIM2,&TIM_InitStructure);
	
	NVIC_InitStruct.NVIC_IRQChannel										=TIM2_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority	=0;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority				=0;
	NVIC_InitStruct.NVIC_IRQChannelCmd								=ENABLE;
	NVIC_Init(&NVIC_InitStruct);
	
}


void TIM3_Config(void)
{
	TIM_TimeBaseInitTypeDef TIM_InitStructure;
	NVIC_InitTypeDef        NVIC_InitStruct;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	
	TIM_InitStructure.TIM_Prescaler					=6400-1;
	TIM_InitStructure.TIM_CounterMode				=TIM_CounterMode_Up;
	TIM_InitStructure.TIM_Period						=5000-1;
	TIM_InitStructure.TIM_ClockDivision			=TIM_CKD_DIV1;
	TIM_InitStructure.TIM_RepetitionCounter	=0;
	TIM_TimeBaseInit(TIM3,&TIM_InitStructure);
	
	TIM_SelectOutputTrigger(TIM3,TIM_TRGOSource_Update);
	
	NVIC_InitStruct.NVIC_IRQChannel										=TIM3_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority	=0;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority				=0;
	NVIC_InitStruct.NVIC_IRQChannelCmd								=ENABLE;
	NVIC_Init(&NVIC_InitStruct);	
	
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
	TIM_Cmd(TIM3,ENABLE);
	
	
}




