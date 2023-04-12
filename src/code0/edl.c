#include "common.h"
#include "code0/main.h"
#include "code0/4600.h"
#include "code0/cache1d.h"
#include "code0/edl.h"
#include "code1/code1.h"

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
    s32 *offset;
} edlUnkStruct1;

extern u8 files_1009A60_ROM_START[];
extern u8 files_1009A60_ROM_END[];
extern u8 files_10271A0_ROM_START[];
extern u8 files_10271A0_ROM_END[];
extern u8 files_1041D90_ROM_START[];
extern u8 files_1041D90_ROM_END[];
extern u8 files_105ADA0_ROM_START[];
extern u8 files_105ADA0_ROM_END[];
extern u8 files_106D8B0_ROM_START[];
extern u8 files_106D8B0_ROM_END[];
extern u8 files_1057DF0_ROM_START[];
extern u8 files_1057DF0_ROM_END[];
extern u8 files_1081080_ROM_START[];
extern u8 files_1081080_ROM_END[];
extern u8 files_1095D20_ROM_START[];
extern u8 files_1095D20_ROM_END[];
extern u8 files_10A4BF0_ROM_START[];
extern u8 files_10A4BF0_ROM_END[];
extern u8 files_10B6DC0_ROM_START[];
extern u8 files_10B6DC0_ROM_END[];
extern u8 files_10C6040_ROM_START[];
extern u8 files_10C6040_ROM_END[];
extern u8 files_10DA3B0_ROM_START[];
extern u8 files_10DA3B0_ROM_END[];
extern u8 files_10DAB40_ROM_START[];
extern u8 files_10DAB40_ROM_END[];
extern u8 files_10DC260_ROM_START[];
extern u8 files_10DC260_ROM_END[];
extern u8 files_10E8750_ROM_START[];
extern u8 files_10E8750_ROM_END[];
extern u8 files_11437F0_ROM_START[];
extern u8 files_11437F0_ROM_END[];
extern u8 files_11736E0_ROM_START[];
extern u8 files_11736E0_ROM_END[];
extern u8 files_1175AD0_ROM_START[];
extern u8 files_1175AD0_ROM_END[];
extern u8 files_1175ED0_ROM_START[];
extern u8 files_1175ED0_ROM_END[];
extern u8 files_1176420_ROM_START[];
extern u8 files_1176420_ROM_END[];
extern u8 files_117AD40_ROM_START[];
extern u8 files_117AD40_ROM_END[];
extern u8 files_117B0C0_ROM_START[];
extern u8 files_117B0C0_ROM_END[];
extern u8 files_117B140_ROM_START[];
extern u8 files_117B140_ROM_END[];
extern u8 files_117B1F0_ROM_START[];
extern u8 files_117B1F0_ROM_END[];
extern u8 files_117A400_ROM_START[];
extern u8 files_117A400_ROM_END[];
extern u8 files_117AAA0_ROM_START[];
extern u8 files_117AAA0_ROM_END[];
extern u8 files_117AB20_ROM_START[];
extern u8 files_117AB20_ROM_END[];
extern u8 files_117AB30_ROM_START[];
extern u8 files_117AB30_ROM_END[];
extern u8 files_117CB90_ROM_START[];
extern u8 files_117CB90_ROM_END[];
extern u8 files_1189460_ROM_START[];
extern u8 files_1189460_ROM_END[];

/*data*/

/*800E0B40*/
static u8 D_800E0B40[32] = {
    0,
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    8,
    0xA,
    0xC,
    0xE,
    0x10,
    0x14,
    0x18,
    0x1C,
    0x20,
    0x28,
    0x30,
    0x38,
    0x40,
    0x50,
    0x60,
    0x70,
    0x80,
    0xA0,
    0xC0,
    0xE0,
    0xFF,
    0,
    0,
    0,
};

/*800E0B60*/
static u8 D_800E0B60[32] = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    1,
    1,
    1,
    1,
    2,
    2,
    2,
    2,
    3,
    3,
    3,
    3,
    4,
    4,
    4,
    4,
    5,
    5,
    5,
    5,
    0,
    0,
    0,
    0,
};

/*800E0B80*/
static u16 D_800E0B80[32] = {
    0,
    1,
    2,
    3,
    4,
    6,
    8,
    0xC,
    0x10,
    0x18,
    0x20,
    0x30,
    0x40,
    0x60,
    0x80,
    0xC0,
    0x100,
    0x180,
    0x200,
    0x300,
    0x400,
    0x600,
    0x800,
    0xC00,
    0x1000,
    0x1800,
    0x2000,
    0x3000,
    0x4000,
    0x6000,
    0,
    0,
};

