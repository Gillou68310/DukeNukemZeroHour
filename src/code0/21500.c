#include "common.h"
#include "code0/9410.h"
#include "code0/main.h"
#include "code0/pragmas.h"

/*.comm*/
/*800FE3F8*/ f32 D_800FE3F8;
/*80105710*/ f32 D_80105710;
/*80106D34*/ f32 D_80106D34;
/*80118154*/ f32 D_80118154;
/*8011824C*/ f32 D_8011824C;
/*80118254*/ f32 D_80118254;
/*80119A60*/ f32 D_80119A60;
/*8012FD90*/ f32 D_8012FD90;
/*80138770*/ f32 D_80138770;
/*80138774*/ f32 D_80138774;
/*8013877C*/ f32 D_8013877C;
/*80138814*/ f32 D_80138814;
/*80168CA0*/ f32 D_80168CA0;
/*80168D00*/ f32 D_80168D00;
/*80168D14*/ u16 D_80168D14; /*tilenum*/
/*80199104*/ f32 D_80199104;
/*80199568*/ f32 D_80199568;
/*801A1984*/ s32 D_801A1984;
/*801ACBE4*/ f32 D_801ACBE4;

/*.text*/
STATIC s32 func_80021464(s32 sectnum, s32 wallnum);
static s32 func_80022C30(s32 sectnum, s32 wallnum);

/*80020900*/
static void func_80020900(u16 tileid)
{
    f32 sizex, dimx, sizey, dimy;
    u16 tilenum;

    tilenum = getTileNum(tileid);
    sizex = gpTileInfo[tilenum].sizex;
    dimx = gpTileInfo[tilenum].dimx;
    sizey = gpTileInfo[tilenum].sizey;
    dimy = gpTileInfo[tilenum].dimy;
    D_80168D14 = tilenum;
    D_80105710 = sizex;
    D_80118254 = dimx;
    D_80199568 = sizey;
    D_80138774 = dimy;
    D_80106D34 = sizex / dimx;
    D_80119A60 = sizey / dimy;
}

/*800209BC*/
static void func_800209BC(u16 wallnum, s16 arg1)
{
    D_80138770 = gpWall[wallnum].unk22 / D_80106D34;
    D_8011824C = gpWall[wallnum].unk24 / D_80106D34;
    D_8013877C = (gpWall[wallnum].unk23 / D_80119A60) / 4.0f;

    if (arg1 & 0x100)
    {
        D_80199104 = (0xFF - gpWall[wallnum].unk25);
        D_80199104 = (D_80138774 / 256.0f) * D_80199104;
    }
    else
    {
        D_80199104 = (gpWall[wallnum].unk25);
        D_80199104 = (D_80138774 / 256.0f) * D_80199104;
        D_8013877C = -D_8013877C;
    }

    D_80168D00 = D_80199104;

    if (arg1 & 4)
        D_80168D00 = (D_80138774 * 32.0f) + (D_80199104 * 32.0f);
    else
        D_80168D00 = D_80199104 * 32.0f;

    D_8012FD90 = D_8011824C * 32.0f;
    D_800FE3F8 = (D_80138770 * 8.0f * 32.0f) + D_8012FD90;
}

/*80020BA0*/
static void func_80020BA0(u16 wallnum, s16 arg1)
{
    D_80138770 = gpWall[wallnum].unk22 / D_80106D34;
    D_8011824C = gpWall[gpWall[wallnum].nextwall].unk24 / D_80106D34;
    D_8013877C = (gpWall[wallnum].unk23 / D_80119A60) / 4.0f;

    if (arg1 & 0x100)
    {
        D_80199104 = (0xFF - gpWall[gpWall[wallnum].nextwall].unk25);
        D_80199104 = (D_80138774 / 256.0f) * D_80199104;
    }
    else
    {
        D_80199104 = gpWall[gpWall[wallnum].nextwall].unk25;
        D_80199104 = (D_80138774 / 256.0f) * D_80199104;
        D_8013877C = -D_8013877C;
    }

    D_80168D00 = D_80199104;

    if (arg1 & 4)
        D_80168D00 = (D_80138774 * 32.0f) + (D_80199104 * 32.0f);
    else
        D_80168D00 = D_80199104 * 32.0f;

    D_8012FD90 = D_8011824C * 32.0f;
    D_800FE3F8 = (D_80138770 * 8.0f * 32.0f) + D_8012FD90;
}

