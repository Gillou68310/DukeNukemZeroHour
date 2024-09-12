#include "common.h"
#include "code0/9410.h"
#include "code0/main.h"
#include "code0/pragmas.h"

/*.comm*/
/*800FE950*/ VertexC gWallVertex[12] ALIGNED(8);
/*800FE3F8*/ f32 _globalWallU2;
/*80105710*/ f32 _globalTileSizeX;
/*80106D34*/ f32 _globalTileScaleX;
/*80118154*/ f32 _globalWallV4;
/*8011824C*/ f32 _globalXpanning;
/*80118254*/ f32 _globalTileDimX;
/*80119A60*/ f32 _globalTileScaleY;
/*8012FD90*/ f32 _globalWallU1;
/*80138770*/ f32 _globalXrepeat;
/*80138774*/ f32 _globalTileDimY;
/*8013877C*/ f32 _globalYrepeat;
/*80138814*/ f32 _globalWallV3;
/*80168CA0*/ f32 _globalWallV2;
/*80168D00*/ f32 _globalWallVoffset;
/*80168D14*/ u16 _globalTileId;
/*80199104*/ f32 _globalYpanning;
/*80199568*/ f32 _globalTileSizeY;
/*801A1984*/ s32 _wallPolyCount;
/*801ACBE4*/ f32 _globalWallV1;

/*.text*/
static s32 _wallCalcSlope(s32 sectnum, s32 wallnum);
static s32 _wallCalcNoSlope(s32 sectnum, s32 wallnum);

/*80020900*/
static void _setTileGlobals(u16 tilenum)
{
    f32 sizex, dimx, sizey, dimy;
    u16 tileid;

    tileid = getTileId(tilenum);
    sizex = gpTileInfo[tileid].sizex;
    dimx = gpTileInfo[tileid].dimx;
    sizey = gpTileInfo[tileid].sizey;
    dimy = gpTileInfo[tileid].dimy;
    _globalTileId = tileid;
    _globalTileSizeX = sizex;
    _globalTileDimX = dimx;
    _globalTileSizeY = sizey;
    _globalTileDimY = dimy;
    _globalTileScaleX = sizex / dimx;
    _globalTileScaleY = sizey / dimy;
}

/*800209BC*/
static void _setWallGlobals(u16 wallnum, s16 cstat)
{
    _globalXrepeat = gpWall[wallnum].xrepeat / _globalTileScaleX;
    _globalXpanning = gpWall[wallnum].xpanning / _globalTileScaleX;
    _globalYrepeat = (gpWall[wallnum].yrepeat / _globalTileScaleY) / 4.0f;

    if (cstat & 256)
    {
        _globalYpanning = (255 - gpWall[wallnum].ypanning);
        _globalYpanning = (_globalTileDimY / 256.0f) * _globalYpanning;
    }
    else
    {
        _globalYpanning = (gpWall[wallnum].ypanning);
        _globalYpanning = (_globalTileDimY / 256.0f) * _globalYpanning;
        _globalYrepeat = -_globalYrepeat;
    }

    _globalWallVoffset = _globalYpanning;

    if (cstat & 4)
        _globalWallVoffset = (_globalTileDimY * 32.0f) + (_globalYpanning * 32.0f);
    else
        _globalWallVoffset = _globalYpanning * 32.0f;

    _globalWallU1 = _globalXpanning * 32.0f;
    _globalWallU2 = (_globalXrepeat * 8.0f * 32.0f) + _globalWallU1;
}

/*80020BA0*/
static void _setWallGlobals2(u16 wallnum, s16 cstat)
{
    _globalXrepeat = gpWall[wallnum].xrepeat / _globalTileScaleX;
    _globalXpanning = gpWall[gpWall[wallnum].nextwall].xpanning / _globalTileScaleX;
    _globalYrepeat = (gpWall[wallnum].yrepeat / _globalTileScaleY) / 4.0f;

    if (cstat & 0x100)
    {
        _globalYpanning = (0xFF - gpWall[gpWall[wallnum].nextwall].ypanning);
        _globalYpanning = (_globalTileDimY / 256.0f) * _globalYpanning;
    }
    else
    {
        _globalYpanning = gpWall[gpWall[wallnum].nextwall].ypanning;
        _globalYpanning = (_globalTileDimY / 256.0f) * _globalYpanning;
        _globalYrepeat = -_globalYrepeat;
    }

    _globalWallVoffset = _globalYpanning;

    if (cstat & 4)
        _globalWallVoffset = (_globalTileDimY * 32.0f) + (_globalYpanning * 32.0f);
    else
        _globalWallVoffset = _globalYpanning * 32.0f;

    _globalWallU1 = _globalXpanning * 32.0f;
    _globalWallU2 = (_globalXrepeat * 8.0f * 32.0f) + _globalWallU1;
}

