#ifndef _AUDIO_H_
#define _AUDIO_H_

#include "common.h"
#include "libmus.h"

void dmaRomToRam(u8 *rom, u8 *ram, s32 size);
void initAudio(void);
void func_80006838(s32, s32);
void func_80006CC0(void);
musHandle func_80007170(u16);
void func_800077F4(s32, s16 spritenum);
void func_80007A44(s32, s16 spritenum, s32);
void func_80007AB8(void);
void func_80008574(s32, u16);
void func_80008710(s16);

#endif
