#include "common.h"
#include "code0/7F6A0.h"
#include "code0/82480.h"
#include "code0/code0.h"

/*.data*/
/*800E0F20*/ EXTERN_DATA STATIC s32 D_800E0F20;
/*800E0F24*/ EXTERN_DATA STATIC s32 D_800E0F24;
/*800E0F28*/ EXTERN_DATA STATIC s32 D_800E0F28;
/*800E0F2C*/ EXTERN_DATA STATIC f32 D_800E0F2C;
/*800E0F30*/ EXTERN_DATA STATIC f32 D_800E0F30;
/*800E0F34*/ EXTERN_DATA STATIC f32 D_800E0F34;
/*800E0F38*/ EXTERN_DATA STATIC f32 D_800E0F38;
/*800E0F3C*/ EXTERN_DATA STATIC f32 D_800E0F3C;
/*800E0F40*/ EXTERN_DATA STATIC f32 D_800E0F40;
/*800E0F44*/ EXTERN_DATA STATIC s32 D_800E0F44;
/*800E0F48*/ EXTERN_DATA STATIC s32 D_800E0F48;
/*800E0F4C*/ EXTERN_DATA STATIC s32 D_800E0F4C;
/*800E0F50*/ EXTERN_DATA STATIC s32 D_800E0F50;
/*800E0F54*/ EXTERN_DATA STATIC s32 D_800E0F54;
/*800E0F58*/ EXTERN_DATA s32 D_800E0F58;
/*800E0F5C*/ EXTERN_DATA STATIC u8 D_800E0F5C;

/*.comm*/
/*800FCBE4*/ s32 D_800FCBE4;
/*8011815C*/ s32 D_8011815C;
/*80119A6C*/ code0UnkStruct18 *D_80119A6C;
/*80119AA0*/ s32 D_80119AA0;
/*80129800*/ s32 D_80129800;
/*8012B940*/ s32 D_8012B940;
/*8012EB50*/ s32 D_8012EB50[32][7] ALIGNED(8);
/*8012F6EC*/ s32 D_8012F6EC;
/*8012F6F8*/ Gfx *D_8012F6F8;
/*801385F8*/ Gfx *D_801385F8;
/*80138810*/ s32 D_80138810;
/*8013F924*/ Vtx *D_8013F924;
/*8016A170*/ code0UnkStruct18 D_8016A170[2048] ALIGNED(16);
/*80197DD0*/ s32 D_80197DD0;
/*80199108*/ u8 D_80199108;
/*80199968*/ s32 D_80199968;
/*801A6AD0*/ Vtx *D_801A6AD0;
/*801AE534*/ s32 D_801AE534;
/*801AE900*/ s32 D_801AE900;

/*.text*/

/*80083890*/
s32 swap32(u8 *arg0)
{
    /*TODO: endianess?*/
    u8 byte[4];

    byte[0] = *arg0++;
    byte[1] = *arg0++;
    byte[2] = *arg0++;
    byte[3] = *arg0++;

    return (byte[0] << 24) | (byte[1] << 16) | (byte[2] << 8) | byte[3];
}

/*800838E0*/
s32 swap16(u8 *arg0)
{
    /*TODO: endianess?*/
    u8 byte[2];

    byte[0] = *arg0++;
    byte[1] = *arg0++;
    return byte[1] | (byte[0] << 8);
}

