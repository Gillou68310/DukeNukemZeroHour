#include "common.h"
#include "code0/main.h"
#include "code0/audio.h"
#include "code0/engine.h"
#include "code0/pragmas.h"
#include "code0/4600.h"
#include "code0/FDE0.h"
#include "code0/17B30.h"
#include "code0/1E7A0.h"
#include "code0/35D90.h"
#include "code0/36410.h"
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

typedef void (*_41940UnkFuncPointer1)(s32 spritenum, s32 arg1);
typedef s32(*_41940UnkFuncPointer2)(s32 spritenum);

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
    /*0x1D*/ s8 unk1D;
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
/*800DEED4*/ EXTERN_DATA STATIC s32 D_800DEED4;
/*800DEEE4*/ EXTERN_DATA u8 D_800DEEE4[MAXPLAYERS];
/*800DEEE8*/ EXTERN_DATA s32 gAutoAim;
/*800DEF10*/ EXTERN_DATA STATIC s32 D_800DEF10;
/*800DEF14*/ EXTERN_DATA STATIC s32 D_800DEF14; /*damage?*/
/*800DEF18*/ EXTERN_DATA STATIC s32 D_800DEF18; /*damage?*/
/*800DEF1C*/ EXTERN_DATA s32 D_800DEF1C;
/*800DEF20*/ EXTERN_DATA STATIC s16 D_800DEF20;
/*800DEF38*/ EXTERN_DATA STATIC s32 D_800DEF38;
/*800DEF3C*/ EXTERN_DATA STATIC _41940UnkFuncPointer2 D_800DEF3C[84];
/*800DF08C*/ EXTERN_DATA STATIC intptr_t D_800DF08C;
/*800DF1A8*/ EXTERN_DATA s32 D_800DF1A8;
/*800DF1AC*/ EXTERN_DATA s16 D_800DF1AC[MAXPLAYERS];
/*800DF1B4*/ EXTERN_DATA s16 D_800DF1B4[9];
/*800DF1C0*/ EXTERN_DATA STATIC char *D_800DF1C0[4];
/*800DF1D0*/ EXTERN_DATA s16 D_800DF1D0[24][3];

/*.comm*/
/*800FE9D4*/ s32 D_800FE9D4;
/*80137DF0*/ s16 D_80137DF0[1024] ALIGNED(16); /*spritenum array*/
/*80138718*/ s32 *gpInst;
/*80138794*/ s32 *D_80138794;
/*80138820*/ s16 D_80138820[8] ALIGNED(8); /*sectornum array*/
/*80197E30*/ s32 D_80197E30;
/*8019955C*/ s16 D_8019955C;
/*8019B89C*/ s32 D_8019B89C; /*unused*/
/*801A1974*/ s32 D_801A1974;
/*801A1978*/ s16 D_801A1978; /*sector count*/
/*801ACC70*/ _41940UnkStruct1 D_801ACC70[32] ALIGNED(16);
/*801C0D68*/ s32 D_801C0D68;

/*.text*/
static s32 func_800413CC(s32 spritenum);
static void func_800418B8(s32);
STATIC s32 func_80042C98(s32 spritenum);
STATIC s32 func_800433D4(s32 spritenum);
static s32 func_8004BC24(s32, s32);
STATIC s32 func_8004DE60(s32 spritenum, s32);
static s32 func_8004EB60(s32 spritenum);
static void func_8004ED40(s32 spritenum);
static s32 func_8004F284(SpriteType *spr, s32 *, s32 spritenum);
static void func_8004F5DC(void);
static void func_8004F704(s32);
static void func_8004F8D0(s32 spritenum);
static void func_8004FA74(s32 spritenum);
static void func_80050E40(void);
static void func_80051088(s32 spritenum);
static void func_80051330(s32 spritenum);
static void func_800519AC(void);
static s32 func_80052AB0(s16, s16, s32);
static void func_80053650(s32, s32 spritenum);
static void func_80056C00(s32);
STATIC void func_80057E7C(void);
static s32 func_80058538(SpriteType *spr, s32);
static s32 func_80058DE0(SpriteType *spr, s32 *);

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

/*80040EF0*/
static void func_80040EF0(s32 spritenum, s16 playernum, s32 arg2)
{
    ModelInfo *ptr;
    s32 i, j;

    if (D_800DEE84 == 0)
    {
        D_80137DE0 = &D_8019B940[D_80106D50[spritenum]];
        D_80137DE0->unk9B++;
        D_80137DE0->unk9C++;
        D_80137DE0->unk9D++;

        if (!(D_8012FD88 & 7))
        {
            if (D_80137DE0->unkA0 != 0)
                D_80137DE0->unkA0--;
        }

        if (D_80137DE0->unk8C != 0)
            D_80137DE0->unk8C--;

        D_8010A918 = arg2;
        D_800FE400 = spritenum;
        gpInst = D_80137DE0->unkC;
        D_80118248 = &gpSprite[spritenum];
        D_8012F6E8 = func_8005A240(spritenum);
        D_801A2628 = playernum;

        if (D_80118248->cstat & 0x1000)
        {
            ptr = D_800D52E0[D_80118248->picnum - 1280];
            D_801B0D30 = (ptr->unk2E - ptr->unk28) << 6;
            if (ptr->unk28 < 0)
                D_80197E30 = 1;
            else
                D_80197E30 = 0;
        }
        else
            D_801B0D30 = getTileSizeY(D_80118248->picnum) * D_80118248->yrepeat * 4;


        j = 0;
        if (D_8013B2D0[spritenum].unk6 != 0)
        {
            D_8013B2D0[spritenum].unk6 -= 8;
            if (D_8013B2D0[spritenum].unk6 < 9)
                D_8013B2D0[spritenum].unk6 = 0;
        }
        func_80051088(spritenum);
        func_80051330(spritenum);

        if (D_80137DE0->unk0 & 0x200)
            func_80036280(spritenum, 0);

        if (D_80137DE0->unk30 == 0)
        {
            while (j == 0)
            {
                j = D_800DEF3C[*gpInst & 0x7FFFFFFF](spritenum);
                if (j != -1)
                {
                    D_80138794 = D_80137DE0->unkC;
                    D_80137DE0->unkC = gpInst;
                    D_800DF08C = ((intptr_t)gpInst - (intptr_t)D_0100F1E0_STATIC_START) - (intptr_t)gStaticSegment;
                }
                else
                    return;

            }
        }
        if ((j != -1) && ((j == 2) || (func_800413CC(spritenum) != -1)))
        {
            if (D_80137DE0->unk0 & 0x20000)
            {
                func_8004F704(spritenum);
                D_80137DE0->unk0 |= 0x8000;
                if ((D_8012FD88 & 0xF) == 0xF)
                    func_800494DC(spritenum, 5, 0, 1);

                D_80137DE0->unk0 &= ~0x8000;
                if (D_8012F6E8 != 2)
                {
                    if (D_80137DE0->unk96 != 0)
                        D_80137DE0->unk96--;
                    else
                        D_80137DE0->unk0 &= ~0x20000;
                }
            }
            func_8004F8D0(spritenum);
            i = gHeadSpriteStat[60];
            while (i >= 0)
            {
                if (gpSprite[i].unk16 == spritenum)
                {
                    gpSprite[i].ang = D_80118248->ang;
                    gpSprite[i].x = D_80118248->x;
                    gpSprite[i].y = D_80118248->y;
                    gpSprite[i].z = D_80118248->z;
                    D_8013B2D0[i].unk2 = D_8013B2D0[spritenum].unk2;
                    changeSpriteSect(i, D_80118248->sectnum);
                }
                i = gNextSpriteStat[i];
            }
            D_801B0D30 = 0;
            D_80197E30 = 0;
        }
    }
}

/*800413CC*/
static s32 func_800413CC(s32 spritenum)
{
    SpriteType *spr;
    s32 i, j;

    if (D_80137DE0->unk30 == 0)
        return 0;

    D_80137DE0->unk30--;
    spr = &gpSprite[spritenum];
    D_80137DE0->unk2E = func_8004DE60(spritenum, 11);

    if (D_80137DE0->unk2E == -1)
        return -1;

    D_80137DE0->unk97 = 0;
    if ((spr->unk18 != 0) || (spr->unk1A != 0))
        D_80137DE0->unk97 = 1;

    if (spr->sectnum == -1)
    {
        func_8004BD24(spritenum);
        return -1;
    }

    if (((D_80137DE0->unk4 & 0x1040) == 0x1040) &&
        (D_8010A918 < D_80137DE0->unk64) &&
        (func_80042C98(spritenum) != 0))
    {
        D_80137DE0->unk4 &= ~0x40;
        func_800418B8(0);
        D_80137DE0->unk4 |= 0x2000;
    }

    if (D_80137DE0->unk4 & 0x30000)
        func_800418B8(0);

    if ((D_80137DE0->unk4 & 0x400) && (gPlayer[0].unk45 != 0))
    {
        if (D_80137DE0->unk4 & 0x20000)
            D_80137DE0->unk99 = D_80137DE0->unkA;

        if ((gPlayer[0].unk45 != 0xFF) && !(D_80137DE0->unk4 & 2))
            func_800418B8(1);
    }

    if (D_80137DE0->unk4 & 0x100)
        func_800418B8(0);

    if (D_80137DE0->unk4 & 0x800)
    {
        j = gpSector[D_80118248->sectnum].unk18 == 2;
        if (gpSector[D_80118248->sectnum].unk18 == 3)
        {
            i = D_80118248->z - D_801B0D30;
            if (func_80036490(D_80118248->sectnum) < (i))
                j = 1;
        }

        if ((j != 0) && !(D_80137DE0->unk4 & 2))
        {
            func_800418B8(1);
            D_80137DE0->unk4 |= 0x20;
        }
    }
    if ((D_80137DE0->unk4 & 4) &&
        (ldist(&gpSprite[D_80118248->unk16], D_80118248) >= gpSprite[D_80118248->unk16].unk1E) &&
        (D_80137DE0->unk92 != 4))
    {
        func_800418B8(1);
        D_80137DE0->unk4 |= 8;
    }

    if ((D_80137DE0->unk4 & 0x10))
    {
        if ((D_80137DE0->unk4 & 0x80) && (D_80137DE0->unk92 != 3))
            func_800418B8(1);
    }

    if ((D_80137DE0->unk4 & 0x4000) && (D_8012F6E8 == 1))
    {
        D_801A1974 = klabs(((D_80118248->z - D_801B0D30) - D_801A1998));
        if (D_801A1974 < 0xA00)
            func_800418B8(0);
        else
            D_80137DE0->unk4 &= ~0x4000;
    }

    func_8004D884();
    func_8004DC74();
    func_8004ED40(spritenum);

    if ((D_80137DE0->unk94 != 0) && (D_80137DE0->unk4 & 0x200))
        func_800418B8(0);

    j = D_80137DE0->unk2E;
    if (j & 0xC000)
    {
        j &= 0xFFFF;
        j -= 0xC000;

        if (j > 0)
        {
            if (!(gpSprite[j].cstat & 0x101))
                return 0;
            if (gpSprite[j].statnum == 10)
                return 0;
        }

        if (!(D_80137DE0->unk0 & 0x80000))
            func_800418B8(0);
    }

    return 0;
}

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

