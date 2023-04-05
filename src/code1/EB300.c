#include "common.h"
#include "code0/main.h"
#include "code0/audio.h"
#include "code0/debug.h"
#include "code0/6ACA0.h"
#include "code0/7F6A0.h"
#include "code0/8E670.h"
#include "code1/EB300.h"
#include "code0/code0.h"
#include "code1/code1.h"

/*.data*/
/*801CA144*/ EXTERN_DATA f32 D_801CA144;
/*801CA14C*/ EXTERN_DATA _EB300UnkStruct1 D_801CA14C[MAP_NUM+1];

/*.comm*/
/*801CC8BC*/ s32 D_801CC8BC;
/*801CDA8C*/ s32 D_801CDA8C;
/*801CDB28*/ u8 D_801CDB28[28] ALIGNED(8);
/*801CDBA8*/ s32 D_801CDBA8;
/*801CDBB0*/ char D_801CDBB0[20] ALIGNED(8);
/*801CDC64*/ u8 D_801CDC64;

/*.text*/
STATIC void func_801C38DC(void);
STATIC void func_801C392C(void);
STATIC void func_801C4E90(void);
STATIC void func_801C509C(void);
STATIC s16 func_801C53E8(s16);
STATIC void func_801C8650(void);

INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBD20);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBD28);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBD34);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBD44);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBD50);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBD5C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBD64);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBD70);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBD7C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBD88);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBD90);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBD98);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBDA0);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBDAC);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBDB8);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBDC0);

extern const char D_801CBDC8[]; /*TODO: mutualized rodata?*/
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBDC8);

INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBDD4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBDE4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBDF8);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBE04);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBE10);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBE1C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBE2C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBE40);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBE5C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBE6C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBE80);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBE90);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBEA0);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBEAC);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBEB8);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBEC4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBED0);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBED8);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBEE4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBEF4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBF08);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C0D80);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C0DCC);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C0E1C);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C0E68);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C0EDC);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C0F28);

/*801C0F70*/
static void func_801C0F70(void)
{
    D_801CE5D8 = 0x25252525;
}

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C0F88);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C0FDC);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C1024);

/*801C1088*/
STATIC f32 func_801C1088(s32 x1, s32 x2, s32 y1, s32 y2)
{
    return ((f32)getAngle(x2 - x1, y2 - y1) * 0.0030679615234375);
}

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C10C8);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C1114);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C1158);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C118C);

/*801C1218*/
void setCameraPosition(f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp, f32 yUp, f32 zUp)
{
    gPosition.xEye = xEye;
    gPosition.yEye = yEye;
    gPosition.zEye = zEye;
    gPosition.xAt = xAt;
    gPosition.yAt = yAt;
    gPosition.zAt = zAt;
    gPosition.xUp = xUp;
    gPosition.yUp = yUp;
    gPosition.zUp = zUp;
}

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C127C);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C146C);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C14B4);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C14C4);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C14D4);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C15CC);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C1950);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C2BE8);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C2F1C);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C2F98);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C305C);

INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBFA8);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBFB8);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBFC8);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBFDC);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBFF0);
INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C30EC);

/*801C328C*/
STATIC void func_801C328C(void)
{
    D_801CDC66 = D_801CE5A0;
    main_80000624(func_801C8650);
}

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C32C4);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C3310);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C3370);

INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC020);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC024);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC028);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC02C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC034);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC038);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC03C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC040);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC044);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC048);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC04C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC050);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC054);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC058);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC060);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC068);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC070);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC074);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC07C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC084);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC08C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC094);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC09C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC0A4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC0AC);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC0B0);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC0B4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC0BC);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC0C4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC0CC);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC0D4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC0DC);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC0E4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC0F0);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC0FC);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC104);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC10C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC114);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC11C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC120);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC128);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC130);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC138);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC140);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC150);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC15C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC164);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC170);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC188);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC198);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC1A4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC1B4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC1C0);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC1CC);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC1D4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC1E0);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC1EC);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC1F4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC204);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC210);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC218);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC21C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC220);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC224);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC228);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC22C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC230);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC234);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC238);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC23C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC240);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC244);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC254);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC268);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC27C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC288);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC29C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC2A4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC2B4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC2C0);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC2CC);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC2D4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC2E0);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC2EC);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC2F4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC308);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC310);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC324);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC334);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC344);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC34C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC35C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC36C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC378);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC384);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC38C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC394);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC3A0);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC3A8);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC3B0);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC3B8);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC3BC);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC3C8);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC3D8);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC3E8);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC3F8);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC404);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC40C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC414);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC424);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC434);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC43C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC448);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC450);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC458);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC464);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC470);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC47C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC480);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC484);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC490);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC4A0);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC4B0);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC4C4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC4D4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC4E0);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC4E8);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC4F4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC50C);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C3524);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C3580);

/*801C35DC*/
STATIC void func_801C35DC(void)
{
    func_8007F07C();
    D_800BD3F9 = 17;
}

/*801C3608*/
static void func_801C3608(void)
{
    D_801CDC64 = 1;
    main_80000624(main_80001F40);
}

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C363C);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C36E4);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C375C);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C37B8);

/*801C3874*/
STATIC void func_801C3874(void)
{
    func_8008E01C(30, 0);
    D_801AE914 = 0;
    func_8007F050();
}

/*801C38A8*/
STATIC void func_801C38A8(void)
{
    D_801AE914 = 0;
    func_8007F050();
    D_80199524 = 1;
}

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C38DC);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C392C);

/*801C3974*/
STATIC void func_801C3974(void)
{
    D_800DF585 = 0;
    func_801C38DC();
}

/*801C399C*/
STATIC void func_801C399C(void)
{
    D_800DF585 = 0;
    func_801C392C();
}

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C39C4);

/*801C3A4C*/
STATIC void func_801C3A4C(void)
{
    func_8007F07C();
    D_801CDBA8 = 1;
    D_801CDA8C = 0;
    D_801CC88C = 1;
}

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C3A88);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C3AD8);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C3E08);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C3E5C);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C45C0);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C4B34);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C4E90);

void func_801C4F38(void)
{
    memset(&D_801CE5F0, 0, sizeof(D_801CE5F0));
    memset(&D_801CE498, 0, sizeof(D_801CE498));
    D_801CE5AC = 0;
    D_801CE5F0.unk103A = 0;
    D_801CE498.unk20 = 1;
    D_801CE498.unk22 = 0;
    D_801CE498.unk1E = 1;
    D_801CE498.unk28 = 0;
    D_801CE498.mastervol = 7;
    D_801CE498.musicvol = 3;
    D_801CE498.unk8 = 2;
    D_801CE498.unk1C = 7;
    D_801CE498.unk16 = 1;
    D_801CE498.unk4E = 1;

    if (osMemSize > 0x400000)
        D_801CE5AC = 2;

    D_801CE498.unk36 = 0;
    D_801CE498.unk38 = 0;
    D_801CE498.unk3A = 0;
    D_801CE498.unk3C = 0;
    D_801CE498.unk3E = 2;
    D_801CE498.unk40 = 2;
    D_801CE498.unk42 = 2;
    D_801CE498.unk44 = 2;
    D_801AE914 = 0;
    D_801A1994 = 0;
    D_80199524 = 0;
    D_800FE3FC = 0;
    D_801CE470 = 0;
    D_800E16BC = 0;
    func_801C4E90();
    sprintf(D_801CDBB0, D_801CBDC8); /*TODO: mutualized rodata?*/
}

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C509C);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C53E8);

INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC550);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC55C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC564);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC56C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC578);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC588);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC594);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC59C);
INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C542C);

INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC5F0);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC600);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC610);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC620);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC630);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC634);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC63C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC648);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC654);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC660);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC66C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC670);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC674);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC678);
INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C5C68);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C63CC);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C6560);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C66D8);

/*801C6CA4*/
STATIC void func_801C6CA4(void)
{
    D_800E16C0 |= 0x1C000000;
}

