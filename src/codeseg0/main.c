#include "common.h"
#include "codeseg0/audio.h"
#include "codeseg0/9410.h"
#include "codeseg0/4590.h"
#include "codeseg0/17B30.h"
#include "codeseg0/1E7A0.h"
#include "codeseg0/20490.h"
#include "codeseg0/2ABE0.h"
#include "codeseg0/35EA0.h"
#include "codeseg0/37090.h"
#include "codeseg0/3FAD0.h"
#include "codeseg0/41940.h"
#include "codeseg0/64530.h"
#include "codeseg0/7A430.h"
#include "codeseg0/7BA50.h"
#include "codeseg0/7CBC0.h"
#include "codeseg0/7F6A0.h"
#include "codeseg0/7FCE0.h"
#include "codeseg0/87010.h"
#include "codeseg0/88690.h"
#include "codeseg0/8E670.h"
#include "codeseg0/8EFE0.h"
#include "codeseg0/95500.h"
#include "codeseg0/A06F0.h"
#include "codeseg0/common0.h"
#include "codeseg0/main.h"
#include "codeseg1/EB300.h"
#include "codeseg1/common1.h"
#include "spseg1/spinit.h"
#include "libmus.h"

#define IDLELOOP_STACKSIZE 0x1000
#define MAINLOOP_STACKSIZE 0x8000
#define NUM_PI_MSGS 256
#define PHYSICAL_SEGMENT 0
#define STATIC_SEGMENT 1
#define FRAMEBUFFER_SEGMENT 2
#define OUTPUT_BUFFER_SIZE 65536

/*.data*/
static s32 D_800BD3D0 = 2;
/*800BD3D4*/ s32 gScreenWidth = SCREEN_WIDTH;
/*800BD3D8*/ s32 gScreenHeight = SCREEN_HEIGHT;
/*800BD3E0*/ static s64 D_800BD3E0 = 0LL;
/*800BD3E8*/ s32 D_800BD3E8 = 0;
/*800BD3EC*/ static u8 r = 0;
/*800BD3ED*/ static u8 g = 0;
/*800BD3EE*/ static u8 b = 0;
/*800BD3F0*/ static s32 D_800BD3F0 = 0;
/*800BD3F4*/ static s32 D_800BD3F4 = 0;
u8 D_800BD3F8 = 0;
/*800BD3F9*/ s8 D_800BD3F9 = 1;
/*800BD3FC*/ static s32 D_800BD3FC = 0;
/*800BD400*/ static OSScMsg replyMsg = {2, {0}};
/*800BD420*/ static s32 framebufferIndex = 0;
/*800BD424*/ s32 gGfxTaskIndex = 0;
static s32 D_800BD428 = 0;
/*800BD42C*/ static u8 D_800BD42C = 1;
/*800BD42D*/ static u8 D_800BD42D = 0;
static u16 D_800BD42E = 0;

/*.bss*/
/*800EA700*/ static OSThread idleLoopThread;
/*800EA8B0*/ static u64 idleLoopThreadStack[IDLELOOP_STACKSIZE / sizeof(u64)];
/*800EB8B0*/ static OSThread mainLoopThread;
/*800EBA60*/ static u64 mainLoopThreadStack[MAINLOOP_STACKSIZE / sizeof(u64)];
static u8 D_800F3A60[0x11B0];
static u8 D_800F4C10[0x2000];
static u8 D_800F6C10[0x08];
static u8 D_800F6C18[0x08];
/*800F6C20*/ static OSMesg piMessages[NUM_PI_MSGS];
/*800F7020*/ static OSMesgQueue piMessageQ;
/*800F7038*/ static s8 viMode;

/*.comm*/
/*800FF530*/ void *gFramebuffer[3];
/*80118160*/ s32 gGfxDebugTime;
/*80119A5C*/ s32 D_80119A5C;
/*80119A78*/ OSMesgQueue D_80119A78;
/*8011BC60*/ Dynamic gDynamic[GFX_TASKS];
/*8012E158*/ OSViMode *D_8012E158;
/*801A1A20*/ u64 gfxYieldBuf[OS_YIELD_DATA_SIZE / sizeof(u64)];
/*801AC8B8*/ OSMesgQueue gfxFrameMsgQ;
/*801ACB00*/ OSScTask gGfxTask[GFX_TASKS];
/*801AE498*/ s64 D_801AE498;
/*801AEA40*/ u64 gDramStack[SP_DRAM_STACK_SIZE64];
/*801B0D40*/ u64 gOutputBuffer[OUTPUT_BUFFER_SIZE / sizeof(u64)];

