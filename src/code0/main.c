#include "common.h"
#include "code0/audio.h"
#include "code0/9410.h"
#include "code0/4590.h"
#include "code0/4600.h"
#include "code0/17B30.h"
#include "code0/1E7A0.h"
#include "code0/20490.h"
#include "code0/cache1d.h"
#include "code0/engine.h"
#include "code0/35EA0.h"
#include "code0/37090.h"
#include "code0/3FAD0.h"
#include "code0/416A0.h"
#include "code0/41940.h"
#include "code0/64530.h"
#include "code0/6ACA0.h"
#include "code0/7A430.h"
#include "code0/7BA50.h"
#include "code0/debug.h"
#include "code0/7F6A0.h"
#include "code0/7FCE0.h"
#include "code0/84490.h"
#include "code0/87010.h"
#include "code0/88690.h"
#include "code0/8E670.h"
#include "code0/8EFE0.h"
#include "code0/95500.h"
#include "code0/A06F0.h"
#include "code0/main.h"
#include "code1/code1.h"
#include "code1/EB300.h"
#include "static/spinit.h"
#include "static/sintable.h"
#include "static/radarang.h"
#include "libmus.h"
#include "assert.h"

DECL_STATIC_SEG_SYM(gTileInfo);
DECL_STATIC_SEG_SYM(gWeaponStrInfo);
DECL_STATIC_SEG_SYM(gWeaponStrInfoCount);
DECL_STATIC_SEG_SYM(gKeyStrInfo);
DECL_STATIC_SEG_SYM(gMsgStrInfo);
DECL_STATIC_SEG_SYM(gMapStrInfo);
DECL_STATIC_SEG_SYM(gActionStrInfo);
DECL_STATIC_SEG_SYM(gActionStrInfoCount);
DECL_STATIC_SEG_SYM(gLicenceStrInfo);
DECL_STATIC_SEG_SYM(gLicenceStrInfoCount);
DECL_STATIC_SEG_SYM(gCreditStrInfo);
DECL_STATIC_SEG_SYM(gCreditStrInfoCount);
DECL_STATIC_SEG_SYM(D_01022510);
DECL_STATIC_SEG_SYM(D_01022790);
DECL_STATIC_SEG_SYM(gControlPreset);
DECL_STATIC_SEG_SYM(gSinTable);
DECL_STATIC_SEG_SYM(gRadarang);
DECL_STATIC_SEG_SYM(D_01024590);
DECL_STATIC_SEG_SYM(D_010245E8);
DECL_STATIC_SEG_SYM(D_0102464C);
DECL_STATIC_SEG_SYM(D_010247AC);
DECL_STATIC_SEG_SYM(D_01025734);
DECL_STATIC_SEG_SYM(D_0102578C);
DECL_STATIC_SEG_SYM(D_0102583C);
DECL_STATIC_SEG_SYM(D_01025840);
DECL_STATIC_SEG_SYM(D_010258D8);
DECL_STATIC_SEG_SYM(D_01025908);
DECL_STATIC_SEG_SYM(D_01025968);
DECL_STATIC_SEG_SYM(D_010259B0);
DECL_STATIC_SEG_SYM(D_01025AAC);
DECL_STATIC_SEG_SYM(D_01025BA0);
DECL_STATIC_SEG_SYM(D_01025CFC);
DECL_STATIC_SEG_SYM(gMapInfo);
DECL_STATIC_SEG_SYM(D_01026910);

extern u8 code0_ROM_START[];
extern u8 code0_ROM_END[];
extern u8 code0_TEXT_SIZE[];
extern u8 code0_VRAM[];
extern u8 code0_VRAM_END[];
extern u8 code1_VRAM[];
extern u8 code1_VRAM_END[];
extern u8 code1_BSS_START[];
extern u8 code1_BSS_END[];
extern u8 code1_ROM_START[];
extern u8 code1_ROM_END[];
extern u8 code1_TEXT_START[];
extern u8 code1_TEXT_END[];
extern u8 static_ROM_START[];
extern u8 static_ROM_END[];

#define IDLELOOP_STACKSIZE 0x1000
#define VILOOP_STACKSIZE 0x1000
#define MAINLOOP_STACKSIZE 0x8000
#define SCHEDULER_STACKSIZE 0x2000
#define NUM_DMA_MSGS 256
#define PHYSICAL_SEGMENT 0
#define STATIC_SEGMENT 1
#define FRAMEBUFFER_SEGMENT 2
#define OUTPUT_BUFFER_SIZE 65536
#define STATIC_SEGMENT_VRAM (STATIC_SEGMENT << 24)
#define FRAMEBUFFER_ALIGN 16
#define DEPTHBUFFER_ALIGN 256

/*.data*/
/*800BD3D0*/ static s32 _framebufferCount = 2;
/*800BD3D4*/ s32 gScreenWidth = SCREEN_WIDTH;
/*800BD3D8*/ s32 gScreenHeight = SCREEN_HEIGHT;
/*800BD3E0*/ static s64 D_800BD3E0 = 0LL;
/*800BD3E8*/ s32 D_800BD3E8 = 0;
/*800BD3EC*/ static u8 _red = 0;
/*800BD3ED*/ static u8 _green = 0;
/*800BD3EE*/ static u8 _blue = 0;
/*800BD3F0*/ static s32 D_800BD3F0 = 0;
/*800BD3F4*/ static s32 D_800BD3F4 = 0;
/*800BD3F8*/ u8 D_800BD3F8 = 0;
/*800BD3F9*/ s8 D_800BD3F9 = 1;
/*800BD3FC*/ static s32 D_800BD3FC = 0;
/*800BD400*/ static OSScMsg _replyMsg = {2, {0}};
/*800BD420*/ static s32 _framebufferIndex = 0;
/*800BD424*/ s32 gGfxTaskIndex = 0;
/*800BD428*/ static s32 D_800BD428 = 0;
/*800BD42C*/ static u8 D_800BD42C = 1;
/*800BD42D*/ static u8 D_800BD42D = 0;
/*800BD42E*/ static s16 D_800BD42E = 0;

