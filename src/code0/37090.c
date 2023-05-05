#include "common.h"
#include "code0/main.h"
#include "code0/engine.h"
#include "code0/pragmas.h"
#include "code0/audio.h"
#include "code0/41940.h"
#include "code0/code0.h"

/*.data*/
/*800DEDE0*/ EXTERN_DATA u8 D_800DEDE0;

/*.text*/

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

    i = D_80106D50[gPlayer[playernum].unk4A];
    if (D_8019B940[i].unk8 > 0)
    {
        if (D_8019B940[i].unk8 < gPlayer[playernum].unk48)
            D_8019B940[i].unk8 = MIN(gPlayer[playernum].unk48, (D_8019B940[i].unk8 + arg1));
    }
}

/*800365C0*/
void func_800365C0(s16 playernum)
{
    if (!gPlayer[playernum].unk45)
    {
        D_8019B940[D_80106D50[gPlayer[playernum].unk4A]].unk8 = 0;
        D_8019B940[D_80106D50[gPlayer[playernum].unk4A]].unk9E = -3;
        gPlayer[playernum].unk45 = 3;
        gPlayer[playernum].unk4E = 0;
        playSfx(krand() % 3 + 538);
        gpSprite[gPlayer[playernum].unk4A].cstat = 0x8000;
    }
}

INCLUDE_ASM("nonmatchings/src/code0/37090", func_8003671C);

/*80036FEC*/
static void func_80036FEC(void)
{
    s16 spritenum;
    s32 z;
    u8 cond;
    u16 cstat;

    if (gPlayer[D_801B0820].unk45 || D_80106D30[D_801B0820])
        D_800DD448 = 1;

    cstat = gpSprite[gPlayer[D_801B0820].unk4A].cstat;
    gpSprite[gPlayer[D_801B0820].unk4A].cstat = cstat & 0xFEFE;

    getzRange(gPlayer[D_801B0820].xpos,
              gPlayer[D_801B0820].ypos,
              gPlayer[D_801B0820].zpos + gPlayer[D_801B0820].unk40 / 2,
              gPlayer[D_801B0820].unk32,
              &D_801A1998,
              &D_801AE9C0,
              &D_80138860,
              &D_800FCBE0,
              0x40, 0x10001U);

    gpSprite[gPlayer[D_801B0820].unk4A].cstat = cstat;
    D_800DD448 = 0;

    cond = 1;
    if (gpSector[gPlayer[D_801B0820].unk32].ceilingstat & 1)
        cond = D_801AE9C0 > 0xBFFF;

    if (cond && (gPlayer[D_801B0820].unk45 == 0) &&
        (D_80106D30[D_801B0820] == 0) &&
        ((D_80138860 - D_801A1998) < (gPlayer[D_801B0820].unk40 / 2)))
        func_800365C0(D_801B0820);

    D_80129804 = getFlorzOfSlope(gPlayer[D_801B0820].unk32,
                                 gPlayer[D_801B0820].xpos,
                                 gPlayer[D_801B0820].ypos) - gPlayer[D_801B0820].unk40;

    D_8012EB4C = getCeilzOfSlope(gPlayer[D_801B0820].unk32,
                                 gPlayer[D_801B0820].xpos,
                                 gPlayer[D_801B0820].ypos) + 1024;

    D_80138860 -= gPlayer[D_801B0820].unk40;
    D_801A1998 += 1024;
    gPlayer[D_801B0820].unk36 = gPlayer[D_801B0820].unk32;

    if ((u32)(D_800FCBE0 - 0x4000) <= 0x7FFFU)
        gPlayer[D_801B0820].unk36 = (D_800FCBE0 - 0x4000);

    if (D_800FCBE0 > 0xBFFF)
    {
        gPlayer[D_801B0820].unk36 = D_800FCBE0 + 0x5000;
        spritenum = D_800FCBE0 + 0x4000;
        if ((gPlayer[D_801B0820].unk59) && (gpSprite[spritenum].statnum == 1))
            D_8019B940[D_80106D50[spritenum]].unk94 |= 1u;
    }

    gPlayer[D_801B0820].unk56 = 0;
    if (gpSector[gPlayer[D_801B0820].unk32].unk18 == 1)
    {
        if (D_80138860 == D_80129804)
        {
            D_80138860 = D_80138860 + 0x2600;
            if (gPlayer[D_801B0820].zpos >= D_80138860)
            {
                gPlayer[D_801B0820].zpos = D_80138860;
                gPlayer[D_801B0820].unk56 = 1;
            }
        }
        D_80129804 = D_80129804 + 0x2600;
    }

    if ((gpSector[gPlayer[D_801B0820].unk32].unk18 == 3) && (gPlayer[D_801B0820].unk14 <= 0))
    {
        z = func_80036490(gPlayer[D_801B0820].unk32);
        if ((gPlayer[D_801B0820].zpos >= (z - 0x1300)) && (gPlayer[D_801B0820].zpos < z))
        {
            gPlayer[D_801B0820].unk56 = 1;
            gPlayer[D_801B0820].zpos = (z - 0x1300);
        }
    }

    if (gpSector[gPlayer[D_801B0820].unk32].unk18 == 4)
    {
        if (D_80138860 == D_80129804)
            D_80138860 = D_80129804 + 0x1000;
        D_80129804 = D_80129804 + 0x1000;
    }

    if (gpSector[gPlayer[D_801B0820].unk32].unk18 == 5)
    {
        if (D_80138860 == D_80129804)
            D_80138860 = D_80129804 + 0x2600;
        D_80129804 = D_80129804 + 0x2600;
    }

    if (gpSector[gPlayer[D_801B0820].unk32].unk18 == 6)
    {
        if (D_80138860 == D_80129804)
            D_80138860 = D_80129804 + 0x1000;
        D_80129804 = D_80129804 + 0x1000;
    }
}

