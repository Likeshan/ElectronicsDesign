#ifndef __TIMER_H
#define __TIMER_H
#include "sys.h"
//ͨ���ı�TIM1->CCR1��ֵ���ı�ռ�ձȣ��Ӷ�����LED0������


#define LEFT_PWM_VAL TIM2->CCR1        //����PWM
#define RIGHT_PWM_VAL TIM2->CCR2       //����PWM


void TIM2_PWM_Init(u16 arr,u16 psc);   //PWM��ʼ������
#endif
