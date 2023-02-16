#ifndef _41940_H_
#define _41940_H_

#include "common.h"
#include "code0/engine.h"
#include "code0/code0.h"

s32 func_80040D40(s32 x1, s32 y1, s32 x2, s32 y2);
s32 func_80040D94(s32 x1, s32 y1, s32 z1, s32 x2, s32 y2, s32 z2);
s16 func_80040E90(s16 ang1, s16 ang2);
void func_80042124(code0UnkStruct3 *, s32);
s32 func_80045E40(s32 spritenum, s32);
s32 func_80045400(s32 x, s32 y, s32 z, s16 sectnum, s32, s32 ang, s32, s32);
void func_800461E8(s32 spritenum, s32, s32);
void func_800494DC(s32 spritenum1, s32, s32 spritenum2, s32);
void func_8004AB6C(s32 spritenum, s32, s32, s32, s32, s32, s32);
void func_8004BC64(s32 x, s32 y, s32 z, s16 sectnum, s32, s32, s32);
void func_8004BD24(s16);
void func_8004BFDC(s32 spritenum, s32, s32 z, s32);
s32 dist(SpriteType *s1, SpriteType *s2);
s32 ldist(SpriteType *s1, SpriteType *s2);
void func_8004D884(void);
void func_8004DC74(void);
void func_8004EA40(s32);
void func_8004E5F8(s16 spritenum, s32, s32, s16);
void func_8004EC38(void);
void func_8004F044(void);
s32 func_8004F4A0(void);
void func_8004FC4C(void);
void func_8004FF08(void);
void func_800502A0(void);
void func_80050408(void);
void func_800504F4(void);
void func_8005087C(void);
void func_80050C14(void);
void func_800514C8(void);
s16 func_80051508(s16 ang1, s32 ang2, s32);
void func_80051568(void);
void func_80057540(SpriteType *, s32, s32, s32);
s16 func_80058934(s32 x, s32 y, s32 z, s16 sectnum, s32);

extern s32 D_800DEE80; /*spritenum?*/
extern s32 D_800DEE9C;
extern s32 D_800DEEA0;
extern s32 D_800DEEA8;
extern s32 D_800DEEAC;
extern s32 D_800DEEB0;
extern s32 D_800DEEB8;
extern s8 D_800DEEE4;
extern s32 D_800DEF1C;
extern s32 D_800DF1A8;
extern s16 D_800DF1AC[4];

#endif
