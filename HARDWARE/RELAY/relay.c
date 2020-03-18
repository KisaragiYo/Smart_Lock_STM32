#include "relay.h"   


//��ʼ��PB15Ϊ�����.��ʹ������ڵ�ʱ��		    
//Relay IO��ʼ��
void Relay_Init(void)
{
 
	 GPIO_InitTypeDef  GPIO_InitStructure;
		
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //ʹ��PB�˿�ʱ��
		
	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;				 //Relay-->PB15�˿�����
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
	 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOB
	 GPIO_ResetBits(GPIOB,GPIO_Pin_15);						 //PB.15�����

}


void Relay_on(void)
{
	 GPIO_SetBits(GPIOB,GPIO_Pin_15);				
}	

void Relay_off(void)
{
	 GPIO_ResetBits(GPIOB,GPIO_Pin_15);				
}	
