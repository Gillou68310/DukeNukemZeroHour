#ifndef _4600_H_
#define _4600_H_

#include "common.h"

void scanSectors(s32 posx, s32 posy, s32, f32, s16);
void func_80004A3C(u16 sectnum);
void func_80004B60(u16);
void func_80004C84(void);
void func_80004ECC(u16 sectnum, s32, s32);
void func_80005118(u16 sectnum, s16, s32, s32);
void Bmemcpy(void *dst, void *src, u32 size);
void Bmemset(void *dst, u8 value, u32 size);

extern u16 gVisibleSectors[128];
extern s32 gVisibleSectorCnt;
extern u16 gDrawCeilingList[128];
extern s32 gDrawCeilCnt;
extern u16 gDrawFloorList[128];
extern s32 gDrawFloorCnt;
extern u16 gDrawWallList[256];
extern s32 gDrawWallCnt;

#endif
