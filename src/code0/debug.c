#include "common.h"

/*.data*/
/*800DF950*/ EXTERN_DATA s16 gLoadMapNum;
/*800DF98C*/ EXTERN_DATA u8 D_800DF98C;
/*800DF990*/ EXTERN_DATA u8 D_800DF990;

/*.text*/

INCLUDE_RODATA("nonmatchings/src/code0/debug", D_800E8DD0);
INCLUDE_RODATA("nonmatchings/src/code0/debug", D_800E8DDC);
INCLUDE_RODATA("nonmatchings/src/code0/debug", D_800E8DE0);
INCLUDE_RODATA("nonmatchings/src/code0/debug", D_800E8DE4);
INCLUDE_RODATA("nonmatchings/src/code0/debug", D_800E8DE8);
INCLUDE_RODATA("nonmatchings/src/code0/debug", D_800E8DEC);
INCLUDE_RODATA("nonmatchings/src/code0/debug", D_800E8DF8);
INCLUDE_RODATA("nonmatchings/src/code0/debug", D_800E8E00);
INCLUDE_RODATA("nonmatchings/src/code0/debug", D_800E8E0C);
INCLUDE_RODATA("nonmatchings/src/code0/debug", D_800E8E14);
INCLUDE_RODATA("nonmatchings/src/code0/debug", D_800E8E20);

INCLUDE_ASM("nonmatchings/src/code0/debug", debugMenu);
