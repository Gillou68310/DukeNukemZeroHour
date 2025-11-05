#ifndef _TIMER_H_
#define _TIMER_H_

#include "common.h"

#define MOVE1_TIMER 1
#define MOVE2_TIMER 2
#define DRAW_TIMER 3

void initTimer(s32 timernum, char *name);
void startTimer(s32 timernum);
void stopTimer(s32 timernum);
f32 getTimerElapsedTime(s32 timernum);

#endif
