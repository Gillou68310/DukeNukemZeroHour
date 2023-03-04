#include "common.h"
#include "code0/main.h"
#include "code0/audio.h"
#include "code0/41940.h"
#include "code1/code1.h"
#include "code1/EB300.h"

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
#define AUDIO_MAXUNK1 32

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

/*data*/
/*800BD460*/ EXTERN_DATA STATIC Music _music ALIGNED(8);
/*800BD604*/ EXTERN_DATA musHandle gMusicHandle;
/*800BD608*/ EXTERN_DATA musHandle gAmbientHandle;
/*800BD610*/ EXTERN_DATA STATIC s32 D_800BD610;
/*800BD618*/ EXTERN_DATA STATIC u8 D_800BD618;
/*800BD634*/ EXTERN_DATA STATIC musHandle D_800BD634[MAXPLAYERS];
/*800BD644*/ EXTERN_DATA STATIC u16 D_800BD644[4];
/*800BD64C*/ EXTERN_DATA STATIC u16 D_800BD64C[8];
/*800BD65C*/ EXTERN_DATA STATIC u16 D_800BD65C[8];
/*800BD66C*/ EXTERN_DATA STATIC u16 D_800BD66C[8];
/*800BD67C*/ EXTERN_DATA STATIC u16 D_800BD67C[4];
/*800BD684*/ EXTERN_DATA STATIC u16 D_800BD684[6];
/*800BD690*/ EXTERN_DATA STATIC audioUnkStruct2 D_800BD690[42];
/*800BD6E4*/ EXTERN_DATA STATIC s16 _multiplier[MUSIC_COUNT+AMBIENT_COUNT] ALIGNED(8);

/*.comm*/
/*800FEA98*/ audioUnkStruct1 D_800FEA98[AUDIO_MAXUNK1] ALIGNED(8);
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
STATIC musHandle audio_800075EC(u16 sfxnum, s16 spritenum, u8);
STATIC musHandle audio_8000730C(u16, u32, s32, u8);
STATIC musHandle audio_80007418(musHandle, s32, s32);

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
    MusSetMasterVolume(1U, (mastervol * 32767) / 100);
    if (gMusicNum != -1)
    {
        musicvol = musicvol * _multiplier[gMusicNum] / 100;
    }
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
        {
            gMusicHandle = NULL;
        }
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
    {
        gAmbientHandle = NULL;
    }
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

    for (i = 0; i < AUDIO_MAXUNK1; i++)
    {
        if (MusHandleAsk(D_800FEA98[i].handle) == 0)
        {
            D_800FEA98[i].handle = NULL;
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
        if (D_80117ED8[0].unk50 != -1)
        {
            if (gMusicHandle == NULL)
            {
                playMusic(MUSIC_WESTERN_MINE_CART);
            }
        }
        else
        {
            MusHandleStop(gMusicHandle, 0);
            gMusicHandle = NULL;
        }
    }
    else
    {
        if (gMusicVolume == 0)
        {
            MusHandleStop(gMusicHandle, 0);
            gMusicHandle = NULL;
        }
        else if (gMusicHandle == NULL)
        {
            playMusic(gMusicNum);
        }
    }
}

/*80006E60*/
static void audio_80006E60(void)
{
    s16 i;

    for (i = 0; i < AUDIO_MAXUNK1; i++)
    {
        if (D_800FEA98[i].handle)
            MusHandleSetVolume(D_800FEA98[i].handle, 0);
    }

    MusHandleSetVolume(gAmbientHandle, 0);
    if ((D_80117ED8[0].unk45 == 0) || (D_8012C470 >= 2))
    {
        MusHandleSetVolume(gMusicHandle, 0);
    }
}

/*80006F08*/
static void audio_80006F08(void)
{
    s16 i;
    s16 volume;

    if (D_80117ED8[0].unk45 != 0)
    {
        if (D_8012C470 == 1)
        {
            gMasterVolume = 0;
            MusSetMasterVolume(1U, 0);
            return;
        }
    }

    for (i = 0; i < AUDIO_MAXUNK1; i++)
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

    for (i = 0; i < AUDIO_MAXUNK1; i++)
    {
        if (D_800FEA98[i].handle == NULL)
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
    return NULL;
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
    return NULL;
}

/*8000730C*/
INCLUDE_ASM("nonmatchings/src/code0/audio", audio_8000730C);

/*80007418*/
INCLUDE_ASM("nonmatchings/src/code0/audio", audio_80007418);

/*80007510*/
u8 audio_80007510(s32 x, s32 y)
{
    u8 i, j;
    s32 value;

    j = 0;
    D_8013871C = 0x40000000;

    for (i = 0; i < D_8012C470; i++)
    {
        value = func_80040D40(D_80117ED8[i].xpos, D_80117ED8[i].ypos, x, y);
        if (value < D_8013871C)
        {
            D_8013871C = value;
            j = i;
        }
    }
    return j;
}

/*800075EC*/
INCLUDE_ASM("nonmatchings/src/code0/audio", audio_800075EC);

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
INCLUDE_ASM("nonmatchings/src/code0/audio", audio_8000784C);

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
INCLUDE_ASM("nonmatchings/src/code0/audio", audio_80007AB8);

/*80007FF4*/
void audio_80007FF4(void)
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
INCLUDE_ASM("nonmatchings/src/code0/audio", audio_800080E0);

/*80008574*/
void audio_80008574(s16 playernum, u16 sfxnum)
{
    if ((MusHandleAsk(D_800BD634[playernum]) == 0) && (D_80117ED8[playernum].unk45 == 0))
    {
        D_800BD634[playernum] = playSfx(sfxnum);
    }
}

/*80008604*/
void audio_80008604(void)
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
    playSfx(sfxnum);
}

/*800086B0*/
void audio_800086B0(u16 arg0)
{
    u16 sfxnum;

    if (!arg0)
    {
        sfxnum = D_800BD67C[func_801C0FDC(3)];
    }
    else
    {
        sfxnum = D_800BD684[func_801C0FDC(6)];
    }
    playSfx(sfxnum);
}

/*80008710*/
void audio_80008710(s16 arg0)
{
    setVolume((D_801CE4B0.musicvol * 100) / 7, (D_801CE4B0.mastervol * 100) / 7);
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
