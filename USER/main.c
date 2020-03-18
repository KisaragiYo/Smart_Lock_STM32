#include "include.h"

#define usart2_baund  57600//串口2波特率，根据指纹模块波特率更改

SysPara AS608Para;//指纹模块AS608参数
u16 ValidN;//模块内有效指纹个数
u8 ensure;
//u8 key_pressed=1;

void Sys_Init(void);
//char getPhoneNumber(void);
int main(void)
{	
	u8 key_num=0;
//	 int a;
	Sys_Init();

	while(1)
	{
		LED0=0;
		delay_ms(50);	 //延时100ms
		LED0=1;
		delay_ms(50);	//延时100ms
//		if(key_pressed==0)//非阻塞方式
//		{
//			printf("%c",getPhoneNumber());
//		}
//			if((a = ttp229_write())!=0)
//		printf("ttp229_write : %ld \r\n",a);
		/**********OLED显示***************/
		OLED_ShowCHinese(18*1-9,4,26);//按
		OLED_ShowCHinese(18*2-9,4,27);//下
		OLED_ShowCHinese(18*3-9,4,28);//手
		OLED_ShowCHinese(18*4-9,4,13);//指	
		OLED_ShowCHinese(18*5-9,4,29);//解	
		OLED_ShowCHinese(18*6-9,4,30);//锁	
		/********************************/	
		if(PS_Sta)	 //检测指纹模块状态，如果有手指按下
		{
			press_FR(0);//刷指纹		
		}		
		if((key_num=KEY_Scan(0))!=0)
		{
			switch(key_num)
			{
				case 1:				
					Relay_on();Beep_on();		
					/**********OLED显示***************/
					OLED_Clear_OP_Area();
					OLED_ShowCHinese(18*1-9,4,24);//一
					OLED_ShowCHinese(18*2,4,31);//键
					OLED_ShowCHinese(18*3+9,4,32);//开
					OLED_ShowCHinese(18*5,4,30);//锁	
					/********************************/	
					delay_ms(1000);
					Relay_off();Beep_off();	
					break;
				case 2:Beep_on();delay_ms(500);Beep_off();Add_FR();break;
				case 3:break;
				case 4:break;
			}
		}
	}
 }



 
void Sys_Init(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	delay_init();	    //延时函数初始化	  
	 
	OLED_Init();			//初始化OLED  
	OLED_Clear(); 
	
	OLED_ShowCHinese(18*0,0,0);//北
	OLED_ShowCHinese(18*1,0,1);//理
	OLED_ShowCHinese(18*2,0,2);//珠
	OLED_ShowCHinese(18*3,0,3);//智
	OLED_ShowCHinese(18*4,0,4);//能	
	OLED_ShowCHinese(18*5,0,5);//门	
	OLED_ShowCHinese(18*6,0,6);//锁	
	
	OLED_ShowCHinese(18*0,2,7);//初
	OLED_ShowCHinese(18*1,2,8);//始
	OLED_ShowCHinese(18*2,2,9);//化
	OLED_ShowCHinese(18*3,2,10);//中
	OLED_ShowString(18*4,2,"...",16);
	
	delay_ms(10000);	
	Beep_Init();                   //初始化蜂鸣器 	 
	Relay_Init();                  //初始化继电器 	 
	LED_Init();		                 //初始化LED
	uart_init(9600);	           //串口1初始化为9600
	usart2_init(usart2_baund);     //初始化串口2,用于与指纹模块通讯
	KEY_Init();                    //初始化按键
	Mpr121_Init();                 //初始化键盘
	PS_StaGPIO_Init();	           //初始化FR读状态引脚
	while(PS_HandShake(&AS608Addr))//与AS608模块握手
	{
		delay_ms(400);
		printf("未检测到模块!!!");
		delay_ms(800);
		printf("尝试连接模块...\r\n");		  
	}
	
	printf("\r\n------------------------读库指纹个数----------------------\r\n");
	ensure=PS_ValidTempleteNum(&ValidN);//读库指纹个数
	if(ensure!=0x00)
		printf(EnsureMessage(ensure));
	
	printf("\r\n------------------------读参数----------------------------");
	ensure=PS_ReadSysPara(&AS608Para);  //读参数 
	
	if(ensure==0x00)
	printf("\r\n---------------------------------------------------------\r\n");
	else
		printf(EnsureMessage(ensure));
	
	OLED_Clear_OP_Area();
	OLED_ShowCHinese(18*0,2,7);//初
	OLED_ShowCHinese(18*1,2,8);//始
	OLED_ShowCHinese(18*2,2,9);//化
	OLED_ShowCHinese(18*3,2,11);//完
	OLED_ShowCHinese(18*4,2,12);//成	
	delay_ms(800);
	OLED_Clear_OP_Area();
}

//char getPhoneNumber(void)
//{
//  int touchNumber;
//	int j;
//  uint16_t touchstatus;
//	char key=-1;

//	if(key_pressed==0)//非阻塞方式
//	{
//		key_pressed=1;
//    touchNumber = 0;
//    
//	  touchstatus = Mpr121_Read(0x01) << 8;
//    touchstatus |= Mpr121_Read(0x00);
//    
//    for (j=0; j<12; j++)  // Check how many electrodes were pressed
//    {
//      if ((touchstatus & (1<<j)))
//        touchNumber++;
//    }
//    printf("touchNumber:%d touchstatus:%d",touchNumber,touchstatus);
//    if (touchNumber == 1)
//    {
//      if (touchstatus & (1<<STAR))
//        key = '*';
//      else if (touchstatus & (1<<SEVEN))
//        key = '7';
//      else if (touchstatus & (1<<FOUR))
//        key= '4';
//      else if (touchstatus & (1<<ONE))
//        key = '1';
//      else if (touchstatus & (1<<ZERO))
//        key= '0';
//      else if (touchstatus & (1<<EIGHT))
//        key = '8';
//      else if (touchstatus & (1<<FIVE))
//        key = '5';
//      else if (touchstatus & (1<<TWO))
//        key = '2';
//      else if (touchstatus & (1<<POUND))
//        key = '#';
//      else if (touchstatus & (1<<NINE))
//        key = '9';
//      else if (touchstatus & (1<<SIX))
//        key = '6';
//      else if (touchstatus & (1<<THREE))
//        key = '3';
//        
//      //Serial.print(key[i]);
//      
//    }
//    else if (touchNumber == 0);
//    else;
//      //Serial.println("Only touch ONE button!");
//	}
//		return key;
//}

