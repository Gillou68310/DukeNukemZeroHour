#include "common.h"
#include "code0/35EA0.h"
#include "code0/code0.h"

/*.text*/
static void func_800355D0(s16 playernum);

/*800352A0*/
static void func_800352A0(s16 playernum)
{
    D_8012D218[playernum][0] = 0x10;
    D_8012D218[playernum][2] = 0x2000;
    D_8012D218[playernum][3] = 8;
    D_8012D218[playernum][4] = 4;
    D_8012D218[playernum][9] = 0x4000;
    D_8012D218[playernum][13] = 2;
    D_8012D218[playernum][14] = 1;
    D_8012D218[playernum][15] = 0x8000;
    D_8012D218[playernum][5] = 0x200;
    D_8012D218[playernum][6] = 0x100;
    D_8012D218[playernum][7] = 0x800;
    D_8012D218[playernum][8] = 0x400;
    D_8012D218[playernum][10] = 0x20;
    D_8012D218[playernum][11] = 0;
    D_8012D218[playernum][12] = 0;

    if (gPlayer[playernum].unk80 & 2)
        func_800355D0(playernum);

    if (gPlayer[playernum].unk80 & 4)
    {
        D_8012D218[playernum][15] = 0;
        D_8012D218[playernum][6] |= 0x8000;
    }
}

/*80035438*/
static void func_80035438(s16 playernum)
{
    D_8012D218[playernum][0] = 0x10;
    D_8012D218[playernum][2] = 0x2000;
    D_8012D218[playernum][9] = 0x4000;
    D_8012D218[playernum][11] = 8;
    D_8012D218[playernum][12] = 4;
    D_8012D218[playernum][13] = 2;
    D_8012D218[playernum][14] = 1;
    D_8012D218[playernum][15] = 0x8000;
    D_8012D218[playernum][5] = 0x200;
    D_8012D218[playernum][6] = 0x100;
    D_8012D218[playernum][7] = 0x800;
    D_8012D218[playernum][8] = 0x400;
    D_8012D218[playernum][10] = 0x20;
    D_8012D218[playernum][3] = 0;
    D_8012D218[playernum][4] = 0;

    if (gPlayer[playernum].unk80 & 2)
        func_800355D0(playernum);

    if (gPlayer[playernum].unk80 & 4)
    {
        D_8012D218[playernum][15] = 0;
        D_8012D218[playernum][6] |= 0x8000;
    }
}

/*800355D0*/
static void func_800355D0(s16 playernum)
{
    s16 i;

    for (i = 0; i < ARRAY_COUNT(D_8012D218[playernum]); i++)
    {
        switch (D_8012D218[playernum][i])
        {
        case 16:
            D_8012D218[playernum][i] = 32;
            break;
        case 32:
            D_8012D218[playernum][i] = 16;
            break;
        case 256:
            D_8012D218[playernum][i] = 1;
            break;
        case 512:
            D_8012D218[playernum][i] = 2;
            break;
        case 1024:
            D_8012D218[playernum][i] = 4;
            break;
        case 2048:
            D_8012D218[playernum][i] = 8;
            break;
        case 1:
            D_8012D218[playernum][i] = 256;
            break;
        case 2:
            D_8012D218[playernum][i] = 512;
            break;
        case 4:
            D_8012D218[playernum][i] = 1024;
            break;
        case 8:
            D_8012D218[playernum][i] = 2048;
            break;
        }
    }
}

/*800356EC*/
void func_800356EC(void)
{
    s16 playernum;

    for (playernum = 0; playernum < ARRAY_COUNT(gPlayer); playernum++)
    {
        gPlayer[playernum].unk80 = 0;
        func_80035794(playernum);
        gPlayer[playernum].unk78 = 1.0f / 3.0f;
        gPlayer[playernum].unk7C = 1.0f / 3.0f;
    }
}

/*80035794*/
void func_80035794(s16 playernum)
{
    switch (gPlayer[playernum].unk80 & 1)
    {
    case 0:
        func_80035438(playernum);
        break;
    case 1:
        func_800352A0(playernum);
        break;
    }
}
