#ifndef _8E670_H_
#define _8E670_H_

#include "common.h"
#include "code0/engine.h"

#define CHEAT_FIRST_PERSON 0
#define CHEAT_BIG_HEAD_MODE 1
#define CHEAT_FLAT_SHADING 2
#define CHEAT_WEATHER 3
#define CHEAT_BIG_GUN 4
#define CHEAT_ICE_SKINS 5
#define CHEAT_ACTION_NUKEM 6
#define CHEAT_SELECT_SKIN 7
#define CHEAT_FAST_ZOMBIES 8

#define CHEAT_WEAPON_SMG 0
#define CHEAT_WEAPON_BLASTER 1
#define CHEAT_WEAPON_SNIPER 2
#define CHEAT_WEAPON_FREEZER 3
#define CHEAT_WEAPON_REVOLVER 4
#define CHEAT_WEAPON_CLAW12 5
#define CHEAT_WEAPON_3030 6
#define CHEAT_WEAPON_SAWEDOFF 7
#define CHEAT_WEAPON_VOLTCANNON 8
#define CHEAT_WEAPON_GATTLINGGUN 9
#define CHEAT_WEAPON_GAMMACANNON 10

#define SKIN_DUKENUKEM (1<<0)
#define SKIN_APOCALYPSEDUKE (1<<1)
#define SKIN_COWBOYDUKE (1<<2)
#define SKIN_VICTORIANDUKE (1<<3)
#define SKIN_POSHDUKE (1<<4)
#define SKIN_BATTLEDRESSDUKE (1<<5)
#define SKIN_DOGTAGDUKE (1<<6)
#define SKIN_EVILDUKE (1<<7)
#define SKIN_MARINE (1<<8)
#define SKIN_SERGEANT (1<<9)
#define SKIN_CUSTER (1<<10)
#define SKIN_RIPPER (1<<11)
#define SKIN_XTERMINATOR (1<<12)
#define SKIN_MARSHALL (1<<13)
#define SKIN_SHERIFF (1<<14)
#define SKIN_SQUAW (1<<15)
#define SKIN_SURVIVOR (1<<16)
#define SKIN_KIMBERLYSTROKES (1<<17)
#define SKIN_PIGCOP (1<<18)
#define SKIN_RIOTPIG (1<<19)
#define SKIN_ROADHOG (1<<20)
#define SKIN_WARPIG (1<<21)
#define SKIN_COWBOYGRUNT (1<<22)
#define SKIN_SAVAGEGRUNT (1<<23)
#define SKIN_SOLDIERGRUNT (1<<24)
#define SKIN_CAPITALISTPIG (1<<25)
#define SKIN_ENFORCER (1<<26)
#define SKIN_ENFORCERCAPTAIN (1<<27)
#define SKIN_BATTLEENFORCER (1<<28)
#define SKIN_ALL (-1)

bool awardMapCheat(s16 mapnum);
void func_8008DC24(void);
void func_8008DE14(void);
void func_8008E01C(s16, s32);
void func_8008E04C(s16 playernum);

extern u8 D_800E16A0[MAXPLAYERS];
extern s32 gUnlockedCheat;
extern s32 gUnlockedSkin;
extern s32 D_800E1748;

#endif
