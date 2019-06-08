#include "rtc.h"
#include "led.h"
#include "delay.h"
#include "usart.h" 
#include "beep.h"
 

NVIC_InitTypeDef   NVIC_InitStructure;

//RTC时间设置
//hour,min,sec:小时,分钟,秒钟
//ampm:@RTC_AM_PM_Definitions  :RTC_H12_AM/RTC_H12_PM
//返回值:SUCEE(1),成功
//       ERROR(0),进入初始化模式失败 
ErrorStatus RTC_Set_Time(u8 hour,u8 min,u8 sec,u8 ampm)
{
	RTC_TimeTypeDef RTC_TimeTypeInitStructure;
	
	RTC_TimeTypeInitStructure.RTC_Hours=hour;
	RTC_TimeTypeInitStructure.RTC_Minutes=min;
	RTC_TimeTypeInitStructure.RTC_Seconds=sec;
	RTC_TimeTypeInitStructure.RTC_H12=ampm;
	
	return RTC_SetTime(RTC_Format_BIN,&RTC_TimeTypeInitStructure);
	
}
//RTC日期设置
//year,month,date:年(0~99),月(1~12),日(0~31)
//week:星期(1~7,0,非法!)
//返回值:SUCEE(1),成功
//       ERROR(0),进入初始化模式失败 
ErrorStatus RTC_Set_Date(u8 year,u8 month,u8 date,u8 week)
{
	RTC_DateTypeDef RTC_DateTypeInitStructure;
	RTC_DateTypeInitStructure.RTC_Date=date;
	RTC_DateTypeInitStructure.RTC_Month=month;
	RTC_DateTypeInitStructure.RTC_WeekDay=week;
	RTC_DateTypeInitStructure.RTC_Year=year;
	return RTC_SetDate(RTC_Format_BIN,&RTC_DateTypeInitStructure);
}

//RTC初始化
//返回值:0,初始化成功;
//       1,LSE开启失败;
//       2,进入初始化模式失败;
u8 My_RTC_Init(void)
{
	RTC_InitTypeDef RTC_InitStructure;
	u16 retry=0X1FFF; 
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);//使能PWR时钟
	PWR_BackupAccessCmd(ENABLE);	// 允许访问RTC
	
	if(RTC_ReadBackupRegister(RTC_BKP_DR0)!=0x5050)		//是否第一次配置?
	{
		RCC_LSEConfig(RCC_LSE_ON); // 使能外部低速晶振振荡器    
		while (RCC_GetFlagStatus(RCC_FLAG_LSERDY) == RESET)	// 等待外部晶振振荡器准备好
		{
			retry++;
			delay_ms(10);
		}
		if(retry==0)return 1;		//LSE 开启失败. 

		RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);		// 选择LSE作为RTC时钟    
		RCC_RTCCLKCmd(ENABLE);	//使能RTC时钟 
		RTC_WaitForSynchro(); // 等待所有的RTC寄存器就绪 

		RTC_InitStructure.RTC_AsynchPrediv = 0x7F;//RTC异步分频系数(1~0X7F)
		RTC_InitStructure.RTC_SynchPrediv  = 0xFF;//RTC同步分频系数(0~7FFF)
		RTC_InitStructure.RTC_HourFormat   = RTC_HourFormat_24;//RTC设置为,24小时格式
		RTC_Init(&RTC_InitStructure);

		RTC_Set_Date(19, 6, 1, 6);	//设置日期

		RTC_WriteBackupRegister(RTC_BKP_DR0,0x5050);	//标记已经初始化过了
	} 
 
	return 0;
}

