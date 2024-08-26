#include "common.h"
#include "code0/main.h"
#include "code0/4590.h"
#include "code0/9410.h"
#include "code0/audio.h"
#include "code0/cache1d.h"
#include "code0/1A7C0.h"
#include "code0/416A0.h"
#include "code0/41940.h"
#include "code0/8E670.h"
#include "code0/95500.h"
#include "code0/code0.h"
#include "code1/EB300.h"
#include "code1/code1.h"

/*.data*/
/*800DF950*/ s16 gLoadMapNum = 0;
/*800DF952*/ static s16 _musicnum = 0;
/*800DF954*/ static u8 D_800DF954 = 0;
/*800DF956*/ static s16 _sfxnum = 1;
/*800DF958*/ static u32 D_800DF958 = 0;

/*800DF95C*/
static char *D_800DF95C[11] = {
    "0",
    "PRESENT DAY",
    "WESTERN",
    "VICTORIAN",
    "FINAL",
    "DUKEMATCH",
    "6",
    "7",
    "8",
    "9",
    "TRAINING",
};

/*800DF988*/ static u8 D_800DF988 = 9;
/*800DF989*/ static u8 D_800DF989 = 0;
/*800DF98A*/ static u8 D_800DF98A = 0;
static u8 _unused1 = 0;
/*800DF98C*/ u8 D_800DF98C = 1;
static u8 _unused2 = 0;
static u8 _unused3 = 2;
static u8 _unused4 = 188;
/*800DF990*/ u8 D_800DF990 = 0;

/*.comm*/
/*801B0814*/ u8 D_801B0814;

/*.text*/