/*.bss*/
/*800EA700*/ static OSThread _idleLoopThread;
/*800EA8B0*/ static u64 _idleLoopThreadStack[IDLELOOP_STACKSIZE / sizeof(u64)] ALIGNED(16);
/*800EB8B0*/ static OSThread _mainLoopThread;
/*800EBA60*/ static u64 _mainLoopThreadStack[MAINLOOP_STACKSIZE / sizeof(u64)] ALIGNED(16);
/*800F3A60*/ static OSThread _viLoopThread;
/*800F3C10*/ static u64 _viLoopThreadStack[VILOOP_STACKSIZE / sizeof(u64)] ALIGNED(16);
/*800F4C10*/ static u64 _schedulerStack[SCHEDULER_STACKSIZE / sizeof(u64)] ALIGNED(16);
/*800F6C10*/ static OSScClient _retraceClient;
/*800F6C18*/ static OSScClient _gfxClient;
/*800F6C20*/ static OSMesg _piMessages[NUM_DMA_MSGS] ALIGNED(16);
/*800F7020*/ static OSMesgQueue _piMessageQ ALIGNED(8);
/*800F7038*/ static u8 _viMode;

/*.comm*/
/*800FE948*/ char ***gpKeyStrInfo;
/*800FF530*/ u8 *gFramebuffer[3];
/*800FF53C*/ ProcPointer D_800FF53C;
/*8010571C*/ u8 *D_8010571C;
/*8010A920*/ OSMesgQueue D_8010A920 ALIGNED(8);
/*80118160*/ s32 gGfxDebugTime;
/*80119A5C*/ s32 D_80119A5C;
/*80119A78*/ OSMesgQueue gRetraceMsgQ ALIGNED(8);
/*8011A668*/ u8 *gCacheMemEnd;
/*8011BC60*/ Dynamic gDynamic[GFX_TASKS] ALIGNED(16);
/*8012C990*/ OSMesg gGfxMessages[NUM_DMA_MSGS] ALIGNED(16);
/*8012E158*/ OSViMode *D_8012E158;
/*8012F6E4*/ _11B300UnkStruct1 *D_8012F6E4;
/*8012FD78*/ Gfx *gDisplayList[GFX_TASKS];
/*80137DE4*/ char **gpWeaponStrInfo;
/*80138684*/ u8 *gStaticSegment;
/*80138788*/ s64 D_80138788;
/*80138818*/ u32 D_80138818;
/*80138864*/ u8 *gDepthBuffer;
/*8013A648*/ u8 *gCacheMemStart;
/*80168D04*/ _11B300UnkStruct2 *D_80168D04;
/*8016D170*/ Vtx *gpVertexN64;
/*8016D178*/ s32 D_8016D178;
/*8016D184*/ Vtx *gVertexN64[GFX_TASKS];
/*80197D4C*/ u8 *D_80197D4C;
/*80197D50*/ char **gpActionStrInfo;
/*80197D58*/ OSMesgQueue gDmaMessageQ ALIGNED(8);
/*80199120*/ OSMesg gRetraceMessages[NUM_DMA_MSGS] ALIGNED(16);
/*801A196C*/ MsgStrInfo *gpMsgStrInfo;
/*801A1A20*/ u64 gfxYieldBuf[OS_YIELD_DATA_SIZE / sizeof(u64)] ALIGNED(16);
/*801A68CC*/ char **gpMapStrInfo;
/*801A6AF8*/ OSSched gScheduler;
/*801AC8B8*/ OSMesgQueue gGfxFrameMsgQ ALIGNED(8);
/*801AC9F0*/ TileInfo *gpTileInfo;
/*801ACB00*/ OSScTask gGfxTask[GFX_TASKS];
/*801ACBD8*/ _11D520UnkStruct1 *D_801ACBD8;
/*801AD070*/ OSMesg gDmaMessages[NUM_DMA_MSGS] ALIGNED(16);
/*801AE498*/ s64 D_801AE498;
/*801AE8B8*/ s32 gDisplayListMaxSize;
/*801AEA14*/ MapInfo *gpMapInfo;
/*801AE8FC*/ s32 gVertexN64MaxSize;
/*801AEA40*/ u64 gDramStack[SP_DRAM_STACK_SIZE64] ALIGNED(16);
/*801B0808*/ Gfx *gpDisplayList;
/*801B0818*/ s32 D_801B0818;
/*801B0D40*/ u64 gOutputBuffer[OUTPUT_BUFFER_SIZE / sizeof(u64)] ALIGNED(16);
/*801C0D60*/ Dynamic *gpDynamic;
/*801C0D64*/ OSMesg D_801C0D64;

/*.text*/
s32 osAfterPreNMI(void);
void func_80000000(u8 *, s32);
static void idleLoop(void *);
static void mainLoop(void *);
static void viLoop(void *);
static void main_800036DC(void);

/*80000450*/
void main_80000450(void)
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
static void main_80000508(void)
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
static void main_800005D8(void)
{
    D_8012E158 = &osViModeTable[OS_VI_PAL_LAF1];
    osViModeTable[OS_VI_PAL_LAF1].fldRegs[0].vStart = 0x4B0237;
    osViModeTable[OS_VI_PAL_LAF1].fldRegs[1].vStart = 0x4D0239;
}

/*80000610*/
void main_80000610(void)
{
    D_800BD3F4 = 1;
}

/*80000624*/
void main_80000624(ProcPointer proc)
{
    D_80119A5C = 5;
    D_800FF53C = proc;
    D_800BD3E8 = 1;
    func_8007F050();
    main_80000450();
    D_800BD3F9 = 6;
}

/*80000678*/
static void main_80000678(void)
{
    if (D_80119A5C == 0)
    {
        cache1d_8002AAC0();
        D_800FF53C();
    }
}

/*800006B4*/
static void main_800006B4(void)
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
        main_80000624(&func_801C6560);
    }
}

