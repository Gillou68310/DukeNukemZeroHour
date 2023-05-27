#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include "common.h"
#include "code0/code0.h"
#include "code1/code1.h"

typedef struct {
    /*0x0*/ u16 button;
    /*0x2*/ u16 button2;
    /*0x4*/ s16 stick_x;
    /*0x6*/ s16 stick_y;
} Controller;

u8 controller_8008A070(void);
void controller_8008A3EC(char *, code1UnkStruct3 *, s32);
void controller_8008A4C4(u8 playernum, u16, u8);
void controller_8008A654(void);
void controller_8008A724(void);
u8 controller_8008AD94(void);
u8 controller_8008AEF0(void);
u8 controller_8008C8DC(void);
u8 controller_8008D354(void);

extern Controller gController[MAXPLAYERS];

#endif
