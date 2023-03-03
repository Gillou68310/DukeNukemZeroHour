#include "common.h"
#include "code0/16FF0.h"
#include "code0/graphics.h"
#include "code0/code0.h"

/*.data*/
/*800BD788*/ EXTERN_DATA s32 D_800BD788;
/*800D52E0*/ EXTERN_DATA ModelInfo *D_800D52E0[1320];
/*800D6780*/ EXTERN_DATA s16 D_800D6780; /*D_800D52E0 count*/

/*.text*/
STATIC s32 func_800115E0(ModelInfo *model);
STATIC s32 func_800117A4(u8 *, u8 *, u8 *);

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_8000F1E0);

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_8000F3C4);

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_8000F474);

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_80011148);

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_80011180);

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_80011410);

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_800115E0);

/*80011700*/
void func_80011700(ModelInfo *model)
{
    u8 *ramaddr1;
    u8 *ramaddr2;
    u8 *ramaddr3;
    _FDE0UnkStruct1 *ptr;

    loadModel(model);
    ramaddr1 = model->ramaddr + model->unkE;
    ptr = model->unk18;
    ramaddr2 = ptr->ramaddr;
    ramaddr3 = model->ramaddr + model->unk10;
    D_800FE944 = model->ramaddr;
    D_80138714 = model->ramaddr + model->unkC;
    if ((D_800BD788 == 0) || (func_800115E0(model) != 0))
        func_800117A4(ramaddr1, ramaddr2, ramaddr3);
}

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_800117A4);

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_80011DA8);

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_80012174);

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_80012318);

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_800124EC);

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_80012630);

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_8001270C);

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_80013FFC);

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_80014040);

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_80014C24);

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_80014C34);

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_80014C7C);

/*80014D04*/
static void func_80014D04(Matrix4f mtx)
{
    D_801ACC60++;
    grMtxCatF(mtx, D_801B0830[D_801ACC60-1], D_801B0830[D_801ACC60]);
}

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_80014D4C);

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_80014D6C);

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_800152AC);

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_80015458);

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_80015DE0);
