#ifndef _CODE0_H_
#define _CODE0_H_

#include "common.h"
#include "libmus.h"
#include "code0/engine.h"

#define MAXPLAYERS 4

typedef struct
{
    /*0x0000*/ u8 pad1[512];
    /*0x0200*/ LookAt lookat;
    /*0x0220*/ u8 pad2[19104];
    /*0x4CC0*/ Mtx projection;
    /*0x4D00*/ Mtx viewing;
    /*0x4D40*/ Mtx identity;
    /*0x4D80*/ Mtx scale;
    /*0x4DC0*/ u8 pad3[8192];
} Dynamic;

typedef struct
{
    /*0x00*/ s32 xpos;
    /*0x04*/ s32 ypos;
    /*0x08*/ s32 zpos;
    /*0x0C*/ s32 unkC; /*XV*/
    /*0x10*/ s32 unk10; /*YV*/
    /*0x14*/ s32 unk14; /*ZV*/
    /*0x18*/ s32 unk18;
    /*0x1C*/ s32 unk1C;
    /*0x20*/ s32 unk20;
    /*0x24*/ s32 unk24;
    /*0x28*/ s32 unk28;
    /*0x2C*/ s32 unk2C;
    /*0x30*/ s32 unk30;
    /*0x32*/ s16 unk32; /*sectnum?*/
    /*0x36*/ s16 unk36;
    /*0x38*/ s16 unk38; /*MapInfo->unk2C*/
    /*0x3A*/ s16 unk3A;
    /*0x3C*/ s16 unk3C;
    /*0x3E*/ s16 unk3E;
    /*0x40*/ s32 unk40;
    /*0x44*/ u8 unk44; /*JF*/
    /*0x45*/ u8 unk45;
    /*0x46*/ s16 unk46;
    /*0x48*/ s16 unk48;
    /*0x4A*/ s16 unk4A; /*spritenum?*/
    /*0x4C*/ s16 unk4C; /*DN*/
    /*0x4E*/ s16 unk4E;
    /*0x50*/ s16 unk50; /*spritenum?*/
    /*0x52*/ s16 unk52;
    /*0x54*/ u8 unk54;
    /*0x55*/ u8 unk55;
    /*0x56*/ u8 unk56; /*OW*/
    /*0x57*/ u8 unk57;
    /*0x58*/ u8 unk58;
    /*0x59*/ u8 unk59; /*OF*/
    /*0x5A*/ u8 unk5A;
    /*0x5B*/ u8 unk5B;
    /*0x5C*/ u8 unk5C;
    /*0x5E*/ s16 unk5E;
    /*0x60*/ u8 unk60;
    /*0x61*/ u8 unk61;
    /*0x64*/ s32 unk64;
    /*0x68*/ s16 unk68;
    /*0x6A*/ s16 unk6A;
    /*0x6C*/ u8 unk6C;
    /*0x6E*/ s16 unk6E;
    /*0x70*/ s16 unk70;
    /*0x72*/ s16 unk72;
    /*0x74*/ s16 unk74;
    /*0x76*/ s16 unk76;
    /*0x78*/ float unk78;
    /*0x7C*/ float unk7C;
    /*0x80*/ u8 unk80;
    /*0x82*/ s16 unk82;
    /*0x84*/ s16 unk84;
    /*0x86*/ s16 unk86;
    /*0x88*/ u8 pad[20];
} code0UnkStruct1;

typedef struct
{
    /*0x00*/ s16 unk0;
    /*0x02*/ u8 unk2;
    /*0x03*/ u8 unk3;
    /*0x04*/ u8 unk4;
    /*0x05*/ u8 unk5;
    /*0x06*/ u8 unk6;
    /*0x07*/ u8 unk7;
    /*0x08*/ u8 unk8;
    /*0x0A*/ s16 unkA;
    /*0x0C*/ s16 unkC;
    /*0x0E*/ s16 unkE;
    /*0x10*/ s16 unk10;
    /*0x12*/ s16 unk12;
    /*0x14*/ s16 unk14;
    /*0x16*/ s16 unk16;
    /*0x18*/ s16 unk18;
} code0UnkStruct2;

