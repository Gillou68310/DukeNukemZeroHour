#include "common.h"
#include "code0/main.h"
#include "code0/engine.h"
#include "code0/pragmas.h"
#include "code0/audio.h"
#include "code0/4590.h"
#include "code0/9410.h"
#include "code0/17B30.h"
#include "code0/37090.h"
#include "code0/3FAD0.h"
#include "code0/41940.h"
#include "code0/609D0.h"
#include "code0/64530.h"
#include "code0/6ACA0.h"
#include "code0/7A430.h"
#include "code0/7F6A0.h"
#include "code0/8E670.h"
#include "code0/8EFE0.h"
#include "code0/95500.h"
#include "code0/A06F0.h"
#include "code0/code0.h"
#include "code1/EB300.h"

typedef struct {
    /*0x00*/ u8 unk0;
    /*0x02*/ s16 unk2;
    /*0x04*/ s16 unk4;
} _37090UnkStruct;

/*.data*/
/*800DEDC0*/ static s8 D_800DEDC0 = 0;
/*800DEDC4*/ static u8 D_800DEDC4[4] = {0};
/*800DEDC8*/ static u8 D_800DEDC8[4] = {0};
/*800DEDCC*/ static u8 D_800DEDCC[4] = {0};
/*800DEDD0*/ static u8 D_800DEDD0[4] = {0};
/*800DEDD4*/ static u8 D_800DEDD4[4] = {0};
/*800DEDD8*/ static u8 D_800DEDD8[4] = {0};
/*800DEDDC*/ static u8 D_800DEDDC[4] = {0};
/*800DEDE0*/ u8 D_800DEDE0 = 0;

/*800DEDE4*/
static s16 D_800DEDE4[24] = {
    -1,
    -1,
    1792,
    1852,
    1797,
    1858,
    1803,
    1879,
    1808,
    1914,
    1816,
    -1,
    1868,
    1872,
    1841,
    1820,
    1884,
    1829,
    1834,
    1834,
    1863,
    1846,
    1852,
    1910,
};

/*800DEE14*/
static _37090UnkStruct D_800DEE14[13] = {
    { 3, 520, 647 },
    { 3, 525, 525 },
    { 3, 1017, 655 },
    { 3, 528, 658 },
    { 2, 523, 653 },
    { 4, 720, 724 },
    { 4, 1092, 1141 },
    { 5, 1087, 1136 },
    { 4, 1021, 1132 },
    { 2, 1616, 1618 },
    { 3, 1025, 1123 },
    { 3, 1636, 1642 },
    { 3, 1639, 1645 },
};

/*800DEE64*/ static u32 D_800DEE64 = 0;

/*.comm*/
/*8011BC44*/ Actor *_pActor2;
/*80138850*/ u8 D_80138850;
/*80199520*/ u8 D_80199520[MAXPLAYERS];

/*.text*/
static void func_8003DDB8(void);
static void func_8003E8D0(void);

/*80036490*/
s32 func_80036490(s16 sectnum)
{
    s16 i;

    i = gHeadSpriteSect[sectnum];
    while (i >= 0)
    {
        if (gpSprite[i].picnum == 15)
        {
            D_8012D338 = gpSprite[i].ang;
            return gpSprite[i].z;
        }
        i = gNextSpriteSect[i];
    }
    return -1;
}

/*80036520*/
void func_80036520(s16 playernum, s16 arg1)
{
    s32 i;

    i = gActorSpriteMap[gPlayer[playernum].unk4A];
    if (gActor[i].unk8 > 0)
    {
        if (gActor[i].unk8 < gPlayer[playernum].unk48)
            gActor[i].unk8 = MIN(gPlayer[playernum].unk48, (gActor[i].unk8 + arg1));
    }
}

/*800365C0*/
void func_800365C0(s16 playernum)
{
    if (!gPlayer[playernum].unk45)
    {
        gActor[gActorSpriteMap[gPlayer[playernum].unk4A]].unk8 = 0;
        gActor[gActorSpriteMap[gPlayer[playernum].unk4A]].unk9E = -3;
        gPlayer[playernum].unk45 = 3;
        gPlayer[playernum].unk4E = 0;
        playSfx(krand() % 3 + 538);
        gpSprite[gPlayer[playernum].unk4A].cstat = 0x8000;
    }
}

/*8003671C*/
void func_8003671C(s16 playernum, u16 arg1, s16 arg2, s16 arg3)
{
    char buf[48];
    Actor *actor;
    s32 m, n;
    s16 playernum2;
    s16 i, j;
    u8 r, g, b;

    actor = &gActor[gActorSpriteMap[gPlayer[playernum].unk4A]];
    if ((gPlayer[playernum].unk52 < 0x800) && (D_800E1748 < 0))
    {
        if (arg3 == 30)
        {
            playSfx(1593);
            gPlayer[playernum].unk82 = 240;
        }

        if ((arg1 != 0) && (gInvulnerability == 0))
        {
            if (actor->unk8 <= 0)
            {
                actor->unk8 = 0;
                return;
            }

            if ((D_801AD470 != 4) ||
                (gConfig.multiplayer.friendly_fire != CONFIG_OFF) ||
                (gpSprite[arg2].statnum != 10) ||
                (D_800E16A0[gpSprite[arg2].unk16] != D_800E16A0[playernum]))
            {
                if (arg1 > 1000)
                    arg1 = 1000;

                actor->unk9E = arg3;
                if (arg1 > 30)
                    D_801AC9F8 = 15;

                gPlayer[playernum].unk52 = -1;
                gPlayer[playernum].unk4E = 0;
                D_801A2790[playernum].unk20 = 0;

                if (arg2 >= 0)
                {
                    if ((arg3 == 9) || (arg3 == 44))
                    {
                        if (D_8010A940[playernum].unk2[6] != 0)
                            return;
                    }
                    else
                    {
                        if (actor->unk7E > 0)
                        {
                            m = (arg1 * actor->unk7E) / 100;
                            n = 1;
                            if (m > 0)
                                n = m;

                            arg1 -= n;
                            actor->unk7E -= n;
                            if (actor->unk7E < 0)
                            {
                                arg1 -= actor->unk7E;
                                actor->unk7E = 0;
                            }
                        }
                    }
                }

                actor->unk8 -= arg1;
                func_801C363C(playernum, 10, CLAMP_MAX((arg1*6), 0xFF));

                switch (arg3)
                {
                case 9:
                case 30:
                case 44:
                    r = 8;
                    g = 0xFF;
                    b = 0x31;
                    break;
                case 15:
                    r = 0;
                    g = 0xFF;
                    b = 0xFF;
                    if (random(100) > actor->unk8)
                        actor->unk8 = 0;
                    break;
                case 20:
                    r = krand() | 0x80;
                    g = 0xFF;
                    b = 0xFF;
                    break;
                case 21:
                    r = 0x8C;
                    g = 8;
                    b = 0xFF;
                    break;
                default:
                    r = 0xFF;
                    g = 0;
                    b = 0;
                    break;
                }
                func_8000EB90(playernum, r, g, b, 0xA0);

                if (actor->unk8 <= 0)
                {
                    actor->unk8 = 0;
                    if (arg2 >= 0)
                    {
                        if (arg3 == 21)
                        {
                            gpSprite[gPlayer[playernum].unk4A].cstat |= 0x800;
                            gpSprite[gPlayer[playernum].unk4A].unk25 = 0x1F;
                        }

                        if (arg3 == 15)
                            actor->flag |= 0x40;

                        if (gpSprite[arg2].statnum == 10)
                        {
                            playernum2 = gpSprite[arg2].unk16;
                            if (playernum2 != playernum)
                            {
                                audio_800080E0(playernum2, 6);

                                D_800FF4F0[playernum2].unk4[playernum]++;
                                if (D_801AD470 == 4)
                                {
                                    for (i = 0; i < gPlayerCount; i++)
                                    {
                                        if (D_800E16A0[i] == D_800E16A0[playernum2])
                                        {
                                            if (D_800E16A0[i] == D_800E16A0[playernum])
                                                D_800FF4F0[i].unk2++;
                                            else
                                                D_800FF4F0[i].unk0++;
                                        }
                                    }
                                }
                                else
                                {
                                    D_800FF4F0[playernum2].unk0++;
                                    if ((D_801AD470 == 3) && ((playernum == D_800FE9D0) || (D_800FE9D0 == -1)))
                                    {
                                        D_800FE9D0 = playernum2;
                                        D_800FF4F0[playernum2].unk0 += 4;
                                    }
                                }

#if VERSION_FR
                                sprintf(buf, "JOUEUR %d TUE\n", playernum + 1);
                                func_800A419C(playernum2, buf);
                                sprintf(buf, "TUE PAR JOUEUR %d", playernum2 + 1);
                                func_800A419C(playernum, buf);
#else
                                sprintf(buf, "KILLED PLAYER %d\n", playernum + 1);
                                func_800A419C(playernum2, buf);
                                sprintf(buf, "KILLED BY PLAYER %d", playernum2 + 1);
                                func_800A419C(playernum, buf);
#endif                        
                                return;
                            }
                        }
                        else
                        {
                            if (gActorSpriteMap[arg2] != -1)
                                gActor[gActorSpriteMap[arg2]].flag |= 0x10000;
                        }
                    }

                    D_800FF4F0[playernum].unk2++;
                    if (D_801AD470 == 4)
                    {
                        for (j = 0; j < gPlayerCount; j++)
                        {
                            if ((D_800E16A0[j] == D_800E16A0[playernum]) && (j != playernum))
                                D_800FF4F0[j].unk2++;
                        }
                    }

                    D_800FF4F0[playernum].unk4[playernum]++;
                    if (playernum == D_800FE9D0)
                        D_800FE9D0 = -1;
                }
                else
                {
                    if ((arg2 >= 0) && ((krand() & 0x3FF) > 0x300))
                        audio_800080E0(playernum, 2);
                    else
                    {
                        if ((arg3 == 9) || (arg3 == 44))
                            audio_800080E0(playernum, 19);
                        else
                        {
                            if (actor->unk8 > 70)
                                audio_800080E0(playernum, 8);
                            else if (actor->unk8 > 30)
                                audio_800080E0(playernum, 9);
                            else
                                audio_800080E0(playernum, 10);
                        }
                    }
                }
            }
        }
    }
}

