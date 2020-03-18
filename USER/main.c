#include "include.h"

#define usart2_baund  57600//����2�����ʣ�����ָ��ģ�鲨���ʸ���

SysPara AS608Para;//ָ��ģ��AS608����
u16 ValidN;//ģ������Чָ�Ƹ���
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
		delay_ms(50);	 //��ʱ100ms
		LED0=1;
		delay_ms(50);	//��ʱ100ms
//		if(key_pressed==0)//��������ʽ
//		{
//			printf("%c",getPhoneNumber());
//		}
//			if((a = ttp229_write())!=0)
//		printf("ttp229_write : %ld \r\n",a);
		/**********OLED��ʾ***************/
		OLED_ShowCHinese(18*1-9,4,26);//��
		OLED_ShowCHinese(18*2-9,4,27);//��
		OLED_ShowCHinese(18*3-9,4,28);//��
		OLED_ShowCHinese(18*4-9,4,13);//ָ	
		OLED_ShowCHinese(18*5-9,4,29);//��	
		OLED_ShowCHinese(18*6-9,4,30);//��	
		/********************************/	
		if(PS_Sta)	 //���ָ��ģ��״̬���������ָ����
		{
			press_FR(0);//ˢָ��		
		}		
		if((key_num=KEY_Scan(0))!=0)
		{
			switch(key_num)
			{
				case 1:				
					Relay_on();Beep_on();		
					/**********OLED��ʾ***************/
					OLED_Clear_OP_Area();
					OLED_ShowCHinese(18*1-9,4,24);//һ
					OLED_ShowCHinese(18*2,4,31);//��
					OLED_ShowCHinese(18*3+9,4,32);//��
					OLED_ShowCHinese(18*5,4,30);//��	
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
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	delay_init();	    //��ʱ������ʼ��	  
	 
	OLED_Init();			//��ʼ��OLED  
	OLED_Clear(); 
	
	OLED_ShowCHinese(18*0,0,0);//��
	OLED_ShowCHinese(18*1,0,1);//��
	OLED_ShowCHinese(18*2,0,2);//��
	OLED_ShowCHinese(18*3,0,3);//��
	OLED_ShowCHinese(18*4,0,4);//��	
	OLED_ShowCHinese(18*5,0,5);//��	
	OLED_ShowCHinese(18*6,0,6);//��	
	
	OLED_ShowCHinese(18*0,2,7);//��
	OLED_ShowCHinese(18*1,2,8);//ʼ
	OLED_ShowCHinese(18*2,2,9);//��
	OLED_ShowCHinese(18*3,2,10);//��
	OLED_ShowString(18*4,2,"...",16);
	
	delay_ms(10000);	
	Beep_Init();                   //��ʼ�������� 	 
	Relay_Init();                  //��ʼ���̵��� 	 
	LED_Init();		                 //��ʼ��LED
	uart_init(9600);	           //����1��ʼ��Ϊ9600
	usart2_init(usart2_baund);     //��ʼ������2,������ָ��ģ��ͨѶ
	KEY_Init();                    //��ʼ������
	Mpr121_Init();                 //��ʼ������
	PS_StaGPIO_Init();	           //��ʼ��FR��״̬����
	while(PS_HandShake(&AS608Addr))//��AS608ģ������
	{
		delay_ms(400);
		printf("δ��⵽ģ��!!!");
		delay_ms(800);
		printf("��������ģ��...\r\n");		  
	}
	
	printf("\r\n------------------------����ָ�Ƹ���----------------------\r\n");
	ensure=PS_ValidTempleteNum(&ValidN);//����ָ�Ƹ���
	if(ensure!=0x00)
		printf(EnsureMessage(ensure));
	
	printf("\r\n------------------------������----------------------------");
	ensure=PS_ReadSysPara(&AS608Para);  //������ 
	
	if(ensure==0x00)
	printf("\r\n---------------------------------------------------------\r\n");
	else
		printf(EnsureMessage(ensure));
	
	OLED_Clear_OP_Area();
	OLED_ShowCHinese(18*0,2,7);//��
	OLED_ShowCHinese(18*1,2,8);//ʼ
	OLED_ShowCHinese(18*2,2,9);//��
	OLED_ShowCHinese(18*3,2,11);//��
	OLED_ShowCHinese(18*4,2,12);//��	
	delay_ms(800);
	OLED_Clear_OP_Area();
}

//char getPhoneNumber(void)
//{
//  int touchNumber;
//	int j;
//  uint16_t touchstatus;
//	char key=-1;

//	if(key_pressed==0)//��������ʽ
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

