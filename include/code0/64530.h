#ifndef _64530_H_
#define _64530_H_

#include "common.h"
#include "code0/engine.h"

void func_80064AA0(void);
void func_80064DE0(SectorType *sec, s16 shade, s16 pal);
void moveEffectors(void);
void func_80068E0C(s16 sectnum);
void func_80068E9C(void);
void func_80069160(void);
void func_800698E8(void);
void func_80069E50(void);

extern u8 D_800DF585;
extern u8 D_800DF2F0;
extern s8 D_800DF2F4[MAXSECTORS];
extern u8 D_800DF590;
extern u8 D_800DF591;

#endif
