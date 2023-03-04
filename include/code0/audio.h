#ifndef _AUDIO_H_
#define _AUDIO_H_

#include "common.h"
#include "libmus.h"

#define MUSIC_PRESENT_DAY2 0
#define MUSIC_PRESENT_DAY1 1
#define MUSIC_TITLE_SCREEN 2
#define MUSIC_WESTERN1 3
#define MUSIC_WESTERN2 4
#define MUSIC_WESTERN_MINE_CART 5
#define MUSIC_VICTORIAN1 6
#define MUSIC_VICTORIAN2 7
#define MUSIC_FINAL_ALIEN_MOTHER 8
#define MUSIC_BOSS 9
#define MUSIC_PRESENT_DAY_BOSS_HOG 10
#define MUSIC_TRAINING_BASE 11

#define MUSIC_AMBIENT1 0
#define MUSIC_AMBIENT2 1
#define MUSIC_AMBIENT3 2
#define MUSIC_AMBIENT4 3
#define MUSIC_AMBIENT5 4
#define MUSIC_AMBIENT6 5
#define MUSIC_AMBIENT7 6
#define MUSIC_AMBIENT8 7
#define MUSIC_AMBIENT9 8

void dmaRomToRam(u8 *rom, u8 *ram, s32 size);
void initAudio(void);
void setVolume(u32 musicvol, u32 mastervol);
void playMusic(s32 musicnum);
void playAmbient(s32 ambientnum);
musHandle playSfx(u16 sfxnum);
musHandle playSfx2(u16 sfxnum, s16 volume, s16 pan, u8 restartflag, s16 priority);
void audio_80006CC0(void);
u8 audio_80007510(s32 x, s32 y);
musHandle audio_800077F4(u16 sfxnum, s16 spritenum);
musHandle audio_80007820(u16 sfxnum, s16 spritenum);
musHandle audio_8000784C(musHandle handle, s16);
musHandle audio_80007A44(u16 sfxnum, s16 spritenum, s32);
musHandle audio_80007A80(musHandle handle, s16, s32);
void audio_80007AB8(void);
s32 audio_800080E0(s32, s16);
void audio_80008574(s16 playernum, u16 sfxnum);
void audio_80008604(void);
void audio_800086B0(u16);
void audio_80008710(s16);

extern musHandle gMusicHandle;
extern musHandle gAmbientHandle;
extern s16 gMusicNum;
extern s32 gMasterVolume;
extern s32 gMusicVolume;

#endif
