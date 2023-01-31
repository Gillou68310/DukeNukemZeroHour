#include "common.h"
#include "code0/4600.h"
#include "code0/cache1d.h"
#include "code0/edl.h"
#include "code0/main.h"
#include "code0/audio.h"
#include "code0/9410.h"
#include "code0/FDE0.h"
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
#include "code0/7CBC0.h"
#include "code0/87010.h"
#include "code0/95500.h"
#include "code0/A06F0.h"
#include "code1/EB300.h"
#include "code1/code1.h"

#define MAXTILESIZE 32832

#define SATURATE_U8(A) \
    (((A) >= 256) ? 255 : A)

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
/*801385F4*/ s16 D_801385F4;
/*80138694*/ s16 D_80138694;
/*80169580*/ u8 D_80169580[TILENUM] ALIGNED(16);
/*80199118*/ s16 D_80199118;
/*80199554*/ s32 D_80199554;
/*80199650*/ u16 D_80199650[128] ALIGNED(8);
/*80199946*/ s16 D_80199946;
/*8019996C*/ s32 D_8019996C;
/*801A19A0*/ s16 D_801A19A0[32] ALIGNED(8);
/*801A2690*/ u16 D_801A2690[128] ALIGNED(8);
/*801AC9EC*/ s32 D_801AC9EC;
/*801C0D6C*/ s16 D_801C0D6C;

/*.text*/
static void initTiles(void);
static u8 func_800099D0(void);
static void floorVtxToN64(s32 secnum);
static void floorVtxToN64Z(s32 secnum, s32 z);
static void ceilingVtxToN64(s32 secnum);

STATIC void decompressMap(void);
STATIC void func_80009A14(u8);
static void func_8000A938(u16 wallnum);
STATIC void func_8000AEE0(u16 wallnum);
STATIC void func_8000B9C0(s16 tileid);
STATIC void func_8000CC54(s32 wallnum);
STATIC void func_8000EBF0(u8, u8);

/*80008810*/
void loadMap(s32 mapnum)
{
    s32 i;
    code0UnkStruct5 *ptr;

    MusStop(3U, 0);
    cache1d_8002AAEC();
    func_801C14D4();
    gNumSectors = gpMapInfo[mapnum].sectors;
    gNumSprites = gpMapInfo[mapnum].sprites;
    gNumWalls = gpMapInfo[mapnum].walls;
    alloCache(&gpSector, gNumSectors * sizeof(SectorType), &_sectorsLock);
    alloCache(&gpWall, gNumWalls * sizeof(WallType), &_wallsLock);
    alloCache(&gpSprite, MAXSPRITES * sizeof(SpriteType), &_spritesLock);
    Bmemset(gpSprite, 0U, MAXSPRITES * sizeof(SpriteType));
    func_80004C84();
    gMapNum = mapnum;
    Bmemset(&D_801A1958, 0U, 0x14U);
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

    func_80008710(gMapNum);
    func_8000EB4C(4U, 0, 0, 0, 0x120);
    func_80094958();
    func_8007AEB4();
    func_80086410();
    func_80001CFC();
    func_800A0E74();
    func_80051568();
    D_800FEA90 = 0;
    D_801AE914 = 0;
    D_800E1748 = -1;
}

