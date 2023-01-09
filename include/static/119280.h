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

typedef struct
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
} ControlMapping;

/*01022510*/ extern u8 D_01022510[];
/*01022790*/ extern u8 D_01022790[];
/*01022990*/ extern ControlMapping gControlPreset[CONTROL_PRESET_NUM];

#endif
