#ifndef _9410_H_
#define _9410_H_

#include "common.h"
#include "code0/engine.h"
#include "static/tileinfo.h"

void loadMap(s32 mapnum);
void func_80008E3C(void);
s32 func_8000921C(void);
void func_8000A070(void);
void func_8000B570(s16);
void func_8000B6A8(s16);
void func_8000B830(s16);
void func_8000BDB0(s16 tileid);
void func_8000C0D0(s16 tilenum);
void func_8000C3E4(s16 tilenum);
void func_8000C76C(void);
void func_8000DBDC(u8, u8);
void func_8000E04C(void);
void func_8000EA0C(u8, s16, s16, s16, s16);
void func_8000EB4C(u8, s16, s16, s16, s16);
u16 getTileNum(u16 tileid);
u8 *loadTile(u16 tilenum);
s32 tileMasks(u16);
s32 tileMaskt(u16);

typedef struct
{
    /*0x00*/ u8 unk0;
    /*0x01*/ u8 unk1;
    /*0x02*/ u8 unk2;
    /*0x03*/ u8 unk3;
} _9410UnkStruct1;

extern f32 gMapXpos;
extern f32 gMapYpos;
extern f32 gMapZpos;

extern _9410UnkStruct1 D_800BD710[5];
extern u32 gDisplayListSize;
extern u32 gVertexN64Size;

#endif
