#include "common.h"
#include "code0/main.h"
#include "code0/graphics.h"
#include "code0/4600.h"
#include "code0/9410.h"
#include "code0/audio.h"
#include "code0/pragmas.h"
#include "code0/17B30.h"
#include "code0/37090.h"
#include "code0/41940.h"
#include "code0/6ACA0.h"
#include "code0/8E670.h"
#include "code0/8EFE0.h"
#include "code0/A06F0.h"
#include "code0/code0.h"
#include "code1/EB300.h"
#include "static/mapinfo.h"

typedef struct {
    u8 unk0;
    s32 unk4; /*x*/
    s32 unk8; /*y*/
    s32 unkC; /*z*/
    s16 unk10;
    s16 unk12;
}_95500UnkStruct1;

/*.data*/
/*800E1770*/ EXTERN_DATA STATIC s32 D_800E1770;
/*800E1780*/ EXTERN_DATA STATIC char *D_800E1780[8];
/*800E17A0*/ EXTERN_DATA STATIC char *D_800E17A0[8];
/*800E17C0*/ EXTERN_DATA STATIC char *D_800E17C0[8];
/*800E17E0*/ EXTERN_DATA u16 D_800E17E0[8];

/*.comm*/
/*80118250*/ s32 D_80118250;
/*80119A34*/ s32 D_80119A34;
/*8011A66C*/ s32 D_8011A66C;
/*8012FC94*/ s32 D_8012FC94;
/*8012FCAC*/ s32 D_8012FCAC;
/*8012FD74*/ s32 D_8012FD74;
/*8019910C*/ s32 D_8019910C;
/*80199564*/ s32 D_80199564;
/*8019964C*/ s32 D_8019964C;
/*80199948*/ s32 D_80199948;
/*80199964*/ s32 D_80199964;
/*801B081C*/ s32 D_801B081C;
/*801A19E8*/ s32 D_801A19E8; /*florhit*/
/*801AC594*/ s32 D_801AC594;
/*801ACBE0*/ s32 D_801ACBE0;
/*801AE8F8*/ s32 D_801AE8F8;
/*801AE9C4*/ s32 D_801AE9C4;
/*801AEE40*/ _95500UnkStruct1 D_801AEE40[200] ALIGNED(16);

INCLUDE_RODATA("nonmatchings/src/code0/95500", D_800E9B60);
INCLUDE_RODATA("nonmatchings/src/code0/95500", D_800E9B6C);
INCLUDE_RODATA("nonmatchings/src/code0/95500", D_800E9B78);
INCLUDE_RODATA("nonmatchings/src/code0/95500", D_800E9B88);
INCLUDE_RODATA("nonmatchings/src/code0/95500", D_800E9B90);
INCLUDE_RODATA("nonmatchings/src/code0/95500", D_800E9BA4);
INCLUDE_RODATA("nonmatchings/src/code0/95500", D_800E9BB0);
INCLUDE_RODATA("nonmatchings/src/code0/95500", D_800E9BBC);
INCLUDE_RODATA("nonmatchings/src/code0/95500", D_800E9BC4);
INCLUDE_RODATA("nonmatchings/src/code0/95500", D_800E9BD4);
INCLUDE_RODATA("nonmatchings/src/code0/95500", D_800E9BE4);
INCLUDE_RODATA("nonmatchings/src/code0/95500", D_800E9BF0);
INCLUDE_RODATA("nonmatchings/src/code0/95500", D_800E9BF8);
INCLUDE_RODATA("nonmatchings/src/code0/95500", D_800E9BFC);

/*.text*/

/*80094900*/
static _95500UnkStruct1 *func_80094900(s32 x, s32 y, s32 z, s16 arg3)
{
    _95500UnkStruct1 *ptr;
    s32 i;

    ptr = D_801AEE40;
    for (i = 0; i < ARRAY_COUNT(D_801AEE40); i++, ptr++)
    {
        if (ptr->unk0 == 0)
        {
            ptr->unk0 = 1;
            ptr->unk4 = x;
            ptr->unk8 = y;
            ptr->unkC = z;
            ptr->unk12 = arg3;
            return ptr;
        }
    }
    return NULL;
}

/*80094958*/
void func_80094958(void)
{
    _95500UnkStruct1 *ptr;
    s32 i;

    ptr = D_801AEE40;
    for (i = 0; i < ARRAY_COUNT(D_801AEE40); i++, ptr++)
        ptr->unk0 = 0;

    D_800E1770 = 0;
}

/*80094984*/
static void func_80094984(void)
{
    s32 x, y, z;
    u16 unk32;

    z = gPlayer[0].zpos;
    x = gPlayer[0].xpos;
    y = gPlayer[0].ypos;
    unk32 = gPlayer[0].unk32;

    x += (((krand() & 0x3FF) - 512) * 10);
    y += (((krand() & 0x3FF) - 512) * 10);
    z -= 0x3900;
    z -= ((krand() & 0x1FFF) * 10);

    if (func_80094900(x, y, z, unk32) != NULL)
        D_800E1770++;
}

