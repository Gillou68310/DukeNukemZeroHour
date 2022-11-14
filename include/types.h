#ifndef _TYPES_H_
#define _TYPES_H_

#include "common.h"

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define GFX_TASKS 2
#define OUTPUT_BUFFER_SIZE 65536

typedef f32 Matrix4f[4][4];

/// Linker symbol address, as in `ld_addrs.h`.
typedef u8 Addr[];

typedef void (*ProcPointer)(void);

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
    f32 xEye;
    f32 yEye;
    f32 zEye;
    f32 xAt;
    f32 yAt;
    f32 zAt;
    f32 xUp;
    f32 yUp;
    f32 zUp;
} Position;

typedef struct
{
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C; /*XV*/
    s32 unk_10; /*YV*/
    s32 unk_14[3];  /*ZV*/
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
    u8 unk_44;  /*JF*/
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
    u8 unk_56;  /*OW*/
    u8 unk_57;
    u8 unk_58;
    u8 unk_59;  /*OF*/
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
} typesUnkStruct1;

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
} typesUnkStruct2;

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
} typesUnkStruct3;

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
} typesUnkStruct4;

typedef struct
{
    s32 unk_00;
    s32 unk_04;
    u8 *unk_08;
} typesUnkStruct5;

typedef struct
{
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
} typesUnkStruct6;

#endif
