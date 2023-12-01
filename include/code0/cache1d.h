#ifndef _CACHE1D_H_
#define _CACHE1D_H_

#include "common.h"

void initCache(u8 *dacachestart, s32 dacachesize);
void suckCache(void *suckptr);
void cache1d_8002AAC0(void);
void ageCache(void);
void alloCache(void *newhandle, u32 newbytes, u8 *newlockptr);
void cache1d_8002AAEC(void);
s32 getRemainingCacheSize(void);

extern s32 gCacheNum;
extern u8 gCacheLock[2];

#endif
