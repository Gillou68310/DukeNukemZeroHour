#include "common.h"
#include "code0/main.h"
#include "code0/pragmas.h"
#include "code0/audio.h"
#include "code0/1E7A0.h"
#include "code0/2ABE0.h"
#include "code0/37090.h"
#include "code0/41940.h"
#include "code0/59D40.h"
#include "code0/6ACA0.h"
#include "code0/8E670.h"
#include "code0/8EFE0.h"
#include "code0/A06F0.h"
#include "code0/code0.h"
#include "code1/code1.h"
#include "code1/EB300.h"

/*.data*/
EXTERN_DATA STATIC s32 D_800DF2E4;
EXTERN_DATA STATIC s32 D_800DF2E8;

/*.text*/
static void func_8005B014(s32 spritenum);

/*80059140*/
void func_80059140(s32 spritenum, s32 arg1)
{
    func_8006A0A0(spritenum);
}

/*80059164*/
void func_80059164(s32 spritenum, s32 arg1)
{
    s32 ang;
    ang = getAngle((gpSprite[D_80118248->unk16].x - D_80118248->x),
                   (gpSprite[D_80118248->unk16].y - D_80118248->y));

    func_800461E8(spritenum, arg1, ang);
}

/*800591EC*/
void func_800591EC(s32 spritenum, s32 arg1)
{
    s16 i, nexti;

    i = gHeadSpriteStat[7];
    while (i >= 0)
    {
        nexti = gNextSpriteStat[i];
        if ((gpSprite[i].unk20 == gpSprite[spritenum].unk1E) && (gpSprite[i].shade == 1))
        {
            gpSprite[spritenum].unk16 = i;
            break;
        }
        i = nexti;
    }
}

/*80059284*/
void func_80059284(s32 spritenum, s32 arg1)
{
    s32 i, j, spritenum_;

    spritenum_ = func_80045E40(spritenum, arg1);
    j = 0;
    i = gHeadSpriteStat[1];

    while (i >= 0)
    {
        if (gpSprite[i].picnum == spritenum_)
            j++;

        i = gNextSpriteStat[i];
    }
    func_800461E8(spritenum, arg1, j);
}

/*8005931C*/
void func_8005931C(s32 spritenum, s32 arg1)
{
    func_800461E8(spritenum, arg1, D_80137DE0->unk86);
}

/*80059348*/
void func_80059348(s32 spritenum, s32 arg1)
{
    s32 unk4A;
    s16 spritenum1;
    s32 spritenum2;

    spritenum1 = insertSprite(D_80118248->sectnum, 4);
    if (spritenum1 != -1)
    {
        gpSprite[spritenum1].unk1E = 2;
        unk4A = D_80117ED8[0].unk4A;
        spritenum2 = func_80045E40(spritenum, arg1);
        if (spritenum2 == 4)
        {
            krand();
        }
        if ((spritenum2 == 6) || (spritenum2 == 2))
        {
            gpSprite[spritenum1].unk1E = 9;
        }
        gpSprite[spritenum1].unk20 = spritenum;
        func_800494DC(unk4A, 8, spritenum1, 0);
        deleteSprite(spritenum1);
    }
}

/*80059460*/
void func_80059460(s32 spritenum, s32 arg1)
{
    s32 spritenum_;

    spritenum_ = D_80117ED8[0].unk4A;
    func_80045E40(spritenum, arg1);
    gpSprite[spritenum].unk1E = 2;
    gpSprite[spritenum].unk16 = 0;
    func_800494DC(spritenum_, 17, spritenum, 0);
    gpSprite[spritenum_].z -= 0x2200;
    func_80057540(&gpSprite[spritenum_], 1500, 1, 0);
    gpSprite[spritenum_].z += 0x2200;
}

/*8005952C*/
void func_8005952C(s32 spritenum, s32 arg1)
{
    func_8004BFDC(spritenum, 3, gpSprite[spritenum].z, 0);
    func_8004AB6C(spritenum, 0x3E8, 0x19, 0x32, 0x4B, 0x64, 0);
}

INCLUDE_ASM("nonmatchings/src/code0/59D40", func_800595A8);

/*80059800*/
void func_80059800(s32 spritenum, s32 arg1)
{
    s32 unk1E;
    s32 i, j, d1, d2, nexti;

    i = gHeadSpriteStat[7];
    j = -1;
    D_800DEE9C = 1;
    d1 = 300000;

    if (D_80137DE0->unk4 & 64)
    {
        unk1E = gpSprite[D_80118248->unk16].unk1E;
    }
    else
    {
        unk1E = D_80118248->unk1E;
    }

    while (i >= 0)
    {
        nexti = gNextSpriteStat[i];
        if ((gpSprite[i].shade == 0) && (gpSprite[i].unk20 == unk1E))
        {
            d2 = ldist(&gpSprite[i], D_80118248);
            if (d2 < d1)
            {
                d1 = d2;
                j = i;
            }
        }
        i = nexti;
    }

    D_80137DE0->unk5C = unk1E;
    D_80137DE0->unk60 = gpSprite[j].unk1E;
}

/*8005996C*/
void func_8005996C(s32 spritenum, s32 arg1)
{
    func_800461E8(spritenum, arg1, dist(D_80118248, &gpSprite[D_80137DE0->unk54]));
}

/*800599E4*/
void func_800599E4(s32 spritenum, s32 arg1)
{
    u32 ang;

    ang = getAngle((D_80117ED8[0].xpos - D_80118248->x),
                   (D_80117ED8[0].ypos - D_80118248->y));

    ang = func_80040E90(D_80118248->ang, ang);
    func_800461E8(spritenum, arg1, 0);
    if ((ang - 301) < 449)
    {
        func_800461E8(spritenum, arg1, 1);
    }
    if ((ang + 749) < 449)
    {
        func_800461E8(spritenum, arg1, 2);
    }
    func_800461E8(spritenum, arg1, 1);
}

/*80059AC0*/
void func_80059AC0(s32 spritenum, s32 arg1)
{
    SpriteType *spr;
    spr = &gpSprite[D_80137DE0->unk54];
    func_800461E8(spritenum, arg1, spr->unk24);
}

/*80059B10*/
void func_80059B10(s32 spritenum, s32 arg1)
{
    s32 z, z1, z2, z3, z4;

    z = func_80045E40(spritenum, arg1);
    z1 = D_80117ED8[0].zpos >> 8;
    z1 += (D_80117ED8[0].unk40 >> 8);
    z2 = (D_80118248[0].z >> 8);
    z2 += z;
    z4 = z3 = z2 - z1;

    if (z3 <= 0)
    {
        z4 = z1 - z2;
    }

    if (z4 < 32)
    {
        func_800461E8(spritenum, arg1, 0);
    }
    else if (z3 < 0)
    {
        func_800461E8(spritenum, arg1, 2);
    }
    else
    {
        func_800461E8(spritenum, arg1, 1);
    }
}

/*80059BBC*/
void func_80059BBC(s32 spritenum, s32 arg1)
{
    s32 z1, z2, z3, z4;

    z1 = (D_80117ED8[0].zpos >> 8);
    z2 = D_80118248[0].z >> 8;
    z1 += (D_80117ED8[0].unk40 >> 8);
    z1 -= 0x48;
    z3 = z4 = z2 - z1;

    if (z3 <= 0)
    {
        z4 = z1 - z2;
    }

    if (z4 < 16)
    {
        func_800461E8(spritenum, arg1, 0);
    }
    else if (z3 < 0)
    {
        func_800461E8(spritenum, arg1, 2);
    }
    else
    {
        func_800461E8(spritenum, arg1, 1);
    }
}

/*80059C48*/
void func_80059C48(s32 spritenum, s32 arg1)
{
    f32 f1, f2, f3;
    s32 z;

    z = (gpSprite[spritenum].z - 0x1200);
    f1 = (D_80117ED8[0].zpos - z) / 16;
    f2 = func_80040D40(D_80117ED8[0].xpos, D_80117ED8[0].ypos, gpSprite[spritenum].x, gpSprite[spritenum].y);
    f3 = func_80029FE0(f1, f2) * 325.9493234521802;

    if (D_8013B2D0[spritenum].unk2 != (s16)f3)
    {
        func_800461E8(spritenum, arg1, 0);
        if (D_8013B2D0[spritenum].unk2 < f3)
        {
            D_8013B2D0[spritenum].unk2 += 8;
            if (f3 < D_8013B2D0[spritenum].unk2)
                D_8013B2D0[spritenum].unk2 = f3;
        }
        else
        {
            D_8013B2D0[spritenum].unk2 -= 8;
            if (D_8013B2D0[spritenum].unk2 < f3)
                D_8013B2D0[spritenum].unk2 = f3;
        }
    }
    else
    {
        func_800461E8(spritenum, arg1, 1);
    }
}

