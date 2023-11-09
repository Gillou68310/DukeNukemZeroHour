#include "common.h"
#include "code0/main.h"
#include "code0/9410.h"
#include "code0/41940.h"
#include "code0/code0.h"

typedef struct
{
    union
    {
        struct
        {
            /*0x00*/ u8 unk0;
            /*0x01*/ u8 unk1; /*palette*/
            /*0x02*/ u8 unk2; /*alpha*/
            /*0x04*/ s16 unk4; /*spritenum*/
            /*0x06*/ s16 unk6;
            /*0x08*/ s16 unk8;
            /*0x0A*/ s16 unkA;
        }s1;
        struct
        {
            /*0x00*/ s32 unk0;
            /*0x04*/ s32 unk4;
            /*0x08*/ s32 unk8;
        }s2;
    }u;
    /*0x0C*/ s32 x;
    /*0x10*/ s32 y;
    /*0x14*/ s32 z;
} _87010UnkStruct1;

typedef struct {
    /*0x00*/ _87010UnkStruct1 unk0[9];
    /*0xD0*/ s32 unkD8;
    /*0xDC*/ s32 unkDC;
    /*0xE0*/ s32 unkE0;
} _87010UnkStruct2;

typedef struct {
    /*0x00*/ _87010UnkStruct1 unk0;
    /*0x18*/ s32 unk18; /*x*/
    /*0x1C*/ s32 unk1C; /*y*/
    /*0x20*/ s32 unk20; /*z*/
} _87010UnkStruct3;

/*.comm*/
/*8011AE00*/ _87010UnkStruct2 D_8011AE00[16] ALIGNED(16);
/*8012B988*/ _87010UnkStruct3 D_8012B988[16] ALIGNED(8);
/*8016D182*/ u8 D_8016D182;

/*.text*/
static void func_8008736C(void);

/*80086410*/
void func_80086410(void)
{
    s16 i;

    for (i = 0; i < ARRAY_COUNT(D_8011AE00); i++)
    {
        D_8011AE00[i].unk0[0].u.s1.unk0 = 0;
        D_8011AE00[i].unk0[0].u.s1.unk4 = -9;
        D_8012B988[i].unk0.u.s1.unk0 = 0;
        D_8012B988[i].unk0.u.s1.unk4 = -9;
    }
}

/*80086490*/
static void func_80086490(_87010UnkStruct2 *arg0, s16 arg1, s16 arg2)
{
    _87010UnkStruct1 *ptr1;
    _87010UnkStruct1 *ptr2;
    _87010UnkStruct1 *ptr3;
    _87010UnkStruct1 *ptr4;
    s32 x1, y1, z1;
    s32 x2, y2, z2;
    s32 j;
    s16 i;

    i = (arg1 + arg2) / 2;
    if ((i == arg1) || (i == arg2))
        return;
    {
        ptr1 = &arg0->unk0[arg1];
        ptr2 = &arg0->unk0[arg2];
        x1 = (ptr1->x + ptr2->x) / 2;
        y1 = (ptr1->y + ptr2->y) / 2;
        z1 = (ptr1->z + ptr2->z) / 2;
        j = func_80040D94(x1, y1, z1, ptr1->x, ptr1->y, ptr1->z);

        if (D_8016D182 != 0)
            j /= 3;

        j = CLAMP_MIN(j, 1);
        x2 = (guRandom() % j) - j / 2;
        y2 = (guRandom() % j) - j / 2;
        z2 = (guRandom() % j) - j / 2;
        if (D_8016D182 == 0)
        {
            ptr3 = &arg0->unk0[i];
            x2 = (x2 * 0.1) + (ptr3[1].u.s2.unk0 * 0.9);
            y2 = (y2 * 0.1) + (ptr3[1].u.s2.unk4 * 0.9);
            z2 = (z2 * 0.1) + (ptr3[1].u.s2.unk8 * 0.9);
        }
        ptr4 = &arg0->unk0[i];
        ptr4->x = x1 + x2;
        ptr4->y = y1 + y2;
        ptr4->z = z1 + z2;
        ptr4[1].u.s2.unk0 = x2;
        ptr4[1].u.s2.unk4 = y2;
        ptr4[1].u.s2.unk8 = z2;
        func_80086490(arg0, arg1, i);
        func_80086490(arg0, i, arg2);
    }
}

