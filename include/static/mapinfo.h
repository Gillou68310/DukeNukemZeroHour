#ifndef _MAPINFO_H_
#define _MAPINFO_H_

#include "common.h"

#define MAP_MEAN_STREETS 0
#define MAP_LIBERTY_OR_DEATH 1
#define MAP_NUCLEAR_WINTER 2
#define MAP_WETWORLD 3
#define MAP_FALLOUT 4
#define MAP_UNDER_SIEGE 5
#define MAP_BOSS_HOG 6
#define MAP_DRY_TOWN 7
#define MAP_JAIL_BREAK 8
#define MAP_UP_SHIP_CREEK 9
#define MAP_FORT_ROSWELL 10
#define MAP_PROBING_THE_DEPTHS 11
#define MAP_CYBORG_SCORPION 12
#define MAP_THE_WHITECHAPEL_KILLINGS 13
#define MAP_DAWN_OF_THE_DUKE 14
#define MAP_HYDROGEN_BOMB 15
#define MAP_THE_RACK 16
#define MAP_GOING_DOWN_THE_RACK 17
#define MAP_BRAINSTORM 18
#define MAP_THE_BROTHERS_NUKEM 19
#define MAP_ALIEN_MOTHER 20
#define MAP_ZERO_HOUR 21
#define MAP_THE_END 22
#define MAP_BASE 23
#define MAP_COUNT 24
#define MAP_COOL_AS_ICE 24
#define MAP_MIND_FUNK 25
#define MAP_CHIMERA 26
#define MAP_SLIDERS 27 
#define MAP_ATOMIC 28
#define MAP_HIGH_NOON 29
#define MAP_ROCKY_KNOLL 30
#define MAP_CASHING_IN 31
#define MAP_HIVE 32
#define MAP_CASTLEMANIA 33
#define MAP_TOXIC_SHOCK 34 
#define MAP_FOGGING_HELL 35
#define MAP_CATACOMBS 36
#define MAP_INFERNO 37
#define MAP_NUM 38

typedef struct
{
    /*0x00*/ u8 *rom_start;
    /*0x04*/ u8 *rom_end;
    /*0x08*/ s32 sector_offset;
    /*0x0C*/ s32 wall_offset;
    /*0x10*/ s32 sprite_offset;
    /*0x14*/ s32 sectors;
    /*0x18*/ s32 sprites;
    /*0x1C*/ s32 walls;
    /*0x20*/ s32 xpos;
    /*0x24*/ s32 ypos;
    /*0x28*/ s32 zpos;
    /*0x2C*/ s32 unk2C;
    /*0x30*/ f32 skytop_r;
    /*0x34*/ f32 skytop_g;
    /*0x38*/ f32 skytop_b;
    /*0x3C*/ f32 skybottom_r;
    /*0x40*/ f32 skybottom_g;
    /*0x44*/ f32 skybottom_b;
} MapInfo;

#define PRESENT_DAY 1
#define WESTERN 2
#define VICTORIAN 3
#define FINAL 4
#define DUKEMATCH 5
#define TRAINING 10

typedef struct {
    /*0x00*/ u16 chapter;
    /*0x04*/ char *mapname;
} MapChapter;

extern MapInfo gMapInfo[MAP_NUM];

#endif
