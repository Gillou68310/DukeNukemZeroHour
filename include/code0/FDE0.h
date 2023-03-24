#ifndef _FDE0_H_
#define _FDE0_H_

#include "common.h"
#include "code0/code0.h"
#include "code0/modelinfo.h"

void func_8000F1E0(void);
/*Skip declaration so it's called with s32 instead*/
/*void func_8000F3C4(s16 r1, s16 g1, s16 b1, s16 r2, s16 g2, s16 b2);*/
void func_80011700(ModelInfo *model);
void func_80012174(void);
void func_80012318(void);
void func_80013FFC(code0unkStruct10 *);
code0unkStruct10 *func_80014040(s16 );

extern s32 D_800BD788;

#endif
