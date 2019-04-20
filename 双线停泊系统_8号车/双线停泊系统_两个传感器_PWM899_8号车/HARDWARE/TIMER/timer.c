#include "timer.h"
#include "led.h"


void TIM2_PWM_Init(u16 arr,u16 psc)
{	
  //PA0的相关设置	
	RCC->APB1ENR	|=1<<0; 	   //TIM2时钟使能
  RCC->APB2ENR |= 1 << 2;  //GPIOA使能
	GPIOA->CRL&=0XFFFFFFF0;	 //PA2清除之前的设置给0
	GPIOA->CRL|=0X0000000B;	 //PA2复用功能输出 
	TIM2->ARR=arr;			     //设定计数器自动重装值 
	TIM2->PSC=psc;			     //预分频器设置

	TIM2->CCMR1|=6<<4;  	   //CH1 PWM1模式		 
	TIM2->CCMR1|=1<<3; 		   //CH1预装载使能	 
 	TIM2->CCER|=1<<0;   	   //OC1 输出使能	
	
  //PA1的相关设置
  
	GPIOA->CRL&=0XFFFFFF1F;	 //PA3清除之前的设置
	GPIOA->CRL|=0X000000B0;	 //PA3复用功能输出 
	TIM2->CCMR1|=6<<12;  	   //CH2 PWM2模式		 
	TIM2->CCMR1|=1<<11; 		 //CH2预装载使能	 
 	TIM2->CCER|=1<<4;   	   //OC2输出使能
	
	
	TIM2->CR1=0x0080;   	  //ARPE使能 
	TIM2->CR1|=0x01;    	  //使能定时器1 
}