/*800E0BC0*/
static u8 D_800E0BC0[32] = {
    1,
    1,
    2,
    2,
    3,
    3,
    4,
    4,
    5,
    5,
    6,
    6,
    7,
    7,
    8,
    8,
    9,
    9,
    0xA,
    0xA,
    0xB,
    0xB,
    0xC,
    0xC,
    0xD,
    0xD,
    0,
    0,
    0,
    0,
    0,
    0,
};

/*800E0BE0*/
static s32 D_800E0BE0 = 0;

/*800E0BE4*/
static s32 D_800E0BE4[13] = {
    0,
    0x131E,
    0x2D16,
    0x3604,
    0x3814,
    0x3874,
    0x38D4,
    0x3934,
    0x3994,
    0x3A9E,
    0x3C50,
    0x3E02,
    0x3FA4,
};

/*800E0C18*/
static s32 D_800E0C18[64] = {
    0,
    0x60,
    0xC0,
    0x10C,
    0x16C,
    0x1CC,
    0x22C,
    0x28C,
    0x2D8,
    0x338,
    0x384,
    0x3E4,
    0x444,
    0x4A4,
    0x4F0,
    0x550,
    0x5B0,
    0x610,
    0x670,
    0x6D0,
    0x730,
    0x790,
    0x7F0,
    0x850,
    0x8B0,
    0x910,
    0x970,
    0x9D0,
    0xA30,
    0xA90,
    0xAF0,
    0xB50,
    0xBB0,
    0xC10,
    0xC70,
    0xCD0,
    0xD30,
    0xD90,
    0xDF0,
    0xE50,
    0xEB0,
    0xF10,
    0xF70,
    0xFD0,
    0x1030,
    0x1090,
    0x10F0,
    0x1150,
    0x11B0,
    0x1210,
    0x1270,
    0x12D0,
    0x1330,
    0x1390,
    0x13F0,
    0x1450,
    0x14B0,
    0x1510,
    0x1570,
    0x15D0,
    0x1630,
    0x1690,
    0x16F0,
    0x1750,
};

/*800E0D18*/
static edlUnkStruct1 D_800E0D18[32] = {
    { files_1009A60_ROM_START, files_1009A60_ROM_END, NULL, NULL },
    { files_10271A0_ROM_START, files_10271A0_ROM_END, NULL, NULL },
    { files_1041D90_ROM_START, files_1041D90_ROM_END, NULL, NULL },
    { files_105ADA0_ROM_START, files_105ADA0_ROM_END, NULL, NULL },
    { files_106D8B0_ROM_START, files_106D8B0_ROM_END, NULL, NULL },
    { files_1057DF0_ROM_START, files_1057DF0_ROM_END, NULL, NULL },
    { files_1081080_ROM_START, files_1081080_ROM_END, NULL, NULL },
    { files_1095D20_ROM_START, files_1095D20_ROM_END, NULL, NULL },
    { files_10A4BF0_ROM_START, files_10A4BF0_ROM_END, NULL, NULL },
    { files_10B6DC0_ROM_START, files_10B6DC0_ROM_END, NULL, NULL },
    { files_10C6040_ROM_START, files_10C6040_ROM_END, NULL, NULL },
    { files_10DA3B0_ROM_START, files_10DA3B0_ROM_END, NULL, NULL },
    { files_10DAB40_ROM_START, files_10DAB40_ROM_END, NULL, NULL },
    { files_10DC260_ROM_START, files_10DC260_ROM_END, NULL, NULL },
    { files_10E8750_ROM_START, files_10E8750_ROM_END, NULL, NULL },
    { files_11437F0_ROM_START, files_11437F0_ROM_END, NULL, NULL },
    { files_11736E0_ROM_START, files_11736E0_ROM_END, NULL, D_800E0BE4 },
    { files_1175AD0_ROM_START, files_1175AD0_ROM_END, NULL, NULL },
    { files_1175ED0_ROM_START, files_1175ED0_ROM_END, NULL, NULL },
    { files_1176420_ROM_START, files_1176420_ROM_END, NULL, NULL },
    { files_117AD40_ROM_START, files_117AD40_ROM_END, NULL, D_800E0C18 },
    { files_117B0C0_ROM_START, files_117B0C0_ROM_END, NULL, NULL },
    { files_117B140_ROM_START, files_117B140_ROM_END, NULL, NULL },
    { files_117B1F0_ROM_START, files_117B1F0_ROM_END, NULL, NULL },
    { files_117A400_ROM_START, files_117A400_ROM_END, NULL, &D_800E0BE0 },
    { files_117AAA0_ROM_START, files_117AAA0_ROM_END, NULL, NULL },
    { files_117AB20_ROM_START, files_117AB20_ROM_END, NULL, NULL },
    { files_117AB30_ROM_START, files_117AB30_ROM_END, NULL, NULL },
    { files_117CB90_ROM_START, files_117CB90_ROM_END, NULL, NULL },
    { files_1189460_ROM_START, files_1189460_ROM_END, NULL, NULL },
    { NULL, NULL, NULL, NULL },
    { NULL, NULL, NULL, NULL },
};

