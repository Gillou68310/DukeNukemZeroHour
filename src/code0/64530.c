#include "common.h"
#include "code0/main.h"
#include "code0/audio.h"
#include "code0/engine.h"
#include "code0/37090.h"
#include "code0/41940.h"
#include "code0/6ACA0.h"
#include "code0/7BA50.h"
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
static void func_800642CC(s16 spritenum1, s16 spritenum2)
{
    s16 sectnum1, sectnum2;
    s16 i, unk18;
    s32 floorz, ceilz, z;
    u8 cond, cond2;

    cond = 0;
    z = gpSprite[spritenum1].unk1C;
    i = gpSprite[spritenum2].unk16;
    sectnum2 = gpSprite[spritenum1].sectnum;
    sectnum1 = gpSprite[i].sectnum;

    if ((gpSprite[spritenum1].statnum == 4) && (gpSprite[spritenum1].unk1E == 18))
    {
        if (z > 0)
            z += 1440;
        else
            z -= 1440;
    }

    if ((gpSprite[spritenum1].statnum != 1) || (D_8019B940[D_80106D50[spritenum1]].unk84 != 5))
    {
        unk18 = gpSector[sectnum2].unk18;
        if (unk18 == 1)
        {
            floorz = getFlorzOfSlope(sectnum2, gpSprite[spritenum1].x, gpSprite[spritenum1].y);
            if ((gpSprite[spritenum1].z + z) >= floorz)
            {
                if (gpSprite[spritenum1].statnum == unk18)
                    audio_800077F4(((krand() % 3) + 533), spritenum1);

                func_8008E3E0(gpSprite[spritenum1].x, gpSprite[spritenum1].y, floorz, sectnum2, 28, 0);
                if (krand() & 1)
                    func_8008E3E0(gpSprite[spritenum1].x, gpSprite[spritenum1].y, floorz, sectnum2, 3, 0);

                gpSprite[spritenum1].x += (gpSprite[i].x - gpSprite[spritenum2].x);
                gpSprite[spritenum1].y += (gpSprite[i].y - gpSprite[spritenum2].y);
                updateSector(gpSprite[spritenum1].x, gpSprite[spritenum1].y, &sectnum1);
                changeSpriteSect(spritenum1, sectnum1);
                gpSprite[spritenum1].z = getCeilzOfSlope(gpSprite[spritenum1].sectnum,
                                                         gpSprite[spritenum1].x, gpSprite[spritenum1].y) + 1024;
                cond = 1;
            }
        }
        else if (unk18 == 2)
        {
            ceilz = getCeilzOfSlope(sectnum2, gpSprite[spritenum1].x, gpSprite[spritenum1].y);
            if (ceilz >= (gpSprite[spritenum1].z + z))
            {
                if (krand() & 1)
                    func_8008E3E0(gpSprite[spritenum1].x, gpSprite[spritenum1].y, ceilz, sectnum2, 3, 0);

                gpSprite[spritenum1].x += (gpSprite[i].x - gpSprite[spritenum2].x);
                gpSprite[spritenum1].y += (gpSprite[i].y - gpSprite[spritenum2].y);
                updateSector(gpSprite[spritenum1].x, gpSprite[spritenum1].y, &sectnum1);
                changeSpriteSect(spritenum1, sectnum1);
                gpSprite[spritenum1].z = getFlorzOfSlope(gpSprite[spritenum1].sectnum,
                                                         gpSprite[spritenum1].x, gpSprite[spritenum1].y) - 1;
                cond = 1;
            }
        }
        else if (gpSprite[spritenum2].unk25 != 0)
        {
            cond2 = 0;
            if (gpSprite[spritenum2].cstat & 8)
                cond2 = gpSprite[spritenum1].z < gpSprite[spritenum2].z;
            else if (gpSprite[spritenum1].z > gpSprite[spritenum2].z)
                cond2 = 1;

            if (cond2)
            {
                if (gpSprite[spritenum1].statnum == 1)
                {
                    switch (D_8019B940[D_80106D50[spritenum1]].unk84)
                    {
                    case 1:
                    case 9:
                    case 17:
                        func_8004BD24(spritenum1);
                        return;
                    }
                }

                gpSprite[spritenum1].x += (gpSprite[i].x - gpSprite[spritenum2].x);
                gpSprite[spritenum1].y += (gpSprite[i].y - gpSprite[spritenum2].y);
                gpSprite[spritenum1].z += (gpSprite[i].z - gpSprite[spritenum2].z);
                updateSector(gpSprite[spritenum1].x, gpSprite[spritenum1].y, &sectnum1);
                changeSpriteSect(spritenum1, sectnum1);
                cond = 1;
            }
        }
        else
        {
            gpSprite[spritenum1].x = gpSprite[i].x;
            gpSprite[spritenum1].y = gpSprite[i].y;
            gpSprite[spritenum1].ang = gpSprite[i].ang;
            gpSprite[spritenum1].z += gpSprite[i].z - gpSprite[spritenum2].z;
            updateSector(gpSprite[spritenum1].x, gpSprite[spritenum1].y, &sectnum1);
            changeSpriteSect(spritenum1, sectnum1);
            func_8008E3E0(gpSprite[i].x, gpSprite[i].y, gpSprite[i].z, gpSprite[i].sectnum, 43, 0);
            audio_800077F4(704, i);
            cond = 1;
        }

        if (cond != 0)
        {
            if (gpSprite[spritenum1].statnum == 4)
            {
                if (gpSprite[spritenum1].unk1E == 18)
                    gpSprite[spritenum1].unk1A = func_8007AE50();

                if (gpSprite[spritenum1].unk1E == 21)
                    gpSprite[spritenum1].unk2A = func_8007AE50();
            }
        }
    }
}