#ifdef NON_MATCHING
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
        D_80117ED8[i].xpos = (s32)(2.0f * gMapXpos);
        D_80117ED8[i].ypos = (s32)(2.0f * gMapYpos);
        D_80117ED8[i].zpos = (s32)(32.0f * gMapZpos);
        updateSector(D_80117ED8[i].xpos, D_80117ED8[i].ypos, &D_80117ED8[i].sectnum);
        floorz = getFlorzOfSlope(D_80117ED8[i].sectnum, D_80117ED8[i].xpos, D_80117ED8[i].ypos);
        D_80117ED8[i].zpos = floorz - 0x3900;
        D_80117ED8[i].unk_38 = gpMapInfo[gMapNum].unk2C;
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
    s32 i;

    func_80040AA0(3, "DR");
    func_80040B2C(3);
    D_801A6D80 = 0;
    D_8012BBCC = 0;
    D_8012F6F0[0] = 0;
    D_8012F6F0[1] = 0;
    D_8012F6F0[2] = 0;
    D_8012F6F0[3] = 0;
    D_801B0820 = 0;

    for (D_801B0820; D_801B0820 < D_8012C470; D_801B0820++)
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

        func_80029130(0xFF, 0x80, 0, 0, 0, 0);
        if ((D_8012C470 == 3) && (D_800DCBD5 == 0))
        {
            func_8001C9E4(0xCF, 0xA4, buffer);
        }
        else
        {
            func_8001CBAC(-1, 0x70, buffer);
        }
    }
    if (!func_800099D0() && (D_800DF98C != 0))
    {
        func_8000A070();
        debugMenu();
    }
    func_80020510();
    if (D_801AE914 != 0)
    {
        func_8000EB4C(4U, 0, 0, 0, 0xC4);
    }
    func_8000EBF0(4, 0);

    gDisplayListSize = ((uintptr_t)gpDisplayList - (uintptr_t)gDisplayList[gGfxTaskIndex]) / sizeof(Gfx);
    gVertexN64Size = ((uintptr_t)gpVertexN64 - (uintptr_t)gVertexN64[gGfxTaskIndex]) / sizeof(Vtx);

    for (i = 0; i < D_8012C470; i++)
    {
        D_8019B940[D_80106D50[D_80117ED8[i].unk_4A]].unk_00 &= ~0x100;
    }
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
    return gDisplayListRemainingSize < 2048U;
}

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
            if ((tileid == 0x14B4) || (tileid == 0x17C0))
            {
                if (D_800BD74B == 0)
                {
                    D_800BD74B = 1;
                    gSPSetGeometryMode(gpDisplayList++, G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
                    gSPTexture(gpDisplayList++, 0x7FC0, 0x7FC0, 0, G_TX_RENDERTILE, G_ON);
                }
                func_8000C76C();
                func_8000DBDC(gpWall[wallnum].unk20, gpWall[wallnum].unk1C);
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

#ifdef NON_MATCHING
STATIC void func_8000B9C0(s16 tileid)
{
    s16 tilenum;

    if (D_801CDBCC != 0)
    {
        tileid = 0x173C;
    }

    if (D_8012DEFC == tileid)
        return;

    tilenum = getTileNum(tileid);
    if (gpTileInfo[tilenum].picanm&192)
    {
        tilenum += animateOffs(tileid, 0);
    }

    gDPLoadTLUT_pal16(gpDisplayList++, 0, loadTile(tilenum));
    gDPLoadTextureBlock_4b(gpDisplayList++, loadTile(tilenum)+32, G_IM_FMT_CI,
                           gpTileInfo[tilenum].dimx, gpTileInfo[tilenum].dimy, 0, 0, 0,
                           tileMasks(tilenum), tileMaskt(tilenum), 0, 0);

    D_8012DEFC = tileid;
    D_801AC9EC++;
}
#else
/*8000B9C0*/
INCLUDE_ASM("nonmatchings/src/code0/9410", func_8000B9C0);
#endif

/*8000BDB0*/
void func_8000BDB0(s16 tileid)
{
    s16 tilenum;

    if (D_8012DEFC == tileid)
        return;

    tilenum = getTileNum(tileid);
    if (gpTileInfo[tilenum].picanm&192)
    {
        tilenum += animateOffs(tileid, 0);
    }

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
                {
                    func_8000B9C0(gpWall[gpWall[wallnum].nextwall].picnum);
                }
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
            gDPSetEnvColor(gpDisplayList++, 0xFF, 0xFF, 0xFF, gpSprite[spriteIndex].shade);
            func_8000B9C0(gpSprite[spriteIndex].unk1E);
            func_8000B570(D_80199554);
        }
    }
}

/*8000CA94*/
static void drawFloorCeiling(void)
{
    s32 i;
    u16 secnum;

    for (i = 0; i < D_80199528; i++)
    {
        secnum = D_801A2690[i];
        if (gpSector[secnum].floorvtxnum != 0)
        {
            if (D_800DF2F4[secnum] & 1)
            {
                func_80004A3C(secnum);
                D_800DF2F4[secnum]--;
            }
            floorVtxToN64(secnum);
            func_8000B9C0(gpSector[secnum].floorpicnum);
            func_8000B570(D_80199554);
        }
    }

    for (i = 0; i < D_80168D10; i++)
    {
        secnum = D_80199650[i];
        if (gpSector[secnum].ceilingvtxnum != 0)
        {
            if (D_800DF2F4[secnum] & 2)
            {
                func_80004B60(secnum);
                D_800DF2F4[secnum] -= 2;
            }
            ceilingVtxToN64(secnum);
            func_8000B9C0(gpSector[secnum].ceilingpicnum);
            func_8000B570(D_80199554);
        }
    }
}

