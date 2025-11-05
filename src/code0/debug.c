#include "common.h"
#include "code0/main.h"
#include "code0/4590.h"
#include "code0/9410.h"
#include "code0/audio.h"
#include "code0/cache1d.h"
#include "code0/1A7C0.h"
#include "code0/timer.h"
#include "code0/41940.h"
#include "code0/8E670.h"
#include "code0/95500.h"
#include "code0/code0.h"
#include "code1/EB300.h"
#include "code1/code1.h"

#define DEBUG_FOG 0
#define DEBUG_SKYTOP 1
#define DEBUG_SKYBOTTOM 2
#define DEBUG_CLOUDS1 3
#define DEBUG_CLOUDS2 4
#define DEBUG_PLAYER 5
#define DEBUG_GFX 6
#define DEBUG_AI 7
#define DEBUG_ALPHA_PALETTE 8
#define DEBUG_SFX 9
#define DEBUG_LEVEL_WRAP 10
#define DEBUG_MIDI 11
#define DEBUG_GLOBAL_PALETTE 12
#define DEBUG_CHEAT 13
#define DEBUG_AI_VALUES 14

/*.data*/
/*800DF950*/ s16 gLoadMapNum = 0;
/*800DF952*/ static s16 _musicnum = 0;
/*800DF954*/ static bool _playAmbient = FALSE;
/*800DF956*/ static s16 _sfxnum = 1;
/*800DF958*/ static musHandle _mushandle = 0;