/*80036FEC*/
static void func_80036FEC(void)
{
    s16 spritenum;
    s32 z;
    u8 cond;
    u16 cstat;

    if (gPlayer[gPlayerNum].unk45 || D_80106D30[gPlayerNum])
        D_800DD448 = 1;

    cstat = gpSprite[gPlayer[gPlayerNum].unk4A].cstat;
    gpSprite[gPlayer[gPlayerNum].unk4A].cstat = cstat & ~0x101;

    getzRange(gPlayer[gPlayerNum].xpos,
              gPlayer[gPlayerNum].ypos,
              gPlayer[gPlayerNum].zpos + gPlayer[gPlayerNum].unk40 / 2,
              gPlayer[gPlayerNum].cursectnum,
              &D_801A1998,
              &D_801AE9C0,
              &D_80138860,
              &D_800FCBE0,
              0x40, 0x10001U);

    gpSprite[gPlayer[gPlayerNum].unk4A].cstat = cstat;
    D_800DD448 = 0;

    cond = 1;
    if (gpSector[gPlayer[gPlayerNum].cursectnum].ceilingstat & 1)
        cond = D_801AE9C0 >= 0xC000;

    if (cond && (gPlayer[gPlayerNum].unk45 == 0) &&
        (D_80106D30[gPlayerNum] == 0) &&
        ((D_80138860 - D_801A1998) < (gPlayer[gPlayerNum].unk40 / 2)))
        func_800365C0(gPlayerNum);

    D_80129804 = getFlorzOfSlope(gPlayer[gPlayerNum].cursectnum,
                                 gPlayer[gPlayerNum].xpos,
                                 gPlayer[gPlayerNum].ypos) - gPlayer[gPlayerNum].unk40;

    D_8012EB4C = getCeilzOfSlope(gPlayer[gPlayerNum].cursectnum,
                                 gPlayer[gPlayerNum].xpos,
                                 gPlayer[gPlayerNum].ypos) + 1024;

    D_80138860 -= gPlayer[gPlayerNum].unk40;
    D_801A1998 += 1024;
    gPlayer[gPlayerNum].unk36 = gPlayer[gPlayerNum].cursectnum;

    if (D_800FCBE0 >= 0x4000 && D_800FCBE0 < 0xC000)
        gPlayer[gPlayerNum].unk36 = (D_800FCBE0 - 0x4000);

    if (D_800FCBE0 >= 0xC000)
    {
        gPlayer[gPlayerNum].unk36 = D_800FCBE0 + 0x5000;
        spritenum = D_800FCBE0 + 0x4000;
        if ((gPlayer[gPlayerNum].unk59) && (gpSprite[spritenum].statnum == 1))
            gActor[gActorSpriteMap[spritenum]].unk94 |= 1;
    }

    gPlayer[gPlayerNum].unk56 = 0;
    if (gpSector[gPlayer[gPlayerNum].cursectnum].unk18 == 1)
    {
        if (D_80138860 == D_80129804)
        {
            D_80138860 = D_80138860 + 0x2600;
            if (gPlayer[gPlayerNum].zpos >= D_80138860)
            {
                gPlayer[gPlayerNum].zpos = D_80138860;
                gPlayer[gPlayerNum].unk56 = 1;
            }
        }
        D_80129804 = D_80129804 + 0x2600;
    }

    if ((gpSector[gPlayer[gPlayerNum].cursectnum].unk18 == 3) && (gPlayer[gPlayerNum].zvect <= 0))
    {
        z = func_80036490(gPlayer[gPlayerNum].cursectnum);
        if ((gPlayer[gPlayerNum].zpos >= (z - 0x1300)) && (gPlayer[gPlayerNum].zpos < z))
        {
            gPlayer[gPlayerNum].unk56 = 1;
            gPlayer[gPlayerNum].zpos = (z - 0x1300);
        }
    }

    if (gpSector[gPlayer[gPlayerNum].cursectnum].unk18 == 4)
    {
        if (D_80138860 == D_80129804)
            D_80138860 = D_80129804 + 0x1000;
        D_80129804 = D_80129804 + 0x1000;
    }

    if (gpSector[gPlayer[gPlayerNum].cursectnum].unk18 == 5)
    {
        if (D_80138860 == D_80129804)
            D_80138860 = D_80129804 + 0x2600;
        D_80129804 = D_80129804 + 0x2600;
    }

    if (gpSector[gPlayer[gPlayerNum].cursectnum].unk18 == 6)
    {
        if (D_80138860 == D_80129804)
            D_80138860 = D_80129804 + 0x1000;
        D_80129804 = D_80129804 + 0x1000;
    }
}

/*8003779C*/
static s32 func_8003779C(u8 arg0)
{
    return gButton[gPlayerNum] & D_8012D218[gPlayerNum][arg0];
}

/*800377E8*/
static s16 func_800377E8(void)
{
    s16 ang, dist;

    D_8012F914[gPlayerNum] = -1;
    if (gpSprite[D_800DEE80].unk25 != 0)
    {
        gPlayer[gPlayerNum].xpos = gpSprite[D_800DEE80].x;
        gPlayer[gPlayerNum].ypos = gpSprite[D_800DEE80].y;
        gPlayer[gPlayerNum].zpos = gpSprite[D_800DEE80].z;
        gPlayer[gPlayerNum].ang = gpSprite[D_800DEE80].ang;
        gPlayer[gPlayerNum].cursectnum = gpSprite[D_800DEE80].sectnum;
        gPlayer[gPlayerNum].unk3E = 0;
        return 0;
    }

    gPlayer[gPlayerNum].unk3E /= 2;
    dist = ldist(&gpSprite[D_800DEE80], &gpSprite[gPlayer[gPlayerNum].unk4A]);

    if (dist < 512)
    {
        ang = gpSprite[D_800DEE80].ang - gPlayer[gPlayerNum].ang;

        if (ang > 1024)
            ang -= 2048;
        if (ang < -1024)
            ang += 2048;

        gPlayer[gPlayerNum].ang += ang / 8;
        gPlayer[gPlayerNum].xpos += (gpSprite[D_800DEE80].x - gPlayer[gPlayerNum].xpos) / 4;
        gPlayer[gPlayerNum].ypos += (gpSprite[D_800DEE80].y - gPlayer[gPlayerNum].ypos) / 4;
        return 0;
    }
    ang = getAngle(gpSprite[D_800DEE80].x - gPlayer[gPlayerNum].xpos,
                   gpSprite[D_800DEE80].y - gPlayer[gPlayerNum].ypos);

    ang -= gPlayer[gPlayerNum].ang;

    if (ang > 1024)
        ang -= 2048;
    if (ang < -1024)
        ang += 2048;

    gPlayer[gPlayerNum].ang = (gPlayer[gPlayerNum].ang + (ang / 3)) & 0x7FF;
    D_80119A30[gPlayerNum] |= 1;

    if (dist < 1024)
        return 13;
    else
        return 20;
}

