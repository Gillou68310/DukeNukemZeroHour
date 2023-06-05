#include "common.h"

typedef struct
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    s32 unk4; /*x1*/
    s32 unk8; /*y1*/
    s32 unkC; /*z1*/
    s32 unk10; /*x2*/
    s32 unk14; /*y2*/
    s32 unk18; /*z2*/
    s32 unk1C; /*x3*/
    s32 unk20; /*y3*/
    s32 unk24; /*z3*/
    s16 unk28;
    s16 unk2A;
    s16 unk2C;
} _7BA50UnkStruct1;

/*.text*/

/*800DF940*/ EXTERN_DATA STATIC u16 D_800DF940;

/*.comm*/
/*800FCBF0*/ _7BA50UnkStruct1 D_800FCBF0[128] ALIGNED(16);

/*8007AE50*/
s32 func_8007AE50(void)
{
    D_800DF940 = (D_800DF940 + 1) & 0x3FFF;
    return D_800DF940;
}

/*8007AE70*/
static s16 func_8007AE70(void)
{
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_800FCBF0); i++)
    {
        if ((D_800FCBF0[i].unk0 & 1) == 0)
            return i;
    }
    return -1;
}

/*8007AEB4*/
void func_8007AEB4(void)
{
    s32 i;
    for (i = 0; i < ARRAY_COUNT(D_800FCBF0); i++)
        D_800FCBF0[i].unk0 = 0;
}

/*8007AED8*/
void func_8007AED8(s32 x1, s32 y1, s32 z1, s32 x2, s32 y2, s32 z2, u8 arg6, u8 arg7, u8 arg8, s16 arg9, s32 argA)
{
    s16 i;

    i = func_8007AE70();
    if (i != -1)
    {
        D_800FCBF0[i].unk0 = (D_800FCBF0[i].unk0 | 1) & 0xFB;
        D_800FCBF0[i].unk4 = x1 * 4;
        D_800FCBF0[i].unk8 = y1 * 4;
        D_800FCBF0[i].unkC = z1 / 4;
        D_800FCBF0[i].unk10 = x2 * 4;
        D_800FCBF0[i].unk14 = y2 * 4;
        D_800FCBF0[i].unk18 = z2 / 4;
        D_800FCBF0[i].unk1C = (D_800FCBF0[i].unk4 - D_800FCBF0[i].unk10) / 2;
        D_800FCBF0[i].unk20 = (D_800FCBF0[i].unk8 - D_800FCBF0[i].unk14) / 2;
        D_800FCBF0[i].unk24 = (D_800FCBF0[i].unkC - D_800FCBF0[i].unk18) / 2;
        D_800FCBF0[i].unk2A = arg9;
        D_800FCBF0[i].unk28 = arg9;
        D_800FCBF0[i].unk1 = arg6;
        D_800FCBF0[i].unk2 = arg7;
        D_800FCBF0[i].unk3 = arg8;
        D_800FCBF0[i].unk2C = argA;
        D_800FCBF0[i].unk1C /= arg9;
        D_800FCBF0[i].unk20 /= arg9;
        D_800FCBF0[i].unk24 /= arg9;
    }
}

/*8007B1F4*/
void func_8007B1F4(s32 x1, s32 y1, s32 z1, s32 x2, s32 y2, s32 z2, s16 arg6, s32 arg7)
{
    s16 i;

    i = func_8007AE70();
    if (i != -1)
    {
        D_800FCBF0[i].unk0 |= 5;
        D_800FCBF0[i].unk4 = x1 * 4;
        D_800FCBF0[i].unk8 = y1 * 4;
        D_800FCBF0[i].unkC = z1 / 4;
        D_800FCBF0[i].unk10 = x2 * 4;
        D_800FCBF0[i].unk14 = y2 * 4;
        D_800FCBF0[i].unk18 = z2 / 4;
        D_800FCBF0[i].unk1C = (D_800FCBF0[i].unk4 - D_800FCBF0[i].unk10) / 2;
        D_800FCBF0[i].unk20 = (D_800FCBF0[i].unk8 - D_800FCBF0[i].unk14) / 2;
        D_800FCBF0[i].unk24 = (D_800FCBF0[i].unkC - D_800FCBF0[i].unk18) / 2;
        D_800FCBF0[i].unk2A = arg6;
        D_800FCBF0[i].unk28 = arg6;
        D_800FCBF0[i].unk2C = arg7;
        D_800FCBF0[i].unk1C /= arg6;
        D_800FCBF0[i].unk20 /= arg6;
        D_800FCBF0[i].unk24 /= arg6;
    }
}

/*8007B4CC*/
void func_8007B4CC(void)
{
    s32 i, unk0;

    for (i = 0; i < ARRAY_COUNT(D_800FCBF0); i++)
    {
        unk0 = D_800FCBF0[i].unk0;
        D_800FCBF0[i].unk0 &= 0xFD;
        if (unk0 & 1)
        {
            D_800FCBF0[i].unk28--;
            D_800FCBF0[i].unk10 += D_800FCBF0[i].unk1C;
            D_800FCBF0[i].unk14 += D_800FCBF0[i].unk20;
            D_800FCBF0[i].unk18 += D_800FCBF0[i].unk24;
            D_800FCBF0[i].unk4 -= D_800FCBF0[i].unk1C;
            D_800FCBF0[i].unk8 -= D_800FCBF0[i].unk20;
            D_800FCBF0[i].unkC -= D_800FCBF0[i].unk24;
            if (D_800FCBF0[i].unk28 == -1)
                D_800FCBF0[i].unk0 = 0;
        }
    }
}

/*8007B5D8*/
static s16 func_8007B5D8(s32 arg0, s16 arg1)
{
    s32 i;
    for (i = 0; i < ARRAY_COUNT(D_800FCBF0); i++)
    {
        if (!(D_800FCBF0[i].unk0 & 1))
            continue;

        if (D_800FCBF0[i].unk28 != arg1)
            continue;

        if (D_800FCBF0[i].unk2C != arg0)
            continue;

        return i;
    }
    return -1;
}

INCLUDE_ASM("nonmatchings/src/code0/7BA50", func_8007B64C);

INCLUDE_ASM("nonmatchings/src/code0/7BA50", func_8007B930);

INCLUDE_ASM("nonmatchings/src/code0/7BA50", func_8007BE80);
