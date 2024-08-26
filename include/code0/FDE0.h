#ifndef _FDE0_H_
#define _FDE0_H_

#include "common.h"
#include "code0/code0.h"
#include "code0/data/modelinfo.h"

typedef struct
{
    /*0x00*/ f32 unk0;
    /*0x04*/ f32 unk4;
    /*0x08*/ f32 unk8;
    /*0x0C*/ u8 unused[12];
    /*0x18*/ s16 unk18;
}_FDE0UnkStruct1;

typedef struct {
    /*0x00*/ u8 unk0;
    /*0x02*/ s16 unk2; /*count of unk4/unk8*/
    /*0x04*/ ModelInfo **model_list;
    /*0x08*/ _FDE0UnkStruct1 *unk8;
}_FDE0UnkStruct2;

void func_8000F1E0(void);
/*Skip following declaration so it defaults to s32*/
/*void func_8000F3C4(s16 r1, s16 g1, s16 b1, s16 r2, s16 g2, s16 b2);*/
void func_80011180(void);
void func_80011700(ModelInfo *model);
void func_80011DA8(void);
void func_80012174(void);
void func_80012318(void);
void func_80013FFC(_FDE0UnkStruct2 *);
_FDE0UnkStruct2 *func_80014040(s16 picnum);
void func_80015DE0(s32 spritenum);

extern s32 D_800BD788;

#endif
