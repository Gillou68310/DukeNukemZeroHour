#include "common.h"
#include "code0/main.h"
#include "code0/audio.h"
#include "code0/graphics.h"
#include "code0/9410.h"
#include "code0/FDE0.h"
#include "code0/17B30.h"
#include "code0/1A7C0.h"
#include "code0/1E7A0.h"
#include "code0/24610.h"
#include "code0/37090.h"
#include "code0/41940.h"
#include "code0/6ACA0.h"
#include "code0/8EFE0.h"
#include "code0/95500.h"
#include "code0/code0.h"
#include "code1/code1.h"
#include "static/mapinfo.h"

/*TODO: include string.h from libkmc instead of libultra*/
char *strcpy(char *, const char *);
size_t strlen(const char *);

/*.data*/
/*800E18F8*/ EXTERN_DATA STATIC Lights2 D_800E18F8;
/*800E192C*/ EXTERN_DATA s32 D_800E192C;

/*.comm*/
/*80106D40*/ u8 D_80106D40;
/*80119A94*/ s16 D_80119A94;
/*8012FD70*/ u8 D_8012FD70[4];
/*8016A140*/ s16 D_8016A140;
/*80199944*/ s16 D_80199944;
/*8019994C*/ s16 D_8019994C;
/*801B0804*/ u8 D_801B0804;

/*.text*/

/*8009FAF0*/
void func_8009FAF0(void)
{
    s16 spritenum;
    u16 sectnum;
    SpriteType *spr;
    s16 temp;
    s32 i, j, k, nextj, nextk;

    for (i = 0; i < D_80138790; i++)
    {
        if (D_800DEE98 == 2)
        {
            sectnum = D_800FF3E8[i];
            temp = sectnum;
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
                    gpSprite[spritenum].unk1E = 5263;
                    gpSprite[spritenum].unk20 = 0;
                    gpSprite[spritenum].unk25 = 0x80;
                    gpSprite[spritenum].cstat = 0x8000;
                    gpSprite[spritenum].ang = 0;
                }
            }
        }
        j = gHeadSpriteSect[D_800FF3E8[i]];
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
        case 1307:
            func_8009A9F0(k);
            return;
        case 1309:
            func_8009C248(k);
            return;
        case 1306:
            func_8009E8C8(k);
            break;
        }
    }
}

/*8009FEB0*/
static s16 func_8009FEB0(s16 x, s16 y, char *arg2, s16 arg3)
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
        displayMessage2(x, y, buffer);
        y += 10;
    }
    return y;
}