/*800867CC*/
void func_800867CC(s16 spritenum, s32 x1, s32 y1, s32 z1, s32 x2, s32 y2, s32 z2, s16 arg7, u8 arg8)
{
    _87010UnkStruct2 *ptr;
    s16 i, j, ang;

    j = -1;

    for (i = 0; i < ARRAY_COUNT(D_8011AE00); i++)
    {
        if (D_8011AE00[i].unk0[0].u.s1.unk0 == 0)
            j = i;

        if (D_8011AE00[i].unk0[0].u.s1.unk4 == spritenum)
        {
            j = i;
            break;
        }
    }

    if (j != -1)
    {
        ptr = &D_8011AE00[j];
        ang = getAngle(x2 - x1, y2 - y1);
        ptr->unk0[0].u.s1.unk6 = (arg7 * gpSinTable[(ang + 1024) & 0x7FF]) / 16384;
        ptr->unk0[0].u.s1.unk8 = (arg7 * gpSinTable[(ang + 512) & 0x7FF]) / 16384;
        ptr->unk0[0].u.s1.unkA = arg7;
        ptr->unk0[0].x = x1;
        ptr->unk0[0].y = y1;
        ptr->unk0[0].z = z1 / 16;
        ptr->unk0[8].x = x2;
        ptr->unk0[8].y = y2;
        ptr->unk0[8].z = z2 / 16;

        if ((guRandom() % 256) >= 5)
            D_8016D182 = 0;
        else
            D_8016D182 = 1;

        func_80086490(ptr, 0, 8);
        ptr->unk0[0].u.s1.unk0 = 2;
        ptr->unk0[0].u.s1.unk1 = arg8;
        ptr->unk0[0].u.s1.unk4 = spritenum;
        ptr->unk0[0].u.s1.unk2 = krand() | 0x80;
    }
}

