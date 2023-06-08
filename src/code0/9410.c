#include "common.h"
#include "code0/4600.h"
#include "code0/cache1d.h"
#include "code0/edl.h"
#include "code0/main.h"
#include "code0/audio.h"
#include "code0/graphics.h"
#include "code0/9410.h"
#include "code0/1A7C0.h"
#include "code0/1E7A0.h"
#include "code0/20490.h"
#include "code0/21500.h"
#include "code0/24610.h"
#include "code0/416A0.h"
#include "code0/7BA50.h"
#include "code0/8E670.h"
#include "code0/609D0.h"
#include "code0/6ACA0.h"
#include "code0/41940.h"
#include "code0/debug.h"
#include "code0/87010.h"
#include "code0/95500.h"
#include "code0/A06F0.h"
#include "code1/EB300.h"
#include "code1/code1.h"

#define MAXTILESIZE 32832

/*.data*/
/*800BD724*/ EXTERN_DATA STATIC u8 *_tileROMAddr;
/*800BD72C*/ EXTERN_DATA f32 gMapXpos;
/*800BD730*/ EXTERN_DATA f32 gMapYpos;
/*800BD734*/ EXTERN_DATA f32 gMapZpos;
/*800BD738*/ EXTERN_DATA STATIC u8 _sectorsLock;
/*800BD739*/ EXTERN_DATA STATIC u8 _wallsLock;
/*800BD73A*/ EXTERN_DATA STATIC u8 _spritesLock;
/*800BD73B*/ EXTERN_DATA STATIC u8 _mapLock;
/*800BD73C*/ EXTERN_DATA STATIC u8 _vertexLock;
/*800BD74B*/ EXTERN_DATA STATIC u8 D_800BD74B;
/*800BD74C*/ EXTERN_DATA STATIC u8 *_tilemap;

/*.comm*/
/*800FE404*/ s16 D_800FE404;
/*80105544*/ u32 gDisplayListRemainingSize;
/*80105708*/ u8 *gpMapBuffer;
/*80106D38*/ u32 gVertexN64Size;
/*80107910*/ s16 gTilemap[MAXTILES] ALIGNED(16);
/*80119A58*/ u32 gDisplayListSize;
/*8012FDA0*/ u8 gTileBuffer[MAXTILESIZE] ALIGNED(16);
/*801385F2*/ u16 D_801385F2; /*perspNorm*/
/*801385F4*/ s16 D_801385F4;
/*80138694*/ s16 D_80138694;
/*80138798*/ s16 D_80138798[5][4] ALIGNED(8); /*MAXPLAYERS?*/
/*8013F930*/ s16 D_8013F930[MAXPLAYERS][4] ALIGNED(8);
/*80169580*/ u8 D_80169580[TILENUM] ALIGNED(16);
/*80199118*/ s16 D_80199118;
/*80199554*/ s32 D_80199554;
/*80199946*/ s16 D_80199946;
/*8019996C*/ s32 D_8019996C;
/*801A19A0*/ s16 D_801A19A0[32] ALIGNED(8);
/*801AC9EC*/ s32 D_801AC9EC;
/*801C0D6C*/ s16 D_801C0D6C;

/*.text*/
static void initTiles(void);
static u8 func_800099D0(void);
static void floorVtxToN64(s32 sectnum);
static void floorVtxToN64Z(s32 sectnum, s32 z);
static void ceilingVtxToN64(s32 sectnum);

STATIC void decompressMap(void);
STATIC void func_80009A14(u8);
static void func_8000A938(u16 wallnum);
STATIC void func_8000AEE0(u16 wallnum);
static void func_8000B9C0(s16 tileid);
STATIC void func_8000CC54(s32 wallnum);
STATIC void func_8000EBF0(u8, u8);

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
    func_80004C84();
    gMapNum = mapnum;
    Bmemset(&D_801A1958, 0, sizeof(D_801A1958));
    alloCache(&gpMapBuffer, gpMapInfo[mapnum].rom_end - gpMapInfo[mapnum].rom_start, &_mapLock);
    readRom(gpMapBuffer, gpMapInfo[mapnum].rom_start, gpMapInfo[mapnum].rom_end - gpMapInfo[mapnum].rom_start);
    initSpriteLists();
    decompressMap();
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
        func_80004B60(i);
        func_80004A3C(i);
    }

    audio_80008710(gMapNum);
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

