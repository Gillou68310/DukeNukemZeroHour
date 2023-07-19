#include "common.h"
#include "code0/audio.h"
#include "code0/pragmas.h"
#include "code0/4600.h"
#include "code0/1E7A0.h"
#include "code0/37090.h"
#include "code0/41940.h"
#include "code0/59D40.h"
#include "code0/64530.h"
#include "code0/6ACA0.h"
#include "code0/7A430.h"
#include "code0/8E670.h"
#include "code0/8EFE0.h"
#include "code0/A06F0.h"
#include "code0/code0.h"
#include "code1/EB300.h"
#include "static/mapinfo.h"

typedef void (*_6ACA0UnkFuncPointer)(s32 spritenum);

/*Skip following declaration so it defaults to s32*/
/*#include "code0/87010.h"*/
/*void func_80087174(s16 spritenum, s32 x1, s32 y1, s32 z1, s32 x2, s32 y2, s32 z2, s16, u8);*/
void func_800867CC(s16 spritenum, s32 x1, s32 y1, s32 z1, s32 x2, s32 y2, s32 z2, s16, u8);

/*.data*/
/*800DF2F0*/ EXTERN_DATA u8 D_800DF2F0;
/*800DF2F4*/ EXTERN_DATA s8 D_800DF2F4[657];
/*800DF585*/ EXTERN_DATA u8 D_800DF585;
/*800DF590*/ EXTERN_DATA STATIC u8 D_800DF590;
/*800DF591*/ EXTERN_DATA STATIC u8 D_800DF591;
/*800DF5A0*/ EXTERN_DATA STATIC _6ACA0UnkFuncPointer D_800DF5A0[50];
/*800DF668*/ EXTERN_DATA STATIC _6ACA0UnkFuncPointer D_800DF668[4];

/*.text*/
static void func_8006CA90(s16 arg0);
static void func_8006B384(s32 spritenum);
static void func_8007963C(s32 spritenum, s32);

/*8006A0A0*/
INCLUDE_ASM("nonmatchings/src/code0/6ACA0", func_8006A0A0);

/*8006AD70*/
static void func_8006AD70(s16 spritenum)
{
    SectorType *sec;
    SpriteType *spr;
    s16 i;

    spr = &gpSprite[spritenum];
    sec = &gpSector[spr->sectnum];
    if (!(spr->cstat & 0x8000))
    {
        switch (spr->unk1E)
        {
        case 12:
            spr->unk2B = 1;
            spr->clipdist = !spr->clipdist;
            break;
        case 13:
            if (spr->unk25 == 0)
                spr->unk25 = 1;
            break;
        case 30:
        case 40:
        case 41:
        case 42:
        case 43:
        case 44:
        case 45:
            spr->unk2B = 1;
            break;
        case 46:
            spr->unk2B = 1;
            i = gHeadSpriteSect[spr->sectnum];
            while (i>=0)
            {
                if ((gpSprite[i].picnum >= 2548) && (gpSprite[i].picnum < 2552))
                    changeSpriteStat(i, 120);
                i = gNextSpriteSect[i];
            }
            D_801A19F0 = playSfx(1599);
            break;
        case 50:
            if (D_800DF2F0 != 0)
            {
                if ((spr->unk1C > 0) || ((spr->unk1C >= 0) && (sec->floorz == sec->ceilingz)))
                    spr->unk1C = -1;
                else
                    spr->unk1C = 1;
            }
            else if (spr->unk1C == 0)
            {

                if (sec->floorz == sec->ceilingz)
                {
                    if (D_800DF591 == 0)
                        spr->unk1C = -1;
                    else
                        break;
                }
                else if (sec->floorz != sec->ceilingz)
                {
                    if (D_800DF590 == 0)
                        spr->unk1C = 1;
                    else
                        break;
                }
                func_80068E0C(spr->sectnum);
            }
            break;
        case 51:
        case 52:
            if (D_800DF2F0 != 0)
            {
                if ((spr->unk1C <= 0) && ((spr->unk1C < 0) || (sec->floorz == sec->ceilingz)))
                    spr->unk1C = 1;
                else
                    spr->unk1C = -1;
            }
            else if (spr->unk1C == 0)
            {
                if (sec->floorz == sec->ceilingz)
                {
                    if (D_800DF591 == 0)
                        spr->unk1C = 1;
                    else
                        break;
                }
                else if (sec->floorz != sec->ceilingz)
                {
                    if (D_800DF590 == 0)
                        spr->unk1C = -1;
                    else
                        break;
                }
                func_80068E0C(spr->sectnum);
            }
            break;
        case 53:
            if (D_800DF2F0 != 0)
            {
                if (spr->unk18 <= 0)
                {
                    if (spr->unk18 < 0)
                        spr->unk18 = -1;
                }
                else
                    spr->unk18 = 1;
            }
            else if (spr->unk18 == 0)
            {
                if (spr->unk25 == 0)
                {
                    if (D_800DF591 == 0)
                        spr->unk18 = spr->unk1C;
                    else
                        break;
                }
                else
                {
                    if (D_800DF590 == 0)
                        spr->unk18 = -spr->unk1C;
                    else
                        break;
                }
                func_80068E0C(spr->sectnum);
            }
            break;
        case 54:
            if (D_800DF2F0 != 0)
            {
                if (spr->unk18 > 0)
                {
                    spr->unk18 = -1;
                    spr->unk25 = !spr->unk25;
                }
                else if (spr->unk18 < 0)
                {
                    spr->unk18 = 1;
                    spr->unk25 = !spr->unk25;
                }
                else if (spr->unk25 != 0)
                    spr->unk18 = -1;
                else
                    spr->unk18 = 1;
            }
            else if (spr->unk18 == 0)
            {
                if (spr->unk25 != 0)
                {
                    if (D_800DF590 == 0)
                        spr->unk18 = -1;
                    else
                        break;
                }
                else
                {
                    if (D_800DF591 == 0)
                        spr->unk18 = 1;
                    else
                        break;
                }
                func_80068E0C(spr->sectnum);
            }
            break;
        case 60:
            spr->unk2B = 1;
            break;
        case 61:
            D_800BD61A = spr->unk25 * 30;
            func_8001F7B4(D_800BD61A, spr->unk24);
            break;
        case 24:
            spr->unk2B = !spr->unk2B;
            break;
        }
    }
}

/*8006B170*/
s8 func_8006B170(s16 arg0)
{
    s16 i;
    s8 ret;

    i = gHeadSpriteStat[3];
    ret = -1;
    while (i >= 0)
    {
        if (gpSprite[i].unk20 == arg0)
        {
            switch (gpSprite[i].unk1E)
            {
            case 50:
            case 51:
            case 52:
                if (gpSector[gpSprite[i].sectnum].floorz != gpSector[gpSprite[i].sectnum].ceilingz)
                    return 0;
                else
                    ret = 1;
                break;

            case 53:
            case 54:
                if (gpSprite[i].unk25 != 0)
                    return 0;
                else
                    ret = 1;
                break;
            }
        }
        i = gNextSpriteStat[i];
    }
    return ret;
}

/*8006B278*/
static void func_8006B278(s16 spritenum)
{

    if (gpSprite[spritenum].picnum == 2290)
    {
        if (gpSprite[spritenum].unk25 == 0)
        {
            changeSpriteStat(spritenum, 55);
            return;
        }
    }
    changeSpriteStat(spritenum, 1);
    func_8006B384(spritenum);
    if (gpSprite[spritenum].picnum >= 49)
    {
        gpSprite[spritenum].cstat &= ~0x8000;
        gpSprite[spritenum].cstat |= 0x101;
    }
    if (gpSprite[spritenum].picnum == 2581)
    {
        gpSprite[spritenum].cstat |= 0x8000;
        gpSprite[spritenum].xrepeat = 0;
        gpSprite[spritenum].yrepeat = 0;
    }
}

/*8006B384*/
static void func_8006B384(s32 spritenum)
{
    s32 i, x, y;
    s32 ret;
    u16 num;

    num = gpSprite[spritenum].picnum - 1293;
    if (num >= 2)
    {
        x = gpSprite[spritenum].x;
        y = gpSprite[spritenum].y;
        x &= ~0x1F;
        y &= ~0x1F;
        i = gHeadSpriteStat[24];
        while (i >= 0)
        {
            if ((x == (gpSprite[i].x & ~0x1F)) && (y == (gpSprite[i].y & ~0x1F)))
                break;
            i = gNextSpriteStat[i];

        }
        if (i != -1)
        {
            D_8019B940[D_80106D50[spritenum]].unk64 = D_800FF528[D_8019B940[D_80106D50[spritenum]].unk84];
            D_8019B940[D_80106D50[spritenum]].unk4 |= 0x40;
            gpSprite[spritenum].unk16 = i;
        }
    }
}

/*8006B4E4*/
void func_8006B4E4(s16 arg0)
{
    func_800A419C(0, "OBJECTIVE COMPLETED");
    D_801AE91E[arg0] = 68;

    if (D_801AE91E[arg0+1] == 70)
        D_801AE91E[arg0+1] = 67;

    if ((gMapNum == MAP_NUCLEAR_WINTER) && (arg0 == 1))
    {
        D_801AE91E[2] = 67;
        D_801AE91E[3] = 67;
        D_801AE91E[4] = 67;
    }
}

