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
#include "code0/6D9E0.h"
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

/*.data*/
/*800E1770*/ static s32 D_800E1770 = 0;
static s32 _unused[3] = {0};

/*800E1780*/
static char *D_800E1780[8] = {
#if defined(VERSION_US) || defined(VERSION_EU) || defined(VERSION_PROTO)
    "ARMOR",
    "SCUBA GEAR",
    "VITAMIN X",
    "PROTECTIVE BOOTS",
    "MEDKIT",
    "NIGHT VISION",
    "GAS MASK",
    "COMPUTER",
#elif VERSION_FR
    "ARMURE",
    "TUBA",
    "VITAMINE X",
    "BOTTES DE SECURITE",
    "KIT",
    "LUNETTES",
    "MASQUE A GAZ",
    "COMPUTER",
#endif
};

/*800E17A0*/
static char *D_800E17A0[8] = {
#if defined(VERSION_US) || defined(VERSION_EU) || defined(VERSION_PROTO)
    "ARMOR",
    "DIVING HELMET",
    "VITAMIN X",
    "PROTECTIVE BOOTS",
    "DOCTOR'S BAG",
    "NIGHT VISION",
    "GAS MASK",
    "COMPUTER",
#elif VERSION_FR
    "ARMURE",
    "CASQUE DE SCAPHANDRE",
    "VITAMINE X",
    "BOTTES DE SECURITE",
    "TROUSSE DE SOINS",
    "LUNETTES",
    "MASQUE A GAZ",
    "COMPUTER",
#endif
};

/*800E17C0*/
static char *D_800E17C0[8] = {
#if defined(VERSION_US) || defined(VERSION_EU) || defined(VERSION_PROTO)
    "",
    "ON",
    "USED",
    "",
    "USED",
    "ACTIVATED",
    "ON",
    "",
#elif VERSION_FR
    "",
    "ACTIVE",
    "UTILISEES",
    "",
    "UTILISEES",
    "ACTIVEES",
    "ACTIVE",
    "",
#endif
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
/*801AEE40*/ _95500UnkStruct1 D_801AEE40[200] ALIGNED(16);

/*.text*/

/*80094900*/
static _95500UnkStruct1 *func_80094900(s32 x, s32 y, s32 z, s16 sectnum)
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
            ptr->unk12 = sectnum;
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
    u16 sectnum;

    z = gPlayer[0].zpos;
    x = gPlayer[0].xpos;
    y = gPlayer[0].ypos;
    sectnum = gPlayer[0].cursectnum;

    x += (((krand() & 0x3FF) - 512) * 10);
    y += (((krand() & 0x3FF) - 512) * 10);
    z -= 0x3900;
    z -= ((krand() & 0x1FFF) * 10);

    if (func_80094900(x, y, z, sectnum) != NULL)
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
    initVertexList();
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

            gSPVertex(gpDisplayList++, gpVertexList, 3, 0);
            gpVertexList += 3;
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
    if ((j > 0) && (gpSector[gPlayer[0].cursectnum].ceilingstat & 1))
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
    unk32 = gPlayer[0].cursectnum;

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
    initVertexList();
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

            gSPVertex(gpDisplayList++, gpVertexList, 3, 0);
            gpVertexList += 3;
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
    if ((j > 0) && (gpSector[gPlayer[0].cursectnum].ceilingstat & 1))
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

    if ((gMapChapter[gMapNum].chapter == WESTERN) || (gMapChapter[gMapNum].chapter == VICTORIAN))
        ptr = D_800E17A0;
    else
        ptr = D_800E1780;

    for (i = 0; i < D_8012C470; i++)
    {
        ptr2 = &D_8010A940[i];

        if (D_8012F6E4[gPlayer[i].skin].unkB == 5)
        {
            ptr2->unk2[5] = 0;
            ptr2->unk2[6] = 0;
        }

        unk2 = ptr2->unk2[1];
        ptr2->unkA[0] = gActor[gActorSpriteMap[gPlayer[i].unk4A]].unk7E;
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
#if defined(VERSION_US) || defined(VERSION_EU) || defined(VERSION_PROTO)
                sprintf(sp10, "%s ON", ptr[1]);
#elif VERSION_FR
                sprintf(sp10, "%s ACTIVE", ptr[1]);
#endif
            }
            else
            {
#if defined(VERSION_US) || defined(VERSION_EU) || defined(VERSION_PROTO)
                sprintf(sp10, "%s OFF", ptr[1]);
#elif VERSION_FR
                sprintf(sp10, "%s DESACTIVE", ptr[1]);
#endif
            }

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
#if defined(VERSION_US) || defined(VERSION_EU) || defined(VERSION_PROTO)
                sprintf(sp10, "%s OFF", ptr[5]);
#elif VERSION_FR
                sprintf(sp10, "%s DESACTIVE", ptr[5]);
#endif
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
#if defined(VERSION_US) || defined(VERSION_EU) || defined(VERSION_PROTO)
                sprintf(sp10, "%s OFF", ptr[6]);
#elif VERSION_FR
                sprintf(sp10, "%s DESACTIVE", ptr[6]);
#endif
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
        if (D_8012F6E4[gPlayer[i].skin].unkB == 5)
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
    Actor *actor;
    s16 min;
    s8 cond;

    cond = -1;
    ptr = D_800E1780;
    ptr1 = &D_8010A940[playernum];
    actor = &gActor[gActorSpriteMap[gPlayer[playernum].unk4A]];

    if ((gMapChapter[gMapNum].chapter == WESTERN) || (gMapChapter[gMapNum].chapter == VICTORIAN))
        ptr = D_800E17A0;

    switch (ptr1->unk0)
    {
    case 2:
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
    case 5:
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
    case 6:
        if (ptr1->unkA[6] > 0)
        {
            cond = ptr1->unk2[6] == 0;
            ptr1->unk2[6] = cond;
        }
        else
            ptr1->unk2[6] = 0;

        break;
    case 4:
        if (ptr1->unkA[4] > 0)
        {
            if (actor->unk8 < gPlayer[playernum].unk48)
            {
                min = MIN(ptr1->unkA[4], (gPlayer[playernum].unk48 - actor->unk8));
                actor->unk8 += min;
                ptr1->unkA[4] -= min;
                cond = 1;
                audio_800080E0(playernum, 5);
            }
        }
        break;
    case 7:
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
        {
#if defined(VERSION_US) || defined(VERSION_EU) || defined(VERSION_PROTO)
            sprintf(buffer, "%s OFF", ptr[ptr1->unk0]);
#elif VERSION_FR
            sprintf(buffer, "%s DESACTIVE", ptr[ptr1->unk0]);
#endif
        }

        func_800A419C(playernum, buffer);
    }
}
