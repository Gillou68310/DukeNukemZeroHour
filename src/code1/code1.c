#define _CODE1_C_
#include "code1/code1.h"

#include "code1/EB300.c"
#include "code1/playback.c"

/*Hack to force splat to generate the non matching func*/
#if 0
INCLUDE_ASM("src/code1/code1", playback_801C9D68);
#endif

