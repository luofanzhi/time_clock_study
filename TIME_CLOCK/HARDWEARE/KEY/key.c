#include "key.h"
#include "delay.h"
#include "rtc.h"
#include "time.h"


KEY_Typedef KEY_Struct;
void KEY_GPIO_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);        //  led4
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;                    //
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;               //
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;          //
    GPIO_Init(GPIOA,&GPIO_InitStructure); 
}

u8 KEY_Scan(u8 mode)//mode-1-支持连按
{
	static u8 key_up=1;//按键松开标志
	if(mode)key_up=1;//支持连按
	if(key_up&&(KEY_UP==0|KEY_DOWN==0|KEY_MODE==0))
	{
		delay_ms(5);
		key_up=0;
		if(KEY_UP==0)return KEY_UP_VALUE;
		else if(KEY_DOWN==0)return KEY_DOWN_VALUE;
			else if(KEY_MODE==0)return KEY_MODE_VALUE;
	}
	else if(KEY_UP==1&&KEY_DOWN==1&&KEY_MODE==1)key_up=1;
	return 0;//无按键按下
}

u8 key_up_adiust(void)
{
	if(KEY_Scan(0)==KEY_MODE_VALUE)
	{
		KEY_Struct.KEY_MODE_NUM +=1;
		if(KEY_Struct.KEY_MODE_NUM > Dispaly_Clock_Mode)
			KEY_Struct.KEY_MODE_NUM = MODE_NONE;
	}
//	if(KEY_Struct.KEY_MODE_NUM==2)
//	{
//		if(KEY_Scan(0)==KEY_UP_VALUE)
//		{
//			KEY_Struct.KEY_UP_NUM_Hour +=1;
//		}
//		else if(KEY_Scan(0)==KEY_DOWN_VALUE)
//		{
//			KEY_Struct.KEY_UP_NUM_Mine +=1;
//		}
//		if(KEY_Struct.KEY_UP_NUM_Hour==24)KEY_Struct.KEY_UP_NUM_Hour=0;
//		if(KEY_Struct.KEY_UP_NUM_Mine==60)KEY_Struct.KEY_UP_NUM_Mine=0;
//	}
									
									

	return 0;
}