/*80094A60*/
void func_80094A60(void)
{
    _95500UnkStruct1 *ptr;
    s32 i;

    gSPClearGeometryMode(gpDisplayList++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING |
                                          G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR |
                                          G_LOD | G_SHADING_SMOOTH);

    gSPSetGeometryMode(gpDisplayList++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH);
    gDPSetRenderMode(gpDisplayList++, G_RM_ZB_XLU_SURF, G_RM_ZB_XLU_SURF2);
    gDPSetTextureLUT(gpDisplayList++, G_TT_NONE);
    func_8000C76C();
    func_8000BDB0(5769);

    gDPSetPrimColor(gpDisplayList++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    gDPSetEnvColor(gpDisplayList++, 0x80, 0x80, 0xB4, 0x00);
    gDPSetCombineLERP(gpDisplayList++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0,
                                       0, PRIMITIVE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED);

    ptr = D_801AEE40;
    for (i = 0; i < ARRAY_COUNT(D_801AEE40); i++, ptr++)
    {
        if (ptr->unk0 != 0)
        {
            gpVertexN64->v.ob[0] = (ptr->unk4 / 2);
            gpVertexN64->v.ob[1] = (ptr->unk8 / 2) - 20;
            gpVertexN64->v.ob[2] = (ptr->unkC / 32) + 20;
            gpVertexN64->v.tc[0] = 1536;
            gpVertexN64->v.tc[1] = 1984;
            gpVertexN64++;

            gpVertexN64->v.ob[0] = (ptr->unk4 / 2);
            gpVertexN64->v.ob[1] = ((ptr->unk8 / 2) + 20);
            gpVertexN64->v.ob[2] = ((ptr->unkC / 32) - 20);
            gpVertexN64->v.tc[0] = 512;
            gpVertexN64->v.tc[1] = 1984;
            gpVertexN64++;

            gpVertexN64->v.ob[0] = (ptr->unk4 / 2);
            gpVertexN64->v.ob[1] = ((ptr->unk8 / 2) -140);
            gpVertexN64->v.ob[2] = ((ptr->unkC / 32) - 140);
            gpVertexN64->v.tc[0] = 960;
            gpVertexN64->v.tc[1] = 0;
            gpVertexN64++;

            gSPVertex(gpDisplayList++, D_80199114, 3, 0);
            D_80199114 += 3;
            gSP1Triangle(gpDisplayList++, 0, 1, 2, 0);
        }
    }
}

/*80094D18*/
void func_80094D18(void)
{
    _95500UnkStruct1 *ptr;
    s32 i, j, z;

    ptr = D_801AEE40;

    for (i = 0; i < ARRAY_COUNT(D_801AEE40); i++, ptr++)
    {
        if (ptr->unk0 != 0)
        {
            ptr->unk8 += ARRAY_COUNT(D_801AEE40);
            ptr->unkC += ARRAY_COUNT(D_801AEE40) * 16;
            if (ptr->unk12 != -1)
            {
                z = getFlorzOfSlope(ptr->unk12, ptr->unk4, ptr->unk8);
                if (ptr->unkC >= z)
                {
                    if ((krand() & 0x7FFF) < 800)
                        func_8008E3E0(ptr->unk4, ptr->unk8, (z - 512), ptr->unk12, 28, 0);

                    ptr->unk0 = 0;
                    D_800E1770--;
                }
            }
            else
            {
                ptr->unk0 = 0;
                D_800E1770--;
            }
        }
    }

    j = MIN(ARRAY_COUNT(D_801AEE40) - D_800E1770, 20);
    if ((j > 0) && (gpSector[gPlayer[0].unk32].ceilingstat & 1))
    {
        for (i = 0; i < j; i++)
            func_80094984();
    }
}

/*80094E98*/
static void func_80094E98(void)
{
    s32 x, y, z;
    u16 unk32;
    _95500UnkStruct1 *ptr;

    z = gPlayer[0].zpos;
    x = gPlayer[0].xpos;
    y = gPlayer[0].ypos;
    unk32 = gPlayer[0].unk32;

    x += (((krand() & 0x3FF) - 512) * 10);
    y += (((krand() & 0x3FF) - 512) * 10);
    z -= 0x3900;
    z -= ((krand() & 0x1FFF) * 10);

    ptr = func_80094900(x, y, z, unk32);
    if (ptr != NULL)
    {
        ptr->unk10 = 0;
        D_800E1770++;
    }
}

/*80094F7C*/
void func_80094F7C(void)
{
    _95500UnkStruct1 *ptr;
    s32 i;

    gSPClearGeometryMode(gpDisplayList++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING |
                                          G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR |
                                          G_LOD | G_SHADING_SMOOTH);

    gSPSetGeometryMode(gpDisplayList++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH);
    gDPSetRenderMode(gpDisplayList++, G_RM_ZB_XLU_SURF, G_RM_ZB_XLU_SURF2);
    gDPSetTextureLUT(gpDisplayList++, G_TT_NONE);
    func_8000C76C();
    func_8000BDB0(5972);

    gDPSetPrimColor(gpDisplayList++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    gDPSetEnvColor(gpDisplayList++, 0x00, 0x00, 0x00, 0x00);
    gDPSetCombineLERP(gpDisplayList++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0,
                                       0, PRIMITIVE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED);

    ptr = D_801AEE40;
    for (i = 0; i < ARRAY_COUNT(D_801AEE40); i++, ptr++)
    {
        if (ptr->unk0 != 0)
        {
            gpVertexN64->v.ob[0] = (ptr->unk4 / 2);
            gpVertexN64->v.ob[1] = (ptr->unk8 / 2) - 40;
            gpVertexN64->v.ob[2] = (ptr->unkC / 32) + 40;
            gpVertexN64->v.tc[0] = 1984;
            gpVertexN64->v.tc[1] = 1984;
            gpVertexN64++;

            gpVertexN64->v.ob[0] = (ptr->unk4 / 2);
            gpVertexN64->v.ob[1] = ((ptr->unk8 / 2) + 40);
            gpVertexN64->v.ob[2] = ((ptr->unkC / 32) + 40);
            gpVertexN64->v.tc[0] = 0;
            gpVertexN64->v.tc[1] = 1984;
            gpVertexN64++;

            gpVertexN64->v.ob[0] = (ptr->unk4 / 2);
            gpVertexN64->v.ob[1] = (ptr->unk8 / 2);
            gpVertexN64->v.ob[2] = ((ptr->unkC / 32) - 40);
            gpVertexN64->v.tc[0] = 960;
            gpVertexN64->v.tc[1] = 0;
            gpVertexN64++;

            gSPVertex(gpDisplayList++, D_80199114, 3, 0);
            D_80199114 += 3;
            gSP1Triangle(gpDisplayList++, 0, 1, 2, 0);
        }
    }
}

/*80095220*/
void func_80095220(void)
{
    _95500UnkStruct1 *ptr;
    s32 i, j;

    ptr = D_801AEE40;
    for (i = 0; i < ARRAY_COUNT(D_801AEE40); i++, ptr++)
    {
        if (ptr->unk0 != 0)
        {
            ptr->unk8 += ptr->unk10;
            ptr->unkC += 720;
            ptr->unk10 += (gpSinTable[ptr->unkC & 0x7FF] * 25) >> 16;

            if ((ptr->unk12 == -1) || (ptr->unkC >= getFlorzOfSlope(ptr->unk12, ptr->unk4, ptr->unk8)))
            {
                ptr->unk0 = 0;
                D_800E1770--;
            }
        }
    }

    j = MIN((ARRAY_COUNT(D_801AEE40) - D_800E1770), 20);
    if ((j > 0) && (gpSector[gPlayer[0].unk32].ceilingstat & 1))
    {
        for (i = 0; i < j; i++)
            func_80094E98();
    }
}

/*80095390*/
void func_80095390(s16 playernum)
{
    Bmemset(&D_8010A940[playernum], 0, sizeof(code0UnkStruct2));
    if (D_8012C470 == 1)
    {
        D_8010A940[playernum].unk0 = 7;
        D_8010A940[playernum].unkA[7] = 0x1000;
    }
    else
        D_8010A940[playernum].unk0 = -1;
}

/*8009542C*/
void func_8009542C(void)
{
    char sp10[32];
    code0UnkStruct2 *ptr2;
    s16 i;
    char **ptr;
    u8 unk2;

    if ((D_801CA14C[gMapNum].unk0 == 2) || (D_801CA14C[gMapNum].unk0 == 3))
        ptr = D_800E17A0;
    else
        ptr = D_800E1780;

    for (i = 0; i < D_8012C470; i++)
    {
        ptr2 = &D_8010A940[i];

        if (D_8012F6E4[gPlayer[i].unk4C].unkB == 5)
        {
            ptr2->unk2[5] = 0;
            ptr2->unk2[6] = 0;
        }

        unk2 = ptr2->unk2[1];
        ptr2->unkA[0] = D_8019B940[D_80106D50[gPlayer[i].unk4A]].unk7E;
        ptr2->unk2[1] = 0;

        if ((gPlayer[i].unk54 != 0) && (ptr2->unkA[1] > 0))
        {
            ptr2->unk2[1] = 1;
            ptr2->unkA[1]--;
        }

        if (ptr2->unk2[1] != unk2)
        {
            if (ptr2->unk2[1] != 0)
            {
                ptr2->unk0 = 1;
                sprintf(sp10, "%s ON", ptr[1]);
            }
            else
                sprintf(sp10, "%s OFF", ptr[1]);

            func_800A419C(i, sp10);

        }
        if (ptr2->unk2[2] != 0)
            ptr2->unkA[2]--;

        if (ptr2->unkA[2] <= 0)
            ptr2->unk2[2] = 0;

        if (ptr2->unk2[5] != 0)
        {
            ptr2->unkA[5]--;
            if (ptr2->unkA[5] <= 0)
            {
                ptr2->unk2[5] = 0;
                sprintf(sp10, "%s OFF", ptr[5]);
                func_800A419C(i, sp10);
            }
        }

        if (gPlayer[i].unk52 != -1)
            ptr2->unk2[5] = 0;

        if (ptr2->unk2[6] != 0)
        {
            ptr2->unkA[6]--;
            if (ptr2->unkA[6] <= 0)
            {
                ptr2->unk2[6] = 0;
                sprintf(sp10, "%s OFF", ptr[6]);
                func_800A419C(i, sp10);
            }
        }
        if (D_8012C470 == 1)
        {
            if (ptr2->unk0 != 7)
            {
                ptr2->unk2[7] = 0;
                ptr2->unkA[7] = 4096;
            }

            if (ptr2->unk2[7] != 0)
                ptr2->unkA[7] = MIN(24576, (ptr2->unkA[7] * 1.2));
            else
                ptr2->unkA[7] = MAX(4096, (ptr2->unkA[7] / 1.2));
        }

        if (ptr2->unk0 >= 0)
        {
            if (ptr2->unkA[ptr2->unk0] == 0)
                ptr2->unk0 = func_8003B31C(i, 1);
        }
        if (D_8012F6E4[gPlayer[i].unk4C].unkB == 5)
        {
            ptr2->unk2[5] = 1;
            ptr2->unk2[6] = 1;
        }
    }
}

/*8009584C*/
void func_8009584C(s16 playernum)
{
    char buffer[32];
    char **ptr;
    code0UnkStruct2 *ptr1;
    code0UnkStruct3 *ptr2;
    s16 unk0, min;
    s8 cond;

    cond = -1;
    ptr = D_800E1780;
    ptr1 = &D_8010A940[playernum];
    ptr2 = &D_8019B940[D_80106D50[gPlayer[playernum].unk4A]];

    if ((D_801CA14C[gMapNum].unk0 - 2U) < 2U)
        ptr = D_800E17A0;

    unk0 = ptr1->unk0 - 2;
    switch (unk0)
    {
    case 0:
        if (ptr1->unkA[2] > 0)
        {
            if (ptr1->unk2[2] == 0)
            {
                ptr1->unk2[2] = 1;
                cond = 1;
                audio_800080E0(playernum, 7);
            }
        }
        else
            ptr1->unk2[2] = 0;

        break;
    case 3:
        if (ptr1->unkA[5] > 0)
        {
            cond = ptr1->unk2[5] == 0;
            ptr1->unk2[5] = cond;
        }
        else
            ptr1->unk2[5] = 0;

        if (ptr1->unk2[5] != 0)
            playSfx(1321);
        else
            playSfx(1322);
        break;
    case 4:
        if (ptr1->unkA[6] > 0)
        {
            cond = ptr1->unk2[6] == 0;
            ptr1->unk2[6] = cond;
        }
        else
            ptr1->unk2[6] = 0;

        break;
    case 2:
        if (ptr1->unkA[4] > 0)
        {
            if (ptr2->unk8 < gPlayer[playernum].unk48)
            {
                min = MIN(ptr1->unkA[4], (gPlayer[playernum].unk48 - ptr2->unk8));
                ptr2->unk8 += min;
                ptr1->unkA[4] -= min;
                cond = 1;
                audio_800080E0(playernum, 5);
            }
        }
        break;
    case 5:
        ptr1->unk2[7] = ptr1->unk2[7] == 0;
        if (ptr1->unk2[7])
        {
            D_8012C989 = 0;
            playSfx(1433);
        }
        else
            playSfx(1432);

        break;
    }

    if (cond != -1)
    {
        if (cond != 0)
            sprintf(buffer, "%s %s", ptr[ptr1->unk0], D_800E17C0[ptr1->unk0]);
        else
            sprintf(buffer, "%s OFF", ptr[ptr1->unk0]);

        func_800A419C(playernum, buffer);
    }
}

/*80095B20*/
static void func_80095B20(s32 spritenum, s32 arg1, f32 x, f32 y, f32 z, s32 arg5)
{
    SpriteType *spr;
    code0UnkStruct5 *ptr;
    f32 ox, oy, oz;
    f32 f1, f2, f3, f4;
    s32 spritenum_;
    u16 cstat;
    s32 i;

    f32 mf5[4][4];
    f32 mf2[4][4];
    f32 mf1[4][4];
    f32 mf3[4][4];
    f32 mf4[4][4];

    ptr = &D_8013B2D0[spritenum];
    f1 = ((ptr->unk2 * 180) / 1024.0);
    f2 = ((ptr->unk0 * 180) / 1024.0);
    f3 = ((ptr->unk4 * 180) / 1024.0);
    f4 = (((gpSprite[spritenum].ang * 180) / 1024.0) + 90.0);
    guRotateRPYF(mf1, f1, 0.0f, 0.0f);
    guRotateRPYF(mf2, 0.0f, f2, 0.0f);
    guRotateRPYF(mf3, 0.0f, 0.0f, f4);
    guRotateRPYF(mf4, 0.0f, 0.0f, -f3);
    grMtxCatF(mf4, mf1, mf5);
    grMtxCatF(mf5, mf2, mf5);
    grMtxCatF(mf5, mf3, mf5);
    grMtxXFMF(mf5, x, y, z, &ox, &oy, &oz);
    spr = &gpSprite[spritenum];
    ox = (ox * (spr->xrepeat / 64.0));
    oy = (oy * (spr->xrepeat / 64.0));
    oz = (oz * (spr->xrepeat / 64.0));
    cstat = spr->cstat;
    spr->cstat = cstat & 0xFEFE;

    spritenum_ = func_8004BC64(spr->x - ((s32)ox * 4), spr->y - ((s32)oy * 4), spr->z + ((s32)oz * 64), spr->sectnum, 32123, 0, 0);
    if (spritenum_ >= 0)
    {
        gpSprite[spritenum_].ang = (gpSprite[spritenum].ang + arg5) & 0x7FF;
        D_8013B2D0[spritenum_].unk4 = D_8013B2D0[spritenum].unk4;
        i = func_8006D3B8(spritenum_, arg1, 0, 0, 0);
        if (i != -1)
        {
            D_8013B2D0[i].unk2 = D_8013B2D0[spritenum].unk2;
            func_8004BD24(spritenum_);
        }
    }
    spr->cstat = cstat;
}

/*80095F58*/
static s32 func_80095F58(s32 arg0, s32 arg1)
{
    s32 i;

    i = gHeadSpriteStat[7];
    while (i >= 0)
    {
        if (gpSprite[i].unk1E == arg0)
        {
            if (gpSprite[i].unk20 == arg1)
                return i;
        }
        i = gNextSpriteStat[i];
    }
    return -1;
}

/*80095FCC*/
static s32 func_80095FCC(s32 ang1, s32 ang2, s32 arg2)
{
    return (((ang1 << 16) + (getAngleDelta(ang1, ang2) << (arg2 + 8))) >> 16) & 0x7FF;
}

/*80096028*/
static s32 func_80096028(s32 spritenum)
{
    s32 i;

    i = gHeadSpriteStat[1];
    while (i >= 0)
    {
        if (gpSprite[i].picnum >= 49)
        {
            if (func_80040D40(gpSprite[i].x,
                gpSprite[i].y,
                gpSprite[spritenum].x,
                gpSprite[spritenum].y) >= 4001)
            {
                if (canSee(gpSprite[i].x,
                    gpSprite[i].y,
                    gpSprite[i].z - 0x3900,
                    gpSprite[i].sectnum,
                    gpSprite[spritenum].x,
                    gpSprite[spritenum].y,
                    gpSprite[spritenum].z - 0x3900,
                    gpSprite[spritenum].sectnum) != 0)
                {
                    return i;
                }
            }
        }
        i = gNextSpriteStat[i];
    }
    return -1;
}

/*8009614C*/
static s32 func_8009614C(s32 spritenum)
{
    s32 i;

    i = gHeadSpriteStat[1];
    while (i >= 0)
    {
        if (gpSprite[i].picnum != 1442 && gpSprite[i].picnum >= 49)
        {
            if (canSee(gpSprite[i].x,
                gpSprite[i].y,
                gpSprite[i].z - 0x3900,
                gpSprite[i].sectnum,
                gpSprite[spritenum].x,
                gpSprite[spritenum].y,
                gpSprite[spritenum].z - 0x3900,
                gpSprite[spritenum].sectnum) != 0)
            {
                return i;
            }
        }
        i = gNextSpriteStat[i];
    }
    return -1;
}

/*80096240*/
static s32 func_80096240(SpriteType *spr)
{
    s32 ceilz, ceilhit, florz;
    u16 cstat;

    cstat = spr->cstat;
    spr->cstat = cstat & 0xFEFE;
    getzRange(spr->x,
              spr->y,
              spr->z,
              spr->sectnum,
              &ceilz,
              &ceilhit,
              &florz,
              &D_801A19E8, 64, 0x10001);
    spr->cstat = cstat;
    return florz;
}

/*800962D0*/
static s32 func_800962D0(SpriteType *spr, s32 walldist)
{
    s32 ceilz, ceilhit, florz;
    u16 cstat;

    cstat = spr->cstat;
    spr->cstat = cstat & 0xFEFE;
    getzRange(spr->x,
              spr->y,
              spr->z,
              spr->sectnum,
              &ceilz,
              &ceilhit,
              &florz,
              &D_801A19E8, walldist, 0x10001);
    spr->cstat = cstat;
    return florz;
}

/*8009635C*/
static s32 func_8009635C(s32 spritenum, s32 arg1, s32 arg2)
{
    SpriteType *spr;
    s32 z;

    spr = &gpSprite[spritenum];
    if (func_80040D40(spr->x, spr->y, gPlayer[0].xpos, gPlayer[0].ypos) < arg2)
    {
        z = klabs(spr->z - gPlayer[0].zpos);
        if (z < arg1)
        {
            if (gMapNum != MAP_PROBING_THE_DEPTHS)
            {
                func_800365C0(0);
            }
            else if (gPlayer[0].unk45 == 0)
            {
                playSfx((krand() % 3) + 538);
                func_8003671C(0, 500, -1, -1);
            }
            return 1;
        }
    }
    return 0;
}

/*80096494*/
static void func_80096494(s32 spritenum, s32 arg1, s32 arg2)
{
    SpriteType *spr2;
    SpriteType *spr1;
    s32 i, nexti;
    s32 z;

    if (func_8009635C(spritenum, arg1, arg2) == 0)
    {
        i = gHeadSpriteStat[1];
        spr1 = &gpSprite[spritenum];
        while (i >= 0)
        {
            spr2 = &gpSprite[i];
            nexti = gNextSpriteStat[i];
            if (func_80040D40(spr1->x, spr1->y, spr2->x, spr2->y) < arg2)
            {
                z = klabs(spr1->z-spr2->z);
                if (z < arg1)
                {
                    playSfx((krand() % 3) + 538);
                    func_80055EC0(i, 0);
                }
            }
            i = nexti;
        }
    }
}

/*800965F8*/
INCLUDE_ASM("nonmatchings/src/code0/95500", func_800965F8);

/*8009A020*/
static s32 func_8009A020(s16 spritenum1, s16 spritenum2)
{
    SpriteType *spr1;
    SpriteType *spr2;
    s16 hitsect, hitwall, hitsprite;
    s32 hitx, hity, hitz;
    s16 statnum;

    spr1 = &gpSprite[spritenum1];
    spr2 = &gpSprite[spritenum2];
    hitScan(spr1->x,
            spr1->y,
            spr1->z,
            spr1->sectnum,
            (spr2->x - spr1->x) / 4,
            (spr2->y - spr1->y) / 4,
            (spr2->z - spr1->z) / 4,
            &hitsect,
            &hitwall,
            &hitsprite,
            &hitx,
            &hity,
            &hitz,
            0x10001);

    if ((hitwall != -1) || (hitsprite == -1))
        return 0;

    statnum = gpSprite[hitsprite].statnum;
    if ((statnum == 1) || (statnum == 51) || (statnum == 52) || (statnum == 10))
        return hitsprite;
    return 0;
}

/*8009A1A0*/
INCLUDE_ASM("nonmatchings/src/code0/95500", func_8009A1A0);

/*8009A43C*/
void func_8009A43C(s32 spritenum)
{
    SpriteType *spr;
    code0UnkStruct3 *ptr;
    s32 i;
    s32 spritenum1, spritenum2, spritenum3;

    ptr = &D_8019B940[D_80106D50[spritenum]];
    spr = &gpSprite[spritenum];
    if (spr->unk22 != 123)
    {
        ptr->unk84 = -1;
        spr->unk22 = 123;
        D_801A1958.enemies_killed++;
        if (D_80118250 != 0)
        {
            ptr->unk68 |= 0x1C0000;
            spritenum1 = func_8008E3E0(spr->x, spr->y, spr->z - 2048, spr->sectnum, 41, 32);
            if (spritenum1 != -1)
            {
                gpSprite[spritenum1].x += (gpSinTable[(spr->ang + 768) & 0x7FF] * 375) >> 12;
                gpSprite[spritenum1].y += (gpSinTable[(spr->ang + 256) & 0x7FF] * 375) >> 12;
            }
            func_8008E3E0(gpSprite[spritenum1].x, gpSprite[spritenum1].y, gpSprite[spritenum1].z, spr->sectnum, 41, 32);
            audio_80007A44(1413, spritenum1, 40000);
            func_8008E3E0(gpSprite[spritenum1].x, gpSprite[spritenum1].y, gpSprite[spritenum1].z, spr->sectnum, 60, 2);
            func_8008E3E0(gpSprite[spritenum1].x, gpSprite[spritenum1].y, gpSprite[spritenum1].z, spr->sectnum, 60, 3);
        }

        if (D_801AE9C4 != 0)
        {
            ptr->unk68 |= 0x38000;
            spritenum2 = func_8008E3E0(spr->x, spr->y, spr->z - 2048, spr->sectnum, 41, 32);
            if (spritenum2 != -1)
            {
                gpSprite[spritenum2].x += (gpSinTable[(spr->ang + 256) & 0x7FF] * 375) >> 12;
                gpSprite[spritenum2].y += (gpSinTable[(spr->ang - 256) & 0x7FF] * 375) >> 12;
            }
            func_8008E3E0(gpSprite[spritenum2].x, gpSprite[spritenum2].y, gpSprite[spritenum2].z, spr->sectnum, 41, 32);
            audio_80007A44(1413, spritenum2, 40000);
            func_8008E3E0(gpSprite[spritenum2].x, gpSprite[spritenum2].y, gpSprite[spritenum2].z, spr->sectnum, 60, 0);
            func_8008E3E0(gpSprite[spritenum2].x, gpSprite[spritenum2].y, gpSprite[spritenum2].z, spr->sectnum, 60, 1);
        }

        func_80042124(ptr, 153);
        if (ptr->unk70 != 0)
        {
            MusHandleStop(ptr->unk70, 0);
            ptr->unk70 = 0;
        }

        i = gHeadSpriteStat[302];
        while (i >= 0)
        {
            if (gpSprite[i].picnum == 42)
            {
                audio_80007A44(1582, spritenum, 32768);
                func_8008E3E0(gpSprite[i].x, gpSprite[i].y, gpSprite[i].z - 24000, gpSprite[i].sectnum, 52, 32);
                spritenum3 = func_80058934(gpSprite[i].x, gpSprite[i].y, gpSprite[i].z, gpSprite[i].sectnum, 105);
                gpSprite[spritenum3].unk20 = 3000;
                gpSprite[spritenum3].unk1E = 1;
                gpSprite[spritenum3].picnum = 3;
                gpSprite[spritenum3].ang = 0;
                gpSprite[spritenum3].unk24 = 0;
                gpSprite[spritenum3].unk25 = 0;
                func_8004BD24(i);
                return;
            }
            i = gNextSpriteStat[i];
        }
    }
}

/*8009A9B8*/
void func_8009A9B8(void)
{
    D_801AE9C4 = 50;
    D_80118250 = 50;
    D_8019910C = 0;
    D_8019964C = 0;
    D_8012FCAC = 120;
}

/*8009A9F0*/
INCLUDE_ASM("nonmatchings/src/code0/95500", func_8009A9F0);

/*8009B838*/
void func_8009B838(s32 spritenum)
{
    D_801B081C = 0;
    D_8012FD74 = 0;
    D_80119A34 = gpSprite[spritenum].z;

    if (D_800DF585 != 0)
        D_8012FC94 = 0;
    else
        D_8012FC94 = 310;
}

/*8009B8A4*/
void func_8009B8A4(s32 spritenum)
{
    SpriteType *spr;
    code0UnkStruct3 *ptr;

    spr = &gpSprite[spritenum];
    ptr = &D_8019B940[D_80106D50[spritenum]];
    if (D_8012FD74 == 0)
    {
        D_801AE8F8 = 90;
        D_801ACBE0 = 0;
        D_8012FD74 = 1;
        D_80199564 = 0;
        spr->unk2B = 0;
        spr->unk22 = 0;
        func_80042124(ptr, 75);
        D_801A1958.enemies_killed++;
        ptr->unk84 = -1;
    }
}

/*8009B974*/
static void func_8009B974(s32 spritenum)
{
    SpriteType *spr;
    SpriteType *spr2;
    code0UnkStruct3 *ptr;
    s32 i, j, k;
    s32 x1, y1, z1;
    s32 x2, y2, z2;
    s32 ang;

    ptr = &D_8019B940[D_80106D50[spritenum]];
    spr = &gpSprite[spritenum];
    switch (spr->unk2B)
    {
    case 0:
        D_80119A34 = gpSprite[gPlayer[0].unk4A].z - 64000;
        func_80042124(ptr, 75);
        spr->unk2B = 1;
        break;
    case 1:
        func_80017268(spritenum);
        D_801B081C = 0;
        spr->unk1C = (D_80119A34 - spr->z) >> 4;
        if (spr->unk1C < 800)
        {
            D_801B081C = 0;
            spr->unk22 = 123;
            func_80042124(ptr, 150);
            spr->unk2B = 6;
            i = gHeadSpriteStat[7];
            while (i >= 0)
            {
                spr2 = &gpSprite[i];
                if (spr2->unk1E == 100)
                {
                    setSprite(spritenum, spr2->x, spr2->y, spr2->z);
                    spr->ang = 1024;
                    func_8006B590(925);
                    break;
                }
                i = gNextSpriteStat[i];
            }
            break;
        }
        func_8004E5F8(spritenum, 0, 0, spr->unk1C);
        break;
    case 6:
        if (D_801AE8F8 != 0)
        {
            if ((func_80042140(spritenum) < 87) && !(D_8012FD88 & 1))
                func_8008E3E0(spr->x, spr->y, (spr->z - 54000), spr->sectnum, 54, 0);

            if ((func_80042140(spritenum) >= 88) && (func_80042140(spritenum) < 301))
            {
                ang = krand() & 0x7FF;
                x2 = gpSprite[spritenum].x + 500;
                y2 = gpSprite[spritenum].y;
                k = (krand() & 0xFFF) + 52000;
                z2 = gpSprite[spritenum].z - k;
                j = (krand() & 0x1FFF) + 20000;
                x1 = x2 + ((j * gpSinTable[(ang + 512) & 0x7FF]) >> 14);
                y1 = y2 + ((j * gpSinTable[ang]) >> 14);
                z1 = z2 + ((krand() & 0xFFFF) - 0x8000);
                func_8004E7F0(x1, y1, z1, x2, y2, z2, 3, (krand() & 0x1F) + 64, 0x800, 31);
                audio_80007820(((krand() % 3) + 1649), spritenum);
            }

            if (func_80042140(spritenum) == 87)
            {
                D_800DEEE4[0] = 1;
                playSfx(1346);
            }

            if (func_80042140(spritenum) == 301)
            {
                func_8008E3E0(spr->x, spr->y, (spr->z - 54000), spr->sectnum, 80, 0);
                D_800DEEE4[0] = 1;
                playSfx(1648);
                func_8008E3E0(spr->x, spr->y, (spr->z - 54000), spr->sectnum, 30, 0);
                spr->unk25 = 31;
                spr->cstat |= 0x800;
            }
            if (func_80042140(spritenum) == 319)
            {
                if (D_8013B2D0[spritenum].unk6 < 251)
                    D_8013B2D0[spritenum].unk6 += 4;
                else
                    spr->cstat = -0x8000;

                D_801AE8F8--;
                if ((D_801AE8F8 == 1) && (gPlayer[0].unk45 == 0))
                    func_8008E01C(30, 1);
            }
            else
                func_80017268(spritenum);
        }
        break;
    }
}

/*8009BED0*/
static s32 func_8009BED0(SpriteType *arg0, s32 x, s32 y, s32 z, s16 sectnum)
{
    s16 sectnum1;
    s32 i, j, k;
    s32 x1, y1, z1;

    x1 = arg0->x;
    y1 = arg0->y;
    z1 = arg0->z;
    sectnum1 = arg0->sectnum;

    i = canSee(x1, y1, z1 - 25000, sectnum1, x, y, z - 7296, sectnum);
    j = canSee(x1, y1, z1 - 50000, sectnum1, x, y, z, sectnum);
    k = canSee(x1, y1, z1, sectnum1, x, y, z - 0x3900, sectnum);

    if (i != 0 || j != 0 || k)
        return 1;

    x1 = arg0->x + ((gpSinTable[(arg0->ang + 1024) & 0x7FF] * 125) >> 11);
    y1 = arg0->y + ((gpSinTable[(arg0->ang + 512) & 0x7FF] * 125) >> 11);
    i = canSee(x1, y1, z1 - 25000, sectnum1, x, y, z - 0x1C80, sectnum);
    j = canSee(x1, y1, z1 - 50000, sectnum1, x, y, z, sectnum);
    k = canSee(x1, y1, z1, sectnum1, x, y, z - 14592, sectnum);

    if (i != 0 || j != 0 || k)
        return 1;

    x1 = arg0->x + ((gpSinTable[arg0->ang & 0x7FF] * 125) >> 11);
    y1 = arg0->y + ((gpSinTable[(arg0->ang - 512) & 0x7FF] * 125) >> 11);
    i = canSee(x1, y1, z1 - 25000, sectnum1, x, y, z - 7296, sectnum);
    j = canSee(x1, y1, z1 - 50000, sectnum1, x, y, z, sectnum);
    k = canSee(x1, y1, z1, sectnum1, x, y, z - 14592, sectnum);

    if (i != 0 || j != 0 || k)
        return 1;

    return 0;
}

/*8009C248*/
INCLUDE_ASM("nonmatchings/src/code0/95500", func_8009C248);

/*8009E5B0*/
void func_8009E5B0(s32 spritenum)
{
    code0UnkStruct3 *ptr;

    ptr = &D_8019B940[D_80106D50[spritenum]];
    D_801AC594 = 0;
    D_80199964 = 0;
    D_80199948 = 0;
    D_80105540 = 0;
    D_8011A66C = 650;
    ptr->unk68 |= 0x3010;
    func_80042124(ptr, 71);
}

/*8009E638*/
void func_8009E638(s32 spritenum)
{
    SpriteType *spr;
    code0UnkStruct3 *ptr;

    spr = &gpSprite[spritenum];
    ptr = &D_8019B940[D_80106D50[spritenum]];
    if (D_80199948 == 0)
    {
        MusHandleStop(D_8013B2D0[spritenum].handle, 0);
        audio_80007A44((krand() & 1) | 1422, spritenum, 32768);
        spr->unk2B = 20;
        D_80199948 = 1;
        func_80042124(ptr, 67);
        D_801A1958.enemies_killed++;
        ptr->unk84 = -1;
    }
}

/*8009E734*/
static void func_8009E734(s32 spritenum)
{
    SpriteType *spr;
    code0UnkStruct5 *ptr;
    s16 sectnum;
    s32 x, y, z;

    spr = &gpSprite[spritenum];
    sectnum = spr->sectnum;
    ptr = &D_8013B2D0[spritenum];

    if ((gpSector[sectnum].floorstat & 2) && (gpSector[sectnum].floorheinum != 0))
    {
        x = (gpSinTable[(spr->ang + 512) & 0x7FF] * 15) >> 13;
        y = (gpSinTable[spr->ang & 0x7FF] * 15) >> 13;
        z = getFlorzOfSlope(sectnum, spr->x, spr->y);
        if (z < getFlorzOfSlope(spr->sectnum, spr->x + x, spr->y + y))
        {
            if (ptr->unk2 <= 64)
                ptr->unk2 = ptr->unk2 + 8;
        }
        else
        {
            if (ptr->unk2 >= -64)
                ptr->unk2 = ptr->unk2 - 8;
        }
    }
    else
    {
        if (ptr->unk2)
        {
            if (ptr->unk2 < 0)
            {
                ptr->unk2 += 8;
                if (ptr->unk2 < 0)
                    return;
                else
                    ptr->unk2 = 0;
            }

            if (ptr->unk2 > 0)
            {
                ptr->unk2 -= 8;
                if (ptr->unk2 <= 0)
                    ptr->unk2 = 0;
            }
        }
    }
}

/*8009E8C8*/
INCLUDE_ASM("nonmatchings/src/code0/95500", func_8009E8C8);

/*8009F648*/
static s32 func_8009F648(s32 spritenum)
{
    s32 i;

    i = gHeadSpriteStat[7];
    while (i >= 0)
    {
        if (gpSprite[i].picnum == 41)
        {
            if (func_80040D40(gpSprite[i].x,
                gpSprite[i].y,
                gpSprite[spritenum].x,
                gpSprite[spritenum].y) >= 4001)
            {
                return i;
            }
        }
        i = gNextSpriteStat[i];
    }
    return -1;
}

/*8009F71C*/
INCLUDE_ASM("nonmatchings/src/code0/95500", func_8009F71C);