#ifdef NON_MATCHING
/*80086A24*/
void func_80086A24(void)
{
    _87010UnkStruct2 *ptr;
    s32 tc1;
    s16 tc2;
    s32 k;
    s16 i, j;
    s32 temp;

    gSPClearGeometryMode(gpDisplayList++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                                          G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);

    gSPSetGeometryMode(gpDisplayList++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH);

    gDPSetCombineLERP(gpDisplayList++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0,
                                       0, PRIMITIVE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED);

    gDPSetRenderMode(gpDisplayList++, G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2);
    gDPSetTextureLUT(gpDisplayList++, G_TT_NONE);
    func_8000C76C();
    func_8000BDB0(5668);

    for (i = 0; i < ARRAY_COUNT(D_8011AE00); i++)
    {
        ptr = &D_8011AE00[i];
        k = 0;
        if (ptr->unk0[0].u.s1.unk0 != 0)
        {
            gDPSetPrimColor(gpDisplayList++, 0, 0, gpAlphaPalette[ptr->unk0[0].u.s1.unk1].primary.r,
                                                   gpAlphaPalette[ptr->unk0[0].u.s1.unk1].primary.g,
                                                   gpAlphaPalette[ptr->unk0[0].u.s1.unk1].primary.b,
                                                   ptr->unk0[0].u.s1.unk2);

            gDPSetEnvColor(gpDisplayList++, gpAlphaPalette[ptr->unk0[0].u.s1.unk1].env.r,
                                            gpAlphaPalette[ptr->unk0[0].u.s1.unk1].env.g,
                                            gpAlphaPalette[ptr->unk0[0].u.s1.unk1].env.b,
                                            ptr->unk0[0].u.s1.unk2);

            for (j = 0; j < ARRAY_COUNT(ptr->unk0)-1; j++)
            {
                tc1 = k & 0xFFF;
                k += func_80040D94(ptr->unk0[j].x, ptr->unk0[j].y, ptr->unk0[j].z,
                                        ptr->unk0[j + 1].x, ptr->unk0[j + 1].y, ptr->unk0[j + 1].z);
                tc2 = k & 0xFFF;
                if (tc2 < tc1)
                    tc2 |= 0x1000;

                temp = 0x3FF; /*FAKEMATCH?*/
                gpVertexN64->v.ob[0] = (ptr->unk0[j].x / 2) - ptr->unk0[0].u.s1.unk6;
                gpVertexN64->v.ob[1] = (ptr->unk0[j].y / 2) - ptr->unk0[0].u.s1.unk8;
                gpVertexN64->v.ob[2] = (ptr->unk0[j].z / 2);
                gpVertexN64->v.tc[0] = tc1;
                gpVertexN64->v.tc[1] = 0;
                gpVertexN64->v.cn[0] = 0xFF;
                gpVertexN64->v.cn[1] = 0xFF;
                gpVertexN64->v.cn[2] = 0xFF;
                gpVertexN64->v.cn[3] = 0xFF;
                gpVertexN64++;

                gpVertexN64->v.ob[0] = ((ptr->unk0[j + 1].x / 2) - ptr->unk0[0].u.s1.unk6);
                gpVertexN64->v.ob[1] = ((ptr->unk0[j + 1].y / 2) - ptr->unk0[0].u.s1.unk8);
                gpVertexN64->v.ob[2] = (ptr->unk0[j + 1].z / 2);
                gpVertexN64->v.tc[0] = tc2;
                gpVertexN64->v.tc[1] = 0;
                gpVertexN64->v.cn[0] = 0xFF;
                gpVertexN64->v.cn[1] = 0xFF;
                gpVertexN64->v.cn[2] = 0xFF;
                gpVertexN64->v.cn[3] = 0xFF;
                gpVertexN64++;

                gpVertexN64->v.ob[0] = (ptr->unk0[0].u.s1.unk6 + (ptr->unk0[j + 1].x / 2));
                gpVertexN64->v.ob[1] = (ptr->unk0[0].u.s1.unk8 + (ptr->unk0[j + 1].y / 2));
                gpVertexN64->v.ob[2] = (ptr->unk0[j + 1].z / 2);
                gpVertexN64->v.tc[0] = tc2;
                gpVertexN64->v.tc[1] = temp;
                gpVertexN64->v.cn[0] = 0xFF;
                gpVertexN64->v.cn[1] = 0xFF;
                gpVertexN64->v.cn[2] = 0xFF;
                gpVertexN64->v.cn[3] = 0xFF;
                gpVertexN64++;

                gpVertexN64->v.ob[0] = (ptr->unk0[0].u.s1.unk6 + (ptr->unk0[j].x / 2));
                gpVertexN64->v.ob[1] = (ptr->unk0[0].u.s1.unk8 + (ptr->unk0[j].y / 2));
                gpVertexN64->v.ob[2] = (ptr->unk0[j].z / 2);
                gpVertexN64->v.tc[0] = tc1;
                gpVertexN64->v.tc[1] = temp;
                gpVertexN64->v.cn[0] = 0xFF;
                gpVertexN64->v.cn[1] = 0xFF;
                gpVertexN64->v.cn[2] = 0xFF;
                gpVertexN64->v.cn[3] = 0xFF;
                gpVertexN64++;

                func_8000B6A8(1);

                gpVertexN64->v.ob[0] = (ptr->unk0[j].x / 2);
                gpVertexN64->v.ob[1] = (ptr->unk0[j].y / 2);
                gpVertexN64->v.ob[2] = ptr->unk0[0].u.s1.unkA + (ptr->unk0[j].z / 2);
                gpVertexN64->v.tc[0] = tc1;
                gpVertexN64->v.tc[1] = 0;
                gpVertexN64->v.cn[0] = 0xFF;
                gpVertexN64->v.cn[1] = 0xFF;
                gpVertexN64->v.cn[2] = 0xFF;
                gpVertexN64->v.cn[3] = 0xFF;
                gpVertexN64++;

                gpVertexN64->v.ob[0] = (ptr->unk0[j + 1].x / 2);
                gpVertexN64->v.ob[1] = (ptr->unk0[j + 1].y / 2);
                gpVertexN64->v.ob[2] = ptr->unk0[0].u.s1.unkA + (ptr->unk0[j + 1].z / 2);
                gpVertexN64->v.tc[0] = tc2;
                gpVertexN64->v.tc[1] = 0;
                gpVertexN64->v.cn[0] = 0xFF;
                gpVertexN64->v.cn[1] = 0xFF;
                gpVertexN64->v.cn[2] = 0xFF;
                gpVertexN64->v.cn[3] = 0xFF;
                gpVertexN64++;

                gpVertexN64->v.ob[0] = (ptr->unk0[j + 1].x / 2);
                gpVertexN64->v.ob[1] = (ptr->unk0[j + 1].y / 2);
                gpVertexN64->v.ob[2] = (ptr->unk0[j + 1].z / 2) - ptr->unk0[0].u.s1.unkA;
                gpVertexN64->v.tc[0] = tc2;
                gpVertexN64->v.tc[1] = temp;
                gpVertexN64->v.cn[0] = 0xFF;
                gpVertexN64->v.cn[1] = 0xFF;
                gpVertexN64->v.cn[2] = 0xFF;
                gpVertexN64->v.cn[3] = 0xFF;
                gpVertexN64++;

                gpVertexN64->v.ob[0] = (ptr->unk0[j].x / 2);
                gpVertexN64->v.ob[1] = (ptr->unk0[j].y / 2);
                gpVertexN64->v.ob[2] = (ptr->unk0[j].z / 2) - ptr->unk0[0].u.s1.unkA;
                gpVertexN64->v.tc[0] = tc1;
                gpVertexN64->v.tc[1] = temp;
                gpVertexN64->v.cn[0] = 0xFF;
                gpVertexN64->v.cn[1] = 0xFF;
                gpVertexN64->v.cn[2] = 0xFF;
                gpVertexN64->v.cn[3] = 0xFF;
                gpVertexN64++;
                func_8000B6A8(1);
            }
        }
    }
    func_8008736C();
}
#else
/*80086A24*/
INCLUDE_ASM("nonmatchings/src/code0/87010", func_80086A24);
#endif

