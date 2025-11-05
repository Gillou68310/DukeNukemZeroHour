#ifndef _EB300_H_
#define _EB300_H_

#include "common.h"
#include "static/mapinfo.h"
#include "code1/code1.h"

s32 random(s16 range);
f32 func_801C1024(f32);
f32 tangentf(f32 angle);
void func_801C10C8(void);
void func_801C1218(f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp, f32 yUp, f32 zUp);
void func_801C146C(void);
void func_801C14D4(void);
void func_801C15CC(void);
void func_801C1950(void);
void func_801C2BE8(code1UnkStruct6 *);
void func_801C3370(void);
void func_801C3524(void);
void func_801C363C(u8 playernum, u16, u8);
void func_801C3E08(void);
void func_801C4B34(void);
void configInitialize(void);
void func_801C542C(void);
void func_801C63CC(void);
void func_801C6560(void);
void func_801C66D8(void);
void func_801C764C(void);
void func_801C899C(void);
void func_801C8F54(void);
void func_801C936C(void);
void func_801C97F0(void);
void func_801C97F8(void);
void func_801C9924(void);
void func_801C9B28(void);
void func_801C9B48(void);
void func_801C9D68(void);
void func_801C9E7C(void);
void func_801C9F74(void);

extern f32 D_801CA144;
extern code1UnkStruct6 D_801CB6E0;
extern code1UnkStruct6 D_801CB870;
extern code1UnkStruct6 D_801CB8F0;
extern MapChapter gMapChapter[MAP_NUM+1];
extern code1UnkStruct5 D_801CB538[9];
extern u8 *D_801CBCE8[12];

#endif