/*80020DC4*/
static void _handleWallCstatSlope(s16 cstat)
{
    f32 f1, prev;
    s32 adjust;

    if (cstat & 8)
    {
        prev = _globalWallU1;
        _globalWallU1 = _globalWallU2;
        _globalWallU2 = prev;
    }
    f1 = MIN(_globalWallV1, MIN(_globalWallV2, MIN(_globalWallV3, _globalWallV4)));
    if (f1 < -32760.0f)
    {
        adjust = f1 - (-32760.0f);
        adjust = ((adjust + 0xFFF) & ~0xFFF);
        _globalWallV1 += adjust;
        _globalWallV2 += adjust;
        _globalWallV3 += adjust;
        _globalWallV4 += adjust;
    }
    f1 = MAX(_globalWallV1, MAX(_globalWallV2, MAX(_globalWallV3, _globalWallV4)));
    if (f1 > 32760.0f)
    {
        adjust = f1 - 32760.0f;
        adjust = ((adjust + 0xFFF) & ~0xFFF);
        _globalWallV1 -= adjust;
        _globalWallV2 -= adjust;
        _globalWallV3 -= adjust;
        _globalWallV4 -= adjust;
    }
}

/*800211D0*/
static void _handleWallCstat(s32 cstat)
{
    f32 f1, prev;
    s32 adjust;

    if (cstat & 8)
    {
        prev = _globalWallU1;
        _globalWallU1 = _globalWallU2;
        _globalWallU2 = prev;
    }
    f1 = MIN(_globalWallV1, _globalWallV2);
    if (f1 < -32760.0f)
    {
        adjust = klabs(f1) - 32760.0f;
        adjust = ((adjust + 0xFFF) & ~0xFFF);
        _globalWallV1 += adjust;
        _globalWallV2 += adjust;
        _globalWallV3 += adjust;
        _globalWallV4 += adjust;
    }
    f1 = MAX(_globalWallV1, _globalWallV2);
    if (f1 > 32760.0f)
    {
        adjust = f1 - 32760.0f;
        adjust = ((adjust + 0xFFF) & ~0xFFF);
        _globalWallV1 -= adjust;
        _globalWallV2 -= adjust;
        _globalWallV3 -= adjust;
        _globalWallV4 -= adjust;
    }
}

/*800213B8*/
u8 wallCalc(s32 sectnum, s32 wallnum)
{
    s16 nextsector;
    u16 cstat;
    s32 ret;

    cstat = gpSector[sectnum].floorstat;
    nextsector = gpWall[wallnum].nextsector;
    cstat |= gpSector[sectnum].ceilingstat;
    if (nextsector != -1)
    {
        cstat |= gpSector[nextsector].floorstat;
        cstat |= gpSector[nextsector].ceilingstat;
    }

    if (!(cstat & 2))
        ret = _wallCalcNoSlope(sectnum, wallnum);
    else
        ret = _wallCalcSlope(sectnum, wallnum);

    return ret;
}

