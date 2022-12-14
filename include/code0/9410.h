#ifndef _9410_H_
#define _9410_H_

#include "common.h"
#include "static/tileinfo.h"

void func_80008810(s16);
void func_80008E3C(void);
void func_8000E04C(void);
void func_8000EA0C(u8, s16, s16, s16, s32);
void func_8000EB4C(u8, s16, s16, s16, s32);
u16 getTileNum(u16 tileid);
u8 *loadTile(u16 tilenum);

typedef struct
{
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
} _9410UnkStruct1;

extern _9410UnkStruct1 D_800BD710[5];

#endif
