#include "common.h"
#include "code0/main.h"
#include "code0/audio.h"
#include "code0/engine.h"
#include "code0/pragmas.h"
#include "code0/4600.h"
#include "code0/1E7A0.h"
#include "code0/37090.h"
#include "code0/41940.h"
#include "code0/6ACA0.h"
#include "code0/7BA50.h"
#include "code0/8EFE0.h"
#include "code0/A06F0.h"
#include "code0/code0.h"

/*.data*/
/*800DF2F0*/ u8 D_800DF2F0 = 0;
/*800DF2F4*/ s8 D_800DF2F4[MAXSECTORS] = {0};
/*800DF585*/ u8 D_800DF585 = 0;
static s32 _unused[2] = {0};
/*800DF590*/ u8 D_800DF590 = 0;
/*800DF591*/ u8 D_800DF591 = 0;

/*.comm*/
/*8012E15C*/ s16 D_8012E15C;
/*8013B280*/ s16 D_8013B280[40] ALIGNED(8);

/*.text*/
static void func_80068D74(s16 sectnum);

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
                if (gpSprite[j].hitag == gpSprite[i].hitag)
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
static void func_80063A40(s16 playernum, s16 spritenum)
{
    s16 i, j, unk18;
    s16 sectnum1, sectnum2;
    u8 cond;

    sectnum2 = gPlayer[playernum].unk32;
    j = gpSprite[spritenum].unk16;
    sectnum1 = gpSprite[j].sectnum;
    unk18 = gpSector[sectnum2].unk18;

    if (unk18 == 1)
    {
        if ((gPlayer[playernum].zpos ==
            ((getFlorzOfSlope(sectnum2,
                gPlayer[playernum].xpos,
                gPlayer[playernum].ypos) - gPlayer[playernum].unk40) + 0x2600)) &&
            (gPlayer[playernum].unk14 > 256))
        {
            gPlayer[playernum].xpos += (gpSprite[j].x - gpSprite[spritenum].x);
            gPlayer[playernum].ypos += (gpSprite[j].y - gpSprite[spritenum].y);
            D_80138610[playernum] += gpSprite[j].x - gpSprite[spritenum].x;
            D_801AE480[playernum] += gpSprite[j].y - gpSprite[spritenum].y;
            gPlayer[playernum].unk32 = sectnum1;
            D_801A19EC = gpSprite[j].unk25;
            updateSector(gPlayer[playernum].xpos, gPlayer[playernum].ypos, &gPlayer[playernum].unk32);

            gPlayer[playernum].zpos = getCeilzOfSlope(gPlayer[playernum].unk32,
                                                      gPlayer[playernum].xpos,
                                                      gPlayer[playernum].ypos) + 1025;

            gPlayer[playernum].unk14 = gPlayer[playernum].unk14 + 512;
        }
    }
    else if (unk18 == 2)
    {
        if (gPlayer[playernum].zpos ==
            (getCeilzOfSlope(sectnum2,
                gPlayer[playernum].xpos,
                gPlayer[playernum].ypos) + 1024))
        {
            gPlayer[playernum].xpos += (gpSprite[j].x - gpSprite[spritenum].x);
            gPlayer[playernum].ypos += (gpSprite[j].y - gpSprite[spritenum].y);
            D_80138610[playernum] += gpSprite[j].x - gpSprite[spritenum].x;
            D_801AE480[playernum] += gpSprite[j].y - gpSprite[spritenum].y;
            gPlayer[playernum].unk32 = sectnum1;
            updateSector(gPlayer[playernum].xpos, gPlayer[playernum].ypos, &gPlayer[playernum].unk32);

            gPlayer[playernum].zpos = getFlorzOfSlope(gPlayer[playernum].unk32,
                                                      gPlayer[playernum].xpos,
                                                      gPlayer[playernum].ypos) - 4864;

            gPlayer[playernum].unk14 = 0;
            gPlayer[playernum].unk44 = 1;
        }
    }
    else if (gpSprite[spritenum].unk25 != 0)
    {
        cond = 0;
        if (gpSprite[spritenum].cstat & 8)
            cond = gPlayer[playernum].zpos < (gpSprite[spritenum].z - 1);
        else if ((gpSprite[spritenum].z + 1) < gPlayer[playernum].zpos)
            cond = 1;

        if (cond)
        {
            gPlayer[playernum].xpos += (gpSprite[j].x - gpSprite[spritenum].x);
            gPlayer[playernum].ypos += (gpSprite[j].y - gpSprite[spritenum].y);
            gPlayer[playernum].zpos += (gpSprite[j].z - gpSprite[spritenum].z);
            D_80138610[playernum] += gpSprite[j].x - gpSprite[spritenum].x;
            D_801AE480[playernum] += gpSprite[j].y - gpSprite[spritenum].y;

            if (gPlayer[playernum].unk58 != 0)
            {
                for (i = gpSector[sectnum1].wallptr; i < (gpSector[sectnum1].wallptr + gpSector[sectnum1].wallnum); i++)
                {
                    if (gpWall[i].unk14 == 50)
                    {
                        gPlayer[playernum].unk5E = i;
                        goto label1;
                    }
                }

                i = gHeadSpriteSect[sectnum1];
                while (i >= 0)
                {
                    if (gpSprite[i].statnum == 115)
                    {
                        gPlayer[playernum].unk5E = i + 0x1000;
                        goto label1;
                    }
                    i = gNextSpriteSect[i];
                }
                gPlayer[playernum].unk58 = 0;
            }
        label1:
            gPlayer[playernum].unk32 = sectnum1;
            gPlayer[playernum].unk68 = sectnum1;
            updateSector(gPlayer[playernum].xpos, gPlayer[playernum].ypos, &gPlayer[playernum].unk32);
        }
    }
    else
    {
        gPlayer[playernum].xpos = gpSprite[j].x;
        gPlayer[playernum].ypos = gpSprite[j].y;
        gPlayer[playernum].unk38 = gpSprite[j].ang;

        gPlayer[playernum].zpos = getFlorzOfSlope(sectnum1,
                                                  gPlayer[playernum].xpos,
                                                  gPlayer[playernum].ypos) - gPlayer[playernum].unk40;

        gPlayer[playernum].unkC = gPlayer[playernum].unk10 = gPlayer[playernum].unk14 = 0;
        gPlayer[playernum].unk32 = sectnum1;
        updateSector(gPlayer[playernum].xpos, gPlayer[playernum].ypos, &gPlayer[playernum].unk32);
        func_8008E3E0(gpSprite[j].x, gpSprite[j].y, gpSprite[j].z, gpSprite[j].sectnum, 43, 0);
        audio_800077F4(704, j);
        D_800DEEE4[playernum] = 1;
    }
}

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

    if ((gpSprite[spritenum1].statnum == 4) && (gpSprite[spritenum1].lotag == 18))
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
                if (gpSprite[spritenum1].lotag == 18)
                    gpSprite[spritenum1].unk1A = func_8007AE50();

                if (gpSprite[spritenum1].lotag == 21)
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
            *arg0 = gpSprite[i].lotag;
            *arg1 = gpSprite[i].hitag;
            if (*arg1 == 0)
                *arg1 = *arg0;

            break;
        }
        i = gNextSpriteSect[i];
    }
}

