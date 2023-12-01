#include "common.h"
#include "code0/main.h"
#include "code0/audio.h"
#include "code0/41940.h"
#include "code1/code1.h"
#include "code1/EB300.h"
#include "code1/code1.h"

#define DMA_LEN 16384
#define MUSIC_COUNT 12
#define AMBIENT_COUNT 9
#define SFX_BANK_SIZE 54152
#define SFX_PBANK_SIZE 167600
#define AUDIO_HEAP_SIZE 163840
#define MUSIC_PBANK_SIZE 16400
#define MUSIC_BUFFER_SIZE 8496
#define AMBIENT_PBANK_SIZE 3836
#define AMBIENT_BUFFER_SIZE 10000

typedef struct
{
    u8 *wbank_start;
    u8 *pbank_start;
    u8 *pbank_end;
    u8 *music_start;
    u8 *music_end;
} MusicInfo;

typedef struct
{
    MusicInfo music[MUSIC_COUNT];
    MusicInfo ambient[AMBIENT_COUNT];
} Music;

typedef struct {
    musHandle handle;
    u16 unk4; /*sfxnum?*/
    u16 unk6;
} audioUnkStruct1;

typedef struct
{
    s8 musicnum;
    s8 ambientnum;
} audioUnkStruct2;

#define PBANK0_START sounds_bank0_ptr_ROM_START
#define PBANK0_END sounds_bank0_ptr_ROM_END
#define WBANK0_START sounds_bank0_wbk_ROM_START
#define WBANK0_END sounds_bank0_wbk_ROM_END
#define SFX_BANK_START sounds_sfx_bfx_ROM_START
#define SFX_BANK_END sounds_sfx_bfx_ROM_END

extern u8 PBANK0_START[];
extern u8 PBANK0_END[];
extern u8 WBANK0_START[];
extern u8 WBANK0_END[];
extern u8 SFX_BANK_START[];
extern u8 SFX_BANK_END[];

extern u8 sounds_bank0_ptr_ROM_START[];
extern u8 sounds_bank0_wbk_ROM_START[];
extern u8 sounds_sfx_bfx_ROM_START[];
extern u8 sounds_training_base_ROM_START[];
extern u8 sounds_bank1_ptr_ROM_START[];
extern u8 sounds_bank1_wbk_ROM_START[];
extern u8 sounds_western1_ROM_START[];
extern u8 sounds_western2_ROM_START[];
extern u8 sounds_bank2_ptr_ROM_START[];
extern u8 sounds_bank2_wbk_ROM_START[];
extern u8 sounds_western_mine_cart_ROM_START[];
extern u8 sounds_bank3_ptr_ROM_START[];
extern u8 sounds_bank3_wbk_ROM_START[];
extern u8 sounds_present_day2_ROM_START[];
extern u8 sounds_present_day1_ROM_START[];
extern u8 sounds_title_screen_ROM_START[];
extern u8 sounds_present_day_boss_hog_ROM_START[];
extern u8 sounds_bank4_ptr_ROM_START[];
extern u8 sounds_bank4_wbk_ROM_START[];
extern u8 sounds_victorian1_ROM_START[];
extern u8 sounds_victorian2_ROM_START[];
extern u8 sounds_bank5_ptr_ROM_START[];
extern u8 sounds_bank5_wbk_ROM_START[];
extern u8 sounds_boss_ROM_START[];
extern u8 sounds_bank6_ptr_ROM_START[];
extern u8 sounds_bank6_wbk_ROM_START[];
extern u8 sounds_final_alien_mother_ROM_START[];
extern u8 sounds_bank7_ptr_ROM_START[];
extern u8 sounds_bank7_wbk_ROM_START[];
extern u8 sounds_ambient1_ROM_START[];
extern u8 sounds_bank8_ptr_ROM_START[];
extern u8 sounds_bank8_wbk_ROM_START[];
extern u8 sounds_ambient2_ROM_START[];
extern u8 sounds_bank9_ptr_ROM_START[];
extern u8 sounds_bank9_wbk_ROM_START[];
extern u8 sounds_ambient3_ROM_START[];
extern u8 sounds_bank10_ptr_ROM_START[];
extern u8 sounds_bank10_wbk_ROM_START[];
extern u8 sounds_ambient4_ROM_START[];
extern u8 sounds_bank11_ptr_ROM_START[];
extern u8 sounds_bank11_wbk_ROM_START[];
extern u8 sounds_ambient5_ROM_START[];
extern u8 sounds_bank12_ptr_ROM_START[];
extern u8 sounds_bank12_wbk_ROM_START[];
extern u8 sounds_ambient6_ROM_START[];
extern u8 sounds_bank13_ptr_ROM_START[];
extern u8 sounds_bank13_wbk_ROM_START[];
extern u8 sounds_ambient7_ROM_START[];
extern u8 sounds_bank14_ptr_ROM_START[];
extern u8 sounds_bank14_wbk_ROM_START[];
extern u8 sounds_ambient8_ROM_START[];
extern u8 sounds_bank15_ptr_ROM_START[];
extern u8 sounds_bank15_wbk_ROM_START[];
extern u8 sounds_ambient9_ROM_START[];
extern u8 sounds_present_day2_ROM_END[];
extern u8 sounds_present_day1_ROM_END[];
extern u8 sounds_title_screen_ROM_END[];
extern u8 sounds_western1_ROM_END[];
extern u8 sounds_western2_ROM_END[];
extern u8 sounds_western_mine_cart_ROM_END[];
extern u8 sounds_victorian1_ROM_END[];
extern u8 sounds_victorian2_ROM_END[];
extern u8 sounds_final_alien_mother_ROM_END[];
extern u8 sounds_boss_ROM_END[];
extern u8 sounds_present_day_boss_hog_ROM_END[];
extern u8 sounds_training_base_ROM_END[];
extern u8 sounds_ambient1_ROM_END[];
extern u8 sounds_ambient2_ROM_END[];
extern u8 sounds_ambient3_ROM_END[];
extern u8 sounds_ambient4_ROM_END[];
extern u8 sounds_ambient5_ROM_END[];
extern u8 sounds_ambient6_ROM_END[];
extern u8 sounds_ambient7_ROM_END[];
extern u8 sounds_ambient8_ROM_END[];
extern u8 sounds_ambient9_ROM_END[];
extern u8 sounds_bank1_ptr_ROM_END[];
extern u8 sounds_bank2_ptr_ROM_END[];
extern u8 sounds_bank3_ptr_ROM_END[];
extern u8 sounds_bank4_ptr_ROM_END[];
extern u8 sounds_bank5_ptr_ROM_END[];
extern u8 sounds_bank6_ptr_ROM_END[];
extern u8 sounds_bank7_ptr_ROM_END[];
extern u8 sounds_bank8_ptr_ROM_END[];
extern u8 sounds_bank9_ptr_ROM_END[];
extern u8 sounds_bank10_ptr_ROM_END[];
extern u8 sounds_bank11_ptr_ROM_END[];
extern u8 sounds_bank12_ptr_ROM_END[];
extern u8 sounds_bank13_ptr_ROM_END[];
extern u8 sounds_bank14_ptr_ROM_END[];
extern u8 sounds_bank15_ptr_ROM_END[];

