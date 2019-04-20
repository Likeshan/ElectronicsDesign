#include "wave.h"
#include "sys.h"
#include "delay.h"
#include "usart.h"
volatile unsigned int wave_flag = 0;
//
void wave_init(void)
{
	TIM3_Int_Init(5000,350);//定时器3初始化
	
	RCC->APB2ENR|=1<<3;    //使能PORTB时钟	   	    	 
	GPIOB->CRL&=0XFF0FFFFF; 
	GPIOB->CRL|=0X00300000;//PB5 推挽输出   	 
  GPIOB->ODR&=~(1<<5);      //PB5 输出低
											  
	GPIOB->CRL&=0XF0FFFFFF;
	GPIOB->CRL|=0X04000000;//PB6浮空输入 
	
}
void open_wave(void)
{
	GPIOB->ODR|=(1<<5);      //PB5 输出高
	delay_us(20);
	GPIOB->ODR&=~(1<<5);      //PB5 输出低
}
void close_wave(void)
{
	TIM3->CR1&=~(1<<0);    //关闭定时器3
	wave_flag =0;
	TIM3->CNT = 0;
}	

unsigned int get_wave_val(void)
{
	unsigned int val = 0;
	open_wave();
	while(PBin(6)==0);
	TIM3->CR1|=0x01;    //使能定时器3
	
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
	if(TIM3->SR&0X0001)//溢出中断
	{
		wave_flag++;   
		//printf("int\r\n");
	}				   
	TIM3->SR&=~(1<<0);//清除中断标志位 	    
}
//通用定时器中断初始化
//这里时钟选择为APB1的2倍，而APB1为36M
//arr：自动重装值。
//psc：时钟预分频数
//这里使用的是定时器3!
void TIM3_Int_Init(u16 arr,u16 psc)
{
	RCC->APB1ENR|=1<<1;	//TIM3时钟使能    
 	TIM3->ARR=arr;  	//设定计数器自动重装值 
	TIM3->PSC=psc;  	//预分频器设置
	//TIM3->DIER|=1<<0;   //允许更新中断		
	TIM3->DIER&=~(1<<0);   //禁止更新中断
	
  //MY_NVIC_Init(2,3,TIM3_IRQn,2);//抢占1，子优先级3，组2									 
}
