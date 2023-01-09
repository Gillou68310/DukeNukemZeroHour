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
#define GFX_TASKS 2

void func_80000450(void);
void func_80000610(void);
void func_80000624(ProcPointer proc);
void func_80000C74(void);
void boot(void);
void readRom(u8 *segStart, u8 *romStart, s32 size);
void func_80000A94(void);
void func_80000C74(void);
void func_80001CFC(void);
void func_80001F40(void);
void func_80001FAC(void);
void func_80002014(s32, s32, s32, s32);
void func_80002390(void);

extern s32 gScreenWidth;
extern s32 gScreenHeight;
extern s32 D_800BD3E8;
extern u8 D_800BD3F8;
extern s8 D_800BD3F9;
extern s32 gGfxTaskIndex;

extern char ***gpKeyStrInfo;
extern s16 *gpRadaRang;
extern _11B300UnkStruct1 *D_8012F6E4;
extern Gfx *gDisplaylist[GFX_TASKS];
extern char **gpWeaponStrInfo;
extern u8 *gStaticSegment;
extern u8 *gDepthBuffer;
extern Vtx *gpVertex;
extern s32 D_8016D178;
extern Vtx *gVertex[GFX_TASKS];
extern char **gpActionStrInfo;
extern OSMesgQueue gDmaMessageQ;
extern MsgStrInfo *gpMsgStrInfo;
extern s16 *gpSinTable;
extern char **gpMapStrInfo;
extern OSSched gScheduler;
extern TileInfo *gpTileInfo;
extern OSScTask gGfxTask[GFX_TASKS];
extern MapInfo *gpMapInfo;
extern Gfx *gpDisplaylist;
extern Dynamic *gpDynamic;
extern _11D520UnkStruct1 *D_801ACBD8;

#endif
