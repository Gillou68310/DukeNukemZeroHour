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

/*01024590*/ extern u8 D_01024590[];
/*010245E8*/ extern s16 D_010245E8[];
/*0102464C*/ extern _11B300UnkStruct2 D_0102464C[44];
/*010247AC*/ extern s16 D_010247AC[];
/*01025734*/ extern s16 D_01025734[];
/*0102578C*/ extern s16 *D_0102578C[];
/*0102583C*/ extern u8 D_0102583C[];
/*01025840*/ extern u8 D_01025840[];
/*010258D8*/ extern u8 D_010258D8[];
/*01025908*/ extern u8 D_01025908[];
/*01025968*/ extern u8 D_01025968[];
/*010259B0*/ extern GlobalPalette gGlobalPalette[42];
/*01025AAC*/ extern AlphaPalette gAlphaPalette[40];
/*01025BA0*/ extern _11B300UnkStruct1 D_01025BA0[29];
/*01025CFC*/ extern u8 D_01025CFC[];

#endif