/*8006B590*/
void func_8006B590(s16 arg0)
{
    code0UnkStruct3 *ptr;
    s16 i, j, k, l;
    s16 nexti;
    u8 cond;

    cond = 0;
    if (arg0 != 0)
    {
        func_8006CA90(arg0);
        i = gHeadSpriteStat[3];
        while (i >= 0)
        {
            if (gpSprite[i].unk20 == arg0)
                func_8006AD70(i);

            i = gNextSpriteStat[i];
        }

        i = gHeadSpriteStat[1];
        while (i >= 0)
        {
            nexti = gNextSpriteStat[i];
            if (gpSprite[i].unk20 == arg0)
                D_8019B940[D_80106D50[i]].unk0 |= 0x400000;

            if ((gpSprite[i].unk1E == arg0) &&
                ((gpSprite[i].picnum == 2219) || (gpSprite[i].picnum == 2220) ||
                    (gpSprite[i].picnum == 1299) || (gpSprite[i].picnum == 1300)))
            {
                if (gpSprite[i].unk25 == 1)
                {
                    changeSpriteStat(i, 72);
                    cond = 1;
                }
            }
            i = nexti;
        }

        i = gHeadSpriteStat[2];
        while (i >= 0)
        {
            nexti = gNextSpriteStat[i];
            if (((gpSprite[i].picnum == 2219) || (gpSprite[i].picnum == 2220) ||
                (gpSprite[i].picnum == 1299) || (gpSprite[i].picnum == 1300)) &&
                 (gpSprite[i].unk1E == arg0))
            {
                if (gpSprite[i].unk25 == 1)
                {
                    ptr = &D_8019B940[D_80106D50[i]];
                    if (ptr->unk70 != 0)
                    {
                        MusHandleStop(ptr->unk70, 0);
                        ptr->unk70 = 0;
                    }

                    if (ptr->unk6C != 0)
                    {
                        MusHandleStop(ptr->unk6C, 0);
                        ptr->unk6C = 0;
                    }
                    changeSpriteStat(i, 72);
                    cond = 1;
                }
            }
            i = nexti;
        }

        if (cond == 0)
        {
            i = gHeadSpriteStat[0];
            while (i >= 0)
            {
                nexti = gNextSpriteStat[i];
                if ((gpSprite[i].picnum == 2219) || (gpSprite[i].picnum == 2220) ||
                     (gpSprite[i].picnum == 1299) || (gpSprite[i].picnum == 1300))
                {
                    if ((gpSprite[i].unk1E == arg0) && (gpSprite[i].unk25 == 1))
                    {
                        changeSpriteStat(i, 1);
                        cond = 2;
                    }
                }
                i = nexti;
            }
        }

        if (cond == 1)
            func_800A419C(0, "DEFENSE SYSTEMS INACTIVE");
        if (cond == 2)
            func_800A419C(0, "DEFENSE SYSTEMS ACTIVE");

        i = gHeadSpriteStat[4];
        while (i >= 0)
        {
            nexti = gNextSpriteStat[i];
            if ((gpSprite[i].unk20 == arg0) && (gpSprite[i].picnum == 1841) && (gpSprite[i].unk2B == 0xFF))
                gpSprite[i].unk2B = 0;

            i = nexti;
        }

        i = gHeadSpriteStat[20];
        while (i >= 0)
        {
            nexti = gNextSpriteStat[i];
            if (gpSprite[i].unk20 == arg0)
                func_8006B278(i);
            i = nexti;
        }

        i = gHeadSpriteStat[21];
        while (i >= 0)
        {
            nexti = gNextSpriteStat[i];
            if (gpSprite[i].unk20 == arg0)
                func_8004EA40(i);

            i = nexti;
        }

        i = gHeadSpriteStat[152];
        while (i >= 0)
        {
            nexti = gNextSpriteStat[i];
            if (gpSprite[i].unk20 == arg0)
            {
                if (gpSprite[i].unk25 != 0)
                {
                    func_8008E3E0(gpSprite[i].x, gpSprite[i].y, gpSprite[i].z,
                                  gpSprite[i].sectnum, 79, 21);

                    audio_800077F4(840, i);
                }

                gpSprite[i].cstat &= ~0x8101;
                changeSpriteStat(i, 150);
                gpSprite[i].unk18 = -1;
                if (gpSprite[i].picnum == 1916)
                {
                    j = func_8008E3E0(gpSprite[i].x, gpSprite[i].y,
                                      (gpSprite[i].z - 4800), gpSprite[i].sectnum, 57, 0);
                    if (j >= 0)
                        gpSprite[j].unk22 = i;
                }
            }
            i = nexti;
        }

        i = gHeadSpriteStat[112];
        while (i >= 0)
        {
            nexti = gNextSpriteStat[i];
            if (gpSprite[i].unk20 == arg0)
                changeSpriteStat(i, 57);

            i = nexti;
        }

        i = gHeadSpriteStat[301];
        while (i >= 0)
        {
            nexti = gNextSpriteStat[i];
            if (gpSprite[i].unk20 == arg0)
            {
                if ((gpSprite[i].picnum == 2326))
                {
                    if (gpSprite[i].unk25 & 0x10)
                        gpSprite[i].unk25 &= ~0x10;
                    else if (gpSprite[i].unk2B == 0)
                        gpSprite[i].unk2B = 1;
                }
                else if (gpSprite[i].unk2B == 0)
                    gpSprite[i].unk2B = 1;
            }
            i = nexti;
        }

        i = gHeadSpriteStat[302];
        while (i >= 0)
        {
            nexti = gNextSpriteStat[i];
            if (gpSprite[i].unk20 == arg0)
            {
                switch (gpSprite[i].picnum)
                {
                case 2341:
                    gpSprite[i].unk2B++;
                    break;

                case 2002:
                case 2005:
                    if ((gpSprite[i].unk25 & 0x7F) == 3)
                        gpSprite[i].unk2B = 10;
                    break;

                default:
                    if (gpSprite[i].unk2B == 0)
                        gpSprite[i].unk2B = 1;
                    break;
                }
            }
            i = nexti;
        }

        i = gHeadSpriteStat[303];
        while (i >= 0)
        {
            nexti = gNextSpriteStat[i];
            if (gpSprite[i].unk20 == arg0)
                gpSprite[i].unk25 ^= 1;

            i = nexti;
        }

        i = gHeadSpriteStat[305];
        while (i >= 0)
        {
            nexti = gNextSpriteStat[i];
            if ((gpSprite[i].unk20 == arg0) && (gpSprite[i].picnum == 1307) && (gpSprite[i].unk2B == 0))
                gpSprite[i].unk2B = 1;

            i = nexti;
        }

        i = gHeadSpriteStat[667];
        while (i >= 0)
        {
            nexti = gNextSpriteStat[i];
            if (gpSprite[i].unk20 == arg0)
            {
                gpSprite[i].cstat &= ~0x8000;
                changeSpriteStat(i, 666);
            }
            i = nexti;
        }

        i = gHeadSpriteStat[116];
        while (i >= 0)
        {
            nexti = gNextSpriteStat[i];
            if (gpSprite[i].unk20 == arg0)
            {
                j = D_800DEE80;
                func_8005E4C4(-1, 1);
                gPlayer->unk52 = i + 0x1000;
                D_800DEE80 = j;
                D_800DEE70 = gpSprite[i].unk1E;
                changeSpriteStat(i, 0);
            }
            i = nexti;
        }

        i = gHeadSpriteStat[118];
        while (i >= 0)
        {
            nexti = gNextSpriteStat[i];
            if (gpSprite[i].unk20 == arg0)
            {
                func_8008E01C(30, 1);
                if (gpSprite[i].unk25 != 0)
                    D_800FEA90 = 1;

                changeSpriteStat(i, 0);
            }
            i = nexti;
        }

        if ((gMapNum == MAP_BASE) && (arg0 == 1301))
            D_800E192C = D_801A1958.unkC;

        if (gMapNum == MAP_UNDER_SIEGE)
        {
            if (arg0 == 1931)
            {
                D_800E192C = -1;
                D_80138678 = D_801A1958.unkC;
            }

            if (arg0 == 1221)
                D_80138678 = -1;
        }

        if ((gMapNum == MAP_THE_WHITECHAPEL_KILLINGS) && (arg0 == 4000))
            D_800DEEBC = D_8012FD88;

        if ((gMapNum == MAP_THE_WHITECHAPEL_KILLINGS) && (arg0 == 4070))
            D_800DEEBC = -1;

        i = gHeadSpriteStat[117];
        while (i >= 0)
        {
            nexti = gNextSpriteStat[i];
            if (gpSprite[i].unk20 == arg0)
            {
                switch (gpSprite[i].unk25)
                {
                case 0:
                    func_8006B4E4(gpSprite[i].unk1E);
                    deleteSprite(i);
                    break;

                case 1:
                    k = -1;
                    for (j = 1; j < 8; j++)
                    {
                        if (D_801AE91E[j] != 0x44)
                        {
                            if (D_801AE91E[j] == 0x43)
                                k = j;

                            D_801AE91E[j] = 0x53;
                        }
                    }

                    if (D_801AE91E[gpSprite[i].unk1E] != 68)
                    {
                        if (gMapNum == MAP_BASE)
                        {
                            if (gpSprite[i].unk1E == 1)
                            {
                                D_800E192C = -1;
                                D_80138678 = D_801A1958.unkC;
                                playSfx(554);
                            }
                        }

                        if (gpSprite[i].unk1E != k)
                            func_800A419C(0, "NEW OBJECTIVE");
                        D_801AE91E[gpSprite[i].unk1E] = 67;
                    }
                    break;

                case 2:
                    for (j = 1; j < 8; j++)
                    {
                        if (D_801AE91E[j] != 68)
                            D_801AE91E[j] = 83;
                    }

                    D_80138678 = -1;
                    D_800E192C = -1;
                    if (gMapNum == MAP_NUCLEAR_WINTER)
                    {
                        func_800A419C(0, "NEW OBJECTIVE");
                        D_801AE91E[2] = 67;
                        D_801AE91E[3] = 67;
                        D_801AE91E[4] = 67;
                        deleteSprite(i);
                    }
                }
            }
            i = nexti;
        }

        i = gHeadSpriteStat[106];
        while (i >= 0)
        {
            nexti = gNextSpriteStat[i];
            if (gpSprite[i].unk20 == arg0)
            {
                switch (gpSprite[i].picnum)
                {
                case 2:
                    func_8006CB38(gpSprite[i].sectnum);
                    break;

                case 4:
                    gpSprite[i].unk25 = gpSprite[i].unk25 == 0;
                    l = gHeadSpriteSect[gpSprite[i].sectnum];
                    while (l >= 0)
                    {
                        if ((gpSprite[l].picnum == 1) || (gpSprite[l].picnum == 3) || (gpSprite[l].picnum == 28))
                            gpSprite[l].cstat ^= 0x8000;

                        l = gNextSpriteSect[l];
                    }
                    break;

                case 8:
                    gpSprite[i].unk25 = 1;
                    gpSprite[i].unk18 = gpSprite[i].unk1A;
                    break;
                }
            }
            i = nexti;
        }

        i = gHeadSpriteStat[50];
        while (i >= 0)
        {
            nexti = gNextSpriteStat[i];
            if ((gpSprite[i].unk20 == arg0) && (gpSprite[i].unk16 == 52))
            {
                if (!(gpSprite[i].cstat & 4))
                {
                    func_8008E3E0(gpSprite[i].x, gpSprite[i].y, gpSprite[i].z, gpSprite[i].sectnum, 80, 33);
                    func_8008E3E0(gpSprite[i].x, gpSprite[i].y, gpSprite[i].z, gpSprite[i].sectnum, 68, 33);
                    func_8001F7B4(120, 15);
                }
                else
                    func_8008E3E0(gpSprite[i].x, gpSprite[i].y, gpSprite[i].z,
                                  gpSprite[i].sectnum, 79, gpSprite[i].unk25);

                deleteSprite(i);
            }
            i = nexti;
        }

        i = gHeadSpriteStat[120];
        while (i >= 0)
        {
            nexti = gNextSpriteStat[i];
            if ((gpSprite[i].unk20 == arg0) && (gpSprite[i].picnum >= 2520) && (gpSprite[i].picnum < 2530))
                changeSpriteStat(i, 0);

            i = nexti;
        }

        l = 0;
        for (i = 0; i < 32; i++)
        {
            if (gTimeMachinePart & (1<<i))
                l++;
        }

        if (l == 13)
        {
            i = gHeadSpriteStat[123];
            while (i >= 0)
            {
                nexti = gNextSpriteStat[i];
                if (gpSprite[i].unk20 == arg0)
                {
                    switch (gpSprite[i].picnum)
                    {
                    case 1417:
                        D_800DEEE4[0] = 1;
                        gpSprite[i].cstat = 0x1101;
                        break;

                    case 5772:
                        func_8008E3E0(gpSprite[i].x, gpSprite[i].y, gpSprite[i].z,
                                      gpSprite[i].sectnum, 52, gpSprite[i].unk25);

                        changeSpriteStat(i, 118);
                        gpSprite[i].unk25 = 1;
                        gpSprite[i].unk20 = 0;
                        break;
                    }
                }
                i = nexti;
            }
        }

        for (i = 0; i < gNumWalls; i++)
        {
            if (gpWall[i].unk16 == arg0)
            {
                if (gpWall[i].unk14 == 40)
                {
                    if (gpWall[i].cstat & 0x10)
                    {
                        gpWall[i].cstat &= ~0x51;
                        gpWall[gpWall[i].nextwall].cstat &= ~0x51;
                    }
                    else
                    {
                        gpWall[i].cstat |= 0x51;
                        gpWall[gpWall[i].nextwall].cstat |= 0x51;
                    }
                }
            }
        }
    }
}

/*8006C9AC*/
static void func_8006C9AC(s16 spritenum)
{
    if ((D_800DF2F0 == 0) && ((gpSprite[spritenum].cstat & 0x8000) == 0))
    {
        switch (gpSprite[spritenum].picnum)
        {
        case 28:
            MusHandleStop(D_8013B2D0[spritenum].handle, 0);
            D_8013B2D0[spritenum].handle = audio_80007820(gpSprite[spritenum].unk1E, spritenum);
            break;
        case 29:
            audio_80008574(0, gpSprite[spritenum].unk1E);
            deleteSprite(spritenum);
            break;
        }
    }
}

/*8006CA90*/
static void func_8006CA90(s16 arg0)
{
    s16 i, nexti;

    if (D_800DF2F0 == 0)
    {
        i = gHeadSpriteStat[111];
        while (i >= 0)
        {
            nexti = gNextSpriteStat[i];
            if (gpSprite[i].unk20 == arg0)
                func_8006C9AC(i);
            i = nexti;
        }
    }
}

/*8006CB38*/
void func_8006CB38(s16 sectnum)
{
    s16 i, nexti;

    i = gHeadSpriteSect[sectnum];
    while (i >= 0)
    {
        nexti = gNextSpriteSect[i];
        switch (gpSprite[i].statnum)
        {
        case 3:
            func_8006AD70(i);
            break;

        case 20:
            func_8006B278(i);
            break;

        case 21:
            func_8004EA40(i);
            break;

        case 110:
            gpSprite[i].unk24 = gpSprite[i].unk24 == 0;
            break;

        case 111:
            func_8006C9AC(i);
            break;

        case 667:
            gpSprite[i].cstat &= 0x7FFF;
            changeSpriteStat(i, 666);
            break;

        case 302:
            gpSprite[i].unk2B = 1;
            break;

        case 303:
            gpSprite[i].unk25 ^= 1;
            break;

        }
        i = nexti;
    }
}

/*8006CCCC*/
void func_8006CCCC(s32 spritenum)
{
    if (gpSprite[spritenum].unk18 == 1)
    {
        if (gpSprite[spritenum].unk1A > 0)
        {
            gpSprite[spritenum].unk1A--;
            if ((gpSprite[spritenum].unk1A) <= 0)
            {
                gpSprite[spritenum].picnum--;
                gpSprite[spritenum].unk2B = 0;
            }
        }
    }
}

/*8006CD38*/
static void func_8006CD38(s16 playernum)
{
    s16 i;

    i = gHeadSpriteStat[4];
    while (i >= 0)
    {
        if (gpSprite[i].unk1E == 10)
        {
            if (gPlayer[playernum].unk4A == gpSprite[i].unk20)
                gpSprite[i].unk22 = 1;
        }
        i = gNextSpriteStat[i];

    }
}

/*8006CDE0*/
static s32 func_8006CDE0(s16 playernum, s32 *arg1, s32 *arg2, s32 *arg3)
{
    SpriteType *spr;
    s32 x1, y1, z1;
    s32 sectnum;
    s32 i, j, nexti;
    s16 ang;
    s32 delta;

    *arg1 = -1;
    *arg2 = -1;
    *arg3 = -1;
    i = gHeadSpriteStat[1];
    x1 = gpSprite[gPlayer[playernum].unk4A].x;
    y1 = gpSprite[gPlayer[playernum].unk4A].y;
    z1 = gpSprite[gPlayer[playernum].unk4A].z;
    j = 0;
    sectnum = gpSprite[gPlayer[playernum].unk4A].sectnum;
    while (i >= 0)
    {
        nexti = gNextSpriteStat[i];
        spr = &gpSprite[i];
        if (func_8004D7D8(i) != 0)
        {
            ang = getAngle(spr->x - x1, spr->y - y1);
            delta = getAngleDelta(ang, gPlayer[playernum].unk38);
            if (((delta > 0) && (getAngleDelta(ang, gPlayer[playernum].unk38)) < 384) ||
                ((delta <= 0) && (-getAngleDelta(ang, gPlayer[playernum].unk38) < 384)))
            {
                if (canSee(x1, y1, z1, sectnum, spr->x, spr->y, spr->z, spr->sectnum) != 0)
                {
                    switch (j)
                    {
                    case 0:
                        *arg1 = i;
                        j = 1;
                        break;
                    case 1:
                        *arg2 = i;
                        j = 2;
                        break;
                    case 2:
                        *arg3 = i;
                        j = 3;
                        break;
                    }
                }
            }
        }
        if (j == 3)
            break;

        i = nexti;
    }
    if ((*arg1 == -1) && (*arg2 == -1) && (*arg3 == -1))
    {
        if (playernum < 0)
        {
            *arg1 = gPlayer[0].unk4A;
            *arg2 = gPlayer[0].unk4A;
            *arg3 = gPlayer[0].unk4A;
            return 1;
        }
        else
            return -1;
    }
    else if (*arg2 == -1)
    {
        *arg2 = *arg1;
        *arg3 = *arg1;
        return 1;
    }
    else if (*arg3 == -1)
    {
        *arg3 = *arg1;
        return 1;
    }

    return 1;
}

/*8006D0E4*/
void func_8006D0E4(s16 playernum)
{
    s16 i;
    for (i = 0; i < ARRAY_COUNT(D_8011A680[playernum]); i++)
        Bmemset(&D_8011A680[playernum][i], 0, 20);

    func_8007AD30();
}

/*8006D180*/
static u8 func_8006D180(SpriteType *spr)
{
    if ((gpSector[spr->sectnum].unk18 == 2) ||
        ((gpSector[spr->sectnum].unk18 == 3) &&
            (func_80036490(spr->sectnum) < spr->z)))
    {
        return 1;
    }
    else
        return 0;
}

