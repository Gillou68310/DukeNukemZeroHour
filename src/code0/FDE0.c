#include "common.h"
#include "code0/main.h"
#include "code0/16FF0.h"
#include "code0/graphics.h"
#include "code0/code0.h"

/*.data*/
/*800BD788*/ EXTERN_DATA s32 D_800BD788;
/*800D52E0*/ EXTERN_DATA ModelInfo *D_800D52E0[1320];
/*800D6780*/ EXTERN_DATA s16 D_800D6780; /*D_800D52E0 count*/

/*.comm*/
/*800FE414*/ u8 D_800FE414;

/*.text*/
STATIC s32 func_800115E0(ModelInfo *model);
STATIC s32 func_800117A4(u8 *, u8 *, u8 *);

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_8000F1E0);

/*8000F3C4*/
void func_8000F3C4(s16 r1, s16 g1, s16 b1, s16 r2, s16 g2, s16 b2)
{
    gSPLightColor(gpDisplayList++, LIGHT_1, ((r1<<24)+(g1<<16)+(b1<<8)));
    gSPLightColor(gpDisplayList++, LIGHT_2, ((r2<<24)+(g2<<16)+(b2<<8)));
}

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_8000F474);

/*80011148*/
static f32 func_80011148(Matrix4f mtx1, Matrix4f mtx2)
{
    return (mtx1[0][0] * mtx2[0][0]) + (mtx1[0][1] * mtx2[0][1]) + (mtx1[0][2] * mtx2[0][2]) + mtx1[0][3];
}

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

/*80012630*/
static void func_80012630(void)
{
    if (D_800FE414 == 0)
    {
        D_801A2688 = D_800FE414;
        gDPSetTextureLUT(gpDisplayList++, G_TT_RGBA16);
        if (D_8019956C == 0)
        {
            gDPSetCombineMode(gpDisplayList++, G_CC_MODULATEIDECALA, G_CC_PASS2);
            gDPSetRenderMode(gpDisplayList++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2);
        }
        else
        {
            gDPSetRenderMode(gpDisplayList++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_SURF2);
            gDPSetCombineLERP(gpDisplayList++, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
        }
    }
}

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_8001270C);

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_80013FFC);

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_80014040);

/*80014C24*/
static void func_80014C24(void)
{
    D_801ACC60 = 0;
}

/*80014C34*/
static void copyMatrix(Matrix4f dst, Matrix4f src)
{
    s32 i, j;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            dst[i][j] = src[i][j];
    }
}

/*80014C7C*/
static void func_80014C7C(f32 r, f32 p, f32 h, f32 s)
{
    func_80014C24();
    grPositionF(D_801B0830[0], r, p, h, s, 0.0, 0.0, 0.0);
}

/*80014D04*/
static void func_80014D04(Matrix4f mtx)
{
    D_801ACC60++;
    grMtxCatF(mtx, D_801B0830[D_801ACC60-1], D_801B0830[D_801ACC60]);
}

/*80014D4C*/
static void func_80014D4C(void)
{
    if (D_801ACC60 != 0)
        D_801ACC60--;
}

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_80014D6C);

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_800152AC);

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_80015458);

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_80015DE0);