/*.text*/
static void idleLoop(void *);
static void mainLoop(void *);
static void createGfxTask(void);
static void func_800036DC();

/*80000450*/
void func_80000450(void)
{
    D_8012E158 = &osViModeTable[OS_VI_PAL_LAF1];
    osViModeTable[OS_VI_PAL_LAF1].fldRegs[0].yScale = 0x800;
    D_8012E158 = &osViModeTable[OS_VI_PAL_LAN1];
    osViModeTable[OS_VI_PAL_LAF1].fldRegs[1].yScale = 0x800;
    osViModeTable[OS_VI_PAL_LAN1].fldRegs[0].yScale = 0x400;
    osViModeTable[OS_VI_PAL_LAN1].fldRegs[1].yScale = 0x400;
    osViModeTable[OS_VI_PAL_HAF1].fldRegs[0].yScale = 0x400;
    D_8012E158 = &osViModeTable[OS_VI_NTSC_HAF1];
    osViModeTable[OS_VI_NTSC_HAF1].fldRegs[0].yScale = 0x800;
    osViModeTable[OS_VI_NTSC_HAF1].fldRegs[1].yScale = 0x800;
    D_8012E158 = &osViModeTable[OS_VI_PAL_HAF1];
    osViModeTable[OS_VI_PAL_HAF1].fldRegs[1].yScale = 0x400;
    D_8012E158 = &osViModeTable[OS_VI_MPAL_HAF1];
    osViModeTable[OS_VI_MPAL_HAF1].fldRegs[0].yScale = 0x800;
    osViModeTable[OS_VI_MPAL_HAF1].fldRegs[1].yScale = 0x800;
    osViBlack(1U);
}

/*80000508*/
static void func_80000508(void)
{
    D_8012E158 = &osViModeTable[OS_VI_PAL_LAF1];
    osViModeTable[OS_VI_PAL_LAF1].fldRegs[0].vStart = 0x2D0237;
    osViModeTable[OS_VI_PAL_LAF1].fldRegs[1].vStart = 0x2F0239;
    D_8012E158 = &osViModeTable[OS_VI_PAL_LAF1];
    osViModeTable[OS_VI_PAL_LAF1].fldRegs[0].yScale = 0x6E5;
    osViModeTable[OS_VI_PAL_LAF1].fldRegs[1].yScale = 0x6E5;
    D_8012E158 = &osViModeTable[OS_VI_PAL_LAN1];
    osViModeTable[OS_VI_PAL_LAN1].fldRegs[0].yScale = 0x37B;
    osViModeTable[OS_VI_PAL_LAN1].fldRegs[1].yScale = 0x37B;
    D_8012E158 = &osViModeTable[OS_VI_NTSC_HAF1];
    osViModeTable[OS_VI_NTSC_HAF1].fldRegs[0].yScale = 0x66C;
    osViModeTable[OS_VI_NTSC_HAF1].fldRegs[1].yScale = 0x66C;
    D_8012E158 = &osViModeTable[OS_VI_PAL_HAF1];
    osViModeTable[OS_VI_PAL_HAF1].fldRegs[0].yScale = 0x574;
    osViModeTable[OS_VI_PAL_HAF1].fldRegs[1].yScale = 0x574;
    D_8012E158 = &osViModeTable[OS_VI_MPAL_HAF1];
    osViModeTable[OS_VI_MPAL_HAF1].fldRegs[0].yScale = 0x66C;
    osViModeTable[OS_VI_MPAL_HAF1].fldRegs[1].yScale = 0x66C;
}

/*800005D8*/
static void func_800005D8(void)
{
    D_8012E158 = &osViModeTable[OS_VI_PAL_LAF1];
    osViModeTable[OS_VI_PAL_LAF1].fldRegs[0].vStart = 0x4B0237;
    osViModeTable[OS_VI_PAL_LAF1].fldRegs[1].vStart = 0x4D0239;
}

/*80000610*/
void func_80000610(void)
{
    D_800BD3F4 = 1;
}

/*80000624*/
void func_80000624(ProcPointer proc)
{
    D_80119A5C = 5;
    D_800FF53C = proc;
    D_800BD3E8 = 1;
    func_8007F050();
    func_80000450();
    D_800BD3F9 = 6;
}

/*80000678*/
static void func_80000678(void)
{
    if (D_80119A5C == 0)
    {
        func_8002AAC0();
        D_800FF53C();
    }
}

/*800006B4*/
static void func_800006B4(void)
{
    s32 i;
    if (func_8008AEF0() & 0xFF)
    {
        for (i = 0; i < 4; i++)
        {
            if (D_8016D174[i] == 0)
                break;
        }

        D_801CC8CA = i;
        func_80000624(&func_801C6560);
    }
}

