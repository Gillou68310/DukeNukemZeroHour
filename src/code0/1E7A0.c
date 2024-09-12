#include "common.h"
#include "code0/main.h"
#include "code0/audio.h"
#include "code0/engine.h"
#include "code0/9410.h"
#include "code0/24610.h"
#include "code0/41940.h"
#include "code0/1E7A0.h"
#include "code0/code0.h"
#include "code1/code1.h"
#include "code1/EB300.h"

/*.data*/
/*800DCA20*/ static u8 D_800DCA20[16] = {90, 130, 160, 190, 200, 205, 210, 212, 210, 205, 200, 190, 160, 130, 90, 0};

/*800DCA30*/
_1E7A0UnkStruct1 D_800DCA30[8] = {
    { 0, 4 },
    { 22, 22 },
    { 11, 11 },
    { 11, 31 },
    { 26, 26 },
    { 27, 27 },
    { 7, 7 },
    { 37, 37 },
};

/*800DCA40*/
_1E7A0UnkStruct2 D_800DCA40[13] = {
    { 34, 2.0f, 0.01f, 34, 10, 1 },
    { 34, 4.0f, 0.06f, 40, 8, 1 },
    { 44, 6.0f, 0.06f, 40, 8, 1 },
    { 50, 3.0f, 0.06f, 24, 5, 1 },
    { 50, 5.0f, 0.16f, 22, 6, 1 },
    { 40, 8.5f, 0.16f, 17, 7, 1 },
    { 21, 1.5f, 0.02f, 37, 2, 1 },
    { 21, 2.5f, 0.02f, 68, 6, 1 },
    { 61, 3.5f, 0.02f, 38, 11, 1 },
    { 40, 10.0f, 0.1f, 25, 10, 0 },
    { 30, 8.0f, 0.2f, 25, 10, 0 },
    { 40, 8.0f, 0.1f, 35, 10, 0 },
    { 0, 0.0f, 0.0f, 0, 0, 0 },
};

/*.text*/

void func_8001DBA0(s16 x, s16 y, s16 z, u8 arg3, u8 arg4, s32 arg5)
{
    code0UnkStruct13 *ptr;
    s16 i;

    if ((krand() & 0x7FFF) >= 9000)
    {
        for (i = 0, ptr = D_801AE538; i < ARRAY_COUNT(D_801AE538); i++, ptr++)
        {
            if (ptr->unk0 == 0)
            {
                ptr->unk0 = 1;
                ptr->unk1 = arg5;
                ptr->unk2 = x;
                ptr->unk4 = y;
                ptr->unk6 = z;
                ptr->unk10 = D_800DCA40[arg5].unk0;
                ptr->unk14 = D_800DCA40[arg5].unk4;
                ptr->unkA = krand();
                ptr->unk18 = arg3;
                ptr->unk19 = arg4;
                ptr->unk8 = krand() % 4 + 5542;
                break;
            }
        }
    }
}

/*8001DCD0*/
void func_8001DCD0(s16 x, s16 y, s16 z, s16 arg3)
{
    func_8001DBA0(x, y, z, D_800DCA30[arg3].unk0, D_800DCA30[arg3].unk1, 9);
}

/*8001DD30*/
void func_8001DD30(s16 x, s16 y, s16 z)
{
    func_8001DBA0(x, y, z, 11, 11, 1);
}

/*8001DD78*/
void func_8001DD78(s32 x, s32 y, s32 z)
{
    code0UnkStruct14 *ptr;
    s16 i;

    for (ptr = D_8012DF10, i = 0; i < ARRAY_COUNT(D_8012DF10); i++, ptr++)
    {
        if (ptr->unk0 == 0)
        {
            ptr->unk0 = 1;
            ptr->unk4 = x;
            ptr->unk8 = y;
            ptr->unkC = z;
            ptr->unk10 = (krand() & 0x7F) - 64;
            ptr->unk14 = (krand() & 0x7F) - 64;
            ptr->unk18 = (krand() & 0x7F) - 64;
            ptr->unk1E = 100;
            ptr->unk20 = krand() & 0x7FF;
            ptr->unk22 = (krand() & 0xF) - 7;
            krand();
            ptr->unk1C = 5949;
            ptr->unk1F = 0;
            break;
        }
    }
}

/*8001DE5C*/
void func_8001DE5C(void)
{
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_801AE538); i++)
        D_801AE538[i].unk0 = 0;
    for (i = 0; i < ARRAY_COUNT(D_8012DF10); i++)
        D_8012DF10[i].unk0 = 0;
}

