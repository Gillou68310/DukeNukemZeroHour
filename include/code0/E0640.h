#ifndef _E0640_H_
#define _E0640_H_

#include "common.h"

typedef struct
{
    /*0x00*/ u8 *texture;
    /*0x04*/ u8 *palette;
    /*0x08*/ s32 texoff;
    /*0x0C*/ s32 paloff;
    /*0x10*/ s16 width;
    /*0x12*/ s16 height;
} _E0640UnkStruct;

extern _E0640UnkStruct D_800DFA40[2];
extern _E0640UnkStruct D_800DFA68[2];
extern _E0640UnkStruct D_800DFA90[2];
extern _E0640UnkStruct D_800DFAB8[2];
extern _E0640UnkStruct D_800DFAE0[2];
extern _E0640UnkStruct D_800DFB08[61];
extern _E0640UnkStruct D_800DFFCC[54];
extern _E0640UnkStruct D_800E0404[4];
extern _E0640UnkStruct D_800E0454[2];
extern _E0640UnkStruct D_800E047C[23];
extern _E0640UnkStruct D_800E064C[15];
extern _E0640UnkStruct D_800E0778[3];
extern _E0640UnkStruct D_800E07B4[2];
extern _E0640UnkStruct D_800E07DC[2];
extern _E0640UnkStruct D_800E0804[8];

#endif
