#include "common.h"
#include "code0/audio.h"
#include "code0/41940.h"
#include "code0/6ACA0.h"
#include "code0/6D9E0.h"
#include "code0/code0.h"
#include "code1/code1.h"

/*.data*/
/*800DF680*/
static u16 D_800DF680[24][4] = { /*sfxnum array?*/
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 1601, 0, 635, 0 },
    { 795, 0, 598, 0 },
    { 1602, 0, 1378, 0 },
    { 786, 0, 1379, 0 },
    { 603, 604, 0, 817 },
    { 787, 0, 871, 0 },
    { 582, 0, 0, 0 },
    { 582, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 1015, 1037, 0, 867 },
    { 777, 778, 0, 815 },
    { 1012, 1013, 0, 869 },
    { 629, 0, 0, 0 },
    { 705, 0, 0, 0 },
    { 788, 1038, 0, 1566 },
    { 1606, 0, 0, 0 },
    { 1380, 0, 598, 0 },
    { 1603, 0, 874, 0 },
};

/*800DF740*/
static u16 D_800DF740[34][4] = {
    { 32768, 65535, 65535, 0 },
    { 65535, 65535, 65535, 0 },
    { 32777, 65535, 65535, 9 },
    { 32785, 14, 65535, 17 },
    { 1, 14, 65535, 25 },
    { 32805, 16, 65535, 37 },
    { 32770, 65535, 65535, 2 },
    { 1, 12, 65535, 24 },
    { 32808, 65535, 65535, 40 },
    { 32824, 65535, 65535, 56 },
    { 19, 65535, 65535, 35 },
    { 3, 65535, 65535, 6 },
    { 19, 65535, 65535, 35 },
    { 19, 65535, 65535, 35 },
    { 19, 65535, 65535, 25 },
    { 32770, 65535, 65535, 2 },
    { 32774, 65535, 65535, 6 },
    { 32772, 65535, 65535, 4 },
    { 32808, 14, 65535, 40 },
    { 32808, 65535, 65535, 40 },
    { 32768, 65535, 65535, 0 },
    { 32828, 65535, 65535, 60 },
    { 0, 10, 65535, 14 },
    { 32800, 16, 65535, 32 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 32778, 4, 0, 10 },
    { 32801, 14, 0, 33 },
    { 32804, 12, 0, 36 },
    { 32803, 65535, 65535, 35 },
};

/*800DF850*/
static s16 D_800DF850[24][3] = {
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 292, 310, -10 },
    { 0, 0, 0 },
    { 292, 310, -10 },
    { 292, 310, -10 },
    { 0, 0, 0 },
    { 398, 155, -1 },
    { 0, 0, 0 },
    { 398, 155, -1 },
    { 260, 139, 3 },
    { 219, 148, -5 },
    { 398, 155, 9 },
    { 260, 139, 3 },
    { 0, 0, 0 },
    { 0, 0, 0 },
};