/*comm*/
/*8012CD90*/ u32 D_8012CD90[288] ALIGNED(16);
/*80168820*/ s32 D_80168820[287] ALIGNED(16);
/*801978A0*/ s32 D_801978A0[288] ALIGNED(16);

/*.text*/
static void parseEDLheader(EDLInfo *info);
static s32 swap(EDLInfo *info, u32 value);

/*800808D0*/
static void decodeEDL0(EDLInfo *info)
{
    u8 *src;
    u8 *dst;
    s32 i;
    s32 size;

    dst = info->dst;
    i = size = info->dsize;
    src = &info->src[12];

    if ((src >= dst) || (dst >= &src[size]))
    {
        for (i = (size-1); i != -1; i--)
            *dst++ = *src++;
    }
    else
    {
        dst = &dst[size-1];
        src = &src[size-1];

        for (i = (size-1); i != -1; i--)
            *dst-- = *src--;
    }
}

/*80080968*/
STATIC void decodeEDL1(EDLInfo *info);
INCLUDE_ASM("nonmatchings/src/code0/edl", decodeEDL1);

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
    if ((info->src[0] == 'E') && (info->src[1] == 'D') && (info->src[2] == 'L'))
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
                info->result = -4;
        }
        else
            info->result = -4;
    }
    else
        info->result = -3;
}

/*8008151C*/
static s32 swap(EDLInfo *info, u32 value)
{
    if (info->file_endian == info->sys_endian)
        return value;
    else
        return (value >> 24) + ((value >> 8) & 0xFF00) + ((value & 0xFF00) << 8) + (value << 24);
}

/*8008155C*/
static s32 getEDLDecompressedSize(u8 *src)
{
    EDLInfo info;

    info.src = src;
    info.sys_endian = BYTE_ORDER;
    parseEDLheader(&info);
    if (info.result == 0)
        return info.dsize;
    else
        return 0;
}

/*80081598*/
s32 decompressEDL(void *src, void *dst)
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
        *handle = dst;
    else
        alloCache(handle, dsize, &gCacheLock[1]);

    info.dst = *handle;
    info.sys_endian = BYTE_ORDER;
    decodeEDL(&info);
}

/*80081660*/
void allocacheEDL(void *handle, s32 size)
{
    alloCache(handle, size + 16, &gCacheLock[1]);
}

/*80081688*/
void edl_80081688(void *handle, s32 id)
{
    s32 size;
    edlUnkStruct1 *info;

    info = &D_800E0D18[id];
    size = info->romend - info->romstart;
    if (size > EDL_FILE_MAX_SIZE)
    {
        while (1);
    }
    readRom(D_801CD96C, info->romstart, size);
    if (isEDL(D_801CD96C) != 0)
    {
        _decompressEDL(handle, D_801CD96C, NULL);
        info->handle = handle;
    }
    else
    {
        alloCache(handle, size, &gCacheLock[1]);
        Bmemcpy(*(u8 **)handle, D_801CD96C, size);
        info->handle = handle;
    }
}

/*80081760*/
void edl_80081760(void *handle, s32 id, void *dst)
{
    s32 size;
    edlUnkStruct1 *info;

    info = &D_800E0D18[id];
    size = info->romend - info->romstart;
    if (size > EDL_FILE_MAX_SIZE)
    {
        while (1);
    }
    readRom(D_801CD96C, info->romstart, size);
    if (isEDL(D_801CD96C) != 0)
    {
        _decompressEDL(handle, D_801CD96C, dst);
        info->handle = handle;
    }
    else
    {
        alloCache(handle, size, &gCacheLock[1]);
        Bmemcpy(*(u8 **)handle, D_801CD96C, size);
        info->handle = handle;
    }
}

/*80081840*/
u8 *edl_80081840(s16 id, s16 off)
{
    s32 *offset = D_800E0D18[id].offset;
    return *D_800E0D18[id].handle + offset[off];
}
