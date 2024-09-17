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

typedef void (*_6D9E0UnkFuncPointer)(s32 spritenum);

/*Skip following declaration so it defaults to s32*/
/*#include "code0/87010.h"*/
/*void func_80087174(s16 spritenum, s32 x1, s32 y1, s32 z1, s32 x2, s32 y2, s32 z2, s16, u8);*/
void func_800867CC(s16 spritenum, s32 x1, s32 y1, s32 z1, s32 x2, s32 y2, s32 z2, s16, u8);
static void func_800730CC(s32 spritenum);
static void func_80073670(s32 spritenum);
static void func_80073E0C(s32 spritenum);
static void func_800724B4(s32 spritenum);
static void func_80072ABC(s32 spritenum);
static void func_80074664(s32 spritenum);
static void func_800749A8(s32 spritenum);
static void func_80074C70(s32 spritenum);
static void func_80076364(s32 spritenum);
static void func_8007675C(s32 spritenum);
static void func_80076C14(s32 spritenum);
static void func_800780AC(s32 spritenum);
static s32 func_80077908(s32 spritenum);
static void func_80077E80(s32 spritenum);
static void func_80078F84(s32 spritenum);
static void func_80078924(s32 spritenum);
static void func_80078300(s32 spritenum);
static void func_80077C70(s32 spritenum);
static void func_80077AB0(s32 spritenum);
static void func_800743C0(s32 spritenum);
static void func_80078B70(s32 spritenum);
static void func_80075380(s32 spritenum);
static void func_800756B0(s32 spritenum);
static void func_80075C88(s32 spritenum);
static void func_80075E28(s32 spritenum);
static void func_800791A8(s32 spritenum);
static void func_80078564(s32 spritenum);
static void func_80076144(s32 spritenum);
static void func_80078DA8(s32 spritenum);
static void func_8007599C(s32 spritenum);
static void func_80077320(s32 spritenum);
static void func_80077608(s32 spritenum);
static void func_8007939C(s32 spritenum);

/*.data*/

/*800DF5A0*/
static _6D9E0UnkFuncPointer D_800DF5A0[50] = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    func_800730CC,
    func_80073670,
    func_80073E0C,
    NULL,
    func_800724B4,
    func_80072ABC,
    func_80074664,
    func_800749A8,
    NULL,
    func_80074C70,
    func_80076364,
    func_8007675C,
    NULL,
    func_80076C14,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    func_800780AC,
    func_80077908,
    NULL,
    func_80077E80,
    func_80078F84,
    func_80078924,
    func_80078300,
    func_80077C70,
    func_80077AB0,
    func_800743C0,
    func_80078B70,
    func_80075380,
    func_800756B0,
    func_80075C88,
    func_80075E28,
    func_800791A8,
    func_80078564,
    func_80076144,
    NULL,
    func_80078DA8,
    func_8007599C,
    func_80077320,
    func_80077608,
};

/*800DF668*/ static _6D9E0UnkFuncPointer D_800DF668[4] = {NULL, func_8007939C, NULL, NULL};

/*.bss*/
/*800F9CD0*/ static s32 D_800F9CD0;

/*.text*/
static void func_8007963C(s32 spritenum, s32);

