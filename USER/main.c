#include "stm32f10x.h"
#include "beep.h"
#include "time.h"
#include "rtc.h"
#include "wakeup.h"
#include "power_adc.h"
#include "key.h"
#include "timer.h"

unsigned char table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
 int main(void)
 {	
//	u8 t=0;
//	u16 POWER_ADC_Value;
	SystemInit();						//ϵͳʱ�ӳ�ʼ��,��ʱ��48M
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //�ж����ȼ�����
	delay_init();
	BEEP_GPIO_Init();
	GPIO_595_Init();
	RTC_Init();	  			//RTC��ʼ��
	//WKUP_Init(); 			//�������ѳ�ʼ��
	Adc_Init();		  		//ADC��ʼ��
	TIM3_Int_Init(99,4799);//10Khz�ļ���Ƶ�ʣ�������100Ϊ10ms  
	//RTC_Set(2020,4,13,13,34,2);
	 
	BEEP_Switch(20,15,10);
  while(1)
	{
		key_up_adiust();
	switch(KEY_Struct.KEY_MODE_NUM)
	{
		case MODE_NONE:				Send_Time_Data_To_595(0x00,0xff);
									Send_Time_Data_To_595(0x01,table[calendar.hour/10]);
									Send_Time_Data_To_595(0x00,0xff);
									Send_Time_Data_To_595(0x02,table[calendar.hour%10]);
									Send_Time_Data_To_595(0x00,0xff);
									Send_Time_Data_To_595(0x04,0xbf);
									Send_Time_Data_To_595(0x00,0xff);
									Send_Time_Data_To_595(0x08,table[calendar.min/10]);
									Send_Time_Data_To_595(0x00,0xff);
									Send_Time_Data_To_595(0x10,table[calendar.min%10]);
									Send_Time_Data_To_595(0x00,0xff);
									Send_Time_Data_To_595(0x20,0xbf);
									Send_Time_Data_To_595(0x00,0xff);
									Send_Time_Data_To_595(0x40,table[calendar.sec /10]);
									Send_Time_Data_To_595(0x00,0xff);
									Send_Time_Data_To_595(0x80,table[calendar.sec %10]);
									
			break;
		case Dispaly_Time_Mode:		Send_Time_Data_To_595(0x00,0xff);
									Send_Time_Data_To_595(0x04,0x89);
									Send_Time_Data_To_595(0x00,0xff);
									Send_Time_Data_To_595(0x08,0x86);
									Send_Time_Data_To_595(0x00,0xff);
									Send_Time_Data_To_595(0x10,0xc7);
									Send_Time_Data_To_595(0x00,0xff);
									Send_Time_Data_To_595(0x20,0xc7);
									Send_Time_Data_To_595(0x00,0xff);
									Send_Time_Data_To_595(0x40,0xc0);
			break;
		case Dispaly_Clock_Mode:	
									Send_Time_Data_To_595(0x00,0xff);
									Send_Time_Data_To_595(0x01,table[KEY_Struct.KEY_UP_NUM_Hour/10]);
									Send_Time_Data_To_595(0x00,0xff);
									Send_Time_Data_To_595(0x02,table[KEY_Struct.KEY_UP_NUM_Hour%10]);
									Send_Time_Data_To_595(0x00,0xff);
									Send_Time_Data_To_595(0x04,0xbf);
									Send_Time_Data_To_595(0x00,0xff);
									Send_Time_Data_To_595(0x08,table[KEY_Struct.KEY_UP_NUM_Mine/10]);
									Send_Time_Data_To_595(0x00,0xff);
									Send_Time_Data_To_595(0x10,table[KEY_Struct.KEY_UP_NUM_Mine%10]);
									Send_Time_Data_To_595(0x00,0xff);
									Send_Time_Data_To_595(0x20,0xbf);
									Send_Time_Data_To_595(0x00,0xff);
									Send_Time_Data_To_595(0x40,table[0]);
									Send_Time_Data_To_595(0x00,0xff);									
									Send_Time_Data_To_595(0x80,table[0]);
									
			break;
	}

		if(KEY_Struct.KEY_UP_NUM_Hour == calendar.hour&&KEY_Struct.KEY_UP_NUM_Mine == calendar.min)
		{	
			if(calendar.sec ==0)
			{
				BEEP_Switch(20,10,20);
			}
		}
		if(calendar.sec ==0&&calendar.min==0)
		{
			BEEP_Switch(100,50,1);
		}
		
		
		//POWER_ADC_Value=Get_Adc_Average(ADC_Channel_1,10);
	}
 }
