#ifndef _CODE1_H_
#define _CODE1_H_

#include "common.h"
#include "code0/engine.h"
#include "static/119280.h"
#include "static/mapinfo.h"

#define CONFIG_OFF 0
#define CONFIG_ON  1

#define CONFIG_SOUND_MONO   0
#define CONFIG_SOUND_STEREO 1

#define CONFIG_GRAPHICS_NORMAL  0
#define CONFIG_GRAPHICS_MEDIUM  1
#define CONFIG_GRAPHICS_HIGHRES 2

#define CONFIG_2P_SPLIT_HORZ 0
#define CONFIG_2P_SPLIT_VERT 1

#define CONFIG_3P_SPLIT_EQUAL 0
#define CONFIG_3P_SPLIT_FULL 1

typedef struct
{
    f32 xEye;
    f32 yEye;
    f32 zEye;
    f32 xAt;
    f32 yAt;
    f32 zAt;
    f32 xUp;
    f32 yUp;
    f32 zUp;
} Position;

typedef struct
{
    struct {
        /*0x00*/ u8 main;
        /*0x01*/ u8 options_2P;
        /*0x02*/ u8 select_single_multi_player;
        /*0x03*/ u8 multiplayer_options;
        /*0x04*/ u8 unk4;
        /*0x05*/ u8 unk5;
        /*0x06*/ u8 controller_config;
        /*0x07*/ u8 options_1P;
        /*0x08*/ u8 select_difficulty;
        /*0x09*/ u8 select_multiplayer_gametype;
        /*0x0A*/ u8 unkA;
        /*0x0B*/ u8 unkB;
        /*0x0C*/ u8 unkC;
        /*0x0D*/ u8 unkD;
        /*0x0E*/ u8 select_player;
        /*0x0F*/ u8 unkF;
        /*0x10*/ u8 player_setup;
        /*0x11*/ u8 unk11;
        /*0x12*/ u8 cheats;
        /*0x13*/ u8 cheats_others;
        /*0x14*/ u8 cheats_game_type;
        /*0x15*/ u8 cheats_weapons;
    } menuIndex;

    /*0x16*/ u16 sound;
    /*0x18*/ u16 mastervol;
    /*0x1A*/ u16 musicvol;
    /*0x1C*/ u16 rumblepak;

    struct {
        /*0x1E*/ u16 radar;
        /*0x20*/ u16 time_limit;
        /*0x22*/ u16 frag_count;
        /*0x24*/ u16 split_2P;
        /*0x26*/ u16 split_3P;
        /*0x28*/ u16 friendly_fire;
        /*0x2A*/ u16 players;
    } multiplayer;

    /*0x2C*/ u16 unused;
    /*0x2E*/ u16 controller_preset[MAXPLAYERS];
    /*0x36*/ u16 crosshair[MAXPLAYERS];
    /*0x3E*/ u16 autoaim[MAXPLAYERS];
    /*0x46*/ u16 autocenter[MAXPLAYERS];
    /*0x4E*/ u16 difficulty;
    /*0x50*/ u8 unk50;
} Config;

typedef struct
{
    /*0x000*/ u16 unk0;
    /*0x002*/ u16 unk2;
    /*0x004*/ u16 unk4[24][3];
    /*0x148*/ u16 unk148[8];
    /*0x164*/ u16 enemies_total;
    /*0x166*/ u16 babes_total;
    /*0x168*/ u16 secrets_total;
    /*0x172*/ s32 unk172; /*time_taken*/
    /*0x176*/ u16 enemies_killed;
    /*0x178*/ u16 babes_saved;
    /*0x180*/ u16 secrets_found;
    /*0x182*/ u8 unk182;
} code1UnkStruct2;

typedef struct
{
    /*0x0000*/ u16 unk0;
    /*0x0002*/ u16 unk2;
    /*0x0004*/ code1UnkStruct2 unk4[MAP_THE_END];
    /*0x0FD4*/ u8 unkFD4;
    /*0x0FD5*/ u8 unkFD5; /*mapnum*/
    /*0x0FD6*/ u8 unkFD6;
    /*0x0FD7*/ u8 unkFD7;
    /*0x0FD8*/ s32 unlocked_skin;
    /*0x0FDC*/ s32 unlocked_cheat;
    /*0x0FE0*/ u16 unlocked_cheat_weapons;
    /*0x0FE4*/ s32 time_machine_part;
    /*0x0FE8*/ Config unkFE8;
    /*0x103A*/ u8 unk103A;
    /*0x103C*/ u8 pad2;
} code1UnkStruct3;

typedef struct
{
    code1UnkStruct3 unk0;
#ifdef AVOID_UB
    u8 pad[0xC4]; /*Align 256 bytes*/
#endif
} code1UnkStruct7;

typedef struct
{
    /*0x00*/ u8 unk0;
    /*0x01*/ u8 unk1;
    /*0x02*/ u8 unk2;
} code1UnkStruct4;

