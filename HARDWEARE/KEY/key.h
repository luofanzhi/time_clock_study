#ifndef _key_h__
#define _key_h__

#include "sys.h"
#define KEY_UP GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_7)
#define KEY_DOWN GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)
#define KEY_MODE GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5)

enum keyvalue{
	KEY_NONE = 0,
	KEY_UP_VALUE,
	KEY_DOWN_VALUE,
	KEY_MODE_VALUE,
};

enum key_mode_value{
	MODE_NONE = 0,
	Dispaly_Time_Mode,
	Dispaly_Clock_Mode,
	Adjust_Hour_Time_Mode,
	Adjust_Mine_Time_Mode,
};

typedef struct{
	u8 MODE;
	u8 KEY_UP_NUM_Hour;
	u8 KEY_DOWN_NUM_Hour;
	
	u8 KEY_UP_NUM_Mine;
	u8 KEY_DOWN_NUM_Mine;
	
	u8 KEY_MODE_NUM;
	
}KEY_Typedef;
extern KEY_Typedef KEY_Struct;
void KEY_GPIO_Init(void);
u8 KEY_Scan(u8 mode);
u8 key_up_adiust(void);
#endif

