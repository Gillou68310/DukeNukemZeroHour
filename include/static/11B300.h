#ifndef _11B300_H_
#define _11B300_H_

#include "common.h"
#include "code0/code0.h"

typedef struct
{
    /*0x00*/ s16 unk0;
    /*0x02*/ s16 unk2;
    /*0x04*/ char *actor;
    /*0x08*/ u8 unk8;
    /*0x09*/ u8 unk9;
    /*0x0A*/ u8 unkA;
    /*0x0B*/ u8 unkB;
} _11B300UnkStruct1;

typedef struct {
    /*0x00*/ s16 unk0;
    /*0x02*/ s16 unk2;
    /*0x04*/ s16 unk4;
    /*0x06*/ s16 unk6;
} _11B300UnkStruct2;

typedef struct
{
    /*0x00*/ Color primary;
    /*0x03*/ Color env;
} AlphaPalette;

typedef struct
{
    /*0x00*/ u16 r;
    /*0x02*/ u16 g;
    /*0x04*/ u16 b;
} GlobalPalette;

extern s16 D_01024590[44];
extern s16 D_010245E8[50];
extern _11B300UnkStruct2 D_0102464C[44];
extern s16 D_010247AC[48];
extern s16 D_01025734[44];
extern s16 *D_0102578C[44];
extern s16 D_0102583C;
extern s32 D_01025840[38];
extern s16 D_010258D8[24];
extern s16 D_01025908[48];
extern s16 D_01025968[36];
extern GlobalPalette gGlobalPalette[42];
extern AlphaPalette gAlphaPalette[40];
extern _11B300UnkStruct1 D_01025BA0[29];
extern s16 D_01025CFC;

#endif