typedef struct
{
    /*0x00*/ u16 unk0;
    /*0x02*/ u16 unk2;
    /*0x04*/ u16 unk4;
    /*0x06*/ u16 unk6;
    /*0x08*/ char *unk8;
    /*0x0C*/ ProcPointer unkC;
    /*0x10*/ struct _code1UnkStruct6 *unk10;
    /*0x14*/ struct _code1UnkStruct6 *unk14;
    /*0x18*/ u16 *unk18;
} code1UnkStruct5;

typedef struct _code1UnkStruct6
{
    /*0x00*/ u16 unk0;
    /*0x04*/ code1UnkStruct5 *unk4;
    /*0x08*/ s16 unk8;
    /*0x0A*/ u16 unkA;
    /*0x0C*/ u8 *unkC;
} code1UnkStruct6;

#ifdef _CODE1_C_
#define _extern
#else
#define _extern extern
#endif

/*801CC7F4*/ _extern u16 gCheatWeatherConfig;
/*801CC888*/ _extern u8 *D_801CC888; /*edlHandle*/
/*801CC88C*/ _extern s32 D_801CC88C;
/*801CC8A8*/ _extern u16 gCheatIceSkinConfig;
/*801CC8B8*/ _extern u16 gCheatWeapon3030Config;
/*801CC8C8*/ _extern u16 gCheatBigGunConfig;
/*801CC8CC*/ _extern u16 gCheatSelectSkinConfig;
/*801CC8CA*/ _extern u16 D_801CC8CA;
/*801CC91C*/ _extern u8 *D_801CC91C; /*edlHandle*/
/*801CC920*/ _extern u8 *D_801CC920; /*edlHandle*/
/*801CC924*/ _extern u16 gCheatWeaponSmgConfig;
/*801CC926*/ _extern u16 gCheatBigHeadModeConfig;
/*801CC930*/ _extern code1UnkStruct7 D_801CC930 ALIGNED(16);
/*801CD96C*/ _extern u8 *D_801CD96C;
/*801CD980*/ _extern s32 D_801CD980;
/*801CD984*/ _extern u16 gCheatWeaponGattlingGunConfig;
/*801CD986*/ _extern u16 D_801CD986[3]; /*TODO: Size?*/
/*801CDA80*/ _extern u16 gCheatWeaponClaw12Config;
/*801CDA98*/ _extern u8 *D_801CDA98; /*edlHandle*/
/*801CDACC*/ _extern s32 D_801CDACC;
/*801CDAD0*/ _extern ControlMapping *gpControlPreset;
/*801CDB00*/ _extern char **gpLicenceStrInfo;
/*801CDB08*/ _extern u8 *D_801CDB08; /*edlHandle*/
/*801CDB10*/ _extern u8 *D_801CDB10;
/*801CDB14*/ _extern u16 gCheatWeaponSawedOffConfig;
/*801CDB18*/ _extern u8 *D_801CDB18;
/*801CDB16*/ _extern u16 gCheatWeaponVoltCannonConfig;
/*801CDB1C*/ _extern u8 *D_801CDB1C; /*edlHandle*/
/*801CDB44*/ _extern u8 *D_801CDB44;
/*801CDB48*/ _extern u16 gCheatWeaponBlasterConfig;
/*801CDB4C*/ _extern s32 D_801CDB4C;
/*801CDBC4*/ _extern u16 gCheatActionNukemConfig;
/*801CDBC6*/ _extern u16 gCheatFirstPersonConfig;
/*801CDBC8*/ _extern u8 *D_801CDBC8; /*edlHandle*/
/*801CDBCC*/ _extern u16 gCheatFlatShadingConfig;
/*801CDC64*/ _extern code1UnkStruct4 D_801CDC64;
/*801CDC68*/ _extern s8 *D_801CDC68;
/*801CDC70*/ _extern s8 D_801CDC70[0x800] ALIGNED(16);
/*801CE470*/ _extern u16 gUnlockedCheatWeapons;
/*801CE478*/ _extern u16 gCheatWeaponRevolverConfig;
/*801CE480*/ _extern u16 gCheatWeaponGammaCannonConfig;
/*801CE48C*/ _extern u16 gCheatFastZombiesConfig;
/*801CE498*/ _extern Config gConfig ALIGNED(8);
/*801CE4EA*/ _extern u16 gPerspNorm;
/*801CE4EC*/ _extern u16 gCheatWeaponSniperConfig;
/*801CE5A0*/ _extern s32 D_801CE5A0;
/*801CE5AC*/ _extern u16 gGraphicsOption;
/*801CE5B0*/ _extern Position gPosition ALIGNED(8);
/*801CE5D4*/ _extern char **gpCreditStrInfo;
/*801CE5D8*/ _extern s32 D_801CE5D8;
/*801CE5E8*/ _extern _119280UnkStruct1 *D_801CE5E8;
/*801CE5F0*/ _extern code1UnkStruct3 D_801CE5F0 ALIGNED(16);
/*801CF634*/ _extern u16 gCheatWeaponFreezerConfig;

#undef _extern

#endif