/*
* @file    rtc.c
* @author  
* @brief   配置rtc
*          设置时间为24小时格式    初始化时间为 
* @param   
* @retval None
*/
void rtc_init(void)
{
	RTC_InitTypeDef    my_RTC_InitStructure;
	RTC_DateTypeDef    my_RTC_DateStructure;
	RTC_TimeTypeDef    my_RTC_TimeStructure;
	EXTI_InitTypeDef   EXTI_InitStructure;

	/* Enable the PWR clock ，使能电源时钟*/
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);
	
	/* Allow access to RTC，允许访问RTC */
	PWR_BackupAccessCmd(ENABLE);
	
	/* Enable the LSE OSC ，使能外部低速晶振振荡器*/
	RCC_LSEConfig(RCC_LSE_ON);
	
	/* Wait till LSE is ready ，等待外部晶振振荡器准备好*/  
	while(RCC_GetFlagStatus(RCC_FLAG_LSERDY) == RESET);

	/* Select the RTC Clock Source ,选择外部晶振作为RTC的时钟源*/
	RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);
	
	/* Enable the RTC Clock，使能RTC的时钟 */
	RCC_RTCCLKCmd(ENABLE);
	
	/* Wait for RTC APB registers synchronisation，等待所有的RTC寄存器就绪 */
	RTC_WaitForSynchro();
	
	if (RTC_ReadBackupRegister(RTC_BKP_DR0) != 0x4567)
	{
		/* Configure the RTC data register and RTC prescaler */
		
		/* ck_spre(1Hz) = RTCCLK(LSE) /(uwAsynchPrediv + 1)/(uwSynchPrediv + 1)=32768/(127+1)/(255+1)=1Hz
		
			因为RTC都是以秒作为最小的时间单位
		*/
		my_RTC_InitStructure.RTC_AsynchPrediv = 0x7F;
		my_RTC_InitStructure.RTC_SynchPrediv = 0xFF;
		my_RTC_InitStructure.RTC_HourFormat = RTC_HourFormat_24;	//24小时格式
		RTC_Init(&my_RTC_InitStructure);

		/* Set the date: 2019/06/2 星期七 */
		my_RTC_DateStructure.RTC_Year = 18;
		my_RTC_DateStructure.RTC_Month = RTC_Month_June;
		my_RTC_DateStructure.RTC_Date = 25;
		my_RTC_DateStructure.RTC_WeekDay = RTC_Weekday_Sunday;
		RTC_SetDate(RTC_Format_BCD, &my_RTC_DateStructure);
		
		/* Set the time to 早上12:50:15*/
		my_RTC_TimeStructure.RTC_H12     = RTC_H12_AM;
		my_RTC_TimeStructure.RTC_Hours   = 12;
		my_RTC_TimeStructure.RTC_Minutes = 50;
		my_RTC_TimeStructure.RTC_Seconds = 33; 
		
		RTC_SetTime(RTC_Format_BCD, &my_RTC_TimeStructure);  
	
	}
	//关闭唤醒功能
	RTC_WakeUpCmd(DISABLE);
	
	//为唤醒功能选择RTC配置好的时钟源
	RTC_WakeUpClockConfig(RTC_WakeUpClock_CK_SPRE_16bits);
	
	//设置唤醒计数值为自动重载，写入值默认是0，1->0
	RTC_SetWakeUpCounter(0);
	
	//清除RTC唤醒中断标志
	RTC_ClearITPendingBit(RTC_IT_WUT);
	
	//使能RTC唤醒中断
	RTC_ITConfig(RTC_IT_WUT, ENABLE);

	//关闭唤醒功能
	RTC_WakeUpCmd(DISABLE);	
	
	/* 配置外部中断控制线22，实现RTC唤醒*/
	EXTI_ClearITPendingBit(EXTI_Line22);
	EXTI_InitStructure.EXTI_Line = EXTI_Line22;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	/* 使能RTC唤醒中断 */
	NVIC_InitStructure.NVIC_IRQChannel = RTC_WKUP_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	/* Indicator for the RTC configuration，写备份寄存器，用于建立判断标志是否要重置RTC的日期与时间 */
	RTC_WriteBackupRegister(RTC_BKP_DR0, 0x4567);
}