/*80059E08*/
void func_80059E08(s32 spritenum, s32 arg1)
{
    if (D_80137DE0->unk44 == 0)
    {
        func_8001DBA0(D_80118248->x/2, D_80118248->y/2, D_80118248->z/32, 0x16, 0x16, 3);
        D_80137DE0->unk44 = 12;
    }
    else
    {
        D_80137DE0->unk44--;
    }
    gpSprite[spritenum].unk1E = 9;
    func_80059EEC(spritenum, 1, 0x800);
}

INCLUDE_ASM("nonmatchings/src/code0/59D40", func_80059EEC);

/*8005A240*/
s32 func_8005A240(s32 spritenum)
{
    s32 unk84;
    unk84 = D_8019B940[D_80106D50[spritenum]].unk84;

    switch (unk84)
    {
    case 2:
    case 3:
    case 4:
    case 5:
        return 1;
    case 6:
    case 7:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
        return 0;
    case 1:
    case 9:
    case 17:
        return 2;
    case 12:
    case 13:
    case 14:
        return 3;
    case 19:
    case 20:
        return 4;
    default:
        return -1;
    }
}

/*8005A2C8*/
void func_8005A2C8(s32 spritenum, s32 arg1)
{
    s32 ang, wallnum;

    wallnum = D_80137DE0->unk2E;
    if ((wallnum - 49152) < 0)
    {
        wallnum &= 0x1FFF;
        ang = getAngle((gpWall[gpWall[wallnum].point2].x - gpWall[wallnum].x),
                       (gpWall[gpWall[wallnum].point2].y - gpWall[wallnum].y));

        if ((func_80040E90(D_80117ED8[0].unk38, ang)) > 0)
        {
            func_800461E8(spritenum, arg1, (ang - 0x400) & 0x7FF);
        }
        else
        {
            func_800461E8(spritenum, arg1, ang & 0x7FF);
        }
    }
}

#ifdef NON_MATCHING
void func_8005A3AC(s32 spritenum, s32 arg1)
{
    s32 ang;
    u16 wallnum;

    wallnum = D_80137DE0->unk2E;
    if ((wallnum - 49152) < 0)
    {
        wallnum &= 0x1FFF;
        ang = ((getAngle(gpWall[gpWall[wallnum].point2].x - gpWall[wallnum].x,
            gpWall[gpWall[wallnum].point2].y - gpWall[wallnum].y) * 2) - gpSprite[spritenum].ang) & 0x7FF;
    }
    else
    {
        ang = krand() & 0x3FF;
        ang += D_80118248->ang;
        ang &= 0x7FF;
    }
    func_800461E8(spritenum, arg1, ang);
}
#else
/*8005A3AC*/
INCLUDE_ASM("nonmatchings/src/code0/59D40", func_8005A3AC);
#endif

INCLUDE_ASM("nonmatchings/src/code0/59D40", func_8005A4A4);

/*8005A800*/
void func_8005A800(s32 spritenum, s32 arg1)
{
    code0unkStruct7 *ptr;

    ptr = &D_80197E40[D_80106D50[spritenum]];
    if (ptr->unkE == 0)
        func_800461E8(spritenum, arg1, ptr->unk0);
    else
        func_800461E8(spritenum, arg1, -1);
}

/*8005A850*/
void func_8005A850(s32 spritenum, s32 arg1)
{
    func_800461E8(spritenum, arg1, gpSprite[spritenum].unk1E);
}

/*8005A894*/
void func_8005A894(s32 spritenum, s32 arg1)
{
    D_80118248->unk16 = D_80118248->sectnum;
}

/*8005A8A8*/
void func_8005A8A8(s32 spritenum, s32 arg1)
{
    s32 var1, var2, ang1, ang2;

    var2 = func_80045E40(spritenum, arg1);
    var1 = D_80137DE0->unk28;
    ang1 = D_80118248->ang;

    if (((D_80137DE0->unk0 & 0x1800) != 0) && (var1 != -1))
    {
        ang2 = getAngle((gpSprite[D_80137DE0->unk28].x - D_80118248->x),
                        (gpSprite[D_80137DE0->unk28].y - D_80118248->y));
    }
    else
    {
        ang2 = getAngle((D_80117ED8[D_801A2628].xpos - D_80118248->x),
                        (D_80117ED8[D_801A2628].ypos - D_80118248->y));
    }

    var1 = func_80040E90(ang1, ang2);
    var1 = klabs(var1);

    if (var1 < var2)
    {
        func_800461E8(spritenum, arg1, 1);
    }
    else
    {
        func_800461E8(spritenum, arg1, 0);
    }
}

/*8005A9EC*/
void func_8005A9EC(s32 spritenum, s32 arg1)
{
    if (D_801CA14C[gMapNum].unk0 == 2)
        D_80137DE0->unk99 = 0x1D;
    else
        D_80137DE0->unk99 = 0x21;
}

/*8005AA30*/
void func_8005AA30(s32 spritenum, s32 arg1)
{
    s32 spritenum_;
    s32 x, y;

    x = (gpSinTable[(D_80118248->ang + 512) & 0x7FF] * 145) >> 12;
    y = (gpSinTable[D_80118248->ang & 0x7FF] * 145) >> 12;
    x += D_80118248->x;
    y += D_80118248->y;

    if (D_8012FD88 & 1)
    {
        spritenum_ = func_8008E3E0(x, y, (D_80118248->z - 0x3000), D_80118248->sectnum, 32, 22);
        if (spritenum_ >= 0)
        {
            gpSprite[spritenum_].ang = D_80118248->ang;
        }
    }

    if ((D_8012FD88 & 0xF) == 0xF)
    {
        x = (gpSinTable[(D_80118248->ang + 512) & 0x7FF] * 15) >> 7;
        y = (gpSinTable[D_80118248->ang & 0x7FF] * 15) >> 7;
        x += D_80118248->x;
        y += D_80118248->y;

        func_8001DCD0(x/2, y/2, D_80118248->z/32, 1);

        if (func_80040D40(D_80117ED8[0].xpos, D_80117ED8[0].ypos, x, y) < 0x4B0)
        {
            func_80059348(spritenum, 1);
        }
    }
}

/*8005AC28*/
void func_8005AC28(s32 spritenum, s32 arg1)
{
    s32 unk48;
    f32 offset;

    D_80137DE0->unk44 = getAngle((gpSprite[D_80137DE0->unk60].x - D_80118248->x),
                                 (gpSprite[D_80137DE0->unk60].y - D_80118248->y));
    unk48 = D_80137DE0->unk48;
    unk48 = unk48 / 12;
    if (unk48 >= 0x8D)
    {
        unk48 = 0x8C;
    }
    offset = (unk48 / 24);
    if (D_80137DE0->unk6C != 0)
    {
        MusHandleSetFreqOffset(D_80137DE0->unk6C, offset);
    }
}

/*8005AD18*/
void func_8005AD18(s32 spritenum, s32 arg1)
{
    s32 i, j, d1, d2, nexti;

    i = gHeadSpriteStat[8];
    j = -1;
    d1 = 300000;

    while (i >= 0)
    {
        nexti = gNextSpriteStat[i];
        if (gpSprite[i].shade == D_80118248->unk1E)
        {
            d2 = ldist(&gpSprite[i], D_80118248);
            if (d2 < d1)
            {
                d1 = d2;
                j = i;
            }
        }
        i = nexti;
    }

    D_80137DE0->unk60 = j;
    D_80137DE0->unk54 = gpSprite[j].unk1E;
}

