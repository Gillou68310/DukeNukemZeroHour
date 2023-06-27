#include "common.h"
#include "code0/main.h"
#include "code0/graphics.h"
#include "code0/9410.h"
#include "code0/41940.h"
#include "code0/code0.h"

typedef struct {
    /*0x00*/ u8 unk0;
    /*0x02*/ u16 unk2;
    /*0x04*/ s32 unk4;
    /*0x08*/ s32 unk8;
    /*0x0C*/ s32 unkC;
    /*0x10*/ s32 unk10;
    /*0x14*/ s32 unk14;
    /*0x18*/ s32 unk18;
    /*0x1C*/ s32 unk1C;
    /*0x20*/ s32 unk20;
    /*0x24*/ s32 unk24;
    /*0x28*/ s32 unk28;
    /*0x2C*/ s32 unk2C;
} _8EFE0UnkStruct1;

/*.comm*/
/*80106730*/ _8EFE0UnkStruct1 D_80106730[32] ALIGNED(16);
/*80139870*/ s32 D_80139870;

/*.text*/

/*8008E3E0*/
INCLUDE_ASM("nonmatchings/src/code0/8EFE0", func_8008E3E0);

/*8008FE88*/
INCLUDE_ASM("nonmatchings/src/code0/8EFE0", func_8008FE88);

/*80093450*/
static s16 func_80093450(s32 x, s32 y, s32 z, s32 sectnum, s32 *arg4)
{
    _8EFE0UnkStruct1 *ptr;
    s32 i, j, spritenum;

    ptr = D_80106730;
    for (i = 0; i < ARRAY_COUNT(D_80106730); i++, ptr++)
    {
        if (!ptr->unk0)
        {
            spritenum = func_80058934(x, y, z, sectnum, 300);
            if (spritenum != -1)
            {
                for (j = 0, ptr->unk0 = 1; j < 3; j++)
                {
                    ((s32 *)ptr)[j+1] = (arg4[j] - x);
                    ((s32 *)ptr)[j+4] = (arg4[j+3] - y);
                    ((s32 *)ptr)[j+7] = (arg4[j+6] - z);
                }
                ptr->unk2 = 100;
                gpSprite[spritenum].unk22 = i;
                gpSprite[spritenum].unk18 = ((krand() & 0x7F) * gpSinTable[D_80139870]) >> 14;
                gpSprite[spritenum].unk1A = ((krand() & 0x7F) * gpSinTable[(D_80139870 + 512) & 0x7FF]) >> 14;
                ptr->unk28 = (krand() & 0x3F) - 0x20;
                ptr->unk2C = (krand() & 0x3F) - 0x20;
                gpSprite[spritenum].unk1C = 0;
                gpSprite[spritenum].ang = 0;
                gpSprite[spritenum].cstat = -0x8000;
                D_8013B2D0[spritenum].unk0 = 0;
                return spritenum;
            }
            break;
        }
    }
    return -1;
}

/*80093670*/
INCLUDE_ASM("nonmatchings/src/code0/8EFE0", func_80093670);

/*80093BB0*/
INCLUDE_ASM("nonmatchings/src/code0/8EFE0", func_80093BB0);

