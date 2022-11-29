#ifndef _EDL_H_
#define _EDL_H_

#include "common.h"

s32 decompressEDL(u8 *src, u8 *dst);
void allocacheEDL(u8 **handle, s32 size);
void func_80081688(u8** handle, s32 id);
void func_80081760(u8 **handle, s32 id, u8 *dst);

#endif