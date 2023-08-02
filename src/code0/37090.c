#include "common.h"
#include "code0/main.h"
#include "code0/engine.h"
#include "code0/pragmas.h"
#include "code0/audio.h"
#include "code0/9410.h"
#include "code0/17B30.h"
#include "code0/37090.h"
#include "code0/41940.h"
#include "code0/6ACA0.h"
#include "code0/7A430.h"
#include "code0/8E670.h"
#include "code0/8EFE0.h"
#include "code0/A06F0.h"
#include "code0/code0.h"
#include "code1/EB300.h"

typedef struct {
    /*0x00*/ u8 unk0;
    /*0x02*/ s16 unk2;
    /*0x04*/ s16 unk4;
} _37090UnkStruct;

/*.data*/
/*800DEDC0*/ EXTERN_DATA STATIC s8 D_800DEDC0;
/*800DEDD0*/ EXTERN_DATA STATIC u8 D_800DEDD0[MAXPLAYERS];
/*800DEDE0*/ EXTERN_DATA u8 D_800DEDE0;
/*800DEE14*/ EXTERN_DATA STATIC _37090UnkStruct D_800DEE14[13];
/*800DEE64*/ EXTERN_DATA STATIC musHandle D_800DEE64;

/*.comm*/
/*8011BC44*/ code0UnkStruct3 *D_8011BC44;
/*80138850*/ u8 D_80138850;

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

/*8003671C*/
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

    if (D_800FCBE0 >= 0x4000 && D_800FCBE0 < 0xC000)
        gPlayer[D_801B0820].unk36 = (D_800FCBE0 - 0x4000);

    if (D_800FCBE0 >= 0xC000)
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

/*80037B84*/
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

        if (D_8010A940[D_801B0820].unk2[2] && D_800DEE80 == -1)
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

