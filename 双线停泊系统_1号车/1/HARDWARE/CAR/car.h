#ifndef __CAR_H
#define __CAR_H
#include "sys.h"
void CAR_INIT(void);

void CAR_FORWARD(void);
void CAR_REVERSE(void);
void CAR_STOP(void);
void RIGHT_TURN(int sig);
void LEFT_TURN(int sig);
#endif