/*8007BFC0*/
void debugMenu(void)
{
#ifdef AVOID_UB
    char buffer[64];
#else
    char buffer[16];
#endif
    AlphaPalette *ptr;
    code0unkStruct12 *ptr2;
    u8 i;
    u32 j;

    if (D_8012C470 == 4)
        return;

    if ((D_800DF990 == 0) && (D_801CC7F4 == 0))
        return;

    D_801B0814 = CLAMP_MAX(D_8012C470, 3);
    if (gButton[D_801B0814] & START_BUTTON)
    {
        if (D_800DF989 == 0)
        {
            D_800DF989 = 1;
            D_800DF988++;
        }
    }
    else
    {
        D_800DF989 = 0;
    }

    if (D_801CC7F4 == 0)
    {
        D_800DF988 &= 0xF;
    }
    else
    {
        if (D_800DF988 == 9)
            D_800DF988 = 0;

        if (D_800DF988 != 0xFF)
        {
            D_800DF988 %= 6;
            if (D_800DF988 == 5)
                D_800DF988 = 0xFF;
        }
    }
    switch (D_800DF988)
    {
    case 0:
        if (gButton[D_801B0814] & A_BUTTON)
            gFog[0].color[0].r = CLAMP_MAX(gFog[0].color[0].r+1, 255);
        if (gButton[D_801B0814] & D_CBUTTONS)
            gFog[0].color[0].g = CLAMP_MAX(gFog[0].color[0].g+1, 255);
        if (gButton[D_801B0814] & R_CBUTTONS)
            gFog[0].color[0].b = CLAMP_MAX(gFog[0].color[0].b+1, 255);
        if (gButton[D_801B0814] & B_BUTTON)
            gFog[0].color[0].r = CLAMP_MIN(gFog[0].color[0].r-1, 0);
        if (gButton[D_801B0814] & L_CBUTTONS)
            gFog[0].color[0].g = CLAMP_MIN(gFog[0].color[0].g-1, 0);
        if (gButton[D_801B0814] & U_CBUTTONS)
            gFog[0].color[0].b = CLAMP_MIN(gFog[0].color[0].b-1, 0);
        if (gButton[D_801B0814] & R_TRIG)
            gFog[0].scale[0].fr = CLAMP_MAX(gFog[0].scale[0].fr+1, 3000);
        if (gButton[D_801B0814] & R_JPAD)
            gFog[0].scale[0].nr = CLAMP_MAX(gFog[0].scale[0].nr+1, 3000);
        if (gButton[D_801B0814] & L_TRIG)
            gFog[0].scale[0].fr = CLAMP_MIN(gFog[0].scale[0].fr-1, 0);
        if (gButton[D_801B0814] & L_JPAD)
            gFog[0].scale[0].nr = CLAMP_MIN(gFog[0].scale[0].nr-1, 0);

        gFog[0].scale[0].fr = MAX(gFog[0].scale[0].fr, gFog[0].scale[0].nr+3);
        gFog[0].scale[1].nr = gFog[0].scale[0].nr;
        gFog[0].scale[1].fr = gFog[0].scale[0].fr;
        gFog[0].unk1E = 0;
        gFog[0].color[1].r = gFog[0].color[0].r;
        gFog[0].color[1].g = gFog[0].color[0].g;
        gFog[0].color[1].b = gFog[0].color[0].b;

        displayDebug(25, 20, "FOG");
        sprintf(buffer, "R %d", gFog[0].color[0].r);
        displayDebug(25, 30, buffer);
        sprintf(buffer, "G %d", gFog[0].color[0].g);
        displayDebug(25, 40, buffer);
        sprintf(buffer, "B %d", gFog[0].color[0].b);
        displayDebug(25, 50, buffer);
        sprintf(buffer, "NR %d", gFog[0].scale[0].nr);
        displayDebug(25, 60, buffer);
        sprintf(buffer, "FR %d", gFog[0].scale[0].fr);
        displayDebug(25, 70, buffer);
        break;
    case 1:
        if (gButton[D_801B0814] & A_BUTTON)
            gSkyTopR = CLAMP_MAX(gSkyTopR+1, 255);
        if (gButton[D_801B0814] & D_CBUTTONS)
            gSkyTopG = CLAMP_MAX(gSkyTopG+1, 255);
        if (gButton[D_801B0814] & R_CBUTTONS)
            gSkyTopB = CLAMP_MAX(gSkyTopB+1, 255);
        if (gButton[D_801B0814] & B_BUTTON)
            gSkyTopR = CLAMP_MIN(gSkyTopR-1, 0);
        if (gButton[D_801B0814] & L_CBUTTONS)
            gSkyTopG = CLAMP_MIN(gSkyTopG-1, 0);
        if (gButton[D_801B0814] & U_CBUTTONS)
            gSkyTopB = CLAMP_MIN(gSkyTopB-1, 0);

        displayDebug(25, 20, "SKY TOP");
        sprintf(buffer, "R %d", gSkyTopR);
        displayDebug(25, 30, buffer);
        sprintf(buffer, "G %d", gSkyTopG);
        displayDebug(25, 40, buffer);
        sprintf(buffer, "B %d", gSkyTopB);
        displayDebug(25, 50, buffer);
        break;
    case 2:
        if (gButton[D_801B0814] & A_BUTTON)
            gSkyBottomR = CLAMP_MAX(gSkyBottomR+1, 255);
        if (gButton[D_801B0814] & D_CBUTTONS)
            gSkyBottomG = CLAMP_MAX(gSkyBottomG+1, 255);
        if (gButton[D_801B0814] & R_CBUTTONS)
            gSkyBottomB = CLAMP_MAX(gSkyBottomB+1, 255);
        if (gButton[D_801B0814] & B_BUTTON)
            gSkyBottomR = CLAMP_MIN(gSkyBottomR-1, 0);
        if (gButton[D_801B0814] & L_CBUTTONS)
            gSkyBottomG = CLAMP_MIN(gSkyBottomG-1, 0);
        if (gButton[D_801B0814] & U_CBUTTONS)
            gSkyBottomB = CLAMP_MIN(gSkyBottomB-1, 0);

        displayDebug(25, 20, "SKY BOTTOM");
        sprintf(buffer, "R %d", gSkyBottomR);
        displayDebug(25, 30, buffer);
        sprintf(buffer, "G %d", gSkyBottomG);
        displayDebug(25, 40, buffer);
        sprintf(buffer, "B %d", gSkyBottomB);
        displayDebug(25, 50, buffer);
        break;
    case 3:
    case 4:
        i = D_800DF988 - 3;
        ptr2 = &D_8012FC48[i];
        if (gButton[D_801B0814] & A_BUTTON)
            ptr2->fog.r = CLAMP_MAX(ptr2->fog.r+1, 255);
        if (gButton[D_801B0814] & D_CBUTTONS)
            ptr2->fog.g = CLAMP_MAX(ptr2->fog.g+1, 255);
        if (gButton[D_801B0814] & R_CBUTTONS)
            ptr2->fog.b = CLAMP_MAX(ptr2->fog.b+1, 255);
        if (gButton[D_801B0814] & B_BUTTON)
            ptr2->fog.r = CLAMP_MIN(ptr2->fog.r-1, 0);
        if (gButton[D_801B0814] & L_CBUTTONS)
            ptr2->fog.g = CLAMP_MIN(ptr2->fog.g-1, 0);
        if (gButton[D_801B0814] & U_CBUTTONS)
            ptr2->fog.b = CLAMP_MIN(ptr2->fog.b-1, 0);
        if (gButton[D_801B0814] & R_TRIG)
            ptr2->unk1C += 300;
        if (gButton[D_801B0814] & L_TRIG)
            ptr2->unk1C -= 300;
        if (gButton[D_801B0814] & R_JPAD)
            D_800FE9C8[i] = CLAMP_MAX(D_800FE9C8[i]+1, 1023);
        if (gButton[D_801B0814] & L_JPAD)
            D_800FE9C8[i] = CLAMP_MIN(D_800FE9C8[i]-1, 0);
        if (gButton[D_801B0814] & U_JPAD)
            D_801AE904[i] = (D_801AE904[i]+4) & 0x7FF;
        if (gButton[D_801B0814] & D_JPAD)
            D_801AE904[i] = (D_801AE904[i]-4) & 0x7FF;

        ptr2->unk8 = (-cosf((D_801AE904[i] * (PI/1024))) * D_800FE9C8[i]) / 50.0f;
        ptr2->unkC = (-sinf((D_801AE904[i] * (PI/1024))) * D_800FE9C8[i]) / 50.0f;

        sprintf(buffer, "CLOUDS %d", i + 1);
        displayDebug(25, 20, buffer);
        sprintf(buffer, "R %d", ptr2->fog.r);
        displayDebug(25, 30, buffer);
        sprintf(buffer, "G %d", ptr2->fog.g);
        displayDebug(25, 40, buffer);
        sprintf(buffer, "B %d", ptr2->fog.b);
        displayDebug(25, 50, buffer);
        sprintf(buffer, "HT %d", ptr2->unk1C / 10);
        displayDebug(25, 60, buffer);
        sprintf(buffer, "AN %d", D_801AE904[i]);
        displayDebug(25, 70, buffer);
        sprintf(buffer, "SP %d", D_800FE9C8[i]);
        displayDebug(25, 80, buffer);
        break;
    case 5:
        displayDebug(25, 20, "PLAYER");
        sprintf(buffer, "XV %d", gPlayer[0].unkC);
        displayDebug(25, 30, buffer);
        sprintf(buffer, "YV %d", gPlayer[0].unk10);
        displayDebug(25, 40, buffer);
        sprintf(buffer, "ZV %d", gPlayer[0].unk14);
        displayDebug(25, 50, buffer);
        sprintf(buffer, "OF %d", gPlayer[0].unk59);
        displayDebug(25, 60, buffer);
        sprintf(buffer, "OW %d", gPlayer[0].unk56);
        displayDebug(25, 70, buffer);
        sprintf(buffer, "JF %d", gPlayer[0].unk44);
        displayDebug(25, 80, buffer);
        sprintf(buffer, "DN %d", gPlayer[0].unk4C);
        displayDebug(25, 90, buffer);

        if (D_800DF98A == 0)
        {
            if (gButton[D_801B0814] & L_TRIG)
            {
                gPlayer[0].unk4C--;
                if (gPlayer[0].unk4C < 0)
                    gPlayer[0].unk4C = D_80138780 - 1;
                D_800DF98A = 1;
                gpSprite[gPlayer[0].unk4A].picnum = D_8012F6E4[gPlayer[0].unk4C].picnum;
            }
            if (gButton[D_801B0814] & R_TRIG)
            {
                gPlayer[0].unk4C++;
                if (gPlayer[0].unk4C >= D_80138780)
                    gPlayer[0].unk4C = 0;
                D_800DF98A = 1;
                gpSprite[gPlayer[0].unk4A].picnum = D_8012F6E4[gPlayer[0].unk4C].picnum;
            }
        }
        else if ((gButton[D_801B0814] & (L_TRIG|R_TRIG)) == 0)
        {
            D_800DF98A = 0;
        }

        break;
    case 6:
        displayDebug(25, 20, "GFX");
        sprintf(buffer, "GLIST %d - %d", gDisplayListSize, gDisplayListMaxSize);
        displayDebug(25, 30, buffer);
        sprintf(buffer, "VLIST %d - %d", gVertexN64Size, gVertexN64MaxSize);
        displayDebug(25, 40, buffer);
        sprintf(buffer, "GFX TIME %d", gGfxTime);
        displayDebug(25, 50, buffer);
        j = func_80040C08(3);
        sprintf(buffer, "DRAW TIME %d", j);
        displayDebug(25, 60, buffer);
        j = func_80040C08(1);
        sprintf(buffer, "MOVE1 TIME %d", j);
        displayDebug(25, 70, buffer);
        j = func_80040C08(2);
        sprintf(buffer, "MOVE2 TIME %d", j);
        displayDebug(25, 80, buffer);
        sprintf(buffer, "CACHE %d/%d", cache1d_8002AD44(), gCacheNum);
        displayDebug(25, 0x5A, buffer);
        sprintf(buffer, "LIST %d%%", func_8000921C());
        displayDebug(25, 0x64, buffer);
        break;
    case 7:
        displayDebug(25, 20, "AI");
        sprintf(buffer, "Ai: %d", D_800DEE84);
        displayDebug(25, 30, buffer);
        sprintf(buffer, "Alert Aliens: %d", gAlertAliens);
        displayDebug(25, 40, buffer);
        sprintf(buffer, "Snoozing Aliens: %d", gSnoozingAliens);
        displayDebug(25, 50, buffer);
        sprintf(buffer, "AutoAim: %d", gAutoAim);
        displayDebug(25, 60, buffer);
        sprintf(buffer, "Difficulty (0=E, 1=M, 2=H) : %d", gConfig.difficulty);
        displayDebug(25, 70, buffer);
        sprintf(buffer, "Invul: %d", gInvulnerability);
        displayDebug(25, 80, buffer);

        if ((D_800DF98A == 0))
        {
            if (gButton[D_801B0814] & A_BUTTON)
            {
                D_800DF98A = 1;
                D_800DEE84 ^= 1;
            }
        }
        if ((D_800DF98A == 0))
        {
            if (gButton[D_801B0814] & L_TRIG)
            {
                gConfig.difficulty++;
                if (gConfig.difficulty >= 3)
                    gConfig.difficulty = 0;
                func_80050408();
                D_800DF98A = 1;
            }
        }
        if ((D_800DF98A == 0))
        {
            if (gButton[D_801B0814] & R_TRIG)
            {
                D_800DF98A = 1;
                gAutoAim ^= 1;
            }
            break;
        }
        else if ((gButton[D_801B0814] & (A_BUTTON|B_BUTTON|L_TRIG|R_TRIG)) == 0)
        {
            D_800DF98A = 0;
        }
        break;
    case 8:
        ptr = gpAlphaPalette;
        if (gButton[D_801B0814] & A_BUTTON)
            ptr->primary.r = CLAMP_MAX(ptr->primary.r+1, 255);
        if (gButton[D_801B0814] & D_CBUTTONS)
            ptr->primary.g = CLAMP_MAX(ptr->primary.g+1, 255);
        if (gButton[D_801B0814] & R_CBUTTONS)
            ptr->primary.b = CLAMP_MAX(ptr->primary.b+1, 255);
        if (gButton[D_801B0814] & B_BUTTON)
            ptr->primary.r = CLAMP_MIN(ptr->primary.r-1, 0);
        if (gButton[D_801B0814] & L_CBUTTONS)
            ptr->primary.g = CLAMP_MIN(ptr->primary.g-1, 0);
        if (gButton[D_801B0814] & U_CBUTTONS)
            ptr->primary.b = CLAMP_MIN(ptr->primary.b-1, 0);
        if (gButton[D_801B0814] & R_TRIG)
            ptr->env.r = CLAMP_MAX(ptr->env.r+1, 255);
        if (gButton[D_801B0814] & R_JPAD)
            ptr->env.g = CLAMP_MAX(ptr->env.g+1, 255);
        if (gButton[D_801B0814] & U_JPAD)
            ptr->env.b = CLAMP_MAX(ptr->env.b+1, 255);
        if (gButton[D_801B0814] & L_TRIG)
            ptr->env.r = CLAMP_MIN(ptr->env.r-1, 0);
        if (gButton[D_801B0814] & L_JPAD)
            ptr->env.g = CLAMP_MIN(ptr->env.g-1, 0);
        if (gButton[D_801B0814] & D_JPAD)
            ptr->env.b = CLAMP_MIN(ptr->env.b-1, 0);

        displayDebug(25, 20, "ALPHA PALETTE");
        sprintf(buffer, "R0 %d", ptr->primary.r);
        displayDebug(25, 30, buffer);
        sprintf(buffer, "G0 %d", ptr->primary.g);
        displayDebug(25, 40, buffer);
        sprintf(buffer, "B0 %d", ptr->primary.b);
        displayDebug(25, 50, buffer);
        sprintf(buffer, "R1 %d", ptr->env.r);
        displayDebug(25, 60, buffer);
        sprintf(buffer, "G1 %d", ptr->env.g);
        displayDebug(25, 70, buffer);
        sprintf(buffer, "B1 %d", ptr->env.b);
        displayDebug(25, 80, buffer);
        break;
    case 9:
        displayDebug(25, 20, "SFX");
        sprintf(buffer, "FX %d", _sfxnum);
        displayDebug(25, 30, buffer);
        sprintf(buffer, "KILLS %d:%d", D_801A1958.enemies_killed, D_801A1958.enemies_total);
        displayDebug(25, 40, buffer);

        if (D_800DF98A == 0)
        {
            if (gButton[D_801B0814] & A_BUTTON)
            {
                D_800DF98A = 1;
                gPlayer[0].unk60 = 1;
                gPlayer[0].unk64 = 0;
            }
            if (gButton[D_801B0814] & B_BUTTON)
            {
                D_800DF98A = 1;
                gPlayer[0].unk60 = 0;
                gPlayer[0].unk64 = 0;
            }
            if (gButton[D_801B0814] & R_TRIG)
            {
                D_800DF98A = 1;
                _sfxnum = CLAMP_MAX(_sfxnum+1, 2000);
            }
            if (gButton[D_801B0814] & L_TRIG)
            {
                D_800DF98A = 1;
                _sfxnum = CLAMP_MIN(_sfxnum-1, 1);
            }
            if (gButton[D_801B0814] & R_JPAD)
            {
                D_800DF98A = 1;
                _sfxnum = CLAMP_MAX(_sfxnum+10, 2000);
            }
            if (gButton[D_801B0814] & L_JPAD)
            {
                D_800DF98A = 1;
                _sfxnum = CLAMP_MIN(_sfxnum-10, 1);
            }
            if (gButton[D_801B0814] & Z_TRIG)
            {
                D_800DF98A = 1;
                MusHandleStop(D_800DF958, 0);
                D_800DF958 = MusStartEffect(_sfxnum);
            }
        }
        else if ((gButton[D_801B0814] & (A_BUTTON|B_BUTTON|Z_TRIG|L_TRIG|R_TRIG)) == 0)
        {
            D_800DF98A = 0;
        }
        break;
    case 10:
        displayDebug(25, 20, "LEVEL WARP");
        j = D_801CA14C[gLoadMapNum].unk0;
        displayDebug(25, 30, D_800DF95C[j]);
        displayDebug(25, 40, D_801CA14C[gLoadMapNum].mapname);

        if (D_800DF98A == 0)
        {
            if (gButton[D_801B0814] & B_BUTTON)
            {
                func_8008E01C(30, 1);
                break;
            }
            if (gButton[D_801B0814] & L_TRIG)
            {
                D_800DF98A = 1;
                gLoadMapNum--;
                if (gLoadMapNum < 0)
                    for (gLoadMapNum = 0; D_801CA14C[gLoadMapNum+1].unk0 != 99; gLoadMapNum++);
            }
            if (gButton[D_801B0814] & R_TRIG)
            {
                D_800DF98A = 1;
                gLoadMapNum++;
                if (D_801CA14C[gLoadMapNum].unk0 == 99)
                    gLoadMapNum = 0;
            }
            if (gButton[D_801B0814] & Z_TRIG)
            {
                D_800DF98A = 1;
                func_8008E01C(30, 2);
                break;
            }
        }
        else if ((gButton[D_801B0814] & (A_BUTTON|Z_TRIG|L_TRIG|R_TRIG)) == 0)
        {
            D_800DF98A = 0;
        }
        break;
    case 11:
        displayDebug(25, 20, "MIDI");

        if (D_800DF954 == 0)
            sprintf(buffer, "TUNE %d", _musicnum);
        else
            sprintf(buffer, "AMBIENT %d", _musicnum);

        displayDebug(25, 30, buffer);
        sprintf(buffer, "CHANNELS %d", MusAsk(3));
        displayDebug(25, 40, buffer);

        if (D_800DF98A == 0)
        {
            if (gButton[D_801B0814] & A_BUTTON)
            {
                D_800DF98A = 1;
                if (D_800DF954 == 0)
                    playMusic(_musicnum);
                else
                    playAmbient(_musicnum);
            }
            if (gButton[D_801B0814] & B_BUTTON)
            {
                D_800DF98A = 1;
                MusStop(2, 0);
            }
            if (gButton[D_801B0814] & R_TRIG)
            {
                D_800DF98A = 1;
                if (D_800DF954 == 0)
                    _musicnum = CLAMP_MAX(_musicnum+1, 11);
                else
                    _musicnum = CLAMP_MAX(_musicnum+1, 8);
            }
            if (gButton[D_801B0814] & L_TRIG)
            {
                D_800DF98A = 1;
                _musicnum = CLAMP_MIN(_musicnum-1, 0);
            }
            if (gButton[D_801B0814] & Z_TRIG)
            {
                D_800DF98A = 1;
                D_800DF954 = D_800DF954 == 0;
            }
        }
        else if ((gButton[D_801B0814] & (A_BUTTON|B_BUTTON|Z_TRIG|L_TRIG|R_TRIG)) == 0)
        {
            D_800DF98A = 0;
        }
        break;
    case 12:
        if (gButton[D_801B0814] & A_BUTTON)
            gpGlobalPalette->r = CLAMP_MAX(gpGlobalPalette->r+1, 256);
        if (gButton[D_801B0814] & D_CBUTTONS)
            gpGlobalPalette->g = CLAMP_MAX(gpGlobalPalette->g+1, 256);
        if (gButton[D_801B0814] & R_CBUTTONS)
            gpGlobalPalette->b = CLAMP_MAX(gpGlobalPalette->b+1, 256);
        if (gButton[D_801B0814] & B_BUTTON)
            gpGlobalPalette->r = CLAMP_MIN(gpGlobalPalette->r-1, 0);
        if (gButton[D_801B0814] & L_CBUTTONS)
            gpGlobalPalette->g = CLAMP_MIN(gpGlobalPalette->g-1, 0);
        if (gButton[D_801B0814] & U_CBUTTONS)
            gpGlobalPalette->b = CLAMP_MIN(gpGlobalPalette->b-1, 0);

        displayDebug(25, 20, "GLOBAL PALETTE");
        sprintf(buffer, "R %d", gpGlobalPalette->r);
        displayDebug(25, 30, buffer);
        sprintf(buffer, "G %d", gpGlobalPalette->g);
        displayDebug(25, 40, buffer);
        sprintf(buffer, "B %d", gpGlobalPalette->b);
        displayDebug(25, 50, buffer);
        break;
    case 13:
        displayDebug(25, 20, "CHEAT");
        displayDebug(25, 30, "Z FOR ALL WEAPONS");
        displayDebug(25, 40, "L FOR ALL ITEMS");
        displayDebug(25, 50, "R FOR ALL KEYS");
        displayDebug(25, 60, "A FOR INVUL");

        if (gButton[D_801B0814] & Z_TRIG)
        {
            for (j = 0; j < 50; j++)
            {
                if (j - 31 < 2 || j == 30)
                    continue;
                else if (j == 33 || j == 0)
                    continue;
                else if (j == 0 || j == 19)
                    continue;
                else if (j == 22 || j == 1)
                    continue;
                else if (j < ARRAY_COUNT(D_8011A680[0]))
                {
                    D_8011A680[0][j][0] |= 1;
                    D_8011A680[0][j][1] = 999;
                }
            }
        }

        if (gButton[D_801B0814] & L_TRIG)
        {
            D_8019B940[D_80106D50[gPlayer[0].unk4A]].unk7E = 100;
            for (j = 0; j < ARRAY_COUNT(D_8010A940[0].unkA); j++)
                D_8010A940[0].unkA[j] = D_800E17E0[j];
        }
        if (gButton[D_801B0814] & R_TRIG)
        {
            for (j = 1; j < ARRAY_COUNT(gPlayer[0].unk88); j++)
                gPlayer[0].unk88[j] = 1;
        }
        if (gButton[D_801B0814] & A_BUTTON)
        {
            if (D_800DF98A == 0)
            {
                audio_80008574(0, 945);
                gInvulnerability ^= 1;
                if (gInvulnerability != 0)
                    D_8019B940[D_80106D50[gPlayer[0].unk4A]].unk8 = 999;
                else
                    D_8019B940[D_80106D50[gPlayer[0].unk4A]].unk8 = gPlayer[0].unk48;
                D_800DF98A = 1;
            }
        }
        else
        {
            D_800DF98A = 0;
        }
        break;
    case 14:
        displayDebug(25, 20, "AI Debug values");
        sprintf(buffer, "Gvar 1 %d", gAiDebugGvar1);
        displayDebug(25, 30, buffer);
        sprintf(buffer, "Gvar 2 %d", gAiDebugGvar2);
        displayDebug(25, 40, buffer);
        sprintf(buffer, "Gvar 3 %d", gAiDebugGvar3);
        displayDebug(25, 50, buffer);

        if (D_800DF98A == 0)
        {
            if (gButton[D_801B0814] & A_BUTTON)
            {
                D_800DF98A = 1;
                if (gButton[D_801B0814] & L_TRIG)
                    gAiDebugGvar1 += 10;
                else
                    gAiDebugGvar1++;
            }
            if (gButton[D_801B0814] & D_CBUTTONS)
            {
                D_800DF98A = 1;
                if (gButton[D_801B0814] & L_TRIG)
                    gAiDebugGvar2 += 10;
                else
                    gAiDebugGvar2++;
            }
            if (gButton[D_801B0814] & R_CBUTTONS)
            {
                D_800DF98A = 1;
                if (gButton[D_801B0814] & L_TRIG)
                    gAiDebugGvar3 += 10;
                else
                    gAiDebugGvar3++;
            }
            if (gButton[D_801B0814] & B_BUTTON)
            {
                D_800DF98A = 1;
                if (gButton[D_801B0814] & L_TRIG)
                    gAiDebugGvar1 -= 10;
                else
                    gAiDebugGvar1--;
            }
            if (gButton[D_801B0814] & L_CBUTTONS)
            {
                D_800DF98A = 1;
                if (gButton[D_801B0814] & L_TRIG)
                    gAiDebugGvar2 -= 10;
                else
                    gAiDebugGvar2--;
            }
            if (gButton[D_801B0814] & U_CBUTTONS)
            {
                D_800DF98A = 1;
                if (gButton[D_801B0814] & L_TRIG)
                    gAiDebugGvar3 -= 10;
                else
                    gAiDebugGvar3--;
            }
        }
        else if ((gButton[D_801B0814] & (A_BUTTON|B_BUTTON|U_CBUTTONS|L_CBUTTONS|R_CBUTTONS|D_CBUTTONS)) == 0)
        {
            D_800DF98A = 0;
        }
        break;
    }
}
