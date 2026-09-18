#include "xun8.h"
#include "stm32f10x.h"                  // Device header

volatile uint16_t ADC_value[8]; 
volatile uint16_t ADC_setvalue[8]; 
volatile int			 mode=0;
volatile uint8_t	 rx=0; 

void xun8_Init(void){
		OUT1_0;OUT2_0;OUT3_0;OUT4_0;
		OUT5_0;OUT6_0;OUT7_0;OUT8_0;
}

void xun8_UpdateOutputs(void){
	if (ADC_value[7] > ADC_setvalue[7]) {OUT1_0;}else{OUT1_1;}
	if (ADC_value[6] > ADC_setvalue[6]) {OUT2_0;}else{OUT2_1;}
	if (ADC_value[5] > ADC_setvalue[5]) {OUT3_0;}else{OUT3_1;}
	if (ADC_value[4] > ADC_setvalue[4]) {OUT4_0;}else{OUT4_1;}
	if (ADC_value[3] > ADC_setvalue[3]) {OUT5_0;}else{OUT5_1;}
	if (ADC_value[2] > ADC_setvalue[2]) {OUT6_0;}else{OUT6_1;}
	if (ADC_value[1] > ADC_setvalue[1]) {OUT7_0;}else{OUT7_1;}
	if (ADC_value[0] > ADC_setvalue[0]) {OUT8_0;}else{OUT8_1;}

}
void xun8_KeyAction(void){
	int i;
	mode++;
	if(mode==1){
		for(i=0;i<=7;i++){
			ADC_setvalue[i]=ADC_value[i];
		}
	}
	if(mode==2){
		for(i=0;i<=7;i++){
			ADC_setvalue[i]=(ADC_value[i]+ADC_value[i])/2;
		}
		mode=3;
	}
	if(mode>=3){
			mode=3;
			GPIO_ResetBits(GPIOB,GPIO_Pin_1);
		}
}
	
	


