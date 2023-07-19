#include "common.h"

/*.text*/

/*8002ADB4*/
s32 mulscale(s64 arg0, s64 arg1, s64 arg2)
{
    return (arg0 * arg1) >> arg2;
}

/*8002AE48*/
s32 mulscale12(s64 arg0, s64 arg1)
{
    return (arg0 * arg1) >> 12;
}

/*8002AEAC*/
s32 mulscale14(s64 arg0, s64 arg1)
{
    return (arg0 * arg1) >> 14;
}

/*8002AF10*/
s32 mulscale16(s64 arg0, s64 arg1)
{
    return (arg0 * arg1) >> 16;
}

/*8002AF74*/
s32 mulscale20(s64 arg0, s64 arg1)
{
    return (arg0 * arg1) >> 20;
}

/*8002AFD8*/
s32 mulscale24(s64 arg0, s64 arg1)
{
    return (arg0 * arg1) >> 24;
}

/*8002B03C*/
s32 mulscale30(s64 arg0, s64 arg1)
{
    return (arg0 * arg1) >> 30;
}

/*8002B0A0*/
s32 mulscale32(s64 arg0, s64 arg1)
{
    return (arg0 * arg1) >> 32;
}

/*8002B0FC*/
s32 dmulscale3(s64 arg0, s64 arg1, s64 arg2, s64 arg3)
{
    return (arg0 * arg1 + arg2 * arg3) >> 3;
}

/*8002B1C4*/
s32 dmulscale6(s64 arg0, s64 arg1, s64 arg2, s64 arg3)
{
    return (arg0 * arg1 + arg2 * arg3) >> 6;
}

/*8002B28C*/
s32 dmulscale14(s64 arg0, s64 arg1, s64 arg2, s64 arg3)
{
    return (arg0 * arg1 + arg2 * arg3) >> 14;
}

/*8002B354*/
s32 dmulscale15(s64 arg0, s64 arg1, s64 arg2, s64 arg3)
{
    return (arg0 * arg1 + arg2 * arg3) >> 15;
}

/*8002B41C*/
s32 dmulscale16(s64 arg0, s64 arg1, s64 arg2, s64 arg3)
{
    return (arg0 * arg1 + arg2 * arg3) >> 16;
}

/*8002B4E0*/
s32 divscale15(s64 arg0, s64 arg1)
{
    return (arg0 << 15) / arg1;
}

/*8002B50C*/
s32 divscale16(s64 arg0, s64 arg1)
{
    return (arg0 << 16) / arg1;
}

/*8002B538*/
s32 divscale20(s64 arg0, s64 arg1)
{
    return (arg0 << 20) / arg1;
}

/*8002B564*/
s32 divscale24(s64 arg0, s64 arg1)
{
    return (arg0 << 24) / arg1;
}

/*8002B590*/
s32 divscale30(s64 arg0, s64 arg1)
{
    return (arg0 << 30) / arg1;
}

/*8002B5BC*/
s32 scale(s32 arg0, s32 arg1, s32 arg2)
{
    return arg0 * (s64)arg1 / arg2;
}

/*8002B600*/
s32 nsqrtasm(s32 arg0)
{
    if (arg0 < 0)
        return 1;

    return (s32)sqrtf((f64)arg0);
}

/*8002B660*/
s32 klabs_(s32 arg0)
{
    if (arg0 < 0)
        return -arg0;
    else
        return arg0;
}

/*8002B674*/
s32 ksgn(s32 arg0)
{
    return (arg0 < 0) ? -1 : 1;
}