/*8005AE18*/
void func_8005AE18(s32 spritenum, s32 arg1)
{
    s32 unk20;
    s32 i, j, d1, d2, nexti;

    unk20 = gpSprite[D_80137DE0->unk60].unk20;
    j = D_80137DE0->unk60;
    d1 = 300000;
    i = gHeadSpriteStat[8];

    while (i >= 0)
    {
        nexti = gNextSpriteStat[i];
        if (gpSprite[i].shade == D_80118248->unk1E)
        {
            if ((unk20 < gpSprite[i].unk20) && (gpSprite[i].unk20 < (unk20 + 11)))
            {
                d2 = ldist(&gpSprite[i], &gpSprite[spritenum]);
                if (d2 < d1)
                {
                    d1 = d2;
                    j = i;
                }
            }
        }
        i = nexti;
    }

    D_80137DE0->unk54 = gpSprite[j].unk1E;
    D_80137DE0->unk60 = j;
}

/*8005AF90*/
void func_8005AF90(s32 spritenum, s32 arg1)
{
}

/*8005AF98*/
void func_8005AF98(s32 spritenum, s32 arg1)
{
    func_8005B014(spritenum);
    func_800461E8(spritenum, arg1, ldist(D_80118248, &gpSprite[D_80137DE0->unk60]));
}

/*8005B014*/
static void func_8005B014(s32 spritenum)
{
    s32 floorheinum;
    s32 x, y;
    s32 floorz1, floorz2;
    s32 value;

    if (((gpSector[D_80118248->sectnum].floorstat & 2) != 0) && (gpSector[D_80118248->sectnum].floorheinum != 0))
    {
        floorheinum = klabs(gpSector[D_80118248->sectnum].floorheinum);
        value = floorheinum / 16;

        x = D_80118248->x;
        y = D_80118248->y;
        x += ((gpSinTable[(D_80118248->ang + 512) & 0x7FF] * 15) >> 14);
        y += ((gpSinTable[D_80118248->ang & 0x7FF] * 15) >> 14);
        floorz1 = getFlorzOfSlope(D_80118248->sectnum, D_80118248->x, D_80118248->y);
        floorz2 = getFlorzOfSlope(D_80118248->sectnum, x, y);
        if (floorz2 < floorz1)
        {
            value = -value;
        }
        D_8013B2D0[spritenum].unk2 = value;
    }
    else
    {
        D_8013B2D0[spritenum].unk2 = 0;
    }
}

/*8005B164*/
void func_8005B164(s32 spritenum, s32 arg1)
{
    func_800461E8(spritenum, arg1, gpSprite[D_80137DE0->unk60].unk24);
}

/*8005B1B4*/
void func_8005B1B4(s32 spritenum, s32 arg1)
{
    gpSprite[D_80137DE0->unk60].unk24 = 1;
}

/*8005B1EC*/
void func_8005B1EC(s16 spritenum, s32 arg1)
{
    s32 i;
    s16 spritenum_;

    for (i = 2223; i < 2227; i++)
    {
        spritenum_ = func_80058934(D_80118248->x, D_80118248->y, D_80118248->z, D_80118248->sectnum, 0x3C);
        gpSprite[spritenum_].picnum = i;
        gpSprite[spritenum_].cstat = 0x1101;
        gpSprite[spritenum_].unk16 = spritenum;
        gpSprite[spritenum_].xrepeat = 0x40;
        gpSprite[spritenum_].yrepeat = 0x40;
        gpSprite[spritenum_].shade = 0;
    }
    D_80137DE0->unk9F |= 4;
}

/*8005B2DC*/
void func_8005B2DC(s32 spritenum, s32 arg1)
{
    s16 i, nexti;

    if (D_80137DE0->unk9F & 4)
    {
        i = gHeadSpriteStat[60];

        while (i >= 0)
        {
            nexti = gNextSpriteStat[i];
            if (gpSprite[i].unk16 == spritenum)
            {
                deleteSprite(i);
            }
            i = nexti;
        }
    }
}

/*8005B388*/
void func_8005B388(s32 spritenum, s32 arg1)
{
    if (D_80118248->unk16 != -1)
    {
        func_8004BD24(D_80118248->unk16);
    }
}

/*8005B3C0*/
void func_8005B3C0(s32 spritenum, s32 arg1)
{
    s32 spritenum_;

    spritenum_ = func_80058934(D_80118248->x, D_80118248->y, D_80118248->z, D_80118248->sectnum, 0xFA);
    gpSprite[spritenum_].picnum = 5550;
    gpSprite[spritenum_].cstat = 0x880;
    D_80118248->unk22 = spritenum_;
    gpSprite[spritenum_].unk16 = D_80118248->picnum;
    gpSprite[spritenum_].xrepeat = 0x40;
    gpSprite[spritenum_].yrepeat = 0x40;
    gpSprite[spritenum_].shade = 0x10;
    gpSprite[spritenum_].unk1A = 0;
    D_8013B2D0[spritenum_].unk6 = 0;
    spritenum_ = func_80058934(D_80118248->x, D_80118248->y, D_80118248->z, D_80118248->sectnum, 0xFA);
    gpSprite[spritenum_].picnum = 5550;
    gpSprite[spritenum_].cstat = 0x880;
    D_80118248->unk16 = spritenum_;
    gpSprite[spritenum_].unk16 = D_80118248->picnum;
    gpSprite[spritenum_].xrepeat = 0x40;
    gpSprite[spritenum_].yrepeat = 0x40;
    gpSprite[spritenum_].shade = 2;
    gpSprite[spritenum_].unk1A = 1;
    D_8013B2D0[spritenum_].unk6 = 0xFF;
}

/*8005B564*/
void func_8005B564(s32 spritenum, s32 arg1)
{
    deleteSprite(gpSprite[spritenum].unk16);
    deleteSprite(gpSprite[spritenum].unk22);
}

/*8005B5C8*/
void func_8005B5C8(s32 spritenum, s32 arg1)
{
    s32 spritenum_;
    s16 unk6;

    spritenum_ = gpSprite[spritenum].unk22;
    if (gpSprite[spritenum_].unk1A == 0)
    {
        unk6 = D_8013B2D0[spritenum_].unk6 + 0x10;
        D_8013B2D0[spritenum_].unk6 = unk6;
        if (unk6 >= 0x100)
        {
            D_8013B2D0[spritenum_].unk6 = 0xFF;
            gpSprite[spritenum_].unk1A = 1;
        }
    }
    else if (gpSprite[spritenum_].unk1A == 1)
    {
        unk6 = D_8013B2D0[spritenum_].unk6 - 0x10;
        D_8013B2D0[spritenum_].unk6 = unk6;
        if (unk6 < 0)
        {
            D_8013B2D0[spritenum_].unk6 = 0;
            gpSprite[spritenum_].unk1A = 0;
        }
    }
    gpSprite[spritenum_].x = D_80118248->x;
    gpSprite[spritenum_].y = D_80118248->y;
    gpSprite[spritenum_].z = D_80118248->z - 0x4000;
    changeSpriteSect(spritenum_, D_80118248->sectnum);

    spritenum_ = gpSprite[spritenum].unk16;
    if (gpSprite[spritenum_].unk1A == 0)
    {
        unk6 = D_8013B2D0[spritenum_].unk6 + 0x10;
        D_8013B2D0[spritenum_].unk6 = unk6;
        if (unk6 >= 0x100)
        {
            D_8013B2D0[spritenum_].unk6 = 0xFF;
            gpSprite[spritenum_].unk1A = 1;
        }
    }
    else if (gpSprite[spritenum_].unk1A == 1)
    {
        unk6 = D_8013B2D0[spritenum_].unk6 - 0x10;
        D_8013B2D0[spritenum_].unk6 = unk6;
        if (unk6 < 0)
        {
            D_8013B2D0[spritenum_].unk6 = 0;
            gpSprite[spritenum_].unk1A = 0;
        }
    }
    gpSprite[spritenum_].x = D_80118248->x;
    gpSprite[spritenum_].y = D_80118248->y;
    gpSprite[spritenum_].z = D_80118248->z - 0x4000;
    changeSpriteSect(spritenum_, D_80118248->sectnum);
}

/*8005B82C*/
void func_8005B82C(s32 spritenum, s32 arg1)
{
    if (D_80117ED8[0].unk36 >= 0x1001)
    {
        if (((D_80117ED8[0].unk36 - 0x1000) == spritenum) && (D_80117ED8[0].unk59 != 0))
        {
            func_800461E8(spritenum, arg1, 1);
            D_80117ED8[0].unk50 = spritenum;
            D_8011BC48 = spritenum;
        }
    }
    else
    {
        func_800461E8(spritenum, arg1, 0);
    }
}