/*80064DE0*/
void func_80064DE0(SectorType *sec, s16 x, s16 y)
{
    s16 i;

    sec->unk27 = y;
    sec->unk23 = y;
    sec->unk26 = x;
    sec->unk22 = x;

    for (i = sec->wallptr; i < (sec->wallptr + sec->wallnum); i++)
    {
        gpWall[i].unk21 = y;
        gpWall[i].unk1C = x;
    }
}

/*80064E78*/
void func_80064E78(void)
{
    s32 x2, y2;
    WallType *wall;
    SectorType *sec;
    SpriteType *spr;
    s16 i, j, k, l, m, n, o, nexti;
    u8 cond, cond2, cond3, cond4;
    u16 cstat;

    Bmemset(&D_8013B280, 0, sizeof(D_8013B280));
    D_8012E15C = 0;
    if (D_800DEE98 == 1)
    {
        D_801AC9E8 = 231424;
        D_800DEE98 = 2;

        i = gHeadSpriteStat[101];
        while (i >= 0)
        {
            nexti = gNextSpriteStat[i];
            deleteSprite(i);
            i = nexti;
        }
        i = gHeadSpriteStat[102];
        while (i >= 0)
        {
            nexti = gNextSpriteStat[i];
            deleteSprite(i);
            i = nexti;
        }
        D_8012FC48[0].unk18 = -1;
        D_8012FC48[1].unk18 = -1;
        gSkyTopR = 30;
        gSkyTopG = 30;
        gSkyTopB = 90;
        gSkyBottomR = 30;
        gSkyBottomG = 30;
        gSkyBottomB = 90;
    }
    else if (D_800DEE98 == 2)
    {
        if (D_801AC9E8 > -231424)
            D_801AC9E8 -= 64;

        i = gHeadSpriteStat[102];
        while (i >= 0)
        {
            nexti = gNextSpriteStat[i];
            gpSprite[i].z = D_801AC9E8;
            if (D_801AC9E8 < gpSector[gpSprite[i].sectnum].ceilingz)
            {
                cond = 0;
                if (!(gpSector[gpSprite[i].sectnum].ceilingstat & 1))
                {
                    j = gHeadSpriteSect[gpSprite[i].sectnum];
                    while (j >= 0)
                    {
                        if (gpSprite[j].statnum == 3)
                        {
                            cond = 1;
                            break;
                        }
                        j = gNextSpriteSect[j];

                    }
                }
                if (!cond)
                {
                    gpSector[gpSprite[i].sectnum].unk18 = 2;
                    deleteSprite(i);
                }
            }
            i = nexti;
        }
    }
    i = gHeadSpriteStat[3];
    while (i >= 0)
    {
        nexti = gNextSpriteStat[i];
        spr = &gpSprite[i];
        sec = &gpSector[spr->sectnum];

        switch (spr->lotag)
        {
        case 0:
            func_80064D30(&m, &n, spr->sectnum);
            m = (spr->unk18 * m) / 128;
            spr->ang = (spr->ang + m) & 0x7FF;
            func_80005118(spr->sectnum, spr->ang, spr->x, spr->y);

            k = spr->unk16;
            for (l = sec->wallptr; l < (sec->wallptr + sec->wallnum); l++)
            {
                rotatePoint(0, 0, D_801AD480[k], D_80105730[k], spr->ang, &x2, &y2);
                dragPoint(l, spr->x + x2, spr->y + y2);
                k++;
            }

            for (k = 0; k < D_8012C470; k++)
            {
                if (gPlayer[k].unk59 != 0)
                {
                    if (gPlayer[k].unk32 == spr->sectnum)
                    {
                        gPlayer[k].unk38 = (gPlayer[k].unk38 + m) & 0x7FF;
                        rotatePoint(spr->x, spr->y, gPlayer[k].xpos, gPlayer[k].ypos, m, &x2, &y2);
                        gPlayer[k].xpos = x2;
                        gPlayer[k].ypos = y2;
                    }
                }
            }
            break;
        case 4:
            if (spr->ang < (D_80168D0C % 2048))
            {
                x2 = spr->unk24;
                y2 = spr->unk25;
            }
            else
            {
                x2 = spr->unk1A;
                y2 = spr->unk1C;
            }
            func_80064DE0(sec, x2, y2);
            break;
        case 10:
            if (spr->unk18 != 0)
            {
                spr->unk18--;
                if (spr->unk18 == 0)
                    func_8006CB38(spr->sectnum);
            }
            break;
        case 12:
            if (spr->unk2B != 0)
            {
                switch (spr->unk18)
                {
                case 0:
                    if (spr->clipdist == 0)
                    {
                        x2 = spr->unk1A;
                        y2 = spr->unk1C;
                    }
                    else
                    {
                        x2 = spr->unk24;
                        y2 = spr->unk25;
                    }

                    m = sec->unk26 + (x2 - sec->unk26) / 4;

                    if (m < x2)
                        m++;

                    if (x2 < m)
                        m--;

                    func_80064DE0(sec, m, y2);
                    if (m == x2)
                        spr->unk2B = 0;
                    break;
                case 1:
                    if (spr->clipdist == 0)
                        func_80064DE0(sec, spr->unk1A, spr->unk1C);
                    else
                        func_80064DE0(sec, spr->unk24, spr->unk25);
                    spr->unk2B = 0;
                    break;
                case 2:
                    if (spr->clipdist == 0)
                    {
                        func_80064DE0(sec, spr->unk1A, spr->unk1C);
                        spr->unk2B = 0;
                        break;
                    }
                    spr->unk2B++;
                    spr->unk22 += D_80168D0C % 128;
                    if (spr->unk22 > 0x100)
                    {
                        x2 = spr->unk24;
                        spr->unk22 = 0;
                        y2 = spr->unk25;
                    }
                    else
                    {
                        x2 = spr->unk1A;
                        y2 = spr->unk1C;
                    }
                    if (spr->unk2B >= 30)
                    {
                        func_80064DE0(sec, spr->unk24, spr->unk25);
                        spr->unk2B = 0;
                        break;
                    }

                    func_80064DE0(sec, x2, y2);
                    break;
                case 3:
                    if ((spr->ang < (D_80168D0C % 2048)) && (spr->clipdist != 0))
                    {
                        x2 = spr->unk24;
                        y2 = spr->unk25;
                    }
                    else
                    {
                        x2 = spr->unk1A;
                        y2 = spr->unk1C;
                    }
                    func_80064DE0(sec, x2, y2);
                    if (spr->clipdist == 0)
                        spr->unk2B = 0;
                    break;
                }
            }
            break;
        case 8:
            if (gpSprite[spr->unk16].lotag >= 50)
            {
                if (gpSprite[spr->unk16].lotag < 53)
                    y2 = gpSector[gpSprite[spr->unk16].sectnum].floorz - gpSector[gpSprite[spr->unk16].sectnum].ceilingz;
                else if (gpSprite[spr->unk16].lotag < 55)
                    y2 = gpSprite[spr->unk16].unk1A;
            }

            if (spr->z == 0)
                x2 = 0;
            else
                x2 = (y2 << 8) / spr->z;

            y2 = spr->unk1A + ((spr->unk24 - spr->unk1A) * x2) / 256;

            if (x2 > 0)
                x2 = spr->unk25;
            else
                x2 = spr->unk1C;

            func_80064DE0(sec, y2, x2);
            break;
        case 13:
            if (spr->unk25 == 1)
            {
                s32 a, b;
                a = (spr->unk18 << 16) + (spr->unk1A & 0xFFFF);
                b = (spr->unk1C << 16) + (spr->unk22 & 0xFFFF);
                sec->floorz = a;
                sec->ceilingz = b;
                sec->floorheinum = spr->ang;
                sec->ceilingheinum = spr->unk16;
                x2 = a;
                y2 = b;
                D_800DF2F4[spr->sectnum] |= 3;
                func_8004FAD8(i);
                deleteSprite(i);
            }
            break;
        case 29:
            y2 = mulscale12(spr->unk18, gpSinTable[spr->ang]);
            spr->ang = (spr->ang + spr->unk1A) & 0x7FF;
            x2 = mulscale12(spr->unk18, gpSinTable[spr->ang]);

            if ((spr->cstat & 8) == 0)
            {
                for (k = 0; k < D_8012C470; k++)
                {
                    if (gPlayer[k].unk59 != 0)
                    {
                        if (gPlayer[k].unk36 == spr->sectnum)
                            gPlayer[k].zpos = gPlayer[k].zpos + (x2 - y2);
                    }
                }
                o = gHeadSpriteSect[spr->sectnum];
                while (o >= 0)
                {
                    if (gpSprite[o].z == sec->floorz)
                    {
                        if (gpSprite[o].picnum > 48)
                            gpSprite[o].z = spr->z + x2;
                    }
                    o = gNextSpriteSect[o];
                }
            }

            if ((sec->unk18 == 3) && !(spr->cstat & 4))
            {
                o = gHeadSpriteSect[spr->sectnum];
                while (o >= 0)
                {
                    if (gpSprite[o].picnum == 15)
                    {
                        gpSprite[o].z = spr->z + x2;
                        break;
                    }
                    o = gNextSpriteSect[o];
                }
            }
            else if (spr->cstat & 8)
            {
                sec->ceilingz = spr->z + x2;
                D_800DF2F4[spr->sectnum] |= 2;
            }
            else
            {
                sec->floorz = spr->z + x2;
                D_800DF2F4[spr->sectnum] |= 1;
            }
            break;
        case 30:
            if (spr->unk2B != 0)
            {
                if (spr->unk1C == 0)
                {
                    if (sec->ceilingz >= spr->z)
                        spr->unk1C = -1;
                    else
                        spr->unk1C = 1;
                }
                func_80064D30(&m, &n, spr->sectnum);

                if (spr->unk1C > 0)
                    spr->unk1C = MIN(spr->unk1C, (spr->z - sec->ceilingz));

                if (spr->unk1C < 0)
                    spr->unk1C = MAX(spr->unk1C, (spr->z - sec->ceilingz));

                sec->ceilingz += spr->unk1C;
                if (spr->unk1C > 0)
                {
                    spr->unk1C = MIN(m, (spr->unk1C + n));

                    if (sec->ceilingz >= spr->z)
                    {
                        sec->ceilingz = spr->z;
                        spr->z = (spr->unk18 << 16) + (spr->unk1A & 0xFFFF);
                        spr->unk18 = sec->ceilingz >> 16;
                        spr->unk1A = sec->ceilingz;
                        spr->unk1C = 0;
                        spr->unk2B = 0;
                    }

                    D_800DF2F4[spr->sectnum] |= 2;
                }

                if (spr->unk1C < 0)
                {
                    spr->unk1C = MAX(-m, (spr->unk1C - n));

                    if (sec->ceilingz <= spr->z)
                    {
                        sec->ceilingz = spr->z;
                        spr->z = (spr->unk18 << 16) + (spr->unk1A & 0xFFFF);
                        spr->unk18 = sec->ceilingz >> 16;
                        spr->unk1A = sec->ceilingz;
                        spr->unk1C = 0;
                        spr->unk2B = 0;
                    }
                    D_800DF2F4[spr->sectnum] |= 2;
                }
            }
            break;
        case 40:
            if (spr->unk2B != 0)
            {
                func_80064D30(&m, &n, spr->sectnum);
                if (spr->unk1C > 0)
                    spr->unk1C = MIN(spr->unk1C, (spr->z - sec->floorz));

                if (spr->unk1C < 0)
                    spr->unk1C = MAX(spr->unk1C, (spr->z - sec->floorz));

                for (k = 0; k < D_8012C470; k++)
                {
                    if (gPlayer[k].unk32 == spr->sectnum)
                        gPlayer[k].zpos += spr->unk1C;
                }

                o = gHeadSpriteSect[spr->sectnum];
                while (o >= 0)
                {
                    if (gpSprite[o].picnum > 48)
                    {
                        if ((*(s32 *)&gpSprite[o].cstat & 0x40300000) != 0x40100000)
                            gpSprite[o].z += spr->unk1C;
                    }
                    o = gNextSpriteSect[o];
                }

                if (sec->floorz < spr->z)
                {
                    sec->floorz += spr->unk1C;
                    spr->unk1C = MIN(m, (spr->unk1C + n));

                    if (sec->floorz >= spr->z)
                    {
                        sec->floorz = spr->z;
                        spr->z = gpSector[nextSectorNeighborZ(spr->sectnum, spr->z, 1, 0)].floorz;
                        spr->unk1C = 0;
                        spr->unk2B = 0;
                    }
                    D_800DF2F4[spr->sectnum] |= 1;
                }

                if (sec->floorz > spr->z)
                {
                    sec->floorz += spr->unk1C;
                    spr->unk1C = MAX(-m, (spr->unk1C - n));

                    if (sec->floorz <= spr->z)
                    {
                        sec->floorz = spr->z;
                        spr->z = gpSector[nextSectorNeighborZ(spr->sectnum, spr->z, 1, 1)].floorz;
                        spr->unk1C = 0;
                        spr->unk2B = 0;
                    }
                    D_800DF2F4[spr->sectnum] |= 1;
                }
            }
            break;
        case 41:
            if (spr->unk2B != 0)
            {
                func_80064D30(&m, &n, spr->sectnum);
                if (spr->unk1C > 0)
                    spr->unk1C = MIN(spr->unk1C, (spr->z - sec->floorz));

                if (spr->unk1C < 0)
                    spr->unk1C = MAX(spr->unk1C, (spr->z - sec->floorz));

                for (k = 0; k < D_8012C470; k++)
                {
                    if (gPlayer[k].unk32 == spr->sectnum)
                        gPlayer[k].zpos += spr->unk1C;
                }

                o = gHeadSpriteSect[spr->sectnum];
                while (o >= 0)
                {
                    if (gpSprite[o].picnum > 48)
                        gpSprite[o].z += spr->unk1C;
                    o = gNextSpriteSect[o];
                }

                if (sec->floorz < spr->z)
                {
                    sec->floorz += spr->unk1C;
                    sec->ceilingz += spr->unk1C;
                    spr->unk1C = MIN(m, (spr->unk1C + n));

                    if (sec->floorz >= spr->z)
                    {
                        sec->floorz = spr->z;
                        spr->z = gpSector[nextSectorNeighborZ(spr->sectnum, spr->z, 1, 0)].floorz;
                        spr->unk1C = 0;
                        spr->unk2B = 0;
                    }
                    D_800DF2F4[spr->sectnum] |= 3;
                }

                if (sec->floorz > spr->z)
                {
                    sec->floorz += spr->unk1C;
                    sec->ceilingz += spr->unk1C;
                    spr->unk1C = MAX(-m, (spr->unk1C - n));

                    if (sec->floorz <= spr->z)
                    {
                        sec->floorz = spr->z;
                        spr->z = gpSector[nextSectorNeighborZ(spr->sectnum, spr->z, 1, 1)].floorz;
                        spr->unk1C = 0;
                        spr->unk2B = 0;
                    }
                    D_800DF2F4[spr->sectnum] |= 3;
                }
            }
            break;
        case 42:
            if (spr->unk2B != 0)
            {
                if (spr->unk1C == 0)
                {
                    if (sec->floorz >= spr->z)
                        spr->unk1C = -1;
                    else
                        spr->unk1C = 1;
                }
                func_80064D30(&m, &n, spr->sectnum);

                if (spr->unk1C > 0)
                    spr->unk1C = MIN(spr->unk1C, (spr->z - sec->floorz));

                if (spr->unk1C < 0)
                    spr->unk1C = MAX(spr->unk1C, (spr->z - sec->floorz));

                for (k = 0; k < D_8012C470; k++)
                {
                    if (gPlayer[k].unk32 == spr->sectnum)
                        gPlayer[k].zpos += spr->unk1C;
                }

                o = gHeadSpriteSect[spr->sectnum];
                while (o >= 0)
                {
                    if (gpSprite[o].picnum > 48)
                    {
                        if ((*(s32 *)&gpSprite[o].cstat & 0x40300000) != 0x40100000)
                            gpSprite[o].z += spr->unk1C;
                    }
                    o = gNextSpriteSect[o];
                }

                sec->floorz += spr->unk1C;
                if (spr->unk1C > 0)
                {
                    spr->unk1C = MIN(m, (spr->unk1C + n));

                    if (sec->floorz >= spr->z)
                    {
                        sec->floorz = spr->z;
                        spr->z = (spr->unk18 << 16) + (spr->unk1A & 0xFFFF);
                        spr->unk18 = sec->floorz >> 16;
                        spr->unk1A = sec->floorz;
                        spr->unk1C = 0;
                        spr->unk2B = 0;
                    }
                    D_800DF2F4[spr->sectnum] |= 1;
                }

                if (spr->unk1C < 0)
                {
                    spr->unk1C = MAX(-m, (spr->unk1C - n));
                    if (sec->floorz <= spr->z)
                    {
                        sec->floorz = spr->z;
                        spr->z = (spr->unk18 << 16) + (spr->unk1A & 0xFFFF);
                        spr->unk18 = sec->floorz >> 16;
                        spr->unk1A = sec->floorz;
                        spr->unk1C = 0;
                        spr->unk2B = 0;
                    }
                    D_800DF2F4[spr->sectnum] |= 1;
                }
            }
            break;
        case 43:
            if ((spr->unk2B != 0) && (spr->unk25 == 0))
            {
                i = gpSprite[spr->unk16].sectnum;
                if (spr->unk1C == 0)
                {
                    if (sec->floorz >= spr->z)
                        spr->unk1C = -1;
                    else
                        spr->unk1C = 1;

                    spr->clipdist = 0;
                }
                x2 = (spr->unk18 << 16) + (spr->unk1A & 0xFFFF);
                func_80064D30(&m, &n, spr->sectnum);
                cond2 = 0;
                if (spr->unk1C > 0)
                {
                    spr->unk1C = MIN(spr->unk1C, (spr->z - sec->floorz));
                    if (((spr->z + x2) / 2) < sec->floorz)
                        cond2 = 1;
                }

                if (spr->unk1C < 0)
                {
                    spr->unk1C = MAX(spr->unk1C, (spr->z - sec->floorz));
                    if (sec->floorz < ((spr->z + x2)/2))
                        cond2 = 1;
                }

                if (cond2 != 0)
                {
                    if (spr->clipdist != 0)
                        cond2 = 0;
                    else
                    {
                        spr->clipdist = 1;
                        gpSprite[spr->unk16].clipdist = 1;
                        spr->unk25 = spr->unk25 == 0;
                        gpSprite[spr->unk16].unk25 = gpSprite[spr->unk16].unk25 == 0;
                    }
                }

                for (k = 0; k < D_8012C470; k++)
                {
                    if (gPlayer[k].unk32 == spr->sectnum)
                    {
                        gPlayer[k].zpos += spr->unk1C;
                        if (cond2)
                        {
                            gPlayer[k].xpos += (gpSprite[spr->unk16].x - spr->x);
                            gPlayer[k].ypos += (gpSprite[spr->unk16].y - spr->y);
                            D_80138610[k] += gpSprite[spr->unk16].x - spr->x;
                            D_801AE480[k] += gpSprite[spr->unk16].y - spr->y;
                            gPlayer[k].unk32 = i;
                            updateSector(gPlayer[k].xpos, gPlayer[k].ypos, &gPlayer[k].unk32);
                            gPlayer[k].unk68 = i;
                        }
                    }
                }

                o = gHeadSpriteSect[spr->sectnum];
                while (o >= 0)
                {
                    k = gNextSpriteSect[o];
                    if (gpSprite[o].picnum > 48)
                    {
                        gpSprite[o].z += spr->unk1C;
                        if (cond2)
                        {
                            gpSprite[o].x += gpSprite[spr->unk16].x - spr->x;
                            gpSprite[o].y += gpSprite[spr->unk16].y - spr->y;
                            changeSpriteSect(o, i);
                        }
                    }
                    o = k;
                }

                sec->floorz += spr->unk1C;
                sec->ceilingz += spr->unk1C;
                gpSector[i].floorz = sec->floorz;
                gpSector[i].ceilingz = sec->ceilingz;
                D_800DF2F4[i] |= 3;

                if (spr->unk1C > 0)
                {
                    spr->unk1C = MIN(m, (spr->unk1C + n));
                    gpSprite[spr->unk16].unk1C = spr->unk1C;
                    if (sec->floorz >= spr->z)
                    {
                        spr->z = (spr->unk18 << 16) + (spr->unk1A & 0xFFFF);
                        x2 = spr->z;
                        spr->unk18 = sec->floorz >> 16;
                        spr->unk1A = sec->floorz;
                        spr->unk1C = 0;
                        spr->unk2B = 0;
                        gpSprite[spr->unk16].z = x2;
                        gpSprite[spr->unk16].unk18 = sec->floorz >> 16;
                        gpSprite[spr->unk16].unk1A = sec->floorz;
                        gpSprite[spr->unk16].unk1C = 0;
                        gpSprite[spr->unk16].unk2B = 0;
                    }
                    D_800DF2F4[spr->sectnum] |= 3;
                }

                if (spr->unk1C < 0)
                {
                    spr->unk1C = MAX(-m, (spr->unk1C - n));
                    gpSprite[spr->unk16].unk1C = spr->unk1C;
                    if (sec->floorz <= spr->z)
                    {
                        spr->z = (spr->unk18 << 16) + (spr->unk1A & 0xFFFF);
                        x2 = spr->z;
                        spr->unk18 = sec->floorz >> 16;
                        spr->unk1A = sec->floorz;
                        spr->unk1C = 0;
                        spr->unk2B = 0;
                        gpSprite[spr->unk16].z = x2;
                        gpSprite[spr->unk16].unk18 = sec->floorz >> 16;
                        gpSprite[spr->unk16].unk1A = sec->floorz;
                        gpSprite[spr->unk16].unk1C = 0;
                        gpSprite[spr->unk16].unk2B = 0;
                    }
                    D_800DF2F4[spr->sectnum] |= 3;
                }
            }
            break;
        case 44:
        case 46:
            if (spr->unk2B != 0)
            {
                x2 = (spr->unk18 << 16) + (spr->unk1A & 0xFFFF);
                y2 = gpSprite[spr->unk16].z;
                if (spr->unk1C == 0)
                {
                    if (y2 >= x2)
                        spr->unk1C = -1;
                    else
                        spr->unk1C = 1;
                }
                func_80064D30(&m, &n, spr->sectnum);

                if (spr->unk1C > 0)
                    spr->unk1C = MIN(spr->unk1C, (x2 - y2));

                if (spr->unk1C < 0)
                    spr->unk1C = MAX(spr->unk1C, (spr->z - y2));

                for (k = 0; k < D_8012C470; k++)
                {
                    if (y2 >= gPlayer[k].zpos)
                    {
                        if (gPlayer[k].unk59 != 0)
                        {
                            if (gPlayer[k].unk32 == spr->sectnum)
                                gPlayer[k].zpos += spr->unk1C;
                        }
                    }
                }

                o = gHeadSpriteSect[spr->sectnum];
                while (o >= 0)
                {
                    if (gpSprite[o].picnum > 48)
                    {
                        if (y2 >= gpSprite[o].z)
                        {
                            if ((*(s32 *)&gpSprite[o].cstat & 0x40300000) != 0x40100000)
                                gpSprite[o].z += spr->unk1C;
                        }
                    }
                    o = gNextSpriteSect[o];
                }

                if (spr->unk1C > 0)
                {
                    spr->unk1C = MIN(m, (spr->unk1C + n));

                    if (gpSprite[spr->unk16].z >= x2)
                    {
                        gpSprite[spr->unk16].z = x2;
                        spr->unk1C = 0;
                        spr->unk2B = 0;
                        if (spr->lotag == 46)
                        {
                            MusHandleStop(D_801A19F0, 0);
                            playSfx(1600);
                            func_8001F7B4(10, 15);
                            o = gHeadSpriteSect[spr->sectnum];
                            while (o >= 0)
                            {
                                if ((gpSprite[o].picnum >= 2548) && (gpSprite[o].picnum < 2552))
                                    changeSpriteStat(o, 0);

                                o = gNextSpriteSect[o];
                            }
                        }
                    }
                }

                if (spr->unk1C < 0)
                {
                    spr->unk1C = MAX(-m, (spr->unk1C - n));

                    if (gpSprite[spr->unk16].z <= spr->z)
                    {
                        gpSprite[spr->unk16].z = spr->z;
                        spr->unk1C = 0;
                        spr->unk2B = 0;
                    }
                }
            }
            break;
        case 45:
            if (spr->unk2B != 0)
            {
                if (spr->unk25 == 0)
                {
                    spr->unk18++;
                    if (spr->unk18 == 1)
                    {
                        D_800DF590 = 0;
                        D_800DF591 = 1;
                        func_8006B590((spr->hitag + 1));
                        D_800DF590 = 0;
                        D_800DF591 = 0;
                    }

                    if (spr->unk18 == 60)
                    {
                        s8 a;
                        a = func_8006B170((spr->hitag + 1));
                        if (a == 0)
                            spr->unk18 = 0;

                        if (a == 1)
                        {
                            for (k = 0; k < D_8012C470; k++)
                            {
                                if (gPlayer[k].unk32 == spr->sectnum)
                                {
                                    gPlayer[k].xpos = gPlayer[k].xpos + (gpSprite[spr->unk16].x - spr->x);
                                    gPlayer[k].ypos = gPlayer[k].ypos + (gpSprite[spr->unk16].y - spr->y);
                                    gPlayer[k].zpos = gPlayer[k].zpos + (gpSprite[spr->unk16].z - spr->z);
                                    D_80138610[k] += gpSprite[spr->unk16].x - spr->x;
                                    D_801AE480[k] += gpSprite[spr->unk16].y - spr->y;
                                    gPlayer[k].unk32 = gpSprite[spr->unk16].sectnum;
                                    updateSector(gPlayer[k].xpos, gPlayer[k].ypos, &gPlayer[k].unk32);
                                    o = gHeadSpriteSect[spr->sectnum];
                                    while (o >= 0)
                                    {
                                        x2 = gNextSpriteSect[o];
                                        if (gpSprite[o].picnum > 48)
                                        {
                                            gpSprite[o].x += gpSprite[spr->unk16].x - spr->x;
                                            gpSprite[o].y += gpSprite[spr->unk16].y - spr->y;
                                            gpSprite[o].z += gpSprite[spr->unk16].z - spr->z;
                                            changeSpriteSect(o, gpSprite[spr->unk16].sectnum);
                                        }
                                        o = x2;
                                    }
                                }
                                else
                                {
                                    if (gPlayer[k].unk32 == gpSprite[spr->unk16].sectnum)
                                    {
                                        gPlayer[k].xpos = gPlayer[k].xpos + (spr->x - gpSprite[spr->unk16].x);
                                        gPlayer[k].ypos = gPlayer[k].ypos + (spr->y - gpSprite[spr->unk16].y);
                                        gPlayer[k].zpos = gPlayer[k].zpos + (spr->z - gpSprite[spr->unk16].z);
                                        D_80138610[k] += spr->x - gpSprite[spr->unk16].x;
                                        D_801AE480[k] += spr->y - gpSprite[spr->unk16].y;
                                        gPlayer[k].unk32 = spr->sectnum;
                                        updateSector(gPlayer[k].xpos, gPlayer[k].ypos, &gPlayer[k].unk32);
                                        o = gHeadSpriteSect[gpSprite[spr->unk16].sectnum];
                                        while (o >= 0)
                                        {
                                            x2 = gNextSpriteSect[o];
                                            if (gpSprite[o].picnum > 48)
                                            {
                                                gpSprite[o].x += spr->x - gpSprite[spr->unk16].x;
                                                gpSprite[o].y += spr->y - gpSprite[spr->unk16].y;
                                                gpSprite[o].z += spr->z - gpSprite[spr->unk16].z;
                                                changeSpriteSect(o, spr->sectnum);
                                            }
                                            o = x2;
                                        }
                                    }
                                }
                            }
                        }
                    }

                    if (spr->unk18 == ((spr->unk24 * 30) + 60))
                    {
                        D_800DF590 = 1;
                        D_800DF591 = 0;
                        func_8006B590((spr->hitag + 1));
                        D_800DF590 = 0;
                        D_800DF591 = 0;
                    }
                    if (spr->unk18 >= ((((spr->unk24 * 16) - spr->unk24) * 2) + 120))
                    {
                        spr->unk2B = 0;
                        spr->unk18 = 0;
                    }
                }
            }
            break;
        case 50:
            if (spr->unk1C != 0)
            {
                func_80064D30(&m, &n, spr->sectnum);
                if (spr->unk1C > 0)
                {
                    sec->ceilingz += spr->unk1C;
                    spr->unk1C = MIN(m, (spr->unk1C + n));

                    if (sec->ceilingz >= sec->floorz)
                    {
                        sec->ceilingz = sec->floorz;
                        spr->unk1C = 0;
                        func_80063930(spr->sectnum);
                    }

                    D_800DF2F4[spr->sectnum] |= 2;
                }
                if (spr->unk1C < 0)
                {
                    sec->ceilingz += spr->unk1C;
                    spr->unk1C = MAX(-m, (spr->unk1C - n));
                    if (sec->ceilingz <= spr->z)
                    {
                        sec->ceilingz = spr->z;
                        func_80068D74(spr->sectnum);
                        spr->unk1C = 0;
                    }
                    D_800DF2F4[spr->sectnum] |= 2;
                }
            }
            break;
        case 51:
            if (spr->unk1C != 0)
            {
                func_80064D30(&m, &n, spr->sectnum);
                if (spr->unk1C < 0)
                {
                    sec->floorz += spr->unk1C;
                    sec->ceilingz -= spr->unk1C;

                    spr->unk1C = MAX(-m, (spr->unk1C - n));

                    if (sec->floorz <= sec->ceilingz)
                    {
                        sec->floorz = sec->ceilingz;
                        spr->unk1C = 0;
                    }

                    D_800DF2F4[spr->sectnum] |= 3;
                }

                if (spr->unk1C > 0)
                {
                    sec->floorz += spr->unk1C;
                    sec->ceilingz -= spr->unk1C;

                    spr->unk1C = MIN(m, (spr->unk1C + n));
                    if (sec->floorz >= spr->z)
                    {
                        sec->floorz = spr->z;
                        func_80068D74(spr->sectnum);
                        spr->unk1C = 0;
                    }

                    D_800DF2F4[spr->sectnum] |= 3;
                }
            }
            break;
        case 52:
            if (spr->unk1C != 0)
            {
                func_80064D30(&m, &n, spr->sectnum);
                if (spr->unk1C < 0)
                {
                    sec->floorz += spr->unk1C;
                    spr->unk1C = MAX(-m, (spr->unk1C - n));

                    if (sec->floorz <= sec->ceilingz)
                    {
                        sec->floorz = sec->ceilingz;
                        spr->unk1C = 0;
                    }

                    D_800DF2F4[spr->sectnum] |= 1;
                }

                if (spr->unk1C > 0)
                {
                    sec->floorz += spr->unk1C;
                    spr->unk1C = MIN(m, (spr->unk1C + n));

                    if (sec->floorz >= spr->z)
                    {
                        sec->floorz = spr->z;
                        func_80068D74(spr->sectnum);
                        spr->unk1C = 0;
                    }

                    D_800DF2F4[spr->sectnum] |= 1;
                }
            }
            break;
        case 53:
            if (spr->unk18 != 0)
            {
                func_80064D30(&m, &n, spr->sectnum);
                m = m / 128;
                n = MAX((n /128), 1);

                if (spr->unk18 > 0)
                    spr->unk18 = MIN(m, (spr->unk18 + n));
                else
                    spr->unk18 = MAX(-m, (spr->unk18 - n));

                spr->ang += spr->unk18;
                spr->unk1A += spr->unk18;

                if (spr->unk1A > 0x200)
                {
                    spr->ang -= (spr->unk1A - 0x200);
                    spr->unk1A = 0x200;
                }

                if (spr->unk1A < 0)
                {
                    spr->ang -= spr->unk1A;
                    spr->unk1A = 0;
                }

                spr->ang &= 0x7FF;
                func_80005118(spr->sectnum, spr->ang, spr->x, spr->y);

                k = spr->unk16;
                for (l = sec->wallptr; l < (sec->wallptr + sec->wallnum); l++)
                {
                    rotatePoint(0, 0, D_801AD480[k], D_80105730[k], spr->ang, &x2, &y2);
                    dragPoint(l, spr->x + x2, spr->y + y2);
                    k++;
                }

                o = gHeadSpriteSect[spr->sectnum];
                while (o >= 0)
                {
                    if (gpSprite[o].picnum > 48)
                    {
                        gpSprite[o].ang = (gpSprite[o].ang + spr->unk18) & 0x7FF;
                        rotatePoint(spr->x, spr->y, gpSprite[o].x, gpSprite[o].y, spr->unk18, &x2, &y2);
                        gpSprite[o].x = x2;
                        gpSprite[o].y = y2;
                    }
                    o = gNextSpriteSect[o];
                }

                for (k = 0; k < D_8012C470; k++)
                {
                    if ((gPlayer[k].unk59 != 0) && (gPlayer[k].unk32 == spr->sectnum))
                    {
                        gPlayer[k].unk38 = (gPlayer[k].unk38 + spr->unk18) & 0x7FF;
                        rotatePoint(spr->x, spr->y, gPlayer[k].xpos, gPlayer[k].ypos, spr->unk18, &x2, &y2);
                        gPlayer[k].xpos = x2;
                        gPlayer[k].ypos = y2;
                    }

                    for (o = sec->wallptr; o < (sec->wallptr + sec->wallnum); o++)
                    {
                        if (clipInsideBox(gPlayer[k].xpos, gPlayer[k].ypos, o, 164) != 0)
                        {
                            D_8013B280[D_8012E15C++] = i;
                            break;
                        }
                    }
                }

                if (((spr->unk1A >= 0x200) && (spr->unk18 > 0)) || ((spr->unk1A <= 0) && (spr->unk18 < 0)))
                {
                    spr->unk18 = 0;
                    spr->unk25 = spr->unk25 == 0;
                    if (spr->unk25 != 0)
                        func_80068D74(spr->sectnum);
                }
            }
            break;
        case 54:
            if (spr->unk18 != 0)
            {
                func_80064D30(&m, &n, spr->sectnum);
                m = m / 16;
                n = MAX((n /16), 1);

                if (spr->unk18 > 0)
                    spr->unk18 = MIN(m, (spr->unk18 + n));
                else
                    spr->unk18 = MAX(-m, (spr->unk18 - n));

                spr->unk1A += spr->unk18;
                if (spr->unk1A > spr->unk1C)
                {
                    spr->unk18 -= (spr->unk1A  - spr->unk1C);
                    spr->unk1A = spr->unk1C;
                }

                if (spr->unk1A < 0)
                {
                    spr->unk18 -= spr->unk1A;
                    spr->unk1A = 0;
                }

                x2 = (spr->unk18 * gpSinTable[(spr->ang + 0x200) & 0x7FF]) / 16384;
                y2 = (spr->unk18 * gpSinTable[spr->ang]) / 16384;
                spr->x += x2;
                spr->y += y2;
                func_80005118(spr->sectnum, 0, spr->x, spr->y);

                k = spr->unk16;
                for (l = sec->wallptr; l < (sec->wallptr + sec->wallnum); l++)
                {
                    dragPoint(l, spr->x + D_801AD480[k], spr->y + D_80105730[k]);
                    k++;
                }

                for (k = 0; k < D_8012C470; k++)
                {
                    if ((gPlayer[k].unk59 != 0) && (gPlayer[k].unk32 == spr->sectnum))
                    {
                        gPlayer[k].xpos += x2;
                        gPlayer[k].ypos += y2;
                    }

                    if (spr->clipdist == 0)
                    {
                        for (l = sec->wallptr; l < (sec->wallptr + sec->wallnum); l++)
                        {
                            if (clipInsideBox(gPlayer[k].xpos, gPlayer[k].ypos, l, 164) != 0)
                            {
                                D_8013B280[D_8012E15C++] = i;
                                spr->clipdist = 1;
                                break;
                            }
                        }
                    }
                }

                if ((spr->unk1A >= spr->unk1C) || (spr->unk1A <= 0))
                {
                    spr->unk25 = spr->unk25 == 0;
                    spr->unk18 = 0;
                    spr->clipdist = 0;
                    if (spr->unk25 != 0)
                        func_80068D74(spr->sectnum);
                }
            }
            break;
        case 60:
            if (spr->unk2B != 0)
            {
                if (gMapNum == MAP_GOING_DOWN_THE_RACK)
                {
                    D_801AC9E8 = MIN(D_801AC9E8, spr->z);
                    spr->unk2B = 0;
                }
                else
                {
                    func_80064D30(&m, &n, spr->sectnum);
                    cond2 = 0;
                    spr->unk1C = MIN(m, (spr->unk1C + n));

                    o = gHeadSpriteStat[102];
                    while (o >= 0)
                    {
                        if (gpSprite[o].hitag == spr->hitag)
                        {
                            if (spr->unk25 != 0)
                                gpSprite[o].z = MIN(spr->z, (gpSprite[o].z + spr->unk1C));
                            else
                                gpSprite[o].z = MAX(spr->z, (gpSprite[o].z - spr->unk1C));

                            if (gpSprite[o].z == spr->z)
                                cond2 = 1;
                        }
                        o = gNextSpriteStat[o];
                    }

                    if (cond2 != 0)
                    {
                        spr->unk25 = 1 - spr->unk25;
                        spr->unk2B = 0;
                        spr->unk1C = 0;
                        x2 = (spr->unk18 << 16) + (spr->unk1A & 0xFFFF);
                        spr->unk18 = spr->z >> 16;
                        spr->unk1A = spr->z;
                        spr->z = x2;
                    }
                }
            }
            break;
        case 24:
            if (spr->unk2B != 0)
            {
                for (k = 0; k < D_8012C470; k++)
                {
                    if (gPlayer[k].unk32 == spr->sectnum)
                    {
                        if (gPlayer[k].unk45 == 0)
                        {
                            cond3 = 0;
                            switch (spr->unk25)
                            {
                            case 0:
                                cond3 = 1;
                                break;
                            case 1:
                                if (gPlayer[k].unk59 != 0)
                                    cond3 = 1;
                                break;
                            case 2:
                                if (gpSprite[gPlayer[k].unk4A].z > func_80036490(gPlayer[k].unk32))
                                    cond3 = 1;
                                break;
                            }

                            if (cond3 != 0)
                            {
                                s32 a, b, c;
                                a = spr->unk24 * gpSinTable[(spr->ang + 0x200) & 0x7FF];
                                b = spr->unk24 * gpSinTable[spr->ang & 0x7FF];

                                c = CLAMP_MIN((gPlayer[k].unk40 - 0x1200), 0x400);
                                clipMove(&gPlayer[k].xpos,
                                        &gPlayer[k].ypos,
                                        &gPlayer[k].zpos,
                                        &gPlayer[k].unk32,
                                        a, b, 164, 0x400, c, 0x10001);
                            }
                        }
                    }
                }
            }
            break;
        }
        i = nexti;
    }
    D_800DF2F0 = 1;

    for (k = 0; k < D_8012C470; k++)
    {
        sec = &gpSector[gPlayer[k].unk32];
        i = gHeadSpriteSect[gPlayer[k].unk32];
        while (i>= 0)
        {
            spr = &gpSprite[i];
            cond4 = 0;
            if (spr->picnum == 1)
            {
                switch (spr->lotag)
                {
                case 50:
                    cond4 = spr->unk1C > 0;
                    break;
                case 51:
                case 52:
                    cond4 = spr->unk1C < 0;
                    break;
                }

                if (cond4 != 0)
                {
                    if ((sec->floorz - sec->ceilingz) < (gPlayer[k].unk40 + 0x400))
                    {
                        audio_800077F4(1325, gPlayer[k].unk4A);
                        if (spr->hitag != 0)
                            func_8006B590(spr->hitag);
                        else
                        {
                            func_8006CB38(spr->sectnum);
                            func_80063930(spr->sectnum);
                        }
                    }
                }
            }
            i = gNextSpriteSect[i];
        }
    }

    for (i = 0; i < D_8012E15C; i++)
    {
        spr = &gpSprite[D_8013B280[i]];
        k = 0;
        if (spr->hitag != 0)
        {
            for (o = 0; o < i; o++)
            {
                if (spr->hitag == gpSprite[D_8013B280[o]].hitag)
                {
                    k = 1;
                    break;
                }
            }
            if (k == 0)
                func_8006B590(spr->hitag);
        }
        else
            func_8006CB38(spr->sectnum);
    }

    D_800DF2F0 = 0;

    for (k = 0; k < D_8012C470; k++)
    {
        if (gPlayer[k].unk45 == 0)
        {
            s16 a;
            cstat = gpSprite[gPlayer[k].unk4A].cstat;
            gpSprite[gPlayer[k].unk4A].cstat = cstat & 0xFEFE;
            x2 = CLAMP_MIN((gPlayer[k].unk40 - 0x1200), 0x400);
            a = pushMove(&gPlayer[k].xpos,
                                  &gPlayer[k].ypos,
                                  &gPlayer[k].zpos,
                                  &gPlayer[k].unk32,
                                  0xA4, 0x400, x2, 0x10001);
            gpSprite[gPlayer[k].unk4A].cstat = cstat;
            if (a == -1)
            {
                func_800365C0(k);
                D_8019B940[D_80106D50[gPlayer[k].unk4A]].unk8 = 0;
            }
        }
    }

    i = gHeadSpriteStat[3];
    while (i >= 0)
    {
        spr = &gpSprite[i];
        if (spr->lotag == 29)
        {
            if (spr->unk25 != 0)
            {
                sec = &gpSector[spr->sectnum];
                if (sec->wallnum == 4)
                {
                    wall = &gpWall[sec->wallptr+2];
                    if (spr->cstat & 8)
                    {
                        alignCeilSlope(spr->sectnum, wall->x, wall->y, gpSector[wall->nextsector].ceilingz);
                        D_800DF2F4[spr->sectnum] |= 2;
                    }
                    else
                    {
                        alignFlorSlope(spr->sectnum, wall->x, wall->y, gpSector[wall->nextsector].floorz);
                        D_800DF2F4[spr->sectnum] |= 1;
                    }
                }
            }
        }
        i = gNextSpriteStat[i];
    }
}