/*8001DE9C*/
void func_8001DE9C(void)
{
    code0UnkStruct14 *ptr;
    f32 fx, fy, fz;
    f32 f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13;
    s32 a, b, c, d, e, f, g, h, j, k;
    s32 x, y, z;
    s16 i;
    s32 tileid;
    u16 sizex, sizey;
    s32 dimy, dimx, dimx1, dimy1;

    gSPClearGeometryMode(gpDisplayList++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING |G_TEXTURE_GEN |
                                          G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);

    gSPSetGeometryMode(gpDisplayList++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH);
    gDPSetRenderMode(gpDisplayList++, G_RM_ZB_CLD_SURF, G_RM_ZB_CLD_SURF2);
    gDPSetTextureLUT(gpDisplayList++, G_TT_NONE);

    gDPSetCombineLERP(gpDisplayList++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                                       0, 0, 0, COMBINED, 0, 0, 0, COMBINED);

    gDPSetColorDither(gpDisplayList++, G_CD_DISABLE);
    gDPSetAlphaDither(gpDisplayList++, G_AD_DISABLE);
    gDPSetDepthSource(gpDisplayList++, G_ZS_PRIM);

    for (ptr = D_8012DF10, i = 0; i < ARRAY_COUNT(D_8012DF10); i++, ptr++)
    {
        if (ptr->unk0 != 0)
        {
            tileid = getTileId(ptr->unk1C);

            fx = ptr->unk4 / 4.0;
            fy = ptr->unk8 / 4.0;
            fz = ptr->unkC / 64.0;

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
                    f12 = ((f7 * 511.0f) + 511.0f) * 32.0f;

                    gDPSetPrimDepth(gpDisplayList++, f12, 0);
                    f7 = (-f7 + 1.0f);
                    initVertexList();
                    f13 = f7 * 16.0f;
                    func_8000BDB0(ptr->unk1C);

                    dimy = gpTileInfo[tileid].dimy;
                    dimy1 = 0;
                    dimx = gpTileInfo[tileid].dimx;
                    dimx1 = 0;

                    sizex = (f13 *  (gpTileInfo[tileid].sizex * ptr->unk1E)) / 16.0f;
                    sizey = (f13 * (gpTileInfo[tileid].sizey * ptr->unk1E)) / 16.0f;

                    k = (ptr->unk20 << 5) & 0xFFE0;
                    f8 = sins(k) / 32768.0;
                    j = (ptr->unk20 << 5) & 0xFFE0;
                    f9 = coss(j) / 32768.0;

                    f10 = (f5 * 4.0f * D_80199110) + (D_80168C9C * 4.0f);
                    f11 = (-f6 * 4.0f * D_801A1980) + (D_801A2684 * 4.0f);

                    a = ((sizex * f9) + (sizey * f8));
                    e = ((-sizey * f9) + (sizex * f8));
                    b = ((-sizex * f9) + (sizey * f8));
                    f = ((-sizey * f9) + (-sizex * f8));
                    c = ((-sizex * f9) + (-sizey * f8));
                    g = ((sizey * f9) + (-sizex * f8));
                    d = ((sizex * f9) + (-sizey * f8));
                    h = ((sizey * f9) + (sizex * f8));

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

                    if (ptr->unk1F >= 8)
                    {
                        gDPSetPrimColor(gpDisplayList++, 0, 0, 0xFF, D_800DCA20[ptr->unk1F], 0, ~((ptr->unk1F - 8) * 42));
                    }
                    else
                    {
                        gDPSetPrimColor(gpDisplayList++, 0, 0, 0xFF, D_800DCA20[ptr->unk1F], 0, 0xFF);
                    }

                    gDPSetEnvColor(gpDisplayList++, D_800DCA20[ptr->unk1F], 0, 0, 0);

                    gSP2Triangles(gpDisplayList++, gVertexBufferIndex, gVertexBufferIndex+1, gVertexBufferIndex+2, gVertexBufferIndex,
                                                   gVertexBufferIndex, gVertexBufferIndex+2, gVertexBufferIndex+3, gVertexBufferIndex);

                    gVertexBufferIndex += 4;
                    gVertexNumber -= 4;
                    x = ptr->unk4 / 2;
                    y = ptr->unk8 / 2;
                    z = ptr->unkC / 32;

                    gpVertexN64->v.ob[0] = x;
                    gpVertexN64->v.ob[1] = y;
                    gpVertexN64->v.ob[2] = z;
                    gpVertexN64->v.tc[0] = dimx << 5;
                    gpVertexN64->v.tc[1] = dimy1 << 5;
                    gpVertexN64++;

                    gpVertexN64->v.ob[0] = x;
                    gpVertexN64->v.ob[1] = y;
                    gpVertexN64->v.ob[2] = z;
                    gpVertexN64->v.tc[0] = dimx1 << 5;
                    gpVertexN64->v.tc[1] = dimy1 << 5;
                    gpVertexN64++;

                    gpVertexN64->v.ob[0] = x;
                    gpVertexN64->v.ob[1] = y;
                    gpVertexN64->v.ob[2] = z;
                    gpVertexN64->v.tc[0] = dimx1 << 5;
                    gpVertexN64->v.tc[1] = dimy << 5;
                    gpVertexN64++;

                    gpVertexN64->v.ob[0] = x;
                    gpVertexN64->v.ob[1] = y;
                    gpVertexN64->v.ob[2] = z;
                    gpVertexN64->v.tc[0] = dimx << 5;
                    gpVertexN64->v.tc[1] = dimy << 5;
                    gpVertexN64++;
                }
            }
        }
    }
    gDPSetDepthSource(gpDisplayList++, G_ZS_PIXEL);
}

