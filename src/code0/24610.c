#include "common.h"
#include "code0/main.h"
#include "code0/9410.h"
#include "code0/pragmas.h"
#include "code0/code0.h"

/*.bss*/
/*800F7040*/ EXTERN_BSS STATIC s32 D_800F7040;
/*800F7044*/ EXTERN_BSS STATIC s32 D_800F7044;
/*800F7048*/ EXTERN_BSS STATIC s32 D_800F7048;
/*800F704C*/ EXTERN_BSS STATIC f32 D_800F704C;
/*800F7050*/ EXTERN_BSS STATIC f32 D_800F7050;
/*800F7054*/ EXTERN_BSS STATIC s32 D_800F7054;

/*.comm*/
/*8010A9A8*/ SpriteType *D_8010A9A8;
/*80119A9C*/ s16 D_80119A9C;
/*801385F0*/ s8 D_801385F0;
/*80168810*/ s16 D_80168810;
/*801A689C*/ u8 D_801A689C;

/*.text*/
STATIC void func_8002433C(s16 spritenum, s32);
STATIC void func_80025C3C(s16 spritenum, s32);
STATIC void func_800273EC(s16 spritenum, s32);
STATIC void func_8002935C(s16 spritenum);

/*80023A10*/
void func_80023A10(void)
{
    D_8012DEFC = 0xFFFF;
    D_801A2688 = 0;
    D_80119A9C = 0xFF;
    D_801A689C = 0;
    D_800F704C = sinf(D_801AEA10 - (PI/2.0));
    D_800F7050 = cosf(D_801AEA10 - (PI/2.0));
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

/*80023C04*/
void func_80023C04(s32 spritenum, u16 arg1, s32 arg2)
{
    s16 alpha;
    s16 i, j, k;
    s32 ang;
    u16 cstat;
    u16 cstat2;

    D_8010A9A8 = &gpSprite[spritenum];
    if (!(D_8010A9A8->cstat & 0x8000) && (D_8010A9A8->xrepeat != 0))
    {
        D_800F7054 = getTileNum(D_8010A9A8->picnum);
        if (D_800F7054 != 1)
        {
            if (gpTileInfo[D_800F7054].picanm & 0xC0)
                D_800F7054 += animateOffs(D_8010A9A8->picnum, 0);

            D_80168810 = -1;

            if (gpSprite[spritenum].cstat & 0x800)
                D_80168810 = gpSprite[spritenum].unk25;

            if (D_80168810 != -1)
            {
                if (D_801A2688 == 0)
                {
                    D_801A2688 = 1;
                    gDPSetTextureLUT(gpDisplayList++, G_TT_NONE);

                    gDPSetCombineLERP(gpDisplayList++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                                                       0, 0, 0, COMBINED, 0, 0, 0, COMBINED);

                    gDPSetRenderMode(gpDisplayList++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_SURF2);
                    gDPSetColorDither(gpDisplayList++, G_CD_NOISE);
                }

                if (D_80119A9C != D_80168810)
                    D_80119A9C = D_80168810;
            }
            else
            {
                if (D_801A2688 != 0)
                {
                    D_801A2688 = 0;
                    D_801385F0 = 1;
                    gDPSetTextureLUT(gpDisplayList++, G_TT_RGBA16);
                    gDPSetCombineMode(gpDisplayList++, G_CC_MODULATEIDECALA, G_CC_PASS2);
                    gDPSetRenderMode(gpDisplayList++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2);
                    gDPSetColorDither(gpDisplayList++, G_CD_MAGICSQ);
                }
            }
            alpha = 0xFF - D_8013B2D0[spritenum].unk6;
            if (D_801A2688 == 0)
            {
                if (alpha < 0xFF)
                {
                    if (D_801385F0 == 1)
                    {
                        D_801385F0 = 0;
                        gDPSetCombineLERP(gpDisplayList++, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0,
                                                           0, 0, 0, COMBINED, 0, 0, 0, COMBINED);

                        gDPSetRenderMode(gpDisplayList++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_SURF2);
                    }
                }
                if ((alpha == 0xFF) && (D_801385F0 == 0))
                {
                    D_801385F0 = 1;
                    gDPSetCombineMode(gpDisplayList++, G_CC_MODULATEIDECALA, G_CC_PASS2);
                    gDPSetRenderMode(gpDisplayList++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2);
                }
            }

            gDPSetPrimColor(gpDisplayList++, 0, 0, gpAlphaPalette[D_80168810].primary.r,
                                                   gpAlphaPalette[D_80168810].primary.g,
                                                   gpAlphaPalette[D_80168810].primary.b,
                                                   alpha);

            gDPSetEnvColor(gpDisplayList++, gpAlphaPalette[D_80168810].env.r,
                                            gpAlphaPalette[D_80168810].env.g,
                                            gpAlphaPalette[D_80168810].env.b,
                                            alpha);

            if (D_8010A9A8->cstat & 0x800)
            {
                D_80138680 = 0xFF;
                D_800FE410 = 0xFF;
                D_8016A148 = 0xFF;
            }
            else
            {
                func_8000DBDC(gpSector[D_8010A9A8->sectnum].unk27, gpSector[D_8010A9A8->sectnum].unk26);
                i = D_8016A148;
                j = D_800FE410;
                k = D_80138680;
                func_8000DCF0(D_8010A9A8->x, D_8010A9A8->y, D_8010A9A8->z, D_8010A9A8->sectnum);
                D_8016A148 = CLAMP_MAX((i + D_8016A148), 0xFF);
                D_800FE410 = CLAMP_MAX((j + D_800FE410), 0xFF);
                D_80138680 = CLAMP_MAX((k + D_80138680), 0xFF);
            }

            cstat = D_8010A9A8->cstat;
            D_800F7040 = gpTileInfo[D_800F7054].dimx;
            D_800F7044 = gpTileInfo[D_800F7054].dimy;
            D_800F7048 = D_800F7040 * D_800F7044;

            if ((cstat & 0x30) == 0x10)
            {
                if (cstat & 0x40)
                {
                    ang = getAngle(D_8010A9A8->x - D_801A6D84, D_8010A9A8->y - D_800FE3F0) - D_8010A9A8->ang;

                    if (ang > 0x400)
                        ang -= 0x800;

                    if (ang < -0x400)
                        ang += 0x800;

                    if (klabs(ang) < 0x200)
                        return;
                }
            }

            cstat2 = D_8010A9A8->cstat;

            if (cstat2 & 0x400)
                func_80025C3C(spritenum, arg2);
            else
            {
                if ((cstat2 & 0x30) == 0x20)
                {
                    if (cstat2 & 0x40)
                    {
                        if (cstat2 & 8)
                        {
                            if (D_80199640 < D_8010A9A8->z)
                                return;
                        }
                        else
                        {
                            if (D_80199640 > D_8010A9A8->z)
                                return;
                        }
                    }

                    if (D_800F7048 <= 0x1000)
                        func_800273EC(spritenum, arg2);
                    else
                        func_80025C3C(spritenum, arg2);
                }
                else if ((cstat2 & 0x30) == 0x30)
                    func_8002935C(spritenum);
                else
                    func_8002433C(spritenum, arg2);
            }
        }
    }
}

/*8002433C*/
INCLUDE_ASM("nonmatchings/src/code0/24610", func_8002433C);

/*80025C3C*/
INCLUDE_ASM("nonmatchings/src/code0/24610", func_80025C3C);

/*800273EC*/
INCLUDE_ASM("nonmatchings/src/code0/24610", func_800273EC);

/*80027C18*/
INCLUDE_ASM("nonmatchings/src/code0/24610", func_80027C18);

/*80028F04*/
void func_80028F04(u8 r1, u8 g1, u8 b1, u8 r2, u8 g2, u8 b2)
{
    D_801A2688 = 1;
    gDPSetAlphaCompare(gpDisplayList++, G_AC_NONE);
    gDPSetTextureLUT(gpDisplayList++, G_TT_NONE);
    gDPSetRenderMode(gpDisplayList++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_SURF2);
    gDPSetCombineLERP(gpDisplayList++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
    gDPSetPrimColor(gpDisplayList++, 0, 0, r1, g1, b1, 0xFF);
    gDPSetEnvColor(gpDisplayList++, r2, g2, b2, 0xFF);
}

/*8002900C*/
void func_8002900C(u8 r1, u8 g1, u8 b1, u8 r2, u8 g2, u8 b2, u8 a)
{
    D_801A2688 = 1;
    gDPSetAlphaCompare(gpDisplayList++, G_AC_NONE);
    gDPSetTextureLUT(gpDisplayList++, G_TT_NONE);
    gDPSetRenderMode(gpDisplayList++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_SURF2);
    gDPSetCombineLERP(gpDisplayList++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
    gDPSetPrimColor(gpDisplayList++, 0, 0, r1, g1, b1, a);
    gDPSetEnvColor(gpDisplayList++, r2, g2, b2, a);
}

/*80029130*/
void func_80029130(u8 r1, u8 g1, u8 b1, u8 r2, u8 g2, u8 b2)
{
    D_801A2688 = 1;
    gDPSetAlphaCompare(gpDisplayList++, G_AC_NONE);
    gDPSetTextureLUT(gpDisplayList++, G_TT_NONE);
    gDPSetRenderMode(gpDisplayList++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineLERP(gpDisplayList++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
    gDPSetPrimColor(gpDisplayList++, 0, 0, r1, g1, b1, 0xFF);
    gDPSetEnvColor(gpDisplayList++, r2, g2, b2, 0xFF);
}

/*80029238*/
void func_80029238(u8 r1, u8 g1, u8 b1, u8 r2, u8 g2, u8 b2, u8 a)
{
    D_801A2688 = 1;
    gDPSetAlphaCompare(gpDisplayList++, G_AC_NONE);
    gDPSetTextureLUT(gpDisplayList++, G_TT_NONE);
    gDPSetRenderMode(gpDisplayList++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineLERP(gpDisplayList++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
    gDPSetPrimColor(gpDisplayList++, 0, 0, r1, g1, b1, a);
    gDPSetEnvColor(gpDisplayList++, r2, g2, b2, a);
}

/*8002935C*/
INCLUDE_ASM("nonmatchings/src/code0/24610", func_8002935C);
