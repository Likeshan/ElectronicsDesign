#include "key.h"
#include "delay.h"

void KEY_Init(void)
{
	RCC->APB2ENR |= 1<<2;
	RCC->APB2ENR |= 1<<4;   
	JTAG_Set(SWD_ENABLE);

	GPIOA->CRH &= 0X0FFFFFFF; //PA15设为输入
	GPIOA->CRH |= 0X80000000;
	GPIOA->ODR |= 1<<15; 
	GPIOC->CRL &= 0XFF0FFFFF;
	GPIOC->CRL |= 0X00800000;
	GPIOC->ODR |= 1<<5;
}

u8 KEY_Scan(u8 mode)
{

	static u8 key_up=1;
	if(mode)key_up=1;
	if(key_up && (KEY0_GET()==0 || KEY1_GET()==0 ))
	{ 
		delay_ms(10);
		key_up=0;
		if(KEY0_GET()==0){
			return 1;
		}
		else if(KEY1_GET()==0){
			return 2;
		}
		
	}else if(KEY0_GET()==1 && KEY1_GET()==1 ){
		key_up=1;
	}
	return 0;
}