/*8006D1F4*/
static void func_8006D1F4(SpriteType *spr, s32 x, s32 y, s32 z, s32 arg4, s32 arg5, s32 arg6)
{
    f32 f1, f2, f3, f4, f5, f6;
    s32 dist;
    s32 z_;

    if (func_8006D180(spr))
    {
        spr->unk18 = 0;
        spr->unk1C = 0;
    }
    else
    {
        z_ = z - spr->z;
        dist = findDistance2D(x - spr->x, y - spr->y);
        spr->ang = getAngle(x - spr->x, y - spr->y);
        f1 = arg4;
        f2 = arg6;
        f3 = (f1 * dist) / f2;

        if (f1 < f3)
            f3 = f1;

        f4 = (dist * 8) / f3;
        f5 = (z_ / f3) - ((arg5 * f3) / 2.0f);
        f6 = sqrtf((f4 * f4) + (f5 * f5));

        if (f2 < f6)
        {
            f6 = f2 / f6;
            spr->unk18 = (f4 * f6);
            spr->unk1C = (f5 * f6);
        }
        else
        {
            spr->unk18 = f4;
            spr->unk1C = f5;
        }
    }
}

/*8006D3B8*/
s32 func_8006D3B8(s32, s32, s32, s32, s32);
INCLUDE_ASM("nonmatchings/src/code0/6ACA0", func_8006D3B8);

/*800720FC*/
s32 func_800720FC(s16 spritenum)
{
    s16 hitsect, hitwall, hitsprite;
    s32 hitx, hity, hitz;
    SpriteType *spr;
    u16 cstat;

    spr = &gpSprite[spritenum];
    cstat = spr->cstat;
    spr->cstat = cstat & ~0x101;

    hitScan(spr->x,
        spr->y,
        spr->z,
        spr->sectnum,
        gpSinTable[(spr->ang + 512) & 0x7FF],
        gpSinTable[spr->ang & 0x7FF], 0,
        &hitsect, &hitwall, &hitsprite, &hitx, &hity, &hitz, 0x10001);

    spr->cstat = cstat;
    if ((hitwall == -1) && (hitsprite != -1))
    {
        if ((gpSprite[hitsprite].statnum == 1) ||
            (gpSprite[hitsprite].statnum == 51) ||
            (gpSprite[hitsprite].statnum == 52) ||
            (gpSprite[hitsprite].statnum == 10) ||
            (gpSprite[hitsprite].statnum == 305))
        {

            if (spr->picnum == 1844)
                func_80047820(spritenum, hitsprite, 50);
            return 1;
        }
    }
    return 0;
}

/*800722A0*/
static u8 func_800722A0(s16 spritenum)
{
    s16 i, nexti;

    i = gHeadSpriteStat[58];
    while (i >= 0)
    {
        nexti = gNextSpriteStat[i];
        if ((klabs_(gpSprite[i].x - gpSprite[spritenum].x) + klabs_(gpSprite[i].y - gpSprite[spritenum].y)) < 500)
        {
            func_8004CC90(i, gpSprite[spritenum].unk1E, gpSprite[spritenum].picnum);
            return 1;
        }
        i = nexti;
    }
    return 0;
}

/*800723BC*/
static s16 func_800723BC(s16 spritenum)
{
    s16 i, nexti;

    i = gHeadSpriteStat[58];
    while (i>=0)
    {
        nexti = gNextSpriteStat[i];
        if ((klabs_(gpSprite[i].x - gpSprite[spritenum].x) + klabs_(gpSprite[i].y - gpSprite[spritenum].y)) < 0x7D00)
            return i;

        i = nexti;
    }
    return -1;
}

/*800724B4*/
void func_800724B4(s32 spritenum)
{
    s32 ceilz, ceilhit, florz, florhit;
    SpriteType *spr;
    s16 ang, diff, z;
    s32 i, num, ang2;
    s16 cstat, cstat2;

    spr = &gpSprite[spritenum];
    z = spr->z;

    num = func_8004E5F8(spritenum,
                        (spr->unk18 * gpSinTable[(spr->ang + 512) & 0x7FF]) >> 14,
                        (spr->unk18 * gpSinTable[spr->ang & 0x7FF]) >> 14,
                        spr->unk1C);

    D_8013B2D0[spritenum].handle = audio_8000784C(D_8013B2D0[spritenum].handle, spritenum);

    if (spr->sectnum == -1)
    {
        MusHandleStop(D_8013B2D0[spritenum].handle, 0);
        deleteSprite(spritenum);
        return;
    }

    if (!(D_8012FD88 & 3))
    {
        if (D_8012C470 == 1)
        {
            for (i = 0; i < 3; i++)
                func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 76, 0);
        }
    }

    D_8013B2D0[spritenum].unk2 = (D_8013B2D0[spritenum].unk2 + spr->unk2B) & 0x7FF;
    D_8013B2D0[spritenum].unk0 = (D_8013B2D0[spritenum].unk0 - (spr->unk2B >> 1)) & 0x7FF;

    cstat2 = gpSprite[spr->unk20].cstat;
    cstat = spr->cstat;
    spr->cstat = cstat & ~0x101;
    gpSprite[spr->unk20].cstat &= ~0x101;

    getzRange(spr->x, spr->y, (spr->z - 2048), spr->sectnum,
              &ceilz, &ceilhit, &florz, &florhit, 64, 0x10001);

    spr->cstat = cstat;
    gpSprite[spr->unk20].cstat = cstat2;

    if ((florz - ceilz) < 256)
        spr->unk22 = 0;

    if (ceilz > spr->z)
    {
        if (gpSector[spr->sectnum].ceilingstat & 1)
        {
            MusHandleStop(D_8013B2D0[spritenum].handle, 0);
            deleteSprite(spritenum);
            return;
        }
        spr->unk1C = -spr->unk1C;
        spr->z = ceilz;
        spr->unk18 /= 2;
        audio_800077F4(588, spritenum);
    }

    florz -= 500;
    if (florz < spr->z)
    {
        spr->z = florz;
        diff = klabs(florz - z);
        if (gpSector[spr->sectnum].unk18 != 1)
        {
            spr->unk1C /= -4;
            if (diff < 200)
                spr->unk1C = 0;
            else
                audio_800077F4(588, spritenum);
        }
        spr->unk18 /= 2;
        spr->unk2B >>= 1;
    }

    if (florz != spr->z)
    {
        if (spr->unk1C < 5000)
            spr->unk1C += 100;
    }
    else
    {
        if (gpSector[spr->sectnum].unk18 != 1)
        {
            if (spr->unk1C < 5000)
                spr->unk1C += 100;
        }
        spr->unk2B >>= 1;
        spr->unk18 /= 2;
    }

    if (num & 0xC000)
    {
        num &= 0xFFFF;
        num -= 0xC000;
        if (num >= 0)
        {
            spr->unk18 = 0;
            spr->unk2B >>= 1;
        }
        else
        {
            num += 0xC000;
            num &= 0x7FFF;

            ang = (getAngle(gpWall[num].x - gpWall[gpWall[num].point2].x,
                gpWall[num].y - gpWall[gpWall[num].point2].y) - 512) & 0x7FF;

            ang2 = getAngleDelta(ang, (spr->ang + 1024) & 0x7FF);
            spr->ang = (ang - ang2) & 0x7FF;
            spr->unk18 /= 2;
            spr->unk2B >>= 1;
            audio_800077F4(588, spritenum);
        }
    }

    if (spr->unk22 != 0)
        spr->unk22--;
    else
    {
        func_8004BFDC(spritenum, 5, spr->z, 1);
        MusHandleStop(D_8013B2D0[spritenum].handle, 0);
        deleteSprite(spritenum);
    }
}

/*80072ABC*/
STATIC void func_80072ABC(s32 spritenum)
{
    s32 ceilz, ceilhit, florz, florhit;
    SpriteType *spr;
    s16 ang, diff, z;
    s32 i, num, ang2;
    s16 cstat, cstat2;

    spr = &gpSprite[spritenum];
    z = spr->z;

    num = func_8004E5F8(spritenum,
                        (spr->unk18 * gpSinTable[(spr->ang + 512) & 0x7FF]) >> 14,
                        (spr->unk18 * gpSinTable[spr->ang & 0x7FF]) >> 14,
                        spr->unk1C);

    D_8013B2D0[spritenum].handle = audio_8000784C(D_8013B2D0[spritenum].handle, spritenum);

    if (spr->sectnum == -1)
    {
        MusHandleStop(D_8013B2D0[spritenum].handle, 0);
        deleteSprite(spritenum);
        return;
    }

    if (!(D_8012FD88 & 3))
    {
        if (D_8012C470 == 1)
        {
            for (i = 0; i < 3; i++)
                func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 76, 0);
        }
    }

    D_8013B2D0[spritenum].unk2 = (D_8013B2D0[spritenum].unk2 + spr->unk2B) & 0x7FF;
    D_8013B2D0[spritenum].unk0 = (D_8013B2D0[spritenum].unk0 - (spr->unk2B >> 1)) & 0x7FF;

    cstat2 = gpSprite[spr->unk20].cstat;
    cstat = spr->cstat;
    spr->cstat = cstat & ~0x101;
    gpSprite[spr->unk20].cstat &= ~0x101;

    getzRange(spr->x, spr->y, (spr->z - 2048), spr->sectnum,
              &ceilz, &ceilhit, &florz, &florhit, 64, 0x10001);

    spr->cstat = cstat;
    gpSprite[spr->unk20].cstat = cstat2;

    if ((florz - ceilz) >= 256)
    {
        if (ceilz > spr->z)
        {
            if (gpSector[spr->sectnum].ceilingstat & 1)
            {
                MusHandleStop(D_8013B2D0[spritenum].handle, 0);
                deleteSprite(spritenum);
                return;
            }
            spr->unk1C = -spr->unk1C;
            spr->z = ceilz;
            spr->unk18 /= 2;
            audio_800077F4(587, spritenum);
        }

        florz -= 500;
        if (florz < spr->z)
        {
            spr->z = florz;
            diff = klabs(florz - z);
            if (gpSector[spr->sectnum].unk18 != 1)
            {
                spr->unk1C /= -2;
                if (diff < 200)
                    spr->unk1C = 0;
                else
                    audio_800077F4(587, spritenum);
            }
            spr->unk18 /= 2;
            spr->unk2B >>= 1;
        }

        if (florz != spr->z)
        {
            if (spr->unk1C < 5000)
                spr->unk1C += 100;
        }
        else
        {
            if (gpSector[spr->sectnum].unk18 != 1)
            {
                if (spr->unk1C < 5000)
                    spr->unk1C += 100;
            }
            spr->unk2B >>= 1;
            spr->unk18 /= 2;
        }

        if (num & 0xC000)
        {
            num &= 0xFFFF;
            num -= 0xC000;
            if (num >= 0)
            {
                spr->unk18 = 0;
                spr->unk2B >>= 1;
            }
            else
            {
                num += 0xC000;
                num &= 0x7FFF;

                func_8004CB3C(num);
                ang = (getAngle(gpWall[num].x - gpWall[gpWall[num].point2].x,
                    gpWall[num].y - gpWall[gpWall[num].point2].y) - 512) & 0x7FF;

                ang2 = getAngleDelta(ang, (spr->ang + 1024) & 0x7FF);
                spr->ang = (ang - ang2) & 0x7FF;
                spr->unk18 /= 2;
                spr->unk2B >>= 1;
                audio_800077F4(587, spritenum);
            }
        }

        if (spr->unk22 != 0)
        {
            spr->unk22--;
            return;
        }
    }

    func_8004BFDC(spritenum, 3, spr->z, 1);
    MusHandleStop(D_8013B2D0[spritenum].handle, 0);
    deleteSprite(spritenum);
}

/*800730CC*/
STATIC void func_800730CC(s32 spritenum)
{
    s32 ceilz, ceilhit, florz, florhit;
    SpriteType *spr;
    s16 ang, diff, z;
    s32 num, ang2;
    s16 cstat, cstat2;

    spr = &gpSprite[spritenum];
    z = spr->z;

    num = func_8004E5F8(spritenum,
                        (spr->unk18 * gpSinTable[(spr->ang + 512) & 0x7FF]) >> 14,
                        (spr->unk18 * gpSinTable[spr->ang & 0x7FF]) >> 14,
                        spr->unk1C);

    if (spr->sectnum == -1)
    {
        deleteSprite(spritenum);
        return;
    }

    if ((D_8012FD88 & 1))
    {
        if (D_8012C470 == 1)
        {
            if (func_8004EFB4(spritenum))
                func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 1, 0);
            else
                func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 24, 19);
        }
    }

    D_8013B2D0[spritenum].unk2 = (D_8013B2D0[spritenum].unk2 + spr->unk2B) & 0x7FF;
    D_8013B2D0[spritenum].unk0 = (D_8013B2D0[spritenum].unk0 - (spr->unk2B >> 1)) & 0x7FF;

    if (!func_800722A0(spritenum))
    {
        cstat = spr->cstat;
        cstat2 = gpSprite[spr->unk20].cstat;
        spr->cstat = cstat & ~0x101;
        gpSprite[spr->unk20].cstat &= ~0x101;

        getzRange(spr->x, spr->y, (spr->z - 2048), spr->sectnum,
                  &ceilz, &ceilhit, &florz, &florhit, 64, 0x10001);

        spr->cstat = cstat;
        gpSprite[spr->unk20].cstat = cstat2;

        if (ceilz > spr->z)
        {
            if (gpSector[spr->sectnum].ceilingstat & 1)
            {
                deleteSprite(spritenum);
                return;
            }
            else
            {
                spr->unk1C = -spr->unk1C;
                spr->z = ceilz;
                spr->unk18 /= 2;
                audio_800077F4(588, spritenum);
            }
        }

        florz -= 500;
        if (florz < spr->z)
        {
            do { spr->z = florz; } while (0); /*FAKEMATCH*/
            if (gpSector[spr->sectnum].unk18 != 1)
            {
                spr->unk18 = spr->unk18 / 2;
                spr->unk2B = spr->unk2B >> 1;
                spr->unk1C = -(spr->unk1C / 2);

                if (spr->unk2A < 3)
                {
                    audio_800077F4(588, spritenum);
                    spr->unk2A++;
                }
            }
        }

        if (florz != spr->z)
        {
            if (spr->unk1C < 5000)
                spr->unk1C += 100;
        }
        else
        {
            if (gpSector[spr->sectnum].unk18 == 1)
            {
                diff = klabs(florz - z);
                if (diff < 200)
                {
                    func_8004BFDC(spritenum, 4, spr->z, 1);
                    deleteSprite(spritenum);
                    return;
                }
                else
                {
                    if (spr->unk1C < 5000)
                        spr->unk1C += 100;
                }
            }
            spr->unk2B >>= 1;
        }

        if (num & 0xC000)
        {
            do { num &= 0xFFFF; } while (0); /*FAKEMATCH*/
            num -= 0xC000;
            if (num >= 0)
            {
                func_8004BFDC(spritenum, 4, spr->z, 1);
                deleteSprite(spritenum);
                return;
            }
            else
            {
                num += 0xC000;
                num &= 0x7FFF;

                func_8004CB3C(num);
                ang = (getAngle(gpWall[num].x - gpWall[gpWall[num].point2].x,
                    gpWall[num].y - gpWall[gpWall[num].point2].y) - 512) & 0x7FF;

                ang2 = getAngleDelta(ang, (spr->ang + 1024) & 0x7FF);
                spr->ang = (ang - ang2) & 0x7FF;
                spr->unk18 /= 2;
                spr->unk2B >>= 1;
                audio_800077F4(588, spritenum);
            }
        }

        if (spr->unk22 != 0)
        {
            spr->unk22--;
            return;
        }
    }

    func_8004BFDC(spritenum, 4, spr->z, 1);
    deleteSprite(spritenum);
}