/*80041968*/
s32 func_80041968(s32 spritenum)
{
    s32 i, j;
    s16 ang;

    gpInst++;
    i = getVar(spritenum, *gpInst++);
    if (i == 0x4000002D)
    {
        if (D_80137DE0->unk38 != -1)
        {
            ang = getAngle(D_80137DE0->unk38 - D_80118248->x,
                           D_80137DE0->unk3C - D_80118248->y);
            j = *gpInst;
            ang = getAngleDelta(D_80118248->ang, ang);
            ang >>= j;
            D_80118248->ang += ang;
            D_80137DE0->unk32 = ang;
            i = 0;
        }
        else
            goto label4;
    }
    if (i == 0x40000008)
    {
    label4:
        ang = getAngle(gPlayer[D_801A2628].xpos - D_80118248->x,
                       gPlayer[D_801A2628].ypos - D_80118248->y);
        j = *gpInst;
        ang = getAngleDelta(D_80118248->ang, ang);
        ang >>= j;
        D_80118248->ang += ang;
        D_80137DE0->unk32 = ang;
        i = 0;
    }
    if (i == 0x4000001F)
    {
        ang = getAngle(gPlayer[D_801A2628].xpos - D_80118248->x,
                       gPlayer[D_801A2628].ypos - D_80118248->y);
        j = *gpInst;
        ang = getAngleDelta(D_80118248->ang, (ang + 1024) & 0x7FF);
        ang >>= j;
        D_80118248->ang += ang;
        D_80137DE0->unk32 = ang;
        i = 0;
    }
    if (i == 0x4000001A)
    {
        D_80118248->ang = getAngle(gPlayer[D_801A2628].xpos - D_80118248->x,
                                   gPlayer[D_801A2628].ypos - D_80118248->y) & 0x7FF;
        i = 0;
    }
    D_80137DE0->unk30 = i;
    if (i == 0)
    {
        gpInst += 3;
        return 0;
    }
    D_80118248->unk18 = getVar(spritenum, *gpInst++);
    D_80118248->unk1A = getVar(spritenum, *gpInst++);
    i = getVar(spritenum, *gpInst++);

    if (D_80137DE0->unk0 & 2)
        D_80118248->unk1C += i;
    else
        D_80118248->unk1C = i;

    return 1;
}

/*80041D10*/
STATIC s32 func_80041D10(s32 spritenum)
{
    s32 i, j, k, l;
    s32 x, y, z1, z2;
    s32 d;
    s32 cond;

    gpInst++;
    i = getVar(spritenum, *gpInst++);
    j = *gpInst++;
    k = getVar(spritenum, *gpInst++);
    l = *gpInst++;

    cond = 0;
    if (j & 0x80)
    {
        if (i == k)
            cond = 1;
    }

    if (j & 0x100)
    {
        if (i != k)
            cond = 1;
    }

    if (j & 0x200)
    {
        if (i < k)
            cond = 1;
    }

    if (j & 0x400)
    {
        if (k < i)
            cond = 1;
    }

    if (j & 0x10)
    {
        if (D_80137DE0->unk8 <= 0)
            cond = 1;
    }

    if (j & 0x40)
    {
        x = D_80118248->x - gPlayer[0].xpos;
        y = D_80118248->y - gPlayer[0].ypos;

        if (x < 0)
            x = -x;

        if (y < 0)
            y = -y;

        x = x + y;
        if (x < i)
            cond = 1;
    }

    if (j & 0x800)
    {
        d = func_80058538(D_80118248, k);
        if (d == -1)
            cond = 0;
        else if (d < i)
            cond = 1;
    }

    if (j & 1)
    {
        if (gpSector[D_80118248->sectnum].unk18 == 2)
            cond = 1;

        if (gpSector[D_80118248->sectnum].unk18 == 3)
        {
            z1 = D_80118248->z - i;
            if (func_80036490(D_80118248->sectnum) < z1)
                cond = 1;
        }
    }

    if (j & 2)
    {
        cond = gpSector[D_80118248->sectnum].unk18 != 2;
        if (gpSector[D_80118248->sectnum].unk18 == 3)
        {
            z2 = D_80118248->z - i;
            cond &= -((func_80036490(D_80118248->sectnum) >= (z2)));
        }
    }

    if (j & 8)
    {
        if (!(D_80137DE0->unk0 & 4))
            cond = 1;
    }

    if (j & 4)
    {
        if (D_80137DE0->unk0 & 4)
            cond = 1;
    }

    if (j & 0x8000)
    {
        if (D_80137DE0->unk38 == -1)
            cond = 1;
    }

    if (cond == 1)
        gpInst = &gpInst[l];

    return 0;
}

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

/*80042598*/
STATIC s32 func_80042598(s32 spritenum)
{
    s32 x, y, z1, z2;
    s32 i, j, k, l, m;
    s32 d;
    s32 cond;

    i = *gpInst++;
    j = getVar(spritenum, *gpInst++);
    k = *gpInst++;
    l = getVar(spritenum, k);
    m = *gpInst++;

    if (i < 0)
        m += 2;

    cond = 0;

    if (j & 0x10)
    {
        if (D_80137DE0->unk8 < 1)
            cond = 1;
    }

    if (j & 0x40)
    {
        x = D_80118248->x - gPlayer[0].xpos;
        y = D_80118248->y - gPlayer[0].ypos;
        if (x < 0)
            x = -x;

        if (y < 0)
            y = -y;

        x = x + y;
        if (x < l)
            cond = 1;
    }

    if (j & 1)
    {
        if (gpSector[D_80118248->sectnum].unk18 == 2)
            cond = 1;

        if (gpSector[D_80118248->sectnum].unk18 == 3)
        {
            z1 = D_80118248->z - l;
            if (func_80036490(D_80118248->sectnum) < z1)
                cond = 1;
        }
    }

    if (j & 0x800)
    {
        d = func_80058538(D_80118248, k);
        if (d == -1)
            cond = 0;
        else if (d < l)
            cond = 1;
    }

    if (j & 2)
    {
        cond = gpSector[D_80118248->sectnum].unk18 != 2;
        if (gpSector[D_80118248->sectnum].unk18 == 3)
        {
            z2 = D_80118248->z - l;
            cond &= -((func_80036490(D_80118248->sectnum) >= z2));
        }
    }

    if (j & 8)
    {
        if (!(D_80137DE0->unk0 & 4))
            cond = 1;
    }

    if (j & 4)
    {
        if (D_80137DE0->unk0 & 4)
            cond = 1;
    }

    if ((j & 0x8000) && (D_80137DE0->unk38 == -1))
        cond = 1;

    if (cond == 0)
        gpInst = &gpInst[m];

    return 0;
}

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

/*80042C98*/
INCLUDE_ASM("nonmatchings/src/code0/41940", func_80042C98);

/*800433D4*/
INCLUDE_ASM("nonmatchings/src/code0/41940", func_800433D4);

/*8004364C*/
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

/*80044394*/
STATIC s32 func_80044394(s32 spritenum)
{
    s16 ang;
    s32 i, j, k, l, m, n;

    gpInst++;
    D_80137DE0->unk30 = getVar(spritenum, *gpInst++);
    i = *gpInst++;
    j = getVar(spritenum, *gpInst++);
    k = getVar(spritenum, *gpInst++);
    l = getVar(spritenum, *gpInst++);

    if (D_80137DE0->unk84 >= 38 && D_80137DE0->unk84 < 44)
    {
        j *= 2;
        k *= 2;
    }

    m = getVar(spritenum, *gpInst++);
    n = getVar(spritenum, i);
    switch (n)
    {
    case 0x4000002D:
        if (D_80137DE0->unk38 == -1)
            ang = getAngle(gPlayer[0].xpos - D_80118248->x,
                           gPlayer[0].ypos - D_80118248->y);
        else
            ang = getAngle(D_80137DE0->unk38 - D_80118248->x,
                           D_80137DE0->unk3C - D_80118248->y);

        i = getAngleDelta(D_80118248->ang, ang) >> m;
        D_80118248->ang = func_80051508(D_80118248->ang, ang, m);
        D_80137DE0->unk32 = i;
        break;
    case 0x40000008:
        if ((D_80137DE0->unk0 & 0x1800) && (D_80137DE0->unk28 != -1))
            ang = getAngle(gpSprite[D_80137DE0->unk28].x - D_80118248->x,
                           gpSprite[D_80137DE0->unk28].y - D_80118248->y);
        else
            ang = getAngle(gPlayer[0].xpos - D_80118248->x,
                           gPlayer[0].ypos - D_80118248->y);

        i = getAngleDelta(D_80118248->ang, ang) >> m;
        D_80118248->ang = func_80051508(D_80118248->ang, ang, m);
        D_80137DE0->unk32 = i;
        break;
    case 0x4000001F:
        ang = (getAngle(gPlayer[D_801A2628].xpos - D_80118248->x,
            gPlayer[D_801A2628].ypos - D_80118248->y) + 1024) & 0x7FF;
        i = getAngleDelta(D_80118248->ang, ang) >> m;
        D_80118248->ang = func_80051508(D_80118248->ang, ang, m);
        D_80137DE0->unk32 = i;
        break;
    case 0x4000001A:
        D_80118248->ang = getAngle(gPlayer[D_801A2628].xpos - D_80118248->x,
                                   gPlayer[D_801A2628].ypos - D_80118248->y) & 0x7FF;
        break;
    case 0x4000001C:
        D_80118248->ang = D_80137DE0->unk5C;
        break;
    default:
        if (n != D_80118248->ang)
        {
            if (m != -1)
            {
                D_80118248->ang = func_80051508(D_80118248->ang, n, m);
                i = (getAngleDelta(D_80118248->ang, n) >> m);
                D_80137DE0->unk32 = i;
            }
            else
                D_80118248->ang = n;
        }
        break;
    }
    j = (j * gpSinTable[(D_80118248->ang + 512) & 0x7FF]) >> 14;
    i = D_80118248->ang; /*FAKEMATCH*/
    k = (k * gpSinTable[i & 0x7FF]) >> 14;
    D_80118248->unk18 = j;
    D_80118248->unk1A = k;

    if (D_80137DE0->unk0 & 2)
        D_80118248->unk1C += l;
    else
        D_80118248->unk1C = l;

    return D_80137DE0->unk30 != 0;
}

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

