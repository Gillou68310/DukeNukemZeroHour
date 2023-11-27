#include "common.h"
#include "code0/main.h"
#include "code0/graphics.h"
#include "code0/4600.h"
#include "code0/9410.h"
#include "code0/audio.h"
#include "code0/pragmas.h"
#include "code0/FDE0.h"
#include "code0/17B30.h"
#include "code0/1E7A0.h"
#include "code0/2ABE0.h"
#include "code0/36410.h"
#include "code0/37090.h"
#include "code0/41940.h"
#include "code0/59D40.h"
#include "code0/64530.h"
#include "code0/6ACA0.h"
//#include "code0/87010.h"
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

#define GET_ANGLE(A,B,C) \
    (((A << 0x10) + (B << C)) >> 0x10) & 0x7FF;

/*.data*/
/*800E1770*/ static s32 D_800E1770 = 0;
static s32 _unused[3] = {0};

/*800E1780*/
static char *D_800E1780[8] = {
    "ARMOR",
    "SCUBA GEAR",
    "VITAMIN X",
    "PROTECTIVE BOOTS",
    "MEDKIT",
    "NIGHT VISION",
    "GAS MASK",
    "COMPUTER",
};

/*800E17A0*/
static char *D_800E17A0[8] = {
    "ARMOR",
    "DIVING HELMET",
    "VITAMIN X",
    "PROTECTIVE BOOTS",
    "DOCTOR'S BAG",
    "NIGHT VISION",
    "GAS MASK",
    "COMPUTER",
};

/*800E17C0*/
static char *D_800E17C0[8] = {
    "",
    "ON",
    "USED",
    "",
    "USED",
    "ACTIVATED",
    "ON",
    "",
};

/*800E17E0*/
s16 D_800E17E0[8] = {
    100, 1800, 900, 1000, 100, 2700, 1800, -1
};

/*800E17F0*/
u8 D_800E17F0[32*7] = {
    0, 0, 0, 0, 4, 0, 0,
    0, 0, 0, 0, 7, 0, 0,
    0, 0, 0, 0, 12,0, 0,
    0, 0, 4, 0, 0, 0, 0,
    0, 0, 7, 0, 0, 0, 0,
    0, 0, 12,0, 0, 0, 0,
    0, 0, 0, 4, 0, 0, 0,
    0, 0, 0, 7, 0, 0, 0,
    0, 0, 0, 12,0, 0, 0,
    0, 0, 0, 0, 0, 4, 0,
    0, 0, 0, 0, 0, 7, 0,
    0, 0, 0, 0, 0, 12,0,
    0, 0, 0, 0, 0, 0, 4,
    0, 0, 0, 0, 0, 0, 7,
    0, 0, 0, 0, 0, 0, 12,
    0, 0, 2, 0, 2, 0, 0,
    0, 0, 4, 0, 4, 0, 0,
    0, 0, 6, 0, 6, 0, 0,
    0, 0, 0, 2, 2, 0, 0,
    0, 0, 0, 4, 4, 0, 0,
    0, 0, 0, 6, 6, 0, 0,
    0, 0, 0, 0, 2, 0, 2,
    0, 0, 0, 0, 4, 0, 4,
    0, 0, 0, 0, 6, 0, 6,
    0, 0, 2, 0, 0, 0, 2,
    0, 0, 4, 0, 0, 0, 4,
    0, 0, 6, 0, 0, 0, 6,
    0, 0, 0, 2, 0, 0, 2,
    0, 0, 0, 4, 0, 0, 4,
    0, 0, 0, 6, 0, 0, 6,
    0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0,
};

/*.comm*/
/*800FE9E8*/ s32 D_800FE9E8;
/*80118244*/ s32 D_80118244;
/*80118250*/ s32 D_80118250;
/*80119A34*/ s32 D_80119A34;
/*8011A66C*/ s32 D_8011A66C;
/*8011BC58*/ s32 D_8011BC58;
/*8012FC94*/ s32 D_8012FC94;
/*8012FCAC*/ s32 D_8012FCAC;
/*8012FD74*/ s32 D_8012FD74;
/*80138698*/ s32 D_80138698;
/*80197D48*/ s32 D_80197D48;
/*80197DDC*/ s32 D_80197DDC;
/*8019910C*/ s32 D_8019910C;
/*80199550*/ s32 D_80199550;
/*80199560*/ s32 D_80199560;
/*80199564*/ s32 D_80199564;
/*8019964C*/ s32 D_8019964C;
/*80199948*/ s32 D_80199948;
/*80199964*/ s32 D_80199964;
/*80199984*/ s32 D_80199984;
/*801B081C*/ s32 D_801B081C;
/*801A19E8*/ s32 D_801A19E8; /*florhit*/
/*801AC594*/ s32 D_801AC594;
/*801AC8DC*/ s32 D_801AC8DC;
/*801ACBE0*/ s32 D_801ACBE0;
/*801AE530*/ s32 D_801AE530;
/*801AE8F8*/ s32 D_801AE8F8;
/*801AE9C4*/ s32 D_801AE9C4;
/*801AEE40*/ _95500UnkStruct1 D_801AEE40[200] ALIGNED(16);

/*.text*/
static void func_8009F71C(s32 spritenum);

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

    if ((D_801CA14C[gMapNum].unk0 == 2) || (D_801CA14C[gMapNum].unk0 == 3))
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

    Matrix4f mf5, mf2, mf1, mf3, mf4;

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

    spritenum_ = func_8004BC64(spr->x - ((s32)ox * 4),
                               spr->y - ((s32)oy * 4),
                               spr->z + ((s32)oz * 64), spr->sectnum, 32123, 0, 0);
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
        if (gpSprite[i].lotag == arg0)
        {
            if (gpSprite[i].hitag == arg1)
                return i;
        }
        i = gNextSpriteStat[i];
    }
    return -1;
}

