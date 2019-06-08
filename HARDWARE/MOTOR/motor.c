#include "motor.h"
#include "pwm.h"
#include "delay.h"

extern u32 period;

/*
* @file    motor.c
* @author  
* @brief   电机初始化 TIM14 F9输出400Hz 占空比50% 的pwm
* @param   
* @retval None
*/
void MOTOR_Init(void)
{ 
    // F9输出  400Hz  50%占空比
    TIM14_PWM_Init(2500-1, 84-1);
	TIM_SetCompare1(TIM14, 1250);
	delay_ms(100);
}

/*
* @file    motor.c
* @author  
* @brief   电机解锁  TIM14 F9输出400Hz 占空比60.8% 的pwm
* @param   
* @retval None
*/
void MOTOR_Start(void)
{
    delay_ms(500); 
    delay_ms(500); 

    // F9输出  400Hz  60.8%占空比  
	TIM_SetCompare1(TIM14, 980);
}


/*
* @file    motor.c
* @author  
* @brief   以20% 占空比输出PWM， 用来停止电机转动
* @param   None
* @retval None
*/
void MOTOR_Stop(void)
{
	TIM_SetCompare1(TIM14, 2000);
}
 
/*
* @file    motor.c
* @author  
* @brief   计算电机转速
* @param   None
* @retval  转速  r/min
*/
u32 MOTOR_Speed(void)
{
	return 60000000/period;
}

