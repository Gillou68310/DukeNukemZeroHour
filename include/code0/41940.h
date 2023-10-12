#ifndef _41940_H_
#define _41940_H_

#include "common.h"
#include "code0/engine.h"
#include "code0/code0.h"

/*s32 func_80040D40(s32 x1, s32 y1, s32 x2, s32 y2);*/
s32 func_80040D40();
s32 func_80040D94(s32 x1, s32 y1, s32 z1, s32 x2, s32 y2, s32 z2);
u16 func_80040DFC(s32, s32, f32);
s16 getAngleDelta(s16 currAngle, s16 newAngle);
void func_80042124(code0UnkStruct3 *, s32);
s32 func_80042140(s32 spritenum);
s32 getVar(s32 spritenum, s32 id);
s32 func_80045400(s32 x, s32 y, s32 z, s32 sectnum, s32, s32 ang, s32, s32);
s32 setVar(s32 spritenum, s32 id, s32 value);
void func_80047820(s32 spritenum, s32, s32);
s32 func_800494DC(s32 spritenum1, s32, s32 spritenum2, s32);
void func_8004AB6C(s32 spritenum, s32, s32, s32, s32, s32, s32);
s32 func_8004BC64(s32 x, s32 y, s32 z, s32 sectnum, s32, s32, s32);
s32 func_8004BD24(s32 spritenum);
s32 func_8004BE90(void);
void func_8004BFDC(s32 spritenum, s32, s32 z, s32);
s32 func_8004CC90(s32 spritenum, s32, s32);
s32 func_8004CB3C(s32);
s32 func_8004CE58(SpriteType *spr, s16, s16);
s32 dist(SpriteType *s1, SpriteType *s2);
s32 ldist(SpriteType *s1, SpriteType *s2);
s32 func_8004D304(SpriteType *, s16, s16);
s32 func_8004D7D8(s32 spritenum);
void func_8004D884(void);
void func_8004DC74(void);
s32 func_8004E5F8(s16 spritenum, s32 xvect, s32 yvect, s32 zvect);
s32 func_8004E7F0(s32, s32, s32, s32, s32,
                  s32, s32, s32, s32, s32);
void func_8004EA40(s32 spritenum);
void func_8004EC38(void);
s32 func_8004EFB4(s32 spritenum);
void func_8004F044(void);
void func_8004F31C(void);
s32 func_8004F4A0(s32 spritenum);
void func_8004FAD8(s32 spritenum);
void func_8004FC4C(void);
void func_8004FF08(void);
void func_800502A0(void);
void func_80050408(void);
void func_800504F4(void);
void func_8005087C(void);
void func_80050C14(s32 spritenum);
void func_800514C8(void);
s32 func_80051508(s32 ang1, s32 ang2, s32);
void func_80051568(void);
void func_800533C4(s32, s32 spritenum);
void func_800539A8(s32, s32 spritenum);
void func_80055EC0(s32, s32);
void func_800563D4(s32 spritenum);
void func_80056600(s32 spritenum);
void func_80056A54(s16 spritenum);
void func_800574A4(s32 spritenum);
s32 func_80057540(SpriteType *spr, s16 picnum, s16, s32);
s32 func_80058600(s32 spritenum);
void func_800586B0(s32 spritenum, s32, s32, s32, s32, s32, s32);
void func_800587B8(s32 spritenum, s32, s32, s32, s32, s32, s32);
void func_80058844(s32 spritenum, s32, s32, s16);
s16 func_80058934(s32 x, s32 y, s32 z, s32 sectnum, s32);
void func_80058A14(s16 spritenum, s16 *hitsprite, s32 *hitx, s32 *hity);
s32 func_80058B3C(s32 x1, s32 y1, s32 z1, s32 sectnum, s32 x2, s32 y2, s32 z2, s32);
void func_80058E44(s32 spritenum);

extern s16 D_800DEE70;
extern s32 D_800DEE80; /*spritenum?*/
extern s32 D_800DEE84;
extern s32 D_800DEE88;
extern s32 D_800DEE8C;
extern s32 D_800DEE98;
extern s32 D_800DEE9C;
extern s32 D_800DEEA0;
extern s32 D_800DEEBC;
extern s32 gAiDebugGvar1;
extern s32 gAiDebugGvar2;
extern s32 gAiDebugGvar3;
extern s32 D_800DEEB8;
extern s32 gInvulnerability;
extern u8 D_800DEED0[MAXPLAYERS];
extern u8 D_800DEEE4[MAXPLAYERS];
extern s32 gAutoAim;
extern s32 D_800DEF1C;
extern s32 D_800DF1A8;
extern s16 D_800DF1AC[MAXPLAYERS];
extern s16 D_800DF1B4[9];
extern s16 D_800DF1D0[24][3];

#endif
