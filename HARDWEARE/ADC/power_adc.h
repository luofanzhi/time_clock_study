#ifndef _power_adc_h__
#define _power_adc_h__

#include "sys.h"

void Adc_Init(void);
u16  Get_Adc(u8 ch); 
u16 Get_Adc_Average(u8 ch,u8 times); 

#endif

