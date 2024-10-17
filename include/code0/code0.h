#ifndef _CODE0_H_
#define _CODE0_H_

#include "common.h"
#include "libmus.h"
#include "code0/engine.h"
#include "code0/data/modelinfo.h"
#include "code0/data/D8D20.h"

#define MAXKEYS 17
#define MAXACTORS 150

#if VERSION_US
#define D_8012FCB0_SIZE 48
#elif VERSION_FR
#define D_8012FCB0_SIZE 64
#elif VERSION_EU
#define D_8012FCB0_SIZE 48
#endif

typedef struct
{
    /*0x0000*/ Mtx mtx1[MAXPLAYERS];
    /*0x0100*/ Mtx mtx2[MAXPLAYERS];
    /*0x0200*/ LookAt lookat[MAXPLAYERS][2];
    /*0x0300*/ Mtx mtx6;
    /*0x0340*/ Mtx mtx7;
    /*0x0380*/ Mtx mtx8;
    /*0x03C0*/ u8 pad1[192];
    /*0x0480*/ Mtx mtx3[256];
    /*0x4480*/ Light light[128];
    /*0x4C80*/ Mtx mtx4;
    /*0x4CC0*/ Mtx projection;
    /*0x4D00*/ Mtx viewing;
    /*0x4D40*/ Mtx identity;
    /*0x4D80*/ Mtx scale;
    /*0x4DC0*/ Mtx mtx5[128]; /*?*/
} Dynamic;

typedef struct
{
    /*0x00*/ s32 xpos;
    /*0x04*/ s32 ypos;
    /*0x08*/ s32 zpos;
    /*0x0C*/ s32 xvect;
    /*0x10*/ s32 yvect;
    /*0x14*/ s32 zvect;
    /*0x18*/ s32 unk18;
    /*0x1C*/ s32 unk1C;
    /*0x20*/ s32 unk20;
    /*0x24*/ s32 unk24;
    /*0x28*/ s32 unk28;
    /*0x2C*/ s32 unk2C;
    /*0x30*/ s32 unk30;
    /*0x32*/ s16 cursectnum;
    /*0x36*/ s16 unk36; /*sectnum?*/
    /*0x38*/ s16 ang;
    /*0x3A*/ s16 unk3A;
    /*0x3C*/ s16 unk3C;
    /*0x3E*/ s16 unk3E;
    /*0x40*/ s32 unk40;
    /*0x44*/ u8 unk44; /*JF*/
    /*0x45*/ u8 unk45; /*Condition to mute music?*/
    /*0x46*/ s16 unk46;
    /*0x48*/ s16 unk48;
    /*0x4A*/ s16 unk4A; /*spritenum?*/
    /*0x4C*/ s16 skin;
    /*0x4E*/ s16 unk4E;
    /*0x50*/ s16 unk50; /*spritenum?*/  /*Inside mine cart?*/
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
    /*0x60*/ bool third_person;
    /*0x61*/ u8 unk61;
    /*0x64*/ f32 unk64;
    /*0x68*/ s16 unk68; /*sectnum*/
    /*0x6A*/ s16 unk6A;
    /*0x6C*/ u8 unk6C;
    /*0x6E*/ s16 unk6E;
    /*0x70*/ s16 unk70;
    /*0x72*/ s16 unk72;
    /*0x74*/ s16 unk74;
    /*0x76*/ s16 unk76;
    /*0x78*/ f32 unk78;
    /*0x7C*/ f32 unk7C;
    /*0x80*/ u8 unk80;
    /*0x82*/ s16 unk82;
    /*0x84*/ s16 unk84;
    /*0x86*/ s16 unk86;
    /*0x88*/ u8 keys[MAXKEYS];
    /*0x99*/ u8 pad[2];
} Player;

typedef struct
{
    /*0x00*/ s16 unk0;
    /*0x02*/ u8 unk2[8];
    /*0x0A*/ s16 unkA[8];
} code0UnkStruct2;