/*80037B84*/
static void func_80037B84(void)
{
    SpriteType *spr;
    f32 f1;
    s32 i, j, k, l, m, n, o;
    s32 x1, y1, x2, y2;
    s32 ang;
    s16 a;

    D_80119A30[gPlayerNum] = 0;
    i = 0;
    j = 0;
    if (D_800DEE80 >= 0)
        i = func_800377E8();
    else
    {
        if (D_80106D30[gPlayerNum] != 0)
        {
            if (D_80199520[gPlayerNum] == 0)
            {
                if (D_80106D30[gPlayerNum] == 1)
                {
                    if (gStickX[gPlayerNum] > 32)
                    {
                        gPlayer[gPlayerNum].skin++;

                        if (gPlayer[gPlayerNum].skin >= D_80138780)
                            gPlayer[gPlayerNum].skin = 0;

                        while (!(gUnlockedSkin & (1 << gPlayer[gPlayerNum].skin)))
                        {
                            gPlayer[gPlayerNum].skin++;
                            if (gPlayer[gPlayerNum].skin >= D_80138780)
                                gPlayer[gPlayerNum].skin = 0;
                        }
                        D_80199520[gPlayerNum] = 10;
                        playSfx(1367);
                    }

                    if (gStickX[gPlayerNum] < -32)
                    {
                        gPlayer[gPlayerNum].skin--;

                        if (gPlayer[gPlayerNum].skin < 0)
                            gPlayer[gPlayerNum].skin = D_80138780 - 1;

                        while (!(gUnlockedSkin & (1 << gPlayer[gPlayerNum].skin)))
                        {
                            gPlayer[gPlayerNum].skin--;
                            if (gPlayer[gPlayerNum].skin < 0)
                                gPlayer[gPlayerNum].skin = D_80138780 - 1;
                        }
                        D_80199520[gPlayerNum] = 10;
                        playSfx(1367);
                    }
                }
                else
                {
                    if (klabs(gStickX[gPlayerNum]) > 32)
                    {
                        D_800E16A0[gPlayerNum] = D_800E16A0[gPlayerNum] == 0;
                        D_80199520[gPlayerNum] = 10;
                        playSfx(1367);
                    }
                }
            }

            if (klabs(gStickX[gPlayerNum]) < 32)
                D_80199520[gPlayerNum] = 0;

            D_80199520[gPlayerNum] = CLAMP_MIN((D_80199520[gPlayerNum]-1), 0);
            gpSprite[gPlayer[gPlayerNum].unk4A].picnum = D_8012F6E4[gPlayer[gPlayerNum].skin].picnum;
            func_8008E04C(gPlayerNum);
        }

        if (D_80138850 == 0)
            return;

        if (D_8012F914[gPlayerNum] == -1)
        {
            if (!(gPlayer[gPlayerNum].unk80 & 1))
            {
                if (func_8003779C(11) != 0)
                {
                    i += 40;
                    D_80119A30[gPlayerNum] |= 1;
                }

                if (func_8003779C(12) != 0)
                {
                    i -= 40;
                    D_80119A30[gPlayerNum] |= 2;
                }
            }
            else if (func_8003779C(15) == 0)
            {
                if (gStickY[gPlayerNum] > 32)
                {
                    i += 40;
                    D_80119A30[gPlayerNum] |= 1;
                }
                if (gStickY[gPlayerNum] < -32)
                {
                    i -= 40;
                    D_80119A30[gPlayerNum] |= 2;
                }
            }

            if (func_8003779C(13) != 0)
            {
                j += 40;
                D_80119A30[gPlayerNum] |= 8;
            }

            if (func_8003779C(14) != 0)
            {
                j -= 40;
                D_80119A30[gPlayerNum] |= 4;
            }

            if (i == 0)
                D_80119A30[gPlayerNum] &= ~3;

            if (j == 0)
                D_80119A30[gPlayerNum] &= ~0xC;
        }

        if (D_80119A30[gPlayerNum] != 0)
        {
            if (gPlayer[gPlayerNum].unk52 < 0x800)
                gPlayer[gPlayerNum].unk52 = -1;
        }

        if ((i != 0) && (j != 0))
        {
            i *= 0.707;
            j *= 0.707;
        }

        k = 0;
        if (gPlayer[gPlayerNum].unk58 != 0)
        {
            D_80119A30[gPlayerNum] = 0;
            D_800DEDC0 = 0;

            if (i > 0)
            {
                D_800DEDC0 = 1;
                D_80119A30[gPlayerNum] = 1;
            }

            if (i < 0)
            {
                D_800DEDC0 = -1;
                D_80119A30[gPlayerNum] = 2;
            }

            j = 0;
            i = 0;
            if (gPlayer[gPlayerNum].unk5E < 0x1000)
            {
                x1 = gpWall[gPlayer[gPlayerNum].unk5E].x;
                y1 = gpWall[gPlayer[gPlayerNum].unk5E].y;
                x2 = gpWall[gpWall[gPlayer[gPlayerNum].unk5E].point2].x;
                y2 = gpWall[gpWall[gPlayer[gPlayerNum].unk5E].point2].y;
                ang = (getAngle(x2 - x1, y2 - y1) + 0x200) & 0x7FF;
                x1 = (x1 + x2) / 2;
                y1 = (y1 + y2) / 2;
                a = 0x100;
            }
            else
            {
                ang = gpSprite[(s16)(gPlayer[gPlayerNum].unk5E - 0x1000)].ang;
                x1 = gpSprite[(s16)(gPlayer[gPlayerNum].unk5E - 0x1000)].x;
                y1 = gpSprite[(s16)(gPlayer[gPlayerNum].unk5E - 0x1000)].y;
                a = 0x100;
            }

            l = ang;
            m = ((ang + 0x400) & 0x7FF);
            m -= gPlayer[gPlayerNum].ang;
            if (m > 0x400)
                m -= 0x800;

            if (m < -0x400)
                m += 0x800;

            gPlayer[gPlayerNum].ang = (gPlayer[gPlayerNum].ang + (m / 2)) & 0x7FF;
            x1 += ((a * gpSinTable[(l + 0x200) & 0x7FF]) >> 14);
            y1 += ((a * gpSinTable[l]) >> 14);
            gPlayer[gPlayerNum].xpos += ((x1 - gPlayer[gPlayerNum].xpos) / 2);
            gPlayer[gPlayerNum].ypos += ((y1 - gPlayer[gPlayerNum].ypos) / 2);
        }
        else
        {
            if (klabs(gStickX[gPlayerNum]) < 4)
                k = 0;
            else
            {
                k = (gStickX[gPlayerNum] * gPlayer[gPlayerNum].unk78 * 256.0f) / gPlayer[gPlayerNum].unk6E;
                if (gStickX[gPlayerNum] > 0)
                    k = MAX(1, k);

                if (gStickX[gPlayerNum] < 0)
                    k = MIN(-1, k);
            }
        }

        if (gPlayer[gPlayerNum].unk52 == -1)
        {
            if (func_8003779C(15) == 0)
            {
                gPlayer[gPlayerNum].ang = (gPlayer[gPlayerNum].ang + k) & 0x7FF;
                if (gPlayer[gPlayerNum].unk6C == 0)
                    gPlayer[gPlayerNum].unk6E = 0x100;
            }
        }
        else
        {
            gPlayer[gPlayerNum].unk6E = 0x100;
            if (gPlayer[gPlayerNum].unk52 < 0x800)
            {
                spr = &gpSprite[gPlayer[gPlayerNum].unk52 & 0x7FF];
                if (spr->unk2A != 81)
                {
                    if (gStickX[gPlayerNum] > 32)
                    {
                        spr->ang += 4;
                        spr->unk18 += 4;
                        if (spr->unk18 >= spr->unk1A)
                        {
                            spr->ang -= (spr->unk18 - spr->unk1A);
                            spr->unk18 = spr->unk1A;
                        }
                    }

                    if (gStickX[gPlayerNum] < -32)
                    {
                        spr->ang -= 4;
                        spr->unk18 -= 4;
                        if (spr->unk18 <= -spr->unk1A)
                        {
                            spr->ang -= (spr->unk18 + spr->unk1A);
                            spr->unk18 = -spr->unk1A;
                        }
                    }

                    spr->ang &= 0x7FF;
                    if (spr->unk2A == 83)
                    {
                        if (gStickY[gPlayerNum] > 32)
                            spr->unk22 = CLAMP_MAX((spr->unk22 * 1.025), 2048.0);

                        if (gStickY[gPlayerNum] < -32)
                            spr->unk22 = CLAMP_MIN((spr->unk22 / 1.025), 256.0);

                        gPlayer[gPlayerNum].unk6E = spr->unk22;
                    }
                }
            }
            D_80138850 = 0;
            return;
        }

        gPlayer[gPlayerNum].unk20 = i;
        gPlayer[gPlayerNum].unk24 = j;
        n = 162;
        f1 = 0.8f;

        if (gPlayer[gPlayerNum].unk5B != 0)
        {
            if (gPlayer[gPlayerNum].unk54 != 0)
            {
                n = 81;
                f1 = 0.9f;
            }
            i *= cosf((gPlayer[gPlayerNum].unk3E * (PI/1024)));
        }

        D_8013B2D0[gPlayer[gPlayerNum].unk4A].unk0 *= f1;
        D_8013B2D0[gPlayer[gPlayerNum].unk4A].unk0 -= ((k * klabs(i)) / n);

        k = 0;
        if (!(gPlayer[gPlayerNum].unk80 & 1))
        {
            if (func_8003779C(15) == 0)
            {
                if (klabs(gStickY[gPlayerNum]) >= 4)
                {
                    k = (gStickY[gPlayerNum] * gPlayer[gPlayerNum].unk7C * 256.0f) / gPlayer[gPlayerNum].unk6E;
                    if (gStickY[gPlayerNum] > 0)
                        k = MAX(1, k);

                    if (gStickY[gPlayerNum] < 0)
                        k = MIN(-1, k);
                }
            }
        }
        else
        {
            if (func_8003779C(3) != 0)
                k = (11*256) / gPlayer[gPlayerNum].unk6E;

            if (func_8003779C(4) != 0)
                k -= (11*256) / gPlayer[gPlayerNum].unk6E;
        }

        gPlayer[gPlayerNum].unk3E = CLAMP_MIN(CLAMP_MAX((gPlayer[gPlayerNum].unk3E + k), (53.0*256.0)/45.0), -((53.0*256.0)/45.0));

    }

    o = (i * gpSinTable[(gPlayer[gPlayerNum].ang + 0x200) & 0x7FF]);
    l = (i * gpSinTable[gPlayer[gPlayerNum].ang & 0x7FF]);
    gPlayer[gPlayerNum].xvect += o;
    gPlayer[gPlayerNum].yvect += l;
    o = j * gpSinTable[gPlayer[gPlayerNum].ang & 0x7FF];
    l = j * gpSinTable[(gPlayer[gPlayerNum].ang - 0x200) & 0x7FF];
    gPlayer[gPlayerNum].xvect += o;
    gPlayer[gPlayerNum].yvect += l;
}

/*800390F0*/
static void func_800390F0(void)
{
    s32 ang, i1, i2;
    s16 sectnum;
    s32 a, b;

    if (gPlayer[gPlayerNum].unk54 != 0)
        return;

    if (gPlayer[gPlayerNum].unk36 >= 0x1000)
        return;

    if (((gPlayer[gPlayerNum].zpos + gPlayer[gPlayerNum].zvect + 1280) >= D_80138860) &&
        (gPlayer[gPlayerNum].unk58 == 0))
    {
        sectnum = gPlayer[gPlayerNum].unk36;
        i1 = sectnum; /*FAKEMATCH*/

        if ((gpSector[sectnum].floorstat & 2) && (gpSector[sectnum].floorheinum != 0))
        {
            gPlayer[gPlayerNum].zpos = D_80138860;
            if (gPlayer[gPlayerNum].zvect < 0)
                gPlayer[gPlayerNum].zvect = 0;

            ang = (getAngle(gpWall[gpWall[gpSector[sectnum].wallptr].point2].x - gpWall[gpSector[sectnum].wallptr].x,
                gpWall[gpWall[gpSector[sectnum].wallptr].point2].y - gpWall[gpSector[sectnum].wallptr].y) + 512) & 0x7FF;

            a = (gpSector[sectnum].floorheinum < 0) ? -1 : 1;
            b = klabs(gpSector[sectnum].floorheinum) / 256;
            i1 = a * b * gpSinTable[(ang + 512) & 0x7FF];
            i2 = a * b * gpSinTable[ang];
            gPlayer[gPlayerNum].xvect += i1;
            gPlayer[gPlayerNum].yvect += i2;
        }
    }
}

/*80039344*/
static void func_80039344(void)
{
    f64 f1, f2, f3;
    s32 i1, i3;
    u8 i2;

    i1 = 0x240000;
    if (gPlayer[gPlayerNum].unk59 != 0)
        i1 = (((f32)D_8012F6E4[gPlayer[gPlayerNum].skin].unkA * (f32)i1) / 100.0);

    if (gPlayer[gPlayerNum].unk36 >= 0x1000)
        i2 = gpSector[gPlayer[gPlayerNum].cursectnum].unk2A;
    else
        i2 = gpSector[gPlayer[gPlayerNum].unk36].unk2A;

    f1 = sqrtf(SQ((f64)gPlayer[gPlayerNum].xvect) +
               SQ((f64)gPlayer[gPlayerNum].yvect));

    if (f1 != 0.0)
    {
        i3 = (32 - i2) * 16384;
        i1 += i3 * 3;

        if (D_8010A940[gPlayerNum].unk2[2] && D_800DEE80 == -1)
            i1 *= 2;

        if (gPlayer[gPlayerNum].unk54 != 0)
            i1 = (i1 * 5) / 8;

        if (gPlayer[gPlayerNum].unk56 != 0)
            i1 /= 3;

        if (gPlayer[gPlayerNum].unk5A != 0)
            i1 /= 3;

        if (gPlayer[gPlayerNum].unk6C != 0)
            i1 /= 4;

        if (i1 < f1)
        {
            f2 = i1 / f1;
            gPlayer[gPlayerNum].xvect *= f2;
            gPlayer[gPlayerNum].yvect *= f2;
        }

        if (f1 <= (i2 * 8192))
        {
            gPlayer[gPlayerNum].xvect = 0;
            gPlayer[gPlayerNum].yvect = 0;
        }
        else
        {
            f3 = (f1 - (i2 * 8192)) / f1;
            gPlayer[gPlayerNum].xvect *= f3;
            gPlayer[gPlayerNum].yvect *= f3;
        }
    }
}