/*8003779C*/
static s32 func_8003779C(u8 arg0)
{
    return D_8012F6FC[D_801B0820] & D_8012D218[D_801B0820][arg0];
}

/*800377E8*/
s32 func_800377E8(void)
{
    s16 ang, dist;

    D_8012F914[D_801B0820] = -1;
    if (gpSprite[D_800DEE80].unk25 != 0)
    {
        gPlayer[D_801B0820].xpos = gpSprite[D_800DEE80].x;
        gPlayer[D_801B0820].ypos = gpSprite[D_800DEE80].y;
        gPlayer[D_801B0820].zpos = gpSprite[D_800DEE80].z;
        gPlayer[D_801B0820].unk38 = gpSprite[D_800DEE80].ang;
        gPlayer[D_801B0820].unk32 = gpSprite[D_800DEE80].sectnum;
        gPlayer[D_801B0820].unk3E = 0;
        return 0;
    }

    gPlayer[D_801B0820].unk3E /= 2;
    dist = ldist(&gpSprite[D_800DEE80], &gpSprite[gPlayer[D_801B0820].unk4A]);

    if (dist < 512)
    {
        ang = gpSprite[D_800DEE80].ang - gPlayer[D_801B0820].unk38;

        if (ang > 1024)
            ang -= 2048;
        if (ang < -1024)
            ang += 2048;

        gPlayer[D_801B0820].unk38 += ang / 8;
        gPlayer[D_801B0820].xpos += (gpSprite[D_800DEE80].x - gPlayer[D_801B0820].xpos) / 4;
        gPlayer[D_801B0820].ypos += (gpSprite[D_800DEE80].y - gPlayer[D_801B0820].ypos) / 4;
        return 0;
    }
    ang = getAngle(gpSprite[D_800DEE80].x - gPlayer[D_801B0820].xpos,
                   gpSprite[D_800DEE80].y - gPlayer[D_801B0820].ypos);

    ang -= gPlayer[D_801B0820].unk38;

    if (ang > 1024)
        ang -= 2048;
    if (ang < -1024)
        ang += 2048;

    gPlayer[D_801B0820].unk38 = (gPlayer[D_801B0820].unk38 + (ang / 3)) & 0x7FF;
    D_80119A30[D_801B0820] |= 1;

    if (dist < 1024)
        return 13;
    else
        return 20;
}

INCLUDE_ASM("nonmatchings/src/code0/37090", func_80037B84);