typedef struct
{
    /*0x00*/ s32 flag;
    /*0x04*/ s32 unk4;
    /*0x08*/ s16 unk8;
    /*0x0A*/ u16 unkA;
    /*0x0C*/ intptr_t *exec_ptr;
    /*0x10*/ intptr_t *unk10;
    /*0x14*/ intptr_t *unk14;
    /*0x18*/ intptr_t *unk18;
    /*0x1C*/ intptr_t *unk1C;
    /*0x20*/ intptr_t *unk20;
    /*0x24*/ intptr_t *unk24;
    /*0x28*/ s16 unk28; /*spritenum?*/
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
    /*0x64*/ intptr_t unk64;
    /*0x68*/ s32 unk68;
    /*0x6C*/ musHandle unk6C; /*musHandle?*/
    /*0x70*/ musHandle unk70; /*musHandle?*/
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
} Actor;

typedef struct
{
    /*0x00*/ u16 enemies_killed;
    /*0x02*/ u16 enemies_total;
    /*0x04*/ u16 babes_saved;
    /*0x06*/ u16 babes_total;
    /*0x08*/ u16 secrets_found;
    /*0x0A*/ u16 secrets_total;
    /*0x0C*/ s32 unkC;
    /*0x10*/ u8 unk10;
} code0UnkStruct4;

typedef struct
{
    /*0x00*/ s16 unk0;
    /*0x02*/ s16 unk2;
    /*0x04*/ s16 unk4; /*ang*/
    /*0x06*/ s16 unk6;
    /*0x08*/ musHandle handle;
} code0UnkStruct5;

typedef struct
{
    /*0x00*/ u16 index;
    /*0x02*/ u16 sectnum;
    /*0x04*/ s32 dist;
} MaskDraw;

typedef struct {
    /*0x00*/ s16 unk0;
    /*0x02*/ s16 unk2;
    /*0x04*/ _D8D20UnkStruct2 *unk4;
    /*0x08*/ _D8D20UnkStruct2 *unk8;
    /*0x0C*/ s16 unkC;
    /*0x0E*/ s16 unkE;
    /*0x10*/ s16 unk10;
    /*0x12*/ s16 unk12;
    /*0x14*/ s16 unk14;
    /*0x16*/ s16 unk16;
    /*0x18*/ _D8D20UnkStruct2 *unk18;
    /*0x1C*/ _D8D20UnkStruct2 *unk1C;
} code0unkStruct8;

typedef struct
{
    /*0x00*/ s32 unk0;
    /*0x04*/ s32 unk4;
    /*0x08*/ s32 unk8;
    /*0x0C*/ s32 unkC;
    /*0x10*/ s32 unk10;
    /*0x14*/ s32 unk14;
    /*0x18*/ s16 picnum;
    /*0x1C*/ s32 height;
    /*0x20*/ Color fog;
} Cloud;

typedef struct
{
    /*0x00*/ s8 unk0;
    /*0x01*/ s8 unk1;
    /*0x02*/ s16 unk2; /*x?*/
    /*0x04*/ s16 unk4; /*y?*/
    /*0x06*/ s16 unk6; /*z?*/
    /*0x08*/ s16 unk8; /*tilenum*/
    /*0x0A*/ s16 unkA;
    /*0x0C*/ u8 pad[4];
    /*0x10*/ f32 unk10;
    /*0x14*/ f32 unk14;
    /*0x18*/ u8 unk18;
    /*0x19*/ u8 unk19;
} code0UnkStruct13;

typedef struct
{
    /*0x00*/ s8 unk0;
    /*0x04*/ s32 unk4; /*x?*/
    /*0x08*/ s32 unk8; /*y?*/
    /*0x0C*/ s32 unkC; /*z?*/
    /*0x10*/ s32 unk10;
    /*0x14*/ s32 unk14;
    /*0x18*/ s32 unk18;
    /*0x1C*/ s16 unk1C; /*tilenum*/
    /*0x1E*/ u8 unk1E;
    /*0x1F*/ u8 unk1F;
    /*0x20*/ s16 unk20;
    /*0x22*/ s16 unk22;
} code0UnkStruct14;

typedef struct
{
    /*0x00*/ s16 x;
    /*0x02*/ s16 y;
    /*0x04*/ s16 z;
} code0UnkStruct18;

