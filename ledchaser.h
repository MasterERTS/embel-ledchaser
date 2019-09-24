#include <TimerOne.h>
#include "lcdincr.h"

#ifndef LEDCHASER_H
#define LEDCHASER_H

#define LED1       4
#define LED0       3
#define LED3       6
#define P0         8

void setupChaser();
void irqHelper();



#endif /* LEDCHASER_H */
