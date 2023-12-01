#ifndef _EDL_H_
#define _EDL_H_

#include "common.h"

typedef struct
{
    u8 *romstart;
    u8 *romend;
    u8 **handle;
    s32 *offset;
} edlUnkStruct1;

#define EDL_FILE_MAX_SIZE 0x5B108

s32 decompressEDL(void *src, void *dst);
void allocacheEDL(void *handle, s32 size);
void edl_80081688(void *handle, s32 id);
void edl_80081760(void *handle, s32 id, void *dst);
u8 *edl_80081840(s16 id, s16 off);

extern edlUnkStruct1 D_800E0D18[32];

#endif
