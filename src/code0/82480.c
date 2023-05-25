#include "common.h"
#include "code0/edl.h"
#include "code0/84490.h"
#include "code0/code0.h"

/*.text*/

/*80081880*/
static f32 _fabs(f32 arg0)
{
    if (!(arg0 >= 0.0f))
        return -arg0;
    else
        return arg0;
}

/*800818A8*/
/*void func_800818A8(code0UnkStruct16 *arg0, s16 id, s16 off, s32 arg3, s32 arg4, s32 arg5, s32 arg6)
{
    s16 *ptr;
    s16 *ptr2;

    ptr = (s16 *)edl_80081840(id, off);
    arg0->unk70 = ptr;
    arg0->unk74 = arg3;
    arg0->unk78 = arg4;
    arg0->unk7C = arg5;
    arg0->unk80 = arg6;
    arg0->unk88 = swap16(ptr);
    arg0->unk84 = (code0UnkStruct18 *)&ptr[1];
    ptr2 = (s16 *)&arg0->unk84[arg0->unk88];
    arg0->unk98 = swap16(ptr2);
    arg0->unk8C = (u8 *)&ptr2[1];
}*/
INCLUDE_ASM("nonmatchings/src/code0/82480", func_800818A8);

INCLUDE_ASM("nonmatchings/src/code0/82480", func_8008196C);

INCLUDE_ASM("nonmatchings/src/code0/82480", func_80081AEC);

INCLUDE_ASM("nonmatchings/src/code0/82480", func_80081E20);

INCLUDE_ASM("nonmatchings/src/code0/82480", func_80082290);

INCLUDE_ASM("nonmatchings/src/code0/82480", func_80082410);

INCLUDE_ASM("nonmatchings/src/code0/82480", func_80082448);

INCLUDE_ASM("nonmatchings/src/code0/82480", func_80082920);

INCLUDE_ASM("nonmatchings/src/code0/82480", func_80082958);

INCLUDE_ASM("nonmatchings/src/code0/82480", func_800829BC);

INCLUDE_ASM("nonmatchings/src/code0/82480", func_80082B44);

INCLUDE_ASM("nonmatchings/src/code0/82480", func_80082BA0);

INCLUDE_ASM("nonmatchings/src/code0/82480", func_800831D8);

INCLUDE_ASM("nonmatchings/src/code0/82480", func_80083200);

INCLUDE_ASM("nonmatchings/src/code0/82480", func_80083430);

INCLUDE_ASM("nonmatchings/src/code0/82480", func_80083700);

INCLUDE_ASM("nonmatchings/src/code0/82480", func_8008372C);

INCLUDE_ASM("nonmatchings/src/code0/82480", func_800837B8);

INCLUDE_ASM("nonmatchings/src/code0/82480", func_8008383C);
