#include "common.h"
#include "code0/2ABE0.h"
#include "code0/4600.h"
#include "code0/pragmas.h"
#include "code0/code0.h"

/*.text*/
STATIC void func_80003B4C(f32, f32, s16);
static void func_80004CFC(u16 sectnum);
static void func_80004F14(u16 sectnum);

/*.data*/
/*800BD430*/ static u16 D_800BD430[9] = {0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80, 0x100};
/*800BD442*/ static u16 D_800BD442 = 0;
/*800BD444*/ static u16 D_800BD444 = 0;

/*.comm*/
/*800FEBA0*/ f32 D_800FEBA0[512] ALIGNED(16);
/*800FF52C*/ s32 D_800FF52C;
/*8012BBD0*/ u8 D_8012BBD0[83] ALIGNED(8);
/*8012C7A0*/ u8 D_8012C7A0[489] ALIGNED(8);
/*8012D210*/ s32 D_8012D210;
/*8012DEF8*/ s16 D_8012DEF8;
/*8012E160*/ s16 D_8012E160[1266] ALIGNED(16);
/*80138628*/ u16 D_80138628[40] ALIGNED(8);
/*80138720*/ u16 D_80138720[40] ALIGNED(8);
/*80168D20*/ f32 D_80168D20[512] ALIGNED(16);
/*80169D40*/ u16 D_80169D40[512] ALIGNED(16);
/*8016A160*/ s32 D_8016A160;
/*80197D78*/ u8 D_80197D78[83] ALIGNED(8);
/*80199758*/ u8 D_80199758[489] ALIGNED(8);
/*80199958*/ s32 D_80199958;
/*801A1988*/ s32 D_801A1988;
/*801A2630*/ u8 D_801A2630[83] ALIGNED(8);
/*801AE9C8*/ s32 D_801AE9C8;
/*801AFE20*/ s16 D_801AFE20[1266] ALIGNED(16);
/*801C0D58*/ s32 D_801C0D58;

/*80003A00*/
static f32 func_80003A00(f32 arg0)
{
    while (arg0 < 0.0f) arg0 += 2*PI;
    while (arg0 >= 2*PI) arg0 -= 2*PI;
    return arg0;
}

/*80003A74*/
static f32 func_80003A74(f32 arg0, f32 arg1)
{
    if (arg0 <= arg1)
    {
        arg1 -= arg0;
        if (arg1 <= PI)
            return arg1;
        else
            return arg1 - 2*PI;
    }
    else
    {
        arg0 -= arg1;
        if (arg0 <= PI)
            return -arg0;
        else
            return -(arg0 - 2*PI);
    }
}

/*80003B00*/
static f32 func_80003B00(f32 arg0, f32 arg1, f32 arg2, f32 arg3)
{
    return -func_80029FE0(arg3 - arg1, arg2 - arg0) + 4.712388980385/*(PI*1.5)*/;
}

/*80003B4C*/
INCLUDE_ASM("nonmatchings/src/code0/4600", func_80003B4C);

/*800042D8*/
s32 func_800042D8(s32 arg0, f32 arg1, f32 arg2)
{
    s32 i;

    for (i = 0; i < D_801A1988; i++)
    {
        if ((D_80169D40[i] == arg0) && (func_80003A74(arg1, D_800FEBA0[i]) <= 0.0f))
        {
            if (func_80003A74(arg2, D_80168D20[i]) >= 0.0f)
                return 0;
        }
    }
    return 1;
}

/*800043F4*/
void func_800043F4(s32 arg0, s32 arg1, s32 arg2, f32 arg3, s16 arg4)
{
    f32 f1, f2, f3, f4, f5;
    s16 sectnum;
    s32 i, j;

    D_8012FC40 = 1;
    f1 = (klabs(D_8016A15C) * 0.7999999999999999)/*(1/1.25)*/ + 0.6283185307179999/*(PI/5)*/;

    if (sinf(D_801AC8E0) > 0.0f)
        f2 = sinf(D_801AC8E0);
    else
        f2 = -sinf(D_801AC8E0);

    if (cosf(D_801AC8E0) > 0.0f)
        f1 *= (f2 + cosf(D_801AC8E0));
    else
        f1 *= (f2 - cosf(D_801AC8E0));

    f3 = func_80003A00((PI - arg3));
    D_801C0D58 = f3;
    D_801AE9C8 = arg0;
    D_8012D210 = arg1;
    D_80199958 = arg2;
    D_80199750 = 0;
    D_80168D10 = 0;
    D_80199528 = 0;
    D_801A1988 = 0;
    D_80138790 = 0;
    f4 = f3 - f1;
    Bmemset(D_8012C7A0, 0, sizeof(D_8012C7A0));
    Bmemset(D_80199758, 0, sizeof(D_80199758));
    Bmemset(D_8012BBD0, 0, sizeof(D_8012BBD0));
    Bmemset(D_801A2630, 0, sizeof(D_801A2630));
    Bmemset(D_80197D78, 0, sizeof(D_80197D78));
    f5 = f3 + f1;

    func_80003B4C(f4, f5, arg4);

    for (i = 0; i < ARRAY_COUNT(D_8012C7A0); i++)
    {
        if (D_8012C7A0[i] != 0)
        {
            for (j = 0; j < ARRAY_COUNT(D_800BD430)-1; j++)
            {
                if (D_8012C7A0[i] & D_800BD430[j])
                {
                    D_8013A448[D_80199750] = (i * 8) + j;
                    D_80199750++;
                }
            }
        }
    }

    for (i = 0; i < (ARRAY_COUNT(D_8012BBD0)-1); i++)
    {
        if (D_8012BBD0[i] != 0)
        {
            for (j = 0; j < ARRAY_COUNT(D_800BD430)-1; j++)
            {
                if (D_8012BBD0[i] & D_800BD430[j])
                {
                    D_801A2690[D_80199528] = (i * 8) + j;
                    D_80199528++;
                }
            }
        }
    }

    for (i = 0; i < (ARRAY_COUNT(D_801A2630)-1); i++)
    {
        if (D_801A2630[i] != 0)
        {
            for (j = 0; j < ARRAY_COUNT(D_800BD430)-1; j++)
            {
                if (D_801A2630[i] & D_800BD430[j])
                {
                    D_80199650[D_80168D10] = (i * 8) + j;
                    D_80168D10++;
                }
            }
        }
    }

    for (i = 0; i < (ARRAY_COUNT(D_80197D78)-1); i++)
    {
        if (D_80197D78[i] != 0)
        {
            for (j = 0; j < ARRAY_COUNT(D_800BD430)-1; j++)
            {
                if (D_80197D78[i] & D_800BD430[j])
                {
                    sectnum = (i * 8) + j;
                    D_800FF3E8[D_80138790] = sectnum;

                    if ((gpSector[sectnum].ceilingstat & 1) || (gpSector[sectnum].floorstat & 1))
                        D_8012FC40 = 0;

                    D_80138790++;
                }
            }
        }
    }

    D_800FF3E8[D_80138790] = 0xFFFF;
    D_80199650[D_80168D10] = 0xFFFF;
    D_801A2690[D_80199528] = 0xFFFF;
    D_8013A448[D_80199750] = 0xFFFF;
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