/*8000071C*/
static void func_8000071C(void)
{
    D_8012E158 = &osViModeTable[OS_VI_PAL_LAF1];
    osViModeTable[OS_VI_PAL_LAF1].comRegs.vSync = 0x270;
    osViModeTable[OS_VI_PAL_LAF1].fldRegs[0].yScale = 0x800;
    osViModeTable[OS_VI_PAL_LAF1].fldRegs[1].yScale = 0x800;
    osViModeTable[OS_VI_PAL_LAF1].fldRegs[0].origin = 0x280;
    osViModeTable[OS_VI_PAL_LAF1].fldRegs[1].origin = 0x500;
    osViModeTable[OS_VI_PAL_LAF1].fldRegs[0].vStart = 0x2D0237;
    D_8012E158 = &osViModeTable[OS_VI_PAL_LAN1];
    osViModeTable[OS_VI_PAL_LAF1].fldRegs[1].vStart = 0x2F0239;
    osViModeTable[OS_VI_PAL_LAN1].fldRegs[0].yScale = 0x400;
    D_8012E158 = &osViModeTable[OS_VI_PAL_HAF1];
    osViModeTable[OS_VI_PAL_HAF1].comRegs.width = 0x200;
    osViModeTable[OS_VI_PAL_HAF1].comRegs.xScale = 0x340;
    osViModeTable[OS_VI_PAL_LAN1].fldRegs[0].vStart = 0x2D0237;
    osViModeTable[OS_VI_PAL_LAN1].fldRegs[1].vStart = 0x2D0237;
    osViModeTable[OS_VI_PAL_HAF1].fldRegs[0].vStart = 0x2D0237;
    osViModeTable[OS_VI_PAL_HAF1].fldRegs[0].yScale = 0x400;
    osViModeTable[OS_VI_PAL_HAF1].fldRegs[1].yScale = 0x400;
    osViModeTable[OS_VI_PAL_HAF1].fldRegs[0].origin = 0x400;
    D_8012E158 = &osViModeTable[OS_VI_NTSC_LAF1];
    osViModeTable[OS_VI_PAL_HAF1].fldRegs[1].origin = 0x800;
    osViModeTable[OS_VI_PAL_HAF1].fldRegs[1].vStart = 0x2F0239;
    osViModeTable[OS_VI_NTSC_LAF1].comRegs.vSync = 0x20C;
    osViModeTable[OS_VI_NTSC_LAF1].fldRegs[0].yScale = 0x800;
    osViModeTable[OS_VI_NTSC_LAF1].fldRegs[1].yScale = 0x800;
    osViModeTable[OS_VI_NTSC_LAF1].fldRegs[0].origin = 0x280;
    osViModeTable[OS_VI_NTSC_LAF1].fldRegs[1].origin = 0x500;
    D_8012E158 = &osViModeTable[OS_VI_NTSC_HAF1];
    osViModeTable[OS_VI_NTSC_LAF1].fldRegs[0].vStart = 0x2301FD;
    osViModeTable[OS_VI_NTSC_LAF1].fldRegs[1].vStart = 0x2501FF;
    osViModeTable[OS_VI_NTSC_HAF1].comRegs.vSync = 0x20C;
    osViModeTable[OS_VI_NTSC_HAF1].comRegs.width = 0x200;
    osViModeTable[OS_VI_NTSC_HAF1].comRegs.xScale = 0x340;
    osViModeTable[OS_VI_NTSC_HAF1].fldRegs[0].origin = 0x400;
    osViModeTable[OS_VI_NTSC_HAF1].fldRegs[1].origin = 0x800;
    osViModeTable[OS_VI_NTSC_HAF1].fldRegs[0].vStart = 0x2301FD;
    osViModeTable[OS_VI_NTSC_HAF1].fldRegs[1].vStart = 0x2501FF;
    D_8012E158 = &osViModeTable[OS_VI_MPAL_LAF1];
    osViModeTable[OS_VI_MPAL_LAF1].comRegs.vSync = 0x20C;
    osViModeTable[OS_VI_MPAL_LAF1].fldRegs[0].yScale = 0x800;
    osViModeTable[OS_VI_MPAL_LAF1].fldRegs[1].yScale = 0x800;
    osViModeTable[OS_VI_MPAL_LAF1].fldRegs[0].origin = 0x280;
    osViModeTable[OS_VI_MPAL_LAF1].fldRegs[1].origin = 0x500;
    D_8012E158 = &osViModeTable[OS_VI_MPAL_HAF1];
    osViModeTable[OS_VI_MPAL_HAF1].comRegs.vSync = 0x20C;
    osViModeTable[OS_VI_MPAL_HAF1].comRegs.width = 0x200;
    osViModeTable[OS_VI_MPAL_HAF1].comRegs.xScale = 0x340;
    osViModeTable[OS_VI_MPAL_HAF1].fldRegs[0].origin = 0x400;
    osViModeTable[OS_VI_MPAL_HAF1].fldRegs[1].origin = 0x800;
}