/*8006CDE0*/
static s16 func_8006CDE0(s16 playernum, s32 *arg1, s32 *arg2, s32 *arg3)
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
            delta = getAngleDelta(ang, gPlayer[playernum].ang);
            if (((delta > 0) && (getAngleDelta(ang, gPlayer[playernum].ang)) < 384) ||
                ((delta <= 0) && (-getAngleDelta(ang, gPlayer[playernum].ang) < 384)))
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
        Bmemset(&D_8011A680[playernum][i], 0, sizeof(D_8011A680[playernum][i]));

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
s32 func_8006D3B8(s32 spritenum, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    Actor sp38;
    s32 xs, ys, zs;

    s16 sectnum;
    s16 hitsect, hitwall, hitsprite;
    s32 hitx, hity, hitz;

    s32 sp100;
    s32 sp104;
    s32 sp108;

    s16 ret;
    s16 sp12E;
    s32 sp134;
    s32 sp13C;

    SpriteType *spr;
    SpriteType *spr2;
    SpriteType *spr3;
    Actor *actor;

    f32 f1, f2, f3;
    s32 i, j, k, l, m, n, o;
    s16 spritenum1, spritenum2;
    s16 ang;
    u16 cstat;

    sp13C = 0;
    sp134 = 0;
    sp12E = -1;
    D_80199638 = 0;

label1:
    ret = spritenum;

    spr = &gpSprite[spritenum];
    if (gActorSpriteMap[spritenum] != -1)
        actor = &gActor[gActorSpriteMap[spritenum]];
    else
        actor = &sp38;

    sectnum = gpSprite[spritenum].sectnum;
    if (spr->statnum == 10)
    {
        j = spr->unk16;

        xs = gPlayer[j].xpos;
        ys = gPlayer[j].ypos;
        zs = gPlayer[j].zpos;

        if ((arg1 != 23) & (arg1 != 26))
            zs += 0x1000;

        ang = gPlayer[j].ang;
        f1 = (gPlayer[j].unk3E * (PI/1024));
        f2 = sinf(f1) / cosf(f1);
        o = f2 * 16384.0f * 16.0f;

        clipMove(&xs, &ys, &zs, &sectnum,
                 arg3 * gpSinTable[((arg2 + ang) + 0x200) & 0x7FF],
                 arg3 * gpSinTable[(arg2 + ang) & 0x7FF], 164, 0x80, 0x80, 0x10001);

        if (gpSector[spr->sectnum].floorstat & 0x8000)
        {
            s16 a;
            a = gHeadSpriteSect[spr->sectnum];
            while (a >= 0)
            {
                if (gpSprite[a].picnum == 39)
                {
                    func_8006B590(gpSprite[a].hitag);
                    gpSector[spr->sectnum].floorstat &= 0x7FFF;
                    deleteSprite(a);
                    break;
                }
                a = gNextSpriteSect[a];
            }
        }
    }
    else
    {
        ang = spr->ang;
        j = -1;
        xs = spr->x;
        ys = spr->y;
        zs = spr->z;
        if (actor->unk84 == 10)
        {
            f32 a;
            a = (gPlayer[0].zpos + 0x4000 - gpSprite[spritenum].z) / 16;
            f1 = getAngleF(a, func_80040D40(gPlayer[0].xpos, gPlayer[0].ypos, gpSprite[spritenum].x, gpSprite[spritenum].y));

            if (f1 >= 1.4726215563703124)
                f1 = 1.4726216f;
            else if (f1 <= -1.4726215563703124)
                f1 = -1.4726216f;
        }
        else
            f1 = (actor->unk7C + 16) * (PI/1024);

        f2 = sinf(f1) / cosf(f1);
        o = f2 * 16384.0f * 16.0f;

        if (gpSprite[spritenum].picnum == 32123)
            ang = (spr->ang - D_8013B2D0[spritenum].unk4) & 0x7FF;
        else
        {
            clipMove(&xs, &ys, &zs, &sectnum,
                    arg3 * gpSinTable[((arg2 + ang) + 0x200) & 0x7FF] * 8,
                    arg3 * gpSinTable[(arg2 + ang) & 0x7FF] * 8, 164, 0x80, 0x80, 0x10001);
        }
    }
    zs += (arg4 << 8);

    if (((actor->unk9E == 15) || (actor->unk9E == 9) || (actor->flag & 0x20000)) && ((arg1 == 100) || (arg1 == 103)))
        return -1;

    switch (arg1)
    {
    case 100:
    case 103:
        if (j >= 0)
            ang -= ((krand() & 0x7F) - 0x40);
        else
            ang -= ((krand() & 0x7F) - 0x440);
        krand();
    case 0:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 16:
    case 20:
    case 22:
    case 23:
    case 26:
    case 29:
        if (j >= 0)
        {
            if (gAutoAim != 0)
            {
                if (D_8013F920[arg1] > 0)
                {
                    sp134 = func_8004CE58(spr, D_8013F920[arg1], arg1);
                    if (sp134 >= 0)
                    {
                        func_80058600(sp134);
                        ldist(&gpSprite[gPlayer[D_801B0820].unk4A], &gpSprite[sp134]);
                        ang = getAngle(gpSprite[sp134].x - xs, gpSprite[sp134].y - ys);
                    }
                }
            }
        }
        else
        {
            zs -= 0x2E00;
            f1 = (actor->unk7C * (PI/1024));
            f2 = sinf(f1) / cosf(f1);
            o = f2 * 16384.0f * 16.0f;
        }

        if (arg1 < 50)
            l = D_8012DF00[arg1];
        else
            l = 32;

        if (actor->unk84 == 36)
            l = 16;

        if (l > 0)
        {
            ang += (krand() % l) - (l / 2);
            l *= 8;
            o += ((krand() % l) - (l / 2)) << 6;

        }
        if ((arg1 != 0x17) && (arg1 != 0x1A))
        {
            if ((arg1 == 7) || (arg1 == 0) || (arg1 == 5))
                zs -= 0xC00;
            else
                zs -= 0xD00;
        }
        cstat = spr->cstat;
        spr->cstat = cstat & 0xFEFE;
        D_80199638 = 1;

        hitScan(xs, ys, zs, sectnum,
            gpSinTable[(ang + 0x200) & 0x7FF],
            gpSinTable[ang & 0x7FF], o, &hitsect, &hitwall, &hitsprite, &hitx, &hity, &hitz, 0x01000040);

        spr->cstat = cstat;
        D_801AE918 = hitx;
        D_8010A9B0 = hity;
        D_8016A150 = hitz;

        if ((arg1 == 100) || (arg1 == 103))
        {
            if (findDistance2D(xs - hitx, ys - hity) >= 0x400)
                return -1;

            if (hitwall < 0)
                return -1;

            if (((gpWall[hitwall].nextsector < 0) || (hitsect < 0) ||
                (gpSector[gpWall[hitwall].nextsector].unk18 != 0) ||
                (gpSector[hitsect].unk18 != 0) ||
                ((gpSector[hitsect].floorz - gpSector[gpWall[hitwall].nextsector].floorz) < 0x1001)) &&
                ((gpWall[hitwall].nextsector != -1) || (gpSector[hitsect].unk18 != 0)))
                return -1;

            if (gpWall[hitwall].cstat & 0x10)
                return -1;

            if ((gpWall[hitwall].nextwall >= 0) && (gpWall[gpWall[hitwall].nextwall].unk16 != 0))
                return -1;

            if (gpWall[hitwall].unk16 != 0)
                return -1;

            n = (getAngle(gpWall[hitwall].x - gpWall[gpWall[hitwall].point2].x,
                gpWall[hitwall].y - gpWall[gpWall[hitwall].point2].y) - 0x200);
            n &= 0x7FF;

            if (arg1 == 100)
            {
                if (gMapNum != MAP_BRAINSTORM)
                    sp12E = func_80045400(hitx, hity, hitz, hitsect, 5, n, 25, 20);
            }
            else
                sp12E = func_80045400(hitx, hity, hitz, hitsect, 5, n, 25, 9);

            if (sp12E != -1)
                func_80056A54(sp12E);

            return -1;
        }

        actor->flag |= 0x100;
        if (hitsect < 0)
            return -1;

        sp12E = func_80058B3C(hitx, hity, hitz, hitsect, xs, ys, zs, arg1);
        if ((arg1 == 20) && (sp12E != -1))
        {
            hitsprite = -1;
            hitx = gpSprite[sp12E].x;
            hity = gpSprite[sp12E].y;
            hitz = gpSprite[sp12E].z;
            hitsect = gpSprite[sp12E].sectnum;
        }
        n = (ang - 0x400);
        n &= 0x7FF;

        if (arg1 == 0)
        {
            if ((klabs_(xs - hitx) + klabs_(ys - hity)) < 0x200)
            {
                if (hitsprite >= 0)
                {
                    Actor *actor2;
                    if (gActorSpriteMap[hitsprite] != -1)
                    {
                        actor2 = &gActor[gActorSpriteMap[hitsprite]];
                        if (func_8004D7D8(hitsprite) != 0)
                        {
                            if ((actor2->unk84 == 0) || (actor2->unk84 == 11) ||
                                (actor2->unk84 == 8) || (actor2->unk84 == 18))
                            {
                                func_8008E3E0(hitx, hity, hitz, hitsect, 42, 9);
                            }
                            else
                            {
                                if (gMapNum != MAP_BRAINSTORM)
                                    func_8008E3E0(hitx, hity, hitz, hitsect, 42, 20);
                            }

                            spritenum1 = func_80058934(hitx, hity, hitz, hitsect, 0);
                            if (spritenum1 != -1)
                            {
                                s32 a;
                                gpSprite[spritenum1].lotag = arg1;
                                gpSprite[spritenum1].hitag = spritenum;
                                gpSprite[spritenum1].unk2A = j;
                                if ((j >= 0) && (spr->picnum == RIPPER))
                                    a = 75;
                                else
                                    a = 15;
                                sp13C = func_80047820(spritenum1, hitsprite, a);
                                deleteSprite(spritenum1);
                            }
                            else
                                sp13C = 0;
                        }
                        n = (krand() & 1) | 536;
                        if (sp13C != 0)
                            n = 1353;

                        if (MusHandleAsk(actor->unk70) == 0)
                        {
                            actor->unk70 = audio_80007A44(n, spritenum, 24000);
                            actor->unk78 = 24000;
                        }
                        else if (MusHandleAsk(actor->unk6C) == 0)
                        {
                            actor->unk6C = audio_80007A44(n, spritenum, 24000);
                            actor->unk74 = 24000;
                        }
                    }
                    else
                    {
                        spritenum1 = func_80058934(hitx, hity, hitz, hitsect, 0);
                        if (spritenum1 != -1)
                        {
                            gpSprite[spritenum1].lotag = 0;
                            gpSprite[spritenum1].hitag = spritenum;
                            gpSprite[spritenum1].unk2A = j;
                            func_80047820(spritenum1, hitsprite, 2);
                            deleteSprite(spritenum1);
                        }
                        audio_80007820(1399, spritenum);
                    }
                }
                if (hitwall >= 0)
                {
                    if (!(gpWall[hitwall].cstat & 0x1000))
                        func_8004CB3C(hitwall);

                    audio_80007820(1399, spritenum);
                }
                if ((hitsprite != -1) || (hitwall != hitsprite))
                    return -1;
            }
            audio_80007820(837, spritenum);
            goto label2; /*FAKEMATCH*/
        }

        if (arg1 != 20)
        {
            if ((hitwall == -1) && (hitsprite == -1))
            {
                if (o < 0)
                {
                    if ((gpSector[hitsect].ceilingstat & 1))
                        return -1;
                }
            }

            if (arg1 == 2)
                func_80045400(hitx, hity, hitz, hitsect, 120, n, 14, 0);
            else
                func_80045400(hitx, hity, hitz, hitsect, 120, n, 6, 0);

            if (hitsprite >= 0)
            {
                s16 b;
                if ((arg1 != 2) && ((krand() & 0x7FFF) < 5000))
                {
                    s32 a;
                    for (a = 0; a < 3; a++)
                    {
                        spritenum1 = func_80045400(hitx, hity, hitz, hitsect, 80, n, 15, 1);
                        if (spritenum1 != -1)
                        {
                            gpSprite[spritenum1].unk22 -= (krand() & 0x3FF);
                            gpSprite[spritenum1].unk18 = krand() & 0x7F;
                        }
                    }

                    audio_800077F4(((krand() % 4) + 0x241), spritenum1);
                }
                b = D_8012E150[arg1];
                if ((j >= 0))
                {
                    if ((arg1 == 23) && (D_8011A680[j][23][0] & 4))
                        b *= 3;
                }
                spritenum1 = func_80058934(hitx, hity, hitz, hitsect, 0);
                if (spritenum1 != -1)
                {
                    gpSprite[spritenum1].lotag = arg1;
                    gpSprite[spritenum1].hitag = spritenum;
                    gpSprite[spritenum1].unk2A = j;
                    func_80047820(spritenum1, hitsprite, b + (krand() % 5));
                    deleteSprite(spritenum1);
                }
                break;
            }

            if (hitwall >= 0)
            {
                s32 a;
                a = getAngle(gpWall[hitwall].x - gpWall[gpWall[hitwall].point2].x,
                                    gpWall[hitwall].y - gpWall[gpWall[hitwall].point2].y);
                ret = a + 0x200;
                n = (a - 0x200);
                n &= 0x7FF;
                if (!(gpWall[hitwall].cstat & 0x1000))
                {
                    if (func_8004CB3C(hitwall) == 0)
                    {
                        if (D_8012C470 == 1)
                        {
                            if (arg1 == 2)
                            {
                                s32 a;
                                a = func_80045400(hitx, hity, hitz, hitsect, 5, n, 7, D_8012C470);
                                if (a >= 0)
                                    func_80056A54(a);
                            }
                            else
                            {
                                s32 a, b, c;
                                a = func_80045400(hitx, hity, hitz, hitsect, 5, n, 7, 0);
                                if (a >= 0)
                                    func_80056A54(a);

                                if ((krand() & 0x7FFF) < 0x1388)
                                {
                                    for (b = 0; b < 3; b++)
                                    {
                                        c = func_80045400(hitx, hity, hitz, hitsect, 80, n, 15, 1);
                                        if (c != -1)
                                        {
                                            gpSprite[c].unk22 -= (krand() & 0x3FF);
                                            gpSprite[c].unk18 = krand() & 0x7F;
                                        }
                                    }

                                    audio_800077F4(((krand() % 4) + 577), c);
                                }
                            }
                        }
                        break;
                    }

                    if ((arg1 == 23) || (arg1 == 26))
                        goto label1;
                }
            }
            break;
        }

        if ((j >= 0) && (gPlayer[j].unk54 != 0))
        {
            func_8008E3E0(xs, ys, zs - 0x400, spr->sectnum, 19, 18);
            spritenum1 = func_8008E3E0(xs, ys, zs - 0x400, spr->sectnum, 48, 0);
            if (spritenum1 != -1)
            {
                gpSprite[spritenum1].lotag = arg1;
                gpSprite[spritenum1].hitag = spritenum;
                gpSprite[spritenum1].unk2A = j;
                func_8004AB6C(spritenum1, 6000, 250, 500, 750, 1000, 1);
            }
            D_8011A680[j][20][1] = 1;
        }
        else
        {
            if (D_8012C470 == 1)
            {
                if (gpSprite[spritenum].statnum == 10)
                {
                    func_80015DE0(spritenum);
                    func_800867CC(spritenum, hitx, hity, hitz, D_801AE910, D_8013F950, D_8016A144, 64, 18);
                    func_800867CC((spritenum + 1), hitx, hity, hitz, D_801AE910, D_8013F950, D_8016A144, 16, 21);
                    func_800867CC((spritenum+2), hitx, hity, hitz, D_801AE910, D_8013F950, D_8016A144, 16, 21);
                }
                else
                {
                    func_800867CC(spritenum, hitx, hity, hitz, xs, ys, zs, 64, 18);
                    func_800867CC((spritenum + 1), hitx, hity, hitz, xs, ys, zs, 16, 21);
                    func_800867CC((spritenum+2), hitx, hity, hitz, xs, ys, zs, 16, 21);
                }
            }
            else
                func_800867CC(spritenum, hitx, hity, hitz, xs, ys, zs, 64, 18);
            func_8008E3E0(hitx, hity, hitz, hitsect, 15, 18);
            spritenum1 = func_80058934(hitx, hity, hitz, hitsect, 0);
            if (spritenum1 != -1)
            {
                gpSprite[spritenum1].unk22 -= (krand() & 0x3FF);
                gpSprite[spritenum1].unk18 = krand() & 0x7F;
            }
            if ((hitsprite >= 0) && (spritenum1 != -1))
            {
                gpSprite[spritenum1].lotag = arg1;
                gpSprite[spritenum1].hitag = spritenum;
                gpSprite[spritenum1].unk2A = j;

                if (D_8012FD88 == ((D_8012FD88 / 3) * 3))
                    func_80047820(spritenum1, hitsprite, D_8012E150[arg1] + (krand() % 5));
            }

            if (hitwall >= 0)
                func_8004CB3C(hitwall);

            if (spritenum1 != -1)
                deleteSprite(spritenum1);
        }
        break;
    case 19:
    case 32:
        actor->flag |= 0x100;
        if (j >= 0)
        {
            if (arg1 == 32)
                sp134 = func_8004CE58(spr, 48, 32);
            else
                sp134 = -1;

            if (sp134 >= 0)
            {
                o = func_80058600(sp134);
                ang = getAngle(gpSprite[sp134].x - xs, gpSprite[sp134].y - ys);
                o = ((((gpSprite[sp134].z - zs) - o) * 1800) / ldist(&gpSprite[gPlayer[j].unk4A], &gpSprite[sp134]));
                o /= 8;
            }
            else
            {
                f2 = sinf(f1) / cosf(f1);
                if ((arg1 == 19))
                    f3 = f2 * 2000.0f;
                else
                    f3 = f2 * 1800.0f;

                o = (2.0f * f3);
            }
        }
        else
        {
            ang = getAngle(gPlayer[0].xpos - xs, gPlayer[0].ypos - ys);
            o = ((((gPlayer[0].unk30 + gPlayer[0].unk40) - zs) * 1800) / ldist(&gpSprite[gPlayer[0].unk4A], spr));
            o /= 8;
        }
        ret = func_80058934(xs, ys, zs, sectnum, 4);
        if (ret != -1)
        {
            if (gpSprite[ret].sectnum != -1)
            {
                spr = &gpSprite[ret];
                spr->unk2A = 1;
                spr->cstat = 0x830;
                spr->xrepeat = 0x40;
                spr->yrepeat = 0x40;
                spr->picnum = 5753;
                spr->unk25 = 14;
                spr->lotag = arg1;
                spr->hitag = spritenum;
                spr->ang = ang;
                spr->unk1C = o;
                spr->unk1A = func_8007AE50();
                spr->unk16 = sp134;
                if (arg1 != 19)
                {
                    spr->unk18 = D_800F9CD0;
                    D_800F9CD0 += 90;
                }
                D_8013B2D0[ret].unk0 = krand() & 0x7FF;

                if (gpSprite[spritenum].picnum == CERBERUSTURRETS)
                    spr->unk2A = 0;
            }
            else
                deleteSprite(ret);
        }
        break;
    case 46:
        actor->flag |= 0x100;
        zs -= 0x4000;
        ang = getAngle(gPlayer[0].xpos - xs, gPlayer[0].ypos - ys);
        o = (((gPlayer[0].unk30 + 0x800 - zs) * 500) / ldist(&gpSprite[gPlayer[0].unk4A], spr));
        o /= 8;
        xs -= (gpSinTable[(ang + 860) & 0x7FF] / 448);
        ys -= (gpSinTable[(ang + 348) & 0x7FF] / 448);
        zs -= 0x100;
        ret = func_80058934(xs, ys, zs, sectnum, 4);
        if (ret != -1)
        {
            D_8013B2D0[ret].unk0 = 0;
            D_8013B2D0[ret].unk2 = 0;
            D_8013B2D0[ret].unk6 = 0;
            spr = &gpSprite[ret];
            spr->cstat = 0x1000;
            spr->xrepeat = 0x40;
            spr->yrepeat = 0x40;
            spr->unk25 = 0;
            spr->unk18 = 0;
            spr->unk1A = 0;
            spr->picnum = 2561;
            spr->lotag = arg1;
            spr->hitag = spritenum;
            spr->ang = ang;
            spr->unk1C = o;
        }
        break;
    case 37:
    {
        s16 a, b;
        b = (spr->ang - gActor[gActorSpriteMap[spritenum]].unk7C) & 0x7FF;
        a = gActor[gActorSpriteMap[spritenum]].unk44;
        zs -= 0x4000;
        ret = func_80058934(xs, ys, zs, sectnum, 4);
        if (ret != -1)
        {
            spr = &gpSprite[ret];
            spr->cstat = 0x830;
            spr->xrepeat = 0x40;
            spr->yrepeat = 0x40;
            spr->unk25 = 0;
            spr->picnum = 5753;
            spr->lotag = arg1;
            spr->hitag = spritenum;
            spr->unk1A = func_8007AE50();
            D_8013B2D0[ret].unk0 = krand() & 0x7FF;

            o = ((gpSprite[a].z - 0x1300 - zs) * 6000) /
                findDistance2D(gpSprite[a].x - xs, gpSprite[a].y - ys);

            o /= 8;
            spr->unk1C = o;
            spr->ang = b;
            spr->unk18 = 0;
            spr->unk22 = 15;
            gActorSpriteMap[ret] = allocActor();
            gActor[gActorSpriteMap[ret]].unk74 = 12000;
        }
    }
    break;
    case 17:
        actor->flag |= 0x100;
        if (j >= 0)
        {
            f2 = sinf(f1) / cosf(f1);
            o = (2.0f * (f2 * 3600.0f));
        }
        else
        {
            zs -= 0x4000;
            ang = getAngle(gPlayer[0].xpos - xs, gPlayer[0].ypos - ys);
            o = ((gPlayer[0].unk30 + 0x800 - zs) * 3600) / ldist(&gpSprite[gPlayer[0].unk4A], spr);
            o /= 8;
        }
        xs -= gpSinTable[(ang + 860) & 0x7FF] / 448;
        ys -= gpSinTable[(ang + 348) & 0x7FF] / 448;
        zs -= 0x100;
        l = D_8012DF00[arg1];
        if (l > 0)
        {
            ang += (krand() % l) - (l / 2);
            l *= 8;
            o += ((krand() % l) - (l / 2));
        }
        ret = func_80058934(xs, ys, zs, sectnum, 4);
        if (ret != -1)
        {
            spr = &gpSprite[ret];
            D_8013B2D0[ret].unk0 = krand() & 0x7FF;
            D_8013B2D0[ret].unk6 = 0;
            spr->cstat = 0x8B0;
            spr->unk25 = 30;
            spr->xrepeat = 0x18;
            spr->yrepeat = 0x18;
            spr->unk18 = 0;
            spr->unk1A = 0;

            if (gpSprite[spritenum].statnum == 10)
                spr->unk22 = 45;
            else
                spr->unk22 = 173;

            if (j >= 0)
            {
                if (gPlayer[j].third_person)
                {
                    spr->xrepeat = 0x24;
                    spr->yrepeat = 0x24;
                }
                else
                {
                    spr->xrepeat = 0x14;
                    spr->yrepeat = 0x14;
                }
            }

            spr->picnum = 5550;
            spr->lotag = arg1;
            spr->hitag = spritenum;
            spr->ang = ang;
            spr->unk1C = o;
        }
        break;
    case 21:
        actor->flag |= 0x100;
        if (j >= 0)
        {
            func_8001F7B4(6, 6);
            f2 = sinf(f1) / cosf(f1);
            o = (2.0f * (f2 * 2300.0f));
        }
        else
        {
            zs -= 0x4000;
            ang = getAngle(gPlayer[0].xpos - xs, gPlayer[0].ypos - ys);
            o = ((gPlayer[0].unk30 + 0x1000 - zs) * 2300) / ldist(&gpSprite[gPlayer[0].unk4A], spr);
            o /= 8;
        }

        xs -= (gpSinTable[(ang + 860) & 0x7FF] / 448);
        ys -= (gpSinTable[(ang + 348) & 0x7FF] / 448);
        zs -= 0x100;
        ret = func_80058934(xs, ys, zs, sectnum, 4);
        if (ret != -1)
        {
            spr = &gpSprite[ret];
            if (D_8012C470 == 1)
                spr->cstat = 0x8000;
            else
                spr->cstat = 0x8B0;
            spr->unk25 = 31;
            spr->xrepeat = 0x60;
            spr->yrepeat = 0x60;
            spr->unk18 = 0;
            spr->unk1A = 0;
            spr->unk1C = 0;
            spr->picnum = 5550;
            spr->lotag = arg1;
            spr->hitag = spritenum;
            spr->ang = ang;
            spr->unk1C = o;
            spr->unk2A = func_8007AE50();
        }
        break;
    case 48:
        actor->flag |= 0x100;
        o = gPlayer[0].xpos + ((krand() & 0xFFF) - 0x800);
        m = gPlayer[0].ypos + ((krand() & 0xFFF) - 0x800);
        l = gpSprite[gPlayer[0].unk4A].z - (krand() & 0x1FFF);
        ang = getAngle(o - xs, m - ys);
        o = ((l - 0x1C80 - zs) * 5000) / findDistance2D(o - xs, m - ys);
        o /= 8;
        xs -= (gpSinTable[(ang + 860) & 0x7FF] / 448);
        ys -= (gpSinTable[(ang + 348) & 0x7FF] / 448);
        zs -= 0x100;
        ret = func_80058934(xs, ys, zs, sectnum, 4);
        if (ret != -1)
        {
            spr = &gpSprite[ret];
            spr->cstat = 0x880;
            spr->unk25 = 28;
            spr->xrepeat = 0x30;
            spr->yrepeat = 0x30;
            spr->unk18 = 0;
            spr->unk1A = 0;
            spr->picnum = 5550;
            spr->lotag = arg1;
            spr->hitag = spritenum;
            spr->ang = ang;
            spr->unk1C = o;
        }
        break;
    case 49:
        actor->flag |= 0x100;
        o = gPlayer[0].xpos;
        m = gPlayer[0].ypos;
        l = gpSprite[gPlayer[0].unk4A].z;
        ang = getAngle(o - xs, m - ys);
        o = ((l - 0x1C80 - zs) * 5000) / findDistance2D(o - xs, m - ys);
        o /= 8;
        xs -= (gpSinTable[(ang + 860) & 0x7FF] / 448);
        ys -= (gpSinTable[(ang + 348) & 0x7FF] / 448);
        zs -= 0x100;
        ret = func_80058934(xs, ys, zs, sectnum, 4);
        if (ret != -1)
        {
            spr = &gpSprite[ret];
            spr->cstat = 0x880;
            spr->unk25 = 1;
            spr->xrepeat = 0;
            spr->yrepeat = 0;
            spr->unk18 = 0;
            spr->unk1A = 0;
            spr->picnum = 5744;
            spr->lotag = arg1;
            spr->hitag = spritenum;
            spr->ang = ang;
            spr->unk1C = o;
        }
        break;
    case 28:
        actor->flag |= 0x100;
        ret = func_80058934(xs, ys, zs, sectnum, 4);
        if (ret != -1)
        {
            spr = &gpSprite[ret];
            spr->cstat = 0x1000;
            spr->xrepeat = 0xFF;
            spr->picnum = 1811;
            spr->unk25 = 0;
            spr->lotag = arg1;
            spr->hitag = spritenum;
            spr->unk1C = 0;
            spr->ang = ang;
        }
        break;
    case 35:
        ret = func_80058934(xs, ys, zs, sectnum, 4);
        if (ret != -1)
        {
            spr = &gpSprite[ret];
            spr->cstat = 0x1000;
            spr->xrepeat = 0xFF;
            spr->unk25 = 0;
            spr->picnum = 2299;
            spr->lotag = arg1;
            spr->hitag = spritenum;
            spr->unk1C = 0;
            spr->ang = gpSprite[spritenum].ang;
        }
        break;
    case 34:
        getAngle(gPlayer[0].xpos - xs, gPlayer[0].ypos - ys);
        ret = func_80058934(xs, ys, zs, sectnum, 4);
        if (ret != -1)
        {
            spr = &gpSprite[ret];
            spr->cstat = 0x1000;
            spr->xrepeat = 0x50;
            spr->picnum = 1873;
            spr->unk25 = 0;
            spr->lotag = arg1;
            spr->hitag = spritenum;
            spr->unk1C = 0;
            func_8006D1F4(spr, gPlayer[0].xpos, gPlayer[0].ypos, gPlayer[0].zpos + 0x3900, 30, 300, 0x2000);
        }
        break;
    case 30:
        actor->flag |= 0x100;
        zs -= 0x2C00;
        ang = getAngle(gPlayer[0].xpos - xs, gPlayer[0].ypos - ys);
        o = (((gPlayer[0].unk30 + (gPlayer[0].unk40/2)) - zs) * 0x7D0) / ldist(&gpSprite[gPlayer[0].unk4A], spr);
        o /= 8;
        ret = func_80058934(xs, ys, zs, sectnum, 4);
        if (ret != -1)
        {
            spr = &gpSprite[ret];
            spr->cstat = -0x8000;
            spr->xrepeat = 0x30;
            spr->yrepeat = 0x30;
            spr->unk18 = 0;
            spr->unk1A = 0;
            spr->unk1C = 0;
            spr->picnum = 5771;
            spr->lotag = arg1;
            spr->hitag = spritenum;
            spr->ang = ang;
            spr->unk1C = o;
        }
        break;
    case 27:
        actor->flag |= 0x100;
        ret = func_80058934(xs, ys, zs, sectnum, 4);
        if (ret != -1)
        {
            if (gpSprite[ret].sectnum != -1)
            {
                spr = &gpSprite[ret];
                spr->cstat = 0x8000;
                spr->picnum = 1557;
                spr->unk25 = 0;
                spr->lotag = arg1;
                spr->hitag = spritenum;
                spr->unk22 = 0;
                func_8008E3E0(xs, ys, zs, spr->sectnum, 66, 8);
            }
            else
                deleteSprite(ret);
        }
        break;
    case 33:
        actor->flag |= 0x100;
        zs -= 0x4000;
        if (((gActor[gActorSpriteMap[spritenum]].flag & 0x1000) || (gActor[gActorSpriteMap[spritenum]].flag & 0x800)) &&
            (gActor[gActorSpriteMap[spritenum]].unk28 != -1))
        {
            k = gActor[gActorSpriteMap[spritenum]].unk28;
            ang = getAngle(gpSprite[k].x - xs, gpSprite[k].y - ys);
            o = ((gpSprite[k].z - 0x1800 - zs) * 4500) / ldist(&gpSprite[k], spr);
        }
        else
        {
            ang = getAngle(gPlayer[0].xpos - xs, gPlayer[0].ypos - ys);
            o = ((gPlayer[0].unk30 + 0x800 - zs) * 4500) / ldist(&gpSprite[gPlayer[0].unk4A], spr);
        }

        o /= 8;
        ang -= ((krand() & 0x3F) - 0x20);

        ret = func_80058934(xs, ys, zs, sectnum, 4);
        if (ret != -1)
        {
            spr = &gpSprite[ret];
            spr->cstat = 0x8000;
            spr->picnum = 5753;
            spr->xrepeat = 0x20;
            spr->yrepeat = 0x20;
            spr->unk18 = 0;
            spr->unk1A = 0;
            spr->unk1C = 0;
            spr->lotag = arg1;
            spr->hitag = spritenum;
            spr->ang = ang;
            spr->unk1C = o;
            spr->unk1A = func_8007AE50();
        }
        break;
    case 43:
        actor->flag |= 0x100;
        zs -= 0x4000;
        if (((gActor[gActorSpriteMap[spritenum]].flag & 0x1000) || (gActor[gActorSpriteMap[spritenum]].flag & 0x800)) &&
            (gActor[gActorSpriteMap[spritenum]].unk28 != -1))
        {
            k = gActor[gActorSpriteMap[spritenum]].unk28;
            ang = getAngle(gpSprite[k].x - xs, gpSprite[k].y - ys);
            o = ((gpSprite[k].z - 0x1800 - zs) * 7000) / ldist(&gpSprite[k], spr);
        }
        else
        {
            ang = getAngle(gPlayer[0].xpos - xs, gPlayer[0].ypos - ys);
            o = ((gPlayer[0].unk30 + 0x800 - zs) * 7000) / ldist(&gpSprite[gPlayer[0].unk4A], spr);
        }

        o /= 8;
        ang -= ((krand() & 0xF) - 8);
        o -= ((krand() & 0x200) - 0xFF);

        ret = func_80058934(xs, ys, zs, sectnum, 4);
        if (ret != -1)
        {
            spr = &gpSprite[ret];
            spr->cstat = 0x8000;
            spr->picnum = 5753;
            spr->xrepeat = 0x20;
            spr->yrepeat = 0x20;
            spr->unk18 = 0;
            spr->unk1A = 0;
            spr->unk1C = 0;
            spr->lotag = arg1;
            spr->hitag = spritenum;
            spr->ang = ang;
            spr->unk1C = o;
            spr->unk1A = func_8007AE50();
        }
        break;
    case 18:
        actor->flag |= 0x100;
        f2 = sinf(f1) / cosf(f1);
        o = (2.0f * (f2 * 2500.0f));
        zs -= 0xA00;

        spritenum2 = func_80058934(xs, ys, zs, sectnum, 4);
        if (spritenum2 != -1)
        {
            spr = &gpSprite[spritenum2];
            spr->cstat = 0x830;
            spr->unk25 = 1;
            spr->xrepeat = 0x40;
            spr->yrepeat = 0x40;
            spr->picnum = 5753;
            spr->lotag = arg1;
            spr->hitag = spritenum;
            spr->unk1C = o;
            spr->unk1A = func_8007AE50();
            ret = spritenum2;
            D_8013B2D0[ret].unk0 = krand() & 0x7FF;

            if (D_8012C470 >= 2)
            {
                spr->ang = ang;
                spr->unk18 = 0;
            }
            else
            {
                spritenum1 = func_80058934(xs, ys, zs, sectnum, 4);
                if (spritenum1 != -1)
                {
                    spr2 = &gpSprite[spritenum1];
                    spr2->cstat = 0x830;
                    spr2->unk25 = 1;
                    spr2->xrepeat = 0x40;
                    spr2->yrepeat = 0x40;
                    spr2->picnum = 5753;
                    spr2->lotag = arg1;
                    spr2->hitag = spritenum;
                    spr2->unk1C = o;
                    spr2->unk1A = func_8007AE50();
                    D_8013B2D0[spritenum1].unk0 = krand() & 0x7FF;
                    spritenum1 = func_80058934(xs, ys, zs, sectnum, 4);

                    if (spritenum1 != -1)
                    {
                        spr3 = &gpSprite[spritenum1];
                        spr3->cstat = 0x830;
                        spr3->unk25 = 1;
                        spr3->xrepeat = 0x40;
                        spr3->yrepeat = 0x40;
                        spr3->picnum = 5753;
                        spr3->lotag = arg1;
                        spr3->hitag = spritenum;
                        spr3->unk1C = o;
                        spr3->unk1A = func_8007AE50();
                        D_8013B2D0[spritenum1].unk0 = krand() & 0x7FF;

                        if (func_8006CDE0(j, &sp100, &sp104, &sp108) == -1)
                        {
                            spr->ang = ang - 24;
                            spr2->ang = ang;
                            spr2->unk1C += 250;
                            spr2->z += 0x200;
                            spr3->ang = ang + 24;
                            spr->unk18 = 0;
                            spr2->unk18 = 682;
                        }
                        else
                        {
                            o = func_80058600(sp100);
                            o = (((gpSprite[sp100].z - zs) - o) * 2500) / ldist(&gpSprite[gPlayer[j].unk4A], &gpSprite[sp100]);
                            o /= 8;
                            spr->unk1C = o;
                            spr->ang = getAngle(gpSprite[sp100].x - xs, gpSprite[sp100].y - ys);
                            spr->unk18 = 0;
                            o = func_80058600(sp104);
                            o = (((gpSprite[sp104].z - zs) - o) * 2500) / ldist(&gpSprite[gPlayer[j].unk4A], &gpSprite[sp104]);
                            o /= 8;
                            spr2->unk1C = o;
                            spr2->ang = getAngle(gpSprite[sp104].x - xs, gpSprite[sp104].y - ys);
                            spr2->unk18 = 682;
                            o = func_80058600(sp108);
                            o = (((gpSprite[sp108].z - zs) - o) * 2500) / ldist(&gpSprite[gPlayer[j].unk4A], &gpSprite[sp108]);
                            o /= 8;
                            spr3->unk1C = o;
                            spr3->ang = getAngle(gpSprite[sp108].x - xs, gpSprite[sp108].y - ys);
                        }
                        spr3->unk18 = 1365;
                    }
                }
            }
        }
        break;
    case 31:
        actor->flag |= 0x100;
        ret = func_80058934(xs, ys, zs, sectnum, 4);
        if (ret != -1)
        {
            spr = &gpSprite[ret];
            spr->cstat = 0x1000;
            spr->xrepeat = 0x40;
            spr->yrepeat = 0x40;
            spr->picnum = 1558;
            spr->unk25 = 0;
            spr->unk16 = 0;
            spr->unk22 = 0;
            spr->lotag = arg1;
            ang = getAngle(gPlayer[0].unk28 - xs, gPlayer[0].unk2C - ys);
            o = ((gPlayer[0].unk30 - zs) * 600) / ldist(&gpSprite[gPlayer[0].unk4A], spr);
            o /= 8;
            spr->ang = ang;
            spr->unk1C = o;
        }
        break;
    case 36:
        getAngle(gPlayer[0].xpos - xs, gPlayer[0].ypos - ys);
        ret = func_80058934(xs, ys, zs, sectnum, 4);
        if (ret != -1)
        {
            spr = &gpSprite[ret];
            spr->cstat = 0x1000;
            spr->xrepeat = 0xFF;
            spr->picnum = 1811;
            spr->unk25 = 0;
            spr->lotag = arg1;
            spr->hitag = spritenum;
            spr->unk1C = 0;
            func_8006D1F4(spr, gPlayer[0].xpos, gPlayer[0].ypos, gPlayer[0].zpos + 0x3900, 80, 300, 0x8000);
        }
        break;
    case 8:
    case 9:
        actor->flag |= 0x100;
        ret = func_80058934(xs, ys, zs, sectnum, 4);
        if (ret != -1)
        {
            s32 a;
            spr = &gpSprite[ret];
            spr->cstat = 0x1000;
            spr->unk2B = 100;
            spr->unk25 = 0;
            spr->lotag = arg1;
            spr->hitag = spritenum;

            if (arg1 == 8)
                spr->unk22 = 90;
            else
                spr->unk16 = 0;

            spr->xrepeat = 0x7F;
            spr->picnum = 1811;
            spr->unk2A = 0;

            if (j >= 0)
                f2 = gPlayer[j].unk3E * (PI/1024);
            else
            {
                ang = getAngle(gPlayer[0].xpos - xs, gPlayer[0].ypos - ys);
                f2 = actor->unk7C * (PI/1024);
            }

            a = (cosf(f2) * 3072.0f);
            o = (sinf(f2) * 3072.0f);
            if (func_8004EFB4(ret) != 0)
            {
                a /= 2;
                o /= 2;
            }
            spr->unk18 = a;
            spr->unk1C = o * 2;
            spr->ang = ang;
        }
        break;
    case 10:
        cstat = spr->cstat;
        spr->cstat = cstat & 0xFEFE;

        hitScan(xs, ys, zs, sectnum,
            gpSinTable[(ang + 0x200) & 0x7FF],
            gpSinTable[ang & 0x7FF],
            o, &hitsect, &hitwall, &hitsprite, &hitx, &hity, &hitz, 0x01000040);

        spr->cstat = cstat;
        ret = func_80058934(xs, ys, zs, sectnum, 4);
        if (ret != -1)
        {
            spr = &gpSprite[ret];
            spr->cstat = 0x1100;
            spr->unk25 = 0;
            spr->lotag = arg1;
            spr->hitag = spritenum;
            spr->unk2B = 100;
            spr->unk22 = 0;
            audio_800077F4(1010, ret);
            spr->xrepeat = 0x7F;
            spr->picnum = 1817;
            func_8006D1F4(spr, hitx, hity, hitz, 30, 0x64, 0x1000);
        }
        break;
    case 12:
    case 13:
        if (j >= 0)
        {
            cstat = spr->cstat;
            spr->cstat = cstat & 0xFEFE;

            hitScan(xs, ys, zs, sectnum,
                gpSinTable[(ang + 0x200) & 0x7FF],
                gpSinTable[ang & 0x7FF],
                o, &hitsect, &hitwall, &hitsprite, &hitx, &hity, &hitz, 0x01000040);

            spr->cstat = cstat;
        }
        else
        {
            hitx = gPlayer[0].xpos;
            hity = gPlayer[0].ypos;
            hitz = gPlayer[0].zpos + 0x3900;
        }
        ret = func_80058934(xs, ys, zs, sectnum, 4);
        if (ret != -1)
        {
            spr = &gpSprite[ret];
            spr->cstat = 0x1000;
            spr->unk2B = 0x64;
            spr->unk25 = 0;
            spr->lotag = arg1;
            spr->hitag = spritenum;
            spr->unk22 = 90;
            audio_800077F4(1010, ret);
            D_8013B2D0[ret].handle = audio_800077F4(581, ret);
            spr->unk1C = 0;
            if (arg1 == 13)
            {
                spr->xrepeat = 0x50;
                spr->picnum = 1873;
                func_8006D1F4(spr, hitx, hity, hitz, 30, 0x64, 0x1000);
            }
            else
            {
                spr->xrepeat = 0x7F;
                spr->picnum = 1869;
                func_8006D1F4(spr, hitx, hity, hitz, 30, 0x64, 0x1000);
            }
        }
        break;
    case 42:
        i = gHeadSpriteStat[7];
        while (i >= 0)
        {
            if (gpSprite[i].hitag == gpSprite[spritenum].hitag)
                break;

            i = gNextSpriteStat[i];
        }
        hitx = gpSprite[i].x;
        hity = gpSprite[i].y;
        hitz = gpSprite[i].z;
        ret = func_80058934(xs, ys, zs, sectnum, 4);
        if (ret != -1)
        {
            spr = &gpSprite[ret];
            spr->cstat = 0x1000;
            spr->unk2B = 0x64;
            spr->xrepeat = 0x40;
            spr->picnum = 1510;
            spr->unk25 = 0;
            spr->lotag = arg1;
            spr->hitag = spritenum;
            spr->unk1C = 0;
            func_8006D1F4(spr, hitx, hity, hitz, 30, 200, 0x1000);
        }
        break;
    case 15:
        actor->flag |= 0x100;
        f2 = sinf(f1) / cosf(f1);
        o = (2.0f * (f2 * 2000.0f));
        zs -= 0xA00;
        ret = func_80058934(xs, ys, zs, sectnum, 4);
        if (ret != -1)
        {
            s32 a;
            spr = &gpSprite[ret];
            a = krand() & 1;
            spr->picnum = a + (krand() & 1) + 5542;
            spr->xrepeat = 0x10;
            spr->yrepeat = 0x10;
            spr->unk25 = 0x12;
            spr->cstat = 0x8B0;
            spr->unk18 = 0;
            spr->unk1A = (krand() & 0x3F) - 0x20;
            spr->lotag = arg1;
            spr->hitag = spritenum;
            spr->unk1C = o;
            spr->ang = ang;
        }
        break;
    case 38:
        actor->flag |= 0x100;
        ang = spr->ang;
        zs -= 0x4000;
        o = ((gpSprite[gPlayer[0].unk4A].z - 0x1C80 - zs) * 3600) /
            findDistance2D(gpSprite[gPlayer[0].unk4A].x - xs, gpSprite[gPlayer[0].unk4A].y - ys);
        o /= 8;
        ang -= ((krand() & 0x3F) - 0x20);
        o -= ((krand() & 0xFF) - 0x80);
        ret = func_80058934(xs, ys, zs, sectnum, 4);
        if (ret != -1)
        {
            spr = &gpSprite[ret];
            D_8013B2D0[ret].unk0 = krand() & 0x7FF;
            D_8013B2D0[ret].unk6 = 0;
            spr->cstat = 0x8B0;
            spr->unk25 = 28;
            spr->xrepeat = 0x40;
            spr->yrepeat = 0x40;
            spr->unk22 = 45;
            spr->unk18 = 0;
            spr->unk1A = 0;
            spr->picnum = 5535;
            spr->lotag = arg1;
            spr->hitag = spritenum;
            spr->ang = ang;
            spr->unk1C = o;
        }
        break;
    case 39:
        ang = spr->ang;
    case 47:
        zs -= 0xA00;
        ret = func_80058934(xs, ys, zs, sectnum, 4);
        if (ret != -1)
        {
            spr = &gpSprite[ret];
            spr->cstat = 0x830;
            spr->unk25 = 1;
            spr->xrepeat = 0x40;
            spr->yrepeat = 0x40;
            spr->picnum = 5753;
            spr->lotag = arg1;
            spr->hitag = spritenum;
            spr->unk1A = func_8007AE50();
            D_8013B2D0[ret].unk0 = krand() & 0x7FF;

            o = ((gpSprite[gPlayer[0].unk4A].z - 0x3900 - zs) * 3600) /
                findDistance2D(gpSprite[gPlayer[0].unk4A].x - xs, gpSprite[gPlayer[0].unk4A].y - ys);

            o /= 8;
            spr->unk1C = o;
            spr->ang = ang;
            spr->unk18 = 0;
            spr->unk22 = 15;
        }
        break;
    case 40:
        ret = func_80058934(xs, ys, zs, sectnum, 4);
        if (ret != -1)
        {
            spr = &gpSprite[ret];
            spr->cstat = 0x830;
            spr->unk25 = 18;
            spr->xrepeat = 1;
            spr->yrepeat = 1;
            spr->picnum = 5771;
            spr->lotag = arg1;
            spr->hitag = spritenum;
            D_8013B2D0[ret].unk0 = 0;
            spr->unk22 = 0x80;
            spr->unk2B = 0;
        }
        break;
    case 41:
        ret = func_80058934(xs, ys, zs, sectnum, 4);
        if (ret != -1)
        {
            spr = &gpSprite[ret];
            spr->cstat = 0x1800;
            spr->unk25 = 18;
            spr->xrepeat = 0xFF;
            spr->yrepeat = 0xFF;
            spr->picnum = 1706;
            spr->lotag = arg1;
            spr->hitag = spritenum;
            spr->ang = krand() & 0x7FF;
            spr->unk22 = 0x80;
            spr->unk1C = -(krand() & 0x3FF);
            spr->unk18 = (krand() & 0x7FF) + 0x28;
            D_8013B2D0[ret].unk2 = krand() & 0x7FF;
            D_8013B2D0[ret].unk0 = krand() & 0x7FF;
        }
        break;
    case 44:
        actor->flag |= 0x100;
        zs -= 0xA00;
        o = 0x640;
        ret = func_80058934(xs, ys, zs, sectnum, 4);
        if (ret != -1)
        {
            s32 a;
            spr = &gpSprite[ret];
            a = krand() & 1;
            spr->picnum = a + (krand() & 1) + 5542;
            spr->xrepeat = 0x10;
            spr->yrepeat = 0x10;
            spr->unk25 = 22;
            spr->cstat = 0x8B0;
            spr->unk18 = 0;
            spr->unk1A = (krand() & 0x3F) - 0x20;
            spr->lotag = arg1;
            spr->hitag = spritenum;
            spr->unk1C = o;
            spr->ang = ang;
        }
        break;
    case 14:
        cstat = gpSprite[gPlayer[j].unk4A].cstat;
        gpSprite[gPlayer[j].unk4A].cstat = cstat & 0xFEFE;
        zs -= 0x800;

        hitScan(xs, ys, zs, sectnum,
                gpSinTable[(ang + 0x200) & 0x7FF],
                gpSinTable[ang & 0x7FF], o, &hitsect, &hitwall, &hitsprite, &hitx, &hity, &hitz, 0x01000040);

        o = 0;
        gpSprite[gPlayer[j].unk4A].cstat = cstat;

        if (hitsprite < 0)
        {
            if (hitwall >= 0)
            {
                if (hitsect >= 0)
                {
                    if ((gpWall[hitwall].overpicnum != 5300) ||(((gpWall[hitwall].cstat & 0x10) == 0)))
                    {
                        if ((gpWall[hitwall].cstat & 0x1000))
                            return -1;

                        if (((hitx - xs) * (hitx - xs)) + ((hity - ys) * (hity - ys)) <= 84099)
                            o = 1;
                    }
                    else
                        return -1;
                }
            }

            if (o == 1)
            {
                ret = func_80058934(hitx, hity, hitz, hitsect, 4);
                if (ret != -1)
                {
                    if (gpSprite[ret].sectnum == -1)
                    {
                        deleteSprite(ret);
                        return -1;
                    }

                    spr = &gpSprite[ret];
                    spr->unk2B = 0;
                    spr->xrepeat = 0x40;
                    spr->yrepeat = 0x40;
                    spr->cstat = 0x1100;
                    spr->picnum = 1841;
                    spr->unk24 = gpSector[hitsect].unk26;
                    spr->lotag = arg1;
                    spr->hitag = spritenum;
                    spritenum1 = getAngle(gpWall[hitwall].x - gpWall[gpWall[hitwall].point2].x,
                                         gpWall[hitwall].y - gpWall[gpWall[hitwall].point2].y) - 0x200;
                    spr->ang = spritenum1;
                    hitx += ((gpSinTable[(spritenum1 + 0x200) & 0x7FF] * 5) >> 13);
                    hity += ((gpSinTable[spritenum1 & 0x7FF] * 5) >> 13);

                    setSprite(ret, hitx, hity, hitz);
                    if (j >= 0)
                    {
                        if (gPlayer[j].cursectnum != -69)
                        {
                            if (D_8011A680[j][arg1][0] & 4)
                                spr->picnum = 1844;

                            audio_800077F4(779, ret);
                        }
                        else
                            spr->hitag = -1;
                    }

                    if (gpSprite[ret].sectnum != -1)
                    {
                        spr->unk18 = 0;
                        spr->unk1A = 0;
                        spr->unk1C = 0;
                        return ret;
                    }
                    deleteSprite(ret);
                }
            }
        }
    label2:
        return -1;
    default:
        break;
    }

    return ret;
}

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
            func_8004CC90(i, gpSprite[spritenum].lotag, gpSprite[spritenum].picnum);
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
static void func_800724B4(s32 spritenum)
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

    cstat2 = gpSprite[spr->hitag].cstat;
    cstat = spr->cstat;
    spr->cstat = cstat & ~0x101;
    gpSprite[spr->hitag].cstat &= ~0x101;

    getzRange(spr->x, spr->y, (spr->z - 2048), spr->sectnum,
              &ceilz, &ceilhit, &florz, &florhit, 64, 0x10001);

    spr->cstat = cstat;
    gpSprite[spr->hitag].cstat = cstat2;

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
static void func_80072ABC(s32 spritenum)
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

    cstat2 = gpSprite[spr->hitag].cstat;
    cstat = spr->cstat;
    spr->cstat = cstat & ~0x101;
    gpSprite[spr->hitag].cstat &= ~0x101;

    getzRange(spr->x, spr->y, (spr->z - 2048), spr->sectnum,
              &ceilz, &ceilhit, &florz, &florhit, 64, 0x10001);

    spr->cstat = cstat;
    gpSprite[spr->hitag].cstat = cstat2;

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
static void func_800730CC(s32 spritenum)
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
        cstat2 = gpSprite[spr->hitag].cstat;
        spr->cstat = cstat & ~0x101;
        gpSprite[spr->hitag].cstat &= ~0x101;

        getzRange(spr->x, spr->y, (spr->z - 2048), spr->sectnum,
                  &ceilz, &ceilhit, &florz, &florhit, 64, 0x10001);

        spr->cstat = cstat;
        gpSprite[spr->hitag].cstat = cstat2;

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
static void func_80073670(s32 spritenum)
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
    cstat2 = gpSprite[spr->hitag].cstat;
    spr->cstat = cstat & ~0x101;
    gpSprite[spr->hitag].cstat &= ~0x101;

    getzRange(spr->x, spr->y, (spr->z - 2048), spr->sectnum,
              &ceilz, &ceilhit, &florz, &florhit, 64, 0x10001);

    spr->cstat = cstat;
    gpSprite[spr->hitag].cstat = cstat2;

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
static void func_80073E0C(s32 spritenum)
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
    cstat2 = gpSprite[spr->hitag].cstat;
    spr->cstat = cstat & ~0x101;
    gpSprite[spr->hitag].cstat &= ~0x101;

    getzRange(spr->x, spr->y, (spr->z - 2048), spr->sectnum,
              &ceilz, &ceilhit, &florz, &florhit, 64, 0x10001);

    spr->cstat = cstat;
    gpSprite[spr->hitag].cstat = cstat2;

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
static void func_800743C0(s32 spritenum)
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
    cstat2 = gpSprite[spr->hitag].cstat;
    spr->cstat = cstat & ~0x101;
    gpSprite[spr->hitag].cstat &= ~0x101;

    getzRange(spr->x, spr->y, (spr->z - 2048), spr->sectnum,
             &ceilz, &ceilhit, &florz, &florhit, 64, 0x10001);

    spr->cstat = cstat;
    gpSprite[spr->hitag].cstat = cstat2;

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
static void func_80074664(s32 spritenum)
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
                if (spr->unk18 > 10)
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
                    if (spr->unk18 > 60)
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
static void func_800749A8(s32 spritenum)
{
    s32 ceilz, ceilhit, florz, florhit;
    SpriteType *spr;
    s32 num;
    u16 cstat;

    spr = &gpSprite[spritenum];
    gpActor = &gActor[gActorSpriteMap[gPlayer[D_801B0820].unk4A]];

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
        gpActor->unk60++;
        if ((gpActor->unk60 & 3) == 3)
            func_8001DBA0((spr->x / 2), (spr->y / 2), (spr->z / 32), 18, 18, 10);

        if (gpActor->unk60 & 1)
            func_8005A4A4(spritenum, 0);

        deleteSprite(spritenum);
    }
}

