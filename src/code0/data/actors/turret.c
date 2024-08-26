#include "common.h"
#include "code0/FDE0.h"

/*.data*/

/*800DB710*/
static _FDE0UnkStruct1 D_800DB710[2] = {
    { 0.0f, 0.0f, 0.0f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, -1 },
    { 0.0f, -0.875f, 0.0f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0 },
};

/*800DB748*/
static _FDE0UnkStruct1 D_800DB748[2] = {
    { 0.0f, 1.55f, 0.0f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, -1 },
    { 0.075f, 4.825f, 0.0f, { 0x3F, 0x19, 0x99, 0x9A, 0, 0, 0, 0, 0, 0, 0, 0 }, 0 },
};

/*800DB780*/
static _FDE0UnkStruct1 D_800DB780[2] = {
    { 0.0f, 1.55f, 0.0f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, -1 },
    { 0.0f, 4.9f, -1.275f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0 },
};

/*800DB7B8*/ _FDE0UnkStruct2 gSentryGuns1Actor = {6, ARRAY_COUNT(gSentryGuns1ModelList), gSentryGuns1ModelList, D_800DB710};
/*800DB7C4*/ _FDE0UnkStruct2 gSentryGuns2Actor = {6, ARRAY_COUNT(gSentryGuns2ModelList), gSentryGuns2ModelList, D_800DB710};
/*800DB7D0*/ _FDE0UnkStruct2 gCerberusTurretsActor = {6, ARRAY_COUNT(gCerberusTurretsModelList), gCerberusTurretsModelList, D_800DB748};
/*800DB7DC*/ _FDE0UnkStruct2 gGorgonTurretsActor = {6, ARRAY_COUNT(gGorgonTurretsModelList), gGorgonTurretsModelList, D_800DB780};
