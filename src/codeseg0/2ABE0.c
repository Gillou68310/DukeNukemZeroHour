#include "common.h"
#include "codeseg0/2ABE0.h"
#include "codeseg0/common0.h"

typedef struct
{
    s32 unk_00;
    s32 unk_04;
    u8 *unk_08;
}unkStruct1;

/*.comm*/
/*800FF540*/ unkStruct1 D_800FF540[2048];

/*.text*/

INCLUDE_ASM(s32, "src/codeseg0/2ABE0", func_80029FE0);

INCLUDE_ASM(s32, "src/codeseg0/2ABE0", func_8002A2B0);

static s8 func_8002A3A0(s32, s32, s32);
INCLUDE_ASM(s32, "src/codeseg0/2ABE0", func_8002A3A0);

INCLUDE_ASM(s32, "src/codeseg0/2ABE0", func_8002A7BC);

INCLUDE_ASM(s32, "src/codeseg0/2ABE0", func_8002A9A0);

INCLUDE_ASM(s32, "src/codeseg0/2ABE0", func_8002AAC0);

INCLUDE_ASM(s32, "src/codeseg0/2ABE0", func_8002AAEC);

void func_8002AC70(void) {
    s32 i;

    for(i = 0; i < D_800DD404; i++)
    {
        if (((*D_800FF540[i].unk_08 - 2) & 0xFF) < 0xC6) {
            (*D_800FF540[i].unk_08)--;
        }
    }
}

void func_8002ACD4(s32 arg0, s32 arg1, s32 arg2) {
    while ((func_8002A3A0(arg0, arg1, arg2)) == 0) {
        func_8002AC70();
    }
}

INCLUDE_ASM(s32, "src/codeseg0/2ABE0", func_8002AD3C);

INCLUDE_ASM(s32, "src/codeseg0/2ABE0", func_8002ADB8);

INCLUDE_ASM(s32, "src/codeseg0/2ABE0", func_8002AE4C);
