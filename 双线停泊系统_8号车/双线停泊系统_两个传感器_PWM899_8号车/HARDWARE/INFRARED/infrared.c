#include "infrared.h"
#include "sys.h"
#include "car.h"
#include "delay.h"
void INFRA_RED_Init(void)
{
	//PB11 12 
	GPIOB->CRH &= 0XFFFF0FFF; //PB11 ��������,�󴫸���
	GPIOB->CRH |= 0X00004000;
	
	GPIOB->CRH &= 0XFFF0FFFF; //PB12 ��������,�д�����
	GPIOB->CRH |= 0X00040000;

}
//���� sig
void ReadRedOut()
{
	if(PBin(11) == 0 && PBin(12) == 0)
	{
		CAR_FORWARD();
	}
	else if(PBin(11) == 1 && PBin(12) == 0)
	{
		RIGHT_TURN();
		
	}
	else if(PBin(11) == 0 && PBin(12) == 1)
	{
		LEFT_TURN();
	}
	
	
}
