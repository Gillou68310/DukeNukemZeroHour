#include "common.h"
#include "code0/4600.h"
#include "code0/cache1d.h"
#include "code0/edl.h"
#include "code0/main.h"
#include "code0/9410.h"

#define MAXTILES 6144
#define MAXTILESIZE 32832

/*.data*/
/*800BD724*/ EXTERN_DATA STATIC u8 *_tileROMAddr;

/*.comm*/
/*80107910*/ s16 gTilemap[MAXTILES] ALIGNED(16);
/*80169580*/ u8 D_80169580[TILENUM] ALIGNED(16);
/*8012FDA0*/ u8 gTileBuffer[MAXTILESIZE] ALIGNED(16);

/*.text*/

INCLUDE_ASM(s32, "src/code0/9410", func_80008810);

INCLUDE_ASM(s32, "src/code0/9410", func_80008B88);

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

INCLUDE_ASM(s32, "src/code0/9410", func_8000D22C);

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
u16 getTileId(u16 tilenum)
{
    u16 tileid;

    if (tilenum == 0)
    {
        return 0;
    }
    tileid = gTilemap[tilenum];
    if (tileid == MAXTILES)
    {
        return 1;
    }
    else
    {
        return tileid;
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
static void func_8000E160(void)
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
u8 *tileLoad(u16 tileid)
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
    {
        size = (gpTileInfo[tileid].dimx * gpTileInfo[tileid].dimy);
    }
    else
    {
        size = (((gpTileInfo[tileid].dimx * gpTileInfo[tileid].dimy) / 2) + 32);
    }
    if (size <= MAXTILESIZE)
    {
        D_80169580[tileid] = 0x82;
        alloCache(&gpTileInfo[tileid].ramaddr, size, &D_80169580[tileid]);
        romAddr = _tileROMAddr;
        romAddr = romAddr + gpTileInfo[tileid].fileoff;
        readRom(gTileBuffer, romAddr, (gpTileInfo[tileid].filesize + 1) & ~1);
        if ((s16)(decompressEDL(gTileBuffer, gpTileInfo[tileid].ramaddr)) != 0)
        {
            Bmemcpy(gpTileInfo[tileid].ramaddr, gTileBuffer, size);
        }
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

INCLUDE_ASM(s32, "src/code0/9410", tileMasks);

INCLUDE_ASM(s32, "src/code0/9410", tileMaskt);

INCLUDE_ASM(s32, "src/code0/9410", func_8000E56C);

INCLUDE_ASM(s32, "src/code0/9410", func_8000EA0C);

INCLUDE_ASM(s32, "src/code0/9410", func_8000EB4C);

INCLUDE_ASM(s32, "src/code0/9410", func_8000EB90);

INCLUDE_ASM(s32, "src/code0/9410", func_8000EBD4);

INCLUDE_ASM(s32, "src/code0/9410", func_8000EBF0);

INCLUDE_ASM(s32, "src/code0/9410", func_8000F1E0);

INCLUDE_ASM(s32, "src/code0/9410", func_8000F3C4);

INCLUDE_ASM(s32, "src/code0/9410", func_8000F474);

INCLUDE_ASM(s32, "src/code0/9410", func_80011148);

INCLUDE_ASM(s32, "src/code0/9410", func_80011180);

INCLUDE_ASM(s32, "src/code0/9410", func_80011410);

INCLUDE_ASM(s32, "src/code0/9410", func_800115E0);

INCLUDE_ASM(s32, "src/code0/9410", func_80011700);

INCLUDE_ASM(s32, "src/code0/9410", func_800117A4);

INCLUDE_ASM(s32, "src/code0/9410", func_80011DA8);

INCLUDE_ASM(s32, "src/code0/9410", func_80012174);

INCLUDE_ASM(s32, "src/code0/9410", func_80012318);

INCLUDE_ASM(s32, "src/code0/9410", func_800124EC);

INCLUDE_ASM(s32, "src/code0/9410", func_80012630);

INCLUDE_ASM(s32, "src/code0/9410", func_8001270C);

INCLUDE_ASM(s32, "src/code0/9410", func_80013FFC);

INCLUDE_ASM(s32, "src/code0/9410", func_80014040);

INCLUDE_ASM(s32, "src/code0/9410", func_80014C24);

INCLUDE_ASM(s32, "src/code0/9410", func_80014C34);

INCLUDE_ASM(s32, "src/code0/9410", func_80014C7C);

INCLUDE_ASM(s32, "src/code0/9410", func_80014D04);

INCLUDE_ASM(s32, "src/code0/9410", func_80014D4C);

INCLUDE_ASM(s32, "src/code0/9410", func_80014D6C);

INCLUDE_ASM(s32, "src/code0/9410", func_800152AC);

INCLUDE_ASM(s32, "src/code0/9410", func_80015458);

INCLUDE_ASM(s32, "src/code0/9410", func_80015DE0);