/*80064AA0*/
void func_80064AA0(void)
{
    u8 cond1, cond2;
    s16 i, j, nextj;

    i = gHeadSpriteStat[9];
    while (i >= 0)
    {
        cond2 = 1;
        cond1 = (gpSector[gpSprite[i].sectnum].unk18 == 1) || (gpSector[gpSprite[i].sectnum].unk18 == 2);
        j = gHeadSpriteSect[gpSprite[i].sectnum];

        while (j >= 0)
        {
            nextj = gNextSpriteSect[j];
            switch (gpSprite[j].statnum)
            {
            case 10:
                cond2 = 0;
                if ((gpSprite[i].unk22 == 0) || cond1)
                    func_80063A40(gpSprite[j].unk16, i);
                break;

            case 1:
                cond2 = 0;
                if ((gpSprite[i].unk22 == 0) || cond1)
                    func_800642CC(j, i);
                break;

            case 4:
                cond2 = 0;
                if ((gpSprite[i].unk22 == 0) || cond1)
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

typedef struct {
    s16 unk0[8];
} _64530UnkStruct1;

static const _64530UnkStruct1 D_800E8954 = {1,2,20,21,22,53,59,65};

/*80068E9C*/
void func_80068E9C(void)
{
    _64530UnkStruct1 sp10;
    s16 i, j, k, l;
    s16 nexti;

    i = gHeadSpriteStat[106];
    while (i >= 0)
    {
        nexti = gNextSpriteStat[i];

        if (gpSprite[i].picnum == 8)
        {
            if (gpSprite[i].unk25 == 1)
            {
                gpSprite[i].unk18--;
                if (gpSprite[i].unk18 <= 0)
                {
                    if (gpSprite[i].cstat & 8)
                        func_8006B590(gpSprite[i].unk1E);
                    else
                        func_8006CB38(gpSprite[i].sectnum);

                    gpSprite[i].unk25 = 0;
                    gpSprite[i].unk2B = 1;
                }
            }
        }
        if (gpSprite[i].picnum == 9)
        {
            l = 0;
            sp10 = D_800E8954;
            for (j = 0; j < 8; j++)
            {
                k = gHeadSpriteStat[sp10.unk0[j]];
                while (k >= 0)
                {
                    if ((gpSprite[k].picnum >= 49) && (gpSprite[i].unk1E == gpSprite[k].unk20))
                        goto label1;
                    k = gNextSpriteStat[k];
                }
            }
            if (l == 0)
            {
                func_8006B590(gpSprite[i].unk20);
                deleteSprite(i);
            }
        }
    label1:
        i = nexti;
    }
}

/*80069160*/
void func_80069160(void)
{
    SpriteType *spr;
    s16 i, j, nexti;
    u8 cond;

    i = gHeadSpriteStat[105];
    while (i >= 0)
    {
        spr = &gpSprite[i];
        nexti = gNextSpriteStat[i];
        if (!(spr->cstat & 0x8000))
        {
            cond = 0;
            switch (spr->unk25)
            {
            case 0:
                for (j = 0; j < D_8012C470; j++)
                {
                    if (gPlayer[j].unk32 == spr->sectnum)
                    {
                        cond = 1;
                        break;
                    }
                }
                break;
            case 1:
                j = gHeadSpriteSect[spr->sectnum];
                while (j >= 0)
                {
                    if ((gpSprite[j].picnum == 2222) || (gpSprite[j].picnum == 2311))
                    {
                        cond = 1;
                        break;
                    }
                    j = gNextSpriteSect[j];
                }
                break;
            case 2:
                j = gHeadSpriteSect[spr->sectnum];
                while (j >= 0)
                {
                    if ((gpSprite[j].statnum == 1) &&
                        (gpSprite[j].picnum >= 49))
                    {
                        if ((D_8019B940[D_80106D50[j]].unk0 & 0x100000) == 0)
                        {
                            cond = 1;
                            break;
                        }
                    }
                    j = gNextSpriteSect[j];
                }
                break;
            case 3:
                for (j = 0; j < D_8012C470; j++)
                {
                    if ((gPlayer[j].unk32 == spr->sectnum) && (gPlayer[j].unk88[spr->ang]))
                    {
                        cond = 1;
                        break;
                    }
                }
                break;
            case 4:
                j = gHeadSpriteSect[spr->sectnum];
                while (j >= 0)
                {
                    if ((gpSprite[j].statnum == 1) && (gpSprite[j].picnum == 46))
                    {
                        cond = 1;
                        break;
                    }
                    j = gNextSpriteSect[j];
                }
                break;
            case 5:
                if (D_800DF585 == 0)
                {
                    for (j = 0; j < D_8012C470; j++)
                    {
                        if (gPlayer[j].unk32 == spr->sectnum)
                        {
                            cond = 1;
                            break;
                        }
                    }
                }
                else
                    deleteSprite(i);

                break;
            }

            if (cond != 0)
            {
                if (spr->unk24 == 0)
                {
                    if (spr->unk20 != 0)
                        func_8006B590(spr->unk20);
                    else
                        func_8006CB38(spr->sectnum);

                    spr->unk24 = 1;
                    if ((spr->unk1E > 0) && (--spr->unk1E == 0))
                        deleteSprite(i);
                }
            }
            else
                spr->unk24 = 0;
        }
        i = nexti;
    }

    i = gHeadSpriteStat[111];
    while (i >= 0)
    {
        nexti = gNextSpriteStat[i];
        if ((gpSprite[i].unk20 == 0) && (gpSprite[i].picnum == 29))
        {
            cond = 0;
            for (j = 0; j < D_8012C470; j++)
            {
                if (gPlayer[j].unk32 == gpSprite[i].sectnum)
                    cond = 1;
            }

            if (cond)
            {
                audio_80008574(0, gpSprite[i].unk1E);
                deleteSprite(i);
            }
        }
        i = nexti;
    }

    i = gHeadSpriteStat[122];
    while (i >= 0)
    {
        nexti = gNextSpriteStat[i];
        if (gPlayer[0].unk32 == gpSprite[i].sectnum)
        {
            if (gpSprite[i].unk24 == 0)
                func_800A419C(0, gpActionStrInfo[gpSprite[i].unk25]);

            if (gMapNum == MAP_BASE)
                gpSprite[i].unk24 = 1;
            else
                deleteSprite(i);
        }
        else
            gpSprite[i].unk24 = 0;

        i = nexti;
    }
}

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
        if (D_8010A940[playernum].unk2[6] == 0)
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