/*80044B38*/
STATIC s32 func_80044B38(s32 spritenum)
{
    s32 ang, ang1, ang2, ang3;
    s32 i, j, k, l, m, n;

    gpInst++;
    D_80137DE0->unk30 = getVar(spritenum, *gpInst++);
    n = *gpInst++;
    i = getVar(spritenum, n);
    j = getVar(spritenum, *gpInst++);
    k = getVar(spritenum, *gpInst++);
    l = getVar(spritenum, *gpInst++);
    m = getVar(spritenum, *gpInst++);

    if (i == 0x40000008)
    {
        ang1 = getAngleDelta(D_80118248->ang,
                             getAngle(gPlayer[0].xpos - D_80118248->x, gPlayer[0].ypos - D_80118248->y)) >> m;
        D_80137DE0->unk32 = ang1;
        D_80118248->ang += ang1;
    }
    if (i == 0x4000001F)
    {
        ang2 = getAngleDelta(D_80118248->ang,
                             (getAngle(gPlayer[D_801A2628].xpos - D_80118248->x,
                                 gPlayer[D_801A2628].ypos - D_80118248->y) + 1024)) >> m;
        D_80137DE0->unk32 = ang2;
        D_80118248->ang += ang2;
    }
    if (i == 0x4000001A)
    {
        D_80118248->ang = getAngle(gPlayer[D_801A2628].xpos - D_80118248->x,
                                   gPlayer[D_801A2628].ypos - D_80118248->y) & 0x7FF;
    }

    if ((n != 0x40000008) && (n != 0x40000009) &&
        (n != 0x4000001F) && (n != 0x4000001A))
    {
        if (i != D_80118248->ang)
        {
            ang3 = getAngleDelta(D_80118248->ang, i) >> m;
            D_80118248->ang += ang3;
            D_80137DE0->unk32 = ang3;
        }
    }

    if (n == 0x4000001C)
        ang = D_80137DE0->unk60;
    else
        ang = D_80118248->ang;

    i = getVar(spritenum, *gpInst++);
    j = (j * gpSinTable[(ang + 512) & 0x7FF]) >> 14;
    l = (l * gpSinTable[i & 0x7FF]) >> 14;
    k = (k * gpSinTable[ang & 0x7FF]) >> 14;

    D_80118248->unk18 = j;
    D_80118248->unk1A = k;

    if (D_80137DE0->unk0 & 2)
        D_80118248->unk1C += l;
    else
        D_80118248->unk1C = l;

    return D_80137DE0->unk30 != 0;
}

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

/*80046540*/
STATIC void func_80046540(void);
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

/*80047820*/
INCLUDE_ASM("nonmatchings/src/code0/41940", func_80047820);

/*800494DC*/
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

/*8004A590*/
static void func_8004A590(s32 spritenum)
{
    s32 i;
    s32 j;

    gpSprite[spritenum].cstat |= 0x101;
    if (gpSprite[spritenum].unk18 == 0)
    {
        func_8004F4A0(spritenum);
        D_80137DE0->unk86 = -32665;
        D_80137DE0->unk58 = 0;
        D_80137DE0->unk0 |= 2;
        gpSprite[spritenum].unk18 = 1;
    }

    if (gpSprite[spritenum].unk18 == 1)
    {
        D_80137DE0->unk0 &= ~2;
        gpSprite[spritenum].unk18 = 2;
        gpSprite[spritenum].unk1C = 0;
    }

    if (gpSprite[spritenum].unk18 == 2)
    {
        if (D_80137DE0->unk54 != 0)
        {
            if ((gpSprite[spritenum].unk1C == 0) && (gpSprite[spritenum].unk25 != 31))
            {
                func_80045400(D_80137DE0->unk44, D_80137DE0->unk48, D_80137DE0->unk4C,
                              D_80137DE0->unk50, 200, D_80137DE0->unk60, 15, 18);
                gpSprite[spritenum].unk1C = 3;
                D_80137DE0->unk54--;
            }
            else
                gpSprite[spritenum].unk1C--;
        }

        if (((gpSprite[spritenum].unk1A++ & 7) == 7) && (gpSprite[spritenum].unk25 != 31))
        {
            audio_80007A44(((krand() % 2) + 57), spritenum, 0x4000);
            D_80137DE0->unk54 = 6;
            gpSprite[spritenum].unk1C = 0;
            D_80137DE0->unk44 = (gpSprite[spritenum].x + (krand() & 0x1F)) - 0xF;
            D_80137DE0->unk48 = (gpSprite[spritenum].y + (krand() & 0x1F)) - 0xF;
            D_80137DE0->unk4C = gpSprite[spritenum].z - ((krand() & 0x3F) << 8);
            D_80137DE0->unk50 = gpSprite[spritenum].sectnum;
            D_80137DE0->unk60 = (D_80118248->ang + (krand() & 512)) - 256;
        }

        if (D_80137DE0->unk58++ > 180)
        {
            if (gpSprite[spritenum].unk25 != 31)
            {
                for (i = 0; i < 3; i++)
                {
                    j = func_8008E3E0(gpSprite[spritenum].x, gpSprite[spritenum].y,
                                      gpSprite[spritenum].z, gpSprite[spritenum].sectnum, 55, 1781);
                    if (j != -1)
                    {
                        gpSprite[j].xrepeat = (krand() & 0x3F) + 0x20;
                        gpSprite[j].yrepeat = (krand() & 0x3F) + 0x20;
                    }
                }
                func_80057540(&gpSprite[spritenum], 1781, 5, 0);
                gpSprite[spritenum].unk1E = 12;
                func_8004BFDC(spritenum, 11, gpSprite[spritenum].z, 1);
            }
            else
            {
                func_8004AB6C(spritenum, 6000, 250, 500, 750, 1000, 1);
                audio_80007A44(591, spritenum, 36000);

                func_8008E3E0(gpSprite[spritenum].x, gpSprite[spritenum].y, gpSprite[spritenum].z - 6144,
                              gpSprite[spritenum].sectnum, 30, 0);

                for (i = 0; i < 3; i++)
                    func_8008E3E0(gpSprite[spritenum].x, gpSprite[spritenum].y,
                                  gpSprite[spritenum].z - 6144, gpSprite[spritenum].sectnum, 20, 0);
            }

            if (gMapNum == MAP_THE_RACK)
            {
                if (gpSprite[spritenum].unk20 == 837)
                    func_8004A4D4(&gpSprite[spritenum], 2364, 4);
            }
            if (gMapNum == MAP_ALIEN_MOTHER)
            {
                if (gpSprite[spritenum].unk20 == 806)
                    func_8004A4D4(&gpSprite[spritenum], 2364, 1);

                if (gpSprite[spritenum].unk20 == 818)
                    func_8004A4D4(&gpSprite[spritenum], 2364, 3);
            }
            func_8004BD24(spritenum);
        }
    }
}

INCLUDE_RODATA("nonmatchings/src/code0/41940", D_800E5618);
/*8004AB6C*/
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
        spr->cstat = 0x8000;
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
    _41940UnkFuncPointer1 func;
    s32 i;

    gpInst++;
    func = (_41940UnkFuncPointer1)*gpInst++;
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

/*8004BFDC*/
INCLUDE_ASM("nonmatchings/src/code0/41940", func_8004BFDC);

/*8004CB3C*/
s32 func_8004CB3C(s32 wallnum)
{
    s16 overpicnum;
    s32 wallnum_;

    wallnum_ = wallnum & 0x7FFF;
    if (gpWall[wallnum_].cstat & 0x10)
    {
        overpicnum = gpWall[wallnum_].overpicnum;
        switch (overpicnum)
        {
        case 3185:
        case 3172:
        case 5300:
            func_80093BB0(wallnum_);
            gpWall[wallnum_].cstat &= ~0x51;
            if (gpWall[wallnum_].nextwall != -1)
                gpWall[gpWall[wallnum_].nextwall].cstat &= ~0x51;

            return 1;

        case 3759:
            gpWall[wallnum_].overpicnum = 3678;
            gpWall[wallnum_].cstat &= ~0x41;
            if (gpWall[wallnum_].nextwall != -1)
            {
                if (gpWall[gpWall[wallnum_].nextwall].overpicnum == overpicnum)
                    gpWall[gpWall[wallnum_].nextwall].overpicnum = 3678;

                gpWall[gpWall[wallnum_].nextwall].cstat &= ~0x41;
            }
            return 1;
        }
    }
    return 0;
}

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

typedef struct
{
    /*0x00*/ s16 unk0[3];
} _41940UnkStruct3;

static const _41940UnkStruct3 D_800E58F4 = {1, 10, 305};

/*8004CE58*/
s32 func_8004CE58(SpriteType *spr, s16 arg1, s16 arg2)
{
    s32 a, b, c, d, e, ret, f, g, h;
    _41940UnkStruct3 stat;
    s32 x, y;
    s32 i, m;
    s16 cond1, cond2;
    s16 j;
    s32 temp;

    stat = D_800E58F4;
    if (spr->statnum == 10)
    {
        i = spr->unk16;
        if (arg2 != 20)
        {
            j = 2 - D_801CE498.unk3E[i];
            switch (j)
            {
            case 0:
                arg1 = (arg1 * 150) / 100;
                break;
            case 1:
                arg1 = (arg1 * 125) / 100;
                break;
            case 2:
                break;
            }
        }
    }

    ret = -1;
    e = ~0x80000000;
    a = gpSinTable[((spr->ang + 512) - arg1) & 0x7FF];
    b = gpSinTable[(spr->ang - arg1) & 0x7FF];
    c = gpSinTable[(spr->ang  + 512 + arg1) & 0x7FF];
    d = gpSinTable[(spr->ang + arg1) & 0x7FF];
    g = gpSinTable[(spr->ang + 512) & 0x7FF];
    h = gpSinTable[spr->ang & 0x7FF];

    if (spr->statnum == 10)
        f = gPlayer[spr->unk16].unk3E;
    else
        f = 0;

    for (i = 0; i < ARRAY_COUNT(stat.unk0); i++)
    {
        j = gHeadSpriteStat[stat.unk0[i]];
        while (j >= 0)
        {
            if (spr != &gpSprite[j])
            {
                if ((gpSprite[j].statnum != 10) ||
                    ((gPlayer[gpSprite[j].unk16].unk45 == 0) && (D_80138690 == 0)))
                {
                    x = gpSprite[j].x - spr->x;
                    y = gpSprite[j].y - spr->y;
                    temp = b * x;

                    if ((a * y) >= (temp))
                    {
                        if ((d * x) >= (c * y))
                        {
                            m = mulscale(g, x, 14) + mulscale(h, y, 14);
                            if (!(m < 513) && (m < e))
                            {
                                cond1 = klabs_(scale(gpSprite[j].z - spr->z, 10, m) - f) < 100;
                                cond2 = (canSee(gpSprite[j].x, gpSprite[j].y, (gpSprite[j].z - 0x2000), gpSprite[j].sectnum,
                                    spr->x, spr->y, (spr->z - 0x2000), spr->sectnum));

                                if (cond1 && cond2)
                                {
                                    e = m;
                                    ret = j;
                                }
                            }
                        }
                    }
                }
            }
            j = gNextSpriteStat[j];
        }
    }
    return ret;
}

