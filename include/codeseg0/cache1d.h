#ifndef _CACHE1D_H_
#define _CACHE1D_H_

#include "common.h"

void initcache(u8 *dacachestart, s32 dacachesize);
void suckcache(u8 **suckptr);
void func_8002AAC0(void);
void agecache(void);
void allocache(u8 **newhandle, u32 newbytes, u8 *newlockptr);

/*800DD404*/ extern s32 gCacNum;
/*800DD3F0*/ extern u8 gCacheLock[2];

#endif
