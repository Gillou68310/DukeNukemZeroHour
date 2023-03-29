#include "common.h"
#include "code0/main.h"
#include "code0/9410.h"
#include "code0/16FF0.h"
#include "code0/17B30.h"
#include "code0/graphics.h"
#include "code0/code0.h"

/*.data*/
/*800BD760*/ EXTERN_DATA STATIC Lights2 _light2;
/*800BD788*/ EXTERN_DATA s32 D_800BD788;

/*.comm*/
/*800FE414*/ u8 D_800FE414;
/*8012FD87*/ u8 D_8012FD87; /*alpha*/
/*80197DF0*/ Matrix4f D_80197DF0 ALIGNED(8);

/*.text*/
STATIC void func_8000F474(s16, f32, f32, f32);
STATIC f32 func_80011410(ModelInfo *model);
STATIC s32 func_800117A4(u8 *, u8 *, u8 *);
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
    gSPClearGeometryMode(gpDisplayList++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH);
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

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_8000F474);

/*80011148*/
static f32 func_80011148(Vec4f vec1, Vec4f vec2)
{
    return (vec1[0] * vec2[0]) + (vec1[1] * vec2[1]) + (vec1[2] * vec2[2]) + vec1[3];
}

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_80011180);

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_80011410);

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
    u8 *ramaddr2;
    u8 *ramaddr3;
    ModelInfoUnkStruct1 *ptr;

    loadModel(model);
    ramaddr1 = model->ramaddr + model->unkE;
    ptr = model->unk18;
    ramaddr2 = ptr->ramaddr;
    ramaddr3 = model->ramaddr + model->unk10;
    D_800FE944 = model->ramaddr;
    D_80138714 = (code0unkStruct11 *)(model->ramaddr + model->unkC);

    if ((D_800BD788 == 0) || (func_800115E0(model) != 0))
        func_800117A4(ramaddr1, ramaddr2, ramaddr3);
}

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_800117A4);

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_80011DA8);

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
    if (D_80117ED8[D_801B0820].unk60 && D_80117ED8[D_801B0820].unk6A < 255 && D_80117ED8[D_801B0820].unk52 < 0)
    {
        func_8000F1E0();
        D_8013B2D0[D_80117ED8[D_801B0820].unk4A].unk6 = 255 - D_80117ED8[D_801B0820].unk6A;
        func_8000F474(D_80117ED8[D_801B0820].unk4A,
                     ((D_8013B2D0[D_80117ED8[D_801B0820].unk4A].unk0 * 180) / 1024.0),
                     ((D_8013B2D0[D_80117ED8[D_801B0820].unk4A].unk2 * 180) / 1024.0),
                     ((((gpSprite[D_80117ED8[D_801B0820].unk4A].ang + D_8013B2D0[D_80117ED8[D_801B0820].unk4A].unk4) * 180) / 1024.0) + 90.0));
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
        gDPSetCombineLERP(gpDisplayList++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
        gDPSetRenderMode(gpDisplayList++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_SURF2);
        gDPSetPrimColor(gpDisplayList++, 0, 0, D_80168D04[arg0].primary.r, D_80168D04[arg0].primary.g, D_80168D04[arg0].primary.b, D_8012FD87);
        gDPSetEnvColor(gpDisplayList++, D_80168D04[arg0].env.r, D_80168D04[arg0].env.g, D_80168D04[arg0].env.b, D_8012FD87);
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
            gDPSetCombineLERP(gpDisplayList++, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
        }
    }
}

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

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_80014D6C);

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

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_80015458);

INCLUDE_ASM("nonmatchings/src/code0/FDE0", func_80015DE0);
