#include "math.h"
#include "common.h"
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
#include "code0/data/DA790.h"

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
/*80106D3C*/ f32 D_80106D3C; /*unused*/
/*8012E154*/ u16 D_8012E154; /*unused*/
/*8012EB48*/ f32 D_8012EB48; /*unused*/
/*8012FD86*/ s16 D_8012FD86; /*alpha*/
/*80197DF0*/ Vec4f _frustumPlanes[4] ALIGNED(8);
/*80199578*/ Matrix4f D_80199578 ALIGNED(8);
/*801AE9D0*/ Matrix4f D_801AE9D0 ALIGNED(8);
/*801AFDE0*/ Matrix4f D_801AFDE0 ALIGNED(8);

/*.text*/
static f32 _computeModelBoundingSphereRadius(ModelInfo *model);
static void _executeModelDisplayCmd(u8 *cmd, code0UnkStruct18 *vtx, ModelLight *light);
static void func_800124EC(s16);
static void func_80012630(void);

/*8000F1E0*/
void func_8000F1E0(void)
{
    initVertexList();
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
void setLight1Ligth2Color(s16 r1, s16 g1, s16 b1, s16 r2, s16 g2, s16 b2)
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
    _FDE0UnkStruct2 *ptr;
    f32 f1;
    s32 x, y, z;
    s32 m, n, o, p;
    s16 j, l;
    s32 size;
    s16 playernum;
    s16 sectnum;
    u16 pal;
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
        }
        if (!(gpSprite[spritenum].cstat & 0x800))
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
            pal = gpSprite[spritenum].unk25;
            D_80168810 = pal;

            if (pal == 31)
                D_80105718 = 1;

            if (gpSprite[spritenum].picnum == 2253)
                D_80105718 = 1;

            gDPSetPrimColor(gpDisplayList++, 0, 0, gpAlphaPalette[pal].primary.r,
                                                   gpAlphaPalette[pal].primary.g,
                                                   gpAlphaPalette[pal].primary.b,
                                                   D_8012FD86);

            gDPSetEnvColor(gpDisplayList++, gpAlphaPalette[pal].env.r,
                                            gpAlphaPalette[pal].env.g,
                                            gpAlphaPalette[pal].env.b,
                                            D_8012FD86);
            D_80119A9C = pal;
        }
        else
        {
            j = 0;
            if (gActorSpriteMap[spritenum] != -1)
                j = gActor[gActorSpriteMap[spritenum]].flag & 0x40;

            if (gCheatIceSkinConfig != CONFIG_OFF)
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

        initVertexList();
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
                if ((gActorSpriteMap[spritenum] == -1) || ((gActor[gActorSpriteMap[spritenum]].flag & 0x10) == 0))
                {
                    k = gpSector[sectnum].floorshade;
                    if (gMapNum == MAP_ZERO_HOUR)
                        k = 200;

                    j = j + ((k - j) / 2);

                    if (j > 254)
                        j = 254;
                }
                func_8000DBDC(gpSector[sectnum].floorpal, j);
                gpSprite[spritenum].unk24 = j;
            }
            else
            {
                cond1 = 1;
                func_8000DBDC(gpSector[sectnum].floorpal, gpSector[sectnum].floorshade);
            }

            r = D_8016A148;
            g = D_800FE410;
            b = D_80138680;
            D_80119A38 = 0;
            if ((gActorSpriteMap[spritenum] != -1) && (gActor[gActorSpriteMap[spritenum]].flag & 0x100))
            {
                if (gpSprite[spritenum].statnum != 10)
                    gActor[gActorSpriteMap[spritenum]].flag &= ~0x100;

                l = D_800D6964[gActor[gActorSpriteMap[spritenum]].unk99];
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

        if (gPlayerCount >= 2)
        {
            if (gpSprite[spritenum].statnum == 10)
            {
                if (D_801AD470 == 4)
                {
                    if (D_800E16A0[gpSprite[spritenum].unk16] == D_800E16A0[gPlayerNum])
                    {
                        cond1 = 1;
                        D_80138680 = 0;
                        D_800FE410 = 0;
                        D_8016A148 = 0;
                        r = D_8012DF04[gPlayerNum].r;
                        g = D_8012DF04[gPlayerNum].g;
                        b = D_8012DF04[gPlayerNum].b;
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
        arg1 += 180.0f;

        if (gpSprite[spritenum].cstat & 0x4000)
        {
            if ((gpSprite[spritenum].cstat & 0x30) == 0x20)
            {
                o = klabs((gGlobalPosZ - z));
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
                o = (func_80040D40(gGlobalPosX,
                    gGlobalPosY,
                    gpSprite[spritenum].x,
                    gpSprite[spritenum].y) << 8) / (gPlayer[gPlayerNum].unk6E * 60);

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
            model = gModelList[gpSprite[spritenum].picnum-MODELLIST];
            if (model != NULL)
            {
                drawModel(model);
                if ((gpSprite[spritenum].picnum == SENTRYDRONE) && (D_80119A38 != 0) && (D_8010A9AC == 0))
                {
                    func_800124EC(D_800D6964[gActor[gActorSpriteMap[spritenum]].unk99]);
                    drawModel(&D_800D06C0);
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
static f32 _dotProduct(Vec4f vec1, Vec4f vec2)
{
    return (vec1[0] * vec2[0]) + (vec1[1] * vec2[1]) + (vec1[2] * vec2[2]) + vec1[3];
}

/*80011180*/
void computeFrustumPlanes(void)
{
    f32 f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14;
    s32 i;
    f1 = sinf(DEG2RAD(35.0f));
    f2 = cosf(DEG2RAD(35.0f));
    f3 = ((SCREEN_WIDTH / 2.0f) - 1.0f) / (f1 / f2);
    f5 = ((SCREEN_HEIGHT / 2.0f) - 1.0f);
    f4 = 1.0 / sqrt(SQ(f3) + SQ(f5));
    _frustumPlanes[0][0] = f2;
    _frustumPlanes[0][1] = 0.0f;
    _frustumPlanes[0][2] = f1;
    _frustumPlanes[0][3] = 0.0f;
    _frustumPlanes[1][0] = -f2;
    _frustumPlanes[1][1] = 0.0f;
    _frustumPlanes[1][2] = f1;
    _frustumPlanes[1][3] = 0.0f;
    _frustumPlanes[2][0] = 0.0f;
    _frustumPlanes[2][1] = f3 * f4;
    _frustumPlanes[2][2] = f4 * f5;
    _frustumPlanes[2][3] = 0.0f;
    _frustumPlanes[3][0] = 0.0f;
    _frustumPlanes[3][1] = -(f3 * f4);
    _frustumPlanes[3][2] = f4 * f5;
    _frustumPlanes[3][3] = 0.0f;
    D_80106D3C = 0.18310827f;
    D_8012EB48 = (f3 * 65536.0) * (1.0 / 12000.0);
    f14 = cosf(gGlobalViewHorizAng);
    f6 = sinf(gGlobalViewHorizAng);
    f7 = cosf(-gGlobalAng);
    f8 = sinf(-gGlobalAng);

    for (i = 0; i < ARRAY_COUNT(_frustumPlanes); i++)
    {
        f9 = _frustumPlanes[i][0];
        f10 = _frustumPlanes[i][1];
        f11 = _frustumPlanes[i][2];
        f12 = (f10 * f14) - (f11 * f6);
        f13 = (f10 * f6) + (f11 * f14);
        _frustumPlanes[i][0] = (f9 * f7) - (f13 * f8);
        _frustumPlanes[i][1] = f12;
        f13 = (f9 * f8) + (f13 * f7);
        _frustumPlanes[i][2] = f13;
    }
}

/*80011410*/
static f32 _computeModelBoundingSphereRadius(ModelInfo *model)
{
    f32 xmin, ymin, ymax, zmin, xmax, zmax, f7, f8;

    xmin = model->xmin;
    ymin = model->ymin;
    zmin = model->zmin;
    xmax = model->xmax;
    ymax = model->ymax;
    zmax = model->zmax;

    f7 = SQ(xmin) + SQ(ymax) + SQ(zmin);

    f8 = SQ(xmax) + SQ(ymax) + SQ(zmin);
    if (f7 < f8)
        f7 = f8;

    f8 = SQ(xmax) + SQ(ymin) + SQ(zmin);
    if (f7 < f8)
        f7 = f8;

    f8 = SQ(xmin) + SQ(ymin) + SQ(zmin);
    if (f7 < f8)
        f7 = f8;

    f8 = SQ(xmin) + SQ(ymax) + SQ(zmax);
    if (f7 < f8)
        f7 = f8;

    f8 = SQ(xmax) + SQ(ymax) + SQ(zmax);
    if (f7 < f8)
        f7 = f8;

    f8 = SQ(xmax) + SQ(ymin) + SQ(zmax);
    if (f7 < f8)
        f7 = f8;

    f8 = SQ(xmin) + SQ(ymin) + SQ(zmax);
    if (f7 < f8)
        f7 = f8;

    return ((sqrtf(f7) * gpSprite[D_801AE8F4].xrepeat) / 64.0);
}

/*800115E0*/
static s32 _isModelVisible(ModelInfo *model)
{
    Matrix4f mtx;
    Vec4f vec;
    Vec4f *ptr;
    f32 radius;
    s32 i;

#ifdef TARGET_N64
    radius = _computeModelBoundingSphereRadius(model);
    grMtxL2F(mtx, &gpDynamic->mtx3[D_801A6D80-1]);
    vec[0] = mtx[3][0] - gMapXpos * 0.5;
    vec[2] = -(mtx[3][1] - gMapYpos * 0.5);
    vec[1] = -(mtx[3][2] - gMapZpos * 0.5);

    for (i = 0, ptr = _frustumPlanes; i < ARRAY_COUNT(_frustumPlanes); i++, ptr++)
    {
        if (_dotProduct(*ptr, vec) < -radius)
            return 0;
    }
#endif
    return 1;
}

/*80011700*/
void drawModel(ModelInfo *model)
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

    if ((D_800BD788 == 0) || (_isModelVisible(model) != 0))
        _executeModelDisplayCmd(cmd, vtx, light);
}

/*800117A4*/
static void _executeModelDisplayCmd(u8 *cmd, code0UnkStruct18 *vtx, ModelLight *light)
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

            gSPVertex(gpDisplayList++, gpVertexList, o, n);
            gpVertexList = &gpVertexList[o];

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

            gSPVertex(gpDisplayList++, gpVertexList, o, n);
            gpVertexList = &gpVertexList[o];

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
            loadModelTexturePalette(*cmd++);
            break;
        case 4:
            loadModelTexture(*cmd++);
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
            loadModelTexture(*cmd++);
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
        if ((gpSprite[D_801A68D0[i]].statnum != 10) || (gpSprite[D_801A68D0[i]].unk16 != gPlayerNum))
        {
            if (D_801A68D0[i] != gPlayer[gPlayerNum].unk52)
            {
                func_8000F474(D_801A68D0[i],
                    ((D_8013B2D0[D_801A68D0[i]].unk0 * 180) / 1024.0),
                    ((D_8013B2D0[D_801A68D0[i]].unk2 * 180) / 1024.0),
                    ((((gpSprite[D_801A68D0[i]].ang +
                        D_8013B2D0[D_801A68D0[i]].unk4) * 180) / 1024.0) + 90.0));
            }
        }
    }

    if (gPlayer[gPlayerNum].third_person)
    {
        if (gPlayer[gPlayerNum].unk52 == -1)
            func_800A3688();
    }

    if ((gPlayer[gPlayerNum].unk52 != -1) ||
        (gPlayer[gPlayerNum].third_person && (gPlayer[gPlayerNum].unk6A >= 0xFF)))
    {
        func_8000F1E0();
        D_8013B2D0[gPlayer[gPlayerNum].unk4A].unk6 = 0;
        func_8000F474(gPlayer[gPlayerNum].unk4A,
            ((D_8013B2D0[gPlayer[gPlayerNum].unk4A].unk0 * 180) / 1024.0),
            ((D_8013B2D0[gPlayer[gPlayerNum].unk4A].unk2 * 180) / 1024.0),
            ((((gpSprite[gPlayer[gPlayerNum].unk4A].ang +
                D_8013B2D0[gPlayer[gPlayerNum].unk4A].unk4) * 180) / 1024.0) + 90.0));
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
        if ((gpSprite[spritenum].statnum != 10) || (gpSprite[spritenum].unk16 != gPlayerNum))
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
    if ((gPlayer[gPlayerNum].third_person) && (gPlayer[gPlayerNum].unk6A < 255) && (gPlayer[gPlayerNum].unk52 < 0))
    {
        func_8000F1E0();
        D_8013B2D0[gPlayer[gPlayerNum].unk4A].unk6 = 255 - gPlayer[gPlayerNum].unk6A;
        func_8000F474(gPlayer[gPlayerNum].unk4A,
                      ((D_8013B2D0[gPlayer[gPlayerNum].unk4A].unk0 * 180) / 1024.0),
                      ((D_8013B2D0[gPlayer[gPlayerNum].unk4A].unk2 * 180) / 1024.0),
                      ((((gpSprite[gPlayer[gPlayerNum].unk4A].ang + D_8013B2D0[gPlayer[gPlayerNum].unk4A].unk4) * 180) / 1024.0) + 90.0));
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
static void func_8001270C(_FDE0UnkStruct2 *arg0, s16 arg1)
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
    ptr = &D_80197E40[gActorSpriteMap[D_801AE8F4]];
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
                    f5 = (gActor[gActorSpriteMap[D_801AE8F4]].unk7C << 5);

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
                f1 = (gActor[gActorSpriteMap[D_801AE8F4]].unk7C << 5);
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
                f3 = (gActor[gActorSpriteMap[D_801AE8F4]].unk7C << 5);
        }

        if (arg0->unk0 == 7)
        {
            if (arg1 == 1)
                f3 = (gActor[gActorSpriteMap[D_801AE8F4]].unk7C << 5);
        }

        if (arg0->unk8[arg1].unk18 != -1)
        {
            fx -= arg0->unk8[arg0->unk8[arg1].unk18].unk0 * 50.0f;
            fy -= arg0->unk8[arg0->unk8[arg1].unk18].unk8 * 50.0f;
            fz -= arg0->unk8[arg0->unk8[arg1].unk18].unk4 * 50.0f;
        }
        cond = 0;
        if (gCheatBigHeadModeConfig != CONFIG_OFF)
        {
            if ((arg0->unk0 == 0) && (arg1 == 9))
                cond = 1;
            if ((arg0->unk0 == 9) && (arg1 == 15))
                cond = 1;
        }

        if (gCheatBigGunConfig != CONFIG_OFF)
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

        if (arg0->model_list[arg1] != NULL)
        {
            m = gActorSpriteMap[D_801AE8F4];
            if (!(gActor[m].unk68 & (1 << arg1)))
            {
                if ((gpSprite[D_801AE8F4].statnum == 10) && (gPlayerCount == 1))
                {
                    playernum = gpSprite[D_801AE8F4].unk16;
                    model1 = arg0->model_list[arg1];
                    model2 = NULL;
                    if (D_8012F6E4[gPlayer[playernum].skin].unkB == 0)
                    {
                        switch (arg1)
                        {
                        case 8:
                            if (gActor[m].unk7E > 0)
                            {
                                /*BulletproofBustModel*/
                                switch (gMapChapter[gMapNum].chapter)
                                {
                                default:
                                    model1 = &D_800C1E4C;
                                    break;
                                case WESTERN:
                                    model1 = &D_800C1F3C;
                                    break;
                                case VICTORIAN:
                                    model1 = &D_800C1EC4;
                                    break;
                                }
                            }
                            if (((gMapChapter[gMapNum].chapter < WESTERN) || (gMapChapter[gMapNum].chapter >= FINAL)) &&
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

                            if ((gMapChapter[gMapNum].chapter >= WESTERN) && (gMapChapter[gMapNum].chapter < FINAL))
                            {
                                if (D_8010A940[playernum].unk2[1] != 0)
                                    model1 = &D_800D0648;
                            }
                            break;
                        case 10:
                            if (gActor[m].unk7E > 0)
                            {
                                if ((gMapChapter[gMapNum].chapter < WESTERN) || (gMapChapter[gMapNum].chapter >= FINAL))
                                    model1 = &D_800C439C;
                            }
                            break;
                        case 13:
                            if (gActor[m].unk7E > 0)
                            {
                                if ((gMapChapter[gMapNum].chapter < WESTERN) || (gMapChapter[gMapNum].chapter >= FINAL))
                                    model1 = &D_800C43D8;
                            }
                            break;
                        }
                    }

                    if ((D_8012F6E4[gPlayer[playernum].skin].unkB == 3) && (arg1 == 1))
                    {
                        switch (gpSprite[D_801AE8F4].picnum)
                        {
                        case ENFORCER:
                            model1 = &D_800C5080;
                            break;
                        case ENFORCERCAPTAIN:
                            model1 = &D_800C50BC;
                            break;
                        case BATTLEENFORCER:
                            model1 = &D_800C50F8;
                            break;
                        }
                    }
                    drawModel(model1);
                    if (model2 != NULL)
                        drawModel(model2);
                }
                else
                {
                    model2 = arg0->model_list[arg1];
                    if ((arg1 == 1) && (gpSprite[D_801AE8F4].picnum >= ENFORCER) &&
                        (gpSprite[D_801AE8F4].picnum <= BATTLEENFORCER) && (func_8004EFB4(D_801AE8F4) != 0))
                    {
                        switch (gpSprite[D_801AE8F4].picnum)
                        {
                        case ENFORCER:
                            model2 = &D_800C5080;
                            break;
                        case ENFORCERCAPTAIN:
                            model2 = &D_800C50BC;
                            break;
                        case BATTLEENFORCER:
                            model2 = &D_800C50F8;
                            break;
                        }
                    }
                    drawModel(model2);
                }
            }
        }

        if ((arg0->unk0 == 0) && ((arg1 == 12) || (arg1 == 15)))
        {
            cond2 = gActor[gActorSpriteMap[D_801AE8F4]].flag;
            cond2 >>= 7;
            l = gActor[gActorSpriteMap[D_801AE8F4]].unk99;
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
                        drawModel(D_800D6784[l+1]);
                    else
                        drawModel(D_800D6784[l]);

                    if (D_80119A38 != 0)
                    {
                        if ((D_8010A9AC == 0) && ((playernum2 == -1) || (gPlayer[playernum2].unk54 == 0)))
                        {
                            if (D_800D689C[l] != NULL)
                            {
                                func_800124EC(D_800D6964[l]);
                                drawModel(D_800D689C[l]);
                                func_80012630();
                            }
                        }
                    }
                }
                if (arg1 == 15)
                {
                    drawModel(D_800D6784[l]);
                    if ((D_80119A38 != 0) && (D_8010A9AC == 0))
                    {
                        if (D_800D689C[l] != NULL)
                        {
                            func_800124EC(D_800D6964[l]);
                            drawModel(D_800D689C[l]);
                            func_80012630();
                        }
                    }
                }
            }
        }

        if ((arg0->unk0 == 6) && (arg1 == 1))
        {
            unk99 = gActor[gActorSpriteMap[D_801AE8F4]].unk99;
            if ((D_80119A38 != 0) && (D_8010A9AC == 0))
            {
                func_800124EC(D_800D6964[unk99]);
                switch (gpSprite[D_801AE8F4].picnum)
                {
                case CERBERUSTURRETS:
                    drawModel(&D_800CFD9C);
                    break;
                case GORGONTURRETS:
                    drawModel(&D_800D0198);
                    break;
                default:
                    drawModel(&D_800D06FC);
                    break;
                }
                func_80012630();
            }
        }

        if ((arg0->unk0 >= 2 && arg0->unk0 < 4) && (arg1 == 1))
        {
            func_800124EC(35);
            if (gActor[gActorSpriteMap[D_801AE8F4]].flag & 0x4000)
                n = 6;
            else
                n = 3;

            switch (random(-1) % n)
            {
            case 0:
                drawModel(&D_800D051C);
                break;
            case 1:
                drawModel(&D_800D0558);
                break;
            case 2:
                drawModel(&D_800D0594);
                break;
            }
            func_80012630();
        }

        if ((arg0->unk0 == 3) && (arg1 == 0))
        {
            unk99 = gActor[gActorSpriteMap[D_801AE8F4]].unk99;
            if ((D_80119A38 != 0) && (D_8010A9AC == 0))
            {
                func_800124EC(D_800D6964[unk99]);
                drawModel(&D_800D04E0);
                func_80012630();
            }
        }
        if ((arg0->unk0 == 2) && (arg1 == 2))
        {
            unk99 = gActor[gActorSpriteMap[D_801AE8F4]].unk99;
            if ((D_80119A38 != 0) && (D_8010A9AC == 0))
            {
                func_800124EC(D_800D6964[unk99]);
                drawModel(&D_800D04A4);
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
void func_80013FFC(_FDE0UnkStruct2 *arg0)
{
    if (gActorSpriteMap[D_801AE8F4] != -1)
        func_8001270C(arg0, 0);
}

/*80014040*/
_FDE0UnkStruct2 *func_80014040(s16 picnum)
{
    switch (picnum)
    {
    case DUKENUKEM:
        return &gDukeNukemActor;
    case COWBOYDUKE:
        return &gCowboyDukeActor;
    case VICTORIANDUKE:
        return &gVictorianDukeActor;
    case POSHDUKE:
        return &gPoshDukeActor;
    case APOCALYPSEDUKE:
        return &gApocalypseDukeActor;
    case BATTLEDRESSDUKE:
        return &gBattleDressDukeActor;
    case DOGTAGDUKE:
        return &gDogTagDukeActor;
    case EVILDUKE:
        return &gEvilDukeActor;
    case XTERMINATOR:
        return &gXterminatorActor;
    case MARINE:
        return &gMarineActor;
    case SERGEANT:
        return &gSergeantActor;
    case MARSHALL:
        return &gMarshallActor;
    case SHERIFF:
        return &gSheriffActor;
    case SQUAW:
        return &gSquawActor;
    case SURVIVOR:
        return &gSurvivorActor;
    case KIMBERLYSTROKES:
        return &gKimberlyStrokesActor;
    case CUSTER:
        return &gCusterActor;
    case RIPPER:
        return &gRipperActor;
    case PIGCOP:
        return &gPigCopActor;
    case PIGCOP1:
        return &gPigCop1Actor;
    case PIGCOP2:
        return &gPigCop2Actor;
    case PIGCOP3:
        return &gPigCop3Actor;
    case PIGCOP4:
        return &gPigCop4Actor;
    case COWBOYGRUNT:
        return &gCowboyGruntActor;
    case COWBOYGRUNT1:
        return &gCowboyGrunt1Actor;
    case COWBOYGRUNT2:
        return &gCowboyGrunt2Actor;
    case COWBOYGRUNT3:
        return &gCowboyGrunt3Actor;
    case COWBOYGRUNT4:
        return &gCowboyGrunt4Actor;
    case SAVAGEGRUNT:
        return &gSavageGruntActor;
    case SAVAGEGRUNT1:
        return &gSavageGrunt1Actor;
    case SAVAGEGRUNT2:
        return &gSavageGrunt2Actor;
    case SAVAGEGRUNT3:
        return &gSavageGrunt3Actor;
    case SAVAGEGRUNT4:
        return &gSavageGrunt4Actor;
    case CAPITALISTPIG:
        return &gCapitalistPigActor;
    case CAPITALISTPIG1:
        return &gCapitalistPig1Actor;
    case CAPITALISTPIG2:
        return &gCapitalistPig2Actor;
    case CAPITALISTPIG3:
        return &gCapitalistPig3Actor;
    case CAPITALISTPIG4:
        return &gCapitalistPig4Actor;
    case SOLDIERGRUNT:
        return &gSoldierGruntActor;
    case SOLDIERGRUNT1:
        return &gSoldierGrunt1Actor;
    case SOLDIERGRUNT2:
        return &gSoldierGrunt2Actor;
    case SOLDIERGRUNT3:
        return &gSoldierGrunt3Actor;
    case SOLDIERGRUNT4:
        return &gSoldierGrunt4Actor;
    case ROADHOG:
        return &gRoadHogActor;
    case ROADHOG1:
        return &gRoadHog1Actor;
    case ROADHOG2:
        return &gRoadHog2Actor;
    case ROADHOG3:
        return &gRoadHog3Actor;
    case ROADHOG4:
        return &gRoadHog4Actor;
    case RIOTPIG:
        return &gRiotPigActor;
    case RIOTPIG1:
        return &gRiotPig1Actor;
    case RIOTPIG2:
        return &gRiotPig2Actor;
    case RIOTPIG3:
        return &gRiotPig3Actor;
    case RIOTPIG4:
        return &gRiotPig4Actor;
    case WARPIG:
        return &gWarPigActor;
    case WARPIG1:
        return &gWarPig1Actor;
    case WARPIG2:
        return &gWarPig2Actor;
    case WARPIG3:
        return &gWarPig3Actor;
    case WARPIG4:
        return &gWarPig4Actor;
    case ENFORCER:
        return &gEnforcerActor;
    case ENFORCER1:
        return &gEnforcer1Actor;
    case ENFORCER2:
        return &gEnforcer2Actor;
    case ENFORCER3:
        return &gEnforcer3Actor;
    case ENFORCER4:
        return &gEnforcer4Actor;
    case ENFORCERCAPTAIN:
        return &gEnforcerCaptainActor;
    case ENFORCERCAPTAIN1:
        return &gEnforcerCaptain1Actor;
    case ENFORCERCAPTAIN2:
        return &gEnforcerCaptain2Actor;
    case ENFORCERCAPTAIN3:
        return &gEnforcerCaptain3Actor;
    case ENFORCERCAPTAIN4:
        return &gEnforcerCaptain4Actor;
    case 2468:
    case BATTLEENFORCER:
        return &gBattleEnforcerActor;
    case BATTLEENFORCER1:
        return &gBattleEnforcer1Actor;
    case BATTLEENFORCER2:
        return &gBattleEnforcer2Actor;
    case BATTLEENFORCER3:
        return &gBattleEnforcer3Actor;
    case BATTLEENFORCER4:
        return &gBattleEnforcer4Actor;
    case CYBORGENFORCER:
        return &gCyborgEnforcerActor;
    case PARAPSYCHE:
        return &gParapsycheActor;
    case BROODLING:
        return &gBroodlingActor;
    case SENTRYGUNS1:
        return &gSentryGuns1Actor;
    case SENTRYGUNS2:
        return &gSentryGuns2Actor;
    case TANK:
        return &gTankActor;
    case HELICOPTER:
        return &gHelicopterActor;
    case ZOMBIE1:
    case 1305:
        return &gZombie1Actor;
    case ZOMBIE2:
        return &gZombie2Actor;
    case ZOMBIE3:
        return &gZombie3Actor;
    case ZOMBIE4:
        return &gZombie4Actor;
    case ZOMBIE5:
        return &gZombie5Actor;
    case ZOMBIE6:
        return &gZombie6Actor;
    case ZOMBIE7:
        return &gZombie7Actor;
    case CHIMERA:
        return &gChimeraActor;
    case BOSSGIANTHOG:
        return &gBossGiantHogActor;
    case CERBERUSTURRETS:
        return &gCerberusTurretsActor;
    case GORGONTURRETS:
        return &gGorgonTurretsActor;
    case BROODMOTHER:
        return &gBroodMotherActor;
    case SHIP1:
        return &gShip1Actor;
    case SHIP2:
        return &gShip2Actor;
    case BOSSCYBORGSCORPION:
        return &gBossCyborgScorpionActor;
    case BOSSZERO:
        return &gBossZeroActor;
    case BOSSBRAINSTORM:
        return &gBossBrainstormActor;
    }
    return NULL;
}

/*80014C24*/
static void func_80014C24(void)
{
    D_801ACC60 = 0;
}

/*80014C34*/
static void _copyMatrix(Matrix4f dst, Matrix4f src)
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
static void func_80014D6C(_FDE0UnkStruct2 *arg0, s16 arg1)
{
    Matrix4f mf1, mf2, mf3, mf4, mf5;
    code0unkStruct8 *ptr;
    f32 f1, f2, f3;
    f32 f4, f5, f6;
    f32 f7;
    s16 i, j, k;

    ptr = &D_80197E40[gActorSpriteMap[D_801AE8F4]];

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
            _copyMatrix(D_80199578, D_801B0830[D_801ACC60]);
        if (arg1 == 13)
            _copyMatrix(D_800FF3A0, D_801B0830[D_801ACC60]);
        if (arg1 == 4)
            _copyMatrix(D_801AE9D0, D_801B0830[D_801ACC60]);
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
static void func_80015458(_FDE0UnkStruct2 *arg0, s16 arg1)
{
    Matrix4f mf2, mf1, mf3, mf4, mf5;
    code0unkStruct8 *ptr;

    f32 fx, fy, fz;
    f32 f1, f2, f3, f4, f5, f6, f7;
    f32 ftemp;

    s32 unk54;

    s16 i, j, k;

    ptr = &D_80197E40[gActorSpriteMap[D_801AE8F4]];

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
        _copyMatrix(D_801AFDE0, D_801B0830[D_801ACC60]);

    for (i = 0; i < arg0->unk2; i++)
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
    if (gActorSpriteMap[D_801AE8F4] != -1)
    {
        ptr = &D_8013B2D0[spritenum];
        spr = &gpSprite[spritenum];
        f1 = (ptr->unk2 * 180) / 1024.0;
        f2 = (ptr->unk0 * 180) / 1024.0;
        f3 = (((spr->ang + ptr->unk4) * 180) / 1024.0) + 90.0;
        if (spr->picnum == BOSSGIANTHOG)
        {
            func_80014C7C(-f1, -f2, f3, ((f32)spr->xrepeat / 64.0));
            func_80014D6C(&gBossGiantHogActor, 0);

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