/*80073670*/
STATIC void func_80073670(s32 spritenum)
{
    s32 ceilz, ceilhit, florz, florhit;
    SpriteType *spr;
    s16 ang, diff, z;
    s32 num, ang2;
    s16 cstat, cstat2;

    spr = &gpSprite[spritenum];
    z = spr->z;

    num = func_8004E5F8(spritenum,
                        (spr->unk18 * gpSinTable[(spr->ang + 512) & 0x7FF]) >> 14,
                        (spr->unk18 * gpSinTable[spr->ang & 0x7FF]) >> 14,
                        spr->unk1C);

    cstat = spr->cstat;
    cstat2 = gpSprite[spr->unk20].cstat;
    spr->cstat = cstat & ~0x101;
    gpSprite[spr->unk20].cstat &= ~0x101;

    getzRange(spr->x, spr->y, (spr->z - 2048), spr->sectnum,
              &ceilz, &ceilhit, &florz, &florhit, 64, 0x10001);

    spr->cstat = cstat;
    gpSprite[spr->unk20].cstat = cstat2;

    if (spr->sectnum != -1)
    {
        if (spr->unk16 == 0)
        {
            if ((D_8012FD88 & 1))
            {
                if (D_8012C470 == 1)
                {
                    if (func_8004EFB4(spritenum))
                        func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 1, 0);
                    else
                        func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 24, 22);
                }
            }

            D_8013B2D0[spritenum].unk2 = (D_8013B2D0[spritenum].unk2 + spr->unk2B) & 0x7FF;
            D_8013B2D0[spritenum].unk0 = (D_8013B2D0[spritenum].unk0 - (spr->unk2B >> 1)) & 0x7FF;

            if (ceilz > spr->z)
            {
                if (!(gpSector[spr->sectnum].ceilingstat & 1))
                {
                    spr->unk1C = -spr->unk1C;
                    spr->z = ceilz;
                    spr->unk18 /= 2;
                    audio_800077F4(588, spritenum);
                }
                else
                {
                    deleteSprite(spritenum);
                    return;
                }
            }

            florz -= 500;
            if (florz < spr->z)
            {
                spr->z = florz;
                diff = klabs(florz - z);
                if (gpSector[spr->sectnum].unk18 != 1)
                {
                    spr->unk1C = -(spr->unk1C / 2);
                    if (diff >= 200)
                        audio_800077F4(588, spritenum);
                    else
                        goto label1;
                }
                spr->unk18 /= 2;
                spr->unk2B >>= 1;
            }

            if (florz != spr->z)
            {
                if (spr->unk1C < 5000)
                    spr->unk1C += 100;
            }
            else
            {
                if (gpSector[spr->sectnum].unk18 == 1)
                {
                    diff = klabs(florz - z);
                    if (diff >= 200)
                    {
                        if (spr->unk1C < 5000)
                            spr->unk1C += 100;
                    }
                    else
                        goto label1;
                }
                spr->unk2B >>= 1;
            }

            if (num & 0xC000)
            {
                num &= 0xFFFF;
                num -= 0xC000;
                if (num >= 0)
                {
                    spr->unk18 = 0;
                }
                else
                {
                    num += 0xC000;
                    num &= 0x7FFF;

                    func_8004CB3C(num);
                    ang = (getAngle(gpWall[num].x - gpWall[gpWall[num].point2].x,
                        gpWall[num].y - gpWall[gpWall[num].point2].y) - 512) & 0x7FF;

                    ang2 = getAngleDelta(ang, (spr->ang + 1024) & 0x7FF);
                    spr->ang = (ang - ang2) & 0x7FF;
                    spr->unk18 /= 2;
                    spr->unk2B >>= 1;
                    audio_800077F4(588, spritenum);
                }
                return;
            label1:
                spr->unk16 = 4;
                spr->unk1A = 0;
                spr->unk1C = 0;
                spr->unk18 = 0;
                D_8013B2D0[spritenum].handle = audio_800077F4(783, spritenum);
            }
            return;
        }
        else
        {
            if (D_8012FD88 & 1)
                func_80059EEC(spritenum, 1, 2048);

            D_8013B2D0[spritenum].handle = audio_8000784C(D_8013B2D0[spritenum].handle, spritenum);
            if (spr->unk1A)
                spr->unk1A--;
            else
            {
                spr->unk1A = 40;
                func_8001DCD0(spr->x/2, spr->y/2, spr->z/32, 1);
                spr->unk16--;
            }
            if (num & 0xC000)
            {
                if (num < 0xC000)
                {
                    num &= 0x7FFF;

                    func_8004CB3C(num);
                    ang = (getAngle(gpWall[num].x - gpWall[gpWall[num].point2].x,
                        gpWall[num].y - gpWall[gpWall[num].point2].y) - 512) & 0x7FF;

                    ang2 = getAngleDelta(ang, (spr->ang + 1024) & 0x7FF);
                    spr->ang = (ang - ang2) & 0x7FF;
                    spr->unk18 /= 2;
                    spr->unk2B >>= 1;
                }
            }
            if (spr->unk16 != 0)
                return;
        }
    }
    MusHandleStop(D_8013B2D0[spritenum].handle, 0);
    playSfx(782);
    func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 24, 22);
    deleteSprite(spritenum);
}

/*80073E0C*/
STATIC void func_80073E0C(s32 spritenum)
{
    s32 ceilz, ceilhit, florz, florhit;
    SpriteType *spr;
    s16 ang, diff, z;
    s32 num, ang2;
    s16 cstat, cstat2;

    spr = &gpSprite[spritenum];
    z = spr->z;

    if (spr->unk22 == 1)
    {
        func_8004BFDC(spritenum, 6, spr->z, 1);
        deleteSprite(spritenum);
        return;
    }

    num = func_8004E5F8(spritenum,
                        (spr->unk18 * gpSinTable[(spr->ang + 512) & 0x7FF]) >> 14,
                        (spr->unk18 * gpSinTable[spr->ang & 0x7FF]) >> 14,
                        spr->unk1C);

    D_8013B2D0[spritenum].unk2 = (D_8013B2D0[spritenum].unk2 + spr->unk2B) & 0x7FF;
    D_8013B2D0[spritenum].unk0 = (D_8013B2D0[spritenum].unk0 - (spr->unk2B >> 1)) & 0x7FF;

    if (spr->sectnum == -1)
    {
        deleteSprite(spritenum);
        return;
    }

    cstat = spr->cstat;
    cstat2 = gpSprite[spr->unk20].cstat;
    spr->cstat = cstat & ~0x101;
    gpSprite[spr->unk20].cstat &= ~0x101;

    getzRange(spr->x, spr->y, (spr->z - 2048), spr->sectnum,
              &ceilz, &ceilhit, &florz, &florhit, 64, 0x10001);

    spr->cstat = cstat;
    gpSprite[spr->unk20].cstat = cstat2;

    if ((florz - ceilz) < 256)
    {
        spr->unk22 = 1;
        return;
    }

    if (ceilz > spr->z)
    {
        if (gpSector[spr->sectnum].ceilingstat & 1)
        {
            deleteSprite(spritenum);
            return;
        }
        else
        {
            spr->unk1C = -spr->unk1C;
            spr->z = ceilz;
            spr->unk18 /= 2;
            audio_800077F4(587, spritenum);
        }
    }

    florz -= 800;
    if (florz < spr->z)
    {
        spr->z = florz;
        diff = klabs(florz - z);
        if (gpSector[spr->sectnum].unk18 != 1)
        {
            spr->unk1C = (-spr->unk1C / 4);
            if (diff < 200)
            {
                spr->unk22 = 2;
                spr->unk1C = 0;
            }
            else
            {
                spr->unk18 /= 2;
                spr->unk2B >>= 1;
                audio_800077F4(587, spritenum);
            }
        }
    }

    if (florz != spr->z)
    {
        if (spr->unk1C < 5000)
            spr->unk1C += 100;
    }
    else
    {
        if (gpSector[spr->sectnum].unk18 == 1)
        {
            if (spr->unk1C < 5000)
                spr->unk1C += 100;
        }
        spr->unk2B >>= 1;
        spr->unk18 /= 2;
        D_8013B2D0[spritenum].unk2 /= 2;
    }


    if (num & 0xC000)
    {
        num &= 0xFFFF;
        num -= 0xC000;
        if (num >= 0)
        {
            if (gpSprite[num].statnum != 4)
            {
                spr->unk18 = 0;
                spr->unk2B >>= 1;
            }
        }
        else
        {
            num += 0xC000;
            num &= 0x7FFF;

            func_8004CB3C(num);
            ang = (getAngle(gpWall[num].x - gpWall[gpWall[num].point2].x,
                gpWall[num].y - gpWall[gpWall[num].point2].y) - 512) & 0x7FF;

            ang2 = getAngleDelta(ang, (spr->ang + 1024) & 0x7FF);
            spr->ang = (ang - ang2) & 0x7FF;
            spr->unk18 /= 2;
            spr->unk2B >>= 1;
            audio_800077F4(587, spritenum);
        }
    }
}

/*800743C0*/
STATIC void func_800743C0(s32 spritenum)
{
    s32 ceilz, ceilhit, florz, florhit;
    SpriteType *spr;
    s32 num;
    s16 cstat, cstat2;

    spr = &gpSprite[spritenum];

    num = func_8004E5F8(spritenum,
                        (spr->unk18 * gpSinTable[(spr->ang + 512) & 0x7FF]) >> 14,
                        (spr->unk18 * gpSinTable[spr->ang & 0x7FF]) >> 14,
                        spr->unk1C);

    D_8013B2D0[spritenum].unk2 = (D_8013B2D0[spritenum].unk2 + 100) & 0x7FF;
    spr->unk1C += 300;

    if (spr->sectnum == -1)
    {
        deleteSprite(spritenum);
        return;
    }

    if (D_8012FD88 & 1)
        func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 24, 19);

    cstat = spr->cstat;
    cstat2 = gpSprite[spr->unk20].cstat;
    spr->cstat = cstat & ~0x101;
    gpSprite[spr->unk20].cstat &= ~0x101;

    getzRange(spr->x, spr->y, (spr->z - 2048), spr->sectnum,
             &ceilz, &ceilhit, &florz, &florhit, 64, 0x10001);

    spr->cstat = cstat;
    gpSprite[spr->unk20].cstat = cstat2;

    if ((florz < spr->z) || (spr->z < ceilz))
    {
        func_8004BFDC(spritenum, 10, florz, 1);
        deleteSprite(spritenum);
    }
    else if (num & 0xC000)
    {
        if (gpSprite[(num & 0xFFFF)-0xC000].statnum != 305)
            func_8004BFDC(spritenum, 10, spr->z, 1);
        deleteSprite(spritenum);
    }
}

/*80074664*/
STATIC void func_80074664(s32 spritenum)
{
    s16 hitsprite;
    s32 hitx, hity;
    SpriteType *spr;
    s32 z;

    spr = &gpSprite[spritenum];
    if (spr->unk2B != 255)
    {
        z = spr->z - 768;
        {
            if (spr->unk1A == 4)
            {
                func_80058A14(spritenum, &hitsprite, &hitx, &hity);

                if (spr->picnum == 1844)
                    func_800867CC(spritenum, spr->x, spr->y, z, hitx, hity, z, 48, 18);
                else
                    func_80087174(spritenum, spr->x, spr->y, z, hitx, hity, z, 32, 8);

                spr->unk18++;
                if (spr->unk18 >= 11)
                {
                    func_8004BFDC(spritenum, 7, spr->z, 1);
                    func_8004BD24(spritenum);
                }
            }
            else
            {
                if (spr->unk1A == 3)
                {
                    spr->unk18 = 0;
                    spr->unk1A = 4;
                }

                if (spr->unk1A == 0)
                {
                    spr->unk18++;
                    if (spr->unk18 >= 61)
                    {
                        audio_800077F4(780, spritenum);
                        spr->unk1A = 1;
                    }
                }

                if (spr->unk1A == 1)
                {
                    func_80058A14(spritenum, &hitsprite, &hitx, &hity);

                    if (spr->picnum == 1844)
                        func_800867CC(spritenum, spr->x, spr->y, z, hitx, hity, z, 48, 18);
                    else
                        func_80087174(spritenum, spr->x, spr->y, z, hitx, hity, z, 32, 8);

                    spr->unk1A++;
                }

                if (spr->unk1A == 2)
                {
                    func_80058A14(spritenum, &hitsprite, &hitx, &hity);

                    if (spr->picnum == 1844)
                        func_800867CC(spritenum, spr->x, spr->y, z, hitx, hity, z, 48, 18);
                    else
                        func_80087174(spritenum, spr->x, spr->y, z, hitx, hity, z, 32, 8);

                    if (func_800720FC(spritenum) != 0)
                    {
                        audio_800077F4(780, spritenum);
                        spr->unk1A = 3;
                    }
                }
            }
        }
    }
}

