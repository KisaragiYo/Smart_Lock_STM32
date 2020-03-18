#include "mpr121.h"


////产生IIC起始信号
//void Mpr121_IIC_Start(void)
//{
//	Mpr121_SDA_OUT();     //sda线输出
//	Mpr121_IIC_SDA=1;	  	  
//	Mpr121_IIC_SCL=1;
//	delay_us(4);
// 	Mpr121_IIC_SDA=0;//START:when CLK is high,DATA change form high to low 
//	delay_us(4);
//	Mpr121_IIC_SCL=0;//钳住I2C总线，准备发送或接收数据 
//}	  
////产生IIC停止信号
//void Mpr121_IIC_Stop(void)
//{
//	Mpr121_SDA_OUT();//sda线输出
//	Mpr121_IIC_SCL=0;
//	Mpr121_IIC_SDA=0;//STOP:when CLK is high DATA change form low to high
// 	delay_us(4);
//	Mpr121_IIC_SCL=1; 
//	Mpr121_IIC_SDA=1;//发送I2C总线结束信号
//	delay_us(4);							   	
//}
////等待应答信号到来
////返回值：1，接收应答失败
////        0，接收应答成功
//u8 Mpr121_IIC_Wait_Ack(void)
//{
//	u8 ucErrTime=0;
//	Mpr121_SDA_IN();      //SDA设置为输入  
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
//	Mpr121_IIC_SCL=0;//时钟输出0 	   
//	return 0;  
//} 
////产生ACK应答
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
////不产生ACK应答		    
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
////IIC发送一个字节
////返回从机有无应答
////1，有应答
////0，无应答			  
//void Mpr121_IIC_Send_Byte(u8 txd)
//{                        
//    u8 t;   
//		Mpr121_SDA_OUT(); 	    
//    Mpr121_IIC_SCL=0;//拉低时钟开始数据传输
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
////读1个字节，ack=1时，发送ACK，ack=0，发送nACK   
//u8 Mpr121_IIC_Read_Byte(unsigned char ack)
//{
//	unsigned char i,receive=0;
//	Mpr121_SDA_IN();//SDA设置为输入
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
//        Mpr121_IIC_NAck();//发送nACK
//    else
//        Mpr121_IIC_Ack(); //发送ACK   
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
// 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO,ENABLE);//使能时钟

//	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_6;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
// 	GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA6


//	//GPIOA.6 中断线以及中断初始化配置   下降沿触发
//	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource6);
//	EXTI_InitStructure.EXTI_Line=EXTI_Line6;	
//	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
//	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
//	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
//	EXTI_Init(&EXTI_InitStructure);	 	//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器

//	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			//使能GPIOA.6所在的外部中断通道
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;	//抢占优先级1
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;					//子优先级1
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//使能外部中断通道
//	NVIC_Init(&NVIC_InitStructure); 
//}

//初始化IIC
void Mpr121_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;	 
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//速度50MHz
 	GPIO_Init(GPIOB, &GPIO_InitStructure);	  //初始化GPIO
 	GPIO_SetBits(GPIOB,GPIO_Pin_0);	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;	 
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//速度50MHz
 	GPIO_Init(GPIOA, &GPIO_InitStructure);	  //初始化GPIO
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

////外部中断服务程序 
//void EXTI9_5_IRQHandler(void)
//{
//	if(EXTI_GetITStatus(EXTI_Line6) != RESET) 
//	{
//		printf("%d \r\n",Mpr121_Read(0x1E)-Mpr121_Read(0x05) << 8|Mpr121_Read(0x04));
//		
//		key_pressed=0;
//			//printf("进来啦！我出的去的！");
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line6);  //清除中断标志位  
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
