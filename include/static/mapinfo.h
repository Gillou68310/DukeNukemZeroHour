#ifndef _MAPINFO_H_
#define _MAPINFO_H_

#include "common.h"

#define MAPNUM 38

typedef struct
{
    u8 *rom_start;
    u8 *rom_end;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 sectors;
    s32 sprites;
    s32 walls;
    s32 xpos;
    s32 ypos;
    s32 zpos;
    s16 starting_angle;
    s16 starting_sector;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
} MapInfo;

extern MapInfo gMapInfo[MAPNUM];

#endif