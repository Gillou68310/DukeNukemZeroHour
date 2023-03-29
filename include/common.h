#ifndef _COMMON_H_
#define _COMMON_H_

#define FALSE 0
#define TRUE 1

#define LITTLE_ENDIAN 0
#define BIG_ENDIAN 1

#define CLAMP_MAX(A, B) \
    (((A) > B) ? B : A)

#define CLAMP_MIN(A, B) \
    (((A) < B) ? B : A)

#ifdef TARGET_N64
#define BYTE_ORDER BIG_ENDIAN
#define printf(ARGS...)
#define exit(A) while(1)

#define DECL_STATIC_SEG_SYM(A) \
    extern u8 A ## _STATIC_START[]

#define GET_STATIC_SEG_SYM(A) \
    ((intptr_t)gStaticSegment + (intptr_t)A ## _STATIC_START)

#else
#define BYTE_ORDER LITTLE_ENDIAN
#define DECL_STATIC_SEG_SYM(A)
#define GET_STATIC_SEG_SYM(A) (A)
#include <stdio.h>
#include <stdlib.h>
#endif

#include "ultra64.h"
#include "macros.h"
#include "types.h"
#include "include_asm.h"

#endif