/*80039774*/
void func_80039774(void)
{
    code0unkStruct8 *ptr;
    f32 f1, f2;
    s16 i, j;
    s32 k, l, m;
    s32 xvect, yvect;

    if (gPlayer[gPlayerNum].zpos < D_80138860)
    {
        if (gPlayer[gPlayerNum].unk5B != 0)
            gPlayer[gPlayerNum].zvect *= 0.667;
        else if (gPlayer[gPlayerNum].unk56 == 0)
            gPlayer[gPlayerNum].zvect += 0x100;
    }
    else if ((D_80138860 < gPlayer[gPlayerNum].zpos) &&
             (((gPlayer[gPlayerNum].zpos - D_80138860) < 0x1200) ||
                 (D_80129804 < gPlayer[gPlayerNum].zpos)))
    {
        gPlayer[gPlayerNum].zpos += ((D_80138860 - gPlayer[gPlayerNum].zpos) / 2);
    }

    if (gPlayer[gPlayerNum].unk58 != 0)
        gPlayer[gPlayerNum].zvect = (-D_800DEDC0 * 0x800) / 7;

    if (gPlayer[gPlayerNum].unk5B != 0)
    {
        s32 temp = gPlayerNum; /*FAKEMATCH?*/
        f1 = gPlayer[gPlayerNum].zvect;
        f2 = gPlayer[gPlayerNum].unk20;
        gPlayer[temp].zvect = (f1 + (f2 * sinf((gPlayer[gPlayerNum].unk3E * (PI/1024))) * 16.0f));
    }

    if ((gPlayer[gPlayerNum].unk56 != 0) &&
        (gPlayer[gPlayerNum].unk3E > 200) &&
        (gPlayer[gPlayerNum].unk20 > 0))
    {
        gPlayer[gPlayerNum].zvect = CLAMP_MAX((gPlayer[gPlayerNum].zvect + 0x101), 0x800);
    }

    if (gPlayer[gPlayerNum].unk45 != 0)
    {
        if (gPlayer[gPlayerNum].unk50 != -1)
        {
            gPlayer[gPlayerNum].unk50 = -1;
            if (gPlayer[gPlayerNum].unk6C == 0)
                gPlayer[gPlayerNum].third_person = gPlayer[gPlayerNum].unk61;
        }

        if (gPlayer[gPlayerNum].unk56 != 0)
            gPlayer[gPlayerNum].zvect += 0x100;
    }

    D_801A6AD4[gPlayerNum] = 0;
    gPlayer[gPlayerNum].unk5C = 0;

    if ((gPlayer[gPlayerNum].unk50 >= 0) &&
        (gpSector[gPlayer[gPlayerNum].cursectnum].floorstat & 0x800) &&
        (func_8003779C(9) != 0))
    {
        gPlayer[gPlayerNum].unk5C = 1;
    }
    else if (D_80138850 != 0)
    {
        if (gPlayer[gPlayerNum].unk6C == 0)
        {
            i = 0;
            if (gPlayer[gPlayerNum].unk36 > 0x1000)
            {
                switch (gpSprite[(s16)(gPlayer[gPlayerNum].unk36 - 0x1000)].statnum)
                {
                case 1:
                    i = gpSprite[(s16)(gPlayer[gPlayerNum].unk36 - 0x1000)].picnum != 2222;
                    break;

                case 10:
                    i = 1;
                    break;

                default:
                    i = 0;
                    break;
                }
            }

            if (((gPlayer[gPlayerNum].unk59 != 0) ||
                (gPlayer[gPlayerNum].unk5B != 0) ||
                (gPlayer[gPlayerNum].unk56 != 0) ||
                (gPlayer[gPlayerNum].unk58 != 0)) &&
                ((gPlayer[gPlayerNum].unk5A == 0) && (i != 1)))
            {

                if (func_8003779C(0) != 0)
                {
                    if (gPlayer[gPlayerNum].unk58 != 0)
                    {
                        if (gPlayer[gPlayerNum].unk44 == 0)
                        {
                            s32 vel = -320; /*FAKEMATCH*/
                            D_80119A30[gPlayerNum] |= 2;
                            xvect = (gpSinTable[(gPlayer[gPlayerNum].ang + 512) & 0x7FF] * vel);
                            yvect = (gpSinTable[gPlayer[gPlayerNum].ang & 0x7FF] * vel);
                            gPlayer[gPlayerNum].xvect += xvect;
                            gPlayer[gPlayerNum].yvect += yvect;
                            D_8012F914[gPlayerNum] = -1;
                            gPlayer[gPlayerNum].unk44 = 1;
                            D_801A6AD4[gPlayerNum] = 1;
                            gPlayer[gPlayerNum].unk58 = 0;
                            _pActor2->unk99 = gPlayer[gPlayerNum].unk72;
                        }
                    }
                    else if (gPlayer[gPlayerNum].unk5B != 0)
                    {
                        gPlayer[gPlayerNum].zvect = CLAMP_MIN((gPlayer[gPlayerNum].zvect - 682), -682);
                    }
                    else if (gPlayer[gPlayerNum].unk44 == 0)
                    {
                        if ((D_80119A30[gPlayerNum] != 0) || (!gPlayer[gPlayerNum].third_person))
                            D_8012F914[gPlayerNum] = 6;
                        else
                            D_8012F914[gPlayerNum] = 27;

                        gPlayer[gPlayerNum].unk44 = 1;
                        D_801A6AD4[gPlayerNum] = 1;
                    }
                }
                else
                    gPlayer[gPlayerNum].unk44 = 0;
            }
            else if (func_8003779C(0) != 0)
                gPlayer[gPlayerNum].unk44 = 1;

            if (D_8012F914[gPlayerNum] > 0)
            {
                D_8012F914[gPlayerNum]--;
                gPlayer[gPlayerNum].unk44 = 1;
            }

            if (D_8012F914[gPlayerNum] == 0)
            {
                s32 temp = -0xA00; /*FAKEMATCH*/
                D_8012F914[gPlayerNum] = -1;
                gPlayer[gPlayerNum].zvect = temp;
            }
        }
    }

    gPlayer[gPlayerNum].zpos += gPlayer[gPlayerNum].zvect;

    if (gPlayer[gPlayerNum].zpos >= D_80138860)
        gPlayer[gPlayerNum].unk59 = 1;
    else
        gPlayer[gPlayerNum].unk59 = 0;

    if (D_801A1998 >= gPlayer[gPlayerNum].zpos)
    {
        gPlayer[gPlayerNum].zpos = D_801A1998;
        if (gPlayer[gPlayerNum].zvect < 0)
            gPlayer[gPlayerNum].zvect = 0x100;
    }

    if (gPlayer[gPlayerNum].zvect > 0)
    {
        if (gPlayer[gPlayerNum].zpos >= D_80138860)
        {
            gPlayer[gPlayerNum].zpos = D_80138860;

            if ((gPlayer[gPlayerNum].unk45 == 0) &&
                ((gpSector[gPlayer[gPlayerNum].cursectnum].unk18 != 1) ||
                    (D_80138860 != D_80129804)))
            {
                if (gPlayer[gPlayerNum].zvect > 0x500)
                    audio_80007820(((krand() % 3) + 1401), gPlayer[gPlayerNum].unk4A);

                if (gPlayer[gPlayerNum].zvect > 0xC00)
                {
                    if (gPlayer[gPlayerNum].zvect - 0xC00 < 0)
                        m = gPlayer[gPlayerNum].zvect - 0x801;
                    else
                        m = gPlayer[gPlayerNum].zvect - 0xC00;

                    j = m >> 10;
                    j = (j * j) * 2;

                    if (gpSector[gPlayer[gPlayerNum].cursectnum].unk18 == 4)
                        j /= 2;

                    if (gpSector[gPlayer[gPlayerNum].cursectnum].unk18 == 5)
                        j /= 4;

                    if (j > 10)
                    {
                        audio_80007820(1407, gPlayer[gPlayerNum].unk4A);

                        if (j > 75)
                            j = 500;

                        func_8003671C(gPlayerNum, j, -1, -2);
                    }
                }
                gPlayer[gPlayerNum].zvect = 0;
            }
        }

        if (gPlayer[gPlayerNum].unk58 != 0)
        {
            k = 0x40000000;
            if (gPlayer[gPlayerNum].unk5E >= 0x1000)
            {
                k = gpSprite[(s16)(gPlayer[gPlayerNum].unk5E - 0x1000)].z -
                    (gModelList[gpSprite[(s16)(gPlayer[gPlayerNum].unk5E - 0x1000)].picnum-MODELLIST]->zmin *
                     (gpSprite[(s16)(gPlayer[gPlayerNum].unk5E - 0x1000)].yrepeat << 6) / 64) -
                    gPlayer[gPlayerNum].unk40;
            }

            k = MIN(D_80138860, k);
            if (gPlayer[gPlayerNum].zpos >= k)
            {
                gPlayer[gPlayerNum].unk58 = 0;
                _pActor2->unk99 = gPlayer[gPlayerNum].unk72;
            }
            goto block_98;
        }
    }
    else
    {
    block_98:
        l = 0xC0000000;
        if (gPlayer[gPlayerNum].unk58 != 0)
        {
            if (gPlayer[gPlayerNum].unk5E < 0x1000)
            {
                if (gpWall[gPlayer[gPlayerNum].unk5E].nextsector != -1)
                {
                    l = getFlorzOfSlope(gpWall[gPlayer[gPlayerNum].unk5E].nextsector,
                                               gPlayer[gPlayerNum].xpos, gPlayer[gPlayerNum].ypos);
                }
            }
            else
            {
                l = gpSprite[(s16)(gPlayer[gPlayerNum].unk5E - 0x1000)].z -
                    ((gModelList[gpSprite[(s16)(gPlayer[gPlayerNum].unk5E - 0x1000)].picnum-MODELLIST]->zmax *
                        (gpSprite[(s16)(gPlayer[gPlayerNum].unk5E - 0x1000)].yrepeat << 6)) / 64);
            }

            if ((gPlayer[gPlayerNum].zpos + gPlayer[gPlayerNum].unk40 / 4) < l)
            {
                gPlayer[gPlayerNum].unk58 = 0;
                gPlayer[gPlayerNum].zvect = -0xA00;
                _pActor2->unk99 = gPlayer[gPlayerNum].unk72;
            }
        }
    }

    if (gPlayer[gPlayerNum].zvect < 0)
    {
        if ((gpSector[gPlayer[gPlayerNum].cursectnum].unk18 == 3) &&
            (gPlayer[gPlayerNum].zpos < func_80036490(gPlayer[gPlayerNum].cursectnum)))
        {
            if (gPlayer[gPlayerNum].unk54 != 0)
            {
                gPlayer[gPlayerNum].zpos = func_80036490(gPlayer[gPlayerNum].cursectnum) - 0x1300;
                gPlayer[gPlayerNum].zvect = 0;
                gPlayer[gPlayerNum].unk44 = 1;
                gPlayer[gPlayerNum].unk56 = 1;
            }
        }
    }

    if ((gPlayer[gPlayerNum].unk59 != 0) && (gPlayer[gPlayerNum].unk45 != 0))
    {
        ptr = &D_80197E40[gActorSpriteMap[gPlayer[gPlayerNum].unk4A]];
        if (ptr->unk8 == &D_800D8E34)
        {
            func_800171D0(ptr, &D_800D980C, 5);
        }
    }
}

