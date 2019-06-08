#ifndef __TIMER_H
#define __TIMER_H
#include "sys.h"
 
void _GPIO_Configuration(void);
void TIM14_PWM_Init(u32 arr,u32 psc);
void TIM4_PWM_2Ch_Init(u32 arr, u16 psc);

#endif
