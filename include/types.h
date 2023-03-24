#ifndef _TYPES_H_
#define _TYPES_H_

#include "common.h"

#ifdef TARGET_N64
typedef u32 uintptr_t;
typedef s32 intptr_t;
#else
#include <stdint.h>
#endif

typedef f32 Matrix4f[4][4];
typedef f32 Vec4f[4];
typedef u8 Addr[];
typedef void (*ProcPointer)(void);

#endif