/*80020DC4*/
static void func_80020DC4(s16 arg0)
{
    f32 f1, prev;
    s32 i;

    if (arg0 & 8)
    {
        prev = D_8012FD90;
        D_8012FD90 = D_800FE3F8;
        D_800FE3F8 = prev;
    }
    f1 = MIN(D_801ACBE4, MIN(D_80168CA0, MIN(D_80138814, D_80118154)));
    if (f1 < -32760.0f)
    {
        i = f1 - (-32760.0f);
        i = ((i + 0xFFF) & ~0xFFF);
        D_801ACBE4 += i;
        D_80168CA0 += i;
        D_80138814 += i;
        D_80118154 += i;
    }
    f1 = MAX(D_801ACBE4, MAX(D_80168CA0, MAX(D_80138814, D_80118154)));
    if (f1 > 32760.0f)
    {
        i = f1 - 32760.0f;
        i = ((i + 0xFFF) & ~0xFFF);
        D_801ACBE4 -= i;
        D_80168CA0 -= i;
        D_80138814 -= i;
        D_80118154 -= i;
    }
}

/*800211D0*/
static void func_800211D0(s32 arg0)
{
    f32 f1, prev;
    s32 i;

    if (arg0 & 8)
    {
        prev = D_8012FD90;
        D_8012FD90 = D_800FE3F8;
        D_800FE3F8 = prev;
    }
    f1 = MIN(D_801ACBE4, D_80168CA0);
    if (f1 < -32760.0f)
    {
        i = klabs(f1) - 32760.0f;
        i = ((i + 0xFFF) & ~0xFFF);
        D_801ACBE4 += i;
        D_80168CA0 += i;
        D_80138814 += i;
        D_80118154 += i;
    }
    f1 = MAX(D_801ACBE4, D_80168CA0);
    if (f1 > 32760.0f)
    {
        i = f1 - 32760.0f;
        i = ((i + 0xFFF) & ~0xFFF);
        D_801ACBE4 -= i;
        D_80168CA0 -= i;
        D_80138814 -= i;
        D_80118154 -= i;
    }
}

/*800213B8*/
u8 func_800213B8(s32 sectnum, s32 wallnum)
{
    s16 nextsector;
    u16 stat;
    s32 ret;

    stat = gpSector[sectnum].floorstat;
    nextsector = gpWall[wallnum].nextsector;
    stat |= gpSector[sectnum].ceilingstat;
    if (nextsector != -1)
    {
        stat |= gpSector[nextsector].floorstat;
        stat |= gpSector[nextsector].ceilingstat;
    }

    if (!(stat & 2))
        ret = func_80022C30(sectnum, wallnum);
    else
        ret = func_80021464(sectnum, wallnum);

    return ret;
}

/*80021464*/
INCLUDE_ASM("nonmatchings/src/code0/21500", func_80021464);