/*data*/

/*800BD460*/
static Music _music = {
    {
        {
            sounds_bank3_wbk_ROM_START,
            sounds_bank3_ptr_ROM_START,
            sounds_bank3_ptr_ROM_END,
            sounds_present_day2_ROM_START,
            sounds_present_day2_ROM_END,
        },
        {
            sounds_bank3_wbk_ROM_START,
            sounds_bank3_ptr_ROM_START,
            sounds_bank3_ptr_ROM_END,
            sounds_present_day1_ROM_START,
            sounds_present_day1_ROM_END,
        },
        {
            sounds_bank3_wbk_ROM_START,
            sounds_bank3_ptr_ROM_START,
            sounds_bank3_ptr_ROM_END,
            sounds_title_screen_ROM_START,
            sounds_title_screen_ROM_END,
        },
        {
            sounds_bank1_wbk_ROM_START,
            sounds_bank1_ptr_ROM_START,
            sounds_bank1_ptr_ROM_END,
            sounds_western1_ROM_START,
            sounds_western1_ROM_END,
        },
        {
            sounds_bank1_wbk_ROM_START,
            sounds_bank1_ptr_ROM_START,
            sounds_bank1_ptr_ROM_END,
            sounds_western2_ROM_START,
            sounds_western2_ROM_END,
        },
        {
            sounds_bank2_wbk_ROM_START,
            sounds_bank2_ptr_ROM_START,
            sounds_bank2_ptr_ROM_END,
            sounds_western_mine_cart_ROM_START,
            sounds_western_mine_cart_ROM_END,
        },
        {
            sounds_bank4_wbk_ROM_START,
            sounds_bank4_ptr_ROM_START,
            sounds_bank4_ptr_ROM_END,
            sounds_victorian1_ROM_START,
            sounds_victorian1_ROM_END,
        },
        {
            sounds_bank4_wbk_ROM_START,
            sounds_bank4_ptr_ROM_START,
            sounds_bank4_ptr_ROM_END,
            sounds_victorian2_ROM_START,
            sounds_victorian2_ROM_END,
        },
        {
            sounds_bank6_wbk_ROM_START,
            sounds_bank6_ptr_ROM_START,
            sounds_bank6_ptr_ROM_END,
            sounds_final_alien_mother_ROM_START,
            sounds_final_alien_mother_ROM_END,
        },
        {
            sounds_bank5_wbk_ROM_START,
            sounds_bank5_ptr_ROM_START,
            sounds_bank5_ptr_ROM_END,
            sounds_boss_ROM_START,
            sounds_boss_ROM_END,
        },
        {
            sounds_bank3_wbk_ROM_START,
            sounds_bank3_ptr_ROM_START,
            sounds_bank3_ptr_ROM_END,
            sounds_present_day_boss_hog_ROM_START,
            sounds_present_day_boss_hog_ROM_END,
        },
        {
            NULL,
            NULL,
            NULL,
            sounds_training_base_ROM_START,
            sounds_training_base_ROM_END,
        },
    },
    {
        {
            sounds_bank7_wbk_ROM_START,
            sounds_bank7_ptr_ROM_START,
            sounds_bank7_ptr_ROM_END,
            sounds_ambient1_ROM_START,
            sounds_ambient1_ROM_END,
        },
        {
            sounds_bank8_wbk_ROM_START,
            sounds_bank8_ptr_ROM_START,
            sounds_bank8_ptr_ROM_END,
            sounds_ambient2_ROM_START,
            sounds_ambient2_ROM_END,
        },
        {
            sounds_bank9_wbk_ROM_START,
            sounds_bank9_ptr_ROM_START,
            sounds_bank9_ptr_ROM_END,
            sounds_ambient3_ROM_START,
            sounds_ambient3_ROM_END,
        },
        {
            sounds_bank10_wbk_ROM_START,
            sounds_bank10_ptr_ROM_START,
            sounds_bank10_ptr_ROM_END,
            sounds_ambient4_ROM_START,
            sounds_ambient4_ROM_END,
        },
        {
            sounds_bank11_wbk_ROM_START,
            sounds_bank11_ptr_ROM_START,
            sounds_bank11_ptr_ROM_END,
            sounds_ambient5_ROM_START,
            sounds_ambient5_ROM_END,
        },
        {
            sounds_bank12_wbk_ROM_START,
            sounds_bank12_ptr_ROM_START,
            sounds_bank12_ptr_ROM_END,
            sounds_ambient6_ROM_START,
            sounds_ambient6_ROM_END,
        },
        {
            sounds_bank13_wbk_ROM_START,
            sounds_bank13_ptr_ROM_START,
            sounds_bank13_ptr_ROM_END,
            sounds_ambient7_ROM_START,
            sounds_ambient7_ROM_END,
        },
        {
            sounds_bank14_wbk_ROM_START,
            sounds_bank14_ptr_ROM_START,
            sounds_bank14_ptr_ROM_END,
            sounds_ambient8_ROM_START,
            sounds_ambient8_ROM_END,
        },
        {
            sounds_bank15_wbk_ROM_START,
            sounds_bank15_ptr_ROM_START,
            sounds_bank15_ptr_ROM_END,
            sounds_ambient9_ROM_START,
            sounds_ambient9_ROM_END,
        },
    },
};