/*80021464*/
static s32 _wallCalcSlope(s32 sectnum, s32 wallnum)
{
    s32 x2, y1, y2, x1;
    s32 z, z1, z2, z3, z4;
    s32 wx, wy;
    u16 cstat;
    u16 i;
    u8 ret;

    i = 0;
    _wallPolyCount = 0;
    ret = 0;

    if (gpWall[wallnum].nextsector == -1)
    {
        x1 = gpWall[wallnum].x;
        y1 = gpWall[wallnum].y;
        x2 = gpWall[gpWall[wallnum].point2].x;
        y2 = gpWall[gpWall[wallnum].point2].y;
        z1 = getCeilzOfSlope(sectnum, x1, y1) >> 4;
        z2 = getFlorzOfSlope(sectnum, x1, y1) >> 4;
        z3 = getFlorzOfSlope(sectnum, x2, y2) >> 4;
        z4 = getCeilzOfSlope(sectnum, x2, y2) >> 4;

        if (((z1 == z2) && (z3 == z4)))
            return ret;

        if (gpWall[wallnum].cstat & 4)
            z = gpSector[sectnum].floorz >> 4;
        else
            z = gpSector[sectnum].ceilingz >> 4;

        _setTileGlobals(gpWall[wallnum].picnum);
        _setWallGlobals(wallnum, gpWall[wallnum].cstat);
        ret |= 8;
        _globalWallV1 = ((z - z1) * _globalYrepeat) + _globalWallVoffset;
        _globalWallV2 = ((z - z2) * _globalYrepeat) + _globalWallVoffset;
        _globalWallV3 = ((z - z3) * _globalYrepeat) + _globalWallVoffset;
        _globalWallV4 = ((z - z4) * _globalYrepeat) + _globalWallVoffset;
        _handleWallCstatSlope(gpWall[wallnum].cstat);

        gWallVertex[i].ob[0] = x1 >> 1;
        gWallVertex[i].ob[2] = z1 >> 1;
        gWallVertex[i].ob[1] = y1 >> 1;
        gWallVertex[i].tc[0] = (s32)_globalWallU1;
        gWallVertex[i].tc[1] = (s32)_globalWallV1;
        i++;

        gWallVertex[i].ob[0] = x1 >> 1;
        gWallVertex[i].ob[2] = z2 >> 1;
        gWallVertex[i].ob[1] = y1 >> 1;
        gWallVertex[i].tc[0] = (s32)_globalWallU1;
        gWallVertex[i].tc[1] = (s32)_globalWallV2;
        i++;

        gWallVertex[i].ob[0] = x2 >> 1;
        gWallVertex[i].ob[2] = z3 >> 1;
        gWallVertex[i].ob[1] = y2 >> 1;
        gWallVertex[i].tc[0] = (s32)_globalWallU2;
        gWallVertex[i].tc[1] = (s32)_globalWallV3;
        i++;

        gWallVertex[i].ob[0] = x2 >> 1;
        gWallVertex[i].ob[2] = z4 >> 1;
        gWallVertex[i].ob[1] = y2 >> 1;
        gWallVertex[i].tc[0] = (s32)_globalWallU2;
        gWallVertex[i].tc[1] = (s32)_globalWallV4;
        i++;
        _wallPolyCount++;

        return ret;
    }
    if (!(gpWall[wallnum].cstat & 0x400))
    {
        x1 = gpWall[wallnum].x;
        y1 = gpWall[wallnum].y;
        x2 = gpWall[gpWall[wallnum].point2].x;
        y2 = gpWall[gpWall[wallnum].point2].y;
        z1 = getCeilzOfSlope(sectnum, x1, y1) >> 4;
        z2 = getCeilzOfSlope(gpWall[wallnum].nextsector, x1, y1) >> 4;
        z3 = getCeilzOfSlope(gpWall[wallnum].nextsector, x2, y2) >> 4;
        z4 = getCeilzOfSlope(sectnum, x2, y2) >> 4;

        if ((z2 < z1) && (z3 < z4))
            ;
        else
        {
            if ((z1 != z2) || (z3 != z4))
            {
                if (z2 < z1)
                    z1 = z2;

                if (z3 < z4)
                    z4 = z3;

                cstat = gpWall[wallnum].cstat & ~4;
                if (gpWall[wallnum].cstat & 4)
                    z = gpSector[sectnum].ceilingz >> 4;
                else
                {
                    cstat = gpWall[wallnum].cstat | 4;
                    z = gpSector[gpWall[wallnum].nextsector].ceilingz >> 4;
                }

                _setTileGlobals(gpWall[wallnum].picnum);
                _setWallGlobals(wallnum, cstat);
                ret |= 1;
                _globalWallV1 = ((z - z1) * _globalYrepeat) + _globalWallVoffset;
                _globalWallV2 = ((z - z2) * _globalYrepeat) + _globalWallVoffset;
                _globalWallV3 = ((z - z3) * _globalYrepeat) + _globalWallVoffset;
                _globalWallV4 = ((z - z4) * _globalYrepeat) + _globalWallVoffset;
                _handleWallCstatSlope(cstat);

                gWallVertex[i].ob[0] = x1 >> 1;
                gWallVertex[i].ob[2] = z1 >> 1;
                gWallVertex[i].ob[1] = y1 >> 1;
                gWallVertex[i].tc[0] = (s32)_globalWallU1;
                gWallVertex[i].tc[1] = (s32)_globalWallV1;
                i++;

                gWallVertex[i].ob[0] = x1 >> 1;
                gWallVertex[i].ob[2] = z2 >> 1;
                gWallVertex[i].ob[1] = y1 >> 1;
                gWallVertex[i].tc[0] = (s32)_globalWallU1;
                gWallVertex[i].tc[1] = (s32)_globalWallV2;
                i++;

                gWallVertex[i].ob[0] = x2 >> 1;
                gWallVertex[i].ob[2] = z3 >> 1;
                gWallVertex[i].ob[1] = y2 >> 1;
                gWallVertex[i].tc[0] = (s32)_globalWallU2;
                gWallVertex[i].tc[1] = (s32)_globalWallV3;
                i++;

                gWallVertex[i].ob[0] = x2 >> 1;
                gWallVertex[i].ob[2] = z4 >> 1;
                gWallVertex[i].ob[1] = y2 >> 1;
                gWallVertex[i].tc[0] = (s32)_globalWallU2;
                gWallVertex[i].tc[1] = (s32)_globalWallV4;
                i++;

                _wallPolyCount++;
            }
        }
    }

    if (!(gpWall[wallnum].cstat & 0x800))
    {
        x1 = gpWall[wallnum].x;
        y1 = gpWall[wallnum].y;
        x2 = gpWall[gpWall[wallnum].point2].x;
        y2 = gpWall[gpWall[wallnum].point2].y;
        z1 = getFlorzOfSlope(gpWall[wallnum].nextsector, x1, y1) >> 4;
        z2 = getFlorzOfSlope(sectnum, x1, y1) >> 4;
        z3 = getFlorzOfSlope(sectnum, x2, y2) >> 4;
        z4 = getFlorzOfSlope(gpWall[wallnum].nextsector, x2, y2) >> 4;

        if (((z2 < z1) && (z3 < z4)))
            ;
        else
        {
            if (((z1 != z2) || (z3 != z4)))
            {
                if (z2 < z1)
                    z2 = z1;

                if (z3 < z4)
                    z3 = z4;

                if (gpWall[wallnum].cstat & 2)
                {
                    _setTileGlobals(gpWall[gpWall[wallnum].nextwall].picnum);

                    if (gpWall[gpWall[wallnum].nextwall].cstat & 4)
                    {
                        cstat = gpWall[wallnum].cstat;
                        z = gpSector[sectnum].ceilingz >> 4;
                        _setWallGlobals2(wallnum, gpWall[gpWall[wallnum].nextwall].cstat & ~4);
                    }
                    else
                    {
                        cstat = gpWall[wallnum].cstat;
                        z = gpSector[gpWall[wallnum].nextsector].floorz >> 4;
                        _setWallGlobals2(wallnum, gpWall[gpWall[wallnum].nextwall].cstat & ~4);
                    }
                }
                else
                {
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
                    _setTileGlobals(gpWall[wallnum].picnum);
                    _setWallGlobals(wallnum, cstat);
                }
                _globalWallV1 = ((z - z1) * _globalYrepeat) + _globalWallVoffset;
                _globalWallV2 = ((z - z2) * _globalYrepeat) + _globalWallVoffset;
                _globalWallV3 = ((z - z3) * _globalYrepeat) + _globalWallVoffset;
                _globalWallV4 = ((z - z4) * _globalYrepeat) + _globalWallVoffset;
                _handleWallCstatSlope(cstat);

                gWallVertex[i].ob[0] = x1 >> 1;
                gWallVertex[i].ob[2] = z1 >> 1;
                gWallVertex[i].ob[1] = y1 >> 1;
                gWallVertex[i].tc[0] = (s32)_globalWallU1;
                gWallVertex[i].tc[1] = (s32)_globalWallV1;
                i++;

                gWallVertex[i].ob[0] = x1 >> 1;
                gWallVertex[i].ob[2] = z2 >> 1;
                gWallVertex[i].ob[1] = y1 >> 1;
                gWallVertex[i].tc[0] = (s32)_globalWallU1;
                gWallVertex[i].tc[1] = (s32)_globalWallV2;
                i++;

                gWallVertex[i].ob[0] = x2 >> 1;
                gWallVertex[i].ob[2] = z3 >> 1;
                gWallVertex[i].ob[1] = y2 >> 1;
                gWallVertex[i].tc[0] = (s32)_globalWallU2;
                gWallVertex[i].tc[1] = (s32)_globalWallV3;
                i++;

                gWallVertex[i].ob[0] = x2 >> 1;
                gWallVertex[i].ob[2] = z4 >> 1;
                gWallVertex[i].ob[1] = y2 >> 1;
                gWallVertex[i].tc[0] = (s32)_globalWallU2;
                gWallVertex[i].tc[1] = (s32)_globalWallV4;
                i++;

                ret |= 2;
                _wallPolyCount++;
            }
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
        z3 = getFlorzOfSlope(gpWall[wallnum].nextsector, x2, y2) >> 4;
        z4 = getCeilzOfSlope(gpWall[wallnum].nextsector, x2, y2) >> 4;

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

        _setTileGlobals(gpWall[wallnum].overpicnum);
        _setWallGlobals(wallnum, cstat);
        ret |= 4;
        _globalWallV1 = ((z - z1) * _globalYrepeat) + _globalWallVoffset;
        _globalWallV2 = ((z - z2) * _globalYrepeat) + _globalWallVoffset;
        _globalWallV3 = ((z - z3) * _globalYrepeat) + _globalWallVoffset;
        _globalWallV4 = ((z - z4) * _globalYrepeat) + _globalWallVoffset;
        _handleWallCstatSlope(cstat);

        gWallVertex[i].ob[0] = x1 >> 1;
        gWallVertex[i].ob[2] = z1 >> 1;
        gWallVertex[i].ob[1] = y1 >> 1;
        gWallVertex[i].tc[0] = (s32)_globalWallU1;
        gWallVertex[i].tc[1] = (s32)_globalWallV1;
        i++;

        gWallVertex[i].ob[0] = x1 >> 1;
        gWallVertex[i].ob[2] = z2 >> 1;
        gWallVertex[i].ob[1] = y1 >> 1;
        gWallVertex[i].tc[0] = (s32)_globalWallU1;
        gWallVertex[i].tc[1] = (s32)_globalWallV2;
        i++;

        gWallVertex[i].ob[0] = x2 >> 1;
        gWallVertex[i].ob[2] = z3 >> 1;
        gWallVertex[i].ob[1] = y2 >> 1;
        gWallVertex[i].tc[0] = (s32)_globalWallU2;
        gWallVertex[i].tc[1] = (s32)_globalWallV3;
        i++;

        gWallVertex[i].ob[0] = x2 >> 1;
        gWallVertex[i].ob[2] = z4 >> 1;
        gWallVertex[i].ob[1] = y2 >> 1;
        gWallVertex[i].tc[0] = (s32)_globalWallU2;
        gWallVertex[i].tc[1] = (s32)_globalWallV4;
        i++;

        _wallPolyCount++;
        return ret;
    }

    if (!(gpWall[wallnum].cstat & 0x10))
        return ret;

    x1 = gpWall[wallnum].x;
    y1 = gpWall[wallnum].y;
    x2 = gpWall[gpWall[wallnum].point2].x;
    y2 = gpWall[gpWall[wallnum].point2].y;

    wx = klabs((gGlobalPosX - ((x1 + x2) / 2)));
    wy = klabs((gGlobalPosY - ((y1 + y2) / 2)));

    gMaskDrawList[gSortSpritesCnt].dist = MAX(wx, wy) + (MIN(wx, wy) >> 2) + (MIN(wx, wy) >> 3);
    gMaskDrawList[gSortSpritesCnt].index = wallnum | 0x8000;
    gSortSpritesCnt++;
    return ret;
}

/*800226C0*/
s32 drawMaskWall(u16 wallnum)
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
    _wallPolyCount = 0;

    x1 = gpWall[wallnum].x;
    y1 = gpWall[wallnum].y;
    x2 = gpWall[gpWall[wallnum].point2].x;
    y2 = gpWall[gpWall[wallnum].point2].y;
    ceilz1 = getCeilzOfSlope(gpWall[wallnum].sectnum, x1, y1) >> 4;
    ceilz2 = getCeilzOfSlope(gpWall[wallnum].sectnum, x2, y2) >> 4;
    z1 = getCeilzOfSlope(gpWall[wallnum].nextsector, x1, y1) >> 4;
    z2 = getCeilzOfSlope(gpWall[wallnum].nextsector, x2, y2) >> 4;

    if (ceilz1 < z1)
    {
        ceilz1 = z1;
        ceilz2 = z2;
    }

    floorz1 = getFlorzOfSlope(gpWall[wallnum].sectnum, x1, y1) >> 4;
    floorz2 = getFlorzOfSlope(gpWall[wallnum].sectnum, x2, y2) >> 4;
    z1 = getFlorzOfSlope(gpWall[wallnum].nextsector, x1, y1) >> 4;
    z2 = getFlorzOfSlope(gpWall[wallnum].nextsector, x2, y2) >> 4;

    if (z1 < floorz1)
    {
        floorz1 = z1;
        floorz2 = z2;
    }

    if (!(gpWall[wallnum].cstat & 4))
    {
        z1 = MAX((gpSector[gpWall[wallnum].sectnum].ceilingz >> 4),
                 (gpSector[gpWall[wallnum].nextsector].ceilingz >> 4));
        cstat = gpWall[wallnum].cstat & ~4;
    }
    else
    {
        z1 = MIN((gpSector[gpWall[wallnum].sectnum].floorz >> 4),
                 (gpSector[gpWall[wallnum].nextsector].floorz >> 4));
        cstat = gpWall[wallnum].cstat & ~4;
    }

    _setTileGlobals(gpWall[wallnum].overpicnum);
    _setWallGlobals(wallnum, cstat);
    ret |= 4;
    _globalWallV1 = ((z1 - ceilz1) * _globalYrepeat) + _globalWallVoffset;
    _globalWallV2 = ((z1 - floorz1) * _globalYrepeat) + _globalWallVoffset;
    _globalWallV3 = ((z1 - floorz2) * _globalYrepeat) + _globalWallVoffset;
    _globalWallV4 = ((z1 - ceilz2) * _globalYrepeat) + _globalWallVoffset;
    _handleWallCstatSlope(cstat);

    gWallVertex[i].ob[0] = x1 >> 1;
    gWallVertex[i].ob[2] = ceilz1 >> 1;
    gWallVertex[i].ob[1] = y1 >> 1;
    gWallVertex[i].tc[0] = (s32)_globalWallU1;
    gWallVertex[i].tc[1] = (s32)_globalWallV1;
    i++;

    gWallVertex[i].ob[0] = x1 >> 1;
    gWallVertex[i].ob[2] = floorz1 >> 1;
    gWallVertex[i].ob[1] = y1 >> 1;
    gWallVertex[i].tc[0] = (s32)_globalWallU1;
    gWallVertex[i].tc[1] = (s32)_globalWallV2;
    i++;

    gWallVertex[i].ob[0] = x2 >> 1;
    gWallVertex[i].ob[2] = floorz2 >> 1;
    gWallVertex[i].ob[1] = y2 >> 1;
    gWallVertex[i].tc[0] = (s32)_globalWallU2;
    gWallVertex[i].tc[1] = (s32)_globalWallV3;
    i++;

    gWallVertex[i].ob[0] = x2 >> 1;
    gWallVertex[i].ob[2] = ceilz2 >> 1;
    gWallVertex[i].ob[1] = y2 >> 1;
    gWallVertex[i].tc[0] = (s32)_globalWallU2;
    gWallVertex[i].tc[1] = (s32)_globalWallV4;

    _wallPolyCount++;
    return ret;
}

