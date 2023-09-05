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
static void func_800273EC(s16 spritenum, s32);
static void func_8002935C(s16 spritenum);

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
    gSPClearGeometryMode(gpDisplayList++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN
                                        | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
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
static void func_800273EC(s16 spritenum, s32 arg1)
{
    f32 f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11;
    s32 i, j;
    u16 dimy, dimx, dimx1, dimy1, x, y;

    if (D_801A689C != 0)
    {
        func_8000C76C();
        D_801A689C = 0;
    }

    if (D_801A2688 != 0)
        func_8000BDB0(D_8010A9A8->picnum);
    else if (D_8010A9A8->cstat & 0x2000)
        func_8000C3E4(D_800F7054);
    else
        func_8000C0D0(D_800F7054);

    dimy1 = 0;
    if (D_8010A9A8->cstat & 8)
        dimy = gpTileInfo[D_800F7054].dimy;
    else
    {
        dimy = 0;
        dimy1 = gpTileInfo[D_800F7054].dimy;
    }

    dimx1 = 0;
    if (D_8010A9A8->cstat & 4)
        dimx = gpTileInfo[D_800F7054].dimx;
    else
    {
        dimx = 0;
        dimx1 = gpTileInfo[D_800F7054].dimx;
    }

    x = (gpTileInfo[D_800F7054].sizex * D_8010A9A8->xrepeat) / 16;
    y = (gpTileInfo[D_800F7054].sizey * D_8010A9A8->yrepeat) / 16;

    if (D_8010A9A8->cstat & 0x2000)
    {
        if (dimx == 0)
            dimx1 = (x >> 2);
        else
            dimx = (x >> 2);

        if (dimy == 0)
            dimy1 = (y >> 2);
        else
            dimy = (y >> 2);
    }

    i = ((D_8010A9A8->ang + 0x200) << 5) & 0xFFE0;
    f1 = (sins(i) / 32768.0);
    i = ((D_8010A9A8->ang + 0x200) << 5) & 0xFFE0;
    f2 = coss(i) / 32768.0;

    f3 = (x * f2) + (y * f1) + (D_8010A9A8->x / 2);
    f4 = (-y * f2) + (x * f1) + (D_8010A9A8->y / 2);

    f5 = (-x * f2) + (y * f1) + (D_8010A9A8->x / 2);
    f6 = (-y * f2) + (-x * f1) + (D_8010A9A8->y / 2);

    f7 = (-x * f2) + (-y * f1) + (D_8010A9A8->x / 2);
    f8 = (y * f2) + (-x * f1) + (D_8010A9A8->y / 2);

    f9 = (x * f2) + (-y * f1) + (D_8010A9A8->x / 2);
    f10 = (y * f2) + (x * f1) + (D_8010A9A8->y / 2);

    if (D_8010A9A8->cstat & 0x4000)
    {
        i = klabs(D_80199640 - D_8010A9A8->z);
        f11 = (D_8010A9A8->z >> 5);
        if (D_8010A9A8->z == gpSector[D_8010A9A8->sectnum].ceilingz)
        {
            j = i + 16;
            if (j < 0)
                j = i + 1039;

            f11 += (j >> 10);
        }
        if (D_8010A9A8->z == gpSector[D_8010A9A8->sectnum].floorz)
        {
            j = i + 16;
            if (j < 0)
                j = i + 1039;

            f11 -= (j >> 10);
        }
    }
    else
    {
        f11 = (D_8010A9A8->z >> 5);
    }

    if (D_80197DD4 == 0)
    {
        D_80197DD4 = 32;
        D_801A2620 = 0;
        gSPVertex(gpDisplayList++, gpVertexN64, 32, 0);
    }

    gSP2Triangles(gpDisplayList++, D_801A2620, D_801A2620+1, D_801A2620+2, D_801A2620,
                                   D_801A2620, D_801A2620+2, D_801A2620+3, D_801A2620);

    D_801A2620 = D_801A2620 + 4;
    D_80197DD4 = D_80197DD4 - 4;

    gpVertexN64->v.ob[0] = f3;
    gpVertexN64->v.ob[1] = f4;
    gpVertexN64->v.ob[2] = f11;
    gpVertexN64->v.tc[0] = dimx1 << 5;
    gpVertexN64->v.tc[1] = dimy << 5;
    gpVertexN64->v.cn[0] = D_8016A148;
    gpVertexN64->v.cn[1] = D_800FE410;
    gpVertexN64->v.cn[2] = D_80138680;
    gpVertexN64->v.cn[3] = 0xFF;
    gpVertexN64++;

    gpVertexN64->v.ob[0] = f5;
    gpVertexN64->v.ob[1] = f6;
    gpVertexN64->v.ob[2] = f11;
    gpVertexN64->v.tc[0] = dimx << 5;
    gpVertexN64->v.tc[1] = dimy << 5;
    gpVertexN64->v.cn[0] = D_8016A148;
    gpVertexN64->v.cn[1] = D_800FE410;
    gpVertexN64->v.cn[2] = D_80138680;
    gpVertexN64->v.cn[3] = 0xFF;
    gpVertexN64++;

    gpVertexN64->v.ob[0] = f7;
    gpVertexN64->v.ob[1] = f8;
    gpVertexN64->v.ob[2] = f11;
    gpVertexN64->v.tc[0] = dimx << 5;
    gpVertexN64->v.tc[1] = dimy1 << 5;
    gpVertexN64->v.cn[0] = D_8016A148;
    gpVertexN64->v.cn[1] = D_800FE410;
    gpVertexN64->v.cn[2] = D_80138680;
    gpVertexN64->v.cn[3] = 0xFF;
    gpVertexN64++;

    gpVertexN64->v.ob[0] = f9;
    gpVertexN64->v.ob[1] = f10;
    gpVertexN64->v.ob[2] = f11;
    gpVertexN64->v.tc[0] = dimx1 << 5;
    gpVertexN64->v.tc[1] = dimy1 << 5;
    gpVertexN64->v.cn[0] = D_8016A148;
    gpVertexN64->v.cn[1] = D_800FE410;
    gpVertexN64->v.cn[2] = D_80138680;
    gpVertexN64->v.cn[3] = 0xFF;
    gpVertexN64++;
}

/*80027C18*/
INCLUDE_ASM("nonmatchings/src/code0/24610", func_80027C18);

/*80028F04*/
void func_80028F04(u8 r1, u8 g1, u8 b1, u8 r2, u8 g2, u8 b2)
{
    D_801A2688 = 1;
    gDPSetAlphaCompare(gpDisplayList++, G_AC_NONE);
    gDPSetTextureLUT(gpDisplayList++, G_TT_NONE);
    gDPSetRenderMode(gpDisplayList++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_SURF2);
    gDPSetCombineLERP(gpDisplayList++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                                       0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
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
    gDPSetCombineLERP(gpDisplayList++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                                       0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
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
    gDPSetCombineLERP(gpDisplayList++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                                       0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
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
    gDPSetCombineLERP(gpDisplayList++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                                       0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
    gDPSetPrimColor(gpDisplayList++, 0, 0, r1, g1, b1, a);
    gDPSetEnvColor(gpDisplayList++, r2, g2, b2, a);
}

/*8002935C*/
static void func_8002935C(s16 spritenum)
{
    f32 fx, fy, fz;
    f32 f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11;
    s32 x, y, z;
    s32 a, b, c, d, e, f, g, h, i, j;
    u16 dimx, dimx1, dimy, dimy1, sizex, sizey;

    fx = (D_8010A9A8->x / 4.0);
    fy = (D_8010A9A8->y / 4.0);
    fz = (D_8010A9A8->z / 64.0);

    f1 = (D_8012B948[0][0] * fx) + (D_8012B948[1][0] * fy) + (D_8012B948[2][0] * fz) + D_8012B948[3][0];
    f2 = (D_8012B948[0][1] * fx) + (D_8012B948[1][1] * fy) + (D_8012B948[2][1] * fz) + D_8012B948[3][1];
    f3 = (D_8012B948[0][2] * fx) + (D_8012B948[1][2] * fy) + (D_8012B948[2][2] * fz) + D_8012B948[3][2];
    f4 = (D_8012B948[0][3] * fx) + (D_8012B948[1][3] * fy) + (D_8012B948[2][3] * fz) + D_8012B948[3][3];

    if (f4 != 0.0f)
    {
        f5 = f1 / f4;
        f6 = f2 / f4;
        f7 = f3 / f4;

        if (!(f5 < -2.0f) && !(f6 < -2.0f) && !(f5 > 2.0f) && !(f6 > 2.0f) && !(f7 < 0.0f) && !(f7 > 1.0f))
        {
            f7 = (-f7 + 1.0f);
            func_8000C76C();
            D_801A689C = 0;

            if (D_801A2688 != 0)
                func_8000BDB0(D_8010A9A8->picnum);
            else if (D_8010A9A8->cstat & 0x2000)
                func_8000C3E4(D_800F7054);
            else
                func_8000C0D0(D_800F7054);

            dimy1 = 0;
            if (D_8010A9A8->cstat & 8)
                dimy = gpTileInfo[D_800F7054].dimy;
            else
            {
                dimy = 0;
                dimy1 = gpTileInfo[D_800F7054].dimy;
            }

            dimx1 = 0;
            if (D_8010A9A8->cstat & 4)
                dimx = gpTileInfo[D_800F7054].dimx;
            else
            {
                dimx = 0;
                dimx1 = gpTileInfo[D_800F7054].dimx;
            }

            f7 = f7 * 16.0f;
            sizex = (f7 * (gpTileInfo[D_800F7054].sizex * D_8010A9A8->xrepeat)) / 16.0f;
            sizey = (f7 * (gpTileInfo[D_800F7054].sizey * D_8010A9A8->yrepeat)) / 16.0f;

            i = (D_8013B2D0[spritenum].unk0 << 5) & 0xFFE0;
            f8 = sins(i) / 32768.0;
            j = (D_8013B2D0[spritenum].unk0 << 5) & 0xFFE0;
            f9 = coss(j) / 32768.0;

            f10 = (f5 * 4.0f * D_80199110) + (D_80168C9C * 4.0f);
            f11 = (-f6 * 4.0f * D_801A1980) + (D_801A2684 * 4.0f);
            a = (sizex * f9) + (sizey * f8);
            e = (-sizey * f9) + (sizex * f8);
            b = (-sizex * f9) + (sizey * f8);
            f = (-sizey * f9) + (-sizex * f8);
            c = (-sizex * f9) + (-sizey * f8);
            g = (sizey * f9) + (-sizex * f8);
            d = (sizex * f9) + (-sizey * f8);
            h = (sizey * f9) + (sizex * f8);
            a = (((a * 4) * D_80199110) / 160.0f) + f10;
            b = (((b * 4) * D_80199110) / 160.0f) + f10;
            c = (((c * 4) * D_80199110) / 160.0f) + f10;
            d = (((d * 4) * D_80199110) / 160.0f) + f10;
            e = (((e * 4) * D_801A1980) / 120.0f) + f11;
            f = (((f * 4) * D_801A1980) / 120.0f) + f11;
            g = (((g * 4) * D_801A1980) / 120.0f) + f11;
            h = (((h * 4) * D_801A1980) / 120.0f) + f11;

            if (D_80197DD4 == 0)
            {
                D_80197DD4 = 32;
                D_801A2620 = 0;

                gSPVertex(gpDisplayList++, gpVertexN64, 32, 0);
                gSPModifyVertex(gpDisplayList++, 0, G_MWO_POINT_XYSCREEN, ((a << 16) + e));
                gSPModifyVertex(gpDisplayList++, 1, G_MWO_POINT_XYSCREEN, ((b << 16) + f));
                gSPModifyVertex(gpDisplayList++, 2, G_MWO_POINT_XYSCREEN, ((c << 16) + g));
                gSPModifyVertex(gpDisplayList++, 3, G_MWO_POINT_XYSCREEN, ((d << 16) + h));
            }

            gSP2Triangles(gpDisplayList++, D_801A2620, D_801A2620+1, D_801A2620+2, D_801A2620,
                                           D_801A2620, D_801A2620+2, D_801A2620+3, D_801A2620);

            D_801A2620 = D_801A2620 + 4;
            D_80197DD4 = D_80197DD4 - 4;
            x = D_8010A9A8->x / 2;
            y = D_8010A9A8->y / 2;
            z = D_8010A9A8->z / 32;

            gpVertexN64->v.ob[0] = x;
            gpVertexN64->v.ob[1] = y;
            gpVertexN64->v.ob[2] = z;
            gpVertexN64->v.tc[0] = dimx1 << 5;
            gpVertexN64->v.tc[1] = dimy << 5;
            gpVertexN64->v.cn[0] = D_8016A148;
            gpVertexN64->v.cn[1] = D_800FE410;
            gpVertexN64->v.cn[2] = D_80138680;
            gpVertexN64->v.cn[3] = 0xFF;
            gpVertexN64++;

            gpVertexN64->v.ob[0] = x;
            gpVertexN64->v.ob[1] = y;
            gpVertexN64->v.ob[2] = z;
            gpVertexN64->v.tc[0] = dimx << 5;
            gpVertexN64->v.tc[1] = dimy << 5;
            gpVertexN64->v.cn[0] = D_8016A148;
            gpVertexN64->v.cn[1] = D_800FE410;
            gpVertexN64->v.cn[2] = D_80138680;
            gpVertexN64->v.cn[3] = 0xFF;
            gpVertexN64++;

            gpVertexN64->v.ob[0] = x;
            gpVertexN64->v.ob[1] = y;
            gpVertexN64->v.ob[2] = z;
            gpVertexN64->v.tc[0] = dimx << 5;
            gpVertexN64->v.tc[1] = dimy1 << 5;
            gpVertexN64->v.cn[0] = D_8016A148;
            gpVertexN64->v.cn[1] = D_800FE410;
            gpVertexN64->v.cn[2] = D_80138680;
            gpVertexN64->v.cn[3] = 0xFF;
            gpVertexN64++;

            gpVertexN64->v.ob[0] = x;
            gpVertexN64->v.ob[1] = y;
            gpVertexN64->v.ob[2] = z;
            gpVertexN64->v.tc[0] = dimx1 << 5;
            gpVertexN64->v.tc[1] = dimy1 << 5;
            gpVertexN64->v.cn[0] = D_8016A148;
            gpVertexN64->v.cn[1] = D_800FE410;
            gpVertexN64->v.cn[2] = D_80138680;
            gpVertexN64->v.cn[3] = 0xFF;
            gpVertexN64++;
        }
    }
}