/*8000090C*/
void boot(void)
{
    osViBlack(1U);
    D_800BD3F4 = 0;
    D_800BD3F0 = 0;
    osInitialize();

    switch (osTvType)
    {
    case OS_TV_PAL:
        viMode = OS_VI_PAL_LAN1;
        break;
    case OS_TV_NTSC:
        viMode = OS_VI_NTSC_LAN1;
        break;
    case OS_TV_MPAL:
        viMode = OS_VI_MPAL_LAN1;
        break;
    }

    osCreateThread(&idleLoopThread, 1, idleLoop, NULL, &idleLoopThreadStack[IDLELOOP_STACKSIZE / sizeof(u64)], 10);
    osStartThread(&idleLoopThread);
}

/*800009D0*/
static void idleLoop(void *arg)
{
    osCreatePiManager(OS_PRIORITY_PIMGR, &piMessageQ, piMessages, NUM_PI_MSGS);
    osCreateThread(&mainLoopThread, 3, mainLoop, arg, &mainLoopThreadStack[MAINLOOP_STACKSIZE / sizeof(u64)], 10);
    osStartThread(&mainLoopThread);
    osSetThreadPri(&idleLoopThread, 0);
    while (1)
        ;
}

/*80000A6C*/
void readRom(u8 *segStart, u8 *romStart, s32 size)
{
    return dmaRomToRam(romStart, segStart, size);
}

/*80000A94*/
void func_80000A94(void)
{
    OSTime start;
    OSTime end;

    while (D_80119A78.validCount >= D_80119A78.msgCount)
    {
        osRecvMesg(&D_80119A78, NULL, 1);
    }
    osRecvMesg(&D_80119A78, NULL, 1);
    start = osGetTime();
    osRecvMesg(&D_80119A78, NULL, 1);
    end = osGetTime();

    D_80138688 = end - start;
}

/*0x80000B68*/
static void clearDepthBuffer(void)
{
    gDPSetDepthImage(gpDisplaylist++, OS_K0_TO_PHYSICAL(gDepthBuffer));
    gDPSetCycleType(gpDisplaylist++, G_CYC_FILL);
    gDPSetColorImage(gpDisplaylist++, G_IM_FMT_RGBA, G_IM_SIZ_16b, gScreenWidth, OS_K0_TO_PHYSICAL(gDepthBuffer));
    gDPSetFillColor(gpDisplaylist++, GPACK_ZDZ(G_MAXFBZ, 0) << 16 | GPACK_ZDZ(G_MAXFBZ, 0));
    gDPFillRectangle(gpDisplaylist++, 0, 0, gScreenWidth - 1, gScreenHeight - 1);
    gDPPipeSync(gpDisplaylist++);
    gDPSetCycleType(gpDisplaylist++, G_CYC_1CYCLE);
}

