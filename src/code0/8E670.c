#include "common.h"
#include "code0/main.h"
#include "code0/4600.h"
#include "code0/20490.h"
#include "code0/41940.h"
#include "code0/6ACA0.h"
#include "code0/8E670.h"
#include "code0/95500.h"
#include "code0/code0.h"
#include "code1/code1.h"
#include "static/mapinfo.h"

/*.data*/
/*800E16A0*/ u8 D_800E16A0[MAXPLAYERS] = {0};

/*800E16A4*/
static s16 D_800E16A4[12] = {-1, 5, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

/*800E16BC*/ s32 D_800E16BC = 0;
/*800E16C0*/ s32 D_800E16C0 = 15;

/*800E16C4*/
static s32 D_800E16C4[MAP_THE_END] = {
    0x04040000,
    0x00080000,
    0x00100000,
    0x08000000,
    0x00200000,
    0x00000040,
    0x00010000,
    0x00800000,
    0x00002000,
    0x10000000,
    0x00000400,
    0x00400000,
    0x0000C000,
    0x00000800,
    0x01000000,
    0x02000000,
    0x00000100,
    0x00000010,
    0x00000200,
    0x00000080,
    0x00000020,
    0xFFFFFFFF,
};

/*800E171C*/
static u16 D_800E171C[MAP_THE_END] = {
    0,
    4097,
    1028,
    2050,
    4101,
    2051,
    0,
    4104,
    9217,
    10245,
    12294,
    10244,
    0,
    9223,
    10240,
    9225,
    10248,
    12290,
    0,
    9219,
    12298,
    0,
};

/*800E1748*/ s32 D_800E1748 = -1;

/*.comm*/
/*8019963C*/ s16 D_8019963C;

/*.text*/

/*8008DA70*/
u8 func_8008DA70(s16 mapnum)
{
    u8 ret;

    ret = 0;
    if (mapnum >= MAP_THE_END)
        return 0;

    D_800E16C0 |= D_800E16C4[mapnum];
    if (gConfig.difficulty == 0)
        return 0;

    if (D_800E171C[mapnum] != 0)
    {
        if (D_800E171C[mapnum] & 0x400)
        {
            if (D_801A1958.enemies_killed >= D_801A1958.enemies_total)
                ret = 1;
        }
        if (D_800E171C[mapnum] & 0x800)
        {
            if (D_801A1958.secrets_found >= D_801A1958.secrets_total)
                ret = 1;
        }
        if (D_800E171C[mapnum] & 0x1000)
        {
            if (D_801A1958.babes_saved >= D_801A1958.babes_total)
                ret = 1;
        }
        if (ret != 0)
        {
            gConfig.unk50 = 1;
            if (D_800E171C[mapnum] & 0x2000)
                D_801CE470 |= (1 << D_800E171C[mapnum]);
            else
                D_800E16BC |= (1 << D_800E171C[mapnum]);
        }
    }

    if (mapnum == MAP_ZERO_HOUR)
    {
        gConfig.unk50 = 1;
        D_800E16BC |= 0x41;
        ret = 1;
    }
    return ret;
}

/*8008DC24*/
void func_8008DC24(void)
{
    s16 i;

    if (D_8012C470 == 1)
    {
        D_80199558 = -1;
        D_801AD470 = 0;
        D_8019963C = -1;
        return;
    }

    for (i = 0; i < D_8012C470; i++)
        gPlayer[i].unk60 = 0;

    Bmemset(D_800FF4F0, 0, sizeof(D_800FF4F0));
    D_80119A64 = 0;
    D_800DCBD4 = 0;
    D_800DCBD5 = 0;
    D_80199558 = D_800E16A4[gConfig.multiplayer.time_limit] * 1800;
    D_8019963C = D_800E16A4[gConfig.multiplayer.frag_count];

    if (D_8012C470 == 2)
        D_800DCBD4 = gConfig.multiplayer.split_2P == CONFIG_2P_SPLIT_HORZ;

    if (D_8012C470 == 3)
        D_800DCBD5 = gConfig.multiplayer.split_3P;

    switch (D_801CDC64.unk2)
    {
    default:
    case 0:
        D_801AD470 = 1;
        break;
    case 3:
        D_801AD470 = 2;
        D_80199558 = -1;
        D_8019963C = -1;
        break;
    case 4:
        D_801AD470 = 3;
        D_800FE9D0 = -1;
        break;
    case 5:
        D_801AD470 = 4;
        break;
    }
}

/*8008DE14*/
void func_8008DE14(void)
{
    s16 i, j, k;

    D_800BD3E8 = 1;
    if (D_800E1748 <= 0)
    {
        j = 0;
        for (i = 0; i < D_8012C470; i++)
        {
            if (D_80106D30[i] != 0)
                j++;
        }

        if (j == 0)
            D_8010554C = 0;

        if ((D_80199558 > 0) && (D_8010554C == 0))
        {
            D_80119A64++;
            if (D_80119A64 >= D_80199558)
                func_8008E01C(60, 1);
        }
        if (D_8019963C > 0)
        {
            for (i = 0; i < D_8012C470; i++)
            {
                if ((D_800FF4F0[i].unk0 - D_800FF4F0[i].unk2) >= D_8019963C)
                    func_8008E01C(60, 1);
            }
        }
        if (D_801AD470 == 2)
        {
            k = 0;
            for (i = 0; i<D_8012C470; i++)
            {
                if (gPlayer[i].unk45 == 0)
                    k++;
            }
            if (k < 2)
                func_8008E01C(60, 1);
        }
    }
}

/*8008E01C*/
void func_8008E01C(s16 arg0, s32 arg1)
{
    if (D_800E1748 == -1)
    {
        D_800E1748 = arg0;
        D_80118148 = arg1;
    }
}

/*8008E04C*/
void func_8008E04C(s16 playernum)
{
    code0UnkStruct3 *ptr;

    ptr = &D_8019B940[D_80106D50[gPlayer[playernum].unk4A]];
    func_8006D0E4(playernum);
    D_8011A680[playernum][0][0] |= 1;
    func_80095390(playernum);
    ptr->unk99 = D_8012F6E4[gPlayer[playernum].unk4C].unk8;
    gPlayer[playernum].unk70 = ptr->unk99;
    D_8011A680[playernum][ptr->unk99][0] |= 1;
    D_8011A680[playernum][ptr->unk99][1] = D_800DF1D0[ptr->unk99][1] * 2;

    switch (D_8012F6E4[gPlayer[playernum].unk4C].unk0)
    {
    case 1282:
    case 1283:
    case 1284:
    case 2309:
        D_8011A680[playernum][ptr->unk99][0] |= 2;
        break;

    case 2002:
    case 2005:
        D_8010A940[playernum].unkA[0] = D_800E17E0[0];
        D_8010A940[playernum].unk0 = 0;
        break;

    case 1289:
        D_8010A940[playernum].unkA[6] = D_800E17E0[6];
        D_8010A940[playernum].unk0 = 6;
        break;
    }

    ptr->unk7E = D_8010A940[playernum].unkA[0];
    gPlayer[playernum].unk46 = D_8012F6E4[gPlayer[playernum].unk4C].unk9;
    gPlayer[playernum].unk48 = gPlayer[playernum].unk46;
    ptr->unk8 = gPlayer[playernum].unk46;

    if (D_8012F6E4[gPlayer[playernum].unk4C].unkB == 5)
        gPlayer[playernum].unk48 = 0;
}