typedef struct
{
    /*0x00*/ s32 unk0;
    /*0x04*/ s32 unk4;
    /*0x08*/ s16 unk8;
    /*0x0A*/ u16 unkA;
    /*0x0C*/ s32 unkC;
    /*0x10*/ s32 unk10;
    /*0x14*/ s32 unk14;
    /*0x18*/ s32 unk18;
    /*0x1C*/ s32 unk1C;
    /*0x20*/ s32 unk20;
    /*0x24*/ s32 unk24;
    /*0x28*/ s16 unk28;
    /*0x2A*/ s16 unk2A;
    /*0x2C*/ s16 unk2C;
    /*0x2E*/ s16 unk2E; /*wallnum?*/
    /*0x30*/ s16 unk30;
    /*0x32*/ s16 unk32;
    /*0x34*/ s16 unk34;
    /*0x36*/ s16 unk36;
    /*0x38*/ s32 unk38; /*x?*/
    /*0x3C*/ s32 unk3C; /*y?*/
    /*0x40*/ s32 unk40; /*z?*/
    /*0x44*/ s32 unk44; /*x?*/
    /*0x48*/ s32 unk48; /*y?*/
    /*0x4C*/ s32 unk4C; /*z?*/
    /*0x50*/ s32 unk50;
    /*0x54*/ s32 unk54; /*spritenum?*/
    /*0x58*/ s32 unk58;
    /*0x5C*/ s32 unk5C;
    /*0x60*/ s32 unk60; /*spritenum?*/
    /*0x64*/ s32 unk64;
    /*0x68*/ s32 unk68;
    /*0x6C*/ musHandle unk6C; /*mushandle?*/
    /*0x70*/ s32 unk70;
    /*0x74*/ s32 unk74;
    /*0x78*/ s32 unk78;
    /*0x7C*/ s16 unk7C;
    /*0x7E*/ s16 unk7E;
    /*0x80*/ s16 unk80;
    /*0x82*/ s16 unk82;
    /*0x84*/ s16 unk84;
    /*0x86*/ s16 unk86;
    /*0x88*/ s16 unk88;
    /*0x8A*/ s16 unk8A;
    /*0x8C*/ s16 unk8C;
    /*0x8E*/ s16 unk8E;
    /*0x90*/ s16 unk90;
    /*0x92*/ u8 unk92;
    /*0x93*/ u8 unk93;
    /*0x94*/ u8 unk94;
    /*0x95*/ u8 unk95;
    /*0x96*/ u8 unk96;
    /*0x97*/ u8 unk97;
    /*0x98*/ u8 unk98;
    /*0x99*/ u8 unk99;
    /*0x9A*/ u8 unk9A;
    /*0x9B*/ u8 unk9B;
    /*0x9C*/ u8 unk9C;
    /*0x9D*/ u8 unk9D;
    /*0x9E*/ u8 unk9E;
    /*0x9F*/ u8 unk9F;
    /*0xA0*/ u8 unkA0;
    /*0xA1*/ u8 unkA1;
    /*0xA2*/ u8 unkA2;
    /*0xA3*/ u8 unkA3;
} code0UnkStruct3;

typedef struct
{
    /*0x00*/ s16 unk0;
    /*0x02*/ s16 unk2;
    /*0x04*/ s16 unk4;
    /*0x06*/ s16 unk6;
    /*0x08*/ s16 unk8;
    /*0x0A*/ s16 unkA;
    /*0x0C*/ s32 unkC;
    /*0x10*/ u8 unk10;
} code0UnkStruct4;

typedef struct
{
    /*0x00*/ s16 unk0;
    /*0x02*/ s16 unk2;
    /*0x04*/ s16 unk4;
    /*0x06*/ s16 unk6;
    /*0x08*/ musHandle handle;
} code0UnkStruct5;

typedef struct
{
    /*0x00*/ u16 unk0;
    /*0x02*/ u16 unk2;
    /*0x04*/ s32 unk4;
} code0UnkStruct6;

typedef struct {
    /*0x00*/ s16 unk0;
    /*0x02*/ s16 unk2;
    /*0x04*/ u8 pad[10];
    /*0x0E*/ s16 unkE;
    /*0x10*/ u8 pad1[16];
} code0unkStruct7;

typedef struct {
    s16 r;
    s16 g;
    s16 b;
} FogColor;

typedef struct {
    s16 nr;
    s16 fr;
} FogScale;

typedef struct
{
    FogColor color[3];
    FogScale scale[3];
    s16 unk1E;
    s16 unk20;
} Fog;

#ifdef _CODE0_C_
#define _extern
#else
#define _extern extern
#endif

