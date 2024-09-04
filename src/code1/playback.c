#include "common.h"
#include "ld_symbols.h"
#include "code0/debug.h"
#include "code0/controller.h"
#include "code0/4590.h"
#include "code0/main.h"
#include "code0/8E670.h"
#include "code0/code0.h"
#include "code1/code1.h"

/*.data*/
/*801CBCE8*/
static u8 *gPlaybackList[12] = {
    playbacks_1003A60_ROM_START,
    playbacks_1004260_ROM_START,
    playbacks_1004A60_ROM_START,
    playbacks_1005260_ROM_START,
    playbacks_1005A60_ROM_START,
    playbacks_1006260_ROM_START,
    playbacks_1006A60_ROM_START,
    playbacks_1007260_ROM_START,
    playbacks_1007A60_ROM_START,
    playbacks_1008260_ROM_START,
    playbacks_1008A60_ROM_START,
    playbacks_1009260_ROM_START,
};

/*801CBD18*/ static u32 D_801CBD18 = 0;

/*.comm*/
/*801CDC68*/ s8 *gpPlaybackBuffer;
/*801CDC70*/ s8 gPlaybackBuffer[0x800] ALIGNED(16);
/*801CDB0C*/ u16 D_801CDB0C;
/*801CF708*/ u16 D_801CF708;
/*801CF710*/ s16 D_801CF710;
/*801CD97C*/ s16 D_801CD97C;

/*.text*/

/*801C9B48*/
void playback_801C9B48(void)
{
    s32 i;

    gpPlaybackBuffer = gPlaybackBuffer;
    i = D_801CBD18 % 5;
    readRom((u8 *)gPlaybackBuffer, gPlaybackList[i], sizeof(gPlaybackBuffer));
    D_801CDB0C = 0;
    D_8012FC90 = 1;
    gRandomSeed = 0;
    D_801CBD18++;
    gLoadMapNum = *gpPlaybackBuffer++;
    gNotPlayback = FALSE;
}

/*801C9C18*/
static void func_801C9C18(void)
{
    u8 i;

    i = *gpPlaybackBuffer;
    if ((i == 0) || (gPlayer[0].unk45 != 0))
    {
        func_8008E01C(30, 5);
        D_8012FC90 = 0;
        return;
    }

    switch (i & 3)
    {
    case 2:
        gpPlaybackBuffer++;
        gStickX[0] = *gpPlaybackBuffer++;
        gStickY[0] = *gpPlaybackBuffer++;
        break;
    case 3:
        gpPlaybackBuffer++;
        gButton[0] = *gpPlaybackBuffer++ << 8;
        gButton[0] += *gpPlaybackBuffer++;
        gButton[0] &= ~START_BUTTON;
        i = *gpPlaybackBuffer;
        if ((i & 3) == 2)
        {
            gpPlaybackBuffer++;
            gStickX[0] = *gpPlaybackBuffer++;
            gStickY[0] = *gpPlaybackBuffer++;
        }
        break;
    }
}

#ifdef NON_MATCHING
/*801C9D68*/
void playback_801C9D68(void)
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

    l = *gpPlaybackBuffer;
    if ((l == 0) || (gPlayer[0].unk45 != 0))
    {
        func_8008E01C(30, 5);
        D_8012FC90 = 0;
    }
    else
    {
        k = *gpPlaybackBuffer;
        m = gpPlaybackBuffer[1];
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
            ptr = &gpPlaybackBuffer;
            gpPlaybackBuffer = &(*ptr)[k];
        }
        func_801C9C18();
    }
}
#else
/*801C9D68*/
INCLUDE_ASM("src/code1/code1", playback_801C9D68);
#endif

/*801C9E7C*/
void playback_801C9E7C(void)
{
    D_801CDB4C = 1;
    gpPlaybackBuffer = gPlaybackBuffer;
    D_801CF708 = 0;
    D_801CF710 = 0;
    D_801CD97C = 0;
    D_801CDB0C = 0;
    gRandomSeed = 0;
    gpPlaybackBuffer = &gPlaybackBuffer[1];
    gPlaybackBuffer[0] = gLoadMapNum;
}

/*801C9EDC*/
static void func_801C9EDC(void)
{
    if (D_801CDB0C != 0)
    {
        if (D_801CDB0C < 64)
        {
            *gpPlaybackBuffer++ = (D_801CDB0C & 0x3F) * 4;
        }
        else
        {
            *gpPlaybackBuffer++ = ((D_801CDB0C & 0x3F) * 4) + 1;
            *gpPlaybackBuffer++ = D_801CDB0C >> 6;
        }
        D_801CDB0C = 0;
    }
}

/*801C9F74*/
void playback_801C9F74(void)
{
    s32 cond;

    if ((&gPlaybackBuffer[sizeof(gPlaybackBuffer)-8]) < gpPlaybackBuffer)
    {
        main_80003940();
        return;
    }
    cond = 0;

    if (D_801CF708 != gButton[0])
    {
        D_801CF708 = gButton[0];
        func_801C9EDC();
        *gpPlaybackBuffer++ = 3;
        *gpPlaybackBuffer++ = gButton[0] >> 8;
        *gpPlaybackBuffer++ = gButton[0];
        cond = 1;
    }

    if ((D_801CF710 != gStickX[0]) || (D_801CD97C != gStickY[0]))
    {
        D_801CF710 = gStickX[0];
        D_801CD97C = gStickY[0];
        func_801C9EDC();
        *gpPlaybackBuffer++ = 2;
        *gpPlaybackBuffer++ = gStickX[0];
        *gpPlaybackBuffer++ = gStickY[0];
        cond = 1;
    }

    if (cond == 0)
        D_801CDB0C++;
}
