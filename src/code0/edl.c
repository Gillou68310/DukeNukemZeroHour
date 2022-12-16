#include "common.h"
#include "code0/main.h"
#include "code0/4600.h"
#include "code0/cache1d.h"
#include "code0/edl.h"

typedef struct
{
    u8 *dst;
    u8 *src;
    s32 csize;
    s32 dsize;
    s32 type;
    s32 sys_endian;
    s32 file_endian;
    s32 result;
} EDLInfo;

typedef struct
{
    u8 *romstart;
    u8 *romend;
    u8 **handle;
    u8 *unkC;
} unkFileInfo;

/*data*/
/*800E0B40*/ EXTERN STATIC u8 D_800E0B40[32];
/*800E0B60*/ EXTERN STATIC u8 D_800E0B60[32];
/*800E0B80*/ EXTERN STATIC u16 D_800E0B80[30];
/*800E0BBC*/ EXTERN STATIC u8 D_800E0BBC[32];
/*800E0D18*/ EXTERN STATIC unkFileInfo D_800E0D18[32];

/*comm*/
/*8012CD90*/ u32 D_8012CD90[288] ALIGNED(16);
/*80168820*/ s32 D_80168820[287] ALIGNED(16);
/*801978A0*/ s32 D_801978A0[288] ALIGNED(16);

/*.text*/
static void parseEDLheader(EDLInfo *info);
static s32 swap(EDLInfo *info, u32 value);

STATIC void decodeEDL0(EDLInfo *info);
INCLUDE_ASM(s32, "src/code0/edl", decodeEDL0);

STATIC void decodeEDL1(EDLInfo *info);
INCLUDE_ASM(s32, "src/code0/edl", decodeEDL1);

/*800813F8*/
static void decodeEDL(EDLInfo *info)
{
    parseEDLheader(info);
    if (info->result == 0)
    {
        switch (info->type)
        {
        case 0:
            decodeEDL0(info);
            break;
        case 1:
            decodeEDL1(info);
            break;
        }
    }
}

/*80081460*/
static void parseEDLheader(EDLInfo *info)
{
    if ((info->src[0] == 0x45) && (info->src[1] == 0x44) && (info->src[2] == 0x4C))
    {
        info->file_endian = info->src[3] >> 7;
        info->type = info->src[3] & 0x7F;
        if (info->type < 2)
        {
            if (info->type >= 0)
            {
                info->result = 0;
                info->csize = swap(info, *(u32 *)&info->src[4]);
                info->dsize = swap(info, *(u32 *)&info->src[8]);
            }
            else
            {
                info->result = -4;
            }
        }
        else
        {
            info->result = -4;
        }
    }
    else
    {
        info->result = -3;
    }
}

/*8008151C*/
static s32 swap(EDLInfo *info, u32 value)
{
    if (info->file_endian == info->sys_endian)
    {
        return value;
    }
    else
    {
        return (value >> 24) + ((value >> 8) & 0xFF00) + ((value & 0xFF00) << 8) + (value << 24);
    }
}

/*8008155C*/
static s32 getEDLDecompressedSize(u8 *src)
{
    EDLInfo info;

    info.src = src;
    info.sys_endian = BYTE_ORDER;
    parseEDLheader(&info);
    if (info.result == 0)
    {
        return info.dsize;
    }
    else
    {
        return 0;
    }
}

/*80081598*/
s32 decompressEDL(u8 *src, u8 *dst)
{
    EDLInfo info;

    info.src = src;
    info.sys_endian = BYTE_ORDER;
    info.dst = dst;
    decodeEDL(&info);
    return info.result;
}

/*800815CC*/
static s32 isEDL(u8 *src)
{
    EDLInfo info;

    info.src = src;
    info.dst = 0;
    parseEDLheader(&info);
    return info.result != -3;
}

/*80081600*/
static void _decompressEDL(u8 **handle, u8 *src, u8 *dst)
{
    EDLInfo info;
    s32 dsize;

    info.src = src;
    dsize = *(s32 *)(&info.src[8]);
    if (dst != NULL)
    {
        *handle = dst;
    }
    else
    {
        allocache(handle, dsize, &gCacheLock[1]);
    }
    info.dst = *handle;
    info.sys_endian = BYTE_ORDER;
    decodeEDL(&info);
}

/*80081660*/
void allocacheEDL(u8 **handle, s32 size)
{
    allocache(handle, size + 16, &gCacheLock[1]);
}

/*80081688*/
void func_80081688(u8 **handle, s32 id)
{
    s32 size;
    unkFileInfo *info;

    info = &D_800E0D18[id];
    size = info->romend - info->romstart;
    if (size > 0x5B108)
    {
        while (1)
            ;
    }
    readRom(D_801CD96C, info->romstart, size);
    if (isEDL(D_801CD96C) != 0)
    {
        _decompressEDL(handle, D_801CD96C, NULL);
        info->handle = handle;
    }
    else
    {
        allocache(handle, size, gCacheLock + 1);
        Bmemcpy(*handle, D_801CD96C, size);
        info->handle = handle;
    }
}

/*80081760*/
void func_80081760(u8 **handle, s32 id, u8 *dst)
{
    s32 size;
    unkFileInfo *info;

    info = &D_800E0D18[id];
    size = info->romend - info->romstart;
    if (size > 0x5B108)
    {
        while (1)
            ;
    }
    readRom(D_801CD96C, info->romstart, size);
    if (isEDL(D_801CD96C) != 0)
    {
        _decompressEDL(handle, D_801CD96C, dst);
        info->handle = handle;
        return;
    }
    allocache(handle, size, gCacheLock + 1);
    Bmemcpy(*handle, D_801CD96C, size);
    info->handle = handle;
}

INCLUDE_ASM(s32, "src/code0/edl", func_80081840);
