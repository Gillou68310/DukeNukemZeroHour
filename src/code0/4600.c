#include "common.h"
#include "code0/2ABE0.h"

#define PI 3.14159265359

/*.text*/

/*80003A00*/
static f32 func_80003A00(f32 arg0)
{
    while (arg0 < 0.0f) arg0 += 2*PI;
    while (arg0 >= 2*PI) arg0 -= 2*PI;
    return arg0;
}

/*80003A74*/
static f32 func_80003A74(f32 arg0, f32 arg1)
{
    if (arg0 <= arg1)
    {
        arg1 -= arg0;
        if (arg1 <= PI)
            return arg1;
        else
            return arg1 - 2*PI;
    }
    else
    {
        arg0 -= arg1;
        if (arg0 <= PI)
            return -arg0;
        else
            return -(arg0 - 2*PI);
    }
}

/*80003B00*/
static f32 func_80003B00(f32 arg0, f32 arg1, f32 arg2, f32 arg3)
{
    return -func_80029FE0(arg3 - arg1, arg2 - arg0) + 4.712388980385;
}

INCLUDE_ASM("nonmatchings/src/code0/4600", func_80003B4C);

INCLUDE_ASM("nonmatchings/src/code0/4600", func_800042D8);

INCLUDE_ASM("nonmatchings/src/code0/4600", func_800043F4);

/*8000491C*/
static void _memcpy(u8 *dst, u8 *src, s32 size)
{
    s32 i;

    for (i = size; i != 0; i--)
    {
        *dst++ = *src++;
    }
}

/*80004944*/
void Bmemcpy(void *dst, void *src, u32 size)
{
    u32 i;

    if (((intptr_t)src & 3) != 0 || ((intptr_t)dst & 3) != 0 || (size & 3) != 0)
    {
        _memcpy(dst, src, size);
    }
    else
    {
        for (i = size >> 2; i != 0; --i)
        {
            *(s32 *)dst = *(s32 *)src;
            dst = (void *)(((s32 *)dst) + 1);
            src = (void *)(((s32 *)src) + 1);
        }
    }
}

/*800049A8*/
static void _memset(u8 *dst, u8 value, s32 size)
{
    s32 i;

    for (i = size; i != 0; i--)
    {
        *dst++ = value;
    }
}

/*800049C8*/
void Bmemset(void *dst, u8 value, u32 size)
{
    u32 i;
    s32 val;

    if (((intptr_t)dst & 3) != 0)
    {
        _memset(dst, value, size);
    }
    else if ((size & 3) != 0)
    {
        _memset(dst, value, size);
    }
    else
    {
        val = value | (value << 8) | (value << 16) | value << 24;
        for (i = size >> 2; i != 0; --i)
        {
            *(s32 *)dst = val;
            dst = (void *)(((s32 *)dst) + 1);
        }
    }
}

INCLUDE_ASM("nonmatchings/src/code0/4600", func_80004A3C);

INCLUDE_ASM("nonmatchings/src/code0/4600", func_80004B60);

INCLUDE_ASM("nonmatchings/src/code0/4600", func_80004C84);

INCLUDE_ASM("nonmatchings/src/code0/4600", func_80004CFC);

INCLUDE_ASM("nonmatchings/src/code0/4600", func_80004ECC);

INCLUDE_ASM("nonmatchings/src/code0/4600", func_80004F14);

INCLUDE_ASM("nonmatchings/src/code0/4600", func_80005118);
