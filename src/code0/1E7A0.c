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
/*800DCA30*/ EXTERN_DATA _1E7A0UnkStruct1 D_800DCA30[8];
/*800DCA40*/ EXTERN_DATA _1E7A0UnkStruct2 D_800DCA40[13];

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
INCLUDE_ASM("nonmatchings/src/code0/1E7A0", func_8001DE9C);

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

    for (i = 0; i < 32; i++)
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

                    if (D_801CE5AC == 2)
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
                                  getTileNum(D_801AE538[i].unk8),
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

    if (D_801CE5AC == 2)
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
                if (D_8013871C >= 0x101)
                {
                    ang = getAngle(gPlayer[playernum].xpos - (D_801AE538[i].unk2 * 2), gPlayer[playernum].ypos - (D_801AE538[i].unk4 * 2));
                    f1 = D_801AE538[i].unk2;
                    D_801AE538[i].unk2 = f1 + (cosf(ang * 0.00306796157577148444) * 8.0f);
                    f2 = D_801AE538[i].unk4;
                    D_801AE538[i].unk4 = f2 + (sinf(ang * 0.00306796157577148444) * 8.0f);
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
