#include "time.h"
#include "sys.h"
#include "delay.h"

///*位选GPIO定义*/
//#define		WEI_DATA_IN			PBout(9)		
//#define 	WEI_DATA_OUT_ENABLE()		GPIO_SetBits(GPIOB,GPIO_Pin_10);
//#define 	WEI_DATA_OUT_DISABLE()		GPIO_ResetBits(GPIOB,GPIO_Pin_10);
//#define 	WEI_DATA_MOVE_ENABLE()		GPIO_SetBits(GPIOB,GPIO_Pin_11);
//#define 	WEI_DATA_MOVE_DISABLE()		GPIO_ResetBits(GPIOB,GPIO_Pin_11);

///*段选GPIO定义*/
//#define 	DUAN_DATA_IN		PBout(12)
//#define 	DUAN_DATA_OUT_ENABLE()		GPIO_SetBits(GPIOB,GPIO_Pin_13);
//#define 	DUAN_DATA_OUT_DISABLE()		GPIO_ResetBits(GPIOB,GPIO_Pin_13);
//#define 	DUAN_DATA_MOVE_ENABLE()		GPIO_SetBits(GPIOB,GPIO_Pin_14);
//#define 	DUAN_DATA_MOVE_DISABLE()		GPIO_ResetBits(GPIOB,GPIO_Pin_14);



void GPIO_595_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitStructure.GPIO_Mode =GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Speed =	GPIO_Speed_10MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	GPIO_ResetBits(GPIOB,GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14);
}

void Send_Time_Data_To_595(uint8_t wei_data,uint8_t duan_data)
{
	char i;
	for(i=0;i<8;i++)
	{
		WEI_DATA_IN=wei_data>>7;
		wei_data=wei_data<<1;
		WEI_DATA_MOVE_ENABLE();
		delay_us(1);
		WEI_DATA_MOVE_DISABLE();
		
		DUAN_DATA_IN=duan_data>>7;
		duan_data=duan_data<<1;
		DUAN_DATA_MOVE_ENABLE();
		delay_us(1);
		DUAN_DATA_MOVE_DISABLE();
	}

		WEI_DATA_OUT_ENABLE();
		DUAN_DATA_OUT_ENABLE();
		delay_us(1);
		WEI_DATA_OUT_DISABLE();
		DUAN_DATA_OUT_DISABLE();
		
	
}

