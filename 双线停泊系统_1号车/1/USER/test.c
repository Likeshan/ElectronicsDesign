#include "sys.h"
#include "usart.h"		
#include "delay.h"	
#include "led.h" 
#include "key.h"
#include "exti.h"
#include "car.h"
#include "timer.h"
#include "infrared.h"
#include "wave.h"
int flag = 0;
int main(void)
{	
	
	int sig = 0;
	Stm32_Clock_Init(9); 
	delay_init(72);	     	
	uart_init(72,9600);
	LED_Init();	
	TIM2_PWM_Init(899,0);

	CAR_INIT();
	
	KEY_Init();
	wave_init();
	while(1)
	{
		if(KEY_Scan(0)==1) //¿ìËÙ
		{
			LEFT_PWM_VAL=899;
			RIGHT_PWM_VAL=899;
			sig = 1;
			break;
		}
		if(KEY_Scan(0)==2) //ÂýËÙ
		{
			LEFT_PWM_VAL=500;
			RIGHT_PWM_VAL=500;
			sig  =2;
			break;
		}
	}

	CAR_FORWARD();
	delay_ms(800);
	EXTI_Init();
	while(1)
	{
		int m;
		//delay_ms(10);
		ReadRedOut(sig);
		m=get_val();
		if(m>=145 && m<=155)
		{
			CAR_STOP();
			while(1);
		}
		//ReadRedOut(sig);
	}
}