/*80083908*/
static void func_80083908(s32 arg0)
{
    if ((D_8012EB50[arg0][6] & 0x40000000) != D_800E0F48)
    {
        D_800E0F48 = D_8012EB50[arg0][6] & 0x40000000;
        if (D_8012EB50[arg0][6] & 0x40000000)
        {
            gSPSetGeometryMode(D_8012F6F8++, G_TEXTURE_GEN);
            D_801ACBD4 = D_8012F6F8;
            gSPTexture(D_8012F6F8++, 0x05BC, 0x05BC, 0, G_TX_RENDERTILE, G_ON);
        }
        else
        {
            gSPClearGeometryMode(D_8012F6F8++, G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
            gSPTexture(D_8012F6F8++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
        }
        gSPVertex(D_8012F6F8++, (Vtx *)&D_8013F924[D_800FE3F4], D_8012F6EC, 0);
    }

    if ((D_8012EB50[arg0][6] & 0x10000000) != D_800E0F44)
    {
        D_800E0F44 = (D_8012EB50[arg0][6] & 0x10000000);
        if (D_8012EB50[arg0][6] & 0x10000000)
        {
            gDPSetTextureLUT(D_8012F6F8++, G_TT_NONE);
            gDPSetRenderMode(D_8012F6F8++, G_RM_ZB_CLD_SURF, G_RM_ZB_CLD_SURF2);
            gDPSetCombineLERP(D_8012F6F8++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                               PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
            return;
        }
        else
        {
            gDPSetCombineMode(D_8012F6F8++, G_CC_MODULATEIA, G_CC_MODULATEIA);
            gDPSetTextureLUT(D_8012F6F8++, G_TT_RGBA16);
        }
    }
    if ((D_8012EB50[arg0][6] & 4) != D_800E0F4C)
    {
        D_800E0F4C = D_8012EB50[arg0][6] & 4;
        if (D_8012EB50[arg0][6] & 4)
        {
            if (D_800E0F58 != 0)
            {
                gDPSetRenderMode(D_8012F6F8++, G_RM_ZB_CLD_SURF, G_RM_ZB_CLD_SURF2);
            }
            else
            {
                gDPSetRenderMode(D_8012F6F8++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
            }
        }
        else
            gDPSetRenderMode(D_8012F6F8++, D_800E0F50, D_800E0F54);
    }
}

/*80083BF4*/
static void func_80083BF4(code0UnkStruct18 *arg0, s32 arg1, code0UnkStruct18 *arg2, s32 arg3)
{
    s32 i;

    for (i = 0; i < arg1; i++)
        arg2[i] = arg0[i];
}

/*80083C40*/
STATIC void func_80083C40(void);
INCLUDE_ASM("nonmatchings/src/code0/84490", func_80083C40);

/*800847F8*/
static void func_800847F8(void)
{
    D_800FE3F4 += D_8012F6EC;
    D_8012F6EC = 0;
    D_8011815C = 0;
}

/*8008482C*/
static void func_8008482C(void)
{
    s32 temp;

    if ((D_8012F6EC + 3) >= D_800E0F28)
        func_80083C40();

    if (D_8012FD8C->unkC & 0x20)
    {
        if (D_8012FD8C->unkC & 0x1000)
        {
            D_801A6AD0 = &D_8013F924[D_80168D18];
            D_80119A6C = &D_8016A170[D_80118168.unk1C];
            D_801A6AD0->v.ob[0] = -D_80119A6C->unk0;
            D_801A6AD0->v.ob[1] = D_80119A6C->unk2;
            D_801A6AD0->v.ob[2] = D_80119A6C->unk4;
            D_801A6AD0->v.tc[0] = D_80118168.unk28 << 6;
            D_801A6AD0->v.tc[1] = D_80118168.unk2A << 6;
            D_801A6AD0->v.flag = 0;
            D_801A6AD0->v.cn[0] = D_80118168.unk34[2].unk0;
            D_801A6AD0->v.cn[1] = D_80118168.unk34[2].unk4;
            D_801A6AD0->v.cn[2] = D_80118168.unk34[2].unk8;
            D_801A6AD0->v.cn[3] = 0xFF;
            D_80168D18++;

            D_801A6AD0 = &D_8013F924[D_80168D18];
            D_80119A6C = &D_8016A170[D_80118168.unk1A];
            D_801A6AD0->v.ob[0] = -D_80119A6C->unk0;
            D_801A6AD0->v.ob[1] = D_80119A6C->unk2;
            D_801A6AD0->v.ob[2] = D_80119A6C->unk4;
            D_801A6AD0->v.tc[0] = D_80118168.unk24 << 6;
            D_801A6AD0->v.tc[1] = D_80118168.unk26 << 6;
            D_801A6AD0->v.flag = 0;
            D_801A6AD0->v.cn[0] = D_80118168.unk34[1].unk0;
            D_801A6AD0->v.cn[1] = D_80118168.unk34[1].unk4;
            D_801A6AD0->v.cn[2] = D_80118168.unk34[1].unk8;
            D_801A6AD0->v.cn[3] = 0xFF;
            D_80168D18++;

            D_801A6AD0 = &D_8013F924[D_80168D18];
            D_80119A6C = &D_8016A170[D_80118168.unk18];
            D_801A6AD0->v.ob[0] = -D_80119A6C->unk0;
            D_801A6AD0->v.ob[1] = D_80119A6C->unk2;
            D_801A6AD0->v.ob[2] = D_80119A6C->unk4;
            D_801A6AD0->v.tc[0] = D_80118168.unk20 << 6;
            D_801A6AD0->v.tc[1] = D_80118168.unk22 << 6;
            D_801A6AD0->v.flag = 0;
            D_801A6AD0->v.cn[0] = D_80118168.unk34[0].unk0;
            D_801A6AD0->v.cn[1] = D_80118168.unk34[0].unk4;
            D_801A6AD0->v.cn[2] = D_80118168.unk34[0].unk8;
            D_801A6AD0->v.cn[3] = 0xFF;
            D_80168D18++;
        }
        else
        {
            D_8013F924[D_80168D18].v.ob[0] = -D_8016A170[D_80118168.unk1C].unk0;
            D_8013F924[D_80168D18].v.ob[1] = D_8016A170[D_80118168.unk1C].unk2;
            D_8013F924[D_80168D18].v.ob[2] = D_8016A170[D_80118168.unk1C].unk4;
            D_8013F924[D_80168D18].v.tc[0] = D_80118168.unk28 << 6;
            D_8013F924[D_80168D18].v.tc[1] = D_80118168.unk2A << 6;
            D_8013F924[D_80168D18].v.flag = 0;
            D_8013F924[D_80168D18].v.cn[0] = D_8013F924[D_80168D18].v.cn[1] = D_8013F924[D_80168D18].v.cn[2] = 0xFF;
            D_8013F924[D_80168D18].v.cn[3] = D_8012FD8C->unk12;
            D_80168D18++;

            D_8013F924[D_80168D18].v.ob[0] = -D_8016A170[D_80118168.unk1A].unk0;
            D_8013F924[D_80168D18].v.ob[1] = D_8016A170[D_80118168.unk1A].unk2;
            D_8013F924[D_80168D18].v.ob[2] = D_8016A170[D_80118168.unk1A].unk4;
            D_8013F924[D_80168D18].v.tc[0] = D_80118168.unk24 << 6;
            D_8013F924[D_80168D18].v.tc[1] = D_80118168.unk26 << 6;
            D_8013F924[D_80168D18].v.flag = 0;
            D_8013F924[D_80168D18].v.cn[0] = D_8013F924[D_80168D18].v.cn[1] = D_8013F924[D_80168D18].v.cn[2] = 0xFF;
            D_8013F924[D_80168D18].v.cn[3] = D_8012FD8C->unk12;
            D_80168D18++;

            D_8013F924[D_80168D18].v.ob[0] = -D_8016A170[D_80118168.unk18].unk0;
            D_8013F924[D_80168D18].v.ob[1] = D_8016A170[D_80118168.unk18].unk2;
            D_8013F924[D_80168D18].v.ob[2] = D_8016A170[D_80118168.unk18].unk4;
            D_8013F924[D_80168D18].v.tc[0] = D_80118168.unk20 << 6;
            D_8013F924[D_80168D18].v.tc[1] = D_80118168.unk22 << 6;
            D_8013F924[D_80168D18].v.flag = 0;
            D_8013F924[D_80168D18].v.cn[0] = D_8013F924[D_80168D18].v.cn[1] = D_8013F924[D_80168D18].v.cn[2] = 0xFF;
            D_8013F924[D_80168D18].v.cn[3] = D_8012FD8C->unk12;
            D_80168D18++;
        }
    }
    else
    {
        D_8013F924[D_80168D18].v.ob[0] = -D_80118168.unk14[D_80118168.unk1C].unk0;
        D_8013F924[D_80168D18].v.ob[1] = D_80118168.unk14[D_80118168.unk1C].unk2;
        D_8013F924[D_80168D18].v.ob[2] = D_80118168.unk14[D_80118168.unk1C].unk4;
        D_8013F924[D_80168D18].v.tc[0] = D_80118168.unk28 << 6;
        D_8013F924[D_80168D18].v.tc[1] = D_80118168.unk2A << 6;
        D_8013F924[D_80168D18].v.flag = 0;
        D_8013F924[D_80168D18].v.cn[0] = D_8013F924[D_80168D18].v.cn[1] = D_8013F924[D_80168D18].v.cn[2] = 0xFF;
        D_8013F924[D_80168D18].v.cn[3] = D_8012FD8C->unk12;
        D_80168D18++;

        D_8013F924[D_80168D18].v.ob[0] = -D_80118168.unk14[D_80118168.unk1A].unk0;
        D_8013F924[D_80168D18].v.ob[1] = D_80118168.unk14[D_80118168.unk1A].unk2;
        D_8013F924[D_80168D18].v.ob[2] = D_80118168.unk14[D_80118168.unk1A].unk4;
        D_8013F924[D_80168D18].v.tc[0] = D_80118168.unk24 << 6;
        D_8013F924[D_80168D18].v.tc[1] = D_80118168.unk26 << 6;
        D_8013F924[D_80168D18].v.flag = 0;
        D_8013F924[D_80168D18].v.cn[0] = D_8013F924[D_80168D18].v.cn[1] = D_8013F924[D_80168D18].v.cn[2] = 0xFF;
        D_8013F924[D_80168D18].v.cn[3] = D_8012FD8C->unk12;
        D_80168D18++;

        D_8013F924[D_80168D18].v.ob[0] = -D_80118168.unk14[D_80118168.unk18].unk0;
        D_8013F924[D_80168D18].v.ob[1] = D_80118168.unk14[D_80118168.unk18].unk2;
        D_8013F924[D_80168D18].v.ob[2] = D_80118168.unk14[D_80118168.unk18].unk4;
        D_8013F924[D_80168D18].v.tc[0] = D_80118168.unk20 << 6;
        D_8013F924[D_80168D18].v.tc[1] = D_80118168.unk22 << 6;
        D_8013F924[D_80168D18].v.flag = 0;
        D_8013F924[D_80168D18].v.cn[0] = D_8013F924[D_80168D18].v.cn[1] = D_8013F924[D_80168D18].v.cn[2] = 0xFF;
        D_8013F924[D_80168D18].v.cn[3] = D_8012FD8C->unk12;
        D_80168D18++;
    }

    temp = D_8012F6EC;
    D_8012EB50[D_8011815C][5] = temp;
    D_8012EB50[D_8011815C][1] = D_80118168.unk4;
    D_8012EB50[D_8011815C][0] = D_80118168.unk0;
    D_8012EB50[D_8011815C][3] = D_80118168.unk8;
    D_8012EB50[D_8011815C][4] = D_80118168.unkC;
    D_8012EB50[D_8011815C][2] = D_80118168.unk10;
    D_8012EB50[D_8011815C][6] = D_80118168.unk30;
    D_8012F6EC += 3;
    D_8011815C++;
}

/*80085128*/
static void func_80085128(void)
{
    u8 pad[16];
    s32 temp;

    if ((D_8012F6EC + 4) >= D_800E0F28)
        func_80083C40();

    if (D_8012FD8C->unkC & 0x20)
    {
        if (D_8012FD8C->unkC & 0x1000)
        {
            D_801A6AD0 = &D_8013F924[D_80168D18];
            D_80119A6C = &D_8016A170[D_80118168.unk1E];
            D_801A6AD0->v.ob[0] = -D_80119A6C->unk0;
            D_801A6AD0->v.ob[1] = D_80119A6C->unk2;
            D_801A6AD0->v.ob[2] = D_80119A6C->unk4;
            D_801A6AD0->v.tc[0] = D_80118168.unk2C << 6;
            D_801A6AD0->v.tc[1] = D_80118168.unk2E << 6;
            D_801A6AD0->v.flag = 0;
            D_801A6AD0->v.cn[0] = D_80118168.unk34[3].unk0;
            D_801A6AD0->v.cn[1] = D_80118168.unk34[3].unk4;
            D_801A6AD0->v.cn[2] = D_80118168.unk34[3].unk8;
            D_801A6AD0->v.cn[3] = 0xFF;
            D_80168D18++;

            D_801A6AD0 = &D_8013F924[D_80168D18];
            D_80119A6C = &D_8016A170[D_80118168.unk1C];
            D_801A6AD0->v.ob[0] = -D_80119A6C->unk0;
            D_801A6AD0->v.ob[1] = D_80119A6C->unk2;
            D_801A6AD0->v.ob[2] = D_80119A6C->unk4;
            D_801A6AD0->v.tc[0] = D_80118168.unk28 << 6;
            D_801A6AD0->v.tc[1] = D_80118168.unk2A << 6;
            D_801A6AD0->v.flag = 0;
            D_801A6AD0->v.cn[0] = D_80118168.unk34[2].unk0;
            D_801A6AD0->v.cn[1] = D_80118168.unk34[2].unk4;
            D_801A6AD0->v.cn[2] = D_80118168.unk34[2].unk8;
            D_801A6AD0->v.cn[3] = 0xFF;
            D_80168D18++;

            D_801A6AD0 = &D_8013F924[D_80168D18];
            D_80119A6C = &D_8016A170[D_80118168.unk1A];
            D_801A6AD0->v.ob[0] = -D_80119A6C->unk0;
            D_801A6AD0->v.ob[1] = D_80119A6C->unk2;
            D_801A6AD0->v.ob[2] = D_80119A6C->unk4;
            D_801A6AD0->v.tc[0] = D_80118168.unk24 << 6;
            D_801A6AD0->v.tc[1] = D_80118168.unk26 << 6;
            D_801A6AD0->v.flag = 0;
            D_801A6AD0->v.cn[0] = D_80118168.unk34[1].unk0;
            D_801A6AD0->v.cn[1] = D_80118168.unk34[1].unk4;
            D_801A6AD0->v.cn[2] = D_80118168.unk34[1].unk8;
            D_801A6AD0->v.cn[3] = 0xFF;
            D_80168D18++;

            D_801A6AD0 = &D_8013F924[D_80168D18];
            D_80119A6C = &D_8016A170[D_80118168.unk18];
            D_801A6AD0->v.ob[0] = -D_80119A6C->unk0;
            D_801A6AD0->v.ob[1] = D_80119A6C->unk2;
            D_801A6AD0->v.ob[2] = D_80119A6C->unk4;
            D_801A6AD0->v.tc[0] = D_80118168.unk20 << 6;
            D_801A6AD0->v.tc[1] = D_80118168.unk22 << 6;
            D_801A6AD0->v.flag = 0;
            D_801A6AD0->v.cn[0] = D_80118168.unk34[0].unk0;
            D_801A6AD0->v.cn[1] = D_80118168.unk34[0].unk4;
            D_801A6AD0->v.cn[2] = D_80118168.unk34[0].unk8;
            D_801A6AD0->v.cn[3] = 0xFF;
            D_80168D18++;
        }
        else
        {
            D_8013F924[D_80168D18].v.ob[0] = -D_8016A170[D_80118168.unk1E].unk0;
            D_8013F924[D_80168D18].v.ob[1] = D_8016A170[D_80118168.unk1E].unk2;
            D_8013F924[D_80168D18].v.ob[2] = D_8016A170[D_80118168.unk1E].unk4;
            D_8013F924[D_80168D18].v.tc[0] = D_80118168.unk2C << 6;
            D_8013F924[D_80168D18].v.tc[1] = D_80118168.unk2E << 6;
            D_8013F924[D_80168D18].v.flag = 0;
            D_8013F924[D_80168D18].v.cn[0] = D_8013F924[D_80168D18].v.cn[1] = D_8013F924[D_80168D18].v.cn[2] = 0xFF;
            D_8013F924[D_80168D18].v.cn[3] = D_8012FD8C->unk12;
            D_80168D18++;

            D_8013F924[D_80168D18].v.ob[0] = -D_8016A170[D_80118168.unk1C].unk0;
            D_8013F924[D_80168D18].v.ob[1] = D_8016A170[D_80118168.unk1C].unk2;
            D_8013F924[D_80168D18].v.ob[2] = D_8016A170[D_80118168.unk1C].unk4;
            D_8013F924[D_80168D18].v.tc[0] = D_80118168.unk28 << 6;
            D_8013F924[D_80168D18].v.tc[1] = D_80118168.unk2A << 6;
            D_8013F924[D_80168D18].v.flag = 0;
            D_8013F924[D_80168D18].v.cn[0] = D_8013F924[D_80168D18].v.cn[1] = D_8013F924[D_80168D18].v.cn[2] = 0xFF;
            D_8013F924[D_80168D18].v.cn[3] = D_8012FD8C->unk12;
            D_80168D18++;

            D_8013F924[D_80168D18].v.ob[0] = -D_8016A170[D_80118168.unk1A].unk0;
            D_8013F924[D_80168D18].v.ob[1] = D_8016A170[D_80118168.unk1A].unk2;
            D_8013F924[D_80168D18].v.ob[2] = D_8016A170[D_80118168.unk1A].unk4;
            D_8013F924[D_80168D18].v.tc[0] = D_80118168.unk24 << 6;
            D_8013F924[D_80168D18].v.tc[1] = D_80118168.unk26 << 6;
            D_8013F924[D_80168D18].v.flag = 0;
            D_8013F924[D_80168D18].v.cn[0] = D_8013F924[D_80168D18].v.cn[1] = D_8013F924[D_80168D18].v.cn[2] = 0xFF;
            D_8013F924[D_80168D18].v.cn[3] = D_8012FD8C->unk12;
            D_80168D18++;

            D_8013F924[D_80168D18].v.ob[0] = -D_8016A170[D_80118168.unk18].unk0;
            D_8013F924[D_80168D18].v.ob[1] = D_8016A170[D_80118168.unk18].unk2;
            D_8013F924[D_80168D18].v.ob[2] = D_8016A170[D_80118168.unk18].unk4;
            D_8013F924[D_80168D18].v.tc[0] = D_80118168.unk20 << 6;
            D_8013F924[D_80168D18].v.tc[1] = D_80118168.unk22 << 6;
            D_8013F924[D_80168D18].v.flag = 0;
            D_8013F924[D_80168D18].v.cn[0] = D_8013F924[D_80168D18].v.cn[1] = D_8013F924[D_80168D18].v.cn[2] = 0xFF;
            D_8013F924[D_80168D18].v.cn[3] = D_8012FD8C->unk12;
            D_80168D18++;
        }
    }
    else
    {
        D_8013F924[D_80168D18].v.ob[0] = -D_80118168.unk14[D_80118168.unk1E].unk0;
        D_8013F924[D_80168D18].v.ob[1] = D_80118168.unk14[D_80118168.unk1E].unk2;
        D_8013F924[D_80168D18].v.ob[2] = D_80118168.unk14[D_80118168.unk1E].unk4;
        D_8013F924[D_80168D18].v.tc[0] = D_80118168.unk2C << 6;
        D_8013F924[D_80168D18].v.tc[1] = D_80118168.unk2E << 6;
        D_8013F924[D_80168D18].v.flag = 0;
        D_8013F924[D_80168D18].v.cn[0] = D_8013F924[D_80168D18].v.cn[1] = D_8013F924[D_80168D18].v.cn[2] = 0xFF;
        D_8013F924[D_80168D18].v.cn[3] = D_8012FD8C->unk12;
        D_80168D18++;

        D_8013F924[D_80168D18].v.ob[0] = -D_80118168.unk14[D_80118168.unk1C].unk0;
        D_8013F924[D_80168D18].v.ob[1] = D_80118168.unk14[D_80118168.unk1C].unk2;
        D_8013F924[D_80168D18].v.ob[2] = D_80118168.unk14[D_80118168.unk1C].unk4;
        D_8013F924[D_80168D18].v.tc[0] = D_80118168.unk28 << 6;
        D_8013F924[D_80168D18].v.tc[1] = D_80118168.unk2A << 6;
        D_8013F924[D_80168D18].v.flag = 0;
        D_8013F924[D_80168D18].v.cn[0] = D_8013F924[D_80168D18].v.cn[1] = D_8013F924[D_80168D18].v.cn[2] = 0xFF;
        D_8013F924[D_80168D18].v.cn[3] = D_8012FD8C->unk12;
        D_80168D18++;

        D_8013F924[D_80168D18].v.ob[0] = -D_80118168.unk14[D_80118168.unk1A].unk0;
        D_8013F924[D_80168D18].v.ob[1] = D_80118168.unk14[D_80118168.unk1A].unk2;
        D_8013F924[D_80168D18].v.ob[2] = D_80118168.unk14[D_80118168.unk1A].unk4;
        D_8013F924[D_80168D18].v.tc[0] = D_80118168.unk24 << 6;
        D_8013F924[D_80168D18].v.tc[1] = D_80118168.unk26 << 6;
        D_8013F924[D_80168D18].v.flag = 0;
        D_8013F924[D_80168D18].v.cn[0] = D_8013F924[D_80168D18].v.cn[1] = D_8013F924[D_80168D18].v.cn[2] = 0xFF;
        D_8013F924[D_80168D18].v.cn[3] = D_8012FD8C->unk12;
        D_80168D18++;

        D_8013F924[D_80168D18].v.ob[0] = -D_80118168.unk14[D_80118168.unk18].unk0;
        D_8013F924[D_80168D18].v.ob[1] = D_80118168.unk14[D_80118168.unk18].unk2;
        D_8013F924[D_80168D18].v.ob[2] = D_80118168.unk14[D_80118168.unk18].unk4;
        D_8013F924[D_80168D18].v.tc[0] = D_80118168.unk20 << 6;
        D_8013F924[D_80168D18].v.tc[1] = D_80118168.unk22 << 6;
        D_8013F924[D_80168D18].v.flag = 0;
        D_8013F924[D_80168D18].v.cn[0] = D_8013F924[D_80168D18].v.cn[1] = D_8013F924[D_80168D18].v.cn[2] = 0xFF;
        D_8013F924[D_80168D18].v.cn[3] = D_8012FD8C->unk12;
        D_80168D18++;
    }

    temp = D_8012F6EC;
    D_8012EB50[D_8011815C][5] = temp;
    D_8012EB50[D_8011815C][1] = D_80118168.unk4;
    D_8012EB50[D_8011815C][0] = D_80118168.unk0;
    D_8012EB50[D_8011815C][3] = D_80118168.unk8;
    D_8012EB50[D_8011815C][4] = D_80118168.unkC;
    D_8012EB50[D_8011815C][2] = D_80118168.unk10;
    D_8012EB50[D_8011815C][6] = D_80118168.unk30;
    D_8012F6EC += 4;
    D_8011815C++;
}

/*80085CDC*/
static void func_80085CDC(void)
{
    code0UnkStruct18 *ptr;
    Vtx *ptr2;

    ptr = &D_8016A170[D_80118168.unk1C];
    ptr2 = &D_8013F924[D_80168D18];
    ptr2->v.ob[0] = -ptr->unk0;
    ptr2->v.ob[1] = ptr->unk2;
    ptr2->v.ob[2] = ptr->unk4;
    ptr = &D_8016A170[D_80118168.unk1A];
    ptr2++;
    ptr2->v.ob[0] = -ptr->unk0;
    ptr2->v.ob[1] = ptr->unk2;
    ptr2->v.ob[2] = ptr->unk4;
    ptr = &D_8016A170[D_80118168.unk18];
    ptr2++;
    ptr2->v.ob[0] = -ptr->unk0;
    ptr2->v.ob[1] = ptr->unk2;
    ptr2->v.ob[2] = ptr->unk4;
    D_80168D18 += 3;
}

/*80085DB0*/
static void func_80085DB0(void)
{
    code0UnkStruct18 *ptr;
    Vtx *ptr2;

    ptr = &D_8016A170[D_80118168.unk1E];
    ptr2 = &D_8013F924[D_80168D18];
    ptr2->v.ob[0] = -ptr->unk0;
    ptr2->v.ob[1] = ptr->unk2;
    ptr2->v.ob[2] = ptr->unk4;
    ptr = &D_8016A170[D_80118168.unk1C];
    ptr2++;
    ptr2->v.ob[0] = -ptr->unk0;
    ptr2->v.ob[1] = ptr->unk2;
    ptr2->v.ob[2] = ptr->unk4;
    ptr = &D_8016A170[D_80118168.unk1A];
    ptr2++;
    ptr2->v.ob[0] = -ptr->unk0;
    ptr2->v.ob[1] = ptr->unk2;
    ptr2->v.ob[2] = ptr->unk4;
    ptr = &D_8016A170[D_80118168.unk18];
    ptr2++;
    ptr2->v.ob[0] = -ptr->unk0;
    ptr2->v.ob[1] = ptr->unk2;
    ptr2->v.ob[2] = ptr->unk4;
    D_80168D18 += 4;
}

/*80085EBC*/
void func_80085EBC(Vtx *arg0, s32 arg1, Gfx **arg2, s32 arg3, s32 arg4)
{
    Gfx *dlist;

    D_8011815C = 0;
    D_8012F6EC = 0;
    D_8013F924 = arg0;
    D_80199968 = arg1;
    dlist = *arg2;
    D_80197DD0 = arg3;
    D_801AE534 = 0;
    D_8012B940 = 0;
    D_800FCBE4 = 0;
    D_80138810 = 0;
    D_80119AA0 = 0;
    D_80199108 = 0;
    D_8012F6F8 = dlist;
    D_801385F8 = dlist;
    gSPTexture(D_8012F6F8++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
}

/*80085F50*/
static void func_80085F50(Gfx **arg0, s32 arg1)
{

    func_80083C40();
    if (D_800E0F44 != 0)
    {
        gDPPipeSync(D_8012F6F8++);
        gDPSetRenderMode(D_8012F6F8++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineMode(D_8012F6F8++, G_CC_MODULATEIA, G_CC_MODULATEIA);
        gDPSetTextureLUT(D_8012F6F8++, G_TT_RGBA16);
    }
    gSPEndDisplayList(D_8012F6F8++);
    *arg0 = D_8012F6F8;
}

/*80086030*/
static void func_80086030(void)
{
    func_80083BF4(D_8012FD8C->unk84, D_8012FD8C->unk88, D_8016A170, 0);
}

/*80086068*/
static void func_80086068(void)
{
    if (D_80118168.unk1C == D_80118168.unk1E)
        func_8008482C();
    else
        func_80085128();
}

/*800860AC*/
static void func_800860AC(s32 arg0)
{
    if (arg0 & 0x80)
        D_800E0F5C = 1;
    else
        D_800E0F5C = 0;

    func_80081E20(func_80086030, func_80086068, 1);
}

/*80086100*/
static void func_80086100(s32 arg0)
{
    u8 pad[64];

    gDPPipeSync(D_8012F6F8++);

    if (arg0 & 0x4000)
    {
        D_800E0F50 = G_RM_ZB_XLU_SURF;
        D_800E0F54 = G_RM_ZB_XLU_SURF2;
    }
    else if (arg0 & 0x80)
    {
        D_800E0F50 = G_RM_AA_ZB_OPA_SURF;
        D_800E0F54 = G_RM_AA_ZB_OPA_SURF2;
    }
    else
    {
        D_800E0F50 = G_RM_OPA_SURF;
        D_800E0F54 = G_RM_OPA_SURF2;
    }

    gDPSetRenderMode(D_8012F6F8++, D_800E0F50, D_800E0F54);
    D_800E0F48 = 0;
    D_800E0F4C = 0;
    D_800E0F44 = 0;
    gSPClearGeometryMode(D_8012F6F8++, G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
}

/*800861F4*/
void func_800861F4(code0UnkStruct20 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4,
                   f32 arg5, s32 arg6, Vtx *arg7, s32 arg8, Gfx *arg9, s32 argA)
{
    code0UnkStruct16 sp20;
    Gfx *dlist;

    D_80168D18 = 0;
    D_800FE3F4 = 0;
    dlist = arg9;
    func_80085EBC(arg7, arg8, &dlist, argA, arg6);
    D_801AE534 = 0;
    D_8012B940 = 0;
    D_800FCBE4 = 0;
    D_80138810 = 0;
    D_80119AA0 = 0;
    D_80199108 = 0;
    func_80086100(arg6);
    D_8012FD8C = &sp20;
    func_8007EC7C(D_8012FD8C);
    D_8012FD8C->unk34 = arg1;
    D_8012FD8C->unk38 = arg2;
    D_8012FD8C->unk3C = arg3;
    D_8012FD8C->unk40 = arg5;
    D_8012FD8C->unk50 = arg4;
    D_8012FD8C->unkC = arg6;
    func_800818A8(D_8012FD8C, arg0->unk0, arg0->unk2, arg0->unk4, arg0->unk8, arg0->unk10, arg0->unkC);
    D_800E0F2C = 32768.0f;
    D_800E0F30 = -32768.0f;
    D_800E0F34 = 32768.0f;
    D_800E0F38 = -32768.0f;
    D_800E0F3C = 32768.0f;
    D_800E0F40 = -32768.0f;
    func_800860AC(arg6);
    func_80085F50(&dlist, arg6);
    D_801AE900 = D_80168D18;
    D_80129800 = D_8012F6F8 - arg9;

    if (D_800E0F20 < D_80168D18)
        D_800E0F20 = D_80168D18;

    if (D_800E0F24 < D_80129800)
        D_800E0F24 = D_80129800;
}