/*80087174*/
void func_80087174(s16 spritenum, s32 x1, s32 y1, s32 z1, s32 x2, s32 y2, s32 z2, s16 arg7, u8 arg8)
{
    _87010UnkStruct3 *ptr;
    s16 i, j, ang;

    j = -1;

    for (i = 0; i < ARRAY_COUNT(D_8012B988); i++)
    {
        if (D_8012B988[i].unk0.u.s1.unk0 == 0)
            j = i;

        if (D_8012B988[i].unk0.u.s1.unk4 == spritenum)
        {
            j = i;
            break;
        }
    }

    if (j != -1)
    {
        ptr = &D_8012B988[j];
        ang = getAngle(x2 - x1, y2 - y1);
        ptr->unk0.u.s1.unk6 = (arg7 * gpSinTable[(ang + 1024) & 0x7FF]) / 16384;
        ptr->unk0.u.s1.unk8 = (arg7 * gpSinTable[(ang + 512) & 0x7FF]) / 16384;
        ptr->unk0.u.s1.unkA = arg7;
        ptr->unk0.x = x1;
        ptr->unk0.y = y1;
        ptr->unk0.z = z1 / 16;
        ptr->unk18 = x2;
        ptr->unk1C = y2;
        ptr->unk20 = z2 / 16;
        ptr->unk0.u.s1.unk0 = 2;
        ptr->unk0.u.s1.unk1 = arg8;
        ptr->unk0.u.s1.unk4 = spritenum;
        ptr->unk0.u.s1.unk2 = krand() | 0x80;
    }
}