/*8003A910*/
static void func_8003A910(void)
{
    s32 x, y;
    u16 cstat;
    ModelInfo *model;
    s16 spritenum;
    s16 ang;
    s32 i, j;
    s32 walldist;
    s32 flordist;

    cstat = gpSprite[gPlayer[gPlayerNum].unk4A].cstat;
    gpSprite[gPlayer[gPlayerNum].unk4A].cstat = cstat & ~0x101;
    walldist = 164;

    if (gpSprite[gPlayer[gPlayerNum].unk4A].cstat & 0x1000)
    {
        model = gModelList[gpSprite[gPlayer[gPlayerNum].unk4A].picnum-MODELLIST];
        walldist = ((model->xmax - model->xmin) *
                    gpSprite[gPlayer[gPlayerNum].unk4A].xrepeat / 64);
        walldist *= 2;
    }

    x = gPlayer[gPlayerNum].xpos;
    y = gPlayer[gPlayerNum].ypos;
    flordist = CLAMP_MIN((gPlayer[gPlayerNum].unk40 - 0x1200), 1024);

    i = clipMove(&gPlayer[gPlayerNum].xpos, &gPlayer[gPlayerNum].ypos,
                 &gPlayer[gPlayerNum].zpos, &gPlayer[gPlayerNum].cursectnum,
                 gPlayer[gPlayerNum].xvect, gPlayer[gPlayerNum].yvect,
                 walldist, 1024, flordist, 0x10001);

    if (gPlayer[gPlayerNum].unk45== 0)
    {
        j = pushMove(&gPlayer[gPlayerNum].xpos, &gPlayer[gPlayerNum].ypos,
                     &gPlayer[gPlayerNum].zpos, &gPlayer[gPlayerNum].cursectnum,
                     walldist, 1024, flordist, 0x10001);

        gpSprite[gPlayer[gPlayerNum].unk4A].cstat = cstat;
        if (j == -1)
            func_800365C0(gPlayerNum);

        if (i != 0)
        {
            gPlayer[gPlayerNum].xvect = (gPlayer[gPlayerNum].xpos - x) << 14;
            gPlayer[gPlayerNum].yvect = (gPlayer[gPlayerNum].ypos - y) << 14;
            if (i >= 0xC000)
            {
                spritenum = i + 0x4000;
                if ((gpSprite[spritenum].picnum == 1398) || (gpSprite[spritenum].picnum == 1399))
                {
                    if (!(D_8012FD88 & 7))
                        func_8003671C(gPlayerNum, 1, -1, -1);
                }
                if (gpSprite[spritenum].statnum == 305)
                {
                    if (gpSprite[spritenum].picnum == BOSSGIANTHOG)
                        func_800365C0(0);
                }

                if (gActorSpriteMap[spritenum] != -1)
                {
                    if (gActor[gActorSpriteMap[spritenum]].unk4 & 0x8000)
                        gActor[gActorSpriteMap[spritenum]].unk4 |= 0x20000;
                }
            }
        }
        if ((gPlayer[gPlayerNum].unk20 > 0) && (gPlayer[gPlayerNum].unk54 == 0))
        {
            if ((i >= 0x8000) && (i < 0xC000))
            {
                if (gpWall[i-0x8000].unk14 == 50)
                {
                    gPlayer[gPlayerNum].unk72 = _pActor2->unk99;
                    gPlayer[gPlayerNum].unk5E = i - 0x8000;
                    gPlayer[gPlayerNum].unk58 = 1;
                    gPlayer[gPlayerNum].yvect = 0;
                    gPlayer[gPlayerNum].xvect = 0;
                    if (_pActor2->unk70 != 0)
                        func_80079C20(gPlayer[gPlayerNum].unk4A);

                    _pActor2->unk99 = 0;
                }
            }
            if (i >= 0xC000)
            {

                if (gpSprite[i-0xC000].statnum == 115)
                {
                    ang = (gpSprite[i - 0xC000].ang + 0x400) & 0x7FF;
                    ang = gPlayer[gPlayerNum].ang - ang;

                    if (ang < -1024)
                        ang += 2048;
                    if (ang > 1024)
                        ang -= 2048;

                    if (klabs(ang) < 256)
                    {
                        gPlayer[gPlayerNum].unk72 = _pActor2->unk99;
                        gPlayer[gPlayerNum].unk5E = i + 0x5000;
                        gPlayer[gPlayerNum].unk58 = 1;
                        gPlayer[gPlayerNum].yvect = 0;
                        gPlayer[gPlayerNum].xvect = 0;
                        if (_pActor2->unk70 != 0)
                            func_80079C20(gPlayer[gPlayerNum].unk4A);

                        _pActor2->unk99 = 0;
                    }
                }
            }
        }
    }
}

/*8003AFD0*/
static void func_8003AFD0(s16 playernum)
{
    gPlayer[playernum].unk6C = 2;
    gPlayer[playernum].unk6E = 256;
    gPlayer[playernum].third_person = FALSE;
    playSfx2(1036, 128, 128, 1, -1);
}

/*8003B04C*/
static void func_8003B04C(s16 playernum)
{
    gPlayer[playernum].unk6E = 256;
    gPlayer[playernum].unk6C = 0;
    if (gPlayer[playernum].unk50 == -1)
    {
        if (gPlayer[playernum].unk5A == 0)
            gPlayer[playernum].third_person = gPlayer[playernum].unk61;
    }
    D_800DEED0[playernum] = 0;
}

/*8003B0E4*/
static void func_8003B0E4(s16 playernum)
{
    D_8012F914[playernum] = -1;

    if (func_8003779C(0) != 0)
    {
        if (D_800DEDD0[playernum] == 0)
        {
            switch (gPlayer[playernum].unk6C)
            {
            case 2:
                gPlayer[playernum].unk6C = 4;
                break;

            case 4:
                gPlayer[playernum].unk6C = 8;
                break;

            case 8:
                gPlayer[playernum].unk6C = 2;
                break;
            }
            D_800DEDD0[playernum] = 1;

            if (gPlayer[playernum].unk6C == 2)
                playSfx2(873, 128, 128, 1, -1);
            else
                playSfx2(1036, 128, 128, 1, -1);
        }
    }
    else
        D_800DEDD0[playernum] = 0;

    if (gPlayer[playernum].unk6E < (gPlayer[playernum].unk6C << 8))
        gPlayer[playernum].unk6E = MIN((gPlayer[playernum].unk6C << 8), (gPlayer[playernum].unk6E * 1.1));
    else
        gPlayer[playernum].unk6E = MAX((gPlayer[playernum].unk6C << 8), (gPlayer[playernum].unk6E / 1.1));
}

/*8003B31C*/
s16 func_8003B31C(s16 playernum, s16 arg1)
{
    s16 i;

    i = D_8010A940[playernum].unk0;
    for (i = (i + arg1) % 8; D_8010A940[playernum].unkA[i] == 0; i = (i + arg1) % 8)
    {
        if (i == D_8010A940[playernum].unk0)
            break;
    }

    if (D_8010A940[playernum].unkA[i] == 0)
        i = -1;

    return i;

}

/*8003B428*/
static void func_8003B428(s16 arg0)
{
    D_80199970[gPlayerNum] = 0;
    if (arg0 < 0)
        arg0 += 24;

    _pActor2->unk99 = (_pActor2->unk99 + arg0) % 24;
    if ((_pActor2->unk99 == 19) || (_pActor2->unk99 == 11))
        _pActor2->unk99 = (_pActor2->unk99 + arg0) % 24;

    while (!(func_80079DE8(gPlayerNum, _pActor2->unk99)))
    {
        _pActor2->unk99 = (_pActor2->unk99 + arg0) % 24;
        if ((_pActor2->unk99 == 19) || (_pActor2->unk99 == 11))
            _pActor2->unk99 = (_pActor2->unk99 + arg0) % 24;
    }
}