/*8005B8A8*/
void func_8005B8A8(s32 spritenum, s32 arg1)
{
    if (D_80117ED8[0].unk50 == D_8011BC48)
    {
        func_800461E8(spritenum, arg1, 0);
    }
    else
    {
        func_800461E8(spritenum, arg1, -1);
        D_8011BC48 = -1;
    }
}

/*8005B8F8*/
void func_8005B8F8(s32 spritenum, s32 arg1)
{
    s32 result;

    if (D_80117ED8[0].unk50 == spritenum)
    {
        result = func_80045E40(D_80117ED8[0].unk50, arg1);
        result = func_80040E90(D_80118248->ang, result) >> 3;
        D_80117ED8[0].unk38 += result;
    }
}

/*8005B958*/
void func_8005B958(s16 spritenum, s32 arg1)
{
    s32 i;

    i = gHeadSpriteStat[1];

    while (i >= 0)
    {
        if (gpSprite[i].sectnum == D_80118248->sectnum)
        {
            if (gpSprite[i].picnum == 2222)
            {
                if (ldist(&gpSprite[i], D_80118248) < 500)
                {
                    D_80118248->unk16 = i;
                    gpSprite[i].unk16 = spritenum;
                    break;
                }
            }
        }
        i = gNextSpriteStat[i];
    }
}

/*8005BA3C*/
void func_8005BA3C(s16 spritenum, s32 arg1)
{
    s32 spritenum_;

    spritenum_ = D_80118248->unk16;
    D_80118248->x = gpSprite[spritenum_].x;
    D_80118248->y = gpSprite[spritenum_].y;
    D_80118248->z = gpSprite[spritenum_].z - 0x1000;
    changeSpriteSect(spritenum, gpSprite[spritenum_].sectnum);
}

/*8005BAAC*/
void func_8005BAAC(s16 spritenum, s32 arg1)
{
    s32 ang, z;

    if (gpSector[D_80118248->sectnum].unk18 == 3)
    {
        z = func_80036490(D_80118248->sectnum);
        if ((z < D_80118248->z) && (D_8012FD88 & 1))
        {
            ang = D_80118248->ang;
            ang -= ((krand() & 0x7F) - 0x80);
            func_80045400(D_80118248->x, D_80118248->y, z - 0x800, D_80118248->sectnum, 0x258, ang, 0x1C, 0);
        }
    }
}

/*8005BB88*/
void func_8005BB88(s32 spritenum, s32 arg1)
{
    f32 f1, f2, f3;
    s32 z;

    z = (gpSprite[spritenum].z - 0x2000);
    f1 = (D_80117ED8[0].zpos - z) / 16;
    f2 = func_80040D40(D_80117ED8[0].xpos, D_80117ED8[0].ypos, gpSprite[spritenum].x, gpSprite[spritenum].y);
    f3 = func_80029FE0(f1, f2) * 325.9493234521802;

    if (D_80137DE0->unk7C != (s16)f3)
    {
        func_800461E8(spritenum, arg1, 0);
        if (D_80137DE0->unk7C < f3)
        {
            D_80137DE0->unk7C += 8;
            if (f3 < D_80137DE0->unk7C)
                D_80137DE0->unk7C = f3;
        }
        else
        {
            D_80137DE0->unk7C -= 8;
            if (D_80137DE0->unk7C < f3)
                D_80137DE0->unk7C = f3;
        }
    }
    else
    {
        func_800461E8(spritenum, arg1, 1);
    }
}

#ifdef NON_MATCHING
void func_8005BD28(s32 spritenum, s32 arg1)
{
    s32 x1, x2, y1, y2, z, z1, z2;
    f32 f1, f2, f3;

    if ((D_80137DE0->unk0 & 0x1800) && (D_80137DE0->unk28 != -1))
    {
        z = (gpSprite[D_80137DE0->unk28].z - D_80118248->z) / 16;
        x1 = gpSprite[D_80137DE0->unk28].x;
        y1 = gpSprite[D_80137DE0->unk28].y;
        x2 = D_80118248->x;
        y2 = D_80118248->y;
        f1 = z;
    }
    else
    {
        if ((D_801CA14C[gMapNum].unk0 == 2) && (D_80137DE0->unk4 & 0x20))
        {
            z1 = D_80117ED8[0].zpos;
            z2 = gpSprite[spritenum].z;
            z2 -= 0x4600;
        }
        else
        {
            z1 = D_80117ED8[0].zpos;
            z2 = gpSprite[spritenum].z;
            z2 -= 0x4000;
        }
        f1 = (z1 - z2) / 16;
        x1 = D_80117ED8[0].xpos;
        y1 = D_80117ED8[0].ypos;
        x2 = gpSprite[spritenum].x;
        y2 = gpSprite[spritenum].y;
    }
    f2 = func_80040D40(x1, y1, x2, y2);
    f3 = func_80029FE0(f1, f2) * 325.9493234521802;

    if (f3 >= 480.0f)
    {
        f3 = 480.0f;
    }
    else if (f3 <= -480.0f)
    {
        f3 = -480.0f;
    }

    if (D_80137DE0->unk7C != (s16)f3)
    {
        if (D_80137DE0->unk7C < f3)
        {
            D_80137DE0->unk7C += 8;
            if (f3 < D_80137DE0->unk7C)
                D_80137DE0->unk7C = f3;
        }
        else
        {
            D_80137DE0->unk7C -= 8;
            if (D_80137DE0->unk7C < f3)
                D_80137DE0->unk7C = f3;
        }
    }
}
#else
/*8005BD28*/
INCLUDE_ASM("nonmatchings/src/code0/59D40", func_8005BD28);
#endif

INCLUDE_ASM("nonmatchings/src/code0/59D40", func_8005BFD8);

/*8005C19C*/
void func_8005C19C(s32 spritenum, s32 arg1)
{
    if (D_80137DE0->unk7C != 0)
    {
        if (D_80137DE0->unk7C < 0)
        {
            D_80137DE0->unk7C += 8;
            if (D_80137DE0->unk7C >= 0)
                D_80137DE0->unk7C = 0;
        }
        else
        {
            D_80137DE0->unk7C -= 8;
            if (D_80137DE0->unk7C <= 0)
                D_80137DE0->unk7C = 0;
        }
    }
}

/*8005C1F4*/
void func_8005C1F4(s32 spritenum, s32 arg1)
{
    D_80118248->unk1E = 0xC;
    func_8004BFDC(spritenum, 0xB, gpSprite[spritenum].z, 1);
}

/*8005C24C*/
void func_8005C24C(s32 spritenum, s32 arg1)
{
    s16 spritenum_;

    D_80118248->unk1E = 0xC;
    func_8004BFDC(spritenum, 9, gpSprite[spritenum].z, 0);
    func_8004BFDC(spritenum, 4, gpSprite[spritenum].z, 1);
    D_80118248->picnum = 2251;
    spritenum_ = func_8008E3E0(D_80118248->x, D_80118248->y, D_80118248->z - 0x1800, D_80118248->sectnum, 8, 0);
    if (spritenum_ >= 0)
    {
        gpSprite[spritenum_].unk18 = 0;
        gpSprite[spritenum_].unk24 = 0x1E;
        gpSprite[spritenum_].shade = 0x4C;
        gpSprite[spritenum_].unk20 = 1;
        gpSprite[spritenum_].unk1E = 6;
    }
}

/*8005C374*/
void func_8005C374(s32 spritenum, s32 arg1)
{
    s32 r1, r2, r3, r4;
    s32 spritenum_;
    s32 i;

    r1 = (krand() & 0x7F) - 0x3F;
    r2 = (krand() & 0x7F) - 0x3F;
    r3 = (krand() & 0x1F) + 0x1F;
    r4 = krand() & 0x7FF;

    for (i = 0; i < 3; i++)
    {
        spritenum_ = func_80045400(D_80118248->x + r1,
                                  D_80118248->y + r2,
                                  D_80118248->z - (r3 << 8),
                                  D_80118248->sectnum, 0x50, r4, 0xF, 1);

        if (spritenum_ >= 0)
        {
            gpSprite[spritenum_].unk22 -= (krand() & 0x3FF);
            gpSprite[spritenum_].unk18 = krand() & 0x7F;
        }
    }
}

