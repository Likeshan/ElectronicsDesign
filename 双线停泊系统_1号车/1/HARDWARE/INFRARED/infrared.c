#include "infrared.h"
#include "sys.h"
#include "car.h"
#include "delay.h"
void INFRA_RED_Init(void)
{
	//PB11 12 13
	GPIOB->CRH &= 0XFFFF0FFF; //PB11 ��������,�󴫸���
	GPIOB->CRH |= 0X00004000;
	
	GPIOB->CRH &= 0XFFF0FFFF; //PB12 ��������,�д�����
	GPIOB->CRH |= 0X00040000;

}
//���� sig
void ReadRedOut(int sig)
{
	if(PBin(11) == 1 )
	{
		RIGHT_TURN(sig);
		delay_ms(350);
		LEFT_TURN(sig);
	}
	else if(PBin(11) == 0 )
	{
		LEFT_TURN(sig);
	}

	
}