/*8003B5F8*/
static void func_8003B5F8(void)
{
    s32 i;
    s16 spritenum, spritenum2;
    s16 j, k, l, m;
    u8 cond1, cond2;
    u8 pad[8]; /*FAKEMATCH?*/

    (void)pad;
    spritenum = gPlayer[gPlayerNum].unk4A;
    _pActor2 = &gActor[gActorSpriteMap[spritenum]];
    D_80138850 = 1;

    if (_pActor2->flag & 0x40)
        D_80138850 = 0;

    if (D_800DEE80 >= 0)
        D_80138850 = 0;

    if (gPlayer[gPlayerNum].unk45 != 0)
        D_80138850 = 0;

    if (D_80106D30[gPlayerNum] != 0)
        D_80138850 = 0;

    if (D_8010554C != 0)
        D_80138850 = 0;

    if (gPlayer[gPlayerNum].unk84 > 0)
        D_80138850 = 0;

    if (gPlayer[gPlayerNum].unk52 >= 0x800)
        D_80138850 = 0;

    if (gPlayer[gPlayerNum].unk86 > 0)
        D_80138850 = 0;

    cond1 = 0;
    if (gPlayer[gPlayerNum].unk57 == 0)
    {
        if (gPlayer[gPlayerNum].unk54 != 0)
        {
            cond1 = 1;
            audio_800077F4(((krand() % 3) + 533), gPlayer[gPlayerNum].unk4A);
        }

    }
    if (gPlayer[gPlayerNum].unk57 != 0)
    {
        if (gPlayer[gPlayerNum].unk54 == 0)
        {
            cond1 = 1;
            audio_800077F4(((krand() % 2) + 998), gPlayer[gPlayerNum].unk4A);
        }
    }

    gPlayer[gPlayerNum].unk57 = gPlayer[gPlayerNum].unk54;
    if (_pActor2->unk8 > 0)
    {
        if (D_80138850 != 0)
        {
            if (func_8003779C(9) != 0)
            {
                if (D_800DEDC8[gPlayerNum] == 0)
                {
                    if (gPlayer[gPlayerNum].unk6C != 0)
                        func_8003B04C(gPlayerNum);
                    else
                        func_8006A0A0(spritenum);

                    D_800DEDC8[gPlayerNum] = 1;
                }
            }
            else
                D_800DEDC8[gPlayerNum] = 0;

            m = 0;
            if (func_8003779C(5) != 0)
                m = -1;

            if (func_8003779C(6) != 0)
                m = 1;

            if (func_8003779C(0xF) != 0)
            {
                if (gStickX[gPlayerNum] > 32)
                    m = 1;

                if (gStickX[gPlayerNum] < -32)
                    m = -1;
            }

            if (m != 0)
            {
                if (D_800DEDC4[gPlayerNum] == 0)
                {
                    if ((gPlayer[gPlayerNum].unk58 == 0) && (D_800FE9D8[gPlayerNum] == 0) && (D_8016A154[gPlayerNum] == 0))
                    {
                        func_8003B428(m);
                        D_8011A680[gPlayerNum][_pActor2->unk99][9] = 0;
                        D_8011A680[gPlayerNum][_pActor2->unk99][8] = 0;
                        D_8011A680[gPlayerNum][_pActor2->unk99][4] = 0;
                    }
                    D_800DEDC4[gPlayerNum] = 20;
                }

                D_800DEDC4[gPlayerNum] = CLAMP_MIN((D_800DEDC4[gPlayerNum]-1), 0);
            }
            else
                D_800DEDC4[gPlayerNum] = 0;

            if ((func_8003779C(10) != 0) || ((func_8003779C(2) != 0) && (func_8003779C(15) != 0)))
            {
                if (D_800DEDD8[gPlayerNum] == 0)
                {
                    func_8009584C(gPlayerNum);
                    D_800DEDD8[gPlayerNum] = 1;
                }
            }
            else
                D_800DEDD8[gPlayerNum] = 0;

            if (D_8010A940[gPlayerNum].unk0 != -1)
            {
                if (D_8010A940[gPlayerNum].unkA[D_8010A940[gPlayerNum].unk0] == 0)
                    D_8010A940[gPlayerNum].unk0 = func_8003B31C(gPlayerNum, 1);

                m = 0;

                if (func_8003779C(8) != 0)
                    m = 1;

                if (func_8003779C(7) != 0)
                    m = 7;

                if (func_8003779C(15) != 0)
                {
                    if (gStickY[gPlayerNum] > 32)
                        m = 7;

                    if (gStickY[gPlayerNum] < -32)
                        m = 1;
                }

                if (m != 0)
                {
                    if (D_800DEDDC[gPlayerNum] == 0)
                    {
                        D_8010A940[gPlayerNum].unk0 = func_8003B31C(gPlayerNum, m);
                        D_800DEDDC[gPlayerNum] = 20;
                    }

                    D_800DEDDC[gPlayerNum] = CLAMP_MIN((D_800DEDDC[gPlayerNum]-1), 0);;
                }
                else
                    D_800DEDDC[gPlayerNum] = 0;
            }
            else
            {
                for (i = 0; i < ARRAY_COUNT(D_8010A940[gPlayerNum].unkA); i++)
                {
                    if (D_8010A940[gPlayerNum].unkA[i] > 0)
                        D_8010A940[gPlayerNum].unk0 = i;
                }
            }
        }
        if (gButton[gPlayerNum] & START_BUTTON)
        {
            if (D_800DEDD4[gPlayerNum] == 0)
            {
                D_800DEDD4[gPlayerNum] = 1;
                if (D_80106D30[gPlayerNum] != 0)
                {
                    s16 a, b, c, d;

                    c = 0;
                    if (D_80106D30[gPlayerNum] == 1)
                    {
                        for (j = 0; j < gPlayerCount; j++)
                        {
                            if (j != gPlayerNum)
                            {
                                if (D_80106D30[j] != 1)
                                {
                                    if (gpSprite[gPlayer[j].unk4A].picnum == gpSprite[spritenum].picnum)
                                        c = 1;
                                }
                            }
                        }
                    }
                    else
                    {
                        a = 0;
                        b = 0;
                        for (k = 0; k < gPlayerCount; k++)
                        {
                            if ((D_80106D30[k] == 0) || (k == gPlayerNum))
                            {
                                if (D_800E16A0[k] != 0)
                                    a++;
                                else
                                    b++;
                            }
                        }

                        if (a == gPlayerCount)
                        {
                            d = 0;
                            c = 1;
                        }
                        else if (b == gPlayerCount)
                        {
                            c = 1;
                        }
                    }
                    d = c;

                    if (d != 0)
                        playSfx(1098);
                    else if ((D_801AD470 == 4) && (D_80106D30[gPlayerNum] == 1))
                    {
                        playSfx(747);
                        D_80106D30[gPlayerNum] = 2;
                    }
                    else
                    {
                        playSfx(D_8012F6E4[gPlayer[gPlayerNum].skin].sfxnum);
                        D_80106D30[gPlayerNum] = 0;
                        gpSprite[spritenum].cstat = (gpSprite[spritenum].cstat & 0x7FFF) | 0x101;
                        if (gPlayerCount == 1)
                            D_8010554C = 0;
                    }
                }
                else if ((D_801AE914 == 0) && (D_800E1748 == -1) &&
                         (gPlayer[gPlayerNum].unk52 < 0x800) && (D_8012FC90 == 0))
                {
                    D_801CD986[gPlayerNum] &= ~0x1000;
                    func_8007F050();

                    D_801CDACC = gPlayerNum;
                    D_801CB538[4].unk18 = &gConfig.controller_preset[gPlayerNum];
                    D_801CB538[5].unk18 = &gConfig.crosshair[gPlayerNum];
                    D_801CB538[6].unk18 = &gConfig.autoaim[gPlayerNum];
                    D_801CB538[7].unk18 = &gConfig.autocenter[gPlayerNum];
                    gConfig.menuIndex.unkB = 0;
                    gConfig.menuIndex.unkC = 0;
                    D_801CD980 = 0;

                    if (D_801CDC64.unk1 >= 2)
                        func_801C2BE8(&D_801CB8F0);
                    else
                        func_801C2BE8(&D_801CB870);

                    D_801CE5A0 = 0;
                    D_801AE914 = gPlayerNum + 1;
                }
            }
        }
        else
            D_800DEDD4[gPlayerNum] = 0;

        gPlayer[gPlayerNum].unk70 = _pActor2->unk99;
        gPlayer[gPlayerNum].unk46 = _pActor2->unk8;
    }
    else
    {
        _pActor2->unk8 = 0;

        cond2 = 0;
        if (gPlayer[gPlayerNum].unk45 == 0)
        {
            gpSprite[spritenum].cstat &= ~0x101;
            gPlayer[gPlayerNum].third_person = gPlayer[gPlayerNum].unk61;

            if (!gPlayer[gPlayerNum].third_person)
                gPlayer[gPlayerNum].unk3C = krand() & 0x7FF;

            if (D_800DEDE4[_pActor2->unk99] != -1)
            {
                spritenum2 = func_80058934(gPlayer[gPlayerNum].xpos,
                    gPlayer[gPlayerNum].ypos,
                    gPlayer[gPlayerNum].zpos + 0x2000,
                    gPlayer[gPlayerNum].cursectnum, 150);

                if (spritenum2 != -1)
                {
                    gpSprite[spritenum2].xrepeat = 80;
                    gpSprite[spritenum2].unk1C = 0;
                    gpSprite[spritenum2].unk18 = 0;

                    if ((_pActor2->unk99 == 14) && (D_8011A680[gPlayerNum][14][0] & 4))
                        gpSprite[spritenum2].picnum = 1844;
                    else
                        gpSprite[spritenum2].picnum = D_800DEDE4[_pActor2->unk99];

                    gpSprite[spritenum2].cstat = 0x1000;
                    gpSprite[spritenum2].unk22 = 0x5678;
                    gpSprite[spritenum2].lotag = D_8011A680[gPlayerNum][_pActor2->unk99][1];

                    if ((D_8011A680[gPlayerNum][_pActor2->unk99][0] & 4))
                    {
                        gpSprite[spritenum2].hitag = D_8011A680[gPlayerNum][_pActor2->unk99][7];

                        if (_pActor2->unk99 != 4)
                            gpSprite[spritenum2].lotag = 0;
                    }
                    else
                        gpSprite[spritenum2].hitag = 0;
                }
            }

            _pActor2->unk99 = 0;
            for (l = 0; l < ARRAY_COUNT(D_8010A940[gPlayerNum].unk2); l++)
            {
                D_8010A940[gPlayerNum].unk2[l] = 0;
                D_8010A940[gPlayerNum].unkA[l] = 0;
            }

            D_8010A940[gPlayerNum].unk0 = -1;
            gPlayer[gPlayerNum].unk4E = 0;

            if (gPlayer[gPlayerNum].unk58 != 0)
            {
                s32 yvect, xvect, vel, h;
                vel = -320; /*FAKEMATCH?*/
                D_80119A30[gPlayerNum] = D_80119A30[gPlayerNum] | 2;
                h = gPlayer[gPlayerNum].ang;
                yvect = (gpSinTable[h & 0x7FF]) * vel;
                xvect = gpSinTable[(h + 0x200) & 0x7FF] * vel;
                gPlayer[gPlayerNum].xvect += xvect;
                gPlayer[gPlayerNum].yvect += yvect;
                D_8012F914[gPlayerNum] = -1;
                gPlayer[gPlayerNum].unk44 = 1;
                D_801A6AD4[gPlayerNum] = 1;
                gPlayer[gPlayerNum].unk58 = 0;
            }

            if (_pActor2->unk70 != 0)
            {
                MusHandleStop(_pActor2->unk70, 0);
                _pActor2->unk70 = 0;
            }

            gPlayer[gPlayerNum].unk45 = 1;
            audio_800080E0(gPlayerNum, 3);
        }

        if (_pActor2->flag & 0x40)
        {
            if (gPlayer[gPlayerNum].unk4E == 30)
                audio_80007A44(D_800DF1B4[krand() & 3], spritenum, 24000);

            if (gPlayer[gPlayerNum].unk4E == 60)
                audio_80007A44(D_800DF1B4[krand() & 3], spritenum, 24000);

            if (gPlayer[gPlayerNum].unk4E == 90)
            {
                audio_80007A44(641, spritenum, 24000);
                func_80045400(gpSprite[spritenum].x,
                              gpSprite[spritenum].y,
                              gpSprite[spritenum].z - 0x3E80,
                              gpSprite[spritenum].sectnum,
                              0,
                              gpSprite[spritenum].ang, 44, 3);

                func_80045400(gpSprite[spritenum].x,
                              gpSprite[spritenum].y,
                              gpSprite[spritenum].z - 0x1F40,
                              gpSprite[spritenum].sectnum,
                              0,
                              gpSprite[spritenum].ang, 44, 3);

                func_8008E3E0(gpSprite[spritenum].x,
                              gpSprite[spritenum].y,
                              gpSprite[spritenum].z - 0x800,
                              gpSprite[spritenum].sectnum, 18, 0);

                gpSprite[spritenum].cstat |= 0x8000;
                _pActor2->flag &= ~0x40;
            }
        }

        if ((gPlayer[gPlayerNum].unk4E >= 31) && (gpSprite[gPlayer[gPlayerNum].unk4A].unk25 == 31))
            D_8013B2D0[spritenum].unk6 = CLAMP_MAX(D_8013B2D0[spritenum].unk6++, 0xFF);

        gPlayer[gPlayerNum].unk3E = (gPlayer[gPlayerNum].unk3E / 2);
        if (gButton[gPlayerNum] & START_BUTTON)
        {
            cond2 = 1;
            D_800DEDD4[gPlayerNum] = 1;
        }

        if (gPlayerCount == 1)
        {
            if ((gPlayer[gPlayerNum].unk54 != 0) && (func_8000EBD4(gPlayerNum) >= 0xFF))
                cond2 = 1;

            if (gPlayer[gPlayerNum].unk4E >= 0xFF)
                cond2 = 1;

        }

        cond2 = (D_800E1748 < 0) ? cond2 : 0;
        if (cond2)
        {
            D_800DF585 = 1;
            D_800DEDD4[gPlayerNum] = 1;
            m = gPlayerCount;

            if (gPlayerCount == 1)
            {
                D_801CD986[gPlayerNum] &= ~0x1000;
                func_8007F050();
                D_801CDACC = 0;
                D_800BD3E8 = m;
                D_801CD980 = 0;
                func_801C2BE8(&D_801CB6E0);
                D_801CE5A0 = 0;
                D_801A1970 = 0;
                D_801AE914 = m;
                return;
            }

            if (D_801AD470 != 2)
                func_80062950(gPlayerNum, 0);
        }
    }
    gPlayer[gPlayerNum].unk54 = 0;

    if (gpSector[gPlayer[gPlayerNum].cursectnum].unk18 == 2)
        gPlayer[gPlayerNum].unk54 = 1;
    else if ((gpSector[gPlayer[gPlayerNum].cursectnum].unk18 == 3) &&
             (gPlayer[gPlayerNum].zpos >func_80036490(gPlayer[gPlayerNum].cursectnum)))
    {
        gPlayer[gPlayerNum].unk54 = 1;
    }

    gPlayer[gPlayerNum].unk5B = 0;

    if (gPlayer[gPlayerNum].unk54 != 0)
        gPlayer[gPlayerNum].unk5B = 1;

    if (gpSector[gPlayer[gPlayerNum].cursectnum].floorstat & 0x400)
        gPlayer[gPlayerNum].unk5B = 1;

    if (gPlayer[gPlayerNum].unk54 == 0)
        D_8011814A[gPlayerNum] = CLAMP_MAX((D_8011814A[gPlayerNum]+4), 600);
    else
    {
        if (gPlayer[gPlayerNum].unk58 != 0)
        {
            gPlayer[gPlayerNum].unk58 = 0;
            _pActor2->unk99 = gPlayer[gPlayerNum].unk72;
        }

        if (D_8010A940[gPlayerNum].unk2[1] == 0)
        {
            if (D_8012F6E4[gPlayer[gPlayerNum].skin].unkB == 4)
                D_8011814A[gPlayerNum] = CLAMP_MIN((D_8011814A[gPlayerNum]-4), 0);
            else
                D_8011814A[gPlayerNum] = CLAMP_MIN((D_8011814A[gPlayerNum]-1), 0);

            if ((D_8011814A[gPlayerNum] <= 0) && !(D_8012FD88 & 0xF))
                func_8003671C(gPlayerNum, 1, -1, -1);
        }
    }

    if ((D_8012F6E4[gPlayer[gPlayerNum].skin].unkB == 3) || (D_8012F6E4[gPlayer[gPlayerNum].skin].unkB == 5))
        D_8011814A[gPlayerNum] = 600;

    if (gPlayer[gPlayerNum].unk82 > 0)
        gPlayer[gPlayerNum].unk82--;

    if (gPlayer[gPlayerNum].unk84 > 0)
        gPlayer[gPlayerNum].unk84--;

    if (gPlayer[gPlayerNum].unk86 > 0)
    {
        gPlayer[gPlayerNum].unk86--;
        if (gPlayer[gPlayerNum].unk86 == 0)
        {
            gPlayer[gPlayerNum].third_person = gPlayer[gPlayerNum].unk61;
            gPlayer[gPlayerNum].unk86 = -3600;
        }
    }

    if (gPlayer[gPlayerNum].unk86 < 0)
        gPlayer[gPlayerNum].unk86++;

    i = 0x3900;
    if (gPlayer[gPlayerNum].unk54 != 0)
        i = 0x1C80;

    if (gPlayer[gPlayerNum].unk45 != 0)
        i = 0x1300;

    if (gPlayer[gPlayerNum].unk5A != 0)
        i = 0x1300;

    if (gPlayer[gPlayerNum].unk5C != 0)
        i = 0x1300;

    if (cond1)
        gPlayer[gPlayerNum].unk40 = i;
    else
        gPlayer[gPlayerNum].unk40 += (i - gPlayer[gPlayerNum].unk40) / 8;

    gpSprite[spritenum].yrepeat = gPlayer[gPlayerNum].unk40 / 228;
    gpSprite[spritenum].unk18 = gPlayer[gPlayerNum].xvect >> 11;
    gpSprite[spritenum].unk1A = gPlayer[gPlayerNum].yvect >> 11;
    gpSprite[spritenum].unk1C = gPlayer[gPlayerNum].zvect;
    func_8003A910();
    func_80036FEC();
    func_800390F0();
    func_80037B84();
    func_80039344();
    func_80039774();
    func_8003DDB8();
    func_8003E8D0();

    spritenum2 = gPlayer[gPlayerNum].unk50;
    if (spritenum2 != -1)
    {
        if (gActor[gActorSpriteMap[spritenum2]].unk9F & 0x40)
        {
            gPlayer[gPlayerNum].xvect = gpSprite[spritenum2].unk18 << 11;
            gPlayer[gPlayerNum].yvect = gpSprite[spritenum2].unk1A << 11;
            gPlayer[gPlayerNum].zvect = gpSprite[spritenum2].unk1C;
            gPlayer[gPlayerNum].unk50 = -1;
            if (gPlayer[gPlayerNum].unk6C == 0)
                gPlayer[gPlayerNum].third_person = gPlayer[gPlayerNum].unk61;
        }
        else
        {
            gPlayer[gPlayerNum].xpos = gpSprite[spritenum2].x;
            gPlayer[gPlayerNum].ypos = gpSprite[spritenum2].y;
            gPlayer[gPlayerNum].cursectnum = gpSprite[spritenum2].sectnum;
            gPlayer[gPlayerNum].third_person = FALSE;
        }
    }

    setSprite(spritenum,
              gPlayer[gPlayerNum].xpos,
              gPlayer[gPlayerNum].ypos,
              gPlayer[gPlayerNum].zpos + gPlayer[gPlayerNum].unk40);

    gpSprite[spritenum].ang = gPlayer[gPlayerNum].ang;
    setSprite(D_8012FCA0[gPlayerNum],
              gPlayer[gPlayerNum].xpos,
              gPlayer[gPlayerNum].ypos,
              getFlorzOfSlope(gPlayer[gPlayerNum].cursectnum, gPlayer[gPlayerNum].xpos, gPlayer[gPlayerNum].ypos));

    gpSprite[D_8012FCA0[gPlayerNum]].ang = gPlayer[gPlayerNum].ang;
    if (gPlayer[gPlayerNum].unk45 != 0)
        D_8013B2D0[D_8012FCA0[gPlayerNum]].unk6 = CLAMP_MAX((D_8013B2D0[D_8012FCA0[gPlayerNum]].unk6+8), 0xFF);

    if (gMapNum == MAP_NUCLEAR_WINTER)
    {
        if (gPlayer[gPlayerNum].unk45 == 0)
        {
            if ((gPlayer[gPlayerNum].unk54 == 0) &&
                gPlayer[gPlayerNum].third_person &&
                ((D_8012FD88 & 0x3F) > 48) &&
                !(D_8012FD88 & 3))
            {
                func_80045400(gPlayer[gPlayerNum].xpos,
                    gPlayer[gPlayerNum].ypos,
                    gPlayer[gPlayerNum].zpos,
                    gPlayer[gPlayerNum].cursectnum,
                    64,
                    gPlayer[gPlayerNum].ang, 6, 1);
            }
        }

    }

    if ((gPlayer[gPlayerNum].unk45 == 0) &&
        (gPlayer[gPlayerNum].unk54 != 0) &&
        gPlayer[gPlayerNum].third_person &&
        ((D_8012FD88 & 0x3F) > 48) &&
        !(D_8012FD88 & 3))
    {
        func_80045400(gPlayer[gPlayerNum].xpos,
            gPlayer[gPlayerNum].ypos,
            gPlayer[gPlayerNum].zpos + (gPlayer[gPlayerNum].unk40 / 2),
            gPlayer[gPlayerNum].cursectnum,
            384,
            gPlayer[gPlayerNum].ang, 1, 0);
    }


    if (D_80138850 != 0)
    {
        if (func_8003779C(2) != 0)
        {
            if (func_8003779C(15))
                D_800DEED0[gPlayerNum] = 0;
            else
            {
                if (D_800DEDCC[gPlayerNum] == 0)
                {
                    if ((_pActor2->unk99 == 23) && (gPlayer[gPlayerNum].unk6C == 0))
                    {
                        func_8003AFD0(gPlayerNum);
                        D_800DEED0[gPlayerNum] = 0;
                    }
                    else
                        D_800DEED0[gPlayerNum] = 1;
                }
            }
            D_800DEDCC[gPlayerNum] = 1;
        }
        else
        {
            D_800DEDCC[gPlayerNum] = 0;
            D_800DEED0[gPlayerNum] = 0;
        }
    }
    else
        D_800DEED0[gPlayerNum] = 0;

    if (gPlayer[gPlayerNum].unk58 != 0)
        D_800DEED0[gPlayerNum] = 0;

    if (gPlayer[gPlayerNum].unk6C != 0)
    {
        if ((_pActor2->unk99 != 23) || (gPlayer[gPlayerNum].unk52 >= 0x800))
            func_8003B04C(gPlayerNum);
        else
            func_8003B0E4(gPlayerNum);
    }
    func_8003F340();
    func_8003FD5C();
}

