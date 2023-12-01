#include "common.h"
#ifndef LIBEDL
#include "ld_symbols.h"
#include "code0/main.h"
#include "code0/4600.h"
#include "code0/cache1d.h"
#include "code0/edl.h"
#include "code1/code1.h"
#endif

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

/*data*/

/*800E0B40*/
static u8 _table1[32] = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x0A, 0x0C, 0x0E, 0x10, 0x14, 0x18, 0x1C,
    0x20, 0x28, 0x30, 0x38, 0x40, 0x50, 0x60, 0x70, 0x80, 0xA0, 0xC0, 0xE0, 0xFF, 0x00, 0x00, 0x00,
};

/*800E0B60*/
static u8 _table2[32] = {
    0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2,
    3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 0, 0, 0, 0,
};

/*800E0B80*/
static u16 _table3[30] = {
    0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0006, 0x0008, 0x000C, 0x0010, 0x0018, 0x0020, 0x0030, 0x0040, 0x0060, 0x0080,
    0x00C0, 0x0100, 0x0180, 0x0200, 0x0300, 0x0400, 0x0600, 0x0800, 0x0C00, 0x1000, 0x1800, 0x2000, 0x3000, 0x4000, 0x6000,
};

/*800E0BBC*/
static s8 _table4[36] = {
    0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x2, 0x2, 0x3, 0x3, 0x4, 0x4, 0x5, 0x5, 0x6, 0x6, 0x7, 0x7,
    0x8, 0x8, 0x9, 0x9, 0xA, 0xA, 0xB, 0xB, 0xC, 0xC, 0xD, 0xD, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
};

#ifndef LIBEDL
/*800E0BE0*/
static s32 D_800E0BE0 = 0;

/*800E0BE4*/
static s32 D_800E0BE4[13] = {
    0x0000, 0x131E, 0x2D16, 0x3604, 0x3814, 0x3874, 0x38D4, 0x3934, 0x3994, 0x3A9E, 0x3C50, 0x3E02, 0x3FA4,
};

/*800E0C18*/
static s32 D_800E0C18[64] = {
    0x0000, 0x0060, 0x00C0, 0x010C, 0x016C, 0x01CC, 0x022C, 0x028C, 0x02D8, 0x0338, 0x0384, 0x03E4, 0x0444, 0x04A4, 0x04F0, 0x0550,
    0x05B0, 0x0610, 0x0670, 0x06D0, 0x0730, 0x0790, 0x07F0, 0x0850, 0x08B0, 0x0910, 0x0970, 0x09D0, 0x0A30, 0x0A90, 0x0AF0, 0x0B50,
    0x0BB0, 0x0C10, 0x0C70, 0x0CD0, 0x0D30, 0x0D90, 0x0DF0, 0x0E50, 0x0EB0, 0x0F10, 0x0F70, 0x0FD0, 0x1030, 0x1090, 0x10F0, 0x1150,
    0x11B0, 0x1210, 0x1270, 0x12D0, 0x1330, 0x1390, 0x13F0, 0x1450, 0x14B0, 0x1510, 0x1570, 0x15D0, 0x1630, 0x1690, 0x16F0, 0x1750,
};