/*800BD604*/ musHandle gMusicHandle = 0;
/*800BD608*/ musHandle gAmbientHandle = 0;
static s32 _unused = 0;
/*800BD610*/ static s32 D_800BD610 = 16384;
/*800BD614*/ static s32 D_800BD614 = 256;
/*800BD618*/ static u8 D_800BD618 = 0;
/*800BD61A*/ s16 D_800BD61A = 0;
/*800BD61C*/ static musHandle D_800BD61C[6] = {0};
/*800BD634*/ static musHandle D_800BD634[MAXPLAYERS] = {0};
/*800BD644*/ static u16 D_800BD644[MAXPLAYERS] = {0};
/*800BD64C*/ static u16 D_800BD64C[8] = {1279, 1625, 1280, 1281, 1626, 1627, 1628, 0};
/*800BD65C*/ static u16 D_800BD65C[8] = {1283, 1629, 1287, 1630, 1631, 1288, 1632, 0};
/*800BD66C*/ static u16 D_800BD66C[8] = {1294, 1298, 1633, 1300, 1301, 1302, 1304, 0};
/*800BD67C*/ static u16 D_800BD67C[4] = {1660, 1661, 1664, 0};
/*800BD684*/ static u16 D_800BD684[6] = {1660, 1661, 1662, 1663, 1664, 1665};