/*8005C4B4*/
void func_8005C4B4(s32 spritenum, s32 arg1)
{
    func_800461E8(spritenum, arg1, gpSprite[gpSprite[spritenum].unk16].shade);
}

/*8005C514*/
void func_8005C514(s32 spritenum, s32 arg1)
{
    D_80137DE0->unk24 = 0;
    D_80137DE0->unk1C = 0;
    D_80137DE0->unk4 &= ~0x4008;
}

/*8005C538*/
void func_8005C538(s32 spritenum, s32 arg1)
{
    D_80137DE0->unk20 = 0;
}

/*8005C548*/
void func_8005C548(s32 spritenum, s32 arg1)
{
    func_800461E8(spritenum, arg1, D_80117ED8[0].unk54);
}

/*8005C570*/
void func_8005C570(s32 spritenum, s32 arg1)
{
    D_80137DE0->unk18 = 0;
}

/*8005C580*/
void func_8005C580(s32 spritenum, s32 arg1)
{
    D_80137DE0->unk1C = 0;
}

/*8005C590*/
void func_8005C590(s32 spritenum, s32 arg1)
{
    D_80118248->unk1E = 0xC;
    if (func_80045E40(spritenum, arg1) == 0)
    {
        func_8004BFDC(spritenum, 4, gpSprite[spritenum].z, 1);
    }
    else
    {
        func_8004BFDC(spritenum, 5, gpSprite[spritenum].z, 1);
        func_8005C1F4(spritenum, 0);
    }
}

/*8005C644(*/
void func_8005C644(s32 spritenum, s32 arg1)
{
    s32 spritenum_;

    D_80118248->picnum = 1712;
    changeSpriteStat(spritenum, 0);
    spritenum_ = func_8008E3E0(D_80118248->x, D_80118248->y, D_80118248->z, D_80118248->sectnum, 8, 0);
    if (spritenum_ >= 0)
    {
        gpSprite[spritenum_].unk18 = 0x1E;
        gpSprite[spritenum_].unk1E = 0;
        gpSprite[spritenum_].unk20 = 4;
    }
}

/*8005C6E4*/
void func_8005C6E4(s32 spritenum, s32 arg1)
{
    s32 i;
    code0UnkStruct3 *ptr;

    i = gHeadSpriteStat[1];

    while ((i >= 0) && (D_80106D50[i] != -1))
    {
        ptr = &D_8019B940[D_80106D50[i]];

        if ((ptr->unk4 & 0x40) &&
            (func_80040D94(gpSprite[spritenum].x, gpSprite[spritenum].y, gpSprite[spritenum].z >> 4,
                gpSprite[i].x, gpSprite[i].y, gpSprite[i].z >> 4) < 8000))
        {
            ptr->unk4 = ((ptr->unk4 | 0x2000) & ~0x40);
            if ((ptr->unk20) && (ptr->unk24 == 0) && ((ptr->unk0 & 0x4000) == 0))
            {
                ptr->unk24 = ptr->unkC;
                ptr->unkC = ptr->unk20;
                ptr->unk2A = ptr->unk30;
                ptr->unk2C = ptr->unk80;
                ptr->unk30 = 0;
                ptr->unk80 = 0;
            }
        }
        i = gNextSpriteStat[i];
    }
}

/*8005C85C*/
void func_8005C85C(s32 spritenum, s32 arg1)
{
    s32 wallnum;

    wallnum = D_80137DE0->unk2E;
    func_800461E8(spritenum, arg1, 0);
    if ((((u16)wallnum - 49152) > 0) && (gpSprite[(u16)wallnum - 49152].statnum == 0xA))
    {
        func_800461E8(spritenum, arg1, 1);
    }
    if (D_8010A918 < 1700)
    {
        func_800461E8(spritenum, arg1, 1);
    }
}

/*8005C920*/
void func_8005C920(s32 spritenum, s32 arg1)
{
    D_80118248->unk1A = 0x5A;
    D_80118248->unk18 = 2;
    D_80118248->unk1C = 0;
    changeSpriteStat(spritenum, 0x35);
}

/*8005C964*/
void func_8005C964(s32 spritenum, s32 arg1)
{
    s32 unk0 = gpSinTable[(D_8012FD88 * 11) & 0x7FF] >> 7;
    D_8013B2D0[spritenum].unk0 = unk0;
}

/*8005C9BC*/
void func_8005C9BC(s32 spritenum, s32 arg1)
{
    s16 unk0 = gpSinTable[(D_80137DE0->unk32 * 11) & 0x7FF] >> 6;
    D_8013B2D0[spritenum].unk0 = unk0;
}

/*8005CA18*/
void func_8005CA18(s32 spritenum, s32 arg1)
{
    D_80137DE0->unk14 = 0;
}

/*8005CA28*/
void func_8005CA28(s32 spritenum, s32 arg1)
{
    code0unkStruct7 *ptr;

    ptr = &D_80197E40[D_80106D50[spritenum]];
    ptr->unk2 = 0;
    ptr->unk0 = 0;
}

/*8005CA54*/
void func_8005CA54(s32 spritenum, s32 arg1)
{
    s32 unk7C;

    unk7C = D_80137DE0->unk7C;
    if (unk7C < 0)
    {
        unk7C += 7;
    }
    func_800461E8(spritenum, arg1, unk7C >> 3);
}

/*8005CA88*/
void func_8005CA88(s32 spritenum, s32 arg1)
{
    func_800461E8(spritenum, arg1, D_80137DE0->unkA);
}

/*8005CAB4*/
void func_8005CAB4(s32 spritenum, s32 arg1)
{
    func_800461E8(spritenum, arg1, D_80118248->unk16);
}

/*8005CAE0*/
void func_8005CAE0(s32 spritenum, s32 arg1)
{
    s32 i, nexti;
    s32 x, y;

    i = gHeadSpriteStat[24];
    x = gpSprite[spritenum].x;
    x &= ~0x1F;
    y = gpSprite[spritenum].y;
    y &= ~0x1F;

    while (i >= 0 && ((x != (gpSprite[i].x&~0x1F)) || (y != (gpSprite[i].y&~0x1F))))
    {
        i = gNextSpriteStat[i];
    }

    if (i != -1)
    {
        D_80137DE0->unkA = gpSprite[i].unk1E;
        D_80118248->unk16 = gpSprite[i].unk20;
    }
}

INCLUDE_ASM("nonmatchings/src/code0/59D40", func_8005CBC4);

/*8005D268*/
void func_8005D268(s32 spritenum, s32 arg1)
{
    s32 z;
    s16 ang;
    s32 unk60;
    f32 f1, f2, f3;

    ang = getAngle(D_80117ED8[0].xpos - D_80118248->x, D_80117ED8[0].ypos - D_80118248->y);
    z = (gpSprite[spritenum].z - 0x5200);
    z = (D_80117ED8[0].zpos - z) - 0x2000;
    f1 = z / 16;
    f2 = func_80040D40(D_80117ED8[0].xpos, D_80117ED8[0].ypos, gpSprite[spritenum].x, gpSprite[spritenum].y);
    f3 = func_80029FE0(f1, f2) * 325.9493234521802;
    ang += ((krand() & 0x1F) - 0x20);
    unk60 = f3;
    unk60 -= ((krand() & 0x3F) - 0x3F);
    D_80137DE0->unk5C = ang;
    D_80137DE0->unk60 = unk60;
}

/*8005D39C*/
void func_8005D39C(s32 spritenum, s32 arg1)
{
    func_800365C0(0);
}

/*8005D3BC*/
void func_8005D3BC(s32 spritenum, s32 arg1)
{
    code0unkStruct7 *ptr;

    ptr = &D_80197E40[D_80106D50[spritenum]];
    if (ptr->unkE == 0)
    {
        if ((ptr->unk0 == 0xE) || (ptr->unk0 == 0x1D))
        {
            func_80007A44(1400, spritenum, 0x4E20);
        }
    }
}

/*8005D430*/
void func_8005D430(s32 spritenum, s32 arg1)
{
    code0unkStruct7 *ptr;

    ptr = &D_80197E40[D_80106D50[spritenum]];
    if (ptr->unkE == 0)
    {
        if ((ptr->unk0 == 0x5) || (ptr->unk0 == 0x14))
        {
            func_80007A44(647, spritenum, 0x4E20);
        }
    }
}

