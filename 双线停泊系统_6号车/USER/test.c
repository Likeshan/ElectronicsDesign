#include "sys.h"
#include "usart.h"		
#include "delay.h"	
#include "led.h" 
#include "key.h"
#include "exti.h"
#include "car.h"
#include "timer.h"
#include "infrared.h"
int flag = 0;
int main(void)
{	
	Stm32_Clock_Init(9); 
	delay_init(72);	     	
	uart_init(72,9600);
	LED_Init();	
	TIM2_PWM_Init(899,0);

	CAR_INIT();
	/*
	while(1)
	{
	if 按键1 按下  快速
	{
		LEFT_PWM_VAL=899;
		RIGHT_PWM_VAL=899;
		sig = 1;
	}
	if 按键2 按下  慢速
	{
		LEFT_PWM_VAL=500;
		RIGHT_PWM_VAL=500;
	  sig  =2;
	}
}
	*/
//	LEFT_PWM_VAL=459;
//	RIGHT_PWM_VAL=409;
	CAR_FORWARD();
	delay_ms(300);
	EXTI_Init();
	while(1)
	{
		delay_ms(10);
		ReadRedOut();
		//ReadRedOut(sig);
	
	}
}