/*800DF95C*/
static char *_chapterName[11] = {
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

/*800DF988*/ static u8 _debugScreen = DEBUG_SFX;
/*800DF989*/ static bool _screenSelectButtonPressed = FALSE;
/*800DF98A*/ static bool _cmdButtonPressed = FALSE;
static u8 _unused1 = 0;
/*800DF98C*/ bool gNotPlayback = TRUE;
static u8 _unused2 = 0;
static u8 _unused3 = 2;
static u8 _unused4 = 188;
/*800DF990*/ bool gDebugMenu = FALSE;

/*.comm*/
/*801B0814*/ u8 _debugPlayerNum;

/*.text*/

/*8007BFC0*/
void debugMenu(void)
{
#ifdef AVOID_UB
    char buffer[64];
#else
    char buffer[16];
#endif
    AlphaPalette *palette;
    Cloud *cloud;
    u8 i;
    u32 j;

    if (gPlayerCount == 4)
        return;

    if ((!gDebugMenu) && (gCheatWeatherConfig == CONFIG_OFF))
        return;

    _debugPlayerNum = CLAMP_MAX(gPlayerCount, 3);
    if (gButton[_debugPlayerNum] & START_BUTTON)
    {
        if (!_screenSelectButtonPressed)
        {
            _screenSelectButtonPressed = TRUE;
            _debugScreen++;
        }
    }
    else
    {
        _screenSelectButtonPressed = FALSE;
    }

    if (gCheatWeatherConfig == CONFIG_OFF)
    {
        _debugScreen &= 0xF;
    }
    else
    {
        if (_debugScreen == DEBUG_SFX)
            _debugScreen = DEBUG_FOG;

        if (_debugScreen != 0xFF)
        {
            _debugScreen %= 6;
            if (_debugScreen == 5)
                _debugScreen = 0xFF;
        }
    }
    switch (_debugScreen)
    {
    case DEBUG_FOG:
        if (gButton[_debugPlayerNum] & A_BUTTON)
            gFog[0].color[0].r = CLAMP_MAX(gFog[0].color[0].r+1, 255);
        if (gButton[_debugPlayerNum] & D_CBUTTONS)
            gFog[0].color[0].g = CLAMP_MAX(gFog[0].color[0].g+1, 255);
        if (gButton[_debugPlayerNum] & R_CBUTTONS)
            gFog[0].color[0].b = CLAMP_MAX(gFog[0].color[0].b+1, 255);
        if (gButton[_debugPlayerNum] & B_BUTTON)
            gFog[0].color[0].r = CLAMP_MIN(gFog[0].color[0].r-1, 0);
        if (gButton[_debugPlayerNum] & L_CBUTTONS)
            gFog[0].color[0].g = CLAMP_MIN(gFog[0].color[0].g-1, 0);
        if (gButton[_debugPlayerNum] & U_CBUTTONS)
            gFog[0].color[0].b = CLAMP_MIN(gFog[0].color[0].b-1, 0);
        if (gButton[_debugPlayerNum] & R_TRIG)
            gFog[0].scale[0].fr = CLAMP_MAX(gFog[0].scale[0].fr+1, 3000);
        if (gButton[_debugPlayerNum] & R_JPAD)
            gFog[0].scale[0].nr = CLAMP_MAX(gFog[0].scale[0].nr+1, 3000);
        if (gButton[_debugPlayerNum] & L_TRIG)
            gFog[0].scale[0].fr = CLAMP_MIN(gFog[0].scale[0].fr-1, 0);
        if (gButton[_debugPlayerNum] & L_JPAD)
            gFog[0].scale[0].nr = CLAMP_MIN(gFog[0].scale[0].nr-1, 0);

        gFog[0].scale[0].fr = MAX(gFog[0].scale[0].fr, gFog[0].scale[0].nr+3);
        gFog[0].scale[1].nr = gFog[0].scale[0].nr;
        gFog[0].scale[1].fr = gFog[0].scale[0].fr;
        gFog[0].unk1E = 0;
        gFog[0].color[1].r = gFog[0].color[0].r;
        gFog[0].color[1].g = gFog[0].color[0].g;
        gFog[0].color[1].b = gFog[0].color[0].b;

        drawDebugString(25, 20, "FOG");
        sprintf(buffer, "R %d", gFog[0].color[0].r);
        drawDebugString(25, 30, buffer);
        sprintf(buffer, "G %d", gFog[0].color[0].g);
        drawDebugString(25, 40, buffer);
        sprintf(buffer, "B %d", gFog[0].color[0].b);
        drawDebugString(25, 50, buffer);
        sprintf(buffer, "NR %d", gFog[0].scale[0].nr);
        drawDebugString(25, 60, buffer);
        sprintf(buffer, "FR %d", gFog[0].scale[0].fr);
        drawDebugString(25, 70, buffer);
        break;
    case DEBUG_SKYTOP:
        if (gButton[_debugPlayerNum] & A_BUTTON)
            gSkyTopR = CLAMP_MAX(gSkyTopR+1, 255);
        if (gButton[_debugPlayerNum] & D_CBUTTONS)
            gSkyTopG = CLAMP_MAX(gSkyTopG+1, 255);
        if (gButton[_debugPlayerNum] & R_CBUTTONS)
            gSkyTopB = CLAMP_MAX(gSkyTopB+1, 255);
        if (gButton[_debugPlayerNum] & B_BUTTON)
            gSkyTopR = CLAMP_MIN(gSkyTopR-1, 0);
        if (gButton[_debugPlayerNum] & L_CBUTTONS)
            gSkyTopG = CLAMP_MIN(gSkyTopG-1, 0);
        if (gButton[_debugPlayerNum] & U_CBUTTONS)
            gSkyTopB = CLAMP_MIN(gSkyTopB-1, 0);

        drawDebugString(25, 20, "SKY TOP");
        sprintf(buffer, "R %d", gSkyTopR);
        drawDebugString(25, 30, buffer);
        sprintf(buffer, "G %d", gSkyTopG);
        drawDebugString(25, 40, buffer);
        sprintf(buffer, "B %d", gSkyTopB);
        drawDebugString(25, 50, buffer);
        break;
    case DEBUG_SKYBOTTOM:
        if (gButton[_debugPlayerNum] & A_BUTTON)
            gSkyBottomR = CLAMP_MAX(gSkyBottomR+1, 255);
        if (gButton[_debugPlayerNum] & D_CBUTTONS)
            gSkyBottomG = CLAMP_MAX(gSkyBottomG+1, 255);
        if (gButton[_debugPlayerNum] & R_CBUTTONS)
            gSkyBottomB = CLAMP_MAX(gSkyBottomB+1, 255);
        if (gButton[_debugPlayerNum] & B_BUTTON)
            gSkyBottomR = CLAMP_MIN(gSkyBottomR-1, 0);
        if (gButton[_debugPlayerNum] & L_CBUTTONS)
            gSkyBottomG = CLAMP_MIN(gSkyBottomG-1, 0);
        if (gButton[_debugPlayerNum] & U_CBUTTONS)
            gSkyBottomB = CLAMP_MIN(gSkyBottomB-1, 0);

        drawDebugString(25, 20, "SKY BOTTOM");
        sprintf(buffer, "R %d", gSkyBottomR);
        drawDebugString(25, 30, buffer);
        sprintf(buffer, "G %d", gSkyBottomG);
        drawDebugString(25, 40, buffer);
        sprintf(buffer, "B %d", gSkyBottomB);
        drawDebugString(25, 50, buffer);
        break;
    case DEBUG_CLOUDS1:
    case DEBUG_CLOUDS2:
        i = _debugScreen - DEBUG_CLOUDS1;
        cloud = &gCloud[i];
        if (gButton[_debugPlayerNum] & A_BUTTON)
            cloud->fog.r = CLAMP_MAX(cloud->fog.r+1, 255);
        if (gButton[_debugPlayerNum] & D_CBUTTONS)
            cloud->fog.g = CLAMP_MAX(cloud->fog.g+1, 255);
        if (gButton[_debugPlayerNum] & R_CBUTTONS)
            cloud->fog.b = CLAMP_MAX(cloud->fog.b+1, 255);
        if (gButton[_debugPlayerNum] & B_BUTTON)
            cloud->fog.r = CLAMP_MIN(cloud->fog.r-1, 0);
        if (gButton[_debugPlayerNum] & L_CBUTTONS)
            cloud->fog.g = CLAMP_MIN(cloud->fog.g-1, 0);
        if (gButton[_debugPlayerNum] & U_CBUTTONS)
            cloud->fog.b = CLAMP_MIN(cloud->fog.b-1, 0);
        if (gButton[_debugPlayerNum] & R_TRIG)
            cloud->height += 300;
        if (gButton[_debugPlayerNum] & L_TRIG)
            cloud->height -= 300;
        if (gButton[_debugPlayerNum] & R_JPAD)
            gCloudSpeed[i] = CLAMP_MAX(gCloudSpeed[i]+1, 1023);
        if (gButton[_debugPlayerNum] & L_JPAD)
            gCloudSpeed[i] = CLAMP_MIN(gCloudSpeed[i]-1, 0);
        if (gButton[_debugPlayerNum] & U_JPAD)
            gCloudAng[i] = (gCloudAng[i]+4) & 0x7FF;
        if (gButton[_debugPlayerNum] & D_JPAD)
            gCloudAng[i] = (gCloudAng[i]-4) & 0x7FF;

        cloud->unk8 = (-cosf((gCloudAng[i] * (PI/1024))) * gCloudSpeed[i]) / 50.0f;
        cloud->unkC = (-sinf((gCloudAng[i] * (PI/1024))) * gCloudSpeed[i]) / 50.0f;

        sprintf(buffer, "CLOUDS %d", i + 1);
        drawDebugString(25, 20, buffer);
        sprintf(buffer, "R %d", cloud->fog.r);
        drawDebugString(25, 30, buffer);
        sprintf(buffer, "G %d", cloud->fog.g);
        drawDebugString(25, 40, buffer);
        sprintf(buffer, "B %d", cloud->fog.b);
        drawDebugString(25, 50, buffer);
        sprintf(buffer, "HT %d", cloud->height / 10);
        drawDebugString(25, 60, buffer);
        sprintf(buffer, "AN %d", gCloudAng[i]);
        drawDebugString(25, 70, buffer);
        sprintf(buffer, "SP %d", gCloudSpeed[i]);
        drawDebugString(25, 80, buffer);
        break;
    case DEBUG_PLAYER:
        drawDebugString(25, 20, "PLAYER");
        sprintf(buffer, "XV %d", gPlayer[0].xvect);
        drawDebugString(25, 30, buffer);
        sprintf(buffer, "YV %d", gPlayer[0].yvect);
        drawDebugString(25, 40, buffer);
        sprintf(buffer, "ZV %d", gPlayer[0].zvect);
        drawDebugString(25, 50, buffer);
        sprintf(buffer, "OF %d", gPlayer[0].unk59);
        drawDebugString(25, 60, buffer);
        sprintf(buffer, "OW %d", gPlayer[0].unk56);
        drawDebugString(25, 70, buffer);
        sprintf(buffer, "JF %d", gPlayer[0].unk44);
        drawDebugString(25, 80, buffer);
        sprintf(buffer, "DN %d", gPlayer[0].skin);
        drawDebugString(25, 90, buffer);

        if (!_cmdButtonPressed)
        {
            if (gButton[_debugPlayerNum] & L_TRIG)
            {
                gPlayer[0].skin--;
                if (gPlayer[0].skin < 0)
                    gPlayer[0].skin = D_80138780 - 1;
                _cmdButtonPressed = TRUE;
                gpSprite[gPlayer[0].unk4A].picnum = D_8012F6E4[gPlayer[0].skin].picnum;
            }
            if (gButton[_debugPlayerNum] & R_TRIG)
            {
                gPlayer[0].skin++;
                if (gPlayer[0].skin >= D_80138780)
                    gPlayer[0].skin = 0;
                _cmdButtonPressed = TRUE;
                gpSprite[gPlayer[0].unk4A].picnum = D_8012F6E4[gPlayer[0].skin].picnum;
            }
        }
        else if ((gButton[_debugPlayerNum] & (L_TRIG|R_TRIG)) == 0)
        {
            _cmdButtonPressed = FALSE;
        }

        break;
    case DEBUG_GFX:
        drawDebugString(25, 20, "GFX");
        sprintf(buffer, "GLIST %d - %d", gDisplayListSize, gDisplayListMaxSize);
        drawDebugString(25, 30, buffer);
        sprintf(buffer, "VLIST %d - %d", gVertexN64Size, gVertexN64MaxSize);
        drawDebugString(25, 40, buffer);
        sprintf(buffer, "GFX TIME %d", gGfxTime);
        drawDebugString(25, 50, buffer);
        j = getTimerElapsedTime(DRAW_TIMER);
        sprintf(buffer, "DRAW TIME %d", j);
        drawDebugString(25, 60, buffer);
        j = getTimerElapsedTime(MOVE1_TIMER);
        sprintf(buffer, "MOVE1 TIME %d", j);
        drawDebugString(25, 70, buffer);
        j = getTimerElapsedTime(MOVE2_TIMER);
        sprintf(buffer, "MOVE2 TIME %d", j);
        drawDebugString(25, 80, buffer);
        sprintf(buffer, "CACHE %d/%d", getRemainingCacheSize(), gCacheNum);
        drawDebugString(25, 0x5A, buffer);
        sprintf(buffer, "LIST %d%%", getDisplayListVertexUsagePercentage());
        drawDebugString(25, 0x64, buffer);
        break;
    case DEBUG_AI:
        drawDebugString(25, 20, "AI");
        sprintf(buffer, "Ai: %d", gDisableAI);
        drawDebugString(25, 30, buffer);
        sprintf(buffer, "Alert Aliens: %d", gAlertAliens);
        drawDebugString(25, 40, buffer);
        sprintf(buffer, "Snoozing Aliens: %d", gSnoozingAliens);
        drawDebugString(25, 50, buffer);
        sprintf(buffer, "AutoAim: %d", gAutoAim);
        drawDebugString(25, 60, buffer);
        sprintf(buffer, "Difficulty (0=E, 1=M, 2=H) : %d", gConfig.difficulty);
        drawDebugString(25, 70, buffer);
        sprintf(buffer, "Invul: %d", gInvulnerability);
        drawDebugString(25, 80, buffer);

        if ((!_cmdButtonPressed))
        {
            if (gButton[_debugPlayerNum] & A_BUTTON)
            {
                _cmdButtonPressed = TRUE;
                gDisableAI ^= 1;
            }
        }
        if ((!_cmdButtonPressed))
        {
            if (gButton[_debugPlayerNum] & L_TRIG)
            {
                gConfig.difficulty++;
                if (gConfig.difficulty >= 3)
                    gConfig.difficulty = 0;
                func_80050408();
                _cmdButtonPressed = TRUE;
            }
        }
        if ((!_cmdButtonPressed))
        {
            if (gButton[_debugPlayerNum] & R_TRIG)
            {
                _cmdButtonPressed = TRUE;
                gAutoAim ^= 1;
            }
            break;
        }
        else if ((gButton[_debugPlayerNum] & (A_BUTTON|B_BUTTON|L_TRIG|R_TRIG)) == 0)
        {
            _cmdButtonPressed = FALSE;
        }
        break;
    case DEBUG_ALPHA_PALETTE:
        palette = gpAlphaPalette;
        if (gButton[_debugPlayerNum] & A_BUTTON)
            palette->primary.r = CLAMP_MAX(palette->primary.r+1, 255);
        if (gButton[_debugPlayerNum] & D_CBUTTONS)
            palette->primary.g = CLAMP_MAX(palette->primary.g+1, 255);
        if (gButton[_debugPlayerNum] & R_CBUTTONS)
            palette->primary.b = CLAMP_MAX(palette->primary.b+1, 255);
        if (gButton[_debugPlayerNum] & B_BUTTON)
            palette->primary.r = CLAMP_MIN(palette->primary.r-1, 0);
        if (gButton[_debugPlayerNum] & L_CBUTTONS)
            palette->primary.g = CLAMP_MIN(palette->primary.g-1, 0);
        if (gButton[_debugPlayerNum] & U_CBUTTONS)
            palette->primary.b = CLAMP_MIN(palette->primary.b-1, 0);
        if (gButton[_debugPlayerNum] & R_TRIG)
            palette->env.r = CLAMP_MAX(palette->env.r+1, 255);
        if (gButton[_debugPlayerNum] & R_JPAD)
            palette->env.g = CLAMP_MAX(palette->env.g+1, 255);
        if (gButton[_debugPlayerNum] & U_JPAD)
            palette->env.b = CLAMP_MAX(palette->env.b+1, 255);
        if (gButton[_debugPlayerNum] & L_TRIG)
            palette->env.r = CLAMP_MIN(palette->env.r-1, 0);
        if (gButton[_debugPlayerNum] & L_JPAD)
            palette->env.g = CLAMP_MIN(palette->env.g-1, 0);
        if (gButton[_debugPlayerNum] & D_JPAD)
            palette->env.b = CLAMP_MIN(palette->env.b-1, 0);

        drawDebugString(25, 20, "ALPHA PALETTE");
        sprintf(buffer, "R0 %d", palette->primary.r);
        drawDebugString(25, 30, buffer);
        sprintf(buffer, "G0 %d", palette->primary.g);
        drawDebugString(25, 40, buffer);
        sprintf(buffer, "B0 %d", palette->primary.b);
        drawDebugString(25, 50, buffer);
        sprintf(buffer, "R1 %d", palette->env.r);
        drawDebugString(25, 60, buffer);
        sprintf(buffer, "G1 %d", palette->env.g);
        drawDebugString(25, 70, buffer);
        sprintf(buffer, "B1 %d", palette->env.b);
        drawDebugString(25, 80, buffer);
        break;
    case DEBUG_SFX:
        drawDebugString(25, 20, "SFX");
        sprintf(buffer, "FX %d", _sfxnum);
        drawDebugString(25, 30, buffer);
        sprintf(buffer, "KILLS %d:%d", D_801A1958.enemies_killed, D_801A1958.enemies_total);
        drawDebugString(25, 40, buffer);

        if (!_cmdButtonPressed)
        {
            if (gButton[_debugPlayerNum] & A_BUTTON)
            {
                _cmdButtonPressed = TRUE;
                gPlayer[0].third_person = TRUE;
                gPlayer[0].unk64 = 0;
            }
            if (gButton[_debugPlayerNum] & B_BUTTON)
            {
                _cmdButtonPressed = TRUE;
                gPlayer[0].third_person = FALSE;
                gPlayer[0].unk64 = 0;
            }
            if (gButton[_debugPlayerNum] & R_TRIG)
            {
                _cmdButtonPressed = TRUE;
                _sfxnum = CLAMP_MAX(_sfxnum+1, 2000);
            }
            if (gButton[_debugPlayerNum] & L_TRIG)
            {
                _cmdButtonPressed = TRUE;
                _sfxnum = CLAMP_MIN(_sfxnum-1, 1);
            }
            if (gButton[_debugPlayerNum] & R_JPAD)
            {
                _cmdButtonPressed = TRUE;
                _sfxnum = CLAMP_MAX(_sfxnum+10, 2000);
            }
            if (gButton[_debugPlayerNum] & L_JPAD)
            {
                _cmdButtonPressed = TRUE;
                _sfxnum = CLAMP_MIN(_sfxnum-10, 1);
            }
            if (gButton[_debugPlayerNum] & Z_TRIG)
            {
                _cmdButtonPressed = TRUE;
                MusHandleStop(_mushandle, 0);
                _mushandle = MusStartEffect(_sfxnum);
            }
        }
        else if ((gButton[_debugPlayerNum] & (A_BUTTON|B_BUTTON|Z_TRIG|L_TRIG|R_TRIG)) == 0)
        {
            _cmdButtonPressed = FALSE;
        }
        break;
    case DEBUG_LEVEL_WRAP:
        drawDebugString(25, 20, "LEVEL WARP");
        j = gMapChapter[gLoadMapNum].chapter;
        drawDebugString(25, 30, _chapterName[j]);
        drawDebugString(25, 40, gMapChapter[gLoadMapNum].mapname);

        if (!_cmdButtonPressed)
        {
            if (gButton[_debugPlayerNum] & B_BUTTON)
            {
                func_8008E01C(30, 1);
                break;
            }
            if (gButton[_debugPlayerNum] & L_TRIG)
            {
                _cmdButtonPressed = TRUE;
                gLoadMapNum--;
                if (gLoadMapNum < 0)
                    for (gLoadMapNum = 0; gMapChapter[gLoadMapNum+1].chapter != 99; gLoadMapNum++);
            }
            if (gButton[_debugPlayerNum] & R_TRIG)
            {
                _cmdButtonPressed = TRUE;
                gLoadMapNum++;
                if (gMapChapter[gLoadMapNum].chapter == 99)
                    gLoadMapNum = 0;
            }
            if (gButton[_debugPlayerNum] & Z_TRIG)
            {
                _cmdButtonPressed = TRUE;
                func_8008E01C(30, 2);
                break;
            }
        }
        else if ((gButton[_debugPlayerNum] & (A_BUTTON|Z_TRIG|L_TRIG|R_TRIG)) == 0)
        {
            _cmdButtonPressed = FALSE;
        }
        break;
    case DEBUG_MIDI:
        drawDebugString(25, 20, "MIDI");

        if (!_playAmbient)
            sprintf(buffer, "TUNE %d", _musicnum);
        else
            sprintf(buffer, "AMBIENT %d", _musicnum);

        drawDebugString(25, 30, buffer);
        sprintf(buffer, "CHANNELS %d", MusAsk(3));
        drawDebugString(25, 40, buffer);

        if (!_cmdButtonPressed)
        {
            if (gButton[_debugPlayerNum] & A_BUTTON)
            {
                _cmdButtonPressed = TRUE;
                if (!_playAmbient)
                    playMusic(_musicnum);
                else
                    playAmbient(_musicnum);
            }
            if (gButton[_debugPlayerNum] & B_BUTTON)
            {
                _cmdButtonPressed = TRUE;
                MusStop(2, 0);
            }
            if (gButton[_debugPlayerNum] & R_TRIG)
            {
                _cmdButtonPressed = TRUE;
                if (!_playAmbient)
                    _musicnum = CLAMP_MAX(_musicnum+1, MUSIC_COUNT-1);
                else
                    _musicnum = CLAMP_MAX(_musicnum+1, AMBIENT_COUNT-1);
            }
            if (gButton[_debugPlayerNum] & L_TRIG)
            {
                _cmdButtonPressed = TRUE;
                _musicnum = CLAMP_MIN(_musicnum-1, 0);
            }
            if (gButton[_debugPlayerNum] & Z_TRIG)
            {
                _cmdButtonPressed = TRUE;
                _playAmbient = !_playAmbient;
            }
        }
        else if ((gButton[_debugPlayerNum] & (A_BUTTON|B_BUTTON|Z_TRIG|L_TRIG|R_TRIG)) == 0)
        {
            _cmdButtonPressed = FALSE;
        }
        break;
    case DEBUG_GLOBAL_PALETTE:
        if (gButton[_debugPlayerNum] & A_BUTTON)
            gpGlobalPalette->r = CLAMP_MAX(gpGlobalPalette->r+1, 256);
        if (gButton[_debugPlayerNum] & D_CBUTTONS)
            gpGlobalPalette->g = CLAMP_MAX(gpGlobalPalette->g+1, 256);
        if (gButton[_debugPlayerNum] & R_CBUTTONS)
            gpGlobalPalette->b = CLAMP_MAX(gpGlobalPalette->b+1, 256);
        if (gButton[_debugPlayerNum] & B_BUTTON)
            gpGlobalPalette->r = CLAMP_MIN(gpGlobalPalette->r-1, 0);
        if (gButton[_debugPlayerNum] & L_CBUTTONS)
            gpGlobalPalette->g = CLAMP_MIN(gpGlobalPalette->g-1, 0);
        if (gButton[_debugPlayerNum] & U_CBUTTONS)
            gpGlobalPalette->b = CLAMP_MIN(gpGlobalPalette->b-1, 0);

        drawDebugString(25, 20, "GLOBAL PALETTE");
        sprintf(buffer, "R %d", gpGlobalPalette->r);
        drawDebugString(25, 30, buffer);
        sprintf(buffer, "G %d", gpGlobalPalette->g);
        drawDebugString(25, 40, buffer);
        sprintf(buffer, "B %d", gpGlobalPalette->b);
        drawDebugString(25, 50, buffer);
        break;
    case DEBUG_CHEAT:
        drawDebugString(25, 20, "CHEAT");
        drawDebugString(25, 30, "Z FOR ALL WEAPONS");
        drawDebugString(25, 40, "L FOR ALL ITEMS");
        drawDebugString(25, 50, "R FOR ALL KEYS");
        drawDebugString(25, 60, "A FOR INVUL");

        if (gButton[_debugPlayerNum] & Z_TRIG)
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

        if (gButton[_debugPlayerNum] & L_TRIG)
        {
            gActor[gActorSpriteMap[gPlayer[0].unk4A]].unk7E = 100;
            for (j = 0; j < ARRAY_COUNT(D_8010A940[0].unkA); j++)
                D_8010A940[0].unkA[j] = D_800E17E0[j];
        }
        if (gButton[_debugPlayerNum] & R_TRIG)
        {
            for (j = 1; j < ARRAY_COUNT(gPlayer[0].keys); j++)
                gPlayer[0].keys[j] = 1;
        }
        if (gButton[_debugPlayerNum] & A_BUTTON)
        {
            if (!_cmdButtonPressed)
            {
                audio_80008574(0, 945);
                gInvulnerability ^= 1;
                if (gInvulnerability != 0)
                    gActor[gActorSpriteMap[gPlayer[0].unk4A]].unk8 = 999;
                else
                    gActor[gActorSpriteMap[gPlayer[0].unk4A]].unk8 = gPlayer[0].unk48;
                _cmdButtonPressed = TRUE;
            }
        }
        else
        {
            _cmdButtonPressed = FALSE;
        }
        break;
    case DEBUG_AI_VALUES:
        drawDebugString(25, 20, "AI Debug values");
        sprintf(buffer, "Gvar 1 %d", gAiDebugGvar1);
        drawDebugString(25, 30, buffer);
        sprintf(buffer, "Gvar 2 %d", gAiDebugGvar2);
        drawDebugString(25, 40, buffer);
        sprintf(buffer, "Gvar 3 %d", gAiDebugGvar3);
        drawDebugString(25, 50, buffer);

        if (!_cmdButtonPressed)
        {
            if (gButton[_debugPlayerNum] & A_BUTTON)
            {
                _cmdButtonPressed = TRUE;
                if (gButton[_debugPlayerNum] & L_TRIG)
                    gAiDebugGvar1 += 10;
                else
                    gAiDebugGvar1++;
            }
            if (gButton[_debugPlayerNum] & D_CBUTTONS)
            {
                _cmdButtonPressed = TRUE;
                if (gButton[_debugPlayerNum] & L_TRIG)
                    gAiDebugGvar2 += 10;
                else
                    gAiDebugGvar2++;
            }
            if (gButton[_debugPlayerNum] & R_CBUTTONS)
            {
                _cmdButtonPressed = TRUE;
                if (gButton[_debugPlayerNum] & L_TRIG)
                    gAiDebugGvar3 += 10;
                else
                    gAiDebugGvar3++;
            }
            if (gButton[_debugPlayerNum] & B_BUTTON)
            {
                _cmdButtonPressed = TRUE;
                if (gButton[_debugPlayerNum] & L_TRIG)
                    gAiDebugGvar1 -= 10;
                else
                    gAiDebugGvar1--;
            }
            if (gButton[_debugPlayerNum] & L_CBUTTONS)
            {
                _cmdButtonPressed = TRUE;
                if (gButton[_debugPlayerNum] & L_TRIG)
                    gAiDebugGvar2 -= 10;
                else
                    gAiDebugGvar2--;
            }
            if (gButton[_debugPlayerNum] & U_CBUTTONS)
            {
                _cmdButtonPressed = TRUE;
                if (gButton[_debugPlayerNum] & L_TRIG)
                    gAiDebugGvar3 -= 10;
                else
                    gAiDebugGvar3--;
            }
        }
        else if ((gButton[_debugPlayerNum] & (A_BUTTON|B_BUTTON|U_CBUTTONS|L_CBUTTONS|R_CBUTTONS|D_CBUTTONS)) == 0)
        {
            _cmdButtonPressed = FALSE;
        }
        break;
    }
}