/*8004D304*/
s32 func_8004D304(SpriteType *arg0, s16 arg1, s16 arg2)
{
    SpriteType *spr;
    s32 a, b, c, d, e, f, g, ret;
    _41940UnkStruct3 stat;
    s32 x, y;
    s16 i;
    s32 j, m;
    s16 cond;

    if (arg1)
        stat = D_800E58F4;
    else
        stat = D_800E58F4;

    ret = -1;
    g = ~0x80000000;

    a = gpSinTable[((arg0->ang + 512) - arg1) & 0x7FF];
    b = gpSinTable[(arg0->ang - arg1) & 0x7FF];
    c = gpSinTable[(arg0->ang + 512 + arg1) & 0x7FF];
    d = gpSinTable[(arg0->ang + arg1) & 0x7FF];
    e = gpSinTable[(arg0->ang + 512) & 0x7FF];
    f = gpSinTable[arg0->ang & 0x7FF];

    for (j = 0; j < ARRAY_COUNT(stat.unk0); j++)
    {
        i = gHeadSpriteStat[stat.unk0[j]];
        while (i >= 0)
        {
            spr = &gpSprite[i];
            if (arg0 != spr)
            {
                if ((spr->statnum != 10) ||
                    ((gPlayer[spr->unk16].unk45  == 0) && (D_80138690 == 0)))
                {
                    x = spr->x - arg0->x;
                    y = spr->y - arg0->y;

                    if ((b * x) <= (a * y))
                    {
                        if ((d * x) >= (c * y))
                        {
                            m = mulscale(e, x, 14) + mulscale(f, y, 14);
                            if (m < g)
                            {
                                cond = (canSee(gpSprite[i].x, gpSprite[i].y, (gpSprite[i].z - 8192) - func_80058600(i),
                                    gpSprite[i].sectnum, arg0->x, arg0->y, (arg0->z - 8192), arg0->sectnum));
                                if (cond != 0)
                                {
                                    g = m;
                                    ret = i;
                                }
                            }
                        }
                    }
                }
            }
            i = gNextSpriteStat[i];
        }
    }
    return ret;
}

/*8004D65C*/
STATIC void func_8004D65C(s32 spritenum)
{
    s16 i, nexti;
    s32 unk20;

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
                        if ((gpSprite[i].unk1E == 101) || (gpSprite[i].unk1E == 102))
                        {
                            if (gpSprite[i].unk1E == 101)
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

/*8004D884*/
void func_8004D884(void)
{
    s32 z1, z2;
    s32 i;
    u16 cstat;

    cstat = D_80118248->cstat;
    D_80118248->cstat = cstat & 0xFEFE;
    getzRange(D_80118248->x, D_80118248->y, D_80118248->z - 2048, D_80118248->sectnum,
              &D_801A1998, &D_801AE9C0, &D_80138860, &D_800FCBE0, 64, 0x10001);
    D_80118248->cstat = cstat;
    D_80129804 = getFlorzOfSlope(D_80118248->sectnum, D_80118248->x, D_80118248->y);
    D_8012EB4C = getCeilzOfSlope(D_80118248->sectnum, D_80118248->x, D_80118248->y) - D_801B0D30;

    if ((gpSector[D_80118248->sectnum].unk18 == 1) && (D_80137DE0->unk0 & 2))
    {
        if (D_80138860 == D_80129804)
        {
            D_80138860 = D_80129804 + 0x2600;
            if ((D_80118248->z - (D_801B0D30 + 0x400)) >= D_80138860)
            {
                D_80118248->z = D_80138860 - 0x400;
                D_80118248->z -= D_801B0D30;
            }
        }
        D_80129804 = D_80129804 + 0x2600;
    }

    if ((gpSector[D_80118248->sectnum].unk18 == 3) && (D_80118248->unk1C <= 0) && (D_80137DE0->unk0 & 2))
    {
        z1 = func_80036490(D_80118248->sectnum);
        z2 = (D_80118248->z - D_801B0D30) + 0x400;
        if (!(z2 < (z1 - 0x1300)) && (z2 < z1))
            D_80118248->z = (D_801B0D30 + z1) - 0xF00;
    }

    if ((D_8012F6E8 != 2 && D_80118248->picnum == 1285) || (D_8012F6E8 == 2 && D_80137DE0->unk48 == 0))
    {
        if (D_80118248->picnum == 1285)
            i = 0x700;
        else
            i = 0x800;

        if (D_80118248->picnum != 1727)
        {
            if (D_80118248->picnum == 1304)
                i = 0x500;

            if (D_80138860 == D_80129804)
                D_80138860 = D_80129804 + i;

            D_80129804 = D_80129804 + i;
        }
    }

    if (gpSector[D_80118248->sectnum].unk18 == 4)
    {
        if (D_80138860 == D_80129804)
            D_80138860 = D_80129804 + 0x1000;

        D_80129804 = D_80129804 + 0x1000;
    }

    if (gpSector[D_80118248->sectnum].unk18 == 5)
    {
        if (D_80138860 == D_80129804)
            D_80138860 = D_80129804 + 0x2600;

        D_80129804 = D_80129804 + 0x2600;
    }

    if ((D_800FCBE0 >= 0xC000) && (gpSprite[D_800FCBE0 - 0xC000].statnum == 10))
        D_80137DE0->unk94 |= 2;
}

/*8004DC74*/
void func_8004DC74(void)
{
    s32 i;

    i = 0x100;
    if (D_80137DE0->unk0 & 0x800000)
    {
        D_80118248->z += D_80118248->unk1C;
        D_80137DE0->unk0 &= ~4;
        return;
    }
    if (D_80118248->z < D_80138860)
    {
        if (D_80137DE0->unk0 & 2)
        {
            if (D_80137DE0->unk84 == 33)
                i = 0x40;

            D_80118248->unk1C += i;
        }
    }
    else if (D_80138860 < D_80118248->z)
    {
        if (((D_80118248->z - D_80138860) < 0x1200) || (D_80129804 < D_80118248->z))
            D_80118248->z += ((D_80138860 - D_80118248->z) / 2);
    }
    D_80118248->z += D_80118248->unk1C;
    D_80137DE0->unk0 &= ~4;

    if (D_80118248->z >= D_80138860)
        D_80137DE0->unk0 |= 4;

    if (D_80197E30 != 0)
    {
        if (D_80118248->z < D_801A1998)
        {
            D_80118248->unk1C = 0;
            D_80118248->z = D_801A1998;
        }
    }
    else if ((D_80118248->z - D_801B0D30) < D_801A1998)
    {
        D_80118248->z = D_801A1998 + D_801B0D30;
        D_80118248->unk1C = 0;
        if (D_80118248->z >= D_80138860)
            D_80118248->z = D_80138860;
    }
    if ((D_80118248->unk1C > 0) && (D_80118248->z >= D_80138860))
    {
        D_80137DE0->unk0 |= 4;
        D_80118248->z = D_80138860;
        D_80118248->unk1C = 0;
    }
}

/*8004DE60*/
INCLUDE_ASM("nonmatchings/src/code0/41940", func_8004DE60);

/*8004E5F8*/
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

/*8004E8BC*/
static void func_8004E8BC(void)
{
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_801ACC70); i++)
    {

        if (D_801ACC70[i].unk0 != 0)
        {
            func_800867CC(D_801ACC70[i].unk0,
                          D_801ACC70[i].unk10,
                          D_801ACC70[i].unk14,
                          D_801ACC70[i].unk18,
                          D_801ACC70[i].unk4,
                          D_801ACC70[i].unk8,
                          D_801ACC70[i].unkC,
                          D_801ACC70[i].unk1D,
                          D_801ACC70[i].unk1C);
        }

        if (D_801ACC70[i].unk2-- == 0)
            D_801ACC70[i].unk0 = 0;
    }
}

/*8004E9B4*/
static void func_8004E9B4(s32 spritenum)
{
    audio_80007820(704, spritenum);
    changeSpriteStat(spritenum, 1);
    gpSprite[spritenum].cstat = (gpSprite[spritenum].cstat & ~0x8000) | 0x101;
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
            if ((u8)(D_800DEEE4[i] - 6) >= 4) /*TODO?*/
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

/*8004F044*/
void func_8004F044(void)
{
    s32 sp10;
    SpriteType *spr;
    s16 i, j, nexti, temp;

    D_801C0D68 = 0;
    D_8012FD88++;
    if (D_800DEE88 != 0)
        D_800DEE88--;

    j = 0;
    i = gHeadSpriteStat[1];
    while (i >= 0)
    {
        nexti = gNextSpriteStat[i];
        if (D_80106D50[i] != -1)
        {
            if (D_8019B940[D_80106D50[i]].unkC != 0)
            {
                if (D_8019B940[D_80106D50[i]].unk0 & 1)
                {
                    spr = &gpSprite[i];
                    if (((D_8019B940[D_80106D50[i]].unk0 & 0x800) || (D_8019B940[D_80106D50[i]].unk0 & 0x1000))
                        && (D_8019B940[D_80106D50[i]].unk28 != -1))
                        j = func_8004F284(spr, &sp10, D_8019B940[D_80106D50[i]].unk28);
                    else
                        j = func_80058DE0(spr, &sp10);

                    if (temp == 0)
                        D_801C0D68++;

                    func_80040EF0(i, j, sp10);
                    func_80017268(i);
                }
            }
        }
        i = nexti;
    }
    func_8004F5DC();
    func_80047710();
    func_80046540();
    func_80057E7C();
    func_8004E8BC();
    func_800519AC();
    gPlayer[j].unk28 = gPlayer[j].xpos;
    gPlayer[j].unk2C = gPlayer[j].ypos;
    gPlayer[j].unk30 = gPlayer[j].zpos;
}

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
static void func_8004F704(s32 arg0)
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
static void func_8004F8D0(s32 spritenum)
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
                            func_8004FA74(spritenum);
                        break;

                    case 1:
                        j = klabs(gpSector[D_80118248->sectnum].floorz - D_80118248->z);
                        j = 0x4000 - j;
                        if (j > 0)
                            func_8004FA74(spritenum);
                        break;

                    default:
                        func_8004FA74(spritenum);
                    }
                }
            }
            else
            {
                if (func_80040D94(gpSprite[spritenum].x,
                    gpSprite[spritenum].y,
                    gpSprite[spritenum].z / 16,
                    spr->x,
                    spr->y,
                    spr->z / 16) < spr->unk22)
                {
                    func_8004FA74(spritenum);
                }
            }
            i = nexti;
        }
    }
}

