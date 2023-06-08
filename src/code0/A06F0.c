#include "common.h"
#include "code0/main.h"
#include "code0/9410.h"
#include "code0/1A7C0.h"
#include "code0/24610.h"
#include "code0/code0.h"

/*TODO: include string.h from libkmc instead of libultra*/
char *strcpy(char *, const char *);

/*.text*/

/*8009FAF0*/
INCLUDE_ASM("nonmatchings/src/code0/A06F0", func_8009FAF0);

/*8009FEB0*/
INCLUDE_ASM("nonmatchings/src/code0/A06F0", func_8009FEB0);

/*800A0014*/
INCLUDE_ASM("nonmatchings/src/code0/A06F0", func_800A0014);

/*800A0698*/
INCLUDE_ASM("nonmatchings/src/code0/A06F0", func_800A0698);

/*800A0BD4*/
INCLUDE_ASM("nonmatchings/src/code0/A06F0", func_800A0BD4);

/*800A0D08*/
INCLUDE_ASM("nonmatchings/src/code0/A06F0", func_800A0D08);

/*800A0E74*/
INCLUDE_ASM("nonmatchings/src/code0/A06F0", func_800A0E74);

INCLUDE_RODATA("nonmatchings/src/code0/A06F0", D_800E9E88);
INCLUDE_RODATA("nonmatchings/src/code0/A06F0", D_800E9EA4);
INCLUDE_RODATA("nonmatchings/src/code0/A06F0", D_800E9EBC);
INCLUDE_RODATA("nonmatchings/src/code0/A06F0", D_800E9ED4);
INCLUDE_RODATA("nonmatchings/src/code0/A06F0", D_800E9EDC);
INCLUDE_RODATA("nonmatchings/src/code0/A06F0", D_800E9EE8);
INCLUDE_RODATA("nonmatchings/src/code0/A06F0", D_800E9EF4);
/*800A0F84*/
INCLUDE_ASM("nonmatchings/src/code0/A06F0", func_800A0F84);

/*800A34CC*/
static void func_800A34CC(s32 x, s32 y, u16 tileid, s16 arg3)
{
    func_8001D128(&x, &y);
    func_80027C18(x,
                  y,
                  (D_80199110 * 3.0f) / 160.0,
                  (D_801A1980 * 3.0f) / 120.0,
                  getTileNum(tileid),
                  arg3);
}

/*800A359C*/
static void func_800A359C(s32 x, s32 y, u16 tileid, s16 arg3)
{
    f32 f1, f2;

    func_8001D128(&x, &y);
    f1 = (gScreenWidth * 3) / 320.0;
    f2 = (gScreenHeight * 3) / 240.0;
    func_80027C18(x,
                  y,
                  f1,
                  f2,
                  getTileNum(tileid),
                  arg3);
}

/*800A3688*/
INCLUDE_ASM("nonmatchings/src/code0/A06F0", func_800A3688);

/*800A419C*/
void func_800A419C(s16 arg0, char *arg1)
{
    s16 i;

    if (D_8012C470 == 1)
    {
        for (i = 3; i > 0; i--)
        {
            D_80138858[i] = D_80138858[i-1];
            strcpy(D_8012FCB0[i], D_8012FCB0[i-1]);
        }
        D_80138858[arg0] = 90;
        strcpy(D_8012FCB0[arg0], arg1);
    }
    else
    {
        D_80138858[arg0] = 90;
        strcpy(D_8012FCB0[arg0], arg1);
    }
}

/*800A42A4*/
INCLUDE_ASM("nonmatchings/src/code0/A06F0", func_800A42A4);

/*800A4478*/
INCLUDE_ASM("nonmatchings/src/code0/A06F0", func_800A4478);
