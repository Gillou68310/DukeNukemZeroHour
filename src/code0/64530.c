#include "common.h"
#include "code0/audio.h"
#include "code0/engine.h"
#include "code0/37090.h"
#include "code0/41940.h"
#include "code0/8EFE0.h"
#include "code0/A06F0.h"
#include "code0/code0.h"

/*.text*/

/*80063930*/
static void func_80063930(s32 sectnum)
{
    s32 i, j;

    i = gHeadSpriteSect[sectnum];
    while (i >= 0)
    {
        if (gpSprite[i].picnum == 2)
        {
            j = gHeadSpriteStat[301];
            while (j >= 0)
            {
                if (gpSprite[j].unk20 == gpSprite[i].unk20)
                {
                    if (gpSprite[j].picnum == 2326)
                    {
                        audio_800077F4(222, j);
                        gpSprite[j].unk2B = 1;
                        return;
                    }
                }
                j = gNextSpriteStat[j];
            }
        }
        i = gNextSpriteSect[i];
    }
}

/*80063A40*/
STATIC void func_80063A40(s16, s16);
INCLUDE_ASM("nonmatchings/src/code0/64530", func_80063A40);

/*800642CC*/
STATIC void func_800642CC(s16, s16);
INCLUDE_ASM("nonmatchings/src/code0/64530", func_800642CC);

/*80064AA0*/
void func_80064AA0(void)
{
    u8 cond1, cond2;
    s16 i, j, nextj;

    i = gHeadSpriteStat[9];
    while (i >= 0)
    {
        cond2 = 1;
        cond1 = (u16)(gpSector[gpSprite[i].sectnum].unk18 - 1) < 2U;
        j = gHeadSpriteSect[gpSprite[i].sectnum];

        while (j >= 0)
        {
            nextj = gNextSpriteSect[j];
            switch (gpSprite[j].statnum)
            {
            case 10:
                cond2 = 0;
                if (((gpSprite[i].unk22 == 0) || cond1))
                    func_80063A40(gpSprite[j].unk16, i);
                break;

            case 1:
                cond2 = 0;
                if (((gpSprite[i].unk22 == 0) || cond1))
                    func_800642CC(j, i);
                break;

            case 4:
                cond2 = 0;
                if (((gpSprite[i].unk22 == 0) || cond1))
                    func_800642CC(j, i);
                break;
            }
            j = nextj;
        }

        if (gpSprite[i].unk22 != 0)
        {
            if (cond2)
                gpSprite[i].unk22--;
        }
        else if (!(cond2))
        {
            gpSprite[gpSprite[i].unk16].unk22 = 2;
        }
        if (cond1 == 0)
        {
            if (gpSprite[gpSprite[i].unk16].unk25 != 0)
                gpSprite[gpSprite[i].unk16].unk22 = 0;
        }
        i = gNextSpriteStat[i];
    }
}

/*80064D30*/
static void func_80064D30(s16 *arg0, s16 *arg1, s16 sectnum)
{
    s16 i;

    *arg0 = 2048;
    *arg1 = 32;
    i = gHeadSpriteSect[sectnum];

    while (i >= 0)
    {

        if (gpSprite[i].picnum == 10)
        {
            *arg0 = gpSprite[i].unk1E;
            *arg1 = gpSprite[i].unk20;
            if (*arg1 == 0)
                *arg1 = *arg0;

            break;
        }
        i = gNextSpriteSect[i];
    }
}

/*80064DE0*/
void func_80064DE0(SectorType *sec, u8 arg1, u8 arg2)
{
    s16 i;

    sec->unk27 = arg2;
    sec->unk23 = arg2;
    sec->unk26 = arg1;
    sec->unk22 = arg1;

    for (i = sec->wallptr; i < (sec->wallptr + sec->wallnum); i++)
    {
        gpWall[i].unk21 = arg2;
        gpWall[i].unk1C = arg1;
    }
}

/*80064E78*/
INCLUDE_ASM("nonmatchings/src/code0/64530", func_80064E78);

/*80068D74*/
static void func_80068D74(s16 sectnum)
{
    s16 i;

    i = gHeadSpriteSect[sectnum];
    while (i >= 0)
    {
        if (gpSprite[i].picnum == 1)
        {
            if (gpSprite[i].unk1E == 10)
                gpSprite[i].unk18 = gpSprite[i].unk1A;
        }
        i = gNextSpriteSect[i];
    }
}

/*80068E0C*/
void func_80068E0C(s16 sectnum)
{
    s16 i;

    i = gHeadSpriteSect[sectnum];
    while (i >= 0)
    {
        if (gpSprite[i].picnum == 1)
        {
            if (gpSprite[i].unk1E == 10)
                gpSprite[i].unk18 = 0;
        }
        i = gNextSpriteSect[i];
    }
}

INCLUDE_RODATA("nonmatchings/src/code0/64530", D_800E8954);
/*80068E9C*/
INCLUDE_ASM("nonmatchings/src/code0/64530", func_80068E9C);

/*80069160*/
INCLUDE_ASM("nonmatchings/src/code0/64530", func_80069160);

/*800697D8*/
static void func_800697D8(s16 playernum, s16 arg1, s16 arg2)
{
    u8 i;

    i = 0;
    switch (arg2)
    {
    case 0:
        i = 1;
        break;
    case 1:
        if (D_8010A940[playernum].unkA[3] != 0)
            D_8010A940[playernum].unkA[3] = CLAMP_MIN((D_8010A940[playernum].unkA[3] - arg1), 0);
        else
            i = 1;
        break;
    case 2:
        if (D_8010A940[playernum].unk8 == 0)
            i = 1;
        break;
    }

    if (i != 0)
        func_8003671C(playernum, arg1, -1, -1);
}

/*800698E8*/
INCLUDE_ASM("nonmatchings/src/code0/64530", func_800698E8);

/*80069E50*/
void func_80069E50(void)
{
    s16 i, nexti;

    i = gHeadSpriteStat[131];
    while (i >= 0)
    {
        nexti = gNextSpriteStat[i];
        if (MusHandleAsk(D_8013B2D0[i].handle) == 0)
        {
            switch (gpSprite[i].picnum)
            {
            case 2244:
            case 2247:
            case 2305:
            case 2308:
                gpSprite[i].picnum = 2250;
                break;

            case 2452:
            case 2453:
            case 2454:
            case 2455:
            case 2456:
                gpSprite[i].picnum = 2451;
                break;

            case 2457:
            case 2458:
            case 2459:
            case 2460:
            case 2461:
                gpSprite[i].picnum = 2462;
                break;

            default:
                gpSprite[i].picnum = 2249;
                break;
            }

            changeSpriteStat(i, 0);
            func_800A419C(0, "BABE SAVED!");
            func_800533C4(gpSprite[i].picnum, i);
            D_801A1958.babes_saved++;
            audio_800077F4(704, i);
            func_8008E3E0(gpSprite[i].x, gpSprite[i].y, gpSprite[i].z, gpSprite[i].sectnum, 43, 0);
            func_80036520(0, 10);
        }
        i = nexti;
    }
}