/*8003DACC*/
void func_8003DACC(void)
{
    f32 f1;
    s32 i;

    gGlobalAng = (D_801A2790[gPlayerNum].unk16 + D_801A2790[gPlayerNum].unk1C) * (PI/1024);
    D_801AC8E0 = (D_801A2790[gPlayerNum].unk1A * (PI/1024));
    if (D_801A2790[gPlayerNum].unk14 != 0)
    {
        if (gPlayer[gPlayerNum].unk82 != 0)
        {
            f1 = ((gpSinTable[D_801A2790[gPlayerNum].unk14] * 0.3) / 16384.0);
            if (gPlayer[gPlayerNum].unk82 < 30)
                f1 = (f1 * gPlayer[gPlayerNum].unk82) / 30.0f;

            D_801AC8E0 += f1;
        }
        else
        {
            D_801AC8E0 += (((gpSinTable[D_801A2790[gPlayerNum].unk14] * 0.03) / 16384.0));
        }
    }

    i = D_801A2790[gPlayerNum].unk18;
    if (i > 0x400)
        i -= 0x800;

    i = i + D_801A2790[gPlayerNum].unk1E;
    if (i > 0x400)
        i -= 0x800;

    gGlobalPosX = D_801A2790[gPlayerNum].x;
    gGlobalPosY = D_801A2790[gPlayerNum].y;
    gGlobalPosZ = D_801A2790[gPlayerNum].z;
    gGlobalSectnum = gPlayer[gPlayerNum].unk68;
    gGlobalViewHorizAng = i * (PI/1024);
    gMapXpos = (gGlobalPosX / 2);
    gMapYpos = ((gGlobalPosY /2));
    gMapZpos = gGlobalPosZ / 32;
}

