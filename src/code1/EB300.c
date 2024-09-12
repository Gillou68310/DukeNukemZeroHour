#include "common.h"
#include "ld_symbols.h"
#include "code0/main.h"
#include "code0/cache1d.h"
#include "code0/audio.h"
#include "code0/edl.h"
#include "code0/debug.h"
#include "code0/4590.h"
#include "code0/64530.h"
#include "code0/6ACA0.h"
#include "code0/7F6A0.h"
#include "code0/7FCE0.h"
#include "code0/82480.h"
#include "code0/84490.h"
#include "code0/controller.h"
#include "code0/8E670.h"
#include "code0/data/E0640.h"
#include "code1/EB300.h"
#include "code0/code0.h"
#include "code1/code1.h"
#include "static/mapinfo.h"

typedef struct {
    /*0x00*/ ProcPointer func;
    /*0x04*/ u8 button_count;
    /*0x06*/ u16 button_list[11];
} CheatCode;

/*.data*/
/*801CA140*/ static s32 D_801CA140 = 2048;
/*801CA144*/ f32 D_801CA144 = 0.0f;
/*801CA148*/ static char D_801CA148 = ' ';

/*801CA14C*/
MapChapter gMapChapter[MAP_NUM+1] = {
#if VERSION_US
    { PRESENT_DAY, "MEAN STREETS" },
    { PRESENT_DAY, "LIBERTY OR DEATH" },
    { PRESENT_DAY, "NUCLEAR WINTER" },
    { PRESENT_DAY, "WETWORLD" },
    { PRESENT_DAY, "FALLOUT" },
    { PRESENT_DAY, "UNDER SIEGE" },
    { PRESENT_DAY, "BOSS HOG" },
    { WESTERN, "DRY TOWN" },
    { WESTERN, "JAIL BREAK" },
    { WESTERN, "UP SHIP CREEK" },
    { WESTERN, "FORT ROSWELL" },
    { WESTERN, "PROBING THE DEPTHS" },
    { WESTERN, "CYBORG SCORPION" },
    { VICTORIAN, "THE WHITECHAPEL KILLINGS" },
    { VICTORIAN, "DAWN OF THE DUKE" },
    { VICTORIAN, "HYDROGEN BOMB" },
    { VICTORIAN, "THE RACK" },
    { VICTORIAN, "GOING DOWN" },
    { VICTORIAN, "BRAINSTORM" },
    { FINAL, "THE BROTHERS NUKEM" },
    { FINAL, "ALIEN MOTHER..." },
    { FINAL, "ZERO HOUR" },
    { 9, "THE END" },
    { TRAINING, "BASE" },
    { DUKEMATCH, "COOL AS ICE" },
    { DUKEMATCH, "MIND FUNK" },
    { DUKEMATCH, "CHIMERA" },
    { DUKEMATCH, "SLIDERS" },
    { DUKEMATCH, "ATOMIC" },
    { DUKEMATCH, "HIGH NOON" },
    { DUKEMATCH, "ROCKY KNOLL" },
    { DUKEMATCH, "CASHING IN" },
    { DUKEMATCH, "HIVE 8" },
    { DUKEMATCH, "CASTLEMANIA" },
    { DUKEMATCH, "TOXIC SHOCK" },
    { DUKEMATCH, "FOGGING HELL" },
    { DUKEMATCH, "CATACOMBS" },
    { DUKEMATCH, "INFERNO" },
    { 99, "COOL AS ICE" },
#elif VERSION_FR
    { PRESENT_DAY, "LE BAS-FONDS" },
    { PRESENT_DAY, "LA LIBERTE OU LA MORT" },
    { PRESENT_DAY, "HIVER NUCLEAIRE" },
    { PRESENT_DAY, "HISTOIRE D'EAU" },
    { PRESENT_DAY, "RETOMBEES" },
    { PRESENT_DAY, "ETAT DE SIEGE" },
    { PRESENT_DAY, "LE SEIGNEUR DES PORCOFLICS" },
    { WESTERN, "VILLE FANTOME" },
    { WESTERN, "LA GRANDE EVASION" },
    { WESTERN, "LA CRIQUE AMONT" },
    { WESTERN, "FORT ROSWELL" },
    { WESTERN, "AU FOND DE LA MINE" },
    { WESTERN, "CYBER SCORPION" },
    { VICTORIAN, "MASSACRES A WHITECHAPEL" },
    { VICTORIAN, "L'AUBE DE DUKE" },
    { VICTORIAN, "LA BOMBE A HYDROGENE" },
    { VICTORIAN, "SUPPLICES ET DELICES" },
    { VICTORIAN, "UNE AVENTURE TITANESQUE" },
    { VICTORIAN, "DR BRAIN" },
    { FINAL, "LES FRERES NUKEM" },
    { FINAL, "LA SOURCE DU MAL" },
    { FINAL, "AU-DELA DU TEMPS" },
    { 9, "THE END" },
    { TRAINING, "BASE" },
    { DUKEMATCH, "FROID COMME LA GLACE" },
    { DUKEMATCH, "FUNKY" },
    { DUKEMATCH, "CHIMERES" },
    { DUKEMATCH, "PORTES COULISSANTES" },
    { DUKEMATCH, "ATOMIQUE" },
    { DUKEMATCH, "LE TRAIN SIFFLERA 4 FOIS" },
    { DUKEMATCH, "LE MONTICULE ROCHEUX" },
    { DUKEMATCH, "PAIEMENT CASH" },
    { DUKEMATCH, "RUCHE 8" },
    { DUKEMATCH, "CASTEL MANIA" },
    { DUKEMATCH, "DECHARGE TOXIQUE" },
    { DUKEMATCH, "LES BROUILLARDS DE L'ENFER" },
    { DUKEMATCH, "CATACOMBES" },
    { DUKEMATCH, "INFERNO" },
    { 99, "COOL AS ICE" },
#endif
};

static s16 _unused1[24] = {0, 8, 4, 1, 7, 3, 2, 6, 5, 4, 5, 1, 3, 5, 7, 4, 4, 2, 5, 3, 4, 6, 0, 3};
static s32 _unused2[23] = {0};

/*801CA310*/
static _119280UnkStruct1 D_801CA310[8] = {
    { 0, 16, 1, 2300, 1400 },
    { 1, 16, 0, 1500, 500 },
    { 2, 16, 2, 600, 300 },
    { 3, 16, 3, 600, 300 },
    { 11, 16, 11, 600, 300 },
    { 20, 16, 12, 100, 300 },
    { 21, 16, 21, 1200, 400 },
    { 22, 16, 22, 100, 300 },
};

/*801CA360*/
static _119280UnkStruct1 D_801CA360[4] = {
    { 4, 16, 4, 100, 300 },
    { 5, 16, 5, 100, 300 },
    { 6, 16, 6, 100, 300 },
    { 7, 16, 7, 100, 300 },
};

/*801CA388*/ static _119280UnkStruct1 D_801CA388[3] = {{ 8, 16, 8, 600, 300 }, { 9, 16, 9, 600, 300 }, { 10, 16, 10, 600, 300 }};
/*801CA3A8*/ static _119280UnkStruct1 D_801CA3A8 = {0, 24, 0, 2300, 1400};

/*801CA3B8*/
static Lights1 D_801CA3B8 = {
    { { { 48, 48, 48 }, 0, { 48, 48, 48 }, 0 } },
    { { { { 255, 255, 255 }, 0, { 255, 255, 255 }, 0, { 176, 176, 60 }, 0 } } },
};

/*801CA3D0*/ static s32 D_801CA3D0 = 0;
/*801CA3D4*/ static s32 D_801CA3D4 = 0;

/*.comm*/
/*801CC7F0*/ u8 *D_801CC7F0;
/*801CC7F8*/ s32 D_801CC7F8;
/*801CC800*/ code0UnkStruct16 *D_801CC800[34] ALIGNED(8);
/*801CC890*/ code0UnkStruct16 *D_801CC890;
/*801CC8B0*/ code0UnkStruct16 *D_801CC8B0;
/*801CC8BC*/ s32 D_801CC8BC;
/*801CC8C0*/ s32 D_801CC8C0;
/*801CC8C4*/ s32 D_801CC8C4;
/*801CC8D0*/ code0UnkStruct16 *D_801CC8D0[16] ALIGNED(8);
/*801CC910*/ s32 D_801CC910;
/*801CC914*/ code0UnkStruct16 *D_801CC914;
/*801CC918*/ u16 D_801CC918;
/*801CC928*/ s32 D_801CC928;
/*801CD970*/ s32 D_801CD970;
/*801CD974*/ s32 D_801CD974;
/*801CD978*/ code0UnkStruct16 *D_801CD978;
/*801CD97C*/ s16 D_801CD97C;
/*801CD990*/ code0UnkStruct16 *D_801CD990[36] ALIGNED(8);
/*801CDA20*/ code0UnkStruct16 *D_801CDA20;
/*801CDA28*/ code0UnkStruct16 *D_801CDA28[MAP_THE_END] ALIGNED(8);
/*801CDA84*/ code0UnkStruct16 *D_801CDA84;
/*801CDA88*/ s32 D_801CDA88;
/*801CDA8C*/ s32 D_801CDA8C;
/*801CDA90*/ u16 D_801CDA90; /*musHandle*/
/*801CDA94*/ u8 *D_801CDA94; /*edlHandle*/
/*801CDAA0*/ code1UnkStruct6 *D_801CDAA0[10] ALIGNED(8);
/*801CDAC8*/ s32 D_801CDAC8;
/*801CDAD4*/ u16 D_801CDAD4[22] ALIGNED(8);
/*801CDB04*/ s32 D_801CDB04;
/*801CDB0C*/ u16 D_801CDB0C;
/*801CDB20*/ s32 D_801CDB20;
/*801CDB28*/ u8 D_801CDB28[28] ALIGNED(8);
/*801CDB50*/ MapChapter *_pDukematchMapChapter;
/*801CDB54*/ s32 _cheatAwarded;
#ifdef AVOID_UB
char D_801CDB58[6][16] ALIGNED(8); /*Fix out of bound access in func_801C764C*/
#else
/*801CDB58*/ char D_801CDB58[5][16] ALIGNED(8);
#endif
/*801CDBA8*/ s32 D_801CDBA8;
/*801CDBB0*/ char D_801CDBB0[20] ALIGNED(8);
/*801CDBD0*/ code0UnkStruct16 *D_801CDBD0[6] ALIGNED(8);
/*801CDBF8*/ code0UnkStruct16 *D_801CDBF8;
/*801CDBFC*/ code0UnkStruct16 *D_801CDBFC;
/*801CDC00*/ s32 D_801CDC00[25] ALIGNED(8);
/*801CE474*/ s32 D_801CE474;
/*801CE484*/ s32 D_801CE484;
/*801CE488*/ s32 D_801CE488;
/*801CE490*/ s32 D_801CE490;
/*801CE494*/ s32 D_801CE494;
/*801CE4F0*/ code0UnkStruct16 *D_801CE4F0[25] ALIGNED(8);
/*801CE558*/ code0UnkStruct16 *D_801CE558[16] ALIGNED(8);
/*801CE59C*/ s32 D_801CE59C;
/*801CE5A4*/ s32 D_801CE5A4;
/*801CE5A8*/ code1UnkStruct6 *D_801CE5A8;
/*801CE5DC*/ s32 D_801CE5DC; /*mapnum*/
/*801CE5E0*/ code0UnkStruct16 *D_801CE5E0;
/*801CE5E4*/ code0UnkStruct16 *D_801CE5E4;
/*801CF62C*/ Gfx *D_801CF62C;
/*801CF630*/ s32 D_801CF630;
/*801CF638*/ u8 *D_801CF638; /*edlHandle*/
/*801CF63C*/ s32 D_801CF63C;
/*801CF640*/ s16 D_801CF640;
/*801CF648*/ char D_801CF648[30][5] ALIGNED(8);
/*801CF6E0*/ code0UnkStruct16 *D_801CF6E0[8] ALIGNED(8);
/*801CF708*/ u16 D_801CF708;
/*801CF70C*/ code0UnkStruct16 *D_801CF70C;
/*801CF710*/ s16 D_801CF710;

/*.text*/
static void func_801C3608(void);
static void func_801C37B8(void);
static void func_801C38DC(void);
static void func_801C3A88(s32);
static void func_801C3AD8(void);
static s16 func_801C53E8(s16);
static void func_801C5C68(void);
static void func_801C7108(void);
static void func_801C73A0(void);
static void func_801C73CC(void);
static void func_801C7574(void);
static void func_801C8650(void);
static void func_801C90E4(void);
static void func_801C948C(void);
static void func_801C959C(void);
static void func_801C9B08(void);
static void _menuControllerConfig(void);
static void _menuSelectPlayer(void);
static void _menuMultiplayerSelectGameType(void);
static void _menuSelectDifficulty(void);
static void _menuLoadGame(void);
static void _menuBack(void);
static void func_801C3874(void);
static void func_801C392C(void);
static void func_801C399C(void);
static void func_801C3974(void);
static void _menuSaveGame(void);
static void func_801C39C4(void);

/*801C0D80*/
static u16 func_801C0D80(void)
{
    s32 i;
    u16 j;

    j = 0;
    for (i = 0; i < D_801CDC64.unk1; i++)
        j |= D_801CD986[i];

    return j;
}

/*801C0DCC*/
static void func_801C0DCC(s32 arg0)
{
    s32 i;
    for (i = 0; i < D_801CDC64.unk1; i++)
        D_801CD986[i] &= ~arg0;
}

/*801C0E1C*/
static void func_801C0E1C(s32 arg0)
{
    s32 i;
    for (i = 0; i < D_801CDC64.unk1; i++)
        D_801CD986[i] |= arg0;
}

/*801C0E68*/
static u16 func_801C0E68(void)
{
    s32 i;
    u16 j;

    if (D_800BD3F9 == 5)
        return func_801C0D80();

    j = 0;
    for (i = 0; i < D_801CC8CA; i++)
        j |= D_801CD986[i];

    return j;
}

/*801C0EDC*/
static void func_801C0EDC(s32 arg0)
{
    s32 i;

    for (i = 0; i < D_801CC8CA; i++)
        D_801CD986[i] &= ~arg0;
}

/*801C0F28*/
static void func_801C0F28(s32 arg0)
{
    s32 i;

    for (i = 0; i < D_801CC8CA; i++)
        D_801CD986[i] |= arg0;
}

/*801C0F70*/
static void func_801C0F70(void)
{
    D_801CE5D8 = 0x25252525;
}

/*801C0F88*/
static u32 func_801C0F88(void)
{
    s32 i;

    i = D_801CE5D8;
    i *= 2;

    if ((D_801CE5D8 ^ i) < 0)
        i |= 1;

    i *= 31055;
    D_801CE5D8 = i;
    return i;
}

/*801C0FDC*/
s32 func_801C0FDC(s16 arg0)
{
    return ((func_801C0F88() >> 16) * arg0) >> 16; /*TODO?*/
}

/*801C1024*/
f32 tanf(f32 angle)
{
    f32 sin;
    f32 cos;

    cos = cosf(angle);
    sin = sinf(angle);

    if (cos == 0.0f)
        return 100000000.0;
    else
        return sin / cos;
}

/*801C1088*/
static f32 func_801C1088(s32 x1, s32 x2, s32 y1, s32 y2)
{
    return ((f32)getAngle(x2 - x1, y2 - y1) * (3.1415926/1024.0));
}

/*801C10C8*/
void func_801C10C8(void)
{
    alloCache(&D_801CD96C, EDL_FILE_MAX_SIZE, gCacheLock);
    func_8007EB24();
    D_801CE5D8 = 0x25252525;
}

/*801C1114*/
static void func_801C1114(void)
{
    code0UnkStruct16 *ptr;

    ptr = func_8007EC10(3);
    D_8011BC40 = ptr;
    ptr->unk10 = 0;
    D_801CC88C = 0;
    ptr->unk3C = -10239.0;
}

/*801C1158*/
static void func_801C1158(u8 r, u8 g, u8 b, u8 a)
{
    D_8011BC40->unk68.r = r;
    D_8011BC40->unk68.g = g;
    D_8011BC40->unk68.b = b;
    D_8011BC40->unk10 = a;
}

/*801C118C*/
static void func_801C118C(void)
{
    if (D_801CC88C != 0)
    {
        if (D_801CC88C < 0)
        {
            D_8011BC40->unk10 -= 16;
            if (D_8011BC40->unk10 <= 16)
            {
                D_8011BC40->unk10 = 0;
                D_801CC88C = 0;
            }
        }
        else
        {
            D_8011BC40->unk10 += 16;
            if (D_8011BC40->unk10 >= (255-16))
            {
                D_8011BC40->unk10 = 0xFF;
                D_801CC88C = 0;
            }
        }
    }
}

/*801C1218*/
void setCameraPosition(f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp, f32 yUp, f32 zUp)
{
    gPosition.xEye = xEye;
    gPosition.yEye = yEye;
    gPosition.zEye = zEye;
    gPosition.xAt = xAt;
    gPosition.yAt = yAt;
    gPosition.zAt = zAt;
    gPosition.xUp = xUp;
    gPosition.yUp = yUp;
    gPosition.zUp = zUp;
}

/*801C127C*/
static void func_801C127C(void)
{
    s32 i, j, cond;

    cond = 1;
    for (i = 0; i < D_801CC8CA; i++)
    {
        if (D_800BD3F9 == 3)
            cond = D_801AE914 != 0;

        if (cond != 0)
        {
            if (gStickY[i] > 60)
                gButton[i] |= U_JPAD;

            if (gStickY[i] < -60)
                gButton[i] |= D_JPAD;

            if (gStickX[i] > 60)
                gButton[i] |= R_JPAD;

            if (gStickX[i] < -60)
                gButton[i] |= L_JPAD;
        }

        for (j = 0; j < 16; j++)
        {
            if (!((D_801CDAD4[i] >> j) & 1))
            {
                if ((gButton[i] >> j) & 1)
                {
                    D_801CD986[i] |= 1 << j;
                    D_801CDAD4[i] |= 1 << j;
                }
            }
            if ((D_801CDAD4[i] >> j) & 1)
            {
                if (!((gButton[i] >> j) & 1))
                {
                    D_801CD986[i] &= ~(1 << j);
                    D_801CDAD4[i] &= ~(1 << j);
                }
            }
        }
    }
}

/*801C146C*/
void func_801C146C(void)
{
    D_801CE5D8 += D_801CC910;
    D_801CC910++;
    func_801C127C();
}

/*801C14B4*/
static void func_801C14B4(code0UnkStruct16 *arg0, u8 r, u8 g, u8 b)
{
    arg0->unk68.r = r;
    arg0->unk68.g = g;
    arg0->unk68.b = b;
}

/*801C14C4*/
static void func_801C14C4(code0UnkStruct16 *arg0, u8 r, u8 g, u8 b)
{
    arg0->unk6B.r = r;
    arg0->unk6B.g = g;
    arg0->unk6B.b = b;
}

