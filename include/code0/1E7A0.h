#ifndef _1E7A0_H_
#define _1E7A0_H_

#include "common.h"

typedef struct
{
    /*0x00*/ u8 unk0;
    /*0x01*/ u8 unk1;
} _1E7A0UnkStruct1;

typedef struct
{
    /*0x00*/ s16 unk0;
    /*0x04*/ f32 unk4;
    /*0x08*/ f32 unk8;
    /*0x0C*/ s16 unkC;
    /*0x0E*/ u8 unkE;
    /*0x0F*/ u8 unkF;
} _1E7A0UnkStruct2;

void func_8001DBA0(s16 x, s16 y, s16 z, u8, u8, s32);
void func_8001DCD0(s16 x, s16 y, s16 z, s16);
void func_8001DD30(s16 x, s16 y, s16 z);
void func_8001DD78(s32 x, s32 y, s32 z);
void func_8001DE5C(void);
void func_8001DE9C(void);
void func_8001EB2C(void);
void func_8001F388(void);
void func_8001F44C(void);
void func_8001F7B4(s32, s32);

extern _1E7A0UnkStruct1 D_800DCA30[8];
extern _1E7A0UnkStruct2 D_800DCA40[13];

#endif