/*8004FA74*/
static void func_8004FA74(s32 spritenum)
{
    (void)spritenum;

    D_80137DE0->unk96++;
    if (D_80137DE0->unk0 & 0x20000)
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

    if (gMapNum == MAP_GOING_DOWN_THE_RACK)
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
                func_80057540(&gpSprite[i], D_801C0D70[temp].unk0, 1, 0x1234);
                func_80057540(&gpSprite[i], D_801C0D70[temp].unk2, 1, 0x1234);
                func_80057540(&gpSprite[i], D_801C0D70[temp].unk4, 1, 0x1234);
                func_80057540(&gpSprite[i], D_801C0D70[temp].unk6, 1, 0x1234);
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

/*800504F4*/
void func_800504F4(void)
{
    SpriteType *spr;
    s16 i, nexti;

    i = gHeadSpriteStat[74];
    while (i >= 0)
    {
        spr = &gpSprite[i];
        nexti = gNextSpriteStat[i];

        if (spr->unk18 == 0)
        {
            spr->unk18 = 1;
            if (spr->picnum == 1549)
                spr->picnum = 1749;
            if ((spr->picnum == 1586) || (spr->picnum == 1587) || (spr->picnum == 1588))
                spr->picnum = 1589;
            else if ((spr->picnum == 1524) || (spr->picnum == 1525))
                spr->picnum = 1435;
            else
                spr->picnum++;

            func_80050C14(i);
            return;
        }
        else if (spr->unk18 == 1)
        {
            spr->unk1C = -3000;
            spr->unk22 = (krand() & 0x1F) - 0xF;
            spr->unk16 = (krand() & 0x1F) - 0xF;
            spr->unk18 = 2;
        }
        else if (spr->unk18 == 2)
        {
            spr->unk1C += 200;
            spr->z += spr->unk1C;
            D_8013B2D0[i].unk2 += spr->unk22;
            D_8013B2D0[i].unk0 += spr->unk16;
            D_80138860 = getFlorzOfSlope(spr->sectnum, spr->x, spr->y);
            if (spr->z >= D_80138860)
            {
                spr->z = D_80138860;
                spr->unk18 = 3;
                if (spr->picnum == 1433)
                {
                    func_8004BFDC(i, 4, gpSprite[i].z, 1);
                    func_8004BD24(i);
                }
            }
            func_8001F7B4(5, 8);
        }
        else if (spr->unk18 == 3)
        {
            if (D_8013B2D0[i].unk2 != 0)
            {
                if (D_8013B2D0[i].unk2 > 0)
                {
                    D_8013B2D0[i].unk2 -= 48;
                    if (D_8013B2D0[i].unk2 <= 0)
                        D_8013B2D0[i].unk2 = 0;
                }
                else
                {
                    D_8013B2D0[i].unk2 += 48;
                    if (D_8013B2D0[i].unk2 >= 0)
                        D_8013B2D0[i].unk2 = 0;
                }
            }

            if (D_8013B2D0[i].unk0 != 0)
            {
                if (D_8013B2D0[i].unk0 > 0)
                {
                    D_8013B2D0[i].unk0 -= 48;
                    if (D_8013B2D0[i].unk0 <= 0)
                        D_8013B2D0[i].unk0 = 0;
                }
                else
                {
                    D_8013B2D0[i].unk0 += 48;
                    if (D_8013B2D0[i].unk0 >= 0)
                        D_8013B2D0[i].unk0 = 0;
                }
            }

            if (D_8013B2D0[i].unk0 == 0 && D_8013B2D0[i].unk2 == 0)
            {
                spr->unk18 = 4;
                func_800533C4(spr->picnum, i);
            }
        }
        i = nexti;
    }
}

/*8005087C*/
void func_8005087C(void)
{
    SpriteType *spr;
    s16 i, nexti;

    i = gHeadSpriteStat[75];
    while (i >= 0)
    {
        spr = &gpSprite[i];
        nexti = gNextSpriteStat[i];
        if (spr->unk18 == 0)
        {
            spr->unk18 = 1;
            if ((spr->picnum == 1586) || (spr->picnum == 1587) || (spr->picnum == 1588))
                spr->picnum = 1589;
            else if ((spr->picnum == 1524) || (spr->picnum == 1525))
                spr->picnum = 1435;
            else if (spr->picnum == 2585)
                spr->picnum = 2595;
            else
                spr->picnum++;

            func_8004AB6C(i, 2048, 25, 50, 75, 100, 0);
            func_80050C14(i);
            return;
        }
        else if (spr->unk18 == 1)
        {
            spr->unk1C = -400;
            spr->unk22 = (krand() & 7) - 3;
            spr->unk16 = (krand() & 7) - 3;
            spr->unk18 = 2;
        }
        else if (spr->unk18== 2)
        {
            spr->unk1C += 100;
            spr->z += spr->unk1C;
            D_8013B2D0[i].unk2 += spr->unk22;
            D_8013B2D0[i].unk0 += spr->unk16;
            getzRange(spr->x, spr->y, (spr->z - 2048), spr->sectnum,
                      &D_801A1998, &D_801AE9C0, &D_80138860, &D_800FCBE0, 64, 0x10001);
            if (spr->z >= D_80138860)
            {
                spr->z = D_80138860;
                spr->unk18 = 3;
            }
        }
        else if (spr->unk18== 3)
        {
            if (D_8013B2D0[i].unk2 != 0)
            {
                if (D_8013B2D0[i].unk2 > 0)
                {
                    D_8013B2D0[i].unk2 -= 16;
                    if (D_8013B2D0[i].unk2 <= 0)
                        D_8013B2D0[i].unk2 = 0;
                }
                else
                {
                    D_8013B2D0[i].unk2 += 16;
                    if (D_8013B2D0[i].unk2 >= 0)
                        D_8013B2D0[i].unk2 = 0;
                }
            }

            if (D_8013B2D0[i].unk0 != 0)
            {
                if (D_8013B2D0[i].unk0 > 0)
                {
                    D_8013B2D0[i].unk0 -= 16;
                    if (D_8013B2D0[i].unk0 <= 0)
                        D_8013B2D0[i].unk0 = 0;
                }
                else
                {
                    D_8013B2D0[i].unk0 += 16;
                    if (D_8013B2D0[i].unk0 >= 0)
                        D_8013B2D0[i].unk0 = 0;
                }
            }

            if ((D_8013B2D0[i].unk0 == 0) && (D_8013B2D0[i].unk2 == 0))
            {
                spr->unk18 = 4;
                func_800533C4(spr->picnum, i);
            }
        }
        i = nexti;
    }
}

/*80050C14*/
void func_80050C14(s32 arg0)
{
    s32 x, y, z;
    s32 spritenum_;
    s32 ang;

    x = gpSprite[arg0].x;
    y = gpSprite[arg0].y;
    z = gpSprite[arg0].z;

    spritenum_ = func_8008E3E0(x, y, z - 2048, gpSprite[arg0].sectnum, 18, 0);
    do {} while (0); /*FAKEMATCH*/
    if (spritenum_ != -1)
    {
        D_8013B2D0[spritenum_].unk2 = 0;
        D_8013B2D0[spritenum_].unk0 = 0;
        gpSprite[spritenum_].ang = 0;
    }

    func_8008E3E0(x, y, z, gpSprite[arg0].sectnum, 17, 0);
    ang = gpSprite[arg0].ang;
    ang = (ang - 1024);
    ang &= 0x7FF;

    spritenum_ = func_8008E3E0(x, y, z, gpSprite[arg0].sectnum, 19, 1);
    if (spritenum_ != -1)
    {
        gpSprite[spritenum_].x += (gpSinTable[(ang + 512) & 0x7FF] * 5) >> 13;
        gpSprite[spritenum_].y += (gpSinTable[ang] * 5) >> 13;
    }

    func_8001F7B4(12, 8);
    audio_80007A44(560, arg0, 40000);
    func_8008E3E0(x, y, z, gpSprite[arg0].sectnum, 41, 32);
}

/*80050E40*/
static void func_80050E40(void)
{
    s32 nexti;
    s32 i;

    i = gHeadSpriteStat[1];
    while (i >= 0)
    {
        nexti = gNextSpriteStat[i];
        if ((func_8005A240(i) != 1) || ((gpSprite[i].unk25 != 5) && (gpSprite[i].unk25 != 1)))
            func_8004BD24(i);

        i = nexti;
    }
    i = gHeadSpriteStat[2];
    while (i >= 0)
    {
        nexti = gNextSpriteStat[i];
        if ((func_8005A240(i) != 1) || ((gpSprite[i].unk25 != 5) && (gpSprite[i].unk25 != 1)))
            func_8004BD24(i);

        i = nexti;
    }
    i = gHeadSpriteStat[20];
    while (i >= 0)
    {
        nexti = gNextSpriteStat[i];
        if ((func_8005A240(i) != 1) || ((gpSprite[i].unk25 != 5) && (gpSprite[i].unk25 != 1)))
            func_8004BD24(i);

        i = nexti;
    }
    i = gHeadSpriteStat[21];
    while (i >= 0)
    {
        nexti = gNextSpriteStat[i];
        if ((func_8005A240(i) != 1) || ((gpSprite[i].unk25 != 5) && (gpSprite[i].unk25 != 1)))
            func_8004BD24(i);

        i = nexti;
    }
}

/*80051088*/
static void func_80051088(s32 spritenum)
{
    s32 i, j, nexti;
    s32 d1, d2, d3;

    j = -1;
    d3 = 0x200000;
    if ((D_80137DE0->unk0 & 0x1000) &&
            ((D_80137DE0->unk28 == -1) ||
                (gpSprite[D_80137DE0->unk28].statnum != 302) ||
                (gpSprite[D_80137DE0->unk28].unk2B != 0)))
    {
        D_80137DE0->unk28 = -1;
        if (D_80137DE0->unk99 == 23)
        {
            i = gHeadSpriteStat[1];
            while (i >= 0)
            {
                nexti = gNextSpriteStat[i];
                if ((gpSprite[i].picnum == 1442) && (gpSprite[i].unk25 == 4))
                {
                    D_80137DE0->unk28 = j;
                    break;
                }
                i = nexti;
            }
        }
        else
        {
            d1 = klabs_(D_80118248->x - gPlayer[0].xpos) + klabs_(D_80118248->y - gPlayer[0].ypos);
            i = gHeadSpriteStat[302];
            while (i >= 0)
            {
                nexti = gNextSpriteStat[i];
                d2 = klabs_(D_80118248->x - gpSprite[i].x) + klabs_(D_80118248->y - gpSprite[i].y);
                if ((d2 < d3) && !(gpSprite[i].unk25 & 0x7F))
                {
                    if (d2 < 20000)
                    {
                        d3 = d2;
                        j = i;
                    }
                }
                i = nexti;
            }
            if ((d1 < d3) && (gpSprite[spritenum].unk24 == 123))
                j = gPlayer[0].unk4A;

            D_80137DE0->unk28 = j;
        }
    }
}

/*80051330*/
static void func_80051330(s32 spritenum)
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
static u8 func_80051684(s16 sectnum)
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
static u8 func_800516EC(s16 spritenum)
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
        if (unk25 >= 1 && unk25 < 4)
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

INCLUDE_RODATA("nonmatchings/src/code0/41940", D_800E5A40);
INCLUDE_RODATA("nonmatchings/src/code0/41940", D_800E5A54);
INCLUDE_RODATA("nonmatchings/src/code0/41940", D_800E5A60);
INCLUDE_RODATA("nonmatchings/src/code0/41940", D_800E5A6C);

/*800519AC*/
static void func_800519AC(void)
{
    SpriteType *spr;
    s32 ceilz, florz;
    s32 i, nexti, k;
    s16 sectnum, spritenum;
    s16 j;

    i = gHeadSpriteStat[150];
    while (i >= 0)
    {
        spr = &gpSprite[i];
        nexti = gNextSpriteStat[i];
        if (spr->unk18 != -1)
        {
            spr->unk1C += 126;
            spr->unk18 = 50;
            spr->unk1A = 50;
            func_8004E5F8(i, 50, 50, spr->unk1C);
            sectnum = spr->sectnum;
            getzsOfSlope(sectnum, spr->x, spr->y, &ceilz, &florz);

            if ((ceilz == florz) || (sectnum < 0) || (sectnum >= 657))
                deleteSprite(i);
            else if (florz < spr->z)
            {
                spr->z = florz;
                spr->unk18 = -1;
            }
        }
        else
        {
            spr->ang = (spr->ang + 7) & 0x7FF;
            D_8013B2D0[i].unk6 = CLAMP_MIN((D_8013B2D0[i].unk6 - 8), 0);
        }
        if (i == nexti)
            nexti = -1;

        i = nexti;
    }

    i = gHeadSpriteStat[151];
    while (i >= 0)
    {
        nexti = gNextSpriteStat[i];
        gpSprite[i].unk1C--;
        if (gpSprite[i].unk1C < 1200)
            gpSprite[i].unk25 = 0;

        if (gpSprite[i].unk1C < 600)
            gpSprite[i].unk25 = 9;

        if (gpSprite[i].unk1C <= 0)
        {
            audio_800077F4(742, i);
            func_8008E3E0(gpSprite[i].x, gpSprite[i].y, gpSprite[i].z, gpSprite[i].sectnum, 19, 33);
            changeSpriteStat(i, 150);
            gpSprite[i].picnum = gpSprite[i].unk16;
            gpSprite[i].cstat = 0x9000;
            gpSprite[i].xrepeat = 80;
            gpSprite[i].unk25 = 0;
            if (gpSprite[i].picnum == 1916)
            {
                spritenum = func_8008E3E0(gpSprite[i].x, gpSprite[i].y,
                                         (gpSprite[i].z - 4800), gpSprite[i].sectnum, 57, 0);
                if (spritenum != -1)
                {
                    if (spritenum >= 0)
                        gpSprite[spritenum].unk22 = i;
                }
            }
            else
                gpSprite[i].cstat &= ~0x8000;
        }
        if (i == nexti)
            nexti = -1;

        i = nexti;
    }

    i = gHeadSpriteStat[160];
    while (i >= 0)
    {
        nexti = gNextSpriteStat[i];
        gpSprite[i].ang = (gpSprite[i].ang + 7) & 0x7FF;
        i = nexti;
    }

    for (j = 0; j < D_8012C470; j++)
    {
        if (gPlayer[j].unk45 == 0)
        {
            k = 600;
            func_800515A0(gpSprite[gPlayer[j].unk4A].sectnum);
            if (gPlayer[j].unk60 != 0)
                k = 400;

            i = gHeadSpriteStat[150];
            florz = gPlayer[j].zpos + (gPlayer[j].unk40 / 2);
            while (i >= 0)
            {

                nexti = gNextSpriteStat[i];
                if (func_80051684(gpSprite[i].sectnum))
                {
                    if (func_80040D40(gpSprite[i].x, gpSprite[i].y, gPlayer[j].xpos, gPlayer[j].ypos) < k)
                    {
                        if (klabs((gpSprite[i].z - florz)) < gPlayer[j].unk40)
                        {
                            if (!(func_800516EC(i)) &&
                                 (func_80052AB0(j, (gpSprite[i].picnum - 1792), i)))
                            {
                                if ((D_8012C470 == 1) || (gpSprite[i].unk22 == 22136))
                                    deleteSprite(i);
                                else
                                {
                                    changeSpriteStat(i, 151);
                                    gpSprite[i].unk1C = 1800;
                                    gpSprite[i].unk16 = gpSprite[i].picnum;
                                    gpSprite[i].picnum = 3913;
                                    gpSprite[i].cstat = 0x800;
                                    gpSprite[i].xrepeat = 32;
                                    gpSprite[i].yrepeat = 32;
                                    gpSprite[i].unk25 = 8;
                                }
                            }
                        }
                    }
                }
                if (i == nexti)
                    nexti = -1;

                i = nexti;
            }

            i = gHeadSpriteStat[4];
            while (i >= 0)
            {
                nexti = gNextSpriteStat[i];
                if (func_80051684(gpSprite[i].sectnum) &&
                    (gpSprite[i].unk1E == 10) && (gpSprite[i].unk22 == 2) &&
                    (func_80040D40(gpSprite[i].x, gpSprite[i].y, gPlayer[j].xpos, gPlayer[j].ypos) < k))
                {
                    if (klabs((gpSprite[i].z - florz)) < gPlayer[j].unk40)
                    {
                        if (func_80052AB0(j, 24, i))
                            deleteSprite(i);
                        break;
                    }
                }
                i = nexti;
            }

            i = gHeadSpriteStat[160];
            while (i >= 0)
            {
                nexti = gNextSpriteStat[i];
                if (func_80051684(gpSprite[i].sectnum) &&
                    (func_80040D40(gpSprite[i].x, gpSprite[i].y, gPlayer[j].xpos, gPlayer[j].ypos) < k))
                {
                    if (klabs((gpSprite[i].z - florz)) < gPlayer[j].unk40)
                    {
                        audio_800077F4(696, i);
                        ceilz = gpSprite[i].unk25;
                        if (ceilz < 17)
                        {
                            char buffer[32];
                            sprintf(buffer, "KEY WITH NO NAME");
                            if (gpKeyStrInfo[gMapNum] != NULL)
                            {
                                if (gpKeyStrInfo[gMapNum][ceilz-1][0] != 0)
                                    sprintf(buffer, gpKeyStrInfo[gMapNum][ceilz-1]);
                            }
                            func_800A419C(j, buffer);
                            gPlayer[j].unk88[ceilz] = 1;
                            func_80051808(i);
                        }
                        deleteSprite(i);
                    }
                }
                i = nexti;
            }
        }
    }
}

/*80052358*/
STATIC u8 func_80052358(s16, s16);
INCLUDE_ASM("nonmatchings/src/code0/41940", func_80052358);

/*800524BC*/
static void func_800524BC(s16 playernum, s16 arg1, s16 arg2)
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
            D_8011A680[playernum][arg1][0] |= 4;
            D_8011A680[playernum][arg1][7] = MIN(j, D_8011A680[playernum][arg1][7]+arg2);
        }
    }
}

