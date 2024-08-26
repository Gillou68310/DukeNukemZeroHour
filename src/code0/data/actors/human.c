#include "common.h"
#include "code0/FDE0.h"

/*.data*/

/*800D9B90*/
static _FDE0UnkStruct1 D_800D9B90[0x10] = {
    { 0.0f, 0.0f, 0.0f, { 0x41, 0x5F, 0x6A, 0xE8, 0x40, 0x84, 0xA, 0x13, 0x40, 0x86, 0x88, 0xE3 }, -1, },
    { 0.0f, 2.825f, 0.0f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0 },
    { 0.2475f, 2.6325f, -0.0225f, { 0xC2, 1, 0xA4, 0xF7, 0x40, 0x22, 0xD9, 0xBE, 0xC0, 0x97, 0xAB, 0x22 }, 1, },
    { 0.3375f, 1.6425f, -0.09f, { 0x41, 0xB2, 0x66, 0x66, 0, 0, 0, 0, 0, 0, 0, 0 }, 2, },
    { 0.18f, 0.45f, 0.09f, { 0xC0, 0x90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 3 },
    { -0.2475f, 2.6325f, -0.0225f, { 0x40, 0x13, 0x33, 0x33, 0, 0, 0, 0, 0, 0, 0, 0 }, 1, },
    { -0.3375f, 1.6425f, -0.09f, { 0x42, 0x8D, 0x99, 0x9A, 0, 0, 0, 0, 0, 0, 0, 0 }, 5, },
    { -0.18f, 0.45f, 0.09f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 6 },
    { 0.0f, 2.9925f, -0.045f, { 0xC0, 0xAD, 0x94, 0x31, 0x41, 0x18, 0xB0, 0xA9, 0xBF, 0x69, 0x15, 0x6A }, 1, },
    { 0.0f, 4.275f, 0.1575f, { 0xBF, 0x61, 0x49, 0xB6, 0xC1, 0x55, 0xF2, 0x13, 0xC0, 0x6C, 0x99, 7 }, 8, },
    { 0.5175f, 3.87f, 0.225f, { 0x41, 0xC6, 0xB1, 0xC4, 0xC0, 0x8D, 0x8C, 0x93, 0xC1, 0x34, 0x8F, 0xC5 }, 8, },
    { 0.81f, 3.195f, 0.225f, { 0xC2, 0xA6, 0xF7, 0xA8, 0xC2, 0xF4, 0xC0, 0, 0x42, 0xF5, 0x16, 4 }, 0xA, },
    { 0.8f, 2.3f, 0.05f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0xB },
    { -0.5175f, 3.87f, 0.225f, { 0xBD, 0x79, 0x33, 0xAE, 0x41, 0x57, 0xEE, 0x63, 0x41, 0x8D, 0x29, 0x5F }, 8, },
    { -0.81f, 3.195f, 0.225f, { 0xC2, 0x8A, 0, 0xD, 0x43, 0x34, 0, 0, 0x43, 0x34, 0, 0 }, 0xD, },
    { -0.8f, 2.3f, 0.05f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0xE },
};

/*800D9D50*/
static _FDE0UnkStruct1 D_800D9D50[0x10] = {
    { 0.0f, 0.0f, 0.0f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, -1 },
    { 0.0f, 2.98f, -0.05f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0 },
    { 0.26f, 2.56f, 0.1f, { 0xC1, 0xE9, 0x3D, 0x3C, 0x40, 0xFF, 0x87, 1, 0xC1, 0x2E, 0x24, 0xB }, 1, },
    { 0.37f, 1.49f, 0.06f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 2 },
    { 0.36f, 0.48f, 0.13f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 3 },
    { -0.26f, 2.56f, 0.1f, { 0x41, 0xC2, 0xC, 0x4A, 0xBF, 0xD8, 0xEA, 0x9E, 0x40, 0x99, 0x20, 0xC5 }, 1, },
    { -0.37f, 1.49f, 0.0599999f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 5 },
    { -0.36f, 0.48f, 0.13f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 6 },
    { 1.86265e-9f, 3.03f, -0.09f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 1 },
    { 0.0f, 4.05f, 0.04f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 8 },
    { 0.39f, 3.76f, 0.07f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 8 },
    { 0.6f, 3.07f, 0.18f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0xA },
    { 0.65f, 2.15f, 0.0f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0xB },
    { -0.39f, 3.76f, 0.07f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 8 },
    { -0.6f, 3.07f, 0.18f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0xD },
    { -0.66f, 2.15f, 0.0f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0xE },
};

/*800D9F10*/
static _FDE0UnkStruct1 D_800D9F10[0x10] = {
    { 0.0f, 0.0f, 0.0f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, -1 },
    { 0.01f, 3.02f, -0.09f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0 },
    { 0.19f, 2.67f, 0.05f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 1 },
    { 0.37f, 1.5f, 0.08f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 2 },
    { 0.37f, 0.5f, 0.13f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 3 },
    { -0.18f, 2.67f, 0.05f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 1 },
    { -0.37f, 1.5f, 0.08f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 5 },
    { -0.37f, 0.5f, 0.14f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 6 },
    { 0.0f, 3.01f, -0.07f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 1 },
    { 0.0f, 4.07f, 0.06f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 8 },
    { 0.4f, 3.69f, 0.09f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 8 },
    { 0.6f, 3.1f, 0.18f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0xA },
    { 0.63f, 2.11f, 0.0f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0xB },
    { -0.38f, 3.7f, 0.09f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 8 },
    { -0.6f, 3.1f, 0.18f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0xD },
    { -0.63f, 2.11f, 0.0f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0xE },
};

/*800DA0D0*/ _FDE0UnkStruct2 gDukeNukemActor = {0, ARRAY_COUNT(gDukeNukemModelList), gDukeNukemModelList, D_800D9B90};
/*800DA0DC*/ _FDE0UnkStruct2 gCowboyDukeActor = {0, ARRAY_COUNT(gCowboyDukeModelList), gCowboyDukeModelList, D_800D9B90};
/*800DA0E8*/ _FDE0UnkStruct2 gVictorianDukeActor = {0, ARRAY_COUNT(gVictorianDukeModelList), gVictorianDukeModelList, D_800D9B90};
/*800DA0F4*/ _FDE0UnkStruct2 gPoshDukeActor = {0, ARRAY_COUNT(gPoshDukeModelList), gPoshDukeModelList, D_800D9B90};
/*800DA100*/ _FDE0UnkStruct2 gApocalypseDukeActor = {0, ARRAY_COUNT(gApocalypseDukeModelList), gApocalypseDukeModelList, D_800D9B90};
/*800DA10C*/ _FDE0UnkStruct2 gBattleDressDukeActor = {0, ARRAY_COUNT(gBattleDressDukeModelList), gBattleDressDukeModelList, D_800D9B90};
/*800DA118*/ _FDE0UnkStruct2 gDogTagDukeActor = {0, ARRAY_COUNT(gDogTagDukeModelList), gDogTagDukeModelList, D_800D9B90};
/*800DA124*/ _FDE0UnkStruct2 gEvilDukeActor = {0, ARRAY_COUNT(gEvilDukeModelList), gEvilDukeModelList, D_800D9B90};
/*800DA130*/ _FDE0UnkStruct2 gXterminatorActor = {0, ARRAY_COUNT(gXterminatorModelList), gXterminatorModelList, D_800D9B90};
/*800DA13C*/ _FDE0UnkStruct2 gMarineActor = {0, ARRAY_COUNT(gMarineModelList), gMarineModelList, D_800D9B90};
/*800DA148*/ _FDE0UnkStruct2 gSergeantActor = {0, ARRAY_COUNT(gSergeantModelList), gSergeantModelList, D_800D9B90};
/*800DA154*/ _FDE0UnkStruct2 gRipperActor = {0, ARRAY_COUNT(gRipperModelList), gRipperModelList, D_800D9B90};
/*800DA160*/ _FDE0UnkStruct2 gSheriffActor = {0, ARRAY_COUNT(gSheriffModelList), gSheriffModelList, D_800D9D50};
/*800DA16C*/ _FDE0UnkStruct2 gCusterActor = {0, ARRAY_COUNT(gCusterModelList), gCusterModelList, D_800D9B90};
/*800DA178*/ _FDE0UnkStruct2 gMarshallActor = {0, ARRAY_COUNT(gMarshallModelList), gMarshallModelList, D_800D9D50};
/*800DA184*/ _FDE0UnkStruct2 gSquawActor = {0, ARRAY_COUNT(gSquawModelList), gSquawModelList, D_800D9D50};
/*800DA190*/ _FDE0UnkStruct2 gSurvivorActor = {0, ARRAY_COUNT(gSurvivorModelList), gSurvivorModelList, D_800D9F10};
/*800DA19C*/ _FDE0UnkStruct2 gKimberlyStrokesActor = {0, ARRAY_COUNT(gKimberlyStrokesModelList), gKimberlyStrokesModelList, D_800D9F10};
