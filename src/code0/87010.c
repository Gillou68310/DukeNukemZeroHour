#include "common.h"
#include "code0/code0.h"

typedef struct {
    /*0x00*/ u8 unk0;
    /*0x01*/ u8 unk1;
    /*0x02*/ u8 unk2;
    /*0x03*/ u8 pad;
    /*0x04*/ s16 unk4;
    /*0x06*/ s16 unk6;
    /*0x08*/ s16 unk8;
    /*0x0A*/ s16 unkA;
    /*0x0C*/ s32 unkC;
    /*0x10*/ s32 unk10;
    /*0x14*/ s32 unk14;
    /*0x18*/ u8 pad2[178];
    /*0xCC*/ s32 unkCC;
    /*0xD0*/ s32 unkD0;
    /*0xD4*/ s32 unkD4;
    /*0xD8*/ u8 pad3[10];
} _87010UnkStruct1;

typedef struct {
    /*0x00*/ u8 unk0;
    /*0x01*/ u8 unk1;
    /*0x02*/ u8 unk2;
    /*0x03*/ u8 pad;
    /*0x04*/ s16 unk4;
    /*0x06*/ s16 unk6;
    /*0x08*/ s16 unk8;
    /*0x0A*/ s16 unkA;
    /*0x0C*/ s32 unkC;
    /*0x10*/ s32 unk10;
    /*0x14*/ s32 unk14;
    /*0x18*/ s32 unk18;
    /*0x1C*/ s32 unk1C;
    /*0x20*/ s32 unk20;
} _87010UnkStruct2;

/*.comm*/
/*8011AE00*/ _87010UnkStruct1 D_8011AE00[16] ALIGNED(16);
/*8012B988*/ _87010UnkStruct2 D_8012B988[16] ALIGNED(8);
/*8016D182*/ u8 D_8016D182;

/*.text*/

/*80086410*/
void func_80086410(void)
{
    s16 i;

    for (i = 0; i < ARRAY_COUNT(D_8011AE00); i++)
    {
        D_8011AE00[i].unk0 = 0;
        D_8011AE00[i].unk4 = -9;
        D_8012B988[i].unk0 = 0;
        D_8012B988[i].unk4 = -9;
    }
}

STATIC void func_80086490(_87010UnkStruct1 *, s16, s16);
INCLUDE_ASM("nonmatchings/src/code0/87010", func_80086490);

/*800867CC*/
void func_800867CC(s16 spritenum, s32 x1, s32 y1, s32 z1, s32 x2, s32 y2, s32 z2, s16 arg7, u8 arg8)
{
    _87010UnkStruct1 *ptr;
    s16 i, j, ang;

    j = -1;

    for (i = 0; i < ARRAY_COUNT(D_8011AE00); i++)
    {
        if (D_8011AE00[i].unk0 == 0)
            j = i;

        if (D_8011AE00[i].unk4 == spritenum)
        {
            j = i;
            break;
        }
    }

    if (j != -1)
    {
        ptr = &D_8011AE00[j];
        ang = getAngle(x2 - x1, y2 - y1);
        ptr->unk6 = (arg7 * gpSinTable[(ang + 1024) & 0x7FF]) / 16384;
        ptr->unk8 = (arg7 * gpSinTable[(ang + 512) & 0x7FF]) / 16384;
        ptr->unkA = arg7;
        ptr->unkC = x1;
        ptr->unk10 = y1;
        ptr->unk14 = z1 / 16;
        ptr->unkCC = x2;
        ptr->unkD0 = y2;
        ptr->unkD4 = z2 / 16;

        if ((guRandom() % 256) >= 5)
            D_8016D182 = 0;
        else
            D_8016D182 = 1;

        func_80086490(ptr, 0, 8);
        ptr->unk0 = 2;
        ptr->unk1 = arg8;
        ptr->unk4 = spritenum;
        ptr->unk2 = krand() | 0x80;
    }
}

INCLUDE_ASM("nonmatchings/src/code0/87010", func_80086A24);

/*80087174*/
void func_80087174(s16 spritenum, s32 x1, s32 y1, s32 z1, s32 x2, s32 y2, s32 z2, s16 arg7, u8 arg8)
{
    _87010UnkStruct2 *ptr;
    s16 i, j, ang;

    j = -1;

    for (i = 0; i < ARRAY_COUNT(D_8012B988); i++)
    {
        if (D_8012B988[i].unk0 == 0)
            j = i;

        if (D_8012B988[i].unk4 == spritenum)
        {
            j = i;
            break;
        }
    }

    if (j != -1)
    {
        ptr = &D_8012B988[j];
        ang = getAngle(x2 - x1, y2 - y1);
        ptr->unk6 = (arg7 * gpSinTable[(ang + 1024) & 0x7FF]) / 16384;
        ptr->unk8 = (arg7 * gpSinTable[(ang + 512) & 0x7FF]) / 16384;
        ptr->unkA = arg7;
        ptr->unkC = x1;
        ptr->unk10 = y1;
        ptr->unk14 = z1 / 16;
        ptr->unk18 = x2;
        ptr->unk1C = y2;
        ptr->unk20 = z2 / 16;
        ptr->unk0 = 2;
        ptr->unk1 = arg8;
        ptr->unk4 = spritenum;
        ptr->unk2 = krand() | 0x80;
    }
}

INCLUDE_ASM("nonmatchings/src/code0/87010", func_8008736C);

/*800879E8*/
void func_800879E8(void)
{
    s16 i;

    for (i = 0; i < ARRAY_COUNT(D_8011AE00); i++)
    {
        D_8011AE00[i].unk0 = MAX((D_8011AE00[i].unk0-1), 0);
        D_8012B988[i].unk0 = MAX((D_8012B988[i].unk0-1), 0);
    }
}
