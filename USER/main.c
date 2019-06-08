#include "delay.h"
#include "timer.h"
#include "led.h"
#include "ILI93xx.h"
#include "usart.h"
#include "sys.h"
#include "motor.h"
#include "rtc.h"
#include "key.h"
#include "wkup.h"
#include "beep.h"
#include "sram.h"
#include "malloc.h"
#include "touch.h"
#include "GUI.h"
#include "MyGui.h"
#include "WM.h"
#include "ds18b20.h"

 


int main(void)
{ 
	u8 key = 0;
	u8 tbuf[40];
	RTC_TimeTypeDef RTC_TimeStruct;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init(168);       
	uart_init(115200);    	//串口波特率设置
	LED_Init();	
	DS18B20_Init();
	
	LED0 = 0;
 	TFTLCD_Init();  
	LCD_Display_Dir(0);
	TP_Init();
	TP_Adjust();
	
	/* 触摸屏扫描速度,100HZ. */
	TIM4_Int_Init(599,839); 
	
	KEY_Init();
	rtc_init();
	FSMC_SRAM_Init();
	/* 1KHZ 定时器3设置为1ms */
	TIM3_Int_Init(999,83); 	
	/* 初始化内部内存池 */
	mem_init(SRAMIN); 		
	/* 初始化外部内存池 */
	mem_init(SRAMEX);  
	/* 初始化CCM内存池 */
	mem_init(SRAMCCM); 		
	 
	TIM5_CH1_Cap_Init(0XFFFFFFFF,84-1); 
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_CRC,ENABLE);//开启CRC时钟
	MOTOR_Init();
//	MOTOR_Start();
	DS18B20_Init();
	LED0 = 0;
 
	MainTask();
  	while(1);
}
