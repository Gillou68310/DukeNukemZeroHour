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
#include "code0/6D9E0.h"
#include "code0/7BA50.h"
#include "code0/87010.h"
#include "code0/A06F0.h"
#include "code0/8EFE0.h"
#include "code0/95500.h"
#include "code0/96A80.h"
#include "code0/code0.h"
#include "code1/code1.h"
#include "code1/EB300.h"
#include "static/105F50.h"

typedef void (*_41940UnkFuncPointer1)(s32 spritenum, s32 arg1);
typedef s32(*_41940UnkFuncPointer2)(s32 spritenum);

typedef struct
{
    /*0x00*/ s16 unk0;  /*spritenum?*/
    /*0x02*/ s16 unk2;
    /*0x04*/ s32 unk4;  /*x?*/
    /*0x08*/ s32 unk8;  /*y?*/
    /*0x0C*/ s32 unkC;  /*z?*/
    /*0x10*/ s32 unk10; /*x?*/
    /*0x14*/ s32 unk14; /*y?*/
    /*0x18*/ s32 unk18; /*z?*/
    /*0x1C*/ u8 unk1C;
    /*0x1D*/ s8 unk1D;
} _41940UnkStruct1;

static s32 func_80041968(s32 spritenum);
static s32 func_80043878(s32 spritenum);
static s32 ifNotVarAnd(s32 spritenum);
static s32 func_80042A6C(s32 spritenum);
static s32 func_80043DE4(s32 spritenum);
static s32 func_80043870(s32 spritenum);
static s32 func_80042598(s32 spritenum);
static s32 func_800437F4(s32 spritenum);
static s32 func_80042AE4(s32 spritenum);
static s32 func_800422BC(s32 spritenum);
static s32 func_80044000(s32 spritenum);
static s32 func_8004201C(s32 spritenum);
static s32 func_8004204C(s32 spritenum);
static s32 func_80042094(s32 spritenum);
static s32 func_8004BE48(s32 spritenum);
static s32 func_80042B98(s32 spritenum);
static s32 func_80043A74(s32 spritenum);
static s32 func_80043B10(s32 spritenum);
static s32 func_80044394(s32 spritenum);
static s32 setVarVar(s32 spritenum);
static s32 addVarVar(s32 spritenum);
static s32 subVarVar(s32 spritenum);
static s32 func_80044B38(s32 spritenum);
static s32 andVarVar(s32 spritenum);
static s32 ifVarVarLE(s32 spritenum);
static s32 ifVarVarAE(s32 spritenum);
static s32 func_80043894(s32 spritenum);
static s32 func_80042434(s32 spritenum);
static s32 ifVarVarN(s32 spritenum);
static s32 ifVarVarE(s32 spritenum);
static s32 multVarVar(s32 spritenum);
static s32 divVarVar(s32 spritenum);
static s32 func_80046494(s32 spritenum);
static s32 orVarVar(s32 spritenum);
static s32 func_80045704(s32 spritenum);
static s32 func_80043BAC(s32 spritenum);
static s32 func_8004B440(s32 spritenum);
static s32 func_80045690(s32 spritenum);
static s32 absVarVar(s32 spritenum);
static s32 func_80044F9C(s32 spritenum);
static s32 func_80045DA8(s32 spritenum);
static s32 negVarVar(s32 spritenum);
static s32 func_80045228(s32 spritenum);
static s32 func_80045B64(s32 spritenum);
static s32 func_80045C44(s32 spritenum);
static s32 func_80045D34(s32 spritenum);
static s32 func_80042178(s32 spritenum);
static s32 func_800450E0(s32 spritenum);
static s32 func_8004BE20(s32 spritenum);
static s32 func_80041D10(s32 spritenum);
static s32 func_80058468(s32 spritenum);
static s32 func_80045CB8(s32 spritenum);
static s32 func_80042210(s32 spritenum);
static s32 func_800420C8(s32 spritenum);
static s32 func_80043D64(s32 spritenum);
static s32 func_80043938(s32 spritenum);
static s32 func_800457BC(s32 spritenum);
static s32 func_8004587C(s32 spritenum);
static s32 func_80043E7C(s32 spritenum);
static s32 func_8004423C(s32 spritenum);
static s32 modVarVar(s32 spritenum);
static s32 func_800458D0(s32 spritenum);
static s32 func_80045988(s32 spritenum);
static s32 func_80045A48(s32 spritenum);
static s32 func_80042380(s32 spritenum);
static s32 func_80044120(s32 spritenum);
static s32 func_80042C18(s32 spritenum);
static s32 func_80042B40(s32 spritenum);
static s32 func_800439D0(s32 spritenum);
static s32 func_80043F3C(s32 spritenum);

/*.data*/
/*800DEE80*/ s32 D_800DEE80 = 0;
/*800DEE84*/ s32 gDisableAI = FALSE;
/*800DEE88*/ s32 D_800DEE88 = 0;
/*800DEE8C*/ s32 D_800DEE8C = 0;
static s32 _unused1[2] = {0};
/*800DEE98*/ s32 D_800DEE98 = 0;
/*800DEE9C*/ s32 D_800DEE9C = 1;
/*800DEEA0*/ s32 D_800DEEA0 = 0;
static s32 _unused2 = 0;
/*800DEEA8*/ s32 gAiDebugGvar1 = 0;
/*800DEEAC*/ s32 gAiDebugGvar2 = 0;
/*800DEEB0*/ s32 gAiDebugGvar3 = 0;
static s32 _unused3 = -1;
/*800DEEB8*/ s32 D_800DEEB8 = 0;
/*800DEEBC*/ s32 D_800DEEBC = -1;
/*800DEEC0*/ s32 gInvulnerability = 0;
static s32 _unused4 = 0;
/*800DEEC8*/ static s32 D_800DEEC8 = 0;
static s32 _unused5 = 0;
/*800DEED0*/ u8 D_800DEED0[MAXPLAYERS] = {0};
/*800DEED4*/ static s32 D_800DEED4 = 35000;
static s32 _unused6[3] = {255, 111, 0};
/*800DEEE4*/ u8 D_800DEEE4[MAXPLAYERS] = {0};
/*800DEEE8*/ s32 gAutoAim = 1;
static s32 _unused7[9] = {-1, -1, -1, -1, -1, -1, -1, -1, 0};
/*800DEF10*/ static s32 D_800DEF10 = 0;
/*800DEF14*/ static s32 D_800DEF14 = 100; /*damage?*/
/*800DEF18*/ static s32 D_800DEF18 = 100; /*damage?*/
/*800DEF1C*/ s32 D_800DEF1C = -1;
/*800DEF20*/ static s16 D_800DEF20 = 64;
static s32 _unused9[5] = {0, 0, 0, 4, 0};
/*800DEF38*/ static s32 D_800DEF38 = 0;

/*800DEF3C*/
static _41940UnkFuncPointer2 D_800DEF3C[84] = {
    func_80041968,
    func_80043878,
    ifNotVarAnd,
    func_80042A6C,
    func_80043DE4,
    func_80043870,
    func_80042598,
    func_80043870,
    func_80043870,
    func_80043870,
    func_800437F4,
    func_80042AE4,
    func_800422BC,
    func_80044000,
    func_80043870,
    func_80043870,
    func_8004201C,
    func_8004204C,
    func_80042094,
    func_80043870,
    func_8004BE48,
    func_80042B98,
    func_80043A74,
    func_80043B10,
    func_80044394,
    setVarVar,
    addVarVar,
    subVarVar,
    func_80044B38,
    andVarVar,
    ifVarVarLE,
    ifVarVarAE,
    func_80043894,
    func_80042434,
    ifVarVarN,
    ifVarVarE,
    multVarVar,
    divVarVar,
    func_80046494,
    orVarVar,
    func_80045704,
    func_80043BAC,
    func_8004B440,
    func_80045690,
    absVarVar,
    func_80043870,
    func_80043870,
    func_80043870,
    func_80044F9C,
    func_8004BD24,
    func_80045DA8,
    negVarVar,
    func_80045228,
    func_80045B64,
    func_80043870,
    func_80045C44,
    func_80045D34,
    func_80042178,
    func_800450E0,
    func_8004BE20,
    func_80041D10,
    func_80058468,
    func_80045CB8,
    func_80042210,
    func_800420C8,
    func_80043D64,
    func_80043938,
    func_800457BC,
    func_8004587C,
    func_80043870,
    func_80043E7C,
    func_8004423C,
    modVarVar,
    func_800458D0,
    func_80045988,
    func_80045A48,
    func_80042380,
    func_80043870,
    func_80043870,
    func_80044120,
    func_80042C18,
    func_80042B40,
    func_800439D0,
    func_80043F3C,
};

/*800DF08C*/ static u8 *D_800DF08C = NULL;

/*800DF090*/
static s16 D_800DF090[32] = {
    -1, -1, ENFORCER2, ENFORCERCAPTAIN2, BATTLEENFORCER2, -1, PIGCOP2, RIOTPIG2, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, CAPITALISTPIG2, COWBOYGRUNT2, SAVAGEGRUNT2, SOLDIERGRUNT2, WARPIG2, ROADHOG2, -1, -1, 0,
};

/*800DF0D0*/
static s16 D_800DF0D0[32] = {
    -1, -1, ENFORCER3, ENFORCERCAPTAIN3, BATTLEENFORCER3, -1, PIGCOP3, RIOTPIG3, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, CAPITALISTPIG3, COWBOYGRUNT3, SAVAGEGRUNT3, SOLDIERGRUNT3, WARPIG3, ROADHOG3, -1, -1, 0,
};

/*800DF110*/
static s16 D_800DF110[32] = {
    -1, -1, ENFORCER1, ENFORCERCAPTAIN1, BATTLEENFORCER1, -1, PIGCOP1, RIOTPIG1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, CAPITALISTPIG1, COWBOYGRUNT1, SAVAGEGRUNT1, SOLDIERGRUNT1, WARPIG1, ROADHOG1, -1, -1, 0,
};

/*800DF150*/
static s16 D_800DF150[32] = {
    -1, -1, ENFORCER4, ENFORCERCAPTAIN4, BATTLEENFORCER4, -1, PIGCOP4, RIOTPIG4, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, CAPITALISTPIG4, COWBOYGRUNT4, SAVAGEGRUNT4, SOLDIERGRUNT4, WARPIG4, ROADHOG4, -1, -1, 0,
};

/*800DF190*/ static s16 D_800DF190[8] = {47, 54, 43, 54, 6, 7, 8, 0};
/*800DF1A0*/ static s16 D_800DF1A0[4] = {6, 7, 8, 0};
/*800DF1A8*/ s32 D_800DF1A8 = -1;
/*800DF1AC*/ s16 D_800DF1AC[MAXPLAYERS] = {0};
/*800DF1B4*/ s16 D_800DF1B4[4] = {650, 651, 652, 702};
static s32 _unused10 = 0; /*TODO: File split?*/

/*.comm*/
/*800FE9D4*/ s32 D_800FE9D4;
/*800FEA94*/ s32 D_800FEA94;
/*80137DF0*/ s16 D_80137DF0[1024] ALIGNED(16); /*spritenum array*/
/*80138718*/ intptr_t *gpInst;
/*80138794*/ intptr_t *D_80138794;
/*80138820*/ s16 D_80138820[8] ALIGNED(8); /*sectornum array*/
/*80168CF8*/ s32 D_80168CF8;
/*80169524*/ s32 D_80169524;
/*80197E30*/ s32 D_80197E30;
/*8019955C*/ s16 D_8019955C;
/*8019995C*/ s32 D_8019995C;
/*8019B89C*/ s32 D_8019B89C; /*unused*/
/*801A1974*/ s32 D_801A1974;
/*801A1978*/ s16 D_801A1978; /*sector count*/
/*801A68A0*/ s32 D_801A68A0;
/*801A68C8*/ s32 D_801A68C8;
/*801AC590*/ s32 D_801AC590;
/*801AC8D0*/ s32 D_801AC8D0;
/*801ACC70*/ _41940UnkStruct1 D_801ACC70[32] ALIGNED(16);
/*801C0D68*/ s32 D_801C0D68;

/*.text*/
static s32 func_800413CC(s32 spritenum);
static void func_800418B8(s32);
static s32 func_80042C98(s32 spritenum);
static s32 func_800433D4(s32 spritenum);
static s32 func_8004BC24(s32, s32);
static s32 func_8004DE60(s32 spritenum, s32);
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
static void func_80053650(s32 picnum, s32 spritenum);
static void func_80055DDC(s32 spritenum);
static void func_80056C00(s32);
static void func_80057E7C(void);
static s32 func_80058538(SpriteType *spr, s32);
static s32 func_80058DE0(SpriteType *spr, s32 *);
static void func_8004EBE4(s32 spritenum);
static void func_80050480(s16, s16 spritenum);
static void func_8004B2B0(s32 spritenum, s32, s32);
static s32 func_8004364C(s32);
static void func_800515A0(s16 sectnum);
static void func_8004A590(s32 spritenum);

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

    if (gDisableAI == FALSE)
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
            ptr = gModelList[D_80118248->picnum-MODELLIST];
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
                    D_800DF08C = (u8 *)((intptr_t)gpInst - (intptr_t)D_0100F1E0_STATIC);
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
        (ldist(&gpSprite[D_80118248->unk16], D_80118248) >= gpSprite[D_80118248->unk16].lotag) &&
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
static s32 func_80041968(s32 spritenum)
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
static s32 func_80041D10(s32 spritenum)
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
            cond = (func_80036490(D_80118248->sectnum) < z2) ? 0 : cond;
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
static s32 func_8004201C(s32 spritenum)
{
    s32 i;
    gpInst++;
    i = *gpInst++;
    gpInst = &gpInst[i];
    return 0;
}

/*8004204C*/
static s32 func_8004204C(s32 spritenum)
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
static s32 func_80042094(s32 spritenum)
{
    gpInst++;
    gpInst = D_80137DE0->unk1C;
    D_80137DE0->unk1C = NULL;
    return 0;
}

