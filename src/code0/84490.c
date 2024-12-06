#include "common.h"
#include "code0/7F6A0.h"
#include "code0/82480.h"
#include "code0/code0.h"

typedef struct
{
    /*0x00*/ u8 *texture;
    /*0x04*/ s32 unk4;
    /*0x08*/ u8 *palette;
    /*0x0C*/ s32 width;
    /*0x10*/ s32 height;
    /*0x14*/ s32 unk14;
    /*0x18*/ s32 unk18;
} _84490UnkStruct1;

/*.data*/
/*800E0F20*/ static s32 D_800E0F20 = 0;
/*800E0F24*/ static s32 D_800E0F24 = 0;
/*800E0F28*/ static s32 D_800E0F28 = 32;
/*800E0F2C*/ static f32 D_800E0F2C[6] = {0.0f};
/*800E0F44*/ static s32 D_800E0F44 = 0;
/*800E0F48*/ static s32 D_800E0F48 = 0;
/*800E0F4C*/ static s32 D_800E0F4C = 0;
/*800E0F50*/ static s32 D_800E0F50 = 0;
/*800E0F54*/ static s32 D_800E0F54 = 0;
/*800E0F58*/ s32 D_800E0F58 = 1;
/*800E0F5C*/ static u8 D_800E0F5C = 0;

/*.comm*/
/*800FCBE4*/ u8 *_palette;
/*8011815C*/ s32 D_8011815C;
/*80119A6C*/ code0UnkStruct18 *D_80119A6C;
/*80119AA0*/ s32 D_80119AA0;
/*80129800*/ s32 D_80129800;
/*8012B940*/ s32 D_8012B940;
/*8012EB50*/ _84490UnkStruct1 D_8012EB50[32] ALIGNED(8);
/*8012F6EC*/ s32 D_8012F6EC;
/*8012F6F8*/ Gfx *_displayList;
/*801385F8*/ Gfx *D_801385F8;
/*80138810*/ u8 *_texture;
/*8013F924*/ Vtx *_vertex;
/*8016A170*/ code0UnkStruct18 D_8016A170[2048] ALIGNED(16);
/*80197DD0*/ s32 D_80197DD0;
/*80199108*/ u8 D_80199108;
/*80199968*/ s32 D_80199968;
/*801A6AD0*/ Vtx *_pvtx;
/*801AE534*/ s32 D_801AE534;
/*801AE900*/ s32 D_801AE900;

/*.text*/

/*80083890*/
s32 swap32(u8 *arg0)
{
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
    u8 byte[2];

    byte[0] = *arg0++;
    byte[1] = *arg0++;
    return byte[1] | (byte[0] << 8);
}

