#include "common.h"
#include "ld_symbols.h"
#include "code0/4600.h"
#include "code0/cache1d.h"
#include "code0/edl.h"
#include "code0/main.h"
#include "code0/audio.h"
#include "code0/pragmas.h"
#include "code0/graphics.h"
#include "code0/9410.h"
#include "code0/FDE0.h"
#include "code0/1A7C0.h"
#include "code0/1E7A0.h"
#include "code0/viewport.h"
#include "code0/21500.h"
#include "code0/24610.h"
#include "code0/37090.h"
#include "code0/timer.h"
#include "code0/7BA50.h"
#include "code0/8E670.h"
#include "code0/609D0.h"
#include "code0/64530.h"
#include "code0/41940.h"
#include "code0/debug.h"
#include "code0/87010.h"
#include "code0/94050.h"
#include "code0/95500.h"
#include "code0/A06F0.h"
#include "code1/EB300.h"
#include "code1/code1.h"
#include "static/spinit.h"

#define MAXTILESIZE 32832

typedef struct {
    s16 r;
    s16 g;
    s16 b;
    s16 a;
} Color16;

/*.comm*/
/*800FE404*/ s16 D_800FE404;
/*80105544*/ u32 _displayListRemainingSize;
/*80105708*/ u8 *_pMapBuffer;
/*80106D38*/ u32 gVertexN64Size;
/*80107910*/ s16 gTilemap[MAXTILES] ALIGNED(16);
/*80117D48*/ OSTime D_80117D48;
/*80117D50*/ OSTime D_80117D50;
/*80117D58*/ OSTime D_80117D58;
/*80117D60*/ OSTime D_80117D60;
/*80117E38*/ OSTime D_80117E38;
/*80117E40*/ OSTime D_80117E40;
/*80117E48*/ OSTime D_80117E48;
/*80117E50*/ OSTime D_80117E50;
/*80119A58*/ u32 gDisplayListSize;
/*8012FDA0*/ u8 _tileBuffer[MAXTILESIZE] ALIGNED(16);
/*801385F2*/ u16 D_801385F2; /*perspNorm*/
/*801385F4*/ s16 _floorCeilingVertexCounter;
/*80138694*/ s16 D_80138694;
/*80138798*/ Color16 D_80138798[5] ALIGNED(8); /*MAXPLAYERS?*/
/*8013F930*/ Color16 D_8013F930[MAXPLAYERS] ALIGNED(8);
/*80169580*/ u8 D_80169580[TILENUM] ALIGNED(16);
/*8016A158*/ s32 D_8016A158;
/*80199118*/ s16 D_80199118;
/*80199554*/ s32 _floorCeilingVertexCount;
/*80199946*/ s16 D_80199946;
/*80199954*/ u8 _wallCalcRes;
/*8019996C*/ s32 D_8019996C;
/*801A19A0*/ s16 D_801A19A0[32] ALIGNED(8);
/*801AC9EC*/ s32 D_801AC9EC;
/*801C0D6C*/ s16 D_801C0D6C;

/*.data*/

/*800BD710*/
_9410UnkStruct1 D_800BD710[5] = {
    { 30, 30, 90, 128 },
    { 30, 60, 30, 166 },
    { 0, 0, 0, 200 },
    { 24, 32, 21, 128 },
    { 22, 77, 17, 128 },
};

/*800BD724*/ static u8 *_tileROMAddr = tiles_ROM_START;
static u8 *_unused1 = tiles_ROM_END;
/*800BD72C*/ f32 gMapXpos = 0.0f;
/*800BD730*/ f32 gMapYpos = 256.0f;
/*800BD734*/ f32 gMapZpos = 0.0f;
/*800BD738*/ static u8 _sectorsLock = 200;
/*800BD739*/ static u8 _wallsLock = 200;
/*800BD73A*/ static u8 _spritesLock = 200;
/*800BD73B*/ static u8 _mapLock = 200;
/*800BD73C*/ static u8 _vertexLock = 200;
static s32 _unused2 = 25;
static s32 _unused3 = 0;
/*800BD748*/ s16 D_800BD748 = 0;
/*800BD74A*/ u8 D_800BD74A = 0;
/*800BD74B*/ static u8 D_800BD74B = 0;
/*800BD74C*/ static u8 *_tilemap = _tileBuffer;
/*800BD750*/ static u32 D_800BD750 = 0;

/*.text*/
s32 tileMasks(u16 tileid);
s32 tileMaskt(u16 tileid);
static void _initTiles(void);
static u8 _isDisplayListFull(void);
static void _floorVtxToN64(s32 sectnum);
static void _floorVtxToN64Z(s32 sectnum, s32 z);
static void _ceilingVtxToN64(s32 sectnum);
static void _decompressMap(void);
static void renderPlayerScene(u8 playernum); /*drawRoom?*/
static void func_8000A938(u16 wallnum);
static void _drawWall(u16 wallnum);
static void func_8000B9C0(s16 tilenum);
static s32 func_8000CC54(s32 wallnum);
static void _setupMatrix(void);
static void func_8000EBF0(u8 playernum, u8);
static void _drawWalls(void);
static void _drawFloorCeiling(void);
static void func_8000A184(void);
static void func_8000A634(void);
static void func_8000C8EC(void);

/*80008810*/
void loadMap(s32 mapnum)
{
    s32 i;
    code0UnkStruct5 *ptr;

    MusStop(3, 0);
    cache1d_8002AAEC();
    func_801C14D4();
    gNumSectors = gpMapInfo[mapnum].sectors;
    gNumSprites = gpMapInfo[mapnum].sprites;
    gNumWalls = gpMapInfo[mapnum].walls;
    alloCache(&gpSector, gNumSectors * sizeof(SectorType), &_sectorsLock);
    alloCache(&gpWall, gNumWalls * sizeof(WallType), &_wallsLock);
    alloCache(&gpSprite, MAXSPRITES * sizeof(SpriteType), &_spritesLock);
    Bmemset(gpSprite, 0, MAXSPRITES * sizeof(SpriteType));
    moveSectReset();
    gMapNum = mapnum;
    Bmemset(&D_801A1958, 0, sizeof(D_801A1958));
    alloCache(&_pMapBuffer, gpMapInfo[mapnum].rom_end - gpMapInfo[mapnum].rom_start, &_mapLock);
    readRom(_pMapBuffer, gpMapInfo[mapnum].rom_start, gpMapInfo[mapnum].rom_end - gpMapInfo[mapnum].rom_start);
    initSpriteLists();
    _decompressMap();
    ptr = D_8013B2D0;
    for (i = 0; i < gNumSprites; i++)
    {
        insertSprite(gpSprite[i].sectnum, gpSprite[i].statnum);
        ptr[i].unk4 = 0;
        ptr[i].unk2 = 0;
        D_8013B2D0[i].unk0 = 0;
    }

    func_80019BC0();
    func_80062300();
    func_8008DC24();
    gFog[0].color[0].r = gFog[0].color[1].r = 0x32;
    gFog[0].color[0].g = gFog[0].color[1].g = 0x32;
    gFog[0].color[0].b = gFog[0].color[1].b = 0x46;
    gFog[0].scale[0].nr = gFog[0].scale[1].nr = 0x3DE;
    gFog[0].scale[0].fr = gFog[0].scale[1].fr = 0x3ED;
    gFog[0].unk1E = 0;
    Bmemcpy(&gFog[1], &gFog[0], sizeof(Fog));
    Bmemcpy(&gFog[2], &gFog[0], sizeof(Fog));
    Bmemcpy(&gFog[3], &gFog[0], sizeof(Fog));
    D_801A19EC = 0;
    func_8001DE5C();

    for (i = 0; i < gNumSectors; i++)
    {
        updateCeilZ(i);
        floorUpdateZ(i);
    }

    playMapAudio(gMapNum);
    func_8000EB4C(4, 0, 0, 0, 288);
    func_80094958();
    func_8007AEB4();
    func_80086410();
    main_80001CFC();
    func_800A0E74();
    func_80051568();
    D_800FEA90 = 0;
    D_801AE914 = 0;
    D_800E1748 = -1;
}

