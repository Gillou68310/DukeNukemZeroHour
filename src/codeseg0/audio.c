#include "common.h"
#include "codeseg0/main.h"
#include "codeseg0/audio.h"
#include "codeseg0/common0.h"
#include "libmus.h"

#define DMA_LEN 16384
#define MUSIC_COUNT 21
#define SFX_BANK_SIZE 54152
#define SFX_PBANK_SIZE 167600
#define AUDIO_HEAP_SIZE 163840
#define MUSIC_PBANK_SIZE 16400

typedef struct
{
    u8 *wbank_start;
    u8 *pbank_start;
    u8 *pbank_end;
    u8 *music_start;
    u8 *music_end;
} MusicInfo;

#define PBANK0_START pbank0SegmentRomStart
#define PBANK0_END pbank0SegmentRomEnd
#define WBANK0_START wbank0SegmentRomStart
#define WBANK0_END wbank0SegmentRomEnd
#define SFX_BANK_START sfxBankSegmentRomStart
#define SFX_BANK_END sfxBankSegmentRomEnd

extern u8 PBANK0_START[];
extern u8 PBANK0_END[];
extern u8 WBANK0_START[];
extern u8 WBANK0_END[];
extern u8 SFX_BANK_START[];
extern u8 SFX_BANK_END[];

/*data*/
/*800BD460*/ extern /*static*/ MusicInfo musicInfo[MUSIC_COUNT];
extern /*static*/ s8 D_800BD618;

/*.comm*/
/*8010A9C0*/ u8 gSfxBankBuffer[SFX_BANK_SIZE];
/*8013F960*/ u8 gSfxPbankBuffer[SFX_PBANK_SIZE];
/*8016D190*/ u8 gAudioMemory[AUDIO_HEAP_SIZE];
/*801A2840*/ u8 gMusicPbankBuffer[MUSIC_PBANK_SIZE];
/*801B0D3C*/ s16 gSfxCount;

/*.text*/

/*800065F0*/
void dmaRomToRam(u8 *rom, u8 *ram, s32 size)
{
    OSIoMesg dmaIOMessageBuf;
    s32 len;

    osInvalDCache(ram, size);
    while (size != 0)
    {
        if (size > DMA_LEN)
        {
            len = DMA_LEN;
        }
        else
        {
            len = size;
        }
        osPiStartDma(&dmaIOMessageBuf, OS_MESG_PRI_NORMAL, OS_READ, (u32)rom, ram, len, &gDmaMessageQ);
        rom += len;
        ram += len;
        size -= len;
        osRecvMesg(&gDmaMessageQ, NULL, 1);
    }
}

/*800066A8*/
static void initMusicDriver(void)
{
    musConfig config;

    dmaRomToRam(PBANK0_START, gSfxPbankBuffer, (PBANK0_END - PBANK0_START));
    config.sched = &gScheduler;
    config.heap_length = AUDIO_HEAP_SIZE;
    config.thread_priority = 39;
    config.heap = gAudioMemory;
    config.control_flag = 0;
    config.ptr = NULL;
    config.wbk = NULL;
    config.default_fxbank = NULL;
    config.fifo_length = 256;
    config.channels = 24;
    config.syn_output_rate = 22050;
    config.syn_rsp_cmds = 4096;
    config.syn_retraceCount = 1;
    config.syn_num_dma_bufs = 30;
    config.syn_updates = 256;
    config.syn_dma_buf_size = 2048;
    MusInitialize(&config);
}

/*80006760*/
static void initBank(u8 *pbank_rom, s32 size, u8 *wbank, u8 *pbank_ram)
{
    readRom(pbank_ram, pbank_rom, size);
    MusPtrBankInitialize(pbank_ram, wbank);
}

/*800067B4*/
static void initSfxBank(u8 *sfx_bank_rom, s32 size)
{
    readRom(gSfxBankBuffer, sfx_bank_rom, size);
    MusFxBankInitialize(gSfxBankBuffer);
    gSfxCount = MusFxBankNumberOfEffects(gSfxBankBuffer);
}

/*80006808*/
static void readMusic(u8 *rom, s32 size, u8 *ram)
{
    readRom(ram, rom, size);
}

INCLUDE_ASM(s32, "src/codeseg0/audio", func_80006838);

/*80006938*/
void initAudio(void)
{
    initMusicDriver();
    MusSetMasterVolume(MUSFLAG_EFFECTS | MUSFLAG_SONGS, 0x7FFF);
    func_80006838(50, 100);
    initBank(PBANK0_START, (PBANK0_END - PBANK0_START), WBANK0_START, gSfxPbankBuffer);
    initSfxBank(SFX_BANK_START, (SFX_BANK_END - SFX_BANK_START));
    MusPtrBankSetCurrent(gMusicPbankBuffer);
    MusFxBankSetPtrBank(gSfxBankBuffer, gSfxPbankBuffer);
}

INCLUDE_ASM(s32, "src/codeseg0/audio", func_800069D8);

INCLUDE_ASM(s32, "src/codeseg0/audio", func_80006BA0);

INCLUDE_ASM(s32, "src/codeseg0/audio", func_80006CC0);

INCLUDE_ASM(s32, "src/codeseg0/audio", func_80006E60);

INCLUDE_ASM(s32, "src/codeseg0/audio", func_80006F08);

INCLUDE_ASM(s32, "src/codeseg0/audio", func_80007084);

INCLUDE_ASM(s32, "src/codeseg0/audio", func_80007170);

INCLUDE_ASM(s32, "src/codeseg0/audio", func_80007218);

INCLUDE_ASM(s32, "src/codeseg0/audio", func_8000730C);

INCLUDE_ASM(s32, "src/codeseg0/audio", func_80007418);

INCLUDE_ASM(s32, "src/codeseg0/audio", func_80007510);

INCLUDE_ASM(s32, "src/codeseg0/audio", func_800075EC);

INCLUDE_ASM(s32, "src/codeseg0/audio", func_800077F4);

INCLUDE_ASM(s32, "src/codeseg0/audio", func_80007820);

INCLUDE_ASM(s32, "src/codeseg0/audio", func_8000784C);

INCLUDE_ASM(s32, "src/codeseg0/audio", func_80007A44);

INCLUDE_ASM(s32, "src/codeseg0/audio", func_80007A80);

INCLUDE_ASM(s32, "src/codeseg0/audio", func_80007AB8);

INCLUDE_ASM(s32, "src/codeseg0/audio", func_80007FF4);

INCLUDE_ASM(s32, "src/codeseg0/audio", func_800080E0);

INCLUDE_ASM(s32, "src/codeseg0/audio", func_80008574);

INCLUDE_ASM(s32, "src/codeseg0/audio", func_80008604);

INCLUDE_ASM(s32, "src/codeseg0/audio", func_800086B0);

INCLUDE_ASM(s32, "src/codeseg0/audio", func_80008710);
