#include "common.h"
#include "code0/cache1d.h"
#include "code0/edl.h"
#include "code0/7F6A0.h"
#include "code0/84490.h"
#include "code0/code0.h"
#include "code1/code1.h"
#include "static/119280.h"

typedef struct {
    /*0x00*/ s32 unk0;
    /*0x04*/ s32 unk4;
    /*0x08*/ s32 unk8;
} _82480UnkStruct1;

/*.comm*/
/*8012FC9C*/ _82480UnkStruct1 *D_8012FC9C;

/*.text*/

/*80081880*/
static f32 _fabs(f32 arg0)
{
    if (!(arg0 >= 0.0f))
        return -arg0;
    else
        return arg0;
}

/*800818A8*/
void func_800818A8(code0UnkStruct16 *arg0, s16 id, s16 off, s32 arg3, s32 arg4, s32 arg5, s32 arg6)
{
    u8 *ptr;
    u8 *ptr2;

    ptr = edl_80081840(id, off);
    arg0->unk70 = ptr;
    arg0->unk74 = arg3;
    arg0->unk78 = arg4;
    arg0->unk7C = arg5;
    arg0->unk80 = arg6;
    arg0->unk88 = swap16(ptr);
    arg0->unk84 = (code0UnkStruct18 *)&ptr[2];
    ptr2 = (u8 *)&arg0->unk84[arg0->unk88];
    arg0->unk98 = swap16(ptr2);
    arg0->unk8C = &ptr2[2];
}

/*8008196C*/
static void func_8008196C(s32 *arg0)
{
    f32 f1, f2, f3, f4, f5;

    f1 = 0.0f;
    f2 = arg0[0];
    if (f2 == 0.0f)
        f2 = 1.0f;

    f3 = arg0[1];
    if (f3 == 0.0f)
        f3 = 1.0f;

    f4 = arg0[2];
    if (f4 == 0.0f)
        f4 = 1.0f;

    f5 = (f2 * f2) + (f3 * f3) + (f4 * f4);
    if (!(f5 < 0.01))
        f1 = (126.0 / sqrtf(f5));

    arg0[0] = (s8)(f2 * f1);
    arg0[1] = (s8)(f3 * f1);
    arg0[2] = (s8)(f4 * f1);
}

INCLUDE_ASM("nonmatchings/src/code0/82480", func_80081AEC);

INCLUDE_ASM("nonmatchings/src/code0/82480", func_80081E20);

/*80082290*/
static void func_80082290(float mf[4][4], f32 arg1, f32 arg2, f32 arg3)
{
    f32 f1, f2, f3, f4, f5, f6;
    f6 = cosf(arg1);
    f5 = sinf(arg1);
    f4 = cosf(arg2);
    f2 = sinf(arg2);
    f3 = cosf(arg3);
    f1 = sinf(arg3);
    mf[0][1] = f1;
    mf[3][0] = 0.0f;
    mf[3][1] = 0.0f;
    mf[3][2] = 0.0f;
    mf[0][3] = 0.0f;
    mf[1][3] = 0.0f;
    mf[0][0] = f3 * f4;
    mf[2][3] = 0.0f;
    mf[3][3] = 1.0f;
    mf[1][0] = ((f6 * (-f1)) * f4) + (f5 * f2);
    mf[2][0] = (((-f5) * (-f1)) * f4) + (f6 * f2);
    mf[2][1] = (-f5) * f3;
    mf[1][1] = f6 * f3;
    mf[0][2] = f3 * (-f2);
    mf[1][2] = ((f6 * (-f1)) * (-f2)) + (f5 * f4);
    mf[2][2] = (((-f5) * (-f1)) * (-f2)) + (f6 * f4);
}

/*80082410*/
void func_80082410(Mtx *m, f32 arg1, f32 arg2, f32 arg3)
{
    float mf[4][4];

    func_80082290(mf, arg1, arg2, arg3);
    guMtxF2L(mf, m);
}

INCLUDE_ASM("nonmatchings/src/code0/82480", func_80082448);

