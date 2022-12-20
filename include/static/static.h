#ifndef _STATIC_H_
#define _STATIC_H_

#include "common.h"

typedef struct
{
    /*0x00*/ s16 unk0;
    /*0x02*/ s16 unk2;
    /*0x04*/ char *actor;
    /*0x08*/ u8 unk8;
    /*0x09*/ u8 unk9;
    /*0x0A*/ u8 unkA;
    /*0x0B*/ u8 unkB;
} staticUnkStruct1;

#ifdef _STATIC_C_
#define _extern
#else
#define _extern extern
#endif

/*0102578C*/ _extern staticUnkStruct1 D_0102578C[0x1D];

#undef _extern

#endif