#ifdef NON_MATCHING
/*80008B88*/
STATIC void decompressMap(void)
{
    s32 i;
    s32 count;
    s32 floorz;
    s32 offset;

    gMapXpos = (f32)gpMapInfo[gMapNum].xpos;
    gMapYpos = (f32)gpMapInfo[gMapNum].ypos;
    gMapZpos = (f32)gpMapInfo[gMapNum].zpos;

    offset = gpMapInfo[gMapNum].sector_offset;
    decompressEDL(&gpMapBuffer[offset], gpSector);

    offset = gpMapInfo[gMapNum].wall_offset;
    decompressEDL(&gpMapBuffer[offset], gpWall);

    offset = gpMapInfo[gMapNum].sprite_offset;
    decompressEDL(&gpMapBuffer[offset], gpSprite);

    count = 0;
    for (i = 0; i < gNumSectors; i++)
    {
        count += gpSector[i].floorvtxnum;
        count += gpSector[i].ceilingvtxnum;
    }

    count *= 3;
    alloCache(&gpVertex, (count * sizeof(VertexType)), &_vertexLock);
    decompressEDL(&gpMapBuffer[0], gpVertex);
    suckCache(&gpMapBuffer);
    initTiles();

    for (i = 0; i < MAXPLAYERS; i++)
    {
        gPlayer[i].xpos = (s32)(2.0f * gMapXpos);
        gPlayer[i].ypos = (s32)(2.0f * gMapYpos);
        gPlayer[i].zpos = (s32)(32.0f * gMapZpos);
        updateSector(gPlayer[i].xpos, gPlayer[i].ypos, &gPlayer[i].unk32);
        floorz = getFlorzOfSlope(gPlayer[i].unk32, gPlayer[i].xpos, gPlayer[i].ypos);
        gPlayer[i].zpos = floorz - 0x3900;
        gPlayer[i].unk38 = gpMapInfo[gMapNum].unk2C;
    }
}
#else
/*80008B88*/
INCLUDE_ASM("nonmatchings/src/code0/9410", decompressMap);
#endif

/*80008E3C*/
void func_80008E3C(void)
{
    char buffer[8];
    s32 value;
    s32 playernum;

    func_80040AA0(3, "DR");
    func_80040B2C(3);
    D_801A6D80 = 0;
    D_8012BBCC = 0;
    D_8012F6F0[0] = 0;
    D_8012F6F0[1] = 0;
    D_8012F6F0[2] = 0;
    D_8012F6F0[3] = 0;
    D_801B0820 = 0;

    for (; D_801B0820 < D_8012C470; D_801B0820++)
    {
        func_8001FD60(D_801B0820, 0);
        func_80009A14(D_801B0820);
    }

    func_8000A070();
    D_80199110 = (f32)(gScreenWidth / 2);
    D_80168C9C = (f32)(gScreenWidth / 2);
    D_801A1980 = (f32)(gScreenHeight / 2);
    D_801A2684 = (f32)(gScreenHeight / 2);
    gDPSetScissor(gpDisplayList++, G_SC_NON_INTERLACE, 0, 0, gScreenWidth, gScreenHeight);

    if (D_80199558 > 0)
    {
        value = (D_80199558 - D_80119A64) / 30;
        value = (value < 0) ? 0 : value;
        sprintf(buffer, "%02d:%02d", value / 60, value % 60);

        func_80029130(255, 128, 0, 0, 0, 0);
        if ((D_8012C470 == 3) && (D_800DCBD5 == 0))
            displayNumbers(207, 164, buffer);
        else
            displayMessage1(-1, 112, buffer);
    }

    if (!func_800099D0() && (D_800DF98C != 0))
    {
        func_8000A070();
        debugMenu();
    }

    func_80020510();

    if (D_801AE914 != 0)
        func_8000EB4C(4, 0, 0, 0, 196);

    func_8000EBF0(4, 0);

    gDisplayListSize = ((uintptr_t)gpDisplayList - (uintptr_t)gDisplayList[gGfxTaskIndex]) / sizeof(Gfx);
    gVertexN64Size = ((uintptr_t)gpVertexN64 - (uintptr_t)gVertexN64[gGfxTaskIndex]) / sizeof(Vtx);

    for (playernum = 0; playernum < D_8012C470; playernum++)
        D_8019B940[D_80106D50[gPlayer[playernum].unk4A]].unk0 &= ~0x100;

    func_80040B70(3);
}

