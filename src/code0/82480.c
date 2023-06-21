#include "common.h"
#include "code0/cache1d.h"
#include "code0/edl.h"
#include "code0/7F6A0.h"
#include "code0/82480.h"
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
/*800FF3E0*/ _82480UnkStruct1 *D_800FF3E0;
/*8012FC9C*/ _82480UnkStruct1 *D_8012FC9C;
/*801AC598*/ Vtx *D_801AC598[200] ALIGNED(8);
/*801AE52C*/ s32 D_801AE52C;

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
void func_800818A8(code0UnkStruct16 *arg0, s16 id, s16 off, void *arg3, void *arg4, void *arg5, void *arg6)
{
    u8 *ptr;
    u8 *ptr2;

    ptr = edl_80081840(id, off);
    arg0->unk70 = (intptr_t)ptr;
    arg0->unk74 = (intptr_t)arg3;
    arg0->unk78 = (intptr_t)arg4;
    arg0->unk7C = (intptr_t)arg5;
    arg0->unk80 = (intptr_t)arg6;
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

/*80081AEC*/
INCLUDE_ASM("nonmatchings/src/code0/82480", func_80081AEC);

/*80081E20*/
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

/*80082448*/
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

/*80082BA0*/
STATIC void func_80082BA0(void);
INCLUDE_ASM("nonmatchings/src/code0/82480", func_80082BA0);

/*800831D8*/
void func_800831D8(void *arg0, s32 arg1)
{
    alloCache(arg0, arg1 + 16, &gCacheLock[1]);
}

/*80083200*/
void func_80083200(_119280UnkStruct1 *arg0, s32 arg1)
{
    code0UnkStruct20 sp30;
    code0UnkStruct16 sp48;
    s32 i;
    u8 *ptr1;
    u8 *ptr2;
    u8 *ptr3;

    ptr1 = D_801CDBC8;
    ptr2 = D_801CC888;
    ptr3 = D_801CDA98;
    D_801AE52C = 0;
    func_800831D8(&D_801AC598[arg0->unk0], arg0->unk6 * sizeof(Vtx));
    func_800831D8(&D_8012C478[arg0->unk0], arg0->unk8 * sizeof(Gfx));
    i = arg1 & 0x1000;
    if (i != 0)
    {
        D_80168D18 = 0;
        D_800FE3F4 = 0;
        D_8012FC9C = (_82480UnkStruct1 *)D_801CD96C;
        D_800FF3E0 = &D_8012FC9C[arg0->unk6];
        func_80085EBC(D_801AC598[arg0->unk0], arg0->unk6, &D_8012C478[arg0->unk0], arg0->unk8, arg1);
        D_8012FD8C = &sp48;
        func_8007EC7C(&sp48);
        D_8012FD8C->unk34 = 0.0f;
        D_8012FD8C->unk38 = 0.0f;
        D_8012FD8C->unk3C = 0.0f;
        D_8012FD8C->unk50 = 0.0f;
        D_8012FD8C->unkC = arg1 | 0x20;
        func_800818A8(D_8012FD8C, arg0->unk2, arg0->unk4, ptr1, ptr2, NULL, ptr3);
        func_80081E20(func_80082920, func_80082BA0, 1);
    }
    sp30.unk0 = arg0->unk2;
    sp30.unk2 = arg0->unk4;
    sp30.unk4 = ptr1;
    sp30.unk8 = ptr2;
    sp30.unkC = ptr3;
    sp30.unk10 = 0;
    if (i != 0)
        arg1 |= 0x2000;

    func_800861F4(&sp30, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, arg1 | 0x20,
                  D_801AC598[arg0->unk0], arg0->unk6, D_8012C478[arg0->unk0], arg0->unk8);
}

/*80083430*/
static void func_80083430(s32 arg0, _119280UnkStruct1 *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6)
{
    code0UnkStruct20 sp30;
    code0UnkStruct16 sp48;
    s32 i;
    u8 *ptr1;
    u8 *ptr2;
    u8 *ptr3;

    D_801AE52C = arg6;
    switch (arg0)
    {
    case 0:
        ptr3 = D_801CC920;
        ptr2 = D_801CC91C;
        ptr1 = D_801CDB1C;
        break;
    case 1:
        ptr3 = D_801CDBC8;
        ptr2 = D_801CC888;
        ptr1 = D_801CDA98;
        break;
    case 2:
        ptr3 = D_801CDB44;
        ptr2 = D_801CDB10;
        ptr1 = D_801CDB18;
        break;
    }
    allocacheEDL(&D_801AC598[arg1->unk0], arg1->unk6 * sizeof(Vtx));
    allocacheEDL(&D_8012C478[arg1->unk0], arg1->unk8 * sizeof(Gfx));
    i = arg2 & 0x1000;
    if (i != 0)
    {
        D_80168D18 = 0;
        D_800FE3F4 = 0;
        D_8012FC9C = (_82480UnkStruct1 *)D_801CD96C;
        D_800FF3E0 = &D_8012FC9C[arg1->unk6];
        func_80085EBC(D_801AC598[arg1->unk0], arg1->unk6, &D_8012C478[arg1->unk0], arg1->unk8, arg2);
        D_8012FD8C = &sp48;
        func_8007EC7C(&sp48);
        D_8012FD8C->unk34 = 0.0f;
        D_8012FD8C->unk38 = 0.0f;
        D_8012FD8C->unk3C = 0.0f;
        D_8012FD8C->unk50 = 0.0f;
        D_8012FD8C->unkC = arg2 | 0x20;
        func_800818A8(D_8012FD8C, arg1->unk2, arg1->unk4, ptr3, ptr2, NULL, ptr1);
        func_80081E20(func_80082920, func_80082BA0, 1);
    }
    sp30.unk0 = arg1->unk2;
    sp30.unk2 = arg1->unk4;
    sp30.unk4 = ptr3;
    sp30.unk8 = ptr2;
    sp30.unkC = ptr1;
    sp30.unk10 = 0;
    if (i != 0)
        arg2 |= 0x2000;

    func_800861F4(&sp30, arg3, arg4, arg5, 0.0f, 1.0f, arg2 | 0x20,
                  D_801AC598[arg1->unk0], arg1->unk6, D_8012C478[arg1->unk0], arg1->unk8);
}

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