//设置闹钟时间(按星期闹铃,24小时制)
//week:星期几(1~7) @ref  RTC_Alarm_Definitions
//hour,min,sec:小时,分钟,秒钟
//ampm:RTC_H12_AM / RTC_H12_PM
void RTC_Set_AlarmA(u8 week,u8 hour,u8 min,u8 sec, u8 ampm)
{ 
	EXTI_InitTypeDef   EXTI_InitStructure;
	RTC_AlarmTypeDef RTC_AlarmTypeInitStructure;
	RTC_TimeTypeDef RTC_TimeTypeInitStructure;
	
	RTC_AlarmCmd(RTC_Alarm_A, DISABLE); // 关闭闹钟A 
	
	RTC_TimeTypeInitStructure.RTC_Hours   = hour;  // 小时
	RTC_TimeTypeInitStructure.RTC_Minutes = min;   // 分钟
	RTC_TimeTypeInitStructure.RTC_Seconds = sec;   // 秒
	RTC_TimeTypeInitStructure.RTC_H12 = ampm;
  
	RTC_AlarmTypeInitStructure.RTC_AlarmDateWeekDay = week; // 星期
	RTC_AlarmTypeInitStructure.RTC_AlarmDateWeekDaySel = RTC_AlarmDateWeekDaySel_WeekDay; // 按星期闹
	RTC_AlarmTypeInitStructure.RTC_AlarmMask = RTC_AlarmMask_None; // 精确匹配星期，时分秒
	RTC_AlarmTypeInitStructure.RTC_AlarmTime = RTC_TimeTypeInitStructure;
	RTC_SetAlarm(RTC_Format_BIN, RTC_Alarm_A, &RTC_AlarmTypeInitStructure);
 
	RTC_ClearITPendingBit(RTC_IT_ALRA);  // 清除RTC闹钟A的标志
	EXTI_ClearITPendingBit(EXTI_Line17); // 清除LINE17上的中断标志位 
	
	RTC_ITConfig(RTC_IT_ALRA, ENABLE); // 开启闹钟A中断
	RTC_AlarmCmd(RTC_Alarm_A, ENABLE); // 开启闹钟A 
	
	EXTI_InitStructure.EXTI_Line = EXTI_Line17;             // LINE17
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;     // 中断事件
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;  // 上升沿触发 
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;               // 使能LINE17
	EXTI_Init(&EXTI_InitStructure);                         // 配置

	NVIC_InitStructure.NVIC_IRQChannel = RTC_Alarm_IRQn; 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02; // 抢占优先级1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;        // 子优先级2
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;              // 使能外部中断通道
	NVIC_Init(&NVIC_InitStructure);                              // 配置
}

//周期性唤醒定时器设置  
/*wksel:  @ref RTC_Wakeup_Timer_Definitions
#define RTC_WakeUpClock_RTCCLK_Div16        ((uint32_t)0x00000000)
#define RTC_WakeUpClock_RTCCLK_Div8         ((uint32_t)0x00000001)
#define RTC_WakeUpClock_RTCCLK_Div4         ((uint32_t)0x00000002)
#define RTC_WakeUpClock_RTCCLK_Div2         ((uint32_t)0x00000003)
#define RTC_WakeUpClock_CK_SPRE_16bits      ((uint32_t)0x00000004)
#define RTC_WakeUpClock_CK_SPRE_17bits      ((uint32_t)0x00000006)
*/
//cnt:自动重装载值.减到0,产生中断.
void RTC_Set_WakeUp(u32 wksel,u16 cnt)
{ 
	EXTI_InitTypeDef   EXTI_InitStructure;

	RTC_WakeUpCmd(DISABLE);//关闭WAKE UP

	RTC_WakeUpClockConfig(wksel);//唤醒时钟选择

	RTC_SetWakeUpCounter(cnt);//设置WAKE UP自动重装载寄存器


	RTC_ClearITPendingBit(RTC_IT_WUT); //清除RTC WAKE UP的标志
	EXTI_ClearITPendingBit(EXTI_Line22);//清除LINE22上的中断标志位 
	 
	RTC_ITConfig(RTC_IT_WUT,ENABLE);//开启WAKE UP 定时器中断
	RTC_WakeUpCmd( ENABLE);//开启WAKE UP 定时器　

	EXTI_InitStructure.EXTI_Line = EXTI_Line22;//LINE22
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;//中断事件
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising; //上升沿触发 
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;//使能LINE22
	EXTI_Init(&EXTI_InitStructure);//配置

	NVIC_InitStructure.NVIC_IRQChannel = RTC_WKUP_IRQn; 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;//抢占优先级1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;//子优先级2
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//使能外部中断通道
	NVIC_Init(&NVIC_InitStructure);//配置
}

//RTC闹钟中断服务函数
void RTC_Alarm_IRQHandler(void)
{    
	if(RTC_GetFlagStatus(RTC_FLAG_ALRAF)==SET)//ALARM A中断
	{
		RTC_ClearFlag(RTC_FLAG_ALRAF);//清除中断标志
		 
		
	}   
	EXTI_ClearITPendingBit(EXTI_Line17);	//清除中断线17的中断标志 											 
}

//RTC WAKE UP中断服务函数
void RTC_WKUP_IRQHandler(void)
{    
	if(RTC_GetFlagStatus(RTC_FLAG_WUTF)==SET)//WK_UP中断?
	{ 
		RTC_ClearFlag(RTC_FLAG_WUTF);	//清除中断标志
		LED1=!LED1; 
	}   
	EXTI_ClearITPendingBit(EXTI_Line22);//清除中断线22的中断标志 								
}
 


