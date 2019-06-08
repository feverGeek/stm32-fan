#ifndef _TIMER_H
#define _TIMER_H
#include "sys.h"


void TIM5_CH1_Cap_Init(u32 arr,u16 psc);   // TIM5输入捕获测周期
void TIM3_Int_Init(u16 arr,u16 psc);
void TIM4_Int_Init(u16 arr,u16 psc);
 
#endif
