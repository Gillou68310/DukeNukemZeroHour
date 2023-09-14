#include "common.h"
#include "code0/main.h"
#include "code0/pragmas.h"
#include "code0/9410.h"
#include "code0/16FF0.h"
#include "code0/17B30.h"
#include "code0/24610.h"
#include "code0/41940.h"
#include "code0/graphics.h"
#include "code0/A06F0.h"
#include "code0/code0.h"

typedef struct {
    Color unk0;
    Color unk1;
} _FDE0UnkStruct1;

/*TODO: include math.h from libkmc*/
double sqrt(double);

/*.data*/
/*800BD760*/ EXTERN_DATA STATIC Lights2 _light2;
/*800BD788*/ EXTERN_DATA s32 D_800BD788;

/*.comm*/
/*800FE414*/ u8 D_800FE414;
/*800FF3A0*/ Matrix4f D_800FF3A0 ALIGNED(8);
/*80106D3C*/ f32 D_80106D3C;
/*8012EB48*/ f32 D_8012EB48;
/*8012FD87*/ u8 D_8012FD87; /*alpha*/
/*80197DF0*/ Matrix4f D_80197DF0 ALIGNED(8);
/*80199578*/ Matrix4f D_80199578 ALIGNED(8);
/*801AE9D0*/ Matrix4f D_801AE9D0 ALIGNED(8);
/*801AFDE0*/ Matrix4f D_801AFDE0 ALIGNED(8);

/*.text*/
STATIC void func_8000F474(s16, f32, f32, f32);
static f32 func_80011410(ModelInfo *model);
static void func_800117A4(u8 *, code0UnkStruct18 *, _FDE0UnkStruct1 *);
STATIC void func_8001270C(code0unkStruct10 *, s32);

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
INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_8000F474);

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
    grMtxL2F(mtx, &gpDynamic->mtx3[D_801A6D80]);
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
    u8 *ramaddr1;
    code0UnkStruct18 *ramaddr2;
    _FDE0UnkStruct1 *ramaddr3;
    ModelInfoUnkStruct1 *ptr;

    loadModel(model);
    ramaddr1 = model->ramaddr + model->unkE;
    ptr = model->unk18;
    ramaddr2 = (code0UnkStruct18 *)ptr->ramaddr;
    ramaddr3 = (_FDE0UnkStruct1 *)(model->ramaddr + model->unk10);
    gpModelTile = model->ramaddr;
    gpModelTileInfo = (ModelTileInfo *)(model->ramaddr + model->tileinfo);

    if ((D_800BD788 == 0) || (func_800115E0(model) != 0))
        func_800117A4(ramaddr1, ramaddr2, ramaddr3);
}

/*800117A4*/
static void func_800117A4(u8 *arg0, code0UnkStruct18 *arg1, _FDE0UnkStruct1 *arg2)
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
        m = *arg0++;
        switch (m)
        {
        case 13:
            l = *arg0++;
            u = *arg0++;
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
            n = *arg0++;
            o = *arg0++;

            gSPVertex(gpDisplayList++, D_80199114, o, n);
            D_80199114 = &D_80199114[o];

            for (i = 0; i < o; i++)
            {
                t = *arg0++;
                tc0_ = *arg0++;
                tc1_ = *arg0++;
                gpVertexN64->v.ob[0] = arg1[t].unk0;
                gpVertexN64->v.ob[1] = arg1[t].unk2;
                gpVertexN64->v.ob[2] = arg1[t].unk4;
                gpVertexN64->v.tc[0] = tc0_ << 6;
                gpVertexN64->v.tc[1] = tc1_ << 6;
                gpVertexN64->v.cn[0] = arg2[t].unk0.r;
                gpVertexN64->v.cn[1] = arg2[t].unk0.g;
                gpVertexN64->v.cn[2] = arg2[t].unk0.b;
                gpVertexN64++;
            }
            break;
        case 1:
            n = *arg0++;
            o = *arg0++;

            gSPVertex(gpDisplayList++, D_80199114, o, n);
            D_80199114 = &D_80199114[o];

            for (i = 0; i < o; i++)
            {
                t = *arg0++;
                p = *arg0++;
                s = (t << 8) | p;
                tc0 = *arg0++;
                tc1 = *arg0++;
                gpVertexN64->v.ob[0] = arg1[s].unk0;
                gpVertexN64->v.ob[1] = arg1[s].unk2;
                gpVertexN64->v.ob[2] = arg1[s].unk4;
                gpVertexN64->v.tc[0] = tc0 << 6;
                gpVertexN64->v.tc[1] = tc1 << 6;
                gpVertexN64->v.cn[0] = arg2[s].unk0.r;
                gpVertexN64->v.cn[1] = arg2[s].unk0.g;
                gpVertexN64->v.cn[2] = arg2[s].unk0.b;
                gpVertexN64++;
            }
            break;
        case 2:
        case 3:
            func_800163F0(*arg0++);
            break;
        case 4:
            func_8001660C(*arg0++);
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
                                                           gpAlphaPalette[D_80168810].primary.b, D_8012FD87);
                }
                else
                {
                    gDPSetCombineMode(gpDisplayList++, G_CC_MODULATEIDECALA, G_CC_PASS2);
                }
                cond = 1;
            }
            break;
        case 5:
            func_8001660C(*arg0++);
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
            j = *arg0++;
            k = *arg0++;
            l = *arg0++;
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
                                               D_8012FD87);

        gDPSetEnvColor(gpDisplayList++, gpAlphaPalette[arg0].env.r,
                                        gpAlphaPalette[arg0].env.g,
                                        gpAlphaPalette[arg0].env.b,
                                        D_8012FD87);
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
INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_8001270C);

/*80013FFC*/
void func_80013FFC(code0unkStruct10 *arg0)
{
    if (D_80106D50[D_801AE8F4] != -1)
        func_8001270C(arg0, 0);
}

/*80014040*/
code0unkStruct10 *func_80014040(s16 arg0)
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
static void func_80014D6C(code0unkStruct10 *arg0, s16 arg1)
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
static void func_80015458(code0unkStruct10 *arg0, s16 arg1)
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
