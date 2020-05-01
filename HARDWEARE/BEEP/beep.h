#ifndef _beep_h__
#define _beep_h__

#include "sys.h"
#include "delay.h"

//#define BEEP PAout(4)
#define 		BEEP_ON() 	GPIO_SetBits(GPIOA,GPIO_Pin_4);
#define 		BEEP_OFF() 	GPIO_ResetBits(GPIOA,GPIO_Pin_4);


typedef struct{
	uint16_t Beep_ON_Time;
	uint16_t Beep_OFF_Time;
	uint16_t Beep_Period;
	uint8_t	 Cycle_index;
	
}BEEP_Typedef;
extern BEEP_Typedef BEEP_Struct;
void BEEP_GPIO_Init(void);
void BEEP_Switch(uint16_t ON_Time,uint16_t OFF_Time,uint8_t cycle_index);


#endif


