#ifndef _COMMON_H_
#define _COMMON_H_

#define SYS_LITTLE_ENDIAN 0
#define SYS_BIG_ENDIAN 1

#ifdef TARGET_N64
#include "ultra64.h"
#include "macros.h"
#include "include_asm.h"

#define FALSE 0
#define TRUE 1

#define SYS_ENDIAN SYS_BIG_ENDIAN

#define printf(ARGS...)
#define exit(A) while(1)

#define DECL_STATIC_SEG_SYM(A) \
        extern u8 A ## _STATIC_START[]

#define GET_STATIC_SEG_SYM(A) \
        ((intptr_t)gStaticSegment + (intptr_t)A ## _STATIC_START)

typedef u32 uintptr_t;
typedef s32 intptr_t;
#else
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define SYS_ENDIAN SYS_LITTLE_ENDIAN
#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#define SYS_ENDIAN SYS_BIG_ENDIAN
#else
#error Platform not supported
#endif

#define DECL_STATIC_SEG_SYM(A)
#define GET_STATIC_SEG_SYM(A) (A)

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef long long s64;
typedef float f32;
typedef double f64;

#define ALIGNED(A)
#endif

#include "types.h"

#define CLAMP_MAX(A, B) \
    (((A) > B) ? B : A)

#define CLAMP_MIN(A, B) \
    (((A) < B) ? B : A)

#define ARRAY_COUNT(arr) \
    (s32)(sizeof(arr) / sizeof(arr[0]))

#define PI 3.14159265359

#endif
