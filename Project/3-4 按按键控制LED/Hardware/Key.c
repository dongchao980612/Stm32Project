#include "stm32f10x.h"                  // Device header

#include "delay.h"

void Key_Init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE); 

	GPIO_InitTypeDef GPIO_InitStructure;	 
				 
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_9|GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
}

uint8_t Key_GetNum(void){
	uint8_t keyNum = 0;
	
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)==0) //按下
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)==0){
			Delay_ms(20);
			keyNum = 1;
			
		}
	}
	
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)==0) //按下
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)==0){
			Delay_ms(20);
			keyNum = 2;
			
		}
	}
	
	return keyNum;
}
