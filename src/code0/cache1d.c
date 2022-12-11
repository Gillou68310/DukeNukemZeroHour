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
/*800DD3F4*/ static s32 cachesize = 0;
/*800DD3F8*/ static s32 cachecount = 0;
/*800DD3FC*/ static u8 zerochar = 0;
/*800DD400*/ static u8 *cachestart = NULL;
/*800DD404*/ s32 gCacNum = 0;

/*.comm*/
/*800FF540*/ cactype gCac[MAXCACHEOBJECTS];
/*8012F920*/ s32 gLockRecip[200];

/*.text*/

/*8002A2B0*/
void initcache(u8 *dacachestart, s32 dacachesize)
{
    s32 i;

    for (i = 0; i < MAXCACHEOBJECTS; i++)
    {
        if (gCac[i].hand)
            *gCac[i].hand = NULL;
        gCac[i].hand = NULL;
        gCac[i].lock = &zerochar;
        gCac[i].leng = 0;
    }

    for (i = 1; i < 200; i++)
    {
        gLockRecip[i] = (1 << 28) / (200 - i);
    }

    cachestart = dacachestart;
    cachesize = dacachesize;

    gCac[0].leng = cachesize;
    gCac[0].lock = &zerochar;
    gCacNum = 1;
}

/*8002A3A0*/
static s8 _allocache(u8 **newhandle, u32 newbytes, u8 *newlockptr);
INCLUDE_ASM(s32, "src/code0/cache1d", _allocache);

/*8002A7BC*/
void suckcache(u8 **suckptr)
{
    s32 i;

    for (i = 0; i < gCacNum; i++)
    {
        if (gCac[i].hand == suckptr)
        {
            if (*gCac[i].lock)
                *gCac[i].hand = 0;
            gCac[i].lock = &zerochar;
            gCac[i].hand = 0;

            if ((i > 0) && (*gCac[i - 1].lock == 0))
            {
                gCac[i - 1].leng += gCac[i].leng;
                gCacNum--;
                Bmemcpy(&gCac[i], &gCac[i + 1], (gCacNum - i) * sizeof(cactype));
            }
            else if ((i < gCacNum - 1) && (*gCac[i + 1].lock == 0))
            {
                gCac[i + 1].leng += gCac[i].leng;
                gCacNum--;
                Bmemcpy(&gCac[i], &gCac[i + 1], (gCacNum - i) * sizeof(cactype));
            }
        }
    }
}

INCLUDE_ASM(s32, "src/code0/cache1d", func_8002A9A0);

INCLUDE_ASM(s32, "src/code0/cache1d", func_8002AAC0);

INCLUDE_ASM(s32, "src/code0/cache1d", func_8002AAEC);

/*8002AC70*/
void agecache(void)
{
    s32 cnt;

    for (cnt = 0; cnt < gCacNum; cnt++)
    {
        if (((*gCac[cnt].lock - 2) & 255) < 198)
        {
            (*gCac[cnt].lock)--;
        }
    }
}

/*8002ACD4*/
void allocache(u8 **newhandle, u32 newbytes, u8 *newlockptr)
{
    while ((_allocache(newhandle, newbytes, newlockptr)) == 0)
    {
        agecache();
    }
}

/*8002AD3C*/
static void reportandexit(char *errormessage)
{
    printf("Cachesize = %ld\n", cachesize);
    printf("Cacnum = %ld\n", gCacNum);
    printf("ERROR: %s", errormessage);
    exit(0);
}

/*8002AD44*/
s32 func_8002AD44(void)
{
    s32 i;
    s32 size;

    size = cachesize;

    for (i = 0; i < gCacNum; i++)
    {
        if (gCac[i].lock != &zerochar)
            size -= gCac[i].leng;
    }

    return size;
}
