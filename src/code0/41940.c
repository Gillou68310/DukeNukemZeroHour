#include "common.h"
#include "code0/main.h"
#include "code0/audio.h"
#include "code0/engine.h"
#include "code0/pragmas.h"
#include "code0/4600.h"
#include "code0/FDE0.h"
#include "code0/1E7A0.h"
#include "code0/37090.h"
#include "code0/41940.h"
#include "code0/59D40.h"
#include "code0/6ACA0.h"
#include "code0/7BA50.h"
#include "code0/87010.h"
#include "code0/A06F0.h"
#include "code0/8EFE0.h"
#include "code0/code0.h"
#include "code1/code1.h"
#include "code1/EB300.h"

DECL_STATIC_SEG_SYM(D_0100F1E0);

typedef void (*unkFuncPointer)(s32 spritenum, s32 arg1);

typedef struct
{
    /*0x00*/ s16 unk0;  /*spritenum?*/
    /*0x02*/ s16 unk2;  /*pad?*/
    /*0x04*/ s32 unk4;  /*x?*/
    /*0x08*/ s32 unk8;  /*y?*/
    /*0x0C*/ s32 unkC;  /*z?*/
    /*0x10*/ s32 unk10; /*x?*/
    /*0x14*/ s32 unk14; /*y?*/
    /*0x18*/ s32 unk18; /*z?*/
    /*0x1C*/ u8 unk1C;
    /*0x1D*/ u8 unk1D;
} _41940UnkStruct1;

/*.data*/
/*800DEE70*/ EXTERN_DATA s16 D_800DEE70;
/*800DEE80*/ EXTERN_DATA s32 D_800DEE80; /*spritenum?*/
/*800DEE84*/ EXTERN_DATA s32 D_800DEE84;
/*800DEE88*/ EXTERN_DATA s32 D_800DEE88;
/*800DEE8C*/ EXTERN_DATA s32 D_800DEE8C;
/*800DEE98*/ EXTERN_DATA s32 D_800DEE98;
/*800DEE9C*/ EXTERN_DATA s32 D_800DEE9C;
/*800DEEA0*/ EXTERN_DATA s32 D_800DEEA0;
/*800DEEA8*/ EXTERN_DATA s32 gAiDebugGvar1;
/*800DEEAC*/ EXTERN_DATA s32 gAiDebugGvar2;
/*800DEEB0*/ EXTERN_DATA s32 gAiDebugGvar3;
/*800DEEB8*/ EXTERN_DATA s32 D_800DEEB8;
/*800DEEBC*/ EXTERN_DATA s32 D_800DEEBC;
/*800DEEC0*/ EXTERN_DATA s32 gInvulnerability;
/*800DEEC8*/ EXTERN_DATA STATIC s32 D_800DEEC8;
/*800DEED0*/ EXTERN_DATA u8 D_800DEED0[MAXPLAYERS];
/*800DEEE4*/ EXTERN_DATA u8 D_800DEEE4[MAXPLAYERS];
/*800DEEE8*/ EXTERN_DATA s32 gAutoAim;
/*800DEF10*/ EXTERN_DATA STATIC s32 D_800DEF10;
/*800DEF14*/ EXTERN_DATA STATIC s32 D_800DEF14; /*damage?*/
/*800DEF18*/ EXTERN_DATA STATIC s32 D_800DEF18; /*damage?*/
/*800DEF1C*/ EXTERN_DATA s32 D_800DEF1C;
/*800DEF20*/ EXTERN_DATA STATIC s16 D_800DEF20;
/*800DEF38*/ EXTERN_DATA STATIC s32 D_800DEF38;
/*800DEF3C*/ EXTERN_DATA STATIC unkFuncPointer D_800DEF3C[84];
/*800DF1A8*/ EXTERN_DATA s32 D_800DF1A8;
/*800DF1AC*/ EXTERN_DATA s16 D_800DF1AC[MAXPLAYERS];
/*800DF1B4*/ EXTERN_DATA s16 D_800DF1B4[9];
/*800DF1C0*/ EXTERN_DATA STATIC char *D_800DF1C0[4];

/*.comm*/
/*800FE9D4*/ s32 D_800FE9D4;
/*80137DF0*/ s16 D_80137DF0[1024] ALIGNED(16); /*spritenum array*/
/*80138718*/ s32 *gpInst;
/*80138820*/ s16 D_80138820[8] ALIGNED(8); /*sectornum array*/
/*8019955C*/ s16 D_8019955C;
/*8019B89C*/ s32 D_8019B89C; /*unused*/
/*801A1978*/ s16 D_801A1978; /*sector count*/
/*801ACC70*/ _41940UnkStruct1 D_801ACC70[32] ALIGNED(16);

/*.text*/
STATIC s32 func_80042C98(s32 spritenum);
STATIC s32 func_800433D4(s32 spritenum);
static s32 func_8004BC24(s32, s32);
static s32 func_8004EB60(s32 spritenum);
static void func_8004FA74(s32);
STATIC void func_80050E40(void);
STATIC void func_80056C00(s32);

/*80040D40*/
s32 func_80040D40(s32 x1, s32 y1, s32 x2, s32 y2)
{
    s32 x, y, a, b, c, d;

    x = klabs(x1 - x2);
    y = klabs(y1 - y2);

    if (x < y) a = y;
    else a = x;

    if (y < x) b = y;
    else b = x;

    c = a + (b >> 2);

    if (y < x) d = y;
    else d = x;

    return c + (d >> 3);
}

/*80040D94*/
s32 func_80040D94(s32 x1, s32 y1, s32 z1, s32 x2, s32 y2, s32 z2)
{
    s32 x, y, z, prev;

    x = klabs(x1 - x2);
    y = klabs(y1 - y2);
    z = klabs(z1 - z2);

    if (x < y)
    {
        prev = x;
        x = y;
        y = prev;
    }
    if (x < z)
    {
        prev = x;
        x = z;
        z = prev;
    }
    return x + ((y + z) >> 2);
}

/*80040DFC*/
u16 func_80040DFC(s32 arg0, s32 arg1, f32 arg2)
{
    s32 result;

    if (arg1 < arg0)
    {
        if ((arg0 - arg1) > 0x7FFF)
            arg1 += 0xFFFF;
    }
    else if ((arg1 - arg0) > 0x7FFF)
        arg0 += 0x10000;

    result = (arg0 * (1.0f - arg2)) + (arg1 * arg2);
    return result;
}

/*80040E90*/
s16 getAngleDelta(s16 currAngle, s16 newAngle)
{
    currAngle &= 2047;
    newAngle &= 2047;

    if (klabs(currAngle-newAngle) < 1024)
        return newAngle-currAngle;

    if (newAngle > 1024)
        newAngle -= 2048;
    if (currAngle > 1024)
        currAngle -= 2048;

    return newAngle-currAngle;
}

INCLUDE_ASM("nonmatchings/src/code0/41940", func_80040EF0);

INCLUDE_ASM("nonmatchings/src/code0/41940", func_800413CC);

/*800418B8*/
static void func_800418B8(s32 arg0)
{
    if (!(D_80137DE0->unk0 & 0x4000) && (D_80137DE0->unk20 != NULL))
    {
        if (D_80137DE0->unk24 == NULL)
        {
            D_80137DE0->unk24 = D_80137DE0->unkC;
            D_80137DE0->unk2A = D_80137DE0->unk30;
            D_80137DE0->unk2C = D_80137DE0->unk80;
            D_80137DE0->unk8A = D_80137DE0->unk86;
            D_80137DE0->unk93 = D_80137DE0->unk92;
            D_80137DE0->unk30 = 0;
            D_80137DE0->unk80 = 0;
            D_80137DE0->unkC = D_80137DE0->unk20;
        }
        if (arg0 != 0)
        {
            D_80137DE0->unkC = D_80137DE0->unk20;
            D_80137DE0->unk8A = D_80137DE0->unk86;
            D_80137DE0->unk93 = D_80137DE0->unk92;
            D_80137DE0->unk30 = 0;
            D_80137DE0->unk80 = 0;
        }
    }
}

INCLUDE_ASM("nonmatchings/src/code0/41940", func_80041968);

INCLUDE_ASM("nonmatchings/src/code0/41940", func_80041D10);

/*8004201C*/
STATIC s32 func_8004201C(s32 spritenum)
{
    s32 i;

    gpInst++;
    i = *gpInst++;
    gpInst = &gpInst[i];
    return 0;
}

/*8004204C*/
STATIC s32 func_8004204C(s32 spritenum)
{
    s32 i;

    gpInst++;
    i = *gpInst++;
    if (D_80137DE0->unk1C == NULL)
    {
        D_80137DE0->unk1C = gpInst;
        gpInst = &gpInst[i];
        return 0;
    }
    else
        return 0;
}

/*80042094*/
STATIC s32 func_80042094(s32 spritenum)
{
    gpInst++;
    gpInst = D_80137DE0->unk1C;
    D_80137DE0->unk1C = NULL;
    return 0;
}

/*800420C8*/
STATIC s32 func_800420C8(s32 spritenum)
{
    s32 i;
    s32 result;

    gpInst++;
    i = *gpInst++;
    result = getVar(spritenum, i);
    if (result != D_80137DE0->unk88)
    {
        D_80137DE0->unk86 = result | 0x8000;
        D_80137DE0->unk88 = result;
        return 0;
    }
    else
        return 0;
}

/*80042124*/
void func_80042124(code0UnkStruct3 *arg0, s32 arg1)
{
    if (arg1 != arg0->unk88)
    {
        arg0->unk86 = arg1 | 0x8000;
        arg0->unk88 = arg1;
    }
}

/*80042140*/
s32 func_80042140(s32 spritenum)
{
    code0unkStruct8 *ptr;

    ptr = &D_80197E40[D_80106D50[spritenum]];
    if (ptr->unkE == 0)
        return ptr->unk0;
    else
        return -1;
}

/*80042178*/
STATIC s32 func_80042178(s32 spritenum)
{
    gpInst++;
    gpInst = D_80137DE0->unk18;
    if (!(D_80137DE0->unk0 & 0x4000))
    {
        D_80137DE0->unk30 = D_80137DE0->unk34;
        D_80137DE0->unk80 = D_80137DE0->unk82;
        D_80137DE0->unk92 = D_80137DE0->unk93;

        if (D_80137DE0->unk86 != D_80137DE0->unk8A)
        {
            D_80137DE0->unk86 = D_80137DE0->unk8A | 0x8000;
            D_80137DE0->unk88 = -1;
        }

        D_80137DE0->unk18 = 0;
        D_80137DE0->unk8E = 0;
    }
    return 0;
}

/*80042210*/
STATIC s32 func_80042210(s32 spritenum)
{
    gpInst++;
    gpInst = D_80137DE0->unk24;
    if (!(D_80137DE0->unk0 & 0x4000))
    {
        D_80137DE0->unk24 = NULL;
        D_80137DE0->unk30 = D_80137DE0->unk2A;
        D_80137DE0->unk80 = D_80137DE0->unk2C;
        D_80137DE0->unk4 &= 0xFFFCBFF7;

        if (D_80137DE0->unk92 != 8)
            D_80137DE0->unk92 = D_80137DE0->unk93;

        if (D_80137DE0->unk86 != D_80137DE0->unk8A)
        {
            D_80137DE0->unk86 = D_80137DE0->unk8A | 0x8000;
            D_80137DE0->unk88 = -1;
        }
    }
    return 0;
}

/*800422BC*/
STATIC s32 func_800422BC(s32 spritenum)
{
    s32 i, j, result;

    i = *gpInst++;
    result = getVar(spritenum, *gpInst++);
    j = *gpInst++;

    if (i < 0)
        j += 2;

    if ((krand() >> 8) < (0xFF - result))
    {
        gpInst += j;
        if ((i && i) && i) {} /*FAKEMATCH*/
        return 0;
    }
    return 0;
}

/*80042380*/
STATIC s32 func_80042380(s32 spritenum)
{
    s32 i, j, result;

    i = *gpInst++;
    result = getVar(spritenum, *gpInst++);
    j = *gpInst++;

    if (i < 0)
        j += 2;

    if (result >= (krand() & 0x1F))
    {
        gpInst = &gpInst[j];
        return 0;
    }
    return 0;
}

/*80042434*/
STATIC s32 func_80042434(s32 spritenum)
{
    s32 i, j, result, result2, result3;

    i = *gpInst++;
    result = getVar(spritenum, *gpInst++);
    result2 = getVar(spritenum, *gpInst++);
    j = *gpInst++;

    if (i < 0)
        j += 2;

    result3 = 0;
    if ((result & 1) && (gPlayer[D_801A2628].zpos < (D_80118248->z - (result2 * 256))))
        result3 = 1;

    if ((result & 2) && (gPlayer[D_801A2628].zpos >(D_80118248->z + (result2 * 256))))
        result3 = 1;

    if (result3 == 0)
        gpInst = &gpInst[j];

    return 0;
}