/*8005259C*/
STATIC u8 func_8005259C(s16, s16, s16, s16);
INCLUDE_ASM("nonmatchings/src/code0/41940", func_8005259C);

/*80052AB0*/
static s32 func_80052AB0(s16 arg0, s16 arg1, s32 arg2)
{
    s16 i, k, ret;
    u8 j;

    i = -1;
    k = -1;
    ret = 0;

    j = (gpSprite[arg2].unk22 == 0x1234) * 4;
    if (gpSprite[arg2].unk22 == 0x5678)
        j = 8;

    switch (arg1)
    {
    case 0x0:
        i = 2;
        j |= 1;
        break;
    case 0x2:
        i = 2;
        j |= 2;
        break;
    case 0x5:
        i = 4;
        j |= 1;
        break;
    case 0x7:
        i = 4;
        j |= 2;
        break;
    case 0xA:
        if (D_8011A680[arg0][4][7] < 24)
        {
            D_8011A680[arg0][4][7] = 24;
            D_8011A680[arg0][4][0] |= 4;
            ret = 1;
        }
        break;
    case 0xB:
        i = 6;
        j |= 1;
        break;
    case 0xD:
        i = 6;
        j |= 2;
        break;
    case 0x10:
        i = 8;
        j |= 1;
        break;
    case 0x12:
        i = 8;
        j |= 2;
        break;
    case 0x15:
        i = 9;
        j |= 2;
        break;
    case 0x18:
        i = 10;
        j |= 1;
        break;
    case 0x1A:
        i = 10;
        j |= 2;
        break;
    case 0x1C:
        i = 15;
        j |= 1;
        break;
    case 0x1E:
        i = 15;
        j |= 2;
        break;
    case 0x25:
        i = 17;
        j |= 1;
        break;
    case 0x27:
        i = 17;
        j |= 2;
        break;
    case 0x2A:
        i = 18;
        j |= 1;
        break;
    case 0x2C:
        i = 18;
        j |= 2;
        break;
    case 0x2F:
        if (D_8011A680[arg0][18][7] < 6)
        {
            D_8011A680[arg0][18][0] |= 4;
            ret = 1;
            D_8011A680[arg0][18][7] = CLAMP_MAX((D_8011A680[arg0][18][7] + 6), 6);
        }
        break;
    case 0x31:
        i = 14;
        j |= 1;
        break;
    case 0x75:
        i = 14;
        j |= 2;
        break;
    case 0x34:
        if (D_8011A680[arg0][14][7] < 12)
        {
            D_8011A680[arg0][14][0] |= 5;
            ret = 1;
            D_8011A680[arg0][14][7] = CLAMP_MAX((D_8011A680[arg0][0xE][7] + 4), 12);
        }
        break;
    case 0x36:
        i = 21;
        j |= 1;
        break;
    case 0x38:
        i = 21;
        j |= 2;
        break;
    case 0x3C:
        i = 3;
        j |= 1;
        break;
    case 0x3E:
        i = 3;
        j |= 2;
        break;
    case 0x41:
        if (D_8011A680[arg0][3][7] < 12)
        {
            D_8011A680[arg0][3][0] |= 4;
            ret = 1;
            D_8011A680[arg0][3][7] = CLAMP_MAX((D_8011A680[arg0][3][7] + 12), 12);
        }
        break;
    case 0x42:
        i = 5;
        j |= 1;
        break;
    case 0x44:
        i = 5;
        j |= 2;
        break;
    case 0x47:
        i = 20;
        j |= 1;
        break;
    case 0x49:
        i = 20;
        j |= 2;
        break;
    case 0x4C:
        i = 12;
        j |= 1;
        break;
    case 0x4E:
        i = 12;
        j |= 2;
        break;
    case 0x50:
        i = 13;
        j |= 1;
        break;
    case 0x52:
        i = 13;
        j |= 2;
        break;
    case 0x57:
        i = 7;
        j |= 1;
        break;
    case 0x59:
        i = 7;
        j |= 2;
        break;
    case 0x5C:
        i = 16;
        j |= 1;
        break;
    case 0x5E:
        i = 16;
        j |= 2;
        break;
    case 0x76:
        i = 23;
        j |= 1;
        break;
    case 0x77:
        i = 23;
        j |= 2;
        break;
    case 0x78:
        if (D_8011A680[arg0][23][7] < 12)
        {
            D_8011A680[arg0][23][0] |= 4;
            ret = 1;
            D_8011A680[arg0][23][7] = CLAMP_MAX((D_8011A680[arg0][23][7] + 4), 12);
        }
        break;
    case 0x7A:
        i = 9;
        j |= 1;
        break;
    case 0x61:
        if ((D_8019B940[D_80106D50[gPlayer[arg0].unk4A]].unk8 < gPlayer[arg0].unk48) &&
            (D_8019B940[D_80106D50[gPlayer[arg0].unk4A]].unk8 != 0))
        {
            ret = 1;
            func_80036520(arg0, 10);
        }
        break;
    case 0x62:
    case 0x63:
    case 0x64:
        if ((D_8019B940[D_80106D50[gPlayer[arg0].unk4A]].unk8 < gPlayer[arg0].unk48) &&
            (D_8019B940[D_80106D50[gPlayer[arg0].unk4A]].unk8 != 0))
        {
            ret = 1;
            func_80036520(arg0, 30);
        }
        break;
    case 0x65:
    case 0x66:
    case 0x67:
        k = 4;
        break;
    case 0x68:
        k = 3;
        break;
    case 0x69:
    case 0x6B:
    case 0x6D:
        if (D_8019B940[D_80106D50[gPlayer[arg0].unk4A]].unk7E < 100)
        {
            ret = 1;
            D_8019B940[D_80106D50[gPlayer[arg0].unk4A]].unk7E =
                CLAMP_MAX((D_8019B940[D_80106D50[gPlayer[arg0].unk4A]].unk7E+gpSprite[arg2].unk22), 100);
            D_8010A940[arg0].unkA[0] = D_8019B940[D_80106D50[gPlayer[arg0].unk4A]].unk7E;
            if (D_8010A940[arg0].unk0 == -1)
                D_8010A940[arg0].unk0 = 0;
        }
        break;
    case 0x6F:
        k = 2;
        break;
    case 0x70:
        k = 5;
        break;
    case 0x71:
        k = 6;
        break;
    case 0x72:
    case 0x73:
        k = 1;
        break;
    case 0x7C:
        if ((((D_8019B940[D_80106D50[gPlayer[arg0].unk4A]].unk8 >= 200)) ||
            (D_8019B940[D_80106D50[gPlayer[arg0].unk4A]].unk8 == 0)) == 0)
        {
            ret = 1;
            D_8019B940[D_80106D50[gPlayer[arg0].unk4A]].unk8 =
                CLAMP_MAX((D_8019B940[D_80106D50[gPlayer[arg0].unk4A]].unk8 + 50), 200);
        }
        break;
    }

    if (i != -1)
        ret = func_8005259C(arg0, i, j, arg2);

    if (k != -1)
        ret = func_80052358(arg0, k);

    if (ret != 0)
    {
        func_800A419C(arg0, gpWeaponStrInfo[arg1]);
        if (i != -1)
        {
            audio_800080E0(arg0, 0);
            audio_800077F4(697, arg2);
        }
        else
        {
            if (k != -1)
                audio_800080E0(arg0, 18);
            audio_800077F4(695, arg2);
        }
    }
    return ret;
}

