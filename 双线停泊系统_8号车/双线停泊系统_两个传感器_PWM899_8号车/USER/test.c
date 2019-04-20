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


int main(void)
{	
	int m;
	int flag = 0;
	Stm32_Clock_Init(9); 
	delay_init(72);	     	
	uart_init(72,9600);
	LED_Init();	
	TIM2_PWM_Init(899,0);

	CAR_INIT();
	//wave_init();
	LEFT_PWM_VAL=229;
	RIGHT_PWM_VAL=209;
	CAR_FORWARD();
	wave_init();
	delay_ms(800);
	//EXTI_Init();
	while(1)
	{
		delay_ms(10);
		ReadRedOut();
		m=get_val();
		if(m>= 300 && m<=310 && flag == 0)
		{
			/*
				×ª¾ÅÊ®¶È
			*/
			flag++;
			LEFT_TURN_BIG();
			delay_ms(500);
		}
		if(m>=175 && m<=185 && flag == 1)
		{
			CAR_STOP();
			while(1);
		}
	}
}