/*8000921C*/
s32 func_8000921C(void)
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
INCLUDE_ASM("nonmatchings/src/code0/9410", func_80009314);

/*80009998*/
static s32 getDisplayListRemainingSize(void)
{
    return gDisplayListMaxSize - ((uintptr_t)gpDisplayList - (uintptr_t)gDisplayList[gGfxTaskIndex]) / sizeof(Gfx);
}

/*800099D0*/
static u8 func_800099D0(void)
{
    s32 size;

    size = ((uintptr_t)gpDisplayList - (uintptr_t)gDisplayList[gGfxTaskIndex]) / sizeof(Gfx);
    size = gDisplayListMaxSize - size;
    gDisplayListRemainingSize = size;
    return gDisplayListRemainingSize < 2048;
}

/*80009A14*/
INCLUDE_ASM("nonmatchings/src/code0/9410", func_80009A14);

/*8000A070*/
void func_8000A070(void)
{
    gDPPipeSync(gpDisplayList++);
    gSPClearGeometryMode(gpDisplayList++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
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
}

/*8000A184*/
INCLUDE_ASM("nonmatchings/src/code0/9410", func_8000A184);

/*8000A634*/
static void func_8000A634(void)
{
    s32 i;
    s16 wallnum;
    s16 tileid;

    func_80023A10();
    func_8000A174(0, D_80138830 - 1);
    D_800BD74B = 0;

    for (i = 0; i < D_80138830; i++)
    {
        if (D_8012BC70[i].unk0 & 0x8000)
        {
            wallnum = D_8012BC70[i].unk0 & 0x7FFF;
            tileid = gpWall[wallnum].overpicnum;
            if ((tileid == 5300) || (tileid == 6080))
            {
                if (D_800BD74B == 0)
                {
                    D_800BD74B = 1;
                    gSPSetGeometryMode(gpDisplayList++, G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
                    gSPTexture(gpDisplayList++, 0x7FC0, 0x7FC0, 0, G_TX_RENDERTILE, G_ON);
                }
                func_8000C76C();
                func_8000DBDC(gpWall[wallnum].unk21, gpWall[wallnum].unk1C);
                func_8000F3C4(0, 0, 0, D_8016A148, D_800FE410, D_80138680);
            }
            else if (D_800BD74B == 1)
            {
                func_8000C76C();
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
                func_8000C76C();
                D_800BD74B = 0;
                gSPClearGeometryMode(gpDisplayList++, G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
                gSPTexture(gpDisplayList++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
            }
            func_80023C04(D_8012BC70[i].unk0, D_8012BC70[i].unk2, D_8012BC70[i].unk4);
        }
    }
    if (D_800BD74B == 1)
    {
        func_8000C76C();
        D_800BD74B = 0;
        gSPClearGeometryMode(gpDisplayList++, G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
        gSPTexture(gpDisplayList++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    }
}

/*8000A938*/
static void func_8000A938(u16 wallnum)
{
    u16 tilenum;

    tilenum = getTileNum(gpWall[wallnum].overpicnum);
    if (tilenum == 1)
        return;

    if (D_801A2688 != 0)
    {
        D_801A2688 = 0;
        gDPSetAlphaCompare(gpDisplayList++, G_AC_NONE);
        gDPSetTextureLUT(gpDisplayList++, G_TT_RGBA16);
        gDPSetCombineLERP(gpDisplayList++, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
    }

    if (D_80197DD4 == 0)
    {
        D_80197DD4 = 32;
        D_801A2620 = 0;
        gSPVertex(gpDisplayList++, gpVertexN64, 32, 0);
    }
    func_800226C0(wallnum);
    func_8000CC54(wallnum);

    if (gpTileInfo[tilenum].picanm&192)
        tilenum += animateOffs(gpWall[wallnum].overpicnum, 0);

    gDPLoadTLUT_pal16(gpDisplayList++, 0, loadTile(tilenum));
    gDPLoadTextureBlock_4b(gpDisplayList++, loadTile(tilenum)+32, G_IM_FMT_CI,
                           gpTileInfo[tilenum].dimx, gpTileInfo[tilenum].dimy, 0, 0, 0,
                           tileMasks(tilenum), tileMaskt(tilenum), 0, 0);


    D_801AC9EC++;
    gSP2Triangles(gpDisplayList++, D_801A2620, D_801A2620+1, D_801A2620+2, D_801A2620,
                                   D_801A2620, D_801A2620+2, D_801A2620+3, D_801A2620);

    D_8012DEFC = -1;
    D_801A2620 += 4;
    D_80197DD4 -= 4;
};

/*8000AEE0*/
INCLUDE_ASM("nonmatchings/src/code0/9410", func_8000AEE0);

/*8000B570*/
void func_8000B570(s16 arg0)
{
    s16 i;

    for (i = arg0; i > 0; i--)
    {
        if (D_80197DD4 == 0)
        {
            gSPVertex(gpDisplayList++, D_80199114, 30, 0);
            D_80197DD4 = 30;
            D_801A2620 = 0;
        }
        gSP1Triangle(gpDisplayList++, D_801A2620, D_801A2620+1, D_801A2620+2, D_801A2620);
        D_801A2620 = D_801A2620 + 3;
        D_80197DD4 = D_80197DD4 - 3;
        D_80199114 += 3;
    }
}

/*8000B6A8*/
void func_8000B6A8(s16 arg0)
{
    s16 i;

    for (i = arg0; i > 0; i--)
    {
        if (D_80197DD4 == 0)
        {
            gSPVertex(gpDisplayList++, D_80199114, 32, 0);
            D_80197DD4 = 32;
            D_801A2620 = 0;
        }
        gSP2Triangles(gpDisplayList++, D_801A2620, D_801A2620+1, D_801A2620+2, D_801A2620,
                                       D_801A2620, D_801A2620+2, D_801A2620+3, D_801A2620);

        D_801A2620 = D_801A2620 + 4;
        D_80197DD4 = D_80197DD4 - 4;
        D_80199114 += 4;
    }
}

/*8000B830*/
void func_8000B830(s16 arg0)
{
    s16 i;

    for (i = arg0; i > 0; i--)
    {
        if (D_80197DD4 == 0)
        {
            gSPVertex(gpDisplayList++, D_80199114, 32, 0);
            D_80197DD4 = 32;
            D_801A2620 = 0;
        }
        gSP2Triangles(gpDisplayList++, D_801A2620, D_801A2620+1, D_801A2620+2, D_801A2620,
                                       D_801A2620+1, D_801A2620+2, D_801A2620+3, D_801A2620);

        D_801A2620 = D_801A2620 + 4;
        D_80197DD4 = D_80197DD4 - 4;
        D_80199114 += 4;
    }
}

/*8000B9C0*/
static void func_8000B9C0(s16 tileid)
{
    s16 tileid_;

    if (D_801CDBCC != 0)
        tileid = 5948;

    tileid_ = tileid;
    if (D_8012DEFC == tileid)
        return;

    tileid = getTileNum(tileid);
    if (gpTileInfo[tileid].picanm & 0xC0)
        tileid += animateOffs(tileid_, 0);

    gDPLoadTLUT_pal16(gpDisplayList++, 0, loadTile(tileid));
    gDPLoadTextureBlock_4b(gpDisplayList++, loadTile(tileid)+32, G_IM_FMT_CI,
                           gpTileInfo[tileid].dimx, gpTileInfo[tileid].dimy, 0, 0, 0,
                           tileMasks(tileid), tileMaskt(tileid), 0, 0);

    D_8012DEFC = tileid_;
    D_801AC9EC++;
}


/*8000BDB0*/
void func_8000BDB0(s16 tileid)
{
    s16 tilenum;

    if (D_8012DEFC == tileid)
        return;

    tilenum = getTileNum(tileid);
    if (gpTileInfo[tilenum].picanm&192)
        tilenum += animateOffs(tileid, 0);

    gDPLoadTextureBlock_4b(gpDisplayList++, loadTile(tilenum)+32, G_IM_FMT_I,
                           gpTileInfo[tilenum].dimx, gpTileInfo[tilenum].dimy, 0, 0, 0,
                           tileMasks(tilenum), tileMaskt(tilenum), 0, 0);

    D_8012DEFC = tileid;
    D_801AC9EC++;
}

/*8000C0D0*/
void func_8000C0D0(s16 tilenum)
{
    if (tilenum != D_8012DEFC)
    {
        gDPLoadTLUT_pal16(gpDisplayList++, 0, loadTile(tilenum));
        gDPLoadTextureBlock_4b(gpDisplayList++, loadTile(tilenum)+32, G_IM_FMT_CI,
                               gpTileInfo[tilenum].dimx, gpTileInfo[tilenum].dimy, 0,
                               G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                               0, 0, 0, 0);
        D_8012DEFC = tilenum;
        D_801AC9EC++;
    }
}

/*8000C3E4*/
void func_8000C3E4(s16 tilenum)
{
    if (tilenum != D_8012DEFC)
    {
        gDPLoadTLUT_pal16(gpDisplayList++, 0, loadTile(tilenum));
        gDPLoadTextureBlock_4b(gpDisplayList++, loadTile(tilenum)+32, G_IM_FMT_CI,
                               gpTileInfo[tilenum].dimx, gpTileInfo[tilenum].dimy, 0, 0, 0,
                               tileMasks(tilenum), tileMaskt(tilenum), 0, 0);
        D_8012DEFC = tilenum;
        D_801AC9EC++;
    }
}

/*8000C76C*/
void func_8000C76C(void)
{
    D_801AC9EC = 0;
    D_80197DD4 = 0;
    D_80199946 = 0;
    D_801A2620 = 0;
    D_80199114 = gpVertexN64;
}

/*8000C7A4*/
static void drawWalls(void)
{
    s32 i;
    u16 wallnum;

    func_8000C76C();
    for (i = 0; i < D_80199750; i++)
    {
        wallnum = D_8013A448[i];
        func_8000AEE0(wallnum);
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
    int spriteIndex;

    D_8012DEFC = -1;
    gDPSetRenderMode(gpDisplayList++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_SURF2);
    gDPSetCombineLERP(gpDisplayList++, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
    gDPSetAlphaCompare(gpDisplayList++, G_AC_NONE);
    gDPSetTextureLUT(gpDisplayList++, G_TT_RGBA16);

    for (i = 0; i < D_80199118; i++)
    {
        spriteIndex = D_801A19A0[i];
        if (gpSector[gpSprite[spriteIndex].sectnum].floorvtxnum != 0)
        {
            floorVtxToN64Z(gpSprite[spriteIndex].sectnum, gpSprite[spriteIndex].z / 32);
            gDPSetEnvColor(gpDisplayList++, 0xFF, 0xFF, 0xFF, gpSprite[spriteIndex].unk25);
            func_8000B9C0(gpSprite[spriteIndex].unk1E);
            func_8000B570(D_80199554);
        }
    }
}

/*8000CA94*/
static void drawFloorCeiling(void)
{
    s32 i;
    u16 sectnum;

    for (i = 0; i < D_80199528; i++)
    {
        sectnum = D_801A2690[i];
        if (gpSector[sectnum].floorvtxnum != 0)
        {
            if (D_800DF2F4[sectnum] & 1)
            {
                func_80004A3C(sectnum);
                D_800DF2F4[sectnum]--;
            }
            floorVtxToN64(sectnum);
            func_8000B9C0(gpSector[sectnum].floorpicnum);
            func_8000B570(D_80199554);
        }
    }

    for (i = 0; i < D_80168D10; i++)
    {
        sectnum = D_80199650[i];
        if (gpSector[sectnum].ceilingvtxnum != 0)
        {
            if (D_800DF2F4[sectnum] & 2)
            {
                func_80004B60(sectnum);
                D_800DF2F4[sectnum] -= 2;
            }
            ceilingVtxToN64(sectnum);
            func_8000B9C0(gpSector[sectnum].ceilingpicnum);
            func_8000B570(D_80199554);
        }
    }
}

/*8000CC54*/
INCLUDE_ASM("nonmatchings/src/code0/9410", func_8000CC54);

#define VERTEX2N64(N64, VTX, Z) \
        N64->v.ob[0] = VTX->v.ob[0]; \
        N64->v.ob[1] = VTX->v.ob[1]; \
        N64->v.ob[2] = Z; \
        N64->v.tc[0] = VTX->v.tc[0]; \
        N64->v.tc[1] = VTX->v.tc[1]; \
        N64->v.cn[0] = CLAMP_MAX((VTX->v.cn[0] + D_8016A148), 255); \
        N64->v.cn[1] = CLAMP_MAX((VTX->v.cn[1] + D_800FE410), 255); \
        N64->v.cn[2] = CLAMP_MAX((VTX->v.cn[2] + D_80138680), 255); 

/*8000D22C*/
static void floorVtxToN64(s32 sectnum)
{
    s32 i;
    VertexType *vtx;

    D_80199554 = 0;
    D_801385F4 = 0;
    vtx = &gpVertex[gpSector[sectnum].floorvtxptr];
    func_8000DBDC(gpSector[sectnum].unk27, gpSector[sectnum].unk26);

    for (i = 0; i < gpSector[sectnum].floorvtxnum; i++)
    {
        VERTEX2N64(gpVertexN64, vtx, vtx->v.ob[2]);
        gpVertexN64->n.a = 0x9B;
        vtx++;
        gpVertexN64++;
        VERTEX2N64(gpVertexN64, vtx, vtx->v.ob[2]);
        gpVertexN64->n.a = 0x9B;
        vtx++;
        gpVertexN64++;
        VERTEX2N64(gpVertexN64, vtx, vtx->v.ob[2]);
        gpVertexN64->n.a = 0x9B;
        vtx++;
        gpVertexN64++;

        D_801385F4++;
    }
    D_80199554 = D_801385F4;
}

/*8000D574*/
static void floorVtxToN64Z(s32 sectnum, s32 z)
{
    s32 i;
    VertexType *vtx;

    D_80199554 = 0;
    D_801385F4 = 0;
    vtx = &gpVertex[gpSector[sectnum].floorvtxptr];
    func_8000DBDC(gpSector[sectnum].unk27, gpSector[sectnum].unk26);

    for (i = 0; i < gpSector[sectnum].floorvtxnum; i++)
    {
        VERTEX2N64(gpVertexN64, vtx, z);
        vtx++;
        gpVertexN64++;
        VERTEX2N64(gpVertexN64, vtx, z);
        vtx++;
        gpVertexN64++;
        VERTEX2N64(gpVertexN64, vtx, z);
        vtx++;
        gpVertexN64++;

        D_801385F4++;
    }
    D_80199554 = D_801385F4;
}

/*8000D894*/
static void ceilingVtxToN64(s32 sectnum)
{
    s32 i;
    VertexType *vtx;

    D_80199554 = 0;
    D_801385F4 = 0;
    vtx = &gpVertex[gpSector[sectnum].ceilingvtxptr];
    func_8000DBDC(gpSector[sectnum].unk23, gpSector[sectnum].unk22);

    for (i = 0; i < gpSector[sectnum].ceilingvtxnum; i++)
    {
        VERTEX2N64(gpVertexN64, vtx, vtx->v.ob[2]);
        gpVertexN64->n.a = 0xFF;
        vtx++;
        gpVertexN64++;
        VERTEX2N64(gpVertexN64, vtx, vtx->v.ob[2]);
        gpVertexN64->n.a = 0xFF;
        vtx++;
        gpVertexN64++;
        VERTEX2N64(gpVertexN64, vtx, vtx->v.ob[2]);
        gpVertexN64->n.a = 0xFF;
        vtx++;
        gpVertexN64++;

        D_801385F4++;
    }
    D_80199554 = D_801385F4;
}

/*8000DBDC*/
void func_8000DBDC(u8 arg0, s16 arg1)
{
    D_8016A148 = (arg1 * gpGlobalPalette[arg0].r) >> 8;
    D_800FE410 = (arg1 * gpGlobalPalette[arg0].g) >> 8;
    D_80138680 = (arg1 * gpGlobalPalette[arg0].b) >> 8;

    if (D_8010A940[D_801B0820].unk7 != 0)
    {
        D_800FE410 = MAX(D_800FE410, D_8016A148);
        D_800FE410 = MAX(D_800FE410, D_80138680);
        D_8016A148 = 0;
        D_800FE410 = CLAMP_MAX((D_800FE410 + 32) * 2, 255);
        D_80138680 = 0;
    }
}

/*8000DCF0*/
INCLUDE_ASM("nonmatchings/src/code0/9410", func_8000DCF0);

/*8000E024*/
static void func_8000E024(s32 arg0, s32 arg1)
{
}

/*8000E02C*/
static void func_8000E02C(s32 arg0, s32 arg1)
{
    u8 pad[10];
}

/*8000E03C*/
static void func_8000E03C(s32 arg0, s32 arg1)
{
    u8 pad[10];
}

/*8000E04C*/
void func_8000E04C(void)
{
    func_8000E024(0, D_80199750 - 1);
    func_8000E02C(0, D_80199528 - 1);
    func_8000E03C(0, D_80168D10 - 1);
}

/*8000E0A0*/
u16 getTileNum(u16 tileid)
{
    u16 tilenum;

    if (tileid == 0)
        return 0;
    tilenum = gTilemap[tileid];

    if (tilenum == MAXTILES)
        return 1;
    else
        return tilenum;
}

/*8000E0D8*/
static void initTileMap(void)
{
    u16 i;

    for (i = 0; i < MAXTILES; i++)
        gTilemap[i] = MAXTILES;

    for (i = 0; i < TILENUM; i++)
        gTilemap[gpTileInfo[i].tileid] = i;
}

/*8000E160*/
static void initTiles(void)
{
    s32 i;

    initTileMap();
    for (i = 0; i < TILENUM; i++)
    {
        gpTileInfo[i].ramaddr = NULL;
        D_80169580[i] = 0;
    }
}

/*8000E1B4*/
u8 *loadTile(u16 tilenum)
{
    u8 i;
    u8 *ptr;
    u8 *romAddr;
    u16 size;
    u8 val;

    if (gpTileInfo[tilenum].ramaddr != NULL)
    {
        D_80169580[tilenum] = 0x82;
        return gpTileInfo[tilenum].ramaddr;
    }

    if (gpTileInfo[tilenum].flags & 0x80)
        size = (gpTileInfo[tilenum].dimx * gpTileInfo[tilenum].dimy);
    else
        size = (((gpTileInfo[tilenum].dimx * gpTileInfo[tilenum].dimy) / 2) + 32);

    if (size <= MAXTILESIZE)
    {
        D_80169580[tilenum] = 0x82;
        alloCache(&gpTileInfo[tilenum].ramaddr, size, &D_80169580[tilenum]);
        romAddr = _tileROMAddr;
        romAddr = romAddr + gpTileInfo[tilenum].fileoff;
        readRom(gTileBuffer, romAddr, (gpTileInfo[tilenum].filesize + 1) & ~1);

        if ((s16)(decompressEDL(gTileBuffer, gpTileInfo[tilenum].ramaddr)) != 0)
            Bmemcpy(gpTileInfo[tilenum].ramaddr, gTileBuffer, size);

        if (!(gpTileInfo[tilenum].flags & 0x80))
        {
            ptr = gpTileInfo[tilenum].ramaddr;
            for (i = 0; i < 16; i++)
            {
                val = *ptr;
                *ptr = *(ptr + 1);
                *(ptr + 1) = val;
                ptr += 2;
            }
        }
        return gpTileInfo[tilenum].ramaddr;
    }
    return NULL;
}

/*8000E3D4*/
s32 tileMasks(u16 arg0)
{
    switch (gpTileInfo[arg0].dimx)
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
s32 tileMaskt(u16 arg0)
{
    switch (gpTileInfo[arg0].dimy)
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
static void func_8000E56C(void)
{
    f32 xUp, yUp, zUp, xAt, yAt, zAt;

    u16 perspNorm;
    Matrix4f projection;
    Matrix4f viewing;

    xAt = sinf(D_801AEA10) * 512.0;
    yAt = cosf(D_801AEA10) * -512.0;
    zAt = (f64)(sinf(D_8016A15C) * 512.0) / cosf(D_8016A15C);

    grPerspectiveF(projection,
                   &perspNorm,
                   (15360.0 / gPlayer[D_801B0820].unk6E),
                   1.3333334f,
                   ((gPlayer[D_801B0820].unk6E * 5) / 256.0),
                   16384.0f,
                   (256.0 / gPlayer[D_801B0820].unk6E));

    grPerspective(&gpDynamic->mtx1[D_801B0820],
                  &perspNorm,
                  (15360.0 / gPlayer[D_801B0820].unk6E),
                  1.3333334f,
                  ((gPlayer[D_801B0820].unk6E * 5) / 256.0),
                  16384.0f,
                  (256.0 / gPlayer[D_801B0820].unk6E));

    D_801385F2 = perspNorm;

    xUp = sinf(D_801AC8E0) * cosf(D_801AEA10);
    yUp = sinf(D_801AC8E0) * sinf(D_801AEA10);
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

    grLookAtReflect(&gpDynamic->mtx2[D_801B0820],
                    &gpDynamic->lookat[D_801B0820][0],
                    gMapXpos * 0.5f,
                    gMapYpos * 0.5f,
                    gMapZpos * 0.5f,
                    (xAt + gMapXpos) * 0.5f,
                    (yAt + gMapYpos) * 0.5f,
                    (zAt + gMapZpos) * 0.5f,
                    xUp,
                    yUp,
                    zUp);

    gSPLookAtX(gpDisplayList++, &gpDynamic->lookat[D_801B0820][0].l[0]);
    gSPLookAtY(gpDisplayList++, &gpDynamic->lookat[D_801B0820][0].l[1]);
    gSPMatrix(gpDisplayList++, OS_K0_TO_PHYSICAL(&gpDynamic->mtx1[D_801B0820]), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gpDisplayList++, OS_K0_TO_PHYSICAL(&gpDynamic->mtx2[D_801B0820]), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
    gSPPerspNormalize(gpDisplayList++, perspNorm);
    grMtxCatF(viewing, projection, D_8012B948);
}

/*8000EA0C*/
void func_8000EA0C(u8 playernum, s16 arg1, s16 arg2, s16 arg3, s16 arg4)
{
    D_80138798[playernum][0] = CLAMP_MIN(CLAMP_MAX(D_80138798[playernum][0] + arg1, 255), 0);
    D_80138798[playernum][1] = CLAMP_MIN(CLAMP_MAX(D_80138798[playernum][1] + arg2, 255), 0);
    D_80138798[playernum][2] = CLAMP_MIN(CLAMP_MAX(D_80138798[playernum][2] + arg3, 255), 0);
    D_80138798[playernum][3] = CLAMP_MIN(D_80138798[playernum][3] + arg4, 0);
}

/*8000EB4C*/
void func_8000EB4C(u8 playernum, s16 arg1, s16 arg2, s16 arg3, s16 arg4)
{
    D_80138798[playernum][0] = arg1;
    D_80138798[playernum][1] = arg2;
    D_80138798[playernum][2] = arg3;
    D_80138798[playernum][3] = arg4;
}

/*8000EB90*/
void func_8000EB90(u8 playernum, s16 arg1, s16 arg2, s16 arg3, s16 arg4)
{
    D_8013F930[playernum][0] = arg1;
    D_8013F930[playernum][1] = arg2;
    D_8013F930[playernum][2] = arg3;
    D_8013F930[playernum][3] = arg4;
}

/*8000EBD4*/
s16 func_8000EBD4(u8 playernum)
{
    return D_80138798[playernum][3];
}

/*8000EBF0*/
INCLUDE_ASM("nonmatchings/src/code0/9410", func_8000EBF0);