/*8003DD54*/
void func_8003DD54(void)
{
    for (gPlayerNum = 0; gPlayerNum < gPlayerCount; gPlayerNum++)
        func_8003B5F8();
}

/*8003DDB8*/
static void func_8003DDB8(void)
{
    s32 x, y, z;
    s32 spritenum, unk38;
    s16 i;
    u8 cond, cond1, cond2;
    code0unkStruct8 *ptr;
    s32 unk18;

    if (gPlayerCount < 2)
    {
        if (((gPlayer[gPlayerNum].unk58 == 0) && (D_801A6AD4[gPlayerNum] != 1)) ||
            ((gPlayer[gPlayerNum].unk58 != 0) && (gPlayer[gPlayerNum].zvect != 0)))
        {
            if (gPlayer[gPlayerNum].unk54 == 0)
            {
                spritenum = gPlayer[gPlayerNum].unk4A;
                ptr = &D_80197E40[gActorSpriteMap[spritenum]];
                if (gPlayer[gPlayerNum].unk56 != 0)
                {
                    x = gpSprite[spritenum].x;
                    y = gpSprite[spritenum].y;
                    if (gpSector[gPlayer[gPlayerNum].cursectnum].unk18 == 3)
                        z = func_80036490(gPlayer[gPlayerNum].cursectnum);
                    else
                        z = gpSector[gPlayer[gPlayerNum].cursectnum].floorz;

                    unk38 = gPlayer[gPlayerNum].ang;

                    if (!(D_8012FD88 & 3) && (((krand() & 0xFF) < 0x20) || (D_80119A30[gPlayerNum] != 0)))
                    {
                        func_80045400(x, y, z, gpSprite[spritenum].sectnum, 0x78, krand() & 0x7FF, 3, 2);
                    }

                    if (!(D_8012FD88 & 0x1F))
                    {
                        if (!(D_8012FD88 & 0x3F))
                            func_80045400(x, y, z, gpSprite[spritenum].sectnum, 240, (unk38 - 0x100), 3, 3);
                        else
                            func_80045400(x, y, z, gpSprite[spritenum].sectnum, 240, (unk38 + 0x100), 3, 3);

                        if (D_80119A30[gPlayerNum] != 0)
                            audio_800077F4(krand() % 4 + 1621, spritenum);
                    }
                }
                else
                {
                    if ((gPlayer[gPlayerNum].unk58 != 0) || (D_80119A30[gPlayerNum] != 0))
                    {
                        cond = gpSector[gPlayer[gPlayerNum].cursectnum].unk1A & 0xF;
                        if (gPlayer[gPlayerNum].unk5A != 0)
                        {
                            cond1 = (D_8012FD88 % 50) == 0;
                            cond2 = (D_8012FD88 % 50) == 25;
                        }
                        else if (gPlayer[gPlayerNum].unk58 != 0)
                        {
                            cond1 = ptr->unk2 == 0;
                            cond2 = ptr->unk2 == 15;
                        }
                        else
                        {
                            cond1 = ptr->unk2 == 5;
                            cond2 = ptr->unk2 == 20;
                        }

                        unk18 = gpSector[gPlayer[gPlayerNum].cursectnum].unk18;
                        if (gpSector[gPlayer[gPlayerNum].cursectnum].unk18 == 3)
                        {
                            z = func_80036490(gPlayer[gPlayerNum].cursectnum);
                            if ((gPlayer[gPlayerNum].zpos >= (z - gPlayer[gPlayerNum].unk40)) &&
                                (gPlayer[gPlayerNum].zpos < z))
                            {
                                unk38 = gPlayer[gPlayerNum].ang;
                                x = gpSprite[spritenum].x;
                                y = gpSprite[spritenum].y;
                                cond = 1;
                                if (cond1 != 0)
                                {
                                    func_80045400(x, y, z, gpSprite[spritenum].sectnum, 60, (unk38 - 0x200), unk18, 0);
                                    func_80045400(x, y, z, gpSprite[spritenum].sectnum, 60, (unk38 - 0x200), 28, 0);
                                }
                                if (cond2 != 0)
                                {
                                    func_80045400(x, y, z, gpSprite[spritenum].sectnum, 60, (unk38 + 0x200), unk18, 0);
                                    func_80045400(x, y, z, gpSprite[spritenum].sectnum, 60, (unk38 + 0x200), 28, 0);
                                }
                            }
                        }

                        if (gpSector[gPlayer[gPlayerNum].cursectnum].unk18 == 4)
                        {
                            if (gPlayer[gPlayerNum].unk36 < 0x1000)
                            {
                                if ((gPlayer[gPlayerNum].unk58 == 0) && (gPlayer[gPlayerNum].unk59 != 0))
                                {
                                    unk38 = gPlayer[gPlayerNum].ang;
                                    x = gpSprite[spritenum].x;
                                    y = gpSprite[spritenum].y;
                                    z = gpSprite[spritenum].z;
                                    i = -1;
                                    if (D_80119A30[gPlayerNum] & 4)
                                        unk38 = (unk38 + 0x200) & 0x7FF;

                                    if (D_80119A30[gPlayerNum] & 8)
                                        unk38 = (unk38 - 0x200) & 0x7FF;

                                    if (cond1 != 0)
                                        i = func_80045400(x, y, z, gpSprite[spritenum].sectnum, 60, (unk38 - 0x200), 73, 1);

                                    if (cond2 != 0)
                                        i = func_80045400(x, y, z, gpSprite[spritenum].sectnum, 60, (unk38 + 0x200), 73, 0);

                                    if (i >= 0)
                                    {
                                        gpSprite[i].ang = unk38;
                                        func_80056A54(i);
                                    }
                                }
                            }
                        }

                        if (gPlayer[gPlayerNum].unk36 >= 0x1000)
                        {
                            i = gPlayer[gPlayerNum].unk36 - 0x1000;
                            cond = (gpSprite[i].statnum == 0x40) ? 8 : 0;
                            switch (gpSprite[i].picnum)
                            {
                            case 5200:
                            case 5205:
                            case 5214:
                            case 5215:
                            case 5231:
                                cond = 8;
                                break;
                            }
                        }
                        if (gPlayer[gPlayerNum].unk58 != 0)
                        {
                            if (gPlayer[gPlayerNum].unk5E < 0x1000)
                            {
                                if (gpWall[gPlayer[gPlayerNum].unk5E].picnum == 3366)
                                    cond = 9;
                                else
                                    cond = 10;
                            }
                            else
                            {
                                switch (gpSprite[gPlayer[gPlayerNum].unk5E & 0xFFF].picnum)
                                {
                                case 2467:
                                case 2433:
                                case 2489:
                                    cond = 9;
                                    break;

                                default:
                                    cond = 10;
                                    break;
                                }
                            }
                        }

                        if (gPlayer[gPlayerNum].unk5A != 0)
                        {
                            if ((cond == 2) || (cond == 8))
                                cond = 11;
                            else
                                cond = 12;
                        }

                        if (((gPlayer[gPlayerNum].unk59 != 0) || (gPlayer[gPlayerNum].unk58 != 0)) && (cond1 || cond2))
                        {
                            if (gpSprite[spritenum].picnum == COWBOYDUKE)
                                audio_800077F4(D_800DEE14[cond].unk4 + krand() % D_800DEE14[cond].unk0, spritenum);
                            else
                                audio_800077F4(D_800DEE14[cond].unk2 + krand() % D_800DEE14[cond].unk0, spritenum);
                        }
                    }
                }
            }
        }
    }
}

/*8003E8D0*/
static void func_8003E8D0(void)
{
    s16 i, j, k;

    j = gPlayer[gPlayerNum].cursectnum;
    if (gPlayer[gPlayerNum].unk45 == 0)
    {
        if (gpSector[j].floorstat & 0x80)
        {
            func_8008E01C(30, 1);
            gpSector[j].floorstat &= ~0x80;
        }

        if (gpSector[j].floorstat & 0x1000)
        {
            D_800FEA90 = 1;
            func_8008E01C(30, 1);
            gpSector[j].floorstat &= ~0x1000;
        }

        if (gpSector[j].floorstat & 0x100)
        {
#if VERSION_FR
            func_800A419C(gPlayerNum, "ZONE SECRETE");
#else
            func_800A419C(gPlayerNum, "SECRET AREA");
#endif
            gpSector[j].floorstat &= ~0x100;
            D_801A1958.secrets_found++;
            playSfx(1595);
            func_801C363C(gPlayerNum, 10, 128);
        }

        if (!(gpSector[j].floorstat & 0x200))
        {
            if (gPlayer[gPlayerNum].unk5A != 0)
            {
                gPlayer[gPlayerNum].unk5A = 0;
                if (gPlayer[gPlayerNum].unk6C == 0)
                    gPlayer[gPlayerNum].third_person = gPlayer[gPlayerNum].unk61;
            }
        }

        if ((gpSector[j].floorstat & 0x2000) && (_pActor2->unk8 > 0) &&
            (_pActor2->unk8 < gPlayer[gPlayerNum].unk48))
        {
            if (D_800DEE64 == 0)
                D_800DEE64 = playSfx(502);

            if (!(D_8012FD88 & 3))
            {
                _pActor2->unk8 = MIN((_pActor2->unk8 + 1), gPlayer[gPlayerNum].unk48);
                func_8008E3E0(gPlayer[gPlayerNum].xpos, gPlayer[gPlayerNum].ypos, gpSector[j].floorz, j, 78, 1);
            }
        }
        else
        {
            MusHandleStop(D_800DEE64, 10);
            D_800DEE64 = 0;
        }

        if ((gpSector[j].floorstat & 0x4000) && (gPlayer[gPlayerNum].unk59 == 0) && (_pActor2->unk8 > 0))
        {
            i = gHeadSpriteStat[121];
            while (i >= 0)
            {
                if (gpSprite[i].sectnum == j)
                    break;

                i = gNextSpriteStat[i];
            }

            k = gPlayerNum;
            if (gPlayer[k].zpos >= gpSprite[i].z)
            {
                gPlayer[k].unk45 = 1;
                gPlayer[k].unk4E = 0;
                _pActor2->unk8 = 0;
                _pActor2->unk9E = 253;
                playSfx(991);
            }
        }

        j = gHeadSpriteStat[118];
        while (j >= 0)
        {
            k = gNextSpriteStat[j];
            if ((gpSprite[j].hitag == 0) && (dist(&gpSprite[j], &gpSprite[gPlayer[gPlayerNum].unk4A]) < 1024))
            {
                if (gMapNum == MAP_ALIEN_MOTHER)
                    func_8006B590(2031);
                else
                    func_8008E01C(30, 1);

                if (gpSprite[j].unk25 != 0)
                    D_800FEA90 = 1;

                changeSpriteStat(j, 0);
            }
            j = k;
        }
    }
}
