#include "common.h"
#include "code0/main.h"
#include "code0/9410.h"
#include "code0/graphics.h"
#include "code0/pragmas.h"
#include "code0/code0.h"
#include "static/F6D70.h"

/*.bss*/
/*800F7040*/ static s32 D_800F7040;
/*800F7044*/ static s32 D_800F7044;
/*800F7048*/ static s32 D_800F7048;
/*800F704C*/ static f32 D_800F704C;
/*800F7050*/ static f32 D_800F7050;
/*800F7054*/ static s32 D_800F7054;

/*.comm*/
/*8010A9A8*/ SpriteType *D_8010A9A8;
/*80119A9C*/ s16 D_80119A9C;
/*801385F0*/ s8 D_801385F0;
/*80168810*/ s16 D_80168810;
/*801A689C*/ u8 D_801A689C;

/*.text*/
static void func_8002433C(s16 spritenum, s32);
static void func_80025C3C(s16 spritenum, s32);
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

#ifdef NON_MATCHING
/*8002433C*/
void func_8002433C(s16 spritenum, s32 arg1)
{
    s32 sp1C;
    s32 sp24;
    s16 x2;
    s16 x3;
    s16 x4;
    s16 y1;
    s16 y2;
    s16 y3;
    s16 y4;
    u16 dimx;

    f32 temp_f20_5;
    f32 temp_f26;

    s32 temp_f2_5;
    s32 temp_s0_2;
    s32 temp_s1;
    s32 temp_s2;

    s32 var_s0;
    s32 var_s1;
    s32 var_s4;
    s32 var_v1_4;

    u8 *var_s3;
    s32 height;
    s16 x1;
    u16 dimx1;
    u16 x;
    u16 y;
    u16 dimy1;
    u16 z2;
    u16 z1;
    u16 dimy;
    u16 a, b;

    if (D_801A689C != 0)
    {
        func_8000C76C();
        D_801A689C = 0;
    }

    D_8012DEFC = 0xFFFF;
    x = (gpTileInfo[D_800F7054].sizex * D_8010A9A8->xrepeat) / 16;
    y = (gpTileInfo[D_800F7054].sizey * D_8010A9A8->yrepeat) / 8;
    temp_s2 = (s32)((((gpTileInfo[D_800F7054].picanm>>8)&255)));
    temp_s2 *= D_8010A9A8->xrepeat;
    temp_s2 /= 8;

    var_s1 = D_8010A9A8->z;

    if (D_8010A9A8->cstat & 0x80)
        var_s1 += (y >> 1) << 5;

    var_s4 = D_800F7044;
    temp_s1 = var_s1 - ((s32)(((s8)((gpTileInfo[D_800F7054].picanm>>16)&255))<<2)*D_8010A9A8->yrepeat);

    if (!(gpTileInfo[D_800F7054].flags & 0x80))
    {
        gDPLoadTLUT_pal16(gpDisplayList++, 0, loadTile(D_800F7054));
        do
        {
            var_s3 = loadTile(D_800F7054) + 0x20;
        } while (0);
    }
    else
    {
        gDPLoadTLUT_pal256(gpDisplayList++, D_01000008);
        do
        {
            var_s3 = loadTile(D_800F7054);
        } while (0);
    }

    z2 = (temp_s1 >> 5) - y;
    sp24 = y;

    dimy = 0;
    if (D_8010A9A8->cstat & 4)
    {
        dimx1 = 0;
        dimx = gpTileInfo[D_800F7054].dimx;
    }
    else
    {
        dimx = 0;
        dimx1 = gpTileInfo[D_800F7054].dimx;
    }

    if (D_8010A9A8->cstat & 0x2000)
    {
        if (dimx == 0)
            dimx1 = (x >> 2);
        else
            dimx = (x >> 2);
    }

    x1 = x2 = x3 = x4 = (D_8010A9A8->x / 2.0);
    y1 = y2 = y3 = y4 = (D_8010A9A8->y / 2.0);

    if ((D_8010A9A8->cstat & 0x30) == 0)
    {
        x1 = (x4 - (D_800F704C * x));
        x2 = (x4 + (D_800F704C * x));
        y2 = (y4 - (D_800F7050 * x));
        y1 = (y4 + (D_800F7050 * x));
        x3 = x2;
        x4 = x1;
        y4 = y1;
        y3 = y2;
    }

    if ((D_8010A9A8->cstat & 0x30) == 0x10)
    {
        temp_f26 = (D_8010A9A8->ang * (PI/1024));

        if (D_8010A9A8->cstat & 0x4000)
        {
            var_s0 = MAX(((arg1 << 8) / ((gPlayer[D_801B0820].unk6E) * 0x78)), 4);
            x1 += (sinf((temp_f26 + (PI/2))) * var_s0);
            y1 -= (cosf((temp_f26 + (PI/2))) * var_s0);
        }

        temp_s0_2 = (x1 - (sinf((temp_f26 - PI)) * x));
        x2 = (x1 + (sinf((temp_f26 - PI)) * x));
        x1 = temp_s0_2;
        y2 = (y1 - (cosf((temp_f26 - PI)) * x));
        y1 = (y1 + (cosf((temp_f26 - PI)) * x));

        if (temp_s2 != 0)
        {
            x1 += (sinf((temp_f26 - PI)) * temp_s2);
            x2 += (sinf((temp_f26 - PI)) * temp_s2);
        }

        x3 = x2;
        x4 = x1;
        y4 = y1;
        y3 = y2;
    }

    if (!(gpTileInfo[D_800F7054].flags & 0x80))
        sp1C = 0x1000 / D_800F7040;
    else
        sp1C = 0x800 / D_800F7040;

    temp_f20_5 = (f32)sp24 / (f32)D_800F7044;
    if (D_8010A9A8->cstat & 8)
        z2 += sp24;

    do
    {
        height = sp1C;
        if (var_s4 < height)
            height = var_s4;

        if (D_801A2688 != 0)
        {
            if (D_8010A9A8->cstat & 0x2000)
            {
                gDPLoadTextureBlock_4b(gpDisplayList++, var_s3, G_IM_FMT_I,
                                        D_800F7040, height, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP,
                                        tileMasks(D_800F7054), tileMaskt(D_800F7054), G_TX_NOLOD, G_TX_NOLOD);
            }
            else
            {
                gDPLoadTextureBlock_4b(gpDisplayList++, var_s3, G_IM_FMT_I,
                                       D_800F7040, height, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                                       G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            }

            var_v1_4 = var_s4+1;
            var_s4 = var_v1_4 - height;
            var_s3 += ((D_800F7040 * (height - 1)) / 8) * 4;
        }
        else if (!(gpTileInfo[D_800F7054].flags & 0x80))
        {
            if ((D_8010A9A8->cstat & 0x2000))
            {
                gDPLoadTextureBlock_4b(gpDisplayList++, var_s3, G_IM_FMT_CI,
                                       D_800F7040, height, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP,
                                       tileMasks(D_800F7054), tileMaskt(D_800F7054), G_TX_NOLOD, G_TX_NOLOD);
            }
            else
            {
                gDPLoadTextureBlock_4b(gpDisplayList++, var_s3, G_IM_FMT_CI,
                                       D_800F7040, height, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                                       G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            }

            var_v1_4 = var_s4+1;
            var_s4 = var_v1_4 - height;
            var_s3 += ((D_800F7040 * (height - 1)) / 8) * 4;
        }
        else
        {
            if ((D_8010A9A8->cstat & 0x2000))
            {
                gDPLoadTextureBlock(gpDisplayList++, var_s3, G_IM_FMT_CI, G_IM_SIZ_8b, D_800F7040,
                                    height, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP,
                                    tileMasks(D_800F7054), tileMaskt(D_800F7054), G_TX_NOLOD, G_TX_NOLOD);
            }
            else
            {
                gDPLoadTextureBlock(gpDisplayList++, var_s3, G_IM_FMT_CI, G_IM_SIZ_8b, D_800F7040,
                                    height, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                                    G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            }

            var_v1_4 = var_s4+1;
            var_s4 = var_v1_4 - height;
            var_s3 += ((D_800F7040 * (height - 1)) / 4) * 4;
        }

        temp_f2_5 = (height * temp_f20_5);
        dimy1 = (height - 1);

        if (D_8010A9A8->cstat & 8)
        {
            z1 = z2;
            b = z2 - temp_f2_5;
            z2 = b;
            do {} while (0); /*FAKE*/
            a = b;
        }
        else
        {
            z1 = z2;
            b = z2 + temp_f2_5;
            z2 = b;
            do {} while (0); /*FAKE*/
            a = b;
        }


        if (gVertexNumber == 0)
        {
            gVertexNumber = 0x20;
            gVertexBufferIndex = 0;
            gSPVertex(gpDisplayList++, gpVertexN64, 32, 0);
        }

        gSP2Triangles(gpDisplayList++, gVertexBufferIndex, gVertexBufferIndex+1, gVertexBufferIndex+2, gVertexBufferIndex,
                                       gVertexBufferIndex, gVertexBufferIndex+2, gVertexBufferIndex+3, gVertexBufferIndex);

        gVertexBufferIndex += 4;
        gVertexNumber -= 4;

        gpVertexN64->v.ob[0] = x1;
        gpVertexN64->v.ob[1] = y1;
        gpVertexN64->v.ob[2] = z1;
        gpVertexN64->v.tc[0] = dimx1 << 5;
        gpVertexN64->v.tc[1] = dimy << 5;
        gpVertexN64->v.cn[0] = D_8016A148;
        gpVertexN64->v.cn[1] = D_800FE410;
        gpVertexN64->v.cn[2] = D_80138680;
        gpVertexN64->v.cn[3] = 0xFF;
        gpVertexN64++;

        gpVertexN64->v.ob[0] = x2;
        gpVertexN64->v.ob[1] = y2;
        gpVertexN64->v.ob[2] = z1;
        gpVertexN64->v.tc[0] = dimx << 5;
        gpVertexN64->v.tc[1] = dimy << 5;
        gpVertexN64->v.cn[0] = D_8016A148;
        gpVertexN64->v.cn[1] = D_800FE410;
        gpVertexN64->v.cn[2] = D_80138680;
        gpVertexN64->v.cn[3] = 0xFF;
        gpVertexN64++;

        gpVertexN64->v.ob[0] = x3;
        gpVertexN64->v.ob[1] = y3;
        gpVertexN64->v.ob[2] = a;
        gpVertexN64->v.tc[0] = dimx << 5;
        gpVertexN64->v.tc[1] = dimy1 << 5;
        gpVertexN64->v.cn[0] = D_8016A148;
        gpVertexN64->v.cn[1] = D_800FE410;
        gpVertexN64->v.cn[2] = D_80138680;
        gpVertexN64->v.cn[3] = 0xFF;
        gpVertexN64++;

        gpVertexN64->v.ob[0] = x4;
        gpVertexN64->v.ob[1] = y4;
        gpVertexN64->v.ob[2] = a;
        gpVertexN64->v.tc[0] = dimx1 << 5;
        gpVertexN64->v.tc[1] = dimy1 << 5;
        gpVertexN64->v.cn[0] = D_8016A148;
        gpVertexN64->v.cn[1] = D_800FE410;
        gpVertexN64->v.cn[2] = D_80138680;
        gpVertexN64->v.cn[3] = 0xFF;
        gpVertexN64++;
    } while (var_s4 >= 2);
}
#else
/*8002433C*/
INCLUDE_ASM("src/code0/24610", func_8002433C);
#endif

#ifdef NON_MATCHING
/*80025C3C*/
void func_80025C3C(s16 spritenum, s32 arg1)
{
    s32 a; //t1
    s32 b; //v0
    s32 sp24;
    u16 x1; //sp2E
    u16 x2; //sp36
    u16 x3; //sp3E
    u16 x4; //sp46
    u16 y3; //sp4E
    u16 y4; //sp56
    u16 dimx; //sp5E
    u16 dimy; //sp6C

    f32 temp_f20;
    f32 var_f20;
    f32 var_f22;
    f32 var_f24;

    u16 dimy1; //t2
    s32 z2; //s6
    s16 z1; //t0

    u16 y1;
    u16 y2;

    s32 var_s1;
    s32 var_s4;

    s32 height; //s2

    s32 var_a0;
    s32 var_v0;

    u16 dimx1; //s0
    u16 x; //s2
    u16 y; //s5

    u8 *var_s3;
    s32 new_var;

    dimy = 0; /*FAKE?*/
    if (D_801A6D80 < 0x100)
    {
        do
        {
            D_8012DEFC = 0xFFFF;
            x = (gpTileInfo[D_800F7054].sizex * D_8010A9A8->xrepeat) / 16;
            y = (gpTileInfo[D_800F7054].sizey * D_8010A9A8->yrepeat) / 8;
            //xoff = (s32)((s8)((gpTileInfo[D_800F7054].picanm>>8)&255));
        } while (0); /*FAKE*/

        var_s1 = 0;
        if ((D_8010A9A8->cstat & 0x80) || ((D_8010A9A8->cstat & 0x30) == 0x20))
            var_s1 = (y >> 1) << 5;

        var_s4 = D_800F7044;
        var_s1 -= ((s32)(((s8)((gpTileInfo[D_800F7054].picanm>>16)&255))<<2)*D_8010A9A8->yrepeat);
        if (!(gpTileInfo[D_800F7054].flags & 0x80))
        {
            gDPLoadTLUT_pal16(gpDisplayList++, 0, loadTile(D_800F7054));
            do
            {
                var_s3 = loadTile(D_800F7054) + 0x20;
            } while (0); /*FAKE*/
        }
        else
        {
            gDPLoadTLUT_pal256(gpDisplayList++, D_01000008);
            //do {
            var_s3 = loadTile(D_800F7054);
            //}while(0);
        }

        z2 = (var_s1 >> 5) - y;
        var_s1 = y;
        new_var = 1; /*FAKE*/

        if (D_8010A9A8->cstat & 4)
        {
            dimx1 = 0;
            dimx = gpTileInfo[D_800F7054].dimx;
        }
        else
        {
            dimx = 0;
            dimx1 = gpTileInfo[D_800F7054].dimx;
        }
        if (D_8010A9A8->cstat & 0x2000)
        {
            if (dimx == 0)
                dimx1 = (x >> 2);
            else
                dimx = (x >> 2);
        }

        x2 = 0;
        y1 = 0;
        y2 = 0;
        x1 = 0;
        var_f24 = 0.0f;
        var_f20 = (D_8010A9A8->z / 64.0);
        if (D_8010A9A8->cstat & 0x400)
        {
            var_f22 = (D_8013B2D0[spritenum].unk2 * 0.17578125);
            var_f24 = (D_8013B2D0[spritenum].unk0 * 0.17578125);
        }
        else
        {
            var_f22 = 90.0f;
            if (D_8010A9A8->cstat & 0x4000)
            {
                s32 c;
                c = klabs((D_80199640 - D_8010A9A8->z));

                if (D_8010A9A8->z == gpSector[D_8010A9A8->sectnum].ceilingz)
                    var_f20 += ((c + 0x10) / 1024);

                if (D_8010A9A8->z == gpSector[D_8010A9A8->sectnum].floorz)
                    var_f20 -= ((c + 0x10) / 1024);
            }
        }
        D_801A689C = 1;
        func_8000C76C();
        x1 = x1 - x;
        x2 = x2 + x;

        grPosition(&gpDynamic->mtx3[D_801A6D80],
                   var_f22,
                   var_f24,
                   ((D_8010A9A8->ang - 0x200) * 0.17578125),
                   0.5f,
                   (D_8010A9A8->x / 4.0),
                   (D_8010A9A8->y / 4.0),
                   var_f20);

        gSPMatrix(gpDisplayList++, &gpDynamic->mtx3[D_801A6D80], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        D_801A6D80++;

        x4 = x1;
        x3 = x2;
        y4 = y1;
        y3 = y2;

        if (!(gpTileInfo[D_800F7054].flags & 0x80))
            sp24 = 0x1000 / D_800F7040;
        else
            sp24 = 0x800 / D_800F7040;

        temp_f20 = (f32)var_s1 / (f32)D_800F7044;
        if (D_8010A9A8->cstat & 8)
            z2 += var_s1;

        do
        {
            height = sp24;
            if (var_s4 < height)
                height = var_s4;

            if (D_801A2688 != 0)
            {
                if (D_8010A9A8->cstat & 0x2000)
                {
                    gDPLoadTextureBlock_4b(gpDisplayList++, var_s3, G_IM_FMT_I,
                                            D_800F7040, height, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP,
                                            tileMasks(D_800F7054), tileMaskt(D_800F7054), G_TX_NOLOD, G_TX_NOLOD);
                }
                else
                {
                    gDPLoadTextureBlock_4b(gpDisplayList++, var_s3, G_IM_FMT_I,
                                           D_800F7040, height, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                                           G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                }
                var_v0 = var_s4+new_var;
                var_s4 = var_v0 - height;
                var_s3 += ((D_800F7040 * (height - 1)) / 8) * 4;
            }
            else if (!(gpTileInfo[D_800F7054].flags & 0x80))
            {
                if ((D_8010A9A8->cstat & 0x2000))
                {
                    gDPLoadTextureBlock_4b(gpDisplayList++, var_s3, G_IM_FMT_CI,
                                           D_800F7040, height, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP,
                                           tileMasks(D_800F7054), tileMaskt(D_800F7054), G_TX_NOLOD, G_TX_NOLOD);
                }
                else
                {
                    gDPLoadTextureBlock_4b(gpDisplayList++, var_s3, G_IM_FMT_CI,
                                           D_800F7040, height, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                                           G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                }
                var_v0 = var_s4+new_var;
                var_s4 = var_v0 - height;
                var_s3 += ((D_800F7040 * (height - 1)) / 8) * 4;
            }
            else
            {
                if ((D_8010A9A8->cstat & 0x2000))
                {
                    gDPLoadTextureBlock(gpDisplayList++, var_s3, G_IM_FMT_CI, G_IM_SIZ_8b, D_800F7040,
                                        height, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP,
                                        tileMasks(D_800F7054), tileMaskt(D_800F7054), G_TX_NOLOD, G_TX_NOLOD);
                }
                else
                {
                    gDPLoadTextureBlock(gpDisplayList++, var_s3, G_IM_FMT_CI, G_IM_SIZ_8b, D_800F7040,
                                        height, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                                        G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                }
                var_v0 = var_s4+new_var;
                var_s4 = var_v0 - height;
                var_s3 += ((D_800F7040 * (height - 1)) / 4) * 4;
            }

            var_a0 = (height * temp_f20);

            dimy1 = (height - 1);
            if (D_8010A9A8->cstat & 8)
            {
                z1 = z2;
                b = z2 - var_a0;
                z2 = b;
                do {} while (0); /*FAKE*/
                a = b;
            }
            else
            {
                z1 = z2;
                b = z2 + var_a0;
                z2 = b;
                do {} while (0); /*FAKE*/
                a = b;
            }

            if (gVertexNumber == 0)
            {
                gVertexNumber = 0x20;
                gVertexBufferIndex = 0;
                gSPVertex(gpDisplayList++, gpVertexN64, 32, 0);
            }
            gSP2Triangles(gpDisplayList++, gVertexBufferIndex, gVertexBufferIndex+1, gVertexBufferIndex+2, gVertexBufferIndex,
                                           gVertexBufferIndex, gVertexBufferIndex+2, gVertexBufferIndex+3, gVertexBufferIndex);

            gVertexBufferIndex += 4;
            gVertexNumber -= 4;

            gpVertexN64->v.ob[0] = x1;
            gpVertexN64->v.ob[1] = y1;
            gpVertexN64->v.ob[2] = z1;
            gpVertexN64->v.tc[0] = dimx1 << 5;
            gpVertexN64->v.tc[1] = dimy << 5;
            gpVertexN64->v.cn[0] = D_8016A148;
            gpVertexN64->v.cn[1] = D_800FE410;
            gpVertexN64->v.cn[2] = D_80138680;
            gpVertexN64->v.cn[3] = 0xFF;
            gpVertexN64++;

            gpVertexN64->v.ob[0] = x2;
            gpVertexN64->v.ob[1] = y2;
            gpVertexN64->v.ob[2] = z1;
            gpVertexN64->v.tc[0] = dimx << 5;
            gpVertexN64->v.tc[1] = dimy << 5;
            gpVertexN64->v.cn[0] = D_8016A148;
            gpVertexN64->v.cn[1] = D_800FE410;
            gpVertexN64->v.cn[2] = D_80138680;
            gpVertexN64->v.cn[3] = 0xFF;
            gpVertexN64++;

            gpVertexN64->v.ob[0] = x3;
            gpVertexN64->v.ob[1] = y3;
            gpVertexN64->v.ob[2] = a;
            gpVertexN64->v.tc[0] = dimx << 5;
            gpVertexN64->v.tc[1] = dimy1 << 5;
            gpVertexN64->v.cn[0] = D_8016A148;
            gpVertexN64->v.cn[1] = D_800FE410;
            gpVertexN64->v.cn[2] = D_80138680;
            gpVertexN64->v.cn[3] = 0xFF;
            gpVertexN64++;

            gpVertexN64->v.ob[0] = x4;
            gpVertexN64->v.ob[1] = y4;
            gpVertexN64->v.ob[2] = a;
            gpVertexN64->v.tc[0] = dimx1 << 5;
            gpVertexN64->v.tc[1] = dimy1 << 5;
            gpVertexN64->v.cn[0] = D_8016A148;
            gpVertexN64->v.cn[1] = D_800FE410;
            gpVertexN64->v.cn[2] = D_80138680;
            gpVertexN64->v.cn[3] = 0xFF;
            gpVertexN64++;
        } while (var_s4 >= 2);

        gSPPopMatrix(gpDisplayList++, G_MTX_MODELVIEW);
    }
}
#else
/*80025C3C*/
INCLUDE_ASM("src/code0/24610", func_80025C3C);
#endif

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

    if (gVertexNumber == 0)
    {
        gVertexNumber = 32;
        gVertexBufferIndex = 0;
        gSPVertex(gpDisplayList++, gpVertexN64, 32, 0);
    }

    gSP2Triangles(gpDisplayList++, gVertexBufferIndex, gVertexBufferIndex+1, gVertexBufferIndex+2, gVertexBufferIndex,
                                   gVertexBufferIndex, gVertexBufferIndex+2, gVertexBufferIndex+3, gVertexBufferIndex);

    gVertexBufferIndex += 4;
    gVertexNumber -= 4;

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

#ifdef NON_MATCHING
void func_80027C18(f32 x1, f32 y1, f32 x2, f32 y2, u16 tilenum, s32 arg5)
{
    f32 fdtdy;
    f32 fdsdx;

    TileInfo *temp_a0;
    TileInfo *temp_a0_2;
    f32 fyl;
    f32 temp_f12;
    f32 fxh;
    f32 temp_f12_3;
    f32 temp_f14;

    f32 temp_f14_3;
    f32 temp_f20;
    f32 fwidth;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f24_2;
    f32 temp_f24_3;

    f32 fxl;
    f32 t;
    f32 temp_f6;
    f32 temp_s5;
    f32 var_f14;
    f32 s;
    f32 fyl_;
    f32 fyh;
    f32 var_f26;
    f32 var_f2;

    f32 height;
    s32 temp_a1;
    s32 temp_a2;

    f32 fyh_;

    s32 var_v0;
    s32 var_v1;

    u8 *var_s2;
    f32 temp;

    temp_f6 = x2 * 4.0f;
    temp_f22 = y2 * 4.0f;
    temp_a0 = &gpTileInfo[tilenum];
    temp_f14 = y1 * 4.0f;
    temp_a2 = (arg5 >> 3) & 1;
    temp_a1 = (arg5 & 4) != 0;
    var_f2 = ((s32)((((temp_a0->picanm>>8)&255))) * temp_f6) / 6.0f;

    if (temp_a1 != 0)
        var_f2 = -var_f2;

    temp_f20 = (temp_a0->sizex * temp_f6) / 6.0f;
    temp_f12 = (x1 * 4.0f) - (2.0f * var_f2);
    temp_f24 = (temp_a0->sizey * temp_f22) / 6.0f;
    var_v0 = 1;

    if (!(temp_f20 < 4.0f))
        var_v0 = 0;

    var_v1 = 1;
    if (!(temp_f24 < 4.0f))
        var_v1 = 0;

    if (!(var_v0 & var_v1))
    {
        fxl = temp_f12 - temp_f20;
        fxh = temp_f12 + temp_f20;
        fyl_ = temp_f14 - temp_f24;
        fyh = temp_f14 + temp_f24;
        fdsdx = (temp_a0->dimx << 0xC) / (fxh - fxl);

        fwidth = temp_a0->dimx;
        fdtdy = (temp_a0->dimy << 0xC) / (fyh - fyl_);
        if (temp_a1 != 0)
        {
            fdsdx = -fdsdx;
            s = (fwidth - 1.0f) * 32.0f;
        }
        else
            s = 0.0f;

        if (temp_a2 != 0)
            fdtdy = -fdtdy;

        temp_a0_2 = &gpTileInfo[tilenum];
        var_s2 = loadTile(tilenum) + 0x20;
        temp_f24_2 = temp_a0->dimy;
        var_f26 = temp_a0_2->dimy;
        temp_s5 = (temp_a0_2->sizey * temp_f22) / 3.0f;

        gDPLoadTLUT_pal16(gpDisplayList++, 0, loadTile(tilenum));

        var_f14 = (f32)(s32)(4096.0f / fwidth);
        if (!((s32)var_f14 & 1))
            var_f14 -= 1.0f;

        temp_f12_3 = temp_s5 / temp_f24_2;
        temp_f14_3 = var_f14 * 4.0f;
        var_f26 = var_f26 * 4.0f;
        temp_f24_3 = (temp_f24_2 * 4.0f) / temp_s5;

        if (temp_a2 != 0)
        {
            do
            {
                height = MIN(var_f26, temp_f14_3);

                var_f26 -= height - 4.0f;
                if (D_801A2688 != 0)
                {
                    gDPLoadTextureBlock_4b(gpDisplayList++, var_s2, G_IM_FMT_I, (s32)fwidth, (s32)(height/4.0f), 0,
                                           G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                                           G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                }
                else
                {
                    gDPLoadTextureBlock_4b(gpDisplayList++, var_s2, G_IM_FMT_CI, (s32)fwidth, (s32)(height/4.0f), 0,
                                           G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                                           G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                }

                temp = ((height - 8.0f) * 8.0f);
                fyl = fyh - (((height * temp_f12_3) / 4.0f) - temp_f12_3);
                t = temp - ((f32)((s32)(f32)((s32)(fyl * 8.0f) & 0x1F) ^ 0x1F) * temp_f24_3);

                gSPScisTextureRectangle(gpDisplayList++, fxl, fyl, fxh, fyh, 0, s, t, (s32)fdsdx, (s32)fdtdy);

                if (!(var_f26 <= 4.0f))
                {
                    fyh -= ((height * temp_f12_3) / 4.0f) - temp_f12_3;
                    var_s2 += ((gpTileInfo[tilenum].dimx * (s32)((height / 4.0f) - 1.0f)) /8) * 4;
                }
                else
                    break;
            } while (1);
        }
        else
        {
            do
            {
                height = MIN(var_f26, temp_f14_3);
                var_f26 -= height - 4.0f;
                if (D_801A2688 != 0)
                {
                    gDPLoadTextureBlock_4b(gpDisplayList++, var_s2, G_IM_FMT_I, (s32)fwidth, (s32)(height/4.0f), 0,
                                           G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                                           G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                }
                else
                {
                    gDPLoadTextureBlock_4b(gpDisplayList++, var_s2, G_IM_FMT_CI, (s32)fwidth, (s32)(height/4.0f), 0,
                                           G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                                           G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                }

                fyh_ = (fyl_ + (((height * temp_f12_3) / 4.0f) - temp_f12_3));
                t = (f32)((s32)(f32)((s32)(fyl_ * 8.0f) & 0x1F) ^ 0x1F) * temp_f24_3;

                gSPScisTextureRectangle(gpDisplayList++, fxl, fyl_, fxh, fyh_, 0, s, t, (s32)fdsdx, (s32)fdtdy);

                if (!(var_f26 <= 4.0f))
                {
                    fyl_ += ((height * temp_f12_3) / 4.0f) - temp_f12_3;
                    var_s2 += ((gpTileInfo[tilenum].dimx * (s32)((height / 4.0f) - 1.0f)) /8) * 4;
                }
                else
                    break;
            } while (1);
        }
    }
}
#else
/*80027C18*/
INCLUDE_ASM("src/code0/24610", func_80027C18);
#endif

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
            a = (((a * 4) * D_80199110) / (SCREEN_WIDTH/2.f)) + f10;
            b = (((b * 4) * D_80199110) / (SCREEN_WIDTH/2.f)) + f10;
            c = (((c * 4) * D_80199110) / (SCREEN_WIDTH/2.f)) + f10;
            d = (((d * 4) * D_80199110) / (SCREEN_WIDTH/2.f)) + f10;
            e = (((e * 4) * D_801A1980) / (SCREEN_HEIGHT/2.f)) + f11;
            f = (((f * 4) * D_801A1980) / (SCREEN_HEIGHT/2.f)) + f11;
            g = (((g * 4) * D_801A1980) / (SCREEN_HEIGHT/2.f)) + f11;
            h = (((h * 4) * D_801A1980) / (SCREEN_HEIGHT/2.f)) + f11;

            if (gVertexNumber == 0)
            {
                gVertexNumber = 32;
                gVertexBufferIndex = 0;

                gSPVertex(gpDisplayList++, gpVertexN64, 32, 0);
                gSPModifyVertex(gpDisplayList++, 0, G_MWO_POINT_XYSCREEN, ((a << 16) + e));
                gSPModifyVertex(gpDisplayList++, 1, G_MWO_POINT_XYSCREEN, ((b << 16) + f));
                gSPModifyVertex(gpDisplayList++, 2, G_MWO_POINT_XYSCREEN, ((c << 16) + g));
                gSPModifyVertex(gpDisplayList++, 3, G_MWO_POINT_XYSCREEN, ((d << 16) + h));
            }

            gSP2Triangles(gpDisplayList++, gVertexBufferIndex, gVertexBufferIndex+1, gVertexBufferIndex+2, gVertexBufferIndex,
                                           gVertexBufferIndex, gVertexBufferIndex+2, gVertexBufferIndex+3, gVertexBufferIndex);

            gVertexBufferIndex += 4;
            gVertexNumber -= 4;
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