/*8001EB2C*/
void func_8001EB2C(void)
{
    f32 fx, fy, fz;
    f32 f1, f2, f3, f4, f5, f6, f7;
    f32 fx_, fy_, fz_;
    s16 primr, primg, primb;
    s16 envr, envg, envb;
    s32 a, prima, enva;
    s16 i, j;

    D_801A2688 = 0;
    gSPClearGeometryMode(gpDisplayList++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                                          G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);

    gSPSetGeometryMode(gpDisplayList++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH);
    gDPSetRenderMode(gpDisplayList++, G_RM_ZB_CLD_SURF, G_RM_ZB_CLD_SURF2);
    gDPSetDepthSource(gpDisplayList++, G_ZS_PRIM);
    gDPSetTexturePersp(gpDisplayList++, G_TP_NONE);

    func_80028F04(0xFF, 0xFF, 0xFF, 0, 0, 0);

    gDPSetCombineLERP(gpDisplayList++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                                       0, 0, 0, COMBINED, 0, 0, 0, COMBINED);

    gDPSetColorDither(gpDisplayList++, G_CD_NOISE);
    gDPSetAlphaDither(gpDisplayList++, G_AD_NOISE);

    for (i = 0; i < ARRAY_COUNT(D_801AE538); i++)
    {
        if (D_801AE538[i].unk0 != 0)
        {
            fx = D_801AE538[i].unk2 / 2;
            fy = D_801AE538[i].unk4 / 2;
            fz = D_801AE538[i].unk6 / 2;

            f1 = ((D_8012B948[0][0] * fx) + (D_8012B948[1][0] * fy) + (D_8012B948[2][0] * fz) + D_8012B948[3][0]);
            f2 = ((D_8012B948[0][1] * fx) + (D_8012B948[1][1] * fy) + (D_8012B948[2][1] * fz) + D_8012B948[3][1]);
            f3 = ((D_8012B948[0][2] * fx) + (D_8012B948[1][2] * fy) + (D_8012B948[2][2] * fz) + D_8012B948[3][2]);
            f4 = ((D_8012B948[0][3] * fx) + (D_8012B948[1][3] * fy) + (D_8012B948[2][3] * fz) + D_8012B948[3][3]);

            if (f4 != 0.0f)
            {
                fx_ = f1 / f4;
                fy_ = f2 / f4;
                fz_ = f3 / f4;

                if (!(fx_ < -2.0f) && !(fy_ < -2.0f) && !(fx_ > 2.0f) && !(fy_ > 2.0f) && !(fz_ < 0.0f) && !(fz_ > 1.0f))
                {
                    f7 = ((fz_ * 511.0f) + 511.0f) * 32.0f;
                    gDPSetPrimDepth(gpDisplayList++, f7, 0);
                    enva = (D_801AE538[i].unk14 * D_800DCA40[D_801AE538[i].unk1].unkC);
                    a = (enva - 0x80) * 2;
                    j = CLAMP_MIN(a, 0);
                    fz_ = (-fz_ + 1.0f);

                    primr = gpAlphaPalette[D_801AE538[i].unk19].primary.r +
                        ((gpAlphaPalette[D_801AE538[i].unk18].primary.r - gpAlphaPalette[D_801AE538[i].unk19].primary.r) * j) / 256;
                    primg = gpAlphaPalette[D_801AE538[i].unk19].primary.g +
                        ((gpAlphaPalette[D_801AE538[i].unk18].primary.g - gpAlphaPalette[D_801AE538[i].unk19].primary.g) * j) / 256;
                    primb = gpAlphaPalette[D_801AE538[i].unk19].primary.b +
                        ((gpAlphaPalette[D_801AE538[i].unk18].primary.b - gpAlphaPalette[D_801AE538[i].unk19].primary.b) * j) / 256;
                    envr = gpAlphaPalette[D_801AE538[i].unk19].env.r +
                        ((gpAlphaPalette[D_801AE538[i].unk18].env.r - gpAlphaPalette[D_801AE538[i].unk19].env.r) * j) / 256;
                    envg = gpAlphaPalette[D_801AE538[i].unk19].env.g +
                        ((gpAlphaPalette[D_801AE538[i].unk18].env.g - gpAlphaPalette[D_801AE538[i].unk19].env.g) * j) / 256;
                    envb = gpAlphaPalette[D_801AE538[i].unk19].env.b +
                        ((gpAlphaPalette[D_801AE538[i].unk18].env.b - gpAlphaPalette[D_801AE538[i].unk19].env.b) * j) / 256;

                    if (gGraphicsOption == CONFIG_GRAPHICS_HIGHRES)
                    {
                        prima = (enva * 0x180) / 256;
                        if (prima > 0xFF)
                            prima = 0xFF;
                    }
                    else
                        prima = enva;

                    gDPSetPrimColor(gpDisplayList++, 0, 0, primr, primg, primb, prima);
                    gDPSetEnvColor(gpDisplayList++, envr, envg, envb, enva);

                    f5 = (fz_ * D_801AE538[i].unk10 * 4.0f * gPlayer[D_801B0820].unk6E * D_80199110) / 40960.0;
                    f6 = (fz_ * D_801AE538[i].unk10 * 4.0f * gPlayer[D_801B0820].unk6E * D_801A1980) / 30720.0;
                    func_80027C18((fx_ * D_80199110) + D_80168C9C,
                                  (-fy_ * D_801A1980) + D_801A2684,
                                  f5,
                                  f6,
                                  getTileId(D_801AE538[i].unk8),
                                  D_801AE538[i].unkA);
                }
            }
        }
    }
    func_8000A070();
    gDPSetDepthSource(gpDisplayList++, G_ZS_PIXEL);
}

