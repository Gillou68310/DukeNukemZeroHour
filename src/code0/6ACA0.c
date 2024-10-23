#include "common.h"
#include "code0/main.h"
#include "code0/audio.h"
#include "code0/pragmas.h"
#include "code0/4600.h"
#include "code0/FDE0.h"
#include "code0/1E7A0.h"
#include "code0/2ABE0.h"
#include "code0/37090.h"
#include "code0/3FAD0.h"
#include "code0/41940.h"
#include "code0/59D40.h"
#include "code0/64530.h"
#include "code0/6ACA0.h"
#include "code0/7A430.h"
#include "code0/7BA50.h"
#include "code0/8E670.h"
#include "code0/8EFE0.h"
#include "code0/A06F0.h"
#include "code0/code0.h"
#include "code1/EB300.h"
#include "static/mapinfo.h"

/*.text*/
static void func_8006CA90(s16 arg0);
static void func_8006B384(s32 spritenum);
static void func_8006CD38(s16 playernum);

/*8006A0A0*/
void func_8006A0A0(s16 spritenum)
{
    s16 neartagsector, neartagwall, neartagsprite;
    s32 neartaghitdist, neartagrange;

    SpriteType *spr1;
    SpriteType *spr2;
    char *ptr;
    s16 *ptr2;

    s16 i, j, nextj, playernum;
    s32 unk99;

    s16 a, b, d, e;
    u32 c;

    spr1 = &gpSprite[spritenum];
    if (spr1->statnum == 10)
    {
        playernum = spr1->unk16;
        neartagrange = 768;
    }
    else
    {
        neartagrange = 1024;
        playernum = -1;
    }

    nearTag(spr1->x, spr1->y, spr1->z, spr1->sectnum, spr1->ang,
            &neartagsector, &neartagwall, &neartagsprite, &neartaghitdist, neartagrange, 3);

    if (playernum >= 0)
    {
        unk99 = gActor[gActorSpriteMap[spritenum]].unk99;
        if (unk99 == 10)
            func_8006CD38(playernum);

        if (D_8010A940[playernum].unkA[7] == 0x6000)
        {
            D_8012C989 = D_8012C989 == 0;
            playSfx(1433);
        }

        if ((neartagwall == -1) && (neartagsprite == neartagwall))
        {
            ptr2 = D_8011A680[playernum][unk99];
            a = ptr2[5];
            if (a > 0)
            {
                b = ptr2[4];
                if (b > 0)
                {
                    c = (u16)ptr2[0]; /*FAKEMATCH?*/
                    d = ptr2[1];

                    if (((c >> 2) & 1) && (unk99 != 4))
                        d = ptr2[7];

                    e = (d + b) - a;

                    if (c & 2)
                        e -= a;

                    if (e > 0)
                    {
                        if (c & 2)
                        {
                            if (unk99 == 2)
                                ptr2[3] = 40;
                            else
                                ptr2[3] = 30;
                        }
                        else
                            ptr2[3] = ptr2[2];

                        ptr2[4] = 0;
                        D_8016A154[playernum] = 1;
                    }
                }
            }
        }

        i = gHeadSpriteStat[50];
        while (i>=0)
        {
            if (gpSprite[i].unk16 == 50)
            {
                if (func_80040D40(gpSprite[i].x, gpSprite[i].y, gpSprite[spritenum].x, gpSprite[spritenum].y) < neartagrange)
                {
                    if (gActor[gActorSpriteMap[spritenum]].unk8 < gPlayer[playernum].unk48)
                    {
                        gActor[gActorSpriteMap[spritenum]].unk8++;
                        if ((krand() & 0x3FF) < 0x100)
                            audio_80008574(playernum, 1527);
                    }
                }
            }
            i = gNextSpriteStat[i];
        }
    }

    if (neartagsprite != -1)
    {
        spr2 = &gpSprite[neartagsprite];
        if (spr2->statnum == 108)
        {
            if ((playernum == -1) || (gPlayer[playernum].keys[spr2->unk25]))
            {
                switch (spr2->unk18)
                {
                case 0:
                    if (spr2->unk2B != 0)
                    {
                        spr2->unk2B = 0;
                        spr2->picnum--;
                    }
                    else
                    {
                        spr2->unk2B = 1;
                        spr2->picnum++;
                    }
                    break;
                case 1:
                    if (spr2->unk2B == 0)
                    {
                        spr2->unk2B = 1;
                        spr2->unk1A = 30;
                        spr2->picnum++;
                    }
                    else
                        return;
                    break;
                case 3:
                    break;
                case 2:
                    if (spr2->unk2B != 0)
                    {
                        spr2->unk2B = 0;
                        spr2->picnum--;
                    }
                    else
                    {
                        spr2->unk2B = 1;
                        spr2->picnum++;
                    }

                    spr2->lotag = 0;
                    changeSpriteStat(neartagsprite, 0);
                    break;
                case 4:
                    spr2->lotag = 0;
                    changeSpriteStat(neartagsprite, 0);
                    if (spr2->picnum == 2365)
                        spr2->picnum = 2411;
                    break;
                default:
                    break;
                }

                if (spr2->hitag != 0)
                    func_8006B590(spr2->hitag);
                else
                    func_8006CB38(spr2->sectnum);
            }
            else
            {
                char sp40[32];

                sprintf(sp40, "KEY WITH NO NAME REQUIRED");
                if (gpKeyStrInfo[gMapNum] != NULL)
                {
                    ptr = gpKeyStrInfo[gMapNum][spr2->unk25-1];
                    if (*ptr != 0)
                    {
#if defined(VERSION_US) || defined(VERSION_EU) || defined(VERSION_PROTO)
                        sprintf(sp40, "%s REQUIRED", ptr);
#elif VERSION_FR
                        sprintf(sp40, "%s", ptr);
#endif
                    }
                }
                func_800A419C(playernum, sp40);
#if VERSION_FR
                func_800A419C(playernum, "INDISPENSABLE");
#endif
            }
        }

        if (spr1->statnum == 10)
        {
            if (spr2->lotag == 70)
            {
                if (gPlayer[playernum].unk5A == 0)
                {
                    gPlayer[playernum].unk5A = 1;
                    gPlayer[playernum].third_person = FALSE;
                    gPlayer[playernum].unk64 = 0;
                }
            }

            if (spr2->statnum == 113)
            {
                if (gPlayer[playernum].unk52 == -1)
                    gPlayer[playernum].unk52 = gHeadSpriteStat[114];
                else
                    gPlayer[playernum].unk52 = gNextSpriteStat[gPlayer[playernum].unk52];

                while (gPlayer[playernum].unk52 >= 0)
                {
                    if (gpSprite[gPlayer[playernum].unk52].hitag != spr2->hitag)
                        gPlayer[playernum].unk52 = gNextSpriteStat[gPlayer[playernum].unk52];
                    else
                        break;
                }

                if (gPlayer[playernum].unk52 == -1)
                    playSfx(1331);
                else
                    playSfx(1330);
            }

            if ((spr2->statnum == 119) || (spr2->picnum == 2361))
                audio_800080E0(playernum, 17);

            if (spr2->statnum == 130)
            {
                changeSpriteStat(neartagsprite, 131);
                D_8013B2D0[neartagsprite].handle = audio_80008604();
            }

            if ((spr2->picnum == 2484) && (spr2->statnum == 0))
            {
                if ((gPlayer[playernum].keys[1] != 0) && (gPlayer[playernum].keys[2] != 0) && (gPlayer[playernum].keys[3] != 0))
                {
                    changeSpriteStat(neartagsprite, 120);
                    func_8006B590(spr2->hitag);
                }
            }

            if (((spr2->picnum == 1462) || (spr2->picnum == 1466)) || (spr2->picnum == 2266))
            {
                if ((gPlayer[playernum].unk58 == 0) && (gPlayer[playernum].unk5A == 0) && (gPlayer[playernum].unk59 != 0) && (gPlayer[playernum].unk86 == 0))
                {
                    gPlayer[playernum].third_person = FALSE;
                    gPlayer[playernum].unk64 = 0;
                    gPlayer[playernum].unk86 = 90;
                    audio_80008574(playernum, ((krand() % 3) + 667) & 0xFFFF);
                    func_80036520(playernum, 10);
                }
            }

            if ((spr2->picnum >= 1520) && (spr2->picnum < 1523))
                audio_80008574(playernum, 908);

            if (spr2->statnum == 301)
            {
                switch (spr2->picnum)
                {
                case 1329:
                    spr2->unk22 = 0x200;
                    break;
                case 2326:
                    if (spr2->unk2B == 0)
                    {
                        if (spr2->unk25 & 0x20)
                        {
                            if (spr1->statnum == 10)
                            {
                                char sp60[32];
#if defined(VERSION_US) || defined(VERSION_EU) || defined(VERSION_PROTO)
                                sprintf(sp60, "PULL SWITCHES TOGETHER");
#elif VERSION_FR
                                sprintf(sp60, "ACTIVEZ INTERRUPTEURS ENSEMBLE");
#endif
                                func_800A419C(playernum, sp60);
                            }
                        }
                        else if (!(spr2->unk25 & 8))
                        {
                            if (!(spr2->unk25 & 0x10))
                            {
                                audio_800077F4(222, neartagsprite);
                                if (spr2->hitag != 0)
                                    func_8006B590(spr2->hitag);
                                else
                                    func_8006CB38(spr2->sectnum);
                            }
                        }
                    }
                    break;
                case 2261:
                case 2324:
                    if (spr2->unk2B == 0)
                    {
                        audio_800077F4(222, neartagsprite);
                        if (spr2->hitag != 0)
                            func_8006B590(spr2->hitag);
                        else
                            func_8006CB38(spr2->sectnum);
                    }
                    break;
                }
            }
        }
        else if ((spr2->picnum == 2326) && (spr2->unk2B == 0) && (spr2->unk25 & 32))
        {
            spr2->unk2B = 1;
            j = gHeadSpriteStat[301];
            while (j>=0)
            {
                nextj = gNextSpriteStat[j];
                if ((gpSprite[j].hitag == spr2->hitag))
                {
                    audio_800077F4(222, j);
                    if (gpSprite[j].picnum == 2326)
                    {
                        if (gpSprite[j].unk25 & 0x10)
                        {
                            gpSprite[j].unk25 = 0;
                            break;
                        }
                    }
                }
                j = nextj;
            }
        }

        if (spr2->statnum == 302)
        {
            switch (spr2->picnum)
            {
            case 1405:
                if ((spr2->hitag != 0) && (spr2->unk2B == 0) && (spr1->statnum != 10))
                    spr2->unk2B = 1;
                break;
            case MARINE:
            case SERGEANT:
                switch (spr2->unk2B)
                {
                case 10:
                case 11:
                    spr2->unk2B = 12;
                    break;
                case 20:
                case 21:
                    spr2->unk2B = 25;
                    break;
                case 0:
                    spr2->unk2B = 35;
                    break;
                case 40:
                case 41:
                    spr2->unk2B = 45;
                    break;
                }
                break;
            }
        }
    }

    if (neartagwall != -1)
    {
        if (gpWall[neartagwall].unk14 == 66)
        {
            if (gpWall[neartagwall].unk16 != 0)
                func_8006B590(gpWall[neartagwall].unk16);
            else
            {
                if (gpWall[neartagwall].nextsector != -1)
                    func_8006CB38(gpWall[neartagwall].nextsector);
                else
                    func_8006CB38(gpWall[neartagwall].sectnum);
            }
        }

        if ((spr1->statnum == 10) && (gpWall[neartagwall].unk14 == 119))
            audio_800080E0(playernum, 17);
    }
}

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
        switch (spr->lotag)
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
        if (gpSprite[i].hitag == arg0)
        {
            switch (gpSprite[i].lotag)
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
            gActor[gActorSpriteMap[spritenum]].unk64 = D_800FF528[gActor[gActorSpriteMap[spritenum]].unk84];
            gActor[gActorSpriteMap[spritenum]].unk4 |= 0x40;
            gpSprite[spritenum].unk16 = i;
        }
    }
}

