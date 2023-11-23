#ifndef _119280_H_
#define _119280_H_

#include "common.h"

#define CONTROL_PRESET_DUKE 0
#define CONTROL_PRESET_ATOMIC 1
#define CONTROL_PRESET_SHAKEN 2
#define CONTROL_PRESET_STIRRED 3
#define CONTROL_PRESET_NUKE 4
#define CONTROL_PRESET_NITRO 5
#define CONTROL_PRESET_GOLDEN 6
#define CONTROL_PRESET_DIAMOND 7
#define CONTROL_PRESET_NUM 8
#define CONTROL_MAPPING_NUM 16

typedef union
{
    struct
    {
        char *turn_left;
        char *turn_right;
        char *move_forward;
        char *move_back;
        char *move_left;
        char *move_right;
        char *look_up;
        char *look_down;
        char *jump;
        char *fire;
        char *open;
        char *next_weapon;
        char *last_weapon;
        char *next_item;
        char *previous_item;
        char *activate_item;
    }u;
    char *mapping[16];
} ControlMapping;

typedef struct
{
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
} _119280UnkStruct1;

extern _119280UnkStruct1 D_01022510[64];
extern u8 D_01022790[512];
extern ControlMapping gControlPreset[CONTROL_PRESET_NUM];

#endif