/*80074C70*/
static void func_80074C70(s32 spritenum)
{
    s32 ceilz, ceilhit, florz, florhit;
    SpriteType *spr;
    s16 ang, num2;
    s32 ang2, num, i, point2;
    s16 cstat;

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
                        if (gpSprite[spritenum].hitag != num)
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
static void func_80075380(s32 spritenum)
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
            if (gpSprite[spritenum].hitag != num)
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
static void func_800756B0(s32 spritenum)
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
        if ((num >= 0) && (gpSprite[spritenum].hitag != num))
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
static void func_8007599C(s32 spritenum)
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
        if ((num >= 0) && (gpSprite[spritenum].hitag != num))
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
static void func_80075C88(s32 spritenum)
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
static void func_80075E28(s32 spritenum)
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
static void func_80076144(s32 spritenum)
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
static void func_80076364(s32 spritenum)
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
static void func_8007675C(s32 spritenum)
{
    s32 ceilz, ceilhit, florz, florhit;
    SpriteType *spr;
    s16 unk16;
    s32 i, num, unk1C;
    s32 ang, ang2;
    u16 cstat;

    spr = &gpSprite[spritenum];
    if (spr->unk16 < 0)
    {
        spr->unk16 = func_8004D304(spr, 512, 19);
        unk1C = 0;
    }

    if (spr->unk16 >= 0)
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
static void func_80076C14(s32 spritenum)
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
                    gpSprite[j].lotag = spritenum;
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
static void func_80077320(s32 spritenum)
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
static void func_80077608(s32 spritenum)
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
static s32 func_80077908(s32 spritenum)
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
static void func_80077AB0(s32 spritenum)
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
            if (gpSprite[spritenum].hitag != num)
                func_80047820(spritenum, num, 12);
        }
        deleteSprite(spritenum);
    }
}

