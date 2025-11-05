#include "common.h"
#include "string.h"
#include "code0/main.h"
#include "code0/audio.h"
#include "code0/graphics.h"
#include "code0/pragmas.h"
#include "code0/debug.h"
#include "code0/4600.h"
#include "code0/9410.h"
#include "code0/FDE0.h"
#include "code0/17B30.h"
#include "code0/1A7C0.h"
#include "code0/1E7A0.h"
#include "code0/viewport.h"
#include "code0/24610.h"
#include "code0/37090.h"
#include "code0/3FAD0.h"
#include "code0/41940.h"
#include "code0/64530.h"
#include "code0/6ACA0.h"
#include "code0/8E670.h"
#include "code0/8EFE0.h"
#include "code0/95500.h"
#include "code0/96A80.h"
#include "code0/A06F0.h"
#include "code0/code0.h"
#include "code1/code1.h"
#include "code1/EB300.h"
#include "static/mapinfo.h"

/*.data*/
/*800E18D0*/
static Lights2 D_800E18D0 = {
    { { { 20, 20, 20 }, 0, { 20, 20, 20 }, 0 } },
    {
        { { { 0, 0, 0 }, 0, { 0, 0, 0 }, 0, { 32, 64, 0 }, 0 } },
        { { { 255, 255, 255 }, 0, { 255, 255, 255 }, 0, { 32, 32, 32 }, 0 } },
    },
};

/*800E18F8*/
static Lights2 D_800E18F8 = {
    { { { 255, 255, 255 }, 0, { 255, 255, 255 }, 0 } },
    {
        { { { 0, 0, 0 }, 0, { 0, 0, 0 }, 0, { 32, 64, 0 }, 0 } },
        { { { 0, 0, 0 }, 0, { 0, 0, 0 }, 0, { 32, 32, 32 }, 0 } },
    },
};

/*800E1920*/
static Color D_800E1920[4] = {
    { 255, 255, 255 },
    { 0, 255, 0 },
    { 0, 255, 255 },
    { 255, 255, 0 }
};

/*800E192C*/ s32 D_800E192C = -1;
/*800E1930*/ static u32 D_800E1930 = -1;

/*800E1934*/
static s16 D_800E1934[24] = {
    -1, -1, 5870, 5870, 3803, 3803, 5869, 5871, 5872, 5872, 5872, -1,
    5872, 5872, -1, 3786, 5871, 3786, 3801, 3801, 5873, 3802, 5870, 5870,
};

/*800E1964*/
static s16 D_800E1964[14] = {
    0, 5870, 5871, 5872, 5873, 3786, 3801, 3802, 3803, 5869, -1, 0, 0, 0
};

/*.comm*/
/*80106D40*/ u8 D_80106D40;
/*80119A94*/ s16 D_80119A94;
/*8012BC28*/ Mtx D_8012BC28;
/*8012FD70*/ u8 D_8012FD70[MAXPLAYERS];
/*8016A140*/ s16 D_8016A140;
/*80199944*/ s16 D_80199944;
/*8019994C*/ s16 D_8019994C;
/*801B0804*/ u8 D_801B0804;

/*.text*/
static void func_800A34CC(s32 x, s32 y, u16 tilenum, s16);
static void func_800A42A4(s16 playernum);

/*8009FAF0*/
void func_8009FAF0(void)
{
    s16 spritenum;
    u16 sectnum;
    SpriteType *spr;
    s16 temp;
    s32 i, j, k, nextj, nextk;

    for (i = 0; i < gVisibleSectorCnt; i++)
    {
        if (D_800DEE98 == 2)
        {
            sectnum = gVisibleSectors[i];
            temp = sectnum; /*FAKEMATCH?*/
            if (gpSector[sectnum].unk18 == 0)
            {
                gpSector[temp].unk18 = 3;
                spritenum = insertSprite(temp, 102);
                if (spritenum != -1)
                {
                    gpSprite[spritenum].x = gpWall[gpSector[temp].wallptr].x;
                    gpSprite[spritenum].y = gpWall[gpSector[temp].wallptr].y;
                    gpSprite[spritenum].z = D_801AC9E8;
                    gpSprite[spritenum].picnum = 15;
                    gpSprite[spritenum].lotag = 5263;
                    gpSprite[spritenum].hitag = 0;
                    gpSprite[spritenum].unk25 = 0x80;
                    gpSprite[spritenum].cstat = 0x8000;
                    gpSprite[spritenum].ang = 0;
                }
            }
        }
        j = gHeadSpriteSect[gVisibleSectors[i]];
        while (j >= 0)
        {

            spr = &gpSprite[j];
            nextj = gNextSpriteSect[j];
            switch (spr->statnum)
            {
            case 50:
                func_8008FE88(j);
                break;
            case 108:
                func_8006CCCC(j);
                break;
            case 120:
                func_800195DC(j);
                break;
            case 301:
                func_800965F8(j);
                break;
            case 303:
                if (spr->unk25 != 0)
                    func_8009A1A0(j);
                break;
            }
            j = nextj;
        }
    }

    k = gHeadSpriteStat[302];
    while (k >= 0)
    {
        nextk = gNextSpriteStat[k];
        func_800965F8(k);
        k = nextk;
    }

    k = gHeadSpriteStat[310];
    while (k >= 0)
    {
        nextk = gNextSpriteStat[k];
        func_8008FE88(k);
        k = nextk;
    }

    k = gHeadSpriteStat[311];
    while (k >= 0)
    {
        nextk = gNextSpriteStat[k];
        func_8008FE88(k);
        k = nextk;
    }

    k = gHeadSpriteStat[305];
    if (k >= 0)
    {
        switch (gpSprite[k].picnum)
        {
        case BOSSCYBORGSCORPION:
            func_8009A9F0(k);
            return;
        case BOSSZERO:
            func_8009C248(k);
            return;
        case BOSSGIANTHOG:
            func_8009E8C8(k);
            break;
        }
    }
}

/*8009FEB0*/
static s16 _drawObjectiveString(s16 x, s16 y, char *arg2, s16 arg3)
{
    char buffer[32];
    s16 i, j;

    j = 0;
    while ((u32)j < strlen(arg2))
    {
        i = 0;
        while (i < arg3)
            buffer[i++] = arg2[j++];

        i--;
        while ((buffer[i] != ' ') && (buffer[i] != '\0'))
        {
            i--;
            j--;
        }
        buffer[i] = '\0';
        drawString2(x, y, buffer);
        y += 10;
    }
    return y;
}