/*80095FCC*/
static s32 func_80095FCC(s32 ang1, s32 ang2, s32 arg2)
{
    return GET_ANGLE(ang1, getAngleDelta(ang1, ang2), (arg2+8));
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
                gpSprite[spritenum].y) > 4000)
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
void func_800965F8(s32 spritenum)
{
    s32 x2, y2;
    s16 sectnum;
    SpriteType *spr;
    SpriteType *spr2;
    SpriteType *spr3;

    code0UnkStruct3 *ptr;
    code0UnkStruct5 *ptr2;

    s32 i, j, k, l, m, n;
    s32 temp_v0_13;
    s32 ang, ang2;
    s32 xpos, ypos;
    s32 z;
    s32 xvect, yvect;
    s32 cond;

    spr3 = gpSprite;
    spr = &gpSprite[spritenum];
    i = spr3[spritenum].statnum;
    xpos = gPlayer[0].xpos;
    ypos = gPlayer[0].ypos;
    z = gpSprite[gPlayer[0].unk4A].z;
    ptr = &D_8019B940[D_80106D50[spritenum]];
    ptr2 = &D_8013B2D0[spritenum];

    if (i == 302)
    {
        if (spr->picnum == 36)
        {
            if (func_800720FC(spritenum) != 0)
            {
                playSfx(165);
                audio_80008574(0, 1486);

                if (spr->hitag != 0)
                    func_8006B590(spr->hitag);
                else
                    func_8006CB38(spr->sectnum);

                func_8004BD24(spritenum);
                func_8004BD24(spr->unk22);
            }
        }
    }

    switch (spr->picnum)
    {
    case 48:
        if (spr->unk2B != 0)
        {
            if (spr->unk2B == 1)
            {
                spr->unk22 = (krand() & 0x3F) + 0xF;
                spr->unk2B++;
            }

            if (spr->unk2B == 2)
            {
                if (spr->unk22 == 0)
                {
                    func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 70, 0);
                    spr->unk2B = 1;
                }
                else
                    spr->unk22--;
            }
        }
        break;
    case 1308:
        if (spr->unk2B == 0)
        {
            func_80017268(spritenum);
            ang2 = getAngle(gPlayer[0].xpos - gpSprite[spritenum].x, gPlayer[0].ypos - gpSprite[spritenum].y) - gpSprite[spritenum].ang;
            if (ang2 > 0x400)
                ang2 -= 0x800;

            if (ang2 < -0x400)
                ang2 += 0x800;

            gpSprite[spritenum].ang = (gpSprite[spritenum].ang + (ang2 / 16)) & 0x7FF;
            gpSprite[spritenum].z += (gpSinTable[gTotalClockLock & 0x7FF]) / 512;
            break;
        }

        if (spr->unk2B < 10)
        {
            spr->unk2B = 10;
            playSfx(1358);
            func_80042124(ptr, 165);
            func_80017268(spritenum);
            break;
        }

        if (!(D_8012FD88 & 7))
        {
            s32 a, b;
            a = spr->x + ((krand() & 0x7FF) - 0x400);
            b = spr->y + ((krand() & 0x7FF) - 0x400);
            func_8008E3E0(a, b, (spr->z - (krand() & 0x1FFF)), spr->sectnum, 39, 0);
        }

        if (func_80042140(spritenum) < 29)
            func_80017268(spritenum);

        break;
    case 2559:
    case 2562:
    case 2563:
    case 2564:
        spr->unk18 = 0;
        spr->xrepeat = 0x80;
        spr->yrepeat = 0x80;
        break;
    case 2560:
        spr->unk18++;
        if (spr->unk18 >= 3)
        {
            spr->unk18 = 0;
            spr->picnum = 2559;
        }
        break;
    case 2597:
        if (ptr->unk8 < 4)
        {
            if (D_800DEEA0 != 0)
            {
                func_8008E3E0(spr->x, spr->y, spr->z - 12000, spr->sectnum, 44, 4);
                func_8008E3E0(spr->x, spr->y, spr->z - 24000, spr->sectnum, 44, 4);
            }
            func_8008E3E0(spr->x, spr->y, spr->z - 12000, spr->sectnum, 41, 32);
            audio_80007A44(560, spritenum, 40000);
            func_8004BD24(spritenum);
        }
        break;
    case 2341:
    case 2342:
        if (spr->unk2B != 200)
        {
            if (spr->unk25 == 1)
            {
                if (spr->unk2B >= 2)
                {
                    func_8001F7B4(12, 8);
                    func_8004AB6C(spritenum, 2000, 50, 100, 150, 200, 0);
                    audio_80007A44(560, spritenum, 40000);
                    audio_80007A44(591, spritenum, 40000);
                    spr->unk2B = 200;
                    break;
                }
            }
            else if (spr->unk2B >= 2)
            {
                spr->picnum = 2340;
                spr->unk2B = 200;

                if (spr->hitag == 602)
                    func_8006B590(1002);

                if (spr->hitag == 603)
                    func_8006B590(1003);

                i = gHeadSpriteStat[1];
                while (i >= 0)
                {
                    j = gNextSpriteStat[i];

                    if (gpSprite[i].hitag == spr->hitag)
                        func_80055EC0(i, 0);

                    i = j;
                }

                i = gHeadSpriteStat[2];
                while (i >= 0)
                {
                    j = gNextSpriteStat[i];

                    if (gpSprite[i].hitag == spr->hitag)
                        func_80055EC0(i, 0);

                    i = j;
                }
                break;
            }

            if (spr->unk2B == 1)
            {
                if (spr->unk1C == 0)
                {
                    s32 a;
                    i = gHeadSpriteStat[1];
                    a = 0;
                    while (i >= 0)
                    {
                        a += (gpSprite[i].hitag == spr->hitag);
                        i = gNextSpriteStat[i];
                    }

                    i = gHeadSpriteStat[2];
                    while (i >= 0)
                    {
                        a += gpSprite[i].hitag == spr->hitag;
                        i = gNextSpriteStat[i];
                    }

                    if ((a < 3) && (++spr->unk1A > 60))
                    {
                        spr->unk1A = 60;
                        i = gHeadSpriteStat[22];
                        k = -1;
                        while (i >= 0)
                        {
                            if (gpSprite[i].hitag == spr->hitag)
                            {
                                k = i;
                                if (func_801C0FDC(10000) < 5000)
                                    goto block_159;
                            }
                            i = gNextSpriteStat[i];
                        }

                        if (k != -1)
                        {
                        block_159:
                            i = gHeadSpriteStat[1];
                            cond = 0;
                            while (i >= 0)
                            {
                                if (func_80040D40(gpSprite[k].x, gpSprite[k].y, gpSprite[i].x, gpSprite[i].y) < 1200)
                                {
                                    cond = 1;
                                    break;
                                }
                                i = gNextSpriteStat[i];
                            }

                            if (cond == 0)
                            {
                                i = gHeadSpriteStat[2];
                                while (i >= 0)
                                {
                                    if (func_80040D40(gpSprite[k].x, gpSprite[k].y, gpSprite[i].x, gpSprite[i].y) < 1200)
                                    {
                                        cond = 1;
                                        break;
                                    }
                                    i = gNextSpriteStat[i];
                                }

                                if (cond == 0)
                                {
                                    i = gHeadSpriteStat[10];
                                    while (i >= 0)
                                    {
                                        if (func_80040D40(gpSprite[k].x, gpSprite[k].y, gpSprite[i].x, gpSprite[i].y) < 1200)
                                        {
                                            cond = 1;
                                            break;
                                        }
                                        i = gNextSpriteStat[i];
                                    }

                                    if (cond == 0)
                                    {
                                        spr->unk22 = k;
                                        spr->unk18 = 0;
                                        spr->unk1A = 0;
                                        spr->unk1C = 1;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
                else
                {
                    k = spr->unk22;
                    spr->unk18++;
                    audio_80007820(((krand() % 2) + 0x39), k);
                    func_800867CC(k,
                                  gpSprite[k].x,
                                  gpSprite[k].y,
                                  gpSprite[k].z - 12000,
                                  spr->x,
                                  spr->y,
                                  spr->z - 8000,
                                  64, 24);

                    if (spr->unk18 >= 9)
                    {
                        spr->unk1C = 0;
                        l = func_8004BC64(gpSprite[k].x,
                                          gpSprite[k].y,
                                          gpSprite[k].z,
                                          gpSprite[k].sectnum,
                                          gpSprite[k].picnum, 0, 0);

                        if (l >= 0)
                        {
                            gpSprite[l].unk25 = gpSprite[k].unk25;
                            gpSprite[l].hitag = gpSprite[k].hitag;
                            gpSprite[l].lotag = gpSprite[k].lotag;
                            gpSprite[l].unk2B = 2;
                            D_8013B2D0[l].unk6 = 0xFF;
                            audio_80007820(704, l);
                            D_8019B940[D_80106D50[l]].unk0 |= 0x01000000;
                            break;
                        }
                    }
                }
            }
        }
        break;
    case 1404:
        spr->cstat = 0x1000;
        switch (spr->unk2B)
        {
        case 1:
            spr->unk22 = 0;
            spr->unk18 = 0;
            spr->unk1A = 0;
            spr->unk1C = 0;
            spr->unk16 = 0;
            spr->unk2B++;
            break;
        case 2:
            k = func_80096240(spr) - 1900;
            if (k != spr->z)
            {
                if (k < spr->z)
                {
                    spr->z = k;
                    spr->unk1A /= 2;
                    spr->unk16 /= 2;
                    spr->unk1C = (-(spr->unk1C * 3)) / 4;
                }
                else
                    spr->unk1C += 10;
            }

            spr->z += spr->unk1C;

            {
                s32 a, b;
                a = (gpSinTable[(spr->ang + 0x200) & 0x7FF]) * 2; b = (gpSinTable[spr->ang & 0x7FF]) * 2; func_8004E5F8(spritenum, (spr->unk1A *a) >> 14, (spr->unk1A *b) >> 14, 0);
            }

            ptr2->unk2 = (ptr2->unk2 + (spr->unk1A/4)) & 0x7FF;

            switch (spr->unk22)
            {
            case 0:
                if ((krand() & 0xFF) < 0x40)
                {
                    spr->unk22 = 1;
                    spr->unk18 = (krand() & 0x1F) + 1;
                }
                else
                {
                    spr->unk16 += (krand() & 0x1F) - 0xF;
                    spr->ang = (spr->ang + spr->unk16) & 0x7FF;

                    if (spr->unk1A < 120)
                        spr->unk1A += (krand() & 0x3F);
                    spr->unk22 = 2;
                }
                break;
            case 1:
                spr->unk18--;
                if (spr->unk18 == 0)
                    spr->unk22 = 0;
                break;
            case 2:
                if (spr->unk1C >= -129)
                    spr->unk1C -= (krand() & 0x3F);

                spr->unk22 = 0;
                break;
            }
            break;
        }
        break;
    case 1960:
        if (func_80040D40(spr->x, spr->y, xpos, ypos) < 2500)
            ptr2->unk2 = (ptr2->unk2 + 0xA) & 0x7FF;

        break;
    case 2533:
        if (ptr->unk8 < 4)
        {
            audio_80007A44(((krand() % 3) + 538), spritenum, 40000);
            func_80058E44(spritenum);
            func_8004BD24(spritenum);
            break;
        }

        if (spr->unk22 != 0)
        {
            ptr2->unk0 = (gpSinTable[((spr->unk22 * (gpSinTable[spr->unk18])) >> 14) & 0x7FF] * 5) >> 10;
            spr->unk22--;
            spr->unk18 = (spr->unk18 + 0x40) & 0x7FF;

            if (spr->unk18 == 0x40)
                audio_80007A44(166, spritenum, spr->unk22 * 16);
            if (spr->unk18 == 0x440)
                audio_80007A44(167, spritenum, spr->unk22 * 16);
        }
        else
            spr->unk18 = 0;

        break;
    case 1989:
        if (func_80040D40(spr->x, spr->y, xpos, ypos) < 2500)
            spr->unk22 = 0x100;
        /* fallthrough */
    case 1329:
    case 1672:
        if (spr->unk22 != 0)
        {
            ptr2->unk0 = (gpSinTable[((spr->unk22 * (gpSinTable[spr->unk18])) >> 14) & 0x7FF] * 25) >> 12;
            spr->unk22--;
            spr->unk18 = (spr->unk18 + 0x40) & 0x7FF;
            if (spr->picnum == 1672)
            {
                if (spr->unk18 == 0x40)
                    audio_80007A44(179, spritenum, spr->unk22 * 16);
                if (spr->unk18 == 0x440)
                    audio_80007A44(180, spritenum, spr->unk22 * 16);
            }
            else
            {
                if (spr->unk18 == 0x40)
                    audio_80007A44(166, spritenum, spr->unk22 * 16);
                if (spr->unk18 == 0x440)
                    audio_80007A44(167, spritenum, spr->unk22 * 16);
            }
        }
        else
            spr->unk18 = 0;

        break;
    case 2402:
        ptr2->unk2 = (gpSinTable[(256 * gpSinTable[spr->unk18] >> 14) & 0x7FF] * 15) >> 13;
        spr->unk18 = (spr->unk18 + 0x40) & 0x7FF;
        if (spr->unk18 == 0x40)
            audio_80007A44(179, spritenum, 8192);
        if (spr->unk18 == 0x440)
            audio_80007A44(180, spritenum, 8192);
        break;
    case 2261:
        if (spr->unk2B == 1)
        {
            if (ptr2->unk0 < 200)
                ptr2->unk0 += 20;
            else
                spr->unk2B = 2;
        }
        break;
    case 2324:
        if (spr->unk2B == 1)
        {
            spr->z += 200;
            spr->unk22++;
            if (spr->unk22 >= 16)
                spr->unk2B = 2;
        }
        break;
    case 2326:
    loop_244:
        switch (spr->unk2B)
        {
        case 1:
            if (spr->unk18 == 0)
            {
                spr->unk18 = 1;
                spr->unk2B = 2;
                goto loop_244;
            }
            if (spr->unk18 == spr->unk2B)
            {
                spr->unk18 = 0;
                spr->unk2B = 3;
                goto loop_244;
            }
            break;
        case 2:
            if (ptr2->unk2 < 500)
            {
                ptr2->unk2 += 50;
                break;
            }
            ptr2->unk2 = 500;
            if (spr->unk25 & 2)
                spr->unk2B = 0;
            else
                spr->unk2B = 4;

            if (spr->unk25 & 8)
                spr->unk25 &= 0xF7;
            else if (spr->unk25 & 4)
                spr->unk25 |= 8;

            break;
        case 3:
            if (ptr2->unk2 > 0)
            {
                ptr2->unk2 -= 50;
                break;
            }
            ptr2->unk2 = 0;
            if (spr->unk25 & 2)
                spr->unk2B = 0;
            else
                spr->unk2B = 4;

            if (spr->unk25 & 8)
                spr->unk25 &= 0xF7;
            else if (spr->unk25 & 4)
                spr->unk25 |= 8;
        }
        break;
    case 1458:
        if (spr->unk2B == 1)
        {
            audio_800077F4(62, spritenum);
            if (spr->hitag != 0)
                func_8006B590(spr->hitag);
            else
                func_8006CB38(spr->sectnum);

            spr->unk2B = 2;
        }
        if (spr->unk2B == 2)
        {
            if (ptr2->unk0 < 0x400)
                ptr2->unk0 += 20;
            else
                ptr2->unk0 = 0x400;
        }
        break;
    case 1491:
    case 1492:
        if (spr->unk2B == 1)
        {
            audio_800077F4(189, spritenum);
            spr->unk2B = 2;
            spr->unk22 = 0;
        }
        if (spr->unk2B == 2)
        {
            if (spr->unk22 < 0x10)
            {
                spr->ang = (spr->ang + 0x10) & 0x7FF;
                spr->unk22++;
            }
            else
                spr->unk2B = 3;
        }
        break;
    case 2293:
        if (spr->unk2B == 1)
        {
            audio_800077F4(166, spritenum);
            spr->unk2B = 2;
            spr->unk22 = 0;
        }
        if (spr->unk2B == 2)
        {
            if (spr->unk22 < 7)
            {
                spr->ang = (spr->ang + 0x80) & 0x7FF;
                spr->unk22++;
            }
            else
            {
                audio_800077F4(531, spritenum);
                spr->unk2B = 3;
            }
        }
        break;
    case 2294:
        if (spr->unk2B == 1)
        {
            spr->unk2B = 2;
            spr->unk22 = 0;
        }
        if (spr->unk2B == 2)
        {
            if (spr->unk22 < 7)
            {
                spr->ang = (spr->ang - 0x80) & 0x7FF;
                spr->unk22++;
            }
            else
                spr->unk2B = 3;
        }
        break;
    case 1443:
        switch (spr->unk2B)
        {
        case 1:
            spr->unk22 = 0;
            spr->unk2B++;
            break;
        case 2:
            j = (gpSinTable[spr->ang & 0x7FF] * 25) >> 13;
            i = (gpSinTable[(spr->ang - 0x200) & 0x7FF] * 25) >> 13;
            spr->x += j;
            spr->y += i;
            setSprite(spritenum, spr->x, spr->y, spr->z);
            spr->unk22++;
            if (spr->unk22 >= 71)
                spr->unk2B++;
            break;
        }
        break;
    case 2361:
    case 2362:
    case 2363:
        switch (spr->unk2B)
        {
        case 1:
            if (spr->picnum == 2363)
            {
                func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 47, 0);
                func_80045400(spr->x, spr->y, spr->z - 16000, spr->sectnum, 0, spr->ang, 44, 130);
                func_80045400(spr->x, spr->y, spr->z - 8000, spr->sectnum, 0, spr->ang, 44, 130);
                func_800574A4(spritenum);
                break;
            }
            func_80045400(spr->x, spr->y, spr->z - 8000, spr->sectnum, 0, spr->ang, 44, 130);
            spr->unk22 = 40;
            spr->unk2B = 2;
            spr->picnum++;
            break;
        case 2:
            if (spr->unk22 != 0)
                spr->unk22--;
            else
                spr->unk2B = 1;
        }
        break;
    case 1625:
        if (spr->unk2B == 1)
        {
            i = func_8004E5F8(spritenum, 0, 0, spr->unk1A);

            if (i >= 0xC000)
                func_80047820(spritenum, (i + 0x4000) & 0xFFFF, 1000);

            spr->unk1A += 400;
            func_8009635C(spritenum, 8000, 900);
            if (func_80096240(spr) < (spr->z + 13000))
            {
                spr->z += 13000;
                audio_800077F4(1056, spritenum);
                func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 44, 2);
                func_800574A4(spritenum);
                spr->unk2B = 2;
            }
        }
        break;
    case 2311:
        xvect = 0;
        if (spr->unk2B != 0)
        {
            yvect = 0;
            ang = 0;
            if (spr->unk22 != 0xFF)
            {
                j = func_80095F58(spr->unk22, spr->lotag);
                if (j == -1)
                    spr->unk22 = 0xFF;
                else if (func_80040D40(gpSprite[j].x, gpSprite[j].y, spr->x, spr->y) < 600)
                {
                    if (spr->unk22 == 0x10)
                        func_8006B590(621);

                    spr->unk22++;
                }

                ang = getAngleDelta(spr->ang, (getAngle(gpSprite[j].x - spr->x, gpSprite[j].y - spr->y) - 0x200) & 0x7FF);
                spr->ang = GET_ANGLE(spr->ang, ang, 0xC);
                if ((spr->unk22 == 0xF))
                {
                    k = gHeadSpriteStat[106];
                    while (k >= 0)
                    {
                        spr2 = &gpSprite[k];
                        if ((spr2->picnum == 8) && ((spr2->hitag == 620)))
                        {
                            if (spr2->unk2B == 0)
                                goto block_332;
                            else
                                break;
                        }

                        k = gNextSpriteStat[k];
                    }
                }

                if (klabs((spr->z-gpSprite[j].z)) < 200)
                {
                    xvect = (gpSinTable[(spr->ang + 0x400) & 0x7FF] * 25) >> 12;
                    yvect = (gpSinTable[(spr->ang + 0x200) & 0x7FF] * 25) >> 12;
                }
            }

        block_332:
            func_8004E5F8(spritenum, xvect, yvect, 0);
            k = gHeadSpriteStat[302];
            while (k >= 0)
            {
                spr2 = &gpSprite[k];
                j = gNextSpriteStat[k];
                if ((spr2->picnum >= 2310) && (spr2->picnum < 2315))
                {
                    changeSpriteSect(k, spr->sectnum);
                    spr2->x = spr->x;
                    spr2->y = spr->y;
                    spr2->z = spr->z;
                    spr2->ang = spr->ang;
                }
                k = j;
            }

            if (gPlayer[0].unk59 != 0)
            {
                if (gPlayer[0].unk36 >= 0x1000)
                {
                    spr2 = &gpSprite[gPlayer[0].unk36-0x1000];
                    if ((spr2->picnum >= 2310) && (spr2->picnum < 2315))
                    {
                        gPlayer[0].xpos += (xvect >> 3);
                        gPlayer[0].ypos += (yvect >> 3);
                        rotatePoint(spr2->x, spr2->y, gPlayer[0].xpos, gPlayer[0].ypos, (ang >> 4), &x2, &y2);
                        gPlayer[0].xpos = x2;
                        gPlayer[0].ypos = y2;
                        gPlayer[0].unk38 = GET_ANGLE(gPlayer[0].unk38, ang, 12);
                        updateSector(x2, y2, &gPlayer[0].unk32);
                    }
                }
            }
        }
        break;
    case 2372:
        if (spr->statnum == 301)
        {
            switch (spr->unk2B)
            {
            case 0:
                i = 2500;
                if (spr->unk25 == 0)
                    i = 6000;

                if (spr->unk1A == 0)
                {
                    if (func_80040D40(spr->x, spr->y, xpos, ypos) < i)
                    {
                        if (spr->unk25 == 0)
                        {
                            spr->unk2B = 1;
                            spr->unk22 = 0;
                            spr->cstat &= 0x7FFF;
                            audio_800077F4(216, spritenum);
                        }
                        else
                        {
                            spr->unk22 = 0;
                            spr->unk2B = 2;
                        }
                    }
                }
                else
                {
                    spr->unk18++;
                    if (spr->unk18 == 300)
                    {
                        if (spr->unk25 == 0)
                        {
                            spr->unk2B = 1;
                            spr->unk22 = 0;
                            spr->cstat &= 0x7FFF;
                            audio_800077F4(216, spritenum);
                        }
                        else
                        {
                            spr->unk22 = 0;
                            spr->unk2B = 2;
                        }
                    }
                }
                break;
            case 1:
                spr->z -= 600;
                spr->unk22 += 600;
                if (spr->unk22 >= 23000)
                {
                    spr->unk22 = 0;
                    spr->unk2B = 2;
                }
                k = gHeadSpriteStat[301];
                while (k >= 0)
                {
                    j = gNextSpriteStat[k];
                    spr2 = &gpSprite[k];
                    if ((spr2->hitag == spr->hitag) && (spr2->picnum >= 2367) && (spr2->picnum < 2372))
                    {
                        spr2->cstat &= 0x7FFF;
                        spr2->z = spr->z;
                    }
                    k = j;
                }
                break;
            case 2:
                if (spr->unk22 != 30)
                {
                    spr->unk22++;
                    break;
                }

                j = (gpSinTable[(spr->ang + 0x200) & 0x7FF] * 75) >> 12;
                i = (gpSinTable[spr->ang & 0x7FF] * 75) >> 12;
                n = func_8004BC64(spr->x + j, spr->y + i, spr->z - 500, spr->sectnum, 1727, 0, 0);
                if (n >= 0)
                {
                    gpSprite[n].unk22 = 1;

                    if (spr->unk1A == 0)
                        gpSprite[n].unk25 = 0;
                    else
                        gpSprite[n].unk25 = 20;

                    gpSprite[n].ang = spr->ang;
                }
                func_8008E3E0(spr->x + j * 2, spr->y + i * 2, spr->z, spr->sectnum, 47, 0);
                func_80045400(spr->x + j * 2, spr->y + i * 2, spr->z - 16000, spr->sectnum, 0, spr->ang, 44, 130);
                func_80045400(spr->x + j * 2, spr->y + i * 2, spr->z - 8000, spr->sectnum, 0, spr->ang, 44, 130);
                deleteSprite(spritenum);
                break;
            }
        }
        else
        {
            switch (spr->unk2B)
            {
            case 1:
                spr->unk22 = 0;
                spr->cstat &= 0x7FFF;
                audio_800077F4(216, spritenum);
                spr->unk2B++;
                break;
            case 2:
                j = (gpSinTable[(spr->ang + 0x200) & 0x7FF] * 75) >> 12;
                i = (gpSinTable[spr->ang & 0x7FF] * 75) >> 12;
                n = func_8004BC64(spr->x + j, spr->y + i, spr->z - 500, spr->sectnum, 1727, 0, 0);
                if (n >= 0)
                {
                    gpSprite[n].unk22 = 1;
                    if (spr->unk1A == 0)
                        gpSprite[n].unk25 = 0;
                    else
                        gpSprite[n].unk25 = 20;

                    gpSprite[n].ang = spr->ang;
                }
                func_8008E3E0(spr->x + j * 2, spr->y + i * 2, spr->z, spr->sectnum, 47, 0);
                func_80045400(spr->x + j * 2, spr->y + i * 2, spr->z - 16000, spr->sectnum, 0, spr->ang, 44, 130);
                func_80045400(spr->x + j * 2, spr->y + i * 2, spr->z - 8000, spr->sectnum, 0, spr->ang, 44, 130);
                deleteSprite(spritenum);
                break;
            }
        }
        break;
    case 2432:
        switch (spr->unk2B)
        {
        case 1:
            ptr2->handle = 0;
            spr->unk2B = 2;
            break;
        case 2:
            if (ptr2->handle != 0)
                ptr2->handle = audio_80007A80(ptr2->handle, spritenum, 40000);

            l = 0;
            m = 0;
            if (spr->unk22 != 0xFF)
            {
                j = func_80095F58(spr->unk22, spr->lotag);
                if (j == -1)
                {
                    spr->unk22 = 0xFF;
                    MusHandleStop(ptr2->handle, 0);
                    audio_80007A44(270, spritenum, 40000);
                }
                else
                {
                    if (func_80040D40(gpSprite[j].x, gpSprite[j].y, spr->x, spr->y) < 600)
                        spr->unk22++;
                }

                ang = getAngleDelta(spr->ang, getAngle(gpSprite[j].x - spr->x, gpSprite[j].y - spr->y)) << 13;
                spr->ang = GET_ANGLE(spr->ang, ang, 0);
                l = (gpSinTable[(spr->ang + 0x200) & 0x7FF] * 175) >> 11;
                m = (gpSinTable[spr->ang] * 175) >> 11;
                ptr2->unk2 = (ptr2->unk2 + 80) & 0x7FF;
            }
            i = func_8004E5F8(spritenum, l, m, spr->unk1A);

            if (i >= 0xC000)
                func_80047820(spritenum, (i + 0x4000) & 0xFFFF, 100);

            spr->unk1A += 200;

            if (spr->unk22 != 0xFF)
                func_80096494(spritenum, 9500, 1600);

            k = func_80096240(spr) - 8000;
            if (k < spr->z)
            {
                if (klabs(spr->unk1A) > 5000)
                {
                    audio_80007A44(270, spritenum, 40000);
                    if (ptr2->handle == 0)
                        ptr2->handle = audio_80007A44(44, spritenum, 40000);
                }
                spr->z = k;
                spr->unk1A = 0;
            }
            break;
        }
        break;
    case 2002:
    case 2005:
        if (spr->unk2B != 0)
        {
            func_80017268(spritenum);
            switch (spr->unk2B)
            {
            case 1:
                spr->cstat &= 0xFEFE;
                audio_800077F4((krand() & 1) + 1249, spritenum);
                func_80056600(spritenum);
                ptr->unk99 = 0;

                if (!(spr->unk25 & 0x7F))
                {
                    spr->unk2B = 2;
                    switch (krand() % 8)
                    {
                    default:
                    case 0:
                        func_80042124(ptr, 54);
                        break;
                    case 1:
                        func_80042124(ptr, 48);
                        break;
                    case 2:
                        func_80042124(ptr, 46);
                        break;
                    case 3:
                        func_80042124(ptr, 55);
                        break;
                    case 4:
                    case 5:
                        func_80042124(ptr, 6);
                        break;
                    }

                    func_80057540(spr, 1500, 1, 0);
                }
                else
                {
                    func_80058E44(spritenum);
                    func_8004BD24(spritenum);
                }
                break;
            case 2:
                if (func_80042140(spritenum) == 45)
                {
                    spr->unk22 = 45;
                    spr->unk2B = 3;
                }
                break;
            case 3:
                if (spr->unk22 != 0)
                {
                    spr->unk22--;
                    break;
                }

                if ((krand() & 0x7FFF) < 0x2000)
                    audio_800077F4(1248, spritenum);

                changeSpriteStat(spritenum, 53);
                spr->unk18 = 2;
                spr->unk1A = 100;
                break;
            case 10:
                if ((krand() & 0x7FFF) < 0x2000)
                    func_80042124(ptr, 144);
                else
                    func_80042124(ptr, 161);

                spr->unk2B++;
                break;
            case 11:
                if (!(D_8012FD88 & 0x3F) && ((krand() & 0xFF) > 200))
                    spr->unk2B--;

                ptr->unk8 = 101;
                break;
            case 12:
                func_80042124(ptr, 143);
                audio_800086B0(0);
                spr->unk2B++;
                break;
            case 13:
                if (func_80042140(spritenum) == 89)
                    spr->unk2B = 10;
                break;
            case 20:
                func_80042124(ptr, 135);
                spr->unk2B++;
                break;
            case 25:
                func_80042124(ptr, 143);
                audio_800086B0(1);
                spr->unk2A = 1;
                spr->unk2B++;
                break;
            case 26:
                if (func_80042140(spritenum) == 89)
                    spr->unk2B = 20;
                break;
            case 35:
                func_80042124(ptr, 143);
                audio_800086B0(1);
                spr->unk2A = 1;
                spr->unk2B++;
                break;
            case 36:
                if (func_80042140(spritenum) == 89)
                {
                    func_80042124(ptr, 133);
                    spr->unk2B = 0;
                    spr->unk22 = 0;
                }
                if (ptr->unk8 < 0)
                    spr->unk2B = 1;

                break;
            case 40:
                func_80042124(ptr, 162);
                spr->unk2B++;
                break;
            case 45:
                func_80042124(ptr, 143);
                audio_800086B0(1);
                spr->unk2A = 1;
                spr->unk2B++;
                break;
            case 46:
                if (func_80042140(spritenum) == 89)
                    spr->unk2B = 40;
                break;
            }
        }
        else if (ptr->unk8 >= 0)
        {
            if ((spr->unk25 & 0x80) ||
                (canSee(spr->x, spr->y, spr->z - 8000, spr->sectnum, xpos, ypos, z, gpSprite[gPlayer[0].unk4A].sectnum) != 0))
            {
                func_80017268(spritenum);
                if (spr->unk22 == 0)
                {
                    if (((krand() & 0x7FFF) < 1000) && (func_8009614C(spritenum) != -1))
                    {
                        func_80042124(ptr, 134);
                        spr->unk22 = (krand() % 3) + 1;
                    }
                }
                else
                {
                    s32 a;
                    a = func_8009614C(spritenum);
                    if (a != -1)
                    {
                        ang = getAngleDelta(spr->ang, getAngle(gpSprite[a].x - gpSprite[spritenum].x, gpSprite[a].y - gpSprite[spritenum].y)) << 13;
                        spr->ang = GET_ANGLE(spr->ang, ang, 0);
                    }

                    if (func_80042140(spritenum) == 25)
                        audio_800077F4(1378, spritenum);

                    if (func_80042140(spritenum) == 45)
                    {
                        func_8006D3B8(spritenum, 4, 0, 0, 0);
                        audio_800077F4(594, spritenum);
                        spr->unk22--;

                        if (spr->unk22 == 0)
                            func_80042124(ptr, 133);
                    }
                }
            }
        }
        else
        {
            spr->unk2B = 1;
        }
        break;
    case 2206:
        spr->ang = (spr->ang + 1) & 0x7FF;
        if (spr->unk2B == 1)
        {
            func_8004BC64(spr->x, spr->y, spr->z, spr->sectnum, 1295, 0, 0);
            func_800574A4(spritenum);
        }
        break;
    case 2208:
        if (spr->unk2B == 1)
        {
            s32 a;
            a = func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 44, 0);
            if (a != -1)
                gpSprite[a].unk25 = spr->unk25;

            func_800574A4(spritenum);
        }
        break;
    case 2437:
    case 2441:
        if (spr->unk2B == 1)
        {
            func_8008E3E0(spr->x, spr->y, (spr->z - 4000), spr->sectnum, 44, 1);
            func_800574A4(spritenum);
        }
        break;
    case 1346:
        if (spr->unk2B == 1)
        {
            func_8004BFDC(spritenum, 3, gpSprite[spritenum].z, 1);
            if (spr->unk25 != 1)
                func_8004AB6C(spritenum, 1000, 25, 50, 75, 100, 0);
            else
                func_8004AB6C(spritenum, 8000, 200, 400, 600, 800, 0);

            func_800574A4(spritenum);
        }
        break;
    case 1405:
        if (spr->unk22 == 0)
        {
            m = gHeadSpriteStat[1];
            while (m >= 0)
            {
                if (func_80040D40(spr->x, spr->y, gpSprite[m].x, gpSprite[m].y) < 3000)
                {
                    gpSprite[m].unk16 = spritenum;
                    spr->unk22 = 1;
                    break;
                }

                m = gNextSpriteStat[m];
            }
        }
        if (spr->unk2B == 1)
        {
            if (func_8006D3B8(spritenum, 34, 0, 90, -35) != 0)
            {
                s32 a, b;
                func_8001F7B4(0xC, 0xC);
                a = ((gpSinTable[(spr->ang + 0x200) & 0x7FF] * 405) >> 13);
                b = ((gpSinTable[spr->ang & 0x7FF] * 405) >> 13);
                func_8008E3E0(spr->x + a,
                              spr->y + b,
                              spr->z - 8600, spr->sectnum, 81, 0);
                audio_800077F4(505, spritenum);
            }
            spr->unk2B = 0;
        }
        break;
    case 1426:
        if (spr->unk2B != 0)
            func_8009F71C(spritenum);
        break;
    case 2292:
        switch (spr->unk2B)
        {
        case 0:
            if (i == 301)
            {
                if (func_800720FC(spritenum) != 0)
                    spr->unk2B = 1;
            }
            break;
        case 1:
            if (func_8006D3B8(spritenum, 35, 0, 0, 0) != 0)
            {
                audio_800077F4(504, spritenum);
            }
            spr->unk22 = 40;
            spr->unk2B = 2;
            break;
        case 2:
            spr->unk22--;
            if (spr->unk22 == 0)
                spr->unk2B = 0;
            break;
        }
        break;
    case 1347:
        switch (spr->unk2B)
        {
        case 0:
            if ((i == 301) && (func_80040D40(spr->x, spr->y, xpos, ypos) < 2500))
                spr->unk2B = 1;
            break;
        case 1:
            j = ((gpSinTable[(spr->ang + 0x200) & 0x7FF] * 25) >> 13);
            i = ((gpSinTable[spr->ang & 0x7FF] * 25) >> 13);
            i = func_8004E5F8(spritenum, j * 8, i * 8, 0);

            if (i >= 0xC000)
                func_80047820(spritenum, (i + 0x4000) & 0xFFFF, 50);

            if (ptr2->unk2 < 0x200)
                ptr2->unk2 = (ptr2->unk2 + 50) & 0x7FF;
            else
                ptr2->unk2 = 0x200;

            k = func_80096240(spr) - 2500;
            if (spr->z < k)
            {
                spr->unk2B = 2;
                spr->unk1A = 0;
            }
            break;
        case 2:
            if (ptr2->unk2 < 0x200)
                ptr2->unk2 = (ptr2->unk2 + 50) & 0x7FF;
            else
                ptr2->unk2 = 0x200;

            i = func_8004E5F8(spritenum, 0, 0, spr->unk1A);
            spr->unk1A += 200;
            k = func_80096240(spr);

            if (i >= 0xC000)
                func_80047820(spritenum, (i + 0x4000) & 0xFFFF, 50);

            if ((k < spr->z) || (i >= 0xC000))
            {
                spr->z = k;
                func_8004AB6C(spritenum, 1000, 25, 50, 75, 100, 0);
                audio_800077F4(215, spritenum);
                func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 44, 2);
                if ((gMapNum == MAP_FORT_ROSWELL) && (spr->hitag == 180))
                {
                    s32 a;
                    a = func_80058934(spr->x, spr->y, spr->z - 0x2000, spr->sectnum, 150);
                    if (a != -1)
                    {
                        gpSprite[a].xrepeat = 0x50;
                        gpSprite[a].lotag = 0x50;
                        gpSprite[a].picnum = 1822;
                        gpSprite[a].unk1C = 0;
                        gpSprite[a].unk18 = 0;
                        gpSprite[a].cstat = 0x1000;
                        gpSprite[a].unk22 = 0;
                    }
                }
                func_800574A4(spritenum);
            }
            break;
        }
        break;
    case 1512:
        switch (spr->unk2B)
        {
        case 0:
            if (i == 301)
            {
                if (func_80040D40(spr->x, spr->y, xpos, ypos) < 2500)
                {
                    spr->unk2B = 1;
                    spr->unk1A = 0;
                }
            }
            break;
        case 1:
            i = func_8004E5F8(spritenum, 0, 0, spr->unk1A);

            if (i >= 0xC000)
                func_80047820(spritenum, (i + 0x4000) & 0xFFFF, 1000);

            spr->unk1A += 400;
            k = (func_80096240(spr) - 8000);
            if (k < spr->z)
            {
                audio_800077F4(269, spritenum);
                func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 44, 4);
                func_8004BD24(spritenum);
            }
            break;
        }
        break;
    case 1563:
        switch (spr->unk2B)
        {
        case 0:
            if ((i == 301) && (func_80040D40(spr->x, spr->y, xpos, ypos) < 2500))
                spr->unk2B = 1;
            break;
        case 1:
            j = (gpSinTable[(spr->ang + 0x200) & 0x7FF] * 25) >> 13;
            i = (gpSinTable[spr->ang & 0x7FF] * 25) >> 13;
            spr->x += j;
            spr->y += i;
            sectnum = spr->sectnum;
            updateSector(spr->x, spr->y, &sectnum);

            if (sectnum != spr->sectnum)
                changeSpriteSect(spritenum, sectnum);

            if (spr->z < func_80096240(spr))
            {
                spr->unk2B = 2;
                spr->unk1A = 0;
            }
            break;
        case 2:
            i = func_8004E5F8(spritenum, 0, 0, spr->unk1A);

            if (i >= 0xC000)
                func_80047820(spritenum, (i  + 0x4000) & 0xFFFF, 1000);

            spr->unk1A += 200;
            k = func_80096240(spr);
            if (k < spr->z)
            {
                audio_800077F4(1056, spritenum);
                spr->z = k;
                spr->unk2B = 3;
            }
            break;
        }
        break;
    case 1398:
    case 1399:
        switch (spr->unk2B)
        {
        case 1:
            playSfx(579);
            func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 47, 0);
            spr->unk18 = 0;
            spr->unk2B++;
            break;
        case 2:
            spr->z -= 6000;
            spr->unk18++;
            if (spr->unk18 >= 21)
                spr->unk2B++;
            break;
        case 3:
            spr->z -= 9000;
            spr->xrepeat--;
            if (!(spr->xrepeat))
                func_800574A4(spritenum);
            break;
        }
        break;
    case 2282:
        switch (spr->unk2B)
        {
        case 0:
            if ((i == 301) && (func_80040D40(spr->x, spr->y, xpos, ypos) < 2500))
            {
                if (func_80096240(spr) != spr->z)
                    spr->unk2B = 2;
                else
                    spr->unk2B = 1;

                spr->unk1A = 0;
            }
            break;
        case 1:
            j = (gpSinTable[(spr->ang + 0x200) & 0x7FF] * 25) >> 13;
            i = (gpSinTable[spr->ang & 0x7FF] * 25) >> 13;
            ptr2->unk2 = (ptr2->unk2 + 0x96) & 0x7FF;
            k = func_80096240(spr) - 2500;
            if (k < spr->z)
            {
                spr->z = k;
                spr->unk1A = -spr->unk1A / 3;
            }
            else if ((k - spr->z) < 50000)
            {
                if (k != spr->z)
                    spr->unk1A += 400;
            }
            else
                spr->unk2B = 2;

            i = func_8004E5F8(spritenum, j * 8, i * 8, spr->unk1A);
            if (i < 0xC000)
            {
                if (i & 0xC000)
                {
                    spr->unk2B = 3;
                    goto block_603;
                }
            }
            else
                goto block_599;
            break;
        case 2:
            i = func_8004E5F8(spritenum, 0, 0, spr->unk1A);
            if (i >= 0xC000)
            {
            block_599:
                func_80047820(spritenum, (i + 0x4000) & 0xFFFF, 50);
                audio_800077F4(215, spritenum);
                func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 44, 2);
                func_800574A4(spritenum);
                break;
            }
            spr->unk1A += 400;
            k = func_80096240(spr);
            if (k < spr->z)
            {
                spr->z = k;
            block_603:
                audio_800077F4(215, spritenum);
                func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 44, 2);
                func_800574A4(spritenum);
            }
            break;
        }
        break;
    case 1688:
        switch (spr->unk2B)
        {
        case 0:
            if ((i == 301) && (func_80040D40(spr->x, spr->y, xpos, ypos) < 2500))
            {
                k = (func_800962D0(spr, 360) - 8000);
                if (k != spr->z)
                    spr->unk2B = 2;
                else
                    spr->unk2B = 1;

                spr->unk1A = 0;
            }
            break;
        case 1:
            j = ((gpSinTable[(spr->ang + 0x200) & 0x7FF] * 25) >> 13);
            i = ((gpSinTable[spr->ang & 0x7FF] * 25) >> 13);
            ptr2->unk2 = (ptr2->unk2 + 50) & 0x7FF;
            i = func_8004E5F8(spritenum, j* 8, i* 8, spr->unk1A);
            if (i < 0xC000)
            {
                if (i & 0xC000)
                {
                    audio_800077F4((krand() & 1) + 271, spritenum);
                    spr->unk2B = 3;
                    break;
                }
            }
            else
                func_80047820(spritenum, (i + 0x4000) & 0xFFFF, 1000);

            func_8009635C(spritenum, 9500, 900);
            temp_v0_13 = func_800962D0(spr, 360);
            k = temp_v0_13 - 8000;
            if (spr->z >= k)
            {
                spr->z = k;
                spr->unk1A = 0;
            }
            else if ((temp_v0_13 - spr->z) <= 49999)
            {
                if (k != spr->z)
                    spr->unk1A += 400;
            }
            else
                spr->unk2B = 2;

            break;
        case 2:
            i = func_8004E5F8(spritenum, 0, 0, spr->unk1A);

            if (i >= 0xC000)
                func_80047820(spritenum, (i + 0x4000) & 0xFFFF, 1000);

            spr->unk1A += 400;

            if (spr->unk25 == 0)
                func_8009635C(spritenum, 9500, 900);

            k = func_800962D0(spr, 360) - 8000;
            if (k < spr->z)
            {
                spr->unk2B = 4;
                spr->z = k;
            }

            if (k == spr->z)
                spr->unk1A = 0;
            break;
        case 4:
            func_8001F7B4(12, 12);
            func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 47, 0);
            func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 44, 4);
            func_8004BD24(spritenum);
        }
        break;
    case 2295:
    case 2297:
        if ((spr->unk2B == 0))
        {
            if ((i == 301) && (func_80040D40(spr->x, spr->y, xpos, ypos) < 600))
            {
                if (klabs((spr->z-z)) < 2500)
                {
                    spr->unk2B = 1;
                    spr->unk1A = 0;
                    spr->picnum = 2296;
                    func_80057540(&gpSprite[gPlayer[0].unk4A], 1500, 1, 0);
                    func_800494DC(gPlayer[0].unk4A, 100, spritenum, 0);
                    audio_800077F4(575, spritenum);
                    audio_80008574(0, 1485);
                }
            }
        }
        break;
    case 2410:
        switch (spr->unk2B)
        {
        case 1:
            audio_800077F4(1352, spritenum);
            spr->unk22 = 0;
            spr->unk2B = 2;
            break;
        case 2:
            ptr2->unk0 -= spr->unk22;
            spr->unk22 += 20;
            if (ptr2->unk0 < -350)
            {
                ptr2->unk0 = -350;
                spr->unk2B = 3;
            }
            break;
        case 3:
            spr->unk2B = 4;
            func_8006D3B8(spritenum, 42, 512, 20, -95);
            break;
        }
        break;
    case 2395:
        if (spr->unk2B == 1)
        {
            s32 nexti;
            if (spr->unk25 == 0)
            {
                spr->ang = (spr->ang - 0x80) & 0x7FF;
                spr->unk2B++;
                break;
            }

            i = gHeadSpriteStat[7];
            while (i >= 0)
            {
                nexti = gNextSpriteStat[i];
                if ((gpSprite[i].picnum == 41) && (gpSprite[i].hitag == spr->hitag))
                    func_8004BD24(i);

                i = nexti;
            }
            func_8004BD24(spritenum);
        }
        break;
    }
}

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
void func_8009A1A0(s32 spritenum)
{
    SpriteType *spr2;
    SpriteType *spr;
    s32 k, l;
    s16 i, j, nexti;
    s16 unk16;

    j = -1;
    spr = &gpSprite[spritenum];
    if (spr->unk2B == 0)
    {
        if (func_801C0FDC(0x800) < spr->ang)
        {
            i = gHeadSpriteStat[303];
            while (i >= 0)
            {
                spr2 = &gpSprite[i];
                nexti = gNextSpriteStat[i];
                if (i != spritenum)
                {
                    if (spr->hitag == spr2->hitag)
                    {
                        k = func_801C0FDC(10000);
                        j = i;
                        if (k < 5000)
                            goto label1;
                    }
                }
                i = nexti;
            }
            if (j != -1)
            {
                i = j;
            label1:
                spr->unk16 = i;
                spr->unk2B = 5;
                audio_80007820(((krand() % 2) + 57), spritenum);
            }
        }
    }
    else
    {
        spr->unk2B--;
        unk16 = spr->unk16;
        spr2 = &gpSprite[unk16];
        func_800867CC(unk16, spr2->x, spr2->y, spr2->z, spr->x, spr->y, spr->z, 64, 18);
        l = func_8009A020(spritenum, unk16);
        if (l != 0)
        {
            if (D_80106D50[l] != -1)
            {
                if ((D_8019B940[D_80106D50[l]].unk84 != 2) &&
                    (D_8019B940[D_80106D50[l]].unk84 != 5) &&
                    !(D_8019B940[D_80106D50[l]].unk0 & 0x2000))
                {
                    func_80057540(&gpSprite[l], 1500, 1, 0);
                    func_800494DC(l, 10, spritenum, 0);
                    audio_800077F4(870, spritenum);
                }
            }
        }
    }
}

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
                gpSprite[spritenum3].hitag = 3000;
                gpSprite[spritenum3].lotag = 1;
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
void func_8009A9B8(s32 spritenum)
{
    D_801AE9C4 = 50;
    D_80118250 = 50;
    D_8019910C = 0;
    D_8019964C = 0;
    D_8012FCAC = 120;
}

