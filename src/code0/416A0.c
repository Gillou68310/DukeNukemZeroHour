#include "common.h"
#include "code0/code0.h"

/*.comm*/
/*800FE9F0*/ char D_800FE9F0[10][16] ALIGNED(8);
/*80168CA8*/ OSTime D_80168CA8[10];
/*80169528*/ OSTime D_80169528[10];
/*801AE928*/ OSTime D_801AE928[10];

/*.text*/

/*80040AA0*/
void func_80040AA0(s32 arg0, char *arg1)
{
    D_80168CA8[arg0] = 0;
    D_801AE928[arg0] = 0;
    D_80169528[arg0] = 0;
    sprintf(D_800FE9F0[arg0], "%s", arg1);
}

/*80040B2C*/
void func_80040B2C(s32 arg0)
{
    D_80169528[arg0] = osGetTime();
}

/*80040B70*/
void func_80040B70(s32 arg0)
{
    D_801AE928[arg0] = osGetTime();
    D_80168CA8[arg0] += (D_801AE928[arg0] - D_80169528[arg0]);
}

/*80040C08*/
f32 func_80040C08(s32 arg0)
{
    return ((f32)D_80168CA8[arg0] / (f32)D_80138688) * 240.0;
}
