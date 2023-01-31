#include "common.h"
#include "code0/graphics.h"
#include "code0/code0.h"

/*.text*/

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_8000F1E0);

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_8000F3C4);

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_8000F474);

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_80011148);

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_80011180);

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_80011410);

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_800115E0);

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_80011700);

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
