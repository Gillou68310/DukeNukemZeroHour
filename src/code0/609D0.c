#include "common.h"
#include "code0/engine.h"
#include "code0/code0.h"
#include "code1/code1.h"
#include "static/mapinfo.h"

typedef struct {
    /*0x00*/ s32 unk0; /*x*/
    /*0x04*/ s32 unk4; /*y*/
    /*0x08*/ s32 unk8; /*z*/
    /*0x0C*/ s16 unkC;
    /*0x0E*/ s16 unkE;
} _609D0UnkStruct1;

/*.comm*/
/*80107908*/ s16 D_80107908;
/*8012F708*/_609D0UnkStruct1 D_8012F708[32] ALIGNED(8);

/*.text*/

/*8005FDD0*/
static void func_8005FDD0(SectorType *sec, s16 arg1)
{
    s16 i;

    for (i = sec->wallptr; i < (sec->wallptr + sec->wallnum); i++)
    {
        if (gpWall[i].nextwall != -1)
        {
            gpWall[gpWall[i].nextwall].unk14 = 66;
            gpWall[gpWall[i].nextwall].unk16 = arg1;
        }
    }
}

/*8005FE84*/
static void func_8005FE84(s16 wallnum)
{
    gpWall[wallnum].cstat |= 0x1000;
    if (gpWall[wallnum].nextwall != -1)
        gpWall[gpWall[wallnum].nextwall].cstat |= 0x1000;
}

INCLUDE_ASM("nonmatchings/src/code0/609D0", func_8005FEE0);

INCLUDE_ASM("nonmatchings/src/code0/609D0", func_80062300);

/*80062688*/
static s16 func_80062688(s16 arg0)
{
    s16 ret;
    s32 d1, d2, d3;

    s16 i, j;

    d3 = -1;
    ret = 0;
    for (i = 0; i < D_80107908; i++)
    {
        d2 = 0x400000;
        for (j = 0; j < D_8012C470; j++)
        {
            if (j != arg0)
            {
                if (gPlayer[j].unk45 == 0)
                {
                    d1 = findDistance2D(D_8012F708[i].unk0 - gPlayer[j].xpos,
                                        D_8012F708[i].unk4 - gPlayer[j].ypos);

                    d2 = MIN(d2, d1);
                }
            }
        }
        if (d3 < d2)
        {
            d3 = d2;
            ret = i;
        }
    }
    return ret;
}

/*800627F8*/
static s32 func_800627F8(void)
{
    s32 num;
    code1UnkStruct3 *ptr;
    code1UnkStruct2 *ptr2;

    num = 1;
    ptr = &D_801CE5F0;
    if ((gMapNum < MAP_THE_END))
    {
        if ((gMapNum != MAP_MEAN_STREETS))
        {
            if (gMapNum == MAP_FALLOUT)
                num += (ptr->unkFD6 < 1);

            if (gMapNum == MAP_BRAINSTORM)
                num += (ptr->unkFD7 == 0);

            ptr2 = &ptr->unk4[gMapNum - num];
            return ptr2->unk0 == 0;
        }
    }
    return 1;
}

/*80062888*/
static void func_80062888(void)
{
    s16 i;

    for (i = 0; i < ARRAY_COUNT(D_801AE91E); i++)
        D_801AE91E[i] = 70;

    D_801AE91E[1] = 67;

    if (gMapNum == MAP_NUCLEAR_WINTER)
    {
        D_801AE91E[2] = 83;
        D_801AE91E[3] = 83;
        D_801AE91E[4] = 83;
        D_801AE91E[5] = 83;
    }
    if (gMapNum == MAP_BASE)
    {
        for (i = 1; i < ARRAY_COUNT(D_801AE91E); i++)
            D_801AE91E[i] = 83;
    }
}

INCLUDE_ASM("nonmatchings/src/code0/609D0", func_80062950);