INCLUDE_ASM("nonmatchings/src/code0/41940", func_80042598);

/*80042860*/
STATIC s32 ifVarVarN(s32 spritenum)
{
    s32 i, j, result, result2;

    i = *gpInst++;
    result = getVar(spritenum, *gpInst++);
    result2 = getVar(spritenum, *gpInst++);
    j = *gpInst++;

    if (i < 0)
        j += 2;

    if (result != result2)
        gpInst = &gpInst[j];

    return 0;
}

/*80042914*/
STATIC s32 ifNotVarAnd(s32 spritenum)
{
    s32 i, j, k, result;

    i = *gpInst++;
    result = getVar(spritenum, *gpInst++);
    j = *gpInst++;
    k = *gpInst++;

    if (i < 0)
        k += 2;

    if (!(result & j))
        gpInst = &gpInst[k];

    return 0;
}

/*800429B4*/
STATIC s32 ifVarVarE(s32 spritenum)
{
    s32 i, j, result, result2;

    i = *gpInst++;
    result = getVar(spritenum, *gpInst++);
    result2 = getVar(spritenum, *gpInst++);
    j = *gpInst++;

    if (i < 0)
        j += 2;

    if (result == result2)
        gpInst = &gpInst[j];

    return 0;
}

/*80042A6C*/
STATIC s32 func_80042A6C(s32 spritenum)
{
    s32 i, j, k;

    i = *gpInst++;
    j = *gpInst++;
    if (i < 0)
        j += 2;

    k = 0;
    if (D_80137DE0->unk4 & 0x40)
        k = D_8010A918 > D_80137DE0->unk64; /*TODO: addr or integer?*/

    if (k == 0)
        gpInst = &gpInst[j];
    return 0;
}

/*80042AE4*/
STATIC s32 func_80042AE4(s32 spritenum)
{
    s32 i, j;

    i = *gpInst++;
    j = *gpInst++;
    if (i < 0)
        j += 2;
    if (!D_80137DE0->unk8C)
        gpInst = &gpInst[j];
    return 0;
}

/*80042B40*/
STATIC s32 func_80042B40(s32 spritenum)
{
    s32 i, j;

    i = *gpInst++;
    j = *gpInst++;
    if (i < 0)
        j += 2;
    if (!gPlayer[0].unk45)
        gpInst = &gpInst[j];
    return 0;
}

/*80042B98*/
STATIC s32 func_80042B98(s32 spritenum)
{
    s32 i, j;

    i = *gpInst++;
    j = *gpInst++;
    if (i < 0)
        j += 2;
    if (func_80042C98(spritenum) == 0)
        gpInst = &gpInst[j];

    return 0;
}

/*80042C18*/
STATIC s32 func_80042C18(s32 spritenum)
{
    s32 i, j;

    i = *gpInst++;
    j = *gpInst++;
    if (i < 0)
        j += 2;
    if (func_800433D4(spritenum) == 0)
        gpInst = &gpInst[j];

    return 0;
}

INCLUDE_ASM("nonmatchings/src/code0/41940", func_80042C98);

INCLUDE_ASM("nonmatchings/src/code0/41940", func_800433D4);

INCLUDE_ASM("nonmatchings/src/code0/41940", func_8004364C);

/*800437F4*/
STATIC s32 func_800437F4(s32 spritenum)
{
    gpInst++;
    D_80118248->xrepeat = getVar(spritenum, *gpInst++);
    D_80118248->yrepeat = getVar(spritenum, *gpInst++);
    return 0;
}

/*80043870*/
STATIC s32 func_80043870(s32 spritenum)
{
}

/*80043878*/
STATIC s32 func_80043878(s32 spritenum)
{
    gpInst++;
    return 2;
}

/*80043894*/
STATIC s32 func_80043894(s32 spritenum)
{
    gpInst++;
    if (D_80137DE0->unk80 == 0)
    {
        D_80137DE0->unk80 = getVar(spritenum, *gpInst);
        func_8004201C(spritenum);
    }
    else
    {
        D_80137DE0->unk80--;
        if ((D_80137DE0->unk80) != 0)
            func_8004201C(spritenum);
        else
            gpInst += 2;
    }
    return 0;
}

/*80043938*/
STATIC s32 func_80043938(s32 spritenum)
{
    s32 i, j, result;

    i = *gpInst++;
    result = getVar(spritenum, *gpInst++);
    j = *gpInst++;

    if (i < 0)
        j += 2;

    if (result != D_80137DE0->unk84)
        gpInst = &gpInst[j];

    return 0;
}

/*800439D0*/
STATIC s32 func_800439D0(s32 spritenum)
{
    s32 i, j, result;

    i = *gpInst++;
    result = getVar(spritenum, *gpInst++);
    j = *gpInst++;

    if (i < 0)
        j += 2;

    if (D_801CA14C[gMapNum].unk0 != result)
        gpInst = &gpInst[j];

    return 0;
}

/*80043A74*/
STATIC s32 func_80043A74(s32 spritenum)
{
    s32 i, j, result;

    i = *gpInst++;
    result = getVar(spritenum, *gpInst++);
    j = *gpInst++;

    if (i < 0)
        j += 2;

    if (result <= D_8010A918)
        gpInst = &gpInst[j];

    return 0;
}

/*80043B10*/
STATIC s32 func_80043B10(s32 spritenum)
{
    s32 i, j, result;

    i = *gpInst++;
    result = getVar(spritenum, *gpInst++);
    j = *gpInst++;

    if (i < 0)
        j += 2;

    if (result >= D_8010A918)
        gpInst = &gpInst[j];

    return 0;
}

/*80043BAC*/
STATIC s32 func_80043BAC(s32 spritenum)
{
    s32 i, j, result, result2, result3;

    i = *gpInst++;
    result = getVar(spritenum, *gpInst++);
    result2 = getVar(spritenum, *gpInst++);
    result3 = getVar(spritenum, *gpInst++);
    j = *gpInst++;

    if (i < 0)
        j += 2;

    result = result-result2;
    if (klabs(result) >= result3)
        gpInst = &gpInst[j];

    return 0;
}

/*80043CA8*/
STATIC s32 ifVarVarLE(s32 spritenum)
{
    s32 i, j, result, result2;

    i = *gpInst++;
    result = getVar(spritenum, *gpInst++);
    result2 = getVar(spritenum, *gpInst++);
    j = *gpInst++;

    if (i < 0)
        j += 2;

    if (result <= result2)
        gpInst = &gpInst[j];

    return 0;
}

/*80043D64*/
STATIC s32 func_80043D64(s32 spritenum)
{
    s32 result;

    gpInst++;
    result = getVar(spritenum, *gpInst++);
    if (result == 0)
        D_80137DE0->unk9B = 0;
    if (result == 1)
        D_80137DE0->unk9C = 0;
    if (result == 2)
        D_80137DE0->unk9D = 0;
    return 0;
}

/*80043DE4*/
STATIC s32 func_80043DE4(s32 spritenum)
{
    s32 i, j, result;

    i = *gpInst++;
    result = getVar(spritenum, *gpInst++);
    j = *gpInst++;

    if (i < 0)
        j += 2;

    if (D_80137DE0->unk86 != result)
        gpInst = &gpInst[j];

    return 0;
}

/*80043E7C*/
STATIC s32 func_80043E7C(s32 spritenum)
{
    s32 i, j, result;
    code0unkStruct8 *ptr;

    ptr = &D_80197E40[D_80106D50[spritenum]];
    i = *gpInst++;
    result = getVar(spritenum, *gpInst++);
    j = *gpInst++;

    if (i < 0)
        j += 2;

    if (ptr->unkE)
        gpInst = &gpInst[j];
    else if ((ptr->unk0 != result))
        gpInst = &gpInst[j];

    return 0;
}

/*80043F3C*/
STATIC s32 func_80043F3C(s32 spritenum)
{
    s32 i, j, result;
    code0unkStruct8 *ptr;

    ptr = &D_80197E40[D_80106D50[spritenum]];
    i = *gpInst++;
    result = getVar(spritenum, *gpInst++);
    j = *gpInst++;

    if (i < 0)
        j += 2;

    if (ptr->unkE)
        gpInst = &gpInst[j];
    else if ((ptr->unk0 < result))
        gpInst = &gpInst[j];

    return 0;
}

/*80044000*/
STATIC s32 func_80044000(s32 spritenum)
{
    s32 i, j, result, result2, result3;

    i = *gpInst++;
    result = getVar(spritenum, *gpInst++);
    result2 = getVar(spritenum, *gpInst++);
    j = *gpInst++;

    if (i < 0)
        j += 2;

    result3 = 0;
    if ((result == 0) && (result2 < D_80137DE0->unk9B))
        result3 = 1;

    if ((result == 1) && (result2 < D_80137DE0->unk9C))
        result3 = 1;

    if ((result == 2) && (result2 < D_80137DE0->unk9D))
        result3 = 1;

    if (result3 == 0)
    {
        gpInst = &gpInst[j];
        return 0;
    }
    return 0;
}

/*80044120*/
STATIC s32 func_80044120(s32 spritenum)
{
    s32 i, j, result, result2, result3;

    i = *gpInst++;
    result = getVar(spritenum, *gpInst++);
    result2 = getVar(spritenum, *gpInst++);
    j = *gpInst++;

    if (i < 0)
        j += 2;

    result3 = 0;
    if ((result == 0) && (D_80137DE0->unk9B == result2))
        result3 = 1;

    if ((result == 1) && (D_80137DE0->unk9C == result2))
        result3 = 1;

    if ((result == 2) && (D_80137DE0->unk9D == result2))
        result3 = 1;

    if (result3 == 0)
    {
        gpInst = &gpInst[j];
        return 0;
    }
    return 0;
}

/*8004423C*/
STATIC s32 func_8004423C(s32 spritenum)
{
    s32 i, j, result;

    i = *gpInst++;
    result = getVar(spritenum, *gpInst++);
    j = *gpInst++;

    if (i < 0)
        j += 2;

    if (D_80137DE0->unk8E < result)
        gpInst = &gpInst[j];

    return 0;
}

/*800442D8*/
STATIC s32 ifVarVarAE(s32 spritenum)
{
    s32 i, j, result, result2;

    i = *gpInst++;
    result = getVar(spritenum, *gpInst++);
    result2 = getVar(spritenum, *gpInst++);
    j = *gpInst++;

    if (i < 0)
        j += 2;

    if (result >= result2)
        gpInst = &gpInst[j];

    return 0;
}

INCLUDE_ASM("nonmatchings/src/code0/41940", func_80044394);

/*80044854*/
STATIC s32 setVarVar(s32 spritenum)
{
    s32 i, result;

    gpInst++;
    i = *gpInst++;
    result = getVar(spritenum, *gpInst++);
    setVar(spritenum, i, result);
    return 0;
}

/*800448C0*/
STATIC s32 addVarVar(s32 spritenum)
{
    s32 i;
    s32 result;

    gpInst++;
    i = *gpInst++;
    result = getVar(spritenum, i);
    result += getVar(spritenum, *gpInst++);
    setVar(spritenum, i, result);
    return 0;
}

/*8004494C*/
STATIC s32 subVarVar(s32 spritenum)
{
    s32 i;
    s32 result;

    gpInst++;
    i = *gpInst++;
    result = getVar(spritenum, i);
    result -= getVar(spritenum, *gpInst++);
    setVar(spritenum, i, result);
    return 0;
}

/*800449DC*/
STATIC s32 multVarVar(s32 spritenum)
{
    s32 i;
    s32 result;

    gpInst++;
    i = *gpInst++;
    result = getVar(spritenum, i);
    result *= getVar(spritenum, *gpInst++);
    setVar(spritenum, i, result);
    return 0;
}

/*80044A78*/
STATIC s32 divVarVar(s32 spritenum)
{
    s32 i;
    s32 result;

    gpInst++;
    i = *gpInst++;
    result = getVar(spritenum, i);
    result /= getVar(spritenum, *gpInst++);
    setVar(spritenum, i, result);
    return 0;
}

INCLUDE_ASM("nonmatchings/src/code0/41940", func_80044B38);

