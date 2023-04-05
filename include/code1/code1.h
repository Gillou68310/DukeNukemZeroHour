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

typedef struct
{
    /*0x00*/ u8 pad[3];
    /*0x03*/ u8 unk3;
    /*0x04*/ u8 pad1;
    /*0x05*/ u8 unk5;
    /*0x06*/ u8 pad2[2];
    /*0x08*/ u8 unk8;
    /*0x09*/ u8 pad3[2];
    /*0x0B*/ u8 unkB;
    /*0x0C*/ u8 unkC;
    /*0x0D*/ u8 pad4[9];
    /*0x16*/ u16 unk16;
    /*0x18*/ u16 mastervol;
    /*0x1A*/ u16 musicvol;
    /*0x1C*/ u16 unk1C;
    /*0x1E*/ u16 unk1E;
    /*0x20*/ u16 unk20;
    /*0x22*/ u16 unk22;
    /*0x24*/ u16 unk24;
    /*0x26*/ u16 unk26;
    /*0x28*/ u16 unk28;
    /*0x2A*/ u16 unk2A;
    /*0x2C*/ u8 pad5[2];
    /*0x2E*/ u16 unk2E[4];
    /*0x36*/ u16 unk36;
    /*0x38*/ u16 unk38;
    /*0x3A*/ u16 unk3A;
    /*0x3C*/ u16 unk3C;
    /*0x3E*/ u16 unk3E;
    /*0x40*/ u16 unk40;
    /*0x42*/ u16 unk42;
    /*0x44*/ u16 unk44;
    /*0x46*/ u16 unk46;
    /*0x48*/ u8 pad6[6];
    /*0x4E*/ u16 unk4E;
    /*0x50*/ u8 unk50;
} code1UnkStruct1;

typedef struct
{
    /*0x0000*/ u8 pad[2];
    /*0x0002*/ s16 unk2;
    /*0x0004*/ u8 pad1[4052];
    /*0x0FD8*/ s32 unkFD8;
    /*0x0FDC*/ s32 unkFDC;
    /*0x0FE0*/ u16 unkFE0;
    /*0x0FE4*/ s32 unkFE4;
    /*0x0FE8*/ code1UnkStruct1 unkFE8;
    /*0x103A*/ u8 unk103A;
    /*0x103C*/ u8 pad3;
} code1UnkStruct2;

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
/*801CC930*/ _extern code1UnkStruct2 D_801CC930;
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
/*801CE498*/ _extern code1UnkStruct1 D_801CE498 ALIGNED(8);
/*801CE4EA*/ _extern u16 gPerspNorm;
/*801CE4EC*/ _extern s16 D_801CE4EC;
/*801CE5AC*/ _extern u16 D_801CE5AC;
/*801CE5B0*/ _extern Position gPosition ALIGNED(8);
/*801CE5D4*/ _extern char **gpCreditStrInfo;
/*801CE5D8*/ _extern s32 D_801CE5D8;
/*801CE5E8*/ _extern u8 *D_801CE5E8;
/*801CE5F0*/ _extern code1UnkStruct2 D_801CE5F0 ALIGNED(16);
/*801CF634*/ _extern s16 D_801CF634;

#undef _extern

#endif