/*8009A9F0*/
void func_8009A9F0(s32 spritenum)
{
    s16 sectnum;
    SpriteType *spr;
    code0UnkStruct3 *ptr;
    s32 d1, d2;
    s32 x, y, z, x1, y1;
    s32 i, j, k;
    s32 ang, spritenum_;

    ptr = &D_8019B940[D_80106D50[spritenum]];
    spr = &gpSprite[spritenum];
    if (spr->unk2B != 0)
    {
        x = gPlayer[0].xpos;
        y = gPlayer[0].ypos;
        z = gpSprite[gPlayer[0].unk4A].z;

        if (spr->unk22 == 123)
        {
            ang = getAngle(x - spr->x, y - spr->y);
            if (func_80040D94(spr->x, spr->y, (spr->z - 32000) >> 4, x, y, z >> 4) < 6000)
            {
                gPlayer[0].xpos += (gpSinTable[(ang + 0x200) & 0x7FF] * 25) >> 10;
                gPlayer[0].ypos += (gpSinTable[ang & 0x7FF] * 25) >> 10;
            }

            if (!(D_8012FD88 & 0x1F))
                audio_80007820(1413, spritenum);

            func_8008E3E0((spr->x + ((krand() & 0xFFF) - 0x800)),
                          (spr->y + ((krand() & 0xFFF) - 0x800)),
                           spr->z - (krand() & 0x7FF), spr->sectnum, 41, 32);

            if (func_80042140(spritenum) < 119)
                func_80017268(spritenum);
            else
                func_8004BD24(spritenum);

            return;
        }

        func_80036280(spritenum, 0);
        func_80017268(spritenum);
        if (D_8012FCAC != 0)
        {
            D_8012FCAC--;
            return;
        }

        ang = getAngle(x - spr->x, y - spr->y);
        if (func_80040D40(spr->x, spr->y, x, y) < 3300)
        {
            func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 59, 0);
            gPlayer[0].xpos += (gpSinTable[(ang + 0x200) & 0x7FF] * 25) >> 10;
            gPlayer[0].ypos += (gpSinTable[ang & 0x7FF] * 25) >> 10;
            func_8003671C(0, 1, -1, -1);
            audio_80007820(1429, spritenum);
        }

        x = gPlayer[0].xpos;
        y = gPlayer[0].ypos;
        if (D_8019910C != 0)
        {
            x += gPlayer[0].unkC >> 8;
            y += gPlayer[0].unk10 >> 8;
        }

        if ((gPlayer[0].unkC == 0) && (gPlayer[0].unk10 == 0))
            D_8019910C = 0;
        else
        {
            if (D_8019910C != 0)
                D_8019910C--;
            else if ((krand() & 0x7FFF) < 3500)
                D_8019910C = 45;
        }

        ang = getAngle(x - spr->x, y - spr->y);
        i = func_80040D40(spr->x, spr->y, x, y);
        if (D_8012F908 != 0)
        {
            D_8012F908 = 0;
            d1 = getAngleDelta(getAngle(D_801A19F4 - spr->x, D_8012C798 - spr->y), spr->ang);

            /*TODO: klabs?*/
            if ((d1 > 0) && (d1 < 350))
            {
                if (D_801AE9C4 != 0)
                {
                    D_801AE9C4--;
                    if (D_801AE9C4 == 0)
                        goto block_37;
                }
                else if (D_80118250 != 0)
                {
                    D_80118250--;
                    if (D_80118250 == 0)
                        goto block_32;
                }
            }

            if ((d1 > -350) && (d1 < 0))
            {
                if (D_80118250 != 0)
                {
                    D_80118250--;
                    if (D_80118250 == 0)
                    {
                    block_32:
                        ptr->unk68 |= 0x1C0000;
                        spritenum_ = func_8008E3E0(spr->x, spr->y, spr->z - 0x800, spr->sectnum, 41, 32);
                        if (spritenum_ != -1)
                        {
                            gpSprite[spritenum_].x += (gpSinTable[(spr->ang + 0x300) & 0x7FF] * 375) >> 12;
                            gpSprite[spritenum_].y += (gpSinTable[(spr->ang + 0x100) & 0x7FF] * 375) >> 12;
                        }

                        func_8008E3E0(gpSprite[spritenum_].x, gpSprite[spritenum_].y, gpSprite[spritenum_].z, spr->sectnum, 41, 32);
                        audio_80007A44(1413, spritenum_, 40000);
                        func_8008E3E0(gpSprite[spritenum_].x, gpSprite[spritenum_].y, gpSprite[spritenum_].z, spr->sectnum, 60, 2);
                        func_8008E3E0(gpSprite[spritenum_].x, gpSprite[spritenum_].y, gpSprite[spritenum_].z, spr->sectnum, 60, 3);
                    }
                }
                else if (D_801AE9C4 != 0)
                {
                    D_801AE9C4--;
                    if (D_801AE9C4 == 0)
                    {
                    block_37:
                        ptr->unk68 |= 0x38000;
                        spritenum_ = func_8008E3E0(spr->x, spr->y, spr->z - 0x800, spr->sectnum, 41, 32);
                        if (spritenum_ != -1)
                        {
                            gpSprite[spritenum_].x += (gpSinTable[(spr->ang + 0x100) & 0x7FF] * 375) >> 12;
                            gpSprite[spritenum_].y += (gpSinTable[(spr->ang - 0x100) & 0x7FF] * 375) >> 12;
                        }

                        func_8008E3E0(gpSprite[spritenum_].x, gpSprite[spritenum_].y, gpSprite[spritenum_].z, spr->sectnum, 41, 32);
                        audio_80007A44(1413, spritenum_, 40000);
                        func_8008E3E0(gpSprite[spritenum_].x, gpSprite[spritenum_].y, gpSprite[spritenum_].z, spr->sectnum, 60, 0);
                        func_8008E3E0(gpSprite[spritenum_].x, gpSprite[spritenum_].y, gpSprite[spritenum_].z, spr->sectnum, 60, 1);
                    }
                }
            }
        }

        if (D_8019964C != 0)
        {
            switch (D_8019964C)
            {
            case 1:
                if ((func_80042140(spritenum) == 30) && (ptr->unk70 == 0))
                    ptr->unk70 = playSfx(1074);

                if (func_80042140(spritenum) == 59)
                {
                    if (ptr->unk70 != 0)
                    {
                        MusHandleStop(ptr->unk70, 0);
                        playSfx(1075);
                        ptr->unk70 = 0;
                    }
                }

                if (func_80042140(spritenum) != 79)
                {
                    if ((func_80042140(spritenum) >= 30) && (func_80042140(spritenum) < 61) && (D_8012FD88 & 1))
                    {
                        func_8006D3B8(spritenum, 38, 0, 220, -70);
                        func_8006D3B8(spritenum, 38, 0, 220, -70);
                        func_8006D3B8(spritenum, 38, 0, 220, -70);
                    }
                }
                else
                    D_8019964C = 0;
                break;

            case 2:
            case 3:
            case 4:
                if ((func_80042140(spritenum) == 35) && (ptr->unk70 == 0))
                {
                    ptr->unk70 = playSfx(705);
                    switch (D_8019964C)
                    {
                    case 2:
                        func_8006D3B8(spritenum, 39, 249, 274, -72);
                        func_8006D3B8(spritenum, 39, 1799, 274, -72);
                        break;
                    case 3:
                        func_8006D3B8(spritenum, 39, 249, 274, -72);
                        break;
                    case 4:
                        func_8006D3B8(spritenum, 39, 1799, 274, -72);
                        break;
                    }
                }

                if (func_80042140(spritenum) == 99)
                    D_8019964C = 0;
                break;
            case 5:
                if (func_80042140(spritenum) == 30)
                    D_8019964C = 0;
                break;
            }
        }
        else
        {
            if (gPlayer[0].unk45 != 0)
                func_80042124(ptr, 83);
            else
            {
                d2 = getAngleDelta(spr->ang, ang);
                spr->ang = (((spr->ang << 8) + (d2 * 16)) >> 8) & 0x7FF;
                j = 0;
                if (spr->sectnum != gPlayer[0].unk32)
                {
                    if ((i > 3000) && (i < 5000))
                        j = 50;
                    else
                    {
                        if (i >= 8000)
                        {
                            if (i > 9500)
                                j = 50;
                        }
                        else
                            j = -50;
                    }
                }
                else
                {
                    if (klabs(d2) < 0x100)
                    {
                        if (i > 3000)
                            j = 50;
                    }
                    else if (i < 2900)
                        j = -50;
                }

                x1 = (j * gpSinTable[(spr->ang + 0x200) & 0x7FF]) >> 14;
                y1 = (j * gpSinTable[spr->ang & 0x7FF]) >> 14;

                if (((x1 != 0) || (y1 != 0)))
                {
                    sectnum = spr->sectnum;
                    updateSector(spr->x + (x1 * 15), spr->y + (y1 * 15), &sectnum);
                    if (sectnum == spr->sectnum)
                    {
                        func_80042124(ptr, 85);
                        func_8004E5F8(spritenum, x1 * 8, y1 * 8, 0);
                    }
                    else
                    {
                        goto block_1; /*FAKEMATCH?*/
                    }
                    /*else if ((ptr->unk86 & 0x7FFF) != 83) {
                        audio_80007A44(1412, spritenum, 40000);
                        func_80042124(ptr, 83);
                    }*/
                }
                else
                {
                    if ((d2 >> 5) != 0)
                        func_80042124(ptr, 85);
                    else
                    {
                    block_1:
                        if ((ptr->unk86 & 0x7FFF) != 83)
                        {
                            audio_80007A44(1412, spritenum, 40000);
                            func_80042124(ptr, 83);
                        }
                    }
                }

                if (((ptr->unk86 & 0x7FFF) == 85) && ((func_80042140(spritenum) == 1) || (func_80042140(spritenum) == 20)))
                    audio_80007A44(1412, spritenum, 40000);

                if ((D_8019964C == 0))
                {
                    if ((i > 3000) && (((krand() & 0x3FFF) < 350)))
                    {
                        if ((krand() & 0x3FF) < 0x200)
                        {
                            ptr->unk70 = 0;
                            D_8019964C = 1;
                            func_80042124(ptr, 84);
                        }
                        else
                        {
                            k = krand() & 0x3FF;
                            if (k < 340)
                            {
                                if ((D_801AE9C4 != 0) && (D_80118250 != 0))
                                {
                                    ptr->unk70 = 0;
                                    D_8019964C = 2;
                                    playSfx((krand() & 1) + 1569);
                                    func_80042124(ptr, 88);
                                }
                            }
                            else if ((k >= 340) && (k < 680))
                            {
                                if (D_801AE9C4 != 0)
                                {
                                    ptr->unk70 = 0;
                                    D_8019964C = 4;
                                    playSfx((krand() & 1) + 1569);
                                    func_80042124(ptr, 89);
                                }
                            }
                            else if (D_80118250 != 0)
                            {
                                ptr->unk70 = 0;
                                D_8019964C = 3;
                                playSfx((krand() & 1) + 1569);
                                func_80042124(ptr, 90);
                            }
                        }
                    }
                }
            }
        }
        D_80118248 = spr;
        D_80137DE0 = ptr;
        D_800FE400 = spritenum;
        D_8012F6E8 = func_8005A240(spritenum);
        func_8004D884();
        func_8004DC74();
    }
}

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
                if (spr2->lotag == 100)
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
                    spr->cstat = 0x8000;

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
void func_8009C248(s32 spritenum)
{
    s32 x1, y1, x2, y2, x3, y3, x4, y4;
    code0UnkStruct5 *ptr2;
    SpriteType *spr;
    SpriteType *spr2;
    code0UnkStruct3 *ptr;
    f32 f1, f2, f3, f4, f5;
    s32 z, z1, z2, z3, z4, z5, z6;
    s32 sectnum;
    s32 spritenum1, spritenum2, spritenum3, spritenum4;
    s32 ang1;
    s32 xpos, ypos;
    s32 delta;
    s32 i, j, k, l, m;
    s16 ang;

    ptr = &D_8019B940[D_80106D50[spritenum]];
    spr = &gpSprite[spritenum];
    spr->xrepeat = 0x52;
    spr->yrepeat = 0x52;
    ptr2 = &D_8013B2D0[spritenum];

    if (D_8012FC94 != 0)
    {
        D_8012FC94--;
        func_80017268(spritenum);
        return;
    }

    if (D_8012FD74 != 0)
    {
        func_8009B974(spritenum);
        return;
    }

    if ((D_801ACBE0 == 0) && (ptr->unk8 < 5000))
    {
        audio_80008574(0, 1258);
        D_801ACBE0 = 1;
    }

    func_80017268(spritenum);
    func_80036280(spritenum, 0);

    if ((gPlayer[0].unk84 > 0) && (gPlayer[0].unk45 == 0))
    {
        gPlayer[0].xpos += ((gpSinTable[(gpSprite[gPlayer[0].unk4A].ang + 0x600) & 0x7FF] * 15) >> 12);
        gPlayer[0].ypos += ((gpSinTable[(gpSprite[gPlayer[0].unk4A].ang + 0x400) & 0x7FF] * 15) >> 12);
    }

    xpos = gPlayer[0].xpos;
    ypos = gPlayer[0].ypos;
    z1 = gpSprite[gPlayer[0].unk4A].z;

    ang1 = getAngle(xpos - spr->x, ypos - spr->y);

    if (func_80040D94(spr->x, spr->y, (spr->z - 32000) >> 4, xpos, ypos, z1 >> 4) < 3000)
    {
        spritenum3 = func_8008E3E0(spr->x, spr->y, spr->z - 32000, spr->sectnum, 67, 0);
        spritenum4 = func_8008E3E0(spr->x, spr->y, spr->z - 32000, spr->sectnum, 67, 1);

        if ((spritenum4 != -1) && (spritenum3 != -1))
            gpSprite[spritenum4].ang = gpSprite[spritenum3].ang;

        gPlayer[0].xpos += (gpSinTable[(ang1 + 0x200) & 0x7FF] * 5) >> 8;
        gPlayer[0].ypos += (gpSinTable[ang1 & 0x7FF] * 5) >> 8;
        audio_80007820(1429, spritenum);
    }

    sectnum = gPlayer[0].unk36;
    D_80197D48 = 0;
    spritenum1 = -1;

    if (sectnum > 0x1000)
        sectnum = gPlayer[0].unk32;

    z = gPlayer[0].zpos - 0x3900;
    if (sectnum != -1)
    {
        i = gHeadSpriteSect[sectnum];
        while (i >= 0)
        {
            spr2 = &gpSprite[i];
            if (spr2->statnum == 7)
            {
                if (spr2->lotag == 0)
                {
                    spritenum1 = i;
                    break;
                }
                else if (spr2->lotag == 20)
                {
                    s32 temp;
                    temp = spr2->hitag;
                    i = gHeadSpriteStat[7];
                    while (i >= 0)
                    {
                        spr2 = &gpSprite[i];
                        if ((spr2->hitag == temp) && (spr2->lotag == 21))
                        {
                            D_80197D48 = 1;
                            spritenum1 = i;
                            break;
                        }
                        i = gNextSpriteStat[i];
                    }
                    break;
                }
            }
            i = gNextSpriteSect[i];
        }
    }

    if ((spr->unk22 == 3) && (func_80042140(spritenum) == 49))
    {
        func_80042124(ptr, 75);
        spr->unk22 = 0;
    }

    if (spritenum1 == -1)
        return;

    switch (spr->unk2B)
    {
    case 0:
        if (((krand() & 0x7FFF) < 17000) &&
            (func_8009BED0(spr, xpos, ypos, z1, sectnum) != 0))
        {
            if (klabs(z1 - spr->z) <= 54999)
                spr->unk2B = 20;
            return;
        }
        else
        {
            if (D_80197D48 == 0)
            {
                if (spritenum1 != -1)
                {
                    i = gHeadSpriteSect[sectnum];
                    while (i >= 0)
                    {
                        spr2 = &gpSprite[i];
                        if (spr2->statnum == 7)
                        {
                            if (spr2->lotag == 10)
                            {
                                x1 = spr2->x;
                                y1 = spr2->y;
                            }
                            if (spr2->lotag == 11)
                            {
                                x2 = spr2->x;
                                y2 = spr2->y;
                            }
                        }
                        i = gNextSpriteSect[i];
                    }

                    x3 = ((x2 - x1) * (krand() & 0xFF)) / 255;
                    y3 = (y2 - y1) * (krand() & 0xFF) / 255;
                    D_801AE530 = x1 + x3;
                    D_80119A34 = spr->z - 1500;
                    D_80138698 = y1 + y3;

                    if (func_80040D40(gPlayer[0].xpos, gPlayer[0].ypos, D_801AE530, D_80138698) > 3500)
                    {
                        D_80199550 = spritenum1;
                        D_80199560 = 0;
                        D_800FE9E8 = 1200;
                        D_801AC8DC = 3;
                        spr->unk2B = 1;
                        if (func_80040D40(spr->x, spr->y, D_801AE530, D_80138698) > 10000)
                        {
                            func_80042124(ptr, 80);
                            spr->unk22 = 1;
                            D_800FE9E8 = 1200;
                        }
                    }
                }
                break;
            }

            i = gHeadSpriteStat[7];
            j = 99999999;
            spritenum2 = -1;
            while (i >= 0)
            {
                spr2 = &gpSprite[i];
                if (spr2->lotag == 21)
                {
                    k = func_80040D40(spr2->x, spr2->y, spr->x, spr->y);
                    if (k < j)
                    {
                        j = k;
                        spritenum2 = i;
                    }
                }
                i = gNextSpriteStat[i];
            }

            if ((spritenum1 != -1) && (spritenum2 != -1))
            {
                if (gpSprite[spritenum2].hitag == gpSprite[spritenum1].hitag)
                {
                    if (canSee(spr->x,
                        spr->y,
                        spr->z - 16000,
                        spr->sectnum,
                        xpos,
                        ypos,
                        z1 - 0x3900,
                        gpSprite[gPlayer[0].unk4A].sectnum) != 0)
                    {
                        f1 = func_80040D40(spr->x, spr->y, xpos, ypos);
                        z2 = (z1 + 20000);
                        z2 -= spr->z;
                        f5 = (func_80029FE0((z2 / 16), f1) * 325.9493234521802);

                        if (klabs(f5) < 256.0f)
                        {
                            if ((krand() & 0x7FFF) < 18000)
                            {
                                spr->unk2B = 3;
                                spr->unk22 = 10;
                                return;
                            }
                        }
                    }

                    /*TODO: They probably wanted to call func_80040D94 here*/
                    if (func_80040D40(spr->x, spr->y, spr->z >> 4, gpSprite[spritenum1].x, gpSprite[spritenum1].y, gpSprite[spritenum1].z>>4) < 3000)
                    {
                        s32 temp;
                        temp = getAngleDelta(spr->ang, getAngle(xpos - spr->x, ypos - spr->y)) << 13;
                        D_801B081C = 0;
                        spr->ang = GET_ANGLE(spr->ang, temp, 0);
                        return;
                    }
                    spritenum2 = gpSprite[spritenum2].hitag;
                }
                else
                {
                    if (gpSprite[spritenum2].hitag >= gpSprite[spritenum1].hitag)
                        spritenum2 = gpSprite[spritenum2].hitag - 1;
                    else
                        spritenum2 = gpSprite[spritenum2].hitag + 1;
                }

                i = gHeadSpriteStat[7];
                while (i >= 0)
                {
                    spr2 = &gpSprite[i];
                    if ((spr2->lotag == 21) && ((spr2->hitag == spritenum2)))
                    {
                        D_80199560 = 0;
                        D_800FE9E8 = 1200;
                        D_801AC8DC = 3;
                        D_801AE530 = spr2->x;
                        D_80138698 = spr2->y;
                        D_80119A34 = spr2->z + 12500;
                        spr->unk2B = 11;

                        if (func_80040D40(spr->x, spr->y, D_801AE530, D_80138698) > 10000)
                        {
                            func_80042124(ptr, 80);
                            spr->unk22 = 1;
                            D_800FE9E8 = 1200;
                        }
                        break;
                    }
                    i = gNextSpriteStat[i];
                }
            }
        }
        break;
    case 1:
        D_80119A34 += (krand() & 0x1FFF) - 0x1000;
        if (z < D_80119A34)
            D_80119A34 = z;

        if (D_80119A34 < (z - 65536))
            D_80119A34 = (z - 65536);

        if (spr->unk22 == 0)
            D_801B081C = D_800FE9E8 / 4;

        else
        {
            if ((func_80040D40(spr->x, spr->y, D_801AE530, D_80138698) < 4000) &&
                ((krand() & 0x7FFF) < 0x2000) &&
                (func_8009BED0(spr, xpos, ypos, z1, sectnum) != 0))
            {
                f2 = func_80040D40(spr->x, spr->y, xpos, ypos);
                z3 = (z1 + 20000);
                z3 -= spr->z;
                f5 = (func_80029FE0((z3 / 16), f2) * 325.9493234521802);

                if (klabs(f5) < 256.0f)
                {
                    spr->unk2B = 3;
                    spr->unk22 = 10;
                    return;
                }
            }
            D_801B081C = 0;
        }

        if (spr->unk22 == 1)
        {
            D_80119A34 -= 1500;
            if (func_80042140(spritenum) == 39)
            {
                func_80042124(ptr, 81);
                spr->unk22 = 2;
                D_800FE9E8 = 1220;
            }
        }

        if (spr->unk22 == 2)
            D_800FE9E8 += 20;

        l = func_80040D40(spr->x, spr->y, D_801AE530, D_80138698);
        if (l < 1500)
        {
            if (spr->unk22 == 2)
            {
                func_80042124(ptr, 82);
                spr->unk22 = 3;
            }
        }

        if (l < 3500)
        {
            if (D_800FE9E8 >= 200)
                D_800FE9E8 -= 10;
            else
                D_801AC8DC = 5;
        }

        if (l < 600)
        {
            D_80197DDC = D_80199550;
            if (((krand() & 0x7F) >= 64) && (gpSprite[spritenum].sectnum == gpSprite[D_80199550].sectnum))
            {
                if ((spritenum1 != -1) && (gpSprite[spritenum].sectnum != sectnum))
                {
                    D_801B081C = 0;
                    spr->unk2B = 2;
                    spr->unk1C = 0;
                    spr->unk22 = 4;
                }
                else
                    goto block_129;
            }
            else
                goto block_130;
        }
        else
        {
        block_129:
            D_80199560++;
            if (D_80199560 >= 121)
            {
            block_130:
                spr->unk2B = 0;
                D_801B081C = 0;
                if (spr->unk22 != 2)
                {
                    if (gpSprite[spritenum].sectnum == gpSprite[D_80199550].sectnum)
                        spr->unk2B = 5;
                }
                else
                {
                    func_80042124(ptr, 82);
                    spr->unk22 = 3;
                }
            }
            else
            {
                spr->unk1C = ((D_80119A34 - spr->z) >> 4);
                delta = (getAngleDelta(spr->ang, getAngle(D_801AE530 - spr->x, D_80138698 - spr->y)) << (D_801AC8DC + 8));
                spr->ang = GET_ANGLE(spr->ang, delta, 0);
                i = func_8004E5F8(spritenum,
                    (D_800FE9E8 * gpSinTable[(spr->ang + 0x200) & 0x7FF]) >> 14,
                    (D_800FE9E8 * gpSinTable[spr->ang]) >> 14, spr->unk1C);

                if (i >= 0xC000)
                    func_80047820(spritenum, (i + 0x4000) & 0xFFFF, 200);

                z4 = func_800962D0(spr, 600);
                if (z4 < spr->z)
                {
                    spr->z = z4;
                    func_80042124(ptr, 77);
                    spr->unk2B = 4;
                    spr->unk22 = 0;
                    D_801B081C = 0;
                }
            }
        }
        break;
    case 2:
        if (spr->unk22 != 6)
        {
            i = func_8004E5F8(spritenum, 0, 0, spr->unk1C);
            if (i >= 0xC000)
                func_80047820(spritenum, (i + 0x4000) & 0xFFFF, 200);
        }
        switch (spr->unk22)
        {
        case 4:
            spr->unk1C -= 500;
            if (spr->unk1C < -7500)
            {
                func_80042124(ptr, 76);
                spr->unk22 = 5;
            }
            break;
        case 5:
            spr->unk1C += 500;
            z4 = func_800962D0(spr, 600);
            if (z4 < spr->z)
            {
                spr->z = z4;
                func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 46, 0);
                func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 47, 0);

                if (gPlayer[0].unk59 != 0)
                    gPlayer[0].unk84 = 29;

                playSfx(1580);
                func_8001F7B4(12, 12);
                func_80042124(ptr, 77);
                spr->unk2B = 4;
                spr->unk22 = 0;
            }
            break;
        }
        break;
    case 3:
        switch (spr->unk22)
        {
        case 10:
            f3 = func_80040D40(spr->x, spr->y, xpos, ypos);
            z5 = (z1 + 20000);
            z5 -= spr->z;
            f5 = (func_80029FE0((z5 /16), f3) * 325.9493234521802);
            ptr2->unk2 = f5;
            delta = getAngleDelta(spr->ang, getAngle(xpos - spr->x, ypos - spr->y));
            spr->ang = GET_ANGLE(spr->ang, delta, 13);

            if (klabs(delta) < 32)
            {
                spr->unk22 = 11;
                func_80042124(ptr, 163);
            }
            break;
        case 11:
            if ((func_80042140(spritenum) >= 12) && (func_80042140(spritenum) < 22))
            {
                playSfx(1342);
                func_8006D3B8(spritenum, 48, -128, 200, -220);
            }

            if (func_80042140(spritenum) == 49)
            {
                func_80042124(ptr, 75);
                spr->unk2B = 0;
                spr->unk22 = 0;
            }
            break;
        }
        break;
    case 4:
        i = gHeadSpriteSect[gpSprite[spritenum].sectnum];
        while (i >= 0)
        {
            spr2 = &gpSprite[i];
            if (spr2->statnum == 7)
            {
                if (spr2->lotag == 50)
                    func_8006B590(spr2->hitag);
            }
            i = gNextSpriteSect[i];
        }

        if (func_80042140(spritenum) == 29)
        {
            D_8011BC58 = 0;
            spr->unk2B = 6;
        }
        break;
    case 5:
        delta = getAngleDelta(spr->ang, getAngle(xpos - spr->x, ypos - spr->y)) << 13;
        spr->ang = GET_ANGLE(spr->ang, delta, 0);
        i = func_8004E5F8(spritenum, 0, 0, spr->unk1C);

        if (i >= 0xC000)
            func_80047820(spritenum, (i + 0x4000) & 0xFFFF, 200);

        spr->unk1C += 500;
        z4 = func_800962D0(spr, 600);
        if (z4 < spr->z)
        {
            spr->z = z4;
            if (gPlayer[0].unk59 != 0)
                gPlayer[0].unk84 = 29;

            playSfx(1580);
            func_8001F7B4(12, 12);
            func_80042124(ptr, 77);
            spr->unk2B = 4;
            spr->unk22 = 0;
            D_801B081C = 0;
        }
        break;
    case 6:
        if (((spritenum1 != -1) && (spr->sectnum != sectnum)) || ((++D_8011BC58 >= 6) && (krand() & 0x7FFF) < 24000))
        {
            func_80042124(ptr, 117);
            audio_80007A44(1607, spritenum, 40000);
            spr->unk2B = 0xA;
            spr->unk22 = 0;
        }

        if (spr->unk2B == 6)
        {
            if (((krand() & 0x7FFF) < 0x1770) && (spritenum1 != -1) && (spr->sectnum == sectnum))
            {
                D_801AE530 = xpos;
                D_80138698 = ypos;
            }
            else if ((krand() & 0x7FFF) >= 21000)
            {
                if ((krand() & 0x7FFF) < 8000)
                {
                    spr->unk2B = 8;
                    func_80042124(ptr, 78);
                }
                else
                {
                    i = gHeadSpriteSect[gpSprite[spritenum].sectnum];
                    while (i >= 0)
                    {
                        spr2 = &gpSprite[i];
                        if (spr2->statnum == 7)
                        {
                            if (spr2->lotag == 10)
                            {
                                x1 = spr2->x;
                                y1 = spr2->y;
                            }
                            if (spr2->lotag == 11)
                            {
                                x2 = spr2->x;
                                y2 = spr2->y;
                            }
                        }
                        i = gNextSpriteSect[i];
                    }
                    x4 = ((x2 - x1) * (krand() & 0xFF)) / 255;
                    y4 = (y2 - y1) * (krand() & 0xFF) / 255;
                    D_801AE530 = x1 + x4;
                    D_80138698 = y1 + y4;
                    func_80042124(ptr, 106);
                    D_801AC8DC = 5;
                    D_80199560 = 0;
                    spr->unk2B = 7;
                }
            }
            else
            {
                ptr->unk44 = gPlayer[0].xpos;
                ptr->unk48 = gPlayer[0].ypos;
                ptr->unk4C = gpSprite[gPlayer[0].unk4A].z - 0x1C80;
                spr->unk2B = 9;
                func_80042124(ptr, 110);
                break;
            }
        }
        break;
    case 7:
        if ((func_80042140(spritenum) == 5) || (func_80042140(spritenum) == 35))
        {
            playSfx(1581);
            func_8001F7B4(6, 6);
        }
        l = func_80040D40(spr->x, spr->y, D_801AE530, D_80138698);
        if ((krand() & 0x7FFF) < 21000)
        {
            ptr->unk44 = gPlayer[0].xpos;
            ptr->unk48 = gPlayer[0].ypos;
            ptr->unk4C = gpSprite[gPlayer[0].unk4A].z - 0x1C80;
            spr->unk2B = 9;
            func_80042124(ptr, 110);
            break;
        }
        D_80199560++;
        if (D_80199560 >= 121)
            spr->unk2B = 6;

        if (l >= 600)
        {
            s32 temp;
            delta = (getAngleDelta(spr->ang, getAngle(D_801AE530 - spr->x, D_80138698 - spr->y)) << (D_801AC8DC + 8));
            spr->ang = GET_ANGLE(spr->ang, delta, 0);
            temp = ((gpSinTable[(spr->ang + 0x200) & 0x7FF] * 325) >> 13);
            i = func_8004E5F8(spritenum,
                (temp),
                (gpSinTable[spr->ang] * 325) >> 13, spr->unk1C);

            if (i >= 0xC000)
                func_80047820(spritenum, (i + 0x4000) & 0xFFFF, 200);

            if (i & 0xC000)
                spr->unk2B = 6;

            z4 = func_800962D0(spr, 600);
            if (z4 < spr->z)
            {
                spr->z = z4;
                spr->unk1C = 0;
            }
            else
                spr->unk1C += 100;
        }
        else
        {
            spr->unk2B = 6;
        }
        break;
    case 8:
        if (func_80042140(spritenum) == 30)
        {
            if (gPlayer[0].unk59 != 0)
                gPlayer[0].unk84 = 29;

            playSfx(1580);
            func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 46, 0);
            func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 47, 0);
            func_8001F7B4(12, 12);
            i = gHeadSpriteSect[gpSprite[spritenum].sectnum];
            while (i >= 0)
            {
                spr2 = &gpSprite[i];
                if (spr2->statnum == 7)
                {
                    if (spr2->lotag == 50)
                        func_8006B590(spr2->hitag);
                }
                i = gNextSpriteSect[i];
            }
        }
        if (func_80042140(spritenum) == 35)
            spr->unk2B = 6;
        break;
    case 9:
        delta = getAngleDelta(spr->ang, getAngle(xpos - spr->x, ypos - spr->y)) << 13;
        spr->ang = GET_ANGLE(spr->ang, delta, 0);
        if (func_80042140(spritenum) == 26)
        {
            spr->unk22 = (krand() & 1) + 20;
            switch (spr->unk22)
            {
            case 20:
                playSfx(585);
                break;

            case 21:
                playSfx(1337);
                break;
            }
        }

        if (func_80042140(spritenum) == 38)
            spr->unk2B = 6;

        if (func_80042140(spritenum) >= 27)
        {
            switch (spr->unk22)
            {
            case 20:
                func_8006D3B8(spritenum, 27, 0, 200, -200);
                break;
            case 21:
                func_8006D3B8(spritenum, 44, 0, 200, -160);
                break;
            }
        }
        break;
    case 10:
        D_801B081C = 0;
        if (func_80042140(spritenum) >= 40)
            spr->z -= 2000;

        if (func_80042140(spritenum) == 59)
        {
            func_80042124(ptr, 75);
            spr->unk2B = 0;
        }
        break;
    case 11:
        if (z < D_80119A34)
            D_80119A34 = z;

        if (D_80119A34 < (z -65536))
            D_80119A34 = (z -65536);

        if (spr->unk22 == 0)
            D_801B081C = D_800FE9E8/4;
        else
            D_801B081C = 0;

        if ((spr->unk22 == 1) && (func_80042140(spritenum) == 39))
        {
            func_80042124(ptr, 81);
            spr->unk22 = 2;
            D_800FE9E8 = 1220;
        }

        if (spr->unk22 == 2)
            D_800FE9E8 += 20;

        l = func_80040D94(spr->x, spr->y, spr->z >> 4, D_801AE530, D_80138698, D_80119A34 >> 4);
        if (l < 2000)
        {
            if (spr->unk22 == 2)
            {
                func_80042124(ptr, 82);
                spr->unk22 = 3;
            }
        }

        if (l < 1500)
        {
            if (D_800FE9E8 >= 200)
                D_800FE9E8 -= 10;
            else
                D_801AC8DC = 5;
        }

        if ((l < 1000) || (++D_80199560 > 120))
        {
            spr->unk2B = 0;
            D_801B081C = 0;
            if (spr->unk22 == 2)
            {
                func_80042124(ptr, 82);
                spr->unk22 = 3;
            }
        }
        else
        {
            spr->unk1C = ((D_80119A34 - spr->z) >> 4);
            delta = (getAngleDelta(spr->ang, getAngle(D_801AE530 - spr->x, D_80138698 - spr->y)) << (D_801AC8DC + 8));
            spr->ang = GET_ANGLE(spr->ang, delta, 0);
            i = func_8004E5F8(spritenum,
                (D_800FE9E8 * gpSinTable[(spr->ang + 0x200) & 0x7FF]) >> 14,
                (D_800FE9E8 * gpSinTable[spr->ang]) >> 14, spr->unk1C);

            if (i >= 0xC000)
                func_80047820(spritenum, (i + 0x4000) & 0xFFFF, 200);

            z4 = func_800962D0(spr, 600);
            if (z4 < spr->z)
            {
                spr->z = z4;
                func_80042124(ptr, 77);
                spr->unk2B = 4;
                spr->unk22 = 0;
                D_801B081C = 0;
            }
        }
        break;
    case 20:
        D_80118244 = (krand() & 0x3F) - 0x1F;

        if (D_80118244 <= 0)
            D_80118244 = -512;
        else
            D_80118244 = 512;

        D_80199984 = (krand() & 0x1F) + 1;
        spr->unk2B++;
        break;
    case 21:
        D_80119A34 += (krand() & 0x1FFF) - 0x1000;
        if (z < D_80119A34)
            D_80119A34 = z;

        if (D_80119A34 < (z -65536))
            D_80119A34 = (z -65536);

        ang1 = getAngle(xpos - spr->x, ypos - spr->y);
        delta = (getAngleDelta(spr->ang, ang1) << 13);
        ang = GET_ANGLE(spr->ang, delta, 0);
        spr->ang = ang;
        delta = (ang1 + D_80118244) & 0x7FF;
        i = func_8004E5F8(spritenum,
            (gpSinTable[(delta + 0x200) & 0x7FF] * 175) >> 12,
            (gpSinTable[delta] * 175) >> 12, (D_80119A34 - spr->z) >> 4);

        if (i >= 0xC000)
            func_80047820(spritenum, (i + 0x4000) & 0xFFFF, 200);

        if (D_80199984 != 0)
            D_80199984--;
        else if ((krand() & 0x7FFF) < 0x1000)
            spr->unk2B = 0;
        else if (func_8009BED0(spr, xpos, ypos, z1, sectnum) != 0)
        {
            if (func_80040D40(spr->x, spr->y, xpos, ypos) >= 25000)
                spr->unk2B = 0;
            else if ((krand() & 0x7FFF) < 20000)
            {
                spr->unk2B = 22;
                spr->unk22 = 10;
            }
            else
                spr->unk2B = 20;
        }
        else
            spr->unk2B = 0;
        break;
    case 22:
        switch (spr->unk22)
        {
        case 10:
            f4 = func_80040D40(spr->x, spr->y, xpos, ypos);
            z6 = (z1 + 20000);
            z6 -= spr->z;
            f5 = (func_80029FE0((z6 / 16), f4) * 325.9493234521802);
            ptr2->unk2 = f5;
            delta = getAngleDelta(spr->ang, getAngle(xpos - spr->x, ypos - spr->y));
            spr->ang = GET_ANGLE(spr->ang, delta, 13);
            if (klabs(delta) < 32)
            {
                m = krand() & 1;
                if (m == 0)
                    func_80042124(ptr, 163);
                else
                    func_80042124(ptr, 164);
                spr->unk22 = m + 11;
            }
            break;
        case 11:
            if ((func_80042140(spritenum) >= 11) && (func_80042140(spritenum) < 22))
            {
                playSfx(1342);
                func_8006D3B8(spritenum, 48, -128, 200, -220);

            }
            if (func_80042140(spritenum) == 49)
            {
                func_80042124(ptr, 75);
                spr->unk2B = 20;
                spr->unk22 = 0;
            }
            break;
        case 12:
            if ((func_80042140(spritenum) >= 11) && (func_80042140(spritenum) < 22))
            {
                playSfx(1113);
                func_8006D3B8(spritenum, 49, 128, 200, -220);
            }
            if (func_80042140(spritenum) == 49)
            {
                func_80042124(ptr, 75);
                spr->unk2B = 20;
                spr->unk22 = 0;
            }
            break;
        }
        break;
    }

    if (spr->unk2B != 3)
        ptr2->unk2 = (ptr2->unk2 + ((D_801B081C - ptr2->unk2) >> 4)) & 0x7FF;
}

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
void func_8009E8C8(s32 spritenum)
{
    SpriteType *spr;
    SpriteType *spr2;
    code0UnkStruct3 *ptr;
    code0UnkStruct5 *ptr2;

    s16 ang;
    s32 x, y, z;
    s32 x1, y1, z1;
    u16 cstat;
    s32 i, j, k, l, m;

    s32 s1, s2, s3;
    s32 ang2;

    s1 = -1;
    s2 = -1;
    s3 = -1;

    ptr = &D_8019B940[D_80106D50[spritenum]];
    spr = &gpSprite[spritenum];
    ptr2 = &D_8013B2D0[spritenum];

    ang = gHeadSpriteStat[302];
    i = ang; /*FAKEMATCH*/

    while (i >= 0)
    {
        spr2 = &gpSprite[i];
        if (spr2->picnum == 2562)
            s1 = i;

        if (spr2->picnum == 2563)
            s2 = i;

        if (spr2->picnum == 2564)
            s3 = i;

        i = gNextSpriteStat[i];
    }

    spr->xrepeat = 0x80;
    spr->yrepeat = 0x80;

    if (spr->unk2B != 21)
    {
        func_80036280(spritenum, 0);
        func_80017268(spritenum);

        if (s1 != -1)
        {
            ang = getAngle(gPlayer[0].xpos - gpSprite[s1].x, gPlayer[0].ypos - gpSprite[s1].y);
            ang2 = getAngleDelta(ang, (spr->ang - 512) & 0x7FF);

            ang2 = MIN(MAX(ang2, -290), 290);
            D_8013B2D0[s1].unk4 = func_80095FCC(D_8013B2D0[s1].unk4, ang2, 5);
        }

        if (s2 != -1)
        {
            ang = getAngle(gPlayer[0].xpos - gpSprite[s2].x, gPlayer[0].ypos - gpSprite[s2].y);
            ang2 = getAngleDelta(ang, (spr->ang + 512) & 0x7FF);

            ang2 = MIN(MAX(ang2, -290), 290);
            ang = D_8013B2D0[s2].unk4; /*FAKEMATCH*/
            D_8013B2D0[s2].unk4 = func_80095FCC(ang, ang2, 5);
        }

        if (s3 != -1)
        {
            ang = getAngle(gPlayer[0].xpos - gpSprite[s3].x, gPlayer[0].ypos - gpSprite[s3].y);
            ang2 = getAngleDelta(ang, (spr->ang + 1024) & 0x7FF);
            D_8013B2D0[s3].unk4 = func_80095FCC(D_8013B2D0[s3].unk4, ang2, 5);
        }

        if (D_80199948 == 0)
        {
            if (ptr2->handle != 0)
                ptr2->handle = audio_80007A80(ptr2->handle, spritenum, 40000);
            else
                ptr2->handle = audio_80007A44(1068, spritenum, 40000);
        }

        x = gPlayer[0].xpos;
        y = gPlayer[0].ypos;
        z = gpSprite[gPlayer[0].unk4A].z;

        if (ptr->unk8 < 3750)
        {
            z1 = 0x1000;
            if (ptr->unk8 < 2500)
                z1 = 0x2000;

            if (ptr->unk8 < 1250)
                z1 = 0x4000;

            if ((D_8012FD88 & 3) && ((krand() & 0x7FFF) < z1))
            {
                x1 = spr->x + ((gpSinTable[(spr->ang + 0x600) & 0x7FF] * 625) >> 12);
                y1 = spr->y + ((gpSinTable[(spr->ang + 0x400) & 0x7FF] * 625) >> 12);
                z1 = spr->z - 16000;

                func_8001DBA0((x1 / 2), (y1 / 2), (z1 / 32), 11, 11, 5);
            }
        }

    loop_38:
        j = func_80095F58(0, spr->unk22);
        if (j == -1)
        {
            spr->unk22 = 0;
            goto loop_38;
        }

        ang = getAngle(gPlayer[0].xpos - spr->x, gPlayer[0].ypos - spr->y);
        switch (spr->unk2B)
        {
        case 0:
            if (D_8012F908 != 0)
            {
                D_8012F908 = 0;
                if (D_80105540 != 0)
                {
                    D_80105540 = 0;
                    func_80042124(ptr, 70);
                }
                else if ((krand() & 0x7FFF) < 10000)
                {
                    func_80042124(ptr, 66);
                }
            }

            if (((ptr->unk86 & 0x7FFF) == 70) && (func_80042140(spritenum) == 21))
                func_80042124(ptr, 71);

            if (((ptr->unk86 & 0x7FFF) == 66) && (func_80042140(spritenum) == 60))
                func_80042124(ptr, 71);


            ang2 = getAngleDelta(spr->ang, getAngle(gpSprite[j].x - spr->x, gpSprite[j].y - spr->y));
            spr->ang = GET_ANGLE(spr->ang, ang2, 13);

            l = func_80040D40(spr->x, spr->y, gpSprite[j].x, gpSprite[j].y);
            if ((klabs(getAngleDelta((spr->ang + 0x400) & 0x7FF, ang)) < 64) && ((krand() & 0x7FFF) < 2000))
            {
                D_80199964 ^= 1;
                if (D_80199964 == 0)
                    spr->unk22++;
                else
                    spr->unk22--;

                if (spr->unk22 < 0)
                    spr->unk22 = 3;

                if (spr->unk22 >= 4)
                    spr->unk22 = 0;

                spr->unk2B = 1;
            }
            else
            {
                if (l < 600)
                {
                    if (D_80199964 == 0)
                        spr->unk22++;
                    else
                        spr->unk22--;

                    if (spr->unk22 < 0)
                        spr->unk22 = 3;

                    if (spr->unk22 >= 4)
                        spr->unk22 = 0;

                    spr->unk2B = 1;
                }

                ang2 = (gpSinTable[(spr->ang + 0x200) & 0x7FF] * 325) >> 13;
                m = func_8004E5F8(spritenum, ang2,
                                  (gpSinTable[spr->ang & 0x7FF] * 325) >> 13, 1000);

                if ((m >= 0xC000) && (gpSprite[(m + 0x4000) & 0xFFFF].statnum == 10))
                    func_800365C0(0);

                if ((ptr->unk86 & 0x7FFF) == 71)
                {
                    D_801AC594++;
                    if (D_801AC594 > 32)
                    {
                        D_801AC594 = 64;
                        if (((krand() & 0x7FFF) < 1000) &&
                            (canSee(spr->x, spr->y, (spr->z - 16000), spr->sectnum,
                                x, y, z, gpSprite[gPlayer[0].unk4A].sectnum) != 0))
                        {
                            D_801AC594 = 0;
                            playSfx(1594);
                            cstat = spr->cstat;
                            spr->cstat = cstat & 0xFEFE;
                            func_80095B20(s3, 36, 0.0f, -35.0f, -215.0f, 0x400);
                            spr->cstat = cstat;
                        }

                        if ((krand() & 0x7FFF) < 1000)
                        {
                            D_801AC594 = 0;
                            if (klabs(getAngleDelta((spr->ang + 0x200) & 0x7FF, ang)) < 290)
                            {
                                playSfx(705);
                                cstat = spr->cstat;
                                spr->cstat = cstat & 0xFEFE;
                                func_80095B20(s2, 47, -210.0f, 0.0f, 16.0f, 0x200);
                                spr->cstat = cstat;
                            }
                            else if (klabs(getAngleDelta((spr->ang - 0x200) & 0x7FF, ang)) < 290)
                            {
                                playSfx(705);
                                cstat = spr->cstat;
                                spr->cstat = cstat & 0xFEFE;
                                func_80095B20(s1, 47, 210.0f, 0.0f, 16.0f, -0x200);
                                spr->cstat = cstat;
                            }
                        }
                    }
                }
            }
            break;
        case 1:
            i = getAngleDelta(spr->ang, getAngle(gpSprite[j].x - spr->x, gpSprite[j].y - spr->y));
            spr->ang = GET_ANGLE(spr->ang, i, 12);
            if (klabs(i) < 24)
            {
                if ((ptr->unk86 & 0x7FFF) != 71)
                    playSfx(((krand() % 3) + 1071));

                func_80042124(ptr, 71);
                spr->unk2B = 0;
            }
            else if (i < 0)
            {
                if ((ptr->unk86 & 0x7FFF) != 68)
                    playSfx(((krand() % 3) + 1071));

                func_80042124(ptr, 68);
            }
            else
            {
                if ((ptr->unk86 & 0x7FFF) != 69)
                {
                    playSfx(((krand() % 3) + 1071));
                }
                func_80042124(ptr, 69);
            }
            break;
        case 20:
            if (func_80042140(spritenum) == 104)
            {
                spr->unk2B = 21;
                func_8006B590(3001);
                return;
            }
            break;
        }

        func_8009E734(spritenum);
        k = func_80096240(spr);
        func_8009635C(spritenum, 16000, 3000);

        if (k < spr->z)
            spr->z = k;

        func_80015DE0(spritenum);
    }
}

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
                gpSprite[spritenum].y) > 4000)
            {
                return i;
            }
        }
        i = gNextSpriteStat[i];
    }
    return -1;
}

