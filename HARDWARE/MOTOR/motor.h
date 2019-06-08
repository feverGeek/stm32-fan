#ifndef __MOTOR_H
#define __MOTOR_H

#include "sys.h"


void MOTOR_Init(void);   // 输出400Hz PWM 占空比50%
void MOTOR_Start(void);  // 以最低转速输出PWM  占空比60.8%
void MOTOR_Stop(void);   // 以20% 占空比输出PWM， 用来停止电机转动
u32 MOTOR_Speed(void);   // 计算电机转速

#endif
