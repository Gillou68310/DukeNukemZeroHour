#ifndef _FDE0_H_
#define _FDE0_H_

#include "common.h"

typedef struct {
    /*0x0*/ u8 pad[4];
    /*0x4*/ s32 unk4;
    /*0x8*/ u8 pad1[4];
} _FDE0UnkStruct1;

typedef struct {
    /*0x0*/ u8 pad[4];
    /*0x4*/ s32 unk4;
    /*0x8*/ u8 pad1[4];
    /*0xC*/ u16 unkC;
    /*0xE*/ u16 unkE;
    /*0x10*/ u16 unk10;
    /*0x12*/ u8 pad2[6];
    /*0x18*/ _FDE0UnkStruct1 *unk18;
    /*0x1C*/ u8 pad3[12];
    /*0x28*/ s16 unk28;
    /*0x2A*/ u8 pad4[4];
    /*0x2E*/ s16 unk2E;
} _FDE0UnkStruct2;

void func_8000F3C4(s32, s32, s32, s32, s32, s32);
void func_80011700(_FDE0UnkStruct2 *);
void func_80016D98(_FDE0UnkStruct2 *);

extern s32 D_800BD788;
extern _FDE0UnkStruct2 *D_800D52E0[1320];
extern s16 D_800D6780; /*D_800D52E0 count*/

#endif