/*800420C8*/
static s32 func_800420C8(s32 spritenum)
{
    s32 result;

    gpInst++;
    result = getVar(spritenum, *gpInst++);
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
static s32 func_80042178(s32 spritenum)
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
static s32 func_80042210(s32 spritenum)
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
static s32 func_800422BC(s32 spritenum)
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
static s32 func_80042380(s32 spritenum)
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
static s32 func_80042434(s32 spritenum)
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
static s32 func_80042598(s32 spritenum)
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
            cond = (func_80036490(D_80118248->sectnum) < z2) ? 0 : cond;
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
static s32 ifVarVarN(s32 spritenum)
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
static s32 ifNotVarAnd(s32 spritenum)
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
static s32 ifVarVarE(s32 spritenum)
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
static s32 func_80042A6C(s32 spritenum)
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
static s32 func_80042AE4(s32 spritenum)
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
static s32 func_80042B40(s32 spritenum)
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
static s32 func_80042B98(s32 spritenum)
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
static s32 func_80042C18(s32 spritenum)
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
static s32 func_80042C98(s32 spritenum)
{
    u16 cstat2;
    s16 hitsect, hitwall, hitsprite;
    s32 hitx, hity, hitz;
    s32 vx, vy, vz;

    SpriteType *spr;
    SpriteType *spr2;
    code0UnkStruct3 *ptr;

    s32 ret;
    s32 i, j, k;
    u16 cstat;

    cstat2 = 0;
    ptr = &D_8019B940[D_80106D50[spritenum]];
    i = ptr->unk28;
    spr = &gpSprite[spritenum];

    if ((ptr->unk0 & 0x1800) && (hitsprite == i))
    {
        D_80137DE0->unk38 = gpSprite[i].x;
        D_80137DE0->unk3C = gpSprite[i].y;
        D_80137DE0->unk40 = gpSprite[i].z;
        if (i == -1)
            return 0;
    }

    if ((ptr->unk0 & 0x1800) && (ptr->unk28 != -1))
        spr2 = &gpSprite[ptr->unk28];
    else
        spr2 = &gpSprite[gPlayer[0].unk4A];

    vx = spr2->x - spr->x;
    vy = spr2->y - spr->y;
    if (D_80197E30 == 0)
        j = D_801B0D30;
    else
        j = -D_801B0D30;

    if (ptr->unk0 & 0x800)
    {
        k = (spr->z - (j / 2)) + 0x1000;
        vz = spr2->z - k;
    }
    else
    {
        k = (spr->z - (j / 2)) + 0x1E80;
        vz = spr2->z - k;
    }

    cstat = spr->cstat;
    spr->cstat = cstat & 0xFEFE;
    hitScan(spr->x, spr->y, spr->z - (j /2), spr->sectnum, vx, vy, vz,
            &hitsect, &hitwall, &hitsprite, &hitx, &hity, &hitz, 0x01000040);
    ret = 0;
    spr->cstat = cstat;
    if ((hitwall != -1) && (func_8004364C(gpWall[hitwall].overpicnum) != 0))
    {
        s32 a = hitwall;
        i = ~0x41;
        cstat = gpWall[hitwall].cstat;
        gpWall[hitwall].cstat = cstat & i;
        if (gpWall[hitwall].nextwall != -1)
        {
            cstat2 = gpWall[gpWall[hitwall].nextwall].cstat;
            gpWall[gpWall[hitwall].nextwall].cstat = cstat2 & i;
        }

        hitScan(hitx, hity, hitz, hitsect, vx, vy, vz, &hitsect,
                &hitwall, &hitsprite, &hitx, &hity, &hitz, 0x01000040);
        gpWall[a].cstat = cstat;
        if (gpWall[a].nextwall != -1)
            gpWall[gpWall[a].nextwall].cstat = cstat2;
    }

    if ((hitsect != -1) && (hitsprite != -1))
    {
        i = ptr->unk28;
        if ((ptr->unk0 & 0x1800) && (hitsprite == i))
        {
            D_80137DE0->unk38 = gpSprite[i].x;
            D_80137DE0->unk3C = gpSprite[i].y;
            D_80137DE0->unk40 = gpSprite[i].z;
            ret = 1;
        }
        else if (gpSprite[hitsprite].statnum == 10)
        {
            D_80137DE0->unk38 = gPlayer[0].xpos;
            D_80137DE0->unk3C = gPlayer[0].ypos;
            D_80137DE0->unk40 = gPlayer[0].zpos;
            ret = 1;
        }
    }

    if (ret == 0)
    {
        cstat = spr->cstat;
        vz = (spr2->z - (spr->z - j)) - 0x3100;
        spr->cstat = cstat & 0xFEFE;

        hitScan(spr->x, spr->y, (spr->z - (0x400 + j)), spr->sectnum, vx, vy, vz,
                &hitsect, &hitwall, &hitsprite, &hitx, &hity, &hitz, 0x01000040);

        spr->cstat = cstat;
        if ((hitwall != -1))
        {
            if ((func_8004364C(gpWall[hitwall].overpicnum) != 0))
            {
                s32 a = hitwall;
                i = ~0x41;
                cstat = gpWall[a].cstat;
                gpWall[a].cstat = cstat & i;
                if (gpWall[a].nextwall != -1)
                {
                    cstat2 = gpWall[gpWall[a].nextwall].cstat;
                    gpWall[gpWall[a].nextwall].cstat = cstat2 & i;
                }

                hitScan(hitx, hity, hitz, hitsect, vx, vy, vz,
                        &hitsect, &hitwall, &hitsprite, &hitx, &hity, &hitz, 0x01000040);

                gpWall[a].cstat = cstat;
                if (gpWall[a].nextwall != -1)
                    gpWall[gpWall[a].nextwall].cstat = cstat2;
            }
        }

        if ((hitsect != -1) && (hitsprite != -1))
        {
            i = ptr->unk28;
            if ((ptr->unk0 & 0x1800) && (hitsprite == i))
            {
                D_80137DE0->unk38 = gpSprite[i].x;
                D_80137DE0->unk3C = gpSprite[i].y;
                D_80137DE0->unk40 = gpSprite[i].z;
                ret = 1;
            }
            else if (gpSprite[hitsprite].statnum == 10)
            {
                D_80137DE0->unk38 = gPlayer[0].xpos;
                D_80137DE0->unk3C = gPlayer[0].ypos;
                D_80137DE0->unk40 = gPlayer[0].zpos;
                ret = 1;
            }
        }
    }
    return ret;
}

/*800433D4*/
static s32 func_800433D4(s32 spritenum)
{
    s16 hitsect, hitwall, hitsprite;
    s32 hitx, hity, hitz;
    SpriteType *spr;
    SpriteType *spr2;
    u16 cstat;
    s32 vx, vy, vz;
    s32 cond;
    s32 z1, z2, z3;

    spr = &gpSprite[spritenum];
    cstat = spr->cstat;
    spr2 = &gpSprite[gPlayer[0].unk4A];
    vx = spr2->x - spr->x;
    vy = spr2->y - spr->y;
    z1 = (spr->z - D_801B0D30) + 0x3500;
    vz = spr2->z - z1;
    spr->cstat = cstat & 0xFEFE;
    z2 = (spr->z - 0x400);

    hitScan(spr->x,
            spr->y,
            z2 - D_801B0D30,
            spr->sectnum,
            vx,
            vy,
            vz,
            &hitsect, &hitwall, &hitsprite, &hitx, &hity, &hitz, 0x01000040);

    cond = 0;
    spr->cstat = cstat;

    if ((hitsect != -1) && (hitsprite != -1))
        cond = gpSprite[hitsprite].statnum == 10;

    cstat = spr->cstat;
    z3 = ((spr->z - (D_801B0D30 / 2)) + 0x1E80);
    vz = spr2->z - z3;
    spr->cstat = cstat & 0xFEFE;

    hitScan(spr->x,
        spr->y,
        spr->z - (D_801B0D30 / 2),
        spr->sectnum,
        vx,
        vy,
        vz,
        &hitsect, &hitwall, &hitsprite, &hitx, &hity, &hitz, 0x01000040);

    spr->cstat = cstat;

    if (hitsect != -1)
    {
        if ((hitsprite != -1) || (hitwall != -1))
        {
            if ((gpSprite[hitsprite].statnum != 10) || (hitwall != -1))
                cond++;
        }
    }
    return (cond == 2);
}

/*8004364C*/
static s32 func_8004364C(s32 arg0)
{
    switch (arg0)
    {
    case 3138:
    case 3150:
    case 3172:
    case 3185:
    case 3305:
    case 3357:
    case 3382:
    case 3678:
    case 4706:
    case 4765:
    case 4766:
    case 4767:
    case 4768:
    case 4769:
    case 4770:
    case 4773:
    case 4814:
    case 5162:
    case 5200:
    case 5205:
    case 5215:
    case 5220:
    case 5231:
    case 5300:
    case 5390:
    case 5519:
    case 5651:
    case 5865:
    case 5905:
    case 5968:
    case 5969:
        return 1;

    default:
        return 0;
    }
}

/*800437F4*/
static s32 func_800437F4(s32 spritenum)
{
    gpInst++;
    D_80118248->xrepeat = getVar(spritenum, *gpInst++);
    D_80118248->yrepeat = getVar(spritenum, *gpInst++);
    return 0;
}

/*80043870*/
static s32 func_80043870(s32 spritenum)
{
}

/*80043878*/
static s32 func_80043878(s32 spritenum)
{
    gpInst++;
    return 2;
}

/*80043894*/
static s32 func_80043894(s32 spritenum)
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
static s32 func_80043938(s32 spritenum)
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
static s32 func_800439D0(s32 spritenum)
{
    s32 i, j, chapter;

    i = *gpInst++;
    chapter = getVar(spritenum, *gpInst++);
    j = *gpInst++;

    if (i < 0)
        j += 2;

    if (gMapChapter[gMapNum].chapter != chapter)
        gpInst = &gpInst[j];

    return 0;
}

/*80043A74*/
static s32 func_80043A74(s32 spritenum)
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
static s32 func_80043B10(s32 spritenum)
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
static s32 func_80043BAC(s32 spritenum)
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
static s32 ifVarVarLE(s32 spritenum)
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
static s32 func_80043D64(s32 spritenum)
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
static s32 func_80043DE4(s32 spritenum)
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
static s32 func_80043E7C(s32 spritenum)
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
static s32 func_80043F3C(s32 spritenum)
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
static s32 func_80044000(s32 spritenum)
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
static s32 func_80044120(s32 spritenum)
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
static s32 func_8004423C(s32 spritenum)
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
static s32 ifVarVarAE(s32 spritenum)
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
static s32 func_80044394(s32 spritenum)
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
static s32 setVarVar(s32 spritenum)
{
    s32 i, result;

    gpInst++;
    i = *gpInst++;
    result = getVar(spritenum, *gpInst++);
    setVar(spritenum, i, result);
    return 0;
}

/*800448C0*/
static s32 addVarVar(s32 spritenum)
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
static s32 subVarVar(s32 spritenum)
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
static s32 multVarVar(s32 spritenum)
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
static s32 divVarVar(s32 spritenum)
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
static s32 func_80044B38(s32 spritenum)
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
static s32 func_80044F9C(s32 spritenum)
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
static s32 func_800450E0(s32 spritenum)
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
static s32 func_80045228(s32 spritenum)
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
static s32 andVarVar(s32 spritenum)
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
static s32 modVarVar(s32 spritenum)
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
static s32 orVarVar(s32 spritenum)
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
static s32 func_80045690(s32 spritenum)
{
    gpInst++;
    D_8013B2D0[spritenum].unk2 = (D_80118248->unk1C >> 0xC) >> getVar(spritenum, *gpInst++);
    return 0;
}

/*80045704*/
static s32 func_80045704(s32 spritenum)
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
static s32 func_800457BC(s32 spritenum)
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
static s32 func_8004587C(s32 spritenum)
{
    musHandle handle;

    handle = D_80137DE0->unk6C;
    gpInst++;
    if (handle)
    {
        MusHandleStop(handle, 0);
        D_80137DE0->unk6C = 0;
    }
    return 0;
}

/*800458D0*/
static s32 func_800458D0(s32 spritenum)
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
static s32 func_80045988(s32 spritenum)
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
static s32 func_80045A48(s32 spritenum)
{
    musHandle handle;

    handle = D_80137DE0->unk70;
    gpInst++;
    if (handle)
    {
        MusHandleStop(handle, 0);
        D_80137DE0->unk70 = 0;
    }
    return 0;
}

/*80045A9C*/
static s32 absVarVar(s32 spritenum)
{
    s32 i, result;

    gpInst++;
    i = *(gpInst++);
    result = getVar(spritenum, i);
    setVar(spritenum, i, klabs(result));
    return 0;
}

/*80045B04*/
static s32 negVarVar(s32 spritenum)
{
    s32 i, result;

    gpInst++;
    i = *gpInst++;
    result = getVar(spritenum, i);
    setVar(spritenum, i, -result);
    return 0;
}

/*80045B64*/
static s32 func_80045B64(s32 spritenum)
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
static s32 func_80045C44(s32 spritenum)
{
    intptr_t *ptr;

    gpInst++;
    ptr = D_0100F1E0_STATIC;
    ptr = &ptr[getVar(spritenum, *gpInst++)];
    D_80137DE0->unk10 = ptr;
    return 0;
}

/*80045CB8*/
static s32 func_80045CB8(s32 spritenum)
{
    intptr_t *ptr;

    gpInst++;
    ptr = D_0100F1E0_STATIC;
    ptr = &ptr[getVar(spritenum, *gpInst++)];
    D_80137DE0->unk20 = ptr;
    D_80137DE0->unk2A = 0;
    D_80137DE0->unk2C = 0;
    return 0;
}

/*80045D34*/
static s32 func_80045D34(s32 spritenum)
{
    intptr_t *ptr;

    gpInst++;
    ptr = D_0100F1E0_STATIC;
    ptr = &ptr[getVar(spritenum, *gpInst++)];
    D_80137DE0->unk14 = ptr;
    return 0;
}

/*80045DA8*/
static s32 func_80045DA8(s32 spritenum)
{
    intptr_t *ptr;
    SpriteType *spr;

    gpInst++;
    ptr = D_0100F1E0_STATIC;
    spr = &gpSprite[spritenum];
    ptr = &ptr[getVar(spritenum, *gpInst++)];
    *(intptr_t *)&spr->hitag = (intptr_t)ptr; /*TODO: addr or integer?*/
    spr->lotag = 0;
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
        id = D_80118248->lotag;
        break;
    case 0x4000002C:
        id = D_80118248->hitag;
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
static s32 func_80046494(s32 spritenum)
{
    gpInst++;
    switch ((s32)*gpInst++)
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

    switch ((s32)*gpInst++)
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
static void func_80046540(void)
{
    s16 unk86;
    s32 ang;
    s32 unk84;
    s16 ang2;
    s16 i, j, nexti;
    s32 delta;
    s32 picnum;
    s32 z;
    s32 spritenum;
    s32 unk9E;
    s32 sp24;
    s16 temp;

    i = gHeadSpriteStat[320];
    while (i >= 0)
    {
        gpSprite[i].cstat &= ~0x101;
        nexti = gNextSpriteStat[i];

        if (D_8013B2D0[i].unk6 < 243)
            D_8013B2D0[i].unk6 += 12;
        else
            func_8004BD24(i);

        i = nexti;
    }

    i = gHeadSpriteStat[53];
    while (i >= 0)
    {
        gpSprite[i].cstat &= 0xFEFE;
        nexti = gNextSpriteStat[i];
        func_80017268(i);
        D_800FE400 = i;
        D_80118248 = &gpSprite[i];
        D_8012F6E8 = func_8005A240(i);
        D_80137DE0 = &D_8019B940[D_80106D50[i]];
        z = (gModelList[gpSprite[i].picnum-MODELLIST]->unk2E - gModelList[gpSprite[i].picnum-MODELLIST]->unk28) << 6;

        if ((D_8012F6E8 == 1) && (D_80118248->picnum == CYBORGENFORCER))
        {
            func_8004A590(i);
            return;
        }
        j = D_800DF1A0[krand() % 3];
        func_8004D884();
        func_8004DC74();

        if (gpSprite[i].unk18 == 0)
        {
            if (krand() & 1)
            {
                if ((D_80137DE0->unk84 == 0) || (D_80137DE0->unk84 == 11) || (D_80137DE0->unk84 == 8) || (D_80137DE0->unk84 == 18))
                    func_8008E3E0(gpSprite[i].x, gpSprite[i].y, gpSprite[i].z, gpSprite[i].sectnum, 36, 0);
                else if ((gMapNum != MAP_BRAINSTORM) && (D_80137DE0->unk9E != 9))
                    func_8008E3E0(gpSprite[i].x, gpSprite[i].y, gpSprite[i].z, gpSprite[i].sectnum, 11, 0);
            }

            sp24 = func_8004F4A0(i);
            if ((D_80137DE0->unk84 < 36 || D_80137DE0->unk84 >= 38) && (D_80137DE0->unk84 < 38 || D_80137DE0->unk84 >= 44))
            {
                if ((D_8012F6E8 == 2) && ((D_80137DE0->unk86 == 44) || (D_80137DE0->unk86 == 40)))
                {
                    j = 39;
                }
                else if ((D_8012F6E8 == 2) && (D_80137DE0->unk86 == 36))
                {
                    j = 39;
                }
                else if (D_80137DE0->unk84 == 18)
                {
                    j = 149;
                }
                else if (D_80137DE0->unk84 == 8)
                {
                    j = 94;
                }
                else if ((D_80137DE0->unk4 & 0x20) && (D_8012F6E8 == 1))
                {
                    j = 74;
                    gpSprite[i].unk18 = 2;
                    goto label1;
                }
                else if ((D_80137DE0->unk86 == 121) && (D_8012F6E8 == 1))
                {
                    j = 142;
                }
                else if ((D_80137DE0->unk97 != 0) && (D_8012F6E8 == 1))
                {
                    if ((krand() & 7) >= 4)
                        j = 101;
                }
                else if ((D_80137DE0->unk4 & 0x20) && (D_80118248->picnum == CHIMERA))
                {
                    j = 97;
                    gpSprite[i].unk18 = 2;
                    goto label1;
                }
                else if (D_80118248->picnum == CHIMERA)
                {
                    j = 96;
                }
                else if ((D_8012F6E8 == 1) && (D_80137DE0->unk98 >= 41) && (D_80137DE0->unk98 < 50))
                {
                    func_800361F4(i, 0);
                    j = 55;
                }
                else
                {
                    ang = D_80118248->ang;
                    ang2 = getAngle(gPlayer[0].xpos - D_80118248->x, gPlayer[0].ypos - D_80118248->y);

                    if (getAngleDelta(ang, ang2) > 0)
                        delta = getAngleDelta(ang, ang2);
                    else
                        delta = -getAngleDelta(ang, ang2);

                    picnum = D_80118248->picnum;
                    unk84 = D_80137DE0->unk84;
                    j = D_800DF190[krand() % 7];

                    if (D_80137DE0->unk9E == 9)
                    {
                        j = 65;
                    }
                    else if (D_80137DE0->unk9E == 0)
                    {
                        j = 43;
                        if (krand() & 1)
                            j = 54;
                    }
                    else
                    {
                        unk9E = D_80137DE0->unk9E;
                        if (((unk9E == 20) || (unk9E == 0) || (unk9E == 17)) == 0)
                        {
                            if (D_80137DE0->unk44 != 0)
                            {
                                if (delta < 0x100)
                                {
                                block_66:
                                    picnum = D_800DF090[unk84];
                                    if ((unk9E == 4) || (unk9E == 5) || (unk9E == 22) || (unk9E == 23) || (unk9E == 16))
                                    {
                                        s32 a;
                                        j = 48;
                                        for (a = 0; a < 3; a++)
                                        {
                                            spritenum = func_8008E3E0(gpSprite[i].x, gpSprite[i].y, (gpSprite[i].z - z) + 0x1200, gpSprite[i].sectnum, 55, 2130);
                                            if (spritenum != -1)
                                            {
                                                do
                                                {
                                                    gpSprite[spritenum].ang = (getAngle(gPlayer[0].xpos - gpSprite[i].x, gPlayer[0].ypos - gpSprite[i].y) - 0x400) & 0x7FF;
                                                } while (0); /*FAKEMATCH*/
                                                gpSprite[spritenum].ang += (krand() & 0xFF) - 0x80;
                                            }
                                        }
                                    }
                                    else if ((unk9E == 20) || (unk9E == 0) || (unk9E == 17))
                                        func_80057540(D_80118248, D_801C0D70[D_80137DE0->unk84].unk0, 1, 0);
                                }
                                else
                                {
                                    if ((delta > 0x100) && (delta < 0x200))
                                        picnum = D_800DF0D0[unk84];
                                    else if (delta >= 0x200)
                                        picnum = D_800DF110[unk84];
                                }
                                spritenum = func_8008E3E0(gpSprite[i].x, gpSprite[i].y, (gpSprite[i].z - z) + 0x1200, gpSprite[i].sectnum, 55, 2130);
                                if (spritenum != -1)
                                {
                                    gpSprite[spritenum].ang = (getAngle(gPlayer[0].xpos - gpSprite[i].x, gPlayer[0].ypos - gpSprite[i].y) - 0x400) & 0x7FF;
                                    gpSprite[spritenum].ang += (krand() & 0xFF) - 0x80;
                                }
                            }
                            else
                            {
                                if (((krand() & 3) != 3) && (D_80137DE0->unk98 != 0xFF))
                                {
                                    spritenum = func_8008E3E0(gpSprite[i].x, gpSprite[i].y, gpSprite[i].z - z, gpSprite[i].sectnum, 55, 2130);
                                    if (spritenum != -1)
                                    {
                                        gpSprite[spritenum].ang = (getAngle(gPlayer[0].xpos - gpSprite[i].x, gPlayer[0].ypos - gpSprite[i].y) - 0x400) & 0x7FF;
                                        gpSprite[spritenum].ang += (krand() & 0xFF) - 0x80;
                                    }
                                    if ((D_80137DE0->unk98 >= 20) && (D_80137DE0->unk98 < 46))
                                    {
                                        picnum = D_800DF150[unk84];
                                        j = 46;
                                        if (delta >= 0x200)
                                            j = 59;
                                    }
                                    if ((D_80137DE0->unk98 >= 41))
                                    {
                                        if (delta >= 0x200)
                                            j = 100;
                                    }
                                }
                            }
                            if (sp24 < 2500)
                                j = 6;

                            if (picnum != -1)
                                D_80118248->picnum = picnum;
                        }
                        else
                        {
                            goto block_66;
                        }
                    }
                }
            }
            gpSprite[i].unk18 = 1;
            D_80137DE0->unk0 |= 2;

        label1:
            D_80137DE0->unk86 = j | 0x8000;
        }


        if (gpSprite[i].unk18 == 1)
        {
            audio_800077F4(((krand() % 3) + 1054), i);
            if (D_80137DE0->unk0 & 4)
            {
                D_80137DE0->unk0 &= ~2;
                gpSprite[i].unk18 = 2;
            }

            if (D_80137DE0->unk84 == 8)
                D_80137DE0->unk86 = -0x7FA1;
        }

        if (gpSprite[i].unk18 == 2)
        {
            if ((D_80137DE0->unk4 & 0x20) && ((D_8012F6E8 == 1) || (D_80118248->picnum == CHIMERA)))
            {
                if (func_8004EFB4(i) != 0)
                {
                    if (D_80118248->z - 0x2400 > func_80036490(D_80118248->sectnum))
                        gpSprite[i].z -= 100;
                }
            }
            else
            {
                if ((gpSprite[i].unk1A < 50) && (D_80137DE0->unk44 != 0) && ((D_8012FD88 & 3) == 3))
                {
                    if (D_80137DE0->unkA0 < 3)
                    {
                        D_80137DE0->unkA0++;
                        D_80118248->z -= 0x1800;

                        if ((D_80137DE0->unk84 == 0) || (D_80137DE0->unk84 == 11))
                            func_80057540(D_80118248, 1501, 1, 0);
                        else if (((D_80137DE0->unk84 == 8) || (D_80137DE0->unk84 == 18)) == 0)
                            func_80057540(D_80118248, 1500, 1, 0);
                        else
                            func_80057540(D_80118248, 1501, 1, 0);

                        D_80118248->z += 0x1800;
                    }
                }
            }
            unk86 = D_80137DE0->unk86;
            if (((unk86 == 6) && (gpSprite[temp = i].unk1A == 43)) || /*FAKEMATCH*/
                ((unk86 == 6) && (gpSprite[i].unk1A == 99)) ||
                ((unk86 == 7) && (gpSprite[i].unk1A == 18)) ||
                ((unk86 == 8) && (gpSprite[i].unk1A == 22)) ||
                ((unk86 == 101) && (gpSprite[i].unk1A == 12)) ||
                ((unk86 == 8) && (gpSprite[i].unk1A == 22)) ||
                ((unk86 == 48) && (gpSprite[i].unk1A == 80)) ||
                ((unk86 == 48) && (gpSprite[i].unk1A == 123)) ||
                ((unk86 == 46) && (gpSprite[i].unk1A == 19)) ||
                ((unk86 == 59) && (gpSprite[i].unk1A == 20)) ||
                ((unk86 == 100) && (gpSprite[i].unk1A == 22)) ||
                ((unk86 == 55) && (gpSprite[i].unk1A  == 72)) ||
                ((unk86 == 55) && (gpSprite[i].unk1A  == 110)))
            {
                audio_800077F4(((krand() % 3) + 1054), i);
            }

            if (gpSprite[i].unk1A >= 90)
            {
                if (D_8013B2D0[i].unk6 >= 0xFF)
                {
                    D_80137DE0 = &D_8019B940[D_80106D50[i]];
                    if (D_800DEF10 != 0)
                    {
                        if ((D_80137DE0->unk84 >= 38) && (D_80137DE0->unk84 < 44))
                            func_8005E2B0(i);
                        else
                            func_8004BD24(i);
                    }
                    else
                        func_8004BD24(i);
                    return;
                }
                D_8013B2D0[i].unk6 += 2;
            }
            gpSprite[i].unk1A++;
        }
        i = nexti;
    }
}

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
s32 func_80047820(s32 spritenum1, s32 spritenum2, s32 arg2)
{
    s32 cond2;
    s32 ret;
    SpriteType *spr;
    volatile u8 *ptr;
    s32 lotag;
    u8 cond;
    s32 nexti;
    s32 i, j, k, l, m, n;

    ret = 0;
    spr = &gpSprite[spritenum1];

    if (gpSprite[spritenum2].picnum == 1688)
    {
        if ((gpSprite[spritenum2].unk2B != 0) && (gpSprite[spritenum2].unk2B < 4) && (gpSprite[spritenum2].unk25 == 0))
            gpSprite[spritenum2].unk2B = 4;
    }

    if ((gpSprite[spritenum2].picnum == 1398) || (gpSprite[spritenum2].picnum == 1399))
    {
        if ((gpSprite[spritenum1].lotag < 12 || gpSprite[spritenum1].lotag >= 14))
        {
            if (gpSprite[spritenum1].lotag != 10)
            {
                changeSpriteStat(spritenum2, 65);
                gpSprite[spritenum2].unk2B = 2;
                gpSprite[spritenum2].unk22 = -1;
            }
        }
    }

    switch (gpSprite[spritenum2].statnum)
    {
    case 4:
        if (((gpSprite[spritenum2].picnum == 1841) || (gpSprite[spritenum2].picnum == 1844)) &&
            (gpSprite[spritenum2].unk1A != gpSprite[spritenum2].statnum))
        {
            gpSprite[spritenum2].unk18 = 15;
            gpSprite[spritenum2].unk1A = 4;
        }

        if (gpSprite[spritenum2].picnum == 1817)
            gpSprite[spritenum2].unk22 = 1;

        return 0;
    case 302:
        switch (gpSprite[spritenum2].picnum)
        {
        case 1346:
        case 1574:
        case 2437:
        case 2441:
            if (gpSprite[spritenum2].unk2B == 0)
            {
                gpSprite[spritenum2].unk2B = 1;
                if (gpSprite[spritenum2].hitag != 0)
                    func_8006B590(gpSprite[spritenum2].hitag);
            }
            break;
        case 1458:
            if (gpSprite[spritenum2].unk2B != 0)
                audio_800077F4(61, spritenum2);
            else
                gpSprite[spritenum2].unk2B = 1;
            break;
        case 1672:
            gpSprite[spritenum2].unk22 = 0x200;
            break;
        case 2533:
            gpSprite[spritenum2].unk22 = 200;
            goto label1;
        case 2395:
            if (gpSprite[spritenum1].lotag == 37)
            {
                if (gpSprite[spritenum2].unk2B == 0)
                    gpSprite[spritenum2].unk2B = 1;
            }
            break;
        case 1625:
            if (gpSprite[spritenum2].unk2B == 0)
                gpSprite[spritenum2].unk2B = 1;
            break;
        case MARINE:
        case SERGEANT:
        case 2341:
        case 2597:
        label1:
            if (func_8004CC90(spritenum2, spr->lotag, spr->picnum) == -1)
                return 0;
            goto label2;
        }
        return 0;
    default:
        goto label1;
    }
label2:
    D_8019B940[D_80106D50[spritenum2]].unk98 = 0xFF;
    lotag = gpSprite[spritenum1].lotag;
    cond2 = 0;
    cond2 = ((lotag == 3) || (lotag == 4) || (lotag == 16) || (lotag == 5) ||
            (lotag == 2) || (lotag == 6) || (lotag == 7) || (lotag == 22) ||
            (lotag == 23) || (lotag == 43) || (lotag == 26));

    if ((D_80106D50[spritenum2] != -1) && (gpSprite[spritenum2].cstat & 0x1000))
    {
        s32 a, b;
        b = (gModelList[gpSprite[spritenum2].picnum-MODELLIST]->unk2E -
             gModelList[gpSprite[spritenum2].picnum-MODELLIST]->unk28) << 6;
        a = klabs((gpSprite[spritenum1].z - gpSprite[spritenum2].z));
        a *= 100;
        if (b != 0)
            a /= b;

        if (cond2 != 0)
            D_8019B940[D_80106D50[spritenum2]].unk98 = 100 - a;
        else
            D_8019B940[D_80106D50[spritenum2]].unk98 = 0xFF;

        if (gpSprite[spritenum2].picnum == 2341)
        {
            s32 a;
            a = gpSprite[spritenum2].unk25;
            if (gpSprite[spritenum2].unk25 != 1)
                return 0;

            func_800494DC(spritenum2, arg2, spritenum1, 1);
            if ((krand() & 0x3FF) < 0x100)
                func_8008E3E0(D_801AE918, D_8010A9B0, D_8016A150, gpSprite[spritenum2].sectnum, 44, a);

            if (D_8019B940[D_80106D50[spritenum2]].unk8 <= 0)
            {
                for (i = 0; i < 4; i++)
                {
                    k = func_8008E3E0(gpSprite[spritenum2].x + ((krand() & 0x3FF) - 0x200),
                                      gpSprite[spritenum2].y + ((krand() & 0x3FF)- 0x200),
                                      gpSprite[spritenum2].z,
                                      gpSprite[spritenum2].sectnum, 38, 500);
                    if (k != -1)
                        gpSprite[k].lotag = -1;

                    func_8008E3E0(gpSprite[spritenum2].x + ((krand() & 0x3FF) - 0x200),
                                  gpSprite[spritenum2].y + ((krand() & 0x3FF) - 0x200),
                                  gpSprite[spritenum2].z - (krand() & 0xFFF),
                                  gpSprite[spritenum2].sectnum, 41, 32);
                }

                D_80106D50[spritenum2] = -1;
                func_8006B590(gpSprite[spritenum2].hitag);
                gpSprite[spritenum2].picnum = 2342;

                switch (gpSprite[spritenum2].hitag)
                {
                case 601:
                    func_8006B590(1001);
                    break;

                case 604:
                    func_8006B590(1004);
                    break;
                }

                i = gHeadSpriteStat[1];
                while (i >= 0)
                {
                    nexti = gNextSpriteStat[i];
                    if (gpSprite[i].hitag == gpSprite[spritenum2].hitag)
                        func_80055EC0(i, 0);
                    i = nexti;
                }

                i = gHeadSpriteStat[2];
                while (i >= 0)
                {
                    nexti = gNextSpriteStat[i];
                    if (gpSprite[i].hitag == gpSprite[spritenum2].hitag)
                        func_80055EC0(i, 0);
                    i = nexti;
                }
            }
        }
        else
            ret = func_800494DC(spritenum2, arg2, spritenum1, 0);
    }
    else
    {
        if ((gpSprite[spritenum2].picnum == 2209) || (gpSprite[spritenum2].picnum == 2210))
        {
            if ((gpSprite[spritenum1].lotag == 19) || (spr->picnum == 1560))
            {
                m = 14;
                for (j = 0; j < 7; j++)
                {
                    if (D_800E17F0[m] != 0)
                    {
                        if (D_800DEEA0 == 0)
                            l = (D_800E17F0[m] >> 1);
                        else
                            l = D_800E17F0[m];
                        func_80057540(&gpSprite[spritenum2], j + 1777, l, 0);
                    }
                    m++;
                }
                func_8006B590(gpSprite[spritenum2].hitag);
                func_8008E3E0(gpSprite[spritenum2].x, gpSprite[spritenum2].y, gpSprite[spritenum2].z, gpSprite[spritenum2].sectnum, 39, 0);
                func_800574A4(spritenum2);
            }
            else if (cond2 != 0)
            {
                spr->unk22++;
                m = 14;
                if (spr->unk22 >= 13)
                {
                    for (j = 0; j < 7; j++)
                    {
                        if (D_800E17F0[m] != 0)
                        {
                            if (D_800DEEA0 == 0)
                                l = (D_800E17F0[m] >> 1);
                            else
                                l = D_800E17F0[m];
                            func_80057540(&gpSprite[spritenum2], j + 1777, l, 0);
                        }
                        m++;
                    }
                    func_8006B590(gpSprite[spritenum2].hitag);
                    func_8008E3E0(gpSprite[spritenum2].x, gpSprite[spritenum2].y, gpSprite[spritenum2].z, gpSprite[spritenum2].sectnum, 39, 0);
                    func_800574A4(spritenum2);
                }
            }
        }

        if (gpSprite[spritenum2].statnum >= 64 && gpSprite[spritenum2].statnum < 72)
        {
            cond = 0;
            switch (gpSprite[spritenum2].statnum)
            {
            case 64:
                if ((lotag == 19) || (spr->picnum == 1560))
                {
                    if (gpSprite[spritenum2].unk16 == 1)
                    {
                        MusHandleStop(D_8013B2D0[gpSprite[i].unk22].handle, 0);
                        deleteSprite(gpSprite[spritenum2].unk22);
                    }
                    gpSprite[spritenum2].unk18 = 0;
                    audio_80007A44(1014, spritenum2, 48000);
                    cond = 1;
                    func_8008E3E0(gpSprite[spritenum2].x, gpSprite[spritenum2].y, gpSprite[spritenum2].z, gpSprite[spritenum2].sectnum, 55, 1713);
                    func_8008E3E0(gpSprite[spritenum2].x, gpSprite[spritenum2].y, gpSprite[spritenum2].z, gpSprite[spritenum2].sectnum, 55, 1715);
                    func_8008E3E0(gpSprite[spritenum2].x, gpSprite[spritenum2].y, gpSprite[spritenum2].z, gpSprite[spritenum2].sectnum, 55, 1716);
                    func_80057540(spr, 5700, (krand() & 3) + 1, 0);
                    changeSpriteStat(spritenum2, 74);
                    break;
                }

                if (cond2 != 0)
                    func_8004EBE4(spritenum2);

                if (gpSprite[spritenum2].unk18 > 0)
                {
                    gpSprite[spritenum2].unk18 -= 10;
                    break;
                }

                if (gpSprite[spritenum2].unk16 == 0)
                {
                    k = func_80058934(gpSprite[spritenum2].x,
                                      gpSprite[spritenum2].y,
                                      gpSprite[spritenum2].z,
                                      gpSprite[spritenum2].sectnum, 110);
                    gpSprite[k].picnum = 5;
                    gpSprite[k].unk1A = 18000;
                    gpSprite[k].unk25 = 0xFF;
                    gpSprite[k].unk18 = 0;
                    gpSprite[k].unk1C = 0;
                    gpSprite[k].lotag = 0x20;
                    gpSprite[spritenum2].unk16 = 1;
                    gpSprite[spritenum2].unk22 = k;
                }
                break;
            case 65:
                if ((lotag == 19) || (spr->picnum == 1560))
                {
                    if (gpSprite[spritenum2].unk22 != -1)
                    {
                        m = gpSprite[spritenum2].unk22;
                        if (m == 999)
                        {
                            n = func_8008E3E0(gpSprite[spritenum2].x,
                                              gpSprite[spritenum2].y,
                                              gpSprite[spritenum2].z,
                                              gpSprite[spritenum2].sectnum, 44, 5);
                            if (n > 0)
                                gpSprite[n].unk25 = 4;
                            goto label3;
                        }
                        else if (m == 1000)
                        {
                            n = func_8008E3E0(gpSprite[spritenum2].x,
                                              gpSprite[spritenum2].y,
                                              gpSprite[spritenum2].z,
                                              gpSprite[spritenum2].sectnum, 44, 6);
                            if (n > 0)
                                gpSprite[n].unk25 = 37;
                            goto label3;
                        }
                        else
                        {
                            m *= 7;
                            if (gMapNum == MAP_ZERO_HOUR)
                                func_8004BFDC(spritenum2, 4, gpSprite[spritenum2].z, 9999);

                            func_80050480(gpSprite[spritenum2].unk22, spritenum2);
                            for (j = 0; j < 7; j++)
                            {
                                if (D_800E17F0[m] != 0)
                                {
                                    if (D_800DEEA0 == 0)
                                        l = (D_800E17F0[m] >> 1);
                                    else
                                        l = D_800E17F0[m];
                                    func_80057540(&gpSprite[spritenum2], j + 1777, l, 0);
                                }
                                m++;
                            }
                        }
                    }

                    if (gpSprite[spritenum2].unk2A != 0)
                    {
                        l = (D_800DEEA0 != 0) ? 7 : 3;
                        for (i = 0; i < l; i++)
                        {
                            k = func_8008E3E0(gpSprite[spritenum2].x,
                                              gpSprite[spritenum2].y,
                                              gpSprite[spritenum2].z,
                                              gpSprite[spritenum2].sectnum, 55, 1782);
                            if (k != -1)
                            {
                                gpSprite[k].xrepeat += krand() & 0x7F;
                                gpSprite[k].yrepeat += krand() & 0x7F;
                            }
                        }
                    }

                    if (gpSprite[spritenum2].unk2B == 1)
                    {
                        func_80057540(&gpSprite[spritenum2], 2130, 4, 0);
                        func_80057540(&gpSprite[spritenum2], 1500, 1, 0);
                        if ((gpSprite[spritenum2].picnum < 2182) || (gpSprite[spritenum2].picnum >= 2184))
                        {
                            if ((gpSprite[spritenum2].unk22 == -1) && (D_800DEEA0 != 0))
                                func_80057540(&gpSprite[spritenum2], 2130, 4, 0);
                            audio_800077F4(((krand() % 3) + 538), spritenum2);
                        }
                    }

                    if (gpSprite[spritenum2].unk2B == 2)
                    {
                        k = gpSprite[spritenum2].z;
                        gpSprite[spritenum2].z = k - 0x2000;
                        func_80057540(&gpSprite[spritenum2], 2414, 6, 0);

                        if (gpSprite[spritenum2].unk22 == -1)
                            func_80057540(&gpSprite[spritenum2], 2414, 6, 0);
                        gpSprite[spritenum2].z = k;

                        audio_800077F4(((krand() % 3) + 538), spritenum2);
                    }

                label3:
                    cond = 1;
                    func_800574A4(spritenum2);
                    break;
                }

                if (gpSprite[spritenum2].unk2A == 0)
                {
                    if ((cond2 != 0) && (gpSprite[spritenum2].unk22 < 3))
                        func_8004EBE4(spritenum2);

                    if (gpSprite[spritenum1].unk2A != 0xFF)
                    {
                        if (lotag == 0)
                        {
                            arg2 = arg2 * ((krand() & 3) + 1);
                            arg2 += arg2/2;
                        }
                        gpSprite[spritenum2].unk18 -= arg2;
                        if ((gpSprite[spritenum2].unk18) <= 0)
                        {
                            if (gpSprite[spritenum2].unk22 != -1)
                            {
                                m = gpSprite[spritenum2].unk22*7;
                                if (gpSprite[spritenum2].unk22 == 999)
                                {
                                    n = func_8008E3E0(gpSprite[spritenum2].x,
                                                      gpSprite[spritenum2].y,
                                                      gpSprite[spritenum2].z,
                                                      gpSprite[spritenum2].sectnum, 44, 5);
                                    if (n > 0)
                                        gpSprite[n].unk25 = 4;
                                    goto label3;
                                }
                                else if (gpSprite[spritenum2].unk22 == 1000)
                                {
                                    n = func_8008E3E0(gpSprite[spritenum2].x,
                                                      gpSprite[spritenum2].y,
                                                      gpSprite[spritenum2].z,
                                                      gpSprite[spritenum2].sectnum, 44, 6);
                                    if (n > 0)
                                        gpSprite[n].unk25 = 37;
                                    goto label3;
                                }
                                else
                                {
                                    if (gMapNum == MAP_ZERO_HOUR)
                                        func_8004BFDC(spritenum2, 4, gpSprite[spritenum2].z, 9999);

                                    func_80050480(gpSprite[spritenum2].unk22, spritenum2);
                                    for (j = 0; j < 7; j++)
                                    {
                                        if (D_800E17F0[m] != 0)
                                        {
                                            if (D_800DEEA0 == 0)
                                                l = (D_800E17F0[m] >> 1);
                                            else
                                                l = D_800E17F0[m];
                                            func_80057540(&gpSprite[spritenum2], j + 1777, l, 0);
                                        }
                                        m++;
                                    }
                                }
                            }

                            if (gpSprite[spritenum2].unk2B == 1)
                            {
                                func_80057540(&gpSprite[spritenum2], 2130, 4, 0);
                                func_80057540(&gpSprite[spritenum2], 1500, 1, 0);
                                if ((gpSprite[spritenum2].picnum < 2182) || (gpSprite[spritenum2].picnum >= 2184))
                                {
                                    if ((gpSprite[spritenum2].unk22 == -1) && (D_800DEEA0 != 0))
                                        func_80057540(&gpSprite[spritenum2], 2130, 4, 0);
                                    audio_800077F4(((krand() % 3) + 538), spritenum2);
                                }
                            }
                            if (gpSprite[spritenum2].unk2B == 2)
                            {
                                k = gpSprite[spritenum2].z;
                                gpSprite[spritenum2].z = k - 0x2000;
                                func_80057540(&gpSprite[spritenum2], 2414, 6, 0);

                                if (gpSprite[spritenum2].unk22 == -1)
                                    func_80057540(&gpSprite[spritenum2], 2414, 6, 0);
                                gpSprite[spritenum2].z = k;
                                audio_800077F4(((krand() % 3) + 538), spritenum2);
                            }
                            changeSpriteStat(spritenum2, 0);
                            func_8004B2B0(spritenum2, 1500, 100);
                            cond = 1;
                            func_800574A4(spritenum2);
                        }
                    }
                }
                break;
            case 66:
                changeSpriteStat(spritenum2, 1);
                switch (gpSprite[spritenum2].picnum)
                {
                case 1338:
                case 1926:
                    func_8004BFDC(spritenum2, 3, gpSprite[spritenum2].z, 1);
                    func_8004AB6C(spritenum2, 1000, 25, 50, 75, 100, 0);
                    cond = 1;
                    func_800574A4(spritenum2);
                    break;
                case 1352:
                    if (cond2 != 0)
                        func_8004EBE4(spritenum2);
                    else
                    {
                        D_80106D50[spritenum2] = func_8004BE90();
                        D_8019B940[D_80106D50[spritenum2]].unkC = D_0101A9A0_STATIC;
                        D_8019B940[D_80106D50[spritenum2]].unk30 = 0;
                        D_8019B940[D_80106D50[spritenum2]].unk80 = 0;
                    }
                    break;
                }
                break;
            case 67:
                changeSpriteStat(spritenum2, 0);
                audio_80007A44(1323, spritenum2, 30000);
                gpSprite[spritenum2].picnum = 5214;
                gpSprite[spritenum2].cstat &= 0xFEFE;
                k = krand() & 3;
                for (j = 0; j < (k); j++)
                    func_80057540(&gpSprite[spritenum2], 1781, 1, 0);
                break;
            case 68:
            case 69:
                break;
            case 70:
                if ((lotag == 19) || (spr->picnum == 1560))
                {
                    m = gpSprite[spritenum2].unk25*7;
                    func_80050480(gpSprite[spritenum2].unk25, spritenum2);
                    for (j = 0; j < 7; j++)
                    {
                        ptr = &D_800E17F0[m];
                        if (*ptr != 0)
                            func_80057540(&gpSprite[spritenum2], j + 1777, *ptr, 0);
                        m++;
                    }

                    if ((gpSprite[spritenum2].picnum == 2266) || (gpSprite[spritenum2].picnum == 1466))
                    {
                        func_80045400(gpSprite[spritenum2].x,
                                      gpSprite[spritenum2].y,
                                      gpSprite[spritenum2].z - 0xC00,
                                      gpSprite[spritenum2].sectnum, 300, gpSprite[spritenum2].ang, 50, 0);
                    }
                    else if (gpSprite[spritenum2].picnum == 1418)
                    {
                        func_80045400(gpSprite[spritenum2].x,
                                      gpSprite[spritenum2].y,
                                      gpSprite[spritenum2].z - 0x1300,
                                      gpSprite[spritenum2].sectnum, 500, (gpSprite[spritenum2].ang + 460) & 0x7FF, 50, 0);
                    }
                    else
                    {
                        func_8008E3E0(gpSprite[spritenum2].x,
                                      gpSprite[spritenum2].y,
                                      gpSprite[spritenum2].z - 0x1200,
                                      gpSprite[spritenum2].sectnum, 50, 0);
                    }
                }
                else
                {
                    if ((cond2 != 0) && (gpSprite[spritenum2].unk25 < 3))
                        func_8004EBE4(spritenum2);

                    if (gpSprite[spritenum1].unk2A == 0xFF)
                        break;

                    gpSprite[spritenum2].unk18--;
                    if (gpSprite[spritenum2].unk18 > 0)
                        break;

                    m = gpSprite[spritenum2].unk25*7;
                    func_80050480(gpSprite[spritenum2].unk25, spritenum2);
                    for (j = 0; j < 7; j++)
                    {
                        ptr = &D_800E17F0[m];
                        if (*ptr != 0)
                            func_80057540(&gpSprite[spritenum2], j + 1777, *ptr, 0);
                        m++;
                    }

                    if ((gpSprite[spritenum2].picnum == 2266) || (gpSprite[spritenum2].picnum == 1466))
                    {
                        func_80045400(gpSprite[spritenum2].x,
                                      gpSprite[spritenum2].y,
                                      gpSprite[spritenum2].z - 0xC00,
                                      gpSprite[spritenum2].sectnum, 300, gpSprite[spritenum2].ang, 50, 0);
                    }
                    else if (gpSprite[spritenum2].picnum == 1418)
                    {
                        func_80045400(gpSprite[spritenum2].x,
                                      gpSprite[spritenum2].y,
                                      gpSprite[spritenum2].z - 0x1300,
                                      gpSprite[spritenum2].sectnum, 500, (gpSprite[spritenum2].ang + 460) & 0x7FF, 50, 0);
                    }
                    else
                    {
                        func_8008E3E0(gpSprite[spritenum2].x,
                                      gpSprite[spritenum2].y,
                                      gpSprite[spritenum2].z - 0x1200,
                                      gpSprite[spritenum2].sectnum, 50, 0);
                    }
                }
                gpSprite[spritenum2].picnum = gpSprite[spritenum2].hitag;
                changeSpriteStat(spritenum2, 0);
                func_8004B2B0(spritenum2, 1500, 100);
                break;
            case 71:
                if ((lotag == 19) || (spr->picnum == 1560))
                {
                    gpSprite[spritenum2].unk18 = 0;
                    changeSpriteStat(spritenum2, 74);
                }
                else if (gpSprite[spritenum1].unk2A != 0xFF)
                {
                    gpSprite[spritenum2].unk18 -= arg2;
                    if ((gpSprite[spritenum2].unk18) <= 0)
                    {
                        gpSprite[spritenum2].unk18 = 0;
                        changeSpriteStat(spritenum2, 75);
                    }
                }
                break;
            default:
                break;
            }

            if (cond != 0)
            {
                if (gpSprite[spritenum2].hitag != 0)
                    func_8006B590(gpSprite[spritenum2].hitag);
            }
        }
    }
    return ret;
}

/*800494DC*/
s32 func_800494DC(s32 spritenum1, s32 arg1, s32 spritenum2, s32 arg3)
{
    SpriteType *spr;
    code0UnkStruct3 *ptr;
    s16 *ptr2;
    s32 cond, ret;
    s32 ang;
    s32 lotag1, lotag2;
    s32 i, j, k, z;
    u32 l;
    s16 m;
    u8 cond2;

    ret = 0;

    if ((D_8013B2D0[spritenum1].unk6 != 0) && (gpSprite[spritenum1].statnum != 10))
        return 0;

    ptr = &D_8019B940[D_80106D50[spritenum1]];
    lotag2 = 0;

    if ((ptr->unk4 & 2))
        return 0;

    if (gpSprite[spritenum1].statnum == 2)
    {
        changeSpriteStat(spritenum1, 1);
        ptr->unk0 |= 0x40000;
    }

    cond = 0;
    if ((gpSprite[spritenum1].statnum == 59) && (gpSprite[spritenum2].lotag != 15))
    {
        gpSprite[spritenum1].unk22 = 90;
        return 0;
    }

    if (gpSprite[gpSprite[spritenum2].hitag].statnum == 10)
    {
        cond2 = 1;
        if (gCheatActionNukemConfig != CONFIG_OFF)
            arg1 = 5000;
    }
    else
        cond2 = 0;

    if (gpSprite[spritenum1].statnum == 305)
    {
        spr = &gpSprite[spritenum2];
        D_8012F908 = 1;
        D_801A19F4 = spr->x;
        D_8012C798 = spr->y;
        D_801AC590 = spr->z;

        if (gpSprite[spritenum1].picnum == BOSSGIANTHOG)
        {
            ang = getAngleDelta(getAngle(D_801A19F4 - gpSprite[spritenum1].x, D_8012C798 - gpSprite[spritenum1].y),
                                gpSprite[spritenum1].ang);

            z = D_801AC590 - gpSprite[spritenum1].z;

            if (gpSprite[spritenum2].lotag == 10)
                D_80105540 = 1;

            else if (ang < -850 || ang > 850)
            {
                if (z >= -0x7CFF)
                {
                    cond = 1;
                    if (gpSprite[spritenum1].unk2B < 20)
                    {
                        i = gHeadSpriteStat[302];
                        while (i >= 0)
                        {
                            if (gpSprite[i].picnum == 2559)
                            {
                                gpSprite[i].picnum = 2560;
                                break;
                            }
                            i = gNextSpriteStat[i];
                        }
                    }
                }
            }
        }
    }

    if (arg3 == 0)
    {
        if ((ptr->unk0 & 0x2000) && (gpSprite[gpSprite[spritenum2].hitag].statnum != 10))
            return 0;
        else
            lotag2 = gpSprite[spritenum2].lotag;
    }

    if ((gpSprite[spritenum1].statnum == 10) && (arg3 == 0))
    {
        if (D_8012C470 == 1)
        {
            k = D_801AD474[D_80197DE8[lotag2]];
            arg1 = (arg1 * k) / 100;

            if (!cond2)
            {
                if (gpSprite[spritenum2].hitag >= 0)
                {
                    m = D_80106D50[gpSprite[spritenum2].hitag];
                    if (m >= 0)
                    {
                        k = D_80105550[D_8019B940[m].unk84];
                        arg1 = (arg1 * k) / 100;
                    }
                }
            }

            if (arg1 >= 5)
                arg1 = (arg1 * D_800DEF18) / 100;
        }

        func_8003671C(gpSprite[spritenum1].unk16, arg1, gpSprite[spritenum2].hitag, gpSprite[spritenum2].lotag);
        D_800FEA94 = ptr->unk8;
        D_801AC8D0 = ptr->unk7E;
        if (D_8012C470 >= 2)
        {
            lotag1 = gpSprite[spritenum2].lotag;
            if (((lotag1 == 3 || lotag1 == 4) || (lotag1 == 16) || (lotag1 == 5) ||
                (lotag1 == 2) || (lotag1 == 6 || lotag1 == 7) || (lotag1 == 22) ||
                (lotag1 == 2) || (lotag1 == 23) || (lotag1 == 17)) &&!(krand() & 3))
            {
                func_8008E3E0(gpSprite[spritenum2].x, gpSprite[spritenum2].y,
                              gpSprite[spritenum2].z, gpSprite[spritenum2].sectnum, 42, 20);
            }
        }
        return 0;
    }

    k = 100;
    if (D_80106D50[spritenum1] != -1)
    {
        if (D_8019B940[D_80106D50[spritenum1]].unk84 == -1)
            return 0;

        if (arg3 == 0)
        {
            ptr2 = D_80129808[D_8019B940[D_80106D50[spritenum1]].unk84];
            if (D_80129808[D_8019B940[D_80106D50[spritenum1]].unk84] == 0)
                return 0;

            ptr2 = &ptr2[D_80197DE8[lotag2]];
            D_801A68A0 = k = *ptr2;
        }
    }

    if (arg3 == 0)
    {
        ptr->unk9E = lotag2;
        arg1 = (arg1 * k) / 100;
    }

    if (ptr->unk7E > 0)
    {
        j = (arg1 * ((krand() % 30) + 0x14)) / 100;
        ptr->unk7E += j;
        arg1 -= j;
        if (ptr->unk7E < 0)
        {
            arg1 += ptr->unk7E;
            ptr->unk7E = 0;
        }
    }

    if ((ptr->unk98 != 0xFF))
    {
        if ((ptr->unk98 < 19))
        {
            if (gpSprite[spritenum1].statnum != 10)
            {
                if (func_8004D7D8(spritenum1) != 0)
                {
                    l = func_8005A240(spritenum1);
                    if ((l < 2) || (l == 2))
                        arg1 += arg1 / 2;
                }
            }
        }
    }

    if (arg1 >= 2)
        arg1 = (arg1 * D_800DEF14) / 100;

    if ((gpSprite[spritenum1].picnum == BOSSGIANTHOG))
    {
        if (cond != 0)
            arg1 *= 2;
    }

    if (arg1 > 0)
        func_800360A0(spritenum1, 0);

    ptr->unk8 -= arg1;
    D_801A68C8 = ptr->unk7E;
    ptr->unk8E += arg1;

    if (ptr->unk8 < 0)
        ptr->unk8 = -1;

    D_8019995C = arg1;
    D_80168CF8 = ptr->unk8;

    if (D_80168CF8 > 0)
    {
        if (arg1 > 0)
        {
            l = func_8005A240(spritenum1);

            if (((l < 2) || (l == 2)) && (gpSprite[spritenum2].lotag != 9))
                func_8006D3B8(spritenum1, 100, 0, 0, 0);

            if ((ptr->unk10 != NULL) && (ptr->unk18 == NULL))
            {
                ptr->unk18 = ptr->unkC;
                ptr->unkC = ptr->unk10;
                ptr->unk34 = ptr->unk30;
                ptr->unk82 = ptr->unk80;
                ptr->unk8A = ptr->unk86;
                ptr->unk93 = ptr->unk92;
                ptr->unk0 |= 8;
                ptr->unk30 = 0;
                ptr->unk80 = 0;
            }
        }
    }
    else
    {
        if (gpSprite[spritenum1].statnum == 305)
        {
            switch (gpSprite[spritenum1].picnum)
            {
            case BOSSCYBORGSCORPION:
                func_8009A43C(spritenum1);
                break;
            case BOSSZERO:
                func_8009B8A4(spritenum1);
                break;
            case BOSSGIANTHOG:
                func_8009E638(spritenum1);
                break;
            }
        }
        else
        {
            if ((gpSprite[spritenum1].picnum == MARINE) || (gpSprite[spritenum1].picnum == SERGEANT))
            {
                if (cond2)
                    audio_80008574(0, 1670);
            }
            else if ((ptr->unk14 != NULL) && !(ptr->unk0 & 0x4000))
            {
                ret = 1;
                if ((cond2) && (func_8004D7D8(spritenum1) != 0))
                {
                    switch (func_8005A240(spritenum1))
                    {
                    case 1:
                        if (func_801C0FDC(100) < 25)
                            audio_800080E0(0, 14);
                        else
                            audio_800080E0(0, 6);
                        break;
                    case 0:
                        if (func_801C0FDC(100) < 50)
                            audio_800080E0(0, 13);
                        else
                            audio_800080E0(0, 6);
                        break;
                    case 2:
                        if (func_801C0FDC(100) < 5)
                            audio_800080E0(0, 12);
                        else
                            audio_800080E0(0, 6);
                        break;
                    default:
                        if (gpSprite[spritenum1].picnum == PARAPSYCHE)
                        {
                            if (func_801C0FDC(100) < 15)
                                audio_800080E0(0, 15);
                            else
                                audio_800080E0(0, 6);
                        }
                        else
                            audio_800080E0(0, 6);
                        break;
                    }
                }
                if (!(gpSprite[spritenum1].cstat & 8) && !(ptr->unk0 & 0x01000000))
                    D_801A1958.enemies_killed++;

                if (gpSprite[spritenum1].statnum == 72)
                    changeSpriteStat(spritenum1, 1);

                ptr->unk30 = 0;
                ptr->unk80 = 0;
                ptr->unkC = ptr->unk14;
                ptr->unk0 |= 0x4000;
            }
        }
    }

    lotag1 = lotag2;
    if (arg3 == 0)
    {
        if ((lotag1 == 3)  || (lotag1 == 4)  || (lotag1 == 16) ||
            (lotag1 == 5)  || (lotag1 == 2)  || (lotag1 == 6)  ||
            (lotag1 == 7)  || (lotag1 == 22) || (lotag1 == 2)  ||
            (lotag1 == 23) || (lotag1 == 17) || (lotag1 == 26))
        {
            if (((lotag1 == 4) || (lotag1 == 16) || (lotag1 == 5) || (lotag1 == 6)) && (krand() & 1))
                return ret;

            ang = gpSprite[spritenum1].x - gPlayer[0].xpos;
            if (((klabs_(ang) + klabs_(gpSprite[spritenum1].y - gPlayer[0].ypos)) > 1200) &&
                (func_8004D7D8(spritenum1) != 0) && (arg1 > 0) && !(ptr->unk0 & 0x20000))
            {
                if (ptr->unkA0 < 3)
                {
                    ptr->unkA0++;
                    if ((lotag1 != 9) || (lotag1 != 15))
                    {
                        if ((ptr->unk84 == 0) || (ptr->unk84 == 11) || (ptr->unk84 == 8) || (ptr->unk84 == 18))
                        {
                            func_80057540(&gpSprite[spritenum2], 1501, 1, 0);
                            func_8008E3E0(gpSprite[spritenum2].x, gpSprite[spritenum2].y,
                                          gpSprite[spritenum2].z, gpSprite[spritenum2].sectnum, 42, 9);
                        }
                        else
                        {
                            if (gMapNum != MAP_BRAINSTORM)
                            {
                                func_80057540(&gpSprite[spritenum2], 1500, 1, 0);
                                func_8008E3E0(gpSprite[spritenum2].x, gpSprite[spritenum2].y,
                                              gpSprite[spritenum2].z, gpSprite[spritenum2].sectnum, 42, 20);
                            }
                            else
                                func_80057540(&gpSprite[spritenum2], 1500, 1, 0);
                        }
                    }
                }
            }
        }
        else
        {
            if ((((u32)ptr->unk4 >> 1) & 1) && (lotag1 != 20))
            {
                ptr->unk9E = lotag1;
                ret = 1;
                func_80055EC0(spritenum1, 0);
            }
        }
    }

    return ret;
}

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
        spr2->lotag = 80;
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
                gpSprite[spritenum].lotag = 12;
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
                if (gpSprite[spritenum].hitag == 837)
                    func_8004A4D4(&gpSprite[spritenum], 2364, 4);
            }
            if (gMapNum == MAP_ALIEN_MOTHER)
            {
                if (gpSprite[spritenum].hitag == 806)
                    func_8004A4D4(&gpSprite[spritenum], 2364, 1);

                if (gpSprite[spritenum].hitag == 818)
                    func_8004A4D4(&gpSprite[spritenum], 2364, 3);
            }
            func_8004BD24(spritenum);
        }
    }
}

