#include "common.h"
#include "code0/2ABE0.h"
#include "code0/code0.h"

#define PI 3.14159265359
#define MAXUNK1 1266
#define MAXUNK2 40

/*.text*/
static void func_80004CFC(u16 secnum);
static void func_80004F14(u16 secnum);

/*.data*/
/*800BD442*/ EXTERN_DATA STATIC u16 D_800BD442;
/*800BD444*/ EXTERN_DATA STATIC u16 D_800BD444;

/*.comm*/
/*800FF52C*/ s32 D_800FF52C;
/*8012DEF8*/ s16 D_8012DEF8;
/*8012E160*/ s16 D_8012E160[MAXUNK1] ALIGNED(16);
/*80138628*/ u16 D_80138628[MAXUNK2] ALIGNED(8);
/*80138720*/ u16 D_80138720[MAXUNK2] ALIGNED(8);
/*8016A160*/ s32 D_8016A160;
/*801AFE20*/ s16 D_801AFE20[MAXUNK1] ALIGNED(16);

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
    return -func_80029FE0(arg3 - arg1, arg2 - arg0) + 4.712388980385;
}

INCLUDE_ASM("nonmatchings/src/code0/4600", func_80003B4C);

INCLUDE_ASM("nonmatchings/src/code0/4600", func_800042D8);

INCLUDE_ASM("nonmatchings/src/code0/4600", func_800043F4);

/*8000491C*/
static void _memcpy(u8 *dst, u8 *src, s32 size)
{
    s32 i;

    for (i = size; i != 0; i--)
    {
        *dst++ = *src++;
    }
}

/*80004944*/
void Bmemcpy(void *dst, void *src, u32 size)
{
    u32 i;

    if (((intptr_t)src & 3) != 0 || ((intptr_t)dst & 3) != 0 || (size & 3) != 0)
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
    {
        *dst++ = value;
    }
}

/*800049C8*/
void Bmemset(void *dst, u8 value, u32 size)
{
    u32 i;
    s32 val;

    if (((intptr_t)dst & 3) != 0)
    {
        _memset(dst, value, size);
    }
    else if ((size & 3) != 0)
    {
        _memset(dst, value, size);
    }
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
void func_80004A3C(u16 secnum)
{
    VertexType *vtx;
    s32 floorz;
    u16 floorvtxnum;
    u16 i;

    vtx = &gpVertex[gpSector[secnum].floorvtxptr];
    floorvtxnum = gpSector[secnum].floorvtxnum * 3;

    if (gpSector[secnum].floorstat & 2)
    {
        for (i = 0; i < floorvtxnum; i++)
        {
            vtx->v.ob[2] = getFlorzOfSlope(secnum, (vtx->v.ob[0] * 2), (vtx->v.ob[1] * 2)) >> 5;
            vtx++;
        }
    }
    else
    {
        floorz = gpSector[secnum].floorz >> 5;
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
void func_80004B60(u16 secnum)
{
    VertexType *vtx;
    s32 ceilingz;
    u16 ceilingvtxnum;
    u16 i;

    vtx = &gpVertex[gpSector[secnum].ceilingvtxptr];
    ceilingvtxnum = gpSector[secnum].ceilingvtxnum * 3;

    if (gpSector[secnum].ceilingstat & 2)
    {
        for (i = 0; i < ceilingvtxnum; i++)
        {
            vtx->v.ob[2] = getCeilzOfSlope(secnum, (vtx->v.ob[0] * 2), (vtx->v.ob[1] * 2)) >> 5;
            vtx++;
        }
    }
    else
    {
        ceilingz = gpSector[secnum].ceilingz >> 5;
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
static void func_80004CFC(u16 secnum)
{
    VertexType *vtx;
    u16 vtxnum;
    u16 i, j;

    vtxnum = 0;
    vtx = NULL;

    for (i = 0; i < MAXUNK2; i++)
    {
        if (D_80138628[i] == secnum)
        {
            return;
        }
    }

    if (gpSector[secnum].ceilingstat & 64)
    {
        vtxnum += gpSector[secnum].ceilingvtxnum * 3;
    }
    if (gpSector[secnum].floorstat & 64)
    {
        vtxnum += gpSector[secnum].floorvtxnum * 3;
    }
    if (gpSector[secnum].ceilingstat & 64)
    {
        vtx = &gpVertex[gpSector[secnum].ceilingvtxptr];
    }
    if (gpSector[secnum].floorstat & 64)
    {
        vtx = &gpVertex[gpSector[secnum].floorvtxptr];
    }

    D_80138628[D_800BD442] = secnum;
    D_80138720[D_800BD442] = D_800BD444;
    D_800BD442++;

    if (D_800BD442 >= (MAXUNK2+1))
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
        if (D_800BD444 >= (MAXUNK1+1))
        {
            printf("D_800BD444: %d\n", D_800BD444);
            exit(0);
        }
    }
}

/*80004ECC*/
void func_80004ECC(s32 secnum, s32 arg1, s32 arg2)
{
    D_800FF52C = arg1 / 2;
    D_8016A160 = arg2 / 2;
    func_80004CFC(secnum);
}

/*80004F14*/
static void func_80004F14(u16 secnum)
{
    s32 x2;
    s32 y2;
    VertexType *vtx;
    u16 vtxnum;
    u16 i, j, k;

    vtxnum = 0;
    vtx = NULL;

    if (gpSector[secnum].ceilingstat & 64)
    {
        vtxnum = gpSector[secnum].ceilingvtxnum * 3;
    }
    if (gpSector[secnum].floorstat & 64)
    {
        vtxnum += gpSector[secnum].floorvtxnum * 3;
    }
    if (gpSector[secnum].ceilingstat & 64)
    {
        vtx = &gpVertex[gpSector[secnum].ceilingvtxptr];
    }
    if (gpSector[secnum].floorstat & 64)
    {
        vtx = &gpVertex[gpSector[secnum].floorvtxptr];
    }

    for (j = 0; j < MAXUNK2; j++)
    {
        if (D_80138628[j] == secnum)
        {
            goto rotate;
        }
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
void func_80005118(s32 secnum, s16 arg1, s32 arg2, s32 arg3)
{
    D_8012DEF8 = arg1;
    D_800FF52C = arg2;
    D_8016A160 = arg3;
    func_80004F14(secnum);
}