/*800A0014*/
static void func_800A0014(void)
{
    char sp20[32];
    s16 x, y;
    s16 i, j, k;
    u8 cond;

    func_8000A070();
    x = D_80119A94 + 80;
    y = D_80199944 + 35;

    if (D_8012C989 != 0)
    {
        cond = 0;
        func_80029238(200, 200, 200, 0x80, 0x80, 0x80, D_80106D40);
        displayMessage2(x, y, "KEYS");
        y += 10;
        func_80029238(0, 200, 200, 0, 0x80, 0x80, D_80106D40);

        for (i = 1; i < ARRAY_COUNT(gPlayer[0].unk88); i++)
        {
            if (gPlayer[0].unk88[i] != 0)
            {
                displayMessage2(x, y, gpKeyStrInfo[gMapNum][i-1]);
                y += 10;
                cond = 1;
            }
        }
        if (!cond)
        {
            displayMessage2(x, y, "NONE");
            y += 10;
        }
        func_80029238(200, 200, 200, 0x80, 0x80, 0x80, D_80106D40);
        y += 10;
        displayMessage2(x, y, "TIME MACHINE PARTS");
        y += 10;
        func_80029238(0, 200, 200, 0, 0x80, 0x80, D_80106D40);

        if ((gMapNum == MAP_WETWORLD) || (gMapNum == MAP_BOSS_HOG) ||
            (gMapNum == MAP_CYBORG_SCORPION) || (gMapNum >= MAP_THE_RACK))
            displayMessage2(x, y, "NONE DETECTED");
        else if (gTimeMachinePart & (1 << gMapNum))
            displayMessage2(x, y, "PART COLLECTED");
        else
            displayMessage2(x, y, "PART NOT FOUND");
    }
    else
    {
        func_80029238(200, 200, 200, 0x80, 0x80, 0x80, D_80106D40);
        displayMessage2(x, y, "PRIMARY GOAL");
        y += 10;
        func_80029238(0, 200, 200, 0, 0x80, 0x80, D_80106D40);
        y = func_8009FEB0(x, y, gpObjectiveStrInfo[gMapNum].addr[0], 29);

        if (gpObjectiveStrInfo[gMapNum].count >= 2)
        {
            y += 10;
            func_80029238(200, 200, 200, 0x80, 0x80, 0x80, D_80106D40);
            displayMessage2(x, y, "CURRENT OBJECTIVES");
            y += 10;
            func_80029238(0, 200, 200, 0, 0x80, 0x80, D_80106D40);

            for (i = 1; i < gpObjectiveStrInfo[gMapNum].count; i++)
            {
                if (D_801AE91E[i] == 67)
                    y = func_8009FEB0(x, y, gpObjectiveStrInfo[gMapNum].addr[i], 29);
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

    sprintf(sp20, "TIME MACHINE PARTS %d:%d", k, 13);
    displayMessage2((D_80119A94 + 80), (D_80199944 + 135), sp20);
    sprintf(sp20, "SECRETS %d:%d   BABES %d:%d", D_801A1958.secrets_found,
            D_801A1958.secrets_total, D_801A1958.babes_saved, D_801A1958.babes_total);
    displayMessage2((D_80119A94 + 80), (D_80199944 + 145), sp20);
    gDPSetTextureLUT(gpDisplayList++, G_TT_RGBA16);
    gDPSetCombineMode(gpDisplayList++, G_CC_DECALRGBA, G_CC_PASS2);
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
    D_801AE8F4 = gPlayer[D_801B0820].unk4A;
    main_80000C74();
    func_8000F1E0();
    func_8000C76C();

    gSPSetLights2(gpDisplayList++, D_800E18F8);
    c = 0xFF;

    for (i = 0; i < D_8012C470; i++)
    {
        if (i != D_801B0820)
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

    x += (cosf(gpSprite[D_801AE8F4].ang * 0.0030679615757714844) * 1204.0f);
    y += (sinf(gpSprite[D_801AE8F4].ang * 0.0030679615757714844) * 1204.0f);

    temp = D_8012FD88 % 360; /*FAKEMATCH*/
    grPosition(
        &gpDynamic->mtx3[D_801A6D80 + 1],
        0.0f,
        180.0f,
        (D_8012FD88 % 360),
        1.0f,
        (x / 4.0),
        (y / 4.0),
        (z / 64.0));

    gSPMatrix(gpDisplayList++, OS_K0_TO_PHYSICAL(&gpDynamic->mtx3[D_801A6D80 + 1]),
              G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    D_801A6D80++;

    dlist = gpDisplayList;
    gpDisplayList = D_801297E0[D_801B0820][gGfxTaskIndex];
    func_80013FFC(func_80014040(gpSprite[D_801AE8F4].picnum));
    gSPEndDisplayList(gpDisplayList++);
    gSPDisplayList(dlist++, D_801297E0[D_801B0820][gGfxTaskIndex]);
    gpDisplayList = dlist;
}

/*800A0BD4*/
static void func_800A0BD4(s16 x, s16 y, char *arg2)
{
    char buffer[32];
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
            displayMessage1(x, y, buffer);
            j = 0;
            y += 12;
        }
    }
    if (j > 0)
    {
        buffer[j] = '\0';
        displayMessage1(x, y, buffer);
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
    if ((gMapNum < MAP_COUNT) && *gpMapStrInfo[gMapNum] != NULL)
        D_8016A140 = strlen(gpMapStrInfo[gMapNum]) + 142;
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

    for (i = 0; i < D_8012C470; i++)
        D_8012FD70[i] = 0;
}

INCLUDE_RODATA("nonmatchings/src/code0/A06F0", D_800E9E88);
INCLUDE_RODATA("nonmatchings/src/code0/A06F0", D_800E9EA4);
INCLUDE_RODATA("nonmatchings/src/code0/A06F0", D_800E9EBC);
INCLUDE_RODATA("nonmatchings/src/code0/A06F0", D_800E9ED4);
INCLUDE_RODATA("nonmatchings/src/code0/A06F0", D_800E9EDC);
INCLUDE_RODATA("nonmatchings/src/code0/A06F0", D_800E9EE8);
INCLUDE_RODATA("nonmatchings/src/code0/A06F0", D_800E9EF4);
/*800A0F84*/
INCLUDE_ASM("nonmatchings/src/code0/A06F0", func_800A0F84);

/*800A34CC*/
static void func_800A34CC(s32 x, s32 y, u16 tileid, s16 arg3)
{
    func_8001D128(&x, &y);
    func_80027C18(x,
                  y,
                  (D_80199110 * 3.0f) / 160.0,
                  (D_801A1980 * 3.0f) / 120.0,
                  getTileNum(tileid),
                  arg3);
}

/*800A359C*/
static void func_800A359C(s32 x, s32 y, u16 tileid, s16 arg3)
{
    f32 f1, f2;

    func_8001D128(&x, &y);
    f1 = (gScreenWidth * 3) / 320.0;
    f2 = (gScreenHeight * 3) / 240.0;
    func_80027C18(x,
                  y,
                  f1,
                  f2,
                  getTileNum(tileid),
                  arg3);
}

/*800A3688*/
INCLUDE_ASM("nonmatchings/src/code0/A06F0", func_800A3688);

/*800A419C*/
void func_800A419C(s16 arg0, char *arg1)
{
    s16 i;

    if (D_8012C470 == 1)
    {
        for (i = 3; i > 0; i--)
        {
            D_80138858[i] = D_80138858[i-1];
            strcpy(D_8012FCB0[i], D_8012FCB0[i-1]);
        }
        D_80138858[arg0] = 90;
        strcpy(D_8012FCB0[arg0], arg1);
    }
    else
    {
        D_80138858[arg0] = 90;
        strcpy(D_8012FCB0[arg0], arg1);
    }
}

/*800A42A4*/
static void func_800A42A4(s16 arg0)
{
    s16 i;
    u8 a;

    if (D_8012C470 == 1)
    {
        for (i = 0; i < ARRAY_COUNT(D_80138858); i++)
        {
            if (D_80138858[i] > 0)
            {
                if (D_8012FCB0[i] != NULL)
                {
                    a = CLAMP_MAX((D_80138858[i] * 8), 0xFF);
                    func_80029238(D_8012DF04[arg0].r, D_8012DF04[arg0].g, D_8012DF04[arg0].b, 0, 0, 0, a);
                    displayMessage1(-1, (72 - (i * 12)), D_8012FCB0[i]);
                }
            }
        }
    }
    else if (D_80138858[arg0] > 0)
    {
        if (D_8012FCB0[arg0] != NULL)
        {
            a = CLAMP_MAX((D_80138858[arg0] * 8), 0xFF);
            func_80029238(D_8012DF04[arg0].r, D_8012DF04[arg0].g, D_8012DF04[arg0].b, 0, 0, 0, a);
            displayMessage1(-1, 78, D_8012FCB0[arg0]);
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

    for (i = 0; i < D_8012C470; i++)
    {
        if ((gPlayer[i].unk54 != 0) || (D_8011814A[i] < 600))
            D_8012FD70[i] = 0x80;
        else
            D_8012FD70[i] = CLAMP_MIN((D_8012FD70[i] - 4), 0);

        if ((D_8010A940[i].unk0 == 7) && (D_8010A940[i].unkA[7] == 0x6000))
            D_80106D40 = CLAMP_MAX((D_80106D40 + 16), 0xFF);
        else
            D_80106D40 = 0;

        if (D_8012C470 >= 2)
        {
            if (D_801AD470 != 2)
            {
                if (gPlayer[i].unk45 != 0)
                {
                    if (gPlayer[i].unk4E > 90)
                        func_800A419C(i, "PRESS START");
                }
            }
        }
    }

    for (i = 0; i < 4; i++)
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

    if ((D_8012C470 == 1) && (D_801AC9F8 > 0))
    {
        D_801AC9F8--;
        D_80119A94 = krand() & 3;
        D_80199944 = krand() & 3;
    }

    if (gMapNum == MAP_PROBING_THE_DEPTHS)
    {
        switch (D_801CE498.difficulty)
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
        switch (D_801CE498.difficulty)
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
                if ((gpSprite[j].picnum == 9) && (gpSprite[j].unk20 == 1221))
                    deleteSprite(j);

                j = nextj;
            }
        }
    }
}