/*80044F9C*/
STATIC s32 func_80044F9C(s32 spritenum)
{
    s32 x, y, z, a, b;

    gpInst++;
    x = getVar(spritenum, *gpInst++);
    y = getVar(spritenum, *gpInst++);
    z = getVar(spritenum, *gpInst++);
    a = getVar(spritenum, *gpInst++);
    b = getVar(spritenum, *gpInst++);
    x += D_80118248->x;
    y += D_80118248->y;
    z += D_80118248->z;
    func_8008E3E0(x, y, z, gpSprite[spritenum].sectnum, a, b);
    return 0;
}

/*800450E0*/
STATIC s32 func_800450E0(s32 spritenum)
{
    s32 x, y, z, a, b;

    gpInst++;
    x = getVar(spritenum, *gpInst++);
    y = getVar(spritenum, *gpInst++);
    z = getVar(spritenum, *gpInst++);
    a = getVar(spritenum, *gpInst++);
    b = getVar(spritenum, *gpInst++);
    x += D_80118248->x;
    y += D_80118248->y;
    z += D_80118248->z;
    func_8004BC64(x, y, z, gpSprite[spritenum].sectnum, a, b, spritenum);
    return 0;
}

/*80045228*/
STATIC s32 func_80045228(s32 spritenum)
{
    s32 x, y, z, ang, b, c, d, e, spritenum_;

    gpInst++;
    ang = getVar(spritenum, *gpInst++);
    b = getVar(spritenum, *gpInst++);
    c = getVar(spritenum, *gpInst++);
    d = getVar(spritenum, *gpInst++);
    e = getVar(spritenum, *gpInst++);

    ang += gpSprite[spritenum].ang;
    x = ((b * gpSinTable[(ang + 512) & 0x7FF]) >> 14);
    y = ((b * gpSinTable[ang & 0x7FF]) >> 14);
    z = (c * 256);

    x += D_80118248->x;
    y += D_80118248->y;
    z += D_80118248->z;

    spritenum_ = func_8008E3E0(x, y, z, gpSprite[spritenum].sectnum, d, e);
    if (spritenum_ != -1)
        gpSprite[spritenum_].ang = ang;
    return 0;
}

/*80045400*/
s32 func_80045400(s32 x, s32 y, s32 z, s32 sectnum, s32 arg4, s32 ang, s32 arg6, s32 arg7)
{
    s32 spritenum;

    x += ((arg4 * gpSinTable[(ang + 512) & 0x7FF]) >> 14);
    y += ((arg4 * gpSinTable[ang & 0x7FF]) >> 14);

    spritenum = func_8008E3E0(x, y, z, sectnum, arg6, arg7);
    gpSprite[spritenum].ang = ang;
    return spritenum;
}

/*800454BC*/
STATIC s32 andVarVar(s32 spritenum)
{
    s32 i;
    s32 result;

    gpInst++;
    i = *gpInst++;
    result = getVar(spritenum, i);
    result &= getVar(spritenum, *gpInst++);
    setVar(spritenum, i, result);
    return 0;
}

/*80045548*/
STATIC s32 modVarVar(s32 spritenum)
{
    s32 i;
    s32 result;

    gpInst++;
    i = *gpInst++;
    result = getVar(spritenum, i);
    result %= getVar(spritenum, *gpInst++);
    setVar(spritenum, i, result);
    return 0;
}

/*80045604*/
STATIC s32 orVarVar(s32 spritenum)
{
    s32 i;
    s32 result;

    gpInst++;
    i = *gpInst++;
    result = getVar(spritenum, i);
    result |= getVar(spritenum, *gpInst++);
    setVar(spritenum, i, result);
    return 0;
}

/*80045690*/
STATIC s32 func_80045690(s32 spritenum)
{
    s32 i;

    gpInst++;
    i = *gpInst++;
    D_8013B2D0[spritenum].unk2 = (D_80118248->unk1C >> 0xC) >> getVar(spritenum, i);
    return 0;
}

/*80045704*/
STATIC s32 func_80045704(s32 spritenum)
{
    s32 sfxnum, result;

    gpInst++;
    sfxnum = getVar(spritenum, *gpInst++);
    result = getVar(spritenum, *gpInst++);

    if (MusHandleAsk(D_80137DE0->unk6C) == 0)
    {
        D_80137DE0->unk6C = audio_80007A44(sfxnum, spritenum, result);
        D_80137DE0->unk74 = result;
    }
    return 0;
}

/*800457BC*/
STATIC s32 func_800457BC(s32 spritenum)
{
    s32 sfxnum, result;

    gpInst++;
    sfxnum = getVar(spritenum, *gpInst++);
    result = getVar(spritenum, *gpInst++);

    if (MusHandleAsk(D_80137DE0->unk6C) == 0)
    {
        D_80137DE0->unk74 = result;
        D_80137DE0->unk6C = audio_80007A44(sfxnum, spritenum, result);
    }
    return 0;
}

/*8004587C*/
STATIC s32 func_8004587C(s32 spritenum)
{
    musHandle handle;

    handle = D_80137DE0->unk6C;
    gpInst++;
    if (handle)
    {
        MusHandleStop(handle, 0);
        D_80137DE0->unk6C = NULL;
    }
    return 0;
}

/*800458D0*/
STATIC s32 func_800458D0(s32 spritenum)
{
    s32 sfxnum, result;

    gpInst++;
    sfxnum = getVar(spritenum, *gpInst++);
    result = getVar(spritenum, *gpInst++);

    if (MusHandleAsk(D_80137DE0->unk70) == 0)
    {
        D_80137DE0->unk70 = audio_80007A44(sfxnum, spritenum, result);
        D_80137DE0->unk78 = result;
    }
    return 0;
}

/*80045988*/
STATIC s32 func_80045988(s32 spritenum)
{
    s32 sfxnum, result;

    gpInst++;
    sfxnum = getVar(spritenum, *gpInst++);
    result = getVar(spritenum, *gpInst++);

    if (MusHandleAsk(D_80137DE0->unk70) == 0)
    {
        D_80137DE0->unk78 = result;
        D_80137DE0->unk70 = audio_80007A44(sfxnum, spritenum, result);
    }
    return 0;
}

/*80045A48*/
STATIC s32 func_80045A48(s32 spritenum)
{
    musHandle handle;

    handle = D_80137DE0->unk70;
    gpInst++;
    if (handle)
    {
        MusHandleStop(handle, 0);
        D_80137DE0->unk70 = NULL;
    }
    return 0;
}

/*80045A9C*/
STATIC s32 absVarVar(s32 spritenum)
{
    s32 i, result;

    gpInst++;
    i = *(gpInst++);
    result = getVar(spritenum, i);
    setVar(spritenum, i, klabs(result));
    return 0;
}

/*80045B04*/
STATIC s32 negVarVar(s32 spritenum)
{
    s32 i, result;

    gpInst++;
    i = *gpInst++;
    result = getVar(spritenum, i);
    setVar(spritenum, i, -result);
    return 0;
}

/*80045B64*/
STATIC s32 func_80045B64(s32 spritenum)
{
    s32 a, b, c, d;

    gpInst++;
    a = getVar(spritenum, *gpInst++);
    b = getVar(spritenum, *gpInst++);
    c = getVar(spritenum, *gpInst++);
    d = getVar(spritenum, *gpInst++);
    func_8006D3B8(spritenum, a, b, c, d);
    return 0;
}

/*80045C44*/
STATIC s32 func_80045C44(s32 spritenum)
{
    s32 i;
    s32 *ptr;

    gpInst++;
    ptr = (s32 *)GET_STATIC_SEG_SYM(D_0100F1E0);
    i = *gpInst++;
    ptr = &ptr[getVar(spritenum, i)];
    D_80137DE0->unk10 = ptr;
    return 0;
}

/*80045CB8*/
STATIC s32 func_80045CB8(s32 spritenum)
{
    s32 i;
    s32 *ptr;

    gpInst++;
    ptr = (s32 *)GET_STATIC_SEG_SYM(D_0100F1E0);
    i = *gpInst++;
    ptr = &ptr[getVar(spritenum, i)];
    D_80137DE0->unk20 = ptr;
    D_80137DE0->unk2A = 0;
    D_80137DE0->unk2C = 0;
    return 0;
}

/*80045D34*/
STATIC s32 func_80045D34(s32 spritenum)
{
    s32 i;
    s32 *ptr;

    gpInst++;
    ptr = (s32 *)GET_STATIC_SEG_SYM(D_0100F1E0);
    i = *gpInst++;
    ptr = &ptr[getVar(spritenum, i)];
    D_80137DE0->unk14 = ptr;
    return 0;
}

/*80045DA8*/
STATIC s32 func_80045DA8(s32 spritenum)
{
    s32 i;
    s32 *ptr;
    SpriteType *spr;

    gpInst++;
    ptr = (s32 *)GET_STATIC_SEG_SYM(D_0100F1E0);
    i = *gpInst++;
    spr = &gpSprite[spritenum];
    ptr = &ptr[getVar(spritenum, i)];
    *(intptr_t *)&spr->unk20 = (intptr_t)ptr; /*TODO: addr or integer?*/
    spr->unk1E = 0;
    return 0;
}

/*80045E40*/
s32 getVar(s32 spritenum, s32 id)
{
    switch (id)
    {
    case 0x40000000:
        id = D_80137DE0->unk44;
        break;
    case 0x40000001:
        id = D_80137DE0->unk48;
        break;
    case 0x40000002:
        id = D_80137DE0->unk4C;
        break;
    case 0x40000003:
        id = D_80137DE0->unk50;
        break;
    case 0x40000004:
        id = D_80137DE0->unk54;
        break;
    case 0x40000005:
        id = D_80137DE0->unk58;
        break;
    case 0x40000006:
        id = D_80137DE0->unk5C;
        break;
    case 0x40000007:
        id = D_80137DE0->unk60;
        break;
    case 0x4000000C:
        id = krand();
        break;
    case 0x4000000D:
        id = D_80137DE0->unk2E;
        break;
    case 0x4000000E:
        id = D_8013B2D0[spritenum].unk2;
        break;
    case 0x4000000A:
        id = D_80137DE0->unk0;
        break;
    case 0x40000034:
        id = D_80137DE0->unk4;
        break;
    case 0x40000011:
        id = D_8013B2D0[spritenum].unk0;
        break;
    case 0x40000020:
        id = D_8013B2D0[spritenum].unk4;
        break;
    case 0x40000010:
        id = 7296;
        id = (gPlayer[D_801A2628].zpos - (D_80118248->z - id) - (D_801B0D30 / 2)) >> 8;
        break;
    case 0x40000009:
        id = D_80118248->ang;
        break;
    case 0x40000012:
        id = D_80118248->unk25;
        break;
    case 0x40000016:
        id = D_80137DE0->unkA1;
        break;
    case 0x40000015:
        id = D_8013B2D0[spritenum].unk6;
        break;
    case 0x40000017:
        id = D_8012FD88;
        break;
    case 0x4000001B:
        id = D_80118248->cstat;
        break;
    case 0x40000018:
        id = D_80137DE0->unk8;
        break;
    case 0x4000001E:
        id = D_80137DE0->unk9A;
        break;
    case 0x40000013:
    case 0x40000019:
        id = D_80118248->unk1C;
        break;
    case 0x40000022:
        id = D_80137DE0->unk99;
        break;
    case 0x40000023:
    case 0x40000024:
        id = D_80137DE0->unk8C;
        break;
    case 0x40000025:
        id = D_80137DE0->unk98;
        break;
    case 0x40000027:
        id = D_80137DE0->unk7C;
        break;
    case 0x40000028:
        id = gAiDebugGvar1;
        break;
    case 0x40000029:
        id = gAiDebugGvar2;
        break;
    case 0x4000002A:
        id = gAiDebugGvar3;
        break;
    case 0x4000002B:
        id = D_80118248->unk1E;
        break;
    case 0x4000002C:
        id = D_80118248->unk20;
        break;
    case 0x40000031:
        id = D_80118248->unk22;
        break;
    case 0x40000026:
        id = D_80137DE0->unk68;
        break;
    case 0x40000030:
        id = D_80137DE0->unk9F;
        break;
    case 0x40000032:
        id = D_80137DE0->unk94;
        break;
    case 0x40000035:
        id = D_80137DE0->unk92;
        break;
    }
    return id;
}

