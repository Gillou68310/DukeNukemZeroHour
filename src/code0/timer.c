#include "common.h"
#include "code0/main.h"
#include "code0/code0.h"

#define MAXTIMER 10

/*.comm*/
/*800FE9F0*/ char _timerName[MAXTIMER][16] ALIGNED(8);
/*80168CA8*/ OSTime _timerDiffTime[MAXTIMER];
/*80169528*/ OSTime _timerStartTime[MAXTIMER];
/*801AE928*/ OSTime _timerStopTime[MAXTIMER];

/*.text*/

/*80040AA0*/
void initTimer(s32 timernum, char *name)
{
    _timerDiffTime[timernum] = 0;
    _timerStopTime[timernum] = 0;
    _timerStartTime[timernum] = 0;
    sprintf(_timerName[timernum], "%s", name);
}

/*80040B2C*/
void startTimer(s32 timernum)
{
    _timerStartTime[timernum] = osGetTime();
}

/*80040B70*/
void stopTimer(s32 timernum)
{
    _timerStopTime[timernum] = osGetTime();
    _timerDiffTime[timernum] += (_timerStopTime[timernum] - _timerStartTime[timernum]);
}

/*80040C08*/
f32 getTimerElapsedTime(s32 timernum)
{
#ifdef MODERN
    /*Force modern gcc to use __floatdisf instead of __floatundisf*/
    return ((f32)(s64)_timerDiffTime[timernum] / (f32)(s64)D_80138688) * (f64)SCREEN_HEIGHT;
#else
    return ((f32)_timerDiffTime[timernum] / (f32)D_80138688) * (f64)SCREEN_HEIGHT;
#endif
}
