#ifndef __MPR121_H
#define __MPR121_H
#include "sys.h"
#include "include.h"


#define MPR121_R 0xB5	// ADD pin is grounded
#define MPR121_W 0xB4	// So address is 0x5A

// MPR121 Register Defines
#define MHD_R	0x2B
#define NHD_R	0x2C
#define	NCL_R 0x2D
#define	FDL_R	0x2E
#define	MHD_F	0x2F
#define	NHD_F	0x30
#define	NCL_F	0x31
#define	FDL_F	0x32
#define	ELE0_T	0x41
#define	ELE0_R	0x42
#define	ELE1_T	0x43
#define	ELE1_R	0x44
#define	ELE2_T	0x45
#define	ELE2_R	0x46
#define	ELE3_T	0x47
#define	ELE3_R	0x48
#define	ELE4_T	0x49
#define	ELE4_R	0x4A
#define	ELE5_T	0x4B
#define	ELE5_R	0x4C
#define	ELE6_T	0x4D
#define	ELE6_R	0x4E
#define	ELE7_T	0x4F
#define	ELE7_R	0x50
#define	ELE8_T	0x51
#define	ELE8_R	0x52
#define	ELE9_T	0x53
#define	ELE9_R	0x54
#define	ELE10_T	0x55
#define	ELE10_R	0x56
#define	ELE11_T	0x57
#define	ELE11_R	0x58
#define	FIL_CFG	0x5D
#define	ELE_CFG	0x5E
#define GPIO_CTRL0	0x73
#define	GPIO_CTRL1	0x74
#define GPIO_DATA	0x75
#define	GPIO_DIR	0x76
#define	GPIO_EN		0x77
#define	GPIO_SET	0x78
#define	GPIO_CLEAR	0x79
#define	GPIO_TOGGLE	0x7A
#define	ATO_CFG0	0x7B
#define	ATO_CFGU	0x7D
#define	ATO_CFGL	0x7E
#define	ATO_CFGT	0x7F


// Match key inputs with electrode numbers
#define STAR 0
#define SEVEN 1
#define FOUR 2
#define ONE 3
#define ZERO 4
#define EIGHT 5
#define FIVE 6
#define TWO 7
#define POUND 8
#define NINE 9
#define SIX 10
#define THREE 11

// Global Constants
//#define TOU_THRESH	0x0F
//#define	REL_THRESH	0x0A
// Global Constants user
#define TOU_THRESH	0x5A
#define	REL_THRESH	0x0A

//IO方向设置
#define Mpr121_SDA_IN()  {GPIOB->CRL&=0XFFFFFFF0;GPIOB->CRL|=(u32)8;}
#define Mpr121_SDA_OUT() {GPIOB->CRL&=0XFFFFFFF0;GPIOB->CRL|=(u32)3;}
//IO操作函数	 
#define Mpr121_IIC_SCL    PAout(7) //SCL
#define Mpr121_IIC_SDA    PBout(0) //SDA	 
#define Mpr121_READ_SDA   PBin(0)  //输入SDA 

#define Mpr121_IRQ   PAin(6)  //中断脚

//IIC所有操作函数
void Mpr121_Init(void);                     //Mpr121初始化			 
void Mpr121_IIC_Start(void);								//发送IIC开始信号
void Mpr121_IIC_Stop(void);	  							//发送IIC停止信号
void Mpr121_IIC_Send_Byte(u8 txd);					//IIC发送一个字节
u8 Mpr121_IIC_Read_Byte(unsigned char ack); //IIC读取一个字节
u8 Mpr121_IIC_Wait_Ack(void); 			      	//IIC等待ACK信号
void Mpr121_IIC_Ack(void);					        //IIC发送ACK信号
void Mpr121_IIC_NAck(void);				   		    //IIC不发送ACK信号  

void Mpr121_Write(unsigned char address, unsigned char data);
unsigned char Mpr121_Read(uint8_t address);

//中断初始函数
void Mpr121_IRQ_Init(void);
unsigned int ttp229_write(void);
#endif