/*80083908*/
static void func_80083908(s32 arg0)
{
    if ((D_8012EB50[arg0].unk18 & 0x40000000) != D_800E0F48)
    {
        D_800E0F48 = D_8012EB50[arg0].unk18 & 0x40000000;
        if (D_8012EB50[arg0].unk18 & 0x40000000)
        {
            gSPSetGeometryMode(_displayList++, G_TEXTURE_GEN);
            D_801ACBD4 = _displayList;
            gSPTexture(_displayList++, 0x05BC, 0x05BC, 0, G_TX_RENDERTILE, G_ON);
        }
        else
        {
            gSPClearGeometryMode(_displayList++, G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
            gSPTexture(_displayList++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
        }
        gSPVertex(_displayList++, (Vtx *)&_vertex[D_800FE3F4], D_8012F6EC, 0);
    }

    if ((D_8012EB50[arg0].unk18 & 0x10000000) != D_800E0F44)
    {
        D_800E0F44 = (D_8012EB50[arg0].unk18 & 0x10000000);
        if (D_8012EB50[arg0].unk18 & 0x10000000)
        {
            gDPSetTextureLUT(_displayList++, G_TT_NONE);
            gDPSetRenderMode(_displayList++, G_RM_ZB_CLD_SURF, G_RM_ZB_CLD_SURF2);
            gDPSetCombineLERP(_displayList++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                                              PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
            return;
        }
        else
        {
            gDPSetCombineMode(_displayList++, G_CC_MODULATEIA, G_CC_MODULATEIA);
            gDPSetTextureLUT(_displayList++, G_TT_RGBA16);
        }
    }
    if ((D_8012EB50[arg0].unk18 & 4) != D_800E0F4C)
    {
        D_800E0F4C = D_8012EB50[arg0].unk18 & 4;
        if (D_8012EB50[arg0].unk18 & 4)
        {
            if (D_800E0F58 != 0)
            {
                gDPSetRenderMode(_displayList++, G_RM_ZB_CLD_SURF, G_RM_ZB_CLD_SURF2);
            }
            else
            {
                gDPSetRenderMode(_displayList++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
            }
        }
        else
            gDPSetRenderMode(_displayList++, D_800E0F50, D_800E0F54);
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
static void func_80083C40(void)
{
    s32 i, v;

    if (D_8012F6EC > 0)
    {
        gSPVertex(_displayList++, &_vertex[D_800FE3F4], D_8012F6EC, 0);
    }

    for (i = 0; i < D_8011815C; i++)
    {
        if ((D_8012EB50[i].texture != _texture) || ((D_8012EB50[i].unk18 & 0x210) != D_80119AA0))
        {
            if (D_8012EB50[i].unk18 & 8)
            {
                gDPPipeSync(_displayList++);
                if (D_8012EB50[i].unk18 & 0x10000000)
                {
                    gDPLoadTextureBlock_4b(_displayList++, D_8012EB50[i].texture, G_IM_FMT_I, D_8012EB50[i].width, D_8012EB50[i].height, 0,
                                                                                  G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                                                                                  6, 6, G_TX_NOLOD, G_TX_NOLOD);
                }
                else
                {
                    gDPLoadTextureBlock_4b(_displayList++, D_8012EB50[i].texture, G_IM_FMT_CI, D_8012EB50[i].width, D_8012EB50[i].height, 0,
                                                                                  G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                                                                                  G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                }
            }
            else if (D_8012EB50[i].unk18 & 0x10000000)
            {

                gDPPipeSync(_displayList++);
                gDPLoadTextureBlock_4b(_displayList++, D_8012EB50[i].texture, G_IM_FMT_I, D_8012EB50[i].width, D_8012EB50[i].height, 0,
                                                                              G_TX_MIRROR | G_TX_CLAMP, G_TX_MIRROR | G_TX_CLAMP,
                                                                              G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            }
            else
            {
                if (D_8012EB50[i].unk18 & 0x40000000)
                {
                    gDPPipeSync(_displayList++);
                    gDPLoadTextureBlock(_displayList++, D_8012EB50[i].texture, G_IM_FMT_CI, G_IM_SIZ_8b, D_8012EB50[i].width, D_8012EB50[i].height, 0,
                                                                               G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                                                                               5, 5, G_TX_NOLOD, G_TX_NOLOD);
                }
                else
                {
                    gDPPipeSync(_displayList++);
                    gDPLoadTextureBlock(_displayList++, D_8012EB50[i].texture, G_IM_FMT_CI, G_IM_SIZ_8b, D_8012EB50[i].width, D_8012EB50[i].height, 0,
                                                                               G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP,
                                                                               G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                }
            }
            _texture = D_8012EB50[i].texture;
            D_80119AA0 = D_8012EB50[i].unk18 & 0x210;
        }

        if (D_8012EB50[i].palette != _palette)
        {
            if (!(D_8012FD8C->unkC & 0x10000))
            {
                gDPPipeSync(_displayList++);
                if (!(D_8012FD8C->unkC & 0x800000))
                {
                    gDPLoadTLUT_pal256(_displayList++, D_8012EB50[i].palette);
                }
            }
            _palette = D_8012EB50[i].palette;
        }

        func_80083908(i);
        if (D_8012EB50[i].unk18 & 1)
        {
            v = D_8012EB50[i].unk14;
            gSP2Triangles(_displayList++, v, v+1, v+2, 0,
                                          v, v+2, v+3, 1);
        }
        else
        {
            v = D_8012EB50[i].unk14;
            gSP1Triangle(_displayList++, v, v+1, v+2, 0);
        }
    }

    D_8011815C = 0;
    D_800FE3F4 += D_8012F6EC;
    D_8012F6EC = 0;
}

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
            _pvtx = &_vertex[D_80168D18];
            D_80119A6C = &D_8016A170[D_80118168.unk1C];
            _pvtx->v.ob[0] = -D_80119A6C->x;
            _pvtx->v.ob[1] = D_80119A6C->y;
            _pvtx->v.ob[2] = D_80119A6C->z;
            _pvtx->v.tc[0] = D_80118168.unk28 << 6;
            _pvtx->v.tc[1] = D_80118168.unk2A << 6;
            _pvtx->v.flag = 0;
            _pvtx->v.cn[0] = D_80118168.unk34[2].unk0;
            _pvtx->v.cn[1] = D_80118168.unk34[2].unk4;
            _pvtx->v.cn[2] = D_80118168.unk34[2].unk8;
            _pvtx->v.cn[3] = 0xFF;
            D_80168D18++;

            _pvtx = &_vertex[D_80168D18];
            D_80119A6C = &D_8016A170[D_80118168.unk1A];
            _pvtx->v.ob[0] = -D_80119A6C->x;
            _pvtx->v.ob[1] = D_80119A6C->y;
            _pvtx->v.ob[2] = D_80119A6C->z;
            _pvtx->v.tc[0] = D_80118168.unk24 << 6;
            _pvtx->v.tc[1] = D_80118168.unk26 << 6;
            _pvtx->v.flag = 0;
            _pvtx->v.cn[0] = D_80118168.unk34[1].unk0;
            _pvtx->v.cn[1] = D_80118168.unk34[1].unk4;
            _pvtx->v.cn[2] = D_80118168.unk34[1].unk8;
            _pvtx->v.cn[3] = 0xFF;
            D_80168D18++;

            _pvtx = &_vertex[D_80168D18];
            D_80119A6C = &D_8016A170[D_80118168.unk18];
            _pvtx->v.ob[0] = -D_80119A6C->x;
            _pvtx->v.ob[1] = D_80119A6C->y;
            _pvtx->v.ob[2] = D_80119A6C->z;
            _pvtx->v.tc[0] = D_80118168.unk20 << 6;
            _pvtx->v.tc[1] = D_80118168.unk22 << 6;
            _pvtx->v.flag = 0;
            _pvtx->v.cn[0] = D_80118168.unk34[0].unk0;
            _pvtx->v.cn[1] = D_80118168.unk34[0].unk4;
            _pvtx->v.cn[2] = D_80118168.unk34[0].unk8;
            _pvtx->v.cn[3] = 0xFF;
            D_80168D18++;
        }
        else
        {
            _vertex[D_80168D18].v.ob[0] = -D_8016A170[D_80118168.unk1C].x;
            _vertex[D_80168D18].v.ob[1] = D_8016A170[D_80118168.unk1C].y;
            _vertex[D_80168D18].v.ob[2] = D_8016A170[D_80118168.unk1C].z;
            _vertex[D_80168D18].v.tc[0] = D_80118168.unk28 << 6;
            _vertex[D_80168D18].v.tc[1] = D_80118168.unk2A << 6;
            _vertex[D_80168D18].v.flag = 0;
            _vertex[D_80168D18].v.cn[0] = _vertex[D_80168D18].v.cn[1] = _vertex[D_80168D18].v.cn[2] = 0xFF;
            _vertex[D_80168D18].v.cn[3] = D_8012FD8C->unk12;
            D_80168D18++;

            _vertex[D_80168D18].v.ob[0] = -D_8016A170[D_80118168.unk1A].x;
            _vertex[D_80168D18].v.ob[1] = D_8016A170[D_80118168.unk1A].y;
            _vertex[D_80168D18].v.ob[2] = D_8016A170[D_80118168.unk1A].z;
            _vertex[D_80168D18].v.tc[0] = D_80118168.unk24 << 6;
            _vertex[D_80168D18].v.tc[1] = D_80118168.unk26 << 6;
            _vertex[D_80168D18].v.flag = 0;
            _vertex[D_80168D18].v.cn[0] = _vertex[D_80168D18].v.cn[1] = _vertex[D_80168D18].v.cn[2] = 0xFF;
            _vertex[D_80168D18].v.cn[3] = D_8012FD8C->unk12;
            D_80168D18++;

            _vertex[D_80168D18].v.ob[0] = -D_8016A170[D_80118168.unk18].x;
            _vertex[D_80168D18].v.ob[1] = D_8016A170[D_80118168.unk18].y;
            _vertex[D_80168D18].v.ob[2] = D_8016A170[D_80118168.unk18].z;
            _vertex[D_80168D18].v.tc[0] = D_80118168.unk20 << 6;
            _vertex[D_80168D18].v.tc[1] = D_80118168.unk22 << 6;
            _vertex[D_80168D18].v.flag = 0;
            _vertex[D_80168D18].v.cn[0] = _vertex[D_80168D18].v.cn[1] = _vertex[D_80168D18].v.cn[2] = 0xFF;
            _vertex[D_80168D18].v.cn[3] = D_8012FD8C->unk12;
            D_80168D18++;
        }
    }
    else
    {
        _vertex[D_80168D18].v.ob[0] = -D_80118168.unk14[D_80118168.unk1C].x;
        _vertex[D_80168D18].v.ob[1] = D_80118168.unk14[D_80118168.unk1C].y;
        _vertex[D_80168D18].v.ob[2] = D_80118168.unk14[D_80118168.unk1C].z;
        _vertex[D_80168D18].v.tc[0] = D_80118168.unk28 << 6;
        _vertex[D_80168D18].v.tc[1] = D_80118168.unk2A << 6;
        _vertex[D_80168D18].v.flag = 0;
        _vertex[D_80168D18].v.cn[0] = _vertex[D_80168D18].v.cn[1] = _vertex[D_80168D18].v.cn[2] = 0xFF;
        _vertex[D_80168D18].v.cn[3] = D_8012FD8C->unk12;
        D_80168D18++;

        _vertex[D_80168D18].v.ob[0] = -D_80118168.unk14[D_80118168.unk1A].x;
        _vertex[D_80168D18].v.ob[1] = D_80118168.unk14[D_80118168.unk1A].y;
        _vertex[D_80168D18].v.ob[2] = D_80118168.unk14[D_80118168.unk1A].z;
        _vertex[D_80168D18].v.tc[0] = D_80118168.unk24 << 6;
        _vertex[D_80168D18].v.tc[1] = D_80118168.unk26 << 6;
        _vertex[D_80168D18].v.flag = 0;
        _vertex[D_80168D18].v.cn[0] = _vertex[D_80168D18].v.cn[1] = _vertex[D_80168D18].v.cn[2] = 0xFF;
        _vertex[D_80168D18].v.cn[3] = D_8012FD8C->unk12;
        D_80168D18++;

        _vertex[D_80168D18].v.ob[0] = -D_80118168.unk14[D_80118168.unk18].x;
        _vertex[D_80168D18].v.ob[1] = D_80118168.unk14[D_80118168.unk18].y;
        _vertex[D_80168D18].v.ob[2] = D_80118168.unk14[D_80118168.unk18].z;
        _vertex[D_80168D18].v.tc[0] = D_80118168.unk20 << 6;
        _vertex[D_80168D18].v.tc[1] = D_80118168.unk22 << 6;
        _vertex[D_80168D18].v.flag = 0;
        _vertex[D_80168D18].v.cn[0] = _vertex[D_80168D18].v.cn[1] = _vertex[D_80168D18].v.cn[2] = 0xFF;
        _vertex[D_80168D18].v.cn[3] = D_8012FD8C->unk12;
        D_80168D18++;
    }

    temp = D_8012F6EC; /*FAKEMATCH?*/
    D_8012EB50[D_8011815C].unk14 = temp;
    D_8012EB50[D_8011815C].unk4 = D_80118168.unk4;
    D_8012EB50[D_8011815C].texture = D_80118168.texture;
    D_8012EB50[D_8011815C].width = D_80118168.width;
    D_8012EB50[D_8011815C].height = D_80118168.height;
    D_8012EB50[D_8011815C].palette = D_80118168.palette;
    D_8012EB50[D_8011815C].unk18 = D_80118168.unk30;
    D_8012F6EC += 3;
    D_8011815C++;
}

/*80085128*/
static void func_80085128(void)
{
    u8 pad[16];
    s32 temp;

    (void)pad;
    if ((D_8012F6EC + 4) >= D_800E0F28)
        func_80083C40();

    if (D_8012FD8C->unkC & 0x20)
    {
        if (D_8012FD8C->unkC & 0x1000)
        {
            _pvtx = &_vertex[D_80168D18];
            D_80119A6C = &D_8016A170[D_80118168.unk1E];
            _pvtx->v.ob[0] = -D_80119A6C->x;
            _pvtx->v.ob[1] = D_80119A6C->y;
            _pvtx->v.ob[2] = D_80119A6C->z;
            _pvtx->v.tc[0] = D_80118168.unk2C << 6;
            _pvtx->v.tc[1] = D_80118168.unk2E << 6;
            _pvtx->v.flag = 0;
            _pvtx->v.cn[0] = D_80118168.unk34[3].unk0;
            _pvtx->v.cn[1] = D_80118168.unk34[3].unk4;
            _pvtx->v.cn[2] = D_80118168.unk34[3].unk8;
            _pvtx->v.cn[3] = 0xFF;
            D_80168D18++;

            _pvtx = &_vertex[D_80168D18];
            D_80119A6C = &D_8016A170[D_80118168.unk1C];
            _pvtx->v.ob[0] = -D_80119A6C->x;
            _pvtx->v.ob[1] = D_80119A6C->y;
            _pvtx->v.ob[2] = D_80119A6C->z;
            _pvtx->v.tc[0] = D_80118168.unk28 << 6;
            _pvtx->v.tc[1] = D_80118168.unk2A << 6;
            _pvtx->v.flag = 0;
            _pvtx->v.cn[0] = D_80118168.unk34[2].unk0;
            _pvtx->v.cn[1] = D_80118168.unk34[2].unk4;
            _pvtx->v.cn[2] = D_80118168.unk34[2].unk8;
            _pvtx->v.cn[3] = 0xFF;
            D_80168D18++;

            _pvtx = &_vertex[D_80168D18];
            D_80119A6C = &D_8016A170[D_80118168.unk1A];
            _pvtx->v.ob[0] = -D_80119A6C->x;
            _pvtx->v.ob[1] = D_80119A6C->y;
            _pvtx->v.ob[2] = D_80119A6C->z;
            _pvtx->v.tc[0] = D_80118168.unk24 << 6;
            _pvtx->v.tc[1] = D_80118168.unk26 << 6;
            _pvtx->v.flag = 0;
            _pvtx->v.cn[0] = D_80118168.unk34[1].unk0;
            _pvtx->v.cn[1] = D_80118168.unk34[1].unk4;
            _pvtx->v.cn[2] = D_80118168.unk34[1].unk8;
            _pvtx->v.cn[3] = 0xFF;
            D_80168D18++;

            _pvtx = &_vertex[D_80168D18];
            D_80119A6C = &D_8016A170[D_80118168.unk18];
            _pvtx->v.ob[0] = -D_80119A6C->x;
            _pvtx->v.ob[1] = D_80119A6C->y;
            _pvtx->v.ob[2] = D_80119A6C->z;
            _pvtx->v.tc[0] = D_80118168.unk20 << 6;
            _pvtx->v.tc[1] = D_80118168.unk22 << 6;
            _pvtx->v.flag = 0;
            _pvtx->v.cn[0] = D_80118168.unk34[0].unk0;
            _pvtx->v.cn[1] = D_80118168.unk34[0].unk4;
            _pvtx->v.cn[2] = D_80118168.unk34[0].unk8;
            _pvtx->v.cn[3] = 0xFF;
            D_80168D18++;
        }
        else
        {
            _vertex[D_80168D18].v.ob[0] = -D_8016A170[D_80118168.unk1E].x;
            _vertex[D_80168D18].v.ob[1] = D_8016A170[D_80118168.unk1E].y;
            _vertex[D_80168D18].v.ob[2] = D_8016A170[D_80118168.unk1E].z;
            _vertex[D_80168D18].v.tc[0] = D_80118168.unk2C << 6;
            _vertex[D_80168D18].v.tc[1] = D_80118168.unk2E << 6;
            _vertex[D_80168D18].v.flag = 0;
            _vertex[D_80168D18].v.cn[0] = _vertex[D_80168D18].v.cn[1] = _vertex[D_80168D18].v.cn[2] = 0xFF;
            _vertex[D_80168D18].v.cn[3] = D_8012FD8C->unk12;
            D_80168D18++;

            _vertex[D_80168D18].v.ob[0] = -D_8016A170[D_80118168.unk1C].x;
            _vertex[D_80168D18].v.ob[1] = D_8016A170[D_80118168.unk1C].y;
            _vertex[D_80168D18].v.ob[2] = D_8016A170[D_80118168.unk1C].z;
            _vertex[D_80168D18].v.tc[0] = D_80118168.unk28 << 6;
            _vertex[D_80168D18].v.tc[1] = D_80118168.unk2A << 6;
            _vertex[D_80168D18].v.flag = 0;
            _vertex[D_80168D18].v.cn[0] = _vertex[D_80168D18].v.cn[1] = _vertex[D_80168D18].v.cn[2] = 0xFF;
            _vertex[D_80168D18].v.cn[3] = D_8012FD8C->unk12;
            D_80168D18++;

            _vertex[D_80168D18].v.ob[0] = -D_8016A170[D_80118168.unk1A].x;
            _vertex[D_80168D18].v.ob[1] = D_8016A170[D_80118168.unk1A].y;
            _vertex[D_80168D18].v.ob[2] = D_8016A170[D_80118168.unk1A].z;
            _vertex[D_80168D18].v.tc[0] = D_80118168.unk24 << 6;
            _vertex[D_80168D18].v.tc[1] = D_80118168.unk26 << 6;
            _vertex[D_80168D18].v.flag = 0;
            _vertex[D_80168D18].v.cn[0] = _vertex[D_80168D18].v.cn[1] = _vertex[D_80168D18].v.cn[2] = 0xFF;
            _vertex[D_80168D18].v.cn[3] = D_8012FD8C->unk12;
            D_80168D18++;

            _vertex[D_80168D18].v.ob[0] = -D_8016A170[D_80118168.unk18].x;
            _vertex[D_80168D18].v.ob[1] = D_8016A170[D_80118168.unk18].y;
            _vertex[D_80168D18].v.ob[2] = D_8016A170[D_80118168.unk18].z;
            _vertex[D_80168D18].v.tc[0] = D_80118168.unk20 << 6;
            _vertex[D_80168D18].v.tc[1] = D_80118168.unk22 << 6;
            _vertex[D_80168D18].v.flag = 0;
            _vertex[D_80168D18].v.cn[0] = _vertex[D_80168D18].v.cn[1] = _vertex[D_80168D18].v.cn[2] = 0xFF;
            _vertex[D_80168D18].v.cn[3] = D_8012FD8C->unk12;
            D_80168D18++;
        }
    }
    else
    {
        _vertex[D_80168D18].v.ob[0] = -D_80118168.unk14[D_80118168.unk1E].x;
        _vertex[D_80168D18].v.ob[1] = D_80118168.unk14[D_80118168.unk1E].y;
        _vertex[D_80168D18].v.ob[2] = D_80118168.unk14[D_80118168.unk1E].z;
        _vertex[D_80168D18].v.tc[0] = D_80118168.unk2C << 6;
        _vertex[D_80168D18].v.tc[1] = D_80118168.unk2E << 6;
        _vertex[D_80168D18].v.flag = 0;
        _vertex[D_80168D18].v.cn[0] = _vertex[D_80168D18].v.cn[1] = _vertex[D_80168D18].v.cn[2] = 0xFF;
        _vertex[D_80168D18].v.cn[3] = D_8012FD8C->unk12;
        D_80168D18++;

        _vertex[D_80168D18].v.ob[0] = -D_80118168.unk14[D_80118168.unk1C].x;
        _vertex[D_80168D18].v.ob[1] = D_80118168.unk14[D_80118168.unk1C].y;
        _vertex[D_80168D18].v.ob[2] = D_80118168.unk14[D_80118168.unk1C].z;
        _vertex[D_80168D18].v.tc[0] = D_80118168.unk28 << 6;
        _vertex[D_80168D18].v.tc[1] = D_80118168.unk2A << 6;
        _vertex[D_80168D18].v.flag = 0;
        _vertex[D_80168D18].v.cn[0] = _vertex[D_80168D18].v.cn[1] = _vertex[D_80168D18].v.cn[2] = 0xFF;
        _vertex[D_80168D18].v.cn[3] = D_8012FD8C->unk12;
        D_80168D18++;

        _vertex[D_80168D18].v.ob[0] = -D_80118168.unk14[D_80118168.unk1A].x;
        _vertex[D_80168D18].v.ob[1] = D_80118168.unk14[D_80118168.unk1A].y;
        _vertex[D_80168D18].v.ob[2] = D_80118168.unk14[D_80118168.unk1A].z;
        _vertex[D_80168D18].v.tc[0] = D_80118168.unk24 << 6;
        _vertex[D_80168D18].v.tc[1] = D_80118168.unk26 << 6;
        _vertex[D_80168D18].v.flag = 0;
        _vertex[D_80168D18].v.cn[0] = _vertex[D_80168D18].v.cn[1] = _vertex[D_80168D18].v.cn[2] = 0xFF;
        _vertex[D_80168D18].v.cn[3] = D_8012FD8C->unk12;
        D_80168D18++;

        _vertex[D_80168D18].v.ob[0] = -D_80118168.unk14[D_80118168.unk18].x;
        _vertex[D_80168D18].v.ob[1] = D_80118168.unk14[D_80118168.unk18].y;
        _vertex[D_80168D18].v.ob[2] = D_80118168.unk14[D_80118168.unk18].z;
        _vertex[D_80168D18].v.tc[0] = D_80118168.unk20 << 6;
        _vertex[D_80168D18].v.tc[1] = D_80118168.unk22 << 6;
        _vertex[D_80168D18].v.flag = 0;
        _vertex[D_80168D18].v.cn[0] = _vertex[D_80168D18].v.cn[1] = _vertex[D_80168D18].v.cn[2] = 0xFF;
        _vertex[D_80168D18].v.cn[3] = D_8012FD8C->unk12;
        D_80168D18++;
    }

    temp = D_8012F6EC; /*FAKEMATCH?*/
    D_8012EB50[D_8011815C].unk14 = temp;
    D_8012EB50[D_8011815C].unk4 = D_80118168.unk4;
    D_8012EB50[D_8011815C].texture = D_80118168.texture;
    D_8012EB50[D_8011815C].width = D_80118168.width;
    D_8012EB50[D_8011815C].height = D_80118168.height;
    D_8012EB50[D_8011815C].palette = D_80118168.palette;
    D_8012EB50[D_8011815C].unk18 = D_80118168.unk30;
    D_8012F6EC += 4;
    D_8011815C++;
}

/*80085CDC*/
static void func_80085CDC(void)
{
    code0UnkStruct18 *ptr;
    Vtx *ptr2;

    ptr = &D_8016A170[D_80118168.unk1C];
    ptr2 = &_vertex[D_80168D18];
    ptr2->v.ob[0] = -ptr->x;
    ptr2->v.ob[1] = ptr->y;
    ptr2->v.ob[2] = ptr->z;
    ptr = &D_8016A170[D_80118168.unk1A];
    ptr2++;
    ptr2->v.ob[0] = -ptr->x;
    ptr2->v.ob[1] = ptr->y;
    ptr2->v.ob[2] = ptr->z;
    ptr = &D_8016A170[D_80118168.unk18];
    ptr2++;
    ptr2->v.ob[0] = -ptr->x;
    ptr2->v.ob[1] = ptr->y;
    ptr2->v.ob[2] = ptr->z;
    D_80168D18 += 3;
}

/*80085DB0*/
static void func_80085DB0(void)
{
    code0UnkStruct18 *ptr;
    Vtx *ptr2;

    ptr = &D_8016A170[D_80118168.unk1E];
    ptr2 = &_vertex[D_80168D18];
    ptr2->v.ob[0] = -ptr->x;
    ptr2->v.ob[1] = ptr->y;
    ptr2->v.ob[2] = ptr->z;
    ptr = &D_8016A170[D_80118168.unk1C];
    ptr2++;
    ptr2->v.ob[0] = -ptr->x;
    ptr2->v.ob[1] = ptr->y;
    ptr2->v.ob[2] = ptr->z;
    ptr = &D_8016A170[D_80118168.unk1A];
    ptr2++;
    ptr2->v.ob[0] = -ptr->x;
    ptr2->v.ob[1] = ptr->y;
    ptr2->v.ob[2] = ptr->z;
    ptr = &D_8016A170[D_80118168.unk18];
    ptr2++;
    ptr2->v.ob[0] = -ptr->x;
    ptr2->v.ob[1] = ptr->y;
    ptr2->v.ob[2] = ptr->z;
    D_80168D18 += 4;
}

/*80085EBC*/
void func_80085EBC(Vtx *vtx, s32 vtx_count, Gfx **dlist, s32 dlist_count, s32 arg4)
{
    Gfx *dlist1;

    D_8011815C = 0;
    D_8012F6EC = 0;
    _vertex = vtx;
    D_80199968 = vtx_count;
    dlist1 = *dlist;
    D_80197DD0 = dlist_count;
    D_801AE534 = 0;
    D_8012B940 = 0;
    _palette = NULL;
    _texture = NULL;
    D_80119AA0 = 0;
    D_80199108 = 0;
    _displayList = dlist1;
    D_801385F8 = dlist1;
    gSPTexture(_displayList++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
}

/*80085F50*/
static void func_80085F50(Gfx **arg0, s32 arg1)
{

    func_80083C40();
    if (D_800E0F44 != 0)
    {
        gDPPipeSync(_displayList++);
        gDPSetRenderMode(_displayList++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineMode(_displayList++, G_CC_MODULATEIA, G_CC_MODULATEIA);
        gDPSetTextureLUT(_displayList++, G_TT_RGBA16);
    }
    gSPEndDisplayList(_displayList++);
    *arg0 = _displayList;
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

    (void)pad;
    gDPPipeSync(_displayList++);

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

    gDPSetRenderMode(_displayList++, D_800E0F50, D_800E0F54);
    D_800E0F48 = 0;
    D_800E0F4C = 0;
    D_800E0F44 = 0;
    gSPClearGeometryMode(_displayList++, G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
}

/*800861F4*/
void func_800861F4(code0UnkStruct20 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4,
                   f32 arg5, s32 arg6, Vtx *vtx, s32 vtx_count, Gfx *dlist, s32 dlist_count)
{
    code0UnkStruct16 sp20;
    Gfx *dlist1;

    D_80168D18 = 0;
    D_800FE3F4 = 0;
    dlist1 = dlist;
    func_80085EBC(vtx, vtx_count, &dlist1, dlist_count, arg6);
    D_801AE534 = 0;
    D_8012B940 = 0;
    _palette = NULL;
    _texture = NULL;
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
    D_800E0F2C[0] = 32768.0f;
    D_800E0F2C[1] = -32768.0f;
    D_800E0F2C[2] = 32768.0f;
    D_800E0F2C[3] = -32768.0f;
    D_800E0F2C[4] = 32768.0f;
    D_800E0F2C[5] = -32768.0f;
    func_800860AC(arg6);
    func_80085F50(&dlist1, arg6);
    D_801AE900 = D_80168D18;
    D_80129800 = _displayList - dlist;

    if (D_800E0F20 < D_80168D18)
        D_800E0F20 = D_80168D18;

    if (D_800E0F24 < D_80129800)
        D_800E0F24 = D_80129800;
}