/*8000071C*/
static void main_8000071C(void)
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
#if defined (MODERN) || defined (NON_MATCHING)
    assert((u32)code0_TEXT_SIZE <= 0x100000);
    if ((code0_ROM_END - code0_ROM_START) > 0x100000)
    {
        osInvalDCache(code0_VRAM+0x100000, (code0_ROM_END-(code0_ROM_START+0x100000)));
        osPiRawStartDma(OS_READ,
                        (u32)(code0_ROM_START+0x100000),
                        (code0_VRAM+0x100000),
                        (code0_ROM_END-(code0_ROM_START+0x100000)));

        while (IO_READ(PI_STATUS_REG) & PI_STATUS_DMA_BUSY);
    }
#endif
    osViBlack(1);
    D_800BD3F4 = 0;
    D_800BD3F0 = 0;
    osInitialize();

    switch (osTvType)
    {
    case OS_TV_PAL:
        _viMode = OS_VI_PAL_LAN1;
        break;
    case OS_TV_NTSC:
        _viMode = OS_VI_NTSC_LAN1;
        break;
    case OS_TV_MPAL:
        _viMode = OS_VI_MPAL_LAN1;
        break;
    }

    osCreateThread(&_idleLoopThread, 1, idleLoop, NULL, &_idleLoopThreadStack[IDLELOOP_STACKSIZE / sizeof(u64)], 10);
    osStartThread(&_idleLoopThread);
}

/*800009D0*/
static void idleLoop(void *arg)
{
    osCreatePiManager(OS_PRIORITY_PIMGR, &_piMessageQ, _piMessages, NUM_DMA_MSGS);
    osCreateThread(&_mainLoopThread, 3, mainLoop, arg, &_mainLoopThreadStack[MAINLOOP_STACKSIZE / sizeof(u64)], 10);
    osStartThread(&_mainLoopThread);
    osSetThreadPri(&_idleLoopThread, 0);
    while (1);
}

/*80000A6C*/
void readRom(u8 *segStart, u8 *romStart, s32 size)
{
    return dmaRomToRam(romStart, segStart, size);
}

/*80000A94*/
void main_80000A94(void)
{
    OSTime start;
    OSTime end;

    while (gRetraceMsgQ.validCount >= gRetraceMsgQ.msgCount)
        osRecvMesg(&gRetraceMsgQ, NULL, OS_MESG_BLOCK);

    osRecvMesg(&gRetraceMsgQ, NULL, OS_MESG_BLOCK);
    start = osGetTime();
    osRecvMesg(&gRetraceMsgQ, NULL, OS_MESG_BLOCK);
    end = osGetTime();

    D_80138688 = end - start;
}

/*0x80000B68*/
static void clearDepthBuffer(void)
{
    gDPSetDepthImage(gpDisplayList++, OS_K0_TO_PHYSICAL(gDepthBuffer));
    gDPSetCycleType(gpDisplayList++, G_CYC_FILL);
    gDPSetColorImage(gpDisplayList++, G_IM_FMT_RGBA, G_IM_SIZ_16b, gScreenWidth, OS_K0_TO_PHYSICAL(gDepthBuffer));
    gDPSetFillColor(gpDisplayList++, GPACK_ZDZ(G_MAXFBZ, 0) << 16 | GPACK_ZDZ(G_MAXFBZ, 0));
    gDPFillRectangle(gpDisplayList++, 0, 0, gScreenWidth - 1, gScreenHeight - 1);
    gDPPipeSync(gpDisplayList++);
    gDPSetCycleType(gpDisplayList++, G_CYC_1CYCLE);
}