/*801C6CC4*/
STATIC void func_801C6CC4(void)
{
    D_800E16C0 |= 0x03FC0000;
}

/*801C6CE4*/
STATIC void func_801C6CE4(void)
{
    D_800E16C0 |= 0x70;
}

/*801C6D00*/
STATIC void func_801C6D00(void)
{
    D_800E16C0 |= 0x3E000;
}

/*801C6D24*/
STATIC void func_801C6D24(void)
{
    D_800E16C0 |= 0x1C80;
}

/*801C6D40*/
STATIC void func_801C6D40(void)
{
    D_800E16C0 |= 0x300;
}

/*801C6D5C*/
STATIC void func_801C6D5C(void)
{
    D_801CDBC6 = 1;
    D_800E16BC |= 1;
}

/*801C6D84*/
STATIC void func_801C6D84(void)
{
    D_801CC926 = 1;
    D_800E16BC |= 2;
}

/*801C6DAC*/
STATIC void func_801C6DAC(void)
{
    D_801CDBCC = 1;
    D_800E16BC |= 4;
}

/*801C6DD4*/
STATIC void func_801C6DD4(void)
{
    D_801CC7F4 = 1;
    D_800E16BC |= 8;
}

/*801C6DFC*/
STATIC void func_801C6DFC(void)
{
    D_801CC8C8 = 1;
    D_800E16BC |= 0x10;
}

/*801C6E24*/
STATIC void func_801C6E24(void)
{
    D_801CC8A8 = 1;
    D_800E16BC |= 0x20;
}

/*801C6E4C*/
STATIC void func_801C6E4C(void)
{
    D_801CDBC4 = 1;
    D_800E16BC |= 0x40;
}

/*801C6E74*/
STATIC void func_801C6E74(void)
{
    D_801CC8CC = 1;
    D_800E16BC |= 0x80;
}

/*801C6E9C*/
STATIC void func_801C6E9C(void)
{
    D_801CE48C = 1;
    D_800E16BC |= 0x100;
}

/*801C6EC4*/
STATIC void func_801C6EC4(void)
{
    D_801CC924 = 1;
    D_801CE470 |= 1;
}

/*801C6EEC*/
STATIC void func_801C6EEC(void)
{
    D_801CDB48 = 1;
    D_801CE470 |= 2;
}

/*801C6F14*/
STATIC void func_801C6F14(void)
{
    D_801CE4EC = 1;
    D_801CE470 |= 4;
}

/*801C6F3C*/
STATIC void func_801C6F3C(void)
{
    D_801CF634 = 1;
    D_801CE470 |= 8;
}

/*801C6F64*/
STATIC void func_801C6F64(void)
{
    D_801CE478 = 1;
    D_801CE470 |= 0x10;
}

/*801C6F8C*/
STATIC void func_801C6F8C(void)
{
    D_801CDA80 = 1;
    D_801CE470 |= 0x20;
}

/*801C6FB4*/
STATIC void func_801C6FB4(void)
{
    D_801CC8B8 = 1;
    D_801CE470 |= 0x40;
}

/*801C6FDC*/
STATIC void func_801C6FDC(void)
{
    D_801CDB14 = 1;
    D_801CE470 |= 0x80;
}

/*801C7004*/
STATIC void func_801C7004(void)
{
    D_801CDB16 = 1;
    D_801CE470 |= 0x100;
}

/*801C702C*/
STATIC void func_801C702C(void)
{
    D_801CD984 = 1;
    D_801CE470 |= 0x200;
}

/*801C7054*/
STATIC void func_801C7054(void)
{
    D_801CE480 = 1;
    D_801CE470 |= 0x400;
}

/*801C707C*/
STATIC void func_801C707C(void)
{
    func_801C6EC4();
    func_801C6EEC();
    func_801C6F14();
    func_801C6F3C();
    func_801C6F64();
    func_801C6F8C();
    func_801C6FB4();
    func_801C6FDC();
    func_801C7004();
    func_801C702C();
    func_801C7054();
}

