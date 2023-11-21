#include "common.h"
#include "code0/data/DA790.h"

/*.data*/

/*800DAA70*/
static _DA790UnkStruct1 D_800DAA70[0x10] = {
    { 0.0f, 0.0f, 0.0f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, -1 },
    { 0.0f, 2.4375f, 0.0f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0 },
    { 0.16875f, 2.45625f, -0.0375f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 1 },
    { 0.35625f, 1.21875f, -0.24375f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 2 },
    { 0.375f, 0.375f, 0.0375f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 3 },
    { -0.16875f, 2.45625f, -0.0375f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 1 },
    { -0.35625f, 1.21875f, -0.24375f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 5 },
    { -0.375f, 0.375f, 0.0375f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 6 },
    { 0.0f, 2.68125f, 0.0f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 1 },
    { 0.40625f, 3.7125f, 0.19375f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 8 },
    { 0.85f, 3.41875f, -0.30625f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 9 },
    { 0.99375f, 3.24375f, -0.84375f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0xA },
    { -0.40625f, 3.7125f, 0.19375f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 8 },
    { -0.85f, 3.41875f, -0.30625f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0xC },
    { -1.01875f, 3.24375f, -0.84375f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0xD },
    { 0.0f, 4.2f, 0.16875f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 8 },
};

/*800DAC30*/
static _DA790UnkStruct1 D_800DAC30[0x10] = {
    { 0.0f, 0.0f, 0.0f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, -1 },
    { 0.0f, 2.41875f, -0.01875f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0 },
    { 0.2625f, 2.3625f, -0.0375f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 1 },
    { 0.375f, 1.18125f, -0.09375f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 2 },
    { 0.45625f, 0.1375f, 0.0f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 3 },
    { -0.225f, 2.38125f, -0.0375f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 1 },
    { -0.39375f, 1.21875f, -0.2625f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 5 },
    { -0.375f, 0.375f, 0.0375f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 6 },
    { 0.0f, 2.6625f, -0.0375f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 1 },
    { 0.5625f, 3.6125f, 0.28125f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 8 },
    { 0.0f, 0.0f, 0.0f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 9 },
    { 0.0f, 0.0f, 0.0f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0xA },
    {
        -0.6f,
        3.65f,
        0.25625f,
        { 0xBE, 0x4C, 0xCC, 0xCD, 0, 0, 0, 0, 0, 0, 0, 0 },
        8,
    },
    { -0.99375f, 3.4125f, -0.225f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0xC },
    { -1.14375f, 3.225f, -0.76875f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0xD },
    { 0.0f, 4.18125f, 0.1875f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 8 },
};

/*800DADF0*/
static _DA790UnkStruct1 D_800DADF0[0x10] = {
    { 0.0f, 0.0f, 0.0f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, -1 },
    { 0.0f, 2.475f, -0.075f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0 },
    { 0.20625f, 2.3625f, -0.05625f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 1 },
    { 0.39375f, 1.21875f, -0.2625f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 2 },
    { 0.375f, 0.375f, 0.0375f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 3 },
    { -0.20625f, 2.3625f, -0.05625f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 1 },
    { -0.39375f, 1.21875f, -0.2625f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 5 },
    { -0.375f, 0.375f, 0.01875f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 6 },
    { 0.0f, 2.71875f, -0.075f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 1 },
    { 0.5125f, 3.63125f, 3.72529e-9f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 8 },
    { 0.99375f, 3.39375f, -0.43125f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 9 },
    { 1.14375f, 3.20625f, -0.99375f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0xA },
    { -0.525f, 3.65625f, 0.075f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 8 },
    { 0.0f, 0.0f, 0.0f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0xC },
    { 0.0f, 0.0f, 0.0f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0xD },
    { 0.0f, 4.1625f, 0.16875f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 8 },
};

/*800DAFB0*/
static _DA790UnkStruct1 D_800DAFB0[0x10] = {
    { 0.0f, 0.0f, 0.0f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, -1 },
    { 0.0f, 2.7f, 0.0f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0 },
    { 0.28125f, 2.11875f, -0.01875f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 1 },
    { 0.3375f, 1.2f, -0.131249f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 2 },
    { 0.3375f, 0.375f, 0.05625f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 3 },
    { -0.28125f, 2.11875f, -0.01875f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 1 },
    { -0.3375f, 1.2f, -0.13125f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 5 },
    { -0.3375f, 0.375f, 0.05625f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 6 },
    { 0.0f, 2.71875f, -0.01875f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 1 },
    { 0.393749f, 3.525f, 0.375f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 8 },
    { 0.825f, 3.2625f, -0.20625f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 9 },
    { 1.03125f, 3.20625f, -0.825f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0xA },
    { -0.39375f, 3.525f, 0.375f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 8 },
    { -0.825f, 3.2625f, -0.20625f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0xC },
    { -1.03125f, 3.20625f, -0.825f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0xD },
    { 0.0f, 3.975f, 0.1875f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 8 },
};