/*800749A8*/
STATIC void func_800749A8(s32 spritenum)
{
    s32 ceilz, ceilhit, florz, florhit;
    SpriteType *spr;
    s32 num;
    u16 cstat;

    spr = &gpSprite[spritenum];
    D_80137DE0 = &D_8019B940[D_80106D50[gPlayer[D_801B0820].unk4A]];

    num = func_8004E5F8(spritenum, (gpSinTable[(spr->ang + 512) & 0x7FF] * 125) >> 10,
                     (gpSinTable[spr->ang & 0x7FF] * 125) >> 10,
                     spr->unk1C);

    spr->xrepeat += 3;
    spr->yrepeat += 3;
    D_8013B2D0[spritenum].unk6 += 10;
    D_8013B2D0[spritenum].unk0 -= spr->unk1A;

    cstat = spr->cstat;
    spr->cstat = cstat & ~0x101;

    getzRange(spr->x, spr->y, spr->z - 512, spr->sectnum,
              &ceilz, &ceilhit, &florz, &florhit, 64, 0x01000040);

    spr->cstat = cstat;

    if ((spr->unk18++ >= 24) || (florz < spr->z) || (spr->z < ceilz) || (num & 0xC000))
    {
        D_80137DE0->unk60++;
        if ((D_80137DE0->unk60 & 3) == 3)
            func_8001DBA0((spr->x / 2), (spr->y / 2), (spr->z / 32), 18, 18, 10);

        if (D_80137DE0->unk60 & 1)
            func_8005A4A4(spritenum, 0);

        deleteSprite(spritenum);
    }
}

/*80074C70*/
STATIC void func_80074C70(s32 spritenum)
{
    s32 ceilz, ceilhit, florz, florhit;
    SpriteType *spr;
    s16 ang, num2;
    s32 ang2, num, i, point2;
    s16 cstat, cstat2;

    spr = &gpSprite[spritenum];
    i = spr->unk22 & 0x7F;
    if (i != 0)
    {
        /*FAKEMATCH*/
        do
        {
            i--;
            D_8013B2D0[spritenum].unk6 = CLAMP_MAX((CLAMP_MIN((8 - i), 0) * 32), 255);
            spr->unk22 = i + (spr->unk22 & 0x80);
        } while (0);

        if (spr->unk18 == 0)
        {
            ang = (gpSinTable[(spr->ang + 512) & 0x7FF] * 225) >> 10;
            num = func_8004E5F8(spritenum,
                                ang,
                                (gpSinTable[spr->ang & 0x7FF] * 225) >> 10,
                                spr->unk1C);

            D_8013B2D0[spritenum].unk0 += 64;

            if (spr->sectnum == -1)
                deleteSprite(spritenum);
            else
            {
                cstat = spr->cstat;
                spr->cstat = cstat & ~0x101;
                getzRange(spr->x, spr->y, (spr->z - 512), spr->sectnum, &ceilz, &ceilhit, &florz, &florhit, 64, 0x01000040);
                spr->cstat = cstat;
                if (florz < spr->z)
                {
                    if ((spr->unk22 & 0x80))
                        deleteSprite(spritenum);
                    else
                    {
                        if ((gpSector[spr->sectnum].floorstat & 2) && (gpSector[spr->sectnum].floorheinum != 0))
                        {
                            point2 = gpWall[gpSector[spr->sectnum].wallptr].point2;
                            ang = (getAngle(gpWall[gpWall[gpSector[spr->sectnum].wallptr].point2].x - gpWall[gpSector[spr->sectnum].wallptr].x,
                                gpWall[point2].y - gpWall[gpSector[spr->sectnum].wallptr].y) - 512) & 0x7FF;

                            ang2 = getAngleDelta(ang, (spr->ang + 1024) & 0x7FF);
                            spr->ang = (ang - ang2) & 0x7FF;
                        }
                        spr->unk1C = -spr->unk1C;
                        if ((D_8012C470 == 1) && (D_800DEEA0 != 0))
                            func_8008E3E0(spr->x, spr->y, florz, spr->sectnum, 61, 0);
                        audio_800077F4(1568, spritenum);
                    }
                }
                else if (spr->z < ceilz)
                {
                    if ((spr->unk22 & 0x80))
                        deleteSprite(spritenum);
                    else
                    {
                        if (gpSector[spr->sectnum].ceilingstat & 1)
                            deleteSprite(spritenum);
                        else
                        {
                            if ((gpSector[spr->sectnum].ceilingstat & 2) && (gpSector[spr->sectnum].ceilingheinum != 0))
                            {
                                point2 = gpWall[gpSector[spr->sectnum].wallptr].point2;
                                ang = (getAngle(gpWall[point2].x - gpWall[gpSector[spr->sectnum].wallptr].x,
                                    gpWall[point2].y - gpWall[gpSector[spr->sectnum].wallptr].y) - 512) & 0x7FF;

                                ang2 = getAngleDelta(ang, (spr->ang + 1024) & 0x7FF);
                                spr->ang = (ang - ang2) & 0x7FF;
                            }
                            spr->unk1C = -spr->unk1C;
                            if ((D_8012C470 == 1) && (D_800DEEA0 != 0))
                                func_8008E3E0(spr->x, spr->y, ceilz, spr->sectnum, 61, 0);
                            audio_800077F4(1568, spritenum);
                        }
                    }
                }
                else if (num & 0xC000)
                {
                    num &= 0xFFFF;
                    num -= 0xC000;
                    if (num >= 0)
                    {
                        if (gpSprite[spritenum].unk20 != num)
                        {
                            func_80047820(spritenum, num, (krand() % 5) + 10);
                            if ((D_8012C470 == 1) && (D_800DEEA0 != 0))
                            {
                                num2 = func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 61, D_8012C470);
                                if (num2 != -1)
                                    gpSprite[num2].ang = spr->ang;
                            }
                            deleteSprite(spritenum);
                        }
                    }
                    else
                    {
                        num += 0xC000;

                        if ((gpWall[num&0x7FFF].nextsector >= 0) &&
                            (gpWall[num&0x7FFF].cstat & 0x400) &&
                            ((gpSprite[spritenum].z < gpSector[gpWall[num&0x7FFF].nextsector].floorz)))
                            deleteSprite(spritenum);
                        else
                        {
                            if (func_8004CB3C(num) == 0)
                            {
                                num &= 0x7FFF;
                                if ((spr->unk22 & 0x80))
                                    deleteSprite(spritenum);
                                else
                                {
                                    ang = (getAngle(gpWall[num].x - gpWall[gpWall[num].point2].x,
                                        gpWall[num].y - gpWall[gpWall[num].point2].y) - 512) & 0x7FF;

                                    ang2 = getAngleDelta(ang, (spr->ang + 1024) & 0x7FF);
                                    spr->ang = (ang - ang2) & 0x7FF;

                                    if ((D_8012C470 == 1) && (D_800DEEA0 != 0))
                                    {
                                        num2 = func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 61, D_8012C470);
                                        if (num2 != -1)
                                            gpSprite[num2].ang = ang;
                                    }
                                    audio_800077F4(1568, spritenum);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else
        deleteSprite(spritenum);
}

/*80075380*/
STATIC void func_80075380(s32 spritenum)
{
    s32 ceilz, ceilhit, florz, florhit;
    SpriteType *spr;
    s32 ang, num, i;
    s16 ang2;
    u16 cstat;

    spr = &gpSprite[spritenum];
    if (spr->unk22 == 45)
    {
        ang = getAngle(gpSprite[gPlayer[0].unk4A].x - spr->x, gpSprite[gPlayer[0].unk4A].y - spr->y);
        ang2 = getAngleDelta(spr->ang, ang);

        if (ang2 > 700)
            ang = (spr->ang + 700) & 0x7FF;
        if (ang2 < -700)
            ang = (spr->ang - 700) & 0x7FF;

        ang -= ((krand() & 0x3F) - 32);
        spr->ang = ang;
    }

    i = spr->unk22;
    if (i != 0)
    {
        i--;
        D_8013B2D0[spritenum].unk6 = CLAMP_MAX((CLAMP_MIN((8 - i), 0) * 32), 255);
        spr->unk22 = i;
    }

    ang = (gpSinTable[(spr->ang + 512) & 0x7FF] * 225) >> 10;
    num = func_8004E5F8(spritenum,
        ang,
        (gpSinTable[spr->ang & 0x7FF] * 225) >> 10, spr->unk1C);

    D_8013B2D0[spritenum].unk0 += 64;

    if (spr->sectnum == -1)
    {
        deleteSprite(spritenum);
        return;
    }
    cstat = spr->cstat;
    spr->cstat = cstat & ~0x101;

    getzRange(spr->x,
              spr->y,
              spr->z - 512,
              spr->sectnum,
              &ceilz, &ceilhit, &florz, &florhit, 64, 0x01000040);

    spr->cstat = cstat;

    if ((florz < spr->z) || (spr->z < ceilz))
        deleteSprite(spritenum);
    else if (num & 0xC000)
    {
        num &= 0xFFFF;
        num -= 0xC000;
        if (num >= 0)
        {
            if (gpSprite[spritenum].unk20 != num)
            {
                func_80047820(spritenum, num, (krand() % 5) + 2);
                deleteSprite(spritenum);
            }
        }
        else
            deleteSprite(spritenum);
    }
}

/*800756B0*/
STATIC void func_800756B0(s32 spritenum)
{
    s32 ceilz, ceilhit, florz, florhit;
    SpriteType *spr;
    s32 ang, num, unk1C;
    s16 ang2, i;
    u16 cstat;

    spr = &gpSprite[spritenum];
    ang = getAngleDelta(spr->ang,
                        getAngle(gpSprite[gPlayer[0].unk4A].x - spr->x, gpSprite[gPlayer[0].unk4A].y - spr->y));

    i = spr->unk22;
    if (i == 0)
    {
        ang = ang >= -300 ? ang : 0;
        ang = ang <= 300 ? ang : 0;
    }
    else
        spr->unk22 = i - 1;

    spr->ang += (ang >> 3);
    ang = (gpSinTable[(spr->ang + 512) & 0x7FF] * 125) >> 10;
    ang2 = (gpSinTable[spr->ang & 0x7FF]* 125) >> 10;
    unk1C = spr->unk1C;
    D_8013B2D0[spritenum].unk0 = (D_8013B2D0[spritenum].unk0 + 32) & 0x7FF;

    num = func_8004E5F8(spritenum, ang, ang2, unk1C);

    if (spr->sectnum == -1)
    {
        deleteSprite(spritenum);
        return;
    }

    cstat = spr->cstat;
    spr->cstat = cstat & ~0x101;

    getzRange(spr->x,
              spr->y,
              (spr->z - 512),
              spr->sectnum,
              &ceilz, &ceilhit, &florz, &florhit, 64, 0x01000040);

    spr->cstat = cstat;

    if ((florz < spr->z) || (spr->z < ceilz))
    {
        func_8004BFDC(spritenum, 12, florz, 1);
        deleteSprite(spritenum);
    }
    else if (num & 0xC000)
    {
        num -= 0xC000;
        if ((num >= 0) && (gpSprite[spritenum].unk20 != num))
        {
            func_8004BFDC(spritenum, 12, florz, 1);
            deleteSprite(spritenum);
        }
        else
        {
            func_8004BFDC(spritenum, 12, florz, 1);
            deleteSprite(spritenum);
        }
    }
    else
    {
        func_80058844(spritenum, spr->unk1A, 16, 16);
        if (!(D_8012FD88 & 3))
            func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 4, 0);
    }
}

/*8007599C*/
STATIC void func_8007599C(s32 spritenum)
{
    s32 ceilz, ceilhit, florz, florhit;
    SpriteType *spr;
    s32 ang, num, unk1C;
    s16 ang2, i;
    u16 cstat;

    spr = &gpSprite[spritenum];
    ang = getAngleDelta(spr->ang,
                        getAngle(gpSprite[gPlayer[0].unk4A].x - spr->x, gpSprite[gPlayer[0].unk4A].y - spr->y));

    i = spr->unk22;
    if (i == 0)
    {
        ang = ang >= -300 ? ang : 0;
        ang = ang <= 300 ? ang : 0;
    }
    else
        spr->unk22 = i - 1;

    spr->ang += (ang >> 3);
    ang = (gpSinTable[(spr->ang + 512) & 0x7FF] * 125) >> 10;
    ang2 = (gpSinTable[spr->ang & 0x7FF]* 125) >> 10;
    unk1C = spr->unk1C;
    D_8013B2D0[spritenum].unk0 = (D_8013B2D0[spritenum].unk0 + 32) & 0x7FF;

    num = func_8004E5F8(spritenum, ang, ang2, unk1C);

    if (spr->sectnum == -1)
    {
        deleteSprite(spritenum);
        return;
    }

    cstat = spr->cstat;
    spr->cstat = cstat & ~0x101;

    getzRange(spr->x,
              spr->y,
              (spr->z - 512),
              spr->sectnum,
              &ceilz, &ceilhit, &florz, &florhit, 64, 0x01000040);

    spr->cstat = cstat;

    if ((florz < spr->z) || (spr->z < ceilz))
    {
        func_8004BFDC(spritenum, 12, florz, 1);
        deleteSprite(spritenum);
    }
    else if (num & 0xC000)
    {
        num -= 0xC000;
        if ((num >= 0) && (gpSprite[spritenum].unk20 != num))
        {
            func_8004BFDC(spritenum, 12, florz, 1);
            deleteSprite(spritenum);
        }
        else
        {
            func_8004BFDC(spritenum, 12, florz, 1);
            deleteSprite(spritenum);
        }
    }
    else
    {
        func_80058844(spritenum, spr->unk1A, 16, 16);
        if (!(D_8012FD88 & 3))
            func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 4, 0);
    }
}

/*80075C88*/
STATIC void func_80075C88(s32 spritenum)
{
    SpriteType *spr;
    s32 i;

    spr = &gpSprite[spritenum];
    if (spr->xrepeat < 64)
    {
        spr->xrepeat++;
        spr->yrepeat++;
    }

    switch (spr->unk2B)
    {
    case 0:
        if (spr->unk22 != 0)
        {
            spr->z -= spr->unk22 * 12;
            spr->unk22--;
            if (spr->unk22 == 0)
            {
                spr->unk2B = 1;
                spr->unk22 = 30;
            }
        }
        break;
    case 1:
        spr->unk22--;
        if (spr->unk22 == 0)
            spr->unk2B = 2;
        break;
    case 2:
        spr->picnum = 5746;
        spr->yrepeat = 0x7F;
        spr->xrepeat = 0xFF;
        spr->unk2B = 3;
        playSfx(641);
        for (i = 0; i < 32; i++)
            func_8006D3B8(spritenum, 41, 0, 0, 0);
        break;
    case 3:
        if (spr->xrepeat >= 9)
        {
            spr->xrepeat /= 2;
            spr->yrepeat /= 2;
            break;
        }
        deleteSprite(spritenum);
        break;
    }
}

/*80075E28*/
STATIC void func_80075E28(s32 spritenum)
{
    s32 ceilz, ceilhit, florz, florhit;
    SpriteType *spr2;
    SpriteType *spr;
    s32 ang2, i, num;
    s16 ang;
    u16 cstat;

    spr = &gpSprite[spritenum];
    num = func_8004E5F8(spritenum,
        (spr->unk18 * gpSinTable[(spr->ang + 512) & 0x7FF]) >> 14,
        (spr->unk18 * gpSinTable[spr->ang & 0x7FF]) >> 14, spr->unk1C);

    if (num & 0xC000)
    {
        num &= 0xFFFF;
        num -= 0xC000;
        if (num < 0)
        {
            num += 0xC000;
            num &= 0x7FFF;
            ang = (getAngle(gpWall[num].x - gpWall[gpWall[num].point2].x,
                gpWall[num].y - gpWall[gpWall[num].point2].y) - 512) & 0x7FF;
            ang2 = getAngleDelta(ang, (spr->ang + 1024) & 0x7FF);
            spr->ang = (ang - ang2) & 0x7FF;
        }
    }
    D_8013B2D0[spritenum].unk2 = (D_8013B2D0[spritenum].unk2 + 34) & 0x7FF;
    D_8013B2D0[spritenum].unk0 = (D_8013B2D0[spritenum].unk0 - 87) & 0x7FF;

    if (spr->sectnum == -1)
    {
        deleteSprite(spritenum);
        return;
    }

    spr2 = &gpSprite[gPlayer[0].unk4A];
    cstat = spr2->cstat;
    spr2->cstat = cstat & ~0x101;

    getzRange(spr->x,
              spr->y,
              (spr->z - 2048),
              spr->sectnum, &ceilz, &ceilhit, &florz, &florhit, 64, 0x10001);

    spr2->cstat = cstat;

    if (ceilz > spr->z)
    {
        spr->z = ceilz;
        spr->unk1C = -spr->unk1C;
    }

    if (florz < spr->z)
    {
        spr->z = florz;
        i = -(spr->unk1C / 2);
        spr->unk1C = i;

        if (((u16)(i + 49)) < 99) /*TODO: if ((i > -50) && (i < 50)) ?*/
            spr->unk1C = 0;
        spr->unk18 = spr->unk18 / 2;
    }

    if (florz != spr->z)
        spr->unk1C += 200;

    if (spr->unk22 != 0)
        spr->unk22--;
    else
        deleteSprite(spritenum);
}

/*80076144*/
STATIC void func_80076144(s32 spritenum)
{
    s32 ceilz, ceilhit, florz, florhit;
    SpriteType *spr;
    s32 num;
    u16 cstat;

    spr = &gpSprite[spritenum];
    num = func_8004E5F8(spritenum,
                        (gpSinTable[(spr->ang + 512) & 0x7FF] * 125) >> 10,
                        (gpSinTable[spr->ang & 0x7FF] * 125) >> 10, spr->unk1C);

    spr->xrepeat += 8;
    spr->yrepeat += 8;
    D_8013B2D0[spritenum].unk6 += 8;
    D_8013B2D0[spritenum].unk0 -= spr->unk1A;
    cstat = spr->cstat;
    spr->cstat = cstat & ~0x101;

    getzRange(spr->x,
              spr->y,
              (spr->z - 512),
              spr->sectnum,
              &ceilz, &ceilhit, &florz, &florhit, 64, 0x10001);

    spr->cstat = cstat;
    if (!(D_8012FD88 & 3) && (func_80040D40(gPlayer[0].xpos, gPlayer[0].ypos, spr->x, spr->y) < 1024))
        func_8003671C(0, 1, -1, 44);

    if (spr->unk18++ < 29)
    {
        if (florz >= spr->z)
        {
            if (spr->z < ceilz)
                spr->z = ceilz;
        }
        else
            spr->z = florz;

        if (num & 0xC000)
            deleteSprite(spritenum);
    }
    else
        deleteSprite(spritenum);
}

/*80076364*/
STATIC void func_80076364(s32 spritenum)
{
    s32 ceilz, ceilhit, florz, florhit;
    SpriteType *spr;
    s32 ang, ang2, ang3;
    s32 num, unk1C;
    u16 cstat;

    spr = &gpSprite[spritenum];
    ang3 = spr->ang;
    ang3 += (gpSinTable[spr->unk18 & 0x7FF] * 5) >> 11;
    ang = (gpSinTable[(ang3 + 512) & 0x7FF] * 625) >> 12;
    ang2 = (gpSinTable[ang3 & 0x7FF] * 625) >> 12;
    unk1C = ((gpSinTable[(spr->unk18 + 512) & 0x7FF] * 35)) >> 13;
    spr->unk18 += 32;
    unk1C += spr->unk1C;
    D_8013B2D0[spritenum].unk0 = (D_8013B2D0[spritenum].unk0 + 32) & 0x7FF;

    num = func_8004E5F8(spritenum, ang, ang2, unk1C);

    if (spr->sectnum == -1)
    {
        deleteSprite(spritenum);
        return;
    }

    cstat = spr->cstat;
    spr->cstat = cstat & ~0x101;

    getzRange(spr->x,
              spr->y,
              (spr->z - 512),
              spr->sectnum,
              &ceilz, &ceilhit, &florz, &florhit, 64, 0x01000040);

    spr->cstat = cstat;

    if (florz < spr->z)
    {
        func_8004BFDC(spritenum, 2, florz, 1);
        deleteSprite(spritenum);
    }
    else if (spr->z < ceilz)
    {
        if (!(gpSector[spr->sectnum].ceilingstat & 1))
            func_8004BFDC(spritenum, 2, florz, 1);

        deleteSprite(spritenum);
    }
    else if (num & 0xC000)
    {
        num -= 0xC000;
        if (num < 0)
        {
            num += 0xC000;
            func_8004CB3C(num);
            if ((gpWall[num & 0x7FFF].nextsector >= 0) && (gpWall[num & 0x7FFF].cstat & 1024))
            {
                if (gpSprite[spritenum].z < gpSector[gpWall[num & 0x7FFF].nextsector].floorz)
                {
                    deleteSprite(spritenum);
                    return;
                }
            }
        }
        else
            func_80047820(spritenum, num, 75);

        func_8004BFDC(spritenum, 2, florz, 1);
        deleteSprite(spritenum);
    }
    else if (func_8004EFB4(spritenum) == 0)
    {
        if (D_8012FD88 & 1)
            func_800586B0(spritenum, spr->unk1A, 0xFF, 0xFF, 0xFF, 64, 42);

        if ((D_8012C470 == 1) && !(D_8012FD88 & 1) && (D_800DEEA0 != 0))
            func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 4, 0);
    }
    else if ((D_8012C470 == 1) && (D_800DEEA0 != 0))
        func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, D_8012C470, 0);
}

/*8007675C*/
STATIC void func_8007675C(s32 spritenum)
{
    s32 ceilz, ceilhit, florz, florhit;
    SpriteType *spr;
    s16 unk16;
    s32 i, num, unk1C;
    s32 ang, ang2;
    u16 cstat;

    spr = &gpSprite[spritenum];
    if ((spr->unk16 >= 0) || (spr->unk16 = func_8004D304(spr, 512, 19), unk1C = 0, (spr->unk16 >= 0)))
    {
        unk16 = spr->unk16;
        i = func_80058600(spr->unk16);
        spr->unk1C = (((gpSprite[unk16].z - spr->z) - i) * 2000) / ldist(&gpSprite[spritenum], &gpSprite[unk16]);
        spr->ang += getAngleDelta(spr->ang, getAngle(gpSprite[unk16].x - spr->x, gpSprite[unk16].y - spr->y)) >> 4;
        unk1C = spr->unk1C / 8;
    }

    ang = (gpSinTable[(spr->ang + 512) & 0x7FF] * 125) >> 10;
    ang2 = (gpSinTable[spr->ang & 0x7FF] * 125) >> 10;
    D_8013B2D0[spritenum].unk0 = (D_8013B2D0[spritenum].unk0 + 32) & 0x7FF;

    num = func_8004E5F8(spritenum, ang, ang2, unk1C);

    if (spr->sectnum == -1)
    {
        deleteSprite(spritenum);
        return;
    }

    cstat = spr->cstat;
    spr->cstat = cstat & ~0x101;

    getzRange(spr->x,
              spr->y,
              (spr->z - 512),
              spr->sectnum,
              &ceilz, &ceilhit, &florz, &florhit, 64, 0x01000040);

    spr->cstat = cstat;

    if (florz < spr->z)
    {
        spr->z = florz;
        func_8004BFDC(spritenum, 1, florz, 1);
        deleteSprite(spritenum);
    }
    else if (spr->z < ceilz)
    {
        spr->z = ceilz;
        if (!(gpSector[spr->sectnum].ceilingstat & 1))
            func_8004BFDC(spritenum, 1, ceilz, 1);

        deleteSprite(spritenum);
    }
    else if (num & 0xC000)
    {
        num -= 0xC000;
        if (num < 0)
        {
            num += 0xC000;
            func_8004CB3C(num);
            if ((gpWall[num & 0x7FFF].nextsector >= 0) && (gpWall[num & 0x7FFF].cstat & 0x400))
            {
                if (gpSprite[spritenum].z < gpSector[gpWall[num & 0x7FFF].nextsector].floorz)
                {
                    deleteSprite(spritenum);
                    return;
                }
            }
        }
        else
            func_80047820(spritenum, num, 75);

        func_8004BFDC(spritenum, 1, spr->z, 1);
        deleteSprite(spritenum);
    }
    else if (func_8004EFB4(spritenum) == 0)
    {
        if (D_8012FD88 & 1)
            func_800586B0(spritenum, spr->unk1A, 0xFF, 0xFF, 0xFF, 64, 40);

        if ((D_8012C470 == 1) && !(D_8012FD88 & 1) && (D_800DEEA0 != 0))
            func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 4, 0);
    }
    else if ((D_8012C470 == 1) && (D_800DEEA0 != 0))
        func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, D_8012C470, 0);
}