INCLUDE_ASM("nonmatchings/src/code0/9410", func_8000CC54);

#define VERTEX2N64(N64, VTX, Z) \
        N64->v.ob[0] = VTX->v.ob[0]; \
        N64->v.ob[1] = VTX->v.ob[1]; \
        N64->v.ob[2] = Z; \
        N64->v.tc[0] = VTX->v.tc[0]; \
        N64->v.tc[1] = VTX->v.tc[1]; \
        N64->v.cn[0] = SATURATE_U8(VTX->v.cn[0] + D_8016A148); \
        N64->v.cn[1] = SATURATE_U8(VTX->v.cn[1] + D_800FE410); \
        N64->v.cn[2] = SATURATE_U8(VTX->v.cn[2] + D_80138680); 

/*8000D22C*/
static void floorVtxToN64(s32 secnum)
{
    s32 i;
    VertexType *vtx;

    D_80199554 = 0;
    D_801385F4 = 0;
    vtx = &gpVertex[gpSector[secnum].floorvtxptr];
    func_8000DBDC(gpSector[secnum].unk27, gpSector[secnum].unk26);

    for (i = 0; i < gpSector[secnum].floorvtxnum; i++)
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
static void floorVtxToN64Z(s32 secnum, s32 z)
{
    s32 i;
    VertexType *vtx;

    D_80199554 = 0;
    D_801385F4 = 0;
    vtx = &gpVertex[gpSector[secnum].floorvtxptr];
    func_8000DBDC(gpSector[secnum].unk27, gpSector[secnum].unk26);

    for (i = 0; i < gpSector[secnum].floorvtxnum; i++)
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
static void ceilingVtxToN64(s32 secnum)
{
    s32 i;
    VertexType *vtx;

    D_80199554 = 0;
    D_801385F4 = 0;
    vtx = &gpVertex[gpSector[secnum].ceilingvtxptr];
    func_8000DBDC(gpSector[secnum].unk23, gpSector[secnum].unk22);

    for (i = 0; i < gpSector[secnum].ceilingvtxnum; i++)
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

INCLUDE_ASM("nonmatchings/src/code0/9410", func_8000DBDC);

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
    {
        return 0;
    }
    tilenum = gTilemap[tileid];
    if (tilenum == MAXTILES)
    {
        return 1;
    }
    else
    {
        return tilenum;
    }
}

/*8000E0D8*/
static void initTileMap(void)
{
    u16 i;

    for (i = 0; i < MAXTILES; i++)
    {
        gTilemap[i] = MAXTILES;
    }
    for (i = 0; i < TILENUM; i++)
    {
        gTilemap[gpTileInfo[i].tileid] = i;
    }
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
    {
        size = (gpTileInfo[tilenum].dimx * gpTileInfo[tilenum].dimy);
    }
    else
    {
        size = (((gpTileInfo[tilenum].dimx * gpTileInfo[tilenum].dimy) / 2) + 32);
    }
    if (size <= MAXTILESIZE)
    {
        D_80169580[tilenum] = 0x82;
        alloCache(&gpTileInfo[tilenum].ramaddr, size, &D_80169580[tilenum]);
        romAddr = _tileROMAddr;
        romAddr = romAddr + gpTileInfo[tilenum].fileoff;
        readRom(gTileBuffer, romAddr, (gpTileInfo[tilenum].filesize + 1) & ~1);
        if ((s16)(decompressEDL(gTileBuffer, gpTileInfo[tilenum].ramaddr)) != 0)
        {
            Bmemcpy(gpTileInfo[tilenum].ramaddr, gTileBuffer, size);
        }
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

INCLUDE_ASM("nonmatchings/src/code0/9410", tileMasks);

INCLUDE_ASM("nonmatchings/src/code0/9410", tileMaskt);

INCLUDE_ASM("nonmatchings/src/code0/9410", func_8000E56C);

INCLUDE_ASM("nonmatchings/src/code0/9410", func_8000EA0C);

INCLUDE_ASM("nonmatchings/src/code0/9410", func_8000EB4C);

INCLUDE_ASM("nonmatchings/src/code0/9410", func_8000EB90);

INCLUDE_ASM("nonmatchings/src/code0/9410", func_8000EBD4);

INCLUDE_ASM("nonmatchings/src/code0/9410", func_8000EBF0);
