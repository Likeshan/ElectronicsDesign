#include "exti.h"
#include "led.h"
#include "key.h"
#include "delay.h"
#include "usart.h"
#include "car.h"
//外部中断0服务程序
extern int flag;
void EXTI15_10_IRQHandler(void)
{
	if(PBin(12)==1)
	{
		while(1){
		CAR_STOP();
		}
	}
	EXTI->PR = 1<<12;
}
void EXTI_Init(void)
{
	Ex_NVIC_Config(GPIO_B,12,RTIR);
	
	MY_NVIC_Init(2,0,EXTI15_10_IRQn,2);//抢占2，子优先级2，组2

}
