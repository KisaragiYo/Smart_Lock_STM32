#include "mpr121.h"


////����IIC��ʼ�ź�
//void Mpr121_IIC_Start(void)
//{
//	Mpr121_SDA_OUT();     //sda�����
//	Mpr121_IIC_SDA=1;	  	  
//	Mpr121_IIC_SCL=1;
//	delay_us(4);
// 	Mpr121_IIC_SDA=0;//START:when CLK is high,DATA change form high to low 
//	delay_us(4);
//	Mpr121_IIC_SCL=0;//ǯסI2C���ߣ�׼�����ͻ�������� 
//}	  
////����IICֹͣ�ź�
//void Mpr121_IIC_Stop(void)
//{
//	Mpr121_SDA_OUT();//sda�����
//	Mpr121_IIC_SCL=0;
//	Mpr121_IIC_SDA=0;//STOP:when CLK is high DATA change form low to high
// 	delay_us(4);
//	Mpr121_IIC_SCL=1; 
//	Mpr121_IIC_SDA=1;//����I2C���߽����ź�
//	delay_us(4);							   	
//}
////�ȴ�Ӧ���źŵ���
////����ֵ��1������Ӧ��ʧ��
////        0������Ӧ��ɹ�
//u8 Mpr121_IIC_Wait_Ack(void)
//{
//	u8 ucErrTime=0;
//	Mpr121_SDA_IN();      //SDA����Ϊ����  
//	Mpr121_IIC_SDA=1;delay_us(1);	   
//	Mpr121_IIC_SCL=1;delay_us(1);	 
//	while(Mpr121_READ_SDA)
//	{
//		ucErrTime++;
//		if(ucErrTime>250)
//		{
//			Mpr121_IIC_Stop();
//			return 1;
//		}
//	}
//	Mpr121_IIC_SCL=0;//ʱ�����0 	   
//	return 0;  
//} 
////����ACKӦ��
//void Mpr121_IIC_Ack(void)
//{
//	Mpr121_IIC_SCL=0;
//	Mpr121_SDA_OUT();
//	Mpr121_IIC_SDA=0;
//	delay_us(2);
//	Mpr121_IIC_SCL=1;
//	delay_us(2);
//	Mpr121_IIC_SCL=0;
//}
////������ACKӦ��		    
//void Mpr121_IIC_NAck(void)
//{
//	Mpr121_IIC_SCL=0;
//	Mpr121_SDA_OUT();
//	Mpr121_IIC_SDA=1;
//	delay_us(2);
//	Mpr121_IIC_SCL=1;
//	delay_us(2);
//	Mpr121_IIC_SCL=0;
//}					 				     
////IIC����һ���ֽ�
////���شӻ�����Ӧ��
////1����Ӧ��
////0����Ӧ��			  
//void Mpr121_IIC_Send_Byte(u8 txd)
//{                        
//    u8 t;   
//		Mpr121_SDA_OUT(); 	    
//    Mpr121_IIC_SCL=0;//����ʱ�ӿ�ʼ���ݴ���
//    for(t=0;t<8;t++)
//    {              
//        //Mpr121_IIC_SDA=(txd&0x80)>>7;
//		if((txd&0x80)>>7)
//			Mpr121_IIC_SDA=1;
//		else
//			Mpr121_IIC_SDA=0;
//		txd<<=1; 	  
//		delay_us(2); 
//		Mpr121_IIC_SCL=1;
//		delay_us(2); 
//		Mpr121_IIC_SCL=0;	
//		delay_us(2);
//    }	 
//} 	    
////��1���ֽڣ�ack=1ʱ������ACK��ack=0������nACK   
//u8 Mpr121_IIC_Read_Byte(unsigned char ack)
//{
//	unsigned char i,receive=0;
//	Mpr121_SDA_IN();//SDA����Ϊ����
//    for(i=0;i<8;i++ )
//	{
//        Mpr121_IIC_SCL=0; 
//        delay_us(2);
//				Mpr121_IIC_SCL=1;
//        receive<<=1;
//        if(Mpr121_READ_SDA)receive++;   
//		delay_us(1); 
//    }					 
//    if (!ack)
//        Mpr121_IIC_NAck();//����nACK
//    else
//        Mpr121_IIC_Ack(); //����ACK   
//    return receive;
//}