/*80076C14*/
STATIC void func_80076C14(s32 spritenum)
{
    s32 x1, y1, z1;
    s32 x2, y2, z2;
    s32 x3, y3, z3;
    s32 ceilz, ceilhit;
    s32 florz, florhit;
    SpriteType *spr;
    s32 i, j;
    s32 ang, ang2, ang3;
    u16 cstat;

    spr = &gpSprite[spritenum];
    x1 = 0;
    z1 = 0;
    y1 = 0;
    if (spr->unk18 == 0)
    {
        ang = (gpSinTable[(spr->ang + 512) & 0x7FF] * 575) >> 12;
        ang2 = (gpSinTable[spr->ang & 0x7FF] * 575) >> 12;

        i = func_8004E5F8(spritenum, ang, ang2, spr->unk1C);
        if (spr->sectnum == -1)
        {
            deleteSprite(spritenum);
            return;
        }

        if (D_8012C470 == 1)
        {
            func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 66, 31);
            func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 15, 31);
        }

        if (D_8012FD88 & 1)
            func_800586B0(spritenum, spr->unk2A, 0x80, 0x80, 0xFF, 48, 60);

        D_8013B2D0[spritenum].unk0 = krand() & 0x7FF;
        cstat = spr->cstat;
        spr->cstat = cstat & 0xFEFE;
        getzRange(spr->x, spr->y, (spr->z - 512), spr->sectnum,
                  &ceilz, &ceilhit, &florz, &florhit, 64, 0x01000040);

        spr->cstat = cstat;
        if ((florz < spr->z) || (spr->z < ceilz))
        {
            spr->unk25 = 0;
            spr->unk18 = 1;
            spr->cstat |= 0x8000;
        }

        if (i & 0xC000)
        {
            spr->unk18 = 1;
            spr->unk25 = 0;
            spr->cstat |= 0x8000;
        }

        if (spr->unk18 == 1)
        {
            if ((florz - spr->z) < 0x6400)
                spr->unk22 = 0;
            else
            {
                if ((spr->z - ceilz) >= 0x6400)
                    spr->unk22 = 2;
                else
                    spr->unk22 = 1;
            }

            if (spr->unk22 == 0)
                func_8008E3E0(spr->x, spr->y, (spr->z - 2048), spr->sectnum, 18, 0);
            if (spr->unk22 == 1)
                func_8008E3E0(spr->x, spr->y, (spr->z + 4096), spr->sectnum, 18, 0);
            if (spr->unk22 == 2)
                func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 18, 0);
        }
    }
    else
    {
        if (spr->unk25 < 2)
        {
            if (spr->unk1A == 0)
            {
                if (spr->unk25 == 0)
                {
                    audio_80007A44(564, spritenum, 0x20000);
                }
                else if (spr->unk25 == 1)
                {
                    func_8004AB6C(spritenum, 6000, 250, 500, 750, 1000, 1);
                    audio_80007A44(591, spritenum, 0x20000);
                }
                j = func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 30, 0);
                if (j != -1)
                {
                    gpSprite[j].unk1E = spritenum;
                    gpSprite[j].unk22 = spr->unk22;
                }
                spr->unk1A++;
            }

            if (spr->unk1A == 1)
            {
                if (D_8012C470 == 1)
                {
                    ang = krand() & 0x7FF;
                    x2 = gpSprite[spritenum].x;
                    y2 = gpSprite[spritenum].y;
                    z2 = gpSprite[spritenum].z;
                    ang2 = (krand() & 0x1FFF) + 400;
                    x3 = x2;
                    y3 = y2;
                    z3 = z2;

                    if (spr->unk22 == 0)
                    {
                        x1 = x3 + ((ang2 * gpSinTable[(ang + 512) & 0x7FF]) >> 14);
                        y1 = y3 + ((ang2 * gpSinTable[ang]) >> 14);
                        ang3 = ((krand() & 0x1FFF) - 55000);
                        z1 = z3 + ang3;
                    }
                    else if (spr->unk22 == 1)
                    {
                        spr->unk22 = 1;
                        x1 = x3 + ((ang2 * gpSinTable[(ang + 512) & 0x7FF]) >> 14);
                        y1 = y3 + ((ang2 * gpSinTable[ang]) >> 14);
                        ang3 = ((krand() & 0x1FFF) + 55000);
                        z1 = z3 + ang3;
                    }
                    else if (spr->unk22 == 2)
                    {
                        x1 = x3 + ((ang2 * gpSinTable[(ang + 512) & 0x7FF]) >> 14);
                        y1 = y3 + ((ang2 * gpSinTable[ang]) >> 14);
                        if (krand() & 1)
                        {
                            ang3 = ((krand() & 0x1FFF) + 55000);
                            z1 = z3 + ang3;
                        }
                        else
                        {
                            ang3 = ((krand() & 0x1FFF) - 55000);
                            z1 = z3 + ang3;
                        }
                    }

                    func_8004E7F0(x1, y1, z1, x3, y3, z3, 0x1F, (krand() & 0x1F) + 64, 2048, 3);
                    func_8004E7F0(x1, y1, z1, x3, y3, z3, 0x1F, (krand() & 0x1F) + 64, 2048, 3);
                }
            }
            if (spr->unk1A == 2)
            {
                spr->unk18++;
                if (spr->unk18 >= 26)
                {
                    spr->unk1A = 0;
                    spr->unk25++;
                }
            }
        }
        else
        {
            deleteSprite(spritenum);
        }
    }
}

