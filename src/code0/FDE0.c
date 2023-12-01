#include "common.h"
#include "math.h"
#include "code0/main.h"
#include "code0/pragmas.h"
#include "code0/FDE0.h"
#include "code0/9410.h"
#include "code0/16FF0.h"
#include "code0/17B30.h"
#include "code0/24610.h"
#include "code0/41940.h"
#include "code0/graphics.h"
#include "code0/8E670.h"
#include "code0/A06F0.h"
#include "code0/code0.h"
#include "code1/EB300.h"
#include "code1/code1.h"

/*.data*/
/*800BD760*/
static Lights2 _light2 = {
    { { { 20, 20, 20 }, 0, { 20, 20, 20 }, 0 } },
    {
        { { { 255, 255, 255 }, 0, { 255, 255, 255 }, 0, { 32, 64, 0 }, 0 } },
        { { { 255, 255, 255 }, 0, { 255, 255, 255 }, 0, { 64, 32, 160 }, 0 } },
    },
};

/*800BD788*/ s32 D_800BD788 = 0;

/*.comm*/
/*800FE414*/ u8 D_800FE414;
/*800FF3A0*/ Matrix4f D_800FF3A0 ALIGNED(8);
/*80106D3C*/ f32 D_80106D3C;
/*8012E154*/ u16 D_8012E154;
/*8012EB48*/ f32 D_8012EB48;
/*8012FD86*/ s16 D_8012FD86; /*alpha*/
/*80197DF0*/ Matrix4f D_80197DF0 ALIGNED(8);
/*80199578*/ Matrix4f D_80199578 ALIGNED(8);
/*801AE9D0*/ Matrix4f D_801AE9D0 ALIGNED(8);
/*801AFDE0*/ Matrix4f D_801AFDE0 ALIGNED(8);

/*.text*/
static f32 func_80011410(ModelInfo *model);
static void func_800117A4(u8 *cmd, code0UnkStruct18 *vtx, ModelLight *light);
static void func_800124EC(s16);
static void func_80012630(void);