/*8006B4E4*/
void func_8006B4E4(s16 arg0)
{
#if defined(VERSION_US) || defined(VERSION_EU) || defined(VERSION_PROTO)
    func_800A419C(0, "OBJECTIVE COMPLETED");
#elif VERSION_FR
    func_800A419C(0, "OBJECTIF ATTEINT");
#endif
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
    Actor *actor;
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
            if (gpSprite[i].hitag == arg0)
                func_8006AD70(i);

            i = gNextSpriteStat[i];
        }

        i = gHeadSpriteStat[1];
        while (i >= 0)
        {
            nexti = gNextSpriteStat[i];
            if (gpSprite[i].hitag == arg0)
                gActor[gActorSpriteMap[i]].flag |= 0x400000;

            if ((gpSprite[i].lotag == arg0) &&
                ((gpSprite[i].picnum == CERBERUSTURRETS) || (gpSprite[i].picnum == GORGONTURRETS) ||
                    (gpSprite[i].picnum == SENTRYGUNS1) || (gpSprite[i].picnum == SENTRYGUNS2)))
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
            if (((gpSprite[i].picnum == CERBERUSTURRETS) || (gpSprite[i].picnum == GORGONTURRETS) ||
                (gpSprite[i].picnum == SENTRYGUNS1) || (gpSprite[i].picnum == SENTRYGUNS2)) &&
                 (gpSprite[i].lotag == arg0))
            {
                if (gpSprite[i].unk25 == 1)
                {
                    actor = &gActor[gActorSpriteMap[i]];
                    if (actor->unk70 != 0)
                    {
                        MusHandleStop(actor->unk70, 0);
                        actor->unk70 = 0;
                    }

                    if (actor->unk6C != 0)
                    {
                        MusHandleStop(actor->unk6C, 0);
                        actor->unk6C = 0;
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
                if ((gpSprite[i].picnum == CERBERUSTURRETS) || (gpSprite[i].picnum == GORGONTURRETS) ||
                     (gpSprite[i].picnum == SENTRYGUNS1) || (gpSprite[i].picnum == SENTRYGUNS2))
                {
                    if ((gpSprite[i].lotag == arg0) && (gpSprite[i].unk25 == 1))
                    {
                        changeSpriteStat(i, 1);
                        cond = 2;
                    }
                }
                i = nexti;
            }
        }

#if defined(VERSION_US) || defined(VERSION_EU) || defined(VERSION_PROTO)
        if (cond == 1)
            func_800A419C(0, "DEFENSE SYSTEMS INACTIVE");
        if (cond == 2)
            func_800A419C(0, "DEFENSE SYSTEMS ACTIVE");
#elif VERSION_FR
        if (cond == 1)
            func_800A419C(0, "SYSTEMES DE DEFENSE DESACTIVES");
        if (cond == 2)
            func_800A419C(0, "SYSTEMES DE DEFENSE ACTIVES");
#endif

        i = gHeadSpriteStat[4];
        while (i >= 0)
        {
            nexti = gNextSpriteStat[i];
            if ((gpSprite[i].hitag == arg0) && (gpSprite[i].picnum == 1841) && (gpSprite[i].unk2B == 0xFF))
                gpSprite[i].unk2B = 0;

            i = nexti;
        }

        i = gHeadSpriteStat[20];
        while (i >= 0)
        {
            nexti = gNextSpriteStat[i];
            if (gpSprite[i].hitag == arg0)
                func_8006B278(i);
            i = nexti;
        }

        i = gHeadSpriteStat[21];
        while (i >= 0)
        {
            nexti = gNextSpriteStat[i];
            if (gpSprite[i].hitag == arg0)
                func_8004EA40(i);

            i = nexti;
        }

        i = gHeadSpriteStat[152];
        while (i >= 0)
        {
            nexti = gNextSpriteStat[i];
            if (gpSprite[i].hitag == arg0)
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
            if (gpSprite[i].hitag == arg0)
                changeSpriteStat(i, 57);

            i = nexti;
        }

        i = gHeadSpriteStat[301];
        while (i >= 0)
        {
            nexti = gNextSpriteStat[i];
            if (gpSprite[i].hitag == arg0)
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
            if (gpSprite[i].hitag == arg0)
            {
                switch (gpSprite[i].picnum)
                {
                case 2341:
                    gpSprite[i].unk2B++;
                    break;

                case MARINE:
                case SERGEANT:
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
            if (gpSprite[i].hitag == arg0)
                gpSprite[i].unk25 ^= 1;

            i = nexti;
        }

        i = gHeadSpriteStat[305];
        while (i >= 0)
        {
            nexti = gNextSpriteStat[i];
            if ((gpSprite[i].hitag == arg0) && (gpSprite[i].picnum == BOSSCYBORGSCORPION) && (gpSprite[i].unk2B == 0))
                gpSprite[i].unk2B = 1;

            i = nexti;
        }

        i = gHeadSpriteStat[667];
        while (i >= 0)
        {
            nexti = gNextSpriteStat[i];
            if (gpSprite[i].hitag == arg0)
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
            if (gpSprite[i].hitag == arg0)
            {
                j = D_800DEE80;
                func_8005E4C4(-1, 1);
                gPlayer[0].unk52 = i + 0x1000;
                D_800DEE80 = j;
                D_800DEE70 = gpSprite[i].lotag;
                changeSpriteStat(i, 0);
            }
            i = nexti;
        }

        i = gHeadSpriteStat[118];
        while (i >= 0)
        {
            nexti = gNextSpriteStat[i];
            if (gpSprite[i].hitag == arg0)
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
            if (gpSprite[i].hitag == arg0)
            {
                switch (gpSprite[i].unk25)
                {
                case 0:
                    func_8006B4E4(gpSprite[i].lotag);
                    deleteSprite(i);
                    break;

                case 1:
                    k = -1;
                    for (j = 1; j < ARRAY_COUNT(D_801AE91E); j++)
                    {
                        if (D_801AE91E[j] != 68)
                        {
                            if (D_801AE91E[j] == 67)
                                k = j;

                            D_801AE91E[j] = 83;
                        }
                    }

                    if (D_801AE91E[gpSprite[i].lotag] != 68)
                    {
                        if (gMapNum == MAP_BASE)
                        {
                            if (gpSprite[i].lotag == 1)
                            {
                                D_800E192C = -1;
                                D_80138678 = D_801A1958.unkC;
                                playSfx(554);
                            }
                        }

                        if (gpSprite[i].lotag != k)
                        {
#if defined(VERSION_US) || defined(VERSION_EU) || defined(VERSION_PROTO)
                            func_800A419C(0, "NEW OBJECTIVE");
#elif VERSION_FR
                            func_800A419C(0, "NOUVEL OBJECTIF");
#endif
                        }
                        D_801AE91E[gpSprite[i].lotag] = 67;
                    }
                    break;

                case 2:
                    for (j = 1; j < ARRAY_COUNT(D_801AE91E); j++)
                    {
                        if (D_801AE91E[j] != 68)
                            D_801AE91E[j] = 83;
                    }

                    D_80138678 = -1;
                    D_800E192C = -1;
                    if (gMapNum == MAP_NUCLEAR_WINTER)
                    {
#if defined(VERSION_US) || defined(VERSION_EU) || defined(VERSION_PROTO)
                        func_800A419C(0, "NEW OBJECTIVE");
#elif VERSION_FR
                        func_800A419C(0, "NOUVEL OBJECTIF");
#endif
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
            if (gpSprite[i].hitag == arg0)
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
            if ((gpSprite[i].hitag == arg0) && (gpSprite[i].unk16 == 52))
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
            if ((gpSprite[i].hitag == arg0) && (gpSprite[i].picnum >= 2520) && (gpSprite[i].picnum < 2530))
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
                if (gpSprite[i].hitag == arg0)
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
                        gpSprite[i].hitag = 0;
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
            D_8013B2D0[spritenum].handle = audio_80007820(gpSprite[spritenum].lotag, spritenum);
            break;
        case 29:
            audio_80008574(0, gpSprite[spritenum].lotag);
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
            if (gpSprite[i].hitag == arg0)
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
            gpSprite[i].unk24 = !gpSprite[i].unk24;
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
        if (gpSprite[i].lotag == 10)
        {
            if (gPlayer[playernum].unk4A == gpSprite[i].hitag)
                gpSprite[i].unk22 = 1;
        }
        i = gNextSpriteStat[i];

    }
}
