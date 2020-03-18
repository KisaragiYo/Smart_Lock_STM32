#include "relay.h"   


//初始化PB15为输出口.并使能这个口的时钟		    
//Relay IO初始化
void Relay_Init(void)
{
 
	 GPIO_InitTypeDef  GPIO_InitStructure;
		
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //使能PB端口时钟
		
	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;				 //Relay-->PB15端口配置
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
	 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //根据设定参数初始化GPIOB
	 GPIO_ResetBits(GPIOB,GPIO_Pin_15);						 //PB.15输出高

}


void Relay_on(void)
{
	 GPIO_SetBits(GPIOB,GPIO_Pin_15);				
}	

void Relay_off(void)
{
	 GPIO_ResetBits(GPIOB,GPIO_Pin_15);				
}	