/*800BD690*/
static audioUnkStruct2 D_800BD690[42] = {
    { 1, 0 },
    { 0, -1 },
    { -1, 6 },
    { -1, 5 },
    { -1, -1 },
    { 1, -1 },
    { 10, -1 },
    { 3, 2 },
    { -1, 2 },
    { 4, 4 },
    { -1, 2 },
    { -1, -1 },
    { 9, -1 },
    { 6, 3 },
    { -1, 3 },
    { 7, 8 },
    { 7, 1 },
    { 6, -1 },
    { 9, -1 },
    { 1, -1 },
    { 8, -1 },
    { 9, 7 },
    { 2, -1 },
    { 11, -1 },
    { 0, -1 },
    { 7, -1 },
    { 6, -1 },
    { 1, -1 },
    { 8, -1 },
    { 3, -1 },
    { 4, -1 },
    { 2, -1 },
    { 8, -1 },
    { 6, -1 },
    { 1, -1 },
    { 0, -1 },
    { 9, -1 },
    { 7, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { 0, 0 },
};

/*800BD6E4*/
static s16 _multiplier[21] = {
    0x46, 0x46, 0x46, 0x46, 0x46, 0x64, 0x46, 0x46, 0x46, 0x46, 0x50,
    0x4B, 0x00, 0x00, 0x00, 0x17, 0x00, 0x08, 0x00, 0x00, 0x00,
};

/*.comm*/
/*800FEA98*/ audioUnkStruct1 D_800FEA98[32] ALIGNED(8);
/*8010A9C0*/ u8 gSfxBankBuffer[SFX_BANK_SIZE] ALIGNED(16);
/*80129810*/ u8 gMusicBuffer[MUSIC_BUFFER_SIZE] ALIGNED(16);
/*80138608*/ s16 gMusicNum;
/*8013F960*/ u8 gSfxPbankBuffer[SFX_PBANK_SIZE] ALIGNED(16);
/*8016D190*/ u8 gAudioMemory[AUDIO_HEAP_SIZE] ALIGNED(16);
/*80195190*/ u8 gAmbientBuffer[AMBIENT_BUFFER_SIZE] ALIGNED(16);
/*80197D54*/ s32 gMasterVolume;
/*80199754*/ s32 gMusicVolume;
/*8019A9A0*/ u8 gAmbientPbankBuffer[AMBIENT_PBANK_SIZE] ALIGNED(16);
/*801A2840*/ u8 gMusicPbankBuffer[MUSIC_PBANK_SIZE] ALIGNED(16);
/*801AC8D4*/ s16 D_801AC8D4[4];
/*801B0D3C*/ u16 gSfxCount;

/*.text*/
static void audio_80006E60(void);
static void audio_80006F08(void);
static musHandle audio_800075EC(u16 sfxnum, s16 spritenum, u8);
static void audio_80007FF4(void);

static inline musHandle get_D_800BD61C(s32 i)
{
    return D_800BD61C[i];
}

/*800065F0*/
void dmaRomToRam(u8 *rom, u8 *ram, s32 size)
{
    OSIoMesg dmaIOMessageBuf;
    s32 len;

    osInvalDCache(ram, size);
    while (size != 0)
    {
        if (size > DMA_LEN)
            len = DMA_LEN;
        else
            len = size;

        osPiStartDma(&dmaIOMessageBuf, OS_MESG_PRI_NORMAL, OS_READ, (uintptr_t)rom, ram, len, &gDmaMessageQ);
        rom += len;
        ram += len;
        size -= len;
        osRecvMesg(&gDmaMessageQ, NULL, OS_MESG_BLOCK);
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

/*80006838*/
void setVolume(u32 musicvol, u32 mastervol)
{
    gMusicVolume = musicvol;
    gMasterVolume = mastervol;
    MusSetMasterVolume(1, (mastervol * 32767) / 100);

    if (gMusicNum != -1)
        musicvol = musicvol * _multiplier[gMusicNum] / 100;

    MusHandleSetVolume(gMusicHandle, (musicvol * 128) / 100);
    MusHandleSetVolume(gAmbientHandle, (mastervol *128) / 100);
}

/*80006938*/
void initAudio(void)
{
    initMusicDriver();
    MusSetMasterVolume(MUSFLAG_EFFECTS | MUSFLAG_SONGS, 32767);
    setVolume(50, 100);
    initBank(PBANK0_START, (PBANK0_END - PBANK0_START), WBANK0_START, gSfxPbankBuffer);
    initSfxBank(SFX_BANK_START, (SFX_BANK_END - SFX_BANK_START));
    MusPtrBankSetCurrent(gMusicPbankBuffer);
    MusFxBankSetPtrBank(gSfxBankBuffer, gSfxPbankBuffer);
}

/*800069D8*/
void playMusic(s32 musicnum)
{
    s16 volume;

    gMusicNum = musicnum;
    if (gMusicVolume != 0)
    {
        MusHandleStop(gMusicHandle, 0);
        while (MusHandleAsk(gMusicHandle));

        if (musicnum < 0)
            gMusicHandle = 0;
        else
        {
            if (_music.music[musicnum].pbank_start)
            {
                initBank(_music.music[musicnum].pbank_start,
                        _music.music[musicnum].pbank_end - _music.music[musicnum].pbank_start,
                        _music.music[musicnum].wbank_start, gMusicPbankBuffer);
                readMusic(_music.music[musicnum].music_start,
                        _music.music[musicnum].music_end - _music.music[musicnum].music_start,
                        gMusicBuffer);
                MusPtrBankSetSingle(gMusicPbankBuffer);
                gMusicHandle = MusStartSong(gMusicBuffer);
            }
            else
            {
                readMusic(_music.music[musicnum].music_start,
                        _music.music[musicnum].music_end - _music.music[musicnum].music_start,
                        gMusicBuffer);
                gMusicHandle = MusStartSong(gMusicBuffer);
            }

            volume = (gMusicVolume * 128) / 100U;
            volume = volume * _multiplier[musicnum] / 100;
            MusHandleSetVolume(gMusicHandle, volume);
        }
    }
}

/*80006BA0*/
void playAmbient(s32 ambientnum)
{
    MusHandleStop(gAmbientHandle, 0);
    while (MusHandleAsk(gAmbientHandle));

    if (ambientnum < 0)
        gAmbientHandle = 0;
    else
    {
        initBank(
          _music.ambient[ambientnum].pbank_start,
          _music.ambient[ambientnum].pbank_end - _music.ambient[ambientnum].pbank_start,
          _music.ambient[ambientnum].wbank_start,
          gAmbientPbankBuffer);
        readMusic(
          _music.ambient[ambientnum].music_start,
          _music.ambient[ambientnum].music_end - _music.ambient[ambientnum].music_start,
          gAmbientBuffer);
        MusPtrBankSetSingle(gAmbientPbankBuffer);
        gAmbientHandle = MusStartSong(gAmbientBuffer);
        MusHandleSetVolume(gAmbientHandle, (gMasterVolume * 128) / 100U);
    }
}

/*80006CC0*/
void audio_80006CC0(void)
{
    s16 i;

    if (D_801AE914 != 0)
    {
        if (D_800BD618 == 0)
        {
            audio_80006E60();
            D_800BD618 = 1;
        }
    }
    else
    {
        if (D_800BD618 == 1)
        {
            audio_80006F08();
            D_800BD618 = 0;
        }
    }

    for (i = 0; i < ARRAY_COUNT(D_800FEA98); i++)
    {
        if (MusHandleAsk(D_800FEA98[i].handle) == 0)
        {
            D_800FEA98[i].handle = 0;
            D_800FEA98[i].unk4 = 0;
            D_800FEA98[i].unk6 = 0;
        }
        else
        {
            D_800FEA98[i].unk6++;
        }
    }

    if (gMapNum == MAP_PROBING_THE_DEPTHS)
    {
        if (gPlayer[0].unk50 != -1)
        {
            if (gMusicHandle == 0)
                playMusic(MUSIC_WESTERN_MINE_CART);
        }
        else
        {
            MusHandleStop(gMusicHandle, 0);
            gMusicHandle = 0;
        }
    }
    else
    {
        if (gMusicVolume == 0)
        {
            MusHandleStop(gMusicHandle, 0);
            gMusicHandle = 0;
        }
        else if (gMusicHandle == 0)
        {
            playMusic(gMusicNum);
        }
    }
}

/*80006E60*/
static void audio_80006E60(void)
{
    s16 i;

    for (i = 0; i < ARRAY_COUNT(D_800FEA98); i++)
    {
        if (D_800FEA98[i].handle)
            MusHandleSetVolume(D_800FEA98[i].handle, 0);
    }

    MusHandleSetVolume(gAmbientHandle, 0);

    if ((gPlayer[0].unk45 == 0) || (D_8012C470 >= 2))
        MusHandleSetVolume(gMusicHandle, 0);
}

/*80006F08*/
static void audio_80006F08(void)
{
    s16 i;
    s16 volume;

    if (gPlayer[0].unk45 != 0)
    {
        if (D_8012C470 == 1)
        {
            gMasterVolume = 0;
            MusSetMasterVolume(1, 0);
            return;
        }
    }

    for (i = 0; i < ARRAY_COUNT(D_800FEA98); i++)
    {
        if (D_800FEA98[i].handle)
            MusHandleSetVolume(D_800FEA98[i].handle, (gMasterVolume * 128) / 100U);
    }

    MusHandleSetVolume(gAmbientHandle, (gMasterVolume * 128) / 100U);
    volume = (gMusicVolume * 128) / 100U;
    volume = volume * _multiplier[gMusicNum] / 100;
    MusHandleSetVolume(gMusicHandle, volume);
}

/*80007084*/
static s32 func_80007084(u16 sfxnum)
{
    s16 count;
    s16 unk6;
    s16 j;
    s16 ret;
    s16 i;

    ret = -1;
    count = 0;
    unk6 = -1;

    for (i = 0; i < ARRAY_COUNT(D_800FEA98); i++)
    {
        if (D_800FEA98[i].handle == 0)
            ret = i;
        else
        {
            if (D_800FEA98[i].unk4 == sfxnum)
            {
                count++;
                if (unk6 < D_800FEA98[i].unk6)
                {
                    unk6 = D_800FEA98[i].unk6;
                    j = i;
                }
            }
        }
    }

    if (count >= 4)
    {
        MusHandleStop(D_800FEA98[j].handle, 0);
        ret = j;
    }
    return ret;
}

/*80007170*/
musHandle playSfx(u16 sfxnum)
{
    s16 i;
    musHandle handle;

    if (sfxnum != 0)
    {
        if (sfxnum < gSfxCount)
        {
            i = func_80007084(sfxnum);
            if (i != -1)
            {
                handle = MusStartEffect(sfxnum);
                D_800FEA98[i].handle = handle;
                D_800FEA98[i].unk4 = sfxnum;
                D_800FEA98[i].unk6 = 0;
                return handle;
            }
        }
    }
    return 0;
}

/*80007218*/
musHandle playSfx2(u16 sfxnum, s16 volume, s16 pan, u8 restartflag, s16 priority)
{
    s16 i;
    musHandle handle;

    if (sfxnum != 0)
    {
        if (sfxnum < gSfxCount)
        {
            i = func_80007084(sfxnum);
            if (i != -1)
            {
                handle = MusStartEffect2(sfxnum, volume, pan, restartflag, priority);
                D_800FEA98[i].handle = handle;
                D_800FEA98[i].unk4 = sfxnum;
                D_800FEA98[i].unk6 = 0;
                return handle;
            }
        }
    }
    return 0;
}

/*8000730C*/
static musHandle audio_8000730C(u16 arg0, u32 arg1, s32 pan, u8 restartflag)
{
    s32 volume;

    if (gConfig.sound == CONFIG_SOUND_MONO)
        pan = 128;

    if (arg1 >= (u32)D_800BD610)
        return 0;

    arg1 = (D_800BD610 - arg1) * (65536.0 / (D_800BD610));
    volume = (arg1 * 128) >> 16;
    volume = (volume * D_800BD614) >> 8;
    return playSfx2(arg0, volume, pan, restartflag, -1);
}

/*80007418*/
static musHandle audio_80007418(musHandle handle, s32 arg1, s32 pan)
{
    s32 volume;

    if (gConfig.sound == CONFIG_SOUND_MONO)
        pan = 128;

    if (MusHandleAsk(handle) != 0)
    {
        if (arg1 < D_800BD610)
        {
            arg1 = (D_800BD610 - arg1) * (65536.0 / D_800BD610);
            volume = (arg1 * 128) >> 16;
            volume = (volume * D_800BD614) >> 8;
            MusHandleSetVolume(handle, volume);
            MusHandleSetPan(handle, pan);
            return handle;
        }
        MusHandleStop(handle, 0);
    }
    return 0;
}

/*80007510*/
u8 audio_80007510(s32 x, s32 y)
{
    u8 playernum, playernum_;
    s32 value;

    playernum_ = 0;
    D_8013871C = 0x40000000;

    for (playernum = 0; playernum < D_8012C470; playernum++)
    {
        value = func_80040D40(gPlayer[playernum].xpos, gPlayer[playernum].ypos, x, y);
        if (value < D_8013871C)
        {
            D_8013871C = value;
            playernum_ = playernum;
        }
    }
    return playernum_;
}

/*800075EC*/
static musHandle audio_800075EC(u16 sfxnum, s16 spritenum, u8 restartflag)
{
    s32 pan;
    s16 playernum;
    u32 spritenum2;
    s16 spritenum1;

    if (gPlayer[0].unk52 >= 2048)
    {
        playernum = 0;
        spritenum1 = gPlayer[0].unk52 & 0x7FF;
        spritenum2 = func_80040D40(gpSprite[spritenum1].x, gpSprite[spritenum1].y,
                                   gpSprite[spritenum].x, gpSprite[spritenum].y);
    }
    else
    {
        playernum = audio_80007510(gpSprite[spritenum].x, gpSprite[spritenum].y);
        spritenum2 = D_8013871C;
        spritenum1 = gPlayer[playernum].unk4A;
    }

    if ((spritenum2 < 512) || (gConfig.sound == CONFIG_SOUND_MONO))
        pan = 128;
    else
    {
        pan = (D_801A2790[playernum].unk16 -
              getAngle(gpSprite[spritenum1].x - gpSprite[spritenum].x, gpSprite[spritenum1].y - gpSprite[spritenum].y));

        pan &= 0x7FF;
        if (pan >= 1024)
            pan = -pan + 2048;

        pan = pan >> 2;
    }
    return audio_8000730C(sfxnum, spritenum2, pan, restartflag);
}

/*800077F4*/
musHandle audio_800077F4(u16 sfxnum, s16 spritenum)
{
    return audio_800075EC(sfxnum, spritenum, 0);
}

/*80007820*/
musHandle audio_80007820(u16 sfxnum, s16 spritenum)
{
    return audio_800075EC(sfxnum, spritenum, 1);
}

/*8000784C*/
musHandle audio_8000784C(musHandle handle, s16 spritenum)
{
    s32 pan;
    s16 playernum;
    s32 spritenum2;
    s16 spritenum1;

    if (gPlayer[0].unk52 >= 2048)
    {
        playernum = 0;
        spritenum1 = gPlayer[0].unk52 & 0x7FF;
        spritenum2 = func_80040D40(gpSprite[spritenum1].x, gpSprite[spritenum1].y,
                                  gpSprite[spritenum].x, gpSprite[spritenum].y);
    }
    else
    {
        playernum = audio_80007510(gpSprite[spritenum].x, gpSprite[spritenum].y);
        spritenum2 = D_8013871C;
        spritenum1 = gPlayer[playernum].unk4A;
    }

    if ((spritenum2 < 512) || (gConfig.sound == CONFIG_SOUND_MONO))
        pan = 128;
    else
    {
        pan = (D_801A2790[playernum].unk16 -
              getAngle(gpSprite[spritenum1].x - gpSprite[spritenum].x, gpSprite[spritenum1].y - gpSprite[spritenum].y));

        pan &= 0x7FF;
        if (pan >= 1024)
            pan = -pan + 2048;

        pan = pan >> 2;
    }
    return audio_80007418(handle, spritenum2, pan);
}

/*80007A44*/
musHandle audio_80007A44(u16 sfxnum, s16 spritenum, s32 arg2)
{
    musHandle handle;
    D_800BD610 = arg2;
    handle = audio_800077F4(sfxnum, spritenum);
    D_800BD610 = 0x4000;
    return handle;
}

/*80007A80*/
musHandle audio_80007A80(musHandle handle, s16 arg1, s32 arg2)
{
    musHandle hand;
    D_800BD610 = arg2;
    hand = audio_8000784C(handle, arg1);
    D_800BD610 = 0x4000;
    return hand;
}

/*80007AB8*/
void audio_80007AB8(void)
{
    SpriteType *spr;
    s16 i;

    u8 j, k, l, m, n;

    audio_80007FF4();
    n = 0;
    m = 0;
    l = 0;
    k = 0;
    j = 0;

    for (i = 0; i < D_8012C470; i++)
    {
        if (gPlayer[i].unk55 != 0)
            j = 1;

        if ((gPlayer[i].unk52 != -1) && (gPlayer[i].unk52 < 0x800))
        {
            if (gpSprite[gPlayer[i].unk52].picnum != 1423)
                k = 1;
            else
                k = 2;
        }

        if (D_8012F6E4[gPlayer[i].unk4C].unkB != 5)
        {
            if ((D_8010A940[i].unk2[1] != 0) || (D_8010A940[i].unk2[6] != 0))
                l = 1;
            if (D_8010A940[i].unk2[5] != 0)
                m = 1;
        }

        if (D_8010A940[i].unk2[2] != 0)
            n = 1;
    }

    if (j)
    {
        if (get_D_800BD61C(0) == 0)
            D_800BD61C[0] = playSfx(15);

        MusHandleSetVolume(gAmbientHandle, (gMasterVolume << 6) / 100U);
    }
    else
    {
        if (get_D_800BD61C(0) != 0)
        {
            MusHandleStop(get_D_800BD61C(0), 10);
            D_800BD61C[0] = 0;
        }
        MusHandleSetVolume(gAmbientHandle, (gMasterVolume << 7) / 100U);
    }

    if (k != 0)
    {
        if (get_D_800BD61C(1) == 0)
        {
            if (k == 1)
                D_800BD61C[1] = playSfx(1332);
            else
                D_800BD61C[1] = playSfx(1608);
        }
    }
    else
    {
        MusHandleStop(get_D_800BD61C(1), 10);
        D_800BD61C[1] = 0;
    }

    if (l != 0)
    {
        if (get_D_800BD61C(2) == 0)
            D_800BD61C[2] = playSfx(28);
    }
    else
    {
        MusHandleStop(get_D_800BD61C(2), 10);
        D_800BD61C[2] = 0;
    }

    if (m != 0)
    {
        if (get_D_800BD61C(3) == 0)
            D_800BD61C[3] = playSfx(1329);
    }
    else
    {
        MusHandleStop(get_D_800BD61C(3), 10);
        D_800BD61C[3] = 0;
    }

    if (n != 0)
    {
        if (get_D_800BD61C(5) == 0)
            D_800BD61C[5] = playSfx(503);
    }
    else
    {
        MusHandleStop(get_D_800BD61C(5), 10);
        D_800BD61C[5] = 0;
    }

    if (D_800BD61A > 0)
    {
        D_800BD61A--;
        if (get_D_800BD61C(4) == 0)
            D_800BD61C[4] = playSfx(1598);
    }
    else
    {
        MusHandleStop(get_D_800BD61C(4), 10);
        D_800BD61C[4] = 0;
    }

    i = gHeadSpriteStat[110];
    while (i >= 0)
    {
        spr = &gpSprite[i];
        if (spr->picnum == 5)
        {
            if (spr->unk24 != 0)
            {
                MusHandleStop(D_8013B2D0[i].handle, 0);
                D_8013B2D0[i].handle = 0;
            }
            else
            {
                D_800BD610 = (u16)spr->unk1A;
                D_800BD614 = spr->unk25;
                if (D_8013B2D0[i].handle == 0)
                    D_8013B2D0[i].handle = audio_800077F4(spr->lotag, i);
                else
                    D_8013B2D0[i].handle = audio_8000784C(D_8013B2D0[i].handle, i);
            }
        }
        i = gNextSpriteStat[i];
    }
    D_800BD610 = 0x4000;
    D_800BD614 = 0x100;
}

/*80007FF4*/
static void audio_80007FF4(void)
{
    s16 i;
    for (i = 0; i < D_8012C470; i++)
    {
        if (D_800BD644[i])
        {
            D_800BD644[i]--;
            if (!D_800BD644[i])
            {
                MusHandleStop(D_800BD634[i], 0);
                D_800BD634[i] = playSfx(D_801AC8D4[i]);
            }
        }
    }
}

/*800080E0*/
void audio_800080E0(s16 playernum, u16 arg1)
{
    _11D520UnkStruct1 *ptr;
    s32 i, l;
    u16 j, k;
    u8 temp; /*FAKEMATCH*/

    if ((arg1 == 3) || (arg1 == 4))
        MusHandleStop(D_800BD634[playernum], 0);

    if (((arg1 == 3) || (arg1 == 4)) ||
        ((MusHandleAsk(D_800BD634[playernum]) == 0) && (gPlayer[playernum].unk45 == 0)))
    {
        temp = 0;
        if ((D_8012C470 < 2) ||
            (((arg1 != 3) && (arg1 != 8)) == 0) ||
            ((arg1 == 9) || (arg1 == 10)))
        {
            if ((arg1 == 3) || (arg1 == 8) ||
                (arg1 == 9) || (arg1 == 10) || (arg1 == 19))
                i = 1;
            else
                i = 0;

            if (D_8012F6E4[gPlayer[playernum].unk4C].unkB != 0)
            {
                switch (D_8012F6E4[gPlayer[playernum].unk4C].unkB)
                {
                case 1:
                    if (arg1 == 3)
                        arg1 = 21;
                    else if ((arg1 == 8) || (arg1 == 9) || (arg1 == 10))
                        arg1 = 20;
                    else
                        arg1 = 0xFFFF;
                    break;
                case 2:
                    if (arg1 == 3)
                        arg1 = 23;
                    else if ((arg1 == 8) || (arg1 == 9) || (arg1 == 10))
                        arg1 = 22;
                    else
                        arg1 = 0xFFFF;
                    break;
                case 4:
                    if (arg1 == 3)
                        arg1 = 25;
                    else if ((arg1 == 8) || (arg1 == 9) || (arg1 == 10))
                        arg1 = 24;
                    else
                        arg1 = 0xFFFF;
                    break;
                case 3:
                    if (arg1 == 3)
                        arg1 = 27;
                    else if ((arg1 == 8) || (arg1 == 9) || (arg1 == 10))
                        arg1 = 26;
                    else
                        arg1 = 0xFFFF;
                    break;
                case 5:
                    arg1 = 28;
                    break;
                }
            }

            if (D_8012F6E4[gPlayer[playernum].unk4C].unk0 == 2366)
            {
                if (arg1 == 3)
                    arg1 = 30;
                else if ((arg1 == 8) || (arg1 == 9) || (arg1 == 10))
                    arg1 = 29;
            }

            if (arg1 != 0xFFFF)
            {
                ptr = &D_801ACBD8[arg1];
                if (func_801C0FDC(100) < ptr->unk6)
                {
                    do
                    {
                        k = ptr->unk4;
                        if (arg1 == 1)
                        {
                            if ((gMapNum < MAP_NUCLEAR_WINTER) || (gMapNum >= MAP_BOSS_HOG))
                                k--;
                        }
                        else if (arg1 == 13)
                        {
                            if ((gMapNum < MAP_NUCLEAR_WINTER) || (gMapNum >= MAP_BOSS_HOG))
                                k--;
                        }
                        l = func_801C0FDC(k);
                        j = ptr->unk0[l];
                    } while (j == D_801AC8D4[playernum]);

                    if (gPlayer[playernum].unk54 != temp)
                    {
                        if (arg1 == 3)
                            j = 1101;

                        if ((arg1 == 8) || (arg1 == 9) || (arg1 == 10))
                            j = func_801C0FDC(5) + 1684;
                    }

                    D_801AC8D4[playernum] = j;
                    D_800BD644[playernum] = 15;

                    if ((i || (arg1 == 4) || (arg1 == 17)))
                        D_800BD644[playernum] = 1;
                }
            }
        }
    }
}

/*80008574*/
void audio_80008574(s16 playernum, u16 sfxnum)
{
    if ((MusHandleAsk(D_800BD634[playernum]) == 0) && (gPlayer[playernum].unk45 == 0))
        D_800BD634[playernum] = playSfx(sfxnum);
}

/*80008604*/
musHandle audio_80008604(void)
{
    u16 sfxnum;

    switch (D_801CA14C[gMapNum].unk0)
    {
    case 2:
        sfxnum = D_800BD65C[func_801C0FDC(7)];
        break;
    case 3:
        sfxnum = D_800BD64C[func_801C0FDC(7)];
        break;
    default:
        sfxnum = D_800BD66C[func_801C0FDC(7)];
        break;
    }
    return playSfx(sfxnum);
}

/*800086B0*/
void audio_800086B0(u16 arg0)
{
    u16 sfxnum;

    if (!arg0)
        sfxnum = D_800BD67C[func_801C0FDC(3)];
    else
        sfxnum = D_800BD684[func_801C0FDC(6)];

    playSfx(sfxnum);
}

/*80008710*/
void audio_80008710(s16 arg0)
{
    setVolume((gConfig.musicvol * 100) / 7, (gConfig.mastervol * 100) / 7);
    if (arg0 == -1)
    {
        playMusic(2);
    }
    else
    {
        playMusic(D_800BD690[arg0].musicnum);
        playAmbient(D_800BD690[arg0].ambientnum);
    }
}
