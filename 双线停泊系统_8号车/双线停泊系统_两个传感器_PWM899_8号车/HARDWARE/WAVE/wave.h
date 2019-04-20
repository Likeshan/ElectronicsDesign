#ifndef __WAVE_H
#define __WAVE_H
#include "sys.h"
void wave_init(void);
void open_wave(void);
void close_wave(void);
unsigned int get_wave_val(void);
unsigned int get_val(void);
void TIM3_Int_Init(u16 arr,u16 psc);
#endif

