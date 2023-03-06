#include "common.h"
#include "code0/main.h"
#include "code0/cache1d.h"
#include "code0/edl.h"
#include "code0/4600.h"
#include "code0/FDE0.h"
#include "code0/code0.h"

extern u8 files_models_ROM_START[];

/*.text*/
INCLUDE_ASM("nonmatchings/src/code0/16FF0", func_800163F0);

INCLUDE_ASM("nonmatchings/src/code0/16FF0", func_8001660C);

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