/*800E0D18*/
edlUnkStruct1 D_800E0D18[32] = {
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
#endif

/*comm*/
/*8012CD90*/ u32 _what[288] ALIGNED(16);
/*80168820*/ u32 _samp[287] ALIGNED(16);
/*801978A0*/ u32 _when[288] ALIGNED(16);

/*.text*/
static void _parseEDLheader(EDLInfo *info);
static s32 _swap(EDLInfo *info, u32 value);

/*800808D0*/
static void _decodeEDL0(EDLInfo *info)
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

#if SYS_ENDIAN == SYS_BIG_ENDIAN
#define SWAP32(A) A
#else
#define SWAP32(A) _swap(info, A)
#endif

#define GET_BITS_(OUTVAR,BITCOUNT,M) \
    { \
    count -= BITCOUNT; \
    if (count < 0) \
    { \
        OUTVAR = data; \
        data = next; \
        next = SWAP32(*in++); \
        OUTVAR = (OUTVAR + (data << (count + BITCOUNT))) & ((M<<BITCOUNT)-1); \
        data >>= -count; \
        count += 0x20; \
    } \
    else \
    { \
        OUTVAR = data & ((M<<BITCOUNT)-1); \
        data >>= BITCOUNT; \
    } \
    }

/*TODO*/
#define GET_BITS1(OUTVAR,BITCOUNT) GET_BITS_(OUTVAR,BITCOUNT,1)
#define GET_BITS2(OUTVAR,BITCOUNT) GET_BITS_(OUTVAR,BITCOUNT,one)

/*80080968*/
static void _decodeEDL1(EDLInfo *info)
{
    u32 number[0x21];
    u8 sp88[0x400];
    u16 large[0x600];
    u16 small[0x300];
    u16 *sp1694;
    s32 sp169C;
    u32 sp16A4;
    u32 sp16BC;

    u32 i, j, k, l, m, n, o, p, q, r, s;
    s32 count;
    s32 *in;
    u8 *out;
    u32 data, next;
    u8 one;

    u8 *src;
    u8 *ptr1;
    u8 *dst;
    u8 *ptr2;

    src = &info->src[12];
    ptr1 = &src[info->csize] - 1;
    dst = info->dst;
    if ((uintptr_t)ptr1 >= (uintptr_t)dst)
    {
        ptr2 = &info->dst[info->dsize];
        if ((uintptr_t)(ptr2 - 1) >= (uintptr_t)ptr1)
        {
            i = 0;
            ptr1 = ptr2 - info->csize;
            ptr2 = src;
            do
            {
                *ptr1++ = *ptr2++;
                i++;
            } while (i < (u32)info->csize);
            src = &dst[info->dsize] - info->csize;
        }
    }

    in = (s32 *)src;
    data = SWAP32(*in++);
    next = SWAP32(*in++);
    out = info->dst;

    count = 32;
    sp16A4 = 0;
    one = 1; /*FAKEMATCH*/
    do
    {
        GET_BITS1(j, 1);

        /*mode 0 - */
        if (j == 0)
        {
            GET_BITS1(i, 15);

            for (i = i - 1; (s32)i != -1; i--)
            {
                GET_BITS1(j, 8);
                *out++ = j;
            }
        }
        else
        {
            /*mode 1 - tables*/
            sp169C = 1;
            do
            {
                sp1694 = &small[0];
                r = 8;
                if (sp169C-- != 0)
                {
                    sp1694 = &large[0];
                    r = 10;
                }

                GET_BITS1(j, 9);

                /*construct tables*/
                s = j;
                if (j != 0)
                {
                    for (k = 1; k < ARRAY_COUNT(number); k++)
                        number[k] = 0;

                    /*iterate to grab entries*/
                    k = 0;
                    do
                    {
                        GET_BITS1(j, 1);

                        if (j == one)
                            GET_BITS1(sp16A4, 4);

                        _what[k] = sp16A4;
                        number[sp16A4]++;
                        k++;
                    } while (k < s);

                    /*build occurance table*/
                    number[0] = 0;
                    m = 0;
                    for (k = 1; k < 16; k++)
                    {
                        for (l = 0; l < s; l++)
                        {
                            if (_what[l] == k)
                            {
                                _when[m] = l;
                                m++;
                            }
                        }
                    }

                    /*sort nibbles*/
                    m = 0;
                    for (i = 1; i < 16; i++)
                    {
                        for (k = 1; number[i] >= k; k++)
                        {
                            _what[m] = i;
                            m++;
                        }
                    }

                    /*generate bitsample table*/
                    _what[m] = 0;
                    k = 0;
                    m = 0;
                    for (i = _what[0]; _what[m] != 0; i++)
                    {
                        for (p = 0; _what[m] == i; p++, m++)
                        {
                            l = k | (one << i);
                            k++;
                            _samp[m] = 0;

                            do
                            {
                                _samp[m] <<= 1;
                                _samp[m] += (l & 1);
                                l >>= 1;
                            } while (l != one);
                        }
                        k <<= 1;
                    }

                    k = 0;
                    do
                    {
                        sp88[k] = 0;
                        k++;
                    } while (k < (u32)(one << r));

                    m = 0;
                    for (i = 1; i < r; i++)
                    {
                        for (k = 1; number[i] >= k; k++, m++)
                        {
                            j = _samp[m];

                            do
                            {
                                sp1694[j] = (_when[m] << 7) + i;
                                j += (one << i);
                            } while (j < (u32)(one << r));
                        }
                    }

                    n = m;
                    for (; i < 16; i++)
                    {
                        for (k = 1; number[i] >= k; k++, m++)
                        {
                            j = _samp[m];
                            l = _what[m];

                            if (sp88[j & ((one << r) - 1)] < l)
                                sp88[j & ((one << r) - 1)] = l;
                        }
                    }

                    j = 0;
                    k = 0;
                    do
                    {
                        if ((sp88[k] & 0xFF) != 0)
                        {
                            if (((sp88[k] & 0xFF) - r) >= 8)
                            {
                                info->result = -8;
                                return;
                            }
                            sp1694[k] = (j << 7) + ((sp88[k] - r) << 4);
                            j += one << (sp88[k] - r);
                        }
                        k++;
                    } while (k < (u32)(one << r));

                    if (j >= 0x200)
                    {
                        info->result = -9;
                        return;
                    }

                    m = n;
                    i = r;
                    if (i < 16)
                    {
                        u16 *ptr;
                        o = one << i;
                        sp16BC = o - 1;
                        do
                        {
                            for (k = 1; number[i] >= k; k++, m++)
                            {
                                j = _samp[m];
                                l = j >> r;
                                ptr = &sp1694[(sp1694[j & sp16BC] >> 7) + o];
                                j = (sp1694[j & sp16BC] >> 4) & 7;
                                do
                                {
                                    ptr[l] = (_when[m] << 7) + _what[m];
                                    l += one << (_what[m] - r);
                                } while (l < (u32)(one << j));
                            }
                            i++;
                        } while (i < 16);
                    }
                }
            } while (sp169C >= 0);

            /*write data*/
            do
            {
                if (count < 0xF)
                    q = data + (next << count);
                else
                    q = data;

                i = large[(q & 0x3FF)];
                if ((i & 0xF) == 0)
                {
                    u16 *a, *b;
                    j = i >> 7;
                    a = &large[0x400];
                    b = &a[((q >> 10) & ((one << ((i >> 4) & 7)) - 1)) + j];
                    i = b[0];
                }

                GET_BITS1(j, (i & 0xF));

                i >>= 7;
                if (i < 0x100)
                {
                    *out = i;
                    out += 1;
                }
                else if (i != 0x100)
                {
                    j = 0;
                    if (_table2[i-0x101] != 0)
                        GET_BITS2(j, _table2[i-0x101]);

                    dst = _table1; /*FAKEMATCH?*/
                    i = (dst[i-0x101] + j) + 3;
                    if (count < 0xF)
                        q = data + (next << count);
                    else
                        q = data;

                    l = small[q & 0xFF];
                    if ((l & 0xF) == 0)
                    {
                        u16 *a, *b;
                        j = l >> 7;
                        a = &small[0x100];
                        b = &a[((q >> 8) & ((one << ((l >> 4) & 7)) - 1)) + j];
                        l = b[0];
                    }

                    GET_BITS1(j, (l & 0xF));

                    /*pull number of bits*/
                    l >>= 7;
                    j = 0;
                    if (_table4[l] != 0)
                        GET_BITS2(j, _table4[l]);

                    l = _table3[l] + j;
                    ptr2 = (out - l) - 1;
                    if (l == 0)
                    {
                        do
                        {
                            *out++ = *ptr2;
                            i--;
                        } while (i != 0);
                    }
                    else
                    {
                        do
                        {
                            *out++ = *ptr2++;
                            i--;
                        } while (i != 0);
                    }
                }
                else
                    break;
            } while (1);
        }

        /*test EOF*/
        GET_BITS1(j, 1);
    } while (j == 0);
}

/*800813F8*/
static void _decodeEDL(EDLInfo *info)
{
    _parseEDLheader(info);
    if (info->result == 0)
    {
        switch (info->type)
        {
        case 0:
            _decodeEDL0(info);
            break;
        case 1:
            _decodeEDL1(info);
            break;
        }
    }
}

/*80081460*/
static void _parseEDLheader(EDLInfo *info)
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
                info->csize = _swap(info, *(u32 *)&info->src[4]);
                info->dsize = _swap(info, *(u32 *)&info->src[8]);
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
static s32 _swap(EDLInfo *info, u32 value)
{
    if (info->file_endian == info->sys_endian)
        return value;
    else
        return (value >> 24) + ((value >> 8) & 0xFF00) + ((value & 0xFF00) << 8) + (value << 24);
}

/*8008155C*/
static s32 _getEDLDecompressedSize(u8 *src)
{
    EDLInfo info;

    info.src = src;
    info.sys_endian = SYS_ENDIAN;
    _parseEDLheader(&info);
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
    info.sys_endian = SYS_ENDIAN;
    info.dst = dst;
    _decodeEDL(&info);
    return info.result;
}

/*800815CC*/
static s32 _isEDL(u8 *src)
{
    EDLInfo info;

#ifdef AVOID_UB
    info.sys_endian = SYS_ENDIAN;
#endif
    info.src = src;
    info.dst = 0;
    _parseEDLheader(&info);
    return info.result != -3;
}

#ifndef LIBEDL
/*80081600*/
static void _decompressEDL(u8 **handle, u8 *src, u8 *dst)
{
    EDLInfo info;
    s32 dsize;

    info.src = src;
#ifdef AVOID_UB
    info.sys_endian = SYS_ENDIAN;
    _parseEDLheader(&info);
    dsize = info.dsize;
#else
    dsize = *(s32 *)(&info.src[8]);
#endif

    if (dst != NULL)
        *handle = dst;
    else
        alloCache(handle, dsize, &gCacheLock[1]);

    info.dst = *handle;
    info.sys_endian = SYS_ENDIAN;
    _decodeEDL(&info);
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
#ifndef TARGET_N64
    if((info->handle != NULL) && (*info->handle != NULL))
    {
        *(u8**)handle = *info->handle;
        return;
    }
#endif
    size = info->romend - info->romstart;
    if (size > EDL_FILE_MAX_SIZE)
    {
        while (1);
    }
    readRom(D_801CD96C, info->romstart, size);
    if (_isEDL(D_801CD96C) != 0)
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
    if (_isEDL(D_801CD96C) != 0)
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
#endif