/*80082920*/
static void func_80082920(void)
{
    s32 i;
    _82480UnkStruct1 *ptr;

    ptr = D_8012FC9C;
    for (i = 0; i < 2048; i++, ptr++)
    {
        ptr->unk0 = 0;
        ptr->unk4 = 0;
        ptr->unk8 = 0;
    }
}

/*80082958*/
static f32 func_80082958(_82480UnkStruct1 *arg0, _82480UnkStruct1 *arg1)
{
    return ((arg0->unk0 * arg1->unk0) + (arg0->unk4 * arg1->unk4) + (arg0->unk8 * arg1->unk8));
}

/*800829BC*/
static f32 func_800829BC(_82480UnkStruct1 *arg0, _82480UnkStruct1 *arg1)
{
    f32 f1, f2, f3, f4, f5, f6;

    f1 = func_80082958(arg1, arg1);
    f2 = 2.0f * func_80082958(arg1, arg0);
    f3 = func_80082958(arg0, arg0) - 4000000.0f;
    f4 = (f2 * f2) - (f1 * 4.0f * f3);
    if (f4 >= 0.0f)
    {
        f4 = sqrtf(f4);
        f5 = (-f2 + f4) / (2.0f * f1);
        f6 = (-f2 - f4) / (2.0f * f1);
        if ((f5 < 0.001) && (f6 < 0.001))
            return -1.0f;

        if ((f5 < f6))
        {
            if (f5 < 0.001)
                return f6;
        }
        else
        {
            if (f6 > 0.001)
                return f6;
        }
        return f5;
    }
    return -1.0f;
}

/*80082B44*/
static void func_80082B44(_82480UnkStruct1 *arg0, f32 arg1, f32 arg2, f32 arg3)
{
    arg0->unk0 -= arg1;
    arg0->unk4 += arg2;
    arg0->unk8 += arg3;
}

INCLUDE_ASM("nonmatchings/src/code0/82480", func_80082BA0);

/*800831D8*/
void func_800831D8(void *arg0, s32 arg1)
{
    alloCache(arg0, arg1 + 16, &gCacheLock[1]);
}

INCLUDE_ASM("nonmatchings/src/code0/82480", func_80083200);

STATIC void func_80083430(s32 arg0, _119280UnkStruct1 *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
INCLUDE_ASM("nonmatchings/src/code0/82480", func_80083430);

/*80083700*/
void func_80083700(s32 arg0, _119280UnkStruct1 *arg1, s32 arg2, s32 arg3)
{
    func_80083430(arg0, arg1, arg2, 0, 0, 0, arg3);
}

/*8008372C*/
code0UnkStruct16 *func_8008372C(s32 arg0, _119280UnkStruct1 *arg1, s32 arg2, u8 *arg3, s32 arg4)
{
    code0UnkStruct16 *ptr;

    func_80083700(arg0, arg1, arg2, arg4);
    ptr = func_8007EC10(2);
    ptr->unk6B.r = 0xFF;
    ptr->unk6B.g = 0xFF;
    ptr->unk6B.b = 0xFF;
    ptr->unk50 = 0;
    ptr->unkC |= 0x20;
    ptr->unkC |= arg2;
    ptr->unkA4 = D_8012C478[arg1->unk0];
    ptr->unkAC = arg3;
    return ptr;
}

/*800837B8*/
code0UnkStruct16 *func_800837B8(u16 *arg0, s32 arg1, u8 *arg2)
{
    code0UnkStruct16 *ptr;

    ptr = func_8007EC10(2);
    ptr->unk6B.r = 0xFF;
    ptr->unk6B.g = 0xFF;
    ptr->unk6B.b = 0xFF;
    ptr->unk50 = 0;
    ptr->unkC |= 0x20;
    ptr->unkC |= arg1;
    ptr->unkA4 = D_8012C478[*arg0];
    ptr->unkAC = arg2;
    return ptr;
}

/*8008383C*/
void func_8008383C(void)
{
    if (D_801CC88C == 0)
    {
        D_8012FD8C->unk4C += D_8012FD8C->unk58;
        D_8012FD8C->unk50 += D_8012FD8C->unk5C;
        D_8012FD8C->unk54 += D_8012FD8C->unk60;
    }
}