/*80068D74*/
static void func_80068D74(s16 sectnum)
{
    s16 i;

    i = gHeadSpriteSect[sectnum];
    while (i >= 0)
    {
        if (gpSprite[i].picnum == 1)
        {
            if (gpSprite[i].lotag == 10)
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
            if (gpSprite[i].lotag == 10)
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
                        func_8006B590(gpSprite[i].lotag);
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
            for (j = 0; j < ARRAY_COUNT(sp10.unk0); j++)
            {
                k = gHeadSpriteStat[sp10.unk0[j]];
                while (k >= 0)
                {
                    if ((gpSprite[k].picnum >= 49) && (gpSprite[i].lotag == gpSprite[k].hitag))
                        goto label1;
                    k = gNextSpriteStat[k];
                }
            }
            if (l == 0)
            {
                func_8006B590(gpSprite[i].hitag);
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
                    if (spr->hitag != 0)
                        func_8006B590(spr->hitag);
                    else
                        func_8006CB38(spr->sectnum);

                    spr->unk24 = 1;
                    if ((spr->lotag > 0) && (--spr->lotag == 0))
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
        if ((gpSprite[i].hitag == 0) && (gpSprite[i].picnum == 29))
        {
            cond = 0;
            for (j = 0; j < D_8012C470; j++)
            {
                if (gPlayer[j].unk32 == gpSprite[i].sectnum)
                    cond = 1;
            }

            if (cond)
            {
                audio_80008574(0, gpSprite[i].lotag);
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
void func_800698E8(void)
{
    SpriteType *spr;
    s32 t2, t4;
    s32 k, l;
    s16 i, j, nexti;
    s16 t3;
    u16 t1;

    i = gHeadSpriteStat[666];
    while (i >= 0)
    {
        spr = &gpSprite[i];
        nexti = gNextSpriteStat[i];
        if ((spr->picnum == 2267) || (spr->picnum == 2268))
        {
            if ((gPlayer[0].unk50 >= 0) && (gPlayer[0].unk5C == 0) &&
                (func_80040D40(spr->x, spr->y, gPlayer[0].xpos, gPlayer[0].ypos) < 0x200))
            {
                audio_800077F4((krand() & 1) | 1364, i);
                func_8003671C(0, 25, -1, -1);
                deleteSprite(i);
            }
        }
        else
        {
            spr->unk1A++;
            if (spr->unk1A >= spr->lotag)
                spr->unk1A = 0;

            if (spr->unk1A == 0)
            {
                if (spr->unk1C == 1)
                {
                    for (j = 0; j < D_8012C470; j++)
                    {
                        if (gPlayer[j].unk32 == spr->sectnum)
                        {
                            switch (spr->unk22)
                            {
                            case 0:
                                if (gPlayer[j].unk59 != 0)
                                {
                                    if (gPlayer[j].unk36 == gPlayer[j].unk32)
                                        func_800697D8(j, spr->unk18, spr->unk2A);
                                }
                                break;

                            case 1:
                                k = klabs(((gpSector[gPlayer[j].unk32].floorz - gpSprite[gPlayer[j].unk4A].z)));
                                k = 0x4000 - k;
                                if (k > 0)
                                    func_800697D8(j, (k * spr->unk18) / 0x4000, spr->unk2A);
                                break;

                            case 2:
                                func_800697D8(j, spr->unk18, spr->unk2A);
                                break;

                            case 3:
                                if (gpSprite[gPlayer[j].unk4A].z > func_80036490(gPlayer[j].unk32))
                                    func_800697D8(j, spr->unk18, spr->unk2A);
                                break;
                            }
                        }
                    }
                }
                else
                {
                    for (j = 0; j < D_8012C470; j++)
                    {
                        l = func_80040D94(gpSprite[gPlayer[j].unk4A].x,
                                          gpSprite[gPlayer[j].unk4A].y,
                                          gpSprite[gPlayer[j].unk4A].z / 16,
                                          spr->x, spr->y, spr->z / 16);

                        if (l < spr->unk22)
                        {
                            l = spr->unk22 - l;
                            func_800697D8(j, (l * spr->unk18) / spr->unk22, spr->unk2A);
                        }
                    }

                }
            }

            if (spr->unk2B != 0)
            {
                if ((gpSector[spr->sectnum].unk18 == 2) ||
                    ((gpSector[spr->sectnum].unk18 == 3) && (func_80036490(spr->sectnum) < spr->z)))
                {
                    spr->xrepeat--;
                    spr->yrepeat--;
                    if ((spr->xrepeat == 0) || (spr->yrepeat == 0))
                        deleteSprite(i);
                }
                else
                {
                    /*FAKEMATCH*/
                    do
                    {
                        t1 = spr->unk16;
                        t2 = t1 << 16;
                        t3 = t1 & 0xFF;
                    } while (0);

                    if (t2 != 0)
                    {
                        t4 = t2 >> 24;
                        if (spr->xrepeat < t4)
                            spr->xrepeat++;
                        if (spr->yrepeat < t3)
                            spr->yrepeat++;
                        if ((spr->xrepeat == t4) && (spr->yrepeat == t3))
                            spr->unk16 = 0;
                    }
                }
            }
        }
        i = nexti;
    }
}

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