/*800461E8*/
s32 setVar(s32 spritenum, s32 id, s32 value)
{
    switch (id)
    {
    case 0x40000000:
        D_80137DE0->unk44 = value;
        break;
    case 0x40000001:
        D_80137DE0->unk48 = value;
        break;
    case 0x40000002:
        D_80137DE0->unk4C = value;
        break;
    case 0x40000003:
        D_80137DE0->unk50 = value;
        break;
    case 0x40000004:
        D_80137DE0->unk54 = value;
        break;
    case 0x40000005:
        D_80137DE0->unk58 = value;
        break;
    case 0x40000006:
        D_80137DE0->unk5C = value;
        break;
    case 0x40000007:
        D_80137DE0->unk60 = value;
        break;
    case 0x4000000A:
        D_80137DE0->unk0 = value | 1;
        break;
    case 0x40000034:
        D_80137DE0->unk4 = value;
        break;
    case 0x4000000F:
        D_80137DE0->unk80 = value;
        break;
    case 0x4000000E:
        D_8013B2D0[spritenum].unk2 = value;
        break;
    case 0x40000011:
        D_8013B2D0[spritenum].unk0 = value;
        break;
    case 0x40000020:
        D_8013B2D0[spritenum].unk4 = value;
        break;
    case 0x40000012:
        D_80118248->unk25 = value;
        break;
    case 0x40000009:
        D_80118248->ang = value;
        break;
    case 0x40000015:
        D_8013B2D0[spritenum].unk6 = value;
        break;
    case 0x40000018:
        D_80137DE0->unk8 = value;
        break;
    case 0x4000001B:
        D_80118248->cstat = value;
        break;
    case 0x40000013:
    case 0x40000019:
        D_80118248->unk1C = value;
        break;
    case 0x40000021:
        D_800FE9D4 = value;
        break;
    case 0x40000022:
        D_80137DE0->unk99 = value;
        break;
    case 0x40000023:
        D_80137DE0->unk7E = value;
        if (value > 0)
            D_80137DE0->unk0 |= 0x400;
        break;
    case 0x40000024:
        D_80137DE0->unk8C = value;
        break;
    case 0x40000026:
        D_80137DE0->unk68 = value;
        break;
    case 0x40000027:
        D_80137DE0->unk7C = value;
    case 0x4000002F:
        D_800DEE8C = value;
        break;
    case 0x40000031:
        D_80118248->unk22 = value;
        break;
    case 0x4000002E:
        D_800DEE88 = value;
        break;
    case 0x40000030:
        D_80137DE0->unk9F = value;
        break;
    case 0x40000016:
        D_80137DE0->unkA1 = value;
        D_80118248->unk24 = value;
        break;
    case 0x40000032:
        D_80137DE0->unk94 = value;
        break;
    case 0x40000033:
        D_80137DE0->unkA = value;
        break;
    case 0x40000035:
        D_80137DE0->unk92 = value;
        break;
    }
    return value;
}

/*80046494*/
STATIC s32 func_80046494(s32 spritenum)
{
    gpInst++;
    switch (*gpInst++)
    {
    case 0x40000000:
    case 0x40000001:
    case 0x40000002:
    case 0x40000003:
    case 0x40000004:
    case 0x40000005:
    case 0x40000006:
    case 0x40000007:
    case 0x40000008:
    case 0x40000009:
    case 0x4000000A:
    case 0x4000000B:
    case 0x4000000D:
    case 0x4000000E:
    case 0x4000000F:
    case 0x40000010:
    case 0x40000011:
    case 0x40000012:
    case 0x40000013:
    case 0x40000014:
    case 0x40000015:
    case 0x40000016:
    case 0x40000017:
    case 0x40000018:
    case 0x40000019:
    case 0x4000001A:
    case 0x4000001B:
    case 0x4000001C:
    case 0x4000001D:
    case 0x4000001E:
    case 0x4000001F:
    case 0x40000020:
    case 0x40000021:
    case 0x40000022:
    case 0x40000023:
    case 0x40000024:
    case 0x40000025:
    case 0x40000026:
    case 0x40000027:
    case 0x40000028:
    case 0x40000029:
    case 0x4000002A:
    case 0x4000002B:
    case 0x4000002C:
    case 0x4000002D:
    case 0x4000002E:
    case 0x4000002F:
    case 0x40000030:
    case 0x40000031:
    case 0x40000032:
    case 0x40000033:
    case 0x40000034:
        break;
    case 0x40000035:
        break;
    case 0x4000000C:
        krand();
        break;
    }

    switch (*gpInst++)
    {
    case 0x40000000:
    case 0x40000001:
    case 0x40000002:
    case 0x40000003:
    case 0x40000004:
    case 0x40000005:
    case 0x40000006:
    case 0x40000007:
    case 0x40000008:
    case 0x40000009:
    case 0x4000000A:
    case 0x4000000B:
    case 0x4000000D:
    case 0x4000000E:
    case 0x4000000F:
    case 0x40000010:
    case 0x40000011:
    case 0x40000012:
    case 0x40000013:
    case 0x40000014:
    case 0x40000015:
    case 0x40000016:
    case 0x40000017:
    case 0x40000018:
    case 0x40000019:
    case 0x4000001A:
    case 0x4000001B:
    case 0x4000001C:
    case 0x4000001D:
    case 0x4000001E:
    case 0x4000001F:
    case 0x40000020:
    case 0x40000021:
    case 0x40000022:
    case 0x40000023:
    case 0x40000024:
    case 0x40000025:
    case 0x40000026:
    case 0x40000027:
    case 0x40000028:
    case 0x40000029:
    case 0x4000002A:
    case 0x4000002B:
    case 0x4000002C:
    case 0x4000002D:
    case 0x4000002E:
    case 0x4000002F:
    case 0x40000030:
    case 0x40000031:
    case 0x40000032:
    case 0x40000033:
    case 0x40000034:
        break;
    case 0x40000035:
        break;
    case 0x4000000C:
        krand();
        break;
    }
    return 0;
}

INCLUDE_ASM("nonmatchings/src/code0/41940", func_80046540);

/*80047710*/
static void func_80047710(void)
{
    s16 i, nexti;

    i = gHeadSpriteStat[64];
    while (i >= 0)
    {
        nexti = gNextSpriteStat[i];
        if (gpSprite[i].unk16 == 1)
        {
            if (gpSprite[i].unk1A <= 0)
            {
                MusHandleStop(D_8013B2D0[gpSprite[i].unk22].handle, 0);
                deleteSprite(gpSprite[i].unk22);
                gpSprite[i].unk16 = 0;
                gpSprite[i].unk18 = 60;
                gpSprite[i].unk22 = 0;
            }
            else
                gpSprite[i].unk1A--;
        }
        i = nexti;
    }
}

INCLUDE_ASM("nonmatchings/src/code0/41940", func_80047820);

INCLUDE_ASM("nonmatchings/src/code0/41940", func_800494DC);

/*8004A4D4*/
static void func_8004A4D4(SpriteType *spr, s32 arg1, s32 arg2)
{
    s32 spritenum;
    SpriteType *spr2;

    spritenum = func_80058934(spr->x, spr->y, spr->z - 2048, spr->sectnum, 160);
    if (spritenum != -1)
    {
        spr2 = &gpSprite[spritenum];
        spr2->xrepeat = 96;
        spr2->unk1E = 80;
        spr2->cstat = 0x1000;
        spr2->unk22 = 0x1234;
        spr2->unk1C = 0;
        spr2->unk18 = 0;
        spr2->unk25 = arg2;
        spr2->picnum = arg1;
        spr2->unk2B = 1;
    }
}

INCLUDE_ASM("nonmatchings/src/code0/41940", func_8004A590);

INCLUDE_RODATA("nonmatchings/src/code0/41940", D_800E5618);
INCLUDE_ASM("nonmatchings/src/code0/41940", func_8004AB6C);


/*8004B2B0*/
static void func_8004B2B0(s32 spritenum, s32 arg1, s32 arg2)
{
    SpriteType *spr;
    s16 sectnum, spritenum_;
    s16 i, nexti;
    s16 unk20, unk1E;

    unk20 = gpSprite[spritenum].unk20;
    unk1E = gpSprite[spritenum].unk1E;
    sectnum = gpSprite[spritenum].sectnum;
    spritenum_ = func_80058934(gpSprite[spritenum].x, gpSprite[spritenum].y, gpSprite[spritenum].z, sectnum, 72);

    if (spritenum_ != -1)
    {
        spr = &gpSprite[spritenum_];
        spr->picnum = 1560;
        spr->cstat = -0x8000;
        spr->unk20 = unk20;
        spr->unk1E = unk1E;

        i = gHeadSpriteStat[65];
        while (i >= 0)
        {
            nexti = gNextSpriteStat[i];
            if (gpSprite[i].sectnum == sectnum)
            {
                if (dist(spr, &gpSprite[i]) < arg1)
                    func_80047820(spritenum_, i, arg2);
            }
            i = nexti;
        }
        deleteSprite(spritenum_);
    }
}

/*8004B440*/
STATIC s32 func_8004B440(s32 spritenum)
{
    s32 i, j, k, l, m;

    i = *gpInst++;
    j = *gpInst++;

    switch (j)
    {
    case 0x40000000:
        j = D_80137DE0->unk44;
        break;
    case 0x40000001:
        j = D_80137DE0->unk48;
        break;
    case 0x40000002:
        j = D_80137DE0->unk4C;
        break;
    case 0x40000003:
        j = D_80137DE0->unk50;
        break;
    case 0x40000004:
        j = D_80137DE0->unk54;
        break;
    case 0x40000005:
        j = D_80137DE0->unk58;
        break;
    case 0x40000006:
        j = D_80137DE0->unk5C;
        break;
    case 0x40000007:
        j = D_80137DE0->unk60;
        break;
    case 0x4000000C:
        j = krand();
        break;
    case 0x4000000D:
        j = D_80137DE0->unk2E;
        break;
    case 0x4000000E:
        j = D_8013B2D0[spritenum].unk2;
        break;
    case 0x4000000A:
        j = D_80137DE0->unk0;
        break;
    case 0x40000034:
        j = D_80137DE0->unk4;
        break;
    case 0x40000011:
        j = D_8013B2D0[spritenum].unk0;
        break;
    case 0x40000020:
        j = D_8013B2D0[spritenum].unk4;
        break;
    case 0x40000010:
        j = 7296;
        j = ((gPlayer[D_801A2628].zpos - (D_80118248->z - j)) - (D_801B0D30 / 2)) >> 8;
        break;
    case 0x40000009:
        j = D_80118248->ang;
        break;
    case 0x40000012:
        j = D_80118248->unk25;
        break;
    case 0x40000016:
        j = D_80137DE0->unkA1;
        break;
    case 0x40000015:
        j = D_8013B2D0[spritenum].unk6;
        break;
    case 0x40000017:
        j = D_8012FD88;
        break;
    case 0x4000001B:
        j = D_80118248->cstat;
        break;
    case 0x40000018:
        j = D_80137DE0->unk8;
        break;
    case 0x4000001E:
        j = D_80137DE0->unk9A;
        break;
    case 0x40000013:
    case 0x40000019:
        j = D_80118248->unk1C;
        break;
    case 0x40000022:
        j = D_80137DE0->unk99;
        break;
    case 0x40000023:
    case 0x40000024:
        j = D_80137DE0->unk8C;
        break;
    case 0x40000025:
        j = D_80137DE0->unk98;
        break;
    case 0x40000027:
        j = D_80137DE0->unk7C;
        break;
    case 0x40000028:
        j = gAiDebugGvar1;
        break;
    case 0x40000029:
        j = gAiDebugGvar2;
        break;
    case 0x4000002A:
        j = gAiDebugGvar3;
        break;
    case 0x4000002B:
        j = D_80118248->unk1E;
        break;
    case 0x4000002C:
        j = D_80118248->unk20;
        break;
    case 0x40000031:
        j = D_80118248->unk22;
        break;
    case 0x40000026:
        j = D_80137DE0->unk68;
        break;
    case 0x40000030:
        j = D_80137DE0->unk9F;
        break;
    case 0x40000032:
        j = D_80137DE0->unk94;
        break;
    case 0x40000035:
        j = D_80137DE0->unk92;
        break;
    }

    k = *gpInst++;
    m = j;
    switch (k)
    {
    case 0x40000000:
        k = D_80137DE0->unk44;
        break;
    case 0x40000001:
        k = D_80137DE0->unk48;
        break;
    case 0x40000002:
        k = D_80137DE0->unk4C;
        break;
    case 0x40000003:
        k = D_80137DE0->unk50;
        break;
    case 0x40000004:
        k = D_80137DE0->unk54;
        break;
    case 0x40000005:
        k = D_80137DE0->unk58;
        break;
    case 0x40000006:
        k = D_80137DE0->unk5C;
        break;
    case 0x40000007:
        k = D_80137DE0->unk60;
        break;
    case 0x4000000C:
        k = krand();
        break;
    case 0x4000000D:
        k = D_80137DE0->unk2E;
        break;
    case 0x4000000E:
        k = D_8013B2D0[spritenum].unk2;
        break;
    case 0x4000000A:
        k = D_80137DE0->unk0;
        break;
    case 0x40000034:
        k = D_80137DE0->unk4;
        break;
    case 0x40000011:
        k = D_8013B2D0[spritenum].unk0;
        break;
    case 0x40000020:
        k = D_8013B2D0[spritenum].unk4;
        break;
    case 0x40000010:
        k = 7296;
        k = ((gPlayer[D_801A2628].zpos - (D_80118248->z - k)) - (D_801B0D30 / 2)) >> 8;
        break;
    case 0x40000009:
        k = D_80118248->ang;
        break;
    case 0x40000012:
        k = D_80118248->unk25;
        break;
    case 0x40000016:
        k = D_80137DE0->unkA1;
        break;
    case 0x40000015:
        k = D_8013B2D0[spritenum].unk6;
        break;
    case 0x40000017:
        k = D_8012FD88;
        break;
    case 0x4000001B:
        k = D_80118248->cstat;
        break;
    case 0x40000018:
        k = D_80137DE0->unk8;
        break;
    case 0x4000001E:
        k = D_80137DE0->unk9A;
        break;
    case 0x40000013:
    case 0x40000019:
        k = D_80118248->unk1C;
        break;
    case 0x40000022:
        k = D_80137DE0->unk99;
        break;
    case 0x40000023:
    case 0x40000024:
        k = D_80137DE0->unk8C;
        break;
    case 0x40000025:
        k = D_80137DE0->unk98;
        break;
    case 0x40000027:
        k = D_80137DE0->unk7C;
        break;
    case 0x40000028:
        k = gAiDebugGvar1;
        break;
    case 0x40000029:
        k = gAiDebugGvar2;
        break;
    case 0x4000002A:
        k = gAiDebugGvar3;
        break;
    case 0x4000002B:
        k = D_80118248->unk1E;
        break;
    case 0x4000002C:
        k = D_80118248->unk20;
        break;
    case 0x40000031:
        k = D_80118248->unk22;
        break;
    case 0x40000026:
        k = D_80137DE0->unk68;
        break;
    case 0x40000030:
        k = D_80137DE0->unk9F;
        break;
    case 0x40000032:
        k = D_80137DE0->unk94;
        break;
    case 0x40000035:
        k = D_80137DE0->unk92;
        break;
    }

    l = *gpInst++;
    if (i < 0)
        l += 2;
    if (func_8004BC24(m, k) < 0)
        gpInst = &gpInst[l];
    return 0;
}