/*80008B88*/
static void _decompressMap(void)
{
    s32 i;
    s32 count;
    s32 floorz;
    u8 *addr;

    gMapXpos = gpMapInfo[gMapNum].xpos;
    gMapYpos = gpMapInfo[gMapNum].ypos;
    gMapZpos = gpMapInfo[gMapNum].zpos;

    addr = (u8 *)(gpMapInfo[gMapNum].sector_offset + (intptr_t)_pMapBuffer);

#ifndef TARGET_N64
    if (decompressEDL(addr, gpSector) != 0)
        Bmemcpy(gpSector, addr, gNumSectors * sizeof(SectorType));
#else
    decompressEDL(addr, gpSector);
#endif

    addr = (u8 *)(gpMapInfo[gMapNum].wall_offset + (intptr_t)_pMapBuffer);
#ifndef TARGET_N64
    if (decompressEDL(addr, gpWall) != 0)
        Bmemcpy(gpWall, addr, gNumWalls * sizeof(WallType));
#else
    decompressEDL(addr, gpWall);
#endif

    addr = (u8 *)(gpMapInfo[gMapNum].sprite_offset + (intptr_t)_pMapBuffer);
#ifndef TARGET_N64
    if (decompressEDL(addr, gpSprite) != 0)
        Bmemcpy(gpSprite, addr, gNumSprites * sizeof(SpriteType));
#else
    decompressEDL(addr, gpSprite);
#endif

    count = 0;
    for (i = 0; i < gNumSectors; i++)
    {
        count += gpSector[i].floorvtxnum;
        count += gpSector[i].ceilingvtxnum;
    }

    count *= 3;
    alloCache(&gpSectorVertex, (count * sizeof(Vertex)), &_vertexLock);
#ifndef TARGET_N64
    if (decompressEDL(&_pMapBuffer[0], gpSectorVertex) != 0)
        Bmemcpy(gpSectorVertex, &_pMapBuffer[0], count * sizeof(Vertex));
#else
    decompressEDL(&_pMapBuffer[0], gpSectorVertex);
#endif

    suckCache(&_pMapBuffer);
    _initTiles();

    for (i = 0; i < MAXPLAYERS; i++)
    {
        gPlayer[i].xpos = (2.0f * gMapXpos);
        gPlayer[i].ypos = (2.0f * gMapYpos);
        gPlayer[i].zpos = (32.0f * gMapZpos);
        updateSector(gPlayer[i].xpos, gPlayer[i].ypos, &gPlayer[i].cursectnum);
        floorz = getFlorzOfSlope(gPlayer[i].cursectnum, gPlayer[i].xpos, gPlayer[i].ypos);
        gPlayer[i].zpos = floorz - 0x3900;
        gPlayer[i].ang = gpMapInfo[gMapNum].ang;
    }
}

/*80008E3C*/
void func_80008E3C(void)
{
    char buffer[8];
    s32 difftime;
    s32 playernum;

    initTimer(DRAW_TIMER, "DR");
    startTimer(DRAW_TIMER);
    D_801A6D80 = 0;
    D_8012BBCC = 0;
    D_8012F6F0[0] = 0;
    D_8012F6F0[1] = 0;
    D_8012F6F0[2] = 0;
    D_8012F6F0[3] = 0;
    gPlayerNum = 0;

    for (; gPlayerNum < gPlayerCount; gPlayerNum++)
    {
        setPlayerViewport(gPlayerNum, 0);
        renderPlayerScene(gPlayerNum);
    }

    setDrawMode2D();
    gViewportScaleX = (f32)(gScreenWidth / 2);
    gViewportTransX = (f32)(gScreenWidth / 2);
    gViewportScaleY = (f32)(gScreenHeight / 2);
    gViewportTransY = (f32)(gScreenHeight / 2);
    gDPSetScissor(gpDisplayList++, G_SC_NON_INTERLACE, 0, 0, gScreenWidth, gScreenHeight);

    if (gMultiplayerTimeLimit > 0)
    {
        difftime = (gMultiplayerTimeLimit - gMultiplayerElapsedTime) / 30;
        difftime = CLAMP_MIN(difftime, 0);
        sprintf(buffer, "%02d:%02d", difftime / 60, difftime % 60);

        func_80029130(255, 128, 0, 0, 0, 0);
        if ((gPlayerCount == 3) && (g3pSplitFull == 0))
            drawNumberString(207, 164, buffer);
        else
            drawString(-1, 112, buffer);
    }

    if (!_isDisplayListFull() && gNotPlayback)
    {
        setDrawMode2D();
        debugMenu();
    }

    drawViewportLines();

    if (D_801AE914 != 0)
        func_8000EB4C(4, 0, 0, 0, 196);

    func_8000EBF0(4, 0);

    gDisplayListSize = ((uintptr_t)gpDisplayList - (uintptr_t)gDisplayList[gGfxTaskIndex]) / sizeof(Gfx);
    gVertexN64Size = ((uintptr_t)gpVertexN64 - (uintptr_t)gVertexN64[gGfxTaskIndex]) / sizeof(Vtx);

    for (playernum = 0; playernum < gPlayerCount; playernum++)
        gActor[gActorSpriteMap[gPlayer[playernum].unk4A]].flag &= ~0x100;

    stopTimer(DRAW_TIMER);
}

/*8000921C*/
s32 getDisplayListVertexUsagePercentage(void)
{
    s32 dlist;
    s32 vertex;
    s32 ret;

    dlist = ((uintptr_t)gpDisplayList - (uintptr_t)gDisplayList[gGfxTaskIndex]) / sizeof(Gfx);
    vertex = ((uintptr_t)gpVertexN64 - (uintptr_t)gVertexN64[gGfxTaskIndex]) / sizeof(Vtx);

    dlist = (dlist * 100) / gDisplayListMaxSize;
    vertex = (vertex * 100) / gVertexN64MaxSize;

    if (dlist < vertex)
        ret = vertex;
    else
        ret = dlist;

    return ret;
}

/*80009314*/
static void _setFog(u8 playernum)
{
    Fog *fog;
    s16 i;

    fog = &gFog[playernum];
    if (gPlayer[playernum].unk55 != 0)
    {
        if (fog->unk20 == 0)
        {
            fog->unk20 = 1;
            fog->color[2].r = fog->color[1].r;
            fog->color[2].g = fog->color[1].g;
            fog->color[2].b = fog->color[1].b;
            fog->scale[2].nr = fog->scale[1].nr;
            fog->scale[2].fr = fog->scale[1].fr;
        }

        fog->color[0].r = fog->color[1].r = D_800BD710[D_801A19EC].unk0;
        fog->color[0].g = fog->color[1].g = D_800BD710[D_801A19EC].unk1;
        fog->color[0].b = fog->color[1].b = D_800BD710[D_801A19EC].unk2;
        fog->scale[0].nr = fog->scale[1].nr = 995;
        fog->scale[0].fr = fog->scale[1].fr = 1000;
        fog->unk1E = 0;
    }
    else if (fog->unk20 != 0)
    {
        fog->unk1E = 0;
        fog->unk20 = 0;
        fog->color[0].r = fog->color[1].r = fog->color[2].r;
        fog->color[0].g = fog->color[1].g = fog->color[2].g;
        fog->color[0].b = fog->color[1].b = fog->color[2].b;
        fog->scale[0].nr = fog->scale[1].nr = fog->scale[2].nr;
        fog->scale[0].fr = fog->scale[1].fr = fog->scale[2].fr;
    }

    if ((gPlayer[playernum].unk55 == 0) && (gCheatWeatherConfig == CONFIG_OFF))
    {
        i = gHeadSpriteSect[gPlayer[playernum].cursectnum];
        while (i != -1)
        {
            if (gpSprite[i].picnum == 14)
            {
                fog->color[1].r = gpSprite[i].unk18;
                fog->color[1].g = gpSprite[i].unk1A;
                fog->color[1].b = gpSprite[i].unk1C;
                fog->scale[1].nr = gpSprite[i].hitag;
                fog->scale[1].fr = gpSprite[i].lotag;
                fog->unk1E = gpSprite[i].ang;

                if (fog->unk1E == 0)
                {
                    fog->color[0].r = fog->color[1].r;
                    fog->color[0].g = fog->color[1].g;
                    fog->color[0].b = fog->color[1].b;
                    fog->scale[0].nr = fog->scale[1].nr;
                    fog->scale[0].fr = fog->scale[1].fr;
                }
                break;
            }
            i = gNextSpriteSect[i];
        }
    }

    if (fog->color[0].r < fog->color[1].r)
        fog->color[0].r = MIN(fog->color[1].r, (fog->color[0].r + fog->unk1E));

    if (fog->color[0].r > fog->color[1].r)
        fog->color[0].r = MAX(fog->color[1].r, (fog->color[0].r - fog->unk1E));

    if (fog->color[0].g < fog->color[1].g)
        fog->color[0].g = MIN(fog->color[1].g, (fog->color[0].g + fog->unk1E));

    if (fog->color[0].g > fog->color[1].g)
        fog->color[0].g = MAX(fog->color[1].g, (fog->color[0].g - fog->unk1E));

    if (fog->color[0].b < fog->color[1].b)
        fog->color[0].b = MIN(fog->color[1].b, (fog->color[0].b + fog->unk1E));

    if (fog->color[0].b > fog->color[1].b)
        fog->color[0].b = MAX(fog->color[1].b, (fog->color[0].b - fog->unk1E));

    if (fog->scale[0].nr < fog->scale[1].nr)
        fog->scale[0].nr = MIN(fog->scale[1].nr, (fog->scale[0].nr + CLAMP_MIN(fog->unk1E/8, 1)));

    if (fog->scale[0].nr > fog->scale[1].nr)
        fog->scale[0].nr = MAX(fog->scale[1].nr, (fog->scale[0].nr - CLAMP_MIN(fog->unk1E/8, 1)));

    if (fog->scale[0].fr < fog->scale[1].fr)
        fog->scale[0].fr = MIN(fog->scale[1].fr, (fog->scale[0].fr + CLAMP_MIN(fog->unk1E/8, 1)));

    if (fog->scale[0].fr > fog->scale[1].fr)
        fog->scale[0].fr = MAX(fog->scale[1].fr, (fog->scale[0].fr - CLAMP_MIN(fog->unk1E/8, 1)));

    fog->scale[0].fr = MAX((fog->scale[0].nr + 5), fog->scale[0].fr);
    gDPSetFogColor(gpDisplayList++, fog->color[0].r, fog->color[0].g, fog->color[0].b, 0);
    gSPFogPosition(gpDisplayList++, fog->scale[0].nr, fog->scale[0].fr);
}

