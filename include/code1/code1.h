#ifndef _CODE1_H_
#define _CODE1_H_

#include "common.h"
#include "static/119280.h"

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

#ifdef _CODE1_C_
#define _extern
#else
#define _extern extern
#endif

/*801CC8CA*/ _extern s16 D_801CC8CA;
/*801CC930*/  extern s32 D_801CC930[];
/*801CD96C*/ _extern u8 *D_801CD96C;
/*801CDAD0*/ _extern ControlMapping *gpControlPreset;
/*801CDB00*/ _extern char **gpLicenceStrInfo;
/*801CDB4C*/ _extern s32 D_801CDB4C;
/*801CDC65*/ _extern u8 D_801CDC65;
/*801CE4C6*/ _extern u16 D_801CE4C6[4];
/*801CE4EA*/ _extern u16 gPerspNorm;
/*801CE5AC*/ _extern u16 D_801CE5AC;
/*801CE5B0*/ _extern Position gPosition;
/*801CE5D4*/ _extern char **gpCreditStrInfo;
/*801CE5D8*/ _extern s32 D_801CE5D8;
/*801CE5E8*/ _extern u8 *D_801CE5E8;

#undef _extern

#endif