/*8005D4A4*/
void func_8005D4A4(s32 spritenum, s32 arg1)
{
    code0unkStruct7 *ptr;

    ptr = &D_80197E40[D_80106D50[spritenum]];
    if (ptr->unkE == 0)
    {
        if ((ptr->unk0 == 0x5) || (ptr->unk0 == 0x14))
        {
            func_80007A44(520, spritenum, 0x4E20);
        }
    }
}

/*8005D518*/
void func_8005D518(s32 spritenum, s32 arg1)
{
    code0unkStruct7 *ptr;

    ptr = &D_80197E40[D_80106D50[spritenum]];
    if (ptr->unkE == 0)
    {
        if ((ptr->unk0 == 5) || (ptr->unk0 == 0x14))
        {
            func_80007A44(((krand() % 3) + 0x272) & 0xFFFF, spritenum, 0x84D0);
        }
    }
}

/*8005D5D4*/
void func_8005D5D4(s32 spritenum, s32 arg1)
{
    s16 hitsect, hitwall, hitsprite;
    s32 hitx, hity, hitz;
    s16 cstat, ang;

    cstat = gpSprite[spritenum].cstat;
    ang = gpSprite[spritenum].ang;
    gpSprite[spritenum].cstat = cstat & 0xFEFE;
    hitScan(gpSprite[spritenum].x,
            gpSprite[spritenum].y,
            gpSprite[spritenum].z - 0x1000,
            gpSprite[spritenum].sectnum,
            gpSinTable[(ang + 512) & 0x7FF],
            gpSinTable[ang & 0x7FF], 0, &hitsect, &hitwall, &hitsprite, &hitx, &hity, &hitz, 0x01000040U);

    gpSprite[spritenum].cstat = cstat;
    if (hitwall != -1)
    {
        ang = getAngle((gpWall[gpWall[hitwall].point2].x - gpWall[hitwall].x),
                       (gpWall[gpWall[hitwall].point2].y - gpWall[hitwall].y));
        ang = (ang + 512) & 0x7FF;
        ang = (ang + 1024) & 0x7FF;
        D_80137DE0->unk44 = ang;
    }
}

/*8005D740*/
void func_8005D740(s32 spritenum, s32 arg1)
{
    s32 unk18, unk1A;

    D_80118248->ang = func_80051508(D_80118248->ang, D_80137DE0->unk44, 2);
    func_8004D884();
    func_8004DC74();
    unk18 = (D_80137DE0->unk48 * gpSinTable[(D_80118248->ang + 512) & 0x7FF]) >> 14;
    unk1A = (D_80137DE0->unk48 * gpSinTable[D_80118248->ang & 0x7FF]) >> 14;
    D_80118248->unk18 = unk18;
    D_80118248->unk1A = unk1A;
    D_80118248->z -= 0x2000;
    func_8004E5F8(spritenum, unk18, unk1A, D_80118248->unk1C);
    D_80118248->z += 0x2000;
}

INCLUDE_ASM("nonmatchings/src/code0/59D40", func_8005D83C);

INCLUDE_ASM("nonmatchings/src/code0/59D40", func_8005DA18);

/*8005DCAC*/
void func_8005DCAC(s32 spritenum, s32 arg1)
{
    D_80118248->unk22 += arg1;
}

/*8005DCC4*/
void func_8005DCC4(s32 spritenum, s32 arg1)
{
    func_80008574(0, func_80045E40(spritenum, arg1));
}

/*8005DCF0*/
void func_8005DCF0(s32 spritenum, s32 arg1)
{
    D_800DEE80 = spritenum;
}

/*8005DD00*/
void func_8005DD00(s32 spritenum, s32 arg1)
{
    D_800DEE80 = -1;
}

/*8005DD14*/
void func_8005DD14(s32 spritenum, s32 arg1)
{
    func_80050C14();
    func_80057540(&gpSprite[spritenum], 0x6F5, 0xE, 0);
    func_8004BC64(D_80118248->x - 0x12C, D_80118248->y, D_80118248->z, D_80118248->sectnum, 0x9EB, 0, 0);
}

/*8005DD9C*/
void func_8005DD9C(s32 spritenum, s32 arg1)
{
    func_8008E01C(func_80045E40(spritenum, arg1), 1);
}

/*8005DDCC*/
void func_8005DDCC(s32 spritenum, s32 arg1)
{
    D_80118248->unk24 = func_80045E40(spritenum, arg1);
}

/*8005DDF4*/
void func_8005DDF4(s32 spritenum, s32 arg1)
{
    s32 i;
    s32 spritenum_;

    func_8008E3E0(gpSprite[spritenum].x + ((75 * gpSinTable[495]) >> 10),
                  gpSprite[spritenum].y + ((75 * gpSinTable[2031]) >> 10),
                  gpSprite[spritenum].z,
                  gpSprite[spritenum].sectnum,
                  11,
                  0);

    for (i = 0; i < 7; i++)
    {
        spritenum_ = func_8008E3E0(gpSprite[spritenum].x, gpSprite[spritenum].y,
                                   gpSprite[spritenum].z, gpSprite[spritenum].sectnum, 55, 2130);
        if (spritenum_ >= 0)
            gpSprite[spritenum_].ang = (krand() & 0x7F) + 1968;
    }

    func_80045400(0x5713, -0x2D7, -0x1D00, 0xA, 0xA0, 0x200, 0x19, 0x14);
}

/*8005DF6C*/
void func_8005DF6C(s32 spritenum, s32 arg1)
{
    s32 floorz;
    floorz = getFlorzOfSlope(D_80118248->sectnum, D_80118248->x, D_80118248->y);
    func_800461E8(spritenum, arg1, (floorz - D_80118248->z));
}

/*8005DFD4*/
void func_8005DFD4(s32 spritenum, s32 arg1)
{
    func_800461E8(spritenum, arg1, D_80137DE0->unk9E);
}

/*8005E000*/
void func_8005E000(s32 spritenum, s32 arg1)
{
    s16 unk22;
    s16 spritenum_;

    if (!MusHandleAsk(D_8013B2D0[spritenum].handle))
    {
        D_8013B2D0[spritenum].handle = func_80007170(1429);
    }
    unk22 = D_80118248->unk22;
    if (unk22 == -1)
    {
        spritenum_ = func_8008E3E0(D_80118248->x, D_80118248->y,
                                   D_80118248->z, D_80118248->sectnum, 0x3B, 1);

        D_80118248->unk22 = spritenum_;
        if (spritenum_ != unk22)
        {
            gpSprite[spritenum_].unk22 = spritenum;
        }
    }
}

/*8005E0E0*/
void func_8005E0E0(s32 spritenum, s32 arg1)
{
    s32 spritenum_;

    func_80007A44(0x3F6, spritenum, 0xBB80);
    spritenum_ = func_8008E3E0(D_80118248->x, D_80118248->y,
                               D_80118248->z, D_80118248->sectnum, 0x37, 0x6B1);
    if (spritenum_ != -1)
    {
        gpSprite[spritenum_].ang = getAngle((D_80117ED8->xpos - D_80118248->x),
                                            (D_80117ED8->ypos - D_80118248->y));
    }
    func_8008E3E0(D_80118248->x, D_80118248->y, D_80118248->z, D_80118248->sectnum, 0x37, 0x6B3);
    func_8008E3E0(D_80118248->x, D_80118248->y, D_80118248->z, D_80118248->sectnum, 0x37, 0x6B4);
    func_80057540(D_80118248, 0x1644, (krand() & 3) + 1, 0);
}

/*8005E228*/
void func_8005E228(s32 spritenum, s32 arg1)
{
    s32 unk1E;

    unk1E = D_80118248->unk1E;
    D_80118248->unk1E = 0xC;
    func_8004AB6C(spritenum, arg1, (arg1 >> 2), (arg1 >> 1), (arg1 - (arg1 >> 2)), 0xC8, 0);
    D_80118248->unk1E = unk1E;
}

/*8005E288*/
void func_8005E288(s32 spritenum, s32 arg1)
{
    D_80137DE0->unkA = D_80137DE0->unk99;
}