typedef struct
{
    /*0x00*/ s8 unk0;
    /*0x04*/ s32 unk4;
    /*0x08*/ u32 unk8;
    /*0x0C*/ s32 unkC; /*flag?*/
    /*0x10*/ u8 unk10; /*alpha?*/
    /*0x11*/ u8 unk11; /*color?*/
    /*0x12*/ u8 unk12;
    /*0x13*/ u8 pad2[1];
    /*0x14*/ s32 unk14;
    /*0x18*/ u8 pad3[28];
    /*0x34*/ f32 unk34;
    /*0x38*/ f32 unk38;
    /*0x3C*/ f32 unk3C;
    /*0x40*/ f32 unk40;
    /*0x44*/ f32 unk44;
    /*0x48*/ f32 unk48;
    /*0x4C*/ f32 unk4C;
    /*0x50*/ f32 unk50;
    /*0x54*/ f32 unk54;
    /*0x58*/ f32 unk58;
    /*0x5C*/ f32 unk5C;
    /*0x60*/ f32 unk60;
    /*0x64*/ f32 unk64;
    /*0x68*/ Color unk68;
    /*0x6B*/ Color unk6B;
    /*0x6E*/ u8 pad7[2];
    /*0x70*/ void *unk70;
    /*0k74*/ intptr_t unk74;
    /*0k78*/ intptr_t unk78;
    /*0k7C*/ void *unk7C;
    /*0k80*/ void *unk80;
    /*0k84*/ code0UnkStruct18 *unk84;
    /*0k88*/ s32 unk88; /*unk84 element count*/
    /*0k8C*/ u8 *unk8C;
    /*0k90*/ s32 unk90;
    /*0k94*/ s32 unk94;
    /*0k98*/ s32 unk98;
    /*0k9C*/ s32 unk9C;
    /*0kA0*/ s32 unkA0;
    /*0xA4*/ Gfx *unkA4;
    /*0xA8*/ u8 pad9[4];
    /*0xAC*/ Lights1 *unkAC;
} code0UnkStruct16;

typedef struct
{
    /*0x00*/ s32 x;
    /*0x04*/ s32 y;
    /*0x08*/ s32 z;
    /*0x0C*/ s32 unkC;
    /*0x10*/ s16 cursectnum;
    /*0x12*/ s16 unk12;
    /*0x14*/ s16 unk14;
    /*0x16*/ s16 unk16;
    /*0x18*/ s16 unk18;
    /*0x1A*/ s16 unk1A;
    /*0x1C*/ s16 unk1C;
    /*0x1E*/ s16 unk1E;
    /*0x20*/ u8 unk20;
    /*0x24*/ s32 unk24;
} code0UnkStruct17;

typedef struct {
    /*0x00*/ s32 unk0;
    /*0x04*/ s32 unk4;
    /*0x08*/ s32 unk8;
} code0UnkStruct21;

typedef struct
{
    /*0x00*/ u8 *texture;
    /*0x04*/ s32 unk4;
    /*0x08*/ s32 width;
    /*0x0C*/ s32 height;
    /*0x10*/ u8 *palette;
    /*0x14*/ code0UnkStruct18 *unk14;
    /*0x18*/ s16 unk18;
    /*0x1A*/ s16 unk1A;
    /*0x1C*/ s16 unk1C;
    /*0x1E*/ s16 unk1E;
    /*0x20*/ s16 unk20;
    /*0x22*/ s16 unk22;
    /*0x24*/ s16 unk24;
    /*0x26*/ s16 unk26;
    /*0x28*/ s16 unk28;
    /*0x2A*/ s16 unk2A;
    /*0x2C*/ s16 unk2C;
    /*0x2E*/ s16 unk2E;
    /*0x30*/ s32 unk30;
    /*0x34*/ code0UnkStruct21 unk34[4];
} code0UnkStruct19;

typedef struct
{
    /*0x00*/ s16 unk0;
    /*0x02*/ s16 unk2;
    /*0x04*/ void *unk4;
    /*0x08*/ void *unk8;
    /*0x0C*/ void *unkC;
    /*0x10*/ void *unk10;
} code0UnkStruct20;

typedef struct
{
    /*0x00*/ s16 unk0;
    /*0x02*/ s16 unk2;
    /*0x04*/ s16 unk4[4];
    /*0x06*/ u8 pad[2];
} code0UnkStruct22;

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
    u8 unk20;
    u8 pad;
} Fog;