typedef struct
{
    /*0x00*/ s32 unk0[3];
} _41940UnkStruct2;

static const _41940UnkStruct2 D_800E5CDC = {15, 45, 67};

/*800533C4*/
void func_800533C4(s32 arg0, s32 spritenum)
{
    _41940UnkStruct2 sp10;
    SpriteType *spr;
    s32 i, j, k;
    s32 spritenum_;

    i = 0;
    k = 0;
    j = -1;
    sp10 = D_800E5CDC;
    spr = &gpSprite[spritenum];
    spritenum_ = spritenum;

    if (spr->xrepeat == 0)
        spr->xrepeat = 0x40;

    if (spr->unk25 == 0)
    {
        switch (arg0)
        {
        case 0x6E7:case 0x6E8:case 0x886:case 0x887:case 0x8B4:case 0x8B5:
        case 0x8B6:case 0x8BE:case 0x8BF:case 0x8C0:case 0x8C1:case 0x967:
            i = 1;

        default:
            j = -1;
            break;

        case 0x6E9:case 0x6ED:case 0x6EE:
            i = 1;
            j = 1;
            break;

        case 0x597:case 0x599:case 0x59B:case 0x59F:case 0x5F4:case 0x5F5:
        case 0x60D:case 0x60E:case 0x610:case 0x62A:case 0x658:case 0x6AE:
        case 0x6AF:case 0x6D6:case 0x785:case 0x78E:case 0x791:case 0x796:
        case 0x7C0:case 0x86C:case 0x8FB:case 0x945:case 0x96C:case 0xA27:
            j = 1;
            break;

        case 0x6F0:
            j = 5;
            i = 1;
            break;

        case 0x6C3:case 0x6C4:
            j = 3;
            i = 1;
            break;

        case 0x6D7:case 0x6EA:case 0x7A9:
            i = 1;
            j = 0;
            break;

        case 0x534:case 0x548:case 0x549:case 0x57F:case 0x58C:case 0x58D:
        case 0x58E:case 0x5B1:case 0x5B4:case 0x5BB:case 0x5BE:case 0x5BF:
        case 0x5C9:case 0x5CA:case 0x5EE:case 0x5EF:case 0x622:case 0x627:
        case 0x628:case 0x629:case 0x643:case 0x647:case 0x648:case 0x649:
        case 0x64A:case 0x64B:case 0x64C:case 0x67A:case 0x684:case 0x69E:
        case 0x6B2:case 0x6B3:case 0x6B4:case 0x6C6:case 0x6C7:case 0x6EF:
        case 0x6F8:case 0x6F9:case 0x6FE:case 0x6FF:case 0x788:case 0x7BA:
        case 0x7BB:case 0x7BC:case 0x7C2:case 0x7C6:case 0x7C7:case 0x867:
        case 0x869:case 0x86D:case 0x873:case 0x874:case 0x875:case 0x877:
        case 0x878:case 0x87E:case 0x880:case 0x88C:case 0x89F:case 0x8A2:
        case 0x926:case 0x927:case 0xA17:case 0xA26:
            j = 0;
            break;

        case 0x7B0:
            i = 1;
            j = 0xD;
            break;

        case 0x545:case 0x546:case 0x5CD:case 0x5CE:case 0x5D7:
            j = 0xD;
            break;

        case 0x6D8:case 0x8C9:case 0x8CA:case 0x993:case 0x99E:
            i = 1;
            j = 0x15;
            break;

        case 0x571:case 0x57E:case 0x584:case 0x585:case 0x5B8:case 0x5D6:
        case 0x5F9:case 0x6BA:case 0x6BB:case 0x6FD:case 0x794:case 0x7AB:
        case 0x7AF:case 0x7B1:case 0x889:case 0x92E:case 0x92F:case 0xA22:
            j = 0x15;
            break;

        case 0x5B5:
            j = 2;
            k = 1;
            break;

        case 0x5A2:case 0x5DD:case 0x5DE:case 0x615:case 0x616:case 0x635:
        case 0x6DD:case 0x784:case 0x883:case 0x90E:case 0x959:
            j = 2;
            break;

        case 0x51E:case 0x51F:case 0x522:case 0x523:case 0x525:case 0x526:
        case 0x527:case 0x528:case 0x52B:case 0x52F:case 0x533:case 0x538:
        case 0x539:case 0x543:case 0x554:case 0x556:case 0x55C:case 0x5BC:
        case 0x5C5:case 0x5C6:case 0x5D2:case 0x5F0:case 0x5F1:case 0x5F2:
        case 0x5F3:case 0x600:case 0x609:case 0x60C:case 0x611:case 0x612:
        case 0x613:case 0x614:case 0x61D:case 0x61F:case 0x620:case 0x621:
        case 0x623:case 0x62D:case 0x62E:case 0x62F:case 0x630:case 0x631:
        case 0x636:case 0x639:case 0x63A:case 0x641:case 0x644:case 0x646:
        case 0x650:case 0x651:case 0x654:case 0x662:case 0x666:case 0x667:
        case 0x668:case 0x679:case 0x6E0:case 0x6E4:case 0x797:case 0x798:
        case 0x799:case 0x79A:case 0x79B:case 0x79C:case 0x79D:case 0x7AD:
        case 0x7B5:case 0x7B6:case 0x7B7:case 0x7CA:case 0x85D:case 0x861:
        case 0x862:case 0x863:case 0x865:case 0x872:case 0x876:case 0x87A:
        case 0x87C:case 0x87D:case 0x890:case 0x891:case 0x892:case 0x893:
        case 0x894:case 0x895:case 0x896:case 0x899:case 0x8D9:case 0x8DD:
        case 0x8DE:case 0x8DF:case 0x8E0:case 0x8E1:case 0x8E2:case 0x8E3:
        case 0x8E4:case 0x8E5:case 0x8E6:case 0x8EA:case 0x965:case 0x966:
        case 0x974:case 0xA12:case 0xF6C:
            j = 3;
            break;

        case 0x520:case 0x521:case 0x524:case 0x5A6:case 0x5AD:case 0x5AE:
        case 0x5AF:case 0x5C4:case 0x5D8:case 0x5FA:case 0x657:case 0x6FB:
        case 0x6FC:case 0x78F:case 0x86E:case 0x879:case 0x882:case 0x946:
        case 0x947:case 0x948:case 0x949:case 0x94A:
            j = 4;
            break;

        case 0x53D:case 0x607:case 0x7AC:
            j = 5;
            break;

        case 0x5C3:case 0x60F:case 0x6DA:case 0x86F:case 0x885:
            j = 6;
            break;

        case 0x529:case 0x52A:case 0x52E:case 0x530:case 0x54A:case 0x5CF:
        case 0x5D0:case 0x5D1:case 0x5E2:case 0x5E3:case 0x5E5:case 0x5E6:
        case 0x5E7:case 0x602:case 0x603:case 0x604:case 0x605:case 0x6C5:
        case 0x6E5:case 0x782:case 0x789:case 0x78A:case 0x78B:case 0x795:
        case 0x7C8:case 0x85F:case 0x860:case 0x864:case 0x88A:case 0x8B8:
        case 0x8B9:case 0x8BA:case 0x8BB:case 0x8BC:case 0x8CF:case 0x8D0:
        case 0x8D1:case 0x8D2:case 0x8D3:
            j = 0xC;
            break;

        case 0x7AE:
            j = 0xE;
            break;

        case 0x52C:case 0x52D:case 0x532:case 0x558:case 0x55A:case 0x655:
        case 0x678:case 0x6D9:case 0x6DB:case 0x6DC:case 0x6DE:case 0x6DF:
        case 0x780:case 0x7B2:case 0x7B3:case 0x7B4:case 0xA21:
            j = 0xF;
            break;

        case 0x559:
            j = 0x10;
            break;

        case 0x7C3:case 0x7C4:
            j = 0x11;
            break;

        case 0x881:
            j = 0x12;
            break;

        case 0x53C:case 0x540:case 0x580:case 0x589:case 0x5B7:case 0x92C:
        case 0x92D:
            j = 0x16;
            break;

        case 0x55B:
            j = 0x18;
            break;

        case 0x637:case 0x638:
            j = 0x19;
            break;

        case 0x54C:case 0x54D:case 0x54E:
            j = 0x3E7;
            break;

        case 0x8E9:
            j = 0x3E8;
            break;

        case 0x575:case 0x576:case 0x577:
            if (spr->statnum == 0)
            {
                i = 2;
                j = -1;
            }
            break;
        }

        spr->unk2A = 0;
        if (k != 0)
            spr->unk2A = 1;

        if (j != -1)
        {
            changeSpriteStat(spritenum_, 65);
            spr->unk22 = j;
            spr->unk18 = sp10.unk0[j % 3];
        }

        if ((j == -1) && (i != 0))
        {
            changeSpriteStat(spritenum_, 65);
            spr->unk22 = -1;
            spr->unk18 = sp10.unk0[0];
        }
        spr->unk2B = i;

        if (i == 2)
            spr->unk18 = sp10.unk0[2];
    }
    func_80053650(arg0, spritenum);
}

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