/*8001F388*/
void func_8001F388(void)
{
    code0UnkStruct14 *ptr;
    s16 i;

    for (ptr = D_8012DF10, i = 0; i < ARRAY_COUNT(D_8012DF10); i++, ptr++)
    {
        if (ptr->unk0 != 0)
        {
            ptr->unk4 += ptr->unk10;
            ptr->unk8 += ptr->unk14;
            ptr->unkC += ptr->unk18;
            ptr->unk20 += ptr->unk22;
            ptr->unk20 &= 0x7FF;

            if (ptr->unk1E < 119)
                ptr->unk1E += 8;
            else
                ptr->unk1E = 127;

            ptr->unk1F++;
            if (ptr->unk1F == 0xF)
                ptr->unk0 = 0;
        }
    }
}

/*8001F44C*/
void func_8001F44C(void)
{
    s16 i, j, k, playernum, ang;
    f32 f1, f2;

    if (gGraphicsOption == CONFIG_GRAPHICS_HIGHRES)
        k = 2;
    else
        k = 1;

    for (i = 0; i < ARRAY_COUNT(D_801AE538); i++)
    {
        for (j = 0; j < k; j++)
        {
            if (D_801AE538[i].unk0 != 0)
            {
                D_801AE538[i].unk10 += D_801AE538[i].unk14;
                D_801AE538[i].unk14 -= D_800DCA40[D_801AE538[i].unk1].unk8;

                if (D_800DCA40[D_801AE538[i].unk1].unkF != 0)
                    D_801AE538[i].unk6 -= (D_801AE538[i].unk14 * (D_800DCA40[D_801AE538[i].unk1].unkC / 6));

                if (D_801AE538[i].unk14 <= 0.0f)
                    D_801AE538[i].unk0 = 0;

                playernum = audio_80007510(D_801AE538[i].unk2 * 2, D_801AE538[i].unk4 * 2);
                if (D_8013871C > 0x100)
                {
                    ang = getAngle(gPlayer[playernum].xpos - (D_801AE538[i].unk2 * 2), gPlayer[playernum].ypos - (D_801AE538[i].unk4 * 2));
                    f1 = D_801AE538[i].unk2;
                    D_801AE538[i].unk2 = f1 + (cosf(ang * (PI/1024)) * 8.0f);
                    f2 = D_801AE538[i].unk4;
                    D_801AE538[i].unk4 = f2 + (sinf(ang * (PI/1024)) * 8.0f);
                }
            }
        }
    }
}

/*8001F7B4*/
void func_8001F7B4(s32 arg0, s32 arg1)
{
    s16 playernum;

    D_800DEE88 = arg0;
    D_800DEE8C = arg1;

    for (playernum = 0; playernum < D_8012C470; playernum++)
    {
        if (gPlayer[playernum].unk45 == 0)
            func_801C363C(playernum, arg0, CLAMP_MAX(arg1*16, 255));
    }
}
