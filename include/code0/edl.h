#ifndef _EDL_H_
#define _EDL_H_

#include "common.h"

s32 decompressEDL(void *src, void *dst);
void allocacheEDL(void *handle, s32 size);
void edl_80081688(void *handle, s32 id);
void edl_80081760(void *handle, s32 id, void *dst);
u8 *edl_80081840(s16 id, s16 off);

#endif