/*801C70EC*/
STATIC void func_801C70EC(void)
{
    D_800DF990 = D_800DF990 == 0;
}

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C7108);

/*801C73A0*/
static void func_801C73A0(void)
{
    s32 i;

    for (i = 0; i < 28; i++)
        D_801CDB28[i] = 0;

    D_801CC8BC = 0;
}

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C73CC);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C7574);

INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC6F8);
INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C764C);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C8650);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C899C);

INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC72C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC73C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC74C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC758);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC764);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC770);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC778);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC780);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC788);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC794);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC79C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC7A8);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC7B4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC7C0);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC7D0);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC7DC);
INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C8DE0);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C8F54);

/*801C90E4*/
static void func_801C90E4(void)
{
    code1UnkStruct3 *ptr;
    code1UnkStruct2 *ptr2;
    s16 ret;
    s32 i;

    ptr = &D_801CE5F0;
    ptr->unk103A = 1;
    ptr->unk2 = 31;
    ptr->unkFE8 = D_801CE498;

    ret = func_801C53E8(gMapNum);
    if (ptr->unkFD5 < ret)
        ptr->unkFD5 = ret;

    if (ret == 3)
        ptr->unkFD6 = 1;

    if (ret == 17)
        ptr->unkFD7 = 1;

    ptr2 = &ptr->unk4[gMapNum];
    if (D_800FE3FC == 0)
    {
        ptr2->unk182 = D_801A1958.unk10;
        ptr2->unk172 = D_801A1958.unkC;
        ptr2->unk178 = D_801A1958.unk4;
        ptr2->unk180 = D_801A1958.unk8;
        ptr2->unk176 = D_801A1958.unk0;
        ptr2->unk164 = D_801A1958.unk2;
        ptr2->unk166 = D_801A1958.unk6;
        ptr2->unk168 = D_801A1958.unkA;
        ptr2->unk0 = D_80117ED8[0].unk46;
        ptr2->unk2 = D_80117ED8[0].unk70;

        for (i = 0; i < 24; i++)
        {
            ptr2->unk4[i][0] = D_8011A680[0][i][0];
            ptr2->unk4[i][1] = D_8011A680[0][i][1];
            ptr2->unk4[i][2] = D_8011A680[0][i][7];
        }

        for (i = 0; i < 8; i++)
            ptr2->unk148[i] = D_8010A940[0].unkA[i];
    }

    ptr->unkFD8 = D_800E16C0;
    ptr->unkFDC = D_800E16BC;
    ptr->unkFE0 = D_801CE470;
    ptr->unkFE4 = D_80168D08;
}

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C936C);

/*801C948C*/
static void func_801C948C(void)
{
    code1UnkStruct3 *ptr;
    ptr = &D_801CE5F0;
    ptr->unk2 = 31;
    ptr->unkFE8 = D_801CE498;
    D_801CC930 = *ptr;
}

/*801C959C*/
static void func_801C959C(void)
{
    code1UnkStruct3 *ptr;
    code1UnkStruct3 *ptr2;

    ptr2 = &D_801CC930;
    ptr = &D_801CE5F0;

    if (ptr2->unk2 == 31)
        D_801CE498 = ptr2->unkFE8;

    *ptr = *ptr2;

    setVolume((D_801CE498.musicvol * 100) / 7, (D_801CE498.mastervol * 100) / 7);
    D_800E16C0 |= ptr->unkFD8;
    D_800E16BC |= ptr->unkFDC;
    D_801CE470 |= ptr->unkFE0;
    D_80168D08 = ptr->unkFE4;
}

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C97A8);

/*801C97F0*/
void func_801C97F0(void)
{
}

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C97F8);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C9924);

/*801C9B08*/
static void func_801C9B08(void)
{
    main_80001F40();
}

/*801C9B28*/
void func_801C9B28(void)
{
    func_801C509C();
}

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C9B48);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C9C18);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C9D68);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C9E7C);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C9EDC);

INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C9F74);
