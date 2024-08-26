#include "common.h"
#include "code0/FDE0.h"

/*.data*/

/*800DC160*/
static _FDE0UnkStruct1 D_800DC160[2] = {
    { 0.0f, 0.0f, 0.0f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, -1 },
    { 0.0f, 6.365f, 0.985f, { 0xC2, 0xAE, 0, 0, 0x43, 0x34, 0, 0, 0x43, 0x34, 0, 0 }, 0, },
};

/*800DC198*/
static _FDE0UnkStruct1 D_800DC198[3] = {
    { 0.0f, 0.0f, 0.0f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, -1 },
    { 0.0f, 6.365f, 0.985f, { 0xC2, 0xAA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0 },
    { 0.0f, 0.975f, -3.175f, { 0xBE, 0xF7, 0xAC, 0x1D, 0x41, 0xC7, 0xF9, 0xA7, 0xBF, 0xAA, 0x19, 0x11 }, 0, },
};

/*800DC1EC*/ _FDE0UnkStruct2 gShip1Actor = {3, ARRAY_COUNT(gShip1ModelList), gShip1ModelList, D_800DC160};
/*800DC1F8*/ _FDE0UnkStruct2 gShip2Actor = {2, ARRAY_COUNT(gShip2ModelList), gShip2ModelList, D_800DC198};
