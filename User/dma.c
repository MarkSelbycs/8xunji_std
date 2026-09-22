#include "dma.h"
#include "stm32f10x.h"                  // Device header
#include "xun8.h"

void DMA1_Config(void){

	DMA_InitTypeDef  DMA_InitStructure;
	NVIC_InitTypeDef NVIC_InitStruct;
	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);
	
	DMA_DeInit(DMA1_Channel1);
	
	DMA_InitStructure.DMA_PeripheralBaseAddr=(uint32_t)&ADC1->DR;
	DMA_InitStructure.DMA_MemoryBaseAddr=(uint32_t)ADC_value;
	DMA_InitStructure.DMA_DIR=DMA_DIR_PeripheralSRC;
	DMA_InitStructure.DMA_BufferSize=8;
	DMA_InitStructure.DMA_PeripheralInc=DMA_PeripheralInc_Disable;
	
	DMA_InitStructure.DMA_MemoryInc=DMA_MemoryInc_Enable;
	
	DMA_InitStructure.DMA_PeripheralDataSize=DMA_PeripheralDataSize_HalfWord;
	DMA_InitStructure.DMA_MemoryDataSize     = DMA_MemoryDataSize_HalfWord;
	DMA_InitStructure.DMA_Mode=DMA_Mode_Circular;
	DMA_InitStructure.DMA_Priority=DMA_Priority_Low;
	DMA_InitStructure.DMA_M2M=DMA_M2M_Disable;
	DMA_Init(DMA1_Channel1,&DMA_InitStructure);

	DMA_ITConfig(DMA1_Channel1,DMA_IT_TC,ENABLE);
	
	NVIC_InitStruct.NVIC_IRQChannel=DMA1_Channel1_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=0;
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStruct);
	
	
	DMA_Cmd(DMA1_Channel1,ENABLE);
	
	
}