/*8005E29C*/
void func_8005E29C(s32 spritenum, s32 arg1)
{
    D_80137DE0->unk99 = D_80137DE0->unkA;
}

INCLUDE_ASM("nonmatchings/src/code0/59D40", func_8005E2B0);

/*8005E4B0*/
void func_8005E4B0(s32 spritenum, s32 arg1)
{
    D_80117ED8[0].unk52 = spritenum + 2048;
}

/*8005E4C4*/
void func_8005E4C4(s32 spritenum, s32 arg1)
{
    s32 i, nexti;

    D_800DEF1C = -1;
    D_80117ED8[0].unk52 = -1;
    D_800DEE80 = -1;
    i = gHeadSpriteStat[1];
    while (i >= 0)
    {
        nexti = gNextSpriteStat[i];
        if (gpSprite[i].picnum == 0x2E && i != spritenum && arg1)
        {
            func_8004BD24(i);
            break;
        }
        i = nexti;
    }
}

/*8005E57C*/
void func_8005E57C(s32 spritenum, s32 arg1)
{
    gpSprite[D_8012FCA0].cstat |= 0x8000;
    gpSprite[D_80117ED8[0].unk4A].xrepeat = 0;
    gpSprite[D_80117ED8[0].unk4A].yrepeat = 0;
}

/*8005E604*/
void func_8005E604(s32 spritenum, s32 arg1)
{
    s32 i;

    i = gHeadSpriteStat[1];
    while (i >= 0)
    {
        if (gpSprite[i].shade == 3 && gpSprite[i].picnum == 1442)
        {
            gpSprite[i].unk22 = 0x7B;
            gpSprite[spritenum].unk16 = i;

        }
        i = gNextSpriteStat[i];
    }
}

/*8005E694*/
void func_8005E694(s32 spritenum, s32 arg1)
{
    s32 i;

    i = gHeadSpriteStat[1];
    while (i >= 0)
    {
        if (gpSprite[i].shade == 3 && gpSprite[i].picnum == 1442)
        {
            gpSprite[i].unk22 = 0x7B;
            D_800DEF1C = i;
            break;
        }
        i = gNextSpriteStat[i];
    }
}

/*8005E718*/
void func_8005E718(s32 spritenum, s32 arg1)
{
    if (((gpSector[D_80118248->sectnum].ceilingz >> 8) + 0x96) >= (D_80118248->z >> 8))
    {
        D_80137DE0->unk44 = 1;
    }
}

/*8005E770*/
void func_8005E770(s32 spritenum, s32 arg1)
{
    D_8013B2D0[spritenum].unk2 = D_800DF2E4;
    D_8013B2D0[spritenum].unk4 = D_800DF2E8;
}

INCLUDE_ASM("nonmatchings/src/code0/59D40", func_8005E7AC);

/*8005E9D8*/
void func_8005E9D8(s32 spritenum, s32 arg1)
{
    func_80007A44(0x25A, spritenum, 0x7D00);
}

/*8005EA04*/
void func_8005EA04(s32 spritenum, s32 arg1)
{
    func_8006B590(0x190);
}

/*8005EA24*/
void func_8005EA24(s32 spritenum, s32 arg1)
{
    func_8006B590(func_80045E40(spritenum, arg1));
}

/*8005EA50*/
void func_8005EA50(s32 spritenum, s32 arg1)
{
    s16 unk16;

    if (D_8013B2D0[spritenum].unk0 < -80)
        D_8013B2D0[spritenum].unk0 = -80;
    else if (D_8013B2D0[spritenum].unk0 >= 81)
        D_8013B2D0[spritenum].unk0 = 80;

    if (D_8013B2D0[spritenum].unk4 < -32)
        D_8013B2D0[spritenum].unk4 = -32;
    else if (D_8013B2D0[spritenum].unk4 >= 33)
        D_8013B2D0[spritenum].unk4 = 32;

    if (D_80118248->picnum == 2443)
    {
        unk16 = D_80118248->unk16;
        D_8013B2D0[unk16].unk2 = D_8013B2D0[spritenum].unk2;
        D_8013B2D0[unk16].unk0 = D_8013B2D0[spritenum].unk0;
        D_8013B2D0[unk16].unk4 = D_8013B2D0[spritenum].unk4;
    }
}

/*8005EB4C*/
void func_8005EB4C(s32 spritenum, s32 arg1)
{
    D_80117ED8[0].unk45 = 0xFF;
    D_80117ED8[0].unk4E = 0;
    D_8019B940[D_80106D50[D_80117ED8[0].unk4A]].unk8 = 0;
}

/*8005EBA0*/
void func_8005EBA0(s32 spritenum, s32 arg1)
{
    s32 i, nexti;

    func_8005E4C4(spritenum, 0);
    i = gHeadSpriteStat[1];
    while (i >= 0)
    {
        nexti = gNextSpriteStat[i];
        if ((D_8019B940[D_80106D50[i]].unk0 & 0x200000) != 0)
        {
            func_8004BD24(i);
        }
        i = nexti;
    }
}

/*8005EC54*/
void func_8005EC54(s32 spritenum, s32 arg1)
{
    D_80118248->ang = (D_80118248->ang + func_80045E40(spritenum, arg1)) & 0x7FF;
}

/*8005EC88*/
void func_8005EC88(s32 spritenum, s32 arg1)
{
    s32 i;

    i = gHeadSpriteStat[1];
    while (i >= 0)
    {
        if (gpSprite[i].picnum == 1727 && gpSprite[i].shade == 0x14)
        {
            D_8019B940[D_80106D50[i]].unk44 = 1;
        }
        i = gNextSpriteStat[i];
    }
}

/*8005ED2C*/
void func_8005ED2C(s32 spritenum, s32 arg1)
{
    func_80007170(func_80045E40(spritenum, arg1));
}

/*8005ED54*/
void func_8005ED54(s32 spritenum, s32 arg1)
{
    s32 spritnum_;
    s32 i;

    for (i = 0; i < 3; i++)
    {
        func_8008E3E0(D_80118248->x, D_80118248->y,
                      D_80118248->z - 0x2000,
                      D_80118248->sectnum, 0x37, 0x852);
    }
    spritnum_ = func_8008E3E0(D_80118248->x, D_80118248->y,
                              D_80118248->z - 0x3000,
                              D_80118248->sectnum, 0x37, 0x852);
    if (spritnum_ != -1)
    {
        gpSprite[spritnum_].ang = 0x180;
    }
    D_80118248->z -= 0x1600;
    func_80057540(D_80118248, 0x5DC, 5, 0);
    D_80118248->z += 0x1600;
}

/*8005EE60*/
void func_8005EE60(s32 spritenum, s32 arg1)
{
    s16 ang1;
    s32 ang2;

    ang1 = getAngle((D_80117ED8->xpos - gpSprite[D_80118248->unk16].x),
                    (D_80117ED8->ypos - gpSprite[D_80118248->unk16].y));

    ang2 = func_80040E90(gpSprite[D_80118248->unk16].ang, ang1);

    ang2 = klabs(ang2);
    if (ang2 < 0x40)
    {
        func_800461E8(spritenum, arg1, 1);
    }
    else
    {
        func_800461E8(spritenum, arg1, 0);
    }
}

/*8005EF54*/
void func_8005EF54(s32 spritenum, s32 arg1)
{
    func_800461E8(spritenum, arg1, func_8004F4A0());
}

/*8005EF98*/
void func_8005EF98(s32 spritenum, s32 arg1)
{
    s32 x, y;

    if ((D_80118248->unk18 != 0) || (D_80118248->unk1A != 0))
    {
        x = klabs_(D_80118248->x - D_80117ED8[0].xpos);
        y = klabs_(D_80118248->y - D_80117ED8[0].ypos);
        if (((x + y) < 0x28A) && (D_80118248->z > D_80117ED8[0].zpos))
        {
            func_800461E8(spritenum, arg1, 1);
        }
    }
}

/*8005F050*/
void func_8005F050(s32 spritenum, s32 arg1)
{
    s32 ang1, ang2;

    ang1 = getAngle(D_80117ED8->xpos - D_80118248->x, D_80117ED8->ypos - D_80118248->y);
    ang2 = func_80040E90(D_80118248->ang, ang1) >> 3;
    D_80118248->ang = func_80051508(D_80118248->ang, ang1, 3);
    D_80137DE0->unk32 = ang2;
}

