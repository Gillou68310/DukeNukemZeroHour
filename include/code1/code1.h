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

/*801CC7F4*/ _extern s16 D_801CC7F4;
/*801CC8A8*/ _extern s16 D_801CC8A8;
/*801CC8B8*/ _extern s16 D_801CC8B8;
/*801CC8C8*/ _extern s16 D_801CC8C8;
/*801CC8CC*/ _extern s16 D_801CC8CC;
/*801CC8CA*/ _extern s16 D_801CC8CA;
/*801CC924*/ _extern s16 D_801CC924;
/*801CC926*/ _extern s16 D_801CC926;
/*801CC930*/  extern s32 D_801CC930[];
/*801CD96C*/ _extern u8 *D_801CD96C;
/*801CD984*/ _extern s16 D_801CD984;
/*801CDA80*/ _extern s16 D_801CDA80;
/*801CDAD0*/ _extern ControlMapping *gpControlPreset;
/*801CDB00*/ _extern char **gpLicenceStrInfo;
/*801CDB14*/ _extern s16 D_801CDB14;
/*801CDB16*/ _extern s16 D_801CDB16;
/*801CDB48*/ _extern s16 D_801CDB48;
/*801CDB4C*/ _extern s32 D_801CDB4C;
/*801CDBC4*/ _extern s16 D_801CDBC4;
/*801CDBC6*/ _extern s16 D_801CDBC6;
/*801CDBCC*/ _extern u16 D_801CDBCC;
/*801CDC65*/ _extern u8 D_801CDC65;
/*801CDC68*/ _extern s8 *D_801CDC68;
/*801CDC70*/ _extern u8 D_801CDC70[0x800] ALIGNED(16);
/*801CE470*/ _extern u16 D_801CE470;
/*801CE478*/ _extern s16 D_801CE478;
/*801CE480*/ _extern s16 D_801CE480;
/*801CE48C*/ _extern u16 D_801CE48C;
/*801CE4C6*/ _extern u16 D_801CE4C6[4];
/*801CE4EA*/ _extern u16 gPerspNorm;
/*801CE4EC*/ _extern s16 D_801CE4EC;
/*801CE5AC*/ _extern u16 D_801CE5AC;
/*801CE5B0*/ _extern Position gPosition ALIGNED(8);
/*801CE5D4*/ _extern char **gpCreditStrInfo;
/*801CE5D8*/ _extern s32 D_801CE5D8;
/*801CE5E8*/ _extern u8 *D_801CE5E8;
/*801CF634*/ _extern s16 D_801CF634;

#undef _extern

#endif