/*80077320*/
STATIC void func_80077320(s32 spritenum)
{
    s32 ceilz, ceilhit, florz, florhit;
    SpriteType *spr;
    s32 num, ang;
    s32 x, y, z;
    u16 cstat;

    spr = &gpSprite[spritenum];
    x = spr->x;
    y = spr->y;
    z = spr->z;
    ang = (gpSinTable[(spr->ang + 512) & 0x7FF] * 625) >> 11;

    num = func_8004E5F8(spritenum,
                        ang,
                        (gpSinTable[spr->ang & 0x7FF] * 625) >> 11, spr->unk1C);

    if (spr->sectnum == -1)
    {
        deleteSprite(spritenum);
        return;
    }

    func_800722A0(spritenum);
    func_80087174(spritenum, spr->x, spr->y, spr->z, x, y, z, 128, 28);
    D_8013B2D0[spritenum].unk0 = krand() & 0x7FF;

    cstat = spr->cstat;
    spr->cstat = cstat & ~0x101;

    getzRange(spr->x,
              spr->y,
              (spr->z - 512),
              spr->sectnum,
              &ceilz, &ceilhit, &florz, &florhit, 64, 0x01000040);

    spr->cstat = cstat;

    if ((florz < spr->z) || (spr->z < ceilz))
        spr->unk18 = 1;

    if (num & 0xC000)
    {
        num -= 0xC000;
        if (num >= 0)
        {
            if (gpSprite[num].statnum != 305)
            {
                if ((krand() & 0x7FFF) < 0x1000)
                    playSfx(1348);

                if (gpSprite[num].statnum == 10)
                    func_801C363C(0, 10, 128);

                func_80047820(spritenum, num, 2);
                spr->unk18 = 1;
            }
        }
        else
            spr->unk18 = 1;
    }

    if (spr->unk18 == 1)
    {
        audio_800077F4(1568, spritenum);
        func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 77, 28);
        deleteSprite(spritenum);
    }
}

/*80077608*/
STATIC void func_80077608(s32 spritenum)
{
    s32 ceilz, ceilhit, florz, florhit;
    SpriteType *spr;
    s32 num, ang;
    s32 x, y, z;
    u16 cstat;
    s16 unk18;

    spr = &gpSprite[spritenum];
    x = spr->x;
    y = spr->y;
    z = spr->z;
    ang = (gpSinTable[(spr->ang + 512) & 0x7FF] * 625) >> 11;

    num = func_8004E5F8(spritenum, ang,
                        (gpSinTable[spr->ang & 0x7FF] * 625) >> 11, spr->unk1C);

    if (spr->sectnum == -1)
    {
        deleteSprite(spritenum);
        return;
    }

    func_800722A0(spritenum);
    func_80087174(spritenum, spr->x, spr->y, spr->z, x, y, z, 128, 1);

    if (spr->xrepeat != 0x40)
    {
        spr->xrepeat += 8;
        spr->yrepeat += 8;
    }

    D_8013B2D0[spritenum].unk0 = D_8013B2D0[spritenum].unk0 + spr->xrepeat;

    cstat = spr->cstat;
    spr->cstat = cstat & ~0x101;

    getzRange(spr->x,
              spr->y,
              (spr->z - 512),
              spr->sectnum,
              &ceilz, &ceilhit, &florz, &florhit, 64, 0x01000040);

    spr->cstat = cstat;

    if ((florz < spr->z) || (spr->z < ceilz))
        spr->unk18 = 1;

    if (num & 0xC000)
    {
        num -= 0xC000;
        if (num >= 0)
        {
            if (gpSprite[num].statnum != 305)
            {
                if ((krand() & 0x7FFF) < 0x1000)
                    playSfx(1348);

                if (gpSprite[num].statnum == 10)
                    func_801C363C(0, 10, 128);

                func_80047820(spritenum, num, 2);
                spr->unk18 = 1;
            }
        }
        else
            spr->unk18 = 1;
    }
    unk18 = spr->unk18;
    if (unk18 == 1)
    {
        func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 77, unk18);
        deleteSprite(spritenum);
    }
}

/*80077908*/
STATIC s32 func_80077908(s32 spritenum)
{
    s32 ceilz, ceilhit, florz, florhit;
    SpriteType *spr;
    s32 unk1C, num;
    s32 ang, ang2;
    u16 cstat;

    spr = &gpSprite[spritenum];
    ang = (gpSinTable[(spr->ang + 512) & 0x7FF] * 75) >> 11;
    ang2 = (gpSinTable[spr->ang & 0x7FF] * 75) >> 11;
    unk1C = spr->unk1C;
    spr->unk1C += 100;

    num = func_8004E5F8(spritenum, ang, ang2, unk1C);

    if (spr->sectnum == -1)
        return deleteSprite(spritenum);

    cstat = spr->cstat;
    spr->cstat = cstat & ~0x101;

    getzRange(spr->x,
              spr->y,
              (spr->z - 512),
              spr->sectnum,
              &ceilz, &ceilhit, &florz, &florhit, 64, 0x01000040);

    spr->cstat = cstat;

    if (florz < spr->z)
    {
        spr->z = florz;
        func_8004BFDC(spritenum, 8, spr->z, 1);
        return deleteSprite(spritenum);
    }

    if (spr->z < ceilz)
    {
        spr->z = ceilz;
        func_8004BFDC(spritenum, 8, spr->z, 1);
        return deleteSprite(spritenum);
    }

    if (!(num & 0xC000))
    {
        return -0x10000;
        do {} while (0); /*FAKEMATCH*/
    }

    num = spritenum;
    func_8004BFDC(num, 8, spr->z, 1);
    return deleteSprite(num);
}

/*80077AB0*/
STATIC void func_80077AB0(s32 spritenum)
{
    s32 ceilz, ceilhit, florz, florhit;
    SpriteType *spr;
    s32 ang, num;
    u16 cstat;

    spr = &gpSprite[spritenum];
    ang = (gpSinTable[(spr->ang + 512) & 0x7FF] * 75) >> 9;
    num = func_8004E5F8(spritenum, ang,
                        (gpSinTable[spr->ang & 0x7FF] * 75) >> 9,
                        spr->unk1C);

    if (spr->sectnum == -1)
    {
        deleteSprite(spritenum);
        return;
    }

    cstat = spr->cstat;
    spr->cstat = cstat & ~0x101;
    getzRange(spr->x,
              spr->y,
              (spr->z - 512),
              spr->sectnum,
              &ceilz, &ceilhit, &florz, &florhit, 64, 0x01000040);

    spr->cstat = cstat;

    if ((florz < spr->z) || (spr->z < ceilz))
    {
        deleteSprite(spritenum);
        return;
    }

    if (num & 0xC000)
    {
        num -= 0xC000;
        if (num >= 0)
        {
            if (gpSprite[spritenum].unk20 != num)
                func_80047820(spritenum, num, 12);
        }
        deleteSprite(spritenum);
    }
}

/*80077C70*/
STATIC void func_80077C70(s32 spritenum)
{
    s32 ceilz, ceilhit, florz, florhit;
    SpriteType *spr;
    s32 num;
    u16 cstat;

    spr = &gpSprite[spritenum];
    num = func_8004E5F8(spritenum,
                        (spr->unk18 * gpSinTable[(spr->ang + 512) & 0x7FF]) >> 14,
                        (spr->unk18 * gpSinTable[spr->ang & 0x7FF]) >> 14,
                        spr->unk1C);

    D_8013B2D0[spritenum].unk2 = (D_8013B2D0[spritenum].unk2 + 100) & 0x7FF;
    spr->unk1C += 300;

    if (spr->sectnum == -1)
    {
        deleteSprite(spritenum);
        return;
    }

    cstat = spr->cstat;
    spr->cstat = cstat & ~0x101;

    getzRange(spr->x,
              spr->y,
              (spr->z - 512),
              spr->sectnum,
              &ceilz, &ceilhit, &florz, &florhit, 64, 0x01000040);

    spr->cstat = cstat;

    if ((florz < spr->z) || (spr->z < ceilz))
    {
        func_8004BFDC(spritenum, 1, florz, 1);
        deleteSprite(spritenum);
        return;
    }

    if (num & 0xC000)
    {
        num -= 0xC000;

        if ((num >= 0) && (gpSprite[spritenum].unk20 != num))
            func_80047820(spritenum, num, 69);

        func_8004BFDC(spritenum, 1, spr->z, 1);
        deleteSprite(spritenum);
    }
}

/*80077E80*/
STATIC void func_80077E80(s32 spritenum)
{
    s32 ceilz, ceilhit, florz, florhit;
    SpriteType *spr;
    s32 ang, num;
    u16 cstat;

    spr = &gpSprite[spritenum];
    ang = (gpSinTable[(spr->ang + 512) & 0x7FF] * 125) >> 10;
    num = func_8004E5F8(spritenum,
        ang,
        (gpSinTable[spr->ang & 0x7FF] * 125) >> 10,
        spr->unk1C);

    func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 33, 0);

    if (spr->sectnum == -1)
    {
        deleteSprite(spritenum);
        return;
    }

    cstat = spr->cstat;
    spr->cstat = cstat & ~0x101;

    getzRange(spr->x,
              spr->y,
              (spr->z - 512),
              spr->sectnum,
              &ceilz, &ceilhit, &florz, &florhit, 64, 0x01000040);

    spr->cstat = cstat;

    if ((florz < spr->z) || (spr->z < ceilz))
    {
        deleteSprite(spritenum);
        return;
    }

    if (num & 0xC000)
    {
        num -= 0xC000;
        if (num >= 0)
        {
            if (gpSprite[spritenum].unk20 != num)
                func_80047820(spritenum, num, (krand() % 5) + 10);
        }
        else
            func_8004CB3C(num + 0xC000);

        deleteSprite(spritenum);
    }
}

/*800780AC*/
STATIC void func_800780AC(s32 spritenum)
{
    s16 hitsect, hitwall, hitsprite;
    s32 hitx, hity, hitz;
    SpriteType *spr;
    code0UnkStruct3 *ptr;
    s32 num;

    spr = &gpSprite[spritenum];
    ptr = &D_8019B940[D_80106D50[spr->unk20]];

    hitScan(spr->x,
            spr->y,
            spr->z,
            spr->sectnum,
            (ptr->unk44 - spr->x) / 4,
            (ptr->unk48 - spr->y) / 4,
            (ptr->unk4C - spr->z) / 4,
            &hitsect, &hitwall, &hitsprite, &hitx, &hity, &hitz, 0x10001);

    func_80087174(spritenum, spr->x, spr->y, spr->z, hitx, hity, hitz, 128, 8);
    func_8008E3E0(hitx, hity, hitz, spr->sectnum, 6, 0);
    num = func_8008E3E0(hitx, hity, hitz, spr->sectnum, 66, 8);

    if (num != -1)
    {
        gpSprite[num].xrepeat = 24;
        gpSprite[num].yrepeat = 24;
    }

    if (spr->unk22 < 4)
        spr->unk22++;
    else
        deleteSprite(spritenum);

    if ((hitwall == -1) && (hitsprite != -1) && !(D_8012FD88 & 3))
        func_80047820(spritenum, hitsprite, 1);
}

/*80078300*/
STATIC void func_80078300(s32 spritenum)
{
    s32 ceilz, ceilhit, florz, florhit;
    SpriteType *spr;
    s32 ang, num;
    u16 cstat;

    spr = &gpSprite[spritenum];
    ang = (gpSinTable[(spr->ang + 512) & 0x7FF] * 1125) >> 12;
    num = func_8004E5F8(spritenum,
                        ang,
                        (gpSinTable[spr->ang & 0x7FF] * 1125) >> 12,
                        spr->unk1C);

    if (spr->sectnum == -1)
    {
        deleteSprite(spritenum);
        return;
    }

    if (num & 0xC000)
    {
        num &= 0xFFFF;
        num -= 0xC000;
        if (num >= 0)
        {
            func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 14, 0);
            if (gpSprite[spritenum].unk20 != num)
                func_80047820(spritenum, num, (krand() % 5) + 6);
        }
        else
            func_8004CB3C(num + 0xC000);

        deleteSprite(spritenum);
        return;
    }

    cstat = spr->cstat;
    spr->cstat = cstat & ~0x101;

    getzRange(spr->x,
              spr->y,
              (spr->z - 512),
              spr->sectnum,
              &ceilz, &ceilhit, &florz, &florhit, 64, 0x01000040);

    spr->cstat = cstat;
    if ((florz < spr->z) || (spr->z < ceilz))
        deleteSprite(spritenum);
    else
        func_800586B0(spritenum, spr->unk1A, 0xFF, 0xFF, 0, 9, 8);
}

