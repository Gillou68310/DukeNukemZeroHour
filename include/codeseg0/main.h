#ifndef _MAIN_H_
#define _MAIN_H_

#include "common.h"

void func_80000450(void);
void func_80000610(void);
void func_80000624(ProcPointer proc);
void func_80000C74(void);
void boot(void);
void readRom(char *segStart, char *romStart, s32 size);
void func_80000A94(void);
void func_80000C74(void);
void func_80001CFC(void);
void func_80001F40(void);
void func_80001FAC(void);
void func_80002014(s32, s32, s32, s32);
void func_80002390(void);

extern s32 gScreenWidth;
extern s32 gScreenHeight;
extern s32 D_800BD3E8;
extern u8 D_800BD3F8;
extern s8 D_800BD3F9;
extern s32 gGfxTaskIndex;

#endif