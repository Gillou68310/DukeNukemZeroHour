#include "common.h"
#include "code0/20490.h"

/*.data*/

/*01001860*/
Gfx gRspInitDl[] = {
    gsSPViewport(&D_800DCB10),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_OFF),
    gsSPSetGeometryMode(G_SHADE | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

/*01001888*/
Gfx gRdpInitDl[] = {
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPPipelineMode(G_PM_1PRIMITIVE),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetCombineMode(G_CC_DECALRGB, G_CC_DECALRGB),
    gsDPSetCombineKey(G_CK_NONE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetRenderMode(G_RM_OPA_SURF, G_RM_OPA_SURF2),
    gsDPSetColorDither(G_CD_DISABLE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

/*01001900*/
Gfx D_01001900[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_SHADING_SMOOTH),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetCombineKey(G_CK_NONE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPNoOp(),
    gsDPSetColorDither(G_CD_BAYER),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_RA_ZB_OPA_SURF2),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_PASS2),
    gsDPSetAlphaDither(G_AD_NOISE),
    gsSPClipRatio(FRUSTRATIO_1),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

