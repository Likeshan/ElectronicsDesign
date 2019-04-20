#include "wave.h"
#include "sys.h"
#include "delay.h"
#include "usart.h"
volatile unsigned int wave_flag = 0;
//
void wave_init(void)
{
	TIM3_Int_Init(5000,350);//��ʱ��3��ʼ��
	
	RCC->APB2ENR|=1<<3;    //ʹ��PORTBʱ��	   	    	 
	GPIOB->CRL&=0XFF0FFFFF; 
	GPIOB->CRL|=0X00300000;//PB5 �������   	 
  GPIOB->ODR&=~(1<<5);      //PB5 �����
											  
	GPIOB->CRL&=0XF0FFFFFF;
	GPIOB->CRL|=0X04000000;//PB6�������� 
	
}
void open_wave(void)
{
	GPIOB->ODR|=(1<<5);      //PB5 �����
	delay_us(20);
	GPIOB->ODR&=~(1<<5);      //PB5 �����
}
void close_wave(void)
{
	TIM3->CR1&=~(1<<0);    //�رն�ʱ��3
	wave_flag =0;
	TIM3->CNT = 0;
}	

unsigned int get_wave_val(void)
{
	unsigned int val = 0;
	open_wave();
	while(PBin(6)==0);
	TIM3->CR1|=0x01;    //ʹ�ܶ�ʱ��3
	
	while(PBin(6)==1);
	//val = flag *0.5 + TIM3->CNT*0.1;
	val = TIM3->CNT;
	//delay_ms(100);
	//val = (flag*0.5+ TIM3->CNT/2/5000)*340;
	close_wave();
	return val;
}
unsigned int get_val(void)
{
	int i;
	int sum = 0;
	for(i=0;i<1;i++)
	{
		sum +=get_wave_val();
	}
	//printf("val:%u \r\n",sum/16);
	return sum;
}


void TIM3_IRQHandler(void)
{ 		    		  			    
	if(TIM3->SR&0X0001)//����ж�
	{
		wave_flag++;   
		//printf("int\r\n");
	}				   
	TIM3->SR&=~(1<<0);//����жϱ�־λ 	    
}
//ͨ�ö�ʱ���жϳ�ʼ��
//����ʱ��ѡ��ΪAPB1��2������APB1Ϊ36M
//arr���Զ���װֵ��
//psc��ʱ��Ԥ��Ƶ��
//����ʹ�õ��Ƕ�ʱ��3!
void TIM3_Int_Init(u16 arr,u16 psc)
{
	RCC->APB1ENR|=1<<1;	//TIM3ʱ��ʹ��    
 	TIM3->ARR=arr;  	//�趨�������Զ���װֵ 
	TIM3->PSC=psc;  	//Ԥ��Ƶ������
	//TIM3->DIER|=1<<0;   //��������ж�		
	TIM3->DIER&=~(1<<0);   //��ֹ�����ж�
	
  //MY_NVIC_Init(2,3,TIM3_IRQn,2);//��ռ1�������ȼ�3����2									 
}
