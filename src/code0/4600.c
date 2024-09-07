#include "common.h"
#include "code0/2ABE0.h"
#include "code0/4600.h"
#include "code0/pragmas.h"
#include "code0/code0.h"

/*.text*/
static void scanSector(f32 lx, f32 rx, s32 sectnum);
static void func_80004CFC(u16 sectnum);
static void func_80004F14(u16 sectnum);
static s8 visWallCheck(s32 w, f32 f1, f32 f2);

/*.data*/
/*800BD430*/ static u16 _pow2char[9] = {0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80, 0x100};
/*800BD442*/ static u16 D_800BD442 = 0;
/*800BD444*/ static u16 D_800BD444 = 0;

/*.comm*/
/*800FF52C*/ s32 D_800FF52C;
/*8012DEF8*/ s16 D_8012DEF8;
/*8012E160*/ s16 D_8012E160[1266] ALIGNED(16);
/*80138628*/ u16 D_80138628[40] ALIGNED(8);
/*80138720*/ u16 D_80138720[40] ALIGNED(8);
/*8016A160*/ s32 D_8016A160;
/*80199958*/ s32 D_80199958;
/*801AFE20*/ s16 D_801AFE20[1266] ALIGNED(16);

/*801AE9C8*/ s32 _globalPosX;
/*8012D210*/ s32 _globalPosY;
/*801A1988*/ s32 _visWallCnt;
/*801C0D58*/ s32 _viewAngle;

/*80169D40*/ u16 _visWall[512] ALIGNED(16);
/*800FEBA0*/ f32 _visWallR1[512] ALIGNED(16);
/*80168D20*/ f32 _visWallR2[512] ALIGNED(16);

/*80199758*/ u8 _wallBitCheck[(MAXWALLS+7)>>3] ALIGNED(8);
/*80197D78*/ u8 _visSectBit1[((MAXSECTORS+7)>>3)] ALIGNED(8);
/*801A2630*/ u8 _ceilingBitCheck[((MAXSECTORS+7)>>3)] ALIGNED(8);
/*8012BBD0*/ u8 _floorBitCheck[((MAXSECTORS+7)>>3)] ALIGNED(8);
/*8012C7A0*/ u8 _visWalltBit[((MAXWALLS+7)>>3)] ALIGNED(8);

/*800FF3E8*/ u16 gVisibleSectors[128] ALIGNED(8);
/*80138790*/ s32 gVisibleSectorCnt;
/*80199650*/ u16 gDrawCeilingList[128] ALIGNED(8);
/*80168D10*/ s32 gDrawCeilCnt;
/*801A2690*/ u16 gDrawFloorList[128] ALIGNED(8);
/*80199528*/ s32 gDrawFloorCnt;
/*8013A448*/ u16 gDrawWallList[256] ALIGNED(8);
/*80199750*/ s32 gDrawWallCnt;

/*80003A00*/
static f32 angleModF(f32 a)
{
    while (a < 0.0f) a += 2*PI;
    while (a >= 2*PI) a -= 2*PI;
    return a;
}

/*80003A74*/
static f32 getAngleDeltaF(f32 a1, f32 a2)
{
    if (a1 <= a2)
    {
        a2 -= a1;
        if (a2 <= PI)
            return a2;
        else
            return a2 - 2*PI;
    }
    else
    {
        a1 -= a2;
        if (a1 <= PI)
            return -a1;
        else
            return -(a1 - 2*PI);
    }
}

/*80003B00*/
static f32 _getAngleF(f32 x1, f32 y1, f32 x2, f32 y2)
{
    return -getAngleF(y2 - y1, x2 - x1) + 4.712388980385/*(PI*1.5)*/;
}

