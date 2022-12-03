#ifndef _CACHE1D_H_
#define _CACHE1D_H_

#include "common.h"

void initCache(u8 *dacachestart, s32 dacachesize);
void suckCache(u8 **suckptr);
void func_8002AAC0(void);
void ageCache(void);
void alloCache(u8 **newhandle, u32 newbytes, u8 *newlockptr);

/*800DD404*/ extern s32 gCacheNum;
/*800DD3F0*/ extern u8 gCacheLock[2];

#endif