//void Mpr121_Write(unsigned char address, unsigned char data)
//{
//  Mpr121_IIC_Start();
//  
//  Mpr121_IIC_Send_Byte(MPR121_W);// write 0xB4
//  Mpr121_IIC_Wait_Ack();
//	
//  Mpr121_IIC_Send_Byte(address);	// write register address
//  Mpr121_IIC_Wait_Ack();
//  
//  Mpr121_IIC_Send_Byte(data);
//  Mpr121_IIC_Wait_Ack();
//  
//  Mpr121_IIC_Stop();
//}

//unsigned char Mpr121_Read(uint8_t address)
//{
//  unsigned char  data;
//  
//  Mpr121_IIC_Start();
// 
//  Mpr121_IIC_Send_Byte(MPR121_W);	// write 0xB4
//  Mpr121_IIC_Wait_Ack();
//  
//  Mpr121_IIC_Send_Byte(address);	// write register address
//  Mpr121_IIC_Wait_Ack();
//  
//  Mpr121_IIC_Start();
//  
//  Mpr121_IIC_Send_Byte(MPR121_R);	// write 0xB5
//  Mpr121_IIC_Wait_Ack();
//  data = Mpr121_IIC_Read_Byte(1);
//  
//  Mpr121_IIC_Stop();
//  
//  return data;
//}

//void Mpr121_IRQ_Init(void)
//{
// 
//	EXTI_InitTypeDef EXTI_InitStructure;
//	NVIC_InitTypeDef NVIC_InitStructure;
// 	GPIO_InitTypeDef GPIO_InitStructure;
// 
// 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO,ENABLE);//ʹ��ʱ��

//	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_6;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
// 	GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOA6


//	//GPIOA.6 �ж����Լ��жϳ�ʼ������   �½��ش���
//	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource6);
//	EXTI_InitStructure.EXTI_Line=EXTI_Line6;	
//	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
//	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
//	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
//	EXTI_Init(&EXTI_InitStructure);	 	//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���

//	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			//ʹ��GPIOA.6���ڵ��ⲿ�ж�ͨ��
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;	//��ռ���ȼ�1
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;					//�����ȼ�1
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ʹ���ⲿ�ж�ͨ��
//	NVIC_Init(&NVIC_InitStructure); 
//}

//��ʼ��IIC
void Mpr121_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;	 
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//�ٶ�50MHz
 	GPIO_Init(GPIOB, &GPIO_InitStructure);	  //��ʼ��GPIO
 	GPIO_SetBits(GPIOB,GPIO_Pin_0);	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;	 
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//�ٶ�50MHz
 	GPIO_Init(GPIOA, &GPIO_InitStructure);	  //��ʼ��GPIO
 	GPIO_SetBits(GPIOA,GPIO_Pin_7);	
//	
//	Mpr121_IRQ_Init();//interrupt set
//	
//  // Section A
//  // This group controls filtering when data is > baseline.
////  Mpr121_Write(MHD_R, 0x01);
////  Mpr121_Write(NHD_R, 0x01);
////  Mpr121_Write(NCL_R, 0x00);
////  Mpr121_Write(FDL_R, 0x00);	
//  // Section A user
//  // This group controls filtering when data is > baseline.
//  Mpr121_Write(MHD_R, 0x01);
//  Mpr121_Write(NHD_R, 0x01);
//  Mpr121_Write(NCL_R, 0x30);
//  Mpr121_Write(FDL_R, 0x00);