/*80003B4C*/
static void scanSector(f32 lx, f32 rx, s32 sectnum)
{
    s32 oviswalcnt;
    f32 f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12;
    s32 i, j, k;
    s16 cond;

    oviswalcnt = k = _visWallCnt;
    if ((gpSector[sectnum].floorheinum != 0) || (gpSector[sectnum].floorz > D_80199640))
        _floorBitCheck[sectnum >> 3] |= _pow2char[sectnum & 7];

    if ((gpSector[sectnum].ceilingheinum != 0) || ((gpSector[sectnum].ceilingz < D_80199640)))
        _ceilingBitCheck[sectnum >> 3] |= _pow2char[sectnum & 7];

    _visSectBit1[sectnum >> 3] |= _pow2char[sectnum & 7];

    f1 = _globalPosX + (sinf(lx) * 5000.0f);
    f2 = _globalPosX + (sinf(rx) * 5000.0f);
    f3 = _globalPosY + (cosf(lx) * 5000.0f);
    f4 = _globalPosY + (cosf(rx) * 5000.0f);

    j = gpSector[sectnum].wallptr + gpSector[sectnum].wallnum;
    for (i = gpSector[sectnum].wallptr; i < j; i++)
    {
        if (!(_wallBitCheck[i >> 3] & _pow2char[i & 7]))
        {
            f32 ft1, ft2, ft3, ft4;
            f5 = _globalPosX;
            f6 = gpWall[i].x;
            f7 = _globalPosY;
            f8 = gpWall[i].y;
            f9 = gpWall[gpWall[i].point2].x;
            f10 = gpWall[gpWall[i].point2].y;

            ft1 = f6 - f5;
            ft2 = f10 - f7;
            ft3 = f9 - f5;
            ft4 = f8 - f7;

            /*Side check*/
            if (((ft1) * (ft2)) < ((ft3) * (ft4)))
            {
                _wallBitCheck[i >> 3] |= _pow2char[i & 7];
                continue;
            }

            /*Visibility check*/
            if (((((f5 - f6) * (f4 - f8)) < ((f2 - f6) * (f7 - f8))) || (!(((f5 - f6) * (f3 - f8)) < ((f1 - f6) * (f7 - f8)))))  &&
                ((((f5 - f9) * (f4 - f10)) < ((f2 - f9) * (f7 - f10))) || (!(((f5 - f9) * (f3 - f10)) < ((f1 - f9) * (f7 - f10))))) &&
                (!(((f5 - f6) * (f4 - f8)) < ((f2 - f6) * (f7 - f8))) || !(((f5 - f6) * (f3 - f8)) < ((f1 - f6) * (f7 - f8))) ||
                    (((f5 - f9) * (f4 - f10)) < ((f2 - f9) * (f7 - f10))) || (((f5 - f9) * (f3 - f10)) < ((f1 - f9) * (f7 - f10)))))
            {
                continue;
            }

            _visWalltBit[i >> 3] |= _pow2char[i & 7];
            if ((gpWall[i].nextsector == -1) ||
                ((gpSector[gpWall[i].nextsector].ceilingz == gpSector[gpWall[i].nextsector].floorz) &&
                    (gpSector[gpWall[i].nextsector].ceilingheinum == gpSector[gpWall[i].nextsector].floorheinum)))
            {
                _wallBitCheck[i >> 3] |= _pow2char[i & 7];
                continue;
            }

            cond = 1;
            f12 = _getAngleF(f9, f10, _globalPosX, _globalPosY);
            f11 = _getAngleF(f6, f8, _globalPosX, _globalPosY);
            if (getAngleDeltaF(lx, f12) < 0.0f)
            {
                f12 = lx;
                cond = 0;
            }
            if (getAngleDeltaF(rx, f11) > 0.0f)
            {
                f11 = rx;
                cond = 0;
            }

            if (cond != 0)
                _wallBitCheck[i >> 3] |= _pow2char[(i & 7)];

            if (visWallCheck(i, f12, f11) == 0)
                continue;

            _visWall[_visWallCnt] = i;
            _visWallR1[_visWallCnt] = f12;
            _visWallR2[_visWallCnt] = f11;
            _visWallCnt++;
            k += 1;

            if (_visWallCnt >= 0x200)
                return;
        }
    }

    for (i = oviswalcnt; i < k; i++)
        scanSector(_visWallR1[i], _visWallR2[i], gpWall[_visWall[i]].nextsector);
}

