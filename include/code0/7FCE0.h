#ifndef _7FCE0_H_
#define _7FCE0_H_

#include "common.h"
#include "code0/code0.h"

typedef struct
{
    /*0x00*/ u8 *texture;
    /*0x04*/ u8 *palette;
    /*0x08*/ s32 texoff;
    /*0x0C*/ s32 paloff;
    /*0x10*/ s16 width;
    /*0x12*/ s16 height;
} _7FCE0UnkStruct2;

void func_8007F0E0(void);
code0UnkStruct16 *func_8007FC08(_7FCE0UnkStruct2 *, void *, s32, s32, s32);
void func_8007FCC8(void);
void func_8007FD8C(_7FCE0UnkStruct2 *, s32);
void func_8007FE04(void *unused, s32 id, void *dst);
code0UnkStruct16 *func_8007FE2C(char *, s32, s32, s32, s32, s32);
void func_8007FEDC(char *src, u8);
void func_8007FF94(char *src, u8);
void func_80080060(void);
void func_800800A8(s32);
void func_8008011C(void);
code0UnkStruct16 *func_800802C0(char *, s32, s32, s32, s32);
void func_8008036C(void);

extern _7FCE0UnkStruct2 D_800DFA68[2];
extern _7FCE0UnkStruct2 D_800DFA40[2];
extern _7FCE0UnkStruct2 D_800DFA90[2];
extern _7FCE0UnkStruct2 D_800DFAB8[2];
extern _7FCE0UnkStruct2 D_800DFAE0[2];
extern _7FCE0UnkStruct2 D_800DFB08[61];
extern _7FCE0UnkStruct2 D_800DFFCC[54];
extern _7FCE0UnkStruct2 D_800E0404[4];
extern _7FCE0UnkStruct2 D_800E0454[2];
extern _7FCE0UnkStruct2 D_800E047C[23];
extern _7FCE0UnkStruct2 D_800E064C[15];
extern _7FCE0UnkStruct2 D_800E0778[3];
extern _7FCE0UnkStruct2 D_800E07B4[2];
extern _7FCE0UnkStruct2 D_800E07DC[2];
extern _7FCE0UnkStruct2 D_800E0804[8];

#endif
