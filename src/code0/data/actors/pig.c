#include "common.h"
#include "code0/FDE0.h"

/*.data*/

/*800DA5E0*/
static _FDE0UnkStruct1 D_800DA5E0[0x10] = {
    { 0.0f, 0.0f, 0.0f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, -1 },
    { 0.0f, 2.975f, 0.025f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0 },
    { 0.275f, 2.6625f, 0.15f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 1 },
    { 0.525f, 1.4625f, -0.025f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 2 },
    { 0.525f, 0.5f, 0.15f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 3 },
    { -0.275f, 2.6625f, 0.15f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 1 },
    { -0.525f, 1.4625f, -0.025f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 5 },
    { -0.525f, 0.5f, 0.15f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 6 },
    { 0.0f, 2.975f, 0.025f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 1 },
    { 0.0f, 3.9875f, 0.075f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 8 },
    { 0.7f, 3.725f, 0.425f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 8 },
    { 0.965f, 2.8075f, 0.54f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0xA },
    { 0.995f, 1.89f, 0.21f, { 0xC1, 0x69, 0x1A, 0x37, 0xBF, 0x76, 0x88, 0x48, 0x40, 0x74, 0xAD, 0xAC }, 0xB, },
    { -0.7f, 3.725f, 0.425f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 8 },
    { -0.965f, 2.8075f, 0.54f, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0xD },
    { -1.0f, 1.89f, 0.21f, { 0xC1, 0x6A, 0xB2, 0xFF, 0x3F, 0x78, 0x4B, 0xF5, 0xC0, 0x74, 0xCA, 0x2E }, 0xE, },
};