/*80000C74*/
void main_80000C74(void)
{
    gDPPipeSync(gpDisplayList++);
    gDPSetCycleType(gpDisplayList++, G_CYC_FILL);
    gDPSetRenderMode(gpDisplayList++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetColorImage(gpDisplayList++, G_IM_FMT_RGBA, G_IM_SIZ_16b, gScreenWidth, OS_K0_TO_PHYSICAL(gDepthBuffer));
    gDPSetFillColor(gpDisplayList++, GPACK_ZDZ(G_MAXFBZ, 0) << 16 | GPACK_ZDZ(G_MAXFBZ, 0));
    gDPFillRectangle(gpDisplayList++, 12, 12, gScreenWidth - 12, gScreenHeight - 12);
    gDPPipeSync(gpDisplayList++);
    gDPSetColorImage(gpDisplayList++, G_IM_FMT_RGBA, G_IM_SIZ_16b, gScreenWidth, OS_K0_TO_PHYSICAL(gFramebuffer[_framebufferIndex]));
    gDPSetCycleType(gpDisplayList++, G_CYC_2CYCLE);
}

/*80000DDC*/
static void main_80000DDC(void)
{
    gDPSetColorImage(gpDisplayList++, G_IM_FMT_RGBA, G_IM_SIZ_16b, gScreenWidth, OS_K0_TO_PHYSICAL(gFramebuffer[_framebufferIndex]));
    if (D_800BD3E8 != 0)
    {
        gDPSetCycleType(gpDisplayList++, G_CYC_FILL);
        gDPSetFillColor(gpDisplayList++, GPACK_RGBA5551(_red, _green, _blue, 1) << 16 | GPACK_RGBA5551(_red, _green, _blue, 1));
        gDPFillRectangle(gpDisplayList++, 0, 0, gScreenWidth - 1, gScreenHeight - 1);
    }
}

/*80000F00*/
static void main_80000F00(void)
{
    if (D_800BD3F9 != 3)
    {
        main_800036DC();
    }
    else if (D_800BD3F0 == 0)
    {
        if (D_801A1970 != 0)
            func_80008E3C();
        if (D_801AE914 != 0)
            main_800036DC();
    }
}

/*80000F68*/
static void main_80000F68(s16 arg0)
{
    D_80117ED8[arg0].unk80 = 0;

    if (D_801CE498.unk2E[arg0] >= 4)
        D_80117ED8[arg0].unk80 = 4;

    if ((D_801CE498.unk2E[arg0] & 3) >= 2)
        D_80117ED8[arg0].unk80 |= 1;

    if (D_801CE498.unk2E[arg0] & 1)
        D_80117ED8[arg0].unk80 |= 2;

    func_80035794(arg0);
}

/*80001038*/
static void main_80001038(void)
{
    s16 i;
    s16 temp;

    if (D_800BD3F0 != 0)
    {
        if (--D_800BD3F0 != 1)
            return;

        D_800BD3E8 = 0;
        main_80000610();
        D_800BD3F0 = 0;
    }
    audio_80006CC0();
    if (D_801AE914 != 0)
    {
        if (D_800BD42C != 0)
        {
            func_8008A654();
            D_800BD42C = 0;
        }
        func_801C4B34();

        for (i = 0; i < D_8012C470; i++)
            main_80000F68(i);
    }
    else
    {
        D_800BD42C = 1;
        if ((D_80199524 != 0) && (func_8008A070() & 0xFF))
            D_80199524 = 0;

        func_80040AA0(1, "SM");
        func_80040B2C(1);
        gTotalClockLock += 4;
        D_80168D0C = RAND(0x7FFF);
        D_801A1958.unkC++;
        ageCache();

        if (D_801AD470 != 0)
            func_8008DE14();

        if (D_800DF1A8 != -1)
            func_8004EA40(0);

        func_80064AA0();
        func_80064E78();
        func_80069160();
        func_80068E9C();
        func_8004FC4C();
        func_8004FF08();
        func_800698E8();
        audio_80007AB8();
        func_80040890();
        func_800502A0();
        func_8009542C();
        func_800A4478();
        func_800504F4();
        func_8005087C();

        for (i = 0; i < D_8012C470; i++)
            func_80017268(D_80117ED8[i].unk4A);

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

        if (gMapNum == MAP_THE_RACK)
            func_80094D18();

        if (gMapNum == MAP_NUCLEAR_WINTER)
            func_80095220();

        func_80040B70(2);

        for (i = 0; i < D_8012C470; i++)
        {
            func_8000EB4C(i, 0, 0, 0, 0);
            func_8000EA0C(i, D_800DF1AC[i], D_800DF1AC[i], D_800DF1AC[i], (s32)D_800DF1AC[i]);

            if (D_8019B940[D_80106D50[D_80117ED8[i].unk4A]].unk0 & 0x40)
                func_8000EA0C(i, 0, 0xFF, 0xFF, 0x80);
            else if (D_8010A940[i].unk7 != 0)
                func_8000EA0C(i, 0, 0xFF, 0, 0x80);
            else if (D_80117ED8[i].unk55 != 0)
                func_8000EA0C(i, D_800BD710[D_801A19EC].unk0, D_800BD710[D_801A19EC].unk1, D_800BD710[D_801A19EC].unk2, D_800BD710[D_801A19EC].unk3);
            else if (D_80117ED8[i].unk82 > 0)
                func_8000EA0C(i, 0, 0xFF, 0, D_80117ED8[i].unk82 / 2);

            if (D_80106D30[i] != 0)
                func_8000EA0C(i, 0, 0, 0, 200);

            if (D_80117ED8[i].unk45 != 0)
            {
                temp = D_80117ED8[i].unk4E;
                if (D_80117ED8[i].unk45 == 4)
                    func_8000EA0C(i, 0xFF - temp, 0xFF - temp, 0xFF - temp, 0xFF);
                else if (D_80117ED8[i].unk45 == 3)
                    func_8000EA0C(i, 0xFF - temp, -temp, -temp, 0xFF);
                else
                    func_8000EA0C(i, -temp, -temp, -temp, temp);
            }
        }

        if (D_800E1748 >= 0)
            func_8000EB4C(4, 0, 0, 0, (s32)(s16)(288 - (D_800E1748 * 8)));
        else
            func_8000EA0C(4, 0, 0, 0, -8);

        if ((D_800E1748 > 0) && (--D_800E1748 == 0))
        {
            MusStop(MUSFLAG_EFFECTS | MUSFLAG_SONGS, 0);
            D_800E1748 = -1;
            D_8012FC90 = 0;
            switch (D_80118148)
            {
            case 2:
                D_800DEDE0 = 1;
                break;
            case 1:
                if (gMapNum == MAP_THE_END)
                    main_80000624(func_801C97F8);
                else
                    main_80000624(func_801C9B28);
                break;
            case 3:
                D_800DEDE0 = 2;
                break;
            case 4:
                D_800DEDE0 = 3;
                break;
            case 5:
                main_80000624(func_801C15CC);
                break;
            case 0:
                main_80000624(func_801C3E08);
                break;
            default:
                main_80000624(func_801C3E08);
                break;
            }
        }
    }
}

/*800017AC*/
static void main_800017AC(void)
{
    s32 i;

    func_8008A724();
    if (D_8012FC90 != 0)
        func_801C9D68();
    else
    {
        for (i = 0; i < 4; i++)
            func_80003990(i);

        if ((D_800BD3F9 == 3) && (D_801CDB4C != 0))
            func_801C9F74();
        func_801C146C();
    }

    switch (D_800BD3F9)
    {
    case 0:
        main_800006B4();
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
        main_80000678();
        break;
    case 3:
        main_80001038();
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
        main_800017AC();
    }
}

/*80001968*/
static void setupSegments(void)
{
    gpDisplayList = gDisplayList[gGfxTaskIndex];
    gpVertexN64 = gVertexN64[gGfxTaskIndex];
    gpDynamic = &gDynamic[gGfxTaskIndex];
    gSPSegment(gpDisplayList++, PHYSICAL_SEGMENT, 0);
    gSPSegment(gpDisplayList++, STATIC_SEGMENT, OS_K0_TO_PHYSICAL(gStaticSegment));
    gSPSegment(gpDisplayList++, FRAMEBUFFER_SEGMENT, OS_K0_TO_PHYSICAL(gFramebuffer[_framebufferIndex]));
    gSPDisplayList(gpDisplayList++, gRdpInitDl);
    gSPDisplayList(gpDisplayList++, gRspInitDl);
    gDPSetScissor(gpDisplayList++, G_SC_NON_INTERLACE, 0, 0, gScreenWidth, gScreenHeight);
}

/*80001AF8*/
static void main_80001AF8(void)
{
    setupSegments();
    clearDepthBuffer();
    main_80000DDC();
}

/*80001B28*/
static void createGfxTask(void)
{
    OSScTask *t;
    char *ucode_boot_end;
    s32 ucode_boot_size;

    ucode_boot_end = (char *)rspbootTextEnd;
    ucode_boot_size = ucode_boot_end - (char *)rspbootTextStart;
    ucode_boot_end = NULL; /*FAKEMATCH*/

    gDPFullSync(gpDisplayList++);
    gSPEndDisplayList(gpDisplayList++);
    t = &gGfxTask[gGfxTaskIndex];
    t->list.t.data_ptr = (u64 *)gDisplayList[gGfxTaskIndex];
    t->list.t.data_size = (s32)(gpDisplayList - gDisplayList[gGfxTaskIndex]) * sizeof(Gfx);
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
    t->msgQ = &gGfxFrameMsgQ;
    t->msg = &_replyMsg;
    t->framebuffer = gFramebuffer[_framebufferIndex];
    osWritebackDCacheAll();
    osSendMesg(osScGetCmdQ(&gScheduler), t, OS_MESG_NOBLOCK);
    gGfxDebugTime = gGfxTask[gGfxTaskIndex].totalTime;
}

/*80001CFC*/
void main_80001CFC(void)
{
    D_800FE9E0 = 0LL;
    D_801AE498 = 0LL;
    D_800BD3E0 = 0LL;
    gTotalClockLock = 0;
}

/*80001D44*/
static void main_80001D44(void)
{
    s16 i;
    s16 width;
    s16 height;

    cache1d_8002AAC0();
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
        main_80000F68(i);
        func_80095390(i);
    }
    D_800DEEA0 = 0;
    if ((u32)osMemSize > 0x400000U)
    {
        D_800DEEA0 = 1;
        gDisplayListMaxSize = 0xA000;
        gVertexN64MaxSize = 0x6000;
    }
    else if (D_8012C470 < 2)
    {
        gDisplayListMaxSize = 0x2800;
        gVertexN64MaxSize = 0x1800;
    }
    else
    {
        gDisplayListMaxSize = 0x3C00;
        gVertexN64MaxSize = 0x2400;
    }
    allocMemory(width, height, gDisplayListMaxSize, gVertexN64MaxSize);
    func_8001F928(width, height);
    _red = 0;
    _green = 0;
    _blue = 0;
    D_800BD3E8 = 1;
    D_801A1970 = 1;
    main_80000DDC();
    clearDepthBuffer();
    D_800DF585 = 0;
}

