#ifndef _24610_H_
#define _24610_H_

#include "common.h"

void setupDrawMask(void);
void drawSprite(s32 spritenum, u16 sectnum, s32 distance);
void drawTileScaled(f32 x, f32 y, f32 scalex, f32 scaley, u16 tileid, s32);
void func_80028F04(u8 r1, u8 g1, u8 b1, u8 r2, u8 g2, u8 b2);
void func_8002900C(u8 r1, u8 g1, u8 b1, u8 r2, u8 g2, u8 b2, u8 a);
void func_80029130(u8 r1, u8 g1, u8 b1, u8 r2, u8 g2, u8 b2);
void func_80029238(u8 r1, u8 g1, u8 b1, u8 r2, u8 g2, u8 b2, u8 a);

/*TODO: Why are the following variables declared unsigned when used outside of 24610.c*/
extern u8 D_801385F0;
extern u16 D_80168810;
extern u16 D_80119A9C;

#endif
