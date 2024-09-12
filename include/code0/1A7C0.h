#ifndef _1A7C0_H_
#define _1A7C0_H_

#include "common.h"

void func_80019BC0(void);
void func_8001A1A4(void);
void func_8001B2D0(void);
void drawSky(void);
void drawClouds(void);
void drawDebugString(s16 x, s16 y, char *string);
void drawNumberString(s16 x, s16 y, char *string);
void drawString(s16 x, s16 y, char *string);
void drawString2(s16 x, s16 y, char *string);
void func_8001D238(s32 x, s32 y, u16 tilenum);
void func_8001D128(s32 *x, s32 *y);

#endif