/*800DF8E0*/
static u16 D_800DF8E0[24][2] = {
    { 0, 0 },
    { 0, 0 },
    { 14, 25 },
    { 6, 25 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
};

/*.comm*/
/*80197DEC*/ code0UnkStruct3 *D_80197DEC;
/*801B0810*/ s16 *D_801B0810;
/*801A19E0*/ s16 D_801A19E0[MAXPLAYERS];

/*.text*/
static void func_80079F60(s32 playernum);
static void func_8007AC6C(s32, s32, s32);
static void func_8007ADBC(s32 playernum);

static inline u16 *get_D_800DF8E0(s32 i, s32 j)
{
    return &D_800DF8E0[i][j];
}

/*80079830*/
void func_80079830(void)
{
    for (D_801B0820 = 0; D_801B0820 < D_8012C470; D_801B0820++)
    {
        func_80079F60(D_801B0820);
        if (gCheatWeaponSmgConfig != CONFIG_OFF)
        {
            D_8011A680[D_801B0820][6][1] = 500;
            D_8011A680[D_801B0820][6][0] |= 1;
        }
        if (gCheatWeaponBlasterConfig != CONFIG_OFF)
        {
            D_8011A680[D_801B0820][2][1] = 280;
            D_8011A680[D_801B0820][2][0] |= 1;
        }
        if (gCheatWeaponSniperConfig != CONFIG_OFF)
        {
            D_8011A680[D_801B0820][23][1] = 30;
            D_8011A680[D_801B0820][23][0] |= 1;
        }
        if (gCheatWeaponFreezerConfig != CONFIG_OFF)
        {
            D_8011A680[D_801B0820][15][1] = 600;
            D_8011A680[D_801B0820][15][0] |= 1;
        }
        if (gCheatWeaponRevolverConfig != CONFIG_OFF)
        {
            D_8011A680[D_801B0820][3][1] = 96;
            D_8011A680[D_801B0820][3][0] |= 1;
        }
        if (gCheatWeaponClaw12Config != CONFIG_OFF)
        {
            D_8011A680[D_801B0820][4][1] = 96;
            D_8011A680[D_801B0820][4][0] |= 1;
        }
        if (gCheatWeapon3030Config != CONFIG_OFF)
        {
            D_8011A680[D_801B0820][7][1] = 100;
            D_8011A680[D_801B0820][7][0] |= 1;
        }
        if (gCheatWeaponSawedOffConfig != CONFIG_OFF)
        {
            D_8011A680[D_801B0820][5][1] = 60;
            D_8011A680[D_801B0820][5][0] |= 1;
        }
        if (gCheatWeaponVoltCannonConfig != CONFIG_OFF)
        {
            D_8011A680[D_801B0820][20][1] = 2400;
            D_8011A680[D_801B0820][20][0] |= 1;
        }
        if (gCheatWeaponGattlingGunConfig != CONFIG_OFF)
        {
            D_8011A680[D_801B0820][16][1] = 500;
            D_8011A680[D_801B0820][16][0] |= 1;
        }
        if (gCheatWeaponGammaCannonConfig != CONFIG_OFF)
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
static u8 func_80079CB4(s16 playernum, s16 arg1)
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
        if (gpSprite[i].lotag == arg1)
        {
            if (gPlayer[playernum].unk4A == gpSprite[i].hitag)
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
static void func_80079F60(s32 playernum)
{
    code0unkStruct8 *ptr;
    s32 unk4A;
    s32 cond;
    s32 a, b, c, d, e, f, g, h, i, j, k, l, m;
    s32 temp, temp2;
    s16 n;
    u8 pad[16]; /*FAKEMATCH*/

    (void)pad;
    temp2 = gPlayer[playernum].unk4A;
    D_800FE9D8[playernum] = 0;
    D_80197DEC = &D_8019B940[D_80106D50[gPlayer[playernum].unk4A]];
    unk4A = gPlayer[playernum].unk4A;
    D_801B0810 = D_8011A680[playernum][D_80197DEC->unk99];
    temp = D_8011A680[playernum][D_80197DEC->unk99][0] & 2;
    cond = temp != 0;
    j = D_80197DEC->unk99;
    cond = (gPlayer[playernum].unk54 == 0) ? cond : 0;
    ptr = &D_80197E40[D_80106D50[temp2]];

    if (gPlayer[playernum].unk54 != 0)
    {
        if (D_80197DEC->unk99 == 4)
            j = 31;
        if (D_80197DEC->unk99 == 7)
            j = 32;
        if (D_80197DEC->unk99 == 10)
            j = 33;
        if (D_80197DEC->unk99 == 12)
            j = 33;
        if (D_80197DEC->unk99 == 13)
            j = 33;
    }

    if ((D_80197DEC->unk99 == 4) && (D_801B0810[0] & 4))
        j = 30;

    a = D_800DF740[j][1];
    b = D_800DF740[j][2];
    c = D_800DF740[j][0];
    k = ptr->unk0;
    D_8016A154[playernum] = 0;

    if (D_801B0810[3] != 0)
    {
        if (D_80197DEC->unk99 == 2)
        {
            if (ptr->unk0 == 19)
                func_8007AC6C(2, unk4A, 1);

            if ((cond != 0) && (ptr->unk0 == 36))
                func_8007AC6C(D_80197DEC->unk99, unk4A, 1);
        }

        if (D_80197DEC->unk99 == 3)
        {
            if (cond == 0)
            {
                if (ptr->unk0 == 12)
                    func_8007AC6C(3, unk4A, 1);
            }
            else
            {
                if (ptr->unk0 == 22)
                    func_8007AC6C(3, unk4A, 1);

                if (ptr->unk0 == 25)
                    func_8007AC6C(D_80197DEC->unk99, unk4A, 1);
            }
        }
        D_8016A154[playernum] = 1;
        D_801B0810[3]--;
        D_80199970[playernum] = 0;
        return;
    }

    if (D_800DEED0[playernum] == 0)
    {
        D_80199970[playernum] = 0;
        if (D_801B0810[9] != 0)
        {
            D_800FE9D8[playernum] |= 1;
            if (c & 0x8000)
            {
                if (D_801B0810[8] >= D_800DF740[j][3])
                {
                    D_801B0810[9] = 0;
                    D_801B0810[8] = 0;

                    if (D_80197DEC->unk70 != 0)
                        func_80079C20(unk4A);

                    return;
                }
            }
            else
            {
                if (ptr->unk0 >= D_800DF740[j][3])
                {
                    D_801B0810[9] = 0;
                    D_801B0810[8] = 0;

                    if (D_80197DEC->unk70 != 0)
                        func_80079C20(unk4A);

                    D_80199970[playernum] = 0;
                    return;
                }
            }
        }
        else
            return;
    }

    i = D_80197DEC->unk99;
    if (((D_801B0810[1] == 0) && (i != 0)) && (!(D_801B0810[0] & 4) || (D_801B0810[7] == 0) || (i == 4)))
    {
        func_80079F24(playernum, i);
        D_800DEED0[playernum] = 0;
        D_801B0810[9] = 0;
        D_80199970[playernum] = 0;
    }

    l = i;
    if (!func_80079DE8(playernum, i))
    {
        for (i = 23; i >= 0; i--) /*TODO: ARRAY_COUNT(D_8011A680[playernum])-1*/
        {
            if (func_80079CB4(playernum, i) && func_80079DE8(playernum, i))
            {
                D_80197DEC->unk99 = i;

                D_8011A680[playernum][i][6] = 15;
                D_8011A680[playernum][i][9] = 0;
                D_8011A680[playernum][i][8] = 0;
                D_8011A680[playernum][i][4] = 0;
                break;
            }
        }
        D_8016A154[playernum] = 0;
        D_800DEED0[playernum] = 0;
        D_80199970[playernum] = 0;
        return;
    }

    i = l;
    if (!(D_801B0810[0] & 1) || ((D_801B0810[1] == 0) && (i != 0)))
    {
        if (!(D_801B0810[0] & 4) || (D_801B0810[7] == 0) || (i == 4))
        {
            D_80199970[playernum] = 0;
            return;
        }
    }

    if (i == 10)
    {
        g = 3;
        if (D_8012C470 == 1)
            g = 5;

        if (func_80079D38(playernum, 10) >= g)
        {
            D_80199970[playernum] = 0;
            return;
        }
    }

    D_800FE9D8[playernum] = 1;
    D_801B0810[9] = 1;

    if (D_80199970[playernum] != 0)
    {
        D_80199970[playernum]--;
        return;
    }

    if ((c != -1) && (c & 0x8000))
    {
        h = c - 0x8000;
        D_801B0810[8]++;

        if (h < D_801B0810[8])
            D_801B0810[8] = 1;
        else if ((cond == 0) || (D_801B0810[8] != (h / 2)))
        {
            if (D_801B0810[8] == 1)
                goto block_80;

            goto block_132;
        }
    }
    else if (c != k)
    {
        if (cond != 0)
        {
            if ((c + 6) == k)
                goto block_80;
        }
        goto block_132;
    }

block_80:
    D_80199970[playernum] = 1;

    if ((D_80197DEC->unk99 == 4) || (D_80197DEC->unk99 == 5))
    {
        func_8006D3B8(gPlayer[playernum].unk4A, D_80197DEC->unk99, 0, 0, 0);
        func_8006D3B8(gPlayer[playernum].unk4A, D_80197DEC->unk99, 0, 0, 0);
        func_8006D3B8(gPlayer[playernum].unk4A, D_80197DEC->unk99, 0, 0, 0);
        func_8006D3B8(gPlayer[playernum].unk4A, D_80197DEC->unk99, 0, 0, 0);
        func_8006D3B8(gPlayer[playernum].unk4A, D_80197DEC->unk99, 0, 0, 0);

        if (D_80197DEC->unk99 == 5)
        {
            func_8006D3B8(gPlayer[playernum].unk4A, 5, 0, 0, 0);
            func_8006D3B8(gPlayer[playernum].unk4A, D_80197DEC->unk99, 0, 0, 0);
            func_8006D3B8(gPlayer[playernum].unk4A, D_80197DEC->unk99, 0, 0, 0);
            func_8006D3B8(gPlayer[playernum].unk4A, D_80197DEC->unk99, 0, 0, 0);
            func_8006D3B8(gPlayer[playernum].unk4A, D_80197DEC->unk99, 0, 0, 0);
        }
    }
    else
    {
        j = D_80197DEC->unk99;
        if ((j == 3) && (D_801B0810[0] & 4))
            j = 22;

        if ((j == 18) && (D_801B0810[0] & 4))
            j = 19;

        d = D_800DF850[D_80197DEC->unk99][0];
        e = D_800DF850[D_80197DEC->unk99][1];
        f = D_800DF850[D_80197DEC->unk99][2];

        if (j == 14)
        {
            if (func_8006D3B8(gPlayer[playernum].unk4A, j, d, e, f) == -1)
                return;
        }
        else if (j == 0)
        {
            if (gPlayer[playernum].unk54 == 0)
            {
                if ((k == 14) || (k == 26) || (k == 37) || (k == 50))
                    func_8006D3B8(gPlayer[playernum].unk4A, j, d, e, f);
                else
                    D_80199970[playernum] = 0;
            }
            else
                return;
        }
        else
            func_8006D3B8(gPlayer[playernum].unk4A, j, d, e, f);
    }

    if (D_80197DEC->unk99 != 0)
    {
        func_8007AC6C(D_80197DEC->unk99, unk4A, 0);
        if (D_80197DEC->unk99 != 0)
        {
            if (D_801B0810[0] & 4)
            {
                D_801B0810[7]--;
                if (D_801B0810[7] == 0)
                    D_801B0810[0] &= ~4;

                if (D_80197DEC->unk99 == 4)
                    D_801B0810[1]--;
            }
            else
            {
                if (D_80197DEC->unk99 == 5)
                    D_801B0810[1] -= 2;
                else
                    D_801B0810[1]--;
            }

            if ((D_80197DEC->unk99 != 0) && (D_801B0810[1] == 0))
            {
                if (D_80197DEC->unk70 != 0)
                {
                    MusHandleStop(D_80197DEC->unk70, 0);
                    D_80197DEC->unk70 = 0;
                }
            }
        }
    }

    if (D_801B0810[5] > 0)
    {
        n = D_801B0810[1];
        if (D_801B0810[0] & 4)
        {
            if (D_80197DEC->unk99 != 4)
                n = D_801B0810[7];
        }

        if (n > 0)
        {
            m = D_801B0810[5];
            D_801B0810[4]++;

            if (D_801B0810[0] & 2)
                m *= 2;

            if (D_801B0810[4] == m)
            {
                if (D_801B0810[0] & 2)
                {
                    if (D_80197DEC->unk99 == 2)
                        D_801B0810[3] = 40;
                    else
                        D_801B0810[3] = 30;
                }
                else
                    D_801B0810[3] = D_801B0810[2];

                D_801B0810[4] = 0;
                D_8016A154[playernum] = 1;
            }
        }
        else
            D_801B0810[4] = 0;
    }

block_132:
    if ((c != -1) && (c & 0x8000))
    {
        if (a == D_801B0810[8])
            func_8007AC6C(D_80197DEC->unk99, unk4A, 1);

        if (b == D_801B0810[8])
            func_8007AC6C(D_80197DEC->unk99, unk4A, 1);
    }
    else
    {
        if (a == k)
            func_8007AC6C(D_80197DEC->unk99, unk4A, 1);

        if (b == k)
        {
            func_8007AC6C(D_80197DEC->unk99, unk4A, 1);
            D_8016A154[playernum] = 1;
        }
    }
}

/*8007AC6C*/
static void func_8007AC6C(s32 arg0, s32 arg1, s32 arg2)
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
void func_8007AD30(void)
{
    s32 i, j;
    s32 temp;

    for (i = 0; i < ARRAY_COUNT(D_8011A680); i++)
    {
        for (j = 0; j < ARRAY_COUNT(D_8011A680[0]) - 1; j++)
        {
            D_8011A680[i][j][5] = *get_D_800DF8E0(j, 0);
            D_8011A680[i][j][2] = *get_D_800DF8E0(j, 1);
            temp = i; i = temp; /*FAKEMATCH*/
            D_8011A680[i][j][3] = 0;
            D_8011A680[i][j][4] = 0;
        }
    }
}

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