/*800A0014*/
static void _drawTerminal(void)
{
    char sp20[32];
    s16 x, y;
    s16 i, j, k;
    u8 cond;

    setDrawMode2D();
    x = D_80119A94 + 80;
    y = D_80199944 + 35;

    if (gTerminalPage != 0)
    {
        cond = 0;
        func_80029238(200, 200, 200, 0x80, 0x80, 0x80, D_80106D40);
#if VERSION_FR
        drawString2(x, y, "TOUCHES");
#else
        drawString2(x, y, "KEYS");
#endif
        y += 10;
        func_80029238(0, 200, 200, 0, 0x80, 0x80, D_80106D40);

        for (i = 1; i < ARRAY_COUNT(gPlayer[0].keys); i++)
        {
            if (gPlayer[0].keys[i] != 0)
            {
                drawString2(x, y, gpKeyStrInfo[gMapNum][i-1]);
                y += 10;
                cond = 1;
            }
        }
        if (!cond)
        {
#if VERSION_FR
            drawString2(x, y, "AUCUN");
#else
            drawString2(x, y, "NONE");
#endif
            y += 10;
        }
        func_80029238(200, 200, 200, 0x80, 0x80, 0x80, D_80106D40);
        y += 10;
#if VERSION_FR
        drawString2(x, y, "MACHINE REMONT. TPS");
#else
        drawString2(x, y, "TIME MACHINE PARTS");
#endif
        y += 10;
        func_80029238(0, 200, 200, 0, 0x80, 0x80, D_80106D40);

        if ((gMapNum == MAP_WETWORLD) || (gMapNum == MAP_BOSS_HOG) ||
            (gMapNum == MAP_CYBORG_SCORPION) || (gMapNum >= MAP_THE_RACK))
        {
#if VERSION_FR
            drawString2(x, y, "RIEN DECELE");
#else
            drawString2(x, y, "NONE DETECTED");
#endif
        }
        else if (gTimeMachinePart & (1 << gMapNum))
        {
#if VERSION_FR
            drawString2(x, y, "PIECE PRISE");
#else
            drawString2(x, y, "PART COLLECTED");
#endif
        }
        else
        {
#if VERSION_FR
            drawString2(x, y, "PIECE NON TROUVEE");
#else
            drawString2(x, y, "PART NOT FOUND");
#endif
        }
    }
    else
    {
        func_80029238(200, 200, 200, 0x80, 0x80, 0x80, D_80106D40);
#if VERSION_FR
        drawString2(x, y, "MISSION PRINCIPALE");
#else
        drawString2(x, y, "PRIMARY GOAL");
#endif
        y += 10;
        func_80029238(0, 200, 200, 0, 0x80, 0x80, D_80106D40);
        y = _drawObjectiveString(x, y, gpObjectiveStrInfo[gMapNum].addr[0], 29);

        if (gpObjectiveStrInfo[gMapNum].count >= 2)
        {
            y += 10;
            func_80029238(200, 200, 200, 0x80, 0x80, 0x80, D_80106D40);
#if VERSION_FR
            drawString2(x, y, "OBJECTIFS EN COURS");
#else
            drawString2(x, y, "CURRENT OBJECTIVES");
#endif
            y += 10;
            func_80029238(0, 200, 200, 0, 0x80, 0x80, D_80106D40);

            for (i = 1; i < gpObjectiveStrInfo[gMapNum].count; i++)
            {
                if (D_801AE91E[i] == 67)
                    y = _drawObjectiveString(x, y, gpObjectiveStrInfo[gMapNum].addr[i], 29);
            }
        }
    }

    func_80029238(200, 200, 0, 0, 0x80, 0x80, D_80106D40);
    k = 0;
    for (j = 0; j < 32; j++)
    {
        if (gTimeMachinePart & (1 << j))
            k++;
    }

#if VERSION_FR
    sprintf(sp20, "MACHINE REMONT. TPS %d:%d", k, 13);
#else
    sprintf(sp20, "TIME MACHINE PARTS %d:%d", k, 13);
#endif
    drawString2((D_80119A94 + 80), (D_80199944 + 135), sp20);
#if VERSION_FR
    sprintf(sp20, "SECRETS %d:%d   GONZ. %d:%d", D_801A1958.secrets_found,
            D_801A1958.secrets_total, D_801A1958.babes_saved, D_801A1958.babes_total);
#else
    sprintf(sp20, "SECRETS %d:%d   BABES %d:%d", D_801A1958.secrets_found,
            D_801A1958.secrets_total, D_801A1958.babes_saved, D_801A1958.babes_total);
#endif
    drawString2((D_80119A94 + 80), (D_80199944 + 145), sp20);
    gDPSetTextureLUT(gpDisplayList++, G_TT_RGBA16);
    gDPSetCombineMode(gpDisplayList++, G_CC_DECALRGBA, G_CC_PASS2);
#ifdef AVOID_UB
    D_801A2688 = 0;
#endif
    func_8001D238(D_80119A94 + 210, D_80199944 + 145, 3997);
    func_8001D238(D_80119A94 + 230, D_80199944 + 145, 3998);
}