/*80094278*/
void func_80094278(void)
{
    _8EFE0UnkStruct1 *ptr;
    s32 i;

    gSPClearGeometryMode(gpDisplayList++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                                          G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gSPSetGeometryMode(gpDisplayList++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH);
    gDPSetRenderMode(gpDisplayList++, G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2);
    gDPSetTextureLUT(gpDisplayList++, G_TT_NONE);
    gDPSetCombineMode(gpDisplayList++, G_CC_PRIMITIVE, G_CC_PASS2);
    gDPSetPrimColor(gpDisplayList++, 0, 0, 0x00, 0x00, 0x00, 0x80);

    i = gHeadSpriteStat[300];
    while (i >= 0)
    {
        func_8000C76C();
        if (D_801A6D80 < ARRAY_COUNT(gpDynamic->mtx3))
        {
            grPosition(&gpDynamic->mtx3[D_801A6D80+1],
                       0.0f,
                       (D_8013B2D0[i].unk0 * 0.17578125),
                       (gpSprite[i].ang * 0.17578125),
                       0.5,
                       (gpSprite[i].x / 4),
                       (gpSprite[i].y / 4),
                       (gpSprite[i].z / 4.0));

            gSPMatrix(gpDisplayList++, OS_K0_TO_PHYSICAL(&gpDynamic->mtx3[D_801A6D80+1]),
                                       G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

            D_801A6D80++;
            ptr = &D_80106730[gpSprite[i].unk22];

            gpVertexN64->v.ob[0] = (ptr->unk4 >> 1);
            gpVertexN64->v.ob[1] = (ptr->unk10 >> 1);
            gpVertexN64->v.ob[2] = (ptr->unk1C >> 1);
            gpVertexN64->v.tc[0] = 0;
            gpVertexN64->v.tc[1] = 0;
            gpVertexN64->v.cn[0] = 0xFF;
            gpVertexN64->v.cn[1] = 0xFF;
            gpVertexN64->v.cn[2] = 0xFF;
            gpVertexN64->v.cn[3] = 0xFF;
            gpVertexN64++;
            gpVertexN64->v.ob[0] = (ptr->unk8 >> 1);
            gpVertexN64->v.ob[1] = (ptr->unk14 >> 1);
            gpVertexN64->v.ob[2] = (ptr->unk20 >> 1);
            gpVertexN64->v.tc[0] = 0x800;
            gpVertexN64->v.tc[1] = 0;
            gpVertexN64->v.cn[0] = 0xFF;
            gpVertexN64->v.cn[1] = 0xFF;
            gpVertexN64->v.cn[2] = 0xFF;
            gpVertexN64->v.cn[3] = 0xFF;
            gpVertexN64++;
            gpVertexN64->v.ob[0] = (ptr->unkC >> 1);
            gpVertexN64->v.ob[1] = (ptr->unk18 >> 1);
            gpVertexN64->v.ob[2] = (ptr->unk24 >> 1);
            gpVertexN64->v.tc[0] = 0x800;
            gpVertexN64->v.tc[1] = 0x800;
            gpVertexN64->v.cn[0] = 0xFF;
            gpVertexN64->v.cn[1] = 0xFF;
            gpVertexN64->v.cn[2] = 0xFF;
            gpVertexN64->v.cn[3] = 0xFF;
            gpVertexN64++;
            func_8000B570(1);

            gSPPopMatrix(gpDisplayList++, G_MTX_MODELVIEW);
            i = gNextSpriteStat[i];
        }
        else
            break;
    }
}

/*800946B8*/
void func_800946B8(void)
{
    s16 sectnum;
    s32 i, nexti;
    SpriteType *spr;

    i = gHeadSpriteStat[300];
    while (i >= 0)
    {
        nexti = gNextSpriteStat[i];
        spr = &gpSprite[i];
        spr->x += spr->unk18 >> 3;
        spr->y += spr->unk1A >> 3;
        spr->z += spr->unk1C;
        sectnum = spr->sectnum;

        if (sectnum == -1)
        {
            D_80106730[gpSprite[i].unk22].unk0 = 0;
            deleteSprite(i);
        }
        else if ((getFlorzOfSlope(sectnum, spr->x, spr->y) >> 4) < spr->z)
        {
            D_80106730[gpSprite[i].unk22].unk0 = 0;
            deleteSprite(i);
        }
        else
        {
            if ((D_80106730[gpSprite[i].unk22].unk2 != 0) &&
                (D_80106730[gpSprite[i].unk22].unk2--, D_80106730[gpSprite[i].unk22].unk2) == 0)
            {
                D_80106730[gpSprite[i].unk22].unk0 = 0;
                deleteSprite(i);
            }
            else
            {
                spr->unk1C += 8;
                spr->ang = (spr->ang + D_80106730[gpSprite[i].unk22].unk28) & 0x7FF;
                D_8013B2D0[i].unk0 = (D_8013B2D0[i].unk0 + D_80106730[gpSprite[i].unk22].unk2C) & 0x7FF;
            }
        }
        i = nexti;
    }
}