/*800DA7A0*/ _FDE0UnkStruct2 gPigCopActor = {0, ARRAY_COUNT(gPigCopModelList), gPigCopModelList, D_800DA5E0};
/*800DA7AC*/ _FDE0UnkStruct2 gPigCop1Actor = {0, ARRAY_COUNT(gPigCop1ModelList), gPigCop1ModelList, D_800DA5E0};
/*800DA7B8*/ _FDE0UnkStruct2 gPigCop2Actor = {0, ARRAY_COUNT(gPigCop2ModelList), gPigCop2ModelList, D_800DA5E0};
/*800DA7C4*/ _FDE0UnkStruct2 gPigCop3Actor = {0, ARRAY_COUNT(gPigCop3ModelList), gPigCop3ModelList, D_800DA5E0};
/*800DA7D0*/ _FDE0UnkStruct2 gPigCop4Actor = {0, ARRAY_COUNT(gPigCop4ModelList), gPigCop4ModelList, D_800DA5E0};
/*800DA7DC*/ _FDE0UnkStruct2 gRiotPigActor = {0, ARRAY_COUNT(gRiotPigModelList), gRiotPigModelList, D_800DA5E0};
/*800DA7E8*/ _FDE0UnkStruct2 gRiotPig1Actor = {0, ARRAY_COUNT(gRiotPig1ModelList), gRiotPig1ModelList, D_800DA5E0};
/*800DA7F4*/ _FDE0UnkStruct2 gRiotPig2Actor = {0, ARRAY_COUNT(gRiotPig2ModelList), gRiotPig2ModelList, D_800DA5E0};
/*800DA800*/ _FDE0UnkStruct2 gRiotPig3Actor = {0, ARRAY_COUNT(gRiotPig3ModelList), gRiotPig3ModelList, D_800DA5E0};
/*800DA80C*/ _FDE0UnkStruct2 gRiotPig4Actor = {0, ARRAY_COUNT(gRiotPig4ModelList), gRiotPig4ModelList, D_800DA5E0};
/*800DA818*/ _FDE0UnkStruct2 gRoadHogActor = {0, ARRAY_COUNT(gRoadHogModelList), gRoadHogModelList, D_800DA5E0};
/*800DA824*/ _FDE0UnkStruct2 gRoadHog1Actor = {0, ARRAY_COUNT(gRoadHog1ModelList), gRoadHog1ModelList, D_800DA5E0};
/*800DA830*/ _FDE0UnkStruct2 gRoadHog2Actor = {0, ARRAY_COUNT(gRoadHog2ModelList), gRoadHog2ModelList, D_800DA5E0};
/*800DA83C*/ _FDE0UnkStruct2 gRoadHog3Actor = {0, ARRAY_COUNT(gRoadHog3ModelList), gRoadHog3ModelList, D_800DA5E0};
/*800DA848*/ _FDE0UnkStruct2 gRoadHog4Actor = {0, ARRAY_COUNT(gRoadHog4ModelList), gRoadHog4ModelList, D_800DA5E0};
/*800DA854*/ _FDE0UnkStruct2 gWarPigActor = {0, ARRAY_COUNT(gWarPigModelList), gWarPigModelList, D_800DA5E0};
/*800DA860*/ _FDE0UnkStruct2 gWarPig1Actor = {0, ARRAY_COUNT(gWarPig1ModelList), gWarPig1ModelList, D_800DA5E0};
/*800DA86C*/ _FDE0UnkStruct2 gWarPig2Actor = {0, ARRAY_COUNT(gWarPig2ModelList), gWarPig2ModelList, D_800DA5E0};
/*800DA878*/ _FDE0UnkStruct2 gWarPig3Actor = {0, ARRAY_COUNT(gWarPig3ModelList), gWarPig3ModelList, D_800DA5E0};
/*800DA884*/ _FDE0UnkStruct2 gWarPig4Actor = {0, ARRAY_COUNT(gWarPig4ModelList), gWarPig4ModelList, D_800DA5E0};
/*800DA890*/ _FDE0UnkStruct2 gCowboyGruntActor = {0, ARRAY_COUNT(gCowboyGruntModelList), gCowboyGruntModelList, D_800DA5E0};
/*800DA89C*/ _FDE0UnkStruct2 gCowboyGrunt1Actor = {0, ARRAY_COUNT(gCowboyGrunt1ModelList), gCowboyGrunt1ModelList, D_800DA5E0};
/*800DA8A8*/ _FDE0UnkStruct2 gCowboyGrunt2Actor = {0, ARRAY_COUNT(gCowboyGrunt2ModelList), gCowboyGrunt2ModelList, D_800DA5E0};
/*800DA8B4*/ _FDE0UnkStruct2 gCowboyGrunt3Actor = {0, ARRAY_COUNT(gCowboyGrunt3ModelList), gCowboyGrunt3ModelList, D_800DA5E0};
/*800DA8C0*/ _FDE0UnkStruct2 gCowboyGrunt4Actor = {0, ARRAY_COUNT(gCowboyGrunt4ModelList), gCowboyGrunt4ModelList, D_800DA5E0};
/*800DA8CC*/ _FDE0UnkStruct2 gSavageGruntActor = {0, ARRAY_COUNT(gSavageGruntModelList), gSavageGruntModelList, D_800DA5E0};
/*800DA8D8*/ _FDE0UnkStruct2 gSavageGrunt1Actor = {0, ARRAY_COUNT(gSavageGrunt1ModelList), gSavageGrunt1ModelList, D_800DA5E0};
/*800DA8E4*/ _FDE0UnkStruct2 gSavageGrunt2Actor = {0, ARRAY_COUNT(gSavageGrunt2ModelList), gSavageGrunt2ModelList, D_800DA5E0};
/*800DA8F0*/ _FDE0UnkStruct2 gSavageGrunt3Actor = {0, ARRAY_COUNT(gSavageGrunt3ModelList), gSavageGrunt3ModelList, D_800DA5E0};
/*800DA8FC*/ _FDE0UnkStruct2 gSavageGrunt4Actor = {0, ARRAY_COUNT(gSavageGrunt4ModelList), gSavageGrunt4ModelList, D_800DA5E0};
/*800DA908*/ _FDE0UnkStruct2 gCapitalistPigActor = {0, ARRAY_COUNT(gCapitalistPigModelList), gCapitalistPigModelList, D_800DA5E0};
/*800DA914*/ _FDE0UnkStruct2 gCapitalistPig1Actor = {0, ARRAY_COUNT(gCapitalistPig1ModelList), gCapitalistPig1ModelList, D_800DA5E0};
/*800DA920*/ _FDE0UnkStruct2 gCapitalistPig2Actor = {0, ARRAY_COUNT(gCapitalistPig2ModelList), gCapitalistPig2ModelList, D_800DA5E0};
/*800DA92C*/ _FDE0UnkStruct2 gCapitalistPig3Actor = {0, ARRAY_COUNT(gCapitalistPig3ModelList), gCapitalistPig3ModelList, D_800DA5E0};
/*800DA938*/ _FDE0UnkStruct2 gCapitalistPig4Actor = {0, ARRAY_COUNT(gCapitalistPig4ModelList), gCapitalistPig4ModelList, D_800DA5E0};
/*800DA944*/ _FDE0UnkStruct2 gSoldierGruntActor = {0, ARRAY_COUNT(gSoldierGruntModelList), gSoldierGruntModelList, D_800DA5E0};
/*800DA950*/ _FDE0UnkStruct2 gSoldierGrunt1Actor = {0, ARRAY_COUNT(gSoldierGrunt1ModelList), gSoldierGrunt1ModelList, D_800DA5E0};
/*800DA95C*/ _FDE0UnkStruct2 gSoldierGrunt2Actor = {0, ARRAY_COUNT(gSoldierGrunt2ModelList), gSoldierGrunt2ModelList, D_800DA5E0};
/*800DA968*/ _FDE0UnkStruct2 gSoldierGrunt3Actor = {0, ARRAY_COUNT(gSoldierGrunt3ModelList), gSoldierGrunt3ModelList, D_800DA5E0};
/*800DA974*/ _FDE0UnkStruct2 gSoldierGrunt4Actor = {0, ARRAY_COUNT(gSoldierGrunt4ModelList), gSoldierGrunt4ModelList, D_800DA5E0};
