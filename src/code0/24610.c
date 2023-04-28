#include "common.h"
#include "code0/main.h"
#include "code0/code0.h"

/*.bss*/
/*800F704C*/ EXTERN_BSS STATIC f32 D_800F704C;
/*800F7050*/ EXTERN_BSS STATIC f32 D_800F7050;

/*.comm*/
extern s8 D_801A689C;

/*.text*/

/*80023A10*/
void func_80023A10(void)
{
    D_8012DEFC = 0xFFFF;
    D_801A2688 = 0;
    D_80119A9C = 0xFF;
    D_801A689C = 0;
    D_800F704C = sinf(D_801AEA10 - 1.570796326795);
    D_800F7050 = cosf(D_801AEA10 - 1.570796326795);
    D_801385F0 = 1;

    gDPSetTextureFilter(gpDisplayList++, G_TF_BILERP);
    gDPSetAlphaCompare(gpDisplayList++, G_AC_NONE);
    gDPSetTextureLUT(gpDisplayList++, G_TT_RGBA16);
    gDPSetColorDither(gpDisplayList++, G_CD_MAGICSQ);
    gSPClearGeometryMode(gpDisplayList++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gSPSetGeometryMode(gpDisplayList++, G_ZBUFFER | G_SHADE | G_FOG | G_SHADING_SMOOTH);
    gDPSetTexturePersp(gpDisplayList++, G_TP_PERSP);
    gDPSetDepthSource(gpDisplayList++, G_ZS_PIXEL);
    gDPSetRenderMode(gpDisplayList++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2);
    gDPSetCombineMode(gpDisplayList++, G_CC_MODULATEIDECALA, G_CC_PASS2);
    gDPSetPrimDepth(gpDisplayList++, 0, 0);
}

INCLUDE_ASM("nonmatchings/src/code0/24610", func_80023C04);

INCLUDE_ASM("nonmatchings/src/code0/24610", func_8002433C);

INCLUDE_ASM("nonmatchings/src/code0/24610", func_80025C3C);

INCLUDE_ASM("nonmatchings/src/code0/24610", func_800273EC);

INCLUDE_ASM("nonmatchings/src/code0/24610", func_80027C18);

/*80028F04*/
void func_80028F04(u8 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5)
{
    D_801A2688 = 1;
    gDPSetAlphaCompare(gpDisplayList++, G_AC_NONE);
    gDPSetTextureLUT(gpDisplayList++, G_TT_NONE);
    gDPSetRenderMode(gpDisplayList++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_SURF2);
    gDPSetCombineLERP(gpDisplayList++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
    gDPSetPrimColor(gpDisplayList++, 0, 0, arg0, arg1, arg2, 0xFF);
    gDPSetEnvColor(gpDisplayList++, arg3, arg4, arg5, 0xFF);
}

/*8002900C*/
void func_8002900C(u8 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6)
{
    D_801A2688 = 1;
    gDPSetAlphaCompare(gpDisplayList++, G_AC_NONE);
    gDPSetTextureLUT(gpDisplayList++, G_TT_NONE);
    gDPSetRenderMode(gpDisplayList++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_SURF2);
    gDPSetCombineLERP(gpDisplayList++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
    gDPSetPrimColor(gpDisplayList++, 0, 0, arg0, arg1, arg2, arg6);
    gDPSetEnvColor(gpDisplayList++, arg3, arg4, arg5, arg6);
}

/*80029130*/
void func_80029130(u8 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5)
{
    D_801A2688 = 1;
    gDPSetAlphaCompare(gpDisplayList++, G_AC_NONE);
    gDPSetTextureLUT(gpDisplayList++, G_TT_NONE);
    gDPSetRenderMode(gpDisplayList++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineLERP(gpDisplayList++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
    gDPSetPrimColor(gpDisplayList++, 0, 0, arg0, arg1, arg2, 0xFF);
    gDPSetEnvColor(gpDisplayList++, arg3, arg4, arg5, 0xFF);
}

/*80029238*/
void func_80029238(u8 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6)
{
    D_801A2688 = 1;
    gDPSetAlphaCompare(gpDisplayList++, G_AC_NONE);
    gDPSetTextureLUT(gpDisplayList++, G_TT_NONE);
    gDPSetRenderMode(gpDisplayList++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineLERP(gpDisplayList++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
    gDPSetPrimColor(gpDisplayList++, 0, 0, arg0, arg1, arg2, arg6);
    gDPSetEnvColor(gpDisplayList++, arg3, arg4, arg5, arg6);
}

INCLUDE_ASM("nonmatchings/src/code0/24610", func_8002935C);