/*80078564*/
STATIC void func_80078564(s32 spritenum)
{
    s32 ceilz, ceilhit, florz, florhit;
    SpriteType *spr;
    s32 ang, num, spritenum_;
    u16 cstat;

    spr = &gpSprite[spritenum];
    ang = (gpSinTable[(spr->ang + 512) & 0x7FF] * 875) >> 11;

    num = func_8004E5F8(spritenum,
                        ang,
                        (gpSinTable[spr->ang & 0x7FF] * 875) >> 11,
                        spr->unk1C);

    if (spr->sectnum == -1)
    {
        deleteSprite(spritenum);
        return;
    }

    if (num & 0xC000)
    {
        num -= 0xC000;
        if (num >= 0)
        {
            func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 6, 0);
            if (gpSprite[spritenum].unk20 != num)
                func_80047820(spritenum, num, (krand() % 5) + 2);
        }
        else
            func_8004CB3C(num + 0xC000);

        if ((krand() & 0x7FFF) < 5000)
        {
            spritenum_ = func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 15, 0);
            if (spritenum_ != -1)
            {
                gpSprite[spritenum_].unk22 -= (krand() & 0x3FF);
                gpSprite[spritenum_].unk18 = krand() & 0x7F;
                audio_800077F4(((krand() % 4) + 577), spritenum_);
            }
        }
        deleteSprite(spritenum);
        return;
    }
    cstat = spr->cstat;
    spr->cstat = cstat & ~0x101;

    getzRange(spr->x,
              spr->y,
              (spr->z - 512),
              spr->sectnum,
              &ceilz, &ceilhit, &florz, &florhit, 64, 0x01000040);

    spr->cstat = cstat;
    if (florz < spr->z)
    {
        func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 6, 0);
        if ((krand() & 0x7FFF) < 5000)
        {
            spritenum_ = func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 15, 0);
            if (spritenum_ != -1)
            {
                gpSprite[spritenum_].unk22 -= (krand() & 0x3FF);
                gpSprite[spritenum_].unk18 = krand() & 0x7F;
                audio_800077F4(((krand() % 4) + 577), spritenum_);
            }
        }
        deleteSprite(spritenum);
    }
    else if (spr->z < ceilz)
    {
        func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 6, 0);
        deleteSprite(spritenum);
    }
    else
        func_800586B0(spritenum, spr->unk1A, 0xFF, 200, 64, 9, 6);
}

/*80078924*/
STATIC void func_80078924(s32 spritenum)
{
    s32 ceilz, ceilhit, florz, florhit;
    SpriteType *spr;
    s32 ang, ang2, num, unk1C;
    u16 cstat;
    s32 temp;

    spr = &gpSprite[spritenum];
    temp = 0x7FF; /*FAKEMATCH*/
    ang = (gpSinTable[(spr->ang + 512) & 0x7FF] * 225) >> 11;
    ang2 = (gpSinTable[spr->ang & temp] * 225) >> 11;
    unk1C = spr->unk1C;

    if (spr->unk2A != 0)
    {
        unk1C += (gpSinTable[(spr->unk18 + 512) & 0x7FF] * 25) >> 9;
        spr->unk18 += 90;
        D_8013B2D0[spritenum].unk0 = (D_8013B2D0[spritenum].unk0 + 32) & 0x7FF;
    }

    num = func_8004E5F8(spritenum, ang, ang2, unk1C);

    if (spr->sectnum == -1)
    {
        deleteSprite(spritenum);
        return;
    }

    cstat = spr->cstat;
    spr->cstat = cstat & ~0x101;

    getzRange(spr->x,
              spr->y,
              (spr->z - 512),
              spr->sectnum,
              &ceilz, &ceilhit, &florz, &florhit, 64, 0x01000040);

    spr->cstat = cstat;

    if (florz < spr->z)
    {
        spr->z = florz;
        func_8004BFDC(spritenum, 0, florz, 1);
        deleteSprite(spritenum);
    }
    else if (spr->z < ceilz)
    {
        spr->z = ceilz;
        func_8004BFDC(spritenum, 0, florz, 1);
        deleteSprite(spritenum);
    }
    else if (num & 0xC000)
    {
        num -= 0xC000;
        if (num < 0)
            func_8004CB3C(num + 0xC000);

        func_8004BFDC(spritenum, 0, florz, 1);
        deleteSprite(spritenum);
    }
    else
        func_800586B0(spritenum, spr->unk1A, 0xFF, 0xFF, 0xFF, 64, 16);
}

/*80078B70*/
STATIC void func_80078B70(s32 spritenum)
{
    s32 ceilz, ceilhit, florz, florhit;
    SpriteType *spr;
    s32 ang, ang2, num, unk1C;
    u16 cstat;

    spr = &gpSprite[spritenum];
    ang = (gpSinTable[(spr->ang + 512) & 0x7FF] * 375) >> 10;
    ang2 = (gpSinTable[spr->ang & 0x7FF] * 375) >> 10;
    unk1C = spr->unk1C;
    D_8013B2D0[spritenum].unk0 = (D_8013B2D0[spritenum].unk0 + 32) & 0x7FF;

    num = func_8004E5F8(spritenum, ang, ang2, unk1C);

    if (spr->sectnum == -1)
    {
        func_8004BD24(spritenum);
        return;
    }

    cstat = spr->cstat;
    spr->cstat = cstat & ~0x101;

    getzRange(spr->x,
              spr->y,
              (spr->z - 512),
              spr->sectnum,
              &ceilz, &ceilhit, &florz, &florhit, 64, 0x01000040);

    spr->cstat = cstat;

    if (florz < spr->z)
    {
        func_8004BFDC(spritenum, 9, florz, 1);
        func_8004BD24(spritenum);
    }
    else if (spr->z < ceilz)
    {
        func_8004BFDC(spritenum, 9, florz, 1);
        func_8004BD24(spritenum);
    }
    else if (num & 0xC000)
    {
        num -= 0xC000;
        if (num >= 0)
        {
            if (gpSprite[spritenum].unk20 != num)
                func_80047820(spritenum, num, 5000);
        }
        else
            func_8004CB3C(num + 0xC000);

        func_8004BFDC(spritenum, 9, florz, 1);
        func_8004BD24(spritenum);
    }
    else if (!(D_8012FD88 & 1))
    {
        func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 4, 0);
    }
}

/*80078DA8*/
STATIC void func_80078DA8(s32 spritenum)
{
    s32 ceilz, ceilhit, florz, florhit;
    SpriteType *spr;
    s32 ang, ang2, num, unk1C;
    u16 cstat;

    spr = &gpSprite[spritenum];
    ang = (gpSinTable[(spr->ang + 512) & 0x7FF] * 375) >> 12;
    ang2 = (gpSinTable[spr->ang & 0x7FF] * 375) >> 12;
    unk1C = spr->unk1C;
    D_8013B2D0[spritenum].unk2 = (D_8013B2D0[spritenum].unk2 + 96) & 0x7FF;
    num = func_8004E5F8(spritenum, ang, ang2, unk1C);

    if (spr->sectnum == -1)
    {
        func_8004BD24(spritenum);
        return;
    }

    cstat = spr->cstat;
    spr->cstat = cstat & ~0x101;

    getzRange(spr->x,
              spr->y,
              (spr->z - 512),
              spr->sectnum,
              &ceilz, &ceilhit, &florz, &florhit, 64, 0x01000040);

    spr->cstat = cstat;
    if ((florz < spr->z) || (spr->z < ceilz))
        func_8004BD24(spritenum);
    else if (num & 0xC000)
    {
        num -= 0xC000;
        if (num >= 0)
        {
            if (gpSprite[spritenum].unk20 != num)
                func_80047820(spritenum, num, 8);
        }
        else
            func_8004CB3C(num + 0xC000);

        func_8004BD24(spritenum);
    }
}

/*80078F84*/
STATIC void func_80078F84(s32 spritenum)
{
    s32 ceilz, ceilhit, florz, florhit;
    SpriteType *spr;
    s32 num, ang, ang2;
    u16 cstat;
    s32 temp;

    spr = &gpSprite[spritenum];
    func_8007963C(spritenum, 0);
    temp = 0x7FF; /*FAKEMATCH*/
    ang = (gpSinTable[(spr->ang + 512) & 0x7FF] * 75) >> 11;
    num = func_8004E5F8(spritenum,
                        ang,
                        (gpSinTable[spr->ang & temp] * 75) >> 11,
                        spr->unk1C);

    if (!(D_8012FD88 & 7))
        func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 1, 0);

    if (spr->sectnum == -1)
    {
        deleteSprite(spritenum);
        return;
    }

    cstat = spr->cstat;
    spr->cstat = cstat & ~0x101;

    getzRange(spr->x,
              spr->y,
              (spr->z - 512),
              spr->sectnum,
              &ceilz, &ceilhit, &florz, &florhit, 64, 0x01000040);

    spr->cstat = cstat;

    if (florz < spr->z)
    {
        spr->z = florz;
        func_8004BFDC(spritenum, 1, spr->z, 1);
        deleteSprite(spritenum);
    }
    else if (spr->z < ceilz)
    {
        spr->z = ceilz;
        func_8004BFDC(spritenum, 1, spr->z, 1);
        deleteSprite(spritenum);
    }
    else if (++spr->unk22 < 241)
    {
        if (func_8004EFB4(spritenum) != 0)
        {
            if (num & 0xC000)
            {
                num -= 0xC000;
                if (num >= 0)
                    func_80047820(spritenum, num, 25);

                func_8004BFDC(spritenum, 2, spr->z, 1);
                deleteSprite(spritenum);
            }
        }
        else
        {
            func_8004BFDC(spritenum, 2, spr->z, 1);
            deleteSprite(spritenum);
        }
    }
    else
    {
        func_8004BFDC(spritenum, 2, spr->z, 1);
        deleteSprite(spritenum);
    }
}

/*800791A8*/
STATIC void func_800791A8(s32 spritenum)
{
    s32 ceilz, ceilhit, florz, florhit;
    SpriteType *spr;
    s32 num;
    u16 cstat, cstat2;

    spr = &gpSprite[spritenum];
    num = func_8004E5F8(spritenum,
                        (spr->unk18 * gpSinTable[(spr->ang + 512) & 0x7FF]) >> 14,
                        (spr->unk18 * gpSinTable[spr->ang & 0x7FF]) >> 14,
                        spr->unk1C);

    if (spr->sectnum == -1)
    {
        func_8006B590(602);
        func_8004BD24(spritenum);
        return;
    }

    cstat = spr->cstat;
    cstat2 = gpSprite[spr->unk20].cstat;
    spr->cstat = spr->cstat & ~0x101;
    gpSprite[spr->unk20].cstat &= ~0x101;

    getzRange(spr->x,
              spr->y,
              (spr->z - 2048),
              spr->sectnum,
              &ceilz, &ceilhit, &florz, &florhit, 64, 0x10001);

    spr->cstat = cstat;
    gpSprite[spr->unk20].cstat = cstat2;
    spr->unk1C += 200;
    if (num & 0xC000)
    {
        num &= 0xFFFF;
        num -= 0xC000;
        if (num < 0)
        {
            func_8006B590(602);
            func_8004BD24(spritenum);
        }
    }
}

/*8007939C*/
STATIC void func_8007939C(s32 spritenum)
{
    SpriteType *spr;
    s32 x, y;

    spr = &gpSprite[spritenum];
    if (spr->unk22 != 0)
    {
        x = D_8019B940[D_80106D50[spritenum]].unk4C;
        y = D_8019B940[D_80106D50[spritenum]].unk50;
    }
    else
    {
        x = D_8019B940[D_80106D50[spritenum]].unk44;
        y = D_8019B940[D_80106D50[spritenum]].unk48;
    }

    gpSprite[spritenum].x = x;
    gpSprite[spritenum].y = y;
    gpSprite[spritenum].unk22 ^= 1;

    if (gpSprite[spritenum].unk25 == 0)
    {
        func_80087174(spritenum, D_8019B940[D_80106D50[spritenum]].unk44,
                      D_8019B940[D_80106D50[spritenum]].unk48,
                      gpSprite[spritenum].z,
                      D_8019B940[D_80106D50[spritenum]].unk4C,
                      D_8019B940[D_80106D50[spritenum]].unk50,
                      gpSprite[spritenum].z, 32, 8);
    }
    else
        func_800587B8(spritenum, spr->unk18, 0, 0, 0, 8, 16);
}

/*80079560*/
void func_80079560(void)
{
    _6ACA0UnkFuncPointer *ptr;
    s16 i, nexti;
    s32 j;

    i = gHeadSpriteStat[4];
    while (i >= 0)
    {
        nexti = gNextSpriteStat[i];
        D_80118248 = &gpSprite[i];
        if (D_80118248->unk1E > 0)
        {
            if (D_80118248->unk1E < 100)
            {
                if (D_80118248->unk1E < ARRAY_COUNT(D_800DF5A0))
                {
                    ptr = D_800DF5A0;
                    if (ptr[D_80118248->unk1E] != NULL)
                        ptr[D_80118248->unk1E](i);
                }
            }
            else
            {
                j = D_80118248->unk1E - 100;
                if (j < ARRAY_COUNT(D_800DF668))
                {
                    ptr = D_800DF668;
                    if (ptr[j] != NULL)
                        ptr[j](i);
                }
            }
        }
        i = nexti;
    }
}

/*8007963C*/
static void func_8007963C(s32 spritenum, s32 arg1)
{
    SpriteType *spr;
    s32 unk4A, unk1C;
    s32 dist, dist2, z;

    unk4A = gPlayer[0].unk4A;
    spr = &gpSprite[spritenum];
    z = spr->z;
    dist = ldist(spr, &gpSprite[unk4A]);
    unk1C = (((gpSprite[unk4A].z - z) - func_80058600(unk4A)) * 600) / dist;
    unk1C /= 8;
    spr->ang += (getAngleDelta(gpSprite[spritenum].ang,
        getAngle(gpSprite[unk4A].x - gpSprite[spritenum].x, gpSprite[unk4A].y - gpSprite[spritenum].y))) >> 5;

    spr->unk1C = unk1C;
    dist2 = MAX(dist / 256, 3);

    if ((dist2 > 31) && (spr->unk16 == 0))
        spr->unk16 = 31;

    if ((dist2 < 31) && (spr->unk16 == 0))
    {
        spr->unk16 = dist2;
        audio_800077F4(557, spritenum);
    }
    else
        spr->unk16--;
}