/*800539A8*/
INCLUDE_ASM("nonmatchings/src/code0/41940", func_800539A8);

/*80055DDC*/
static void func_80055DDC(s32 spritenum)
{
    if (gpSprite[spritenum].statnum == 21)
        gpSprite[spritenum].cstat = gpSprite[spritenum].cstat | 0x8000;
    else if (gpSprite[spritenum].statnum == 22)
        gpSprite[spritenum].cstat = 0x8000;
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

/*80055EC0*/
INCLUDE_ASM("nonmatchings/src/code0/41940", func_80055EC0);

/*800563D4*/
void func_800563D4(s32 spritenum)
{
    s32 unk9E;

    if (D_80137DE0->unk6C != 0)
    {
        MusHandleStop(D_80137DE0->unk6C, 0);
        D_80137DE0->unk6C = 0;
    }

    D_80137DE0->unk99 = 0;
    unk9E = D_80137DE0->unk9E;
    func_8006D3B8(spritenum, 103, 0, 0, 0);

    if (unk9E == 19 || unk9E == 32 || unk9E == 18 || unk9E == 8 ||
        unk9E == 10 || unk9E == 13 || unk9E == 12 || unk9E == 14)
    {
        func_80057540(&gpSprite[spritenum], 1501, 2, 0);
        func_80057540(&gpSprite[spritenum], 1501, 2, 0);
        func_8008E3E0(gpSprite[spritenum].x, gpSprite[spritenum].y, gpSprite[spritenum].z,
                      gpSprite[spritenum].sectnum, 36, 0);
        audio_800077F4(((krand() % 3) + 538), spritenum);
        func_8004BD24(spritenum);
    }
    else
    {
        D_80137DE0->unk44 = 0;
        func_80035A98(spritenum, 0);
        changeSpriteStat(spritenum, 53);
        gpSprite[spritenum].unk18 = 0;
        gpSprite[spritenum].unk1A = 0;
        if (unk9E == 21)
        {
            gpSprite[spritenum].cstat |= 0x800;
            gpSprite[spritenum].unk25 = 31;
        }
    }
}

/*80056600*/
void func_80056600(s32 spritenum)
{
    s32 i;
    s32 spritenum_;
    s32 x, y, z, sectnum;

    i = D_8019B940[D_80106D50[spritenum]].unk84;

    if ((i == 36) || (i == 37))
        return;

    if (D_801AE8F0[i] != -1)
    {
        x = gpSprite[spritenum].x;
        y = gpSprite[spritenum].y;
        z = gpSprite[spritenum].z;
        sectnum = gpSprite[spritenum].sectnum;
        spritenum_ = func_80058934(x, y, (z - 8192), sectnum, 150);
        if (spritenum_ != -1)
        {
            gpSprite[spritenum_].xrepeat = 80;
            gpSprite[spritenum_].unk1C = 0;
            gpSprite[spritenum_].unk18 = 0;
            gpSprite[spritenum_].unk1E = 80;
            gpSprite[spritenum_].picnum = D_801AE8F0[i] + 0x700;
            gpSprite[spritenum_].cstat = 0x1000;
            gpSprite[spritenum_].unk22 = 0x1234;

            if (i == 40)
            {
                if (D_8019B940[D_80106D50[spritenum]].unk54 > 180)
                    gpSprite[spritenum_].picnum = 1858;
            }

            if (i == 41)
            {
                if (D_8019B940[D_80106D50[spritenum]].unk54 > 12)
                    gpSprite[spritenum_].picnum = 1797;
            }

            if (((i == 2) || (i == 3)) && (D_801CA14C[gMapNum].unk0 == 2))
                gpSprite[spritenum_].picnum = 1852;

            if (i == 4)
            {
                if (gpSprite[spritenum].unk25 == 50)
                    gpSprite[spritenum_].picnum = 1910;
            }

            if ((gpSprite[spritenum].unk2B == 1) && (i != 34))
            {
                if (gpSprite[spritenum_].picnum == 1914)
                    gpSprite[spritenum_].picnum = 1813;
                else if (gpSprite[spritenum_].picnum == 1910)
                    gpSprite[spritenum_].picnum++;
                else
                    gpSprite[spritenum_].picnum += 2;
            }

            if ((D_8019B940[D_80106D50[spritenum]].unk0 & 0x400) &&
                (D_8019B940[D_80106D50[spritenum]].unk99 != 8) && ((krand() % 10) >= 10))
            {
                gpSprite[spritenum_].picnum = 1897;
                gpSprite[spritenum_].unk22 = (krand() % 74) + 24;
            }
        }
    }
}

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

/*80056C00*/
static void func_80056C00(s32 spritenum)
{
    SpriteType *spr;
    code0UnkStruct3 *ptr;
    s32 cond;
    s16 i, nexti;
    s32 x1, y1, x2, y2;
    s32 ang;
    s32 d1, d2, d3;
    s16 cond2;

    i = gHeadSpriteStat[2];
    gSnoozingAliens = 0;
    gAlertAliens = 0;
    cond = gpSprite[spritenum].statnum == 10;

    while (i >= 0)
    {
        nexti = gNextSpriteStat[i];
        ptr = &D_8019B940[D_80106D50[i]];
        if (ptr->unk6C != 0)
            ptr->unk6C = audio_80007A80(ptr->unk6C, i, ptr->unk74);

        if (ptr->unk70 != 0)
            ptr->unk70 = audio_80007A80(ptr->unk70, i, ptr->unk78);

        if (gMapNum == MAP_WETWORLD)
            d1 = 25000;
        else
            d1 = 30000;

        if ((D_8019B940[D_80106D50[i]].unkC != 0) && (D_8019B940[D_80106D50[i]].unk0 & 1))
        {
            spr = &gpSprite[i];
            d2 = klabs_(gpSprite[spritenum].x - spr->x) + klabs_(gpSprite[spritenum].y - spr->y);
            if (d2 < d1)
            {
                ang = ((krand() & 0x7F) - 64);
                x2 = gpSprite[spritenum].x - ang;
                ang = ((krand() & 0x7F) - 64);
                y2 = gpSprite[spritenum].y - ang;
                ang = ((krand() & 0x7F) - 64);
                x1 = spr->x - ang;
                ang = ((krand() & 0x7F) - 64);
                y1 = spr->y - ang;

                if (cond == 0)
                    cond2 = 1;
                else
                    cond2 = canSee(x1, y1, (spr->z - ((krand() % 40) << 8)), spr->sectnum,
                                    x2, y2, ((gpSprite[spritenum].z - ((krand() % 40) << 8))),
                                    gpSprite[spritenum].sectnum);

                if (cond2 != 0)
                    changeSpriteStat(i, 1);
            }
        }
        i = nexti;
    }

    if (D_800DEF1C == -1)
    {
        i = gHeadSpriteStat[1];
        while (i >= 0)
        {
            nexti = gNextSpriteStat[i];
            ptr = &D_8019B940[D_80106D50[i]];

            if (ptr->unk6C != 0)
                ptr->unk6C = audio_80007A80(ptr->unk6C, i, ptr->unk74);

            if (ptr->unk70 != 0)
                ptr->unk70 = audio_80007A80(ptr->unk70, i, ptr->unk78);

            if (D_8019B940[D_80106D50[i]].unkC != 0)
            {
                if ((D_8019B940[D_80106D50[i]].unk0 & 1) &&
                    !(D_8019B940[D_80106D50[i]].unk0 & 0x40000) &&
                    !(D_8019B940[D_80106D50[i]].unk4 & 0x40))
                {
                    spr = &gpSprite[i];
                    d2 = klabs_(gpSprite[spritenum].x - spr->x) + klabs_(gpSprite[spritenum].y - spr->y);
                    d3 = D_800DEED4;

                    if ((gMapNum == MAP_UP_SHIP_CREEK) && (cond == 0))
                        d3 >>= 1;

                    if (gpSprite[i].picnum == 2468)
                        d3 += 10000;

                    if (gMapNum == MAP_WETWORLD)
                        d3 = 30000;

                    if ((d3 < d2) && (D_8013B2D0[i].unk6 == 0))
                    {
                        ang = ((krand() & 0x7F) - 64);
                        x2 = gpSprite[spritenum].x - ang;
                        ang = ((krand() & 0x7F) - 64);
                        y2 = gpSprite[spritenum].y - ang;
                        ang = ((krand() & 0x7F) - 64);
                        x1 = spr->x - ang;
                        ang = ((krand() & 0x7F) - 64);
                        y1 = spr->y - ang;

                        cond2 = canSee(x1, y1, (spr->z - ((krand() % 40) << 8)), spr->sectnum,
                                       x2, y2, ((gpSprite[spritenum].z - ((krand() % 40) << 8))),
                                       gpSprite[spritenum].sectnum);

                        if (cond2 == 0)
                            changeSpriteStat(i, 2);
                    }
                }
            }
            i = nexti;
        }
    }

    i = gHeadSpriteStat[1];
    gAlertAliens = 0;
    gSnoozingAliens = 0;

    while (i >= 0)
    {
        i = gNextSpriteStat[i];
        gAlertAliens++;
    }

    i = gHeadSpriteStat[2];
    while (i >= 0)
    {
        i = gNextSpriteStat[i];
        gSnoozingAliens++;
    }
}

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

/*80057540*/
INCLUDE_ASM("nonmatchings/src/code0/41940", func_80057540);

/*80057E7C*/
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
                d1 = d2;
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
void func_800587B8(s32 spritenum, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6)
{
    func_8007AED8(gpSprite[spritenum].x, gpSprite[spritenum].y, gpSprite[spritenum].z,
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
        if ((z < z1) && (z2 < z))
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
/*80058E44*/
INCLUDE_ASM("nonmatchings/src/code0/41940", func_80058E44);
#endif
