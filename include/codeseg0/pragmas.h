#ifndef _PRAGMAS_H_
#define _PRAGMAS_H_

#include "common.h"

s32 mulscale(s64 arg0, s64 arg1, s64 arg2);
s32 mulscale12(s64 arg0, s64 arg1);
s32 mulscale14(s64 arg0, s64 arg1);
s32 mulscale16(s64 arg0, s64 arg1);
s32 mulscale20(s64 arg0, s64 arg1);
s32 mulscale24(s64 arg0, s64 arg1);
s32 mulscale30(s64 arg0, s64 arg1);
s32 mulscale32(s64 arg0, s64 arg1);
s32 dmulscale3(s64 arg0, s64 arg1, s64 arg2, s64 arg3);
s32 dmulscale6(s64 arg0, s64 arg1, s64 arg2, s64 arg3);
s32 dmulscale14(s64 arg0, s64 arg1, s64 arg2, s64 arg3);
s32 dmulscale15(s64 arg0, s64 arg1, s64 arg2, s64 arg3);
s32 dmulscale16(s64 arg0, s64 arg1, s64 arg2, s64 arg3);
s32 divscale15(s64 arg0, s64 arg1);
s32 divscale16(s64 arg0, s64 arg1);
s32 divscale20(s64 arg0, s64 arg1);
s32 divscale24(s64 arg0, s64 arg1);
s32 divscale30(s64 arg0, s64 arg1);
s32 scale(s32 arg0, s32 arg1, s32 arg2);
s32 nsqrtasm(s32 arg0);
s32 klabs(s32 arg0);
s32 func_8002B674(s32 arg0);

#endif