/*8005F0F0*/
void func_8005F0F0(s32 spritenum, s32 arg1)
{
    s32 unk38, unk3E;
    s32 spritenum_;
    s32 ang;
    f32 f1, f2, f3;

    D_80138690 = 1;
    ang = getAngle(D_80137DE0->unk44 - D_80137DE0->unk48, D_80118248->x - D_80118248->y);

    spritenum_ = ang; /*FIXME*/

    f1 = (D_80137DE0->unk4C - D_80118248->z) / 16;
    f2 = func_80040D40(D_80137DE0->unk44,
                       D_80137DE0->unk48,
                       D_80118248->x,
                       D_80118248->y);
    f3 = func_80029FE0(f1, f2) * 325.9493234521802;

    unk38 = D_80117ED8[0].unk38;
    D_80117ED8[0].unk38 = ang;
    unk3E = D_80117ED8[0].unk3E;
    D_80117ED8[0].unk3E = f3;
    spritenum_ = func_8006D3B8(D_80117ED8[0].unk4A, 0x13, 0, 0, 0);
    D_80117ED8[0].unk38 = unk38;
    D_80117ED8[0].unk3E = unk3E;

    if (spritenum_ > 0)
    {
        setSprite(spritenum_, D_80137DE0->unk44, D_80137DE0->unk48, D_80137DE0->unk4C);
        gpSprite[spritenum_].unk16 = spritenum;
    }
}

/*8005F290*/
void func_8005F290(s32 spritenum, s32 arg1)
{
    D_80118248->picnum = 0x8EC;
    func_8008E3E0(D_80118248->x, D_80118248->y,
                  D_80118248->z, D_80118248->sectnum, 0x2F, 0);

    func_80045400(D_80118248->x, D_80118248->y, D_80118248->z - 0x3E80,
                  D_80118248->sectnum, 0, D_80118248->ang, 0x2C, 0x82);

    func_80045400(D_80118248->x, D_80118248->y, D_80118248->z - 0x1F40,
                  D_80118248->sectnum, 0, D_80118248->ang, 0x2C, 0x82);
}

/*8005F358*/
void func_8005F358(s32 spritenum, s32 arg1)
{
    changeSpriteStat(spritenum, 160);
    D_80118248->shade = 3;
}

INCLUDE_ASM("nonmatchings/src/code0/59D40", func_8005F38C);

INCLUDE_ASM("nonmatchings/src/code0/59D40", func_8005F560);

/*8005F6A8*/
void func_8005F6A8(s32 spritenum, s32 arg1)
{
    if ((D_80118248->cstat & 8) == 0)
        D_801A1958.unk0++;
}

/*8005F6DC*/
void func_8005F6DC(s32 spritenum, s32 arg1)
{
    if (D_801CE48C != 0)
    {
        func_800461E8(spritenum, arg1, func_80045E40(spritenum, arg1) * 4);
    }
}

/*8005F730*/
void func_8005F730(s32 spritenum, s32 arg1)
{
    s16 spritenum_;

    spritenum_ = func_80058934(D_80118248->x, D_80118248->y, D_80118248->z, D_80118248->sectnum, 0);
    gpSprite[spritenum_].cstat = 0x1000;
    gpSprite[spritenum_].xrepeat = 0x40;
    gpSprite[spritenum_].yrepeat = 0x40;
    gpSprite[spritenum_].picnum = 0xA13;
    gpSprite[spritenum_].shade = 0;
    gpSprite[spritenum_].unk16 = spritenum;
}

/*8005F7E8*/
void func_8005F7E8(s32 spritenum, s32 arg1)
{
    D_800DEEB8 = 1;
}

/*8005F7FC*/
void func_8005F7FC(s32 spritenum, s32 arg1)
{
    s32 i;

    i = gHeadSpriteStat[1];
    while (i >= 0)
    {
        if (gpSprite[i].picnum == 2596)
        {
            func_8001F7B4(0xC, 8);
            D_800DEEB8 = 0;
            gpSprite[i].unk22 = 1;
            break;
        }
        i = gNextSpriteStat[i];
    }
}

/*8005F8A0*/
void func_8005F8A0(s32 spritenum, s32 arg1)
{
}

/*8005F8A8*/
void func_8005F8A8(s32 spritenum, s32 arg1)
{
    D_8013B2D0[spritenum].unk6 = (krand() & 0x3F) + 64;
}

/*8005F8F0*/
void func_8005F8F0(s32 spritenum, s32 arg1)
{
    s32 i;

    i = gHeadSpriteStat[1];
    while (i >= 0)
    {
        if (gpSprite[i].picnum == 2487)
        {
            func_8004BD24(i);
            break;
        }
        i = gNextSpriteStat[i];
    }
    D_800DEEE4 = 1;
}

/*8005F974*/
void func_8005F974(s32 spritenum, s32 arg1)
{
    D_800DEEB8 = 2;
}

/*8005F988*/
void func_8005F988(s32 spritenum, s32 arg1)
{
    s32 x, y;

    x = klabs_(D_80118248->x - D_80137DE0->unk38);
    y = klabs_(D_80118248->y - D_80137DE0->unk3C);
    if ((x + y) < 500)
    {
        D_80137DE0->unk38 = -1;
    }
}

/*8005FA08*/
void func_8005FA08(s32 spritenum, s32 arg1)
{
    D_80137DE0->unk44 = D_80117ED8[0].xpos;
    D_80137DE0->unk48 = D_80117ED8[0].ypos;
    D_80137DE0->unk4C = gpSprite[D_80117ED8[0].unk4A].z - 7296;
}

/*8005FA60*/
void func_8005FA60(s32 spritenum, s32 arg1)
{
    changeSpriteStat(spritenum, 0);
}

/*8005FA88*/
void func_8005FA88(s32 spritenum, s32 arg1)
{
    s32 i;

    func_800077F4(0x2B8, D_80117ED8[0].unk4A);
    func_800A419C(0, *gpKeyStrInfo[gMapNum]);
    D_80117ED8[0].pad[1] = 1;

    i = gHeadSpriteSect[D_80117ED8[0].unk32];
    while (i >= 0)
    {
        if (gpSprite[i].picnum == 2002 || gpSprite[i].picnum == 2005)
        {
            gpSprite[i].unk2B = 0;
            gpSprite[i].unk22 = 0;
            gpSprite[i].shade = 0;
            func_80042124(&D_8019B940[D_80106D50[i]], 133);
            D_8019B940[D_80106D50[i]].unk8 = 30;
        }
        i = gNextSpriteSect[i];
    }
}

/*8005FBFC*/
void func_8005FBFC(s32 spritenum, s32 arg1)
{
    D_80137DE0->unk64 = D_80137DE0->unk1C;
    if (D_80137DE0->unk1C)
        D_80137DE0->unk1C = 0;
}

/*8005FC20*/
void func_8005FC20(s32 spritenum, s32 arg1)
{
    D_80137DE0->unk1C = D_80137DE0->unk64;
}

/*8005FC34*/
void func_8005FC34(s32 spritenum, s32 arg1)
{
    func_800A419C(0, "BABE SAVED!");
    D_801A1958.unk4++;
    func_800077F4(0x2C0, spritenum);
    func_8008E3E0(gpSprite[spritenum].x, gpSprite[spritenum].y, gpSprite[spritenum].z, gpSprite[spritenum].sectnum, 0x2B, 0);
    func_80036520(0, 0xA);
}

/*8005FCDC*/
void func_8005FCDC(s32 spritenum, s32 arg1)
{
    if (D_800DEEA0)
        func_80045400(D_80118248->x, D_80118248->y, D_80118248->z, D_80118248->sectnum, 0, 0, 44, 7);
}

/*8005FD38*/
void func_8005FD38(s32 spritenum, s32 arg1)
{
    D_80137DE0->unk84 = -1;
}

/*8005FD4C*/
void func_8005FD4C(s32 spritenum, s32 arg1)
{
    D_80137DE0->unk84 = 38;
}

/*8005FD60*/
void func_8005FD60(s32 spritenum, s32 arg1)
{
    if (D_801CA14C[gMapNum].unk0 == 1 && D_80118248->picnum != 1304)
        func_80007A44(752, spritenum, 16000);
}