/*800226C0*/
s32 func_800226C0(u16 wallnum)
{
    s32 x1, y1, z1;
    s32 x2, y2, z2;
    s32 floorz1, floorz2;
    s32 ceilz1, ceilz2;
    u16 i;
    u8 ret;
    u16 cstat;

    ret = 0;
    i = 0;
    D_801A1984 = 0;

    x1 = gpWall[wallnum].x;
    y1 = gpWall[wallnum].y;
    x2 = gpWall[gpWall[wallnum].point2].x;
    y2 = gpWall[gpWall[wallnum].point2].y;
    ceilz1 = getCeilzOfSlope(gpWall[wallnum].unk1A, x1, y1) >> 4;
    ceilz2 = getCeilzOfSlope(gpWall[wallnum].unk1A, x2, y2) >> 4;
    z1 = getCeilzOfSlope(gpWall[wallnum].nextsector, x1, y1) >> 4;
    z2 = getCeilzOfSlope(gpWall[wallnum].nextsector, x2, y2) >> 4;

    if (ceilz1 < z1)
    {
        ceilz1 = z1;
        ceilz2 = z2;
    }

    floorz1 = getFlorzOfSlope(gpWall[wallnum].unk1A, x1, y1) >> 4;
    floorz2 = getFlorzOfSlope(gpWall[wallnum].unk1A, x2, y2) >> 4;
    z1 = getFlorzOfSlope(gpWall[wallnum].nextsector, x1, y1) >> 4;
    z2 = getFlorzOfSlope(gpWall[wallnum].nextsector, x2, y2) >> 4;

    if (z1 < floorz1)
    {
        floorz1 = z1;
        floorz2 = z2;
    }

    if (!(gpWall[wallnum].cstat & 4))
    {
        z1 = MAX((gpSector[gpWall[wallnum].unk1A].ceilingz >> 4),
                 (gpSector[gpWall[wallnum].nextsector].ceilingz >> 4));
        cstat = gpWall[wallnum].cstat & 0xFFFB;
    }
    else
    {
        z1 = MIN((gpSector[gpWall[wallnum].unk1A].floorz >> 4),
                 (gpSector[gpWall[wallnum].nextsector].floorz >> 4));
        cstat = gpWall[wallnum].cstat & 0xFFFB;
    }

    func_80020900(gpWall[wallnum].overpicnum);
    func_800209BC(wallnum, cstat);
    ret |= 4;
    D_801ACBE4 = ((z1 - ceilz1) * D_8013877C) + D_80168D00;
    D_80168CA0 = ((z1 - floorz1) * D_8013877C) + D_80168D00;
    D_80138814 = ((z1 - floorz2) * D_8013877C) + D_80168D00;
    D_80118154 = ((z1 - ceilz2) * D_8013877C) + D_80168D00;
    func_80020DC4(cstat);

    D_800FE950[i].ob[0] = x1 >> 1;
    D_800FE950[i].ob[2] = ceilz1 >> 1;
    D_800FE950[i].ob[1] = y1 >> 1;
    D_800FE950[i].tc[0] = (s32)D_8012FD90;
    D_800FE950[i].tc[1] = (s32)D_801ACBE4;
    i++;

    D_800FE950[i].ob[0] = x1 >> 1;
    D_800FE950[i].ob[2] = floorz1 >> 1;
    D_800FE950[i].ob[1] = y1 >> 1;
    D_800FE950[i].tc[0] = (s32)D_8012FD90;
    D_800FE950[i].tc[1] = (s32)D_80168CA0;
    i++;

    D_800FE950[i].ob[0] = x2 >> 1;
    D_800FE950[i].ob[2] = floorz2 >> 1;
    D_800FE950[i].ob[1] = y2 >> 1;
    D_800FE950[i].tc[0] = (s32)D_800FE3F8;
    D_800FE950[i].tc[1] = (s32)D_80138814;
    i++;

    D_800FE950[i].ob[0] = x2 >> 1;
    D_800FE950[i].ob[2] = ceilz2 >> 1;
    D_800FE950[i].ob[1] = y2 >> 1;
    D_800FE950[i].tc[0] = (s32)D_800FE3F8;
    D_800FE950[i].tc[1] = (s32)D_80118154;

    D_801A1984++;
    return ret;
}

