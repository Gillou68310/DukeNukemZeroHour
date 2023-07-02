#include "common.h"
#include "code0/audio.h"
#include "code0/code0.h"
#include "code1/code1.h"

/*.data*/
/*800DF680*/ EXTERN_DATA STATIC u16 D_800DF680[58][4]; /*sfxnum array?*/
/*800DF850*/ EXTERN_DATA STATIC u16 D_800DF850[24][3];
/*800DF8E0*/ EXTERN_DATA STATIC u16 D_800DF8E0[24][2];

/*.comm*/
/*801A19E0*/ s16 D_801A19E0[MAXPLAYERS];

/*.text*/
STATIC void func_80079F60(s32 playernum);
static void func_8007ADBC(s32 playernum);

/*80079830*/
void func_80079830(void)
{

    for (D_801B0820 = 0; D_801B0820 < D_8012C470; D_801B0820++)
    {
        func_80079F60(D_801B0820);
        if (D_801CC924 != 0)
        {
            D_8011A680[D_801B0820][6][1] = 500;
            D_8011A680[D_801B0820][6][0] |= 1;
        }
        if (D_801CDB48 != 0)
        {
            D_8011A680[D_801B0820][2][1] = 280;
            D_8011A680[D_801B0820][2][0] |= 1;
        }
        if (D_801CE4EC != 0)
        {
            D_8011A680[D_801B0820][23][1] = 30;
            D_8011A680[D_801B0820][23][0] |= 1;
        }
        if (D_801CF634 != 0)
        {
            D_8011A680[D_801B0820][15][1] = 600;
            D_8011A680[D_801B0820][15][0] |= 1;
        }
        if (D_801CE478 != 0)
        {
            D_8011A680[D_801B0820][3][1] = 96;
            D_8011A680[D_801B0820][3][0] |= 1;
        }
        if (D_801CDA80 != 0)
        {
            D_8011A680[D_801B0820][4][1] = 96;
            D_8011A680[D_801B0820][4][0] |= 1;
        }
        if (D_801CC8B8 != 0)
        {
            D_8011A680[D_801B0820][7][1] = 100;
            D_8011A680[D_801B0820][7][0] |= 1;
        }
        if (D_801CDB14 != 0)
        {
            D_8011A680[D_801B0820][5][1] = 60;
            D_8011A680[D_801B0820][5][0] |= 1;
        }
        if (D_801CDB16 != 0)
        {
            D_8011A680[D_801B0820][20][1] = 2400;
            D_8011A680[D_801B0820][20][0] |= 1;
        }
        if (D_801CD984 != 0)
        {
            D_8011A680[D_801B0820][16][1] = 500;
            D_8011A680[D_801B0820][16][0] |= 1;
        }
        if (D_801CE480 != 0)
        {
            D_8011A680[D_801B0820][17][1] = 750;
            D_8011A680[D_801B0820][17][0] |= 1;
        }
        func_8007ADBC(D_801B0820);
    }
}

/*80079C20*/
void func_80079C20(s16 spritenum)
{
    code0UnkStruct3 *ptr;
    u16 sfxnum;

    ptr = &D_8019B940[D_80106D50[spritenum]];
    MusHandleStop(ptr->unk70, 0);
    ptr->unk70 = 0;
    sfxnum = D_800DF680[ptr->unk99][1];
    if (sfxnum != 0)
        audio_800077F4(sfxnum, spritenum);
}

/*80079CB4*/
static s32 func_80079CB4(s16 playernum, s16 arg1)
{
    s16 i;

    i = arg1 - 8;
    switch (i)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 10:
    case 11:
    case 13:
    case 15:
        return 0;
    default:
        return ((gPlayer[playernum].unk54 != 0) && (arg1 == 20)) ^ 1;
    }
}

/*80079D38*/
static s16 func_80079D38(s16 playernum, s16 arg1)
{
    s16 i, j;

    i = gHeadSpriteStat[4];
    j = 0;
    while (i >= 0)
    {
        if (gpSprite[i].unk1E == arg1)
        {
            if (gPlayer[playernum].unk4A == gpSprite[i].unk20)
                j++;
        }
        i = gNextSpriteStat[i];
    }
    return j;
}

/*80079DE8*/
u8 func_80079DE8(s16 playernum, s16 arg1)
{
    s16 *ptr;

    ptr = D_8011A680[playernum][arg1];
    if (arg1 == 5)
    {
        if (ptr[1] < 2)
            return 0;
    }

    if (arg1 == 0)
        return 1;

    if (arg1 == 14)
    {
        if (func_80079D38(playernum, 14) >= 5)
            return 0;
    }

    if ((ptr[0] & 1) == 0)
        return 0;

    if (ptr[1] > 0)
        return 1;

    if ((ptr[0] & 4) != 0)
    {
        if (ptr[7] > 0 && arg1 != 4)
            return 1;
    }
    if (arg1 == 10)
    {
        if (func_80079D38(playernum, 10) > 0)
            return 1;
    }

    return 0;
}

/*80079F24*/
static void func_80079F24(s16 playernum, s16 arg1)
{
    if (D_800DF680[arg1][3] != 0)
        playSfx(D_800DF680[arg1][3]);
}

/*80079F60*/
INCLUDE_ASM("nonmatchings/src/code0/7A430", func_80079F60);

/*8007AC6C*/
void func_8007AC6C(s32 arg0, s32 arg1, s32 arg2)
{
    code0UnkStruct3 *ptr;

    ptr = &D_8019B940[D_80106D50[arg1]];
    if (arg2 == 0)
    {
        if (D_800DF680[arg0][1] != 0)
        {
            if (ptr->unk70 == 0)
                ptr->unk70 = audio_800077F4(D_800DF680[arg0][0], arg1);
        }
        else
            audio_800077F4(D_800DF680[arg0][0], arg1);
    }
    else
        audio_800077F4(D_800DF680[arg0][2], arg1);
}

/*8007AD30*/
INCLUDE_ASM("nonmatchings/src/code0/7A430", func_8007AD30);

/*8007ADBC*/
static void func_8007ADBC(s32 playernum)
{
    if (D_8011A680[playernum][2][0] != 0)
    {
        if (D_8011A680[playernum][2][1] == 0)
        {
            D_801A19E0[playernum]++;
            if (D_801A19E0[playernum] >= 600)
                D_8011A680[playernum][2][1] = 1;
        }
        else
            D_801A19E0[playernum] = 0;
    }
}
