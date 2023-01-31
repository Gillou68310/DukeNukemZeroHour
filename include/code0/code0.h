#ifndef _CODE0_H_
#define _CODE0_H_

#include "common.h"
#include "libmus.h"
#include "code0/engine.h"

#define MAXPLAYERS 4

typedef struct
{
    u8 pad1[512];
    LookAt lookat;
    u8 pad2[19104];
    /*Mtx ?           -> 768*/
    /*Mtx ?           -> 896*/
    /*Mtx ?           -> 19584*/
    Mtx projection;
    Mtx viewing;
    Mtx identity;
    Mtx scale;
    u8 pad3[8192];
} Dynamic;

typedef struct
{
    s32 xpos;
    s32 ypos;
    s32 zpos;
    s32 unk_0C;    /*XV*/
    s32 unk_10;    /*YV*/
    s32 unk_14[3]; /*ZV*/
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    s16 sectnum;
    s16 unk_36;
    s16 unk_38; /*MapInfo->unk2C*/
    s16 unk_3A;
    s16 unk_3C;
    s16 unk_3E;
    s32 unk_40;
    u8 unk_44; /*JF*/
    u8 unk_45;
    s16 unk_46;
    s16 unk_48;
    s16 unk_4A;
    s16 unk_4C; /*DN*/
    s16 unk_4E;
    s16 unk_50;
    s16 unk_52;
    u8 unk_54;
    u8 unk_55;
    u8 unk_56; /*OW*/
    u8 unk_57;
    u8 unk_58;
    u8 unk_59; /*OF*/
    u8 unk_5A;
    u8 unk_5B;
    u8 unk_5C;
    s16 unk_5E;
    u8 unk_60;
    u8 unk_61;
    s32 unk_64;
    s16 unk_68;
    s16 unk_6A;
    u8 unk_6C;
    s16 unk_6E;
    s16 unk_70;
    s16 unk_72[3]; /*2->3?*/
    float unk_78;
    float unk_7C;
    u8 unk_80;
    s16 unk_82;
    s16 unk_84;
    s16 unk_86;
    u8 unk_88;
    u8 unk_89;
    u8 unk_8A;
    u8 unk_8B[17]; /*14->17?*/
} code0UnkStruct1;

typedef struct
{
    s16 unk_00;
    u8 unk_02;
    u8 unk_03;
    u8 unk_04[3];
    u8 unk_07;
    u8 unk_08;
    s16 unk_0A[2];
    s16 unk_0E;
    s16 unk_10[2];
    s16 unk_14;
    s16 unk_16;
    s16 unk_18;
} code0UnkStruct2;

typedef struct
{
    s32 unk_00;
    s32 unk_04;
    s16 unk_08;
    s32 unk_0C[7];
    s16 unk_28[3];
    s16 unk_2E;
    s16 unk_30[4]; /*3->4?*/
    s32 unk_38;
    s32 unk_3C;
    s32 unk_40;
    s32 unk_44;
    s32 unk_48;
    s32 unk_4C;
    s32 unk_50;
    s32 unk_54[2];
    s32 unk_5C;
    s32 unk_60;
    s32 unk_64;
    s32 unk_68[3];
    s32 unk_74[2];
    s16 unk_7C;
    s16 unk_7E;
    s16 unk_80[2];
    s16 unk_84;
    s16 unk_86;
    s16 unk_88[2];
    s16 unk_8C[3];
    u8 unk_92[2];
    u8 unk_94;
    u8 unk_95[3];
    u8 unk_98;
    u8 unk_99[4];
    u8 unk_9D;
    u8 unk_9E;
    u8 unk_9F[2];
    u8 unk_A1[3]; /*0->3?*/
} code0UnkStruct3;

typedef struct
{
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
    s16 unk_06;
    s16 unk_08;
    s16 unk_0A;
    s32 unk_0C;
    u8 unk_10;
} code0UnkStruct4;

typedef struct
{
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    musHandle handle;
} code0UnkStruct5;

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

typedef struct
{
    u16 unk0;
    u16 unk2;
    s32 unk4;
} code0UnkStruct7;

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
/*80106D50*/ _extern s16 D_80106D50[MAXSPRITES];
/*8010A914*/ _extern VertexType *gpVertex;
/*8010A938*/ _extern s32 D_8010A938;
/*8010A940*/ _extern code0UnkStruct2 D_8010A940[MAXPLAYERS];
/*80117ED8*/ _extern code0UnkStruct1 D_80117ED8[MAXPLAYERS];
/*80118148*/ _extern u8 D_80118148;
/*80119A64*/ _extern s32 D_80119A64;
/*801297E0*/ _extern Gfx *D_801297E0[MAXPLAYERS][2];
/*80129808*/ _extern u8 *D_80129808;
/*8012BBCC*/ _extern s16 D_8012BBCC;
/*8012BC70*/ _extern code0UnkStruct7 D_8012BC70[256];
/*8012C470*/ _extern s16 D_8012C470;
/*8012DEFC*/ _extern u16 D_8012DEFC;
/*8012DF00*/ _extern u8 *D_8012DF00;
/*8012E150*/ _extern u8 *D_8012E150;
/*8012EED0*/ _extern u8 *D_8012EED0;
/*8012F6F0*/ _extern s8 D_8012F6F0[4];
/*8012FC90*/ _extern s32 D_8012FC90;
/*80138680*/ _extern s32 D_80138680;
/*80138688*/ _extern OSTime D_80138688;
/*80138778*/ _extern u8 *D_80138778;
/*80138780*/ _extern u16 D_80138780;
/*80138830*/ _extern s32 D_80138830;
/*8013A448*/ _extern u16 D_8013A448[256];
/*8013B2D0*/ _extern code0UnkStruct5 D_8013B2D0[MAXSPRITES];
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
/*80199110*/ _extern f32 D_80199110;
/*80199114*/ _extern Vtx *D_80199114;
/*80199524*/ _extern s32 D_80199524;
/*80199528*/ _extern s32 D_80199528;
/*80199558*/ _extern s32 D_80199558;
/*80199750*/ _extern s32 D_80199750;
/*8019B940*/ _extern code0UnkStruct3 D_8019B940[150];
/*801A1958*/ _extern code0UnkStruct4 D_801A1958;
/*801A1970*/ _extern s32 D_801A1970;
/*801A1980*/ _extern f32 D_801A1980;
/*801A19EC*/ _extern u8 D_801A19EC;
/*801A2620*/ _extern s16 D_801A2620;
/*801A2684*/ _extern f32 D_801A2684;
/*801A2688*/ _extern s8 D_801A2688;
/*801A6D80*/ _extern s16 D_801A6D80;
/*801ACC60*/ _extern s32 D_801ACC60;
/*801AD470*/ _extern u8 D_801AD470;
/*801AD474*/ _extern u8 *D_801AD474;
/*801AE4A0*/ _extern Fog gFog[MAXPLAYERS];
/*801AE528*/ _extern s32 D_801AE528;
/*801AE8F0*/ _extern u8 *D_801AE8F0;
/*801AE914*/ _extern s32 D_801AE914;
/*801B0815*/ _extern u8 D_801B0815;
/*801B0820*/ _extern u8 D_801B0820;
/*801B0830*/ _extern Matrix4f D_801B0830[20];
/*801C0D70*/ _extern u8 *D_801C0D70;

#undef _extern

#endif
