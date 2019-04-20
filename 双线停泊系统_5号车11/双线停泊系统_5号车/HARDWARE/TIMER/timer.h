#ifndef __TIMER_H
#define __TIMER_H
#include "sys.h"
//通过改变TIM1->CCR1的值来改变占空比，从而控制LED0的亮度


#define LEFT_PWM_VAL TIM2->CCR1        //左轮PWM
#define RIGHT_PWM_VAL TIM2->CCR2       //右轮PWM


void TIM2_PWM_Init(u16 arr,u16 psc);   //PWM初始化函数
#endif
