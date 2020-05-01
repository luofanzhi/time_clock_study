#ifndef _time_h__
#define _time_h__

#include "sys.h"
/*位选GPIO定义*/
#define		WEI_DATA_IN			PBout(9)		
#define 	WEI_DATA_OUT_ENABLE()		GPIO_SetBits(GPIOB,GPIO_Pin_10);
#define 	WEI_DATA_OUT_DISABLE()		GPIO_ResetBits(GPIOB,GPIO_Pin_10);
#define 	WEI_DATA_MOVE_ENABLE()		GPIO_SetBits(GPIOB,GPIO_Pin_11);
#define 	WEI_DATA_MOVE_DISABLE()		GPIO_ResetBits(GPIOB,GPIO_Pin_11);

/*段选GPIO定义*/
#define 	DUAN_DATA_IN		PBout(12)
#define 	DUAN_DATA_OUT_ENABLE()		GPIO_SetBits(GPIOB,GPIO_Pin_13);
#define 	DUAN_DATA_OUT_DISABLE()		GPIO_ResetBits(GPIOB,GPIO_Pin_13);
#define 	DUAN_DATA_MOVE_ENABLE()		GPIO_SetBits(GPIOB,GPIO_Pin_14);
#define 	DUAN_DATA_MOVE_DISABLE()	GPIO_ResetBits(GPIOB,GPIO_Pin_14);

/*函数声明*/
void GPIO_595_Init(void);
void Send_Time_Data_To_595(uint8_t wei_data,uint8_t duan_data);
#endif

