#include "common.h"
#include "code0/main.h"
#include "code0/4600.h"
#include "code0/viewport.h"
#include "code0/41940.h"
#include "code0/6ACA0.h"
#include "code0/6D9E0.h"
#include "code0/8E670.h"
#include "code0/95500.h"
#include "code0/code0.h"
#include "code1/code1.h"
#include "static/mapinfo.h"

#define MAP_CHEAT_AWARD_NONE 0
#define MAP_CHEAT_AWARD_ON_ALL_ENEMIES (1<<10)
#define MAP_CHEAT_AWARD_ON_ALL_SECRETS (1<<11)
#define MAP_CHEAT_AWARD_ON_ALL_BABES (1<<12)
#define MAP_CHEAT_AWARD_WEAPON (1<<13)

/*.data*/
/*800E16A0*/ u8 D_800E16A0[MAXPLAYERS] = {0};

/*800E16A4*/
static s16 D_800E16A4[12] = {-1, 5, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

/*800E16BC*/ s32 gUnlockedCheat = 0;
/*800E16C0*/ s32 gUnlockedSkin = SKIN_DUKENUKEM|SKIN_APOCALYPSEDUKE|SKIN_COWBOYDUKE|SKIN_VICTORIANDUKE;

/*800E16C4*/
static s32 _mapSkinAward[MAP_THE_END] = {
    /*MEAN_STREETS*/ SKIN_PIGCOP|SKIN_ENFORCER,
    /*LIBERTY_OR_DEATH*/ SKIN_RIOTPIG,
    /*NUCLEAR_WINTER*/ SKIN_ROADHOG,
    /*WETWORLD*/ SKIN_ENFORCERCAPTAIN,
    /*FALLOUT*/ SKIN_WARPIG,
    /*UNDER_SIEGE*/ SKIN_DOGTAGDUKE,
    /*BOSS_HOG*/ SKIN_SURVIVOR,
    /*DRY_TOWN*/ SKIN_SAVAGEGRUNT,
    /*JAIL_BREAK*/ SKIN_MARSHALL,
    /*UP_SHIP_CREEK*/ SKIN_BATTLEENFORCER,
    /*FORT_ROSWELL*/ SKIN_CUSTER,
    /*PROBING_THE_DEPTHS*/ SKIN_COWBOYGRUNT,
    /*CYBORG_SCORPION*/ SKIN_SHERIFF|SKIN_SQUAW,
    /*THE_WHITECHAPEL_KILLINGS*/ SKIN_RIPPER,
    /*DAWN_OF_THE_DUKE*/ SKIN_SOLDIERGRUNT,
    /*HYDROGEN_BOMB*/ SKIN_CAPITALISTPIG,
    /*THE_RACK*/ SKIN_MARINE,
    /*GOING_DOWN_THE_RACK*/ SKIN_POSHDUKE,
    /*BRAINSTORM*/ SKIN_SERGEANT,
    /*THE_BROTHERS_NUKEM*/ SKIN_EVILDUKE,
    /*ALIEN_MOTHER*/ SKIN_BATTLEDRESSDUKE,
    /*ZERO_HOUR*/ SKIN_ALL,
};

/*800E171C*/
static u16 _mapCheatAward[MAP_THE_END] = {
    /*MEAN_STREETS*/ MAP_CHEAT_AWARD_NONE,
    /*LIBERTY_OR_DEATH*/ MAP_CHEAT_AWARD_ON_ALL_BABES|CHEAT_BIG_HEAD_MODE,
    /*NUCLEAR_WINTER*/ MAP_CHEAT_AWARD_ON_ALL_ENEMIES|CHEAT_BIG_GUN,
    /*WETWORLD*/ MAP_CHEAT_AWARD_ON_ALL_SECRETS|CHEAT_FLAT_SHADING,
    /*FALLOUT*/ MAP_CHEAT_AWARD_ON_ALL_BABES|CHEAT_ICE_SKINS,
    /*UNDER_SIEGE*/ MAP_CHEAT_AWARD_ON_ALL_SECRETS|CHEAT_WEATHER,
    /*BOSS_HOG*/ MAP_CHEAT_AWARD_NONE,
    /*DRY_TOWN*/ MAP_CHEAT_AWARD_ON_ALL_BABES|CHEAT_FAST_ZOMBIES,
    /*JAIL_BREAK*/ MAP_CHEAT_AWARD_ON_ALL_ENEMIES|MAP_CHEAT_AWARD_WEAPON|CHEAT_WEAPON_BLASTER,
    /*UP_SHIP_CREEK*/ MAP_CHEAT_AWARD_ON_ALL_SECRETS|MAP_CHEAT_AWARD_WEAPON|CHEAT_WEAPON_CLAW12,
    /*FORT_ROSWELL*/ MAP_CHEAT_AWARD_ON_ALL_BABES|MAP_CHEAT_AWARD_WEAPON|CHEAT_WEAPON_3030,
    /*PROBING_THE_DEPTHS*/ MAP_CHEAT_AWARD_ON_ALL_SECRETS|MAP_CHEAT_AWARD_WEAPON|CHEAT_WEAPON_REVOLVER,
    /*CYBORG_SCORPION*/ MAP_CHEAT_AWARD_NONE,
    /*THE_WHITECHAPEL_KILLINGS*/ MAP_CHEAT_AWARD_ON_ALL_ENEMIES|MAP_CHEAT_AWARD_WEAPON|CHEAT_WEAPON_SAWEDOFF,
    /*DAWN_OF_THE_DUKE*/ MAP_CHEAT_AWARD_ON_ALL_SECRETS|MAP_CHEAT_AWARD_WEAPON|CHEAT_WEAPON_SMG,
    /*HYDROGEN_BOMB*/ MAP_CHEAT_AWARD_ON_ALL_ENEMIES|MAP_CHEAT_AWARD_WEAPON|CHEAT_WEAPON_GATTLINGGUN,
    /*THE_RACK*/ MAP_CHEAT_AWARD_ON_ALL_SECRETS|MAP_CHEAT_AWARD_WEAPON|CHEAT_WEAPON_VOLTCANNON,
    /*GOING_DOWN_THE_RACK*/ MAP_CHEAT_AWARD_ON_ALL_BABES|MAP_CHEAT_AWARD_WEAPON|CHEAT_WEAPON_SNIPER,
    /*BRAINSTORM*/ MAP_CHEAT_AWARD_NONE,
    /*THE_BROTHERS_NUKEM*/ MAP_CHEAT_AWARD_ON_ALL_ENEMIES|MAP_CHEAT_AWARD_WEAPON|CHEAT_WEAPON_FREEZER,
    /*ALIEN_MOTHER*/ MAP_CHEAT_AWARD_ON_ALL_BABES|MAP_CHEAT_AWARD_WEAPON|CHEAT_WEAPON_GAMMACANNON,
    /*ZERO_HOUR*/ MAP_CHEAT_AWARD_NONE,
};

/*800E1748*/ s32 D_800E1748 = -1;

/*.comm*/
/*8019963C*/ s16 D_8019963C;

/*.text*/

/*8008DA70*/
bool awardMapCheat(s16 mapnum)
{
    bool ret;

    ret = FALSE;
    if (mapnum >= MAP_THE_END)
        return FALSE;

    gUnlockedSkin |= _mapSkinAward[mapnum];
    if (gConfig.difficulty == 0)
        return FALSE;

    if (_mapCheatAward[mapnum] != MAP_CHEAT_AWARD_NONE)
    {
        if (_mapCheatAward[mapnum] & MAP_CHEAT_AWARD_ON_ALL_ENEMIES)
        {
            if (D_801A1958.enemies_killed >= D_801A1958.enemies_total)
                ret = TRUE;
        }
        if (_mapCheatAward[mapnum] & MAP_CHEAT_AWARD_ON_ALL_SECRETS)
        {
            if (D_801A1958.secrets_found >= D_801A1958.secrets_total)
                ret = TRUE;
        }
        if (_mapCheatAward[mapnum] & MAP_CHEAT_AWARD_ON_ALL_BABES)
        {
            if (D_801A1958.babes_saved >= D_801A1958.babes_total)
                ret = TRUE;
        }
        if (ret)
        {
            gConfig.unk50 = 1;
            if (_mapCheatAward[mapnum] & MAP_CHEAT_AWARD_WEAPON)
                gUnlockedCheatWeapons |= (1 << _mapCheatAward[mapnum]);
            else
                gUnlockedCheat |= (1 << _mapCheatAward[mapnum]);
        }
    }

    if (mapnum == MAP_ZERO_HOUR)
    {
        gConfig.unk50 = 1;
        gUnlockedCheat |= ((1<<CHEAT_ACTION_NUKEM)|(1<<CHEAT_FIRST_PERSON));
        ret = TRUE;
    }
    return ret;
}

/*8008DC24*/
void func_8008DC24(void)
{
    s16 i;

    if (gPlayerCount == 1)
    {
        gMultiplayerTimeLimit = -1;
        D_801AD470 = 0;
        D_8019963C = -1;
        return;
    }

    for (i = 0; i < gPlayerCount; i++)
        gPlayer[i].third_person = FALSE;

    Bmemset(D_800FF4F0, 0, sizeof(D_800FF4F0));
    gMultiplayerElapsedTime = 0;
    g2pSplitHorz = FALSE;
    g3pSplitFull = 0;
    gMultiplayerTimeLimit = D_800E16A4[gConfig.multiplayer.time_limit] * 1800;
    D_8019963C = D_800E16A4[gConfig.multiplayer.frag_count];

    if (gPlayerCount == 2)
        g2pSplitHorz = gConfig.multiplayer.split_2P == CONFIG_2P_SPLIT_HORZ;

    if (gPlayerCount == 3)
        g3pSplitFull = gConfig.multiplayer.split_3P;

    switch (D_801CDC64.unk2)
    {
    default:
    case 0:
        D_801AD470 = 1;
        break;
    case 3:
        D_801AD470 = 2;
        gMultiplayerTimeLimit = -1;
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
        for (i = 0; i < gPlayerCount; i++)
        {
            if (D_80106D30[i] != 0)
                j++;
        }

        if (j == 0)
            D_8010554C = 0;

        if ((gMultiplayerTimeLimit > 0) && (D_8010554C == 0))
        {
            gMultiplayerElapsedTime++;
            if (gMultiplayerElapsedTime >= gMultiplayerTimeLimit)
                func_8008E01C(60, 1);
        }
        if (D_8019963C > 0)
        {
            for (i = 0; i < gPlayerCount; i++)
            {
                if ((D_800FF4F0[i].unk0 - D_800FF4F0[i].unk2) >= D_8019963C)
                    func_8008E01C(60, 1);
            }
        }
        if (D_801AD470 == 2)
        {
            k = 0;
            for (i = 0; i<gPlayerCount; i++)
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
    Actor *actor;

    actor = &gActor[gActorSpriteMap[gPlayer[playernum].unk4A]];
    func_8006D0E4(playernum);
    D_8011A680[playernum][0][0] |= 1;
    func_80095390(playernum);
    actor->unk99 = D_8012F6E4[gPlayer[playernum].skin].unk8;
    gPlayer[playernum].unk70 = actor->unk99;
    D_8011A680[playernum][actor->unk99][0] |= 1;
    D_8011A680[playernum][actor->unk99][1] = D_800DF1D0[actor->unk99][1] * 2;

    switch (D_8012F6E4[gPlayer[playernum].skin].picnum)
    {
    case ENFORCER:
    case ENFORCERCAPTAIN:
    case BATTLEENFORCER:
    case CUSTER:
        D_8011A680[playernum][actor->unk99][0] |= 2;
        break;

    case MARINE:
    case SERGEANT:
        D_8010A940[playernum].unkA[0] = D_800E17E0[0];
        D_8010A940[playernum].unk0 = 0;
        break;

    case RIOTPIG:
        D_8010A940[playernum].unkA[6] = D_800E17E0[6];
        D_8010A940[playernum].unk0 = 6;
        break;
    }

    actor->unk7E = D_8010A940[playernum].unkA[0];
    gPlayer[playernum].unk46 = D_8012F6E4[gPlayer[playernum].skin].unk9;
    gPlayer[playernum].unk48 = gPlayer[playernum].unk46;
    actor->unk8 = gPlayer[playernum].unk46;

    if (D_8012F6E4[gPlayer[playernum].skin].unkB == 5)
        gPlayer[playernum].unk48 = 0;
}
