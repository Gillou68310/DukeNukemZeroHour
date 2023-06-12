#include "common.h"
#include "code0/9410.h"
#include "code0/main.h"

typedef struct
{
    u8 unk0;
    u8 unk1; /*r*/
    u8 unk2; /*g*/
    u8 unk3; /*b*/
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

/*8007B64C*/
static void func_8007B64C(s32 arg0)
{
    s32 i, j, k, l, d, m;
    s32 temp;

    k = 0;
    gDPSetCombineMode(gpDisplayList++, G_CC_SHADE, G_CC_PASS2);
    func_8000C76C();
    temp = arg0;
    for (i = 127; i >= 0; i--)
    {
        l = func_8007B5D8(temp, i);
        if (l != -1)
        {
            d = (D_800FCBF0[l].unk28 << 7) / D_800FCBF0[l].unk2A;
            j = (k == 0);
            D_800FCBF0[l].unk0 |= 2;
            m = CLAMP_MAX(d, 0xFF);
            for (; j < 2; j++)
            {
                gpVertexN64->v.ob[0] = D_800FCBF0[l].unk4 / 8;
                gpVertexN64->v.ob[1] = D_800FCBF0[l].unk8 / 8;
                gpVertexN64->v.ob[2] = D_800FCBF0[l].unkC / 8;
                gpVertexN64->v.tc[0] = 0;
                gpVertexN64->v.tc[1] = 0;
                gpVertexN64->v.cn[0] = D_800FCBF0[l].unk1;
                gpVertexN64->v.cn[1] = D_800FCBF0[l].unk2;
                gpVertexN64->v.cn[2] = D_800FCBF0[l].unk3;
                gpVertexN64->v.cn[3] = m;
                gpVertexN64++;
                gpVertexN64->v.ob[0] = D_800FCBF0[l].unk10 / 8;
                gpVertexN64->v.ob[1] = D_800FCBF0[l].unk14 / 8;
                gpVertexN64->v.ob[2] = D_800FCBF0[l].unk18 / 8;
                gpVertexN64->v.tc[0] = 0;
                gpVertexN64->v.tc[1] = 0;
                gpVertexN64->v.cn[0] = D_800FCBF0[l].unk1;
                gpVertexN64->v.cn[1] = D_800FCBF0[l].unk2;
                gpVertexN64->v.cn[2] = D_800FCBF0[l].unk3;
                gpVertexN64->v.cn[3] = m;
                gpVertexN64++;
            }
            k += 1;
        }
    }
    if (k >= 2)
        func_8000B830(k - 1);
}

/*8007B930*/
STATIC void func_8007B930(s16);
INCLUDE_ASM("nonmatchings/src/code0/7BA50", func_8007B930);

/*8007BE80*/
void func_8007BE80(void)
{
    s32 i;

    gSPClearGeometryMode(gpDisplayList++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                                          G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gSPSetGeometryMode(gpDisplayList++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH);
    gDPSetRenderMode(gpDisplayList++, G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2);

    for (i = 0; i < ARRAY_COUNT(D_800FCBF0); i++)
    {
        if ((D_800FCBF0[i].unk0 & 1) && !(D_800FCBF0[i].unk0 & 2))
        {
            if (D_800FCBF0[i].unk0 & 4)
                func_8007B930(D_800FCBF0[i].unk2C);
            else
                func_8007B64C(D_800FCBF0[i].unk2C);
        }
    }
    for (i = 0; i < ARRAY_COUNT(D_800FCBF0); i++)
    {
        D_800FCBF0[i].unk0 &= 0xFD;
    }
}
