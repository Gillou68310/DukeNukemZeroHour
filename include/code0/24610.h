#ifndef _24610_H_
#define _24610_H_

#include "common.h"

void func_80023A10(void);
void func_80023C04(s32 spritenum, u16, s32);
void func_80027C18(f32 x1, f32 y1, f32 x2, f32 y2, u16 tilenum, s32);
void func_80028F04(u8 r1, u8 g1, u8 b1, u8 r2, u8 g2, u8 b2);
void func_8002900C(u8 r1, u8 g1, u8 b1, u8 r2, u8 g2, u8 b2, u8 a);
void func_80029130(u8 r1, u8 g1, u8 b1, u8 r2, u8 g2, u8 b2);
void func_80029238(u8 r1, u8 g1, u8 b1, u8 r2, u8 g2, u8 b2, u8 a);

#ifdef __CTX__
extern s8 D_801385F0;
extern s16 D_80168810;
extern s16 D_80119A9C;
#else
/*TODO: Why are the following variables declared unsigned when used outside of 24610.c*/
extern u8 D_801385F0;
extern u16 D_80168810;
extern u16 D_80119A9C;
#endif

#endif
