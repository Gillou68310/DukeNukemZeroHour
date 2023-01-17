#include "common.h"
#include "code0/4600.h"
#include "code0/cache1d.h"
#include "code0/edl.h"
#include "code0/main.h"
#include "code0/audio.h"
#include "code0/9410.h"
#include "code0/1A7C0.h"
#include "code0/1E7A0.h"
#include "code0/7BA50.h"
#include "code0/8E670.h"
#include "code0/609D0.h"
#include "code0/41940.h"
#include "code0/87010.h"
#include "code0/95500.h"
#include "code0/A06F0.h"
#include "code1/EB300.h"

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

/*.comm*/
/*80107910*/ s16 gTilemap[MAXTILES] ALIGNED(16);
/*80169580*/ u8 D_80169580[TILENUM] ALIGNED(16);
/*8012FDA0*/ u8 gTileBuffer[MAXTILESIZE] ALIGNED(16);
/*80105708*/ u8 *gpMapBuffer;

/*.text*/
STATIC void decompressMap(void);
static void initTiles(void);

/*80008810*/
void loadMap(s32 mapnum)
{
    code0UnkStruct5 *ptr;
    s32 i;

    MusStop(3U, 0);
    cache1d_8002AAEC();
    func_801C14D4();
    gNumSectors = gpMapInfo[mapnum].sectors;
    gNumSprites = gpMapInfo[mapnum].sprites;
    gNumWalls = gpMapInfo[mapnum].walls;
    alloCache((u8 **)&gpSector, gNumSectors * sizeof(SectorType), &_sectorsLock);
    alloCache((u8 **)&gpWall, gNumWalls * sizeof(WallType), &_wallsLock);
    alloCache((u8 **)&gpSprite, MAXSPRITES * sizeof(SpriteType), &_spritesLock);
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
    D_801AE4A0[0].unk0 = D_801AE4A0[0].unk6 = 0x32;
    D_801AE4A0[0].unk8 = 0x32;
    D_801AE4A0[0].unk2 = 0x32;
    D_801AE4A0[0].unkA = 0x46;
    D_801AE4A0[0].unk4 = 0x46;
    D_801AE4A0[0].unk16 = 0x3DE;
    D_801AE4A0[0].unk12 = 0x3DE;
    D_801AE4A0[0].unk18 = 0x3ED;
    D_801AE4A0[0].unk14 = 0x3ED;
    D_801AE4A0[0].unk1E = 0;
    Bmemcpy(&D_801AE4A0[1], &D_801AE4A0[0], sizeof(code0UnkStruct6));
    Bmemcpy(&D_801AE4A0[2], &D_801AE4A0[0], sizeof(code0UnkStruct6));
    Bmemcpy(&D_801AE4A0[3], &D_801AE4A0[0], sizeof(code0UnkStruct6));
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
    decompressEDL(&gpMapBuffer[offset], (u8 *)gpSector);

    offset = gpMapInfo[gMapNum].wall_offset;
    decompressEDL(&gpMapBuffer[offset], (u8 *)gpWall);

    offset = gpMapInfo[gMapNum].sprite_offset;
    decompressEDL(&gpMapBuffer[offset], (u8 *)gpSprite);

    count = 0;
    for (i = 0; i<gNumSectors; i++)
    {
        count += gpSector[i].unk2B;
        count += gpSector[i].unk2C;
    }

    count *= 3;
    alloCache((u8 **)&gpVertex, (count * sizeof(VertexType)), &_vertexLock);
    decompressEDL(&gpMapBuffer[0], (u8 *)gpVertex);
    suckCache(&gpMapBuffer);
    initTiles();

    for (i = 0; i < 4; i++)
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
INCLUDE_ASM(s32, "src/code0/9410", decompressMap);
#endif

INCLUDE_ASM(s32, "src/code0/9410", func_80008E3C);

INCLUDE_ASM(s32, "src/code0/9410", func_8000921C);

INCLUDE_ASM(s32, "src/code0/9410", func_80009314);

INCLUDE_ASM(s32, "src/code0/9410", func_80009998);

INCLUDE_ASM(s32, "src/code0/9410", func_800099D0);

INCLUDE_ASM(s32, "src/code0/9410", func_80009A14);

INCLUDE_ASM(s32, "src/code0/9410", func_8000A070);

INCLUDE_ASM(s32, "src/code0/9410", func_8000A174);

INCLUDE_ASM(s32, "src/code0/9410", func_8000A184);

INCLUDE_ASM(s32, "src/code0/9410", func_8000A634);

INCLUDE_ASM(s32, "src/code0/9410", func_8000A938);

INCLUDE_ASM(s32, "src/code0/9410", func_8000AEE0);

INCLUDE_ASM(s32, "src/code0/9410", func_8000B570);

INCLUDE_ASM(s32, "src/code0/9410", func_8000B6A8);

INCLUDE_ASM(s32, "src/code0/9410", func_8000B830);

INCLUDE_ASM(s32, "src/code0/9410", func_8000B9C0);

INCLUDE_ASM(s32, "src/code0/9410", func_8000BDB0);

INCLUDE_ASM(s32, "src/code0/9410", func_8000C0D0);

INCLUDE_ASM(s32, "src/code0/9410", func_8000C3E4);

INCLUDE_ASM(s32, "src/code0/9410", func_8000C76C);

INCLUDE_ASM(s32, "src/code0/9410", func_8000C7A4);

INCLUDE_ASM(s32, "src/code0/9410", func_8000C8EC);

INCLUDE_ASM(s32, "src/code0/9410", func_8000CA94);

INCLUDE_ASM(s32, "src/code0/9410", func_8000CC54);

#define SATURATE_U8(A) \
    (((A) >= 256) ? 255 : A)

#define VERTEX2N64(N64, VTX) \
        N64->v.ob[0] = VTX->v.ob[0]; \
        N64->v.ob[1] = VTX->v.ob[1]; \
        N64->v.ob[2] = VTX->v.ob[2]; \
        N64->v.tc[0] = VTX->v.tc[0]; \
        N64->v.tc[1] = VTX->v.tc[1]; \
        N64->v.cn[0] = SATURATE_U8(VTX->v.cn[0] + D_8016A148); \
        N64->v.cn[1] = SATURATE_U8(VTX->v.cn[1] + D_800FE410); \
        N64->v.cn[2] = SATURATE_U8(VTX->v.cn[2] + D_80138680); \
        N64->v.cn[3] = 0x9B;

/*8000D22C*/
static void vertexToN64(s32 secnum)
{
    s32 i;
    VertexType *vtx;

    D_80199554 = 0;
    D_801385F4 = 0;
    vtx = &gpVertex[gpSector[secnum].vtxptr];
    func_8000DBDC(gpSector[secnum].unk27, gpSector[secnum].unk26, gpVertex);
    for (i = 0; i < gpSector[secnum].unk2B; i++)
    {
        VERTEX2N64(gpVertexN64, vtx);
        vtx++;
        gpVertexN64++;

        VERTEX2N64(gpVertexN64, vtx);
        vtx++;
        gpVertexN64++;

        VERTEX2N64(gpVertexN64, vtx);
        vtx++;
        gpVertexN64++;

        D_801385F4++;
    }
    D_80199554 = D_801385F4;
}

INCLUDE_ASM(s32, "src/code0/9410", func_8000D574);

INCLUDE_ASM(s32, "src/code0/9410", func_8000D894);

INCLUDE_ASM(s32, "src/code0/9410", func_8000DBDC);

INCLUDE_ASM(s32, "src/code0/9410", func_8000DCF0);

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

INCLUDE_ASM(s32, "src/code0/9410", tileMasks);

INCLUDE_ASM(s32, "src/code0/9410", tileMaskt);

INCLUDE_ASM(s32, "src/code0/9410", func_8000E56C);

INCLUDE_ASM(s32, "src/code0/9410", func_8000EA0C);

INCLUDE_ASM(s32, "src/code0/9410", func_8000EB4C);

INCLUDE_ASM(s32, "src/code0/9410", func_8000EB90);

INCLUDE_ASM(s32, "src/code0/9410", func_8000EBD4);

INCLUDE_ASM(s32, "src/code0/9410", func_8000EBF0);