/*80009998*/
static s32 _getDisplayListRemainingSize(void)
{
    return gDisplayListMaxSize - ((uintptr_t)gpDisplayList - (uintptr_t)gDisplayList[gGfxTaskIndex]) / sizeof(Gfx);
}

/*800099D0*/
static u8 _isDisplayListFull(void)
{
    s32 size;

    size = ((uintptr_t)gpDisplayList - (uintptr_t)gDisplayList[gGfxTaskIndex]) / sizeof(Gfx);
    size = gDisplayListMaxSize - size;
    _displayListRemainingSize = size;
    return _displayListRemainingSize < 2048;
}

/*80009A14*/
static void renderPlayerScene(u8 playernum)
{
    u8 cond;

    updateSector(gPlayer[playernum].xpos, gPlayer[playernum].ypos, &gPlayer[playernum].cursectnum);
    func_8003DACC();
    _setupMatrix();
    computeFrustumPlanes();
    D_80117D48 = osGetTime();
    scanSectors(gGlobalPosX, gGlobalPosY, gGlobalPosZ, gGlobalAng, gGlobalSectnum);
    D_80117E38 = osGetTime();
    gDPPipeSync(gpDisplayList++);
    gSPDisplayList(gpDisplayList++, D_01001900);
    drawSky();
    initVertexList();
    gSPDisplayList(gpDisplayList++, D_01001900);
    drawClouds();
    grTranslate(&gpDynamic->mtx6, 0.0f, 0.0f, 0.0f);
    grScale(&gpDynamic->mtx8, 0.5f, 0.5f, 0.5f);
    gSPMatrix(gpDisplayList++, OS_K0_TO_PHYSICAL(&gpDynamic->mtx6), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPMatrix(gpDisplayList++, OS_K0_TO_PHYSICAL(&gpDynamic->mtx8), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gpDisplayList++, D_01001900);

    _setFog(playernum);
    gSortSpritesCnt = 0;
    gLastPicnum = -1;
    D_80117D50 = osGetTime();
    func_8000E04C();
    D_80117E40 = osGetTime();
    initVertexList();
    D_80117D58 = osGetTime();
    D_8019996C = 0;
    _drawWalls();
    D_80117E48 = osGetTime();
    initVertexList();
    D_80117D60 = osGetTime();
    _drawFloorCeiling();
    D_80117E50 = osGetTime();

    if (_isDisplayListFull())
        return;

    initVertexList();

    gSPClearGeometryMode(gpDisplayList++, G_CULL_BACK);

    setupDrawMask();
    func_8000A184();
    if (_isDisplayListFull())
        return;

    initVertexList();
    D_800BD788 = 1;
    func_80011DA8();
    D_800BD788 = 0;

    gSPTexture(gpDisplayList++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);

    if (_isDisplayListFull())
        return;

    initVertexList();
    func_8000A634();

    if (_isDisplayListFull())
        return;

    initVertexList();
    func_8000C8EC();

    if (_isDisplayListFull())
        return;

    func_8007BE80();
    func_80086A24();

    if (_isDisplayListFull())
        return;

    func_8001DE9C();

    if (_isDisplayListFull())
        return;

    func_8001EB2C();
    func_80094278();

    if (gMapNum == MAP_THE_RACK)
        func_80094A60();

    if (gMapNum == MAP_NUCLEAR_WINTER)
        func_80094F7C();

    if (_isDisplayListFull())
        return;

    initVertexList();
    func_80012174();

    gSPTexture(gpDisplayList++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);

    if (_isDisplayListFull())
        return;

    func_80012318();

    if (_isDisplayListFull())
        return;

    cond = 0;
    func_8001A1A4();
    func_8001B2D0();

    if (gPlayerCount == 1)
    {
        cond = D_8010A940[playernum].unk2[5] != 0;
        if (gPlayer[playernum].unk52 >= 0)
        {
            if (gPlayer[playernum].unk52 < 2048)
                cond = 1;

            if (gMapNum == MAP_BASE)
            {
                if ((gpSprite[gPlayer[gPlayerNum].unk52 & 0x7FF].hitag == 400) ||
                    (gpSprite[gPlayer[gPlayerNum].unk52 & 0x7FF].hitag == 402))
                    cond = 1;
            }

            if (cond != 0)
                func_8000EA0C(playernum, -D_800BD748, -D_800BD748, -D_800BD748, D_800BD748);
        }
    }

    func_8000EBF0(playernum, cond);

    if (_isDisplayListFull())
        return;

    drawHud();
    D_8016A158 = _getDisplayListRemainingSize();
}

/*8000A070*/
void setDrawMode2D(void)
{
    gDPPipeSync(gpDisplayList++);
    gSPClearGeometryMode(gpDisplayList++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING |
                                          G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gSPSetGeometryMode(gpDisplayList++, G_SHADE | G_SHADING_SMOOTH);
    gDPSetTextureLUT(gpDisplayList++, G_TT_RGBA16);
    gDPSetCombineMode(gpDisplayList++, G_CC_DECALRGBA, G_CC_PASS2);
    gDPSetRenderMode(gpDisplayList++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetAlphaCompare(gpDisplayList++, G_AC_NONE);
    gDPSetTexturePersp(gpDisplayList++, G_TP_NONE);
}

/*8000A174*/
static void func_8000A174(s32 arg0, s32 arg1)
{
    u8 pad[20];
    (void)arg0;
    (void)arg1;
    (void)pad;
}

/*8000A184*/
static void func_8000A184(void)
{
    s16 i;
    s32 j, k, l, m;

    s16 stat[2] = {55, 305};

    D_8012DEFA = 0;
    D_8016D180 = 0;
    D_80199118 = 0;
    D_80105720 = 0;

    for (i = 0; i < ARRAY_COUNT(stat); i++)
    {
        j = gHeadSpriteStat[stat[i]];
        while (j >= 0)
        {
            if (gpSprite[j].cstat & 0x1000)
            {
                if (D_8012DEFA != ARRAY_COUNT(D_801A68D0))
                {
                    D_801A68D0[D_8012DEFA] = j;
                    D_8012DEFA++;
                }
            }
            else
            {
                m = klabs((gGlobalPosX - gpSprite[j].x));
                l = klabs((gGlobalPosY - gpSprite[j].y));
                m = MAX(m, l) + (MIN(m, l) >> 2) + (MIN(m, l) >> 3);
                drawSprite(j, gpSprite[j].sectnum, m);
            }
            j = gNextSpriteStat[j];
        }
    }

    for (k = 0; k < gVisibleSectorCnt; k++)
    {
        j = gHeadSpriteSect[gVisibleSectors[k]];
        while (j >= 0)
        {
            if (gpSprite[j].statnum != 55)
            {
                if (gpSprite[j].statnum != 305)
                {
                    if (gpSprite[j].picnum == 15)
                    {
                        if (D_80199118 < ARRAY_COUNT(D_801A19A0))
                        {
                            D_801A19A0[D_80199118] = j;
                            D_80199118++;
                        }
                    }
                    else
                    {
                        if (!(gpSprite[j].cstat & 0x8000))
                        {
                            if (gpSprite[j].picnum >= 49)
                            {
                                if (gpSprite[j].xrepeat != 0)
                                {
                                    if (gpSprite[j].cstat & 0x1000)
                                    {
                                        if (!(gpSprite[j].cstat & 0x800))
                                        {
                                            if (D_8012DEFA != ARRAY_COUNT(D_801A68D0))
                                            {
                                                D_801A68D0[D_8012DEFA] = j;
                                                D_8012DEFA++;
                                            }
                                        }
                                        else
                                        {
                                            if (D_8016D180 != ARRAY_COUNT(D_801AC8E8))
                                            {
                                                D_801AC8E8[D_8016D180] = j;
                                                D_8016D180++;
                                            }
                                        }
                                    }
                                    else if (!(gpSprite[j].cstat & 0xA02))
                                    {
                                        m = klabs((gGlobalPosX - gpSprite[j].x));
                                        l = klabs((gGlobalPosY - gpSprite[j].y));
                                        m = MAX(m, l) + (MIN(m, l) >> 2) + (MIN(m, l) >> 3);
                                        drawSprite(j, gVisibleSectors[k], m);

                                    }
                                    else if (gpSprite[j].statnum == 109)
                                    {
                                        if (D_80105720 != ARRAY_COUNT(D_800FCBA0))
                                        {
                                            D_800FCBA0[D_80105720] = j;
                                            D_80105720++;
                                        }
                                    }
                                    else
                                    {
                                        if (gSortSpritesCnt != 0x100)
                                        {
                                            m = klabs((gGlobalPosX - gpSprite[j].x));
                                            l = klabs((gGlobalPosY - gpSprite[j].y));
                                            gMaskDrawList[gSortSpritesCnt].dist = MAX(m, l) + (MIN(m, l) >> 2) + (MIN(m, l) >> 3);
                                            gMaskDrawList[gSortSpritesCnt].index = j;
                                            gMaskDrawList[gSortSpritesCnt].sectnum = gVisibleSectors[k];
                                            gSortSpritesCnt++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            j = gNextSpriteSect[j];
        }
    }
}

/*8000A634*/
static void func_8000A634(void)
{
    s32 i;
    s16 wallnum;
    s16 tilenum;

    setupDrawMask();
    func_8000A174(0, gSortSpritesCnt - 1);
    D_800BD74B = 0;

    for (i = 0; i < gSortSpritesCnt; i++)
    {
        if (gMaskDrawList[i].index & 0x8000)
        {
            wallnum = gMaskDrawList[i].index & 0x7FFF;
            tilenum = gpWall[wallnum].overpicnum;
            if ((tilenum == 5300) || (tilenum == 6080))
            {
                if (D_800BD74B == 0)
                {
                    D_800BD74B = 1;
                    gSPSetGeometryMode(gpDisplayList++, G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
                    gSPTexture(gpDisplayList++, 0x7FC0, 0x7FC0, 0, G_TX_RENDERTILE, G_ON);
                }
                initVertexList();
                func_8000DBDC(gpWall[wallnum].pal, gpWall[wallnum].shade);
                setLight1Ligth2Color(0, 0, 0, D_8016A148, D_800FE410, D_80138680);
            }
            else if (D_800BD74B == 1)
            {
                initVertexList();
                D_800BD74B = 0;
                gSPClearGeometryMode(gpDisplayList++, G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
                gSPTexture(gpDisplayList++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
            }
            func_8000A938(wallnum);
        }
        else
        {
            if (D_800BD74B == 1)
            {
                initVertexList();
                D_800BD74B = 0;
                gSPClearGeometryMode(gpDisplayList++, G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
                gSPTexture(gpDisplayList++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
            }
            drawSprite(gMaskDrawList[i].index, gMaskDrawList[i].sectnum, gMaskDrawList[i].dist);
        }
    }
    if (D_800BD74B == 1)
    {
        initVertexList();
        D_800BD74B = 0;
        gSPClearGeometryMode(gpDisplayList++, G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
        gSPTexture(gpDisplayList++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    }
}

/*8000A938*/
static void func_8000A938(u16 wallnum)
{
    u16 tileid;

    tileid = getTileId(gpWall[wallnum].overpicnum);
    if (tileid == 1)
        return;

    if (D_801A2688 != 0)
    {
        D_801A2688 = 0;
        gDPSetAlphaCompare(gpDisplayList++, G_AC_NONE);
        gDPSetTextureLUT(gpDisplayList++, G_TT_RGBA16);
        gDPSetCombineLERP(gpDisplayList++, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT,
                                           0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
    }

    if (gVertexNumber == 0)
    {
        gVertexNumber = 32;
        gVertexBufferIndex = 0;
        gSPVertex(gpDisplayList++, gpVertexN64, 32, 0);
    }
    drawMaskWall(wallnum);
    func_8000CC54(wallnum);

    if (gpTileInfo[tileid].picanm&192)
        tileid += animateOffs(gpWall[wallnum].overpicnum, 0);

    gDPLoadTLUT_pal16(gpDisplayList++, 0, loadTile(tileid));
    gDPLoadTextureBlock_4b(gpDisplayList++, loadTile(tileid)+32, G_IM_FMT_CI,
                           gpTileInfo[tileid].dimx, gpTileInfo[tileid].dimy, 0, 0, 0,
                           tileMasks(tileid), tileMaskt(tileid), 0, 0);


    D_801AC9EC++;
    gSP2Triangles(gpDisplayList++, gVertexBufferIndex, gVertexBufferIndex+1, gVertexBufferIndex+2, gVertexBufferIndex,
                                   gVertexBufferIndex, gVertexBufferIndex+2, gVertexBufferIndex+3, gVertexBufferIndex);

    gLastPicnum = -1;
    gVertexBufferIndex += 4;
    gVertexNumber -= 4;
};

/*8000AEE0*/
static void _drawWall(u16 wallnum)
{
    VertexC *wall;
    s16 sectnum, w;
    s16 a, b, c, d, e, f;
    s16 i, j, k;
    s16 point2;

    wall = gWallVertex;
    point2 = gpWall[wallnum].point2;
    _wallCalcRes = wallCalc(gpWall[wallnum].sectnum, wallnum);

    if (_wallCalcRes & 8)
        D_80138694 = 1;
    else
        D_80138694 = 0;

    if (_wallCalcRes & 1)
        D_800FE404 = 1;
    else
        D_800FE404 = 0;

    if (_wallCalcRes & 2)
        D_801C0D6C = 1;
    else
        D_801C0D6C = 0;

    if (gpWall[wallnum].unk14 == 4)
    {
        sectnum = gpWall[wallnum].sectnum;
        func_8000DBDC(gpSector[sectnum].floorpal, gpSector[sectnum].floorshade);
        d = D_8016A148;
        e = D_800FE410;
        f = D_80138680;
        func_8000DBDC(gpSector[sectnum].ceilingpal, gpSector[sectnum].ceilingshade);
        a = D_8016A148;
        b = D_800FE410;
        c = D_80138680;
    }
    else
    {
        func_8000DBDC(gpWall[wallnum].pal, gpWall[wallnum].shade);
        d = D_8016A148;
        e = D_800FE410;
        f = D_80138680;

        w = wallnum;
        if (gpWall[wallnum].unk14 == 2)
            w = point2;

        if (gpWall[wallnum].unk14 == 3)
        {
            if (gpWall[point2].nextwall != -1)
                w = gpWall[gpWall[point2].nextwall].point2;
            else
                w = point2;
        }

        func_8000DBDC(gpWall[w].pal, gpWall[w].shade);
        a = D_8016A148;
        b = D_800FE410;
        c = D_80138680;
    }
    for (i = 0; i < (D_80138694 + D_800FE404 + D_801C0D6C); i++)
    {
        for (j = 0; j < 2; j++)
        {
            for (k = 0; k < 2; k++)
            {
                gpVertexN64->v.ob[0] = wall->ob[0];
                gpVertexN64->v.ob[1] = wall->ob[1];
                gpVertexN64->v.ob[2] = wall->ob[2];
                gpVertexN64->v.tc[0] = wall->tc[0];
                gpVertexN64->v.tc[1] = wall->tc[1];

                if (j == 0)
                {
                    if ((gpWall[wallnum].unk14 == 4) && (k == 0))
                    {
                        gpVertexN64->v.cn[0] = CLAMP_MAX((gpWall[wallnum].unk1D+a), 0xFF);
                        gpVertexN64->v.cn[1] = CLAMP_MAX((gpWall[wallnum].unk1E+b), 0xFF);
                        gpVertexN64->v.cn[2] = CLAMP_MAX((gpWall[wallnum].unk1F+c), 0xFF);
                    }
                    else
                    {
                        gpVertexN64->v.cn[0] = CLAMP_MAX((gpWall[wallnum].unk1D+d), 0xFF);
                        gpVertexN64->v.cn[1] = CLAMP_MAX((gpWall[wallnum].unk1E+e), 0xFF);
                        gpVertexN64->v.cn[2] = CLAMP_MAX((gpWall[wallnum].unk1F+f), 0xFF);
                    }
                }
                else
                {
                    if ((gpWall[wallnum].unk14 == 4) && (k == 0))
                    {
                        gpVertexN64->v.cn[0] = CLAMP_MAX((gpWall[point2].unk1D+d), 0xFF);
                        gpVertexN64->v.cn[1] = CLAMP_MAX((gpWall[point2].unk1E+e), 0xFF);
                        gpVertexN64->v.cn[2] = CLAMP_MAX((gpWall[point2].unk1F+f), 0xFF);
                    }
                    else
                    {
                        gpVertexN64->v.cn[0] = CLAMP_MAX((gpWall[point2].unk1D+a), 0xFF);
                        gpVertexN64->v.cn[1] = CLAMP_MAX((gpWall[point2].unk1E+b), 0xFF);
                        gpVertexN64->v.cn[2] = CLAMP_MAX((gpWall[point2].unk1F+c), 0xFF);
                    }
                }

                gpVertexN64->v.cn[3] = 0xFF;
                gpVertexN64++;
                wall++;
            }
        }
    }
}

/*8000B570*/
void drawTriangles(s16 arg0)
{
    s16 i;

    for (i = arg0; i > 0; i--)
    {
        if (gVertexNumber == 0)
        {
            gSPVertex(gpDisplayList++, gpVertexList, 30, 0);
            gVertexNumber = 30;
            gVertexBufferIndex = 0;
        }
        gSP1Triangle(gpDisplayList++, gVertexBufferIndex, gVertexBufferIndex+1, gVertexBufferIndex+2, gVertexBufferIndex);
        gVertexBufferIndex += 3;
        gVertexNumber -= 3;
        gpVertexList += 3;
    }
}

/*8000B6A8*/
void func_8000B6A8(s16 arg0)
{
    s16 i;

    for (i = arg0; i > 0; i--)
    {
        if (gVertexNumber == 0)
        {
            gSPVertex(gpDisplayList++, gpVertexList, 32, 0);
            gVertexNumber = 32;
            gVertexBufferIndex = 0;
        }
        gSP2Triangles(gpDisplayList++, gVertexBufferIndex, gVertexBufferIndex+1, gVertexBufferIndex+2, gVertexBufferIndex,
                                       gVertexBufferIndex, gVertexBufferIndex+2, gVertexBufferIndex+3, gVertexBufferIndex);

        gVertexBufferIndex += 4;
        gVertexNumber -= 4;
        gpVertexList += 4;
    }
}

/*8000B830*/
void func_8000B830(s16 arg0)
{
    s16 i;

    for (i = arg0; i > 0; i--)
    {
        if (gVertexNumber == 0)
        {
            gSPVertex(gpDisplayList++, gpVertexList, 32, 0);
            gVertexNumber = 32;
            gVertexBufferIndex = 0;
        }
        gSP2Triangles(gpDisplayList++, gVertexBufferIndex, gVertexBufferIndex+1, gVertexBufferIndex+2, gVertexBufferIndex,
                                       gVertexBufferIndex+1, gVertexBufferIndex+2, gVertexBufferIndex+3, gVertexBufferIndex);

        gVertexBufferIndex += 4;
        gVertexNumber -= 4;
        gpVertexList += 4;
    }
}

/*8000B9C0*/
static void func_8000B9C0(s16 tilenum)
{
    s16 tilenum_;

    if (gCheatFlatShadingConfig != CONFIG_OFF)
        tilenum = 5948;

    tilenum_ = tilenum;
    if (gLastPicnum == tilenum)
        return;

    tilenum = getTileId(tilenum);
    if (gpTileInfo[tilenum].picanm&192)
        tilenum += animateOffs(tilenum_, 0);

    gDPLoadTLUT_pal16(gpDisplayList++, 0, loadTile(tilenum));
    gDPLoadTextureBlock_4b(gpDisplayList++, loadTile(tilenum)+32, G_IM_FMT_CI,
                           gpTileInfo[tilenum].dimx, gpTileInfo[tilenum].dimy, 0, 0, 0,
                           tileMasks(tilenum), tileMaskt(tilenum), 0, 0);

    gLastPicnum = tilenum_;
    D_801AC9EC++;
}


/*8000BDB0*/
void func_8000BDB0(s16 tilenum)
{
    s16 tileid;

    if (gLastPicnum == tilenum)
        return;

    tileid = getTileId(tilenum);
    if (gpTileInfo[tileid].picanm&192)
        tileid += animateOffs(tilenum, 0);

    gDPLoadTextureBlock_4b(gpDisplayList++, loadTile(tileid)+32, G_IM_FMT_I,
                           gpTileInfo[tileid].dimx, gpTileInfo[tileid].dimy, 0, 0, 0,
                           tileMasks(tileid), tileMaskt(tileid), 0, 0);

    gLastPicnum = tilenum;
    D_801AC9EC++;
}

/*8000C0D0*/
void func_8000C0D0(s16 tileid)
{
    if (tileid != gLastPicnum)
    {
        gDPLoadTLUT_pal16(gpDisplayList++, 0, loadTile(tileid));
        gDPLoadTextureBlock_4b(gpDisplayList++, loadTile(tileid)+32, G_IM_FMT_CI,
                               gpTileInfo[tileid].dimx, gpTileInfo[tileid].dimy, 0,
                               G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                               0, 0, 0, 0);
        gLastPicnum = tileid;
        D_801AC9EC++;
    }
}

/*8000C3E4*/
void func_8000C3E4(s16 tileid)
{
    if (tileid != gLastPicnum)
    {
        gDPLoadTLUT_pal16(gpDisplayList++, 0, loadTile(tileid));
        gDPLoadTextureBlock_4b(gpDisplayList++, loadTile(tileid)+32, G_IM_FMT_CI,
                               gpTileInfo[tileid].dimx, gpTileInfo[tileid].dimy, 0, 0, 0,
                               tileMasks(tileid), tileMaskt(tileid), 0, 0);
        gLastPicnum = tileid;
        D_801AC9EC++;
    }
}

/*8000C76C*/
void initVertexList(void)
{
    D_801AC9EC = 0;
    gVertexNumber = 0;
    D_80199946 = 0;
    gVertexBufferIndex = 0;
    gpVertexList = gpVertexN64;
}

/*8000C7A4*/
static void _drawWalls(void)
{
    s32 i;
    u16 wallnum;

    initVertexList();
    for (i = 0; i < gDrawWallCnt; i++)
    {
        wallnum = gDrawWallList[i];
        _drawWall(wallnum);
        if ((D_80138694 + D_800FE404 + D_801C0D6C) != 0)
        {
            D_8019996C++;
            func_8000B9C0(gpWall[wallnum].picnum);
            func_8000B6A8(D_80138694 + D_800FE404);
            if (D_801C0D6C > 0)
            {
                if (gpWall[wallnum].cstat & 2)
                    func_8000B9C0(gpWall[gpWall[wallnum].nextwall].picnum);

                func_8000B6A8(D_801C0D6C);
            }
        }
    }
}

/*8000C8EC*/
static void func_8000C8EC(void)
{
    s32 i;
    s32 spriteIndex;

    gLastPicnum = -1;
    gDPSetRenderMode(gpDisplayList++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_SURF2);
    gDPSetCombineLERP(gpDisplayList++, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT,
                                       0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
    gDPSetAlphaCompare(gpDisplayList++, G_AC_NONE);
    gDPSetTextureLUT(gpDisplayList++, G_TT_RGBA16);

    for (i = 0; i < D_80199118; i++)
    {
        spriteIndex = D_801A19A0[i];
        if (gpSector[gpSprite[spriteIndex].sectnum].floorvtxnum != 0)
        {
            _floorVtxToN64Z(gpSprite[spriteIndex].sectnum, gpSprite[spriteIndex].z / 32);
            gDPSetEnvColor(gpDisplayList++, 0xFF, 0xFF, 0xFF, gpSprite[spriteIndex].unk25);
            func_8000B9C0(gpSprite[spriteIndex].lotag);
            drawTriangles(_floorCeilingVertexCount);
        }
    }
}

/*8000CA94*/
static void _drawFloorCeiling(void)
{
    s32 i;
    u16 sectnum;

    for (i = 0; i < gDrawFloorCnt; i++)
    {
        sectnum = gDrawFloorList[i];
        if (gpSector[sectnum].floorvtxnum != 0)
        {
            if (D_800DF2F4[sectnum] & 1)
            {
                floorUpdateZ(sectnum);
                D_800DF2F4[sectnum]--;
            }
            _floorVtxToN64(sectnum);
            func_8000B9C0(gpSector[sectnum].floorpicnum);
            drawTriangles(_floorCeilingVertexCount);
        }
    }

    for (i = 0; i < gDrawCeilCnt; i++)
    {
        sectnum = gDrawCeilingList[i];
        if (gpSector[sectnum].ceilingvtxnum != 0)
        {
            if (D_800DF2F4[sectnum] & 2)
            {
                updateCeilZ(sectnum);
                D_800DF2F4[sectnum] -= 2;
            }
            _ceilingVtxToN64(sectnum);
            func_8000B9C0(gpSector[sectnum].ceilingpicnum);
            drawTriangles(_floorCeilingVertexCount);
        }
    }
}

/*8000CC54*/
static s32 func_8000CC54(s32 wallnum)
{
    VertexC *wall;
    f32 f1, f2, f3, f4;
    s32 wallnum_;
    s32 ang2;
    s16 ang;
    s32 i, j;
    u16 cstat;
    u8 alpha;
    s32 x1, y1, x2, y2;

    alpha = 0xFF;
    wall = gWallVertex;
    cstat = gpWall[wallnum].cstat;
    wallnum_ = gpWall[wallnum].point2;
    ang = 0;
    if (cstat & 0x80)
    {
        alpha = 0xAB;
        if (cstat & 0x200)
            alpha = 0x55;
    }
    if (D_801A2688 == 0)
    {
        if (alpha < 0xFF)
        {
            if (D_801385F0 == 1)
            {
                D_801385F0 = 0;
                gDPSetCombineLERP(gpDisplayList++, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT,
                                                   0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
                gDPSetRenderMode(gpDisplayList++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_SURF2);
            }
        }

        if ((alpha == 0xFF) && (D_801385F0 == 0))
        {
            D_801385F0 = 1;
            gDPSetCombineMode(gpDisplayList++, G_CC_MODULATEIDECALA, G_CC_PASS2);
            gDPSetRenderMode(gpDisplayList++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2);
        }
    }

    gDPSetEnvColor(gpDisplayList++, 0xFF, 0xFF, 0xFF, alpha);

    func_8000DBDC(gpWall[wallnum].pal, gpWall[wallnum].shade);

    if (D_800BD74B != 0)
    {
        x2 = gpWall[wallnum].x;
        y2 = gpWall[wallnum].y;
        x1 = gpWall[wallnum_].x;
        y1 = gpWall[wallnum_].y;
        ang = (getAngle(x1 - x2, y1 - y2) + 512) & 0x7FF;
    }

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            if (D_800BD74B == 0)
            {
                gpVertexN64->v.ob[0] = wall->ob[0];
                gpVertexN64->v.ob[1] = wall->ob[1];
                gpVertexN64->v.ob[2] = wall->ob[2];
                gpVertexN64->v.tc[0] = wall->tc[0];
                gpVertexN64->v.tc[1] = wall->tc[1];

                if (i == 0)
                {
                    gpVertexN64->v.cn[0] = CLAMP_MAX((gpWall[wallnum].unk1D + D_8016A148), 255);
                    gpVertexN64->v.cn[1] = CLAMP_MAX((gpWall[wallnum].unk1E + D_800FE410), 255);
                    gpVertexN64->v.cn[2] = CLAMP_MAX((gpWall[wallnum].unk1F + D_80138680), 255);
                }
                else
                {
                    gpVertexN64->v.cn[0] = CLAMP_MAX((gpWall[wallnum_].unk1D + D_8016A148), 255);
                    gpVertexN64->v.cn[1] = CLAMP_MAX((gpWall[wallnum_].unk1E + D_800FE410), 255);
                    gpVertexN64->v.cn[2] = CLAMP_MAX((gpWall[wallnum_].unk1F + D_80138680), 255);
                }
                gpVertexN64->v.cn[3] = alpha;
            }
            else
            {
                gpVertexN64->v.ob[0] = wall->ob[0];
                gpVertexN64->v.ob[1] = wall->ob[1];
                gpVertexN64->v.ob[2] = wall->ob[2];
                gpVertexN64->v.tc[0] = wall->tc[0];
                gpVertexN64->v.tc[1] = wall->tc[1];
                if (i == 0)
                {
                    ang2 = ang - 45;
                    f3 = (j == 0) ? 16.0f : -16.0f;
                }
                else
                {
                    ang2 = ang + 45;
                    f3 = (j == 0) ? -16.0f : 16.0f;
                }
                f1 = (gpSinTable[(ang2 + 512) & 0x7FF] * 0x7F) >> 14;
                f2 = (gpSinTable[ang2 & 0x7FF] * 0x7F) >> 14;
                f4 = 127.0 / sqrtf(SQ(f1) + SQ(f2) + SQ(f3));
                f1 *= f4;
                gpVertexN64->v.cn[0] = (s32)f1;
                f2 *= f4;
                gpVertexN64->v.cn[1] = (s32)f2;
                f3 *= f4;
                gpVertexN64->v.cn[2] = (s32)f3;
                gpVertexN64->v.cn[3] = alpha;
            }
            gpVertexN64++;
            wall++;
        }
    }
    return 1;
}

/*8000D22C*/
static void _floorVtxToN64(s32 sectnum)
{
    s32 i;
    Vertex *vtx;

    _floorCeilingVertexCount = 0;
    _floorCeilingVertexCounter = 0;
    vtx = &gpSectorVertex[gpSector[sectnum].floorvtxptr];
    func_8000DBDC(gpSector[sectnum].floorpal, gpSector[sectnum].floorshade);

    for (i = 0; i < gpSector[sectnum].floorvtxnum; i++)
    {
        gpVertexN64->v.ob[0] = vtx->v.ob[0];
        gpVertexN64->v.ob[1] = vtx->v.ob[1];
        gpVertexN64->v.ob[2] = vtx->v.ob[2];
        gpVertexN64->v.tc[0] = vtx->v.tc[0];
        gpVertexN64->v.tc[1] = vtx->v.tc[1];
        gpVertexN64->v.cn[0] = CLAMP_MAX((vtx->v.cn[0] + D_8016A148), 255);
        gpVertexN64->v.cn[1] = CLAMP_MAX((vtx->v.cn[1] + D_800FE410), 255);
        gpVertexN64->v.cn[2] = CLAMP_MAX((vtx->v.cn[2] + D_80138680), 255);
        gpVertexN64->n.a = 0x9B;
        vtx++;
        gpVertexN64++;
        gpVertexN64->v.ob[0] = vtx->v.ob[0];
        gpVertexN64->v.ob[1] = vtx->v.ob[1];
        gpVertexN64->v.ob[2] = vtx->v.ob[2];
        gpVertexN64->v.tc[0] = vtx->v.tc[0];
        gpVertexN64->v.tc[1] = vtx->v.tc[1];
        gpVertexN64->v.cn[0] = CLAMP_MAX((vtx->v.cn[0] + D_8016A148), 255);
        gpVertexN64->v.cn[1] = CLAMP_MAX((vtx->v.cn[1] + D_800FE410), 255);
        gpVertexN64->v.cn[2] = CLAMP_MAX((vtx->v.cn[2] + D_80138680), 255);
        gpVertexN64->n.a = 0x9B;
        vtx++;
        gpVertexN64++;
        gpVertexN64->v.ob[0] = vtx->v.ob[0];
        gpVertexN64->v.ob[1] = vtx->v.ob[1];
        gpVertexN64->v.ob[2] = vtx->v.ob[2];
        gpVertexN64->v.tc[0] = vtx->v.tc[0];
        gpVertexN64->v.tc[1] = vtx->v.tc[1];
        gpVertexN64->v.cn[0] = CLAMP_MAX((vtx->v.cn[0] + D_8016A148), 255);
        gpVertexN64->v.cn[1] = CLAMP_MAX((vtx->v.cn[1] + D_800FE410), 255);
        gpVertexN64->v.cn[2] = CLAMP_MAX((vtx->v.cn[2] + D_80138680), 255);
        gpVertexN64->n.a = 0x9B;
        vtx++;
        gpVertexN64++;

        _floorCeilingVertexCounter++;
    }
    _floorCeilingVertexCount = _floorCeilingVertexCounter;
}

/*8000D574*/
static void _floorVtxToN64Z(s32 sectnum, s32 z)
{
    s32 i;
    Vertex *vtx;

    _floorCeilingVertexCount = 0;
    _floorCeilingVertexCounter = 0;
    vtx = &gpSectorVertex[gpSector[sectnum].floorvtxptr];
    func_8000DBDC(gpSector[sectnum].floorpal, gpSector[sectnum].floorshade);

    for (i = 0; i < gpSector[sectnum].floorvtxnum; i++)
    {
        gpVertexN64->v.ob[0] = vtx->v.ob[0];
        gpVertexN64->v.ob[1] = vtx->v.ob[1];
        gpVertexN64->v.ob[2] = z;
        gpVertexN64->v.tc[0] = vtx->v.tc[0];
        gpVertexN64->v.tc[1] = vtx->v.tc[1];
        gpVertexN64->v.cn[0] = CLAMP_MAX((vtx->v.cn[0] + D_8016A148), 255);
        gpVertexN64->v.cn[1] = CLAMP_MAX((vtx->v.cn[1] + D_800FE410), 255);
        gpVertexN64->v.cn[2] = CLAMP_MAX((vtx->v.cn[2] + D_80138680), 255);
        vtx++;
        gpVertexN64++;
        gpVertexN64->v.ob[0] = vtx->v.ob[0];
        gpVertexN64->v.ob[1] = vtx->v.ob[1];
        gpVertexN64->v.ob[2] = z;
        gpVertexN64->v.tc[0] = vtx->v.tc[0];
        gpVertexN64->v.tc[1] = vtx->v.tc[1];
        gpVertexN64->v.cn[0] = CLAMP_MAX((vtx->v.cn[0] + D_8016A148), 255);
        gpVertexN64->v.cn[1] = CLAMP_MAX((vtx->v.cn[1] + D_800FE410), 255);
        gpVertexN64->v.cn[2] = CLAMP_MAX((vtx->v.cn[2] + D_80138680), 255);
        vtx++;
        gpVertexN64++;
        gpVertexN64->v.ob[0] = vtx->v.ob[0];
        gpVertexN64->v.ob[1] = vtx->v.ob[1];
        gpVertexN64->v.ob[2] = z;
        gpVertexN64->v.tc[0] = vtx->v.tc[0];
        gpVertexN64->v.tc[1] = vtx->v.tc[1];
        gpVertexN64->v.cn[0] = CLAMP_MAX((vtx->v.cn[0] + D_8016A148), 255);
        gpVertexN64->v.cn[1] = CLAMP_MAX((vtx->v.cn[1] + D_800FE410), 255);
        gpVertexN64->v.cn[2] = CLAMP_MAX((vtx->v.cn[2] + D_80138680), 255);
        vtx++;
        gpVertexN64++;

        _floorCeilingVertexCounter++;
    }
    _floorCeilingVertexCount = _floorCeilingVertexCounter;
}

/*8000D894*/
static void _ceilingVtxToN64(s32 sectnum)
{
    s32 i;
    Vertex *vtx;

    _floorCeilingVertexCount = 0;
    _floorCeilingVertexCounter = 0;
    vtx = &gpSectorVertex[gpSector[sectnum].ceilingvtxptr];
    func_8000DBDC(gpSector[sectnum].ceilingpal, gpSector[sectnum].ceilingshade);

    for (i = 0; i < gpSector[sectnum].ceilingvtxnum; i++)
    {
        gpVertexN64->v.ob[0] = vtx->v.ob[0];
        gpVertexN64->v.ob[1] = vtx->v.ob[1];
        gpVertexN64->v.ob[2] = vtx->v.ob[2];
        gpVertexN64->v.tc[0] = vtx->v.tc[0];
        gpVertexN64->v.tc[1] = vtx->v.tc[1];
        gpVertexN64->v.cn[0] = CLAMP_MAX((vtx->v.cn[0] + D_8016A148), 255);
        gpVertexN64->v.cn[1] = CLAMP_MAX((vtx->v.cn[1] + D_800FE410), 255);
        gpVertexN64->v.cn[2] = CLAMP_MAX((vtx->v.cn[2] + D_80138680), 255);
        gpVertexN64->n.a = 0xFF;
        vtx++;
        gpVertexN64++;
        gpVertexN64->v.ob[0] = vtx->v.ob[0];
        gpVertexN64->v.ob[1] = vtx->v.ob[1];
        gpVertexN64->v.ob[2] = vtx->v.ob[2];
        gpVertexN64->v.tc[0] = vtx->v.tc[0];
        gpVertexN64->v.tc[1] = vtx->v.tc[1];
        gpVertexN64->v.cn[0] = CLAMP_MAX((vtx->v.cn[0] + D_8016A148), 255);
        gpVertexN64->v.cn[1] = CLAMP_MAX((vtx->v.cn[1] + D_800FE410), 255);
        gpVertexN64->v.cn[2] = CLAMP_MAX((vtx->v.cn[2] + D_80138680), 255);
        gpVertexN64->n.a = 0xFF;
        vtx++;
        gpVertexN64++;
        gpVertexN64->v.ob[0] = vtx->v.ob[0];
        gpVertexN64->v.ob[1] = vtx->v.ob[1];
        gpVertexN64->v.ob[2] = vtx->v.ob[2];
        gpVertexN64->v.tc[0] = vtx->v.tc[0];
        gpVertexN64->v.tc[1] = vtx->v.tc[1];
        gpVertexN64->v.cn[0] = CLAMP_MAX((vtx->v.cn[0] + D_8016A148), 255);
        gpVertexN64->v.cn[1] = CLAMP_MAX((vtx->v.cn[1] + D_800FE410), 255);
        gpVertexN64->v.cn[2] = CLAMP_MAX((vtx->v.cn[2] + D_80138680), 255);
        gpVertexN64->n.a = 0xFF;
        vtx++;
        gpVertexN64++;

        _floorCeilingVertexCounter++;
    }
    _floorCeilingVertexCount = _floorCeilingVertexCounter;
}

/*8000DBDC*/
void func_8000DBDC(u8 pal, s16 shade)
{
    D_8016A148 = (shade * gpGlobalPalette[pal].r) >> 8;
    D_800FE410 = (shade * gpGlobalPalette[pal].g) >> 8;
    D_80138680 = (shade * gpGlobalPalette[pal].b) >> 8;

    if (D_8010A940[gPlayerNum].unk2[5] != 0)
    {
        D_800FE410 = MAX(D_800FE410, D_8016A148);
        D_800FE410 = MAX(D_800FE410, D_80138680);
        D_8016A148 = 0;
        D_800FE410 = CLAMP_MAX((D_800FE410 + 32) * 2, 0xFF);
        D_80138680 = 0;
    }
}

/*8000DCF0*/
void func_8000DCF0(s32 x, s32 y, s32 z, s16 sectnum)
{
    s16 i;
    s32 x1, y1;
    s32 j, k, hitag;
    f32 f1;

    i = gHeadSpriteStat[100];
    D_80138680 = 0;
    D_800FE410 = 0;
    D_8016A148 = 0;
    j = 0x40000000;
    while (i != -1)
    {
        if ((gpSprite[i].ang > 1024) || (gpSprite[i].sectnum == sectnum))
        {
            x1 = gpSprite[i].x;
            y1 = gpSprite[i].y;
            hitag = gpSprite[i].hitag;
            k = func_80040D40(x, y, x1, y1);
            if (k < hitag)
            {
                if (k < j)
                {
                    j = k;
                    D_801B080C = x1;
                    D_8016A14C = y1;
                    D_8013A438 = gpSprite[i].z;
                }
                f1 = 1.0f - ((f32)k / (f32)hitag);
                D_8016A148 += (gpSprite[i].unk18 * f1);
                D_800FE410 += (gpSprite[i].unk1A * f1);
                D_80138680 += (gpSprite[i].unk1C * f1);
            }
        }
        i = gNextSpriteStat[i];
    }

    if (D_8016A148 > 0xFF)
        D_8016A148 = 0xFF;

    if (D_800FE410 > 0xFF)
        D_800FE410 = 0xFF;

    if (D_80138680 > 0xFF)
        D_80138680 = 0xFF;

    if (D_8010A940[gPlayerNum].unk2[5] != 0)
    {
        D_800FE410 = MAX(D_800FE410, D_8016A148);
        D_800FE410 = MAX(D_800FE410, D_80138680);
        D_8016A148 = 0;
        D_800FE410 = CLAMP_MAX((D_800FE410 + 32) * 2, 0xFF);
        D_80138680 = 0;
    }
}

/*8000E024*/
static void func_8000E024(s32 arg0, s32 arg1)
{
}

/*8000E02C*/
static void func_8000E02C(s32 arg0, s32 arg1)
{
    u8 pad[10];
    (void)pad;
}

/*8000E03C*/
static void func_8000E03C(s32 arg0, s32 arg1)
{
    u8 pad[10];
    (void)pad;
}

/*8000E04C*/
void func_8000E04C(void)
{
    func_8000E024(0, gDrawWallCnt - 1);
    func_8000E02C(0, gDrawFloorCnt - 1);
    func_8000E03C(0, gDrawCeilCnt - 1);
}

/*8000E0A0*/
u16 getTileId(u16 tilenum)
{
    u16 tileid;

    if (tilenum == 0)
        return 0;
    tileid = gTilemap[tilenum];

    if (tileid == MAXTILES)
        return 1;
    else
        return tileid;
}

/*8000E0D8*/
static void _initTileMap(void)
{
    u16 i;

    for (i = 0; i < MAXTILES; i++)
        gTilemap[i] = MAXTILES;

    for (i = 0; i < TILENUM; i++)
        gTilemap[gpTileInfo[i].tile] = i;
}

/*8000E160*/
static void _initTiles(void)
{
#ifdef TARGET_N64
    s32 i;

    _initTileMap();
    for (i = 0; i < TILENUM; i++)
    {
        gpTileInfo[i].ramaddr = NULL;
        D_80169580[i] = 0;
    }
#else
    _initTileMap();
#endif
}

/*8000E1B4*/
u8 *loadTile(u16 tileid)
{
    u8 i;
    u8 *ptr;
    u8 *romAddr;
    u16 size;
    u8 val;

    if (gpTileInfo[tileid].ramaddr != NULL)
    {
        D_80169580[tileid] = 0x82;
        return gpTileInfo[tileid].ramaddr;
    }

    if (gpTileInfo[tileid].flags & 0x80)
        size = (gpTileInfo[tileid].dimx * gpTileInfo[tileid].dimy);
    else
        size = (((gpTileInfo[tileid].dimx * gpTileInfo[tileid].dimy) / 2) + 32);

    if (size <= MAXTILESIZE)
    {
        D_80169580[tileid] = 0x82;
        alloCache(&gpTileInfo[tileid].ramaddr, size, &D_80169580[tileid]);
        romAddr = _tileROMAddr;
        romAddr = romAddr + gpTileInfo[tileid].fileoff;
        readRom(_tileBuffer, romAddr, (gpTileInfo[tileid].filesize + 1) & ~1);

        if ((s16)(decompressEDL(_tileBuffer, gpTileInfo[tileid].ramaddr)) != 0)
            Bmemcpy(gpTileInfo[tileid].ramaddr, _tileBuffer, size);

        if (!(gpTileInfo[tileid].flags & 0x80))
        {
            ptr = gpTileInfo[tileid].ramaddr;
            for (i = 0; i < 16; i++)
            {
                val = *ptr;
                *ptr = *(ptr + 1);
                *(ptr + 1) = val;
                ptr += 2;
            }
        }
        return gpTileInfo[tileid].ramaddr;
    }
    return NULL;
}

/*8000E3D4*/
s32 tileMasks(u16 tileid)
{
    switch (gpTileInfo[tileid].dimx)
    {
    case 0:
        return 0;
    case 2:
        return 1;
    case 4:
        return 2;
    case 8:
        return 3;
    case 16:
        return 4;
    case 32:
        return 5;
    case 64:
        return 6;
    case 128:
        return 7;
    case 256:
        return 8;
    }
    return 0;
}

/*8000E4A0*/
s32 tileMaskt(u16 tileid)
{
    switch (gpTileInfo[tileid].dimy)
    {
    case 0:
        return 0;
    case 2:
        return 1;
    case 4:
        return 2;
    case 8:
        return 3;
    case 16:
        return 4;
    case 32:
        return 5;
    case 64:
        return 6;
    case 128:
        return 7;
    case 256:
        return 8;
    }
    return 0;
}

/*8000E56C*/
static void _setupMatrix(void)
{
    f32 xUp, yUp, zUp, xAt, yAt, zAt;

    u16 perspNorm;
    Matrix4f projection;
    Matrix4f viewing;

    xAt = sinf(gGlobalAng) * 512.0;
    yAt = cosf(gGlobalAng) * -512.0;
    zAt = (sinf(gGlobalViewHorizAng) * 512.0) / cosf(gGlobalViewHorizAng);

    grPerspectiveF(projection,
                   &perspNorm,
                   ((60.0*256.0) / gPlayer[gPlayerNum].unk6E),
                   ASPECT_RATIO,
                   ((gPlayer[gPlayerNum].unk6E * 5) / 256.0),
                   16384.0f,
                   (256.0 / gPlayer[gPlayerNum].unk6E));

    grPerspective(&gpDynamic->mtx1[gPlayerNum],
                  &perspNorm,
                  ((60.0*256.0) / gPlayer[gPlayerNum].unk6E),
                  ASPECT_RATIO,
                  ((gPlayer[gPlayerNum].unk6E * 5) / 256.0),
                  16384.0f,
                  (256.0 / gPlayer[gPlayerNum].unk6E));

    D_801385F2 = perspNorm;

    xUp = sinf(D_801AC8E0) * cosf(gGlobalAng);
    yUp = sinf(D_801AC8E0) * sinf(gGlobalAng);
    zUp = -cosf(D_801AC8E0);

    grLookAtF(viewing,
              gMapXpos * 0.5f,
              gMapYpos * 0.5f,
              gMapZpos * 0.5f,
              (xAt + gMapXpos) * 0.5f,
              (yAt + gMapYpos) * 0.5f,
              (zAt + gMapZpos) * 0.5f,
              xUp,
              yUp,
              zUp);

    grLookAtReflect(&gpDynamic->mtx2[gPlayerNum],
                    &gpDynamic->lookat[gPlayerNum][0],
                    gMapXpos * 0.5f,
                    gMapYpos * 0.5f,
                    gMapZpos * 0.5f,
                    (xAt + gMapXpos) * 0.5f,
                    (yAt + gMapYpos) * 0.5f,
                    (zAt + gMapZpos) * 0.5f,
                    xUp,
                    yUp,
                    zUp);

    gSPLookAtX(gpDisplayList++, &gpDynamic->lookat[gPlayerNum][0].l[0]);
    gSPLookAtY(gpDisplayList++, &gpDynamic->lookat[gPlayerNum][0].l[1]);
    gSPMatrix(gpDisplayList++, OS_K0_TO_PHYSICAL(&gpDynamic->mtx1[gPlayerNum]),
                               G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gpDisplayList++, OS_K0_TO_PHYSICAL(&gpDynamic->mtx2[gPlayerNum]),
                               G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
    gSPPerspNormalize(gpDisplayList++, perspNorm);
    grMtxCatF(viewing, projection, D_8012B948);
}

/*8000EA0C*/
void func_8000EA0C(u8 playernum, s16 r, s16 g, s16 b, s16 a)
{
    D_80138798[playernum].r = CLAMP_MIN(CLAMP_MAX(D_80138798[playernum].r + r, 255), 0);
    D_80138798[playernum].g = CLAMP_MIN(CLAMP_MAX(D_80138798[playernum].g + g, 255), 0);
    D_80138798[playernum].b = CLAMP_MIN(CLAMP_MAX(D_80138798[playernum].b + b, 255), 0);
    D_80138798[playernum].a = CLAMP_MIN(D_80138798[playernum].a + a, 0);
}

/*8000EB4C*/
void func_8000EB4C(u8 playernum, s16 r, s16 g, s16 b, s16 a)
{
    D_80138798[playernum].r = r;
    D_80138798[playernum].g = g;
    D_80138798[playernum].b = b;
    D_80138798[playernum].a = a;
}

/*8000EB90*/
void func_8000EB90(u8 playernum, s16 r, s16 g, s16 b, s16 a)
{
    D_8013F930[playernum].r = r;
    D_8013F930[playernum].g = g;
    D_8013F930[playernum].b = b;
    D_8013F930[playernum].a = a;
}

/*8000EBD4*/
s16 func_8000EBD4(u8 playernum)
{
    return D_80138798[playernum].a;
}

#define SCALE_TO_SCREEN_WIDTH(TILE_SIZEX, OFFSET) (gViewportScaleX / (SCREEN_WIDTH/2.0) * \
                                                  (((SCREEN_WIDTH/2.0)+OFFSET)*6/TILE_SIZEX))

#define SCALE_TO_SCREEN_HEIGHT(TILE_SIZEY, OFFSET) (gViewportScaleY / (SCREEN_HEIGHT/2.0) * \
                                                   (((SCREEN_HEIGHT/2.0)+OFFSET)*6/TILE_SIZEY))

/*8000EBF0*/
static void func_8000EBF0(u8 playernum, u8 arg1)
{
    s16 alpha;
    f32 scalex, scaley;

    setDrawMode2D();
    if (playernum == 4)
    {
        gDPSetAlphaDither(gpDisplayList++, G_AD_DISABLE);
    }
    else
    {
        gDPSetAlphaDither(gpDisplayList++, G_AD_NOISE);
    }

    if (arg1)
    {
        switch (D_800BD74A)
        {
        case 0:
            if (random(1000) >= 985)
                D_800BD74A = 1;
            break;
        case 1:
            D_800BD748 = CLAMP_MAX((D_800BD748 + 4), 255);
            if (random(1000) >= 934)
                D_800BD74A = 2;
            break;
        case 2:
            D_800BD748 -= 4;
            if (D_800BD748 <= 0)
            {
                D_800BD748 = 0;
                D_800BD74A = 0;
            }
            break;
        }

        if ((D_800BD748 / 2) > 0)
        {
            if (D_800BD750 == 0)
                D_800BD750 = playSfx2(1596, (D_800BD748 / 2), 0x80, 1, -1);
            else
                MusHandleSetVolume(D_800BD750, (D_800BD748 / 2));
        }
        else
        {
            MusHandleStop(D_800BD750, 0);
            D_800BD750 = 0;
        }
    }
    else
    {
        if (playernum != 4)
        {
            MusHandleStop(D_800BD750, 0);
            D_800BD750 = 0;
        }
    }

    if (D_80138798[playernum].a > 0)
    {
        alpha = CLAMP_MIN(CLAMP_MAX(D_80138798[playernum].a, 255), 0);

        if (alpha != 255)
        {
            gDPSetRenderMode(gpDisplayList++, 0x504B40, 0); /*TODO*/
        }
        else
        {
            gDPSetRenderMode(gpDisplayList++, G_RM_FOG_SHADE_A, G_RM_RA_OPA_SURF2);
        }

        if (arg1)
        {
            gDPSetEnvColor(gpDisplayList++, D_800BD748, D_800BD748, D_800BD748, 0xFF);
            gDPSetCombineLERP(gpDisplayList++, NOISE, 0, ENVIRONMENT, PRIMITIVE, 0, 0, 0, PRIMITIVE,
                                               NOISE, 0, ENVIRONMENT, PRIMITIVE, 0, 0, 0, PRIMITIVE);
        }
        else
        {
            gDPSetCombineMode(gpDisplayList++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
        }
        gDPSetPrimColor(gpDisplayList++, 0, 0, D_80138798[playernum].r, D_80138798[playernum].g, D_80138798[playernum].b, alpha);

        scalex = SCALE_TO_SCREEN_WIDTH(16, 0);
        scaley = SCALE_TO_SCREEN_HEIGHT(16, 5);
        if (playernum >= 4)
        {
            drawTileScaled((gScreenWidth/2), (gScreenHeight / 2), scalex, scaley, getTileId(5948), 0);
            return;
        }
        drawTileScaled(gViewportTransX, gViewportTransY, scalex, scaley, getTileId(5948), 0);
    }

    if (playernum < 4)
    {
        if (D_8013F930[playernum].a > 0)
        {
            scalex = SCALE_TO_SCREEN_WIDTH(64, -BORDER_SIZE);
            scaley = SCALE_TO_SCREEN_HEIGHT(64, -BORDER_SIZE/ASPECT_RATIO);
            alpha = CLAMP_MIN(CLAMP_MAX(D_8013F930[playernum].a, 255), 0);

            func_8002900C(D_8013F930[playernum].r, D_8013F930[playernum].g, D_8013F930[playernum].b,
                          D_8013F930[playernum].r, D_8013F930[playernum].g, D_8013F930[playernum].b, alpha);

            drawTileScaled(gViewportTransX, gViewportTransY, scalex, scaley, getTileId(5983), 0);
            D_8013F930[playernum].a = CLAMP_MIN((D_8013F930[playernum].a - 8), 0);
        }
    }
}