/*8004BC24*/
static s32 func_8004BC24(s32 arg0, s32 arg1)
{
    if (arg1 >= arg0)
    {
        arg1 = arg1 - arg0;
        if (arg1 <= 1024)
            return arg1;
        else
            return arg1 - 2048;
    }
    else
    {
        arg0 = arg0 - arg1;
        if (arg0 <= 1024)
            return -arg0;
        else
            return 2048 - arg0;
    }
}

/*8004BC64*/
s32 func_8004BC64(s32 x, s32 y, s32 z, s32 sectnum, s32 arg4, s32 arg5, s32 arg6)
{
    SpriteType *spr;
    s32 spritenum;

    spritenum = func_80058934(x, y, z, sectnum, 1);
    if (spritenum != -1)
    {
        spr = &gpSprite[spritenum];
        spr->xrepeat = 64;
        spr->yrepeat = 64;
        spr->cstat = 0;
        spr->unk16 = arg6;
        spr->picnum = arg4;
        spr->unk25 = 0;

        if (arg4 == 2487)
            spr->unk25 = arg5;

        spr->ang = 0;
        func_800539A8(arg4, spritenum);
        return spritenum;
    }
}

/*8004BD24*/
s32 func_8004BD24(s32 spritenum)
{
    code0UnkStruct3 *ptr;
    s16 i;

    if (gpSprite[spritenum].sectnum != MAXSECTORS)
    {
        i = D_80106D50[spritenum];
        if (i != -1)
        {
            ptr = &D_8019B940[i];
            if (ptr->unk6C != 0)
            {
                MusHandleStop(ptr->unk6C, 0);
                ptr->unk6C = 0;
            }
            if (ptr->unk70 != 0)
            {
                MusHandleStop(ptr->unk70, 0);
                D_80137DE0->unk70 = 0;
            }
            ptr->unk0 = 0;
            D_80106D50[spritenum] = -1;
        }
        else
        {
            gpSprite[spritenum].unk16 = -1;
        }
        deleteSprite(spritenum);
    }
    return -1;
}

/*8004BE20*/
STATIC s32 func_8004BE20(s32 spritenum)
{
    changeSpriteStat(spritenum, 0);
    return -1;
}

/*8004BE48*/
STATIC s32 func_8004BE48(s32 spritenum)
{
    unkFuncPointer func;
    s32 i;

    gpInst++;
    func = (unkFuncPointer)*gpInst++;
    func(spritenum, *gpInst++);
    return 0;
}

/*8004BE90*/
s32 func_8004BE90(void)
{
    s32 i, j;

    i = 0;
    j = D_800DEEC8;
    while (D_8019B940[j].unk0 & 1)
    {
        j++;
        i++;
        if (j >= ARRAY_COUNT(D_8019B940))
            j = 0;

        if (i > ARRAY_COUNT(D_8019B940))
            break;
    }

    if (i > ARRAY_COUNT(D_8019B940))
        return -1;
    else
    {
        D_800DEEC8 = j;
        Bmemset(&D_8019B940[j], 0, sizeof(code0UnkStruct3));
        D_8019B940[j].unk38 = -1;
        D_8019B940[j].unk3C = -1;
        D_8019B940[j].unk40 = -1;
        D_8019B940[j].unk0 = 1;
        D_8019B940[j].unk88 = -1;
        D_8019B940[j].unk84 = -1;
        D_8019B940[j].unk28 = -1;
        return j;
    }
}

INCLUDE_ASM("nonmatchings/src/code0/41940", func_8004BFDC);

INCLUDE_ASM("nonmatchings/src/code0/41940", func_8004CB3C);

/*8004CC90*/
s32 func_8004CC90(s32 spritenum, s32 arg1, s32 arg2)
{
    if ((gpSprite[spritenum].statnum == 58)
         && (((arg1 == 19) || (arg1 == 13))
             || ((arg1 == 12) || (arg1 == 10))
             || ((arg1 == 32) || (arg1 == 8))
             || ((arg1 == 18) || (arg1 == 14))
             || ((arg1 == 21) || (arg2 == 1560))))
    {
        if (gpSprite[spritenum].unk20 != 0)
        {
            if (gpSprite[spritenum].unk25 == 1)
            {
                D_800DEE98 = gpSprite[spritenum].unk25;
                func_80050E40();
            }
            func_8006B590(gpSprite[spritenum].unk20);
            deleteSprite(spritenum);
            return -1;
        }
    }
    return 0;
}

/*8004CDE0*/
s32 dist(SpriteType *s1, SpriteType *s2)
{
    return findDistance3D((s1->x - s2->x), (s1->y - s2->y), (s1->z - s2->z) >> 4);
}

/*8004CE24*/
s32 ldist(SpriteType *s1, SpriteType *s2)
{
    return findDistance2D((s1->x - s2->x), (s1->y - s2->y)) + 1;
}

INCLUDE_RODATA("nonmatchings/src/code0/41940", D_800E58F4);
INCLUDE_ASM("nonmatchings/src/code0/41940", func_8004CE58);

INCLUDE_ASM("nonmatchings/src/code0/41940", func_8004D304);

/*8004D65C*/
STATIC void func_8004D65C(s32 spritenum)
{
    s16 i, nexti;
    s32 unk20;
    u16 unk1E;

    spritenum &= 0xFFFF;
    if (spritenum & 0xC000)
    {
        spritenum -= 0xC000;
        if (spritenum >= 0)
        {
            if ((gpSprite[spritenum].statnum == 4) && (gpSprite[spritenum].unk1E == 102))
            {
                i = gHeadSpriteStat[4];
                unk20 = gpSprite[spritenum].unk20;
                while (i > 0)
                {
                    nexti = gNextSpriteStat[i];
                    if (gpSprite[i].unk20 == unk20)
                    {
                        unk1E = gpSprite[i].unk1E;
                        if ((u16)(unk1E - 101) < 2)
                        {
                            if ((s16)unk1E == 101)
                            {
                                D_80106D50[i] = -1;
                                D_8019B89C = 0;
                            }
                            deleteSprite(i);
                        }
                    }
                    i = nexti;
                }
                D_8019B940[D_80106D50[unk20]].unk5C = 1;
            }
        }
    }
}

/*8004D7D8*/
s32 func_8004D7D8(s32 spritenum)
{
    s16 ret;

    if (gpSprite[spritenum].statnum == 53)
        return 1;

    if (gpSprite[spritenum].statnum == 10)
        return 1;

    if (D_80106D50[spritenum] == -1)
        return 0;

    ret = 0;
    switch (D_8019B940[D_80106D50[spritenum]].unk84)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 6:
    case 7:
    case 8:
    case 9:
    case 11:
    case 15:
    case 17:
    case 18:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 41:
    case 42:
    case 43:
        ret = 1;
    }
    return ret;
}

INCLUDE_ASM("nonmatchings/src/code0/41940", func_8004D884);

INCLUDE_ASM("nonmatchings/src/code0/41940", func_8004DC74);

INCLUDE_ASM("nonmatchings/src/code0/41940", func_8004DE60);

INCLUDE_ASM("nonmatchings/src/code0/41940", func_8004E5F8);

/*8004E7F0*/
s32 func_8004E7F0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                  s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9)
{
    s32 ret;

    D_801ACC70[D_800DEF38].unk2 = arg9;
    D_801ACC70[D_800DEF38].unk0 = D_800DEF38 + arg8;
    D_801ACC70[D_800DEF38].unk4 = arg0;
    D_801ACC70[D_800DEF38].unk8 = arg1;
    D_801ACC70[D_800DEF38].unkC = arg2;
    D_801ACC70[D_800DEF38].unk10 = arg3;
    D_801ACC70[D_800DEF38].unk14 = arg4;
    D_801ACC70[D_800DEF38].unk18 = arg5;
    D_801ACC70[D_800DEF38].unk1C = arg6;
    D_801ACC70[D_800DEF38].unk1D = arg7;
    ret = D_800DEF38 + arg8;
    D_800DEF38++;
    D_800DEF38 &= 31;
    return ret;
}

#ifdef NON_MATCHING
STATIC void func_8004E8BC(void)
{
    _41940UnkStruct1 *ptr;
    s32 i;

    ptr = D_801ACC70;
    i = 0;
    do
    {
        if (ptr->unk0 != 0)
        {
            func_800867CC(ptr->unk0,
                          D_801ACC70[i].unk10,
                          D_801ACC70[i].unk14,
                          D_801ACC70[i].unk18,
                          D_801ACC70[i].unk4,
                          D_801ACC70[i].unk8,
                          D_801ACC70[i].unkC,
                          D_801ACC70[i].unk1D,
                          D_801ACC70[i].unk1C);
        }
        if (ptr->unk2-- == 0)
            ptr->unk0 = 0;

        ptr++;
        i++;
    } while ((intptr_t)ptr < (intptr_t)&D_801ACC70[32]);
}
#else
/*8004E8BC*/
INCLUDE_ASM("nonmatchings/src/code0/41940", func_8004E8BC);
#endif

/*8004E9B4*/
static void func_8004E9B4(s32 spritenum)
{
    audio_80007820(704, spritenum);
    changeSpriteStat(spritenum, 1);
    gpSprite[spritenum].cstat = (gpSprite[spritenum].cstat & 0x7FFF) | 0x101;
    D_8013B2D0[spritenum].unk6 = 0xFF;
}

/*8004EA40*/
void func_8004EA40(s32 spritenum)
{
    if (D_800DF1A8 == -1)
    {
        if (func_8004EB60(spritenum) != 0)
        {
            D_800DF1A8 = spritenum;
        }
        else
        {
            func_8008E3E0(gpSprite[spritenum].x, gpSprite[spritenum].y,
                          gpSprite[spritenum].z, gpSprite[spritenum].sectnum, 43, 0);
            func_8004E9B4(spritenum);
        }
    }
    else if (func_8004EB60(D_800DF1A8) == 0)
    {
        func_8008E3E0(gpSprite[D_800DF1A8].x, gpSprite[D_800DF1A8].y,
                      gpSprite[D_800DF1A8].z, gpSprite[D_800DF1A8].sectnum, 43, 0);
        func_8004E9B4(D_800DF1A8);
        D_800DF1A8 = -1;
    }
}

