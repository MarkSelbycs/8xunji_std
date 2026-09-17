#include "stm32f10x.h"                  // Device header
#include <stdio.h>


int fputc(int ch,FILE *f){
			
		while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);
		USART_SendData(USART1,(uint8_t)ch);
	  return ch;


}


void USART1_Config(){
		GPIO_InitTypeDef GPIO_Initstructure;
		USART_InitTypeDef USART_InitStructure;
    NVIC_InitTypeDef  NVIC_InitStructure;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_USART1,ENABLE);
		
		GPIO_Initstructure.GPIO_Pin=GPIO_Pin_9;
		GPIO_Initstructure.GPIO_Mode=GPIO_Mode_AF_PP;
		GPIO_Initstructure.GPIO_Speed=GPIO_Speed_50MHz;
		GPIO_Init(GPIOA,&GPIO_Initstructure);
	
		GPIO_Initstructure.GPIO_Pin=GPIO_Pin_10;
		GPIO_Initstructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
		GPIO_Init(GPIOA,&GPIO_Initstructure);
	
		USART_InitStructure.USART_BaudRate=115200;
		USART_InitStructure.USART_WordLength=USART_WordLength_8b;
		USART_InitStructure.USART_StopBits=USART_StopBits_1;
		USART_InitStructure.USART_Parity=USART_Parity_No;
		USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
		USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
		USART_Init(USART1,&USART_InitStructure);
		
		USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
		USART_Cmd(USART1,ENABLE);
	
		NVIC_InitStructure.NVIC_IRQChannel=USART1_IRQn;
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0;
		NVIC_InitStructure.NVIC_IRQChannelSubPriority=0;
		NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
		NVIC_Init(&NVIC_InitStructure);
	
}



