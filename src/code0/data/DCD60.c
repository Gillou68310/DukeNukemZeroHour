#include "common.h"
#include "code0/data/DA790.h"

/*.data*/

/*800DC160*/
static _DA790UnkStruct1 D_800DC160[2] = {
    { 0.0f, 0.0f, 0.0f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, -1 },
    {
        0.0f,
        6.365f,
        0.985f,
        { 0xC2, 0xAE, 0, 0, 0x43, 0x34, 0, 0, 0x43, 0x34, 0, 0 },
        0,
    },
};

/*800DC198*/
static _DA790UnkStruct1 D_800DC198[3] = {
    { 0.0f, 0.0f, 0.0f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, -1 },
    { 0.0f, 6.365f, 0.985f, { 0xC2, 0xAA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0 },
    {
        0.0f,
        0.975f,
        -3.175f,
        { 0xBE, 0xF7, 0xAC, 0x1D, 0x41, 0xC7, 0xF9, 0xA7, 0xBF, 0xAA, 0x19, 0x11 },
        0,
    },
};

/*800DC1EC*/ _DA790UnkStruct2 D_800DC1EC = {3, ARRAY_COUNT(D_800D7E6C), D_800D7E6C, D_800DC160};
/*800DC1F8*/ _DA790UnkStruct2 D_800DC1F8 = {2, ARRAY_COUNT(D_800D7E74), D_800D7E74, D_800DC198};
