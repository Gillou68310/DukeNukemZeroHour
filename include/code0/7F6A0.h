#ifndef _7F6A0_H_
#define _7F6A0_H_

#include "common.h"

typedef struct
{
    /*0x00*/ s32 unk0;
    /*0x04*/ s32 unk4;
    /*0x08*/ s32 unk8;
    /*0x0C*/ s32 unkC;
    /*0x10*/ s32 unk10;
} _7F6A0UnkStruct1;

void func_8007EF70(void);
void func_8007F050(void);
void func_8007EAA0(void *, s32, s32); /*memset*/

/*800DFA90*/ extern _7F6A0UnkStruct1 D_800DFA90;
/*800DFB08*/ extern _7F6A0UnkStruct1 D_800DFB08;

#endif