/*80039774*/
void func_80039774(void)
{
    code0unkStruct8 *ptr;
    f32 f1, f2;
    s16 i, j;
    s32 k, l, m;
    s32 ang1, ang2;

    if (gPlayer[D_801B0820].zpos < D_80138860)
    {
        if (gPlayer[D_801B0820].unk5B != 0)
            gPlayer[D_801B0820].unk14 *= 0.667;
        else if (gPlayer[D_801B0820].unk56 == 0)
            gPlayer[D_801B0820].unk14 += 0x100;
    }
    else if ((D_80138860 < gPlayer[D_801B0820].zpos) &&
             (((gPlayer[D_801B0820].zpos - D_80138860) < 0x1200) ||
                 (D_80129804 < gPlayer[D_801B0820].zpos)))
    {
        gPlayer[D_801B0820].zpos += ((D_80138860 - gPlayer[D_801B0820].zpos) / 2);
    }

    if (gPlayer[D_801B0820].unk58 != 0)
        gPlayer[D_801B0820].unk14 = (-D_800DEDC0 * 0x800) / 7;

    if (gPlayer[D_801B0820].unk5B != 0)
    {
        s32 temp = D_801B0820; /*FAKEMATCH?*/
        f1 = gPlayer[D_801B0820].unk14;
        f2 = gPlayer[D_801B0820].unk20;
        gPlayer[temp].unk14 = (f1 + (f2 * sinf((gPlayer[D_801B0820].unk3E * 0.0030679615757714844)) * 16.0f));
    }

    if ((gPlayer[D_801B0820].unk56 != 0) &&
        (gPlayer[D_801B0820].unk3E > 200) &&
        (gPlayer[D_801B0820].unk20 > 0))
    {
        gPlayer[D_801B0820].unk14 = CLAMP_MAX((gPlayer[D_801B0820].unk14 + 0x101), 0x800);
    }

    if (gPlayer[D_801B0820].unk45 != 0)
    {
        if (gPlayer[D_801B0820].unk50 != -1)
        {
            gPlayer[D_801B0820].unk50 = -1;
            if (gPlayer[D_801B0820].unk6C == 0)
                gPlayer[D_801B0820].unk60 = gPlayer[D_801B0820].unk61;
        }

        if (gPlayer[D_801B0820].unk56 != 0)
            gPlayer[D_801B0820].unk14 += 0x100;
    }

    D_801A6AD4[D_801B0820] = 0;
    gPlayer[D_801B0820].unk5C = 0;

    if ((gPlayer[D_801B0820].unk50 >= 0) &&
        (gpSector[gPlayer[D_801B0820].unk32].floorstat & 0x800) &&
        (func_8003779C(9) != 0))
    {
        gPlayer[D_801B0820].unk5C = 1;
    }
    else if (D_80138850 != 0)
    {
        if (gPlayer[D_801B0820].unk6C == 0)
        {
            i = 0;
            if (gPlayer[D_801B0820].unk36 > 0x1000)
            {
                switch (gpSprite[(s16)(gPlayer[D_801B0820].unk36 - 0x1000)].statnum)
                {
                case 1:
                    i = gpSprite[(s16)(gPlayer[D_801B0820].unk36 - 0x1000)].picnum != 2222;
                    break;

                case 10:
                    i = 1;
                    break;

                default:
                    i = 0;
                    break;
                }
            }

            if (((gPlayer[D_801B0820].unk59 != 0) ||
                (gPlayer[D_801B0820].unk5B != 0) ||
                (gPlayer[D_801B0820].unk56 != 0) ||
                (gPlayer[D_801B0820].unk58 != 0)) &&
                ((gPlayer[D_801B0820].unk5A == 0) && (i != 1)))
            {

                if (func_8003779C(0) != 0)
                {
                    if (gPlayer[D_801B0820].unk58 != 0)
                    {
                        if (gPlayer[D_801B0820].unk44 == 0)
                        {
                            s32 temp = -320; /*FAKEMATCH*/
                            D_80119A30[D_801B0820] |= 2;
                            ang1 = (gpSinTable[(gPlayer[D_801B0820].unk38 + 512) & 0x7FF] * temp);
                            ang2 = (gpSinTable[gPlayer[D_801B0820].unk38 & 0x7FF] * temp);
                            gPlayer[D_801B0820].unkC += ang1;
                            gPlayer[D_801B0820].unk10 += ang2;
                            D_8012F914[D_801B0820] = -1;
                            gPlayer[D_801B0820].unk44 = 1;
                            D_801A6AD4[D_801B0820] = 1;
                            gPlayer[D_801B0820].unk58 = 0;
                            D_8011BC44->unk99 = gPlayer[D_801B0820].unk72;
                        }
                    }
                    else if (gPlayer[D_801B0820].unk5B != 0)
                    {
                        gPlayer[D_801B0820].unk14 = CLAMP_MIN((gPlayer[D_801B0820].unk14 - 682), -682);
                    }
                    else if (gPlayer[D_801B0820].unk44 == 0)
                    {
                        if ((D_80119A30[D_801B0820] != 0) || (gPlayer[D_801B0820].unk60 == 0))
                            D_8012F914[D_801B0820] = 6;
                        else
                            D_8012F914[D_801B0820] = 27;

                        gPlayer[D_801B0820].unk44 = 1;
                        D_801A6AD4[D_801B0820] = 1;
                    }
                }
                else
                    gPlayer[D_801B0820].unk44 = 0;
            }
            else if (func_8003779C(0) != 0)
                gPlayer[D_801B0820].unk44 = 1;

            if (D_8012F914[D_801B0820] > 0)
            {
                D_8012F914[D_801B0820]--;
                gPlayer[D_801B0820].unk44 = 1;
            }

            if (D_8012F914[D_801B0820] == 0)
            {
                s32 temp = -0xA00; /*FAKEMATCH*/
                D_8012F914[D_801B0820] = -1;
                gPlayer[D_801B0820].unk14 = temp;
            }
        }
    }

    gPlayer[D_801B0820].zpos += gPlayer[D_801B0820].unk14;

    if (gPlayer[D_801B0820].zpos >= D_80138860)
        gPlayer[D_801B0820].unk59 = 1;
    else
        gPlayer[D_801B0820].unk59 = 0;

    if (D_801A1998 >= gPlayer[D_801B0820].zpos)
    {
        gPlayer[D_801B0820].zpos = D_801A1998;
        if (gPlayer[D_801B0820].unk14 < 0)
            gPlayer[D_801B0820].unk14 = 0x100;
    }

    if (gPlayer[D_801B0820].unk14 > 0)
    {
        if (gPlayer[D_801B0820].zpos >= D_80138860)
        {
            gPlayer[D_801B0820].zpos = D_80138860;

            if ((gPlayer[D_801B0820].unk45 == 0) &&
                ((gpSector[gPlayer[D_801B0820].unk32].unk18 != 1) ||
                    (D_80138860 != D_80129804)))
            {
                if (gPlayer[D_801B0820].unk14 > 0x500)
                    audio_80007820(((krand() % 3) + 1401), gPlayer[D_801B0820].unk4A);

                if (gPlayer[D_801B0820].unk14 > 0xC00)
                {
                    if (gPlayer[D_801B0820].unk14 - 0xC00 < 0)
                        m = gPlayer[D_801B0820].unk14 - 0x801;
                    else
                        m = gPlayer[D_801B0820].unk14 - 0xC00;

                    j = m >> 10; /*TODO?*/
                    j = (j * j) * 2;

                    if (gpSector[gPlayer[D_801B0820].unk32].unk18 == 4)
                        j /= 2;

                    if (gpSector[gPlayer[D_801B0820].unk32].unk18 == 5)
                        j /= 4;

                    if (j >= 11)
                    {
                        audio_80007820(1407, gPlayer[D_801B0820].unk4A);

                        if (j > 75)
                            j = 500;

                        func_8003671C(D_801B0820, j, -1, -2);
                    }
                }
                gPlayer[D_801B0820].unk14 = 0;
            }
        }

        if (gPlayer[D_801B0820].unk58 != 0)
        {
            k = 0x40000000;
            if (gPlayer[D_801B0820].unk5E >= 0x1000)
            {
                k = gpSprite[(s16)(gPlayer[D_801B0820].unk5E - 0x1000)].z -
                    (D_800D52E0[gpSprite[(s16)(gPlayer[D_801B0820].unk5E - 0x1000)].picnum-1280]->unk28 *
                     (gpSprite[(s16)(gPlayer[D_801B0820].unk5E - 0x1000)].yrepeat << 6) / 64) -
                    gPlayer[D_801B0820].unk40;
            }

            k = MIN(D_80138860, k);
            if (gPlayer[D_801B0820].zpos >= k)
            {
                gPlayer[D_801B0820].unk58 = 0;
                D_8011BC44->unk99 = gPlayer[D_801B0820].unk72;
            }
            goto block_98;
        }
    }
    else
    {
    block_98:
        l = 0xC0000000;
        if (gPlayer[D_801B0820].unk58 != 0)
        {
            if (gPlayer[D_801B0820].unk5E < 0x1000)
            {
                if (gpWall[gPlayer[D_801B0820].unk5E].nextsector != -1)
                {
                    l = getFlorzOfSlope(gpWall[gPlayer[D_801B0820].unk5E].nextsector,
                                               gPlayer[D_801B0820].xpos, gPlayer[D_801B0820].ypos);
                }
            }
            else
            {
                l = gpSprite[(s16)(gPlayer[D_801B0820].unk5E - 0x1000)].z -
                    ((D_800D52E0[gpSprite[(s16)(gPlayer[D_801B0820].unk5E - 0x1000)].picnum-1280]->unk2E *
                        (gpSprite[(s16)(gPlayer[D_801B0820].unk5E - 0x1000)].yrepeat << 6)) / 64);
            }

            if ((gPlayer[D_801B0820].zpos + gPlayer[D_801B0820].unk40 / 4) < l)
            {
                gPlayer[D_801B0820].unk58 = 0;
                gPlayer[D_801B0820].unk14 = -0xA00;
                D_8011BC44->unk99 = gPlayer[D_801B0820].unk72;
            }
        }
    }

    if (gPlayer[D_801B0820].unk14 < 0)
    {
        if ((gpSector[gPlayer[D_801B0820].unk32].unk18 == 3) &&
            (gPlayer[D_801B0820].zpos < func_80036490(gPlayer[D_801B0820].unk32)))
        {
            if (gPlayer[D_801B0820].unk54 != 0)
            {
                gPlayer[D_801B0820].zpos = func_80036490(gPlayer[D_801B0820].unk32) - 0x1300;
                gPlayer[D_801B0820].unk14 = 0;
                gPlayer[D_801B0820].unk44 = 1;
                gPlayer[D_801B0820].unk56 = 1;
            }
        }
    }

    if ((gPlayer[D_801B0820].unk59 != 0) && (gPlayer[D_801B0820].unk45 != 0))
    {
        ptr = &D_80197E40[D_80106D50[gPlayer[D_801B0820].unk4A]];
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

    cstat = gpSprite[gPlayer[D_801B0820].unk4A].cstat;
    gpSprite[gPlayer[D_801B0820].unk4A].cstat = cstat & 0xFEFE;
    walldist = 164;

    if (gpSprite[gPlayer[D_801B0820].unk4A].cstat & 0x1000)
    {
        model = D_800D52E0[gpSprite[gPlayer[D_801B0820].unk4A].picnum - 1280];
        walldist = ((model->unk2A - model->unk24) *
                    gpSprite[gPlayer[D_801B0820].unk4A].xrepeat / 64);
        walldist *= 2;
    }

    x = gPlayer[D_801B0820].xpos;
    y = gPlayer[D_801B0820].ypos;
    flordist = CLAMP_MIN((gPlayer[D_801B0820].unk40 - 0x1200), 1024);

    i = clipMove(&gPlayer[D_801B0820].xpos, &gPlayer[D_801B0820].ypos,
                 &gPlayer[D_801B0820].zpos, &gPlayer[D_801B0820].unk32,
                 gPlayer[D_801B0820].unkC, gPlayer[D_801B0820].unk10,
                 walldist, 1024, flordist, 0x10001);

    if (gPlayer[D_801B0820].unk45== 0)
    {
        j = pushMove(&gPlayer[D_801B0820].xpos, &gPlayer[D_801B0820].ypos,
                     &gPlayer[D_801B0820].zpos, &gPlayer[D_801B0820].unk32,
                     walldist, 1024, flordist, 0x10001);

        gpSprite[gPlayer[D_801B0820].unk4A].cstat = cstat;
        if (j == -1)
            func_800365C0(D_801B0820);

        if (i != 0)
        {
            gPlayer[D_801B0820].unkC = (gPlayer[D_801B0820].xpos - x) << 14;
            gPlayer[D_801B0820].unk10 = (gPlayer[D_801B0820].ypos - y) << 14;
            if (i >= 0xC000)
            {
                spritenum = i + 0x4000;
                if ((gpSprite[spritenum].picnum == 1398) || (gpSprite[spritenum].picnum == 1399))
                {
                    if (!(D_8012FD88 & 7))
                        func_8003671C(D_801B0820, 1, -1, -1);
                }
                if (gpSprite[spritenum].statnum == 305)
                {
                    if (gpSprite[spritenum].picnum == 1306)
                        func_800365C0(0);
                }

                if (D_80106D50[spritenum] != -1)
                {
                    if (D_8019B940[D_80106D50[spritenum]].unk4 & 0x8000)
                        D_8019B940[D_80106D50[spritenum]].unk4 |= 0x20000;
                }
            }
        }
        if ((gPlayer[D_801B0820].unk20 > 0) && (gPlayer[D_801B0820].unk54 == 0))
        {
            if ((i >= 0x8000) && (i < 0xC000))
            {
                if (gpWall[i-0x8000].unk14 == 50)
                {
                    gPlayer[D_801B0820].unk72 = D_8011BC44->unk99;
                    gPlayer[D_801B0820].unk5E = i - 0x8000;
                    gPlayer[D_801B0820].unk58 = 1;
                    gPlayer[D_801B0820].unk10 = 0;
                    gPlayer[D_801B0820].unkC = 0;
                    if (D_8011BC44->unk70 != 0)
                        func_80079C20(gPlayer[D_801B0820].unk4A);

                    D_8011BC44->unk99 = 0;
                }
            }
            if (i >= 0xC000)
            {

                if (gpSprite[i-0xC000].statnum == 115)
                {
                    ang = (gpSprite[i - 0xC000].ang + 0x400) & 0x7FF;
                    ang = gPlayer[D_801B0820].unk38 - ang;

                    if (ang < -1024)
                        ang += 2048;
                    if (ang > 1024)
                        ang -= 2048;

                    if (klabs(ang) < 256)
                    {
                        gPlayer[D_801B0820].unk72 = D_8011BC44->unk99;
                        gPlayer[D_801B0820].unk5E = i + 0x5000;
                        gPlayer[D_801B0820].unk58 = 1;
                        gPlayer[D_801B0820].unk10 = 0;
                        gPlayer[D_801B0820].unkC = 0;
                        if (D_8011BC44->unk70 != 0)
                            func_80079C20(gPlayer[D_801B0820].unk4A);

                        D_8011BC44->unk99 = 0;
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
    D_80199970[D_801B0820] = 0;
    if (arg0 < 0)
        arg0 += 24;

    D_8011BC44->unk99 = (D_8011BC44->unk99 + arg0) % 24;
    if ((D_8011BC44->unk99 == 19) || (D_8011BC44->unk99 == 11))
        D_8011BC44->unk99 = (D_8011BC44->unk99 + arg0) % 24;

    while (!(func_80079DE8(D_801B0820, D_8011BC44->unk99)))
    {
        D_8011BC44->unk99 = (D_8011BC44->unk99 + arg0) % 24;
        if ((D_8011BC44->unk99 == 19) || (D_8011BC44->unk99 == 11))
            D_8011BC44->unk99 = (D_8011BC44->unk99 + arg0) % 24;
    }
}

/*8003B5F8*/
STATIC void func_8003B5F8(void);
INCLUDE_ASM("nonmatchings/src/code0/37090", func_8003B5F8);

/*8003DACC*/
void func_8003DACC(void)
{
    f32 f1;
    s32 i;

    D_801AEA10 = (D_801A2790[D_801B0820].unk16 + D_801A2790[D_801B0820].unk1C) * 0.0030679615757714844;
    D_801AC8E0 = (D_801A2790[D_801B0820].unk1A * 0.0030679615757714844);
    if (D_801A2790[D_801B0820].unk14 != 0)
    {
        if (gPlayer[D_801B0820].unk82 != 0)
        {
            f1 = ((gpSinTable[D_801A2790[D_801B0820].unk14] * 0.3) / 16384.0);
            if (gPlayer[D_801B0820].unk82 < 0x1E)
                f1 = (f1 * gPlayer[D_801B0820].unk82) / 30.0f;

            D_801AC8E0 = D_801AC8E0 + f1;
        }
        else
        {
            D_801AC8E0 += (((gpSinTable[D_801A2790[D_801B0820].unk14] * 0.03) / 16384.0));
        }
    }

    i = D_801A2790[D_801B0820].unk18;
    if (i > 0x400)
        i -= 0x800;

    i = i + D_801A2790[D_801B0820].unk1E;
    if (i > 0x400)
        i -= 0x800;

    D_801A6D84 = D_801A2790[D_801B0820].unk0;
    D_800FE3F0 = D_801A2790[D_801B0820].unk4;
    D_80199640 = D_801A2790[D_801B0820].unk8;
    D_8012F6F4 = gPlayer[D_801B0820].unk68;
    D_8016A15C = i * 0.0030679615757714844;
    gMapXpos = (D_801A6D84 / 2);
    gMapYpos = ((D_800FE3F0 /2));
    gMapZpos = D_80199640 / 32;
}

/*8003DD54*/
void func_8003DD54(void)
{
    for (D_801B0820 = 0; D_801B0820 < D_8012C470; D_801B0820++)
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

    if (D_8012C470 < 2)
    {
        if (((gPlayer[D_801B0820].unk58 == 0) && (D_801A6AD4[D_801B0820] != 1)) ||
            ((gPlayer[D_801B0820].unk58 != 0) && (gPlayer[D_801B0820].unk14 != 0)))
        {
            if (gPlayer[D_801B0820].unk54 == 0)
            {
                spritenum = gPlayer[D_801B0820].unk4A;
                ptr = &D_80197E40[D_80106D50[spritenum]];
                if (gPlayer[D_801B0820].unk56 != 0)
                {
                    x = gpSprite[spritenum].x;
                    y = gpSprite[spritenum].y;
                    if (gpSector[gPlayer[D_801B0820].unk32].unk18 == 3)
                        z = func_80036490(gPlayer[D_801B0820].unk32);
                    else
                        z = gpSector[gPlayer[D_801B0820].unk32].floorz;

                    unk38 = gPlayer[D_801B0820].unk38;

                    if (!(D_8012FD88 & 3) && (((krand() & 0xFF) < 0x20) || (D_80119A30[D_801B0820] != 0)))
                    {
                        func_80045400(x, y, z, gpSprite[spritenum].sectnum, 0x78, krand() & 0x7FF, 3, 2);
                    }

                    if (!(D_8012FD88 & 0x1F))
                    {
                        if (!(D_8012FD88 & 0x3F))
                            func_80045400(x, y, z, gpSprite[spritenum].sectnum, 240, (unk38 - 0x100), 3, 3);
                        else
                            func_80045400(x, y, z, gpSprite[spritenum].sectnum, 240, (unk38 + 0x100), 3, 3);

                        if (D_80119A30[D_801B0820] != 0)
                            audio_800077F4(krand() % 4 + 1621, spritenum);
                    }
                }
                else
                {
                    if ((gPlayer[D_801B0820].unk58 != 0) || (D_80119A30[D_801B0820] != 0))
                    {
                        cond = gpSector[gPlayer[D_801B0820].unk32].unk1A & 0xF;
                        if (gPlayer[D_801B0820].unk5A != 0)
                        {
                            cond1 = (D_8012FD88 % 50) == 0;
                            cond2 = (D_8012FD88 % 50) == 25;
                        }
                        else if (gPlayer[D_801B0820].unk58 != 0)
                        {
                            cond1 = ptr->unk2 == 0;
                            cond2 = ptr->unk2 == 15;
                        }
                        else
                        {
                            cond1 = ptr->unk2 == 5;
                            cond2 = ptr->unk2 == 20;
                        }

                        unk18 = gpSector[gPlayer[D_801B0820].unk32].unk18;
                        if (gpSector[gPlayer[D_801B0820].unk32].unk18 == 3)
                        {
                            z = func_80036490(gPlayer[D_801B0820].unk32);
                            if ((gPlayer[D_801B0820].zpos >= (z - gPlayer[D_801B0820].unk40)) &&
                                (gPlayer[D_801B0820].zpos < z))
                            {
                                unk38 = gPlayer[D_801B0820].unk38;
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

                        if (gpSector[gPlayer[D_801B0820].unk32].unk18 == 4)
                        {
                            if (gPlayer[D_801B0820].unk36 < 0x1000)
                            {
                                if ((gPlayer[D_801B0820].unk58 == 0) && (gPlayer[D_801B0820].unk59 != 0))
                                {
                                    unk38 = gPlayer[D_801B0820].unk38;
                                    x = gpSprite[spritenum].x;
                                    y = gpSprite[spritenum].y;
                                    z = gpSprite[spritenum].z;
                                    i = -1;
                                    if (D_80119A30[D_801B0820] & 4)
                                        unk38 = (unk38 + 0x200) & 0x7FF;

                                    if (D_80119A30[D_801B0820] & 8)
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

                        if (gPlayer[D_801B0820].unk36 >= 0x1000)
                        {
                            i = gPlayer[D_801B0820].unk36 - 0x1000;
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
                        if (gPlayer[D_801B0820].unk58 != 0)
                        {
                            if (gPlayer[D_801B0820].unk5E < 0x1000)
                            {
                                if (gpWall[gPlayer[D_801B0820].unk5E].picnum == 3366)
                                    cond = 9;
                                else
                                    cond = 10;
                            }
                            else
                            {
                                switch (gpSprite[gPlayer[D_801B0820].unk5E & 0xFFF].picnum)
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

                        if (gPlayer[D_801B0820].unk5A != 0)
                        {
                            if ((cond == 2) || (cond == 8))
                                cond = 11;
                            else
                                cond = 12;
                        }

                        if (((gPlayer[D_801B0820].unk59 != 0) || (gPlayer[D_801B0820].unk58 != 0)) && (cond1 || cond2))
                        {
                            if (gpSprite[spritenum].picnum == 1533)
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

    j = gPlayer[D_801B0820].unk32;
    if (gPlayer[D_801B0820].unk45 == 0)
    {
        if (gpSector[j].floorstat & 0x80)
        {
            func_8008E01C(30, 1);
            gpSector[j].floorstat &= 0xFF7F;
        }

        if (gpSector[j].floorstat & 0x1000)
        {
            D_800FEA90 = 1;
            func_8008E01C(30, 1);
            gpSector[j].floorstat &= 0xEFFF;
        }

        if (gpSector[j].floorstat & 0x100)
        {
            func_800A419C(D_801B0820, "SECRET AREA");
            gpSector[j].floorstat &= 0xFEFF;
            D_801A1958.secrets_found++;
            playSfx(1595);
            func_801C363C(D_801B0820, 10, 128);
        }

        if (!(gpSector[j].floorstat & 0x200))
        {
            if (gPlayer[D_801B0820].unk5A != 0)
            {
                gPlayer[D_801B0820].unk5A = 0;
                if (gPlayer[D_801B0820].unk6C == 0)
                    gPlayer[D_801B0820].unk60 = gPlayer[D_801B0820].unk61;
            }
        }

        if ((gpSector[j].floorstat & 0x2000) && (D_8011BC44->unk8 > 0) &&
            (D_8011BC44->unk8 < gPlayer[D_801B0820].unk48))
        {
            if (D_800DEE64 == 0)
                D_800DEE64 = playSfx(502);

            if (!(D_8012FD88 & 3))
            {
                D_8011BC44->unk8 = MIN((D_8011BC44->unk8 + 1), gPlayer[D_801B0820].unk48);
                func_8008E3E0(gPlayer[D_801B0820].xpos, gPlayer[D_801B0820].ypos, gpSector[j].floorz, j, 78, 1);
            }
        }
        else
        {
            MusHandleStop(D_800DEE64, 10);
            D_800DEE64 = 0;
        }

        if ((gpSector[j].floorstat & 0x4000) && (gPlayer[D_801B0820].unk59 == 0) && (D_8011BC44->unk8 > 0))
        {
            i = gHeadSpriteStat[121];
            while (i >= 0)
            {
                if (gpSprite[i].sectnum == j)
                    break;

                i = gNextSpriteStat[i];
            }

            k = D_801B0820;
            if (gPlayer[k].zpos >= gpSprite[i].z)
            {
                gPlayer[k].unk45 = 1;
                gPlayer[k].unk4E = 0;
                D_8011BC44->unk8 = 0;
                D_8011BC44->unk9E = 253;
                playSfx(991);
            }
        }

        j = gHeadSpriteStat[118];
        while (j >= 0)
        {
            k = gNextSpriteStat[j];
            if ((gpSprite[j].hitag == 0) && (dist(&gpSprite[j], &gpSprite[gPlayer[D_801B0820].unk4A]) < 1024))
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