//  // Section B
//  // This group controls filtering when data is < baseline.
////  Mpr121_Write(MHD_F, 0x01);
////  Mpr121_Write(NHD_F, 0x01);
////  Mpr121_Write(NCL_F, 0xFF);
////  Mpr121_Write(FDL_F, 0x02);
//  // Section B
//  // This group controls filtering when data is < baseline.
//  Mpr121_Write(MHD_F, 0x03);
//  Mpr121_Write(NHD_F, 0x03);
//  Mpr121_Write(NCL_F, 0x01);
//  Mpr121_Write(FDL_F, 0x00);
//  
//  // Section C
//  // This group sets touch and release thresholds for each electrode
//  Mpr121_Write(ELE0_T, TOU_THRESH);
//  Mpr121_Write(ELE0_R, REL_THRESH);
//  Mpr121_Write(ELE1_T, TOU_THRESH);
//  Mpr121_Write(ELE1_R, REL_THRESH);
//  Mpr121_Write(ELE2_T, TOU_THRESH);
//  Mpr121_Write(ELE2_R, REL_THRESH);
//  Mpr121_Write(ELE3_T, TOU_THRESH);
//  Mpr121_Write(ELE3_R, REL_THRESH);
//  Mpr121_Write(ELE4_T, TOU_THRESH);
//  Mpr121_Write(ELE4_R, REL_THRESH);
//  Mpr121_Write(ELE5_T, TOU_THRESH);
//  Mpr121_Write(ELE5_R, REL_THRESH);
//  Mpr121_Write(ELE6_T, TOU_THRESH);
//  Mpr121_Write(ELE6_R, REL_THRESH);
//  Mpr121_Write(ELE7_T, TOU_THRESH);
//  Mpr121_Write(ELE7_R, REL_THRESH);
//  Mpr121_Write(ELE8_T, TOU_THRESH);
//  Mpr121_Write(ELE8_R, REL_THRESH);
//  Mpr121_Write(ELE9_T, TOU_THRESH);
//  Mpr121_Write(ELE9_R, REL_THRESH);
//  Mpr121_Write(ELE10_T, TOU_THRESH);
//  Mpr121_Write(ELE10_R, REL_THRESH);
//  Mpr121_Write(ELE11_T, TOU_THRESH);
//  Mpr121_Write(ELE11_R, REL_THRESH);
//  
//  // Section D
//  // Set the Filter Configuration
//  // Set ESI2
//  Mpr121_Write(FIL_CFG, 0x04);
//  
//  // Section E
//  // Electrode Configuration
//  // Enable 6 Electrodes and set to run mode
//  // Set ELE_CFG to 0x00 to return to standby mode
//  Mpr121_Write(ELE_CFG, 0x0C);	// Enables all 12 Electrodes
//  //Mpr121_Write(ELE_CFG, 0x06);		// Enable first 6 electrodes
}

////�ⲿ�жϷ������ 
//void EXTI9_5_IRQHandler(void)
//{
//	if(EXTI_GetITStatus(EXTI_Line6) != RESET) 
//	{
//		printf("%d \r\n",Mpr121_Read(0x1E)-Mpr121_Read(0x05) << 8|Mpr121_Read(0x04));
//		
//		key_pressed=0;
//			//printf("���������ҳ���ȥ�ģ�");
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line6);  //����жϱ�־λ  
//}
//unsigned int ttp229_write(void)
//{
//	unsigned char i;
//	unsigned int temp=0;
//	Mpr121_SDA_OUT();
//	Mpr121_IIC_SDA=0;
//	delay_us(100);
//	Mpr121_IIC_SDA=1;
//	delay_us(20);Mpr121_SDA_IN(); 
//	for(i=0;i<16;i++)
//	{
//	  temp>>=1;
//		Mpr121_IIC_SCL=0;
//		if(!Mpr121_READ_SDA)
//			temp|=0x80;
//		Mpr121_IIC_SCL=1;
//	}
//return temp;
//}

unsigned int ttp229_write(void)
{
	unsigned char i;
	unsigned int temp=0;
	Mpr121_SDA_OUT();
	Mpr121_IIC_SCL = 0;
	Mpr121_IIC_SDA = 0;
	delay_us(100);
	Mpr121_IIC_SDA = 1;
	delay_us(20);Mpr121_SDA_IN(); 
	for (i = 0; i < 16; i++)
	{
		Mpr121_IIC_SCL = 1; 
		delay_us(1);
		Mpr121_IIC_SCL = 0; 
		delay_us(1);

		if (Mpr121_READ_SDA)
		{
			temp |= (1 << i);
			return i+1;
			//dat = temp;	
		}
	}
	return temp;
}