/*80000C74*/
void func_80000C74(void)
{
    gDPPipeSync(gpDisplaylist++);
    gDPSetCycleType(gpDisplaylist++, G_CYC_FILL);
    gDPSetRenderMode(gpDisplaylist++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetColorImage(gpDisplaylist++, G_IM_FMT_RGBA, G_IM_SIZ_16b, gScreenWidth, OS_K0_TO_PHYSICAL(gDepthBuffer));
    gDPSetFillColor(gpDisplaylist++, GPACK_ZDZ(G_MAXFBZ, 0) << 16 | GPACK_ZDZ(G_MAXFBZ, 0));
    gDPFillRectangle(gpDisplaylist++, 12, 12, gScreenWidth - 12, gScreenHeight - 12);
    gDPPipeSync(gpDisplaylist++);
    gDPSetColorImage(gpDisplaylist++, G_IM_FMT_RGBA, G_IM_SIZ_16b, gScreenWidth, OS_K0_TO_PHYSICAL(gFramebuffer[framebufferIndex]));
    gDPSetCycleType(gpDisplaylist++, G_CYC_2CYCLE);
}

/*80000DDC*/
static void func_80000DDC(void)
{
    gDPSetColorImage(gpDisplaylist++, G_IM_FMT_RGBA, G_IM_SIZ_16b, gScreenWidth, OS_K0_TO_PHYSICAL(gFramebuffer[framebufferIndex]));
    if (D_800BD3E8 != 0)
    {
        gDPSetCycleType(gpDisplaylist++, G_CYC_FILL);
        gDPSetFillColor(gpDisplaylist++, GPACK_RGBA5551(r, g, b, 1) << 16 | GPACK_RGBA5551(r, g, b, 1));
        gDPFillRectangle(gpDisplaylist++, 0, 0, gScreenWidth - 1, gScreenHeight - 1);
    }
}

/*80000F00*/
static void func_80000F00(void)
{
    if (D_800BD3F9 != 3)
    {
        func_800036DC();
        return;
    }
    if (D_800BD3F0 == 0)
    {
        if (D_801A1970 != 0)
            func_80008E3C();
        if (D_801AE914 != 0)
            func_800036DC();
    }
}

/*80000F68*/
static void func_80000F68(s16 arg0)
{
    D_80117ED8[arg0].unk_80 = 0;

    if (D_801CE4C6[arg0] >= 4U)
    {
        D_80117ED8[arg0].unk_80 = 4;
    }
    if ((D_801CE4C6[arg0] & 3) >= 2U)
    {
        D_80117ED8[arg0].unk_80 |= 1;
    }
    if (D_801CE4C6[arg0] & 1)
    {
        D_80117ED8[arg0].unk_80 |= 2;
    }
    func_80035794(arg0);
}

/*80001038*/
static void func_80001038(void)
{
    s16 i;
    s16 temp;

    if (D_800BD3F0 != 0)
    {
        if (--D_800BD3F0 != 1)
        {
            return;
        }
        D_800BD3E8 = 0;
        func_80000610();
        D_800BD3F0 = 0;
    }
    func_80006CC0();
    if (D_801AE914 != 0)
    {
        if (D_800BD42C != 0)
        {
            func_8008A654();
            D_800BD42C = 0;
        }
        func_801C4B34();
        for (i = 0; i < D_8012C470; i++)
        {
            func_80000F68(i);
        }
    }
    else
    {
        D_800BD42C = 1;
        if ((D_80199524 != 0) && (func_8008A070() & 0xFF))
        {
            D_80199524 = 0;
        }
        func_80040AA0(1, "SM");
        func_80040B2C(1);
        D_80197DE0 += 4;
        D_80168D0C = RAND(0x7FFF);
        D_801A1958.unk_0C++;
        func_8002AC70();
        if (D_801AD470 != 0)
        {
            func_8008DE14();
        }
        if (D_800DF1A8 != -1)
        {
            func_8004EA40(0);
        }
        func_80064AA0();
        func_80064E78();
        func_80069160();
        func_80068E9C();
        func_8004FC4C();
        func_8004FF08();
        func_800698E8();
        func_80007AB8();
        func_80040890();
        func_800502A0();
        func_8009542C();
        func_800A4478();
        func_800504F4();
        func_8005087C();
        for (i = 0; i < D_8012C470; i++)
        {
            func_80017268(D_80117ED8[i].unk_4A);
        }
        func_80069E50();
        func_8009FAF0();
        func_80040B70(1);
        func_80040AA0(2, "SW");
        func_80040B2C(2);
        func_8004F044();
        func_8007B4CC();
        func_800879E8();
        func_8001F388();
        func_8001F44C();
        func_800946B8();
        func_800514C8();
        func_8003DD54();
        func_80079830();
        func_80079560();
        func_8004EC38();
        if (D_800FE416 == 0x10)
        {
            func_80094D18();
        }
        if (D_800FE416 == 2)
        {
            func_80095220();
        }
        func_80040B70(2);

        for (i = 0; i < D_8012C470; i++)
        {
            func_8000EB4C(i, 0, 0, 0, 0);
            func_8000EA0C(i, D_800DF1AC[i], D_800DF1AC[i], D_800DF1AC[i], (s32)D_800DF1AC[i]);

            if (D_8019B940[D_80106D50[D_80117ED8[i].unk_4A]].unk_00 & 0x40)
            {
                func_8000EA0C(i, 0, 255, 255, 128);
            }
            else if (D_8010A940[i].unk_07 != 0)
            {
                func_8000EA0C(i, 0, 255, 0, 128);
            }
            else if (D_80117ED8[i].unk_55 != 0)
            {
                func_8000EA0C(i, D_800BD710[D_801A19EC].unk_00, D_800BD710[D_801A19EC].unk_01, D_800BD710[D_801A19EC].unk_02, D_800BD710[D_801A19EC].unk_03);
            }
            else if (D_80117ED8[i].unk_82 > 0)
            {
                func_8000EA0C(i, 0, 255, 0, D_80117ED8[i].unk_82 / 2);
            }
            if (D_80106D30[i] != 0)
            {
                func_8000EA0C(i, 0, 0, 0, 200);
            }

            if (D_80117ED8[i].unk_45 != 0)
            {
                temp = D_80117ED8[i].unk_4E;
                if (D_80117ED8[i].unk_45 == 4)
                {
                    func_8000EA0C(i, 0xFF - temp, 0xFF - temp, 0xFF - temp, 255);
                }
                else if (D_80117ED8[i].unk_45 == 3)
                {
                    func_8000EA0C(i, 0xFF - temp, -temp, -temp, 255);
                }
                else
                {
                    func_8000EA0C(i, -temp, -temp, -temp, temp);
                }
            }
        }
        if (D_800E1748 >= 0)
        {
            func_8000EB4C(4, 0, 0, 0, (s32)(s16)(0x120 - (D_800E1748 * 8)));
        }
        else
        {
            func_8000EA0C(4, 0, 0, 0, -8);
        }

        if ((D_800E1748 > 0) && (--D_800E1748 == 0))
        {
            MusStop(MUSFLAG_EFFECTS | MUSFLAG_SONGS, 0);
            D_800E1748 = -1;
            D_8012FC90 = 0;
            switch (D_80118148)
            {
            case 2:
                D_800DEDE0 = 1;
                return;
            case 1:
                if (D_800FE416 == 0x16)
                {
                    func_80000624(func_801C97F8);
                }
                else
                {
                    func_80000624(func_801C9B28);
                }
                break;
            case 3:
                D_800DEDE0 = 2;
                return;
            case 4:
                D_800DEDE0 = 3;
                return;
            case 5:
                func_80000624(func_801C15CC);
                break;
            case 0:
                func_80000624(func_801C3E08);
                break;
            default:
                func_80000624(func_801C3E08);
                break;
            }
        }
    }
}

/*800017AC*/
static void func_800017AC(void)
{
    s32 i;

    func_8008A724();
    if (D_8012FC90 != 0)
    {
        func_801C9D68();
    }
    else
    {
        for (i = 0; i < 4; i++)
        {
            func_80003990(i);
        }
        if ((D_800BD3F9 == 3) && (D_801CDB4C != 0))
        {
            func_801C9F74();
        }
        func_801C146C();
    }

    switch (D_800BD3F9)
    {
    case 0:
        func_800006B4();
        break;
    case 9:
        func_801C97F0();
        break;
    case 10:
        func_801C764C();
        break;
    case 11:
        func_801C899C();
        break;
    case 12:
        func_801C8F54();
        break;
    case 1:
        func_801C1950();
        break;
    case 2:
        func_801C4B34();
        break;
    case 5:
        func_801C542C();
        break;
    case 4:
        func_801C63CC();
        break;
    case 8:
        func_801C66D8();
        break;
    case 6:
        func_80000678();
        break;
    case 3:
        func_80001038();
        break;
    case 13:
        func_801C3370();
        break;
    case 14:
        func_801C9924();
        break;
    case 17:
        func_801C3524();
        break;
    }
    if (D_800BD42D != 0)
    {
        D_800BD42D = 0;
        func_800017AC();
    }
}

/*80001968*/
static void setupSegments(void)
{
    gpDisplaylist = gDisplaylist[gGfxTaskIndex];
    gpVertex = gVertex[gGfxTaskIndex];
    gpDynamic = &gDynamic[gGfxTaskIndex];
    gSPSegment(gpDisplaylist++, PHYSICAL_SEGMENT, 0x0);
    gSPSegment(gpDisplaylist++, STATIC_SEGMENT, OS_K0_TO_PHYSICAL(gStaticSegment));
    gSPSegment(gpDisplaylist++, FRAMEBUFFER_SEGMENT, OS_K0_TO_PHYSICAL(gFramebuffer[framebufferIndex]));
    gSPDisplayList(gpDisplaylist++, rdpInitDl);
    gSPDisplayList(gpDisplaylist++, rspInitDl);
    gDPSetScissor(gpDisplaylist++, G_SC_NON_INTERLACE, 0, 0, gScreenWidth, gScreenHeight);
}

/*80001AF8*/
static void func_80001AF8(void)
{
    setupSegments();
    clearDepthBuffer();
    func_80000DDC();
}

/*80001B28*/
static void createGfxTask(void)
{
    OSScTask *t;
    char *ucode_boot_end;
    s32 ucode_boot_size;

    ucode_boot_end = (char *)rspbootTextEnd;
    ucode_boot_size = ucode_boot_end - (char *)rspbootTextStart;
    ucode_boot_end = NULL;

    gDPFullSync(gpDisplaylist++);
    gSPEndDisplayList(gpDisplaylist++);
    t = &gGfxTask[gGfxTaskIndex];
    t->list.t.data_ptr = (u64 *)gDisplaylist[gGfxTaskIndex];
    t->list.t.data_size = (s32)(gpDisplaylist - gDisplaylist[gGfxTaskIndex]) * sizeof(Gfx);
    t->list.t.type = M_GFXTASK;
    t->list.t.flags = 0;
    t->list.t.ucode_boot = (u64 *)rspbootTextStart;
    t->list.t.ucode_boot_size = ucode_boot_size;
    t->list.t.ucode = (u64 *)gspF3DLX2_NoN_fifoTextStart;
    t->list.t.ucode_data = (u64 *)gspF3DEX2_NoN_fifoDataStart;
    t->list.t.ucode_data_size = SP_UCODE_DATA_SIZE;
    t->list.t.dram_stack = (u64 *)gDramStack;
    t->list.t.dram_stack_size = SP_DRAM_STACK_SIZE8;
    t->list.t.output_buff = (u64 *)gOutputBuffer;
    t->list.t.output_buff_size = (u64 *)&gOutputBuffer[OUTPUT_BUFFER_SIZE / sizeof(u64)];
    t->list.t.yield_data_ptr = (u64 *)gfxYieldBuf;
    t->list.t.yield_data_size = OS_YIELD_DATA_SIZE;
    t->next = NULL;
    t->flags = OS_SC_NEEDS_RDP | OS_SC_NEEDS_RSP | OS_SC_LAST_TASK | OS_SC_SWAPBUFFER;
    t->msgQ = &gfxFrameMsgQ;
    t->msg = &replyMsg;
    t->framebuffer = gFramebuffer[framebufferIndex];
    osWritebackDCacheAll();
    osSendMesg(osScGetCmdQ(&gScheduler), t, 0);
    gGfxDebugTime = gGfxTask[gGfxTaskIndex].totalTime;
}

/*80001CFC*/
void func_80001CFC(void)
{
    D_800FE9E0 = 0LL;
    D_801AE498 = 0LL;
    D_800BD3E0 = 0LL;
    D_80197DE0 = 0;
}

/*80001D44*/
static void func_80001D44(void)
{
    s16 i;
    s16 width;
    s16 height;

    func_8002AAC0();
    MusStop(MUSFLAG_EFFECTS | MUSFLAG_SONGS, 0);
    switch (D_801CE5AC)
    {
    case 0:
        width = 320;
        height = 240;
        break;
    case 1:
        width = 320;
        height = 480;
        break;
    case 2:
        width = 512;
        height = 384;
        break;
    }
    D_8012C470 = D_801CDC65;
    if (D_801CDC65 == 0)
    {
        D_8012C470 = 1;
    }
    for (i = 0; i < D_8012C470; i++)
    {
        func_80000F68(i);
        func_80095390(i);
    }
    D_800DEEA0 = 0;
    if ((u32)osMemSize > 0x400000U)
    {
        D_800DEEA0 = 1;
        D_801AE8B8 = 0xA000;
        D_801AE8FC = 0x6000;
    }
    else if (D_8012C470 < 2)
    {
        D_801AE8B8 = 0x2800;
        D_801AE8FC = 0x1800;
    }
    else
    {
        D_801AE8B8 = 0x3C00;
        D_801AE8FC = 0x2400;
    }
    func_80002014(width, height, D_801AE8B8, D_801AE8FC);
    func_8001F928(width, height);
    r = 0;
    g = 0;
    b = 0;
    D_800BD3E8 = 1;
    D_801A1970 = 1;
    func_80000DDC();
    clearDepthBuffer();
    D_800DF585 = 0;
}

/*80001F40*/
void func_80001F40(void)
{
    func_80001D44();
    func_80050408();
    func_80008810(D_800DF950);
    D_800BD3F9 = 3;
    D_800BD42D = 1;
    D_801CA144 = 0.0f;
    func_80002390();
    D_800BD3F0 = 0xA;
}

/*80001FAC*/
void func_80001FAC(void)
{
    D_801CDC65 = 1;
    func_80001D44();
    D_800BD3F9 = 3;
    D_800BD42D = 0;
    D_801CA144 = 0.0f;
    func_80002390();
    D_800BD3F0 = 0x64;
    D_800DEDE0 = 4;
}

INCLUDE_ASM(s32, "src/codeseg0/main", func_80002014);

/*80002390*/
void func_80002390(void)
{
    func_8001F928(gScreenWidth, gScreenHeight);
    switch (osTvType)
    {
    case OS_TV_NTSC:
        if (gScreenWidth == 512)
        {
            viMode = OS_VI_NTSC_HAF1;
        }
        else
        {
            if (gScreenHeight == 240)
            {
                viMode = OS_VI_NTSC_LAN1;
            }
            else
            {
                viMode = OS_VI_NTSC_LAF1;
            }
        }
        break;
    case OS_TV_PAL:
        if (gScreenWidth == 512)
        {
            viMode = OS_VI_PAL_HAF1;
        }
        else
        {
            if (gScreenHeight == 240)
            {
                viMode = OS_VI_PAL_LAN1;
            }
            else
            {
                viMode = OS_VI_PAL_LAF1;
            }
        }
        break;
    case OS_TV_MPAL:
        if (gScreenWidth == 512)
        {
            viMode = OS_VI_MPAL_HAF1;
        }
        else
        {
            if (gScreenHeight == 240)
            {
                viMode = OS_VI_MPAL_LAN1;
            }
            else
            {
                viMode = OS_VI_MPAL_LAF1;
            }
        }
        break;
    }
}

/*80002494*/
static void func_80002494(void)
{
    func_80002014(320, 480, 0x2800, 0);
    func_801C10C8();
    setCameraPosition(0.0f, 0.0f, -500.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    func_8007FD8C(&D_800DFB08, 11);
    func_8007FD8C(&D_800DFA90, 2);
    D_800BD3F9 = 0;
    D_800BD3E8 = 1;
    func_80002390();
    func_80000610();
}

/*.rodata*/
const char D_800E4468[] = "DUKE ZERO HOUR.A";

INCLUDE_ASM(s32, "src/codeseg0/main", mainLoop);

INCLUDE_ASM(s32, "src/codeseg0/main", func_800031F8);

/*800034F4*/
static void func_800034F4(void)
{
    guPerspective(
        &gpDynamic->projection,
        &gPerspNorm,
        37.0,
        1.3333334,
        10.0,
        5600.0,
        1.0);

    guLookAt(
        &gpDynamic->viewing,
        gPosition.xEye,
        gPosition.yEye,
        gPosition.zEye,
        gPosition.xAt,
        gPosition.yAt,
        gPosition.zAt,
        0.0,
        1.0,
        0.0);

    gSPMatrix(gpDisplaylist++, &gpDynamic->projection, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gpDisplaylist++, &gpDynamic->viewing, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
    gSPPerspNormalize(gpDisplaylist++, gPerspNorm);

    guLookAtReflect(
        &gpDynamic->viewing,
        &gpDynamic->lookat,
        gPosition.xEye,
        gPosition.yEye,
        gPosition.zEye,
        gPosition.xAt,
        gPosition.yAt,
        gPosition.zAt,
        0.0,
        1.0,
        0.0);

    gSPLookAtX(gpDisplaylist++, &gpDynamic->lookat.l[0]);
    gSPLookAtY(gpDisplaylist++, &gpDynamic->lookat.l[1]);
}

/*800036DC*/
static void func_800036DC(void)
{
    gSPViewport(gpDisplaylist++, &D_800DCB10);
    guMtxIdent(&gpDynamic->identity);
    guScale(&gpDynamic->scale, 0.25, 0.25, 0.25);
    D_801AE528 = 0;
    D_80168D18 = 0;
    D_800FE3F4 = 0;
    gDPPipeSync(gpDisplaylist++);
    gDPSetScissor(gpDisplaylist++, G_SC_NON_INTERLACE, 0, 0, gScreenWidth, gScreenHeight);
    gDPSetCycleType(gpDisplaylist++, G_CYC_1CYCLE);
    gDPSetRenderMode(gpDisplaylist++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineMode(gpDisplaylist++, G_CC_MODULATEIA, G_CC_MODULATEIA);
    gDPSetTextureFilter(gpDisplaylist++, G_TF_BILERP);
    gDPSetTextureLUT(gpDisplaylist++, G_TT_RGBA16);
    gSPClearGeometryMode(gpDisplaylist++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gSPSetGeometryMode(gpDisplaylist++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
    gDPSetTexturePersp(gpDisplaylist++, G_TP_PERSP);
    func_800034F4();
    gSPTexture(gpDisplaylist++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    func_8007EF70();
}

INCLUDE_ASM(s32, "src/codeseg0/main", func_80003940);