typedef struct {
    u16 unk0[16];
} _41940UnkStruct4;
static const _41940UnkStruct4 D_800E5618 = {1,2,58,64,65,66,67,70,71,72,10,120,302,4,305,301};

/*8004AB6C*/
void func_8004AB6C(s32 spritenum, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6)
{
    _41940UnkStruct4 sp20;
    s16 sectnum;
    s16 spritenum_;
    s16 i, j, k, l;
    s16 hitag, lotag;
    s16 nexti;
    SpriteType *spr2;
    SpriteType *spr1;
    WallType *wall;
    s32 m, n;
    s32 temp;

    sp20 = D_800E5618;
    sectnum = gpSprite[spritenum].sectnum;
    hitag = gpSprite[spritenum].hitag;
    lotag = gpSprite[spritenum].lotag;
    spritenum_ = func_80058934(gpSprite[spritenum].x, gpSprite[spritenum].y, gpSprite[spritenum].z, sectnum, 72);

    if (spritenum_ != -1)
    {
        spr1 = &gpSprite[spritenum_];
        spr1->picnum = 1560;
        spr1->cstat = 0x8000;
        spr1->hitag = hitag;
        spr1->lotag = lotag;

        for (j = 0; j < ARRAY_COUNT(sp20.unk0); j++)
        {
            i = gHeadSpriteStat[sp20.unk0[j]];
            while (i >= 0)
            {
                spr2 = &gpSprite[i];
                nexti = gNextSpriteStat[i];
                m = dist(spr1, spr2);
                n = arg5;

                if (sp20.unk0[j] == 305)
                    m = m / 2;

                /*FAKEMATCH*/
                if (((temp = arg6 != 0) && (m < arg1)) ||
                    ((m < arg1) && (canSee(spr2->x, spr2->y, spr2->z - 0x800, spr2->sectnum, spr1->x, spr1->y, spr1->z - 0xC00, spr1->sectnum) != 0)))
                {
                    if (m < (arg1 / 3))
                    {
                        arg5 += arg5 == arg4;
                        n = arg4 + (krand() % (arg5 - arg4));
                    }
                    else if (m < ((arg1 * 2) / 3))
                    {
                        arg4 += arg4 == arg3;
                        n = arg3 + (krand() % (arg4 - arg3));
                    }
                    else if (m < arg1)
                    {
                        arg3 += arg3 == arg2;
                        n = arg2 + (krand() % (arg3 - arg2));
                    }

                    if ((gpSprite[i].picnum == SHIP1) || (gpSprite[i].picnum == SENTRYGUNS2))
                    {
                        if (hitag != i)
                            func_80047820(spritenum_, i, n);
                    }
                    else
                    {
                        if ((gpSprite[i].picnum == 1398) || (gpSprite[i].picnum == 1399))
                        {
                            if (gpSprite[i].statnum >= 301)
                                gpSprite[i].unk2B = 1;
                            else
                                goto block_29;
                        }
                        else if ((gpSprite[i].picnum == MARINE) || (gpSprite[i].picnum == SERGEANT))
                        {
                            if (arg1 == 0x800)
                                gpSprite[i].unk2B = 1;
                            else
                                goto block_29;
                        }
                        else if ((lotag != 21) || (gpSprite[spritenum].hitag != i))
                        {
                        block_29:
                            func_80047820(spritenum_, i, n);
                        }
                    }
                }
                i = nexti;
            }
        }

        func_800515A0(spr1->sectnum);
        D_80199638 = 0;
        for (i = 0; i < D_801A1978; i++)
        {
            k = gpSector[D_80138820[i]].wallptr + gpSector[D_80138820[i]].wallnum;
            for (l = gpSector[D_80138820[i]].wallptr, wall = &gpWall[l]; l < k; l++, wall++)
            {
                if ((klabs_(wall->x - spr1->x) + klabs_(wall->y - spr1->y)) < arg1)
                {
                    s32 a, b;
                    a = (((wall->x + gpWall[wall->point2].x) >> 1) + spr1->x) >> 1;
                    b = (((wall->y + gpWall[wall->point2].y) >> 1) + spr1->y) >> 1;
                    updateSector(a, b, &sectnum);
                    if (sectnum >= 0)
                    {
                        if (canSee(a, b, spr1->z, sectnum, spr1->x, spr1->y, spr1->z, spr1->sectnum) != 0)
                            func_8004CB3C(l);
                    }
                }

            }
        }
        deleteSprite(spritenum_);
    }
}