/*80001F40*/
void main_80001F40(void)
{
    main_80001D44();
    func_80050408();
    loadMap(gLoadMapNum);
    D_800BD3F9 = 3;
    D_800BD42D = 1;
    D_801CA144 = 0.0f;
    main_80002390();
    D_800BD3F0 = 0xA;
}

/*80001FAC*/
void main_80001FAC(void)
{
    D_801CDC65 = 1;
    main_80001D44();
    D_800BD3F9 = 3;
    D_800BD42D = 0;
    D_801CA144 = 0.0f;
    main_80002390();
    D_800BD3F0 = 100;
    D_800DEDE0 = 4;
}

/*80002014*/
void allocMemory(s32 height, s32 width, s32 dlist_size, s32 vertex_size)
{
    s16 i;
    u8 *plock;
    u8 *handler;
    s32 fb_size;
    u8 *fb_addr;
    s32 depth_align;
    s32 remaining_size;

    plock = &gCacheLock[1];
    main_80000450();
    if ((D_800BD3F8 == 0))
    {
        if (width == 480)
            width = 512;
    }

    if (osMemSize == 0x400000)
        _framebufferCount = 2;
    else
        _framebufferCount = 3;

    gCacheMemEnd = (u8 *)(osMemSize - 0x80000000);
    initCache(gCacheMemStart, (gCacheMemEnd - gCacheMemStart));

    fb_size = height * width * 2;
    alloCache(&gFramebuffer[0], ((fb_size + FRAMEBUFFER_ALIGN) * _framebufferCount), &gCacheLock[0]);
    fb_addr = (u8 *)(((intptr_t)gFramebuffer[0] + (FRAMEBUFFER_ALIGN-1)) & ~(FRAMEBUFFER_ALIGN-1));
    gFramebuffer[0] = fb_addr;
    gFramebuffer[1] = fb_addr + fb_size;

    if (_framebufferCount == 3)
    {
        gFramebuffer[2] = fb_addr + fb_size + fb_size;
    }

    alloCache(&gDisplayList[0], (dlist_size * sizeof(Gfx) * GFX_TASKS), &gCacheLock[0]);
    gDisplayList[1] = &gDisplayList[0][dlist_size];

    depth_align = DEPTHBUFFER_ALIGN; /*FAKEMATCH*/
    remaining_size = gCacheMemEnd - gCacheMemStart;
    remaining_size -= ((((fb_size + FRAMEBUFFER_ALIGN) * _framebufferCount) + depth_align) + fb_size);
    remaining_size -= (dlist_size * sizeof(Gfx) * GFX_TASKS);

    if (vertex_size != 0)
    {
        alloCache(&gVertexN64[0], (vertex_size * sizeof(Vtx) * GFX_TASKS), &gCacheLock[0]);
        remaining_size -= (vertex_size * sizeof(Vtx) * GFX_TASKS);
        gVertexN64[1] = &gVertexN64[0][vertex_size];

        alloCache(&D_801297E0[0][0], (D_8012C470 * 1600 * sizeof(Gfx) * GFX_TASKS), &gCacheLock[0]);
        D_801297E0[0][1] = D_801297E0[0][0] + 1600;
        for (i = 1; i<D_8012C470; i++)
        {
            D_801297E0[i][0] = D_801297E0[i-1][1] + 1600;
            D_801297E0[i][1] = D_801297E0[i][0] + 1600;
        }
        remaining_size -= (D_8012C470 * 1600 * sizeof(Gfx) * GFX_TASKS);
    }

    alloCache(&handler, remaining_size, plock);
    alloCache(&gDepthBuffer, (fb_size + DEPTHBUFFER_ALIGN), &gCacheLock[0]);
    gDepthBuffer = (u8 *)(((intptr_t)gDepthBuffer + (DEPTHBUFFER_ALIGN-1)) & ~(DEPTHBUFFER_ALIGN-1));
    suckCache(&handler);
    Bmemset(gFramebuffer[0], 0, ((fb_size + FRAMEBUFFER_ALIGN) * _framebufferCount));
    _framebufferIndex = 0;
    gScreenWidth = height;
    gScreenHeight = width;
    D_800E0F58 = 1;
}