/*8004EB60*/
static s32 func_8004EB60(s32 spritenum)
{
    s32 x, y;

    x = klabs_(gpSprite[spritenum].x - gPlayer[0].xpos);
    y = klabs_(gpSprite[spritenum].y - gPlayer[0].ypos);
    if ((x + y) < 500)
        return -1;
    else
        return 0;
}

/*8004EBE4*/
static void func_8004EBE4(s32 spritenum)
{
    audio_80007820(krand() % 4 + 577, spritenum);
}

/*8004EC38*/
void func_8004EC38(void)
{
    s16 i;

    for (i = 0; i < D_8012C470; i++)
    {
        if (D_800DEEE4[i])
        {
            if ((u8)(D_800DEEE4[i] - 6) >= 4)
            {
                if (D_800DEEE4[i] < 5)
                    D_800DF1AC[i] += 64;
                if (D_800DF1AC[i] > 255)
                    D_800DF1AC[i] = 255;
                else
                    D_800DF1AC[i] -= 8;
            }
            D_800DEEE4[i]++;
            if (D_800DF1AC[i] < 0)
            {
                D_800DF1AC[i] = 0;
                D_800DEEE4[i] = 0;
            }
        }
    }
}

/*8004ED40*/
static void func_8004ED40(s32 spritenum)
{
    code0unkStruct8 *ptr;
    s32 ang;
    s32 unk18;
    s32 x, y, z;

    ptr = &D_80197E40[D_80106D50[spritenum]];
    unk18 = gpSector[D_80118248->sectnum].unk18;
    if (unk18 == 3)
    {
        z = func_80036490(D_80118248->sectnum);
        if ((z < D_80118248->z) && ((D_80118248->z - 8192) < z) && (D_80137DE0->unk0 & 2) && (D_80137DE0->unk97 != 0))
        {
            x = D_80118248->x;
            y = D_80118248->y;
            ang = D_80118248->ang;

            if (ptr->unk0 == 10)
            {
                func_80045400(x, y, z, D_80118248->sectnum, 60, ang - 512, unk18, 0);
                func_80045400(x, y, z, D_80118248->sectnum, 60, ang - 512, 28, 0);
                audio_800077F4(((krand() % 3) + 525), spritenum);
            }

            if (ptr->unk0 == 28)
            {
                func_80045400(x, y, z, (s32)D_80118248->sectnum, 60, ang + 512, unk18, 0);
                func_80045400(x, y, z, (s32)D_80118248->sectnum, 60, ang + 512, 28, 0);
                audio_800077F4(((krand() % 3) + 525), spritenum);
            }
        }
    }
}


/*8004EFB4*/
s32 func_8004EFB4(s32 spritenum)
{
    SpriteType *spr;

    if (gpSector[gpSprite[spritenum].sectnum].unk18 == 2)
        return 1;

    spr = &gpSprite[spritenum];
    if (gpSector[spr->sectnum].unk18 == 3)
    {
        if (func_80036490(spr->sectnum) < spr->z)
            return 1;
    }
    return 0;
}

INCLUDE_ASM("nonmatchings/src/code0/41940", func_8004F044);

/*8004F284*/
static s32 func_8004F284(SpriteType *spr, s32 *arg1, s32 spritenum)
{
    *arg1 = klabs(gpSprite[spritenum].x - spr->x)
        + klabs(gpSprite[spritenum].y - spr->y)
        + (klabs(gpSprite[spritenum].z - spr->z) >> 4);

    return 0;
}

/*8004F31C*/
void func_8004F31C(void)
{
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_8019B940); i++)
        Bmemset(&D_8019B940[i], 0, sizeof(code0UnkStruct3));

    D_800DEEB8 = 0;
    D_800DEEBC = -1;
    D_800DF1A8 = -1;
    D_80138690 = 0;
    D_800DEEC8 = 0;
    D_800DEF10 = 0;
    D_800DEF1C = -1;

    for (i = 0; i < ARRAY_COUNT(D_8012FCB0); i++)
    {
        D_8012FCB0[i][0] = 0;
        D_80138858[i] = 0;
    }

    for (i = 0; i < ARRAY_COUNT(D_80106D50); i++)
    {
        D_80106D50[i] = -1;
        D_8013B2D0[i].unk2 = 0;
        D_8013B2D0[i].unk0 = 0;
        D_8013B2D0[i].unk4 = 0;
        D_8013B2D0[i].unk6 = 0;
        D_8013B2D0[i].handle = 0;
    }

    if (D_800DEEA0 == 0)
        D_800DEF20 = 0x10;
    else
        D_800DEF20 = 0x40;

    D_8019955C = 0;

    for (i = 0; i < D_800DEF20; i++)
        D_80137DF0[i] = -1;
}

/*8004F4A0*/
s32 func_8004F4A0(s32 spritenum)
{
    s16 hitsect, hitwall, hitsprite;
    s32 hitx, hity, hitz;

    s16 ang;
    s32 ret;
    u16 cstat;

    cstat = gpSprite[spritenum].cstat;
    ang = (gpSprite[spritenum].ang - 1024) & 0x7FF;
    gpSprite[spritenum].cstat = cstat & 0xFEFE;

    hitScan(gpSprite[spritenum].x,
            gpSprite[spritenum].y,
            gpSprite[spritenum].z - 0x1000,
            gpSprite[spritenum].sectnum,
            gpSinTable[(ang + 512) & 0x7FF],
            gpSinTable[ang],
            0,
            &hitsect,
            &hitwall,
            &hitsprite,
            &hitx,
            &hity,
            &hitz,
            0x01000040);

    ret = -1;
    gpSprite[spritenum].cstat = cstat;
    if (hitwall != -1)
        ret = klabs_(gpSprite[spritenum].x - hitx) + klabs_(gpSprite[spritenum].y - hity);

    return ret;
}

/*8004F5DC*/
static void func_8004F5DC(void)
{
    s32 i, nexti;
    SpriteType *spr;

    i = gHeadSpriteStat[55];
    while (i >= 0)
    {
        nexti = gNextSpriteStat[i];
        spr = &gpSprite[i];
        if (spr->picnum == 2290)
        {
            spr->x += (gpSinTable[(spr->ang + 512) & 0x7FF] * 5) >> 11;
            spr->y += (gpSinTable[spr->ang & 0x7FF] * 5) >> 11;
            D_8013B2D0[i].unk4++;
            spr->unk22++;
            if (spr->unk22 >= 600)
                deleteSprite(i);
        }
        i = nexti;
    }
}

/*8004F704*/
static void func_8004F704(s16 arg0)
{
    s32 a, b;
    s32 x, y, z;
    s32 spritenum;

    if ((D_80137DE0->unk95 < 6) && ((D_8012FD88 & 3) == 3))
    {
        z = D_80118248->z;
        x = D_80118248->x;
        y = D_80118248->y;

        z -= ((krand() % 25) * 256);
        a = krand() & 0x7FF;
        b = (krand() & 0x7F) + 50;
        spritenum = func_80045400(x, y, z, D_80118248->sectnum, b, a, 38, (krand() & 0x1F) + 0x1F);

        if (spritenum != -1)
        {
            gpSprite[spritenum].unk1E = arg0;
            D_8013B2D0[spritenum].unk6 = (krand() & 0x1F) + 0x40;
            gpSprite[spritenum].xrepeat += (krand() & 0x1F) - 0xF;
            gpSprite[spritenum].yrepeat += (krand() & 0x1F) - 0xF;
        }
        D_80137DE0->unk95++;
    }
}

/*8004F8D0*/
static void func_8004F8D0(s32 arg0)
{
    SpriteType *spr;
    s16 i, nexti;
    s32 j;

    if (D_8012F6E8 == 0)
    {
        i = gHeadSpriteStat[666];
        while (i >= 0)
        {
            nexti = gNextSpriteStat[i];
            spr = &gpSprite[i];
            if (spr->unk1C == 1)
            {
                if (D_80118248->sectnum == spr->sectnum)
                {
                    switch (spr->unk22)
                    {
                    case 0:
                        if (D_80137DE0->unk0 & 4)
                            func_8004FA74(arg0);
                        break;

                    case 1:
                        j = klabs(gpSector[D_80118248->sectnum].floorz - D_80118248->z);
                        j = 0x4000 - j;
                        if (j > 0)
                            func_8004FA74(arg0);
                        break;

                    default:
                        func_8004FA74(arg0);
                    }
                }
            }
            else
            {
                if (func_80040D94(gpSprite[arg0].x,
                    gpSprite[arg0].y,
                    gpSprite[arg0].z / 16,
                    spr->x,
                    spr->y,
                    spr->z / 16) < spr->unk22)
                {
                    func_8004FA74(arg0);
                }
            }
            i = nexti;
        }
    }
}

/*8004FA74*/
static void func_8004FA74(s32 arg0)
{
    (void)arg0;

    D_80137DE0->unk96++;
    if ((D_80137DE0->unk0 & 0x20000) != 0)
    {
        if (D_80137DE0->unk96 < 120)
            D_80137DE0->unk96++;
    }
    else if (D_80137DE0->unk96 > 60)
    {
        D_80137DE0->unk0 |= 0x20000;
    }
}

/*8004FAD8*/
void func_8004FAD8(s32 spritenum)
{
    s32 x, y, z;
    s32 i;

    if (gMapNum == 0x11)
    {
        func_80045400(gpSprite[spritenum].x,
                      gpSprite[spritenum].y,
                      gpSprite[spritenum].z - 16000,
                      gpSprite[spritenum].sectnum, 0,
                      gpSprite[spritenum].ang, 44, 130);

        func_80045400(gpSprite[spritenum].x,
                      gpSprite[spritenum].y,
                      gpSprite[spritenum].z - 8000,
                      gpSprite[spritenum].sectnum, 0,
                      gpSprite[spritenum].ang, 44, 130);
    }
    else
    {
        for (i = 0; i < 6; i++)
        {
            x = ((krand() & 0x7F) - 0x3F) * 4;
            y = ((krand() & 0x7F) - 0x3F) * 4;
            z = ((krand() & 0x7F) + 0x20) * 256;
            func_8008E3E0(gpSprite[spritenum].x + x,
                          gpSprite[spritenum].y + y,
                          gpSprite[spritenum].z - z,
                          gpSprite[spritenum].sectnum, 13, 0);
        }
    }
}

/*8004FC4C*/
void func_8004FC4C(void)
{
    s16 i, nexti;

    i = gHeadSpriteStat[57];
    while (i >= 0)
    {
        nexti = gNextSpriteStat[i];
        if (gpSprite[i].unk1E <= 0)
        {
            switch (gpSprite[i].unk25)
            {
            case 0:
                func_8008E3E0(gpSprite[i].x, gpSprite[i].y, gpSprite[i].z, gpSprite[i].sectnum, 41, 32);
                break;
            case 1:
                func_8004AB6C(i, 2048, 25, 50, 75, 100, 0);
                func_8008E3E0(gpSprite[i].x, gpSprite[i].y, gpSprite[i].z, gpSprite[i].sectnum, 41, 32);
                func_8001F7B4(10, 6);
                audio_80007A44(560, i, 40000);
                break;
            case 2:
                func_8008E3E0(gpSprite[i].x, gpSprite[i].y, gpSprite[i].z, gpSprite[i].sectnum, 68, 33);
                break;
            case 3:
                func_8004BFDC(i, 4, gpSprite[i].z, 1);
                break;
            case 4:
                func_8008E3E0(gpSprite[i].x, gpSprite[i].y, gpSprite[i].z, gpSprite[i].sectnum, 80, 0);
                playSfx(1648);
                func_8003671C(0, 500, -1, -1);
                func_8001F7B4(100, 12);
                break;
            }
            deleteSprite(i);
        }
        else
            gpSprite[i].unk1E--;

        i = nexti;
    }
}

