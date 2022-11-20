#ifndef _COMMON_H_
#define _COMMON_H_

#define FALSE 0
#define TRUE 1

#define LITTLE_ENDIAN   0
#define BIG_ENDIAN      1

#ifdef TARGET_N64
#define BYTE_ORDER      BIG_ENDIAN
#else
#define BYTE_ORDER      LITTLE_ENDIAN
#endif

#include "ultra64.h"
#include "types.h"
#include "include_asm.h"

#endif