/*80002390*/
void main_80002390(void)
{
    func_8001F928(gScreenWidth, gScreenHeight);
    switch (osTvType)
    {
    case OS_TV_NTSC:
        if (gScreenWidth == 512)
            _viMode = OS_VI_NTSC_HAF1;
        else
        {
            if (gScreenHeight == 240)
                _viMode = OS_VI_NTSC_LAN1;
            else
                _viMode = OS_VI_NTSC_LAF1;
        }
        break;
    case OS_TV_PAL:
        if (gScreenWidth == 512)
            _viMode = OS_VI_PAL_HAF1;
        else
        {
            if (gScreenHeight == 240)
                _viMode = OS_VI_PAL_LAN1;
            else
                _viMode = OS_VI_PAL_LAF1;
        }
        break;
    case OS_TV_MPAL:
        if (gScreenWidth == 512)
            _viMode = OS_VI_MPAL_HAF1;
        else
        {
            if (gScreenHeight == 240)
                _viMode = OS_VI_MPAL_LAN1;
            else
                _viMode = OS_VI_MPAL_LAF1;
        }
        break;
    }
}

/*80002494*/
static void main_80002494(void)
{
    allocMemory(320, 480, 0x2800, 0);
    func_801C10C8();
    setCameraPosition(0.0f, 0.0f, -500.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    func_8007FD8C(D_800DFB08, 11);
    func_8007FD8C(D_800DFA90, 2);
    D_800BD3F9 = 0;
    D_800BD3E8 = 1;
    main_80002390();
    main_80000610();
}

/*80002548*/
static void mainLoop(void *arg)
{
    s16 i, j;
    s16 *count;
    s16 count2;
    intptr_t *addr_;
    s32 size;
    MsgStrInfo *msg_;
    intptr_t offset_;
    u8 *temp;

    osCreateMesgQueue(&gDmaMessageQ, gDmaMessages, NUM_DMA_MSGS);

    D_80197D4C = code1_VRAM;
    D_8010571C = (u8 *)main_80000450;
    D_80138818 = (u32)(code1_VRAM - (u8 *)main_80000450) >> 10;
    gStaticSegment = (u8 *)code1_VRAM_END;
    size = static_ROM_END - static_ROM_START;
    gCacheMemStart = (u8 *)((intptr_t)(&gStaticSegment[size] + 0x3F) & ~0x3F);

    osInvalICache(code1_TEXT_START, code1_TEXT_END - code1_TEXT_START);
    readRom(code1_VRAM, code1_ROM_START, code1_ROM_END - code1_ROM_START);
    Bmemset(code1_BSS_START, 0, code1_BSS_END - code1_BSS_START);
    readRom(code1_VRAM_END, static_ROM_START, size);

    gpTileInfo = (TileInfo *)GET_STATIC_SEG_SYM(gTileInfo);
    gpKeyStrInfo = (char ***)GET_STATIC_SEG_SYM(gKeyStrInfo);
    gpMsgStrInfo = (MsgStrInfo *)GET_STATIC_SEG_SYM(gMsgStrInfo);

    count = (s16 *)GET_STATIC_SEG_SYM(gWeaponStrInfoCount);
    gpWeaponStrInfo = (char **)GET_STATIC_SEG_SYM(gWeaponStrInfo);

#ifdef TARGET_N64
    for (i = 0; i < *count; i++)
    {
        intptr_t *addr = (intptr_t *)gpWeaponStrInfo;
        intptr_t offset = (intptr_t)gStaticSegment - STATIC_SEGMENT_VRAM;
        addr[i] += offset;
    }
#endif

    gpMapStrInfo = (char **)GET_STATIC_SEG_SYM(gMapStrInfo);

#ifdef TARGET_N64
    for (i = 0; i < MAP_STRINFO_NUM; i++)
    {
        intptr_t *addr = (intptr_t *)gpMapStrInfo;
        intptr_t offset = (intptr_t)gStaticSegment - STATIC_SEGMENT_VRAM;
        addr[i] += offset;
    }

    i = 0;
    addr_ = (intptr_t *)gpKeyStrInfo;
    msg_ = gpMsgStrInfo;
    offset_ = (intptr_t)gStaticSegment - STATIC_SEGMENT_VRAM;
    while (i < MAP_STRINFO_NUM)
    {
        MsgStrInfo *msg;
        addr_[i] += offset_;
        *(intptr_t *)&msg_[i].addr += offset_;

        for (j = 0; j < KEY_STRINFO_NUM; j++)
        {
            intptr_t *addr = (intptr_t *)addr_[i];
            addr[j] += offset_;
        }

        /*FAKEMATCH*/
        if (i)
        {
        }
        msg = msg_;
        for (j = 0; j < msg[i].count; j++)
        {
            intptr_t *addr = (intptr_t *)msg[i].addr;
            addr[j] += offset_;
        }

        i++;
    }
#endif

    gpSinTable = (s16 *)GET_STATIC_SEG_SYM(gSinTable);
    gpRadaRang = (s16 *)GET_STATIC_SEG_SYM(gRadarang);
    D_8012EED0 = (u8 *)GET_STATIC_SEG_SYM(D_010259B0);
    D_80168D04 = (_11B300UnkStruct2 *)GET_STATIC_SEG_SYM(D_01025AAC);
    D_8012F6E4 = (_11B300UnkStruct1 *)GET_STATIC_SEG_SYM(D_01025BA0);
    count2 = *(u16 *)GET_STATIC_SEG_SYM(D_01025CFC);
    D_80138780 = count2;

#ifdef TARGET_N64
    temp = gStaticSegment;
    for (i = 0; i < count2; i++)
    {
        /*FAKEMATCH*/
        _11B300UnkStruct1 *unk = (_11B300UnkStruct1 *)(temp + (intptr_t)D_01025BA0_STATIC_START);
        intptr_t offset = (intptr_t)temp - STATIC_SEGMENT_VRAM;
        *(intptr_t *)&unk[i].actor += offset;
    }
#endif

    count = (s16 *)GET_STATIC_SEG_SYM(gActionStrInfoCount);
    gpMapInfo = (MapInfo *)GET_STATIC_SEG_SYM(gMapInfo);
    gpActionStrInfo = (char **)GET_STATIC_SEG_SYM(gActionStrInfo);

#ifdef TARGET_N64
    for (i = 0; i < *count; i++)
    {
        intptr_t *addr = (intptr_t *)gpActionStrInfo;
        intptr_t offset = (intptr_t)gStaticSegment - STATIC_SEGMENT_VRAM;
        addr[i] += offset;
    }
#endif

    D_801ACBD8 = (_11D520UnkStruct1 *)GET_STATIC_SEG_SYM(D_01026910);

#ifdef TARGET_N64
    for (i = 0; i < D_01026910_NUM; i++)
    {
        intptr_t *addr = (intptr_t *)D_801ACBD8;
        intptr_t offset = (intptr_t)gStaticSegment - STATIC_SEGMENT_VRAM;
        addr[i*2] += offset;
    }
#endif

    count = (s16 *)GET_STATIC_SEG_SYM(D_0102583C);
    D_801AE8F0 = (u8 *)GET_STATIC_SEG_SYM(D_01024590);
    D_80197DE8 = (u8 *)GET_STATIC_SEG_SYM(D_010245E8);
    D_801C0D70 = (u8 *)GET_STATIC_SEG_SYM(D_0102464C);
    D_80129808 = (u8 *)GET_STATIC_SEG_SYM(D_0102578C);

#ifdef TARGET_N64
    for (i = 0; i < *count; i++)
    {
        intptr_t *addr = (intptr_t *)D_80129808;
        intptr_t offset = (intptr_t)gStaticSegment - STATIC_SEGMENT_VRAM;
        addr[i] += offset;
    }
#endif

    count = (s16 *)GET_STATIC_SEG_SYM(gLicenceStrInfoCount);
    D_801AD474 = (u8 *)GET_STATIC_SEG_SYM(D_010247AC);
    D_80105550 = (u8 *)GET_STATIC_SEG_SYM(D_01025734);
    D_800FF528 = (u8 *)GET_STATIC_SEG_SYM(D_01025840);
    D_8013F920 = (u8 *)GET_STATIC_SEG_SYM(D_010258D8);
    D_8012DF00 = (u8 *)GET_STATIC_SEG_SYM(D_01025908);
    D_8012E150 = (u8 *)GET_STATIC_SEG_SYM(D_01025968);
    gpLicenceStrInfo = (char **)GET_STATIC_SEG_SYM(gLicenceStrInfo);

#ifdef TARGET_N64
    for (i = 0; i < *count; i++)
    {
        intptr_t *addr = (intptr_t *)gpLicenceStrInfo;
        intptr_t offset = (intptr_t)gStaticSegment - STATIC_SEGMENT_VRAM;
        addr[i] += offset;
    }
#endif

    count = (s16 *)GET_STATIC_SEG_SYM(gCreditStrInfoCount);
    gpCreditStrInfo = (char **)GET_STATIC_SEG_SYM(gCreditStrInfo);

#ifdef TARGET_N64
    for (i = 0; i < *count; i++)
    {
        intptr_t *addr = (intptr_t *)gpCreditStrInfo;
        intptr_t offset = (intptr_t)gStaticSegment - STATIC_SEGMENT_VRAM;
        addr[i] += offset;
    }
#endif

    D_801CE5E8 = (_119280UnkStruct1 *)GET_STATIC_SEG_SYM(D_01022510);
    D_80138778 = (u8 *)GET_STATIC_SEG_SYM(D_01022790);
    gpControlPreset = (ControlMapping *)GET_STATIC_SEG_SYM(gControlPreset);

#ifdef TARGET_N64
    for (i = 0; i < CONTROL_PRESET_NUM; i++)
    {
        for (j = 0; j < CONTROL_MAPPING_NUM; j++)
        {
            intptr_t *addr = (s32 *)gpControlPreset;
            intptr_t offset = (intptr_t)gStaticSegment - STATIC_SEGMENT_VRAM;
            *(addr + (i*CONTROL_MAPPING_NUM) + j) += offset;
        }
    }
#endif

    allocMemory(SCREEN_WIDTH, SCREEN_HEIGHT, 0x2800, 0);
    osCreateScheduler(&gScheduler, &_schedulerStack[SCHEDULER_STACKSIZE / sizeof(u64)], 40, _viMode, (u8)1);
    osViBlack(1U);
    osCreateThread(&_viLoopThread, 7, viLoop, arg, &_viLoopThreadStack[VILOOP_STACKSIZE / sizeof(u64)], 20);
    initAudio();
    func_801C4F38();
    func_8008AD94();
    func_8008A3EC("DUKE ZERO HOUR.A", &D_801CC930, 4156);
    switch (osTvType)
    {
    case 0:
        D_801B0815 = 0;
        break;
    case 1:
        D_801B0815 = 1;
        break;
    case 2:
        D_801B0815 = 1;
        break;
    }
    osCreateMesgQueue(&D_8010A920, &D_801C0D64, 1);
    osCreateMesgQueue(&gRetraceMsgQ, gRetraceMessages, NUM_DMA_MSGS);
    osScAddClient(&gScheduler, &_retraceClient, &gRetraceMsgQ);
    osStartThread(&_viLoopThread);
    main_80000A94();
    func_800356EC();
    engine_8002B680();
    main_80001CFC();
    main_80000450();
    main_8000071C();
    main_80002494();
    gLoadMapNum = 0;

    do
    {
        if (D_800DEDE0)
        {
            if (D_800DEDE0 == 2)
                func_801C9B48();
            if (D_800DEDE0 == 3)
                func_801C9E7C();
            if (D_800DEDE0 == 4)
            {
                D_800BD3E8 = 0;
                main_80000610();
                D_800BD3F0 = 0;
                func_801C9B48();
            }
            loadMap(gLoadMapNum);
            D_800DEDE0 = 0;
            D_801A1970 = 1;
        }

        D_80138788 = D_800FE9E0;
        D_800BD3E0 += D_800FE9E0 - D_801AE498;
        D_801CE5D8 += D_800FE9E0 - D_801AE498;

        if (D_800BD3E0 > 8LL)
            D_800BD3E0 = 8LL;

        D_801AE498 = D_80138788;

        for (; D_800BD3E0 > 2; D_800BD3E0 -= 2)
            main_800017AC();

        if (D_800BD3E0 >= 0)
        {
            main_800017AC();
            main_80001AF8();
            main_80000F00();

            D_800BD3E0 -= 2;

            if (D_800BD3FC != 0)
            {
                osRecvMesg(&D_8010A920, NULL, OS_MESG_BLOCK);
                D_800BD3FC = 0;

                if (D_80119A5C != 0)
                    D_80119A5C -= 1;

                if (_framebufferCount < 3)
                {
                    if (gRetraceMsgQ.validCount >= gRetraceMsgQ.msgCount)
                        osRecvMesg(&gRetraceMsgQ, NULL, OS_MESG_BLOCK);

                    osRecvMesg(&gRetraceMsgQ, NULL, OS_MESG_BLOCK);
                }
            }
            createGfxTask();
            D_800BD3FC = 1;
            D_800BD428 = gGfxTaskIndex;
            gGfxTaskIndex ^= 1;
            _framebufferIndex++;
            if (_framebufferIndex == _framebufferCount)
                _framebufferIndex = 0;
        }
    } while (1);
}

/*800031F8*/
static void viLoop(void *arg)
{
    OSScMsg *message;

    osCreateMesgQueue(&gGfxFrameMsgQ, gGfxMessages, NUM_DMA_MSGS);
    osScAddClient(&gScheduler, &_gfxClient, &gGfxFrameMsgQ);
    while (1)
    {
        osRecvMesg(&gGfxFrameMsgQ, (OSMesg *)&message, OS_MESG_BLOCK);
        switch (message->type)
        {
        case OS_SC_RETRACE_MSG:
            D_800FE9E0++;
            if (osTvType == OS_TV_PAL)
            {
                D_800BD42E++;
                if ((D_800BD42E % 5) == 0)
                    D_800FE9E0++;

                if (D_800BD42E == 60)
                {
                    D_800BD42E = 0;
                    D_800FE9E0++;
                }
            }
            break;
        case OS_SC_DONE_MSG:
            D_801B0818 = gGfxTask[D_800BD428].totalTime;
            D_8016D178 = D_801B0818 - gGfxDebugTime;
            osSendMesg(&D_8010A920, NULL, OS_MESG_NOBLOCK);
            D_8016D178 *= gScreenHeight;
            D_8016D178 /= D_80138688;
            if (D_800BD3F4 != 0)
            {
                D_800BD3F4--;
                if (D_800BD3F4 == 0)
                {
                    if (D_800BD3F8 != 0)
                        main_80000508();
                    else
                        main_800005D8();
                    osViSetMode(&osViModeTable[_viMode]);
                    osViSetSpecialFeatures(OS_VI_GAMMA_OFF | OS_VI_DITHER_FILTER_ON);
                }
            }
            break;
        case OS_SC_PRE_NMI_MSG:
            main_80000450();
            osAfterPreNMI();
            MusStop(3, 0);
            func_8008A654();

            while (1)
                func_8008A724();

            break;
        }
    }
}

/*800034F4*/
static void main_800034F4(void)
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

    gSPMatrix(gpDisplayList++, &gpDynamic->projection, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gpDisplayList++, &gpDynamic->viewing, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
    gSPPerspNormalize(gpDisplayList++, gPerspNorm);

    guLookAtReflect(
        &gpDynamic->viewing,
        &gpDynamic->lookat[0][0],
        gPosition.xEye,
        gPosition.yEye,
        gPosition.zEye,
        gPosition.xAt,
        gPosition.yAt,
        gPosition.zAt,
        0.0,
        1.0,
        0.0);

    gSPLookAtX(gpDisplayList++, &gpDynamic->lookat[0][0].l[0]);
    gSPLookAtY(gpDisplayList++, &gpDynamic->lookat[0][0].l[1]);
}

/*800036DC*/
static void main_800036DC(void)
{
    gSPViewport(gpDisplayList++, &D_800DCB10);
    guMtxIdent(&gpDynamic->identity);
    guScale(&gpDynamic->scale, 0.25, 0.25, 0.25);
    D_801AE528 = 0;
    D_80168D18 = 0;
    D_800FE3F4 = 0;
    gDPPipeSync(gpDisplayList++);
    gDPSetScissor(gpDisplayList++, G_SC_NON_INTERLACE, 0, 0, gScreenWidth, gScreenHeight);
    gDPSetCycleType(gpDisplayList++, G_CYC_1CYCLE);
    gDPSetRenderMode(gpDisplayList++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineMode(gpDisplayList++, G_CC_MODULATEIA, G_CC_MODULATEIA);
    gDPSetTextureFilter(gpDisplayList++, G_TF_BILERP);
    gDPSetTextureLUT(gpDisplayList++, G_TT_RGBA16);
    gSPClearGeometryMode(gpDisplayList++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gSPSetGeometryMode(gpDisplayList++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
    gDPSetTexturePersp(gpDisplayList++, G_TP_PERSP);
    main_800034F4();
    gSPTexture(gpDisplayList++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    func_8007EF70();
}

/*80003940*/
void main_80003940(void)
{
    *(D_801CDC68++) = 0;
    D_801CDB4C = 0;
    func_80000000(D_801CDC70, 2048);
}
