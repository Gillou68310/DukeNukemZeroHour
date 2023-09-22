#ifndef _TILEINFO_H_
#define _TILEINFO_H_

#include "common.h"

#define TILENUM 1976

typedef struct
{
    /*0x00*/ s32 fileoff;
    /*0x04*/ u8 *ramaddr;
    /*0x08*/ s32 picanm;
    /*0x0C*/ s16 sizex;
    /*0x0E*/ s16 sizey;
    /*0x10*/ u16 filesize;
    /*0x12*/ u16 dimx;
    /*0x14*/ u16 dimy;
    /*0x16*/ u8 flags;
    /*0x18*/ u16 tileid;
} TileInfo;

extern TileInfo gTileInfo[TILENUM];

#endif