/*8009F71C*/
static void func_8009F71C(s32 spritenum)
{
    SpriteType *spr;
    SpriteType *spr2;
    code0UnkStruct3 *ptr;
    s32 i, j, k, l;
    u16 m;

    spr2 = gpSprite; /*FAKEMATCH?*/
    ptr = &D_8019B940[D_80106D50[spritenum]];
    spr = &spr2[spritenum];

    if (spr->unk2B == 1)
    {
        if (ptr->unk6C == 0)
            ptr->unk6C = audio_80007A44(150, spritenum, 40000);

        spr->unk1A = 0;
        spr->unk2B = 2;
        spr->cstat &= 0x7FFF;
    }

    if (ptr->unk6C != 0)
        audio_80007A80(ptr->unk6C, spritenum, 40000);

    if (spr->unk2B != 0xFF)
    {
        i = func_80095F58(spr->unk1A, spr->lotag);
        if (i == -1)
        {
            if (spr->unk25 != 0)
                playSfx(1446);

            if (ptr->unk6C != 0)
                MusHandleStop(ptr->unk6C, 0);

            spr->unk2B = 0xFF;
        }
        else
        {
            if (func_80040D40(gpSprite[i].x, gpSprite[i].y, spr->x, spr->y) < 500)
                spr->unk1A++;

            i = getAngleDelta(spr->ang, getAngle(gpSprite[i].x - spr->x, gpSprite[i].y - spr->y)) << 11;
            spr->ang = GET_ANGLE(spr->ang, i, 0);
            ptr->unk7C = GET_ANGLE(ptr->unk7C, i, 0);

            j = (gpSinTable[(spr->ang + 0x200) & 0x7FF] * 5) >> 8;
            k = (gpSinTable[spr->ang & 0x7FF] * 5) >> 8;
            l = func_8004E5F8(spritenum, j, k, 0);

            if (l >= 0xC000)
            {
                m = (l + 0x4000);
                if (gpSprite[m].statnum == 10)
                    func_800365C0(0);
                else
                    func_80047820(spritenum, m, 300);
            }
        }
    }

    if (spr->unk25 == 0)
        i = func_80096028(spritenum);
    else
    {
        i = -1;
        if (spr->unk1A == 2)
            i = func_8009F648(spritenum);
    }

    if (i != -1)
    {
        ptr->unk44 = i;
        ptr->unk7C = func_80095FCC(ptr->unk7C,
                                   getAngleDelta(getAngle(gpSprite[i].x - spr->x, gpSprite[i].y - spr->y), spr->ang) & 0x7FF, 5);
        spr->unk22++;
        if (spr->unk22 > 32)
        {
            spr->unk22 = 0;
            audio_80007A44(217, spritenum, 40000);
            func_8006D3B8(spritenum, 37, -ptr->unk7C, 310, 0);
        }
    }

    if (spr->unk2B != 0xFF)
        func_80096494(spritenum, 20000, 1500);
}