/*800DB170*/
static _DA790UnkStruct1 D_800DB170[0x10] = {
    { 0.0f, 0.0f, 0.0f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, -1 },
    { 0.0f, 2.4375f, 0.0f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0 },
    { 0.20625f, 2.4f, -0.08125f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 1 },
    { 0.39375f, 1.21875f, -0.2625f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 2 },
    { 0.375f, 0.39375f, 0.0375f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 3 },
    { -0.20625f, 2.4f, -0.05625f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 1 },
    { -0.39375f, 1.21875f, -0.2625f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 5 },
    { -0.375f, 0.39375f, 0.0375f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 6 },
    { 0.0f, 2.68125f, 0.0f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 1 },
    { 0.61875f, 3.6375f, 0.20625f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 8 },
    { 0.0f, 0.0f, 0.0f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 9 },
    { 0.0f, 0.0f, 0.0f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0xA },
    { -0.525f, 3.68125f, 0.25625f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 8 },
    { -0.975f, 3.425f, -0.2f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0xC },
    { -1.14375f, 3.225f, -0.75f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0xD },
    { 0.0f, 4.21875f, 0.20625f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 8 },
};

/*800DB330*/
static _DA790UnkStruct1 D_800DB330[0x10] = {
    { 0.0f, 0.0f, 0.0f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, -1 },
    { 0.0f, 3.175f, 0.1f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0 },
    { 0.3f, 3.125f, 0.15f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 1 },
    { 0.375f, 1.675f, -0.15f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 2 },
    { 0.325f, 0.35f, 0.1f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 3 },
    { -0.3f, 3.125f, 0.15f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 1 },
    { -0.375f, 1.675f, -0.15f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 5 },
    { -0.325f, 0.35f, 0.1f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 6 },
    { 0.0f, 3.8f, 0.05f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 1 },
    { 0.3f, 4.65f, 0.25f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 8 },
    { 0.95f, 4.05f, -0.025f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 9 },
    { 1.225f, 3.65f, -0.825f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0xA },
    { -0.3f, 4.65f, 0.25f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 8 },
    { -0.95f, 4.05f, -0.025f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0xC },
    { -1.225f, 3.65f, -0.825f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0xD },
    { 0.0f, 5.0f, 0.25f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 8 },
};

/*800DB4F0*/
static _DA790UnkStruct1 D_800DB4F0[0x10] = {
    { -9.15431f, 0.0f, 4.49082f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, -1 },
    { 0.0f, 2.67675f, 0.0f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0 },
    { 0.22825f, 2.34475f, 0.02075f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 1 },
    { 0.3735f, 1.2035f, -0.249f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 2 },
    { 0.3735f, 0.35275f, 0.0415f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 3 },
    { -0.22825f, 2.34475f, 0.02075f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 1 },
    { -0.3735f, 1.2035f, -0.249f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 5 },
    { -0.3735f, 0.35275f, 0.0415f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 6 },
    { 0.0f, 2.75975f, 0.0f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 1 },
    { 0.47725f, 3.652f, 0.332f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 8 },
    { 0.97525f, 3.071f, 0.2075f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 9 },
    { 1.245f, 2.656f, -0.14525f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0xA },
    { -0.47725f, 3.652f, 0.332f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 8 },
    { -0.97525f, 3.071f, 0.2075f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0xC },
    { -1.245f, 2.656f, -0.14525f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0xD },
    { 0.0f, 4.08775f, 0.22825f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 8 },
};

/*800DB6B0*/ _DA790UnkStruct2 D_800DB6B0 = {9, ARRAY_COUNT(D_800D7B88), D_800D7B88, D_800DAA70};
/*800DB6BC*/ _DA790UnkStruct2 D_800DB6BC = {9, ARRAY_COUNT(D_800D7BC8), D_800D7BC8, D_800DAC30};
/*800DB6C8*/ _DA790UnkStruct2 D_800DB6C8 = {9, ARRAY_COUNT(D_800D7C08), D_800D7C08, D_800DADF0};
/*800DB6D4*/ _DA790UnkStruct2 D_800DB6D4 = {9, ARRAY_COUNT(D_800D7C48), D_800D7C48, D_800DAFB0};
/*800DB6E0*/ _DA790UnkStruct2 D_800DB6E0 = {9, ARRAY_COUNT(D_800D7C88), D_800D7C88, D_800DB170};
/*800DB6EC*/ _DA790UnkStruct2 D_800DB6EC = {9, ARRAY_COUNT(D_800D7CC8), D_800D7CC8, D_800DB330};
/*800DB6F8*/ _DA790UnkStruct2 D_800DB6F8 = {9, ARRAY_COUNT(D_800D7D08), D_800D7D08, D_800DB4F0};