/*8004FF08*/
void func_8004FF08(void)
{
    s32 i, nexti, temp;

    i = gHeadSpriteStat[59];
    while (i >= 0)
    {
        D_800FE400 = i;
        D_80137DE0 = &D_8019B940[D_80106D50[i]];
        D_80118248 = &gpSprite[i];
        D_8012F6E8 = func_8005A240(i);
        func_8004D884();
        func_8004DC74();
        nexti = gNextSpriteStat[i];
        gpSprite[i].unk22++;
        gpSprite[i].cstat |= 0x101;

        if (gpSprite[i].unk22 >= 90)
        {
            audio_80007A44(641, i, 36000);
            temp = gpSprite[i].z - 16000; /*FAKEMATCH*/
            func_80045400(gpSprite[i].x, gpSprite[i].y, gpSprite[i].z - 16000, gpSprite[i].sectnum, 0, gpSprite[i].ang, 44, 3);
            func_80045400(gpSprite[i].x, gpSprite[i].y, gpSprite[i].z - 8000, gpSprite[i].sectnum, 0, gpSprite[i].ang, 44, 3);
            func_8008E3E0(gpSprite[i].x, gpSprite[i].y, gpSprite[i].z - 2048, gpSprite[i].sectnum, 18, 0);

            temp = D_8019B940[D_80106D50[i]].unk84;
            if (D_801C0D70[temp].unk0 != -1)
            {
                func_80057540(&gpSprite[i], D_801C0D70[temp].unk0, 1, 4660);
                func_80057540(&gpSprite[i], D_801C0D70[temp].unk2, 1, 4660);
                func_80057540(&gpSprite[i], D_801C0D70[temp].unk4, 1, 4660);
                func_80057540(&gpSprite[i], D_801C0D70[temp].unk6, 1, 4660);
            }

            D_80137DE0->unk0 = 0;
            D_80106D50[i] = -1;
            audio_800080E0(0, 6);

            if ((gpSprite[i].cstat & 8) == 0)
                D_801A1958.enemies_killed++;

            deleteSprite(i);
        }
        else
        {
            if (gpSprite[i].unk22 == 30)
                audio_80007A44(D_800DF1B4[krand() & 3], i, 24000);

            if (gpSprite[i].unk22 == 60)
                audio_80007A44(D_800DF1B4[krand() & 3], i, 24000);
        }
        i = nexti;
    }
}

/*800502A0*/
void func_800502A0(void)
{
    s32 i, j, k;

    if (gPlayer[0].unk36 >= 4096)
    {
        j = gPlayer[0].unk36 - 4096;
        if (gPlayer[0].unk59 && (gpSprite[j].statnum == 64))
        {
            i = gHeadSpriteStat[64];
            while (i >= 0)
            {
                if (j == i)
                {
                    if (gpSprite[i].unk16 == 0)
                    {
                        k = func_80058934(gpSprite[i].x, gpSprite[i].y, gpSprite[i].z, gpSprite[i].sectnum, 110);
                        gpSprite[k].picnum = 5;
                        gpSprite[k].unk1A = 18000;
                        gpSprite[k].unk25 = 0xff;
                        gpSprite[k].unk1E = 32;
                        gpSprite[k].unk18 = 0;
                        gpSprite[k].unk1C = 0;
                        gpSprite[i].unk16 = 1;
                        gpSprite[i].unk22 = k;
                        gpSprite[i].unk1A = 450;
                        break;
                    }
                }
                i = gNextSpriteStat[i];
            }
        }
    }
}

/*80050408*/
void func_80050408(void)
{
    switch (D_801CE498.difficulty)
    {
    case 0:
        D_800DEF14 = 200;
        D_800DEF18 = 25;
        break;
    case 1:
        D_800DEF14 = 150;
        D_800DEF18 = 75;
        break;
    case 2:
        D_800DEF14 = 100;
        D_800DEF18 = 100;
        break;
    }
}

/*80050480*/
static void func_80050480(s16 arg0, s16 spritenum)
{
    switch (arg0)
    {
    case 0:
    case 9:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 18:
    case 19:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 27:
    case 28:
        audio_80007A44(1357, spritenum, 40000);
        break;
    case 1:
    case 10:
    case 17:
    case 20:
    case 26:
    case 29:
        audio_80007A44(1363, spritenum, 40000);
        break;
    case 2:
    case 11:
        audio_80007A44(1356, spritenum, 40000);
        break;
    case 3:
    case 4:
    case 6:
    case 7:
        audio_80007A44(1365, spritenum, 40000);
        break;
    case 5:
    case 8:
        audio_80007A44(1364, spritenum, 40000);
        break;
    }
}

INCLUDE_RODATA("nonmatchings/src/code0/41940", D_800E5A40);
INCLUDE_RODATA("nonmatchings/src/code0/41940", D_800E5A54);
INCLUDE_RODATA("nonmatchings/src/code0/41940", D_800E5A60);
INCLUDE_RODATA("nonmatchings/src/code0/41940", D_800E5A6C);

INCLUDE_ASM("nonmatchings/src/code0/41940", func_800504F4);

INCLUDE_ASM("nonmatchings/src/code0/41940", func_8005087C);

INCLUDE_ASM("nonmatchings/src/code0/41940", func_80050C14);

INCLUDE_ASM("nonmatchings/src/code0/41940", func_80050E40);

INCLUDE_ASM("nonmatchings/src/code0/41940", func_80051088);

/*80051330*/
static void func_80051330(void)
{
    s32 i, nexti;
    s32 ret;
    s32 d1, d2;

    ret = -1;
    d2 = 0x200000;
    if ((D_80137DE0->unk0 & 0x800) && ((D_80137DE0->unk28 == -1) || (gpSprite[D_80137DE0->unk28].statnum != 1)))
    {
        klabs_(D_80118248->x - gPlayer[0].xpos);
        klabs_(D_80118248->y - gPlayer[0].ypos);
        i = gHeadSpriteStat[1];

        while (i >= 0)
        {
            nexti = gNextSpriteStat[i];
            d1 = klabs_(D_80118248->x - gpSprite[i].x) + klabs_(D_80118248->y - gpSprite[i].y);
            if (d1 < 22000)
            {
                if ((d1 < d2) && (func_8004D7D8(i) != 0))
                {
                    d2 = d1;
                    ret = i;
                }
            }
            i = nexti;
        }

        D_80137DE0->unk28 = ret;
    }
}

/*800514C8*/
void func_800514C8(void)
{
    func_80056C00(gPlayer[0].unk4A);
    if (gPlayer[0].unk52 >= 0)
        func_80056C00(gPlayer[0].unk52 & 0x7FF);
}

/*80051508*/
s32 func_80051508(s32 ang1, s32 ang2, s32 arg2)
{
    ang1 = (ang1 << 16) + (getAngleDelta(ang1, ang2) << (16 - arg2));
    ang1 = (ang1 >> 16);
    return ang1 & 0x7FF;
}

/*80051568*/
void func_80051568(void)
{
    s32 i;
    s16 unused;

    for (i = 0; i < MAXSPRITES; i++)
    {
        if (D_80106D50[i] != -1)
            unused++;
        else if (gpSprite[i].x != -1)
            unused++;
    }
}

/*800515A0*/
static void func_800515A0(s16 sectnum)
{
    s16 i;

    D_80138820[0] = sectnum;
    D_801A1978 = 1;

    for (i = gpSector[sectnum].wallptr; i < gpSector[sectnum].wallptr + gpSector[sectnum].wallnum; i++)
    {
        if (D_801A1978 >= 8)
            break;

        if (gpWall[i].nextsector != -1)
            D_80138820[D_801A1978++] = gpWall[i].nextsector;
    }
}

/*80051684*/
static s32 func_80051684(s16 sectnum)
{
    s16 i;

    for (i = 0; i < D_801A1978; i++)
    {
        if (D_80138820[i] == sectnum)
            return 1;
    }
    return 0;
}

/*800516EC*/
static s32 func_800516EC(s16 spritenum)
{
    SpriteType *spr;
    u8 ret;

    ret = 0;
    spr = &gpSprite[spritenum];
    if (spr->picnum >= 1559)
    {
        if (spr->picnum < 1562)
        {
            func_800A419C(0, D_800DF1C0[spr->picnum-1559]);
            func_8006B590(spr->unk20);
            ret = 1;
        }
        else if (spr->picnum < 2483)
        {
            if (spr->picnum >= 2469)
            {
                audio_800080E0(0, 16);
                gTimeMachinePart |= 1 << gMapNum;
                func_800A419C(0, D_800DF1C0[3]);
                ret = 1;
            }
        }
    }
    if (ret != 0)
    {
        audio_800077F4(695, spritenum);
        deleteSprite(spritenum);
    }
    return ret;
}

/*80051808*/
static void func_80051808(s16 spritenum)
{
    s16 unk25;

    unk25 = gpSprite[spritenum].unk25;
    if (gMapNum == MAP_NUCLEAR_WINTER)
    {
        if ((u16)(unk25 - 1) < 3)
            func_8006B4E4(unk25 + 1);

        if ((D_801AE91E[2] == 68) && (D_801AE91E[3] == D_801AE91E[2]) && (D_801AE91E[4] == D_801AE91E[3]))
        {
            D_801AE91E[5] = 67;
            D_801AE91E[6] = 70;
            func_8006B590(8765);
        }
    }

    if (gMapNum == MAP_DRY_TOWN)
    {
        if (unk25 == 3)
            func_8006B590(351);
    }

    if (gMapNum == MAP_HYDROGEN_BOMB)
    {
        if (unk25 == 1)
            func_8006B4E4(2);
    }

    if (gMapNum == MAP_THE_RACK)
    {
        if (unk25 == 3)
            audio_80008574(0, 1506);
        if (unk25 == 4)
            audio_80008574(0, 1509);
    }

    if (gMapNum == MAP_ALIEN_MOTHER)
    {
        if (unk25 == 1)
            audio_80008574(0, 1510);
        if (unk25 == 2)
            func_8006B4E4(2);
    }
}

INCLUDE_ASM("nonmatchings/src/code0/41940", func_800519AC);

INCLUDE_ASM("nonmatchings/src/code0/41940", func_80052358);

/*800524BC*/
static void func_800524BC(s16 arg0, s16 arg1, s16 arg2)
{
    s16 i, j;

    if (arg2 != 0)
    {
        i = arg1 - 3;
        j = 0;
        switch (i)
        {
        case 1:
            j = 24;
            break;
        case 15:
            j = 6;
            break;
        case 0:
        case 11:
        case 20:
            j = 12;
            break;
        }

        if (j != 0)
        {
            D_8011A680[arg0][arg1][0] |= 4;
            D_8011A680[arg0][arg1][7] = MIN(j, D_8011A680[arg0][arg1][7]+arg2);
        }
    }
}

INCLUDE_ASM("nonmatchings/src/code0/41940", func_8005259C);

INCLUDE_ASM("nonmatchings/src/code0/41940", func_80052AB0);

INCLUDE_RODATA("nonmatchings/src/code0/41940", D_800E5CDC);
INCLUDE_ASM("nonmatchings/src/code0/41940", func_800533C4);

/*80053650*/
static void func_80053650(s32 arg0, s32 spritenum)
{
    SpriteType *spr;

    spr = &gpSprite[spritenum];
    if (spr->xrepeat == 0)
        spr->xrepeat = 64;

    if (spr->unk25 == 0)
    {
        switch (arg0)
        {
        case 1430:
        case 1432:
        case 1434:
        case 1438:
        case 1524:
        case 1525:
        case 1549:
        case 1550:
        case 1552:
        case 1586:
        case 1587:
        case 1588:
            spr->unk16 = 0;
            spr->unk22 = 0;
            spr->unk18 = 60;
            spr->cstat |= 0x1101;
            changeSpriteStat(spritenum, 64);
            break;

        case 1926:
        case 1338:
            spr->cstat |= 0x1101;
            changeSpriteStat(spritenum, 66);
            break;

        case 1418:
            changeSpriteStat(spritenum, 70);
            spr->unk18 = 2;
            spr->unk25 = 0;
            spr->unk20 = 2538;
            break;

        case 1466:
            changeSpriteStat(spritenum, 70);
            spr->unk18 = 2;
            spr->unk25 = 0;
            spr->unk20 = 2536;
            break;

        case 2266:
            changeSpriteStat(spritenum, 70);
            spr->unk18 = 2;
            spr->unk25 = 0;
            spr->unk20 = 2537;
            break;

        case 1483:
            changeSpriteStat(spritenum, 70);
            spr->unk18 = 2;
            spr->unk25 = 0;
            spr->unk20 = 1603;
            break;

        case 5215:
            spr->clipdist = 32;
            spr->cstat |= 0x101;
            changeSpriteStat(spritenum, 67);
            break;

        case 23:
            changeSpriteStat(spritenum, 80);
            spr->picnum = 0;
            spr->cstat |= 0x8000;
            spr->picnum = 2854;
            spr->xrepeat = 128;
            spr->yrepeat = 128;
            break;

        case 2585:
        case 1445:
            spr->unk18 = 12;
            changeSpriteStat(spritenum, 71);
            break;
        }
    }
}

/*80053900*/
static code0UnkStruct3 *func_80053900(s32 spritenum)
{
    s16 i;

    i = func_8004BE90();
    D_80106D50[spritenum] = i;
    D_8019B940[i].unkA1 = gpSprite[spritenum].unk24;
    return &D_8019B940[D_80106D50[spritenum]];
}

