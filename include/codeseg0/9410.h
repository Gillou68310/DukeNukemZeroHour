#ifndef _9410_H_
#define _9410_H_

#include "common.h"

void func_80008810(s16);
void func_80008E3C(void);
void func_8000EA0C(u8, s16, s16, s16, s32);
void func_8000EB4C(u8, s16, s16, s16, s32);

typedef struct
{
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
} _9410unkStruct1;

/*800BD710*/ extern _9410unkStruct1 D_800BD710[5];

#endif