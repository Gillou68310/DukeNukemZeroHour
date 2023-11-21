#include "common.h"
#include "code0/main.h"
#include "code0/cache1d.h"
#include "code0/edl.h"
#include "code0/4600.h"
#include "code0/data/modelinfo.h"
#include "code0/code0.h"

/*Skip following declaration so it defaults to s32*/
/*#include "code0/9410.h"*/
/*u16 getTileNum(u16 tileid);*/
/*s32 tileMasks(u16);*/
/*s32 tileMaskt(u16);*/
u8 *loadTile(u16 tilenum);

extern u8 files_models_ROM_START[];

/*.text*/

/*800163F0*/
void func_800163F0(u8 arg0)
{
    u16 i;
    u16 *pal;
    u8 *ptr;

    if (D_801A2688 == 0)
    {
        if (D_8010A9AC == 0)
        {
            ptr = gpModelTile;
            pal = (u16 *)&ptr[gpModelTileInfo[arg0].offset];
            ptr = (u8 *)pal;

            for (i = 0; i < 16; i++)
            {
                if (pal[i] == 0xF83F)
                    pal[i] = 0x8420;
            }
            gDPLoadTLUT_pal16(gpDisplayList++, 0, ptr);
        }
        else if (D_8010A9AC == 1)
        {
            gDPLoadTLUT_pal16(gpDisplayList++, 0, loadTile(getTileNum(5741)));
        }
        else
        {
            gDPLoadTLUT_pal16(gpDisplayList++, 0, loadTile(getTileNum(3328)));
        }
    }
}

/*8001660C*/
void func_8001660C(u8 arg0)
{
    intptr_t pTile;
    s16 dimx, dimy;
    s32 dimx2, dimy2;
    s32 masks, maskt;
    s32 tilenum;

    if (D_8010A9AC == 0)
    {
        dimx = gpModelTileInfo[arg0].dimx;
        dimy = gpModelTileInfo[arg0].dimy;

        switch (dimx)
        {
        case 1:
            masks = 0;
            break;
        case 2:
            masks = 1;
            break;
        case 4:
            masks = 2;
            break;
        case 8:
            masks = 3;
            break;
        case 16:
            masks = 4;
            break;
        case 32:
            masks = 5;
            break;
        case 64:
            masks = 6;
            break;
        case 128:
            masks = 7;
            break;
        default:
            masks = 7;
            break;
        }

        switch (dimy)
        {
        case 1:
            maskt = 0;
            break;
        case 2:
            maskt = 1;
            break;
        case 4:
            maskt = 2;
            break;
        case 8:
            maskt = 3;
            break;
        case 16:
            maskt = 4;
            break;
        case 32:
            maskt = 5;
            break;
        case 64:
            maskt = 6;
            break;
        case 128:
            maskt = 7;
            break;
        default:
            maskt = 7;
            break;
        }

        pTile = (intptr_t)gpModelTile;
        pTile = (intptr_t)&((u8 *)pTile)[gpModelTileInfo[arg0].offset];

        if (D_801A2688 != 0)
        {
            if (D_80105718 != 0)
            {
                tilenum = 6050;
                tilenum += animateOffs(6050, 0);
                pTile = (intptr_t)loadTile(getTileNum(tilenum));
            }
            gDPLoadTextureBlock_4b(gpDisplayList++, pTile+32, G_IM_FMT_I,
                                   dimx, dimy, 0, 0, 0,
                                   masks, maskt, 0, 0);
        }
        else
        {
            gDPLoadTextureBlock_4b(gpDisplayList++, pTile+32, G_IM_FMT_CI,
                                   dimx, dimy, 0, 0, 0,
                                   masks, maskt, 0, 0);
        }
    }
    else
    {
        /*FAKEMATCH?*/
        pTile = getTileNum(5741);
        gDPLoadTextureBlock_4b(gpDisplayList++, loadTile(pTile)+32, G_IM_FMT_CI,
                               gpTileInfo[pTile].dimx, gpTileInfo[pTile].dimy, 0, 0, 0,
                               tileMasks(pTile), tileMaskt(pTile), 0, 0);
    }
}

/*80016D98*/
void loadModel(ModelInfo *model)
{
    u8 *romaddr;
    s32 size;

    model->lock = -126;
    if (model->ramaddr == NULL)
    {
        size = (model->unk8 + 1) & ~1;
        alloCache(&model->ramaddr, (((size + model->unk12) + 1) & ~1), (u8 *)&model->lock);
        model->unk18->ramaddr = &model->ramaddr[size];

        size = model->unkA;
        if (size < model->unk18->unkA)
            size = model->unk18->unkA;

        D_80169520 = 200;
        alloCache(&D_80138854, size, &D_80169520);
        size = model->unkA;
        romaddr = files_models_ROM_START;
        romaddr += model->fileoff;
        readRom(D_80138854, romaddr, ((size + 1) & ~1));

        if (decompressEDL(D_80138854, model->ramaddr) != 0)
            Bmemcpy(model->ramaddr, D_80138854, size);

        size = model->unk18->unkA;
        romaddr = files_models_ROM_START;
        romaddr += model->unk18->fileoff;
        readRom(D_80138854, romaddr, ((size + 1) & ~1));

        if (decompressEDL(D_80138854, model->unk18->ramaddr) != 0)
            Bmemcpy(model->unk18->ramaddr, D_80138854, size);

        suckCache(&D_80138854);
    }
}
