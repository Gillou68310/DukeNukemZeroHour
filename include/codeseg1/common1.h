#ifndef _COMMON1_H_
#define _COMMON1_H_

#include "common.h"

typedef struct
{
    f32 xEye;
    f32 yEye;
    f32 zEye;
    f32 xAt;
    f32 yAt;
    f32 zAt;
    f32 xUp;
    f32 yUp;
    f32 zUp;
} Position;

#ifdef _COMMON1_C_
#define _extern
#else
#define _extern extern
#endif

_extern s16 D_801CC8CA;      /*801CC8CA*/
_extern s32 D_801CDB4C;      /*801CDB4C*/
_extern u8 D_801CDC65;       /*801CDC65*/
_extern u16 D_801CE4C6[4];   /*801CE4C6*/
_extern u16 gPerspNorm;      /*801CE4EA*/
_extern u16 D_801CE5AC;      /*801CE5AC*/
_extern Position gPosition;  /*801CE5B0*/

#undef _extern

#endif