/*800042D8*/
static s8 visWallCheck(s32 w, f32 f1, f32 f2)
{
    s32 i;

    for (i = 0; i < _visWallCnt; i++)
    {
        if ((_visWall[i] == w) && (getAngleDeltaF(f1, _visWallR1[i]) <= 0.0f))
        {
            if (getAngleDeltaF(f2, _visWallR2[i]) >= 0.0f)
                return 0;
        }
    }
    return 1;
}

/*800043F4*/
void scanSectors(s32 posx, s32 posy, s32 arg2, f32 arg3, s16 arg4)
{
    f32 viewrange, f2, viewangle, viewangler2, viewangler1;
    s16 sectnum;
    s32 i, j;

    D_8012FC40 = 1;
    viewrange = (klabs(D_8016A15C) * 0.7999999999999999)/*(1/1.25)*/ + 0.6283185307179999/*(PI/5)*/;

    if (sinf(D_801AC8E0) > 0.0f)
        f2 = sinf(D_801AC8E0);
    else
        f2 = -sinf(D_801AC8E0);

    if (cosf(D_801AC8E0) > 0.0f)
        viewrange *= (f2 + cosf(D_801AC8E0));
    else
        viewrange *= (f2 - cosf(D_801AC8E0));

    viewangle = angleModF((PI - arg3));
    _viewAngle = viewangle;
    _globalPosX = posx;
    _globalPosY = posy;
    D_80199958 = arg2;
    gDrawWallCnt = 0;
    gDrawCeilCnt = 0;
    gDrawFloorCnt = 0;
    _visWallCnt = 0;
    gVisibleSectorCnt = 0;
    viewangler2 = viewangle - viewrange;
    Bmemset(_visWalltBit, 0, sizeof(_visWalltBit));
    Bmemset(_wallBitCheck, 0, sizeof(_wallBitCheck));
    Bmemset(_floorBitCheck, 0, sizeof(_floorBitCheck));
    Bmemset(_ceilingBitCheck, 0, sizeof(_ceilingBitCheck));
    Bmemset(_visSectBit1, 0, sizeof(_visSectBit1));
    viewangler1 = viewangle + viewrange;

    scanSector(viewangler2, viewangler1, arg4);

    for (i = 0; i < ((MAXWALLS+7)>>3); i++)
    {
        if (_visWalltBit[i] != 0)
        {
            for (j = 0; j < ARRAY_COUNT(_pow2char)-1; j++)
            {
                if (_visWalltBit[i] & _pow2char[j])
                {
                    gDrawWallList[gDrawWallCnt] = (i * 8) + j;
                    gDrawWallCnt++;
                }
            }
        }
    }

    for (i = 0; i < (((MAXSECTORS+7)>>3)-1); i++)
    {
        if (_floorBitCheck[i] != 0)
        {
            for (j = 0; j < ARRAY_COUNT(_pow2char)-1; j++)
            {
                if (_floorBitCheck[i] & _pow2char[j])
                {
                    gDrawFloorList[gDrawFloorCnt] = (i * 8) + j;
                    gDrawFloorCnt++;
                }
            }
        }
    }

    for (i = 0; i < (((MAXSECTORS+7)>>3)-1); i++)
    {
        if (_ceilingBitCheck[i] != 0)
        {
            for (j = 0; j < ARRAY_COUNT(_pow2char)-1; j++)
            {
                if (_ceilingBitCheck[i] & _pow2char[j])
                {
                    gDrawCeilingList[gDrawCeilCnt] = (i * 8) + j;
                    gDrawCeilCnt++;
                }
            }
        }
    }

    for (i = 0; i < (((MAXSECTORS+7)>>3)-1); i++)
    {
        if (_visSectBit1[i] != 0)
        {
            for (j = 0; j < ARRAY_COUNT(_pow2char)-1; j++)
            {
                if (_visSectBit1[i] & _pow2char[j])
                {
                    sectnum = (i * 8) + j;
                    gVisibleSectors[gVisibleSectorCnt] = sectnum;

                    if ((gpSector[sectnum].ceilingstat & 1) || (gpSector[sectnum].floorstat & 1))
                        D_8012FC40 = 0;

                    gVisibleSectorCnt++;
                }
            }
        }
    }

    gVisibleSectors[gVisibleSectorCnt] = -1;
    gDrawCeilingList[gDrawCeilCnt] = -1;
    gDrawFloorList[gDrawFloorCnt] = -1;
    gDrawWallList[gDrawWallCnt] = -1;
}