/*800390F0*/
static void func_800390F0(void)
{
    s32 ang, i1, i2;
    s16 sectnum;
    s32 temp, temp1;

    if (gPlayer[D_801B0820].unk54 != 0)
        return;

    if (gPlayer[D_801B0820].unk36 >= 0x1000)
        return;

    if (((gPlayer[D_801B0820].zpos + gPlayer[D_801B0820].unk14 + 1280) >= D_80138860) &&
        (gPlayer[D_801B0820].unk58 == 0))
    {
        sectnum = gPlayer[D_801B0820].unk36;
        i1 = sectnum; /*FAKEMATCH*/

        if ((gpSector[sectnum].floorstat & 2) && (gpSector[sectnum].floorheinum != 0))
        {
            gPlayer[D_801B0820].zpos = D_80138860;
            if (gPlayer[D_801B0820].unk14 < 0)
                gPlayer[D_801B0820].unk14 = 0;

            ang = (getAngle(gpWall[gpWall[gpSector[sectnum].wallptr].point2].x - gpWall[gpSector[sectnum].wallptr].x,
                gpWall[gpWall[gpSector[sectnum].wallptr].point2].y - gpWall[gpSector[sectnum].wallptr].y) + 512) & 0x7FF;

            temp = (gpSector[sectnum].floorheinum < 0) ? -1 : 1;
            temp1 = klabs(gpSector[sectnum].floorheinum) / 256;
            i1 = temp * temp1 * gpSinTable[(ang + 512) & 0x7FF];
            i2 = temp * temp1 * gpSinTable[ang];
            gPlayer[D_801B0820].unkC += i1;
            gPlayer[D_801B0820].unk10 += i2;
        }
    }
}

/*80039344*/
static void func_80039344(void)
{
    f64 f1, f2, f3;
    s32 i1;
    s32 temp;
    u8 i2;

    i1 = 0x240000;
    if (gPlayer[D_801B0820].unk59 != 0)
        i1 = (((f32)D_8012F6E4[gPlayer[D_801B0820].unk4C].unkA * (f32)i1) / 100.0);

    if (gPlayer[D_801B0820].unk36 >= 0x1000)
        i2 = gpSector[gPlayer[D_801B0820].unk32].unk2A;
    else
        i2 = gpSector[gPlayer[D_801B0820].unk36].unk2A;

    f1 = sqrtf(((f64)gPlayer[D_801B0820].unkC * (f64)gPlayer[D_801B0820].unkC) +
               ((f64)gPlayer[D_801B0820].unk10 * (f64)gPlayer[D_801B0820].unk10));

    if (f1 != 0.0)
    {
        temp = (32 - i2) * 16384;
        i1 += temp * 3;

        if (D_8010A940[D_801B0820].unk4 && D_800DEE80 == -1)
            i1 *= 2;

        if (gPlayer[D_801B0820].unk54 != 0)
            i1 = (i1 * 5) / 8;

        if (gPlayer[D_801B0820].unk56 != 0)
            i1 /= 3;

        if (gPlayer[D_801B0820].unk5A != 0)
            i1 /= 3;

        if (gPlayer[D_801B0820].unk6C != 0)
            i1 /= 4;

        if (i1 < f1)
        {
            f2 = i1 / f1;
            gPlayer[D_801B0820].unkC *= f2;
            gPlayer[D_801B0820].unk10 *= f2;
        }

        if (f1 <= (i2 * 8192))
        {
            gPlayer[D_801B0820].unkC = 0;
            gPlayer[D_801B0820].unk10 = 0;
        }
        else
        {
            f3 = (f1 - (i2 * 8192)) / f1;
            gPlayer[D_801B0820].unkC *= f3;
            gPlayer[D_801B0820].unk10 *= f3;
        }
    }
}

INCLUDE_ASM("nonmatchings/src/code0/37090", func_80039774);

INCLUDE_ASM("nonmatchings/src/code0/37090", func_8003A910);

/*8003AFD0*/
static void func_8003AFD0(s16 playernum)
{
    gPlayer[playernum].unk6C = 2;
    gPlayer[playernum].unk6E = 256;
    gPlayer[playernum].unk60 = 0;
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
            gPlayer[playernum].unk60 = gPlayer[playernum].unk61;
    }
    D_800DEED0[playernum] = 0;
}

INCLUDE_ASM("nonmatchings/src/code0/37090", func_8003B0E4);

INCLUDE_ASM("nonmatchings/src/code0/37090", func_8003B31C);

INCLUDE_ASM("nonmatchings/src/code0/37090", func_8003B428);

STATIC void func_8003B5F8(void);
INCLUDE_ASM("nonmatchings/src/code0/37090", func_8003B5F8);

INCLUDE_ASM("nonmatchings/src/code0/37090", func_8003DACC);

/*8003DD54*/
void func_8003DD54(void)
{
    for (D_801B0820 = 0; D_801B0820 < D_8012C470; D_801B0820++)
        func_8003B5F8();
}

INCLUDE_ASM("nonmatchings/src/code0/37090", func_8003DDB8);

INCLUDE_ASM("nonmatchings/src/code0/37090", func_8003E8D0);