INCLUDE_ASM("nonmatchings/src/code0/41940", func_800539A8);

/*80055DDC*/
static void func_80055DDC(s32 spritenum)
{
    if (gpSprite[spritenum].statnum == 21)
        gpSprite[spritenum].cstat = gpSprite[spritenum].cstat | 0x8000;
    else if (gpSprite[spritenum].statnum == 22)
        gpSprite[spritenum].cstat = -0x8000;
    else if (((gpSprite[spritenum].statnum == 0) || (gpSprite[spritenum].statnum == 54)))
    {
        gpSprite[spritenum].unk2B = 0;
        if (gpSprite[spritenum].statnum == 54)
            gpSprite[spritenum].unk2B = 1;
        changeSpriteStat(spritenum, 20);
        gpSprite[spritenum].cstat = gpSprite[spritenum].cstat | 0x8000;
    }
    else
        changeSpriteStat(spritenum, 1);
}

INCLUDE_ASM("nonmatchings/src/code0/41940", func_80055EC0);

INCLUDE_ASM("nonmatchings/src/code0/41940", func_800563D4);

INCLUDE_ASM("nonmatchings/src/code0/41940", func_80056600);

/*80056A54*/
void func_80056A54(s16 spritenum)
{
    s16 spritenum_;

    if (D_800DEF20 > 0)
    {
        spritenum_ = D_80137DF0[D_8019955C];
        if (spritenum_ >= 0)
        {
            if (D_80106D50[spritenum_] != -1)
            {
                D_8019B940[D_80106D50[spritenum_]].unk0 = 0;
                D_80106D50[spritenum_] = -1;
            }
            if (gpSprite[spritenum_].statnum != 0x400)
                deleteSprite(spritenum_);
        }
        D_80137DF0[D_8019955C] = spritenum;
        D_8019955C = (D_8019955C + 1) % D_800DEF20;
    }
    else
    {
        if (D_80106D50[spritenum] != -1)
        {
            D_8019B940[D_80106D50[spritenum]].unk0 = 0;
            D_80106D50[spritenum] = -1;
        }
        if (gpSprite[spritenum].statnum != 0x400)
            deleteSprite(spritenum);
    }
}

INCLUDE_ASM("nonmatchings/src/code0/41940", func_80056C00);

/*8005731C*/
STATIC s32 func_8005731C(s32 spritenum)
{
    SpriteType *spr;
    s32 unk16;
    s32 unk1C;
    s32 temp;
    s32 z;
    s32 ang;

    unk16 = gpSprite[spritenum].unk16;
    spr = &gpSprite[spritenum];
    if ((unk16 < 0) || (D_80106D50[unk16] == -1))
        return 0;

    z = spr->z;
    temp = func_80058600(unk16);
    unk1C = (((gpSprite[unk16].z - z) - temp) * 2000) / ldist(&gpSprite[spritenum], &gpSprite[unk16]);
    unk1C /= 8;
    ang = (getAngleDelta(gpSprite[spritenum].ang,
        getAngle(gpSprite[unk16].x - gpSprite[spritenum].x, gpSprite[unk16].y - gpSprite[spritenum].y))) >> 3;
    spr->unk1C = unk1C;
    spr->ang = spr->ang + ang;
    return 0;
}

/*800574A4*/
void func_800574A4(s32 spritenum)
{
    if (gpSprite[spritenum].sectnum != MAXSECTORS)
    {
        if (D_80106D50[spritenum] != -1)
            D_8019B940[D_80106D50[spritenum]].unk0 = 0;

        deleteSprite(spritenum);
        D_80106D50[spritenum] = -1;
    }
}

INCLUDE_ASM("nonmatchings/src/code0/41940", func_80057540);

INCLUDE_ASM("nonmatchings/src/code0/41940", func_80057E7C);

/*80058468*/
STATIC s32 func_80058468(s32 spritenum)
{
    s16 a, b;
    s32 c;

    gpInst++;
    a = getVar(spritenum, *gpInst++);
    b = getVar(spritenum, *gpInst++);
    c = getVar(spritenum, *gpInst++);

    return func_80057540(&gpSprite[spritenum], a, b, c);
}

/*80058538*/
static s32 func_80058538(SpriteType *spr, s32 arg1)
{
    s32 i, j, d1, d2, nexti;

    i = gHeadSpriteStat[4];
    d1 = 0x200000;

    while (i >= 0)
    {
        if (gpSprite[i].unk1E != arg1)
        {
            d2 = dist(&gpSprite[i], spr);
            if (d2 < d1)
            {
                d1 = d2;
            }
        }
        i = gNextSpriteStat[i];
    }

    if (d1 == 0x200000)
        return -1;
    else
        return d1;
}

/*80058600*/
s32 func_80058600(s32 spritenum)
{
    s32 ret, temp;
    ModelInfo *model;

    ret = 0x3900;
    if (gpSprite[spritenum].cstat & 0x1000)
    {
        model = D_800D52E0[gpSprite[spritenum].picnum-1280];
        if (model != NULL)
        {
            ret = (model->unk2E - model->unk28) * 32;
            temp = gpSprite[spritenum].xrepeat * ret;
            ret = temp / 64;
        }
        ret -= 2048;
    }
    else
    {
        ret = ((gpSprite[spritenum].xrepeat * gpSprite[spritenum].yrepeat) * 2) - 768;
    }
    return ret;
}

/*800586B0*/
void func_800586B0(s32 spritenum, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6)
{
    s32 x, y;

    x = (arg5 * (gpSinTable[(gpSprite[spritenum].ang + 1024) & 0x7FF])) / 16384;
    y = (arg5 * (gpSinTable[(gpSprite[spritenum].ang + 512) & 0x7FF])) / 16384;

    func_8007AED8((gpSprite[spritenum].x + x),
                  (gpSprite[spritenum].y + y),
                  gpSprite[spritenum].z,
                  (gpSprite[spritenum].x - x),
                  (gpSprite[spritenum].y - y),
                  gpSprite[spritenum].z,
                  arg2,
                  arg3,
                  arg4,
                  arg6,
                  arg1);
}

/*800587B8*/
s32 func_800587B8(s32 spritenum, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6)
{
    return func_8007AED8(gpSprite[spritenum].x, gpSprite[spritenum].y, gpSprite[spritenum].z,
                         gpSprite[spritenum].x, gpSprite[spritenum].y, gpSprite[spritenum].z - (arg5 << 6),
                         arg2, arg3, arg4, arg6, arg1);
}

/*80058844*/
void func_80058844(s32 spritenum, s32 arg1, s32 arg2, s16 arg3)
{
    s32 x, y, temp;

    temp = 0x10;
    x = (arg2 * (gpSinTable[(gpSprite[spritenum].ang + 1024) & 0x7FF] * temp)) / 16384;
    y = (arg2 * (gpSinTable[(gpSprite[spritenum].ang + 512) & 0x7FF] * temp)) / 16384;

    func_8007B1F4((gpSprite[spritenum].x + x),
                  (gpSprite[spritenum].y + y),
                  gpSprite[spritenum].z,
                  (gpSprite[spritenum].x - x),
                  (gpSprite[spritenum].y - y),
                  gpSprite[spritenum].z,
                  arg3, arg1);
}

/*80058934*/
s16 func_80058934(s32 x, s32 y, s32 z, s32 sectnum, s32 arg4)
{
    s16 spritenum;

    spritenum = insertSprite(sectnum, arg4);
    if (spritenum != -1)
    {
        setSprite(spritenum, x, y, z);
        gpSprite[spritenum].cstat = 0;
        gpSprite[spritenum].unk24 = 0;
        D_8013B2D0[spritenum].unk2 = 0;
        D_8013B2D0[spritenum].unk0 = 0;
        D_8013B2D0[spritenum].unk4 = 0;
        D_8013B2D0[spritenum].unk6 = 0;
        D_8013B2D0[spritenum].handle = 0;
        return spritenum;
    }
    return -1;
}

/*80058A14*/
void func_80058A14(s16 spritenum, s16 *hitsprite, s32 *hitx, s32 *hity)
{
    s16 hitsect, hitwall;
    s32 x, y, z;

    hitScan(gpSprite[spritenum].x,
            gpSprite[spritenum].y,
            gpSprite[spritenum].z,
            gpSprite[spritenum].sectnum,
            gpSinTable[(gpSprite[spritenum].ang + 512) & 0x7FF],
            gpSinTable[gpSprite[spritenum].ang & 0x7FF],
            0,
            &hitsect,
            &hitwall,
            hitsprite,
            &x,
            &y,
            &z,
            0x10001);

    *hitx = x;
    *hity = y;
    findDistance2D((x - gpSprite[spritenum].x), (y - gpSprite[spritenum].y));
}

/*80058B3C*/
s32 func_80058B3C(s32 x1, s32 y1, s32 z1, s32 sectnum, s32 x2, s32 y2, s32 z2, s32 arg7)
{
    f32 f1;
    s16 unk18;
    s32 x, y, z;
    s32 ret;

    if (arg7 == 0)
        return -1;

    unk18 = gpSector[sectnum].unk18;
    ret = -1;

    if (unk18 == 3)
    {
        z = func_80036490(sectnum);
        if ((z < z1) & (z2 < z))
        {
            f1 = z - z2;
            f1 /= (z1 - z2);
            x = ((x1 - x2) * f1) + x2;
            y = ((y1 - y2) * f1) + y2;

            if (arg7 == 20)
                ret = func_8008E3E0(x, y, z, sectnum, 6, 0);
            else
            {
                ret = func_8008E3E0(x, y, z, sectnum, 28, 0);
                if (krand() & 1)
                    func_8008E3E0(x, y, z, sectnum, unk18, 2);
            }
        }
    }

    if (gpSector[sectnum].unk18 == 1)
    {
        if (z1 >= getFlorzOfSlope(sectnum, x1, y1))
        {
            if (arg7 == 20)
                ret = func_8008E3E0(x1, y1, z1, sectnum, 6, 0);
            else
            {
                ret = func_8008E3E0(x1, y1, z1, sectnum, 28, 0);
                if (krand() & 1)
                    func_8008E3E0(x1, y1, z1, sectnum, 3, 2);
            }
        }
    }
    return ret;
}


/*80058DE0*/
static s32 func_80058DE0(SpriteType *spr, s32 *arg1)
{
    *arg1 = klabs(gPlayer[0].unk28 - spr->x)
        + klabs(gPlayer[0].unk2C - spr->y)
        + (klabs(gPlayer[0].unk30 - spr->z + 7168) >> 4);

    return 0;
}

#ifdef NON_MATCHING
/*80058E44*/
void func_80058E44(s32 spritenum)
{
    code0UnkStruct3 *ptr;
    s32 unk84;
    s32 i;

    ptr = &D_8019B940[D_80106D50[spritenum]];
    unk84 = ptr->unk84;
    if ((unk84 == 0) || (unk84 == 11) || (unk84 == 8) || (unk84 == 18))
    {
        i = 36;
        if (D_800DEEA0 != 0)
        {
            func_80057540(&gpSprite[spritenum], 1501, 2, 0);
            func_80057540(&gpSprite[spritenum], 2130, 4, 0);
        }
        else
        {
            func_80057540(&gpSprite[spritenum], 1501, 1, 0);
            func_80057540(&gpSprite[spritenum], 2130, 2, 0);
        }
    }
    else
    {
        i = 11;
        if (D_800DEEA0 != 0)
        {
            func_80057540(&gpSprite[spritenum], 1500, 4, 0);
            func_80057540(&gpSprite[spritenum], 2130, 4, 0);
        }
        else
        {
            func_80057540(&gpSprite[spritenum], 1500, 2, 0);
            func_80057540(&gpSprite[spritenum], 2130, 2, 0);
        }
    }

    if ((krand() & 3) == 3)
        func_8008E3E0(gpSprite[spritenum].x, gpSprite[spritenum].y,
                      gpSprite[spritenum].z, gpSprite[spritenum].sectnum, i, 0);

    unk84 = ptr->unk84;
    if (D_801C0D70[unk84].unk0 != -1)
    {
        if (func_8005A240(spritenum) != 2)
            func_80057540(&gpSprite[spritenum], D_801C0D70[unk84].unk0, 1, 0);

        func_80057540(&gpSprite[spritenum], D_801C0D70[unk84].unk2, 1, 0);
        func_80057540(&gpSprite[spritenum], D_801C0D70[unk84].unk4, 1, 0);
        func_80057540(&gpSprite[spritenum], D_801C0D70[unk84].unk6, 1, 0);
    }
    audio_800077F4(538, spritenum);
}
#else
INCLUDE_ASM("nonmatchings/src/code0/41940", func_80058E44);
#endif
