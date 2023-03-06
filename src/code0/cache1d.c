#include "common.h"
#include "code0/4600.h"
#include "code0/pragmas.h"
#include "code0/cache1d.h"

#define MAXCACHEOBJECTS 2048

#ifdef TARGET_N64
#define reportAndExit(A) _reportAndExit()
#endif

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
static void reportAndExit(char *errormessage);

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
        gLockRecip[i] = (1 << 28) / (200 - i);

    _cachestart = dacachestart;
    _cachesize = dacachesize;

    gCache[0].leng = _cachesize;
    gCache[0].lock = &_zerochar;
    gCacheNum = 1;
}

/*8002A3A0*/
static s8 _alloCache(u8 **newhandle, u32 newbytes, u8 *newlockptr)
{
    s32 i, j, z, zz, bestz, daval, bestval, besto, o1, o2, sucklen, suckz;

    newbytes = ((newbytes+15)&0xfffffff0);

    if ((unsigned)newbytes > (unsigned)_cachesize)
    {
        printf("Cachesize: %ld\n", _cachesize);
        printf("*Newhandle: 0x%x, Newbytes: %ld, *Newlock: %d\n", newhandle, newbytes, *newlockptr);
        reportAndExit("BUFFER TOO BIG TO FIT IN CACHE!");
    }

    if (*newlockptr == 0)
        reportAndExit("ALLOCACHE CALLED WITH LOCK OF 0!");

    if (*newlockptr > 200)
        reportAndExit("ALLOCACHE CALLED WITH LOCK ABOVE 200!");

    //Find best place
    bestval = 0x7fffffff; o1 = _cachesize;
    for (z = gCacheNum-1; z>=0; z--)
    {
        o1 -= gCache[z].leng;
        o2 = o1+newbytes; if (o2 > _cachesize) continue;

        daval = 0;
        for (i = o1, zz = z; i<o2; i += gCache[zz++].leng)
        {
            if (*gCache[zz].lock == 0) continue;
            if (*gCache[zz].lock >= 100) { daval = 0x7fffffff; break; }
            daval += mulscale32((s64)(gCache[zz].leng+65536), (s64)(gLockRecip[*gCache[zz].lock]));
            if (daval >= bestval) break;
        }
        if (daval < bestval)
        {
            bestval = daval; besto = o1; bestz = z;
            if (bestval == 0) break;
        }
    }

    if (bestval == 0x7fffffff)
        return 0; //reportAndExit("CACHE SPACE ALL LOCKED UP!");

    //Suck things out
    for (sucklen = -newbytes, suckz = bestz; sucklen<0; sucklen += gCache[suckz++].leng)
        if (*gCache[suckz].lock) *gCache[suckz].hand = NULL;

    //Remove all blocks except 1
    suckz -= (bestz+1); gCacheNum -= suckz;
    Bmemcpy(&gCache[bestz], &gCache[bestz+suckz], (gCacheNum-bestz)*sizeof(cactype));
    gCache[bestz].hand = newhandle; *newhandle = _cachestart+besto;
    gCache[bestz].leng = newbytes;
    gCache[bestz].lock = newlockptr;
    _cachecount++;

    //Add new empty block if necessary
    if (sucklen <= 0) return 1;

    bestz++;
    if (bestz == gCacheNum)
    {
        gCacheNum++; //if (gCacheNum > MAXCACHEOBJECTS) reportAndExit("Too many objects in cache! (cacnum > MAXCACHEOBJECTS)");
        gCache[bestz].leng = sucklen;
        gCache[bestz].lock = &_zerochar;
        return 1;
    }

    if (*gCache[bestz].lock == 0) { gCache[bestz].leng += sucklen; return 1; }

    gCacheNum++; //if (gCacheNum > MAXCACHEOBJECTS) reportAndExit("Too many objects in cache! (cacnum > MAXCACHEOBJECTS)");
    for (z = gCacheNum-1; z>bestz; z--) gCache[z] = gCache[z-1];
    gCache[bestz].leng = sucklen;
    gCache[bestz].lock = &_zerochar;
    return 1;
}

/*8002A7BC*/
void suckCache(void *suckptr)
{
    s32 i;

    for (i = 0; i < gCacheNum; i++)
    {
        if (gCache[i].hand == suckptr)
        {
            if (*gCache[i].lock)
                *gCache[i].hand = NULL;
            gCache[i].lock = &_zerochar;
            gCache[i].hand = NULL;

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

/*8002A9A0*/
static s8 func_8002A9A0(void)
{
    s32 i;

    for (i = 0; i < gCacheNum; i++)
    {
        if (*gCache[i].lock)
            *gCache[i].hand = NULL;
        gCache[i].lock = &_zerochar;
        gCache[i].hand = NULL;

        if (i > 0)
        {
            if (*gCache[i-1].lock == 0)
            {
                gCache[i-1].leng += gCache[i].leng;
                Bmemcpy(&gCache[i], &gCache[i+1], (--gCacheNum-i)*sizeof(cactype));
                return 1;
            }
        }
    }
    return 0;
}

/*8002AAC0*/
void cache1d_8002AAC0(void)
{
    while (func_8002A9A0() != 0);
}

/*8002AAEC*/
void cache1d_8002AAEC(void)
{
    s32 i, j;

    do
    {
        j = 0;
        for (i = 0; i < gCacheNum; i++)
        {
            if (gCache[i].lock != &gCacheLock[0])
            {
                if (*gCache[i].lock)
                    *gCache[i].hand = NULL;
                gCache[i].lock = &_zerochar;
                gCache[i].hand = NULL;

                if (i > 0)
                {
                    if (gCache[i-1].lock != &gCacheLock[0])
                    {
                        gCache[i-1].leng += gCache[i].leng;
                        Bmemcpy(&gCache[i], &gCache[i+1], (--gCacheNum-i)*sizeof(cactype));
                    }
                }
                j++;
            }
        }
    } while (j >= 2);
}

/*8002AC70*/
void ageCache(void)
{
    s32 cnt;

    for (cnt = 0; cnt < gCacheNum; cnt++)
    {
        if (((*gCache[cnt].lock - 2) & 255) < 198)
            (*gCache[cnt].lock)--;
    }
}

/*8002ACD4*/
void alloCache(void *newhandle, u32 newbytes, u8 *newlockptr)
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
s32 cache1d_8002AD44(void)
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
