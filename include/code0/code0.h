#ifndef _CODE0_H_
#define _CODE0_H_

#include "common.h"

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
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;    /*XV*/
    s32 unk_10;    /*YV*/
    s32 unk_14[3]; /*ZV*/
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    s16 unk_34;
    s16 unk_36;
    s16 unk_38[2];
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

#ifdef _CODE0_C_
#define _extern
#else
#define _extern extern
#endif

/*800FE3F4*/ _extern s32 D_800FE3F4;
/*800FE416*/ _extern s16 D_800FE416;
/*800FF528*/ _extern u8 *D_800FF528;
/*800FE9E0*/ _extern s64 D_800FE9E0;
/*80105550*/ _extern u8 *D_80105550;
/*80106D30*/ _extern u8 D_80106D30[4];
/*80106D50*/ _extern s16 D_80106D50[1500];
/*8010A938*/ _extern s32 D_8010A938;
/*8010A940*/ _extern code0UnkStruct2 D_8010A940[4];
/*80117ED8*/ _extern code0UnkStruct1 D_80117ED8[4];
/*80118148*/ _extern u8 D_80118148;
/*801297E0*/ _extern Gfx *D_801297E0[8];
/*80129808*/ _extern u8 *D_80129808;
/*8012C470*/ _extern s16 D_8012C470;
/*8012DF00*/ _extern u8 *D_8012DF00;
/*8012E150*/ _extern u8 *D_8012E150;
/*8012EED0*/ _extern u8 *D_8012EED0;
/*8012FC90*/ _extern s32 D_8012FC90;
/*80138688*/ _extern OSTime D_80138688;
/*80138778*/ _extern u8 *D_80138778;
/*80138780*/ _extern u16 D_80138780;
/*8013A648*/ _extern u8 *D_8013A648;
/*8013F920*/ _extern u8 *D_8013F920;
/*80168D0C*/ _extern s16 D_80168D0C;
/*80168D10*/ _extern s32 D_80168D10;
/*80168D04*/ _extern u8 *D_80168D04;
/*80168D18*/ _extern s32 D_80168D18;
/*8016D174*/ _extern u8 D_8016D174[4];
/*80197DE8*/ _extern u8 *D_80197DE8;
/*80199524*/ _extern s32 D_80199524;
/*80199528*/ _extern s32 D_80199528;
/*80199750*/ _extern s32 D_80199750;
/*8019B940*/ _extern code0UnkStruct3 D_8019B940[150];
/*801A1958*/ _extern code0UnkStruct4 D_801A1958;
/*801A1970*/ _extern s32 D_801A1970;
/*801A19EC*/ _extern u8 D_801A19EC;
/*801AD470*/ _extern u8 D_801AD470;
/*801AD474*/ _extern u8 *D_801AD474;
/*801AE528*/ _extern s32 D_801AE528;
/*801AE8B8*/ _extern s32 D_801AE8B8;
/*801AE8F0*/ _extern u8 *D_801AE8F0;
/*801AE8FC*/ _extern s32 D_801AE8FC;
/*801AE914*/ _extern s32 D_801AE914;
/*801B0815*/ _extern u8  D_801B0815;
/*801C0D70*/ _extern u8 *D_801C0D70;

#undef _extern

#endif
