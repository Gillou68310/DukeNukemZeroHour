#include "common.h"
#include "code0/FDE0.h"

/*.data*/

/*800DB7F0*/
static _FDE0UnkStruct1 D_800DB7F0[2] = {
    { 0.00465173f, 0.0f, -0.0618059f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, -1 },
    { 0.112128f, 8.175f, -6.98733f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0 },
};

/*800DB828*/
static _FDE0UnkStruct1 D_800DB828[2] = {
    { 0.0f, 0.0f, 0.0f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, -1 },
    { 0.0f, 0.0f, 0.0f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0 },
};

/*800DB860*/ _FDE0UnkStruct2 gHelicopterActor = {8, ARRAY_COUNT(gHelicopterModelList), gHelicopterModelList, D_800DB7F0};
/*800DB86C*/ _FDE0UnkStruct2 gTankActor = {7, ARRAY_COUNT(gTankModelList), gTankModelList, D_800DB828};