/*8000F1E0*/
void func_8000F1E0(void)
{
    func_8000C76C();
    D_8010A9AC = 0;
    D_801A2688 = 0;
    D_8019956C = 0;
    D_80105718 = 0;
    D_80119A9C = 0xFFFF;

    gSPSetLights2(gpDisplayList++, _light2);
    gDPSetRenderMode(gpDisplayList++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2);
    gDPSetCombineMode(gpDisplayList++, G_CC_MODULATEIDECALA, G_CC_PASS2);

    gSPClearGeometryMode(gpDisplayList++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING |
                                          G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH);

    gSPSetGeometryMode(gpDisplayList++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH);
    gSPTexture(gpDisplayList++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    gDPSetAlphaCompare(gpDisplayList++, G_AC_NONE);
    gDPSetTextureLUT(gpDisplayList++, G_TT_RGBA16);
    gDPSetTexturePersp(gpDisplayList++, G_TP_PERSP);
}

/*8000F3C4*/
void func_8000F3C4(s16 r1, s16 g1, s16 b1, s16 r2, s16 g2, s16 b2)
{
    gSPLightColor(gpDisplayList++, LIGHT_1, ((r1<<24)+(g1<<16)+(b1<<8)));
    gSPLightColor(gpDisplayList++, LIGHT_2, ((r2<<24)+(g2<<16)+(b2<<8)));
}

/*8000F474*/
static void func_8000F474(s16 spritenum, f32 arg1, f32 arg2, f32 arg3)
{
    Mtx mtx2, mtx1, mtx3, mtx4, mtx5;
    Gfx *dlist;
    ModelInfo *model;
    _DA790UnkStruct2 *ptr;
    f32 f1;
    s32 x, y, z;
    s32 m, n, o, p;
    s16 j, l;
    s32 size;
    s16 playernum;
    s16 sectnum;
    u16 i;
    u16 r, g, b;
    u8 k;
    u8 cond1, cond2;

    cond2 = 0;
    cond1 = 0;
    dlist = NULL;
    playernum = 0;

    if ((D_801A6D80 < 0x100) && (D_8012BBCC < 0x80))
    {
        D_801AE8F4 = spritenum;
        D_8012E154 = gpSprite[spritenum].picnum;
        D_8012FD86 = 0xFF - D_8013B2D0[spritenum].unk6;
        D_8012FD86 = CLAMP_MIN(CLAMP_MAX((D_8012FD86), 0xFF), 0);

        if ((gpSprite[D_801AE8F4].statnum != 10))
        {
            size = (((intptr_t)gpDisplayList) - ((intptr_t)gDisplayList[gGfxTaskIndex])) / (sizeof(Gfx));
            size = gDisplayListMaxSize - size;
            if (size < 0xA00)
                return;
        }

        if (gpSprite[spritenum].cstat & 0x800)
        {
            if (D_801A2688 == 0)
            {
                if (D_8010A9AC == 1)
                {
                    D_8010A9AC = 0;
                    gSPClearGeometryMode(gpDisplayList++, G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
                    gSPTexture(gpDisplayList++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
                }
                D_801A2688 = 1;
                gSPClearGeometryMode(gpDisplayList++, G_CULL_BACK);
                gDPSetTextureLUT(gpDisplayList++, G_TT_NONE);
                gDPSetCombineLERP(gpDisplayList++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                                                   0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
                gDPSetRenderMode(gpDisplayList++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_SURF2);
            }
        } if (!(gpSprite[spritenum].cstat & 0x800))
        {
            if (D_801A2688 == 1)
            {
                D_801A2688 = 0;
                D_8010A9AC = 0;
                D_8019956C = 0;
                gSPSetGeometryMode(gpDisplayList++, G_CULL_BACK);
                gDPSetTextureLUT(gpDisplayList++, G_TT_RGBA16);
                gDPSetCombineMode(gpDisplayList++, G_CC_MODULATEIDECALA, G_CC_PASS2);
                gDPSetRenderMode(gpDisplayList++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2);
            }
        }

        D_80105718 = 0;
        if (D_801A2688 != 0)
        {
            D_8010A9AC = 0;
            D_8019956C = 0;
            i = gpSprite[spritenum].unk25;
            D_80168810 = i;

            if (i == 31)
                D_80105718 = 1;

            if (gpSprite[spritenum].picnum == 2253)
                D_80105718 = 1;

            gDPSetPrimColor(gpDisplayList++, 0, 0, gpAlphaPalette[i].primary.r,
                                                   gpAlphaPalette[i].primary.g,
                                                   gpAlphaPalette[i].primary.b,
                                                   D_8012FD86);

            gDPSetEnvColor(gpDisplayList++, gpAlphaPalette[i].env.r,
                                            gpAlphaPalette[i].env.g,
                                            gpAlphaPalette[i].env.b,
                                            D_8012FD86);
            D_80119A9C = i;
        }
        else
        {
            j = 0;
            if (D_80106D50[spritenum] != -1)
                j = D_8019B940[D_80106D50[spritenum]].unk0 & 0x40;

            if (D_801CC8A8 != 0)
                j = 1;

            if (j != 0)
            {
                if (D_8010A9AC == 0)
                {
                    D_8010A9AC = 1;
                    gSPSetGeometryMode(gpDisplayList++, G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
                    gSPTexture(gpDisplayList++, 0x0FF8, 0x0FF8, 0, G_TX_RENDERTILE, G_ON);
                }
            }
            else if (D_8010A9AC == 1)
            {
                D_8010A9AC = 0;
                gSPClearGeometryMode(gpDisplayList++, G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
                gSPTexture(gpDisplayList++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
            }
            if (D_8012FD86 == 0xFF)
            {
                if (D_8019956C == 1)
                {
                    D_8019956C = 0;
                    gDPSetRenderMode(gpDisplayList++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2);
                    gDPSetCombineMode(gpDisplayList++, G_CC_MODULATEIDECALA, G_CC_PASS2);
                }
            }
            else if (D_8019956C == 0)
            {
                if (gpSprite[D_801AE8F4].statnum == 10)
                {
                    gDPSetRenderMode(gpDisplayList++, 0xC8104B70, 0); /*TODO*/
                }
                else
                {
                    gDPSetRenderMode(gpDisplayList++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_SURF2);
                }
                D_8019956C = 1;
                gDPSetCombineLERP(gpDisplayList++, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0,
                                                   0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
            }
            gDPSetEnvColor(gpDisplayList++, 0xFF, 0xFF, 0xFF, D_8012FD86);
        }

        func_8000C76C();
        if (gpSprite[spritenum].statnum == 55)
        {
            r = 0x80;
            g = 0x80;
            b = 0x80;
            cond1 = 1;
            D_8016A148 = 0;
            D_800FE410 = 0;
            D_80138680 = 0;
        }
        else if ((gpSprite[spritenum].picnum >= 2547) && (gpSprite[spritenum].picnum < 2553))
        {
            r = 0x64;
            g = 0x64;
            b = 0x64;
            cond1 = 1;
            D_8016A148 = 0;
            D_800FE410 = 0;
            D_80138680 = 0;
        }
        else if ((gpSprite[spritenum].statnum == 150) || (gpSprite[spritenum].statnum == 160))
        {
            cond1 = 1;
            r = (sins(gTotalClockLock << 7) >> 9) + 0x80;
            g = (sins(gTotalClockLock << 7) >> 9) + 0x80;
            b = (sins(gTotalClockLock << 7) >> 9) + 0x80;
            D_8016A148 = 0;
            D_800FE410 = 0;
            D_80138680 = 0;
        }
        else
        {
            j = gpSprite[spritenum].unk24;
            sectnum = gpSprite[spritenum].sectnum;
            if (j != 0xFF)
            {
                if ((D_80106D50[spritenum] == -1) || ((D_8019B940[D_80106D50[spritenum]].unk0 & 0x10) == 0))
                {
                    k = gpSector[sectnum].unk26;
                    if (gMapNum == MAP_ZERO_HOUR)
                        k = 200;

                    j = j + ((k - j) / 2);

                    if (j > 254)
                        j = 254;
                }
                func_8000DBDC(gpSector[sectnum].unk27, j);
                gpSprite[spritenum].unk24 = j;
            }
            else
            {
                cond1 = 1;
                func_8000DBDC(gpSector[sectnum].unk27, gpSector[sectnum].unk26);
            }

            r = D_8016A148;
            g = D_800FE410;
            b = D_80138680;
            D_80119A38 = 0;
            if ((D_80106D50[spritenum] != -1) && (D_8019B940[D_80106D50[spritenum]].unk0 & 0x100))
            {
                if (gpSprite[spritenum].statnum != 10)
                    D_8019B940[D_80106D50[spritenum]].unk0 &= ~0x100;

                l = D_800D6964[D_8019B940[D_80106D50[spritenum]].unk99];
                if (l != -1)
                {
                    D_80119A38 = 1;
                    D_8016A148 = (gpAlphaPalette[l].primary.r + gpAlphaPalette[l].env.r) >> 1;
                    D_800FE410 = (gpAlphaPalette[l].primary.g + gpAlphaPalette[l].env.g) >> 1;
                    D_80138680 = (gpAlphaPalette[l].primary.b + gpAlphaPalette[l].env.b) >> 1;
                    D_801B080C = gpSprite[spritenum].x + (cosf((gpSprite[spritenum].ang * (PI/1024))) * 256.0f);
                    D_8016A14C = gpSprite[spritenum].y + (sinf((gpSprite[spritenum].ang * (PI/1024))) * 256.0f);
                    D_8013A438 = gpSprite[spritenum].z;
                    cond2 = 1;
                }
                else
                {
                    goto block_66;
                }
            }
            else
            {
            block_66:
                func_8000DCF0(gpSprite[spritenum].x, gpSprite[spritenum].y, gpSprite[spritenum].z, sectnum);
            }
        }

        if (D_8012C470 >= 2)
        {
            if (gpSprite[spritenum].statnum == 10)
            {
                if (D_801AD470 == 4)
                {
                    if (D_800E16A0[gpSprite[spritenum].unk16] == D_800E16A0[D_801B0820])
                    {
                        cond1 = 1;
                        D_80138680 = 0;
                        D_800FE410 = 0;
                        D_8016A148 = 0;
                        r = D_8012DF04[D_801B0820].r;
                        g = D_8012DF04[D_801B0820].g;
                        b = D_8012DF04[D_801B0820].b;
                    }
                }

                if (D_801AD470 == 3)
                {
                    if (gpSprite[spritenum].unk16 == D_800FE9D0)
                    {
                        cond1 = 1;
                        r = 0;
                        g = 0xFF;
                        b = 0xFF;
                        D_80138680 = 0;
                        D_800FE410 = 0;
                        D_8016A148 = 0;
                    }
                }
            }
        }

        if (cond1 != 0)
        {
            gSPLightColor(gpDisplayList++, LIGHT_1, 0);
            gSPLightColor(gpDisplayList++, LIGHT_2, 0);
            r = CLAMP_MAX((r+D_8016A148), 0xFF);
            g = CLAMP_MAX((g+D_800FE410), 0xFF);
            b = CLAMP_MAX((b+D_80138680), 0xFF);
            gSPLightColor(gpDisplayList++, LIGHT_3, (r << 24) + (g << 16) + (b << 8));
        }
        else
        {
            if ((D_8016A148 | D_800FE410 | D_80138680) != 0)
            {
                D_801B080C -= gpSprite[spritenum].x;
                D_8016A14C -= gpSprite[spritenum].y;
                D_8013A438 -= gpSprite[spritenum].z;
                D_8013A438 /= 16;
                m = MAX(klabs(D_801B080C), MAX(klabs(D_8016A14C), klabs(D_8013A438)));
                if (m == 0)
                {
                    D_801B080C = 0;
                    D_8016A14C = 0;
                    D_8013A438 = -127;
                }
                else
                {
                    D_801B080C = (D_801B080C * 127) / m;
                    D_8016A14C = (D_8016A14C * 127) / m;
                    D_8013A438 = (D_8013A438 * 127) / m;
                }

                gpDynamic->light[D_8012BBCC].l.dir[0] = D_801B080C;
                gpDynamic->light[D_8012BBCC].l.dir[1] = D_8016A14C;
                gpDynamic->light[D_8012BBCC].l.dir[2] = D_8013A438;
                gSPLight(gpDisplayList++, &gpDynamic->light[D_8012BBCC], 1);
                gSPNumLights(gpDisplayList++, 2);
            }

            gSPLightColor(gpDisplayList++, LIGHT_1, ((D_8016A148 << 24) + (D_800FE410 << 16) + (D_80138680 << 8)));
            gSPLightColor(gpDisplayList++, LIGHT_2, (r << 24) + (g << 16) + (b << 8));

            if (!cond2)
            {
                r += D_8016A148 / 2;
                g += D_800FE410 / 2;
                b += D_80138680 / 2;
            }
            r *= 0.25;
            g *= 0.25;
            b *= 0.25;
            gSPLightColor(gpDisplayList++, LIGHT_3, (r << 24) + (g << 16) + (b << 8));
        }

        if (gpSprite[D_801AE8F4].statnum == 10)
        {
            n = playernum = gpSprite[D_801AE8F4].unk16;
            if (D_8012F6F0[n] != 0)
            {
                gSPDisplayList(gpDisplayList++, D_801297E0[n][gGfxTaskIndex]);
                return;
            }
            D_8012F6F0[n] = 1;
            dlist = gpDisplayList;
            gpDisplayList = D_801297E0[n][gGfxTaskIndex];
        }

        x = gpSprite[spritenum].x;
        y = gpSprite[spritenum].y;
        z = gpSprite[spritenum].z;
        arg1 = arg1 + 180.0f;

        if (gpSprite[spritenum].cstat & 0x4000)
        {
            if ((gpSprite[spritenum].cstat & 0x30) == 0x20)
            {
                o = klabs((D_80199640 - z));
                if (z == gpSector[gpSprite[spritenum].sectnum].ceilingz)
                {
                    z += ((o+16) / 32);
                }
                if (z == gpSector[gpSprite[spritenum].sectnum].floorz)
                {
                    z -= ((o+16) / 32);
                }
            }

            if ((gpSprite[spritenum].cstat & 0x30) == 0x10)
            {
                o = (func_80040D40(D_801A6D84,
                    D_800FE3F0,
                    gpSprite[spritenum].x,
                    gpSprite[spritenum].y) << 8) / (gPlayer[D_801B0820].unk6E * 60);

                if (o < 8)
                    o = 8;

                x = x + (sinf((gpSprite[spritenum].ang * (PI / 1024)) + (PI / 2)) * o);
                y = y - (cosf((gpSprite[spritenum].ang * (PI / 1024)) + (PI / 2)) * o);
            }
        }

        p = 0;
        if (gpSprite[spritenum].statnum == 302)
        {
            if (gpSprite[spritenum].picnum < 2565)
            {
                if (gpSprite[spritenum].picnum >= 2562)
                    p = 1;
            }
        }

        if (p == 0)
        {
            grPosition(&gpDynamic->mtx3[D_801A6D80],
                arg2,
                arg1,
                arg3,
                gpSprite[spritenum].xrepeat / 64.0,
                x / 4.0,
                y / 4.0,
                z / 64.0);
        }
        else
        {
            arg3 = ((gpSprite[spritenum].ang * 180) / 1024.0) + 90.0;
            f1 = ((D_8013B2D0[spritenum].unk4) * 180) / 1024.0;
            guRotateRPY(&mtx1, arg2, 0.0f, 0.0f);
            guRotateRPY(&mtx2, 0.0f, arg1, 0.0f);
            guRotateRPY(&mtx3, 0.0f, 0.0f, arg3);
            guRotateRPY(&mtx4, 0.0f, 0.0f, f1);

            grPosition(&mtx5, 0.0f, 0.0f, 0.0f,
                gpSprite[spritenum].xrepeat / 64.0,
                x / 4.0,
                y / 4.0,
                z / 64.0);

            grMtxCatL(&mtx4, &mtx1, &gpDynamic->mtx3[D_801A6D80]);
            grMtxCatL(&gpDynamic->mtx3[D_801A6D80], &mtx2, &gpDynamic->mtx3[D_801A6D80]);
            grMtxCatL(&gpDynamic->mtx3[D_801A6D80], &mtx3, &gpDynamic->mtx3[D_801A6D80]);
            grMtxCatL(&gpDynamic->mtx3[D_801A6D80], &mtx5, &gpDynamic->mtx3[D_801A6D80]);
        }

        gSPMatrix(gpDisplayList++, OS_K0_TO_PHYSICAL(&gpDynamic->mtx3[D_801A6D80]),
                                   G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        D_801A6D80++;
        D_8012BBCC++;
        ptr = func_80014040(gpSprite[spritenum].picnum);
        if (ptr == NULL)
        {
            model = D_800D52E0[gpSprite[spritenum].picnum-1280];
            if (model != NULL)
            {
                func_80011700(model);
                if ((gpSprite[spritenum].picnum == 1296) && (D_80119A38 != 0) && (D_8010A9AC == 0))
                {
                    func_800124EC(D_800D6964[D_8019B940[D_80106D50[spritenum]].unk99]);
                    func_80011700(&D_800D06C0);
                    func_80012630();
                }
            }
        }
        else
            func_80013FFC(ptr);

        gSPPopMatrix(gpDisplayList++, G_MTX_MODELVIEW);
        if (gpSprite[D_801AE8F4].statnum == 10)
        {
            gSPEndDisplayList(gpDisplayList++);
            gSPDisplayList(dlist, D_801297E0[playernum][gGfxTaskIndex]);
            gpDisplayList = dlist+1;
        }
    }
}

/*80011148*/
static f32 func_80011148(Vec4f vec1, Vec4f vec2)
{
    return (vec1[0] * vec2[0]) + (vec1[1] * vec2[1]) + (vec1[2] * vec2[2]) + vec1[3];
}

/*80011180*/
void func_80011180(void)
{
    f32 f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14;
    s32 i;
    f1 = sinf(0.61086524f);
    f2 = cosf(0.61086524f);
    f3 = 159.0f / (f1 / f2);
    f5 = 119.0f;
    f4 = 1.0 / sqrt((f3 * f3) + 14161.0f);
    D_80197DF0[0][0] = f2;
    D_80197DF0[0][1] = 0.0f;
    D_80197DF0[0][2] = f1;
    D_80197DF0[0][3] = 0.0f;
    D_80197DF0[1][0] = -f2;
    D_80197DF0[1][1] = 0.0f;
    D_80197DF0[1][2] = f1;
    D_80197DF0[1][3] = 0.0f;
    D_80197DF0[2][0] = 0.0f;
    D_80197DF0[2][1] = f3 * f4;
    D_80197DF0[2][2] = f4 * 119.0f;
    D_80197DF0[2][3] = 0.0f;
    D_80197DF0[3][0] = 0.0f;
    D_80197DF0[3][1] = -(f3 * f4);
    D_80197DF0[3][2] = f4 * 119.0f;
    D_80197DF0[3][3] = 0.0f;
    D_80106D3C = 0.18310827f;
    D_8012EB48 = (f3 * 65536.0) * (1.0 / 12000.0);
    f5 = cosf(D_8016A15C);
    f14 = f5;
    f6 = sinf(D_8016A15C);
    f7 = cosf(-D_801AEA10);
    f8 = sinf(-D_801AEA10);

    for (i = 0; i < 4; i++)
    {
        f9 = D_80197DF0[i][0];
        f10 = D_80197DF0[i][1];
        f11 = D_80197DF0[i][2];
        f12 = (f10 * f14) - (f11 * f6);
        f13 = (f10 * f6) + (f11 * f14);
        D_80197DF0[i][0] = (f9 * f7) - (f13 * f8);
        D_80197DF0[i][1] = f12;
        f13 = (f9 * f8) + (f13 * f7);
        D_80197DF0[i][2] = f13;
    }
}

/*80011410*/
static f32 func_80011410(ModelInfo *model)
{
    f32 f1, f2, f5, f3, f4, f6, f7, f8;

    f1 = model->unk24;
    f2 = model->unk26;
    f3 = model->unk28;
    f4 = model->unk2A;
    f5 = model->unk2C;
    f6 = model->unk2E;

    f7 = (f1 * f1) + (f5 * f5) + (f3 * f3);

    f8 = (f4 * f4) + (f5 * f5) + (f3 * f3);
    if (f7 < f8)
        f7 = f8;

    f8 = (f4 * f4) + (f2 * f2) + (f3 * f3);
    if (f7 < f8)
        f7 = f8;

    f8 = (f1 * f1) + (f2 * f2) + (f3 * f3);
    if (f7 < f8)
        f7 = f8;

    f8 = (f1 * f1) + (f5 * f5) + (f6 * f6);
    if (f7 < f8)
        f7 = f8;

    f8 = (f4 * f4) + (f5 * f5) + (f6 * f6);
    if (f7 < f8)
        f7 = f8;

    f8 = (f4 * f4) + (f2 * f2) + (f6 * f6);
    if (f7 < f8)
        f7 = f8;

    f8 = (f1 * f1) + (f2 * f2) + (f6 * f6);
    if (f7 < f8)
        f7 = f8;

    return ((sqrtf(f7) * gpSprite[D_801AE8F4].xrepeat) / 64.0);
}

/*800115E0*/
static s32 func_800115E0(ModelInfo *model)
{
    Matrix4f mtx;
    Vec4f vec;
    Vec4f *ptr;
    f32 f;
    s32 i;

    f = func_80011410(model);
    grMtxL2F(mtx, &gpDynamic->mtx3[D_801A6D80-1]);
    vec[0] = mtx[3][0] - gMapXpos * 0.5;
    vec[2] = -(mtx[3][1] - gMapYpos * 0.5);
    vec[1] = -(mtx[3][2] - gMapZpos * 0.5);

    for (i = 0, ptr = D_80197DF0; i < 4; i++, ptr++)
    {
        if (func_80011148(*ptr, vec) < -f)
            return 0;
    }
    return 1;
}

/*80011700*/
void func_80011700(ModelInfo *model)
{
    u8 *cmd;
    code0UnkStruct18 *vtx;
    ModelLight *light;
    ModelVertexInfo *vertex_info;

    loadModel(model);
    cmd = model->ramaddr + model->cmd_off;
    vertex_info = model->vertex_info;
    vtx = (code0UnkStruct18 *)vertex_info->ramaddr;
    light = (ModelLight *)(model->ramaddr + model->lights_off);
    gpModelTexture = model->ramaddr;
    gpModelTextureInfo = (ModelTextureInfo *)(model->ramaddr + model->texture_info_off);

    if ((D_800BD788 == 0) || (func_800115E0(model) != 0))
        func_800117A4(cmd, vtx, light);
}

/*800117A4*/
static void func_800117A4(u8 *cmd, code0UnkStruct18 *vtx, ModelLight *light)
{
    s16 pixel;
    s16 cond;
    s32 i, s, t, u;
    u8 j, k, l, m, n, o, p;
    u8 r, g, b;
    s8 tc0, tc1;
    s8 tc0_, tc1_;

    cond = 0;
    while (1)
    {
        m = *cmd++;
        switch (m)
        {
        case 13:
            l = *cmd++;
            u = *cmd++;
            pixel = (l << 8) | u;
            if (D_801A2688 == 0)
            {
                if (D_8010A9AC != 0)
                {
                    r = 0;
                    g = 0xFF;
                    b = 0xFF;
                }
                else
                {
                    /*ARGB1555*/
                    r = ((pixel & 0x7C00) >> 10) << 3;
                    g = ((pixel & 0x3E0) >> 5) << 3;
                    b = (pixel & 0x1F) << 3;
                }
                gDPSetPrimColor(gpDisplayList++, 0, 0, r, g, b, 0xFF);
                if (cond != 2)
                {
                    gDPSetCombineLERP(gpDisplayList++, PRIMITIVE, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT,
                                                       0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
                    cond = 2;
                }
            }
            break;
        case 0:
            n = *cmd++;
            o = *cmd++;

            gSPVertex(gpDisplayList++, D_80199114, o, n);
            D_80199114 = &D_80199114[o];

            for (i = 0; i < o; i++)
            {
                t = *cmd++;
                tc0_ = *cmd++;
                tc1_ = *cmd++;
                gpVertexN64->n.ob[0] = vtx[t].x;
                gpVertexN64->n.ob[1] = vtx[t].y;
                gpVertexN64->n.ob[2] = vtx[t].z;
                gpVertexN64->n.tc[0] = tc0_ << 6;
                gpVertexN64->n.tc[1] = tc1_ << 6;
                gpVertexN64->n.n[0] = light[t].n[0];
                gpVertexN64->n.n[1] = light[t].n[1];
                gpVertexN64->n.n[2] = light[t].n[2];
                gpVertexN64++;
            }
            break;
        case 1:
            n = *cmd++;
            o = *cmd++;

            gSPVertex(gpDisplayList++, D_80199114, o, n);
            D_80199114 = &D_80199114[o];

            for (i = 0; i < o; i++)
            {
                t = *cmd++;
                p = *cmd++;
                s = (t << 8) | p;
                tc0 = *cmd++;
                tc1 = *cmd++;
                gpVertexN64->n.ob[0] = vtx[s].x;
                gpVertexN64->n.ob[1] = vtx[s].y;
                gpVertexN64->n.ob[2] = vtx[s].z;
                gpVertexN64->n.tc[0] = tc0 << 6;
                gpVertexN64->n.tc[1] = tc1 << 6;
                gpVertexN64->n.n[0] = light[s].n[0];
                gpVertexN64->n.n[1] = light[s].n[1];
                gpVertexN64->n.n[2] = light[s].n[2];
                gpVertexN64++;
            }
            break;
        case 2:
        case 3:
            func_800163F0(*cmd++);
            break;
        case 4:
            func_8001660C(*cmd++);
            if (cond != 1)
            {
                if (D_8019956C == 1)
                {
                    gDPSetCombineLERP(gpDisplayList++, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0,
                                                       0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
                }
                else if (D_801A2688 == 1)
                {
                    gDPSetCombineLERP(gpDisplayList++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                                                       0, 0, 0, COMBINED, 0, 0, 0, COMBINED);

                    gDPSetPrimColor(gpDisplayList++, 0, 0, gpAlphaPalette[D_80168810].primary.r,
                                                           gpAlphaPalette[D_80168810].primary.g,
                                                           gpAlphaPalette[D_80168810].primary.b, D_8012FD86);
                }
                else
                {
                    gDPSetCombineMode(gpDisplayList++, G_CC_MODULATEIDECALA, G_CC_PASS2);
                }
                cond = 1;
            }
            break;
        case 5:
            func_8001660C(*cmd++);
            if (cond != 1)
            {
                if (D_8019956C == 1)
                {
                    gDPSetCombineLERP(gpDisplayList++, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0,
                                                       0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
                }
                else if (D_801A2688 == 1)
                {
                    gDPSetCombineLERP(gpDisplayList++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                                                       0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
                }
                else
                {
                    gDPSetCombineMode(gpDisplayList++, G_CC_MODULATEIDECALA, G_CC_PASS2);
                }
                cond = 1;
            }
            break;
        case 6:
            j = *cmd++;
            k = *cmd++;
            l = *cmd++;
            gSP1Triangle(gpDisplayList++, j, k, l, j);
            break;
        case 7:
            return;
        default:
            while (1);
        }
    }
}

/*80011DA8*/
void func_80011DA8(void)
{
    s16 i;

    func_8000F1E0();
    for (i = 0; i < D_8012DEFA; i++)
    {
        if ((gpSprite[D_801A68D0[i]].statnum != 10) || (gpSprite[D_801A68D0[i]].unk16 != D_801B0820))
        {
            if (D_801A68D0[i] != gPlayer[D_801B0820].unk52)
            {
                func_8000F474(D_801A68D0[i],
                    ((D_8013B2D0[D_801A68D0[i]].unk0 * 180) / 1024.0),
                    ((D_8013B2D0[D_801A68D0[i]].unk2 * 180) / 1024.0),
                    ((((gpSprite[D_801A68D0[i]].ang +
                        D_8013B2D0[D_801A68D0[i]].unk4) * 180) / 1024.0) + 90.0));
            }
        }
    }

    if (gPlayer[D_801B0820].unk60 != 0)
    {
        if (gPlayer[D_801B0820].unk52 == -1)
            func_800A3688();
    }

    if ((gPlayer[D_801B0820].unk52 != -1) ||
        ((gPlayer[D_801B0820].unk60 != 0) && (gPlayer[D_801B0820].unk6A >= 0xFF)))
    {
        func_8000F1E0();
        D_8013B2D0[gPlayer[D_801B0820].unk4A].unk6 = 0;
        func_8000F474(gPlayer[D_801B0820].unk4A,
            ((D_8013B2D0[gPlayer[D_801B0820].unk4A].unk0 * 180) / 1024.0),
            ((D_8013B2D0[gPlayer[D_801B0820].unk4A].unk2 * 180) / 1024.0),
            ((((gpSprite[gPlayer[D_801B0820].unk4A].ang +
                D_8013B2D0[gPlayer[D_801B0820].unk4A].unk4) * 180) / 1024.0) + 90.0));
    }
}

/*80012174*/
void func_80012174(void)
{
    s16 i;
    u16 spritenum;

    func_8000F1E0();

    for (i = 0; i < D_8016D180; i++)
    {
        spritenum = D_801AC8E8[i];
        if ((gpSprite[spritenum].statnum != 10) || (gpSprite[spritenum].unk16 != D_801B0820))
        {
            func_8000F474(spritenum,
                         ((D_8013B2D0[spritenum].unk0 * 180) / 1024.0),
                         ((D_8013B2D0[spritenum].unk2 * 180) / 1024.0),
                         ((((gpSprite[spritenum].ang + D_8013B2D0[spritenum].unk4) * 180) / 1024.0) + 90.0));
        }
    }
}

/*80012318*/
void func_80012318(void)
{
    if (gPlayer[D_801B0820].unk60 && gPlayer[D_801B0820].unk6A < 255 && gPlayer[D_801B0820].unk52 < 0)
    {
        func_8000F1E0();
        D_8013B2D0[gPlayer[D_801B0820].unk4A].unk6 = 255 - gPlayer[D_801B0820].unk6A;
        func_8000F474(gPlayer[D_801B0820].unk4A,
                     ((D_8013B2D0[gPlayer[D_801B0820].unk4A].unk0 * 180) / 1024.0),
                     ((D_8013B2D0[gPlayer[D_801B0820].unk4A].unk2 * 180) / 1024.0),
                     ((((gpSprite[gPlayer[D_801B0820].unk4A].ang + D_8013B2D0[gPlayer[D_801B0820].unk4A].unk4) * 180) / 1024.0) + 90.0));
    }
}

/*800124EC*/
static void func_800124EC(s16 arg0)
{
    D_800FE414 = D_801A2688;
    if (D_801A2688 == 0)
    {
        D_801A2688 = 1;
        D_80168810 = arg0;
        gDPSetTextureLUT(gpDisplayList++, G_TT_NONE);

        gDPSetCombineLERP(gpDisplayList++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE,
                                           0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED);

        gDPSetRenderMode(gpDisplayList++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_SURF2);

        gDPSetPrimColor(gpDisplayList++, 0, 0, gpAlphaPalette[arg0].primary.r,
                                               gpAlphaPalette[arg0].primary.g,
                                               gpAlphaPalette[arg0].primary.b,
                                               D_8012FD86);

        gDPSetEnvColor(gpDisplayList++, gpAlphaPalette[arg0].env.r,
                                        gpAlphaPalette[arg0].env.g,
                                        gpAlphaPalette[arg0].env.b,
                                        D_8012FD86);
    }
}

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
            gDPSetCombineLERP(gpDisplayList++, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0,
                                               0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
        }
    }
}

/*8001270C*/
static void func_8001270C(_DA790UnkStruct2 *arg0, s16 arg1)
{
    Mtx mtx1;
    Mtx mtx2;
    Mtx mtx3;
    Mtx mtx4;

    ModelInfo *model1;
    ModelInfo *model2;

    code0unkStruct8 *ptr;
    f32 fx, fy, fz;
    f32 f1, f2, f3, f4, f5, f6, f7;
    f32 ftemp;

    s32 prev;
    s32 m, n;

    s16 playernum, playernum2;

    s16 i, j, k, l;

    u8 cond, cond2, cond3;
    u8 unk99;

    f2 = 0.0f;
    f1 = 0.0f;
    f3 = 0.0f;
    ptr = &D_80197E40[D_80106D50[D_801AE8F4]];
    if (D_801A6D80 < 0x100)
    {
        if (ptr->unk8 == NULL)
        {
            fx = arg0->unk8[arg1].unk0 * 50.0f;
            fy = arg0->unk8[arg1].unk8 * 50.0f;
            fz = arg0->unk8[arg1].unk4 * 50.0f;
        }
        else
        {
            if ((arg1 >= 8) && (arg0->unk0 == 0))
            {
                func_80016F7C(ptr->unk4);
                j = ptr->unk0 + (arg1 * ptr->unk4->unk14);
                if (ptr->unk14 == -1)
                {
                    f2 = ptr->unk4->unk1C[j].unk4;
                    f1 = ptr->unk4->unk1C[j].unk2;
                    f3 = ptr->unk4->unk1C[j].unk0;
                }
                else
                {
                    func_80016F7C(ptr->unk18);
                    k = ptr->unk14 + (arg1 * klabs(ptr->unk18->unk14));
                    f4 = (f32)klabs(ptr->unkC) / (f32)ptr->unk10;
                    f2 = func_80040DFC(ptr->unk4->unk1C[j].unk4, ptr->unk18->unk1C[k].unk4, f4);
                    f1 = func_80040DFC(ptr->unk4->unk1C[j].unk2, ptr->unk18->unk1C[k].unk2, f4);
                    f3 = func_80040DFC(ptr->unk4->unk1C[j].unk0, ptr->unk18->unk1C[k].unk0, f4);
                }
            }
            else
            {
                func_80016F7C(ptr->unk8);
                j = ptr->unk2 + (arg1 * ptr->unk8->unk14);
                if (ptr->unk16 == -1)
                {
                    f2 = ptr->unk8->unk1C[j].unk4;
                    f1 = ptr->unk8->unk1C[j].unk2;
                    f3 = ptr->unk8->unk1C[j].unk0;
                }
                else
                {
                    func_80016F7C(ptr->unk1C);
                    k = ptr->unk16 + (arg1 * klabs(ptr->unk1C->unk14));
                    f4 = (f32)klabs(ptr->unkE) / (f32)ptr->unk12;
                    f2 = func_80040DFC(ptr->unk8->unk1C[j].unk4, ptr->unk1C->unk1C[k].unk4, f4);
                    f1 = func_80040DFC(ptr->unk8->unk1C[j].unk2, ptr->unk1C->unk1C[k].unk2, f4);
                    f3 = func_80040DFC(ptr->unk8->unk1C[j].unk0, ptr->unk1C->unk1C[k].unk0, f4);
                }
            }

            if (arg0->unk0 == 0)
            {
                cond3 = 0;
                if (gpSprite[D_801AE8F4].statnum == 10)
                {
                    cond3 = gPlayer[gpSprite[D_801AE8F4].unk16].unk54;
                    f5 = (gPlayer[gpSprite[D_801AE8F4].unk16].unk3E << 5);

                    if (gPlayer[gpSprite[D_801AE8F4].unk16].unk58 != 0)
                        f5 = 0.0f;
                }
                else
                    f5 = (D_8019B940[D_80106D50[D_801AE8F4]].unk7C << 5);

                if (cond3 != 0)
                {
                    if (arg1 == 1)
                        f1 += f5;
                }
                else
                {
                    if (f5 >= 0.0f)
                    {
                        f6 = CLAMP_MAX(f5, 5461.0f);
                        f7 = CLAMP_MIN((f5 - 5461.0f), 0.0f);
                    }
                    else
                    {
                        f6 = CLAMP_MIN(f5, -7281.0f);
                        f7 = CLAMP_MAX((f5 + 7281.0f), 0.0f);
                    }

                    if (((arg1 >= 9) && (arg1 < 11)) || (arg1 == 13))
                        f1 += f6;
                    if (arg1 == 8)
                        f1 += f7;
                }
            }

            fx = arg0->unk8[arg1].unk0 * 50.0f;
            fy = arg0->unk8[arg1].unk8 * 50.0f;
            if ((arg1 == 1) && ((arg0->unk0 < 6) || (arg0->unk0 >= 8)) && (arg0->unk0 != 8))
            {
                if (ptr->unk16 != -1)
                {
                    f4 = (f32)ptr->unkE / (f32)ptr->unk12;
                    ftemp = ptr->unk8->unk18[ptr->unk2].unk0;
                    fx += ftemp;
                    ftemp = ptr->unk8->unk18[ptr->unk2].unk4;
                    fy += ftemp;
                    fz = (ptr->unk8->unk18[ptr->unk2].unk2 * (1.0f - f4)) +
                        (ptr->unk1C->unk18[ptr->unk16].unk2 * f4);
                }
                else
                {
                    fx += ptr->unk8->unk18[ptr->unk2].unk0;
                    fz = ptr->unk8->unk18[ptr->unk2].unk2;
                    fy += ptr->unk8->unk18[ptr->unk2].unk4;
                }
            }
            else
                fz = arg0->unk8[arg1].unk4 * 50.0f;
        }

        if (arg0->unk0 == 6)
        {
            if (arg1 == 1)
                f1 = (D_8019B940[D_80106D50[D_801AE8F4]].unk7C << 5);
        }

        if (arg0->unk0 == 8)
        {
            if (arg1 == 1)
                f3 = ((gTotalClockLock * 1532) & 0xFFFF);
        }

        if ((arg0->unk0 >= 2) && (arg0->unk0 < 4))
        {
            if (arg1 == 0)
            {
                s32 a, b;
                a = (gTotalClockLock*2) & 0x7FF;
                m = gpSinTable[a];
                a = ((m / 32));
                b = a - 0x100;
                f1 = f3 = b;
                b = (gTotalClockLock*4) & 0x7FF;
                a = ((gpSinTable[b] / 32));
                a = a - 0x100;
                f2 = a;
            }

            if (arg1 == 1)
                f1 = (gpSprite[D_801AE8F4].unk22 << 5);

            if ((arg0->unk0 == 2) && (arg1 == arg0->unk0))
                f3 = (D_8019B940[D_80106D50[D_801AE8F4]].unk7C << 5);
        }

        if (arg0->unk0 == 7)
        {
            if (arg1 == 1)
                f3 = (D_8019B940[D_80106D50[D_801AE8F4]].unk7C << 5);
        }

        if (arg0->unk8[arg1].unk18 != -1)
        {
            fx -= arg0->unk8[arg0->unk8[arg1].unk18].unk0 * 50.0f;
            fy -= arg0->unk8[arg0->unk8[arg1].unk18].unk8 * 50.0f;
            fz -= arg0->unk8[arg0->unk8[arg1].unk18].unk4 * 50.0f;
        }
        cond = 0;
        if (D_801CC926 != 0)
        {
            if ((arg0->unk0 == 0) && (arg1 == 9))
                cond = 1;
            if ((arg0->unk0 == 9) && (arg1 == 15))
                cond = 1;
        }

        if (D_801CC8C8 != 0)
        {
            if (arg0->unk0 == 0)
            {
                if ((arg1 == 12) || (arg1 == 15))
                    cond = 1;
            }
        }
        if (cond != 0)
            guPosition(&mtx4, 0.0f, 0.0f, 0.0f, 2.5f, fx, fy, fz);
        else
            grTranslate(&mtx4, fx, fy, fz);

        f1 = (f1 * 360.0f) / 65536.0f;
        f2 = (f2 * 360.0f) / 65536.0f;
        f3 = (f3 * 360.0f) / 65536.0f;
        guRotateRPY(&mtx1, f1, 0.0f, 0.0f);
        guRotateRPY(&mtx2, 0.0f, f2, 0.0f);
        guRotateRPY(&mtx3, 0.0f, 0.0f, f3);
        grMtxCatL(&mtx2, &mtx1, &gpDynamic->mtx3[D_801A6D80]);
        grMtxCatL(&gpDynamic->mtx3[D_801A6D80], &mtx3, &gpDynamic->mtx3[D_801A6D80]);
        grMtxCatL(&gpDynamic->mtx3[D_801A6D80], &mtx4, &gpDynamic->mtx3[D_801A6D80]);
        gSPMatrix(gpDisplayList++, &gpDynamic->mtx3[D_801A6D80], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        prev = D_800BD788;
        D_800BD788 = 0;
        D_801A6D80++;

        if (arg0->unk4[arg1] != NULL)
        {
            m = D_80106D50[D_801AE8F4];
            if (!(D_8019B940[m].unk68 & (1 << arg1)))
            {
                if ((gpSprite[D_801AE8F4].statnum == 10) && (D_8012C470 == 1))
                {
                    playernum = gpSprite[D_801AE8F4].unk16;
                    model1 = arg0->unk4[arg1];
                    model2 = NULL;
                    if (D_8012F6E4[gPlayer[playernum].unk4C].unkB == 0)
                    {
                        switch (arg1)
                        {
                        case 8:
                            if (D_8019B940[m].unk7E > 0)
                            {
                                switch (D_801CA14C[gMapNum].unk0)
                                {
                                default:
                                    model1 = &D_800C1E4C;
                                    break;
                                case 2:
                                    model1 = &D_800C1F3C;
                                    break;
                                case 3:
                                    model1 = &D_800C1EC4;
                                    break;
                                }
                            }
                            if (((D_801CA14C[gMapNum].unk0 < 2) || (D_801CA14C[gMapNum].unk0 >= 4)) &&
                                (D_8010A940[playernum].unk2[1] != 0))
                            {
                                model2 = &D_800D1458;
                            }
                            break;
                        case 9:
                            if (D_8010A940[playernum].unk2[5] != 0)
                                model1 = &D_800D05D0;

                            if (D_8010A940[playernum].unk2[6] != 0)
                                model1 = &D_800D060C;

                            if ((D_801CA14C[gMapNum].unk0 >= 2) && (D_801CA14C[gMapNum].unk0 < 4))
                            {
                                if (D_8010A940[playernum].unk2[1] != 0)
                                    model1 = &D_800D0648;
                            }
                            break;
                        case 10:
                            if (D_8019B940[m].unk7E > 0)
                            {
                                if ((D_801CA14C[gMapNum].unk0 < 2) || (D_801CA14C[gMapNum].unk0 >= 4))
                                    model1 = &D_800C439C;
                            }
                            break;
                        case 13:
                            if (D_8019B940[m].unk7E > 0)
                            {
                                if ((D_801CA14C[gMapNum].unk0 < 2) || (D_801CA14C[gMapNum].unk0 >= 4))
                                    model1 = &D_800C43D8;
                            }
                            break;
                        }
                    }

                    if ((D_8012F6E4[gPlayer[playernum].unk4C].unkB == 3) && (arg1 == 1))
                    {
                        switch (gpSprite[D_801AE8F4].picnum)
                        {
                        case 1282:
                            model1 = &D_800C5080;
                            break;
                        case 1283:
                            model1 = &D_800C50BC;
                            break;
                        case 1284:
                            model1 = &D_800C50F8;
                            break;
                        }
                    }
                    func_80011700(model1);
                    if (model2 != NULL)
                        func_80011700(model2);
                }
                else
                {
                    model2 = arg0->unk4[arg1];
                    if ((arg1 == 1) && (gpSprite[D_801AE8F4].picnum >= 1282) &&
                        (gpSprite[D_801AE8F4].picnum < 1285) && (func_8004EFB4(D_801AE8F4) != 0))
                    {
                        switch (gpSprite[D_801AE8F4].picnum)
                        {
                        case 1282:
                            model2 = &D_800C5080;
                            break;
                        case 1283:
                            model2 = &D_800C50BC;
                            break;
                        case 1284:
                            model2 = &D_800C50F8;
                            break;
                        }
                    }
                    func_80011700(model2);
                }
            }
        }

        if ((arg0->unk0 == 0) && ((arg1 == 12) || (arg1 == 15)))
        {
            cond2 = D_8019B940[D_80106D50[D_801AE8F4]].unk0;
            cond2 >>= 7;
            l = D_8019B940[D_80106D50[D_801AE8F4]].unk99;
            playernum2 = -1;
            if (gpSprite[D_801AE8F4].statnum == 10)
            {
                playernum2 = gpSprite[D_801AE8F4].unk16;
                if (D_8011A680[playernum2][l][0] & 2)
                    cond2 = 1;
            }

            if (l == 10)
                cond2 = 1;

            if (l != 0)
            {
                if ((arg1 == 12) && (cond2))
                {
                    if (l == 10)
                        func_80011700(D_800D6784[l+1]);
                    else
                        func_80011700(D_800D6784[l]);

                    if (D_80119A38 != 0)
                    {
                        if ((D_8010A9AC == 0) && ((playernum2 == -1) || (gPlayer[playernum2].unk54 == 0)))
                        {
                            if (D_800D689C[l] != NULL)
                            {
                                func_800124EC(D_800D6964[l]);
                                func_80011700(D_800D689C[l]);
                                func_80012630();
                            }
                        }
                    }
                }
                if (arg1 == 15)
                {
                    func_80011700(D_800D6784[l]);
                    if ((D_80119A38 != 0) && (D_8010A9AC == 0))
                    {
                        if (D_800D689C[l] != NULL)
                        {
                            func_800124EC(D_800D6964[l]);
                            func_80011700(D_800D689C[l]);
                            func_80012630();
                        }
                    }
                }
            }
        }

        if ((arg0->unk0 == 6) && (arg1 == 1))
        {
            unk99 = D_8019B940[D_80106D50[D_801AE8F4]].unk99;
            if ((D_80119A38 != 0) && (D_8010A9AC == 0))
            {
                func_800124EC(D_800D6964[unk99]);
                switch (gpSprite[D_801AE8F4].picnum)
                {
                case 2219:
                    func_80011700(&D_800CFD9C);
                    break;
                case 2220:
                    func_80011700(&D_800D0198);
                    break;
                default:
                    func_80011700(&D_800D06FC);
                    break;
                }
                func_80012630();
            }
        }

        if ((arg0->unk0 >= 2 && arg0->unk0 < 4) && (arg1 == 1))
        {
            func_800124EC(35);
            if (D_8019B940[D_80106D50[D_801AE8F4]].unk0 & 0x4000)
                n = 6;
            else
                n = 3;

            switch (func_801C0FDC(-1) % n)
            {
            case 0:
                func_80011700(&D_800D051C);
                break;
            case 1:
                func_80011700(&D_800D0558);
                break;
            case 2:
                func_80011700(&D_800D0594);
                break;
            }
            func_80012630();
        }

        if ((arg0->unk0 == 3) && (arg1 == 0))
        {
            unk99 = D_8019B940[D_80106D50[D_801AE8F4]].unk99;
            if ((D_80119A38 != 0) && (D_8010A9AC == 0))
            {
                func_800124EC(D_800D6964[unk99]);
                func_80011700(&D_800D04E0);
                func_80012630();
            }
        }
        if ((arg0->unk0 == 2) && (arg1 == 2))
        {
            unk99 = D_8019B940[D_80106D50[D_801AE8F4]].unk99;
            if ((D_80119A38 != 0) && (D_8010A9AC == 0))
            {
                func_800124EC(D_800D6964[unk99]);
                func_80011700(&D_800D04A4);
                func_80012630();
            }
        }

        for (i = 0; i < arg0->unk2; i++)
        {
            if (arg0->unk8[i].unk18 == arg1)
                func_8001270C(arg0, i);
        }

        D_800BD788 = prev;
        gSPPopMatrix(gpDisplayList++, G_MTX_MODELVIEW);
    }
}

/*80013FFC*/
void func_80013FFC(_DA790UnkStruct2 *arg0)
{
    if (D_80106D50[D_801AE8F4] != -1)
        func_8001270C(arg0, 0);
}

/*80014040*/
_DA790UnkStruct2 *func_80014040(s16 arg0)
{
    switch (arg0)
    {
    case 1535:
        return &D_800DA0D0;
    case 1533:
        return &D_800DA0DC;
    case 1532:
        return &D_800DA0E8;
    case 2003:
        return &D_800DA0F4;
    case 1534:
        return &D_800DA100;
    case 2000:
        return &D_800DA10C;
    case 2001:
        return &D_800DA118;
    case 2366:
        return &D_800DA124;
    case 2382:
        return &D_800DA130;
    case 2002:
        return &D_800DA13C;
    case 2005:
        return &D_800DA148;
    case 2301:
        return &D_800DA178;
    case 2302:
        return &D_800DA160;
    case 2303:
        return &D_800DA184;
    case 2006:
        return &D_800DA190;
    case 2574:
        return &D_800DA19C;
    case 2309:
        return &D_800DA16C;
    case 2004:
        return &D_800DA154;
    case 1286:
        return &D_800DA7A0;
    case 1821:
        return &D_800DA7AC;
    case 1824:
        return &D_800DA7B8;
    case 1825:
        return &D_800DA7C4;
    case 1826:
        return &D_800DA7D0;
    case 1287:
        return &D_800DA890;
    case 1851:
        return &D_800DA89C;
    case 1853:
        return &D_800DA8A8;
    case 1855:
        return &D_800DA8B4;
    case 1856:
        return &D_800DA8C0;
    case 1290:
        return &D_800DA8CC;
    case 1859:
        return &D_800DA8D8;
    case 1861:
        return &D_800DA8E4;
    case 1862:
        return &D_800DA8F0;
    case 1864:
        return &D_800DA8FC;
    case 1288:
        return &D_800DA908;
    case 1882:
        return &D_800DA914;
    case 1875:
        return &D_800DA920;
    case 1877:
        return &D_800DA92C;
    case 1878:
        return &D_800DA938;
    case 1291:
        return &D_800DA944;
    case 1866:
        return &D_800DA950;
    case 1867:
        return &D_800DA95C;
    case 1880:
        return &D_800DA968;
    case 1871:
        return &D_800DA974;
    case 1998:
        return &D_800DA818;
    case 1835:
        return &D_800DA824;
    case 1838:
        return &D_800DA830;
    case 1840:
        return &D_800DA83C;
    case 1842:
        return &D_800DA848;
    case 1289:
        return &D_800DA7DC;
    case 1827:
        return &D_800DA7E8;
    case 1828:
        return &D_800DA7F4;
    case 1830:
        return &D_800DA800;
    case 1833:
        return &D_800DA80C;
    case 1999:
        return &D_800DA854;
    case 1843:
        return &D_800DA860;
    case 1845:
        return &D_800DA86C;
    case 1847:
        return &D_800DA878;
    case 1850:
        return &D_800DA884;
    case 1282:
        return &D_800DA370;
    case 1800:
        return &D_800DA394;
    case 1801:
        return &D_800DA3A0;
    case 1806:
        return &D_800DA3AC;
    case 1807:
        return &D_800DA3B8;
    case 1283:
        return &D_800DA37C;
    case 1812:
        return &D_800DA3C4;
    case 1814:
        return &D_800DA3D0;
    case 1815:
        return &D_800DA3DC;
    case 1819:
        return &D_800DA3E8;
    case 2468:
    case 1284:
        return &D_800DA388;
    case 1793:
        return &D_800DA3F4;
    case 1795:
        return &D_800DA400;
    case 1796:
        return &D_800DA40C;
    case 1798:
        return &D_800DA418;
    case 1285:
        return &D_800DBE5C;
    case 1292:
        return &D_800DA5D4;
    case 1295:
        return &D_800DAA60;
    case 1299:
        return &D_800DB7B8;
    case 1300:
        return &D_800DB7C4;
    case 1426:
        return &D_800DB86C;
    case 1442:
        return &D_800DB860;
    case 1303:
    case 1305:
        return &D_800DB6B0;
    case 1304:
        return &D_800DB6D4;
    case 1724:
        return &D_800DB6BC;
    case 1725:
        return &D_800DB6C8;
    case 1726:
        return &D_800DB6E0;
    case 1727:
        return &D_800DB6EC;
    case 1728:
        return &D_800DB6F8;
    case 1280:
        return &D_800DBACC;
    case 1306:
        return &D_800DBC68;
    case 2219:
        return &D_800DB7D0;
    case 2220:
        return &D_800DB7DC;
    case 1531:
        return &D_800DC148;
    case 1293:
        return &D_800DC1EC;
    case 1294:
        return &D_800DC1F8;
    case 1307:
        return &D_800DC4E8;
    case 1309:
        return &D_800DC848;
    case 1308:
        return &D_800DC9E8;
    }
    return 0;
}

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

/*80014D6C*/
static void func_80014D6C(_DA790UnkStruct2 *arg0, s16 arg1)
{
    Matrix4f mf1, mf2, mf3, mf4, mf5;
    code0unkStruct8 *ptr;
    f32 f1, f2, f3;
    f32 f4, f5, f6;
    f32 f7;
    s16 i, j, k;

    ptr = &D_80197E40[D_80106D50[D_801AE8F4]];

    f1 = 0.0f;
    f2 = 0.0f;
    f3 = 0.0f;

    if (ptr->unk8 == NULL)
    {
        f4 = arg0->unk8[arg1].unk0;
        f5 = arg0->unk8[arg1].unk8;
        f6 = arg0->unk8[arg1].unk4;
    }
    else
    {
        func_80016F7C(ptr->unk8);
        j = ptr->unk2 + (arg1 * ptr->unk8->unk14);

        if (ptr->unk16 == -1)
        {
            f1 = ptr->unk8->unk1C[j].unk4;
            f2 = ptr->unk8->unk1C[j].unk2;
            f3 = ptr->unk8->unk1C[j].unk0;
        }
        else
        {
            func_80016F7C(ptr->unk1C);
            k = ptr->unk16 + (arg1 * klabs(ptr->unk1C->unk14));
            f7 = (f32)klabs(ptr->unkE) / ptr->unk12;
            f1 = func_80040DFC(ptr->unk8->unk1C[j].unk4, ptr->unk1C->unk1C[k].unk4, f7);
            f2 = func_80040DFC(ptr->unk8->unk1C[j].unk2, ptr->unk1C->unk1C[k].unk2, f7);
            f3 = func_80040DFC(ptr->unk8->unk1C[j].unk0, ptr->unk1C->unk1C[k].unk0, f7);
        }

        f4 = arg0->unk8[arg1].unk0;
        f5 = arg0->unk8[arg1].unk8;
        f6 = arg0->unk8[arg1].unk4;
    }

    j = arg0->unk8[arg1].unk18;
    if (j != -1)
    {
        do { f4 -= arg0->unk8[j].unk0; } while (0); /*FAKEMATCH*/
        f5 -= arg0->unk8[j].unk8;
        f6 -= arg0->unk8[j].unk4;
    }

    f2 = (f2 * 360.0f) / 65536.0f;
    f1 = (f1 * 360.0f) / 65536.0f;
    f3 = (f3 * 360.0f) / 65536.0f;

    guRotateRPYF(mf1, f2, 0.0f, 0.0f);
    guRotateRPYF(mf2, 0.0f, f1, 0.0f);
    guRotateRPYF(mf3, 0.0f, 0.0f, f3);
    grTranslateF(mf4, f4 * 50.0f, -f5 * 50.0f, f6 * 50.0f);
    grMtxCatF(mf2, mf1, mf5);
    grMtxCatF(mf5, mf3, mf5);
    grMtxCatF(mf5, mf4, mf5);
    func_80014D04(mf5);

    if (arg0->unk0 == 11)
    {
        if (arg1 == 12)
            copyMatrix(D_80199578, D_801B0830[D_801ACC60]);
        if (arg1 == 13)
            copyMatrix(D_800FF3A0, D_801B0830[D_801ACC60]);
        if (arg1 == 4)
            copyMatrix(D_801AE9D0, D_801B0830[D_801ACC60]);
    }

    for (i = 0; i < arg0->unk2; i++)
    {
        if (arg0->unk8[i].unk18 == arg1)
            func_80014D6C(arg0, i);
    }

    func_80014D4C();
}

/*800152AC*/
static void func_800152AC(s32 spritenum1, s32 spritenum2, Matrix4f mf, s32 x, s32 y, s32 z)
{
    f32 ox, oy, oz;
    SpriteType *spr1;
    SpriteType *spr2;

    spr1 = &gpSprite[spritenum1];
    spr2 = &gpSprite[spritenum2];
    changeSpriteSect(spritenum1, spr2->sectnum);
    grMtxXFMF(mf, x, y, z, &ox, &oy, &oz);
    spr1->x = spr2->x - ((s32)ox * 4);
    spr1->y = spr2->y - ((s32)oy * 4);
    spr1->z = spr2->z - ((s32)oz * 64);
    spr1->ang = spr2->ang;
    D_8013B2D0[spritenum1].unk2 = D_8013B2D0[spritenum2].unk2;
    D_8013B2D0[spritenum1].unk0 = D_8013B2D0[spritenum2].unk0;
}

/*80015458*/
static void func_80015458(_DA790UnkStruct2 *arg0, s16 arg1)
{
    Matrix4f mf2, mf1, mf3, mf4, mf5;
    code0unkStruct8 *ptr;

    f32 fx, fy, fz;
    f32 f1, f2, f3, f4, f5, f6, f7;
    f32 ftemp;

    s32 unk54;

    s16 i, j, k, l;

    ptr = &D_80197E40[D_80106D50[D_801AE8F4]];

    f2 = 0.0f;
    f1 = 0.0f;
    f3 = 0.0f;
    fx = 0.0f; /*FAKEMATCH?*/

    if (ptr->unk8 == NULL)
    {
        fx = arg0->unk8[arg1].unk0 * 50.0f;
        fy = arg0->unk8[arg1].unk8 * 50.0f;
        fz = arg0->unk8[arg1].unk4 * 50.0f;
    }
    else
    {
        if (arg1 >= 8)
        {
            func_80016F7C(ptr->unk4);
            j = ptr->unk0 + (arg1 * ptr->unk4->unk14);
            if (ptr->unk14 == -1)
            {
                f2 = ptr->unk4->unk1C[j].unk4;
                f1 = ptr->unk4->unk1C[j].unk2;
                f3 = ptr->unk4->unk1C[j].unk0;
            }
            else
            {
                func_80016F7C(ptr->unk18);
                k = ptr->unk14 + (arg1 * klabs(ptr->unk18->unk14));
                f4 = (f32)klabs(ptr->unkC) / (f32)ptr->unk10;
                f2 = func_80040DFC(ptr->unk4->unk1C[j].unk4, ptr->unk18->unk1C[k].unk4, f4);
                f1 = func_80040DFC(ptr->unk4->unk1C[j].unk2, ptr->unk18->unk1C[k].unk2, f4);
                f3 = func_80040DFC(ptr->unk4->unk1C[j].unk0, ptr->unk18->unk1C[k].unk0, f4);
            }
        }
        else
        {
            func_80016F7C(ptr->unk8);
            j = ptr->unk2 + (arg1 * ptr->unk8->unk14);
            if (ptr->unk16 == -1)
            {
                f2 = ptr->unk8->unk1C[j].unk4;
                f1 = ptr->unk8->unk1C[j].unk2;
                f3 = ptr->unk8->unk1C[j].unk0;
            }
            else
            {
                func_80016F7C(ptr->unk1C);
                k = ptr->unk16 + (arg1 * klabs(ptr->unk1C->unk14));
                f4 = (f32)klabs(ptr->unkE) / (f32)ptr->unk12;
                f2 = func_80040DFC(ptr->unk8->unk1C[j].unk4, ptr->unk1C->unk1C[k].unk4, f4);
                f1 = func_80040DFC(ptr->unk8->unk1C[j].unk2, ptr->unk1C->unk1C[k].unk2, f4);
                f3 = func_80040DFC(ptr->unk8->unk1C[j].unk0, ptr->unk1C->unk1C[k].unk0, f4);
            }
        }

        unk54 = gPlayer[gpSprite[D_801AE8F4].unk16].unk54;
        f5 = (gPlayer[gpSprite[D_801AE8F4].unk16].unk3E << 5);

        if (gPlayer[gpSprite[D_801AE8F4].unk16].unk58 != 0)
            f5 = 0.0f;
        if (unk54 != 0)
        {
            if (arg1 == 1)
                f1 += f5;
        }
        else
        {
            if (f5 >= 0.0f)
            {
                f6 = CLAMP_MAX(f5, 5461.0f);
                f7 = CLAMP_MIN((f5 - 5461.0f), 0.0f);
            }
            else
            {
                f6 = CLAMP_MIN(f5, -7281.0f);
                f7 = CLAMP_MAX((f5 + 7281.0f), 0.0f);
            }

            if ((arg1 >= 9 && arg1 < 11) || (arg1 == 13))
                f1 += f6;
            if (arg1 == 8)
                f1 += f7;
        }

        fx = arg0->unk8[arg1].unk0 * 50.0f;
        fy = arg0->unk8[arg1].unk8 * 50.0f;

        if (arg1 == 1)
        {
            if (ptr->unk16 != -1)
            {
                f4 = (f32)ptr->unkE / (f32)ptr->unk12;
                ftemp = ptr->unk8->unk18[ptr->unk2].unk0;
                fx += ftemp;
                ftemp = ptr->unk8->unk18[ptr->unk2].unk4;
                fy += ftemp;
                fz = (ptr->unk8->unk18[ptr->unk2].unk2 * (1.0f - f4)) +
                    (ptr->unk1C->unk18[ptr->unk16].unk2 * f4);
            }
            else
            {
                fx += ptr->unk8->unk18[ptr->unk2].unk0;
                fy += ptr->unk8->unk18[ptr->unk2].unk4;
                fz = ptr->unk8->unk18[ptr->unk2].unk2;
            }
        }
        else
            fz = arg0->unk8[arg1].unk4 * 50.0f;
    }

    if (arg0->unk8[arg1].unk18 != -1)
    {
        fx -= arg0->unk8[arg0->unk8[arg1].unk18].unk0 * 50.0f;
        fy -= arg0->unk8[arg0->unk8[arg1].unk18].unk8 * 50.0f;
        fz -= arg0->unk8[arg0->unk8[arg1].unk18].unk4 * 50.0f;
    }

    f1 = (f1 * 360.0f) / 65536.0f;
    f2 = (f2 * 360.0f) / 65536.0f;
    f3 = (f3 * 360.0f) / 65536.0f;
    guRotateRPYF(mf1, -f1, 0.0f, 0.0f);
    guRotateRPYF(mf2, 0.0f, f2, 0.0f);
    guRotateRPYF(mf3, 0.0f, 0.0f, -f3);
    grTranslateF(mf4, fx, -fy, fz);
    grMtxCatF(mf2, mf1, mf5);
    grMtxCatF(mf5, mf3, mf5);
    grMtxCatF(mf5, mf4, mf5);
    func_80014D04(mf5);

    if (arg1 == 15)
        copyMatrix(D_801AFDE0, D_801B0830[D_801ACC60]);

    for (i = 0; i <arg0->unk2; i++)
    {
        if (arg0->unk8[i].unk18 == arg1)
            func_80015458(arg0, i);
    }

    func_80014D4C();
}

/*80015DE0*/
void func_80015DE0(s32 spritenum)
{
    SpriteType *spr;
    SpriteType *spr2;
    code0UnkStruct5 *ptr;
    f32 f3, f2, f1;
    s32 i, nexti;

    D_801AE8F4 = spritenum;
    if (D_80106D50[D_801AE8F4] != -1)
    {
        ptr = &D_8013B2D0[spritenum];
        spr = &gpSprite[spritenum];
        f1 = (ptr->unk2 * 180) / 1024.0;
        f2 = (ptr->unk0 * 180) / 1024.0;
        f3 = (((spr->ang + ptr->unk4) * 180) / 1024.0) + 90.0;
        if (spr->picnum == 1306)
        {
            func_80014C7C(-f1, -f2, f3, ((f32)spr->xrepeat / 64.0));
            func_80014D6C(&D_800DBC68, 0);

            i = gHeadSpriteStat[302];
            while (i >= 0)
            {
                nexti = gNextSpriteStat[i];
                spr2 = &gpSprite[i];
                if ((spr2->picnum == 2559) || (spr2->picnum == 2560))
                {
                    changeSpriteSect(i, spr->sectnum);
                    spr2->x = spr->x;
                    spr2->y = spr->y;
                    spr2->z = spr->z;
                    spr2->ang = spr->ang;
                    D_8013B2D0[i].unk2 = ptr->unk2;
                }

                if (spr2->picnum == 2562)
                    func_800152AC(i, spritenum, D_80199578, 0, 0, 0);

                if (spr2->picnum == 2563)
                    func_800152AC(i, spritenum, D_800FF3A0, 0, 0, 0);

                if (spr2->picnum == 2564)
                    func_800152AC(i, spritenum, D_801AE9D0, 0, 0, 0);

                i = nexti;
            }
        }

        if (spr->statnum == 10)
        {
            func_80014C7C(f1, f2, f3, ((f32)spr->xrepeat / 64.0));
            func_80015458(func_80014040(gpSprite[spritenum].picnum), 0);
            i = func_80058934(spr->x, spr->y, spr->z, spr->sectnum, 72);
            func_800152AC(i, spritenum, D_801AFDE0, 0, 0xF, -80);
            D_801AE910 = gpSprite[i].x;
            D_8013F950 = gpSprite[i].y;
            D_8016A144 = gpSprite[i].z;
            deleteSprite(i);
        }
    }
}
