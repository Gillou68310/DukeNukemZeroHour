#include "common.h"
#include "code0/main.h"
#include "code0/audio.h"
#include "code0/engine.h"
#include "code0/4600.h"
#include "code0/9410.h"
#include "code0/3FAD0.h"
#include "code0/41940.h"
#include "code0/6ACA0.h"
#include "code0/8E670.h"
#include "code0/8EFE0.h"
#include "code0/95500.h"
#include "code0/code0.h"
#include "code1/code1.h"
#include "code1/EB300.h"
#include "static/mapinfo.h"

typedef struct {
    /*0x00*/ s32 unk0; /*x*/
    /*0x04*/ s32 unk4; /*y*/
    /*0x08*/ s32 unk8; /*z*/
    /*0x0C*/ s16 unkC;
    /*0x0E*/ s16 unkE;
} _609D0UnkStruct1;

/*.comm*/
/*80107908*/ s16 D_80107908;
/*8012F708*/_609D0UnkStruct1 D_8012F708[32] ALIGNED(8);

/*.text*/

/*8005FDD0*/
static void func_8005FDD0(SectorType *sec, s16 arg1)
{
    s16 i;

    for (i = sec->wallptr; i < (sec->wallptr + sec->wallnum); i++)
    {
        if (gpWall[i].nextwall != -1)
        {
            gpWall[gpWall[i].nextwall].unk14 = 66;
            gpWall[gpWall[i].nextwall].unk16 = arg1;
        }
    }
}

/*8005FE84*/
static void func_8005FE84(s16 wallnum)
{
    gpWall[wallnum].cstat |= 0x1000;
    if (gpWall[wallnum].nextwall != -1)
        gpWall[gpWall[wallnum].nextwall].cstat |= 0x1000;
}

/*8005FEE0*/
INCLUDE_ASM("nonmatchings/src/code0/609D0", func_8005FEE0);

/*80062300*/
INCLUDE_ASM("nonmatchings/src/code0/609D0", func_80062300);

/*80062688*/
static s16 func_80062688(s16 arg0)
{
    s16 ret;
    s32 d1, d2, d3;

    s16 i, j;

    d3 = -1;
    ret = 0;
    for (i = 0; i < D_80107908; i++)
    {
        d2 = 0x400000;
        for (j = 0; j < D_8012C470; j++)
        {
            if (j != arg0)
            {
                if (gPlayer[j].unk45 == 0)
                {
                    d1 = findDistance2D(D_8012F708[i].unk0 - gPlayer[j].xpos,
                                        D_8012F708[i].unk4 - gPlayer[j].ypos);

                    d2 = MIN(d2, d1);
                }
            }
        }
        if (d3 < d2)
        {
            d3 = d2;
            ret = i;
        }
    }
    return ret;
}

/*800627F8*/
static s32 func_800627F8(void)
{
    s32 num;
    code1UnkStruct3 *ptr;
    code1UnkStruct2 *ptr2;

    num = 1;
    ptr = &D_801CE5F0;
    if ((gMapNum < MAP_THE_END))
    {
        if ((gMapNum != MAP_MEAN_STREETS))
        {
            if (gMapNum == MAP_FALLOUT)
                num += (ptr->unkFD6 < 1);

            if (gMapNum == MAP_BRAINSTORM)
                num += (ptr->unkFD7 == 0);

            ptr2 = &ptr->unk4[gMapNum - num];
            return ptr2->unk0 == 0;
        }
    }
    return 1;
}

/*80062888*/
static void func_80062888(void)
{
    s16 i;

    for (i = 0; i < ARRAY_COUNT(D_801AE91E); i++)
        D_801AE91E[i] = 70;

    D_801AE91E[1] = 67;

    if (gMapNum == MAP_NUCLEAR_WINTER)
    {
        D_801AE91E[2] = 83;
        D_801AE91E[3] = 83;
        D_801AE91E[4] = 83;
        D_801AE91E[5] = 83;
    }
    if (gMapNum == MAP_BASE)
    {
        for (i = 1; i < ARRAY_COUNT(D_801AE91E); i++)
            D_801AE91E[i] = 83;
    }
}