/*80077C70*/
static void func_80077C70(s32 spritenum)
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

        if ((num >= 0) && (gpSprite[spritenum].hitag != num))
            func_80047820(spritenum, num, 69);

        func_8004BFDC(spritenum, 1, spr->z, 1);
        deleteSprite(spritenum);
    }
}

/*80077E80*/
static void func_80077E80(s32 spritenum)
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
            if (gpSprite[spritenum].hitag != num)
                func_80047820(spritenum, num, (krand() % 5) + 10);
        }
        else
            func_8004CB3C(num + 0xC000);

        deleteSprite(spritenum);
    }
}

/*800780AC*/
static void func_800780AC(s32 spritenum)
{
    s16 hitsect, hitwall, hitsprite;
    s32 hitx, hity, hitz;
    SpriteType *spr;
    Actor *actor;
    s32 num;

    spr = &gpSprite[spritenum];
    actor = &gActor[gActorSpriteMap[spr->hitag]];

    hitScan(spr->x,
            spr->y,
            spr->z,
            spr->sectnum,
            (actor->unk44 - spr->x) / 4,
            (actor->unk48 - spr->y) / 4,
            (actor->unk4C - spr->z) / 4,
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
static void func_80078300(s32 spritenum)
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
            if (gpSprite[spritenum].hitag != num)
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
static void func_80078564(s32 spritenum)
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
            if (gpSprite[spritenum].hitag != num)
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
static void func_80078924(s32 spritenum)
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
static void func_80078B70(s32 spritenum)
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
            if (gpSprite[spritenum].hitag != num)
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
static void func_80078DA8(s32 spritenum)
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
            if (gpSprite[spritenum].hitag != num)
                func_80047820(spritenum, num, 8);
        }
        else
            func_8004CB3C(num + 0xC000);

        func_8004BD24(spritenum);
    }
}

