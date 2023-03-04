#ifndef _FDE0_H_
#define _FDE0_H_

#include "common.h"

typedef struct {
    /*0x00*/ s32 fileoff;
    /*0x04*/ u8 *ramaddr;
    /*0x08*/ s16 unk8;
    /*0x0A*/ s16 unkA;
} _FDE0UnkStruct1;

typedef struct {
    /*0x00*/ s32 fileoff;
    /*0x04*/ u8 *ramaddr;
    /*0x08*/ u16 unk8;
    /*0x0A*/ u16 unkA;
    /*0x0C*/ u16 unkC;
    /*0x0E*/ u16 unkE;
    /*0x10*/ u16 unk10;
    /*0x12*/ u16 unk12;
    /*0x14*/ u8 pad2[4];
    /*0x18*/ _FDE0UnkStruct1 *unk18;
    /*0x1C*/ u8 pad3[4];
    /*0x20*/ s8 lock;
    /*0x21*/ u8 pad4[3];
    /*0x24*/ s16 unk24;
    /*0x26*/ s16 unk26;
    /*0x28*/ s16 unk28;
    /*0x2A*/ s16 unk2A;
    /*0x2C*/ s16 unk2C;
    /*0x2E*/ s16 unk2E;
} ModelInfo;

/*Skip declaration so it's called with s32 instead*/
/*void func_8000F3C4(s16 r1, s16 g1, s16 b1, s16 r2, s16 g2, s16 b2);*/
void func_80011700(ModelInfo *model);

extern s32 D_800BD788;
extern ModelInfo *D_800D52E0[1320];
extern s16 D_800D6780; /*D_800D52E0 count*/

#endif