/*8000491C*/
static void _memcpy(u8 *dst, u8 *src, s32 size)
{
    s32 i;

    for (i = size; i != 0; i--)
        *dst++ = *src++;
}

/*80004944*/
void Bmemcpy(void *dst, void *src, u32 size)
{
    u32 i;

    if (((intptr_t)src & 3) || ((intptr_t)dst & 3) || (size & 3))
    {
        _memcpy(dst, src, size);
    }
    else
    {
        for (i = size >> 2; i != 0; --i)
        {
            *(s32 *)dst = *(s32 *)src;
            dst = (void *)(((s32 *)dst) + 1);
            src = (void *)(((s32 *)src) + 1);
        }
    }
}

/*800049A8*/
static void _memset(u8 *dst, u8 value, s32 size)
{
    s32 i;

    for (i = size; i != 0; i--)
        *dst++ = value;
}

/*800049C8*/
void Bmemset(void *dst, u8 value, u32 size)
{
    u32 i;
    s32 val;

    if ((intptr_t)dst & 3)
        _memset(dst, value, size);
    else if (size & 3)
        _memset(dst, value, size);
    else
    {
        val = value | (value << 8) | (value << 16) | value << 24;
        for (i = size >> 2; i != 0; --i)
        {
            *(s32 *)dst = val;
            dst = (void *)(((s32 *)dst) + 1);
        }
    }
}

/*80004A3C*/
void func_80004A3C(u16 sectnum)
{
    Vertex *vtx;
    s32 floorz;
    u16 floorvtxnum;
    u16 i;

    vtx = &gpVertex[gpSector[sectnum].floorvtxptr];
    floorvtxnum = gpSector[sectnum].floorvtxnum * 3;

    if (gpSector[sectnum].floorstat & 2)
    {
        for (i = 0; i < floorvtxnum; i++)
        {
            vtx->v.ob[2] = getFlorzOfSlope(sectnum, (vtx->v.ob[0] * 2), (vtx->v.ob[1] * 2)) >> 5;
            vtx++;
        }
    }
    else
    {
        floorz = gpSector[sectnum].floorz >> 5;
        if (vtx->v.ob[2] != floorz)
        {
            for (i = 0; i < floorvtxnum; i++)
            {
                vtx->v.ob[2] = floorz;
                vtx++;
            }
        }
    }
}

/*80004B60*/
void func_80004B60(u16 sectnum)
{
    Vertex *vtx;
    s32 ceilingz;
    u16 ceilingvtxnum;
    u16 i;

    vtx = &gpVertex[gpSector[sectnum].ceilingvtxptr];
    ceilingvtxnum = gpSector[sectnum].ceilingvtxnum * 3;

    if (gpSector[sectnum].ceilingstat & 2)
    {
        for (i = 0; i < ceilingvtxnum; i++)
        {
            vtx->v.ob[2] = getCeilzOfSlope(sectnum, (vtx->v.ob[0] * 2), (vtx->v.ob[1] * 2)) >> 5;
            vtx++;
        }
    }
    else
    {
        ceilingz = gpSector[sectnum].ceilingz >> 5;
        if (vtx->v.ob[2] != ceilingz)
        {
            for (i = 0; i < ceilingvtxnum; i++)
            {
                vtx->v.ob[2] = ceilingz;
                vtx++;
            }
        }
    }
}

