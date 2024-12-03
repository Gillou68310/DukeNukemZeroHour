#ifndef _MAIN_H_
#define _MAIN_H_

#include "common.h"
#include "PR/sched.h"
#include "static/tileinfo.h"
#include "static/strinfo.h"
#include "static/mapinfo.h"
#include "static/11B300.h"
#include "static/11D520.h"
#include "code0/code0.h"

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define ASPECT_RATIO (4.0f / 3.0f)

#define GFX_TASKS 2
#define DISPLAY_LIST_SIZE 0x1400

void main_80000450(void);
void main_80000610(void);
void main_80000624(ProcPointer proc);
void main_80000C74(void);
void boot(void);
void readRom(u8 *segStart, u8 *romStart, s32 size);
void main_80000A94(void);
void main_80000C74(void);
void main_80001CFC(void);
void main_80001F40(void);
void main_80001FAC(void);
void allocMemory(s32 width, s32 height, s32 dlist_size, s32 vertex_size);
void main_80002390(void);
void main_80003940(void);

extern s32 gScreenWidth;
extern s32 gScreenHeight;
extern s32 D_800BD3E8;
extern u8 D_800BD3F8;
extern s8 D_800BD3F9;
extern s32 gGfxTaskIndex;

extern char ***gpKeyStrInfo;
extern _11B300UnkStruct1 *D_8012F6E4;
extern Gfx *gDisplayList[GFX_TASKS];
extern char **gpWeaponStrInfo;
extern u8 *gStaticSegment;
extern u8 *gDepthBuffer;
extern Vtx *gpVertexN64;
extern AlphaPalette *gpAlphaPalette;
extern s32 gGfxTime;
extern Vtx *gVertexN64[GFX_TASKS];
extern char **gpActionStrInfo;
extern OSMesgQueue gDmaMessageQ;
extern ObjectiveStrInfo *gpObjectiveStrInfo;
extern char **gpMapStrInfo;
extern OSSched gScheduler;
extern TileInfo *gpTileInfo;
extern MapInfo *gpMapInfo;
extern Gfx *gpDisplayList;
extern Dynamic *gpDynamic;
extern _11D520UnkStruct1 *D_801ACBD8;
extern s32 gDisplayListMaxSize;
extern s32 gVertexN64MaxSize;
extern GlobalPalette *gpGlobalPalette;
extern _11B300UnkStruct2 *D_801C0D70;

#endif