/*80062950*/
void func_80062950(s16 playernum, u8 arg1)
{
    s16 i;
    s16 spritenum;

    gPlayer[playernum].unk45 = 1;
    gPlayer[playernum].unk40 = 0x3900;

    if (D_800FE3FC == 0)
        gTimeMachinePart &= ~(1 << gMapNum);

    if (D_80107908 > 0)
    {
        if (D_8012C470 == 1)
            i = 0;
        else if ((playernum == 0) && (arg1))
            i = krand() % D_80107908;
        else
            i = func_80062688(playernum);

        gPlayer[playernum].xpos = D_8012F708[i].unk0;
        gPlayer[playernum].ypos = D_8012F708[i].unk4;
        gPlayer[playernum].zpos = D_8012F708[i].unk8 - gPlayer[playernum].unk40;
        gPlayer[playernum].unk38 = D_8012F708[i].unkC;
        gPlayer[playernum].unk32 = D_8012F708[i].unkE;
    }

    D_80138610[playernum] = 0;
    D_801AE480[playernum] = 0;
    D_8012F914[playernum] = -1;
    D_8011814A[playernum] = 600;
    func_80062888();

    if (arg1)
    {
        spritenum = insertSprite(gPlayer[playernum].unk32, 10);
        gPlayer[playernum].unk4A = spritenum;
        gpSprite[spritenum].unk16 = playernum;
        D_80106D50[spritenum] = func_8004BE90();
    }
    else
    {
        spritenum = gPlayer[playernum].unk4A;
        changeSpriteSect(gPlayer[playernum].unk4A, gPlayer[playernum].unk32);
    }

    if (D_8012C470 >= 2)
    {
        if (arg1)
            gpSprite[spritenum].picnum = playernum + 1532;
    }
    else
    {
        switch (D_801CA14C[gMapNum].unk0)
        {
        default:
        case 0:
        case 1:
        case 4:
            if (gMapNum >= MAP_NUCLEAR_WINTER && gMapNum < MAP_DRY_TOWN)
                gpSprite[spritenum].picnum = 1534;
            else
                gpSprite[spritenum].picnum = 1535;
            break;
        case 2:
            gpSprite[spritenum].picnum = 1533;
            break;
        case 3:
            gpSprite[spritenum].picnum = 1532;
            break;
        }
    }

    gpSprite[spritenum].cstat = 0x1101;
    gpSprite[spritenum].xrepeat = 64;
    gpSprite[spritenum].yrepeat = 64;
    gpSprite[spritenum].unk24 = gpSector[gPlayer[playernum].unk32].unk26;
    setSprite(spritenum, gPlayer[playernum].xpos, gPlayer[playernum].ypos, gPlayer[playernum].zpos + gPlayer[playernum].unk40);
    gpSprite[spritenum].ang = gPlayer[playernum].unk38;
    gpSprite[spritenum].unk25 = 0;

    if ((!(D_8012C470 < 2)) && !(arg1))
    {
        func_8008E3E0(gPlayer[playernum].xpos,
                      gPlayer[playernum].ypos,
                      gPlayer[playernum].zpos + gPlayer[playernum].unk40,
                      gPlayer[playernum].unk32, 43, 0);

        audio_800077F4(704, spritenum);
        D_800DEEE4[playernum] = 1;
    }

    D_8013B2D0[spritenum].unk2 = 0;
    D_8013B2D0[spritenum].unk0 = 0;
    D_8013B2D0[spritenum].unk4 = 0;
    D_8013B2D0[spritenum].unk6 = 0;
    D_8019B940[D_80106D50[spritenum]].unk68 = 0;
    D_8019B940[D_80106D50[spritenum]].unk0 = 1;
    func_8006D0E4(playernum);

    if ((D_8012C470 == 1) && (gMapNum < MAP_THE_END))
        func_801C936C();

    if ((func_800627F8() != 0) || (D_801A1994 == 1) || (D_8012C470 >= 2) ||
        (gMapNum == MAP_BASE) || (gMapNum == MAP_MEAN_STREETS) || (gMapNum == MAP_NUCLEAR_WINTER) ||
        (gMapNum == MAP_DRY_TOWN) || (gMapNum == MAP_JAIL_BREAK) ||
        (gMapNum == MAP_THE_WHITECHAPEL_KILLINGS) || (gMapNum == MAP_THE_BROTHERS_NUKEM))
    {
        func_8006D0E4(playernum);

        D_8011A680[playernum][0][0] |= 1;
        if (D_801CA14C[gMapNum].unk0 == 2)
        {
            if (gMapNum == MAP_JAIL_BREAK)
                gPlayer[playernum].unk70 = 0;
            else
            {
                D_8011A680[playernum][3][1] = 12;
                D_8011A680[playernum][3][0] |= 1;
                gPlayer[playernum].unk70 = 3;
            }
        }
        else
        {
            D_8011A680[playernum][2][1] = 42;
            D_8011A680[playernum][2][0] |= 1;
            gPlayer[playernum].unk70 = 2;
        }

        func_80095390(playernum);

        if (gMapNum == MAP_MEAN_STREETS)
        {
            D_8011A680[playernum][2][1] = 84;
            D_8011A680[playernum][23][1] = 10;
            D_8011A680[playernum][23][0] |= 1;
            D_8010A940[playernum].unkA[5] = D_800E17E0[5];
            D_8010A940[playernum].unkA[6] = D_800E17E0[6];
        }
        gPlayer[playernum].unk46 = 100;

        if (D_8012C470 >= 2)
            func_8008E04C(playernum);
    }

    if (D_8010A940[playernum].unkA[2] < D_800E17E0[2])
        D_8010A940[playernum].unkA[2] = 0;

    if (D_8012C470 == 1)
        gPlayer[playernum].unk48 = 100;

    D_8019B940[D_80106D50[spritenum]].unk99 = gPlayer[playernum].unk70;
    D_8019B940[D_80106D50[spritenum]].unk8 = gPlayer[playernum].unk46;
    D_8019B940[D_80106D50[spritenum]].unk7E = D_8010A940[playernum].unkA[0];

    if (arg1)
    {
        spritenum = insertSprite(gPlayer[playernum].unk32, 0);
        D_8012FCA0[playernum] = spritenum;
    }
    else
        spritenum = D_8012FCA0[playernum];

    setSprite(spritenum,
              gPlayer[playernum].xpos,
              gPlayer[playernum].ypos,
              getFlorzOfSlope(gPlayer[playernum].unk32, gPlayer[playernum].xpos, gPlayer[playernum].ypos));

    gpSprite[spritenum].picnum = 5615;
    gpSprite[spritenum].unk16 = playernum;
    gpSprite[spritenum].cstat = 0x4820;
    gpSprite[spritenum].xrepeat = 64;
    gpSprite[spritenum].yrepeat = 64;
    gpSprite[spritenum].unk25 = 7;
    D_8013B2D0[spritenum].unk6 = 0;

    if ((D_8012C470 >= 2) || (D_801CDBC6 != 0))
    {
        gPlayer[playernum].unk61 = 0;
        gPlayer[playernum].unk60 = 0;
    }
    else
    {
        gPlayer[playernum].unk61 = 1;
        gPlayer[playernum].unk60 = 1;
    }

    gPlayer[playernum].unk44 = 0;
    gPlayer[playernum].unk45 = 0;
    gPlayer[playernum].unk54 = 0;

    if (func_8004EFB4(gPlayer[playernum].unk4A) != 0)
        gPlayer[playernum].unk54 = 1;

    gPlayer[playernum].unk50 = -1;
    gPlayer[playernum].unk56 = 0;
    gPlayer[playernum].unk55 = 0;
    gPlayer[playernum].unk5B = 0;
    gPlayer[playernum].unk58 = 0;
    gPlayer[playernum].unk82 = 0;
    gPlayer[playernum].unk84 = 0;
    gPlayer[playernum].unk86 = 0;
    gPlayer[playernum].unk5A = 0;
    gPlayer[playernum].unk88[0] = 1;
    gPlayer[playernum].unk57 = gPlayer[playernum].unk54;

    for (i = 1; i < ARRAY_COUNT(gPlayer[playernum].unk88); i++)
        gPlayer[playernum].unk88[i] = 0;

    gPlayer[playernum].unk52 = -1;
    gPlayer[playernum].unk6E = 0x100;
    gPlayer[playernum].unk6A = 0x100;
    gPlayer[playernum].unk6C = 0;
    gPlayer[playernum].unk3C = 0;
    gPlayer[playernum].unk3E = 0;
    gPlayer[playernum].unkC = 0;
    gPlayer[playernum].unk10 = 0;
    gPlayer[playernum].unk14 = 0;
    D_800DEF1C = -1;
    func_8000EB90(playernum & 0xFF, 0, 0, 0, 0);
    D_80106D30[playernum] = 0;

    if ((D_8012C470 >= 2) || (D_801CC8CC != 0))
    {
        if (arg1 != 0)
        {
            if (D_8010554C != 0)
            {
                gpSprite[gPlayer[playernum].unk4A].cstat |= 0x8000;
                gpSprite[gPlayer[playernum].unk4A].cstat &= 0xFEFE;
                D_80106D30[playernum] = 1;
                gPlayer[playernum].unk4C = playernum;
            }
        }

        gpSprite[gPlayer[playernum].unk4A].picnum = D_8012F6E4[gPlayer[playernum].unk4C].unk0;
        D_80138858[playernum] = 0;
    }
    else
        gPlayer[playernum].unk4C = 0;

    gPlayer[playernum].unk4E = 0;
    gPlayer[playernum].unk68 = gPlayer[playernum].unk32;
    gPlayer[playernum].unk64 = 1524.0f;
    Bmemset(&D_801A2790[playernum], 0, 40);
    D_801A2790[playernum].unk16 = gPlayer[playernum].unk38;
    D_801A2790[playernum].unk24 = 1524;
    D_801B0820 = playernum;
    func_8003F340();
    func_8003FD5C();
}

/*hack for wrong rodata aligment*/
static const f64 _force_rodata_alignment = 0;
