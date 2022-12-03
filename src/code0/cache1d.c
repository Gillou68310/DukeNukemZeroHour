#include "common.h"
#include "code0/4600.h"
#include "code0/cache1d.h"

#define MAXCACHEOBJECTS 2048

typedef struct
{
    u8 **hand;
    s32 leng;
    u8 *lock;
} cactype;

/*data*/
/*800DD3F0*/ u8 gCacheLock[2] = {200, 200};
/*800DD3F4*/ static s32 _cachesize = 0;
/*800DD3F8*/ static s32 _cachecount = 0;
/*800DD3FC*/ static u8 _zerochar = 0;
/*800DD400*/ static u8 *_cachestart = NULL;
/*800DD404*/ s32 gCacheNum = 0;

/*.comm*/
/*800FF540*/ cactype gCache[MAXCACHEOBJECTS] ALIGNED(16);
/*8012F920*/ s32 gLockRecip[200] ALIGNED(8);

/*.text*/

/*8002A2B0*/
void initCache(u8 *dacachestart, s32 dacachesize)
{
    s32 i;

    for (i = 0; i < MAXCACHEOBJECTS; i++)
    {
        if (gCache[i].hand)
            *gCache[i].hand = NULL;
        gCache[i].hand = NULL;
        gCache[i].lock = &_zerochar;
        gCache[i].leng = 0;
    }

    for (i = 1; i < 200; i++)
    {
        gLockRecip[i] = (1 << 28) / (200 - i);
    }

    _cachestart = dacachestart;
    _cachesize = dacachesize;

    gCache[0].leng = _cachesize;
    gCache[0].lock = &_zerochar;
    gCacheNum = 1;
}

/*8002A3A0*/
STATIC s8 _alloCache(u8 **newhandle, u32 newbytes, u8 *newlockptr);
INCLUDE_ASM(s32, "src/code0/cache1d", _alloCache);

/*8002A7BC*/
void suckCache(u8 **suckptr)
{
    s32 i;

    for (i = 0; i < gCacheNum; i++)
    {
        if (gCache[i].hand == suckptr)
        {
            if (*gCache[i].lock)
                *gCache[i].hand = 0;
            gCache[i].lock = &_zerochar;
            gCache[i].hand = 0;

            if ((i > 0) && (*gCache[i - 1].lock == 0))
            {
                gCache[i - 1].leng += gCache[i].leng;
                gCacheNum--;
                Bmemcpy(&gCache[i], &gCache[i + 1], (gCacheNum - i) * sizeof(cactype));
            }
            else if ((i < gCacheNum - 1) && (*gCache[i + 1].lock == 0))
            {
                gCache[i + 1].leng += gCache[i].leng;
                gCacheNum--;
                Bmemcpy(&gCache[i], &gCache[i + 1], (gCacheNum - i) * sizeof(cactype));
            }
        }
    }
}

INCLUDE_ASM(s32, "src/code0/cache1d", func_8002A9A0);

INCLUDE_ASM(s32, "src/code0/cache1d", func_8002AAC0);

INCLUDE_ASM(s32, "src/code0/cache1d", func_8002AAEC);

/*8002AC70*/
void ageCache(void)
{
    s32 cnt;

    for (cnt = 0; cnt < gCacheNum; cnt++)
    {
        if (((*gCache[cnt].lock - 2) & 255) < 198)
        {
            (*gCache[cnt].lock)--;
        }
    }
}

/*8002ACD4*/
void alloCache(u8 **newhandle, u32 newbytes, u8 *newlockptr)
{
    while ((_alloCache(newhandle, newbytes, newlockptr)) == 0)
    {
        ageCache();
    }
}

/*8002AD3C*/
static void reportAndExit(char *errormessage)
{
    printf("Cachesize = %ld\n", _cachesize);
    printf("Cacnum = %ld\n", gCacheNum);
    printf("ERROR: %s", errormessage);
    exit(0);
}

/*8002AD44*/
s32 func_8002AD44(void)
{
    s32 i;
    s32 size;

    size = _cachesize;

    for (i = 0; i < gCacheNum; i++)
    {
        if (gCache[i].lock != &_zerochar)
            size -= gCache[i].leng;
    }

    return size;
}