/*8004B2B0*/
static void func_8004B2B0(s32 spritenum, s32 arg1, s32 arg2)
{
    SpriteType *spr;
    s16 sectnum, spritenum_;
    s16 i, nexti;
    s16 hitag, lotag;

    hitag = gpSprite[spritenum].hitag;
    lotag = gpSprite[spritenum].lotag;
    sectnum = gpSprite[spritenum].sectnum;
    spritenum_ = func_80058934(gpSprite[spritenum].x, gpSprite[spritenum].y, gpSprite[spritenum].z, sectnum, 72);

    if (spritenum_ != -1)
    {
        spr = &gpSprite[spritenum_];
        spr->picnum = 1560;
        spr->cstat = 0x8000;
        spr->hitag = hitag;
        spr->lotag = lotag;

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
static s32 func_8004B440(s32 spritenum)
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
        j = D_80118248->lotag;
        break;
    case 0x4000002C:
        j = D_80118248->hitag;
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
        k = D_80118248->lotag;
        break;
    case 0x4000002C:
        k = D_80118248->hitag;
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
s32 func_8004BC64(s32 x, s32 y, s32 z, s32 sectnum, s32 picnum, s32 arg5, s32 arg6)
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
        spr->picnum = picnum;
        spr->unk25 = 0;

        if (picnum == 2487)
            spr->unk25 = arg5;

        spr->ang = 0;
        func_800539A8(picnum, spritenum);
        return spritenum;
    }
    /*TODO: return?*/
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
static s32 func_8004BE20(s32 spritenum)
{
    changeSpriteStat(spritenum, 0);
    return -1;
}

/*8004BE48*/
static s32 func_8004BE48(s32 spritenum)
{
    _41940UnkFuncPointer1 func;

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

#ifdef NON_MATCHING
/*8004BFDC*/
void func_8004BFDC(s32 spritenum, s32 arg1, s32 z, s32 arg3)
{
    s32 sp2C;
    u8 sp37;
    u16 sp3E;

    s32 i, j, k, l;
    s32 x1, y1, z1;

    u8 cond;
    s16 a;

    i = arg1;
    sp3E = 0x20;
    D_80118248 = &gpSprite[spritenum];

    switch (arg1)
    {
    case 0x40000000:
        arg1 = D_80137DE0->unk44;
        break;
    case 0x40000001:
        arg1 = D_80137DE0->unk48;
        break;
    case 0x40000002:
        arg1 = D_80137DE0->unk4C;
        break;
    case 0x40000003:
        arg1 = D_80137DE0->unk50;
        break;
    case 0x40000004:
        arg1 = D_80137DE0->unk54;
        break;
    case 0x40000005:
        arg1 = D_80137DE0->unk58;
        break;
    case 0x40000006:
        arg1 = D_80137DE0->unk5C;
        break;
    case 0x40000007:
        arg1 = D_80137DE0->unk60;
        break;
    case 0x4000000C:
        arg1 = krand();
        break;
    case 0x4000000D:
        arg1 = D_80137DE0->unk2E;
        break;
    case 0x4000000E:
        arg1 = D_8013B2D0[spritenum].unk2;
        break;
    case 0x4000000A:
        arg1 = D_80137DE0->unk0;
        break;
    case 0x40000034:
        arg1 = D_80137DE0->unk4;
        break;
    case 0x40000011:
        arg1 = D_8013B2D0[spritenum].unk0;
        break;
    case 0x40000020:
        arg1 = D_8013B2D0[spritenum].unk4;
        break;
    case 0x40000010:
        arg1 = 0x1C80;
        arg1 = ((gPlayer[D_801A2628].zpos - (D_80118248->z - arg1)) - (D_801B0D30 / 2)) >> 8;
        break;
    case 0x40000009:
        arg1 = D_80118248->ang;
        break;
    case 0x40000012:
        arg1 = D_80118248->unk25;
        break;
    case 0x40000016:
        arg1 = D_80137DE0->unkA1;
        break;
    case 0x40000015:
        arg1 = D_8013B2D0[spritenum].unk6;
        break;
    case 0x40000017:
        arg1 = D_8012FD88;
        break;
    case 0x4000001B:
        arg1 = D_80118248->cstat;
        break;
    case 0x40000018:
        arg1 = D_80137DE0->unk8;
        break;
    case 0x4000001E:
        arg1 = D_80137DE0->unk9A;
        break;
    case 0x40000013:
    case 0x40000019:
        arg1 = D_80118248->unk1C;
        break;
    case 0x40000022:
        arg1 = D_80137DE0->unk99;
        break;
    case 0x40000023:
    case 0x40000024:
        arg1 = D_80137DE0->unk8C;
        break;
    case 0x40000025:
        arg1 = D_80137DE0->unk98;
        break;
    case 0x40000027:
        arg1 = D_80137DE0->unk7C;
        break;
    case 0x40000028:
        arg1 = gAiDebugGvar1;
        break;
    case 0x40000029:
        arg1 = gAiDebugGvar2;
        break;
    case 0x4000002A:
        arg1 = gAiDebugGvar3;
        break;
    case 0x4000002B:
        arg1 = D_80118248->lotag;
        break;
    case 0x4000002C:
        arg1 = D_80118248->hitag;
        break;
    case 0x40000031:
        arg1 = D_80118248->unk22;
        break;
    case 0x40000026:
        arg1 = D_80137DE0->unk68;
        break;
    case 0x40000030:
        arg1 = D_80137DE0->unk9F;
        break;
    case 0x40000032:
        arg1 = D_80137DE0->unk94;
        break;
    case 0x40000035:
        arg1 = D_80137DE0->unk92;
        break;
    }

    i = arg1;
    x1 = D_80118248->x;
    y1 = D_80118248->y;
    z1 = D_80118248->z;
    sp2C = func_8004EFB4(spritenum);

    if (klabs(z1 - gpSector[gpSprite[spritenum].sectnum].floorz) < 0x400)
        sp37 = 1;
    else
        sp37 = 0;

    l = 1800;
    k = 75;
    if (sp2C == 0)
    {
        if (((z - D_80118248->z) >> 8) < 100)
        {
            j = func_8008E3E0(x1, y1, z - 0x800, gpSprite[spritenum].sectnum, 18, 0);
            if (j != -1)
            {
                D_8013B2D0[j].unk2 = 0;
                D_8013B2D0[j].unk0 = 0;
                gpSprite[j].ang = 0;
            }
        }
        else
        {
            j = func_8008E3E0(x1, y1, z1 - 0x1000, gpSprite[spritenum].sectnum, 22, 0);
            if (j != -1)
            {
                D_8013B2D0[j].unk2 = 0;
                D_8013B2D0[j].unk0 = 0;
                gpSprite[j].ang = 0;
            }
        }

        func_8008E3E0(x1, y1, z1, gpSprite[spritenum].sectnum, 17, 0);
        k = gpSprite[spritenum].ang;
        k -= 0x400;
        k = (k) & 0x7FF;
        j = func_8008E3E0(x1, y1, z1, gpSprite[spritenum].sectnum, 19, 1);
        if (j != -1)
        {
            gpSprite[j].x += (gpSinTable[(k + 0x200) & 0x7FF] * 5) >> 13;
            gpSprite[j].y += (gpSinTable[k] * 5) >> 13;
        }
    }
    else
        func_8008E3E0(x1, y1, z1, gpSprite[spritenum].sectnum, 39, 0);

    j = (u16)D_8019B940[D_80106D50[spritenum]].unk2E;
    if ((j & 0xC000) && ((j - 0xC000) <= 0))
        func_8004CB3C(j);

    cond = 0;
    if (sp2C == 0)
    {
        if (D_8012C470 == 1)
            cond = D_800DEEA0 != 0;
    }

    if (i >= 0 && i < 13)
    {
        switch (i)
        {
        case 0:
        case 12:
            k = 75;
            l = 1780;
            break;
        case 1:
            k = 150;
            l = 2000;
            break;
        case 2:
            k = 75;
            sp3E = 8;
            l = 1000;
            break;
        case 3:
            k = 200;
            l = 2500;
            if (cond)
            {
                if (sp37 != 0)
                    func_8008E3E0(x1, y1, z1, gpSprite[spritenum].sectnum, 12, 0);
                else
                    func_8008E3E0(x1, y1, z1, gpSprite[spritenum].sectnum, 65, 0);
            }
            break;
        case 4:
            l = 3000;
            k = 200;
            if (cond)
            {
                func_8008E3E0(x1, y1, z1, gpSprite[spritenum].sectnum, 26, 0);
                if (sp37 == 0)
                    func_8008E3E0(x1, y1, z1, gpSprite[spritenum].sectnum, 26, 1);

                func_80057540(&gpSprite[spritenum], 5700, (krand() & 3) + 1, 0);
            }
            break;
        case 5:
            k = 200;
            l = 2500;
            if (cond)
            {
                if (sp37 != 0)
                    func_8008E3E0(x1, y1, z1, gpSprite[spritenum].sectnum, 12, 0);
                else
                    func_8008E3E0(x1, y1, z1, gpSprite[spritenum].sectnum, 65, 0);
            }
            break;
        case 6:
            l = 3000;
            k = 200;
            if (cond)
            {
                if (sp37 != 0)
                    func_8008E3E0(x1, y1, z1, gpSprite[spritenum].sectnum, 12, 0);
                else
                    func_8008E3E0(x1, y1, z1, gpSprite[spritenum].sectnum, 65, 0);
            }
            break;
        case 7:
            l = 4880;
            k = 200;
            if (cond)
            {
                j = func_8008E3E0(x1, y1, z1, gpSprite[spritenum].sectnum, 65, 0);
                if (j != -1)
                    gpSprite[j].cstat &= 0xFBFF;
            }
            break;
        case 8:
            l = 1780;
            k = 25;
            break;
        case 9:
            l = 3000;
            k = 200;
            break;
        case 10:
            k = 40;
            l = 2000;
            break;
        case 11:
            k = 50;
            l = 1000;
            break;
        }
    }
    func_8001F7B4(12, 8);
    if (arg3 != 9999)
        func_8004AB6C(spritenum, l, k >> 2, k >> 1, k - (k >> 2), k, 0);

    if (arg3 != 0)
        audio_80007A44((func_801C0FDC(6) + 559), spritenum, 40000);

    a = sp3E;
    if (cond && (a != 0))
    {
        func_8008E3E0(x1, y1, z1, gpSprite[spritenum].sectnum, 41, a);
        func_8001DCD0(x1/2, y1/2, z1/32, 6);
    }
}
#else
/*8004BFDC*/
INCLUDE_ASM("src/code0/41940", func_8004BFDC);
#endif

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
    if ((gpSprite[spritenum].statnum == 58) &&
        ((arg1 == 19) || (arg1 == 13) || (arg1 == 12) || (arg1 == 10) || (arg1 == 32) ||
            (arg1 == 8) || (arg1 == 18) || (arg1 == 14) || (arg1 == 21) || (arg2 == 1560)))
    {
        if (gpSprite[spritenum].hitag != 0)
        {
            if (gpSprite[spritenum].unk25 == 1)
            {
                D_800DEE98 = gpSprite[spritenum].unk25;
                func_80050E40();
            }
            func_8006B590(gpSprite[spritenum].hitag);
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
s16 func_8004CE58(SpriteType *spr, s16 arg1, s16 arg2)
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
            j = 2 - gConfig.autoaim[i];
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
                    temp = b * x; /*FAKEMATCH?*/

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
static void func_8004D65C(s32 spritenum)
{
    s16 i, nexti;
    s32 hitag;

    spritenum &= 0xFFFF;
    if (spritenum & 0xC000)
    {
        spritenum -= 0xC000;
        if (spritenum >= 0)
        {
            if ((gpSprite[spritenum].statnum == 4) && (gpSprite[spritenum].lotag == 102))
            {
                i = gHeadSpriteStat[4];
                hitag = gpSprite[spritenum].hitag;
                while (i > 0)
                {
                    nexti = gNextSpriteStat[i];
                    if (gpSprite[i].hitag == hitag)
                    {
                        if ((gpSprite[i].lotag == 101) || (gpSprite[i].lotag == 102))
                        {
                            if (gpSprite[i].lotag == 101)
                            {
                                D_80106D50[i] = -1;
                                D_8019B89C = 0;
                            }
                            deleteSprite(i);
                        }
                    }
                    i = nexti;
                }
                D_8019B940[D_80106D50[hitag]].unk5C = 1;
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

    if ((D_8012F6E8 != 2 && D_80118248->picnum == CYBORGENFORCER) || (D_8012F6E8 == 2 && D_80137DE0->unk48 == 0))
    {
        if (D_80118248->picnum == CYBORGENFORCER)
            i = 0x700;
        else
            i = 0x800;

        if (D_80118248->picnum != ZOMBIE6)
        {
            if (D_80118248->picnum == ZOMBIE2)
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
static s32 func_8004DE60(s32 spritenum, s32 arg1)
{
    ModelInfo *ptr;
    s32 x, y, z, z2;
    s32 sectnum_;
    s32 cond;
    s32 unk18, unk1A;
    s32 spritenum_;
    s32 i, j;
    s32 cliptype;
    s32 walldist;
    s16 sectnum;
    s16 ret, ret2;
    u16 cstat;

    cond = 0;
    cond = (D_80137DE0->unk4 & 0x10) != cond;
    x = 0;
    y = 0;
    sectnum_ = 0;
    sectnum = gpSprite[spritenum].sectnum;
    z = gpSprite[spritenum].z;
    unk18 = gpSprite[spritenum].unk18;
    unk1A = gpSprite[spritenum].unk1A;

    if (gpSprite[spritenum].cstat & 0x1000)
    {
        i = gModelList[gpSprite[spritenum].picnum-MODELLIST]->unk2E << 6;
        i = i - (i >> 2);
    }
    else
    {
        i = getTileSizeY(gpSprite[spritenum].picnum) * gpSprite[spritenum].yrepeat * 4;
    }

    z -= i;
    if (gpSprite[spritenum].cstat & 0x1000)
    {
        ptr = gModelList[gpSprite[spritenum].picnum-MODELLIST];
        walldist = ((ptr->unk2A - ptr->unk24) * gpSprite[spritenum].xrepeat / 64);
        walldist *= 2;
    }
    else
    {
        walldist = gpSprite[spritenum].xrepeat;
    }

    if ((D_80137DE0->unk4 & 1) && (D_8010A918 < D_80137DE0->unkA))
        D_80137DE0->unk4 |= 0x100;

    cliptype = 0x10001;
    if (gpSprite[spritenum].statnum == 4)
        cliptype = 0x01000040;

    cliptype = (gpSprite[spritenum].picnum != 46) ? cliptype : 0;
    if (cond != 0)
    {
        x = gpSprite[spritenum].x;
        y = gpSprite[spritenum].y;
        sectnum_ = gpSprite[spritenum].sectnum;
        D_8019B940[D_80106D50[spritenum]].unk4 &= ~0x80;
    }

    cstat = gpSprite[spritenum].cstat;
    gpSprite[spritenum].cstat = cstat & ~0x101;

    if (((u16)gpSprite[spritenum].unk1C | ((u16)gpSprite[spritenum].unk18 | (u16)gpSprite[spritenum].unk1A)) == 0)
    {
        ret = 0;
    }
    else
    {
        ret = clipMove(&gpSprite[spritenum].x,
                       &gpSprite[spritenum].y,
                       &z,
                       &sectnum,
                       (unk18 << arg1),
                       (unk1A << arg1),
                       walldist,
                       1024,
                       CLAMP_MIN((i - 0x1200), 1024),
                       cliptype);
    }

    spritenum_ = ret;
    if (!(D_8019B940[D_80106D50[spritenum]].unk0 & 0x40000))
    {
        ret2 = pushMove(&gpSprite[spritenum].x,
                        &gpSprite[spritenum].y,
                        &z,
                        &sectnum,
                        walldist,
                        1024,
                        CLAMP_MIN((i - 0x1200), 1024),
                        cliptype);
    }
    else
    {
        ret2 = 0;
    }

    gpSprite[spritenum].cstat = cstat;
    if (ret2 == -1)
    {
        func_80058E44(spritenum);
        func_8004BD24(spritenum);
        return -1;
    }

    if ((sectnum >= 0) && (sectnum != gpSprite[spritenum].sectnum))
        changeSpriteSect(spritenum, sectnum);

    if (cond != 0)
    {
        if (gpSprite[spritenum].sectnum != sectnum_)
        {
            if (D_8019B940[D_80106D50[spritenum]].unk92 != 3)
            {
                gpSprite[spritenum].x = x;
                gpSprite[spritenum].y = y;
                setSprite(spritenum, x, y, gpSprite[spritenum].z);
                spritenum_ = 0;
                ret = 0;
                D_8019B940[D_80106D50[spritenum]].unk4 |= 0x80;
            }
        }
    }

    spritenum_ &= 0xFFFF;
    if (D_80137DE0->unk4 & 0x8000)
    {
        if ((spritenum_ & 0xC000) && (gpSprite[spritenum_-0xC000].statnum == 10))
            D_80137DE0->unk4 |= 0x20000;

        if (D_8010A918 < 1200)
        {
            z2 = (D_80118248->z - 0x3900);
            D_80169524 = z2 - gPlayer[0].zpos;

            if ((D_80169524 >= -0x7FF) && (D_80169524 < 0x12C0) && (gPlayer[0].unk45 == 0))
                D_80137DE0->unk4 |= 0x10000;
        }
    }

    if (func_8005A240(spritenum) == 1)
    {
        if (spritenum_ & 0xC000)
        {
            spritenum_ -= 0xC000;
            if (spritenum_ > 0)
            {
                if (gpSprite[spritenum_].cstat & 0x1000)
                    j = gModelList[gpSprite[spritenum_].picnum-MODELLIST]->unk2E << 6;
                else
                    j = getTileSizeY(gpSprite[spritenum_].picnum) * gpSprite[spritenum_].yrepeat * 4;

                if (((gpSprite[spritenum].z - (gpSprite[spritenum_].z - j)) >= 0x1200) &&
                    ((gpSprite[spritenum].z - (gpSprite[spritenum_].z - j)) < 0x3800))
                {
                    D_8019B940[D_80106D50[spritenum]].unk4 |= 0x4000;
                }
            }
            else
            {
                spritenum_ += 0xC000;
                if (gpWall[spritenum_ & 0x7FFF].unk16 == 0x7D00)
                    D_8019B940[D_80106D50[spritenum]].unk4 |= 0x4000;
            }
        }
    }
    return ret & 0xFFFF;
}

/*8004E5F8*/
s32 func_8004E5F8(s16 spritenum, s32 xvect, s32 yvect, s32 zvect)
{
    s32 z;
    s32 picnum;
    s32 walldist;
    s32 cliptype;
    u16 ret;
    s32 temp;
    s16 sectnum;
    s16 spritenum_;

    temp = -0x200;
    sectnum = gpSprite[spritenum].sectnum;
    z = gpSprite[spritenum].z - 4096;

    if ((gpSprite[spritenum].cstat & 0x1000))
    {
        picnum = gpSprite[spritenum].picnum;
        walldist = (gModelList[picnum-MODELLIST]->unk2A
                  - gModelList[picnum-MODELLIST]->unk24)
            * gpSprite[spritenum].xrepeat
            / 64;

        switch (gpSprite[spritenum].statnum)
        {
        case 302:
            if (picnum == TANK)
                walldist = 1500;
            break;

        case 305:
            walldist = 600;
            if (picnum == BOSSZERO)
                walldist = 2500;
            if (picnum == BOSSGIANTHOG)
                walldist = 2600;
            break;
        }
    }
    else
    {
        walldist = gpSprite[spritenum].xrepeat;
        walldist *= 2;
    }

    spritenum_ = spritenum;
    if (gpSprite[spritenum_].statnum == 4)
        cliptype = 0x01000040;
    else
        cliptype = 0x10001;

    z = gpSprite[spritenum_].z + zvect;
#ifdef AVOID_UB
    ret = clipMove(&gpSprite[spritenum_].x, &gpSprite[spritenum_].y, &z, &sectnum,
                   xvect << 11, yvect << 11, walldist, 1024, 1024, cliptype);
#else
    ret = clipMove(&gpSprite[spritenum_].x, &gpSprite[spritenum_].y, &z, &sectnum,
                   xvect << 11, yvect << 11, walldist, 1024, MAX(1024, spritenum_ = temp), cliptype); /*FAKEMATCH*/
#endif
    gpSprite[spritenum].z = z;
    if (sectnum >= 0 && sectnum != gpSprite[spritenum].sectnum)
        changeSpriteSect(spritenum, sectnum);
    return ret;
}

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
            if (D_800DEEE4[i] < 6 || D_800DEEE4[i] >= 10)
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
            if (D_8019B940[D_80106D50[i]].unkC != NULL)
            {
                if (D_8019B940[D_80106D50[i]].unk0 & 1)
                {
                    spr = &gpSprite[i];
                    if (((D_8019B940[D_80106D50[i]].unk0 & 0x800) || (D_8019B940[D_80106D50[i]].unk0 & 0x1000))
                        && (D_8019B940[D_80106D50[i]].unk28 != -1))
                        j = func_8004F284(spr, &sp10, D_8019B940[D_80106D50[i]].unk28);
                    else
                        j = func_80058DE0(spr, &sp10);

                    if (temp == 0) /*FAKEMATCH?*/
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
            gpSprite[spritenum].lotag = arg0;
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
        if (gpSprite[i].lotag <= 0)
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
            gpSprite[i].lotag--;

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
                        gpSprite[k].lotag = 32;
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
    switch (gConfig.difficulty)
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
                if ((gpSprite[i].picnum == HELICOPTER) && (gpSprite[i].unk25 == 4))
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
    return (((ang1 << 0x10) + (getAngleDelta(ang1, ang2) << (0x10 - arg2))) >> 0x10) & 0x7FF;
}

/*80051568*/
void func_80051568(void)
{
    s32 i;
    s16 unused = 0;

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

/*800DF1C0*/
static char *D_800DF1C0[4] = {
#if VERSION_US
    "TNT BARREL",
    "FUSE WIRE",
    "PLUNGER BOX",
    "TIME MACHINE PART"
#elif VERSION_FR
    "BARIL DE DYNAMITE",
    "MECHE",
    "DETONATEUR A MANETTE",
    "MACHINE REMONT. TPS"
#endif
};

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
            func_8006B590(spr->hitag);
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

            if ((ceilz == florz) || (sectnum < 0) || (sectnum >= MAXSECTORS))
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
            if (gPlayer[j].third_person)
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
                    (gpSprite[i].lotag == 10) && (gpSprite[i].unk22 == 2) &&
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
                        if (ceilz < MAXKEYS)
                        {
                            char buffer[32];
                            sprintf(buffer, "KEY WITH NO NAME");
                            if (gpKeyStrInfo[gMapNum] != NULL)
                            {
                                if (gpKeyStrInfo[gMapNum][ceilz-1][0] != 0)
                                    sprintf(buffer, gpKeyStrInfo[gMapNum][ceilz-1]);
                            }
                            func_800A419C(j, buffer);
                            gPlayer[j].keys[ceilz] = 1;
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
static u8 func_80052358(s16 playernum, s16 arg1)
{
    if (D_8010A940[playernum].unkA[arg1] >= D_800E17E0[arg1])
        return 0;

    switch (D_8012F6E4[gPlayer[playernum].unk4C].unkB)
    {
    case 3:
        if (arg1 == 1)
            return 0;
        break;
    case 5:
        if ((arg1 == 1) || (arg1 == 5) || (arg1 == 6) || (arg1 == 4))
            return 0;
        break;
    }
    D_8010A940[playernum].unkA[arg1] = D_800E17E0[arg1];

    if (D_8010A940[playernum].unk0 == -1)
        D_8010A940[playernum].unk0 = arg1;
    return 1;
}

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

/*800DF1D0*/
s16 D_800DF1D0[24][3] = {
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 280, 14, 42 },
    { 96, 6, 12 },
    { 96, 8, 12 },
    { 60, 12, 12 },
    { 500, 50, 25 },
    { 100, 5, 10 },
    { 48, 12, 12 },
    { 48, 12, 12 },
    { 48, 1, 6 },
    { 0, 0, 0 },
    { 48, 1, 6 },
    { 48, 1, 6 },
    { 12, 1, 4 },
    { 600, 200, 200 },
    { 500, 50, 50 },
    { 750, 75, 75 },
    { 60, 12, 12 },
    { 6, 0, 6 },
    { 2400, 240, 240 },
    { 12, 3, 3 },
    { 12, 12, 12 },
    { 30, 5, 5 },
};

#ifdef NON_MATCHING
/*8005259C*/
static u8 func_8005259C(s16 playernum, s16 arg1, u32 arg2, s16 spritenum) /*Pickup Ammo+weapon?*/
{
    u8 cond;
    s16 i;
    u32 j;
    s16 spritenum_;

    j = arg2;
    arg2 &= 1;
    spritenum_ = spritenum;

    cond = (D_8011A680[playernum][arg1][1] >= D_800DF1D0[arg1][0]);
    if (arg2)
    {
        cond = ((D_8011A680[playernum][arg1][0] & 1) ? cond : 0);

        if ((arg1 == 2) ||(arg1 == 3) || (arg1 == 6))
            cond = ((D_8011A680[playernum][arg1][0] & 2) ? cond : 0);
    }

    if (cond)
        return 0;

    if (j & 1)
    {
        if ((arg1 == 2) ||(arg1 == 3) || (arg1 == 6))
        {
            if (D_8011A680[playernum][arg1][0] & 1)
                D_8011A680[playernum][arg1][0] |= 2;
        }
        D_8011A680[playernum][arg1][0] |= 1;

        if (D_8019B940[D_80106D50[gPlayer[playernum].unk4A]].unk99 == 0)
        {
            D_8019B940[D_80106D50[gPlayer[playernum].unk4A]].unk99 = arg1;
            D_800DEED0[playernum] = 0;
        }
        i = D_800DF1D0[arg1][1];

        if (((j >> 2) & 1) && (i >= 3))
            i -= krand() % (i / 2);

        if (arg1 == 5)
            i &= 0xFFFE;

        if (j & 8)
        {
            i = gpSprite[spritenum_].lotag;

            if (gpSprite[spritenum_].hitag != 0)
                func_800524BC(playernum, arg1, gpSprite[spritenum_].hitag);
        }
        D_8011A680[playernum][arg1][1] = MIN(D_800DF1D0[arg1][0], (D_8011A680[playernum][arg1][1] + i));
    }

    if (j & 2)
    {
        if ((arg1 == 10) || (arg1 == 12) || (arg1 == 13) || (arg1 == 14))
            D_8011A680[playernum][arg1][0] |= 1;

        i = D_800DF1D0[arg1][2];

        if (((j >> 2) & 1) && (i >= 3))
            i -= krand() % (i / 2);

        D_8011A680[playernum][arg1][1] = MIN(D_800DF1D0[arg1][0], (D_8011A680[playernum][arg1][1] + i));
    }
    return 1;
}
#else
/*8005259C*/
STATIC u8 func_8005259C(s16 playernum, s16 arg1, u32 arg2, s16 spritenum);
INCLUDE_ASM("src/code0/41940", func_8005259C);
#endif

/*80052AB0*/
static s32 func_80052AB0(s16 playernum, s16 arg1, s32 spritenum)
{
    s16 i, k, ret;
    u8 j;

    i = -1;
    k = -1;
    ret = 0;

    j = (gpSprite[spritenum].unk22 == 0x1234) * 4;
    if (gpSprite[spritenum].unk22 == 0x5678)
        j = 8;

    switch (arg1)
    {
    case 0:
        i = 2;
        j |= 1;
        break;
    case 2:
        i = 2;
        j |= 2;
        break;
    case 5:
        i = 4;
        j |= 1;
        break;
    case 7:
        i = 4;
        j |= 2;
        break;
    case 10:
        if (D_8011A680[playernum][4][7] < 24)
        {
            D_8011A680[playernum][4][7] = 24;
            D_8011A680[playernum][4][0] |= 4;
            ret = 1;
        }
        break;
    case 11:
        i = 6;
        j |= 1;
        break;
    case 13:
        i = 6;
        j |= 2;
        break;
    case 16:
        i = 8;
        j |= 1;
        break;
    case 18:
        i = 8;
        j |= 2;
        break;
    case 21:
        i = 9;
        j |= 2;
        break;
    case 24:
        i = 10;
        j |= 1;
        break;
    case 26:
        i = 10;
        j |= 2;
        break;
    case 28:
        i = 15;
        j |= 1;
        break;
    case 30:
        i = 15;
        j |= 2;
        break;
    case 37:
        i = 17;
        j |= 1;
        break;
    case 39:
        i = 17;
        j |= 2;
        break;
    case 42:
        i = 18;
        j |= 1;
        break;
    case 44:
        i = 18;
        j |= 2;
        break;
    case 47:
        if (D_8011A680[playernum][18][7] < 6)
        {
            D_8011A680[playernum][18][0] |= 4;
            ret = 1;
            D_8011A680[playernum][18][7] = CLAMP_MAX((D_8011A680[playernum][18][7] + 6), 6);
        }
        break;
    case 49:
        i = 14;
        j |= 1;
        break;
    case 117:
        i = 14;
        j |= 2;
        break;
    case 52:
        if (D_8011A680[playernum][14][7] < 12)
        {
            D_8011A680[playernum][14][0] |= 5;
            ret = 1;
            D_8011A680[playernum][14][7] = CLAMP_MAX((D_8011A680[playernum][14][7] + 4), 12);
        }
        break;
    case 54:
        i = 21;
        j |= 1;
        break;
    case 56:
        i = 21;
        j |= 2;
        break;
    case 60:
        i = 3;
        j |= 1;
        break;
    case 62:
        i = 3;
        j |= 2;
        break;
    case 65:
        if (D_8011A680[playernum][3][7] < 12)
        {
            D_8011A680[playernum][3][0] |= 4;
            ret = 1;
            D_8011A680[playernum][3][7] = CLAMP_MAX((D_8011A680[playernum][3][7] + 12), 12);
        }
        break;
    case 66:
        i = 5;
        j |= 1;
        break;
    case 68:
        i = 5;
        j |= 2;
        break;
    case 71:
        i = 20;
        j |= 1;
        break;
    case 73:
        i = 20;
        j |= 2;
        break;
    case 76:
        i = 12;
        j |= 1;
        break;
    case 78:
        i = 12;
        j |= 2;
        break;
    case 80:
        i = 13;
        j |= 1;
        break;
    case 82:
        i = 13;
        j |= 2;
        break;
    case 87:
        i = 7;
        j |= 1;
        break;
    case 89:
        i = 7;
        j |= 2;
        break;
    case 92:
        i = 16;
        j |= 1;
        break;
    case 94:
        i = 16;
        j |= 2;
        break;
    case 118:
        i = 23;
        j |= 1;
        break;
    case 119:
        i = 23;
        j |= 2;
        break;
    case 120:
        if (D_8011A680[playernum][23][7] < 12)
        {
            D_8011A680[playernum][23][0] |= 4;
            ret = 1;
            D_8011A680[playernum][23][7] = CLAMP_MAX((D_8011A680[playernum][23][7] + 4), 12);
        }
        break;
    case 122:
        i = 9;
        j |= 1;
        break;
    case 97:
        if ((D_8019B940[D_80106D50[gPlayer[playernum].unk4A]].unk8 < gPlayer[playernum].unk48) &&
            (D_8019B940[D_80106D50[gPlayer[playernum].unk4A]].unk8 != 0))
        {
            ret = 1;
            func_80036520(playernum, 10);
        }
        break;
    case 98:
    case 99:
    case 100:
        if ((D_8019B940[D_80106D50[gPlayer[playernum].unk4A]].unk8 < gPlayer[playernum].unk48) &&
            (D_8019B940[D_80106D50[gPlayer[playernum].unk4A]].unk8 != 0))
        {
            ret = 1;
            func_80036520(playernum, 30);
        }
        break;
    case 101:
    case 102:
    case 103:
        k = 4;
        break;
    case 104:
        k = 3;
        break;
    case 105:
    case 107:
    case 109:
        if (D_8019B940[D_80106D50[gPlayer[playernum].unk4A]].unk7E < 100)
        {
            ret = 1;
            D_8019B940[D_80106D50[gPlayer[playernum].unk4A]].unk7E =
                CLAMP_MAX((D_8019B940[D_80106D50[gPlayer[playernum].unk4A]].unk7E+gpSprite[spritenum].unk22), 100);
            D_8010A940[playernum].unkA[0] = D_8019B940[D_80106D50[gPlayer[playernum].unk4A]].unk7E;
            if (D_8010A940[playernum].unk0 == -1)
                D_8010A940[playernum].unk0 = 0;
        }
        break;
    case 111:
        k = 2;
        break;
    case 112:
        k = 5;
        break;
    case 113:
        k = 6;
        break;
    case 114:
    case 115:
        k = 1;
        break;
    case 124:
        if ((((D_8019B940[D_80106D50[gPlayer[playernum].unk4A]].unk8 >= 200)) ||
            (D_8019B940[D_80106D50[gPlayer[playernum].unk4A]].unk8 == 0)) == 0)
        {
            ret = 1;
            D_8019B940[D_80106D50[gPlayer[playernum].unk4A]].unk8 =
                CLAMP_MAX((D_8019B940[D_80106D50[gPlayer[playernum].unk4A]].unk8 + 50), 200);
        }
        break;
    }

    if (i != -1)
        ret = func_8005259C(playernum, i, j, spritenum);

    if (k != -1)
        ret = func_80052358(playernum, k);

    if (ret != 0)
    {
        func_800A419C(playernum, gpWeaponStrInfo[arg1]);
        if (i != -1)
        {
            audio_800080E0(playernum, 0);
            audio_800077F4(697, spritenum);
        }
        else
        {
            if (k != -1)
                audio_800080E0(playernum, 18);
            audio_800077F4(695, spritenum);
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
void func_800533C4(s32 picnum, s32 spritenum)
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
        switch (picnum)
        {
        case 1767: case 1768: case 2182: case 2183: case 2228: case 2229:
        case 2230: case 2238: case 2239: case 2240: case 2241: case 2407:
            i = 1;

        default:
            j = -1;
            break;

        case 1769: case 1773: case 1774:
            i = 1;
            j = 1;
            break;

        case 1431: case 1433: case 1435: case 1439: case 1524: case 1525:
        case 1549: case 1550: case 1552: case 1578: case 1624: case 1710:
        case 1711: case 1750: case 1925: case 1934: case 1937: case 1942:
        case 1984: case 2156: case 2299: case 2373: case 2412: case 2599:
            j = 1;
            break;

        case 1776:
            j = 5;
            i = 1;
            break;

        case 1731: case 1732:
            j = 3;
            i = 1;
            break;

        case 1751: case 1770: case 1961:
            i = 1;
            j = 0;
            break;

        case 1332: case 1352: case 1353: case 1407: case 1420: case 1421:
        case 1422: case 1457: case 1460: case 1467: case 1470: case 1471:
        case 1481: case 1482: case 1518: case 1519: case 1570: case 1575:
        case 1576: case 1577: case 1603: case 1607: case 1608: case 1609:
        case 1610: case 1611: case 1612: case 1658: case 1668: case 1694:
        case 1714: case 1715: case 1716: case 1734: case 1735: case 1775:
        case 1784: case 1785: case 1790: case 1791: case 1928: case 1978:
        case 1979: case 1980: case 1986: case 1990: case 1991: case 2151:
        case 2153: case 2157: case 2163: case 2164: case 2165: case 2167:
        case 2168: case 2174: case 2176: case 2188: case 2207: case 2210:
        case 2342: case 2343: case 2583: case 2598:
            j = 0;
            break;

        case 1968:
            i = 1;
            j = 13;
            break;

        case 1349: case 1350: case 1485: case 1486: case 1495:
            j = 13;
            break;

        case 1752: case 2249: case 2250: case 2451: case 2462:
            i = 1;
            j = 21;
            break;

        case 1393: case 1406: case 1412: case 1413: case 1464: case 1494:
        case 1529: case 1722: case 1723: case 1789: case 1940: case 1963:
        case 1967: case 1969: case 2185: case 2350: case 2351: case 2594:
            j = 21;
            break;

        case 1461:
            j = 2;
            k = 1;
            break;

        case 1442: case 1501: case 1502: case 1557: case 1558: case 1589:
        case 1757: case 1924: case 2179: case 2318: case 2393:
            j = 2;
            break;

        case 1310: case 1311: case 1314: case 1315: case 1317: case 1318:
        case 1319: case 1320: case 1323: case 1327: case 1331: case 1336:
        case 1337: case 1347: case 1364: case 1366: case 1372: case 1468:
        case 1477: case 1478: case 1490: case 1520: case 1521: case 1522:
        case 1523: case 1536: case 1545: case 1548: case 1553: case 1554:
        case 1555: case 1556: case 1565: case 1567: case 1568: case 1569:
        case 1571: case 1581: case 1582: case 1583: case 1584: case 1585:
        case 1590: case 1593: case 1594: case 1601: case 1604: case 1606:
        case 1616: case 1617: case 1620: case 1634: case 1638: case 1639:
        case 1640: case 1657: case 1760: case 1764: case 1943: case 1944:
        case 1945: case 1946: case 1947: case 1948: case 1949: case 1965:
        case 1973: case 1974: case 1975: case 1994: case 2141: case 2145:
        case 2146: case 2147: case 2149: case 2162: case 2166: case 2170:
        case 2172: case 2173: case 2192: case 2193: case 2194: case 2195:
        case 2196: case 2197: case 2198: case 2201: case 2265: case 2269:
        case 2270: case 2271: case 2272: case 2273: case 2274: case 2275:
        case 2276: case 2277: case 2278: case 2282: case 2405: case 2406:
        case 2420: case 2578: case 3948:
            j = 3;
            break;

        case 1312: case 1313: case 1316: case 1446: case 1453: case 1454:
        case 1455: case 1476: case 1496: case 1530: case 1623: case 1787:
        case 1788: case 1935: case 2158: case 2169: case 2178: case 2374:
        case 2375: case 2376: case 2377: case 2378:
            j = 4;
            break;

        case 1341: case 1543: case 1964:
            j = 5;
            break;

        case 1475: case 1551: case 1754: case 2159: case 2181:
            j = 6;
            break;

        case 1321: case 1322: case 1326: case 1328: case 1354: case 1487:
        case 1488: case 1489: case 1506: case 1507: case 1509: case 1510:
        case 1511: case 1538: case 1539: case 1540: case 1541: case 1733:
        case 1765: case 1922: case 1929: case 1930: case 1931: case 1941:
        case 1992: case 2143: case 2144: case 2148: case 2186: case 2232:
        case 2233: case 2234: case 2235: case 2236: case 2255: case 2256:
        case 2257: case 2258: case 2259:
            j = 12;
            break;

        case 1966:
            j = 14;
            break;

        case 1324: case 1325: case 1330: case 1368: case 1370: case 1621:
        case 1656: case 1753: case 1755: case 1756: case 1758: case 1759:
        case 1920: case 1970: case 1971: case 1972: case 2593:
            j = 15;
            break;

        case 1369:
            j = 16;
            break;

        case 1987: case 1988:
            j = 17;
            break;

        case 2177:
            j = 18;
            break;

        case 1340: case 1344: case 1408: case 1417: case 1463: case 2348:
        case 2349:
            j = 22;
            break;

        case 1371:
            j = 24;
            break;

        case 1591: case 1592:
            j = 25;
            break;

        case 1356: case 1357: case 1358:
            j = 999;
            break;

        case 2281:
            j = 1000;
            break;

        case 1397: case 1398: case 1399:
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
    func_80053650(picnum, spritenum);
}

/*80053650*/
static void func_80053650(s32 picnum, s32 spritenum)
{
    SpriteType *spr;

    spr = &gpSprite[spritenum];
    if (spr->xrepeat == 0)
        spr->xrepeat = 64;

    if (spr->unk25 == 0)
    {
        switch (picnum)
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
            spr->hitag = 2538;
            break;

        case 1466:
            changeSpriteStat(spritenum, 70);
            spr->unk18 = 2;
            spr->unk25 = 0;
            spr->hitag = 2536;
            break;

        case 2266:
            changeSpriteStat(spritenum, 70);
            spr->unk18 = 2;
            spr->unk25 = 0;
            spr->hitag = 2537;
            break;

        case 1483:
            changeSpriteStat(spritenum, 70);
            spr->unk18 = 2;
            spr->unk25 = 0;
            spr->hitag = 1603;
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
void func_800539A8(s32 picnum, s32 spritenum)
{
    SpriteType *spr;
    code0UnkStruct3 *ptr;
    s32 i, j;
    s32 spritenum_;
    u16 unk4A;

    spr = &gpSprite[spritenum];
    spritenum_ = spritenum;

    switch (picnum)
    {
    case 2559:
    case 2562:
    case 2563:
    case 2564:
        spr->cstat |= 0x1101;
        break;

    case 2597:
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = 34;
        ptr->unkC = NULL;
        ptr->unk8 = 100;
        changeSpriteStat(spritenum_, 302);
        break;

    case 2533:
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = 34;
        ptr->unkC = NULL;
        ptr->unk8 = 100;
        changeSpriteStat(spritenum_, 302);
        break;

    case MARINE:
    case SERGEANT:
        spr->xrepeat = 0x40;
        spr->yrepeat = 0x40;
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = 34;
        ptr->unk99 = 4;
        ptr->unkC = NULL;
        ptr->unk8 = 30;
        if (((spr->unk25 & 0x7F) >= 4) && ((spr->unk25 & 0x7F) < 8))
        {
            func_80055DDC(spritenum_);
            ptr->unkC = D_0101F780_STATIC;
            ptr->unk0 |= 0x100000;
        }
        else
            changeSpriteStat(spritenum_, 302);
        break;

    case 2539:
        spr->xrepeat = 0x40;
        spr->yrepeat = 0x40;
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = -1;
        ptr->unk8 = -1;
        ptr->unkC = D_010201B8_STATIC;
        func_80055DDC(spritenum_);
        break;

    case 2581:
        spr->xrepeat = 0;
        spr->yrepeat = 0;
        spr->cstat = -0x7000;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = -1;
        ptr->unk8 = -1;
        ptr->unkC = D_01020F10_STATIC;
        func_80055DDC(spritenum_);
        break;

    case 2487:
        if (spr->unk25 == 1)
        {
            spr->xrepeat = 0;
            spr->yrepeat = 0;
            spr->cstat = 0x1000;
            ptr = func_80053900(spritenum_);
            ptr->unk84 = -1;
            ptr->unk8 = -1;
            ptr->unkC = D_01021464_STATIC;
            func_80055DDC(spritenum_);
        }
        break;

    case 2553:
        spr->xrepeat = 0;
        spr->yrepeat = 0;
        spr->cstat = 0x1000;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = -1;
        ptr->unk8 = -1;
        ptr->unkC = D_01021228_STATIC;
        func_80055DDC(spritenum_);
        break;

    case 2577:
        spr->xrepeat = 0x40;
        spr->yrepeat = 0x40;
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = -1;
        ptr->unk8 = -1;
        ptr->unkC = NULL;
        ptr->unkC = D_0101FB20_STATIC;
        ptr->unk48 = spr->unk24;
        if (spr->unk25 == 0)
        {
            spr->picnum = DUKENUKEM;
            ptr->unk99 = 2;
        }
        else if (spr->unk25 == 1)
            spr->picnum = VICTORIANDUKE;
        else if (spr->unk25 == 2)
            spr->picnum = COWBOYDUKE;
        else if (spr->unk25 == 3)
            spr->picnum = APOCALYPSEDUKE;
        else if (spr->unk25 == 4)
            spr->picnum = BATTLEDRESSDUKE;
        else if (spr->unk25 == 5)
            spr->picnum = DOGTAGDUKE;
        else if (spr->unk25 == 6)
            spr->picnum = POSHDUKE;
        else if (spr->unk25 == 7)
            spr->picnum = XTERMINATOR;
        else if (spr->unk25 == 8)
            spr->picnum = DUKENUKEM;
        func_80055DDC(spritenum_);
        break;

    case 11:
        spr->xrepeat = 0x40;
        spr->yrepeat = 0x40;
        changeSpriteStat(spritenum_, 50);
        gpSprite[spritenum_].unk16 = 8;
        break;

    case SENTRYDRONE:
        spr->xrepeat = 0x40;
        spr->yrepeat = 0x40;
        ptr = func_80053900(spritenum_);
        spr->cstat |= 0x1101;
        ptr->unkC = D_01014468_STATIC;
        ptr->unk84 = 12;
        ptr->unk8 = 50;

        if (!(gpSprite[spritenum_].cstat & 8) && (gpSprite[spritenum_].statnum != 22))
            D_801A1958.enemies_total++;

        func_80055DDC(spritenum_);
        break;

    case 1841:
        spr->xrepeat = 0x40;
        if ((spr->statnum != 4) && (spr->unk25 != 0))
        {
            spr->x += (gpSinTable[(spr->ang + 0x200) & 0x7FF] * 25) >> 13;
            spr->y += (gpSinTable[spr->ang & 0x7FF] * 25) >> 13;
            gPlayer[0].unk38 = (spr->ang - 0x400) & 0x7FF;
            gPlayer[0].xpos = spr->x;
            gPlayer[0].ypos = spr->y;
            gPlayer[0].zpos = spr->z;
            gPlayer[0].unk3E = 0;
            gPlayer[0].unk32 = -69;
            unk4A = gPlayer[0].unk4A;
            i = insertSprite(spr->sectnum, 10);
            if (i != -1)
            {
                gpSprite[i].unk16 = 0;
                gPlayer[0].unk4A = i;
                j = func_8006D3B8(i, 14, 0, 0, 0);
                gPlayer[0].unk4A = unk4A;
                deleteSprite(i);
                if (j != -1)
                {
                    gpSprite[j].hitag = spr->hitag;
                    if (spr->unk25 == 1)
                        gpSprite[j].unk2B = 0xFF;
                    else
                        gpSprite[j].unk2B = 0;
                    deleteSprite(spritenum_);
                }
            }
        }
        break;

    case 1378:
        spr->xrepeat = 0x40;
        ptr = func_80053900(spritenum_);
        spr->cstat |= 0x1000;
        ptr->unkC = D_0101AA1C_STATIC;
        ptr->unk84 = -1;
        func_80055DDC(spritenum_);
        break;

    case 1717:
        spr->xrepeat = 0x40;
        if (spr->unk25 == 1)
        {
            ptr = func_80053900(spritenum_);
            spr->cstat |= 0x1000;
            ptr->unkC = D_0101C310_STATIC;
            ptr->unk84 = -1;
            ptr->unk8 = -1;
            changeSpriteStat(spritenum_, 1);
        }
        break;

    case 1709:
        spr->xrepeat = 0x40;
        if (spr->unk25 == 1)
        {
            ptr = func_80053900(spritenum_);
            spr->cstat |= 0x1000;
            ptr->unkC = D_0101C458_STATIC;
            ptr->unk84 = -1;
            ptr->unk8 = -1;
            func_80055DDC(spritenum_);
        }
        break;

    case EXTERMINATIONDRONE:
        spr->xrepeat = 0x40;
        ptr = func_80053900(spritenum_);
        spr->cstat |= 0x1101;
        ptr->unkC = D_01013B0C_STATIC;
        ptr->unk84 = 13;
        ptr->unk8 = 50;
        func_80055DDC(spritenum_);

        if (!(gpSprite[spritenum_].cstat & 8) && (gpSprite[spritenum_].statnum != 22))
            D_801A1958.enemies_total++;
        break;

    case AQUADRONE:
        spr->xrepeat = 0x40;
        ptr = func_80053900(spritenum_);
        spr->cstat |= 0x1101;
        ptr->unkC = D_01013E74_STATIC;
        ptr->unk84 = 14;
        ptr->unk8 = 50;
        func_80055DDC(spritenum_);

        if (!(gpSprite[spritenum_].cstat & 8) && (gpSprite[spritenum_].statnum != 22))
            D_801A1958.enemies_total++;
        break;

    case BROODLING:
        spr->xrepeat = 0x40;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = 11;
        ptr->unk8 = 10;
        ptr->unkC = D_0101A220_STATIC;
        spr->cstat = 0x1101;
        func_80055DDC(spritenum_);

        if (!(gpSprite[spritenum_].cstat & 8) && (gpSprite[spritenum_].statnum != 22))
            D_801A1958.enemies_total++;
        break;

    case BROODMOTHER:
        spr->xrepeat = 0x40;
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = 18;
        ptr->unk8 = 350;
        ptr->unkC = D_010198B4_STATIC;
        func_80055DDC(spritenum_);

        if (!(gpSprite[spritenum_].cstat & 8) && (gpSprite[spritenum_].statnum != 22))
            D_801A1958.enemies_total++;
        break;

    case SPOREEGGS:
        spr->xrepeat = 0x40;
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = 16;
        ptr->unk8 = 12;
        ptr->unkC = D_0101A624_STATIC;
        func_80055DDC(spritenum_);

        if (!(gpSprite[spritenum_].cstat & 8) && (gpSprite[spritenum_].statnum != 22))
            D_801A1958.enemies_total++;
        break;

    case 2443:
        if (spr->unk25 == 1)
        {
            spr->xrepeat = 0x40;
            spr->cstat |= 0x1000;
            ptr = func_80053900(spritenum_);
            ptr->unk84 = -1;
            ptr->unk8 = -1;
            ptr->unkC = D_0101F5E8_STATIC;
            func_80055DDC(spritenum_);
        }
        break;

    case CERBERUSTURRETS:
        spr->xrepeat = 0x40;
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = 30;
        ptr->unk8 = 600;
        ptr->unkC = D_0101C8A0_STATIC;
        func_80055DDC(spritenum_);

        if (!(gpSprite[spritenum_].cstat & 8) && (gpSprite[spritenum_].statnum != 22))
            D_801A1958.enemies_total++;
        break;

    case GORGONTURRETS:
        spr->xrepeat = 0x40;
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = 30;
        ptr->unk8 = 600;
        ptr->unkC = D_0101CF20_STATIC;
        func_80055DDC(spritenum_);

        if (!(gpSprite[spritenum_].cstat & 8) && (gpSprite[spritenum_].statnum != 22))
            D_801A1958.enemies_total++;
        break;

    case SURVIVOR:
    case KIMBERLYSTROKES:
        spr->xrepeat = 0x40;
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = -1;
        ptr->unk8 = -1;
        ptr->unkC = D_0101F4B4_STATIC;
        func_80055DDC(spritenum_);
        break;

    case 2283:
        if (spr->unk25 == 2)
        {
            spr->xrepeat = 0x40;
            spr->cstat |= 0x1101;
            ptr = func_80053900(spritenum_);
            ptr->unk84 = -1;
            ptr->unk8 = -1;
            ptr->unkC = D_0101FF1C_STATIC;
            func_80055DDC(spritenum_);
        }
        break;

    case 2580:
        spr->xrepeat = 0x40;
        spr->cstat = 0x1000;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = -1;
        ptr->unk8 = -1;
        ptr->unkC = D_01020DDC_STATIC;
        func_80055DDC(spritenum_);
        break;

    case 2596:
        spr->xrepeat = 0x40;
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = -1;
        ptr->unk8 = -1;
        ptr->unkC = D_01020EDC_STATIC;
        func_80055DDC(spritenum_);
        break;

    case 2284:
        if (spr->unk25 == 2)
        {
            spr->xrepeat = 0x40;
            spr->cstat |= 0x1101;
            ptr = func_80053900(spritenum_);
            ptr->unk84 = -1;
            ptr->unk8 = -1;
            ptr->unkC = D_010200C8_STATIC;
            func_80055DDC(spritenum_);
        }
        break;

    case 2290:
        if (spr->unk25 == 1)
        {
            spr->xrepeat = 0x40;
            spr->cstat |= 0x1000;
            ptr = func_80053900(spritenum_);
            ptr->unk84 = -1;
            ptr->unk8 = -1;
            ptr->unkC = D_0102037C_STATIC;
            func_80055DDC(spritenum_);
        }
        else
        {
            spr->xrepeat = 0x40;
            spr->cstat |= 0x1000;
            spr->xrepeat = 0x40;
            spr->unk22 = 0;
            spr->z -= 0x4000;
            spr->ang += 48;
            func_80055DDC(spritenum_);
        }
        break;

    case SENTRYGUNS1:
    case SENTRYGUNS2:
        spr->xrepeat = 0x80;
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        if (spr->picnum == SENTRYGUNS1)
        {
            ptr->unk84 = 19;
            ptr->unkC = D_01017854_STATIC;
        }
        if (spr->picnum == SENTRYGUNS2)
        {
            ptr->unk84 = 20;
            ptr->unkC = D_01017850_STATIC;
        }
        ptr->unk8 = 20;
        func_80055DDC(spritenum_);

        if (!(gpSprite[spritenum_].cstat & 8) && (gpSprite[spritenum_].statnum != 22))
            D_801A1958.enemies_total++;
        break;

    case 2468:
        spr->xrepeat = 0x48;
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = 4;
        ptr->unk8 = 100;
        ptr->unkC = D_0100F1E0_STATIC;
        if (spr->unk25 == 1)
            ptr->unk0 |= 0x800;

        spr->unk25 = 50;
        func_80055DDC(spritenum_);

        if (!(gpSprite[spritenum_].cstat & 8) && (gpSprite[spritenum_].statnum != 22))
            D_801A1958.enemies_total++;
        break;

    case COWBOYGRUNT:
        spr->xrepeat = 0x48;
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = 24;
        ptr->unk8 = 100;
        ptr->unk7E = 100;
        ptr->unkC = D_010151EC_STATIC;
        func_80055DDC(spritenum_);

        if (!(gpSprite[spritenum_].cstat & 8) && (gpSprite[spritenum_].statnum != 22))
            D_801A1958.enemies_total++;
        break;

    case CAPITALISTPIG:
        spr->xrepeat = 0x48;
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = 23;
        ptr->unk8 = 100;
        ptr->unk7E = 100;
        ptr->unkC = D_010151EC_STATIC;
        func_80055DDC(spritenum_);

        if (!(gpSprite[spritenum_].cstat & 8) && (gpSprite[spritenum_].statnum != 22))
            D_801A1958.enemies_total++;
        break;

    case SAVAGEGRUNT:
        spr->xrepeat = 0x48;
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = 25;
        ptr->unk8 = 100;
        ptr->unk7E = 50;
        ptr->unkC = D_010151EC_STATIC;
        func_80055DDC(spritenum_);

        if (!(gpSprite[spritenum_].cstat & 8) && (gpSprite[spritenum_].statnum != 22))
            D_801A1958.enemies_total++;
        break;

    case ROADHOG:
        spr->xrepeat = 0x48;
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = 28;
        ptr->unk8 = 100;
        ptr->unk7E = 100;
        ptr->unkC = D_010151EC_STATIC;
        func_80055DDC(spritenum_);

        if (!(gpSprite[spritenum_].cstat & 8) && (gpSprite[spritenum_].statnum != 22))
            D_801A1958.enemies_total++;
        break;

    case SOLDIERGRUNT:
        spr->xrepeat = 0x48;
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = 26;
        ptr->unk8 = 100;
        ptr->unk7E = 100;
        ptr->unkC = D_010151EC_STATIC;
        func_80055DDC(spritenum_);

        if (!(gpSprite[spritenum_].cstat & 8) && (gpSprite[spritenum_].statnum != 22))
            D_801A1958.enemies_total++;
        break;

    case WARPIG:
        spr->xrepeat = 0x48;
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = 27;
        ptr->unk8 = 100;
        ptr->unk7E = 100;
        ptr->unkC = D_010151EC_STATIC;
        func_80055DDC(spritenum_);

        if (!(gpSprite[spritenum_].cstat & 8) && (gpSprite[spritenum_].statnum != 22))
            D_801A1958.enemies_total++;
        break;

    case RIOTPIG:
        spr->xrepeat = 0x48;
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = 7;
        ptr->unk8 = 100;
        ptr->unk7E = 25;
        ptr->unkC = D_010151EC_STATIC;
        func_80055DDC(spritenum_);

        if (!(gpSprite[spritenum_].cstat & 8) && (gpSprite[spritenum_].statnum != 22))
            D_801A1958.enemies_total++;
        break;

    case PIGCOP:
        spr->xrepeat = 0x48;
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = 6;
        ptr->unk8 = 100;
        ptr->unk7E = 5;
        ptr->unkC = D_010151EC_STATIC;
        func_80055DDC(spritenum_);

        if (!(gpSprite[spritenum_].cstat & 8) && (gpSprite[spritenum_].statnum != 22))
            D_801A1958.enemies_total++;
        break;

    case 2566:
        spr->xrepeat = 0x40;
        spr->picnum = COWBOYDUKE;
        D_800DEF10 = 1;
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = 38;
        ptr->unk8 = 400;
        ptr->unkC = D_0101EB64_STATIC;
        func_80055DDC(spritenum_);

        if (!(gpSprite[spritenum_].cstat & 8) && (gpSprite[spritenum_].statnum != 22))
            D_801A1958.enemies_total++;
        break;

    case 2567:
        spr->xrepeat = 0x40;
        spr->picnum = APOCALYPSEDUKE;
        D_800DEF10 = 1;
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = 39;
        ptr->unk8 = 400;
        ptr->unkC = D_0101EB64_STATIC;
        func_80055DDC(spritenum_);

        if (!(gpSprite[spritenum_].cstat & 8) && (gpSprite[spritenum_].statnum != 22))
            D_801A1958.enemies_total++;
        break;

    case 2401:
        if (spr->unk25 == 1)
            spr->cstat &= 0xFEFE;
        break;

    case 2568:
        spr->xrepeat = 0x40;
        spr->picnum = POSHDUKE;
        D_800DEF10 = 1;
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = 40;
        ptr->unk8 = 600;
        ptr->unkC = D_0101EB64_STATIC;
        func_80055DDC(spritenum_);

        if (!(gpSprite[spritenum_].cstat & 8) && (gpSprite[spritenum_].statnum != 22))
            D_801A1958.enemies_total++;
        break;

    case 2569:
        spr->xrepeat = 0x40;
        spr->picnum = BATTLEDRESSDUKE;
        D_800DEF10 = 1;
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = 41;
        ptr->unk8 = 600;
        ptr->unkC = D_0101EB64_STATIC;
        func_80055DDC(spritenum_);

        if (!(gpSprite[spritenum_].cstat & 8) && (gpSprite[spritenum_].statnum != 22))
            D_801A1958.enemies_total++;
        break;

    case 2570:
        spr->xrepeat = 0x40;
        spr->picnum = EVILDUKE;
        D_800DEF10 = 1;
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = 42;
        ptr->unk8 = 600;
        ptr->unkC = D_0101EB64_STATIC;
        func_80055DDC(spritenum_);

        if (!(gpSprite[spritenum_].cstat & 8) && (gpSprite[spritenum_].statnum != 22))
            D_801A1958.enemies_total++;
        break;

    case 2571:
        spr->xrepeat = 0x40;
        spr->picnum = XTERMINATOR;
        D_800DEF10 = 1;
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = 43;
        ptr->unk8 = 1000;
        ptr->unkC = D_0101EB64_STATIC;
        func_80055DDC(spritenum_);

        if (!(gpSprite[spritenum_].cstat & 8) && (gpSprite[spritenum_].statnum != 22))
            D_801A1958.enemies_total++;
        break;

    case CUSTER:
        spr->xrepeat = 0x40;
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = 36;
        ptr->unk8 = 500;
        ptr->unkC = D_0101DFC4_STATIC;
        func_80055DDC(spritenum_);

        if (!(gpSprite[spritenum_].cstat & 8) && (gpSprite[spritenum_].statnum != 22))
            D_801A1958.enemies_total++;
        break;

    case RIPPER:
        spr->xrepeat = 0x40;
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = 37;
        ptr->unk8 = 750;
        ptr->unkC = D_0101E5C8_STATIC;
        func_80055DDC(spritenum_);

        if (!(gpSprite[spritenum_].cstat & 8) && (gpSprite[spritenum_].statnum != 22))
            D_801A1958.enemies_total++;
        break;

    case ENFORCER:
        spr->xrepeat = 0x40;
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = 2;
        ptr->unk8 = 30;
        ptr->unkC = D_0100F1E0_STATIC;
        func_80055DDC(spritenum_);

        if (!(gpSprite[spritenum_].cstat & 8) && (gpSprite[spritenum_].statnum != 22))
            D_801A1958.enemies_total++;
        break;

    case ENFORCERCAPTAIN:
        spr->xrepeat = 0x40;
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = 3;
        ptr->unk8 = 50;
        ptr->unkC = D_0100F1E0_STATIC;
        func_80055DDC(spritenum_);

        if (!(gpSprite[spritenum_].cstat & 8) && (gpSprite[spritenum_].statnum != 22))
            D_801A1958.enemies_total++;
        break;

    case BATTLEENFORCER:
        spr->xrepeat = 0x40;
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = 4;
        ptr->unk8 = 100;
        ptr->unkC = D_0100F1E0_STATIC;
        func_80055DDC(spritenum_);

        if (!(gpSprite[spritenum_].cstat & 8) && (gpSprite[spritenum_].statnum != 22))
            D_801A1958.enemies_total++;
        break;

    case CYBORGENFORCER:
        spr->xrepeat = 0x40;
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = 5;
        ptr->unk8 = 400;
        ptr->unk7E = 50;
        ptr->unkC = D_0102040C_STATIC;
        func_80055DDC(spritenum_);

        if (!(gpSprite[spritenum_].cstat & 8) && (gpSprite[spritenum_].statnum != 22))
            D_801A1958.enemies_total++;
        break;

    case 2262:
        spr->xrepeat = 0x40;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = -1;
        ptr->unkC = D_0101E560_STATIC;
        func_80055DDC(spritenum_);
        spr->cstat &= 0x7FFF;
        break;

    case 2263:
        spr->xrepeat = 0x40;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = -1;
        ptr->unkC = D_0101E594_STATIC;
        func_80055DDC(spritenum_);
        spr->cstat &= 0x7FFF;
        break;

    case 2222:
        spr->xrepeat = 0x40;
        spr->unk16 = -1;
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = -1;
        ptr->unkC = D_0101BC88_STATIC;
        func_80055DDC(spritenum_);
        break;

    case 1449:
    case 2254:
        spr->xrepeat = 0x40;
        spr->unk16 = -1;
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = -1;
        ptr->unkC = D_0101B9C8_STATIC;
        func_80055DDC(spritenum_);
        break;

    case ZOMBIE1:
    case ZOMBIE2:
    case ZOMBIE3:
    case ZOMBIE4:
    case ZOMBIE5:
    case ZOMBIE6:
    case ZOMBIE7:
        spr->xrepeat = 0x40;
        spr->yrepeat = 0x40;
        spr->cstat |= 0x1101;
        spr->unk22 = spr->unk24;
        ptr = func_80053900(spritenum_);
        if ((spr->unk22 == 0) || (spr->unk25 == 20))
        {
            spr->cstat |= 0x8000;
            ptr->unk86 = -32669;
        }
        ptr->unk84 = 9;
        ptr->unk8 = 80;
        ptr->unkC = D_01017AFC_STATIC;
        func_80055DDC(spritenum_);

        if (!(gpSprite[spritenum_].cstat & 8) && (gpSprite[spritenum_].statnum != 22))
            D_801A1958.enemies_total++;
        break;

    case PARAPSYCHE:
        spr->xrepeat = 0x40;
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = 8;
        ptr->unkC = D_010189A4_STATIC;
        if (spr->unk25 == 6)
            ptr->unk8 = 750;
        else
            ptr->unk8 = 250;
        func_80055DDC(spritenum_);

        if (!(gpSprite[spritenum_].cstat & 8) && (gpSprite[spritenum_].statnum != 22))
            D_801A1958.enemies_total++;
        break;

    case TANK:
        spr->xrepeat = 0x40;
        spr->cstat |= 0x1101;
        if ((spr->statnum == 301) || (spr->statnum == 302))
            spr->cstat |= 0x8000;
        spr->unk22 = 0;
        spr->unk2B = 0;
        ptr = func_80053900(spritenum_);
        ptr->unkC = NULL;
        ptr->unk84 = 21;
        break;

    case 1404:
        spr->xrepeat = 0x40;
        spr->cstat = 0x1000;
        changeSpriteStat(spritenum_, 302);
        break;

    case 26:
        spr->xrepeat = 0x40;
        changeSpriteStat(spritenum_, 7);
        spr->cstat = 0x8000;
        spr->picnum = 0;
        spr->xrepeat = 0x20;
        spr->yrepeat = 0x20;
        spr->unk2B = 0;
        break;

    case HELICOPTER:
        spr->xrepeat = 0x40;
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        if (spr->unk25 == 0)
            changeSpriteStat(spritenum_, 0);
        else
        {
            ptr->unk84 = 22;
            ptr->unkC = D_0101999C_STATIC;
            func_80055DDC(spritenum_);
            if (spr->unk25 == 2)
                changeSpriteStat(spritenum_, 1);
        }
        spr->cstat &= 0x7FFF;
        break;

    case SHIP2:
        spr->xrepeat = 0x40;
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = 10;
        ptr->unk8 = 400;
        ptr->unkC = D_01012FCC_STATIC;
        func_80055DDC(spritenum_);
        spr->unk2A = 0;

        if (!(gpSprite[spritenum_].cstat & 8) && (gpSprite[spritenum_].statnum != 22))
            D_801A1958.enemies_total++;
        break;

    case 1956:
        spr->xrepeat = 0x40;
        spr->cstat |= 0x1000;
        ptr = func_80053900(spritenum_);
        changeSpriteStat(spritenum_, 1);
        ptr->unk84 = -1;
        ptr->unkC = D_0101D440_STATIC;
        spr->unk2A = 0;
        break;

    case SHIP1:
        spr->xrepeat = 0x40;
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = 10;
        ptr->unk8 = 400;
        ptr->unkC = D_01013404_STATIC;
        func_80055DDC(spritenum_);
        spr->unk2A = 0;

        if (!(gpSprite[spritenum_].cstat & 8) && (gpSprite[spritenum_].statnum != 22))
            D_801A1958.enemies_total++;
        break;

    case MARSHALL:
    case SHERIFF:
    case SQUAW:
        spr->xrepeat = 0x40;
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = -1;
        ptr->unkC = D_0101D470_STATIC;
        func_80055DDC(spritenum_);
        if (spr->unk25 == 0)
            D_801A1958.babes_total++;
        break;

    case 44:
        spr->xrepeat = 0x20;
        spr->cstat = 0x8000;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = -1;
        ptr->unkC = D_0101E524_STATIC;
        func_80055DDC(spritenum_);
        break;

    case CHIMERA:
        spr->xrepeat = 0x40;
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = 0;
        ptr->unk8 = 400;
        ptr->unkC = D_0101ACAC_STATIC;
        func_80055DDC(spritenum_);

        if (!(gpSprite[spritenum_].cstat & 8) && (gpSprite[spritenum_].statnum != 22))
            D_801A1958.enemies_total++;
        break;

    case VICTORIANDUKE:
        if (spr->unk25 == 50)
        {
            spr->xrepeat = 0x40;
            spr->cstat |= 0x1101;
            ptr = func_80053900(spritenum_);
            ptr->unk84 = -1;
            ptr->unk8 = -1;
            ptr->unkC = D_0101F8F8_STATIC;
            func_80055DDC(spritenum_);
        }
        break;

    case BOSSGIANTHOG:
        spr->unk2B = 0;
        spr->unk22 = 0;
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        func_8009E5B0(spritenum_);
        ptr->unk84 = 31;
        ptr->unkC = NULL;
        ptr->unk8 = 5000;
        changeSpriteStat(spritenum_, 305);

        if (!(gpSprite[spritenum_].cstat & 8) && (gpSprite[spritenum_].statnum != 22))
            D_801A1958.enemies_total++;
        break;

    case BOSSZERO:
        spr->unk2B = 0;
        spr->unk22 = 0;
        spr->cstat |= 0x1101;
        func_8009B838(spritenum_);
        ptr = func_80053900(spritenum_);
        spr->xrepeat = 0x20;
        ptr->unk84 = 33;
        if (spr->unk25 == 1)
        {
            ptr->unk8 = 0;
            ptr->unk84 = -1;
            ptr->unkC = D_01020284_STATIC;
            changeSpriteStat(spritenum_, 1);
        }
        else
        {
            ptr->unkC = NULL;
            ptr->unk8 = 10000;
            changeSpriteStat(spritenum_, 305);

            if (!(gpSprite[spritenum_].cstat & 8) && (gpSprite[spritenum_].statnum != 22))
                D_801A1958.enemies_total++;
        }
        break;

    case BOSSBRAINSTORM:
        spr->cstat |= 0x1101;
        changeSpriteStat(spritenum_, 302);
        func_80053900(spritenum_);
        break;

    case 33:
        spr->xrepeat = 0x40;
        changeSpriteStat(spritenum_, 8);
        spr->cstat = 0x8000;
        spr->picnum = 0;
        spr->xrepeat = 0x20;
        spr->yrepeat = 0x20;
        break;

    case 2341:
        changeSpriteStat(spritenum_, 302);
        spr->unk18 = 0;
        spr->unk1A = 0;
        spr->unk1C = 0;
        if (spr->unk25 == 1)
        {
            ptr = func_80053900(spritenum_);
            ptr->unk84 = 32;
            ptr->unkC = NULL;
            ptr->unk8 = 300;
        }
        break;

    case 2356:
        spr->cstat |= 0x1101;
        ptr = func_80053900(spritenum_);
        ptr->unk0 |= 2;
        spr->unk22 = 0;
        break;

    case BOSSCYBORGSCORPION:
        spr->lotag = 140;
        spr->cstat |= 0x1101;
        func_8009A9B8(spritenum_);
        ptr = func_80053900(spritenum_);
        ptr->unk0 |= 2;
        ptr->unkC = NULL;
        ptr->unk84 = 35;
        ptr->unk8 = 5000;
        spr->unk22 = 0;
        changeSpriteStat(spritenum_, 305);

        if (!(gpSprite[spritenum_].cstat & 8) && (gpSprite[spritenum_].statnum != 22))
            D_801A1958.enemies_total++;
        break;

    case 46:
        spr->cstat = 0x8000;
        spr->picnum = 46;
        ptr = func_80053900(spritenum_);
        ptr->unk84 = -1;
        ptr->unkC = D_0101F1B4_STATIC;
        ptr->unk0 |= 0x240000;
        func_80055DDC(spritenum_);
        break;
    }
}

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

/*800DF260*/
static s32 D_800DF260[32] = {
    4, 32768, 512, 512, 512, 512, 512, 512, -1, 32768, -1, -1, -1, -1, -1, -1,
    -1, 32768, -1, -1, -1, -1, -1, 512, 512, 512, 512, 512, 512, 512, 0, 0,
};

#ifdef NON_MATCHING
/*80055EC0*/
void func_80055EC0(s32 spritenum, s32 arg1)
{
    s32 i;
    s32 unk9E;

    if (gMapNum == MAP_BRAINSTORM)
    {
        audio_80007A44(704, spritenum, 40000);
        changeSpriteStat(spritenum, 320);
        gpSprite[spritenum].cstat |= 0x800;
        gpSprite[spritenum].unk25 = 31;
        D_801A1958.enemies_killed++;
    }

    if (gMapNum == MAP_UP_SHIP_CREEK)
    {
        if (gpSprite[spritenum].hitag == 0x10E1)
            func_8004A4D4(&gpSprite[spritenum], 2189, 1);
    }

    if (D_80137DE0->unk70 != 0)
    {
        MusHandleStop(D_80137DE0->unk70, 0);
        D_80137DE0->unk70 = 0;
    }

    if (D_80137DE0->unk6C != 0)
    {
        MusHandleStop(D_80137DE0->unk6C, 0);
        D_80137DE0->unk6C = 0;
    }

    if (gMapNum != MAP_BRAINSTORM)
    {
        if ((D_80137DE0->unk84 != -1) && (gpSprite[spritenum].unk2B != 2))
            func_80056600(spritenum);

        D_80137DE0->unk99 = 0;
        i = func_8005A240(spritenum);
        unk9E = D_80137DE0->unk9E;
        if ((unk9E != 15) & (unk9E != 9))
        {
            if (!(D_80137DE0->unk0 & 0x20000))
                func_8006D3B8(spritenum, 100, 0, 0, 0);
        }

        if ((unk9E == 19) || (unk9E == 32) ||
            (unk9E == 18) || (unk9E == 8) ||
            (unk9E == 10) || (unk9E == 13) ||
            (unk9E == 12) || (unk9E == 14) ||
            (unk9E == 37) || (D_80137DE0->unk9F >> 7) || (i == 2))
        {
            if ((i != 1) || (D_80118248->picnum != CYBORGENFORCER))
            {
                if ((i == 2) && (gMapChapter[gMapNum].chapter == VICTORIAN))
                    func_8008E3E0(gpSprite[spritenum].x, gpSprite[spritenum].y,
                                  gpSprite[spritenum].z, gpSprite[spritenum].sectnum, 0x38, 0);

                func_80058E44(spritenum);
                if ((D_800DEF10 != 0) && ((D_80137DE0->unk84 >= 38) && (D_80137DE0->unk84 < 44)))
                    func_8005E2B0(spritenum);
                else
                    func_8004BD24(spritenum);
                return;
            }
        }
        else
        {
            D_80137DE0->unk44 = 0;
            if (((D_80137DE0->unk84 == 1) || (D_80137DE0->unk84 == 9) || (D_80137DE0->unk84 == 17)) &&
                ((D_80137DE0->unk86 == 44) || (D_80137DE0->unk86 == 40) || (D_80137DE0->unk86 == 36)))
            {
                func_80035A98(spritenum, 0);
                changeSpriteStat(spritenum, 53);
                gpSprite[spritenum].unk18 = 0;
                gpSprite[spritenum].unk1A = 0;
                if ((unk9E == 21) && (gpSprite[spritenum].picnum != CYBORGENFORCER))
                {
                    gpSprite[spritenum].cstat |= 0x800;
                    gpSprite[spritenum].unk25 = 31;
                }
            }

            if ((unk9E != 0) || (D_8010A940->unk2[2] != 0))
            {
                if ((D_80137DE0->unk98 != 0xFF))
                {
                    s16 tmp;
                    tmp = D_80137DE0->unk84;
                    if ((D_80137DE0->unk98 < 19))
                    {
                        arg1 = D_800DF260[tmp];
                        if (arg1 != -1)
                        {
                            D_80137DE0->unk44 = 1;
                            D_80137DE0->unk48 = arg1;
                        }
                    }
                }
            }
        }

        func_80035A98(spritenum, 0);
        changeSpriteStat(spritenum, 53);
        gpSprite[spritenum].unk18 = 0;
        gpSprite[spritenum].unk1A = 0;
        if (unk9E == 21)
        {
            gpSprite[spritenum].cstat |= 0x800;
            gpSprite[spritenum].unk25 = 0x1F;
        }
    }
}
#else
/*80055EC0*/
INCLUDE_ASM("src/code0/41940", func_80055EC0);
#endif

/*800563D4*/
void func_800563D4(s32 spritenum, s32 arg1)
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
            gpSprite[spritenum_].lotag = 80;
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

            if (((i == 2) || (i == 3)) && (gMapChapter[gMapNum].chapter == WESTERN))
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

        if ((D_8019B940[D_80106D50[i]].unkC != NULL) && (D_8019B940[D_80106D50[i]].unk0 & 1))
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

            if (D_8019B940[D_80106D50[i]].unkC != NULL)
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
static s32 func_8005731C(s32 spritenum)
{
    SpriteType *spr;
    s32 unk16;
    s32 unk1C;
    s32 i;
    s32 z;
    s32 ang;

    unk16 = gpSprite[spritenum].unk16;
    spr = &gpSprite[spritenum];
    if ((unk16 < 0) || (D_80106D50[unk16] == -1))
        return 0;

    z = spr->z;
    i = func_80058600(unk16);
    unk1C = (((gpSprite[unk16].z - z) - i) * 2000) / ldist(&gpSprite[spritenum], &gpSprite[unk16]);
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
s32 func_80057540(SpriteType *spr, s16 picnum, s16 arg2, s32 arg3)
{
    ModelInfo *model;
    s32 x, y;
    s32 z, z1;
    s32 sizey;
    s32 cond;
    s16 ang;
    s16 spritenum;
    s16 i, j;

    if (arg2 >= 2)
    {
        if (D_800DEEA0 == 0)
            arg2 /= 2;
    }

    if (((picnum < 1500) || (picnum >= 1502)) && (picnum != 5700) && (arg2 >= 2))
    {
        for (i = 0; i != (arg2 / 2); i++)
            func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 55, picnum);
    }

    z1 = (arg3 << 8) + 0x800;
    z = spr->z - z1;
    z1 = getFlorzOfSlope(spr->sectnum, spr->x, spr->y) - 0x800;

    if (z1 < z)
        z = z1;

    sizey = 0;
    if (spr->cstat & 0x1000)
    {
        model = gModelList[spr->picnum-MODELLIST];
        if (model != NULL)
            sizey = (model->unk2E - model->unk28) << 6;
    }
    else
        sizey = getTileSizeY(spr->picnum) * spr->yrepeat * 4;

    for (j = 0; j < arg2; j++)
    {
        ang = krand() & 0x7FF;
        x = (spr->x + (krand() & 0xFF)) - 0x80;
        y = (spr->y + (krand() & 0xFF)) - 0x80;
        spritenum = func_80058934(x, y, z - (krand() & 0x1FFF), spr->sectnum, 94);

        if (spritenum == -1)
            return -1;

        gpSprite[spritenum].cstat = 0;
        gpSprite[spritenum].unk25 = 0;
        cond = func_8004EFB4(spritenum) != 0;

        switch (picnum)
        {
        case 1500:
        case 1501:
            cond = 1;
            gpSprite[spritenum].picnum = 1500;
            gpSprite[spritenum].cstat |= 0x8000;
            break;
        case 1505:
        case 1506:
        case 1507:
        case 1508:
        case 1509:
        case 1510:
            gpSprite[spritenum].xrepeat = (krand() & 0x1F) + 0x18;
            gpSprite[spritenum].yrepeat = (krand() & 0x1F) + 0x18;
            gpSprite[spritenum].cstat |= 0x1000;
            break;

        case 1777:
        case 1778:
        case 1779:
        case 1780:
        case 1781:
        case 1782:
        case 1783:
            gpSprite[spritenum].xrepeat = (krand() & 0x7F) + 0x20;
            gpSprite[spritenum].yrepeat = (krand() & 0x7F) + 0x20;
            gpSprite[spritenum].cstat |= 0x1000;
            break;

        case 1713:
        case 1714:
        case 1715:
        case 1716:
            gpSprite[spritenum].xrepeat = 0x40;
            gpSprite[spritenum].cstat |= 0x1000;
            break;

        case 2130:
            gpSprite[spritenum].picnum = picnum + (krand() & 3);
            gpSprite[spritenum].xrepeat = (krand() & 0x1F) + 0x40;
            cond = 1;
            gpSprite[spritenum].cstat |= 0x1000;
            break;

        case 2414:
            gpSprite[spritenum].picnum = picnum + (krand() % 3);
            gpSprite[spritenum].xrepeat = (krand() & 0x1F) - 0x80;
            cond = 1;
            gpSprite[spritenum].cstat |= 0x1000;
            break;

        case 2038:
        case 2039:
        case 2040:
        case 2041:
        case 2042:
        case 2043:
        case 2044:
        case 2045:
        case 2046:
        case 2047:
        case 2048:
        case 2049:
        case 2050:
        case 2051:
        case 2052:
        case 2053:
        case 2054:
        case 2055:
        case 2056:
        case 2057:
        case 2058:
        case 2059:
        case 2060:
        case 2061:
        case 2062:
        case 2063:
        case 2064:
        case 2065:
        case 2066:
        case 2067:
        case 2068:
        case 2069:
        case 2070:
        case 2071:
        case 2072:
        case 2073:
        case 2074:
        case 2075:
        case 2076:
        case 2077:
        case 2078:
        case 2079:
        case 2080:
        case 2081:
        case 2082:
        case 2083:
        case 2084:
        case 2085:
        case 2086:
        case 2087:
        case 2088:
        case 2089:
        case 2090:
        case 2091:
        case 2092:
        case 2093:
        case 2094:
        case 2095:
        case 2096:
        case 2097:
        case 2098:
            gpSprite[spritenum].xrepeat = 0x40;
            gpSprite[spritenum].cstat |= 0x1000;
            cond = 1;
            gpSprite[spritenum].z = spr->z - sizey;
            break;

        case 5700:
            gpSprite[spritenum].xrepeat = 28;
            break;
        }

        gpSprite[spritenum].picnum = picnum;
        gpSprite[spritenum].ang = ang;

        if ((picnum < 1500) && (picnum >= 1502))
        {
            gpSprite[spritenum].unk18 = (krand() & 0x1F) + 0x30;
            gpSprite[spritenum].unk1C = -0x200 - (krand() & 0x7FF);
        }
        else if ((picnum >= 1777) && (picnum < 1784))
        {
            gpSprite[spritenum].unk18 = (krand() & 6) + 0x4C;
            gpSprite[spritenum].unk1C = -0x310 - (krand() & 0x3FF);
        }
        else
        {
            gpSprite[spritenum].unk18 = (krand() & 0xF) + 0x14;
            gpSprite[spritenum].unk1C = -0x11C - (krand() & 0x1FF);
        }

        if (picnum == 0x1644)
        {
            gpSprite[spritenum].picnum = 1510;
            gpSprite[spritenum].unk1C = -0x7D0 - (krand() & 0x3FF);
            gpSprite[spritenum].unk18 = (krand() & 0x3F) + 0x44;
        }

        D_80106D50[spritenum] = func_8004BE90();

        if (D_80106D50[spritenum] == -1)
            return deleteSprite(spritenum);


        D_8019B940[D_80106D50[spritenum]].unk5C = (krand() & 0x3F) + 0x40;
        D_8019B940[D_80106D50[spritenum]].unk60 = (krand() & 0x3F) + 0x40;
        D_8019B940[D_80106D50[spritenum]].unk54 = 0;

        if (arg3 == 0x1234)
            D_8019B940[D_80106D50[spritenum]].unk0 |= 0x40;

        if (cond == 0)
        {
            if (picnum != 5700)
            {
                if (((krand() & 3) == 1) && (picnum == 1781))
                {
                    D_8019B940[D_80106D50[spritenum]].unk50 = func_8007AE50();
                    D_8019B940[D_80106D50[spritenum]].unk54 = 2;
                }
            }
            else
            {
                D_8019B940[D_80106D50[spritenum]].unk50 = func_8007AE50();
                D_8019B940[D_80106D50[spritenum]].unk54 = 3;
            }
        }
    }
    /*TODO: return?*/
}

/*80057E7C*/
static void func_80057E7C(void)
{
    s32 nexti;
    s32 i, j;
    s32 z1, z2;
    s16 sectnum;
    SpriteType *spr;
    s32 temp;

    temp = 0x32; /*FAKEMATCH?*/
    i = gHeadSpriteStat[94];
    while (i >= 0)
    {
        nexti = gNextSpriteStat[i];
        spr = &gpSprite[i];
        D_80137DE0 = &D_8019B940[D_80106D50[i]];
        sectnum = spr->sectnum;

        if (spr->unk18 > 0)
            spr->unk18--;
        else
            spr->unk18 = 0;

        if (D_80137DE0->unk58 < 300)
            D_80137DE0->unk58++;
        else
            spr->xrepeat = 0;

        if ((spr->unk1C > 0x400) && (spr->unk1C < 0x500))
        {
            setSprite(i, spr->x, spr->y, spr->z);
            sectnum = spr->sectnum;
        }

        z1 = getFlorzOfSlope(sectnum, spr->x, spr->y);
        z2 = getCeilzOfSlope(sectnum, spr->x, spr->y);

        if ((z2 == z1) || (sectnum < 0) || (sectnum > 656))
            spr->xrepeat = 0;

        if (spr->z < (z1 - 0x200))
        {
            if (D_80137DE0->unk48 < 2)
                D_80137DE0->unk48++;
            else if (gpSector[sectnum].unk18 != 2)
            {
                D_80137DE0->unk48 = 0;
                if (D_80137DE0->unk44 >= 3)
                    D_80137DE0->unk44 = 0;
                else
                    D_80137DE0->unk44++;
            }

            if (spr->unk1C < 0x1800)
            {
                if (gpSector[sectnum].unk18 == 2)
                {
                    if (spr->unk1C >= 0x400)
                        spr->unk1C = 0x400;
                    else
                        spr->unk1C += 48;
                }
                else
                {
                    spr->unk1C -= temp;
                    spr->unk1C += 176;
                }
            }
            spr->x += ((spr->unk18 * gpSinTable[(spr->ang + 0x200) & 0x7FF]) >> 14);
            spr->y += ((spr->unk18 * gpSinTable[spr->ang & 0x7FF]) >> 14);
            spr->z += spr->unk1C;

            if ((spr->picnum >= 2038) && (spr->picnum < 2099))
            {
                if (!(D_80137DE0->unk0 & 0x40))
                    func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 15, 20);
            }
        }
        else
        {
            z1 = D_80137DE0->unk4C == 0; /*FAKEMATCH*/
            if (z1)
            {
                if (spr->sectnum == -1)
                    spr->xrepeat = 0;
                D_80137DE0->unk4C++;
            }
            spr->z = (getFlorzOfSlope(spr->sectnum, spr->x, spr->y) - 0x200);
            spr->unk18 = 0;
            spr->xrepeat = 0;
        }

        D_8013B2D0[i].unk0 += D_80137DE0->unk5C;
        D_8013B2D0[i].unk2 += D_80137DE0->unk60;

        if (D_80137DE0->unk54 == 1)
        {
            if (gMapNum == MAP_BRAINSTORM)
                func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 15, 1);
            else
                func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 15, 20);
        }
        else if (D_80137DE0->unk54 == 2)
            func_80058844(i, D_80137DE0->unk50, 20, 16);
        else if (D_80137DE0->unk54 == 3)
            func_80058844(i, D_80137DE0->unk50, 20, 16);

        if ((D_8012FD88 & 3) && (krand() & 1))
        {
            if (spr->picnum == 1500)
            {
                if (gMapNum == MAP_BRAINSTORM)
                    func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 15, 1);
                else
                    func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 34, 20);
            }
            if (spr->picnum == 1501)
                func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 34, 9);
        }

        if (spr->xrepeat == 0)
        {
            if (spr->picnum == 1510)
            {
                if ((gpSector[sectnum].unk18 == 0) || (gpSector[sectnum].unk18 >= 4))
                {
                    j = func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 38, 100);
                    if (j != -1)
                        gpSprite[j].lotag = -1;
                }
            }
            func_8004BD24(i);
        }
        i = nexti;
    }
}

/*80058468*/
static s32 func_80058468(s32 spritenum)
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
    s32 i, d1, d2;

    i = gHeadSpriteStat[4];
    d1 = 0x200000;

    while (i >= 0)
    {
        if (gpSprite[i].lotag != arg1)
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
    s32 ret, i;
    ModelInfo *model;

    ret = 0x3900;
    if (gpSprite[spritenum].cstat & 0x1000)
    {
        model = gModelList[gpSprite[spritenum].picnum-MODELLIST];
        if (model != NULL)
        {
            ret = (model->unk2E - model->unk28) * 32;
            i = gpSprite[spritenum].xrepeat * ret;
            ret = i / 64;
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

    temp = 0x10; /*FAKEMATCH?*/
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
INCLUDE_ASM("src/code0/41940", func_80058E44);
#endif

#if VERSION_FR
/*hack for wrong rodata aligment*/
static const f64 _force_rodata_alignment = 0;
#endif
