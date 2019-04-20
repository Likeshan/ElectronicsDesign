#include "exti.h"
#include "led.h"
#include "key.h"
#include "delay.h"
#include "usart.h"
#include "car.h"
#include "timer.h"

//外部中断0服务程序
extern int flag;

void EXTI15_10_IRQHandler(void)
{
	//右转PWM
//	LEFT_PWM_VAL=214;
//	RIGHT_PWM_VAL=60;
//	delay_ms(100);
	//flag=1;
	EXTI->PR = 1<<11;

}
void EXTI_Init(void)
{
	Ex_NVIC_Config(GPIO_B,11,RTIR);
	
	MY_NVIC_Init(2,0,EXTI15_10_IRQn,2);//抢占2，子优先级2，组2

}