/*80022C30*/
static s32 _wallCalcNoSlope(s32 sectnum, s32 wallnum)
{
    s32 x2, y2, z2;
    s32 x1, y1, z1;
    s32 z, wx, wy;
    s32 nextsector;
    s16 cstat;
    u16 i;
    u8 ret;

    nextsector = gpWall[wallnum].nextsector;
    i = 0;
    _wallPolyCount = 0;
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

        _setTileGlobals(gpWall[wallnum].picnum);
        _setWallGlobals(wallnum, gpWall[wallnum].cstat);
        _globalWallV1 = ((z - z1) * _globalYrepeat) + _globalWallVoffset;
        _globalWallV2 = ((z - z2) * _globalYrepeat) + _globalWallVoffset;
        _handleWallCstat(gpWall[wallnum].cstat);

        gWallVertex[0].ob[0] = x1 >> 1;
        gWallVertex[0].ob[2] = z1 >> 1;
        gWallVertex[0].ob[1] = y1 >> 1;
        gWallVertex[0].tc[0] = (s32)_globalWallU1;
        gWallVertex[0].tc[1] = (s32)_globalWallV1;

        gWallVertex[1].ob[0] = x1 >> 1;
        gWallVertex[1].ob[2] = z2 >> 1;
        gWallVertex[1].ob[1] = y1 >> 1;
        gWallVertex[1].tc[0] = (s32)_globalWallU1;
        gWallVertex[1].tc[1] = (s32)_globalWallV2;

        gWallVertex[2].ob[0] = x2 >> 1;
        gWallVertex[2].ob[2] = z2 >> 1;
        gWallVertex[2].ob[1] = y2 >> 1;
        gWallVertex[2].tc[0] = (s32)_globalWallU2;
        gWallVertex[2].tc[1] = (s32)_globalWallV2;

        gWallVertex[3].ob[0] = x2 >> 1;
        gWallVertex[3].ob[2] = z1 >> 1;
        gWallVertex[3].ob[1] = y2 >> 1;
        gWallVertex[3].tc[0] = (s32)_globalWallU2;
        gWallVertex[3].tc[1] = (s32)_globalWallV1;

        _wallPolyCount++;
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

            _setTileGlobals(gpWall[wallnum].picnum);
            _setWallGlobals(wallnum, cstat);
            ret |= 1;
            _globalWallV1 = ((z - z1) * _globalYrepeat) + _globalWallVoffset;
            _globalWallV2 = ((z - z2) * _globalYrepeat) + _globalWallVoffset;
            _handleWallCstat(cstat);

            gWallVertex[i].ob[0] = x1 >> 1;
            gWallVertex[i].ob[2] = z1 >> 1;
            gWallVertex[i].ob[1] = y1 >> 1;
            gWallVertex[i].tc[0] = (s32)_globalWallU1;
            gWallVertex[i].tc[1] = (s32)_globalWallV1;
            i++;

            gWallVertex[i].ob[0] = x1 >> 1;
            gWallVertex[i].ob[2] = z2 >> 1;
            gWallVertex[i].ob[1] = y1 >> 1;
            gWallVertex[i].tc[0] = (s32)_globalWallU1;
            gWallVertex[i].tc[1] = (s32)_globalWallV2;
            i++;

            gWallVertex[i].ob[0] = x2 >> 1;
            gWallVertex[i].ob[2] = z2 >> 1;
            gWallVertex[i].ob[1] = y2 >> 1;
            gWallVertex[i].tc[0] = (s32)_globalWallU2;
            gWallVertex[i].tc[1] = (s32)_globalWallV2;
            i++;

            gWallVertex[i].ob[0] = x2 >> 1;
            gWallVertex[i].ob[2] = z1 >> 1;
            gWallVertex[i].ob[1] = y2 >> 1;
            gWallVertex[i].tc[0] = (s32)_globalWallU2;
            gWallVertex[i].tc[1] = (s32)_globalWallV1;
            i++;
            _wallPolyCount++;
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
                _setTileGlobals(gpWall[gpWall[wallnum].nextwall].picnum);

                if (gpWall[gpWall[wallnum].nextwall].cstat & 4)
                {
                    cstat = gpWall[wallnum].cstat;
                    z = gpSector[sectnum].ceilingz >> 4;
                    _setWallGlobals2(wallnum, gpWall[gpWall[wallnum].nextwall].cstat & ~4);
                }
                else
                {
                    cstat = gpWall[wallnum].cstat;
                    z = gpSector[gpWall[wallnum].nextsector].floorz >> 4;
                    _setWallGlobals2(wallnum, gpWall[gpWall[wallnum].nextwall].cstat & ~4);
                }
            }
            else
            {
                cstat = gpWall[wallnum].cstat & ~4;

                if (gpWall[wallnum].cstat & 4)
                    z = gpSector[sectnum].ceilingz >> 4;
                else
                    z = z1;

                _setTileGlobals(gpWall[wallnum].picnum);
                _setWallGlobals(wallnum, cstat);
            }

            _globalWallV1 = ((z - z1) * _globalYrepeat) + _globalWallVoffset;
            _globalWallV2 = ((z - z2) * _globalYrepeat) + _globalWallVoffset;
            _handleWallCstat(cstat);
            ret |= 2;

            gWallVertex[i].ob[0] = x1 >> 1;
            gWallVertex[i].ob[2] = z1 >> 1;
            gWallVertex[i].ob[1] = y1 >> 1;
            gWallVertex[i].tc[0] = (s32)_globalWallU1;
            gWallVertex[i].tc[1] = (s32)_globalWallV1;
            i++;

            gWallVertex[i].ob[0] = x1 >> 1;
            gWallVertex[i].ob[2] = z2 >> 1;
            gWallVertex[i].ob[1] = y1 >> 1;
            gWallVertex[i].tc[0] = (s32)_globalWallU1;
            gWallVertex[i].tc[1] = (s32)_globalWallV2;
            i++;

            gWallVertex[i].ob[0] = x2 >> 1;
            gWallVertex[i].ob[2] = z2 >> 1;
            gWallVertex[i].ob[1] = y2 >> 1;
            gWallVertex[i].tc[0] = (s32)_globalWallU2;
            gWallVertex[i].tc[1] = (s32)_globalWallV2;
            i++;

            gWallVertex[i].ob[0] = x2 >> 1;
            gWallVertex[i].ob[2] = z1 >> 1;
            gWallVertex[i].ob[1] = y2 >> 1;
            gWallVertex[i].tc[0] = (s32)_globalWallU2;
            gWallVertex[i].tc[1] = (s32)_globalWallV1;
            i++;
            _wallPolyCount++;
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

        _setTileGlobals(gpWall[wallnum].overpicnum);
        _setWallGlobals(wallnum, cstat);
        ret |= 4;
        _globalWallV1 = ((z - z1) * _globalYrepeat) + _globalWallVoffset;
        _globalWallV2 = ((z - z2) * _globalYrepeat) + _globalWallVoffset;
        _handleWallCstat(cstat);

        gWallVertex[i].ob[0] = x1 >> 1;
        gWallVertex[i].ob[2] = z1 >> 1;
        gWallVertex[i].ob[1] = y1 >> 1;
        gWallVertex[i].tc[0] = (s32)_globalWallU1;
        gWallVertex[i].tc[1] = (s32)_globalWallV1;
        i++;

        gWallVertex[i].ob[0] = x1 >> 1;
        gWallVertex[i].ob[2] = z2 >> 1;
        gWallVertex[i].ob[1] = y1 >> 1;
        gWallVertex[i].tc[0] = (s32)_globalWallU1;
        gWallVertex[i].tc[1] = (s32)_globalWallV2;
        i++;

        gWallVertex[i].ob[0] = x2 >> 1;
        gWallVertex[i].ob[2] = z2 >> 1;
        gWallVertex[i].ob[1] = y2 >> 1;
        gWallVertex[i].tc[0] = (s32)_globalWallU2;
        gWallVertex[i].tc[1] = (s32)_globalWallV2;
        i++;

        gWallVertex[i].ob[0] = x2 >> 1;
        gWallVertex[i].ob[2] = z1 >> 1;
        gWallVertex[i].ob[1] = y2 >> 1;
        gWallVertex[i].tc[0] = (s32)_globalWallU2;
        gWallVertex[i].tc[1] = (s32)_globalWallV1;

        _wallPolyCount++;
        return ret;
    }

    if (!(gpWall[wallnum].cstat & 0x10))
        return ret;

    x1 = gpWall[wallnum].x;
    y1 = gpWall[wallnum].y;
    x2 = gpWall[gpWall[wallnum].point2].x;
    y2 = gpWall[gpWall[wallnum].point2].y;

    wx = klabs((gGlobalPosX - ((x1 + x2) / 2)));
    wy = klabs((gGlobalPosY - ((y1 + y2) / 2)));

    gMaskDrawList[gSortSpritesCnt].dist = MAX(wx, wy) + (MIN(wx, wy) >> 2) + (MIN(wx, wy) >> 3);
    gMaskDrawList[gSortSpritesCnt].index = wallnum | 0x8000;
    gSortSpritesCnt++;
    return ret;
}