/*800FE3F4*/ _extern s32 D_800FE3F4;
/*800FE410*/ _extern s32 D_800FE410;
/*800FE416*/ _extern s16 gMapNum;
/*800FF528*/ _extern u8 *D_800FF528;
/*800FE9E0*/ _extern s64 D_800FE9E0;
/*800FEA90*/ _extern s8 D_800FEA90;
/*80105550*/ _extern u8 *D_80105550;
/*80106D30*/ _extern u8 D_80106D30[MAXPLAYERS];
/*80106D50*/ _extern s16 D_80106D50[MAXSPRITES] ALIGNED(16);
/*8010A914*/ _extern VertexType *gpVertex;
/*8010A918*/ _extern s32 D_8010A918;
/*8010A938*/ _extern s32 D_8010A938;
/*8010A940*/ _extern code0UnkStruct2 D_8010A940[MAXPLAYERS] ALIGNED(8);
/*80117ED8*/ _extern code0UnkStruct1 D_80117ED8[MAXPLAYERS] ALIGNED(8);
/*80118148*/ _extern u8 D_80118148;
/*80118248*/ _extern SpriteType *D_80118248;
/*80119A64*/ _extern s32 D_80119A64;
/*8011BC48*/ _extern s32 D_8011BC48;
/*801297E0*/ _extern Gfx *D_801297E0[MAXPLAYERS][2] ALIGNED(8);
/*80129808*/ _extern u8 *D_80129808;
/*8012BBCC*/ _extern s16 D_8012BBCC;
/*8012BC70*/ _extern code0UnkStruct6 D_8012BC70[256] ALIGNED(16);
/*8012C470*/ _extern s16 D_8012C470;
/*8012DEFC*/ _extern u16 D_8012DEFC;
/*8012DF00*/ _extern u8 *D_8012DF00;
/*8012E150*/ _extern u8 *D_8012E150;
/*8012EED0*/ _extern u8 *D_8012EED0;
/*8012F6F0*/ _extern s8 D_8012F6F0[4];
/*8012FC90*/ _extern s32 D_8012FC90;
/*8012FCA0*/ _extern s16 D_8012FCA0;
/*8012FD88*/ _extern s32 D_8012FD88;
/*80137DE0*/ _extern code0UnkStruct3 *D_80137DE0;
/*80138680*/ _extern s32 D_80138680;
/*80138688*/ _extern OSTime D_80138688;
/*80138690*/ _extern s32 D_80138690;
/*80138778*/ _extern u8 *D_80138778;
/*80138780*/ _extern u16 D_80138780;
/*80138830*/ _extern s32 D_80138830;
/*8013A448*/ _extern u16 D_8013A448[256] ALIGNED(8);
/*8013B2D0*/ _extern code0UnkStruct5 D_8013B2D0[MAXSPRITES] ALIGNED(16);
/*8013F920*/ _extern u8 *D_8013F920;
/*80168C9C*/ _extern f32 D_80168C9C;
/*80168D0C*/ _extern s16 D_80168D0C;
/*80168D10*/ _extern s32 D_80168D10;
/*80168D04*/ _extern u8 *D_80168D04;
/*80168D18*/ _extern s32 D_80168D18;
/*8016A148*/ _extern s32 D_8016A148;
/*8016D174*/ _extern u8 D_8016D174[4];
/*80197DD4*/ _extern s16 D_80197DD4;
/*80197DE8*/ _extern u8 *D_80197DE8;
/*80197E40*/ _extern code0unkStruct7 D_80197E40[150] ALIGNED(16);
/*80199110*/ _extern f32 D_80199110;
/*80199114*/ _extern Vtx *D_80199114;
/*80199524*/ _extern s32 D_80199524;
/*80199528*/ _extern s32 D_80199528;
/*80199558*/ _extern s32 D_80199558;
/*80199750*/ _extern s32 D_80199750;
/*8019B940*/ _extern code0UnkStruct3 D_8019B940[150] ALIGNED(16);
/*801A1958*/ _extern code0UnkStruct4 D_801A1958 ALIGNED(8);
/*801A1970*/ _extern s32 D_801A1970;
/*801A1980*/ _extern f32 D_801A1980;
/*801A19EC*/ _extern u8 D_801A19EC;
/*801A2620*/ _extern s16 D_801A2620;
/*801A2628*/ _extern s16 D_801A2628;
/*801A2684*/ _extern f32 D_801A2684;
/*801A2688*/ _extern s8 D_801A2688;
/*801A6D80*/ _extern s16 D_801A6D80;
/*801ACC60*/ _extern s32 D_801ACC60;
/*801AD470*/ _extern u8 D_801AD470;
/*801AD474*/ _extern u8 *D_801AD474;
/*801AE4A0*/ _extern Fog gFog[MAXPLAYERS] ALIGNED(8);
/*801AE528*/ _extern s32 D_801AE528;
/*801AE8F0*/ _extern u8 *D_801AE8F0;
/*801AE914*/ _extern s32 D_801AE914;
/*801B0815*/ _extern u8 D_801B0815;
/*801B0820*/ _extern u8 D_801B0820;
/*801B0830*/ _extern Matrix4f D_801B0830[20] ALIGNED(16);
/*801B0D30*/ _extern s32 D_801B0D30;
/*801C0D70*/ _extern u8 *D_801C0D70;

#undef _extern

#endif
