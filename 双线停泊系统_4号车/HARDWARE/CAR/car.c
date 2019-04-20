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
	
	LEFT_PWM_VAL=239;
	RIGHT_PWM_VAL=209;
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
	/*
	LEFT_PWM_VAL=209;
	RIGHT_PWM_VAL=139;
	*/
	LEFT_PWM_VAL=209;
	RIGHT_PWM_VAL=149;
	
	PBout(7) = 1;
	PBout(8) = 0;
	
	PBout(9) = 1;
	PBout(10)= 0;
}
void LEFT_TURN(void)
{

	/*LEFT_PWM_VAL=79;
	RIGHT_PWM_VAL=199;
	*/
	LEFT_PWM_VAL=79;
	RIGHT_PWM_VAL=219;
	
	PBout(7) = 1;
	PBout(8) = 0;
	
	PBout(9) = 1;
	PBout(10)= 0;
}