/*800A0698*/
static void func_800A0698(void)
{
    Gfx *dlist;
    f32 x, y, z;
    s16 i, c;
    s32 temp;

    D_8010A9AC = 0;
    D_8019956C = 0;
    D_80119A38 = 0;
    D_80105718 = 0;
    D_801AE8F4 = gPlayer[gPlayerNum].unk4A;
    main_80000C74();
    func_8000F1E0();
    initVertexList();

    gSPSetLights2(gpDisplayList++, D_800E18F8);
    c = 0xFF;

    for (i = 0; i < gPlayerCount; i++)
    {
        if (i != gPlayerNum)
        {
            if (D_80106D30[i] != 1)
            {
                if (gpSprite[gPlayer[i].unk4A].picnum == gpSprite[D_801AE8F4].picnum)
                    c = 0x40;
            }
        }
    }

    gSPLightColor(gpDisplayList++, LIGHT_3, (c<<24)+(c<<16)+(c<<8));

    x = gpSprite[D_801AE8F4].x;
    y = gpSprite[D_801AE8F4].y;
    z = (gpSprite[D_801AE8F4].z - 0x1964);

    x += (cosf(gpSprite[D_801AE8F4].ang * (PI/1024)) * 1204.0f);
    y += (sinf(gpSprite[D_801AE8F4].ang * (PI/1024)) * 1204.0f);

    temp = D_8012FD88 % 360; /*FAKEMATCH*/
    grPosition(
        &gpDynamic->mtx3[D_801A6D80],
        0.0f,
        180.0f,
        (D_8012FD88 % 360),
        1.0f,
        (x / 4.0),
        (y / 4.0),
        (z / 64.0));

    gSPMatrix(gpDisplayList++, OS_K0_TO_PHYSICAL(&gpDynamic->mtx3[D_801A6D80]),
              G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    D_801A6D80++;

    dlist = gpDisplayList;
    gpDisplayList = D_801297E0[gPlayerNum][gGfxTaskIndex];
    func_80013FFC(func_80014040(gpSprite[D_801AE8F4].picnum));
    gSPEndDisplayList(gpDisplayList++);
    gSPDisplayList(dlist++, D_801297E0[gPlayerNum][gGfxTaskIndex]);
    gpDisplayList = dlist;
}

/*800A0BD4*/
static void _drawMapStrInfo(s16 x, s16 y, char *arg2)
{
#ifdef AVOID_UB
    char buffer[64];
#else
    char buffer[32];
#endif
    s16 i, j;

    j = 0;
    for (i = 0; i < D_8019994C; i++)
    {
        if (arg2[i] == '\0')
            break;
        else if (arg2[i] != '\n')
            buffer[j++] = arg2[i];
        else
        {
            buffer[j] = '\0';
            drawString(x, y, buffer);
            j = 0;
            y += 12;
        }
    }
    if (j > 0)
    {
        buffer[j] = '\0';
        drawString(x, y, buffer);
    }
}

/*800A0D08*/
static void func_800A0D08(s16 arg0, s16 arg1)
{
    s32 x1, y1, x2, y2;

    x1 = 0;
    y1 = arg0;
    func_8001D128(&x1, &y1);
    x2 = 320;
    y2 = arg0 + arg1;
    func_8001D128(&x2, &y2);
    gDPSetRenderMode(gpDisplayList++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineMode(gpDisplayList++, G_CC_PRIMITIVE, G_CC_PASS2);
    gDPSetPrimColor(gpDisplayList++, 0, 0, 0xFF, 0xFF, 0xFF, 0x40);
    gSPTextureRectangle(gpDisplayList++, x1*4, y1*4, x2*4, y2*4, G_TX_RENDERTILE, 0, 0, 1, 1);
}

/*800A0E74*/
void func_800A0E74(void)
{
    s16 i;

    D_80138678 = -1;
    D_801B0804 = 0;
    if ((gMapNum < MAP_COUNT) && (gpMapStrInfo[gMapNum][0] != '\0'))
        D_8016A140 = (s16)strlen(gpMapStrInfo[gMapNum]) + 142;
    else
        D_8016A140 = -1;

    if (D_800DF585 != 0)
        D_8016A140 = -1;

    D_800BD74A = 2;
    D_8019994C = 0;
    D_800BD748 = 0xFF;
    D_800DEE70 = 0;
    D_801AC9F8 = 0;
    D_80106D40 = 0;

    for (i = 0; i < gPlayerCount; i++)
        D_8012FD70[i] = 0;
}

/*800A0F84*/
void drawHud(void)
{
    char sp20[32];
    s32 xl1, yl1, xh1, yh1, xl2, yl2, xh2, yh2, xl3, yl3, xh3, yh3;
    ModelInfo **ptr;
    f32 f1, f2, f3, f4;
    s16 i, j, k, l, m, n, o, p, q;
    s32 a, b;
    u32 c;
    s32 *ptr2;
    s16 *ptr3;

    setDrawMode2D();
    setPlayerViewport(gPlayerNum, 1);
    gDPPipeSync(gpDisplayList++);

    if (D_8016A140 > 0)
    {
        a = 0xFF;
        if (D_8016A140 < 0x20)
            a = D_8016A140 * 8;

        func_80029238(0x20, 0xFF, 0x20, 0x20, 0xFF, 0x20, a);
        _drawMapStrInfo(25, 140, gpMapStrInfo[gMapNum]);
    }

    if (gMapNum == MAP_BASE)
    {
        if (gPlayer[gPlayerNum].unk52 >= 0x800)
        {
            if ((gpSprite[gPlayer[gPlayerNum].unk52 & 0x7FF].hitag == 400) ||
                (gpSprite[gPlayer[gPlayerNum].unk52 & 0x7FF].hitag == 402))
            {
                func_80029238(0x20, 0xFF, 0xC0, 0x20, 0xFF, 0xC0, ((random(0x40) - 0x40)));
                func_800A34CC(50, 160, 6070, 0);
                func_800A34CC(270, 160, 6070, 4);
                func_800A34CC(50, 60, 6070, 8);
                func_800A34CC(270, 60, 6070, 12);
#if VERSION_FR
                drawString2(90, 150, "LIEN TEMPOREL ESTABLI");
                drawString2(90, 160, "SOURCE DE TRANSMISSION");
                drawString2(90, 170, "LONDRES, ANGLETERRE 1888");
#else
                drawString2(90, 150, "TEMPORAL LINK ESTABLISHED");
                drawString2(90, 160, "TRANSMISSION SOURCE:");
                drawString2(90, 170, "LONDON, ENGLAND 1888 AD");
#endif
                ptr2 = ((D_8012FD88 >> 1)) + (s32 *)drawHud; /*TODO: Funky way of getting random values?*/
                sprintf(sp20, "%08X", *ptr2++);
                drawString2(240, 30, sp20);
                sprintf(sp20, "%08X", *ptr2++);
                drawString2(240, 40, sp20);
                sprintf(sp20, "%08X", *ptr2++);
                drawString2(240, 50, sp20);
                sprintf(sp20, "%08X", *ptr2);
                drawString2(240, 60, sp20);
                func_8001D238(20, 130, 3964);
                func_800A0D08(((D_8012FD88 * 4) % 240), 0x10);
                func_800A0D08((((D_8012FD88 * 4) + 120) % 240), 0x10);
            }
        }
    }

    if (gMapNum == MAP_THE_WHITECHAPEL_KILLINGS)
    {
        if (gPlayer[gPlayerNum].unk52 >= 0x800)
        {
            if ((gpSprite[gPlayer[gPlayerNum].unk52 & 0x7FF].hitag == 4010) ||
                (gpSprite[gPlayer[gPlayerNum].unk52 & 0x7FF].hitag == 4070))
            {
                func_80029238(0x20, 0xFF, 0x20, 0x20, 0xFF, 0x20, 0xC0);
                func_800A34CC(50, 170, 3836, 8);
                func_800A34CC(270, 170, 3836, 12);
                func_800A34CC(50, 50, 3836, 0);
                func_800A34CC(270, 50, 3836, 4);
                func_800A0D08(((D_8012FD88 * 4) % 240), 0x10);
                func_800A0D08((((D_8012FD88 * 4) + 0x78) % 240), 0x10);
            }
        }
    }

    if (gPlayer[gPlayerNum].unk52 >= 0x800)
    {
        xl1 = 0;
        yl1 = 0;
        func_8001D128(&xl1, &yl1);
        xh1 = SCREEN_WIDTH;
        yh1 = 28;
        func_8001D128(&xh1, &yh1);

        gDPSetRenderMode(gpDisplayList++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
        gDPSetCombineMode(gpDisplayList++, G_CC_PRIMITIVE, G_CC_PASS2);
        gDPSetPrimColor(gpDisplayList++, 0, 0, 0x00, 0x00, 0x00, 0xFF);
        gSPTextureRectangle(gpDisplayList++, xl1*4, yl1*4, xh1*4, yh1*4, G_TX_RENDERTILE, 0, 0, 1, 1);

        xl1 = 0;
        yl1 = 194;
        func_8001D128(&xl1, &yl1);
        xh1 = SCREEN_WIDTH;
        yh1 = SCREEN_HEIGHT;
        func_8001D128(&xh1, &yh1);
        gSPTextureRectangle(gpDisplayList++, xl1*4, yl1*4, xh1*4, yh1*4, G_TX_RENDERTILE, 0, 0, 1, 1);
        return;
    }

    if (gNotPlayback)
    {
        if (D_801AD470 == 4)
        {
            if (D_800E16A0[gPlayerNum] != 0)
            {
                D_8012DF04[gPlayerNum].r = 0xFF;
                D_8012DF04[gPlayerNum].g = 0x40;
                D_8012DF04[gPlayerNum].b = 0x40;
            }
            else
            {
                D_8012DF04[gPlayerNum].r = 0x40;
                D_8012DF04[gPlayerNum].g = 0xC8;
                D_8012DF04[gPlayerNum].b = 0xFF;
            }
        }
        else
        {
            D_8012DF04[gPlayerNum].r = D_800E1920[gPlayerNum].r;
            D_8012DF04[gPlayerNum].g = D_800E1920[gPlayerNum].g;
            D_8012DF04[gPlayerNum].b = D_800E1920[gPlayerNum].b;
        }

        if (D_80106D30[gPlayerNum] != 0)
        {
            func_800A0698();
            setDrawMode2D();
            func_80029130(D_8012DF04[gPlayerNum].r, D_8012DF04[gPlayerNum].g, D_8012DF04[gPlayerNum].b, 0, 0, 0);

            if (D_80106D30[gPlayerNum] == 1)
                drawString(-1, 200, D_8012F6E4[gPlayer[gPlayerNum].skin].actor);
            else if (D_800E16A0[gPlayerNum] != 0)
            {
#if VERSION_FR
                drawString(-1, 200, "EQUIPE ROUGE");
#else
                drawString(-1, 200, "RED TEAM");
#endif
            }
            else
            {
#if VERSION_FR
                drawString(-1, 200, "EQUIPE BLEUE");
#else
                drawString(-1, 200, "BLUE TEAM");
#endif
            }
            return;
        }

        if ((!gPlayer[gPlayerNum].third_person) || (gPlayer[gPlayerNum].unk52 >= 0))
            func_800A3688();

        if (gPlayer[gPlayerNum].unk52 >= 0 && gPlayer[gPlayerNum].unk52 < 0x800)
        {
            func_800A0D08((D_8012FD88 % 240), 1);
            return;
        }
        if (D_8010A940[gPlayerNum].unk2[5] != 0)
            func_800A0D08((0xF0 - (D_8012FD88 % 240)), 1);

        func_800A42A4(gPlayerNum);
        if (gPlayer[gPlayerNum].unk45 == 0)
        {
            setDrawMode2D();

            if (gPlayerCount == 1)
            {
#ifdef AVOID_UB
                D_801A2688 = 0;
#endif
                func_8001D238(D_80119A94 + 20, D_80199944 + 200, 5692);
                o = 36;
            }
            else
                o = 20;

            k = MAX(gActor[gActorSpriteMap[gPlayer[gPlayerNum].unk4A]].unk8, 0);
            if (k >= 31)
            {
                p = 0;
                n = 0xFF;
            }
            else
            {
                p = 0xFF;
                n = 0;
            }

            func_80029130(p, n, 0, 0, 0, 0);
            sprintf(sp20, "%d", k);

            if (gPlayerCount == 1)
                drawNumberString((o + D_80119A94), (D_80199944 + 200), sp20);
            else
                drawString((o + D_80119A94), (D_80199944 + 200), sp20);

            func_80029130(0xFF, 0xFF, 0, 0, 0, 0);
            c = D_8010A940[gPlayerNum].unk0;
            if ((s32)c != -1)
            {
                if (D_800E17E0[c] > 0)
                {
                    p = (D_8010A940[gPlayerNum].unkA[c] * 100) / D_800E17E0[c];
                    sprintf(sp20, "%d", p);

                    if (gPlayerCount == 1)
                        drawNumberString((D_80119A94 + 30), (D_80199944 + 60), sp20);
                    else
                        drawString((D_80119A94 + 30), (D_80199944 + 60), sp20);
                }
            }

            k = gActor[gActorSpriteMap[gPlayer[gPlayerNum].unk4A]].unk99;
            if (k == 11)
                k = 10;

            if (k!= 0)
            {
                u32 temp;
                ptr3 = D_8011A680[gPlayerNum][k];
                temp = (u16)ptr3[0];

                if (((temp >> 2) & 1) && (k!= 4))
                    q = ptr3[7];
                else
                    q = ptr3[1];

                n = ptr3[5];
                if (ptr3[0] & 2)
                    n *= 2;

                if (n > 0)
                {
                    if (((q + ptr3[4]) - n) >= 0)
                        p = (q + ptr3[4]) - n;
                    else
                        p = 0;
                }
                else
                    p = q;

                if ((k == 20) || (k == 15))
                    p = (p + 9) / 10;

                if (ptr3[0] & 4)
                    func_80029130(0xFF, 0, 0, 0, 0, 0);

                if (gPlayerCount >= 2)
                    k = 0xFE;
                else
                    k = 0x101;

                sprintf(sp20, "%3d", p);
                if (gPlayerCount == 1)
                    drawNumberString((k + D_80119A94), (D_80199944 + 60), sp20);
                else
                    drawString((k + D_80119A94), (D_80199944 + 60), sp20);

                if (n > 0)
                {
                    func_80029130(0xFF, 0x80, 0, 0, 0, 0);
                    p = n - ptr3[4];
                    p = MIN(p, q);
                    p = (D_8016A154[gPlayerNum] == 0) ? p : 0;
                    sprintf(sp20, "%3d", p);
                    b = (gPlayerCount >= 2) ? 43 : 35;

                    if (gPlayerCount == 1)
                        drawNumberString((D_80119A94 + (k - b)), (D_80199944 + 60), sp20);
                    else
                        drawString((D_80119A94 + (k - b)), (D_80199944 + 60), sp20);
                }
            }

            if (gMapNum == MAP_PROBING_THE_DEPTHS)
            {
                switch (gConfig.difficulty)
                {
                default:
                case 0:
                    a = 21600;
                    break;

                case 1:
                    a = 18000;
                    break;

                case 2:
                    a = 14400;
                    break;
                }

                sprintf(sp20, "%02d:%02d", ((s16)((a - D_801A1958.unkC) / 30U) / 60),
                                           ((s16)((a - D_801A1958.unkC) / 30U) % 60));
                func_80029130(0xFF, 0, 0, 0, 0, 0);
                drawNumberString(-1, 30, sp20);
            }

            if ((gMapNum == MAP_BASE) && (D_80138678 != -1))
            {
                if (D_800E192C != -1)
                {
                    c = (D_800E192C - D_80138678) / 30U;

                    if ((s32)D_800E1930 == -1)
                        D_800E1930 = c;
                    else
                        D_800E1930 = MIN(D_800E1930, c);
                }
                else
                    c = (D_801A1958.unkC - D_80138678) / 30U;

                sprintf(sp20, "%02d:%02d", (s16)c/60, (s16)c%60);
                func_80029130(0, 0xFF, 0xFF, 0, 0, 0);
                drawNumberString(-1, 30, sp20);
                if ((s32)D_800E1930 != -1)
                {
                    sprintf(sp20, "%02d:%02d", (s16)D_800E1930/60, (s16)D_800E1930%60);
                    func_80029130(0, 0xFF, 0x80, 0, 0, 0);
                    drawNumberString(-1, 45, sp20);
                }
            }

            if ((gMapNum == MAP_UNDER_SIEGE) && (D_80138678 != -1))
            {
                switch (gConfig.difficulty)
                {
                default:
                case 0:
                    c = 3600;
                    break;

                case 1:
                    c = 2700;
                    break;

                case 2:
                    c = 1800;
                    break;
                }

                a = D_801A1958.unkC;
                a = (c - (a - D_80138678));
                sprintf(sp20, "%02d:%02d", (s16)(a / 30U) / 60,
                                           (s16)(a / 30U) % 60);
                func_80029130(0xFF, 0, 0, 0, 0, 0);
                drawNumberString(-1, 30, sp20);
            }

            if (D_8012FD70[gPlayerNum] != 0)
            {
                xl2 = 20;
                yl2 = 190;
                func_8001D128(&xl2, &yl2);
                yh2 = 195;
                xh2 = D_8011814A[gPlayerNum]; xh2 = (xh2 / 12) + 20;
                func_8001D128(&xh2, &yh2);

                gDPSetRenderMode(gpDisplayList++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
                gDPSetCombineMode(gpDisplayList++, G_CC_PRIMITIVE, G_CC_PASS2);
                gDPSetPrimColor(gpDisplayList++, 0, 0, 0x00, 0xFF, 0xFF, D_8012FD70[gPlayerNum]);
                gSPTextureRectangle(gpDisplayList++, xl2*4, yl2*4, xh2*4, yh2*4, G_TX_RENDERTILE, 0, 0, 1, 1);
            }

            n = gHeadSpriteStat[305];
            if (gMapNum == MAP_BRAINSTORM)
            {
                i = gHeadSpriteStat[302];
                while (i>=0)
                {
                    if (gpSprite[i].picnum == BOSSBRAINSTORM)
                        n = i;

                    i = gNextSpriteStat[i];
                }
            }
            if (n >= 0)
            {
                if (gpSprite[n].picnum == BOSSBRAINSTORM)
                {
                    k = 0;
                    j = gHeadSpriteStat[302];
                    while (j >= 0)
                    {
                        if (gpSprite[j].picnum == 2341)
                            k += 25;

                        j = gNextSpriteStat[j];
                    }
                }
                else
                    k = gActor[gActorSpriteMap[n]].unk8;

                k = CLAMP_MIN(k, 0);
                switch (gpSprite[n].picnum)
                {
                case BOSSGIANTHOG:
                    p = 5000;
                    m = 5;
                    break;
                case BOSSCYBORGSCORPION:
                    p = 5000;
                    m = 6;
                    break;
                case BOSSBRAINSTORM:
                    p = 100;
                    m = 7;
                    break;
                case BOSSZERO:
                    p = 10000;
                    m = 8;
                    break;
                }

                xl3 = 110;
                yl3 = 40 - m;
                func_8001D128(&xl3, &yl3);
                xh3 = 210;
                yh3 = m + 40;
                func_8001D128(&xh3, &yh3);

                gDPSetRenderMode(gpDisplayList++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
                gDPSetCombineMode(gpDisplayList++, G_CC_PRIMITIVE, G_CC_PASS2);
                gDPSetPrimColor(gpDisplayList++, 0, 0, 0x00, 0x00, 0x00, 0x80);
                gSPTextureRectangle(gpDisplayList++, xl3*4, yl3*4, xh3*4, yh3*4, G_TX_RENDERTILE, 0, 0, 1, 1);

                if (k > 0)
                {
                    k = (k * 50) / p;
                    k = CLAMP_MIN(k, 2);
                    xl3 = 160 - k;
                    yl3 = 40 - m;
                    func_8001D128(&xl3, &yl3);
                    xh3 = k + 160;
                    yh3 = m + 40;
                    func_8001D128(&xh3, &yh3);
                    xl3++;
                    yl3++;
                    xh3--;
                    yh3--;

                    if (k < 12)
                    {
                        gDPSetPrimColor(gpDisplayList++, 0, 0, 0xFF, 0x00, 0x00, 0xC0);
                    }
                    else
                    {
                        gDPSetPrimColor(gpDisplayList++, 0, 0, 0xFF, 0xFF, 0x00, 0xC0);
                    }
                    gSPTextureRectangle(gpDisplayList++, xl3*4, yl3*4, xh3*4, yh3*4, G_TX_RENDERTILE, 0, 0, 1, 1);
                }
            }
            if (gPlayerCount >= 2)
            {
                l = D_800FF4F0[gPlayerNum].unk0 - D_800FF4F0[gPlayerNum].unk2;
                l = CLAMP_MAX(l, 999);
                l = CLAMP_MIN(l, -99);

                sprintf(sp20, "%3d", l);
                func_80029130(D_8012DF04[gPlayerNum].r, D_8012DF04[gPlayerNum].g, D_8012DF04[gPlayerNum].b, 0, 0, 0);
                drawString(254, 200, sp20);

                if (gConfig.multiplayer.radar != CONFIG_OFF)
                {
                    for (p = 0; p < gPlayerCount; p++)
                    {
                        if (p != gPlayerNum)
                        {
                            if (gPlayer[p].unk45 == 0)
                            {
                                if (D_80106D30[p] == 0)
                                {
                                    s32 temp, temp2;
                                    temp = gPlayer[gPlayerNum].xpos - D_80138610[gPlayerNum];
                                    temp2 = (gPlayer[gPlayerNum].ypos - D_801AE480[gPlayerNum]);
                                    temp = getAngle((gPlayer[p].xpos - D_80138610[p]) - (temp),
                                                    (gPlayer[p].ypos - D_801AE480[p]) - temp2);
                                    f4 = ((((temp - (u16)gPlayer[gPlayerNum].ang) - 0x200) & 0x7FF) * (PI/1024));
                                    k = (cosf(f4) * 100.0f);
                                    n = (sinf(f4) * 100.0f);
                                    func_80029130(D_8012DF04[p].r, D_8012DF04[p].g, D_8012DF04[p].b, 0, 0, 0);
                                    func_8001D238(k + 144, n + 104, 5535);
                                }
                            }
                        }
                    }
                }
            }
            guOrtho(&D_8012BC28, -100.0f, 100.0f, -75.0f, 75.0f, 5.0f, 100.0f, 1.0f);

            gSPMatrix(gpDisplayList++, OS_K0_TO_PHYSICAL(&D_8012BC28), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            func_8000F1E0();
            initVertexList();

            gDPSetRenderMode(gpDisplayList++, G_RM_FOG_SHADE_A, G_RM_AA_TEX_EDGE2);

            gSPSetLights2(gpDisplayList++, D_800E18D0);

            ptr = &D_800D683C[gActor[gActorSpriteMap[gPlayer[gPlayerNum].unk4A]].unk99];
            if (*ptr != NULL)
            {
                ModelInfo *temp;
                grPosition(&gpDynamic->mtx3[D_801A6D80], 270.0f, 0.0f, 0.0f, 0.45f, (D_80119A94 + 60.0), (50.0 - D_80199944), 32.0f);
                gSPMatrix(gpDisplayList, OS_K0_TO_PHYSICAL(&gpDynamic->mtx3[D_801A6D80]), G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

                temp = *ptr;
                gpDisplayList++;
                D_801A6D80++;
                drawModel(temp);
            }

            if (D_8010A940[gPlayerNum].unk0 != -1)
            {
                f1 = 0.3375f;
                f2 = -70.0f;
                f3 = 50.0f;
                k = D_8010A940[gPlayerNum].unk0;
                if (k == 7)
                {
                    f1 = (D_8010A940[gPlayerNum].unkA[7] * 0.3375f) / 4096.0f;
                    f2 *= (6.0 - (D_8010A940[gPlayerNum].unkA[7] / 4096.0)) / 5.0;
                    f3 *= (6.0 - (D_8010A940[gPlayerNum].unkA[7] / 4096.0)) / 5.0;
                }
                grPosition(&gpDynamic->mtx3[D_801A6D80], 270.0f, 0.0f, 0.0f, f1, f2 + D_80119A94, f3 - D_80199944, 32.0f);

                gSPMatrix(gpDisplayList++, OS_K0_TO_PHYSICAL(&gpDynamic->mtx3[D_801A6D80]), G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                D_801A6D80++;

                if (k == 7)
                {
                    gDPSetRenderMode(gpDisplayList++, G_RM_FOG_SHADE_A, G_RM_TEX_EDGE2);

                    drawModel(&D_800D42C0);
                    if ((D_8010A940[gPlayerNum].unkA[7] == 0x6000) && (gMapNum < MAP_COUNT))
                    {
                        _drawTerminal();
                        func_8000F1E0();
                        initVertexList();

                        gDPSetRenderMode(gpDisplayList++, G_RM_FOG_SHADE_A, G_RM_AA_TEX_EDGE2);
                        gSPSetLights2(gpDisplayList++, D_800E18D0);
                    }
                }

                switch (gMapChapter[gMapNum].chapter)
                {
                default:
                    drawModel(D_800D69C8[k]);
                    break;

                case WESTERN:
                    drawModel(D_800D6A08[k]);
                    break;

                case VICTORIAN:
                    drawModel(D_800D69E8[k]);
                    break;

                }
            }
        }
    }
}

/*800A34CC*/
static void func_800A34CC(s32 x, s32 y, u16 tilenum, s16 arg3)
{
    func_8001D128(&x, &y);
    drawTileScaled(x,
                   y,
                   (gViewportScaleX * 3.0f) / (SCREEN_WIDTH / 2.0),
                   (gViewportScaleY * 3.0f) / (SCREEN_HEIGHT / 2.0),
                   getTileId(tilenum),
                   arg3);
}

/*800A359C*/
static void func_800A359C(s32 x, s32 y, s16 tilenum, s16 arg3)
{
    f32 scalex, scaley;

    func_8001D128(&x, &y);
    scalex = (gScreenWidth * 3) / (f64)SCREEN_WIDTH;
    scaley = (gScreenHeight * 3) / (f64)SCREEN_HEIGHT;
    drawTileScaled(x,
                   y,
                   scalex,
                   scaley,
                   getTileId(tilenum),
                   arg3);
}

/*800A3688*/
void func_800A3688(void)
{
    char buffer[8];
    s16 hitsect, hitwall, hitsprite;
    s32 hitx, hity, hitz;

    Actor *actor;
    f32 fx, fy, fz;
    f32 f1, f2, f5, f6, f7;
    s32 x, y, z;

    s16 i, j, k, l;
    u16 cstat;

    if ((gPlayer[gPlayerNum].unk45 == 0) && gNotPlayback)
    {
        actor = &gActor[gActorSpriteMap[gPlayer[gPlayerNum].unk4A]];
        l = D_800E1934[actor->unk99];

        if (gConfig.crosshair[gPlayerNum] != 0)
            l = D_800E1964[gConfig.crosshair[gPlayerNum]];

        setDrawMode2D();

        if ((gPlayer[gPlayerNum].unk52 >= 0) && (gPlayer[gPlayerNum].unk52 < 0x800))
        {
            if (gpSprite[gPlayer[gPlayerNum].unk52].picnum == 1423)
            {
                func_80028F04(0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
                func_800A34CC(50, 190, 6070, 0);
                func_800A34CC(270, 190, 6070, 4);
                func_800A34CC(50, 50, 6070, 8);
                func_800A34CC(270, 50, 6070, 12);
                func_80029130(0, 0xFF, 0xFF, 0, 0xFF, 0xFF);
                func_8001D238(230, 185, 6069);
                if ((D_8012FD88 & 0x1F) > 16)
                {
                    func_80028F04(0xFF, 0, 0, 0xFF, 0, 0);
                    func_8001D238(260, 185, 6071);
                }
            }
            else
            {
                func_80028F04(0, 0xFF, 0, 0, 0xFF, 0);
                func_800A34CC(50, 200, 3836, 8);
                func_800A34CC(270, 200, 3836, 12);
                func_800A34CC(50, 0x28, 3836, 0);
                func_800A34CC(270, 0x28, 3836, 4);

                j = (D_8012FD88 >> 3) & 0xFF;
                for (i = 0; i < 8; i++)
                {
                    if ((j >> i) & 1)
                        func_8001D238(14, (i * 15) + 50, 6071);
                }
            }
        }
        else if ((l != -1) || (gPlayer[gPlayerNum].unk6C != 0))
        {
            if (!gPlayer[gPlayerNum].third_person)
            {
                if (gPlayer[gPlayerNum].unk6C != 0)
                {
                    func_80028F04(0, 0, 0, 0, 0xFF, 0);
                    func_800A34CC((SCREEN_WIDTH/2), (SCREEN_HEIGHT/2), 5868, 0);
                    func_80029130(0, 0xFF, 0, 0, 0, 0);
                    drawString(190, 160, "X");
                    sprintf(buffer, "%d", gPlayer[gPlayerNum].unk6E / 256);
                    drawNumberString(200, 160, buffer);
                    if (gPlayerCount == 1)
                    {
                        sprintf(buffer, "%03d", (s16)((gPlayer[gPlayerNum].ang & 0x7FF) * (45.0/256)));
                        drawString2(0x98, 0xAA, buffer);
                        k = ((gPlayer[gPlayerNum].unk3E & 0x7FF) * (45.0/256));
                        if (k > 180)
                            k -= 360;

                        sprintf(buffer, "%d", klabs(k));
                        drawString2(220, 107, buffer);
                    }
                }
                else
                {
                    func_80028F04(0xFF, 0, 0, 0xFF, 0, 0);
                    func_800A359C((SCREEN_WIDTH/2), (SCREEN_HEIGHT/2), l, 0);
                }
            }
            else
            {
                hitsprite = func_8004CE58(&gpSprite[gPlayer[gPlayerNum].unk4A],
                                          D_8013F920[actor->unk99], actor->unk99);
                if (hitsprite < 0)
                {
                    f1 = (gPlayer[gPlayerNum].ang * (PI/1024));
                    f2 = (gPlayer[gPlayerNum].unk3E * (PI/1024));
                    fx = cosf(f1);
                    fy = sinf(f1);
                    f1 = sinf(f2) / cosf(f2);
                    x = fx* 16384.0f;
                    y = fy* 16384.0f;
                    z = f1* 16384.0f * 16.0f;
                }
                else
                {
                    f1 = ((s16)getAngle(gpSprite[hitsprite].x - gPlayer[gPlayerNum].xpos,
                        gpSprite[hitsprite].y - gPlayer[gPlayerNum].ypos) * (PI/1024));

                    f2 = (gPlayer[gPlayerNum].unk3E * (PI/1024));
                    fx = cosf(f1);
                    fy = sinf(f1);
                    f1 = ((sinf(f2) / cosf(f2)));
                    x = fx* 16384.0f;
                    y = fy* 16384.0f;
                    z = f1* 16384.0f * 16.0f;
                }

                cstat = gpSprite[gPlayer[gPlayerNum].unk4A].cstat;
                gpSprite[gPlayer[gPlayerNum].unk4A].cstat = cstat & ~0x101;

                hitScan(gPlayer[gPlayerNum].xpos,
                        gPlayer[gPlayerNum].ypos,
                        gPlayer[gPlayerNum].zpos + 0x300,
                        gPlayer[gPlayerNum].cursectnum,
                        x,
                        y,
                        z, &hitsect, &hitwall, &hitsprite, &hitx, &hity, &hitz, 0x01000040);

                gpSprite[gPlayer[gPlayerNum].unk4A].cstat = cstat;
                f1 = (hitx / 4.0);
                f2 = (hity / 4.0);
                f5 = (hitz / 64.0);

                fx = ((D_8012B948[0][0] * f1) +
                      (D_8012B948[1][0] * f2) +
                      (D_8012B948[2][0] * f5) +
                       D_8012B948[3][0]);

                fy = ((D_8012B948[0][1] * f1) +
                      (D_8012B948[1][1] * f2) +
                      (D_8012B948[2][1] * f5) +
                       D_8012B948[3][1]);

                fz = ((D_8012B948[0][3] * f1) +
                      (D_8012B948[1][3] * f2) +
                      (D_8012B948[2][3] * f5) +
                       D_8012B948[3][3]);

                if (fz > 0.0f)
                {
                    f6 = fx / fz;
                    f7 = fy / fz;

                    if ((f7 < -2.0f) || (f7 > 2.0f) || (f6 < -2.0f) || (f6 > 2.0f))
                        return;
                    else
                    {
                        func_80028F04(0xFF, 0, 0, 0xFF, 0, 0);
                        drawTileScaled((f6 * gViewportScaleX) + gViewportTransX,
                                      (-f7 * gViewportScaleY) + gViewportTransY,
                                      ((gViewportScaleX * 3.0f) / (SCREEN_WIDTH/2.0)),
                                      ((gViewportScaleY * 3.0f) / (SCREEN_HEIGHT/2.0)),
                                      getTileId(l), 0);
                    }
                }
            }
        }
    }
}

/*800A419C*/
void func_800A419C(s16 playernum, char *arg1)
{
    s16 i;

    if (gPlayerCount == 1)
    {
        for (i = ARRAY_COUNT(D_80138858)-1; i > 0; i--)
        {
            D_80138858[i] = D_80138858[i-1];
            strcpy(D_8012FCB0[i], D_8012FCB0[i-1]);
        }
        D_80138858[playernum] = 90;
        strcpy(D_8012FCB0[playernum], arg1);
    }
    else
    {
        D_80138858[playernum] = 90;
        strcpy(D_8012FCB0[playernum], arg1);
    }
}

/*800A42A4*/
static void func_800A42A4(s16 playernum)
{
    s16 i;
    u8 a;

    if (gPlayerCount == 1)
    {
        for (i = 0; i < ARRAY_COUNT(D_80138858); i++)
        {
            if (D_80138858[i] > 0)
            {
                if (D_8012FCB0[i] != NULL)
                {
                    a = CLAMP_MAX((D_80138858[i] * 8), 0xFF);
                    func_80029238(D_8012DF04[playernum].r, D_8012DF04[playernum].g, D_8012DF04[playernum].b, 0, 0, 0, a);
#if VERSION_FR
                    drawString(-1, (84 - (i * 12)), D_8012FCB0[i]);
#else
                    drawString(-1, (72 - (i * 12)), D_8012FCB0[i]);
#endif
                }
            }
        }
    }
    else if (D_80138858[playernum] > 0)
    {
        if (D_8012FCB0[playernum] != NULL)
        {
            a = CLAMP_MAX((D_80138858[playernum] * 8), 0xFF);
            func_80029238(D_8012DF04[playernum].r, D_8012DF04[playernum].g, D_8012DF04[playernum].b, 0, 0, 0, a);
#if VERSION_FR
            drawString(-1, 90, D_8012FCB0[playernum]);
#else
            drawString(-1, 78, D_8012FCB0[playernum]);
#endif
        }
    }
}

/*800A4478*/
void func_800A4478(void)
{
    s16 j;
    s16 i;
    s16 nextj;
    s32 a, b;

    for (i = 0; i < gPlayerCount; i++)
    {
        if ((gPlayer[i].unk54 != 0) || (D_8011814A[i] < 600))
            D_8012FD70[i] = 0x80;
        else
            D_8012FD70[i] = CLAMP_MIN((D_8012FD70[i] - 4), 0);

        if ((D_8010A940[i].unk0 == 7) && (D_8010A940[i].unkA[7] == 0x6000))
            D_80106D40 = CLAMP_MAX((D_80106D40 + 16), 0xFF);
        else
            D_80106D40 = 0;

        if (gPlayerCount >= 2)
        {
            if (D_801AD470 != 2)
            {
                if (gPlayer[i].unk45 != 0)
                {
                    if (gPlayer[i].unk4E > 90)
                    {
#if VERSION_FR
                        func_800A419C(i, "APPUYER SUR START");
#else
                        func_800A419C(i, "PRESS START");
#endif
                    }
                }
            }
        }
    }

    for (i = 0; i < ARRAY_COUNT(D_80138858); i++)
    {
        if (gPlayer[i].unk52 < 0x800)
        {
            if (D_80138858[i] > 0)
                D_80138858[i]--;
        }
    }

    if (D_8016A140 > 0)
    {
        D_8016A140--;
        D_8019994C++;
    }

    D_80119A94 = 0;
    D_80199944 = 0;

    if ((gPlayerCount == 1) && (D_801AC9F8 > 0))
    {
        D_801AC9F8--;
        D_80119A94 = krand() & 3;
        D_80199944 = krand() & 3;
    }

    if (gMapNum == MAP_PROBING_THE_DEPTHS)
    {
        switch (gConfig.difficulty)
        {
        case 0:
        default:
            b = 21600;
            break;
        case 1:
            b = 18000;
            break;
        case 2:
            b = 14400;
            break;
        }
        if ((((b - D_801A1958.unkC) / 30U) == 0) && (D_801B0804 == 0))
        {
            D_801B0804 = 1;
            func_8003671C(0, 1000, -1, -1);
            func_8001F7B4(60, 15);
            playSfx(1648);
            D_800DEEE4[0] = 1;
            gPlayer[0].unk45 = 4;
        }
    }

    if ((gMapNum == MAP_UNDER_SIEGE) && (D_80138678 != -1))
    {
        switch (gConfig.difficulty)
        {
        case 0:
        default:
            a = 3600;
            break;
        case 1:
            a = 2700;
            break;
        case 2:
            a = 1800;
            break;
        }

        b = D_801A1958.unkC - D_80138678;
        b = (a - b) / 30U;
        if (b == 0)
        {
            D_80138678 = -1;
            D_800E192C = -1;
            func_8006B590(1918);
            j = gHeadSpriteStat[106];
            while (j >= 0)
            {
                nextj = gNextSpriteStat[j];
                if ((gpSprite[j].picnum == 9) && (gpSprite[j].hitag == 1221))
                    deleteSprite(j);

                j = nextj;
            }
        }
    }
}