/*80004C84*/
void func_80004C84(void)
{
    D_800BD442 = 0;
    D_800BD444 = 0;
    Bmemset(&D_80138628, 0xFF, sizeof(D_80138628));
    Bmemset(&D_80138720, 0xFF, sizeof(D_80138720));
    Bmemset(&D_801AFE20, 0xFF, sizeof(D_801AFE20));
    Bmemset(&D_8012E160, 0xFF, sizeof(D_8012E160));
}

/*80004CFC*/
static void func_80004CFC(u16 sectnum)
{
    Vertex *vtx;
    u16 vtxnum;
    u16 i, j;

    vtxnum = 0;
    vtx = NULL;

    for (i = 0; i < ARRAY_COUNT(D_80138628); i++)
    {
        if (D_80138628[i] == sectnum)
            return;
    }

    if (gpSector[sectnum].ceilingstat & 0x40)
        vtxnum += gpSector[sectnum].ceilingvtxnum * 3;

    if (gpSector[sectnum].floorstat & 0x40)
        vtxnum += gpSector[sectnum].floorvtxnum * 3;

    if (gpSector[sectnum].ceilingstat & 0x40)
        vtx = &gpVertex[gpSector[sectnum].ceilingvtxptr];

    if (gpSector[sectnum].floorstat & 0x40)
        vtx = &gpVertex[gpSector[sectnum].floorvtxptr];

    D_80138628[D_800BD442] = sectnum;
    D_80138720[D_800BD442] = D_800BD444;
    D_800BD442++;

    if (D_800BD442 > ARRAY_COUNT(D_80138628))
    {
        printf("D_800BD442: %d\n", D_800BD442);
        exit(0);
    }

    for (j = 0; j < vtxnum; j++)
    {
        D_801AFE20[D_800BD444] = vtx->v.ob[0] - D_800FF52C;
        D_8012E160[D_800BD444] = vtx->v.ob[1] - D_8016A160;
        vtx++;
        D_800BD444++;
        if (D_800BD444 > ARRAY_COUNT(D_801AFE20))
        {
            printf("D_800BD444: %d\n", D_800BD444);
            exit(0);
        }
    }
}

/*80004ECC*/
void func_80004ECC(u16 sectnum, s32 arg1, s32 arg2)
{
    D_800FF52C = arg1 / 2;
    D_8016A160 = arg2 / 2;
    func_80004CFC(sectnum);
}

/*80004F14*/
static void func_80004F14(u16 sectnum)
{
    s32 x2;
    s32 y2;
    Vertex *vtx;
    u16 vtxnum;
    u16 i, j, k;

    vtxnum = 0;
    vtx = NULL;

    if (gpSector[sectnum].ceilingstat & 0x40)
        vtxnum = gpSector[sectnum].ceilingvtxnum * 3;

    if (gpSector[sectnum].floorstat & 0x40)
        vtxnum += gpSector[sectnum].floorvtxnum * 3;

    if (gpSector[sectnum].ceilingstat & 0x40)
        vtx = &gpVertex[gpSector[sectnum].ceilingvtxptr];

    if (gpSector[sectnum].floorstat & 0x40)
        vtx = &gpVertex[gpSector[sectnum].floorvtxptr];


    for (j = 0; j < ARRAY_COUNT(D_80138628); j++)
    {
        if (D_80138628[j] == sectnum)
            goto rotate;
    }
    return;

rotate:
    k = D_80138720[j];
    for (i = 0; i < vtxnum; i++)
    {
        rotatePoint(0, 0, (2 * D_801AFE20[k]), (2 * D_8012E160[k]), D_8012DEF8 & 0x7FF, &x2, &y2);
        k++;
        vtx->v.ob[0] = (D_800FF52C + x2) / 2;
        vtx->v.ob[1] = (D_8016A160 + y2) / 2;
        vtx++;
    }
}

/*80005118*/
void func_80005118(u16 sectnum, s16 arg1, s32 arg2, s32 arg3)
{
    D_8012DEF8 = arg1;
    D_800FF52C = arg2;
    D_8016A160 = arg3;
    func_80004F14(sectnum);
}