/*801C14D4*/
void func_801C14D4(void)
{
    s32 i;

    D_801CD96C = gDepthBuffer - 746000;
    func_8007EB24();
    setCameraPosition(0.0f, 0.0f, -90.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    edl_80081688(&D_801CDB08, 20);
    edl_80081688(&D_801CC888, 21);
    edl_80081688(&D_801CDBC8, 23);
    edl_80081688(&D_801CDA98, 22);
    D_800E0F58 = 0;

    for (i = 0; i < ARRAY_COUNT(D_01022510); i++)
        func_80083200(&D_801CE5E8[i], 0);

    D_800E0F58 = 1;
}

/*801C15CC*/
void func_801C15CC(void)
{
    s32 i;

    D_801CE5D8 = 0x25252525;
    allocMemory(SCREEN_WIDTH, SCREEN_HEIGHT*2, DISPLAY_LIST_SIZE*2, 0);
    setCameraPosition(0.0f, 0.0f, -500.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    func_801C10C8();
    func_8007FD8C(&D_800DFA40[0], 0);
    D_801CDA94 = D_8010A938;
    func_8007FD8C(&D_800DFB08[0], 11);
    func_8007FD8C(&D_800E0778[0], 5);
    D_801CDA20 = func_8007FC08(&D_800DFA40[0], NULL, 0, 0, 500);
    edl_80081688(&D_801CF638, 16);
    edl_80081688(&D_801CC91C, 17);
    edl_80081688(&D_801CC920, 19);
    edl_80081688(&D_801CDB1C, 18);
    D_801CF70C = func_8008372C(0, &D_801CA310[1], 0x9080, &D_801CA3B8, 0);
    D_801CF62C = D_801ACBD4;
    gSPTexture(D_801ACBD4, 0x05BC, 0x05BC, 0, G_TX_RENDERTILE, G_ON);
    D_801CC890 = func_8008372C(0, &D_801CA310[2], 0, &D_801CA3B8, 0);
    D_801CC890->unk64 -= 30.0f;
    func_801C14B4(D_801CC890, 0, 0, 0xFF);
    D_801CF70C->unk3C = -1920.0f;
    D_801CDBFC = func_8008372C(0, &D_801CA310[3], 0x9080, &D_801CA3B8, 0);
    D_801CDBFC->unk12 = 80;
    D_801CDBFC->unk3C = 400.0f;
    func_801C14B4(D_801CDBFC, 0, 0, 0xFF);
    D_801CDB04 = 0;
    D_801CF630 = 0xFF;

    for (i = 0; i < ARRAY_COUNT(D_801CA360); i++)
        func_80083700(0, &D_801CA360[i], 0, 0);

    for (i = 0; i < ARRAY_COUNT(D_801CA388); i++)
        func_80083700(0, &D_801CA388[i], 0x1000, 0);

    func_80083700(0, &D_801CA310[0], 128, 0);
    main_80002390();
    main_80000610();
    func_801C1114();
    func_801C1158(0, 0, 0, 0xFF);
    D_801CC88C = -1;
    func_801C73A0();
    D_801CF640 = 0;
    D_801CC918 = 0;
    playSfx(1059);

    if ((gMusicHandle == 0) || (MusHandleAsk(gMusicHandle) == 0) || (gMusicNum != 2))
        playMusic(2);

    D_800BD3F9 = 1;
    D_801CD974 = 0;
}

/*801C1950*/
void func_801C1950(void)
{
    /*TODO: This function is reusing D_801AE538 as a pointer array? memory optimization?*/
    s32 i;

    func_801C73CC();
    if (gMusicVolume == 0)
    {
        MusHandleStop(gMusicHandle, 0);
        gMusicHandle = 0;
    }
    else if (gMusicHandle == 0)
        playMusic(gMusicNum);

    if (D_801CC88C == 1)
    {
        if ((D_8011BC40->unk10) == 0xFF)
        {
            if (D_801CDA8C == 0)
                func_8007F050();

            D_801CDA8C++;
            if (D_801CDA8C >= 5)
            {
                if (D_801CD974 > 1050)
                    main_80000624(main_80001FAC);
                else
                {
                    cache1d_8002AAEC();
                    func_801C3AD8();
                }
            }
        }
        else
        {
            D_8011BC40->unk10 += 0x10;
            if (D_8011BC40->unk10 >= 0xEF)
                D_8011BC40->unk10 = 0xFF;
        }
    }
    else
    {
        func_801C118C();
        D_801CD974++;

        if (func_801C0E68() & 0xFFFF)
            D_801CD974 = 0;

        if ((func_801C0E68() & 0x1000) || (D_801CD974 > 1050))
        {
            func_801C0EDC(0x1000);
            func_801C1158(0, 0, 0, 0);
            D_801CC88C = 1;
            D_801CDA8C = 0;
        }

        switch (D_801CDB04)
        {
        case 0:
            if (D_801CF70C->unk3C < -530.0f)
            {
                D_801CF70C->unk50 = -(D_801CF70C->unk3C + 530.0f) * 0.01;
                D_801CF70C->unk3C += 13.0f;
                D_801CDBFC->unk34 = tanf(D_801CF70C->unk50) * (D_801CDBFC->unk3C - D_801CF70C->unk3C);
                D_801CDBFC->unk40 = ((400.0f - D_801CF70C->unk3C) / 500.0) + 1.0;

                if ((D_801CDBFC->unk34 < 5000.0f) && (D_801CDBFC->unk34 > -5000.0f))
                    D_801CDBFC->unkC |= 1;
                else
                    D_801CDBFC->unkC &= ~1;
            }
            else
            {
                if (D_801CF630 == 0xFF)
                {
                    D_801CF70C->unk50 = 0.0f;
                    D_801CF70C->unk3C = -530.0f;
                    D_801CDBFC->unkC &= ~1;
                    func_801C1158(0xFF, 0xFF, 0xFF, 0xFF);
                    D_801CF630--;
                }
                else if (D_801CF630 == 254)
                {
                    func_8007FE04(D_800DFA40, 1, D_801CDA94);
                    D_801CF630--;
                }
                else
                {
                    if (D_801CF630 == 253)
                    {
                        D_801CE494 = 30;
                        D_801CF630 = 0;
                        D_801CDB04++;

                        for (i = 0; i < 15; i++)
                        {
                            ((code0UnkStruct16 **)D_801AE538)[i] = func_800837B8(&D_801CA360[i % 4], 0, &D_801CA3B8);
                            func_801C14B4(((code0UnkStruct16 **)D_801AE538)[i], 0xFF, 0xFF, 0xFF);
                            ((code0UnkStruct16 **)D_801AE538)[i]->unk3C = -600.0f;
                            ((code0UnkStruct16 **)D_801AE538)[i]->unk34 = (func_801C0FDC(0x200) - 0x100);
                            ((code0UnkStruct16 **)D_801AE538)[i]->unk38 = (func_801C0FDC(0x200) - 0x100);
                            ((code0UnkStruct16 **)D_801AE538)[i]->unk60 = ((func_801C0FDC(4) - 2) * 0.01);
                        }

                        for (i = 0; i < ARRAY_COUNT(D_801CE4F0); i++)
                        {
                            D_801CE4F0[i] = func_800837B8(&D_801CA388[i % 3], 0x1000, &D_801CA3B8);
                            D_801CE4F0[i]->unk3C = -600.0f;
                            D_801CE4F0[i]->unk34 = ((sins(i*2621) * 145) >> 14);
                            D_801CE4F0[i]->unk38 = ((coss(i*2621) * 145) >> 14);
                            D_801CE4F0[i]->unk58 = ((func_801C0FDC(24) - 12) * 0.01);
                            D_801CE4F0[i]->unk5C = ((func_801C0FDC(24) - 12) * 0.01);
                            D_801CE4F0[i]->unk60 = ((func_801C0FDC(24) - 12) * 0.01);
                            D_801CDC00[i] = 16;
                            D_801CE4F0[i]->unk40 = ((func_801C0FDC(150) / 200) + 0.5);
                        }
                        playSfx(1102);
                    }
                }
            }
            break;
        case 1:
            if (D_8011BC40->unk10 != 0)
            {
                if (D_8011BC40->unk10 >= 9)
                    D_8011BC40->unk10 -= 7;
                else
                    D_8011BC40->unk10 = 0;
            }

            if (D_801CE494 == 0)
            {
                D_801CDA20->unk34 = 0.0f;
                D_801CDA20->unk38 = 0.0f;
                D_801CF70C->unk34 = 0.0f;
                D_801CF70C->unk38 = 0.0f;
            }
            else
            {
                D_801CE494--;
                D_801CA3D0 = func_801C0FDC(D_801CE494) - (D_801CE494 / 2);
                D_801CA3D4 = func_801C0FDC(D_801CE494) - (D_801CE494 / 2);
                D_801CDA20->unk34 = D_801CA3D0;
                D_801CDA20->unk38 = D_801CA3D4;
                D_801CF70C->unk34 = (D_801CA3D0 * 4);
                D_801CF70C->unk38 = (-D_801CA3D4 * 2);
            }

            D_801CF630++;
            for (i = 0; i < 15; i++)
            {
                ((code0UnkStruct16 **)D_801AE538)[i]->unk3C -= 10.0f;
                if (((code0UnkStruct16 **)D_801AE538)[i]->unk12 != 0)
                    ((code0UnkStruct16 **)D_801AE538)[i]->unk12 -= 2;
            }

            for (i = 0; i < ARRAY_COUNT(D_801CDC00); i++)
            {
                if (D_801CE494 == 2)
                    D_801CDC00[i] = func_801C0FDC(24) + 8;
                D_801CE4F0[i]->unk3C -= D_801CDC00[i];
            }

            if (D_801CF630 >= 121)
            {

                for (i = 0; i < 15; i++)
                    func_8007ECC8(((code0UnkStruct16 **)D_801AE538)[i]);

                for (i = 0; i < ARRAY_COUNT(D_801CE4F0); i++)
                    func_8007ECC8(D_801CE4F0[i]);

                D_801CD978 = func_800837B8(&D_801CA310[0], 128, &D_801CA3B8);
                D_801CD978->unk34 = -910.0f;
                D_801CD978->unk38 = -10.0f;
                D_801CD978->unk3C = -1850.0f;
                D_801CD978->unk40 = 0.3f;
                D_801CD978->unk4C = 0.22f;
                D_801CDA84 = func_8008372C(0, &D_801CA310[4], 0, &D_801CA3B8, 0);
                func_801C14B4(D_801CDA84, 0, 0, 0);
                func_801C14C4(D_801CDA84, 0, 0, 0);
                D_801CDA84->unk12 = 150;
                D_801CDA84->unk3C = -600.0f;
                playSfx(1057);
                D_801CDB04++;
            }
            break;
        case 2:
            if (D_801CC890 != NULL)
            {
                D_801CC890->unk12 -= 10;
                if (D_801CC890->unk12 < 14)
                {
                    func_8007ECC8(D_801CC890);
                    D_801CC890 = NULL;
                }
            }

            if (D_801CD978->unk34 < 0.0f)
                D_801CD978->unk34 += 16.0f;
            else
            {
                D_801CD978->unk34 = 0.0f;
                D_801CDB04++;
            }
            break;
        case 3:
            if (D_801CD978->unk3C > -1900.0f)
                D_801CD978->unk3C += -25.0f;
            else
            {
                D_801CD978->unk3C = -1900.0f;
                D_801CDB04++;
            }
            break;
        case 4:
            if (!(D_801CD978->unk38 < 280.0f))
                D_801CD978->unk38 = 280.0f;
            else
            {
                D_801CD978->unk38 += 19.0f;
                if ((D_801CD978->unk38 > 280.0f))
                    D_801CD978->unk38 = 280.0f;
            }

            if (D_801CD978->unk3C < -600.0f)
            {
                D_801CD978->unk3C += 86.0f;
                if (D_801CD978->unk3C > -600.0f)
                {
                    playSfx(1103);
                    D_801CE494 = 20;
                    D_801CD978->unk3C = -600.0f;
                }
            }
            else
            {
                if (D_801CE494 == 0)
                {
                    D_801CDA20->unk34 = 0.0f;
                    D_801CDA20->unk38 = 0.0f;
                    D_801CF70C->unk34 = 0.0f;
                    D_801CF70C->unk38 = 0.0f;
                    D_801CD978->unk34 = 0.0f;
                    D_801CD978->unk38 = 280.0f;
                    D_801CDB04++;
                }
                else
                {
                    D_801CE494--;
                    D_801CA3D0 = func_801C0FDC(D_801CE494) - (D_801CE494 / 2);
                    D_801CA3D4 = func_801C0FDC(D_801CE494) - (D_801CE494 / 2);
                    D_801CDA20->unk34 = D_801CA3D0;
                    D_801CDA20->unk38 = D_801CA3D4;
                    D_801CF70C->unk34 = (D_801CA3D0 * 4);
                    D_801CF70C->unk38 = (-D_801CA3D4 * 2);
                    D_801CD978->unk34 = (D_801CA3D0 * 4);
                    D_801CD978->unk38 = (280 - (D_801CA3D4 * 2));
                }
            }
            break;
        case 5:
            func_8007FE2C("^", gScreenWidth - 30, 60, 64, 1, 0);
            D_801CDB04++;
            break;
        case 6:
            D_801CE5E4 = func_8007FC08(&D_800E0778[0], NULL, -181, gScreenHeight - 175, -2000);
            D_801CC914 = func_8007FC08(&D_800E0778[1], NULL, gScreenWidth + 58, gScreenHeight - 175, -2000);
            D_801CDB04++;
            break;
        case 7:
            D_801CE5E4->unk34 += 16.0f;
            D_801CC914->unk34 -= 16.0f;
            if (D_801CC914->unk34 < (gScreenWidth/2 + 17))
            {
                playSfx(1058);
                D_801CE494 = 20;
                D_801CE484 = D_801CE5E4->unk34;
                D_801CDB04++;
                D_801CC928 = D_801CC914->unk34;
                D_801CE5A4 = D_801CE5E4->unk38;
                D_801CC7F8 = D_801CC914->unk38;
            }
            break;
        case 8:
            if (D_801CE494 == 0)
            {
                D_801CDA20->unk34 = 0.0f;
                D_801CDA20->unk38 = 0.0f;
                D_801CF70C->unk34 = 0.0f;
                D_801CF70C->unk38 = 0.0f;
                D_801CD978->unk38 = 280.0f;
                D_801CD978->unk34 = 0.0f;
                D_801CE5E4->unk34 = D_801CE484;
                D_801CC914->unk34 = D_801CC928;
                D_801CE5E4->unk38 = D_801CE5A4;
                D_801CC914->unk38 = D_801CC7F8;
#if VERSION_US
                D_801CE5E0 = func_8007FE2C("PRESS START", gScreenWidth / 2, gScreenHeight - 48, 64, 1, 0);
#elif VERSION_FR
                D_801CE5E0 = func_8007FE2C("APPUYER SUR START", gScreenWidth / 2, gScreenHeight - 48, 64, 1, 0);
#endif
                D_801CDB04++;
            }
            else
            {
                D_801CE494--;
                D_801CA3D0 = func_801C0FDC(D_801CE494) - (D_801CE494 / 2);
                D_801CA3D4 = func_801C0FDC(D_801CE494) - (D_801CE494 / 2);
                D_801CDA20->unk34 = D_801CA3D0;
                D_801CDA20->unk38 = D_801CA3D4;
                D_801CE5E4->unk34 = (D_801CE484 + D_801CA3D0);
                D_801CE5E4->unk38 = (D_801CE5A4 + D_801CA3D4);
                D_801CC914->unk34 = (D_801CC928 + D_801CA3D0);
                D_801CC914->unk38 = (D_801CC7F8 + D_801CA3D4);
                D_801CF70C->unk34 = (D_801CA3D0 * 4);
                D_801CF70C->unk38 = (-D_801CA3D4 * 2);
                D_801CD978->unk34 = (D_801CA3D0 * 4);
                D_801CD978->unk38 = (280 - (D_801CA3D4 * 2));
            }
            break;
        }

        if (((D_801CDB04 >= 2) && (D_801CDB04 < 5)) || ((D_801CDB04 == 8)))
        {
            D_801CDA84->unk40 = (600.0f - D_801CD978->unk3C) / 1275.0;
            D_801CDA84->unk38 = (D_801CD978->unk38 * 0.8) - 135.0;
            D_801CDA84->unk34 = (D_801CD978->unk34 * 1.5) - 30.0;
        }

        if (D_801CDB04 >= 7)
        {
            if ((D_801CC910 & 0xF) < 7)
            {
                if (D_801CDB04 == 9)
                    D_801CE5E0->unkC &= ~1;
            }
            else if (D_801CDB04 == 9)
                D_801CE5E0->unkC |= 1;
        }

        if (D_801CC890 != NULL)
        {
            D_801CC890->unk50 = D_801CF70C->unk50;
            D_801CC890->unk34 = D_801CF70C->unk34;
            D_801CC890->unk38 = D_801CF70C->unk38;
            D_801CC890->unk3C = D_801CF70C->unk3C;
        }
    }
}

extern code1UnkStruct6 D_801CA970;

/*801C2BE8*/
void func_801C2BE8(code1UnkStruct6 *arg0)
{
    code1UnkStruct5 *ptr;
    s32 i;
    s16 j;

    ptr = arg0->unk4;
    D_801CE490 = 0;

    for (i = 0; i < arg0->unk0; i++, ptr++)
    {
        j = ptr->unk2;

        if (j == -1)
            j = gScreenWidth / 2;
        else if (gScreenWidth == 512)
            j += 96;

        D_801CD990[D_801CE490] = func_800802C0(ptr->unk8, j, arg0->unk8 + (i * arg0->unkA), 200, ptr->unk0);

        if (ptr->unk4 & 1)
        {
            func_801C14C4(D_801CD990[D_801CE490], 32, 0xFF, 32);
            D_801CD990[D_801CE490]->unk3C -= 100.0f;
        }
        else
            func_801C14C4(D_801CD990[D_801CE490], 140, 140, 165);

        if (ptr->unk4 & 2)
            D_801CD990[D_801CE490]->unk12 = 150;

        D_801CE490++;
        if (ptr->unk14 != NULL)
        {
            j = ptr->unk14->unk4[ptr->unk18[0]].unk2;

            if (j == -1)
                j = gScreenWidth / 2;
            else if (gScreenWidth == 512)
                j += 96;

            D_801CD990[D_801CE490-1]->unk7C = func_800802C0(ptr->unk14->unk4[ptr->unk18[0]].unk8,
                                                            j,
                                                            arg0->unk8 + (i * arg0->unkA),
                                                            200,
                                                            ptr->unk14->unk4[ptr->unk18[0]].unk0);

            if ((ptr->unk14 == &D_801CA970) && ((ptr->unk18[0] != 0)))
                func_801C14C4((code0UnkStruct16 *)D_801CD990[D_801CE490-1]->unk7C, 0xFF, 0xFF, 0xFF);
            else
                func_801C14C4((code0UnkStruct16 *)D_801CD990[D_801CE490-1]->unk7C, 0, 200, 200);

            if (ptr->unk14->unk4->unk4 & 2)
                ((code0UnkStruct16 *)D_801CD990[D_801CE490-1]->unk7C)->unk12 = 150;
        }
    }
    D_801CE5A8 = arg0;
}

/*801C2F1C*/
static void func_801C2F1C(void)
{
    s32 i;

    for (i = 0; i < D_801CE490; i++)
    {
        if (D_801CD990[i]->unk7C != 0)
            func_8007ECC8((code0UnkStruct16 *)D_801CD990[i]->unk7C);

        func_8007ECC8(D_801CD990[i]);
    }
}

/*801C2F98*/
static void _menuEnter(void)
{
    code1UnkStruct6 *ptr;

    func_801C2F1C();
    gConfig.menuIndex.multiplayer_options = 8;
    gConfig.menuIndex.unk5 = 1;
    D_801CDAA0[D_801CD980] = D_801CE5A8;
    D_801CD980++;
    *D_801CE5A8->unkC = D_801CE5A0;
    ptr = D_801CE5A8->unk4[D_801CE5A0].unk10;
    D_801CE5A8 = ptr;
    func_801C3A88(*ptr->unkC);
    func_801C2BE8(D_801CE5A8);
}

/*801C305C*/
static void _menuExit(void)
{
    code1UnkStruct6 *ptr;

    if (D_801CD980 != 0)
    {
        func_801C2F1C();
        D_801CD980--;
        *D_801CE5A8->unkC = D_801CE5A0;
        ptr = D_801CDAA0[D_801CD980];
        D_801CE5A8 = ptr;
        D_801CE5A0 = *ptr->unkC;
        func_801C2BE8(ptr);
    }
}

/*801CA3D8*/
static code1UnkStruct5 D_801CA3D8[5] = {
#if VERSION_US
    { 1, -1, 1, 0, "IF RUMBLE PAKS ARE", NULL, NULL, NULL, NULL },
    { 1, -1, 1, 0, "TO BE USED, PLEASE", NULL, NULL, NULL, NULL },
    { 1, -1, 1, 0, "INSERT THEM INTO", NULL, NULL, NULL, NULL },
    { 1, -1, 1, 0, "THE CONTROLLERS", NULL, NULL, NULL, NULL },
    { 1, -1, 1, 0, "AND PRESS START", NULL, NULL, NULL, NULL },
#elif VERSION_FR
    { 1, -1, 1, 0, "SI VOUS UTILISEZ", NULL, NULL, NULL, NULL },
    { 1, -1, 1, 0, "DES RUMBLE PAKS", NULL, NULL, NULL, NULL },
    { 1, -1, 1, 0, "VEUILLEZ LES", NULL, NULL, NULL, NULL },
    { 1, -1, 1, 0, "INSERER DANS LES", NULL, NULL, NULL, NULL },
    { 1, -1, 1, 0, "MANETTES", NULL, NULL, NULL, NULL },
#endif
};

/*801CA464*/ static code1UnkStruct6 D_801CA464 = {ARRAY_COUNT(D_801CA3D8), D_801CA3D8, 68, 24, NULL};

/*801C30EC*/
static void func_801C30EC(void)
{
    s32 i;
    s64 prev;

#ifdef TARGET_N64
    prev = D_800FE9E0;
    while (prev == D_800FE9E0);
#else
    (void)prev;
#endif

    cache1d_8002AAEC();
    edl_80081688(&D_801CDB08, 20);
    edl_80081688(&D_801CC888, 21);
    edl_80081688(&D_801CDBC8, 23);
    edl_80081688(&D_801CDA98, 22);
    func_8007FD8C(&D_800DFAE0[0], 4);
    D_800E0F58 = 0;

    for (i = 0; i < ARRAY_COUNT(D_01022510); i++)
        func_80083700(1, &D_801CE5E8[i], 0, 0);

    D_800E0F58 = 1;
    func_8007F050();
    D_801CDA20 = func_8007FC08(&D_800DFAE0[0], NULL, 0, 0, 500);
    func_801C1114();
    func_801C1158(0, 0, 0, 0xFF);
    D_801CC88C = -1;
    func_801C2BE8(&D_801CA464);
    D_801CC8C0 = 0;
    D_800BD3F9 = 13;
    D_801CA144 = 1.8f;
}

/*801C328C*/
static void _menuMultiplayerSelectLevel(void)
{
    D_801CDC64.unk2 = D_801CE5A0;
    main_80000624(func_801C8650);
}

/*801C32C4*/
static void func_801C32C4(void)
{
    if (gConfig.rumblepak == 0)
    {
        main_80000624(func_801C9B08);
    }
    else
    {
        func_801C30EC();
        D_801CDAC8 = 0;
    }
}

/*801C3310*/
static void func_801C3310(void)
{
    if ((gLoadMapNum == MAP_THE_END) || (gConfig.rumblepak == 0))
        main_80000624(func_801C9B08);
    else
    {
        func_801C30EC();
        D_801CDAC8 = 0;
    }
}

/*801C3370*/
void func_801C3370(void)
{
    s32 prev;
    func_801C118C();

    if (D_801CC8C0 == 1)
    {
        if (D_801CA144 > -1.8)
        {
            D_801CA144 -= 0.2;
            if (D_801CA144 < -1.8)
            {
                prev = D_801CC8C0;
                D_801CC8C0 = 0;
                D_80199524 = prev;
                D_801CA144 = 1.8f;

                switch (D_801CDAC8)
                {
                case 0:
                    main_80000624(func_801C9B08);
                    break;

                case 1:
                    func_801C3608();
                    break;
                }
                return;
            }
        }
    }
    if (D_801CC8C0 == 0)
    {
        if (D_801CA144 > 0.0f)
        {
            D_801CA144 -= 0.2;
            if (D_801CA144 < 0.0f)
                D_801CA144 = 0.0f;
        }
        if ((func_801C0D80() & 0x8000) || (func_801C0D80() & 0x1000))
        {
            func_801C0DCC(0x8000);
            func_801C0DCC(0x1000);
            playSfx(747);
            D_801CC8C0 = 1;
            D_801CC88C = 1;
        }
    }
}

/*801C3524*/
void func_801C3524(void)
{
    if (MusHandleAsk(D_801CDA90) == 0)
    {
        MusStop(2, 30);
        *D_801CE5A8->unkC = D_801CE5A0;
        func_801C37B8();
        func_801C32C4();
    }
}

/*801CA474*/
static code1UnkStruct5 D_801CA474[3] = {
#if VERSION_US
    { 1, 280, 0, 0, "2", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "3", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "4", NULL, NULL, NULL, NULL },
#elif VERSION_FR
    { 1, 284, 0, 0, "2", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "3", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "4", NULL, NULL, NULL, NULL },
#endif
};

/*801CA4C8*/ static code1UnkStruct6 D_801CA4C8 = {ARRAY_COUNT(D_801CA474), D_801CA474, 0, 0, NULL};

/*801CA4D8*/
static code1UnkStruct5 D_801CA4D8[11] = {
#if VERSION_US
    { 1, 280, 0, 0, "DEFAULT", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "a", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "b", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "c", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "d", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "e", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "f", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "g", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "h", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "i", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "NONE", NULL, NULL, NULL, NULL },
#elif VERSION_FR
    { 1, 284, 0, 0, "PAR DEFAUT", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "a", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "b", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "c", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "d", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "e", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "f", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "g", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "h", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "i", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "AUCUN", NULL, NULL, NULL, NULL },
#endif
};

/*801CA60C*/ static code1UnkStruct6 D_801CA60C = {ARRAY_COUNT(D_801CA4D8), D_801CA4D8, 0, 0, NULL};

/*801CA61C*/
static code1UnkStruct5 D_801CA61C[3] = {
#if VERSION_US
    { 1, 280, 0, 0, "LOW", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "MEDIUM", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "HIGH", NULL, NULL, NULL, NULL },
#elif VERSION_FR
    { 1, 284, 0, 0, "FAIBLE", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "MOYEN", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "ELEVE", NULL, NULL, NULL, NULL },
#endif
};

/*801CA670*/ static code1UnkStruct6 D_801CA670 = {ARRAY_COUNT(D_801CA61C), D_801CA61C, 0, 0, NULL};

/*801CA680*/
static code1UnkStruct5 D_801CA680[8] = {
#if VERSION_US
    { 1, 280, 0, 0, "DUKE", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "ATOMIC", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "SHAKEN", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "STIRRED", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "NUKE", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "NITRO", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "GOLDEN", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "DIAMOND", NULL, NULL, NULL, NULL },
#elif VERSION_FR
    { 1, 284, 0, 0, "DUKE", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "ATOMIC", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "SECOUSSE", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "FRISSON", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "NUCLEAIRE", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "NITRO", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "OR", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "DIAMANT", NULL, NULL, NULL, NULL },
#endif
};

/*801CA760*/ static code1UnkStruct6 D_801CA760 = {ARRAY_COUNT(D_801CA680), D_801CA680, 0, 0, NULL};

/*801CA770*/
static code1UnkStruct5 D_801CA770[2] = {
#if VERSION_US
    { 1, 280, 0, 0, "OFF", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "ON", NULL, NULL, NULL, NULL },
#elif VERSION_FR
    { 1, 284, 0, 0, "DESACT.", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "ACTIVE", NULL, NULL, NULL, NULL },
#endif
};

/*801CA7A8*/ static code1UnkStruct6 D_801CA7A8 = {ARRAY_COUNT(D_801CA770), D_801CA770, 0, 0, NULL};

#if VERSION_FR
static code1UnkStruct5 _ouiNonElmt[2] = {
    { 1, 284, 0, 0, "NON", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "OUI", NULL, NULL, NULL, NULL },
};

static code1UnkStruct6 _ouiNon = {ARRAY_COUNT(_ouiNonElmt), _ouiNonElmt, 0, 0, NULL};
#endif

/*801CA7B8*/
static code1UnkStruct5 D_801CA7B8[2] = {
#if VERSION_US
    { 1, 280, 0, 0, "HORZ", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "VERT", NULL, NULL, NULL, NULL },
#elif VERSION_FR
    { 1, 284, 0, 0, "HORIZ.", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "VERT.", NULL, NULL, NULL, NULL },
#endif
};

/*801CA7F0*/ static code1UnkStruct6 D_801CA7F0 = {ARRAY_COUNT(D_801CA7B8), D_801CA7B8, 0, 0, NULL};

/*801CA800*/
static code1UnkStruct5 D_801CA800[2] = {
#if VERSION_US
    { 1, 280, 0, 0, "EQUAL", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "FULL", NULL, NULL, NULL, NULL },
#elif VERSION_FR
    { 1, 284, 0, 0, "EGAL", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "PLEIN ECRAN", NULL, NULL, NULL, NULL },
#endif
};

/*801CA838*/ static code1UnkStruct6 D_801CA838 = {ARRAY_COUNT(D_801CA800), D_801CA800, 0, 0, NULL};

/*801CA848*/
static code1UnkStruct5 D_801CA848[2] = {
#if VERSION_US
    { 1, 280, 0, 0, "MONO", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "STEREO", NULL, NULL, NULL, NULL },
#elif VERSION_FR
    { 1, 284, 0, 0, "MONO", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "STEREO", NULL, NULL, NULL, NULL },
#endif
};

/*801CA880*/ static code1UnkStruct6 D_801CA880 = {ARRAY_COUNT(D_801CA848), D_801CA848, 0, 0, NULL};

/*801CA890*/
static code1UnkStruct5 D_801CA890[8] = {
#if VERSION_US
    { 0, 332, 0, 0, "^OFF", NULL, NULL, NULL, NULL },
    { 0, 332, 0, 0, "~}|", NULL, NULL, NULL, NULL },
    { 0, 332, 0, 0, "~}}|", NULL, NULL, NULL, NULL },
    { 0, 332, 0, 0, "~}}}|", NULL, NULL, NULL, NULL },
    { 0, 332, 0, 0, "~}}}}|", NULL, NULL, NULL, NULL },
    { 0, 332, 0, 0, "~}}}}}|", NULL, NULL, NULL, NULL },
    { 0, 332, 0, 0, "~}}}}}}|", NULL, NULL, NULL, NULL },
    { 0, 332, 0, 0, "~}}}}}}}|", NULL, NULL, NULL, NULL },
#elif VERSION_FR
    { 0, 336, 0, 0, "^DESACT.", NULL, NULL, NULL, NULL },
    { 0, 336, 0, 0, "~}|", NULL, NULL, NULL, NULL },
    { 0, 336, 0, 0, "~}}|", NULL, NULL, NULL, NULL },
    { 0, 336, 0, 0, "~}}}|", NULL, NULL, NULL, NULL },
    { 0, 336, 0, 0, "~}}}}|", NULL, NULL, NULL, NULL },
    { 0, 336, 0, 0, "~}}}}}|", NULL, NULL, NULL, NULL },
    { 0, 336, 0, 0, "~}}}}}}|", NULL, NULL, NULL, NULL },
    { 0, 336, 0, 0, "~}}}}}}}|", NULL, NULL, NULL, NULL },
#endif
};

/*801CA970*/ code1UnkStruct6 D_801CA970 = {ARRAY_COUNT(D_801CA890), D_801CA890, 0, 0, NULL};

/*801CA980*/
static code1UnkStruct5 D_801CA980[3] = {
#if VERSION_US
    { 1, 280, 0, 0, "NORMAL", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "MEDIUM", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "HIGHRES", NULL, NULL, NULL, NULL },
#elif VERSION_FR
    { 1, 284, 0, 0, "NORMAL", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "MOYEN", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "HAUTE RES", NULL, NULL, NULL, NULL },
#endif
};

/*801CA9D4*/ static code1UnkStruct6 D_801CA9D4 = {ARRAY_COUNT(D_801CA980), D_801CA980, 0, 0, NULL};

/*801CA9E4*/
static code1UnkStruct5 D_801CA9E4[2] = {
#if VERSION_US
    { 1, -1, 1, 0, "CONFIGURATION", NULL, NULL, NULL, NULL },
    { 0, 16, 0, 0, "PRESET", NULL, NULL, &D_801CA760, gConfig.controller_preset },
#elif VERSION_FR
    { 1, -1, 1, 0, "CONFIGURATION", NULL, NULL, NULL, NULL },
    { 0, -55, 0, 0, "PRESELECTION", NULL, NULL, &D_801CA760, gConfig.controller_preset },
#endif
};

/*801CAA1C*/ static code1UnkStruct6 D_801CAA1C = {ARRAY_COUNT(D_801CA9E4), D_801CA9E4, 0, 230, &gConfig.menuIndex.controller_config};

/*801CAA2C*/
static code1UnkStruct5 D_801CAA2C[5] = {
#if VERSION_US
    { 1, -1, 1, 0, "PLAYER SETUP", NULL, NULL, NULL, NULL },
    { 1, -1, 0, 0, "CONTROL CONFIGURATION", _menuControllerConfig, &D_801CAA1C, NULL, NULL, },
    { 0, 0, 0, 0, "CROSSHAIR", NULL, NULL, &D_801CA60C, gConfig.crosshair },
    { 0, 0, 0, 0, "AUTOAIM", NULL, NULL, &D_801CA670, gConfig.autoaim },
    { 0, 0, 0, 0, "AUTO CENTER", NULL, NULL, &D_801CA7A8, gConfig.autocenter },
#elif VERSION_FR
    { 1, -1, 1, 0, "CONFIG. JOUEURS", NULL, NULL, NULL, NULL },
    { 1, -1, 0, 0, "CONFIG. COMMANDES", _menuControllerConfig, &D_801CAA1C, NULL, NULL, },
    { 0, -55, 0, 0, "MIRE", NULL, NULL, &D_801CA60C, gConfig.crosshair },
    { 0, -55, 0, 0, "VISEE AUTO", NULL, NULL, &D_801CA670, gConfig.autoaim },
    { 0, -55, 0, 0, "AUTO CENTER", NULL, NULL, &D_801CA7A8, gConfig.autocenter },
#endif
};

/*801CAAB8*/ static code1UnkStruct6 D_801CAAB8 = {ARRAY_COUNT(D_801CAA2C), D_801CAA2C, 56, 24, &gConfig.menuIndex.player_setup};

/*801CAAC8*/
static code1UnkStruct5 D_801CAAC8[4] = {
#if VERSION_US
    { 1, -1, 0, 0, "PLAYER ONE", _menuSelectPlayer, &D_801CAAB8, NULL, NULL },
    { 1, -1, 0, 0, "PLAYER TWO", _menuSelectPlayer, &D_801CAAB8, NULL, NULL },
    { 1, -1, 0, 0, "PLAYER THREE", _menuSelectPlayer, &D_801CAAB8, NULL, NULL },
    { 1, -1, 0, 0, "PLAYER FOUR", _menuSelectPlayer, &D_801CAAB8, NULL, NULL },
#elif VERSION_FR
    { 1, -1, 0, 0, "JOUEUR UN", _menuSelectPlayer, &D_801CAAB8, NULL, NULL },
    { 1, -1, 0, 0, "JOUEUR DEUX", _menuSelectPlayer, &D_801CAAB8, NULL, NULL },
    { 1, -1, 0, 0, "JOUEUR TROIS", _menuSelectPlayer, &D_801CAAB8, NULL, NULL },
    { 1, -1, 0, 0, "JOUEUR QUATRE", _menuSelectPlayer, &D_801CAAB8, NULL, NULL },
#endif
};

/*801CAB38*/ static code1UnkStruct6 D_801CAB38 = {ARRAY_COUNT(D_801CAAC8), D_801CAAC8, 84, 24, &gConfig.menuIndex.select_player};

/*801CAB48*/
static code1UnkStruct5 D_801CAB48[8] = {
#if VERSION_US
    { 1, -1, 1, 0, "OPTIONS", NULL, NULL, NULL, NULL },
    { 0, 0, 0, 0, "SFX VOLUME", NULL, NULL, &D_801CA970, &gConfig.mastervol },
    { 0, 0, 0, 0, "MUSIC VOLUME", NULL, NULL, &D_801CA970, &gConfig.musicvol },
    { 0, 0, 0, 0, "SOUND", NULL, NULL, &D_801CA880, &gConfig.sound },
    { 0, 0, 0, 0, "RUMBLE PAK", NULL, NULL, &D_801CA970, &gConfig.rumblepak },
    { 0, 0, 0, 0, "GRAPHICS", NULL, NULL, &D_801CA9D4, &gGraphicsOption },
    { 1, -1, 0, 0, "PLAYER SETUP", _menuEnter, &D_801CAB38, NULL, NULL },
    { 1, -1, 0, 0, "EXIT", _menuExit, NULL, NULL, NULL },
#elif VERSION_FR
    { 1, -1, 1, 0, "OPTIONS", NULL, NULL, NULL, NULL },
    { 0, -55, 0, 0, "VOLUME FX", NULL, NULL, &D_801CA970, &gConfig.mastervol },
    { 0, -55, 0, 0, "VOLUME MUSIQUE", NULL, NULL, &D_801CA970, &gConfig.musicvol },
    { 0, -55, 0, 0, "SON", NULL, NULL, &D_801CA880, &gConfig.sound },
    { 0, -55, 0, 0, "RUMBLE PAK", NULL, NULL, &D_801CA970, &gConfig.rumblepak },
    { 0, -55, 0, 0, "GRAPHISMES", NULL, NULL, &D_801CA9D4, &gGraphicsOption },
    { 1, -1, 0, 0, "CONFIGURATION JOUEURS", _menuEnter, &D_801CAB38, NULL, NULL },
    { 1, -1, 0, 0, "QUITTER", _menuExit, NULL, NULL, NULL },
#endif
};

/*801CAC28*/ static code1UnkStruct6 D_801CAC28 = {ARRAY_COUNT(D_801CAB48), D_801CAB48, 12, 32, &gConfig.menuIndex.options_2P};

/*801CAC38*/
static code1UnkStruct5 D_801CAC38[12] = {
#if VERSION_US
    { 1, 280, 0, 0, "OFF", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "5", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "10", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "20", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "30", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "40", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "50", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "60", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "70", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "80", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "90", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "100", NULL, NULL, NULL, NULL },
#elif VERSION_FR
    { 1, 284, 0, 0, "DESACT.", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "5", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "10", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "20", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "30", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "40", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "50", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "60", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "70", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "80", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "90", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "100", NULL, NULL, NULL, NULL },
#endif
};

/*801CAD88*/ static code1UnkStruct6 D_801CAD88 = {ARRAY_COUNT(D_801CAC38), D_801CAC38, 0, 0, NULL};

/*801CAD98*/
static code1UnkStruct5 D_801CAD98[8] = {
#if VERSION_US
    { 1, 280, 0, 0, "OFF", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "5", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "10", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "20", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "30", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "40", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "50", NULL, NULL, NULL, NULL },
    { 1, 280, 0, 0, "60", NULL, NULL, NULL, NULL },
#elif VERSION_FR
    { 1, 284, 0, 0, "DESACT.", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "5", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "10", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "20", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "30", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "40", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "50", NULL, NULL, NULL, NULL },
    { 1, 284, 0, 0, "60", NULL, NULL, NULL, NULL },
#endif
};

/*801CAE78*/ static code1UnkStruct6 D_801CAE78 = {ARRAY_COUNT(D_801CAD98), D_801CAD98, 0, 0, NULL};

/*801CAE88*/
static code1UnkStruct5 D_801CAE88[6] = {
#if VERSION_US
    { 1, -1, 1, 0, "SELECT GAME TYPE", NULL, NULL, NULL, NULL },
    { 1, -1, 1, 0, &D_801CA148, NULL, NULL, NULL, NULL },
    { 1, -1, 0, 0, "DUKEMATCH", _menuMultiplayerSelectLevel, NULL, NULL, NULL },
    { 1, -1, 0, 0, "LAST MAN STANDING", _menuMultiplayerSelectLevel, NULL, NULL, NULL },
    { 1, -1, 0, 0, "KING OF THE HILL", _menuMultiplayerSelectLevel, NULL, NULL, NULL },
    { 1, -1, 0, 0, "TEAM DUKEMATCH", _menuMultiplayerSelectLevel, NULL, NULL, NULL },
#elif VERSION_FR
    { 1, -1, 1, 0, "CHOISIR TYPE DE PARTIE", NULL, NULL, NULL, NULL },
    { 1, -1, 1, 0, &D_801CA148, NULL, NULL, NULL, NULL },
    { 1, -1, 0, 0, "DUKEMATCH", _menuMultiplayerSelectLevel, NULL, NULL, NULL },
    { 1, -1, 0, 0, "LE SURVIVANT", _menuMultiplayerSelectLevel, NULL, NULL, NULL },
    { 1, -1, 0, 0, "LE ROI DE LA MONTAGNE", _menuMultiplayerSelectLevel, NULL, NULL, NULL },
    { 1, -1, 0, 0, "DUKEMATCH PAR EQUIPE", _menuMultiplayerSelectLevel, NULL, NULL, NULL },
#endif
};

/*801CAF30*/ static code1UnkStruct6 D_801CAF30 = {ARRAY_COUNT(D_801CAE88), D_801CAE88, 34, 24, &gConfig.menuIndex.select_multiplayer_gametype};

/*801CAF40*/
static code1UnkStruct5 D_801CAF40[9] = {
#if VERSION_US
    { 1, -1, 1, 0, "MULTIPLAYER OPTIONS", NULL, NULL, NULL, NULL },
    { 0, 0, 0, 0, "PLAYERS", NULL, NULL, &D_801CA4C8, &gConfig.multiplayer.players },
    { 0, 0, 0, 0, "TIME LIMIT", NULL, NULL, &D_801CAE78, &gConfig.multiplayer.time_limit },
    { 0, 0, 0, 0, "FRAG COUNT", NULL, NULL, &D_801CAD88, &gConfig.multiplayer.frag_count },
    { 0, 0, 0, 0, "RADAR", NULL, NULL, &D_801CA7A8, &gConfig.multiplayer.radar },
    { 0, 0, 0, 0, "2P SPLIT", NULL, NULL, &D_801CA7F0, &gConfig.multiplayer.split_2P },
    { 0, 0, 0, 0, "3P SPLIT", NULL, NULL, &D_801CA838, &gConfig.multiplayer.split_3P },
    { 0, 0, 0, 0, "FRIENDLY FIRE", NULL, NULL, &D_801CA7A8, &gConfig.multiplayer.friendly_fire },
    { 1, -1, 0, 0, "PLAY", _menuMultiplayerSelectGameType, &D_801CAF30, NULL, NULL },
#elif VERSION_FR
    { 1, -1, 1, 0, "OPTIONS MODE MULTIJ.", NULL, NULL, NULL, NULL },
    { 0, -55, 0, 0, "JOUEURS", NULL, NULL, &D_801CA4C8, &gConfig.multiplayer.players },
    { 0, -55, 0, 0, "CONTRE LA MONTRE", NULL, NULL, &D_801CAE78, &gConfig.multiplayer.time_limit },
    { 0, -55, 0, 0, "PALMARED", NULL, NULL, &D_801CAD88, &gConfig.multiplayer.frag_count },
    { 0, -55, 0, 0, "RADAR", NULL, NULL, &D_801CA7A8, &gConfig.multiplayer.radar },
    { 0, -55, 0, 0, "SPLIT 2", NULL, NULL, &D_801CA7F0, &gConfig.multiplayer.split_2P },
    { 0, -55, 0, 0, "SPLIT 3", NULL, NULL, &D_801CA838, &gConfig.multiplayer.split_3P },
    { 0, -55, 0, 0, "TIR AMI", NULL, NULL, &D_801CA7A8, &gConfig.multiplayer.friendly_fire },
    { 1, -1, 0, 0, "JOUER", _menuMultiplayerSelectGameType, &D_801CAF30, NULL, NULL },
#endif
};

/*801CB03C*/ static code1UnkStruct6 D_801CB03C = {ARRAY_COUNT(D_801CAF40), D_801CAF40, 30, 24, &gConfig.menuIndex.multiplayer_options};

/*801CB04C*/
static code1UnkStruct5 D_801CB04C[4] = {
#if VERSION_US
    { 1, -1, 1, 0, "SELECT DIFFICULTY", NULL, NULL, NULL, NULL },
    { 1, -1, 1, 0, &D_801CA148, NULL, NULL, NULL, NULL },
    { 1, -1, 0, 0, "NORMAL", _menuSelectDifficulty, NULL, NULL, NULL },
    { 1, -1, 0, 0, "HARD", _menuSelectDifficulty, NULL, NULL, NULL },
#elif VERSION_FR
    { 1, -1, 1, 0, "CHOISIR NIVEAU DIFFIC.", NULL, NULL, NULL, NULL },
    { 1, -1, 1, 0, &D_801CA148, NULL, NULL, NULL, NULL },
    { 1, -1, 0, 0, "NORMAL", _menuSelectDifficulty, NULL, NULL, NULL },
    { 1, -1, 0, 0, "DIFFICILE", _menuSelectDifficulty, NULL, NULL, NULL },
#endif
};

/*801CB0BC*/ static code1UnkStruct6 D_801CB0BC = {ARRAY_COUNT(D_801CB04C), D_801CB04C, 60, 24, &gConfig.menuIndex.select_difficulty};

/*801CB0CC*/
static code1UnkStruct5 D_801CB0CC[4] = {
#if VERSION_US
    { 1, -1, 1, 0, "SELECT", NULL, NULL, NULL, NULL },
    { 1, -1, 1, 0, &D_801CA148, NULL, NULL, NULL, NULL },
    { 1, -1, 0, 0, "SINGLE PLAYER", _menuEnter, &D_801CB0BC, NULL, NULL },
    { 1, -1, 0, 0, "MULTI-PLAYER", _menuEnter, &D_801CB03C, NULL, NULL },
#elif VERSION_FR
    { 1, -1, 1, 0, "SELECT", NULL, NULL, NULL, NULL },
    { 1, -1, 1, 0, &D_801CA148, NULL, NULL, NULL, NULL },
    { 1, -1, 0, 0, "UN SEUL JOUEUR", _menuEnter, &D_801CB0BC, NULL, NULL },
    { 1, -1, 0, 0, "MULTIJOUEUR", _menuEnter, &D_801CB03C, NULL, NULL },
#endif
};

/*801CB13C*/ static code1UnkStruct6 D_801CB13C = {ARRAY_COUNT(D_801CB0CC), D_801CB0CC, 60, 24, &gConfig.menuIndex.select_single_multi_player};

/*801CB14C*/
static code1UnkStruct5 D_801CB14C[12] = {
#if VERSION_US
    { 0, -16, 2, 0, "SMG", NULL, NULL, &D_801CA7A8, &gCheatWeaponSmgConfig },
    { 0, -16, 2, 0, "BLASTER", NULL, NULL, &D_801CA7A8, &gCheatWeaponBlasterConfig },
    { 0, -16, 2, 0, "SNIPER", NULL, NULL, &D_801CA7A8, &gCheatWeaponSniperConfig },
    { 0, -16, 2, 0, "FREEZER", NULL, NULL, &D_801CA7A8, &gCheatWeaponFreezerConfig },
    { 0, -16, 2, 0, "REVOLVER", NULL, NULL, &D_801CA7A8, &gCheatWeaponRevolverConfig },
    { 0, -16, 2, 0, "CLAW-12", NULL, NULL, &D_801CA7A8, &gCheatWeaponClaw12Config },
    { 0, -16, 2, 0, ".30-30", NULL, NULL, &D_801CA7A8, &gCheatWeapon3030Config },
    { 0, -16, 2, 0, "SAWED OFF", NULL, NULL, &D_801CA7A8, &gCheatWeaponSawedOffConfig },
    { 0, -16, 2, 0, "VOLT CANNON", NULL, NULL, &D_801CA7A8, &gCheatWeaponVoltCannonConfig },
    { 0, -16, 2, 0, "GATTLING GUN", NULL, NULL, &D_801CA7A8, &gCheatWeaponGattlingGunConfig },
    { 0, -16, 2, 0, "GAMMA CANNON", NULL, NULL, &D_801CA7A8, &gCheatWeaponGammaCannonConfig },
    { 1, -1, 0, 0, "EXIT", _menuExit, NULL, NULL, NULL },
#elif VERSION_FR
    { 0, -55, 2, 0, "SMG", NULL, NULL, &_ouiNon, &gCheatWeaponSmgConfig },
    { 0, -55, 2, 0, "BLASTER", NULL, NULL, &_ouiNon, &gCheatWeaponBlasterConfig },
    { 0, -55, 2, 0, "SNIPER", NULL, NULL, &_ouiNon, &gCheatWeaponSniperConfig },
    { 0, -55, 2, 0, "FIGEUR", NULL, NULL, &_ouiNon, &gCheatWeaponFreezerConfig },
    { 0, -55, 2, 0, "REVOLVER", NULL, NULL, &_ouiNon, &gCheatWeaponRevolverConfig },
    { 0, -55, 2, 0, "SERRE-12", NULL, NULL, &_ouiNon, &gCheatWeaponClaw12Config },
    { 0, -55, 2, 0, ".30-30", NULL, NULL, &_ouiNon, &gCheatWeapon3030Config },
    { 0, -55, 2, 0, "SCIE", NULL, NULL, &_ouiNon, &gCheatWeaponSawedOffConfig },
    { 0, -55, 2, 0, "CANON ELEC", NULL, NULL, &_ouiNon, &gCheatWeaponVoltCannonConfig },
    { 0, -55, 2, 0, "MITR. GATLING", NULL, NULL, &_ouiNon, &gCheatWeaponGattlingGunConfig },
    { 0, -55, 2, 0, "CANON PLASMA", NULL, NULL, &_ouiNon, &gCheatWeaponGammaCannonConfig },
    { 1, -1, 0, 0, "QUITTER", _menuExit, NULL, NULL, NULL },
#endif
};

/*801CB29C*/ static code1UnkStruct6 D_801CB29C = {ARRAY_COUNT(D_801CB14C), D_801CB14C, -20, 24, &gConfig.menuIndex.cheats_weapons};

/*801CB2AC*/
static code1UnkStruct5 D_801CB2AC[4] = {
#if VERSION_US
    { 0, -16, 2, 0, "FIRST PERSON", NULL, NULL, &D_801CA7A8, &gCheatFirstPersonConfig },
    { 0, -16, 2, 0, "ACTION NUKEM", NULL, NULL, &D_801CA7A8, &gCheatActionNukemConfig },
    { 0, -16, 2, 0, "SELECT SKIN", NULL, NULL, &D_801CA7A8, &gCheatSelectSkinConfig },
    { 1, -1, 0, 0, "EXIT", _menuExit, NULL, NULL, NULL },
#elif VERSION_FR
    { 0, -55, 2, 0, "1RE PERSONNE", NULL, NULL, &D_801CA7A8, &gCheatFirstPersonConfig },
    { 0, -55, 2, 0, "NUKEM ACTIF", NULL, NULL, &D_801CA7A8, &gCheatActionNukemConfig },
    { 0, -55, 2, 0, "SELECTION", NULL, NULL, &D_801CA7A8, &gCheatSelectSkinConfig },
    { 1, -1, 0, 0, "QUITTER", _menuExit, NULL, NULL, NULL },
#endif
};

/*801CB31C*/ static code1UnkStruct6 D_801CB31C = {ARRAY_COUNT(D_801CB2AC), D_801CB2AC, 76, 24, &gConfig.menuIndex.cheats_game_type};

/*801CB32C*/
static code1UnkStruct5 D_801CB32C[7] = {
#if VERSION_US
    { 0, -16, 2, 0, "BIG HEAD MODE", NULL, NULL, &D_801CA7A8, &gCheatBigHeadModeConfig },
    { 0, -16, 2, 0, "FLAT SHADING", NULL, NULL, &D_801CA7A8, &gCheatFlatShadingConfig },
    { 0, -16, 2, 0, "WEATHER", NULL, NULL, &D_801CA7A8, &gCheatWeatherConfig },
    { 0, -16, 2, 0, "BIG GUN", NULL, NULL, &D_801CA7A8, &gCheatBigGunConfig },
    { 0, -16, 2, 0, "ICE SKINS", NULL, NULL, &D_801CA7A8, &gCheatIceSkinConfig },
    { 0, -16, 2, 0, "FAST ZOMBIES", NULL, NULL, &D_801CA7A8, &gCheatFastZombiesConfig },
    { 1, -1, 0, 0, "EXIT", _menuExit, NULL, NULL, NULL },
#elif VERSION_FR
    { 0, -55, 2, 0, "MODE GROSSE TETE", NULL, NULL, &D_801CA7A8, &gCheatBigHeadModeConfig },
    { 0, -55, 2, 0, "OMBRAGE MAT", NULL, NULL, &D_801CA7A8, &gCheatFlatShadingConfig },
    { 0, -55, 2, 0, "METEO", NULL, NULL, &D_801CA7A8, &gCheatWeatherConfig },
    { 0, -55, 2, 0, "GROS CANON", NULL, NULL, &D_801CA7A8, &gCheatBigGunConfig },
    { 0, -55, 2, 0, "PEAUX DE GLACE", NULL, NULL, &D_801CA7A8, &gCheatIceSkinConfig },
    { 0, -55, 2, 0, "ZOMBIES RAPIDES", NULL, NULL, &D_801CA7A8, &gCheatFastZombiesConfig },
    { 1, -1, 0, 0, "QUITTER", _menuExit, NULL, NULL, NULL },
#endif
};

/*801CB3F0*/ static code1UnkStruct6 D_801CB3F0 = {ARRAY_COUNT(D_801CB32C), D_801CB32C, 24, 32, &gConfig.menuIndex.cheats_others};

/*801CB400*/
static code1UnkStruct5 D_801CB400[5] = {
#if VERSION_US
    { 1, -1, 1, 0, "CHEATS", NULL, NULL, NULL, NULL },
    { 1, -1, 0, 0, "WEAPONS", _menuEnter, &D_801CB29C, NULL, NULL },
    { 1, -1, 0, 0, "GAME TYPE", _menuEnter, &D_801CB31C, NULL, NULL },
    { 1, -1, 0, 0, "OTHERS", _menuEnter, &D_801CB3F0, NULL, NULL },
    { 1, -1, 0, 0, "EXIT", _menuExit, NULL, NULL, NULL },
#elif VERSION_FR
    { 1, -1, 1, 0, "TRICHES", NULL, NULL, NULL, NULL },
    { 1, -1, 0, 0, "ARMES", _menuEnter, &D_801CB29C, NULL, NULL },
    { 1, -1, 0, 0, "TYPE DE PARTIE", _menuEnter, &D_801CB31C, NULL, NULL },
    { 1, -1, 0, 0, "AUTRES", _menuEnter, &D_801CB3F0, NULL, NULL },
    { 1, -1, 0, 0, "QUITTER", _menuExit, NULL, NULL, NULL },
#endif
};

/*801CB48C*/ static code1UnkStruct6 D_801CB48C = {ARRAY_COUNT(D_801CB400), D_801CB400, 68, 24, &gConfig.menuIndex.cheats};

/*801CB49C*/
static code1UnkStruct5 D_801CB49C[5] = {
#if VERSION_US
    { 1, -1, 1, 0, D_801CDBB0, NULL, NULL, NULL, NULL },
    { 1, -1, 0, 0, "START GAME", _menuEnter, &D_801CB13C, NULL, NULL },
    { 1, -1, 0, 0, "LOAD GAME", _menuLoadGame, NULL, NULL, NULL },
    { 1, -1, 0, 0, "OPTIONS", _menuEnter, &D_801CAC28, NULL, NULL },
    { 1, -1, 0, 0, "CHEATS", _menuEnter, &D_801CB48C, NULL, NULL },
#elif VERSION_FR
    { 1, -1, 1, 0, D_801CDBB0, NULL, NULL, NULL, NULL },
    { 1, -1, 0, 0, "COMMENCER LA PARTIE", _menuEnter, &D_801CB13C, NULL, NULL },
    { 1, -1, 0, 0, "CHARGER LA PARTIE", _menuLoadGame, NULL, NULL, NULL },
    { 1, -1, 0, 0, "OPTIONS", _menuEnter, &D_801CAC28, NULL, NULL },
    { 1, -1, 0, 0, "TRICHES", _menuEnter, &D_801CB48C, NULL, NULL },
#endif
};

/*801CB528*/ static code1UnkStruct6 D_801CB528 = {ARRAY_COUNT(D_801CB49C)-1, D_801CB49C, 64, 24, &gConfig.menuIndex.main};

/*801CB538*/
code1UnkStruct5 D_801CB538[9] = {
#if VERSION_US
    { 0, -16, 0, 0, "SFX VOLUME", NULL, NULL, &D_801CA970, &gConfig.mastervol },
    { 0, -16, 0, 0, "MUSIC VOLUME", NULL, NULL, &D_801CA970, &gConfig.musicvol },
    { 0, -16, 0, 0, "SOUND", NULL, NULL, &D_801CA880, &gConfig.sound },
    { 0, -16, 0, 0, "RUMBLE PAK", NULL, NULL, &D_801CA970, &gConfig.rumblepak },
    { 0, -16, 0, 0, "CONTROLLER", NULL, NULL, &D_801CA760, gConfig.controller_preset },
    { 0, -16, 0, 0, "CROSSHAIR", NULL, NULL, &D_801CA60C, gConfig.crosshair },
    { 0, -16, 0, 0, "AUTOAIM", NULL, NULL, &D_801CA670, gConfig.autoaim },
    { 0, -16, 0, 0, "AUTO CENTER", NULL, NULL, &D_801CA7A8, gConfig.autocenter },
    { 1, -1, 0, 0, "EXIT", _menuExit, NULL, NULL, NULL },
#elif VERSION_FR
    { 0, -55, 0, 0, "VOLUME FX", NULL, NULL, &D_801CA970, &gConfig.mastervol },
    { 0, -55, 0, 0, "VOLUME MUSIQUE", NULL, NULL, &D_801CA970, &gConfig.musicvol },
    { 0, -55, 0, 0, "SON", NULL, NULL, &D_801CA880, &gConfig.sound },
    { 0, -55, 0, 0, "RUMBLE PAK", NULL, NULL, &D_801CA970, &gConfig.rumblepak },
    { 0, -55, 0, 0, "MANETTE", NULL, NULL, &D_801CA760, gConfig.controller_preset },
    { 0, -55, 0, 0, "MIRE", NULL, NULL, &D_801CA60C, gConfig.crosshair },
    { 0, -55, 0, 0, "VISEE AUTO", NULL, NULL, &D_801CA670, gConfig.autoaim },
    { 0, -55, 0, 0, "AUTO CENTER", NULL, NULL, &D_801CA7A8, gConfig.autocenter },
    { 1, -1, 0, 0, "QUITTER", _menuExit, NULL, NULL, NULL },
#endif
};

/*801CB634*/ static code1UnkStruct6 D_801CB634 = {ARRAY_COUNT(D_801CB538), D_801CB538, 16, 25, &gConfig.menuIndex.options_1P};

/*801CB644*/
static code1UnkStruct5 D_801CB644[3] = {
#if VERSION_US
    { 1, -1, 1, 0, "QUIT GAME?", NULL, NULL, NULL, NULL },
    { 1, -1, 0, 0, "NO", _menuBack, NULL, NULL, NULL },
    { 1, -1, 0, 0, "YES", func_801C3874, NULL, NULL, NULL },
#elif VERSION_FR
    { 1, -1, 1, 0, "QUITTER LA PARTIE ?", NULL, NULL, NULL, NULL },
    { 1, -1, 0, 0, "NON", _menuBack, NULL, NULL, NULL },
    { 1, -1, 0, 0, "OUI", func_801C3874, NULL, NULL, NULL },
#endif
};

/*801CB698*/ static code1UnkStruct6 D_801CB698 = {ARRAY_COUNT(D_801CB644), D_801CB644, 94, 24, &gConfig.menuIndex.unkB};

/*801CB6A8*/
static code1UnkStruct5 D_801CB6A8[2] = {
#if VERSION_US
    { 1, -1, 0, 0, "CONTINUE GAME", func_801C392C, NULL, NULL, NULL },
    { 1, -1, 0, 0, "RESTART LEVEL", func_801C38DC, NULL, NULL, NULL },
#elif VERSION_FR
    { 1, -1, 0, 0, "CHARGER PARTIE ENREGIS.", func_801C392C, NULL, NULL, NULL },
    { 1, -1, 0, 0, "RECOMMENCER NIVEAU", func_801C38DC, NULL, NULL, NULL },
#endif
};

/*801CB6E0*/ code1UnkStruct6 D_801CB6E0 = {ARRAY_COUNT(D_801CB6A8), D_801CB6A8, 102, 24, &gConfig.menuIndex.unkF};

/*801CB6F0*/
static code1UnkStruct5 D_801CB6F0[2] = {
#if VERSION_US
    { 1, -1, 0, 0, "REPLAY SAVED GAME", func_801C399C, NULL, NULL, NULL },
    { 1, -1, 0, 0, "RESTART LEVEL", func_801C3974, NULL, NULL, NULL },
#elif VERSION_FR
    { 1, -1, 0, 0, "CHARGER PARTIE ENREGIS.", func_801C399C, NULL, NULL, NULL },
    { 1, -1, 0, 0, "RECOMMENCER NIVEAU", func_801C3974, NULL, NULL, NULL },
#endif
};

/*801CB728*/ static code1UnkStruct6 D_801CB728 = {ARRAY_COUNT(D_801CB6F0), D_801CB6F0, 100, 24, &gConfig.menuIndex.unkD};

/*801CB738*/
static code1UnkStruct5 D_801CB738[3] = {
#if VERSION_US
    { 1, -1, 1, 0, "RESTART LEVEL?", NULL, NULL, NULL, NULL },
    { 1, -1, 0, 0, "NO", _menuBack, NULL, NULL, NULL },
    { 1, -1, 0, 0, "YES", _menuEnter, &D_801CB728, NULL, NULL },
#elif VERSION_FR
    { 1, -1, 1, 0, "RECOMMENCER NIVEAU ?", NULL, NULL, NULL, NULL },
    { 1, -1, 0, 0, "NON", _menuBack, NULL, NULL, NULL },
    { 1, -1, 0, 0, "OUI", _menuEnter, &D_801CB728, NULL, NULL },
#endif
};

/*801CB78C*/ static code1UnkStruct6 D_801CB78C = {ARRAY_COUNT(D_801CB738), D_801CB738, 94, 24, &gConfig.menuIndex.unkC};

/*801CB79C*/
static code1UnkStruct5 D_801CB79C[3] = {
#if VERSION_US
    { 1, -1, 1, 0, "RESTART LEVEL?", NULL, NULL, NULL, NULL },
    { 1, -1, 0, 0, "NO", _menuBack, NULL, NULL, NULL },
    { 1, -1, 0, 0, "YES", func_801C38DC, NULL, NULL, NULL },
#elif VERSION_FR
    { 1, -1, 1, 0, "RECOMMENCER NIVEAU ?", NULL, NULL, NULL, NULL },
    { 1, -1, 0, 0, "NON", _menuBack, NULL, NULL, NULL },
    { 1, -1, 0, 0, "OUI", func_801C38DC, NULL, NULL, NULL },
#endif
};

/*801CB7F0*/ static code1UnkStruct6 D_801CB7F0 = {ARRAY_COUNT(D_801CB79C), D_801CB79C, 94, 24, &gConfig.menuIndex.unkC};

/*801CB800*/
static code1UnkStruct5 D_801CB800[4] = {
#if VERSION_US
    { 1, -1, 0, 0, "CONTINUE", _menuBack, NULL, NULL, NULL },
    { 1, -1, 0, 0, "OPTIONS", _menuEnter, &D_801CB634, NULL, NULL },
    { 1, -1, 0, 0, "RESTART", _menuEnter, &D_801CB78C, NULL, NULL },
    { 1, -1, 0, 0, "QUIT GAME", _menuEnter, &D_801CB698, NULL, NULL },
#elif VERSION_FR
    { 1, -1, 0, 0, "CONTINUER", _menuBack, NULL, NULL, NULL },
    { 1, -1, 0, 0, "OPTIONS", _menuEnter, &D_801CB634, NULL, NULL },
    { 1, -1, 0, 0, "RECOMMENCER", _menuEnter, &D_801CB78C, NULL, NULL },
    { 1, -1, 0, 0, "QUITTER LA PARTIE", _menuEnter, &D_801CB698, NULL, NULL },
#endif
};

/*801CB870*/ code1UnkStruct6 D_801CB870 = {ARRAY_COUNT(D_801CB800), D_801CB800, 76, 24, &gConfig.menuIndex.unkA};

/*801CB880*/
static code1UnkStruct5 D_801CB880[4] = {
#if VERSION_US
    { 1, -1, 0, 0, "CONTINUE", _menuBack, NULL, NULL, NULL },
    { 1, -1, 0, 0, "OPTIONS", _menuEnter, &D_801CB634, NULL, NULL },
    { 1, -1, 0, 0, "RESTART", _menuEnter, &D_801CB7F0, NULL, NULL },
    { 1, -1, 0, 0, "QUIT GAME", _menuEnter, &D_801CB698, NULL, NULL },
#elif VERSION_FR
    { 1, -1, 0, 0, "CONTINUER", _menuBack, NULL, NULL, NULL },
    { 1, -1, 0, 0, "OPTIONS", _menuEnter, &D_801CB634, NULL, NULL },
    { 1, -1, 0, 0, "RECOMMENCER", _menuEnter, &D_801CB7F0, NULL, NULL },
    { 1, -1, 0, 0, "QUITTER LA PARTIE", _menuEnter, &D_801CB698, NULL, NULL },
#endif
};

/*801CB8F0*/ code1UnkStruct6 D_801CB8F0 = {ARRAY_COUNT(D_801CB880), D_801CB880, 76, 24, &gConfig.menuIndex.unkA};

/*801CB900*/
static code1UnkStruct5 D_801CB900[2] = {
#if VERSION_US
    { 1, -1, 0, 0, "SAVE", _menuSaveGame, NULL, NULL, NULL },
    { 1, -1, 0, 0, "CONTINUE WITHOUT SAVING", func_801C39C4, NULL, NULL, NULL },
#elif VERSION_FR
    { 1, -1, 0, 0, "ENREGISTRER", _menuSaveGame, NULL, NULL, NULL },
    { 1, -1, 0, 0, "CONTINUER SANS ENREGIS.", func_801C39C4, NULL, NULL, NULL },
#endif
};

/*801CB938*/ static code1UnkStruct6 D_801CB938 = {ARRAY_COUNT(D_801CB900), D_801CB900, 224, 24, &gConfig.menuIndex.unk11};

/*801C3580*/
static void _menuMultiplayerSelectGameType(void)
{
    D_801CDC64.unk1 = gConfig.multiplayer.players + 2;

    if (D_801CDC64.unk1 < 3)
        D_801CAE88[5].unk4 = 2;
    else
        D_801CAE88[5].unk4 = 0;

    _menuEnter();
}

/*801C35DC*/
static void _menuSelectDifficulty(void)
{
    func_8007F07C();
    D_800BD3F9 = 17;
}

/*801C3608*/
static void func_801C3608(void)
{
    D_801CDC64.unk0 = 1;
    main_80000624(main_80001F40);
}

/*801C363C*/
void func_801C363C(u8 playernum, u16 arg1, u8 arg2)
{
    if (D_8012FC90 == 0)
    {
        if (gPlayer[playernum].unk45 == 0)
        {
            if (gConfig.rumblepak != 0)
                controller_8008A4C4(playernum, arg1, ((arg2 * gConfig.rumblepak) / 7));
        }
    }
}

/*801C36E4*/
static void _menuSelectPlayer(void)
{
    D_801CDACC = D_801CE5A0;
    D_801CA9E4[1].unk18 = &gConfig.controller_preset[D_801CE5A0];
    D_801CAA2C[2].unk18 = &gConfig.crosshair[D_801CE5A0];
    D_801CAA2C[3].unk18 = &gConfig.autoaim[D_801CE5A0];
    D_801CAA2C[4].unk18 = &gConfig.autocenter[D_801CE5A0];
    _menuEnter();
}

/*801C375C*/
static void func_801C375C(void)
{
    D_801CA9E4[1].unk18 = gConfig.controller_preset;
    D_801CAA2C[2].unk18 = gConfig.crosshair;
    D_801CDACC = 0;
    D_801CAA2C[3].unk18 = gConfig.autoaim;
    D_801CAA2C[4].unk18 = gConfig.autocenter;
    _menuEnter();
}

/*801C37B8*/
static void func_801C37B8(void)
{
    s16 i;

    D_800FE3FC = 0;
    D_801CDC64.unk0 = 0;
    D_801CDC64.unk1 = 1;
    gLoadMapNum = 0;
    Amemset(&D_801CE5F0, 0, sizeof(D_801CE5F0));

    for (i = 0; gMapChapter[gLoadMapNum].chapter != TRAINING; i++)
        gLoadMapNum++;

    gTimeMachinePart = 0;
    D_8010554C = gCheatSelectSkinConfig;
}

/*801C3874*/
static void func_801C3874(void)
{
    func_8008E01C(30, 0);
    D_801AE914 = 0;
    func_8007F050();
}

/*801C38A8*/
static void _menuBack(void)
{
    D_801AE914 = 0;
    func_8007F050();
    D_80199524 = 1;
}

/*801C38DC*/
static void func_801C38DC(void)
{
    D_801A1994 = 1;
    D_801AE914 = 0;
    func_8007F050();
    D_800BD3E8 = 1;
    func_8008E01C(30, 2);
}

/*801C392C*/
static void func_801C392C(void)
{
    D_801A1994 = 0;
    D_801AE914 = 0;
    func_8007F050();
    D_800BD3E8 = 1;
    func_8008E01C(30, 2);
}

/*801C3974*/
static void func_801C3974(void)
{
    D_800DF585 = 0;
    func_801C38DC();
}

/*801C399C*/
static void func_801C399C(void)
{
    D_800DF585 = 0;
    func_801C392C();
}

/*801C39C4*/
static void func_801C39C4(void)
{
    func_8007F07C();
    D_801CDBA8 = 0;
    D_801CDA8C = 0;
    if (D_800FE3FC == 0)
    {
        gLoadMapNum = func_801C53E8(gMapNum);
        if (gMapChapter[gLoadMapNum].chapter == 99)
            gLoadMapNum = 0;
    }
    D_801CC88C = 1;
}

/*801C3A4C*/
static void _menuSaveGame(void)
{
    func_8007F07C();
    D_801CDBA8 = 1;
    D_801CDA8C = 0;
    D_801CC88C = 1;
}

/*801C3A88*/
static void func_801C3A88(s32 arg0)
{
    D_801CE5A0 = arg0;
    while (1)
    {
        if (D_801CE5A8->unk4[D_801CE5A0].unk4 != 0)
            D_801CE5A0++;
        else
            break;
    }
}

/*801C3AD8*/
static void func_801C3AD8(void)
{
    s32 i;

    D_801CE5D8 = 0x25252525;
    gNotPlayback = TRUE;
    D_800BD3E8 = 1;
    D_801CC8C4 = 0;
    func_801C0EDC(0xD000);
    setCameraPosition(0.0f, 0.0f, -90.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    edl_80081688(&D_801CDB08, 20);
    edl_80081688(&D_801CC888, 21);
    edl_80081688(&D_801CDBC8, 23);
    edl_80081688(&D_801CDA98, 22);
    func_8007FD8C(&D_800DFB08[0], 11);
    func_8007FD8C(&D_800DFAB8[0], 3);
    D_800E0F58 = 0;

    for (i = 0; i < ARRAY_COUNT(D_01022510); i++)
        func_80083700(1, &D_801CE5E8[i], 0, 0);

    D_800E0F58 = 1;
    func_8007F050();
    D_801CDA20 = func_8007FC08(&D_800DFAB8[0], NULL, 0, 0, 500);
    func_801C1114();
    func_801C1158(0, 0, 0, 0xFF);
    D_801CC88C = -1;

    if ((gUnlockedCheat != 0) || (gUnlockedCheatWeapons != 0))
        gConfig.unk50 = 1;

    if (gConfig.unk50 == 0)
        D_801CB528.unk0 = 4;
    else
        D_801CB528.unk0 = 5;

    D_801CD980 = 0;
    func_801C2BE8(&D_801CB528);
    func_801C3A88(*D_801CE5A8->unkC);

    D_801CA144 = 1.8f;
    i = D_801CC8CA;
    D_801CAB38.unk0 = i;

    if (i == 1)
    {
        D_801CAB48[6].unkC = func_801C375C;
        D_801CAB48[6].unk10 = &D_801CAAB8;
        D_801CB49C[1].unk10 = &D_801CB0BC;
    }

    if (i == 2)
        D_801CDC64.unk1 = 2;

    gConfig.multiplayer.players = i - 2;
    D_801CA4C8.unk0 = i - 1;
    D_8010554C = 0;

    if (osMemSize == 0x400000)
    {
        D_801CAB48[5].unk4 = 2;
        D_801CA980[0].unk4 = 2;
        D_801CA980[1].unk4 = 2;
    }

    if ((gMusicHandle == 0) || (MusHandleAsk(gMusicHandle) == 0) || (gMusicNum != 2))
        playMusic(2);

    MusStop(1, 0);
    D_801CDA90 = 0;
    func_801C7108();
    D_800BD3F9 = 2;
}

/*801C3E08*/
void func_801C3E08(void)
{
    cache1d_8002AAC0();
    allocMemory(SCREEN_WIDTH, SCREEN_HEIGHT*2, DISPLAY_LIST_SIZE*2, 0);
    func_801C10C8();
    func_801C3AD8();
    main_80002390();
    main_80000610();
}

/*801C3E5C*/
static void func_801C3E5C(void)
{
    code1UnkStruct5 *ptr1;
    code1UnkStruct5 *ptr2;
    code0UnkStruct16 *ptr3;

    ptr1 = &D_801CE5A8->unk4[D_801CE5A0];
    if (func_801C0E68() & 0x800)
    {
        func_801C0EDC(0x800);
        playSfx(746);
        func_801C14C4(D_801CD990[D_801CE5A0], 140, 140, 165);
        do
        {
            if (D_801CE5A0 == 0)
                D_801CE5A0 = D_801CE5A8->unk0 - 1;
            else
                D_801CE5A0--;
        } while (D_801CE5A8->unk4[D_801CE5A0].unk4 != 0);
    }
    else if (func_801C0E68() & 0x400)
    {
        func_801C0EDC(0x400);
        playSfx(746);
        func_801C14C4(D_801CD990[D_801CE5A0], 140, 140, 165);

        do
        {
            if (D_801CE5A0 == (D_801CE5A8->unk0 - 1))
                func_801C3A88(0);
            else
                D_801CE5A0++;
        } while (D_801CE5A8->unk4[D_801CE5A0].unk4 != 0);
    }
    else
    {
        if (func_801C0E68() & 0x1000)
        {
            func_801C0EDC(0x1000);
            func_801C0F28(0x8000);
        }
        if (func_801C0E68() & 0x8000)
        {
            func_801C0EDC(0x8000);
            if (ptr1->unkC != NULL)
            {
                if (D_801CE5A8 != &D_801CB0BC)
                    playSfx(747);
                else
                {
                    gConfig.difficulty = D_801CE5A0 - 1;
                    switch (gConfig.difficulty)
                    {
                    case 0:
                        D_801CDA90 = playSfx(915);
                        break;

                    case 1:
                        D_801CDA90 = playSfx(951);
                        break;

                    case 2:
                        D_801CDA90 = playSfx(943);
                        break;

                    }
                }
                D_801CC8C0 = 1;
            }
        }
        else if (func_801C0E68() & 0x4000)
        {
            func_801C0EDC(0x4000);
            if (D_801CD980 != 0)
            {
                D_801CC8C0 = -1;
                playSfx(748);
            }
        }
        else if (ptr1->unk14 != NULL)
        {
            if (func_801C0E68() & 0x200)
            {
                func_801C0EDC(0x200);
                playSfx(746);

                if (ptr1->unk18[0] == 0)
                    ptr1->unk18[0] = ptr1->unk14->unk0 - 1;
                else
                    ptr1->unk18[0]--;

                if (D_801CE5A8 == &D_801CB03C)
                {
                    if (D_801CE5A0 == 2)
                    {
                        ptr2 = &D_801CB03C.unk4[3];
                        if (ptr1->unk18[0] == 0)
                        {
                            if (*ptr2->unk18 == 0)
                            {
                                *ptr2->unk18 = 1;
                                ptr3 = (code0UnkStruct16 *)D_801CD990[3]->unk7C;
                                ptr3->unk70 = ptr2->unk14[0].unk4[*ptr2->unk18].unk8;
                            }
                        }
                    }
                    else if (D_801CE5A0 == 3)
                    {
                        ptr2 = &D_801CB03C.unk4[2];
                        if (ptr1->unk18[0] == 0)
                        {
                            if (*ptr2->unk18 == 0)
                            {
                                *ptr2->unk18 = 1;
                                ptr3 = (code0UnkStruct16 *)D_801CD990[2]->unk7C;
                                ptr3->unk70 = ptr2->unk14[0].unk4[*ptr2->unk18].unk8;
                            }
                        }
                    }
                }

                if ((ptr1->unk18 == &gConfig.musicvol) || (ptr1->unk18 == (&gConfig.mastervol)))
                    setVolume((gConfig.musicvol * 100) / 7, (gConfig.mastervol * 100) / 7);

                ptr3 = (code0UnkStruct16 *)D_801CD990[D_801CE5A0]->unk7C;
                ptr3->unk70 = ptr1->unk14->unk4[ptr1->unk18[0]].unk8;
                if (ptr1->unk14 == &D_801CA970)
                {
                    if (ptr1->unk18[0] == 0)
                        func_801C14C4(ptr3, 0, 200, 200);
                    else
                        func_801C14C4(ptr3, 0xFF, 0xFF, 0xFF);
                }
            }
            if (func_801C0E68() & 0x100)
            {
                func_801C0EDC(0x100);
                playSfx(746);

                if ((ptr1->unk18[0]) != (ptr1->unk14->unk0 - 1))
                    ptr1->unk18[0]++;
                else
                    ptr1->unk18[0] = 0;

                if (D_801CE5A8 == &D_801CB03C)
                {
                    if (D_801CE5A0 == 2)
                    {
                        ptr2 = &D_801CB03C.unk4[3];
                        if (ptr1->unk18[0] == 0)
                        {
                            if (*ptr2->unk18 == 0)
                            {
                                *ptr2->unk18 = 1;
                                ptr3 = (code0UnkStruct16 *)D_801CD990[3]->unk7C;
                                ptr3->unk70 = ptr2->unk14[0].unk4[*ptr2->unk18].unk8;
                            }
                        }
                    }
                    else if (D_801CE5A0 == 3)
                    {
                        ptr2 = &D_801CB03C.unk4[2];
                        if (ptr1->unk18[0] == 0)
                        {
                            if (*ptr2->unk18 == 0)
                            {
                                *ptr2->unk18 = 1;
                                ptr3 = (code0UnkStruct16 *)D_801CD990[2]->unk7C;
                                ptr3->unk70 = ptr2->unk14[0].unk4[*ptr2->unk18].unk8;
                            }
                        }
                    }
                }

                if ((ptr1->unk18 == &gConfig.musicvol) || (ptr1->unk18 == (&gConfig.mastervol)))
                    setVolume((gConfig.musicvol * 100) / 7, (gConfig.mastervol * 100) / 7);

                ptr3 = (code0UnkStruct16 *)D_801CD990[D_801CE5A0]->unk7C;
                ptr3->unk70 = ptr1->unk14->unk4[ptr1->unk18[0]].unk8;
                if (ptr1->unk14 == &D_801CA970)
                {
                    if (ptr1->unk18[0] == 0)
                        func_801C14C4(ptr3, 0, 200, 200);
                    else
                        func_801C14C4(ptr3, 0xFF, 0xFF, 0xFF);
                }
            }
        }
    }
}

/*801C45C0*/
static void func_801C45C0(void)
{
    code1UnkStruct5 *ptr;
    code0UnkStruct16 *ptr2;

    ptr = &D_801CE5A8->unk4[D_801CE5A0];
    if (D_801CD986[D_801CDACC] & 0x800)
    {
        D_801CD986[D_801CDACC] &= ~0x800;
        playSfx(746);
        func_801C14C4(D_801CD990[D_801CE5A0], 140, 140, 165);
        do
        {
            if (D_801CE5A0 == 0)
                D_801CE5A0 = D_801CE5A8->unk0 - 1;
            else
                D_801CE5A0--;

        } while (D_801CE5A8->unk4[D_801CE5A0].unk4 != 0);
    }
    else if (D_801CD986[D_801CDACC] & 0x400)
    {
        D_801CD986[D_801CDACC] &= ~0x400;
        playSfx(746);
        func_801C14C4(D_801CD990[D_801CE5A0], 140, 140, 165);
        do
        {
            if (D_801CE5A0 == (D_801CE5A8->unk0 - 1))
                func_801C3A88(0);
            else
                D_801CE5A0++;

        } while (D_801CE5A8->unk4[D_801CE5A0].unk4 != 0);
    }
    else
    {
        if ((D_801CD986[D_801CDACC] & 0x1000) || (D_801CD986[D_801CDACC] & 0x8000))
        {
            D_801CD986[D_801CDACC] &= ~0x1000;
            if (ptr->unkC != NULL)
            {
                playSfx(747);
                D_801CC8C0 = 1;
            }
        }
        else if (D_801CD986[D_801CDACC] & 0x4000)
        {
            D_801CD986[D_801CDACC] &= ~0x4000;
            if (D_801CD980 != 0)
            {
                playSfx(748);
                D_801CC8C0 = -1;
                return;
            }
            if ((D_801CE5A8 == &D_801CB870) || (D_801CE5A8 == &D_801CB8F0))
            {
                playSfx(748);
                func_801C14C4(D_801CD990[D_801CE5A0], 140, 140, 165);
                func_801C3A88(0);
                D_801CC8C0 = 1;
            }
        }
        else if (ptr->unk14 != NULL)
        {
            if (D_801CD986[D_801CDACC] & 0x200)
            {
                D_801CD986[D_801CDACC] &= ~0x200;
                playSfx(746);
                if (ptr->unk18[0] == 0)
                    ptr->unk18[0] = ptr->unk14->unk0 - 1;
                else
                    ptr->unk18[0]--;

                if ((ptr->unk18 == &gConfig.musicvol) || (ptr->unk18 == &gConfig.mastervol))
                    setVolume((gConfig.musicvol * 100) / 7, (gConfig.mastervol * 100) / 7);

                ptr2 = (code0UnkStruct16 *)D_801CD990[D_801CE5A0]->unk7C;
                ptr2->unk70 = ptr->unk14->unk4[*ptr->unk18].unk8;
                if (ptr->unk14 == &D_801CA970)
                {
                    if (*ptr->unk18 == 0)
                        func_801C14C4(ptr2, 0, 200, 200);
                    else
                        func_801C14C4(ptr2, 0xFF, 0xFF, 0xFF);
                }
            }

            if (D_801CD986[D_801CDACC] & 0x100)
            {
                D_801CD986[D_801CDACC] &= ~0x100;
                playSfx(746);
                if (ptr->unk18[0] != (ptr->unk14->unk0 - 1))
                    ptr->unk18[0]++;
                else
                    ptr->unk18[0] = 0;

                if ((ptr->unk18 == &gConfig.musicvol) || (ptr->unk18 == &gConfig.mastervol))
                    setVolume((gConfig.musicvol * 100) / 7, (gConfig.mastervol * 100) / 7);

                ptr2 = (code0UnkStruct16 *)D_801CD990[D_801CE5A0]->unk7C;
                ptr2->unk70 = ptr->unk14->unk4[*ptr->unk18].unk8;
                if (ptr->unk14 == &D_801CA970)
                {
                    if (*ptr->unk18 == 0)
                        func_801C14C4(ptr2, 0, 200, 200);
                    else
                        func_801C14C4(ptr2, 0xFF, 0xFF, 0xFF);
                }
            }
        }
    }
}

/*801C4B34*/
void func_801C4B34(void)
{
    code0UnkStruct16 *ptr;
    code1UnkStruct5 *ptr2;
    u8 c;
    s16 sin;

    ptr2 = &D_801CE5A8->unk4[D_801CE5A0];
    if (D_801AE914 == 0)
        func_801C118C();

    sin = sins(D_801CC910 << 13);
    ptr = D_801CD990[D_801CE5A0];
    c = ((sin*3) >> 11) - 49;
    ptr->unk6B.b = c;
    ptr->unk6B.g = c;
    ptr->unk6B.r = c;

    if (gMusicVolume == 0)
    {
        MusHandleStop(gMusicHandle, 0);
        gMusicHandle = 0;
    }
    else if (gMusicHandle == 0)
    {
        playMusic(gMusicNum);
    }

    if ((D_801AE914 == 0) && (D_801CE5A8 == &D_801CB528))
    {
        D_801CC8C4++;
        if (func_801C0E68())
            D_801CC8C4 = 0;

        if (D_801CC8C4 >= 451)
        {
            main_80000624(func_801C15CC);
            return;
        }
    }

    if (D_801CC8C0 == 1)
    {
        if (D_801CA144 > -1.8)
        {
            D_801CA144 -= 0.2;
            if (D_801CA144 < -1.8)
            {
                D_801CC8C0 = 0;
                D_801CA144 = 1.8f;
                if (ptr2->unkC != NULL)
                    ptr2->unkC();
            }
        }
    }
    if (D_801CC8C0 == -1)
    {
        if (D_801CA144 > -1.8)
        {
            D_801CA144 -= 0.2;
            if (D_801CA144 < -1.8)
            {
                D_801CC8C0 = 0;
                D_801CA144 = 1.8f;
                _menuExit();
            }
        }
    }
    if (D_801CC8C0 == 0)
    {
        if (D_801CA144 > 0.0f)
        {
            D_801CA144 -= 0.2;
            if (D_801CA144 < 0.0f)
                D_801CA144 = 0.0f;
        }
        if (D_801CA144 == 0.0f)
        {
            if (D_801AE914 == 0)
                func_801C3E5C();
            else
                func_801C45C0();
        }
    }
}

/*801C4E90*/
static void func_801C4E90(void)
{
    gCheatFirstPersonConfig = CONFIG_OFF;
    gCheatActionNukemConfig = CONFIG_OFF;
    gCheatSelectSkinConfig = CONFIG_OFF;
    gCheatBigHeadModeConfig = CONFIG_OFF;
    gCheatFlatShadingConfig = CONFIG_OFF;
    gCheatWeatherConfig = CONFIG_OFF;
    gCheatBigGunConfig = CONFIG_OFF;
    gCheatIceSkinConfig = CONFIG_OFF;
    gCheatFastZombiesConfig = CONFIG_OFF;
    gCheatWeaponSmgConfig = CONFIG_OFF;
    gCheatWeaponBlasterConfig = CONFIG_OFF;
    gCheatWeaponSniperConfig = CONFIG_OFF;
    gCheatWeaponFreezerConfig = CONFIG_OFF;
    gCheatWeaponRevolverConfig = CONFIG_OFF;
    gCheatWeaponClaw12Config = CONFIG_OFF;
    gCheatWeapon3030Config = CONFIG_OFF;
    gCheatWeaponSawedOffConfig = CONFIG_OFF;
    gCheatWeaponVoltCannonConfig = CONFIG_OFF;
    gCheatWeaponGattlingGunConfig = CONFIG_OFF;
    gCheatWeaponGammaCannonConfig = CONFIG_OFF;
}

/*801C4F38*/
void configInitialize(void)
{
    Amemset(&D_801CE5F0, 0, sizeof(D_801CE5F0));
    Amemset(&gConfig, 0, sizeof(gConfig));
    gGraphicsOption = CONFIG_GRAPHICS_NORMAL;
    D_801CE5F0.unk103A = 0;
    gConfig.multiplayer.time_limit = 1;
    gConfig.multiplayer.frag_count = 0;
    gConfig.multiplayer.radar = CONFIG_ON;
    gConfig.multiplayer.friendly_fire = CONFIG_OFF;
    gConfig.mastervol = 7;
    gConfig.musicvol = 3;
    gConfig.menuIndex.select_difficulty = 2;
    gConfig.rumblepak = 7;
    gConfig.sound = CONFIG_SOUND_STEREO;
    gConfig.difficulty = 1;

    if (osMemSize > 0x400000)
        gGraphicsOption = CONFIG_GRAPHICS_HIGHRES;

    gConfig.crosshair[0] = 0;
    gConfig.crosshair[1] = 0;
    gConfig.crosshair[2] = 0;
    gConfig.crosshair[3] = 0;
    gConfig.autoaim[0] = 2;
    gConfig.autoaim[1] = 2;
    gConfig.autoaim[2] = 2;
    gConfig.autoaim[3] = 2;
    D_801AE914 = 0;
    D_801A1994 = 0;
    D_80199524 = 0;
    D_800FE3FC = 0;
    gUnlockedCheatWeapons = 0;
    gUnlockedCheat = 0;
    func_801C4E90();
    sprintf(D_801CDBB0, "ZERO HOUR");
}

#ifdef AVOID_UB
/*801CB948*/ static s32 D_801CB948[11] = {0, 10, 6, 8, 7, 9, 0, 0, 0, 0, 0}; /*Fix out of bound access*/
#else
/*801CB948*/ static s32 D_801CB948[6] = {0, 10, 6, 8, 7, 9};
#endif

/*801C509C*/
static void func_801C509C(void)
{
    f32 f1, f2, f3;
    s32 i;

    D_801A1994 = 0;

    if (D_801A1958.enemies_total == 0)
        f1 = 1.0f;
    else
        f1 = (f32)D_801A1958.enemies_killed / (f32)D_801A1958.enemies_total;

    if (D_801A1958.babes_total == 0)
        f2 = 1.0f;
    else
        f2 = (f32)D_801A1958.babes_saved / (f32)D_801A1958.babes_total;

    if (D_801A1958.secrets_total == 0)
        f3 = 1.0f;
    else
        f3 = (f32)D_801A1958.secrets_found / (f32)D_801A1958.secrets_total;

    f1 *= 2.0f;
    f2 *= 2.0f;

    D_801A1958.unk10 = (s32)(((f1 + f2 + f3) / 5.0) * 100.0);
    if (D_801CDC64.unk0 == 1)
    {
        func_801C5C68();
        return;
    }

    _cheatAwarded = awardMapCheat(gMapNum);
    allocMemory(SCREEN_WIDTH, SCREEN_HEIGHT*2, DISPLAY_LIST_SIZE*2, 0);
    D_800BD3E8 = 1;
    func_801C10C8();
    setCameraPosition(0.0f, 0.0f, -90.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    edl_80081688(&D_801CDB08, 20);
    edl_80081688(&D_801CC888, 21);
    edl_80081688(&D_801CDBC8, 23);
    edl_80081688(&D_801CDA98, 22);
    func_8007FD8C(&D_800DFB08[0], 11);
    func_8007FD8C(&D_800E0454[0], D_801CB948[gMapChapter[gMapNum].chapter]);
    func_8007FD8C(&D_800DFA90[0], 2);
    D_800E0F58 = 0;

    for (i = 0; i < ARRAY_COUNT(D_01022510); i++)
        func_80083700(1, &D_801CE5E8[i], 0, 0);

    D_800E0F58 = 1;
    main_80002390();
    main_80000610();
    D_801CDB04 = 0;

    if (gMapChapter[gLoadMapNum].chapter == TRAINING)
    {
        gLoadMapNum = 0;
        main_80000624(func_801C9B08);
        return;
    }

    if (D_800FE3FC == 0)
        func_801C90E4();

    D_801CDBA8 = 0;
    D_800BD3F9 = 5;
    D_800DF585 = 0;
}

/*801C53E8*/
static s16 func_801C53E8(s16 mapnum)
{
    if (D_800FEA90 == 0)
    {
        if (mapnum+1 != MAP_WETWORLD)
        {
            if (mapnum+1 != MAP_GOING_DOWN_THE_RACK)
                return mapnum+1;
            else
                return mapnum+2;
        }
        else
            return mapnum+2;
    }
    else
        return mapnum+1;
}

/*801C542C*/
void func_801C542C(void)
{
    code1UnkStruct2 *ptr;
    s32 i, j;

    switch (D_801CDB04)
    {
    case 0:
        func_801C53E8(gMapNum);
        func_801C0EDC(0x9000);
        func_8007F050();
        D_801CDA20 = func_8007FC08(&D_800E0454[0], NULL, 0, 0, 500);
        func_801C1114();
        func_801C1158(0, 0, 0, 0xFF);
        D_801CC88C = -1;
        D_801CF6E0[0] = func_800802C0(gMapChapter[gMapNum].mapname, gScreenWidth / 2, -12, 180, 1);
        func_801C14C4(D_801CF6E0[0], 32, 0xFF, 32);
#if VERSION_US
        D_801CF6E0[1] = func_800802C0("TIME TAKEN:", 0, 65, 200, 0);
        D_801CF6E0[2] = func_800802C0("KILLS:", 0, 87, 200, 0);
        D_801CF6E0[3] = func_800802C0("BABES:", 0, 109, 200, 0);
        D_801CF6E0[4] = func_800802C0("SECRETS:", 0, 131, 200, 0);
        D_801CF6E0[5] = func_800802C0("OVERALL RATING:", 0, 153, 200, 0);
#elif VERSION_FR
        D_801CF6E0[1] = func_800802C0("TEMPS ECOULE:", 0, 65, 200, 0);
        D_801CF6E0[2] = func_800802C0("TUES:", 0, 87, 200, 0);
        D_801CF6E0[3] = func_800802C0("LES GONZESSES:", 0, 109, 200, 0);
        D_801CF6E0[4] = func_800802C0("SECRETS:", 0, 131, 200, 0);
        D_801CF6E0[5] = func_800802C0("TOTAL:", 0, 153, 200, 0);
#endif
        D_801CD980 = 0;
        func_801C2BE8(&D_801CB938);

        if (D_80138620 != 0)
            D_801CE5A0 = 1;
        else
            D_801CE5A0 = 0;

        sprintf(D_801CDB58[0], "%d : %02d", D_801A1958.unkC / 1800U,
                (D_801A1958.unkC / 30U) - ((D_801A1958.unkC / 1800U) * 60));
        D_801CDBD0[0] = func_800802C0(D_801CDB58[0], gScreenWidth, 65, 200, 2);
        sprintf(D_801CDB58[1], "%d / %d", D_801A1958.enemies_killed, D_801A1958.enemies_total);
        D_801CDBD0[1] = func_800802C0(D_801CDB58[1], gScreenWidth, 87, 200, 2);
        sprintf(D_801CDB58[2], "%d / %d", D_801A1958.babes_saved, D_801A1958.babes_total);
        D_801CDBD0[2] = func_800802C0(D_801CDB58[2], gScreenWidth, 109, 200, 2);
        sprintf(D_801CDB58[3], "%d / %d", D_801A1958.secrets_found, D_801A1958.secrets_total);
        D_801CDBD0[3] = func_800802C0(D_801CDB58[3], gScreenWidth, 131, 200, 2);
        sprintf(D_801CDB58[4], "%d%%", D_801A1958.unk10);
        D_801CDBD0[4] = func_800802C0(D_801CDB58[4], gScreenWidth, 153, 200, 2);

        for (i = 0; i < ARRAY_COUNT(D_801CDBD0)-1; i++)
            func_801C14C4(D_801CDBD0[i], 0, 200, 200);

        D_801CA144 = 0.0f;
        D_801CE59C = 0;

        if (_cheatAwarded)
        {
#if VERSION_US
            D_801CF6E0[6] = func_8007FE2C("CHEAT AWARDED", gScreenWidth/2, 128, 200, 1, 0);
#elif VERSION_FR
            D_801CF6E0[6] = func_8007FE2C("TRUC OFFERT", gScreenWidth/2, 128, 200, 1, 0);
#endif
        }

        if ((((gMapNum == MAP_WETWORLD) || (gMapNum == MAP_BOSS_HOG)) == 0) &&
            (((gMapNum == MAP_CYBORG_SCORPION) || ((gMapNum >= MAP_THE_RACK))) == 0))
        {
            if (gTimeMachinePart & (1 << gMapNum))
            {
                D_801CE59C = 1;
#if VERSION_US
                D_801CF6E0[7] = func_8007FE2C("TIME MACHINE PART FOUND",
                                              gScreenWidth / 2, (gScreenHeight / 2) + 96, 200, 1, 0);
#elif VERSION_FR
                D_801CF6E0[7] = func_8007FE2C("MACHINE REMONT. TPS PRISE",
                                              gScreenWidth / 2, (gScreenHeight / 2) + 96, 200, 1, 0);
#endif
            }
            else
            {
#if VERSION_US
                D_801CF6E0[7] = func_8007FE2C("TIME MACHINE PART NOT FOUND",
                                              gScreenWidth / 2, (gScreenHeight / 2) + 96, 200, 1, 0);
#elif VERSION_FR
                D_801CF6E0[7] = func_8007FE2C("MACHINE REMONT. TPS NON TROUVEE",
                                              gScreenWidth / 2, (gScreenHeight / 2) + 96, 200, 1, 0);
#endif
                D_801CF6E0[7]->unkC |= 0x04000000;
            }
        }
        D_801CDB04++;
        break;
    case 1:
        j = D_801CC88C;
        if (j == D_801CDB04)
        {
            if (D_8011BC40->unk10 == 0xFF)
            {
                if (D_801CDA8C == 0)
                    func_8007F050();

                D_801CDA8C++;
                if (D_801CDA8C >= 11)
                {
                    if (D_801CDBA8 == j)
                    {
                        func_801C90E4();
                        ptr = &D_801CE5F0.unk4[gMapNum];
                        ptr->unk182 = D_801A1958.unk10;
                        ptr->unk172 = D_801A1958.unkC;
                        ptr->babes_saved = D_801A1958.babes_saved;
                        ptr->secrets_found = D_801A1958.secrets_found;
                        ptr->enemies_killed = D_801A1958.enemies_killed;
                        ptr->enemies_total = D_801A1958.enemies_total;
                        ptr->babes_total = D_801A1958.babes_total;
                        ptr->secrets_total = D_801A1958.secrets_total;
                        func_801C948C();
                        D_801CDB04 = 2;
                    }
                    else if (D_800FE3FC == 0)
                        func_801C3310();
                    else
                        main_80000624(func_801C7574);
                }
            }
            else
            {
                D_8011BC40->unk10 += 16;
                if (D_8011BC40->unk10 >= 0xEF)
                    D_8011BC40->unk10 = 0xFF;
            }
        }
        else
        {
            func_801C118C();
            func_801C4B34();
            if (D_801CA144 > 0.0f)
            {
                D_801CA144 -= 0.2;
                if (D_801CA144 < 0.0f)
                    D_801CA144 = 0.0f;
            }
            if (_cheatAwarded)
            {
                if ((D_801CC910 & 0xF) < 7)
                    D_801CF6E0[6]->unkC &= ~1;
                else
                    D_801CF6E0[6]->unkC |= 1;
            }
            if (D_801CE59C != 0)
            {
                if ((D_801CC910 & 0xF) < 7)
                    D_801CF6E0[7]->unkC &= ~1;
                else
                    D_801CF6E0[7]->unkC |= 1;
            }
        }
        break;
    case 2:
        if (controller_8008C8DC())
            D_801CDB04 = 0;
        break;
    }
}

/*801CB960*/ static char *D_801CB960[4] = {
#if VERSION_US
    "PLAYER 1 WINS",
    "PLAYER 2 WINS",
    "PLAYER 3 WINS",
    "PLAYER 4 WINS",
#elif VERSION_FR
    "VAINQUEUR : JOUEUR 1",
    "VAINQUEUR : JOUEUR 2",
    "VAINQUEUR : JOUEUR 3",
    "VAINQUEUR : JOUEUR 4",
#endif
};

typedef struct {
    /*0x00*/ char *unk0[4];
    /*0x10*/ char *unk10[2];
} _EB300UnkStruct3;

/*801CB970*/ static _EB300UnkStruct3 D_801CB970 = {
#if VERSION_US
    {"PLAYER 1", "PLAYER 2", "PLAYER 3", "PLAYER 4"},
    {"BLUE", "RED"},
#elif VERSION_FR
    {"JOUEUR 1", "JOUEUR 2", "JOUEUR 3", "JOUEUR 4"},
    {"BLEUE", "ROUGE"},
#endif
};

/*801CB988*/ static char *D_801CB988[4] = {"P1", "P2", "P3", "P4"};

/*801C5C68*/
static void func_801C5C68(void)
{
    code0UnkStruct16 *sp28[2];
    code0UnkStruct16 *ptr;
    s32 i, j, k, l, m, n, o;

    allocMemory(SCREEN_WIDTH, SCREEN_HEIGHT*2, DISPLAY_LIST_SIZE*2, 0);
    func_801C10C8();
    setCameraPosition(0.0f, 0.0f, -90.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    edl_80081688(&D_801CDB08, 20);
    edl_80081688(&D_801CC888, 21);
    edl_80081688(&D_801CDBC8, 23);
    edl_80081688(&D_801CDA98, 22);
    func_8007FD8C(&D_800DFB08[0], 11);
    func_8007FD8C(&D_800E0454[0], D_801CB948[gMapChapter[gMapNum].chapter]);
    D_800E0F58 = 0;

    for (i = 0; i < ARRAY_COUNT(D_01022510); i++)
        func_80083700(1, &D_801CE5E8[i], 0, 0);

    D_800E0F58 = 1;
    func_801C1114();
    D_801CDA20 = func_8007FC08(&D_800E0454[0], NULL, 0, 0, 500);
    func_801C1158(0, 0, 0, 0xFF);
    D_801CC88C = -1;
    D_801CF6E0[0] = func_800802C0(gMapChapter[gMapNum].mapname, gScreenWidth / 2, 24, 200, 1);
    func_801C14C4(D_801CF6E0[0], 32, 0xFF, 32);
#if VERSION_US
    D_801CF6E0[1] = func_800802C0("PRESS START TO ENTER", gScreenWidth/2, 186, 200, 1);
#elif VERSION_FR
    D_801CF6E0[1] = func_800802C0("APPUYEZ SUR START POUR", gScreenWidth/2, 186, 200, 1);
#endif
    D_801CF6E0[2] = func_800802C0(gMapChapter[gMapNum + 1].mapname, gScreenWidth / 2, 208, 200, 1);

    if (D_801CDC64.unk2 == 5)
    {

        m = (gScreenWidth / 2) - 72;
        k = 0;
        for (i = 0; i < ARRAY_COUNT(D_801CB970.unk10); i++)
        {
            sp28[i] = func_800802C0(D_801CB970.unk10[i], 104, m+i*28, 200, 0);

            for (l = 0; l < D_801CDC64.unk1; l++)
            {
                if (D_800E16A0[l] == i)
                    break;
            }

            o = CLAMP_MAX((D_800FF4F0[l].unk0 - D_800FF4F0[l].unk2), 9999);

            sprintf(D_801CF648[k], "%4d", o);
            func_800802C0(D_801CF648[k], 170, m+i*28, 200, 0);
            k++;
        }

        sp28[0]->unk6B.r = 0;
        sp28[0]->unk6B.g = 0xFF;
        sp28[0]->unk6B.b = 0xFF;
        sp28[1]->unk6B.r = 0xFF;
        sp28[1]->unk6B.g = 0x32;
        sp28[1]->unk6B.b = 0x32;
    }
    else if (D_801CDC64.unk2 == 3)
    {
        n = -1;
        for (i = 0; i < D_801CDC64.unk1; i++)
        {
            if (gPlayer[i].unk45 == 0)
            {
                n = i;
                break;
            }
        }

        if (n != -1)
            D_801CF6E0[3] = func_800802C0(D_801CB960[n], gScreenWidth/2, 102, 200, 1);
        else
        {
#if VERSION_US
            D_801CF6E0[3] = func_800802C0("DRAW", gScreenWidth/2, 102, 200, 1);
#elif VERSION_FR
            D_801CF6E0[3] = func_800802C0("MATCH NUL", gScreenWidth/2, 102, 200, 1);
#endif
        }
    }
    else
    {
        m = (gScreenWidth / 2) + 40;
        ptr = func_8007FE2C("TOTAL", (D_801CDC64.unk1 * 40) + 118, (gScreenWidth / 2) + 20, 64, 1, 0);
        ptr->unkC |= 0x08000000;

        k = 0;
        for (i = 0; i < D_801CDC64.unk1; i++)
        {

            ptr = func_8007FE2C(D_801CB970.unk0[i], 24, m+i*20, 64, 0, 0);
            ptr->unkC |= 0x08000000;
            ptr = func_8007FE2C(D_801CB988[i], 126 + i*40, m - 20, 64, 2, 0);
            ptr->unkC |= 0x08000000;

            for (j = 0; j < D_801CDC64.unk1; j++)
            {
                o = MIN(D_800FF4F0[i].unk4[j], 9999);
                sprintf(D_801CF648[k], "%d", o);
                func_8007FE2C(D_801CF648[k], 118+j*40, m+i*20, 64, 1, 0);
                k++;
            }

            o = CLAMP_MAX((D_800FF4F0[i].unk0 - D_800FF4F0[i].unk2), 9999);
            sprintf(D_801CF648[k], "%d", o);
            func_8007FE2C(D_801CF648[k], (D_801CDC64.unk1 * 40) + 118, m+i*20, 64, 1, 0);
            k++;

        }
    }
    D_801CA144 = 0.0f;
    D_800BD3F9 = 4;
    main_80002390();
    main_80000610();
}

/*801C63CC*/
void func_801C63CC(void)
{

    if (D_801CC88C == 1)
    {
        if (D_8011BC40->unk10 == 0xFF)
        {
            if (D_801CDA8C == 0)
                func_8007F050();

            D_801CDA8C++;
            if (D_801CDA8C >= 11)
                main_80000624(main_80001F40);
        }
        else
        {
            D_8011BC40->unk10 += 0x10;
            if (D_8011BC40->unk10 >= 0xEF)
                D_8011BC40->unk10 = 0xFF;
        }
    }
    else
    {
        func_801C118C();
        if ((func_801C0E68() & 0x8000) || (func_801C0E68() & 0x1000))
        {
            func_801C0EDC(0x8000);
            func_801C0EDC(0x1000);
            playSfx(747);
            gLoadMapNum++;
            if (gMapChapter[gLoadMapNum].chapter == 99)
            {
                for (gLoadMapNum = 0; gMapChapter[gLoadMapNum].chapter != DUKEMATCH; gLoadMapNum++)
                    ;
            }
            D_801CDA8C = 0;
            D_801CC88C = 1;
        }
    }
}

/*801C6560*/
void func_801C6560(void)
{
    s32 i;

    allocMemory(SCREEN_WIDTH, SCREEN_HEIGHT*2, DISPLAY_LIST_SIZE*4, 0);
    func_801C10C8();
    setCameraPosition(0.0f, 0.0f, -500.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    func_8007FD8C(&D_800DFB08[0], 11);
    func_8007FD8C(&D_800E0404[0], 13);

    for (i = 0; gpLicenceStrInfo[i]; i++)
        func_8007FE2C(gpLicenceStrInfo[i], gScreenWidth / 2, (46 + i * 12), 64, 1, 0);

    func_801C1114();
    func_801C1158(0, 0, 0, 0xFF);
    D_801CC88C = -1;
    main_80002390();
    main_80000610();
    D_800BD3F9 = 8;
    D_801CDB04 = 100;
    D_801CE494 = 0;
    D_800BD3E8 = 1;
}

/*801C66D8*/
void func_801C66D8(void)
{
    s32 i;

    switch (D_801CE494)
    {
    case 0:
        i = D_801CC88C;
        if (i == 1)
        {
            if (D_8011BC40->unk10 == 0xFF)
            {
                if (D_801CDA8C == 0)
                    func_8007F050();

                D_801CDA8C++;
                if (D_801CDA8C >= 5)
                {
                    if (osMemSize > 0x400000)
                    {
                        edl_80081688(&D_801CC7F0, 24);
                        edl_80081688(&D_801CDB10, 25);
                        edl_80081688(&D_801CDB44, 27);
                        edl_80081688(&D_801CDB18, 26);
                        func_8007F050();
                        D_801CDBF8 = func_8008372C(2, &D_801CA3A8, 0x9080, &D_801CA3B8, 0);
                        D_801CDBF8->unk3C = 100.0f;
                        func_801C1114();
                        func_801C1158(0, 0, 0, 0xFF);
                        D_801CC88C = -1;
#if VERSION_US
                        func_8007FE2C("EXPANSION PAK FOUND", gScreenWidth / 2, (gScreenHeight / 2) + 150, 0, i, 0);
#elif VERSION_FR
                        func_8007FE2C("PACK D'EXTENSION DETECTE", gScreenWidth / 2, (gScreenHeight / 2) + 150, 0, i, 0);
#endif
                    }
                    else
                    {
                        D_801CE494++;
                        cache1d_8002AAC0();
                        allocMemory(SCREEN_WIDTH, SCREEN_HEIGHT, DISPLAY_LIST_SIZE*2, 0);
                        func_801C10C8();
                        func_8007FD8C(&D_800DFB08[0], 11);
                        func_8007FD8C(&D_800E0404[0], 13);
                        D_800BD3F8 = 1;
                        func_801C1114();
                        func_8007FC08(&D_800E0404[0], NULL, 0, 0, 500);
                        func_801C1158(0, 0, 0, 0xFF);
                        D_801CC88C = -1;
                        main_80002390();
                        main_80000610();
                    }
                    D_801CDB04 = 100;
                    D_801CE494++;
                }
            }
            else
            {
                D_8011BC40->unk10 += 0x10;
                if (D_8011BC40->unk10 >= 0xEF)
                    D_8011BC40->unk10 = 0xFF;
            }
            return;
        }
        if (D_801CDB04 != 0)
        {
            D_801CDB04--;
            if (D_801CDB04 == 0)
                break;
        }
        goto block_39;
    case 1:
        if (D_801CC88C == 1)
        {
            if (D_8011BC40->unk10 == 0xFF)
            {
                if (D_801CDA8C == 0)
                    func_8007F050();

                D_801CDA8C++;
                if (D_801CDA8C >= 5)
                {
                    cache1d_8002AAC0();
                    allocMemory(SCREEN_WIDTH, SCREEN_HEIGHT, DISPLAY_LIST_SIZE*2, 0);
                    func_801C10C8();
                    func_8007FD8C(&D_800DFB08[0], 11);
                    func_8007FD8C(&D_800E0404[0], 13);
                    D_800BD3F8 = 1;
                    func_801C1114();
                    func_8007FC08(&D_800E0404[0], NULL, 0, 0, 500);
                    func_801C1158(0, 0, 0, 0xFF);
                    D_801CC88C = -1;
                    main_80002390();
                    main_80000610();
                    D_801CDB04 = 100;
                    D_801CE494++;
                }
            }
            else
            {
                D_801CDBF8->unk4C += 0.02;
                D_801CDBF8->unk50 += 0.03;
                D_8011BC40->unk10 += 0x10;
                if (D_8011BC40->unk10 >= 0xEF)
                    D_8011BC40->unk10 = 0xFF;
            }
            return;
        }
        if (D_801CDB04 != 0)
        {
            D_801CDBF8->unk4C += 0.02;
            D_801CDBF8->unk50 += 0.03;
        }
        if (D_801CDB04 != 0)
        {
            D_801CDB04--;
            if (D_801CDB04 == 0)
                break;
        }
        goto block_39;
    case 2:
        if (D_801CC88C == 1)
        {
            if (D_8011BC40->unk10 == 0xFF)
            {
                func_8007F050();
                func_801C1114();
                func_8007FC08(&D_800E0404[1], NULL, 0, 0, 500);
                func_801C1158(0, 0, 0, 0xFF);
                D_801CC88C = -1;
                D_801CDB04 = 100;
                D_801CE494++;
            }
            else
            {
                D_8011BC40->unk10 += 0x10;
                if (D_8011BC40->unk10 >= 0xEF)
                    D_8011BC40->unk10 = 0xFF;
            }
            return;
        }
        if (D_801CDB04 != 0)
        {
            D_801CDB04--;
            if (D_801CDB04 == 0)
                break;
        }
        goto block_39;
    case 3:
        if (D_801CC88C == 1)
        {
            if (D_8011BC40->unk10 == 0xFF)
            {
                func_8007F050();
                func_801C1114();
                func_8007FC08(&D_800E0404[2], NULL, 0, 0, 500);
                func_801C1158(0, 0, 0, 0xFF);
                D_801CC88C = -1;
                D_801CDB04 = 100;
                D_801CE494++;
            }
            else
            {
                D_8011BC40->unk10 += 0x10;
                if (D_8011BC40->unk10 >= 0xEF)
                    D_8011BC40->unk10 = 0xFF;
            }
            return;
        }
        if (D_801CDB04 != 0)
        {
            D_801CDB04--;
            if (D_801CDB04 == 0)
                break;
        }
        goto block_39;
    case 4:
        if (D_801CC88C == 1)
        {
            if (D_8011BC40->unk10 == 0xFF)
            {
                if (D_801CDA8C == 0)
                    func_8007F050();

                D_801CDA8C++;
                if (D_801CDA8C >= 5)
                {
                    cache1d_8002AAC0();
                    func_801C15CC();
                }
            }
            else
            {
                D_8011BC40->unk10 += 0x10;
                if (D_8011BC40->unk10 >= 0xEF)
                    D_8011BC40->unk10 = 0xFF;
            }
            return;
        }
        if (D_801CDB04 != 0)
        {
            D_801CDB04--;
            if (D_801CDB04 == 0)
                break;
        }
        goto block_39;
    default:
    block_39:
        if (*D_801CD986 & 0x1000)
        {
            *D_801CD986 &= ~0x1000;
            if (D_801CE494 > 0)
                D_801CDB04 = 1;
        }
        func_801C118C();
        return;
    }

    func_801C1158(0, 0, 0, 0);
    D_801CC88C = 1;
    D_801CDA8C = 0;
}

/*801C6CA4*/
static void _unlockSkinEnforcers(void)
{
    gUnlockedSkin |= SKIN_ENFORCER|SKIN_ENFORCERCAPTAIN|SKIN_BATTLEENFORCER;
}

/*801C6CC4*/
static void _unlockSkinPigs(void)
{
    gUnlockedSkin |= SKIN_PIGCOP|SKIN_RIOTPIG|SKIN_ROADHOG|SKIN_WARPIG|SKIN_COWBOYGRUNT|SKIN_SAVAGEGRUNT|SKIN_SOLDIERGRUNT|SKIN_CAPITALISTPIG;
}

/*801C6CE4*/
static void _unlockSkinDukes(void)
{
    gUnlockedSkin |= SKIN_POSHDUKE|SKIN_BATTLEDRESSDUKE|SKIN_DOGTAGDUKE;
}

/*801C6D00*/
static void _unlockSkinWomen(void)
{
    gUnlockedSkin |= SKIN_MARSHALL|SKIN_SHERIFF|SKIN_SQUAW|SKIN_SURVIVOR|SKIN_KIMBERLYSTROKES;
}

/*801C6D24*/
static void _unlockSkinBrothersNukem(void)
{
    gUnlockedSkin |= SKIN_EVILDUKE|SKIN_CUSTER|SKIN_RIPPER|SKIN_XTERMINATOR;
}

/*801C6D40*/
static void _unlockSkinSoldiers(void)
{
    gUnlockedSkin |= SKIN_MARINE|SKIN_SERGEANT;
}

/*801C6D5C*/
static void _unlockCheatFirstPerson(void)
{
    gCheatFirstPersonConfig = CONFIG_ON;
    gUnlockedCheat |= (1<<CHEAT_FIRST_PERSON);
}

/*801C6D84*/
static void _unlockCheatBigHeadMode(void)
{
    gCheatBigHeadModeConfig = CONFIG_ON;
    gUnlockedCheat |= (1<<CHEAT_BIG_HEAD_MODE);
}

/*801C6DAC*/
static void _unlockCheatFlatShading(void)
{
    gCheatFlatShadingConfig = CONFIG_ON;
    gUnlockedCheat |= (1<<CHEAT_FLAT_SHADING);
}

/*801C6DD4*/
static void _unlockCheatWeather(void)
{
    gCheatWeatherConfig = CONFIG_ON;
    gUnlockedCheat |= (1<<CHEAT_WEATHER);
}

/*801C6DFC*/
static void _unlockCheatBigGun(void)
{
    gCheatBigGunConfig = CONFIG_ON;
    gUnlockedCheat |= (1<<CHEAT_BIG_GUN);
}

/*801C6E24*/
static void _unlockCheatIceSkin(void)
{
    gCheatIceSkinConfig = CONFIG_ON;
    gUnlockedCheat |= (1<<CHEAT_ICE_SKINS);
}

/*801C6E4C*/
static void _unlockCheatActionNukem(void)
{
    gCheatActionNukemConfig = CONFIG_ON;
    gUnlockedCheat |= (1<<CHEAT_ACTION_NUKEM);
}

/*801C6E74*/
static void _unlockCheatSelectSkin(void)
{
    gCheatSelectSkinConfig = CONFIG_ON;
    gUnlockedCheat |= (1<<CHEAT_SELECT_SKIN);
}

/*801C6E9C*/
static void _unlockCheatFastZombies(void)
{
    gCheatFastZombiesConfig = CONFIG_ON;
    gUnlockedCheat |= (1<<CHEAT_FAST_ZOMBIES);
}

/*801C6EC4*/
static void _unlockCheatWeaponSmg(void)
{
    gCheatWeaponSmgConfig = CONFIG_ON;
    gUnlockedCheatWeapons |= (1<<CHEAT_WEAPON_SMG);
}

/*801C6EEC*/
static void _unlockCheatWeaponBlaster(void)
{
    gCheatWeaponBlasterConfig = CONFIG_ON;
    gUnlockedCheatWeapons |= (1<<CHEAT_WEAPON_BLASTER);
}

/*801C6F14*/
static void _unlockCheatWeaponSniper(void)
{
    gCheatWeaponSniperConfig = CONFIG_ON;
    gUnlockedCheatWeapons |= (1<<CHEAT_WEAPON_SNIPER);
}

/*801C6F3C*/
static void _unlockCheatWeaponFreezer(void)
{
    gCheatWeaponFreezerConfig = CONFIG_ON;
    gUnlockedCheatWeapons |= (1<<CHEAT_WEAPON_FREEZER);
}

/*801C6F64*/
static void _unlockCheatWeaponRevolver(void)
{
    gCheatWeaponRevolverConfig = CONFIG_ON;
    gUnlockedCheatWeapons |= (1<<CHEAT_WEAPON_REVOLVER);
}

/*801C6F8C*/
static void _unlockCheatWeaponClaw12(void)
{
    gCheatWeaponClaw12Config = CONFIG_ON;
    gUnlockedCheatWeapons |= (1<<CHEAT_WEAPON_CLAW12);
}

/*801C6FB4*/
static void _unlockCheatWeapon3030(void)
{
    gCheatWeapon3030Config = CONFIG_ON;
    gUnlockedCheatWeapons |= (1<<CHEAT_WEAPON_3030);
}

/*801C6FDC*/
static void _unlockCheatWeaponSawedOff(void)
{
    gCheatWeaponSawedOffConfig = CONFIG_ON;
    gUnlockedCheatWeapons |= (1<<CHEAT_WEAPON_SAWEDOFF);
}

/*801C7004*/
static void _unlockCheatWeaponVoltCannon(void)
{
    gCheatWeaponVoltCannonConfig = CONFIG_ON;
    gUnlockedCheatWeapons |= (1<<CHEAT_WEAPON_VOLTCANNON);
}

/*801C702C*/
static void _unlockCheatWeaponGattlingGun(void)
{
    gCheatWeaponGattlingGunConfig = CONFIG_ON;
    gUnlockedCheatWeapons |= (1<<CHEAT_WEAPON_GATTLINGGUN);
}

/*801C7054*/
static void _unlockCheatWeaponGammaCannon(void)
{
    gCheatWeaponGammaCannonConfig = CONFIG_ON;
    gUnlockedCheatWeapons |= (1<<CHEAT_WEAPON_GAMMACANNON);
}

/*801C707C*/
static void _unlockCheatWeaponAll(void)
{
    _unlockCheatWeaponSmg();
    _unlockCheatWeaponBlaster();
    _unlockCheatWeaponSniper();
    _unlockCheatWeaponFreezer();
    _unlockCheatWeaponRevolver();
    _unlockCheatWeaponClaw12();
    _unlockCheatWeapon3030();
    _unlockCheatWeaponSawedOff();
    _unlockCheatWeaponVoltCannon();
    _unlockCheatWeaponGattlingGun();
    _unlockCheatWeaponGammaCannon();
}

/*801C70EC*/
static void _toggleDebugMenu(void)
{
    gDebugMenu = !gDebugMenu;
}

/*801C7108*/
static void func_801C7108(void)
{
    s32 i, j, k;

    for (i = 0; i < ARRAY_COUNT(D_801CB32C)-1; i++)
        D_801CB32C[i].unk4 = 2;
    for (j = 0; j < ARRAY_COUNT(D_801CB2AC)-1; j++)
        D_801CB2AC[j].unk4 = 2;
    for (k = 0; k < ARRAY_COUNT(D_801CB14C)-1; k++)
        D_801CB14C[k].unk4 = 2;

    if (gUnlockedCheat & (1<<CHEAT_BIG_HEAD_MODE))
        D_801CB32C[0].unk4 = 0;
    if (gUnlockedCheat & (1<<CHEAT_FLAT_SHADING))
        D_801CB32C[1].unk4 = 0;
    if (gUnlockedCheat & (1<<CHEAT_WEATHER))
        D_801CB32C[2].unk4 = 0;
    if (gUnlockedCheat & (1<<CHEAT_BIG_GUN))
        D_801CB32C[3].unk4 = 0;
    if (gUnlockedCheat & (1<<CHEAT_ICE_SKINS))
        D_801CB32C[4].unk4 = 0;
    if (gUnlockedCheat & (1<<CHEAT_FAST_ZOMBIES))
        D_801CB32C[5].unk4 = 0;
    if (gUnlockedCheat & (1<<CHEAT_FIRST_PERSON))
        D_801CB2AC[0].unk4 = 0;
    if (gUnlockedCheat & (1<<CHEAT_ACTION_NUKEM))
        D_801CB2AC[1].unk4 = 0;
    if (gUnlockedCheat & (1<<CHEAT_SELECT_SKIN))
        D_801CB2AC[2].unk4 = 0;
    if (gUnlockedCheatWeapons & (1<<CHEAT_WEAPON_SMG))
        D_801CB14C[0].unk4 = 0;
    if (gUnlockedCheatWeapons & (1<<CHEAT_WEAPON_BLASTER))
        D_801CB14C[1].unk4 = 0;
    if (gUnlockedCheatWeapons & (1<<CHEAT_WEAPON_SNIPER))
        D_801CB14C[2].unk4 = 0;
    if (gUnlockedCheatWeapons & (1<<CHEAT_WEAPON_FREEZER))
        D_801CB14C[3].unk4 = 0;
    if (gUnlockedCheatWeapons & (1<<CHEAT_WEAPON_REVOLVER))
        D_801CB14C[4].unk4 = 0;
    if (gUnlockedCheatWeapons & (1<<CHEAT_WEAPON_CLAW12))
        D_801CB14C[5].unk4 = 0;
    if (gUnlockedCheatWeapons & (1<<CHEAT_WEAPON_3030))
        D_801CB14C[6].unk4 = 0;
    if (gUnlockedCheatWeapons & (1<<CHEAT_WEAPON_SAWEDOFF))
        D_801CB14C[7].unk4 = 0;
    if (gUnlockedCheatWeapons & (1<<CHEAT_WEAPON_VOLTCANNON))
        D_801CB14C[8].unk4 = 0;
    if (gUnlockedCheatWeapons & (1<<CHEAT_WEAPON_GATTLINGGUN))
        D_801CB14C[9].unk4 = 0;
    if (gUnlockedCheatWeapons & (1<<CHEAT_WEAPON_GAMMACANNON))
        D_801CB14C[10].unk4 = 0;
}

/*801C73A0*/
static void func_801C73A0(void)
{
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_801CDB28); i++)
        D_801CDB28[i] = 0;

    D_801CC8BC = 0;
}

/*801CB998*/
static CheatCode gCheatCode[28] = {
    { _unlockSkinEnforcers, 7, { A_BUTTON, L_TRIG, R_TRIG, L_JPAD, B_BUTTON, D_JPAD, U_JPAD, 0, 0, 0, 0 } },
    { _unlockSkinPigs, 5, { B_BUTTON, A_BUTTON, A_BUTTON, R_TRIG, L_TRIG, 0, 0, 0, 0, 0, 0 } },
    { _unlockSkinDukes, 7, { L_TRIG, L_TRIG, U_JPAD, D_JPAD, R_TRIG, B_BUTTON, A_BUTTON, 0, 0, 0, 0 } },
    { _unlockSkinWomen, 6, { B_BUTTON, B_BUTTON, B_BUTTON, R_TRIG, L_JPAD, A_BUTTON, 0, 0, 0, 0, 0 } },
    { _unlockSkinBrothersNukem, 6, { R_JPAD, B_BUTTON, L_JPAD, L_TRIG, A_BUTTON, Z_TRIG, 0, 0, 0, 0, 0 } },
    { _unlockSkinSoldiers, 6, { U_JPAD, D_JPAD, B_BUTTON, A_BUTTON, A_BUTTON, L_JPAD, 0, 0, 0, 0, 0 } },
    { _unlockCheatFirstPerson, 10, { D_JPAD, U_JPAD, L_TRIG, B_BUTTON, Z_TRIG, L_JPAD, U_CBUTTONS, R_CBUTTONS, L_CBUTTONS, Z_TRIG, 0 } },
    { _unlockCheatBigHeadMode, 8, { B_BUTTON, U_JPAD, D_JPAD, D_JPAD, A_BUTTON, Z_TRIG, A_BUTTON, R_JPAD, 0, 0, 0 } },
    { _unlockCheatFlatShading, 7, { D_JPAD, U_JPAD, L_JPAD, L_JPAD, A_BUTTON, R_JPAD, D_JPAD, 0, 0, 0, 0 } },
    { _unlockCheatWeather, 7, { Z_TRIG, A_BUTTON, L_TRIG, B_BUTTON, D_JPAD, U_JPAD, R_TRIG, 0, 0, 0, 0 } },
    { _unlockCheatBigGun, 7, { U_CBUTTONS, L_CBUTTONS, Z_TRIG, B_BUTTON, L_TRIG, Z_TRIG, A_BUTTON, 0, 0, 0, 0 } },
    { _unlockCheatIceSkin, 7, { B_BUTTON, Z_TRIG, U_JPAD, L_TRIG, A_BUTTON, R_CBUTTONS, A_BUTTON, 0, 0, 0, 0 } },
    { _unlockCheatActionNukem, 7, { D_JPAD, D_JPAD, A_BUTTON, Z_TRIG, Z_TRIG, L_JPAD, A_BUTTON, 0, 0, 0, 0 } },
    { _unlockCheatSelectSkin, 8, { L_CBUTTONS, R_TRIG, L_JPAD, U_JPAD, D_JPAD, B_BUTTON, A_BUTTON, Z_TRIG, 0, 0, 0 } },
    { _unlockCheatFastZombies, 7, { A_BUTTON, A_BUTTON, Z_TRIG, A_BUTTON, R_TRIG, D_CBUTTONS, B_BUTTON, 0, 0, 0, 0 } },
    { _unlockCheatWeaponSmg, 6, { L_TRIG, B_BUTTON, B_BUTTON, R_TRIG, Z_TRIG, A_BUTTON, 0, 0, 0, 0, 0 } },
    { _unlockCheatWeaponBlaster, 6, { B_BUTTON, L_JPAD, A_BUTTON, R_TRIG, R_TRIG, B_BUTTON, 0, 0, 0, 0, 0 } },
    { _unlockCheatWeaponSniper, 6, { L_JPAD, R_JPAD, U_JPAD, B_BUTTON, D_JPAD, A_BUTTON, 0, 0, 0, 0, 0 } },
    { _unlockCheatWeaponFreezer, 6, { D_JPAD, U_JPAD, A_BUTTON, L_TRIG, R_TRIG, Z_TRIG, 0, 0, 0, 0, 0 } },
    { _unlockCheatWeaponRevolver, 6, { R_JPAD, A_BUTTON, R_TRIG, Z_TRIG, B_BUTTON, A_BUTTON, 0, 0, 0, 0, 0 } },
    { _unlockCheatWeaponClaw12, 6, { B_BUTTON, Z_TRIG, Z_TRIG, A_BUTTON, Z_TRIG, L_TRIG, 0, 0, 0, 0, 0 } },
    { _unlockCheatWeapon3030, 6, { U_CBUTTONS, D_CBUTTONS, L_CBUTTONS, R_CBUTTONS, L_TRIG, R_TRIG, 0, 0, 0, 0, 0 } },
    { _unlockCheatWeaponSawedOff, 6, { B_BUTTON, A_BUTTON, D_CBUTTONS, Z_TRIG, L_TRIG, L_CBUTTONS, 0, 0, 0, 0, 0 } },
    { _unlockCheatWeaponVoltCannon, 6, { L_TRIG, Z_TRIG, Z_TRIG, A_BUTTON, Z_TRIG, R_TRIG, 0, 0, 0, 0, 0 } },
    { _unlockCheatWeaponGattlingGun, 6, { R_CBUTTONS, R_TRIG, R_JPAD, Z_TRIG, B_BUTTON, A_BUTTON, 0, 0, 0, 0, 0 } },
    { _unlockCheatWeaponGammaCannon, 6, { U_CBUTTONS, D_JPAD, A_BUTTON, A_BUTTON, L_CBUTTONS, R_TRIG, 0, 0, 0, 0, 0 } },
    { _unlockCheatWeaponAll, 10, { D_JPAD, A_BUTTON, U_JPAD, L_TRIG, Z_TRIG, R_TRIG, U_CBUTTONS, D_CBUTTONS, B_BUTTON, L_CBUTTONS, 0 } },
    { _toggleDebugMenu, 10, { U_CBUTTONS, U_JPAD, L_CBUTTONS, R_JPAD, D_CBUTTONS, D_JPAD, R_CBUTTONS, R_TRIG, A_BUTTON, B_BUTTON, 0 } },
};

/*801C73CC*/
static void func_801C73CC(void)
{
    CheatCode *cheat;
    s32 i;

    for (i = 0; i < 16; i++)
    {
        if (!((D_801CC918 >> i) & 1))
        {
            if ((gButton[0] >> i) & 1)
            {
                D_801CC918 = 1 << i;
                D_801CC8BC = 1 << i;
                D_801CF640 = D_801CF640 | (1 << i);
            }
        }
        if (((D_801CC918 >> i) & 1))
        {
            if (!((gButton[0] >> i) & 1))
            {
                D_801CF640 = D_801CF640 & (~(1 << i));
                D_801CC918 = D_801CC918 & (~(1 << i));
            }
        }
    }

    if (D_801CC8BC != 0)
    {
        cheat = gCheatCode;
        for (i = 0; i < ARRAY_COUNT(D_801CDB28); i++, cheat++)
        {
            if (D_801CC8BC == cheat->button_list[D_801CDB28[i]])
            {
                D_801CDB28[i]++;
                if ((D_801CDB28[i]) == cheat->button_count)
                {
                    playSfx(46);
                    gConfig.unk50 = 1;
                    cheat->func();
                    func_801C73A0();
                }
            }
            else
                D_801CDB28[i] = 0;
        }
        D_801CC8BC = 0;
    }
}

/*801C7574*/
static void func_801C7574(void)
{
    D_801CE5D8 = 0x25252525;
    allocMemory(SCREEN_WIDTH, SCREEN_HEIGHT*2, DISPLAY_LIST_SIZE*2, 0);
    setCameraPosition(0.0f, 0.0f, -90.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    func_801C10C8();
    D_800BD3E8 = 1;
    func_8007FD8C(&D_800DFA90[0], 2);
    func_8007FD8C(&D_800DFB08[0], 11);
    D_800BD3F9 = 10;
    main_80002390();
    main_80000610();
    D_801CDB04 = 0;
    D_801CE494 = 0;
}

/*801C764C*/
void func_801C764C(void)
{
    code1UnkStruct2 *ptr;
    s32 i, j, k, l;

    l = D_801CE5F0.unkFD5;
    l = MIN(l, 21);
    func_801C118C();

    if ((D_800FE3FC != 0) && (D_801CDB04 == 0))
    {
        D_800BD3E8 = 1;
        func_8007F050();
        func_801C1114();
        func_801C1158(0, 0, 0, 0xFF);
        D_801CC88C = -1;
        D_801CDB04++;
    }

    switch (D_801CDB04)
    {
    case 0:
        if (controller_8008D354())
        {
            if (D_80138620 != 0)
            {
                func_801C959C();
                D_800BD3E8 = 1;
                func_8007F050();
                if (D_801CE5F0.unkFD5 != 0)
                {
                    D_801CDB04++;
                    main_80000450();
                }
                else
                    main_80000624(func_801C3E08);
            }
            else
            {
                func_8007F050();
                main_80000624(func_801C3E08);
            }
        }
        break;
    case 1:
        D_801CE494++;
        if (D_801CE494 >= 11)
            D_801CDB04 = 2;
        break;
    case 2:
        cache1d_8002AAC0();
        allocMemory(SCREEN_WIDTH, SCREEN_HEIGHT*2, DISPLAY_LIST_SIZE, 0);
        setCameraPosition(0.0f, 0.0f, -90.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
        func_801C10C8();
        D_800BD3E8 = 1;
        func_801C0EDC(0xFFFF);
        edl_80081688(&D_801CDB08, 20);
        edl_80081688(&D_801CC888, 21);
        edl_80081688(&D_801CDBC8, 23);
        edl_80081688(&D_801CDA98, 22);
        D_800E0F58 = 0;

        for (i = 0; i < ARRAY_COUNT(D_01022510); i++)
            func_80083700(1, &D_801CE5E8[i], 0, 0);

        D_800E0F58 = 1;
        func_8007FD8C(&D_800DFB08[0], 11);
        func_8007FD8C(&D_800E047C[0], 14);
#if VERSION_US
        func_800802C0("SELECT LEVEL", gScreenWidth/2, 24, 64, 1);
#elif VERSION_FR
        func_800802C0("CHOISIR NIVEAU", gScreenWidth/2, 24, 64, 1);
#endif
        D_801CA144 = 0.0f;

        if (D_800FE3FC == 0)
            D_801CE5DC = l;
        else
            D_801CE5DC = gLoadMapNum;

        for (i = 0; i < (l + 1); i++)
        {
            D_801CDA28[i] = func_8007FC08(&D_800E047C[i], NULL, 0, (gScreenHeight / 2) - 88, 500);
            k = D_801CE5DC * 256;
            D_801CDA88 = ((D_801CE5DC * 16384) + k) * 2;
            D_801CDA28[i]->unk34 = ((gScreenWidth / 2) - 60 + (i * 130) - (D_801CDA88 >> 8));

            if ((D_801CDA28[i]->unk34 < (gScreenWidth + 80)) && (D_801CDA28[i]->unk34 > -130.0f))
                D_801CDA28[i]->unkC |= 1;
            else
                D_801CDA28[i]->unkC &= ~1;
        }

        D_801CDB20 = 0;
        D_801CA3D4 = gScreenHeight/2 + 100;
        D_801CC8B0 = func_8007FE2C(gMapChapter[D_801CE5DC].mapname, gScreenWidth / 2, D_801CA3D4, 64, 1, 0);
        D_801CA3D4 += 12;
#if VERSION_US
        D_801CF6E0[1] = func_8007FE2C("TIME TAKEN:", 48, D_801CA3D4 + 12, 64, 0, 0);
        D_801CF6E0[2] = func_8007FE2C("KILLS:", 48, D_801CA3D4 + 24, 64, 0, 0);
        D_801CF6E0[3] = func_8007FE2C("BABES:", 48, D_801CA3D4 + 36, 64, 0, 0);
        D_801CF6E0[4] = func_8007FE2C("SECRETS:", 48, D_801CA3D4 + 48, 64, 0, 0);
        D_801CF6E0[6] = func_8007FE2C("TIME MACHINE PARTS:", 48, D_801CA3D4 + 60, 64, 0, 0);
        D_801CF6E0[5] = func_8007FE2C("OVERALL RATING:", 48, D_801CA3D4 + 72, 64, 0, 0);
#elif VERSION_FR
        D_801CF6E0[1] = func_8007FE2C("TEMPS ECOULE:", 48, D_801CA3D4 + 12, 64, 0, 0);
        D_801CF6E0[2] = func_8007FE2C("TUES:", 48, D_801CA3D4 + 24, 64, 0, 0);
        D_801CF6E0[3] = func_8007FE2C("LES GONZESSES:", 48, D_801CA3D4 + 36, 64, 0, 0);
        D_801CF6E0[4] = func_8007FE2C("SECRETS:", 48, D_801CA3D4 + 48, 64, 0, 0);
        D_801CF6E0[6] = func_8007FE2C("MACHINE REMONT. TPS:", 48, D_801CA3D4 + 60, 64, 0, 0);
        D_801CF6E0[5] = func_8007FE2C("TOTAL:", 48, D_801CA3D4 + 72, 64, 0, 0);
#endif

        ptr = &D_801CE5F0.unk4[D_801CE5DC];

        sprintf(D_801CDB58[0], "%d : %02d", (ptr->unk172 / 1800U),
                (ptr->unk172 / 30U) - ((ptr->unk172 / 1800U) * 60));
        D_801CDBD0[0] = func_8007FE2C(D_801CDB58[0], gScreenWidth - 48, D_801CA3D4 + 12, 64, 2, 0);
        sprintf(D_801CDB58[1], "%d / %d", ptr->enemies_killed, ptr->enemies_total);
        D_801CDBD0[1] = func_8007FE2C(D_801CDB58[1], gScreenWidth - 48, D_801CA3D4 + 24, 64, 2, 0);
        sprintf(D_801CDB58[2], "%d / %d", ptr->babes_saved, ptr->babes_total);
        D_801CDBD0[2] = func_8007FE2C(D_801CDB58[2], gScreenWidth - 48, D_801CA3D4 + 36, 64, 2, 0);
        sprintf(D_801CDB58[3], "%d / %d", ptr->secrets_found, ptr->secrets_total);
        D_801CDBD0[3] = func_8007FE2C(D_801CDB58[3], gScreenWidth - 48, D_801CA3D4 + 48, 64, 2, 0);
        sprintf(D_801CDB58[4], "%d%%", ptr->unk182);
        D_801CDBD0[4] = func_8007FE2C(D_801CDB58[4], gScreenWidth - 48, D_801CA3D4 + 72, 64, 2, 0);

        if ((D_801CE5DC == MAP_WETWORLD) || (D_801CE5DC == MAP_BOSS_HOG) ||
            (D_801CE5DC == MAP_CYBORG_SCORPION) || (D_801CE5DC >= MAP_THE_RACK))
        {
#if VERSION_US
            sprintf(D_801CDB58[5], "NONE");
#elif VERSION_FR
            sprintf(D_801CDB58[5], "AUCUN");
#endif
        }
        else if (D_801CE5F0.time_machine_part & (1 << D_801CE5DC))
            sprintf(D_801CDB58[5], "1 / 1");
        else
            sprintf(D_801CDB58[5], "0 / 1");

        D_801CDBD0[5] = func_8007FE2C(D_801CDB58[5], (gScreenWidth - 48), (D_801CA3D4 + 60), 64, 2, 0);

        if ((D_801CE5DC == MAP_WETWORLD) || (D_801CE5DC == MAP_BOSS_HOG) ||
            (D_801CE5DC == MAP_CYBORG_SCORPION) || (D_801CE5DC >= MAP_THE_RACK))
            D_801CDBD0[5]->unkC |= 0x04000000;
        else
            D_801CDBD0[5]->unkC &= ~0x04000000;

        for (i = 0; i < ARRAY_COUNT(D_801CDBD0); i++)
        {
            D_801CF6E0[i+1]->unkC &= ~1;
            D_801CDBD0[i]->unkC &= ~1;
        }

        func_801C1114();
        func_801C1158(0, 0, 0, 0xFF);
        D_801CC88C = -1;
        main_80002390();
        main_80000610();
        D_801CDB04++;
        break;
    case 3:
        if (D_801CDB04 != 3)
            break;

        for (i = 0; i < (l + 1); i++)
        {
            D_801CDA28[i]->unk34 = ((gScreenWidth / 2) - 60 + (i * 130) - (D_801CDA88 >> 8));
            if ((D_801CDA28[i]->unk34 < (gScreenWidth + 80)) && (D_801CDA28[i]->unk34 > -130.0f))
                D_801CDA28[i]->unkC |= 1;
            else
                D_801CDA28[i]->unkC &= ~1;
        }

        j = D_801CE5DC * 256;
        j = ((((D_801CE5DC * 16384) + j) * 2) - D_801CDA88) >> 1;
        D_801CDA88 += j;

        if (!(func_801C0E68() & 0x300))
            j = 0;

        if ((j > -300) && (j < 300))
        {
            for (i = 0; i < (l + 1); i++)
                D_801CDA28[i]->unk10 = 110;

            D_801CDA28[D_801CE5DC]->unk10 = 0xFF;
            D_801CC8B0->unk70 = gMapChapter[D_801CE5DC].mapname;
            ptr = &D_801CE5F0.unk4[D_801CE5DC];
            sprintf(D_801CDB58[0], "%d : %02d", (ptr->unk172 / 1800U),
                                                (ptr->unk172 / 30U) - ((ptr->unk172 / 1800U) * 60));
            sprintf(D_801CDB58[1], "%d / %d", ptr->enemies_killed, ptr->enemies_total);
            sprintf(D_801CDB58[2], "%d / %d", ptr->babes_saved, ptr->babes_total);
            sprintf(D_801CDB58[3], "%d / %d", ptr->secrets_found, ptr->secrets_total);
            sprintf(D_801CDB58[4], "%d%%", ptr->unk182);

            if (D_801CE5DC == D_801CE5F0.unkFD5)
            {
                for (i = 0; i < ARRAY_COUNT(D_801CDBD0); i++)
                {
                    D_801CF6E0[i+1]->unkC &= ~1;
                    D_801CDBD0[i]->unkC &= ~1;
                }
            }
            else
            {
                for (i = 0; i < ARRAY_COUNT(D_801CDBD0); i++)
                {
                    D_801CF6E0[i+1]->unkC |= 1;
                    D_801CDBD0[i]->unkC |= 1;
                }

                if ((D_801CE5DC == MAP_WETWORLD) || (D_801CE5DC == MAP_BOSS_HOG) ||
                    (D_801CE5DC == MAP_CYBORG_SCORPION) || (D_801CE5DC >= MAP_THE_RACK))
                {
#if VERSION_US
                    sprintf(D_801CDB58[5], "NONE");
#elif VERSION_FR
                    sprintf(D_801CDB58[5], "AUCUN");
#endif
                    D_801CDBD0[5]->unkC |= 0x04000000;
                }
                else if (D_801CE5F0.time_machine_part & (1 << D_801CE5DC))
                {
                    sprintf(D_801CDB58[5], "1 / 1");
                    D_801CDBD0[5]->unkC &= ~0x04000000;
                }
                else
                {
                    sprintf(D_801CDB58[5], "0 / 1");
                    D_801CDBD0[5]->unkC &= ~0x04000000;
                }
            }
            D_801CDB20 = 0;
        }
        if (D_801CDB20 == 0)
        {
            if (func_801C0E68() & 0x200)
            {
                if (D_801CE5DC != MAP_MEAN_STREETS)
                {
                    playSfx(746);
                    D_801CE5DC--;

                    if ((D_801CE5DC == MAP_WETWORLD) && (D_801CE5F0.unkFD6 == 0))
                        D_801CE5DC--;

                    if ((D_801CE5DC == MAP_GOING_DOWN_THE_RACK) && (D_801CE5F0.unkFD7 == 0))
                        D_801CE5DC = MAP_THE_RACK;
                }
                D_801CDB20 = 1;
            }
            if (func_801C0E68() & 0x100)
            {
                if (D_801CE5DC != l)
                {
                    playSfx(746);
                    D_801CE5DC++;

                    if ((D_801CE5DC == MAP_WETWORLD) && (D_801CE5F0.unkFD6 == 0))
                        D_801CE5DC++;

                    if ((D_801CE5DC == MAP_GOING_DOWN_THE_RACK) && (D_801CE5F0.unkFD7 == 0))
                        D_801CE5DC = MAP_BRAINSTORM;
                }
                D_801CDB20 = 1;
            }
        }
        if (func_801C0E68() & 0x8000)
        {
            playSfx(747);
            func_801C0EDC(0x8000);
            gMapNum = gLoadMapNum = D_801CE5DC;

            if (D_801CE5DC != l)
                D_800FE3FC = 1;
            else
                D_800FE3FC = 0;

            D_801A1994 = 0;
            D_801CDC64.unk0 = 0;
            D_801CDC64.unk1 = 1;
            gLoadMapNum = gMapNum;

            if (gConfig.rumblepak == 0)
                main_80000624(main_80001F40);
            else
            {
                func_801C30EC();
                D_801CDAC8 = 0;
            }
        }
        if (func_801C0E68() & 0x4000)
        {
            playSfx(748);
            func_801C0EDC(0x4000);
            func_8007F050();
            main_80000624(func_801C3E08);
        }
        break;
    }
}

/*801C8650*/
static void func_801C8650(void)
{
    s32 i;

    D_801CE5D8 = 0x25252525;
    allocMemory(SCREEN_WIDTH, SCREEN_HEIGHT*2, DISPLAY_LIST_SIZE*2, 0);
    setCameraPosition(0.0f, 0.0f, -90.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    func_801C10C8();
    D_800BD3E8 = 1;

    for (i = 0; gMapChapter[i].chapter != DUKEMATCH; i++);

    _pDukematchMapChapter = &gMapChapter[i];
    func_8007F050();
    setCameraPosition(0.0f, 0.0f, -90.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    func_8007FD8C(&D_800E064C[0], 15);
    func_8007FD8C(&D_800DFB08[0], 11);
    edl_80081688(&D_801CDB08, 20);
    edl_80081688(&D_801CC888, 21);
    edl_80081688(&D_801CDBC8, 23);
    edl_80081688(&D_801CDA98, 22);
    func_801C1114();
    func_801C1158(0, 0, 0, 0xFF);
    D_801CC88C = -1;
    D_800E0F58 = 0;

    for (i = 0; i < ARRAY_COUNT(D_01022510); i++)
        func_80083700(1, &D_801CE5E8[i], 0, 0);

    D_800E0F58 = 1;
#if VERSION_US
    func_800802C0("SELECT LEVEL", (gScreenWidth / 2), 24, 64, 1);
#elif VERSION_FR
    func_800802C0("CHOISIR NIVEAU", (gScreenWidth / 2), 24, 64, 1);
#endif
    D_801CA144 = 0.0f;

    for (i = 0; i < ARRAY_COUNT(D_800E064C)-1; i++)
    {
        D_801CDA28[i] = func_8007FC08(&D_800E064C[i], NULL, (gScreenWidth / 2) - 60 + (i * 130), (gScreenHeight / 2) - 88, 500);
        D_801CDA28[i]->unkC &= ~1;
    }

    D_800BD3F9 = 11;
    main_80002390();
    main_80000610();
    D_801CE5DC = MAP_MEAN_STREETS;
    D_801CDA88 = 0;
    D_801CDB20 = 0;
    D_801CC8B0 = func_8007FE2C(_pDukematchMapChapter->mapname, gScreenWidth / 2, (gScreenHeight / 2) + 100, 64, 1, 0);
    D_8010554C = 1;
}

/*801C899C*/
void func_801C899C(void)
{
    s32 i, j;
    s64 prev;

    func_801C118C();

    for (i = 0; i < 14; i++)
    {
        D_801CDA28[i]->unk34 = ((gScreenWidth / 2) - 60 + (i * 130) - (D_801CDA88 >> 8));
        if ((D_801CDA28[i]->unk34 < (gScreenWidth + 80)) && (D_801CDA28[i]->unk34 > -130.0f))
            D_801CDA28[i]->unkC |= 1;
        else
            D_801CDA28[i]->unkC &= ~1;
    }

    j = D_801CE5DC * 256;
    j = ((((D_801CE5DC * 16384) + j) * 2) - D_801CDA88) >> 1;
    D_801CDA88 += j;

    if (!(func_801C0E68() & 0x300))
        j = 0;

    if ((j > -300) && (j < 300))
    {

        for (i = 0; i < 14; i++)
            D_801CDA28[i]->unk10 = 110;

        D_801CDA28[D_801CE5DC]->unk10 = 0xFF;
        D_801CDB20 = 0;
        D_801CC8B0->unk70 = _pDukematchMapChapter[D_801CE5DC].mapname;
    }

    if (D_801CDB20 == 0)
    {
        if (func_801C0E68() & 0x200)
        {
            if (D_801CE5DC != MAP_MEAN_STREETS)
            {
                playSfx(746);
                D_801CE5DC--;
            }
            D_801CDB20 = 1;
        }
        if (func_801C0E68() & 0x100)
        {
            if (D_801CE5DC != MAP_THE_WHITECHAPEL_KILLINGS)
            {
                playSfx(746);
                D_801CE5DC++;
            }
            D_801CDB20 = 1;
        }
    }
    if (func_801C0E68() & 0x8000)
    {
        func_801C0EDC(0x8000);
        playSfx(747);
        for (gLoadMapNum = 0; gMapChapter[gLoadMapNum].chapter != DUKEMATCH; gLoadMapNum++);
        gLoadMapNum += D_801CE5DC;
        if (gConfig.rumblepak == 0)
        {
            func_801C3608();
            return;
        }
        func_801C30EC();
        D_801CDAC8 = 1;
    }

    if (func_801C0E68() & 0x4000)
    {
        playSfx(748);
        func_801C0EDC(0x4000);

#ifdef TARGET_N64
        prev = D_800FE9E0;
        while (prev == D_800FE9E0);
#else
        (void)prev;
#endif

        func_8007F050();
        cache1d_8002AAEC();
        func_801C3AD8();
        func_801C2F1C();
        D_801CDAA0[D_801CD980++] = &D_801CB528;
        D_801CDAA0[D_801CD980++] = &D_801CB13C;
        D_801CDAA0[D_801CD980++] = &D_801CB03C;
        func_801C2BE8(&D_801CAF30);
        func_801C3A88(*D_801CE5A8->unkC);
    }
}

/*801CBCA8*/
static char *D_801CBCA8[16] = {
#if VERSION_US
    "TURN LEFT",
    "TURN RIGHT",
    "MOVE FORWARD",
    "MOVE BACK",
    "MOVE LEFT",
    "MOVE RIGHT",
    "LOOK UP",
    "LOOK DOWN",
    "JUMP",
    "FIRE",
    "OPEN",
    "NEXT WEAPON",
    "LAST WEAPON",
    "NEXT ITEM",
    "PREVIOUS ITEM",
    "ACTIVATE ITEM",
#elif VERSION_FR
    "TOURNER A GAUCHE",
    "TOURNER A DROITE",
    "AVANCER",
    "RECULER",
    "DEPLACEMENT A GAUCHE",
    "DEPLACEMENT A DROITE",
    "REGARDER EN HAUT",
    "REGARDER EN BAS",
    "SAUTER",
    "TIRER",
    "OUVRIR",
    "ARME SUIVANTE",
    "DERNIERE ARME",
    "PROCAIN OBJET",
    "ARTICLE PRECENDENT",
    "UTILISER UN ARTICLE",
#endif
};

/*801C8DE0*/
static void _menuControllerConfig(void)
{
    s32 i, j;

    _menuEnter();
    j = -110;
    for (i = 0; i < ARRAY_COUNT(D_801CE558); i++)
    {
        D_801CE558[i] = func_8007FE2C(D_801CBCA8[i], (gScreenWidth / 2) - 136,
                                      (gScreenHeight / 2) + (j + (i * 14)), 64, 0, 0);
        D_801CE558[i]->unk10 = 0;
    }
    j = -110;
    for (i = 0; i < ARRAY_COUNT(D_801CC8D0); i++)
    {
        D_801CC8D0[i] = func_8007FE2C(gpControlPreset[gConfig.controller_preset[D_801CDACC]].mapping[i],
                                      (gScreenWidth / 2) + 136, (gScreenHeight / 2) + (j + (i * 14)), 64, 2, 0);
        D_801CC8D0[i]->unk10 = 0;
    }
    D_800BD3F9 = 12;
}

/*801C8F54*/
void func_801C8F54(void)
{
    s32 i;

    func_801C4B34();
    if (D_801CC8C0 == -1)
    {
        for (i = 0; i < ARRAY_COUNT(D_801CC8D0); i++)
        {
            if (D_801CC8D0[i] != NULL)
            {
                if (D_801CC8D0[i]->unk10 > 48)
                    D_801CC8D0[i]->unk10 -= 32;
                else
                {
                    func_8007ECC8(D_801CC8D0[i]);
                    D_801CC8D0[i] = NULL;
                }
            }
            if (D_801CE558[i] != NULL)
            {
                if (D_801CE558[i]->unk10 > 48)
                    D_801CE558[i]->unk10 -= 32;
                else
                {
                    func_8007ECC8(D_801CE558[i]);
                    D_801CE558[i] = NULL;
                }
            }
        }
    }
    else
    {
        for (i = 0; i < ARRAY_COUNT(D_801CC8D0); i++)
        {
            if (D_801CC8D0[i] != NULL)
            {
                if (D_801CC8D0[i]->unk10 < 207)
                    D_801CC8D0[i]->unk10 += 32;
                else
                    D_801CC8D0[i]->unk10 = 0xFF;

                D_801CC8D0[i]->unk70 = gpControlPreset[gConfig.controller_preset[D_801CDACC]].mapping[i];
            }
            if (D_801CE558[i] != NULL)
            {
                if (D_801CE558[i]->unk10 < 207)
                    D_801CE558[i]->unk10 += 32;
                else
                    D_801CE558[i]->unk10 = 0xFF;
            }
        }
    }
}

/*801C90E4*/
static void func_801C90E4(void)
{
    code1UnkStruct3 *ptr;
    code1UnkStruct2 *ptr2;
    s16 ret;
    s32 i;

    ptr = &D_801CE5F0;
    ptr->unk103A = 1;
    ptr->unk2 = 31;
    ptr->unkFE8 = gConfig;

    ret = func_801C53E8(gMapNum);
    if (ptr->unkFD5 < ret)
        ptr->unkFD5 = ret;

    if (ret == 3)
        ptr->unkFD6 = 1;

    if (ret == 17)
        ptr->unkFD7 = 1;

    ptr2 = &ptr->unk4[gMapNum];
    if (D_800FE3FC == 0)
    {
        ptr2->unk182 = D_801A1958.unk10;
        ptr2->unk172 = D_801A1958.unkC;
        ptr2->babes_saved = D_801A1958.babes_saved;
        ptr2->secrets_found = D_801A1958.secrets_found;
        ptr2->enemies_killed = D_801A1958.enemies_killed;
        ptr2->enemies_total = D_801A1958.enemies_total;
        ptr2->babes_total = D_801A1958.babes_total;
        ptr2->secrets_total = D_801A1958.secrets_total;
        ptr2->unk0 = gPlayer[0].unk46;
        ptr2->unk2 = gPlayer[0].unk70;

        for (i = 0; i < ARRAY_COUNT(D_8011A680[0]); i++)
        {
            ptr2->unk4[i][0] = D_8011A680[0][i][0];
            ptr2->unk4[i][1] = D_8011A680[0][i][1];
            ptr2->unk4[i][2] = D_8011A680[0][i][7];
        }

        for (i = 0; i < ARRAY_COUNT(D_8010A940[0].unkA); i++)
            ptr2->unk148[i] = D_8010A940[0].unkA[i];
    }

    ptr->unlocked_skin = gUnlockedSkin;
    ptr->unlocked_cheat = gUnlockedCheat;
    ptr->unlocked_cheat_weapons = gUnlockedCheatWeapons;
    ptr->time_machine_part = gTimeMachinePart;
}

/*801C936C*/
void func_801C936C(void)
{
    code1UnkStruct2 *ptr;
    code1UnkStruct3 *ptr2;
    s32 i;

    i = 1;
    ptr2 = &D_801CE5F0;
    if (gMapNum)
    {
        if (gMapNum == MAP_FALLOUT)
            i += (ptr2->unkFD6 == 0);

        if (gMapNum == MAP_BRAINSTORM)
            i += ptr2->unkFD7 == 0;

        ptr = &ptr2->unk4[gMapNum - i];
        gPlayer[0].unk46 = ptr->unk0;
        gPlayer[0].unk70 = ptr->unk2;

        for (i = 0; i < ARRAY_COUNT(D_8011A680[0]); i++)
        {
            D_8011A680[0][i][0] = ptr->unk4[i][0];
            D_8011A680[0][i][1] = ptr->unk4[i][1];
            D_8011A680[0][i][7] = ptr->unk4[i][2];
        }

        D_8010A940[0].unk0 = 0;
        for (i = 0; i < ARRAY_COUNT(D_8010A940[0].unk2); i++)
        {
            D_8010A940[0].unk2[i] = 0;
            D_8010A940[0].unkA[i] = ptr->unk148[i];
        }
    }
}

/*801C948C*/
static void func_801C948C(void)
{
    code1UnkStruct3 *ptr;
    ptr = &D_801CE5F0;
    ptr->unk2 = 31;
    ptr->unkFE8 = gConfig;
    D_801CC930.unk0 = *ptr;
}

/*801C959C*/
static void func_801C959C(void)
{
    code1UnkStruct3 *ptr;
    code1UnkStruct3 *ptr2;

    ptr2 = &D_801CC930.unk0;
    ptr = &D_801CE5F0;

    if (ptr2->unk2 == 31)
        gConfig = ptr2->unkFE8;

    *ptr = *ptr2;

    setVolume((gConfig.musicvol * 100) / 7, (gConfig.mastervol * 100) / 7);
    gUnlockedSkin |= ptr->unlocked_skin;
    gUnlockedCheat |= ptr->unlocked_cheat;
    gUnlockedCheatWeapons |= ptr->unlocked_cheat_weapons;
    gTimeMachinePart = ptr->time_machine_part;
}

/*801C97A8*/
static void _menuLoadGame(void)
{
    *D_801CE5A8->unkC = D_801CE5A0;
    D_800FE3FC = 0;
    cache1d_8002AAC0();
    func_801C7574();
}

/*801C97F0*/
void func_801C97F0(void)
{
}

/*801C97F8*/
void func_801C97F8(void)
{
    s32 i;

    cache1d_8002AAC0();
    allocMemory(SCREEN_WIDTH, SCREEN_HEIGHT*2, DISPLAY_LIST_SIZE*2, 0);
    func_801C10C8();
    D_800BD3E8 = 1;
    func_801C0EDC(0xD000);
    func_8007FD8C(&D_800DFB08[0], 11);
    func_8007FD8C(&D_800E07DC[0], 28);
    func_8007F050();
    D_801CDA20 = func_8007FC08(&D_800E07DC[0], NULL, 0, 0, 500);
    main_80002390();
    main_80000610();
    func_801C1114();
    func_801C1158(0, 0, 0, 0xFF);

    D_801CC88C = -1;
    for (i = 0; i < ARRAY_COUNT(D_801CC800); i++)
        D_801CC800[i] = 0;

    D_801CD970 = 0;
    D_801CE474 = 0;
    D_801CE488 = 0;
    D_801CF63C = 0;
    playMusic(2);
    D_800BD3F9 = 14;
}

/*801C9924*/
void func_801C9924(void)
{
    s32 i;

    func_801C118C();
    if ((D_801CF63C != 0) && (D_801CC88C == 0))
    {
        main_80000624(func_801C3E08);
        return;
    }

    if (D_801CE488 >= 15)
    {
        D_801CE488 = 0;
        if (D_801CC800[D_801CD970] != NULL)
        {
            D_801CC800[D_801CD970]->unk38 = 484.0f;
            D_801CC800[D_801CD970]->unk70 = gpCreditStrInfo[D_801CE474];
        }
        else
            D_801CC800[D_801CD970] = func_8007FE2C(gpCreditStrInfo[D_801CE474],
                                                   gScreenWidth / 2, 484, 64, 1, 0);

        D_801CD970++;
        if (D_801CD970 == ARRAY_COUNT(D_801CC800)-1)
            D_801CD970 = 0;

        D_801CE474++;
        if (gpCreditStrInfo[D_801CE474] == NULL)
        {
            D_801CC88C = 1;
            D_801CF63C = 1;
        }
    }
    for (i = 0; i < ARRAY_COUNT(D_801CC800)-1; i++)
    {
        if (D_801CC800[i] != NULL)
            D_801CC800[i]->unk38 -= 1.0f;
    }
    D_801CE488++;
}

/*801C9B08*/
static void func_801C9B08(void)
{
    main_80001F40();
}

/*801C9B28*/
void func_801C9B28(void)
{
    func_801C509C();
}

/*801CBCE8*/
static u8 *D_801CBCE8[12] = {
    files_1003A60_ROM_START,
    files_1004260_ROM_START,
    files_1004A60_ROM_START,
    files_1005260_ROM_START,
    files_1005A60_ROM_START,
    files_1006260_ROM_START,
    files_1006A60_ROM_START,
    files_1007260_ROM_START,
    files_1007A60_ROM_START,
    files_1008260_ROM_START,
    files_1008A60_ROM_START,
    files_1009260_ROM_START,
};

/*801CBD18*/ static u32 D_801CBD18 = 0;

/*801C9B48*/
void func_801C9B48(void)
{
    s32 i;

    D_801CDC68 = D_801CDC70;
    i = D_801CBD18 % 5;
    readRom((u8 *)D_801CDC70, D_801CBCE8[i], 2048);
    D_801CDB0C = 0;
    D_8012FC90 = 1;
    gRandomSeed = 0;
    D_801CBD18++;
    gLoadMapNum = *D_801CDC68++;
    gNotPlayback = FALSE;
}

/*801C9C18*/
static void func_801C9C18(void)
{
    u8 i;

    i = *D_801CDC68;
    if ((i == 0) || (gPlayer[0].unk45 != 0))
    {
        func_8008E01C(30, 5);
        D_8012FC90 = 0;
        return;
    }

    switch (i & 3)
    {
    case 2:
        D_801CDC68++;
        gStickX[0] = *D_801CDC68++;
        gStickY[0] = *D_801CDC68++;
        break;
    case 3:
        D_801CDC68++;
        gButton[0] = *D_801CDC68++ << 8;
        gButton[0] += *D_801CDC68++;
        gButton[0] &= ~START_BUTTON;
        i = *D_801CDC68;
        if ((i & 3) == 2)
        {
            D_801CDC68++;
            gStickX[0] = *D_801CDC68++;
            gStickY[0] = *D_801CDC68++;
        }
        break;
    }
}

#ifdef NON_MATCHING
/*801C9D68*/
void func_801C9D68(void)
{
    s32 i, j;
    u8 k, l, m;
    s8 **ptr;

    for (i = 0; i < D_801CC8CA; i++)
    {
        if (gController[i].button & START_BUTTON)
        {
            func_8008E01C(30, 0);
            D_8012FC90 = 0;
            return;
        }
    }

    l = *D_801CDC68;
    if ((l == 0) || (gPlayer[0].unk45 != 0))
    {
        func_8008E01C(30, 5);
        D_8012FC90 = 0;
    }
    else
    {
        k = *D_801CDC68;
        m = D_801CDC68[1];
        if ((k&3) < 2)
        {
            do { j = k >> 2; } while (0); /*FAKE*/

            if ((k&3) != 0)
                j += (m << 6);

            if (D_801CDB0C < j)
            {
                D_801CDB0C++;
                return;
            }

            D_801CDB0C = 0;
            k = (k&3) + 1;
            ptr = &D_801CDC68;
            D_801CDC68 = &(*ptr)[k];
        }
        func_801C9C18();
    }
}
#else
/*801C9D68*/
INCLUDE_ASM("src/code1/EB300", func_801C9D68);
#endif

/*801C9E7C*/
void func_801C9E7C(void)
{
    D_801CDB4C = 1;
    D_801CDC68 = D_801CDC70;
    D_801CF708 = 0;
    D_801CF710 = 0;
    D_801CD97C = 0;
    D_801CDB0C = 0;
    gRandomSeed = 0;
    D_801CDC68 = &D_801CDC70[1];
    D_801CDC70[0] = gLoadMapNum;
}

/*801C9EDC*/
static void func_801C9EDC(void)
{
    if (D_801CDB0C != 0)
    {
        if (D_801CDB0C < 64)
        {
            *D_801CDC68++ = (D_801CDB0C & 0x3F) * 4;
        }
        else
        {
            *D_801CDC68++ = ((D_801CDB0C & 0x3F) * 4) + 1;
            *D_801CDC68++ = D_801CDB0C >> 6;
        }
        D_801CDB0C = 0;
    }
}

/*801C9F74*/
void func_801C9F74(void)
{
    s32 cond;

    if ((&D_801CDC70[sizeof(D_801CDC70)-8]) < D_801CDC68)
    {
        main_80003940();
        return;
    }
    cond = 0;

    if (D_801CF708 != gButton[0])
    {
        D_801CF708 = gButton[0];
        func_801C9EDC();
        *D_801CDC68++ = 3;
        *D_801CDC68++ = gButton[0] >> 8;
        *D_801CDC68++ = gButton[0];
        cond = 1;
    }

    if ((D_801CF710 != gStickX[0]) || (D_801CD97C != gStickY[0]))
    {
        D_801CF710 = gStickX[0];
        D_801CD97C = gStickY[0];
        func_801C9EDC();
        *D_801CDC68++ = 2;
        *D_801CDC68++ = gStickX[0];
        *D_801CDC68++ = gStickY[0];
        cond = 1;
    }

    if (cond == 0)
        D_801CDB0C++;
}