/*80022C30*/
static s32 func_80022C30(s32 sectnum, s32 wallnum)
{
    s32 x2, y2, z2;
    s32 x1, y1, z1;
    s32 z, m, l;
    s32 nextsector;
    s16 cstat;
    u16 i;
    u8 ret;

    nextsector = gpWall[wallnum].nextsector;
    i = 0;
    D_801A1984 = 0;
    ret = 0;

    if (nextsector == -1)
    {
        z1 = gpSector[sectnum].ceilingz >> 4;
        z2 = gpSector[sectnum].floorz >> 4;

        if (z1 == z2)
            return 0;

        x1 = gpWall[wallnum].x;
        y1 = gpWall[wallnum].y;
        x2 = gpWall[gpWall[wallnum].point2].x;
        y2 = gpWall[gpWall[wallnum].point2].y;

        if (gpWall[wallnum].cstat & 4)
            z = z2;
        else
            z = z1;

        func_80020900(gpWall[wallnum].picnum);
        func_800209BC(wallnum, gpWall[wallnum].cstat);
        D_801ACBE4 = ((z - z1) * D_8013877C) + D_80168D00;
        D_80168CA0 = ((z - z2) * D_8013877C) + D_80168D00;
        func_800211D0(gpWall[wallnum].cstat);

        D_800FE950[0].ob[0] = x1 >> 1;
        D_800FE950[0].ob[2] = z1 >> 1;
        D_800FE950[0].ob[1] = y1 >> 1;
        D_800FE950[0].tc[0] = (s32)D_8012FD90;
        D_800FE950[0].tc[1] = (s32)D_801ACBE4;

        D_800FE950[1].ob[0] = x1 >> 1;
        D_800FE950[1].ob[2] = z2 >> 1;
        D_800FE950[1].ob[1] = y1 >> 1;
        D_800FE950[1].tc[0] = (s32)D_8012FD90;
        D_800FE950[1].tc[1] = (s32)D_80168CA0;

        D_800FE950[2].ob[0] = x2 >> 1;
        D_800FE950[2].ob[2] = z2 >> 1;
        D_800FE950[2].ob[1] = y2 >> 1;
        D_800FE950[2].tc[0] = (s32)D_800FE3F8;
        D_800FE950[2].tc[1] = (s32)D_80168CA0;

        D_800FE950[3].ob[0] = x2 >> 1;
        D_800FE950[3].ob[2] = z1 >> 1;
        D_800FE950[3].ob[1] = y2 >> 1;
        D_800FE950[3].tc[0] = (s32)D_800FE3F8;
        D_800FE950[3].tc[1] = (s32)D_801ACBE4;

        D_801A1984++;
        return 8;
    }

    if (!(gpWall[wallnum].cstat & 0x400))
    {
        z1 = gpSector[sectnum].ceilingz >> 4;
        z2 = gpSector[nextsector].ceilingz >> 4;
        if (z1 < z2)
        {
            x1 = gpWall[wallnum].x;
            y1 = gpWall[wallnum].y;
            x2 = gpWall[gpWall[wallnum].point2].x;
            y2 = gpWall[gpWall[wallnum].point2].y;

            if (gpWall[wallnum].cstat & 4)
            {
                z = z1;
                cstat = gpWall[wallnum].cstat & ~4;
            }
            else
            {
                z = z2;
                cstat = gpWall[wallnum].cstat | 4;
            }

            func_80020900(gpWall[wallnum].picnum);
            func_800209BC(wallnum, cstat);
            ret |= 1;
            D_801ACBE4 = ((z - z1) * D_8013877C) + D_80168D00;
            D_80168CA0 = ((z - z2) * D_8013877C) + D_80168D00;
            func_800211D0(cstat);

            D_800FE950[i].ob[0] = x1 >> 1;
            D_800FE950[i].ob[2] = z1 >> 1;
            D_800FE950[i].ob[1] = y1 >> 1;
            D_800FE950[i].tc[0] = (s32)D_8012FD90;
            D_800FE950[i].tc[1] = (s32)D_801ACBE4;
            i++;

            D_800FE950[i].ob[0] = x1 >> 1;
            D_800FE950[i].ob[2] = z2 >> 1;
            D_800FE950[i].ob[1] = y1 >> 1;
            D_800FE950[i].tc[0] = (s32)D_8012FD90;
            D_800FE950[i].tc[1] = (s32)D_80168CA0;
            i++;

            D_800FE950[i].ob[0] = x2 >> 1;
            D_800FE950[i].ob[2] = z2 >> 1;
            D_800FE950[i].ob[1] = y2 >> 1;
            D_800FE950[i].tc[0] = (s32)D_800FE3F8;
            D_800FE950[i].tc[1] = (s32)D_80168CA0;
            i++;

            D_800FE950[i].ob[0] = x2 >> 1;
            D_800FE950[i].ob[2] = z1 >> 1;
            D_800FE950[i].ob[1] = y2 >> 1;
            D_800FE950[i].tc[0] = (s32)D_800FE3F8;
            D_800FE950[i].tc[1] = (s32)D_801ACBE4;
            i++;
            D_801A1984++;
        }
    }

    if (!(gpWall[wallnum].cstat & 0x800))
    {
        z1 = gpSector[gpWall[wallnum].nextsector].floorz >> 4;
        z2 = gpSector[sectnum].floorz >> 4;
        if (z1 < z2)
        {
            x1 = gpWall[wallnum].x;
            y1 = gpWall[wallnum].y;
            x2 = gpWall[gpWall[wallnum].point2].x;
            y2 = gpWall[gpWall[wallnum].point2].y;
            if (gpWall[wallnum].cstat & 2)
            {
                func_80020900(gpWall[gpWall[wallnum].nextwall].picnum);

                if (gpWall[gpWall[wallnum].nextwall].cstat & 4)
                {
                    cstat = gpWall[wallnum].cstat;
                    z = gpSector[sectnum].ceilingz >> 4;
                    func_80020BA0(wallnum, gpWall[gpWall[wallnum].nextwall].cstat & ~4);
                }
                else
                {
                    cstat = gpWall[wallnum].cstat;
                    z = gpSector[gpWall[wallnum].nextsector].floorz >> 4;
                    func_80020BA0(wallnum, gpWall[gpWall[wallnum].nextwall].cstat & ~4);
                }
            }
            else
            {
                cstat = gpWall[wallnum].cstat & ~4;

                if (gpWall[wallnum].cstat & 4)
                    z = gpSector[sectnum].ceilingz >> 4;
                else
                    z = z1;

                func_80020900(gpWall[wallnum].picnum);
                func_800209BC(wallnum, cstat);
            }

            D_801ACBE4 = ((z - z1) * D_8013877C) + D_80168D00;
            D_80168CA0 = ((z - z2) * D_8013877C) + D_80168D00;
            func_800211D0(cstat);
            ret |= 2;

            D_800FE950[i].ob[0] = x1 >> 1;
            D_800FE950[i].ob[2] = z1 >> 1;
            D_800FE950[i].ob[1] = y1 >> 1;
            D_800FE950[i].tc[0] = (s32)D_8012FD90;
            D_800FE950[i].tc[1] = (s32)D_801ACBE4;
            i++;

            D_800FE950[i].ob[0] = x1 >> 1;
            D_800FE950[i].ob[2] = z2 >> 1;
            D_800FE950[i].ob[1] = y1 >> 1;
            D_800FE950[i].tc[0] = (s32)D_8012FD90;
            D_800FE950[i].tc[1] = (s32)D_80168CA0;
            i++;

            D_800FE950[i].ob[0] = x2 >> 1;
            D_800FE950[i].ob[2] = z2 >> 1;
            D_800FE950[i].ob[1] = y2 >> 1;
            D_800FE950[i].tc[0] = (s32)D_800FE3F8;
            D_800FE950[i].tc[1] = (s32)D_80168CA0;
            i++;

            D_800FE950[i].ob[0] = x2 >> 1;
            D_800FE950[i].ob[2] = z1 >> 1;
            D_800FE950[i].ob[1] = y2 >> 1;
            D_800FE950[i].tc[0] = (s32)D_800FE3F8;
            D_800FE950[i].tc[1] = (s32)D_801ACBE4;
            i++;
            D_801A1984++;
        }
    }

    if (gpWall[wallnum].cstat & 0x20)
    {
        x1 = gpWall[wallnum].x;
        y1 = gpWall[wallnum].y;
        x2 = gpWall[gpWall[wallnum].point2].x;
        y2 = gpWall[gpWall[wallnum].point2].y;
        z1 = getCeilzOfSlope(gpWall[wallnum].nextsector, x1, y1) >> 4;
        z2 = getFlorzOfSlope(gpWall[wallnum].nextsector, x1, y1) >> 4;

        if (gpWall[wallnum].cstat & 4)
        {
            z = gpSector[sectnum].ceilingz >> 4;
            cstat = gpWall[wallnum].cstat & ~4;
        }
        else
        {
            z = gpSector[gpWall[wallnum].nextsector].floorz >> 4;
            cstat = gpWall[wallnum].cstat & ~4;
        }

        func_80020900(gpWall[wallnum].overpicnum);
        func_800209BC(wallnum, cstat);
        ret |= 4;
        D_801ACBE4 = ((z - z1) * D_8013877C) + D_80168D00;
        D_80168CA0 = ((z - z2) * D_8013877C) + D_80168D00;
        func_800211D0(cstat);

        D_800FE950[i].ob[0] = x1 >> 1;
        D_800FE950[i].ob[2] = z1 >> 1;
        D_800FE950[i].ob[1] = y1 >> 1;
        D_800FE950[i].tc[0] = (s32)D_8012FD90;
        D_800FE950[i].tc[1] = (s32)D_801ACBE4;
        i++;

        D_800FE950[i].ob[0] = x1 >> 1;
        D_800FE950[i].ob[2] = z2 >> 1;
        D_800FE950[i].ob[1] = y1 >> 1;
        D_800FE950[i].tc[0] = (s32)D_8012FD90;
        D_800FE950[i].tc[1] = (s32)D_80168CA0;
        i++;

        D_800FE950[i].ob[0] = x2 >> 1;
        D_800FE950[i].ob[2] = z2 >> 1;
        D_800FE950[i].ob[1] = y2 >> 1;
        D_800FE950[i].tc[0] = (s32)D_800FE3F8;
        D_800FE950[i].tc[1] = (s32)D_80168CA0;
        i++;

        D_800FE950[i].ob[0] = x2 >> 1;
        D_800FE950[i].ob[2] = z1 >> 1;
        D_800FE950[i].ob[1] = y2 >> 1;
        D_800FE950[i].tc[0] = (s32)D_800FE3F8;
        D_800FE950[i].tc[1] = (s32)D_801ACBE4;

        D_801A1984++;
        return ret;
    }

    if (!(gpWall[wallnum].cstat & 0x10))
        return ret;

    x1 = gpWall[wallnum].x;
    y1 = gpWall[wallnum].y;
    x2 = gpWall[gpWall[wallnum].point2].x;
    y2 = gpWall[gpWall[wallnum].point2].y;

    m = klabs((D_801A6D84 - ((x1 + x2) / 2)));
    l = klabs((D_800FE3F0 - ((y1 + y2) / 2)));

    D_8012BC70[D_80138830].unk4 = MAX(m, l) + (MIN(m, l) >> 2) + (MIN(m, l) >> 3);
    D_8012BC70[D_80138830].unk0 = wallnum | 0x8000;
    D_80138830++;
    return ret;
}
