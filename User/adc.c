#include "adc.h"
#include "stm32f10x.h"                  // Device header

void ADC1_Config(){

		ADC_InitTypeDef ADC_InitStructure;
		GPIO_InitTypeDef GPIO_InitStructure;
		uint8_t i;
	
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1 | RCC_APB2Periph_GPIOA, ENABLE);
	
		RCC_ADCCLKConfig(RCC_PCLK2_Div4);
		
		GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 |
                                   GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;

		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
	
		ADC_InitStructure.ADC_Mode								=ADC_Mode_Independent;
		ADC_InitStructure.ADC_ScanConvMode				=ENABLE;
		ADC_InitStructure.ADC_ContinuousConvMode	=ENABLE;
		ADC_InitStructure.ADC_ExternalTrigConv		=ADC_ExternalTrigConv_T3_TRGO;
		ADC_InitStructure.ADC_DataAlign						=ADC_DataAlign_Right;
		ADC_InitStructure.ADC_NbrOfChannel				=8;
		ADC_Init(ADC1,&ADC_InitStructure);
		
		for(i=0;i<8;i++){
			ADC_RegularChannelConfig(ADC1,(uint8_t)(ADC_Channel_0+i),(uint8_t)(i+1),
															 ADC_SampleTime_239Cycles5);
		}
		ADC_Cmd(ADC1,ENABLE);
			
		ADC_ResetCalibration(ADC1);
		while(ADC_GetResetCalibrationStatus(ADC1)==SET){}
		ADC_StartCalibration(ADC1);
		while(ADC_GetCalibrationStatus(ADC1)==SET){}
		ADC_ExternalTrigConvCmd(ADC1, ENABLE);	
		ADC_DMACmd(ADC1, ENABLE); 			
}
