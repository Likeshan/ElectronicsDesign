#include "car.h"
#include "sys.h"
#include "timer.h"
void CAR_INIT(void)
{	
	RCC->APB2ENR |= 1<<3;//IOPB使能

	GPIOB->CRL &= 0X0FFFFFFF;
	GPIOB->CRL |= 0X30000000;//PB7
	
	GPIOB->CRH &= 0XFFFFFFF0;
	GPIOB->CRH |= 0X00000003;//PB8
	
	GPIOB->CRH &= 0XFFFFFF0F;
	GPIOB->CRH |= 0X00000030;//PB9
	
	GPIOB->CRH &= 0XFFFFF0FF;
	GPIOB->CRH |= 0X00000300;//PB10
	
	GPIOB->CRH &= 0XF0FFFFFF;//TB6612FNG驱动STBY引脚给高电平
	GPIOB->CRH |= 0X03000000; 
	PBout(14) = 1;//TB6612FNG驱动STBY引脚给高电平
}
// PB7 8 左
// PB9 10右
void CAR_FORWARD(void)
{
	
	LEFT_PWM_VAL=200;
	RIGHT_PWM_VAL=200;
	PBout(7) = 1;
	PBout(8) = 0;
	
	PBout(9) = 1;
	PBout(10)= 0;
}



void CAR_STOP(void)
{

	PBout(7) = 1;
	PBout(8) = 1;
	
	PBout(9) = 1;
	PBout(10)= 1;
}


void RIGHT_TURN(void)
{
	/*if(sig = 1)
	{
		LEFT_PWM_VAL=899;
		RIGHT_PWM_VAL=459;
	}
	if(sig = 2)
	{
		LEFT_PWM_VAL=699;
		RIGHT_PWM_VAL=359;
	}
	*/
	
	LEFT_PWM_VAL=230;
	RIGHT_PWM_VAL=105;
	
	/*LEFT_PWM_VAL=629;
	RIGHT_PWM_VAL=389;*/
	PBout(7) = 1;
	PBout(8) = 0;
	
	PBout(9) = 1;
	PBout(10)= 0;
}
void LEFT_TURN(void)
{
	/*if(sig = 1)
	{
		LEFT_PWM_VAL=459;
		RIGHT_PWM_VAL=899;
	}
	if(sig = 2)
	{
		LEFT_PWM_VAL=359;
		RIGHT_PWM_VAL=699;
	}
	*/
	LEFT_PWM_VAL=130;
	RIGHT_PWM_VAL=250;
	
	/*LEFT_PWM_VAL=289;
	RIGHT_PWM_VAL=629;*/
	PBout(7) = 1;
	PBout(8) = 0;
	
	PBout(9) = 1;
	PBout(10)= 0;
}
