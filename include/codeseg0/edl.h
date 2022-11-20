#ifndef _EDL_H_
#define _EDL_H_

#include "common.h"

s32 decompressEDL(u8 *src, u8 *dst);
void allocacheEDL(u8 **handle, s32 size);
void func_80081688(s32 *, s32);

#endif