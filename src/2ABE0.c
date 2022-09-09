#include "common.h"

INCLUDE_ASM(s32, "2ABE0", func_80029FE0);

INCLUDE_ASM(s32, "2ABE0", func_8002A2B0);

INCLUDE_ASM(s32, "2ABE0", func_8002A3A0);

INCLUDE_ASM(s32, "2ABE0", func_8002A7BC);

INCLUDE_ASM(s32, "2ABE0", func_8002A9A0);

INCLUDE_ASM(s32, "2ABE0", func_8002AAC0);

INCLUDE_ASM(s32, "2ABE0", func_8002AAEC);

INCLUDE_ASM(s32, "2ABE0", func_8002AC70);

s8 func_8002A3A0(s32, s32, s32);
void func_8002AC70(void);

void func_8002ACD4(s32 arg0, s32 arg1, s32 arg2) {
    while ((func_8002A3A0(arg0, arg1, arg2)) == 0) {
        func_8002AC70();
    }
}

INCLUDE_ASM(s32, "2ABE0", func_8002AD3C);

INCLUDE_ASM(s32, "2ABE0", func_8002ADB8);

INCLUDE_ASM(s32, "2ABE0", func_8002AE4C);
