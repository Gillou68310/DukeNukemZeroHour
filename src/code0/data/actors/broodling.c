#include "common.h"
#include "code0/FDE0.h"

/*.data*/

/*800DA980*/
static _FDE0UnkStruct1 D_800DA980[8] = {
    { 0.0f, 0.0f, 0.0f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, -1 },
    { 0.0f, 0.625f, -0.01f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0 },
    { -0.345f, 0.665f, -0.09f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 1 },
    { 0.27f, 0.63f, -0.08f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 1 },
    { -0.33f, 0.53f, 0.175f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 1 },
    { 0.24f, 0.55f, 0.17f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 1 },
    { 0.105f, 0.57f, -0.42f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 1 },
    { -0.18f, 0.58f, -0.425f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 1 },
};

/*800DAA60*/ _FDE0UnkStruct2 gBroodlingActor = {4, ARRAY_COUNT(gBroodlingModelList), gBroodlingModelList, D_800DA980};