#ifdef _CODE0_C_
#define _extern
#else
#define _extern extern
#endif

#ifdef AVOID_UB
#define _volatile volatile
#else
#define _volatile
#endif

/*800FCBA0*/ _extern s16 D_800FCBA0[32] ALIGNED(8);
/*800FCBE0*/ _extern s32 D_800FCBE0; /*floorhit*/
/*800FE3FC*/ _extern s32 D_800FE3FC;
/*800FE3F0*/ _extern s32 gGlobalPosY;
/*800FE3F4*/ _extern s32 D_800FE3F4;
/*800FE400*/ _extern s32 D_800FE400;
/*800FE410*/ _extern s32 D_800FE410;
/*800FE416*/ _extern s16 gMapNum;
/*800FE944*/ _extern u8 *gpModelTexture;
/*800FE9C8*/ _extern s32 gCloudSpeed[2];
/*800FE9D0*/ _extern s8 D_800FE9D0; /*playernum2*/
/*800FE9D8*/ _extern u8 D_800FE9D8[8];
/*800FE9E0*/ _extern _volatile s64 D_800FE9E0;
/*800FEA90*/ _extern u8 D_800FEA90;
/*800FF4F0*/ _extern code0UnkStruct22 D_800FF4F0[MAXPLAYERS] ALIGNED(8);
/*800FF528*/ _extern s32 *D_800FF528;
/*80105540*/ _extern s32 D_80105540;
/*8010554C*/ _extern u8 D_8010554C;
/*80105550*/ _extern s16 *D_80105550;
/*80105718*/ _extern u8 D_80105718;
/*80105720*/ _extern s16 D_80105720;
/*80105730*/ _extern s32 gOriginsY[1024] ALIGNED(16);
/*80106D30*/ _extern u8 D_80106D30[MAXPLAYERS];
/*80106D50*/ _extern s16 gActorSpriteMap[MAXSPRITES] ALIGNED(16);
/*8010A914*/ _extern Vertex *gpSectorVertex;
/*8010A918*/ _extern s32 D_8010A918;
/*8010A938*/ _extern u8 *D_8010A938; /*edlHandle*/
/*8010A940*/ _extern code0UnkStruct2 D_8010A940[MAXPLAYERS] ALIGNED(8);
/*8010A9AC*/ _extern u8 D_8010A9AC;
/*8010A9B0*/ _extern s32 D_8010A9B0;
/*80117ED8*/ _extern Player gPlayer[MAXPLAYERS] ALIGNED(8);
/*80118148*/ _extern u8 D_80118148;
/*8011814A*/ _extern s16 D_8011814A[5];
/*80118168*/ _extern code0UnkStruct19 D_80118168 ALIGNED(8);
/*80118248*/ _extern SpriteType *D_80118248;
/*80118260*/ _extern char D_80118260[6096] ALIGNED(16);
/*80119A30*/ _extern u8 D_80119A30[MAXPLAYERS];
/*80119A38*/ _extern u8 D_80119A38;
/*80119A64*/ _extern s32 D_80119A64;
/*8011A680*/ _extern s16 D_8011A680[MAXPLAYERS][24][10] ALIGNED(16);
/*8011BC40*/ _extern code0UnkStruct16 *D_8011BC40;
/*8011BC48*/ _extern s32 D_8011BC48;
/*801297E0*/ _extern Gfx *D_801297E0[MAXPLAYERS][2] ALIGNED(8);
/*80129804*/ _extern s32 D_80129804;
/*80129808*/ _extern s16 **D_80129808;
/*8012B948*/ _extern Matrix4f D_8012B948 ALIGNED(8); /*viewing*/
/*8012BBCC*/ _extern u16 D_8012BBCC;
/*8012BC70*/ _extern MaskDraw gMaskDrawList[256] ALIGNED(16);
/*8012C470*/ _extern s16 D_8012C470; /*playernum?*/
/*8012C478*/ _extern Gfx *D_8012C478[200] ALIGNED(8);
/*8012C798*/ _extern s32 D_8012C798;
/*8012C989*/ _extern u8 D_8012C989;
/*8012D218*/ _extern u32 D_8012D218[MAXPLAYERS][18] ALIGNED(8);
/*8012D338*/ _extern s8 D_8012D338; /*angle*/
/*8012DEFA*/ _extern u16 D_8012DEFA;
/*8012DEFC*/ _extern u16 gLastPicnum;
/*8012DF00*/ _extern s16 *D_8012DF00;
/*8012DF04*/ _extern Color D_8012DF04[MAXPLAYERS];
/*8012DF10*/ _extern code0UnkStruct14 D_8012DF10[16] ALIGNED(8);
/*8012E150*/ _extern s16 *D_8012E150;
/*8012EB4C*/ _extern s32 D_8012EB4C;
/*8012F6E8*/ _extern s32 D_8012F6E8;
/*8012F6F0*/ _extern u8 D_8012F6F0[MAXPLAYERS];
/*8012F6F4*/ _extern s16 D_8012F6F4; /*sectnum*/
/*8012F908*/ _extern s32 D_8012F908;
/*8012F914*/ _extern s16 D_8012F914[MAXPLAYERS];
/*8012FC40*/ _extern u8 D_8012FC40;
/*8012FC48*/ _extern Cloud gCloud[2] ALIGNED(8);
/*8012FC90*/ _extern s32 D_8012FC90;
/*8012FCA0*/ _extern s16 D_8012FCA0[MAXPLAYERS];
/*8012FCB0*/ _extern char D_8012FCB0[MAXPLAYERS][D_8012FCB0_SIZE] ALIGNED(8);
/*8012FD80*/ _extern s32 gAlertAliens;
/*8012FD88*/ _extern s32 D_8012FD88; /*ang*/
/*8012FD8C*/ _extern code0UnkStruct16 *D_8012FD8C;
/*80137DE0*/ _extern Actor *gpActor;
/*80138610*/ _extern s32 D_80138610[MAXPLAYERS] ALIGNED(8);
/*80138620*/ _extern u8 D_80138620;
/*80138678*/ _extern s32 D_80138678;
/*80138680*/ _extern s32 D_80138680;
/*80138688*/ _extern OSTime D_80138688;
/*80138690*/ _extern s32 D_80138690;
/*8013869C*/ _extern s16 gSkyBottomB;
/*80138714*/ _extern ModelTextureInfo *gpModelTextureInfo;
/*8013871C*/ _extern s32 D_8013871C;
/*80138778*/ _extern u8 *D_80138778; /*palette*/
/*80138780*/ _extern s16 D_80138780;
/*80138830*/ _extern s32 gSortSpritesCnt;
/*80138854*/ _extern u8 *D_80138854; /*cache buffer*/
/*80138858*/ _extern s16 D_80138858[MAXPLAYERS];
/*80138860*/ _extern s32 D_80138860; /*floorz*/
/*8013A438*/ _extern s32 D_8013A438; /*lightz*/
/*8013B2D0*/ _extern code0UnkStruct5 D_8013B2D0[MAXSPRITES] ALIGNED(16);
/*8013F920*/ _extern s16 *D_8013F920;
/*8013F950*/ _extern s32 D_8013F950;
/*80168C9C*/ _extern f32 D_80168C9C;
/*80168D0C*/ _extern s16 D_80168D0C;
/*80168D08*/ _extern s32 gTimeMachinePart;
/*80168D18*/ _extern s32 D_80168D18;
/*80169520*/ _extern u8 D_80169520; /*cache lock*/
/*80169522*/ _extern s16 gSkyTopG;
/*8016A144*/ _extern s32 D_8016A144;
/*8016A148*/ _extern s32 D_8016A148;
/*8016A14C*/ _extern s32 D_8016A14C; /*lighty*/
/*8016A150*/ _extern s32 D_8016A150;
/*8016A154*/ _extern u8 D_8016A154[MAXPLAYERS];
/*8016A15C*/ _extern f32 D_8016A15C;
/*8016D174*/ _extern u8 D_8016D174[MAXPLAYERS];
/*8016D180*/ _extern u16 D_8016D180;
/*80197DCC*/ _extern s16 gSkyTopB;
/*80197DD4*/ _extern s16 gVertexNumber;
/*80197DE8*/ _extern s16 *D_80197DE8;
/*80197E40*/ _extern code0unkStruct8 D_80197E40[MAXACTORS] ALIGNED(16);
/*80199110*/ _extern f32 D_80199110;
/*80199114*/ _extern Vtx *gpVertexList;
/*80199524*/ _extern s32 D_80199524;
/*80199558*/ _extern s32 D_80199558;
/*8019956C*/ _extern u8 D_8019956C;
/*80199638*/ _extern s32 D_80199638;
/*80199640*/ _extern s32 gGlobalPosZ;
/*80199942*/ _extern s16 D_80199942;
/*80199970*/ _extern s32 D_80199970[MAXPLAYERS] ALIGNED(8);
/*8019B940*/ _extern Actor gActor[MAXACTORS] ALIGNED(16);
/*801A1958*/ _extern code0UnkStruct4 D_801A1958 ALIGNED(8);
/*801A1970*/ _extern s32 D_801A1970;
/*801A1980*/ _extern f32 D_801A1980;
/*801A198C*/ _extern s16 gSkyBottomG;
/*801A1994*/ _extern s32 D_801A1994;
/*801A1998*/ _extern s32 D_801A1998; /*ceilz*/
/*801A19EC*/ _extern u8 D_801A19EC;
/*801A19F0*/ _extern musHandle D_801A19F0;
/*801A19F4*/ _extern s32 D_801A19F4;
/*801A2620*/ _extern s16 gVertexBufferIndex;
/*801A2628*/ _extern s16 D_801A2628; /*playernum?*/
/*801A2684*/ _extern f32 D_801A2684;
/*801A2688*/ _extern s8 D_801A2688;
/*801A2790*/ _extern code0UnkStruct17 D_801A2790[MAXPLAYERS] ALIGNED(8);
/*801A68D0*/ _extern u16 D_801A68D0[256] ALIGNED(8);
/*801A6AD4*/ _extern u8 D_801A6AD4[MAXPLAYERS];
/*801A6D80*/ _extern u16 D_801A6D80;
/*801A6D84*/ _extern s32 gGlobalPosX;
/*801AC8E0*/ _extern f32 D_801AC8E0;
/*801AC8E8*/ _extern s16 D_801AC8E8[128] ALIGNED(8);
/*801AC9E8*/ _extern s32 D_801AC9E8;
/*801AC9F8*/ _extern s16 D_801AC9F8;
/*801ACBD4*/ _extern Gfx *D_801ACBD4;
/*801ACC60*/ _extern s32 D_801ACC60;
/*801AD470*/ _extern u8 D_801AD470;
/*801AD474*/ _extern s16 *D_801AD474;
/*801AD480*/ _extern s32 gOriginsX[1024] ALIGNED(16);
/*801AE480*/ _extern s32 D_801AE480[MAXPLAYERS] ALIGNED(8);
/*801AE490*/ _extern s32 gSnoozingAliens;
/*801AE4A0*/ _extern Fog gFog[MAXPLAYERS] ALIGNED(8);
/*801AE528*/ _extern s32 D_801AE528;
/*801AE538*/ _extern code0UnkStruct13 D_801AE538[32] ALIGNED(8);
/*801AE8F0*/ _extern s16 *D_801AE8F0;
/*801AE8F4*/ _extern u16 D_801AE8F4; /*spritenum*/
/*801AE904*/ _extern s32 gCloudAng[2];
/*801AE910*/ _extern s32 D_801AE910;
/*801AE914*/ _extern s32 D_801AE914;
/*801AE918*/ _extern s32 D_801AE918;
/*801AE91E*/ _extern u8 D_801AE91E[8];
/*801AE9C0*/ _extern s32 D_801AE9C0; /*ceilhit*/
/*801AEA10*/ _extern f32 gGlobalAng;
/*801AEA30*/ _extern s16 gSkyBottomR;
/*801B080C*/ _extern s32 D_801B080C; /*lightx*/
/*801B0815*/ _extern u8 D_801B0815;
/*801B0820*/ _extern u8 D_801B0820; /*playernum?*/
/*801B0830*/ _extern Matrix4f D_801B0830[20] ALIGNED(16);
/*801B0D30*/ _extern s32 D_801B0D30;
/*801C0D5C*/ _extern s16 gSkyTopR;

#undef _extern

#endif
