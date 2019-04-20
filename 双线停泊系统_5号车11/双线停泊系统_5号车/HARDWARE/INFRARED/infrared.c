#include "infrared.h"
#include "sys.h"
#include "car.h"
#include "delay.h"
void INFRA_RED_Init(void)
{
	//PB11 12 13
	GPIOB->CRH &= 0XFFFF0FFF; //PB11 浮空输入,左传感器
	GPIOB->CRH |= 0X00004000;
	
	GPIOB->CRH &= 0XFFF0FFFF; //PB12 浮空输入,中传感器
	GPIOB->CRH |= 0X00040000;

}
//参数 sig
void ReadRedOut()
{
	if(PBin(11) == 1 )
	{
		RIGHT_TURN();
		delay_ms(80);
		LEFT_TURN();
	}
	else if(PBin(11) == 0 )
	{
		LEFT_TURN();
	}

	
}