/*8008736C*/
static void func_8008736C(void)
{
    _87010UnkStruct3 *ptr;
    s16 i;

    gSPClearGeometryMode(gpDisplayList++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                                          G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);

    gSPSetGeometryMode(gpDisplayList++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH);

    gDPSetCombineLERP(gpDisplayList++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0,
                                       0, PRIMITIVE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED);

    gDPSetRenderMode(gpDisplayList++, G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2);
    gDPSetTextureLUT(gpDisplayList++, G_TT_NONE);
    func_8000C76C();
    func_8000BDB0(5668);

    for (i = 0; i < ARRAY_COUNT(D_8012B988); i++)
    {
        ptr = &D_8012B988[i];

        if (ptr->unk0.u.s1.unk0 != 0)
        {
            gDPSetPrimColor(gpDisplayList++, 0, 0, gpAlphaPalette[ptr->unk0.u.s1.unk1].primary.r,
                                                   gpAlphaPalette[ptr->unk0.u.s1.unk1].primary.g,
                                                   gpAlphaPalette[ptr->unk0.u.s1.unk1].primary.b,
                                                   ptr->unk0.u.s1.unk2);

            gDPSetEnvColor(gpDisplayList++, gpAlphaPalette[ptr->unk0.u.s1.unk1].env.r,
                                            gpAlphaPalette[ptr->unk0.u.s1.unk1].env.g,
                                            gpAlphaPalette[ptr->unk0.u.s1.unk1].env.b,
                                            ptr->unk0.u.s1.unk2);

            gpVertexN64->v.ob[0] = (ptr->unk0.x / 2) - ptr->unk0.u.s1.unk6;
            gpVertexN64->v.ob[1] = (ptr->unk0.y / 2) - ptr->unk0.u.s1.unk8;
            gpVertexN64->v.ob[2] = ptr->unk0.z / 2;
            gpVertexN64->v.tc[0] = 0;
            gpVertexN64->v.tc[1] = 0;
            gpVertexN64->v.cn[0] = 0xFF;
            gpVertexN64->v.cn[1] = 0xFF;
            gpVertexN64->v.cn[2] = 0xFF;
            gpVertexN64->v.cn[3] = 0xFF;
            gpVertexN64++;

            gpVertexN64->v.ob[0] = (ptr->unk18 / 2) - ptr->unk0.u.s1.unk6;
            gpVertexN64->v.ob[1] = (ptr->unk1C / 2) - ptr->unk0.u.s1.unk8;
            gpVertexN64->v.ob[2] = ptr->unk20 / 2;
            gpVertexN64->v.tc[0] = 0x3FF;
            gpVertexN64->v.tc[1] = 0;
            gpVertexN64->v.cn[0] = 0xFF;
            gpVertexN64->v.cn[1] = 0xFF;
            gpVertexN64->v.cn[2] = 0xFF;
            gpVertexN64->v.cn[3] = 0xFF;
            gpVertexN64++;

            gpVertexN64->v.ob[0] = ptr->unk0.u.s1.unk6 + (ptr->unk18 / 2);
            gpVertexN64->v.ob[1] = ptr->unk0.u.s1.unk8 + (ptr->unk1C / 2);
            gpVertexN64->v.ob[2] = ptr->unk20 / 2;
            gpVertexN64->v.tc[0] = 0x3FF;
            gpVertexN64->v.tc[1] = 0x3FF;
            gpVertexN64->v.cn[0] = 0xFF;
            gpVertexN64->v.cn[1] = 0xFF;
            gpVertexN64->v.cn[2] = 0xFF;
            gpVertexN64->v.cn[3] = 0xFF;
            gpVertexN64++;

            gpVertexN64->v.ob[0] = ptr->unk0.u.s1.unk6 + (ptr->unk0.x / 2);
            gpVertexN64->v.ob[1] = ptr->unk0.u.s1.unk8 + (ptr->unk0.y / 2);
            gpVertexN64->v.ob[2] = ptr->unk0.z / 2;
            gpVertexN64->v.tc[0] = 0;
            gpVertexN64->v.tc[1] = 0x3FF;
            gpVertexN64->v.cn[0] = 0xFF;
            gpVertexN64->v.cn[1] = 0xFF;
            gpVertexN64->v.cn[2] = 0xFF;
            gpVertexN64->v.cn[3] = 0xFF;
            gpVertexN64++;

            func_8000B6A8(1);

            gpVertexN64->v.ob[0] = ptr->unk0.x / 2;
            gpVertexN64->v.ob[1] = ptr->unk0.y / 2;
            gpVertexN64->v.ob[2] = ptr->unk0.u.s1.unkA + (ptr->unk0.z /2);
            gpVertexN64->v.tc[0] = 0;
            gpVertexN64->v.tc[1] = 0;
            gpVertexN64->v.cn[0] = 0xFF;
            gpVertexN64->v.cn[1] = 0xFF;
            gpVertexN64->v.cn[2] = 0xFF;
            gpVertexN64->v.cn[3] = 0xFF;
            gpVertexN64++;

            gpVertexN64->v.ob[0] = ptr->unk18 / 2;
            gpVertexN64->v.ob[1] = ptr->unk1C / 2;
            gpVertexN64->v.ob[2] = ptr->unk0.u.s1.unkA + (ptr->unk20 / 2);
            gpVertexN64->v.tc[0] = 0x3FF;
            gpVertexN64->v.tc[1] = 0;
            gpVertexN64->v.cn[0] = 0xFF;
            gpVertexN64->v.cn[1] = 0xFF;
            gpVertexN64->v.cn[2] = 0xFF;
            gpVertexN64->v.cn[3] = 0xFF;
            gpVertexN64++;

            gpVertexN64->v.ob[0] = ptr->unk18 / 2;
            gpVertexN64->v.ob[1] = ptr->unk1C / 2;
            gpVertexN64->v.ob[2] = (ptr->unk20 / 2) - ptr->unk0.u.s1.unkA;
            gpVertexN64->v.tc[0] = 0x3FF;
            gpVertexN64->v.tc[1] = 0x3FF;
            gpVertexN64->v.cn[0] = 0xFF;
            gpVertexN64->v.cn[1] = 0xFF;
            gpVertexN64->v.cn[2] = 0xFF;
            gpVertexN64->v.cn[3] = 0xFF;
            gpVertexN64++;

            gpVertexN64->v.ob[0] = ptr->unk0.x / 2;
            gpVertexN64->v.ob[1] = ptr->unk0.y / 2;
            gpVertexN64->v.ob[2] = (ptr->unk0.z / 2) - ptr->unk0.u.s1.unkA;
            gpVertexN64->v.tc[0] = 0;
            gpVertexN64->v.tc[1] = 0x3FF;
            gpVertexN64->v.cn[0] = 0xFF;
            gpVertexN64->v.cn[1] = 0xFF;
            gpVertexN64->v.cn[2] = 0xFF;
            gpVertexN64->v.cn[3] = 0xFF;
            gpVertexN64++;
            func_8000B6A8(1);
        }
    }
}

/*800879E8*/
void func_800879E8(void)
{
    s16 i;

    for (i = 0; i < ARRAY_COUNT(D_8011AE00); i++)
    {
        D_8011AE00[i].unk0[0].u.s1.unk0 = MAX((D_8011AE00[i].unk0[0].u.s1.unk0-1), 0);
        D_8012B988[i].unk0.u.s1.unk0 = MAX((D_8012B988[i].unk0.u.s1.unk0-1), 0);
    }
}
