#include "common.h"
#include "code0/engine.h"
#include "code0/37090.h"
#include "code0/code0.h"

/*.text*/

INCLUDE_ASM("nonmatchings/src/code0/64530", func_80063930);

INCLUDE_ASM("nonmatchings/src/code0/64530", func_80063A40);

INCLUDE_ASM("nonmatchings/src/code0/64530", func_800642CC);

INCLUDE_ASM("nonmatchings/src/code0/64530", func_80064AA0);

/*80064D30*/
static void func_80064D30(s16 *arg0, s16 *arg1, s16 sectnum)
{
    s16 i;

    *arg0 = 2048;
    *arg1 = 32;
    i = gHeadSpriteSect[sectnum];

    while (i >= 0)
    {

        if (gpSprite[i].picnum == 10)
        {
            *arg0 = gpSprite[i].unk1E;
            *arg1 = gpSprite[i].unk20;
            if (*arg1 == 0)
                *arg1 = *arg0;

            break;
        }
        i = gNextSpriteSect[i];
    }
}

/*80064DE0*/
void func_80064DE0(SectorType *sec, u8 arg1, u8 arg2)
{
    s16 i;

    sec->unk27 = arg2;
    sec->unk23 = arg2;
    sec->unk26 = arg1;
    sec->unk22 = arg1;

    for (i = sec->wallptr; i < (sec->wallptr + sec->wallnum); i++)
    {
        gpWall[i].unk21 = arg2;
        gpWall[i].unk1C = arg1;
    }
}

INCLUDE_ASM("nonmatchings/src/code0/64530", func_80064E78);

/*80068D74*/
static void func_80068D74(s16 sectnum)
{
    s16 i;

    i = gHeadSpriteSect[sectnum];
    while (i >= 0)
    {
        if (gpSprite[i].picnum == 1)
        {
            if (gpSprite[i].unk1E == 10)
                gpSprite[i].unk18 = gpSprite[i].unk1A;
        }
        i = gNextSpriteSect[i];
    }
}

/*80068E0C*/
void func_80068E0C(s16 sectnum)
{
    s16 i;

    i = gHeadSpriteSect[sectnum];
    while (i >= 0)
    {
        if (gpSprite[i].picnum == 1)
        {
            if (gpSprite[i].unk1E == 10)
                gpSprite[i].unk18 = 0;
        }
        i = gNextSpriteSect[i];
    }
}

INCLUDE_RODATA("nonmatchings/src/code0/64530", D_800E8954);
INCLUDE_ASM("nonmatchings/src/code0/64530", func_80068E9C);

INCLUDE_ASM("nonmatchings/src/code0/64530", func_80069160);

/*800697D8*/
static void func_800697D8(s16 playernum, s16 arg1, s16 arg2)
{
    u8 i;

    i = 0;
    switch (arg2)
    {
    case 0:
        i = 1;
        break;
    case 1:
        if (D_8010A940[playernum].unkA[3] != 0)
            D_8010A940[playernum].unkA[3] = CLAMP_MIN((D_8010A940[playernum].unkA[3] - arg1), 0);
        else
            i = 1;
        break;
    case 2:
        if (D_8010A940[playernum].unk8 == 0)
            i = 1;
        break;
    }

    if (i != 0)
        func_8003671C(playernum, arg1, -1, -1);
}

INCLUDE_ASM("nonmatchings/src/code0/64530", func_800698E8);

INCLUDE_ASM("nonmatchings/src/code0/64530", func_80069E50);