/*80078F84*/
static void func_80078F84(s32 spritenum)
{
    s32 ceilz, ceilhit, florz, florhit;
    SpriteType *spr;
    s32 num, ang;
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
static void func_800791A8(s32 spritenum)
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
    cstat2 = gpSprite[spr->hitag].cstat;
    spr->cstat = spr->cstat & ~0x101;
    gpSprite[spr->hitag].cstat &= ~0x101;

    getzRange(spr->x,
              spr->y,
              (spr->z - 2048),
              spr->sectnum,
              &ceilz, &ceilhit, &florz, &florhit, 64, 0x10001);

    spr->cstat = cstat;
    gpSprite[spr->hitag].cstat = cstat2;
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
static void func_8007939C(s32 spritenum)
{
    SpriteType *spr;
    s32 x, y;

    spr = &gpSprite[spritenum];
    if (spr->unk22 != 0)
    {
        x = gActor[gActorSpriteMap[spritenum]].unk4C;
        y = gActor[gActorSpriteMap[spritenum]].unk50;
    }
    else
    {
        x = gActor[gActorSpriteMap[spritenum]].unk44;
        y = gActor[gActorSpriteMap[spritenum]].unk48;
    }

    gpSprite[spritenum].x = x;
    gpSprite[spritenum].y = y;
    gpSprite[spritenum].unk22 ^= 1;

    if (gpSprite[spritenum].unk25 == 0)
    {
        func_80087174(spritenum, gActor[gActorSpriteMap[spritenum]].unk44,
                      gActor[gActorSpriteMap[spritenum]].unk48,
                      gpSprite[spritenum].z,
                      gActor[gActorSpriteMap[spritenum]].unk4C,
                      gActor[gActorSpriteMap[spritenum]].unk50,
                      gpSprite[spritenum].z, 32, 8);
    }
    else
        func_800587B8(spritenum, spr->unk18, 0, 0, 0, 8, 16);
}

/*80079560*/
void func_80079560(void)
{
    _6D9E0UnkFuncPointer *ptr;
    s16 i, nexti;
    s32 j;

    i = gHeadSpriteStat[4];
    while (i >= 0)
    {
        nexti = gNextSpriteStat[i];
        D_80118248 = &gpSprite[i];
        if (D_80118248->lotag > 0)
        {
            if (D_80118248->lotag < 100)
            {
                if (D_80118248->lotag < ARRAY_COUNT(D_800DF5A0))
                {
                    ptr = D_800DF5A0;
                    if (ptr[D_80118248->lotag] != NULL)
                        ptr[D_80118248->lotag](i);
                }
            }
            else
            {
                j = D_80118248->lotag - 100;
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
