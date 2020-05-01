#include "beep.h"
#include "sys.h"


BEEP_Typedef BEEP_Struct;
void BEEP_GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitStructure.GPIO_Mode =GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Speed =	GPIO_Speed_10MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	GPIO_ResetBits(GPIOA,GPIO_Pin_4);
	
}

/*****蜂鸣器频响函数******/
/*
	* ON_Time：蜂鸣器开启时间
	* OFF_Time：蜂鸣器关断时间
	* cycle_index：循环次数
	* 时间的计量单位是10ms

*/
void BEEP_Switch(uint16_t period,uint16_t ON_Time,uint8_t cycle_index)
{

	BEEP_Struct.Beep_Period = period;
	BEEP_Struct.Beep_ON_Time = ON_Time;
	BEEP_Struct.Cycle_index = cycle_index;
}

