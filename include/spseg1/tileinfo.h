#ifndef _TILEINFO_H_
#define _TILEINFO_H_

#include "common.h"

#define TILENUM 1976

typedef struct
{
    s32 fileoff;
    u8 *ramaddr;
    s32 picanm;
    s16 sizex;
    s16 sizey;
    u16 filesize;
    u16 dimx;
    u16 dimy;
    u8 flags;
    u16 tileid;
} TileInfo;

#endif
