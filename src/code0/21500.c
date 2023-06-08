#include "common.h"
#include "code0/9410.h"
#include "code0/main.h"
#include "code0/pragmas.h"

/*.comm*/
/*800FE3F8*/ f32 D_800FE3F8;
/*80105710*/ f32 D_80105710;
/*80106D34*/ f32 D_80106D34;
/*80118154*/ f32 D_80118154;
/*8011824C*/ f32 D_8011824C;
/*80118254*/ f32 D_80118254;
/*80119A60*/ f32 D_80119A60;
/*8012FD90*/ f32 D_8012FD90;
/*80138770*/ f32 D_80138770;
/*80138774*/ f32 D_80138774;
/*8013877C*/ f32 D_8013877C;
/*80138814*/ f32 D_80138814;
/*80168CA0*/ f32 D_80168CA0;
/*80168D00*/ f32 D_80168D00;
/*80168D14*/ u16 D_80168D14; /*tilenum*/
/*80199104*/ f32 D_80199104;
/*80199568*/ f32 D_80199568;
/*801ACBE4*/ f32 D_801ACBE4;

/*.text*/
STATIC s32 func_80021464(s32 sectnum, s32 wallnum);
STATIC s32 func_80022C30(s32 sectnum, s32 wallnum);

/*80020900*/
static void func_80020900(u16 tileid)
{
    f32 sizex, dimx, sizey, dimy;
    u16 tilenum;

    tilenum = getTileNum(tileid);
    sizex = gpTileInfo[tilenum].sizex;
    dimx = gpTileInfo[tilenum].dimx;
    sizey = gpTileInfo[tilenum].sizey;
    dimy = gpTileInfo[tilenum].dimy;
    D_80168D14 = tilenum;
    D_80105710 = sizex;
    D_80118254 = dimx;
    D_80199568 = sizey;
    D_80138774 = dimy;
    D_80106D34 = sizex / dimx;
    D_80119A60 = sizey / dimy;
}

/*800209BC*/
static void func_800209BC(u16 wallnum, s16 arg1)
{
    D_80138770 = gpWall[wallnum].unk22 / D_80106D34;
    D_8011824C = gpWall[wallnum].unk24 / D_80106D34;
    D_8013877C = (gpWall[wallnum].unk23 / D_80119A60) / 4.0f;

    if (arg1 & 0x100)
    {
        D_80199104 = (0xFF - gpWall[wallnum].unk25);
        D_80199104 = (D_80138774 / 256.0f) * D_80199104;
    }
    else
    {
        D_80199104 = (gpWall[wallnum].unk25);
        D_80199104 = (D_80138774 / 256.0f) * D_80199104;
        D_8013877C = -D_8013877C;
    }

    D_80168D00 = D_80199104;

    if (arg1 & 4)
        D_80168D00 = (D_80138774 * 32.0f) + (D_80199104 * 32.0f);
    else
        D_80168D00 = D_80199104 * 32.0f;

    D_8012FD90 = D_8011824C * 32.0f;
    D_800FE3F8 = (D_80138770 * 8.0f * 32.0f) + D_8012FD90;
}

/*80020BA0*/
static void func_80020BA0(u16 wallnum, s16 arg1)
{
    D_80138770 = gpWall[wallnum].unk22 / D_80106D34;
    D_8011824C = gpWall[gpWall[wallnum].nextwall].unk24 / D_80106D34;
    D_8013877C = (gpWall[wallnum].unk23 / D_80119A60) / 4.0f;

    if (arg1 & 0x100)
    {
        D_80199104 = (0xFF - gpWall[gpWall[wallnum].nextwall].unk25);
        D_80199104 = (D_80138774 / 256.0f) * D_80199104;
    }
    else
    {
        D_80199104 = gpWall[gpWall[wallnum].nextwall].unk25;
        D_80199104 = (D_80138774 / 256.0f) * D_80199104;
        D_8013877C = -D_8013877C;
    }

    D_80168D00 = D_80199104;

    if (arg1 & 4)
        D_80168D00 = (D_80138774 * 32.0f) + (D_80199104 * 32.0f);
    else
        D_80168D00 = D_80199104 * 32.0f;

    D_8012FD90 = D_8011824C * 32.0f;
    D_800FE3F8 = (D_80138770 * 8.0f * 32.0f) + D_8012FD90;
}

/*80020DC4*/
static void func_80020DC4(s32 arg0)
{
    f32 f1, prev;
    s32 i;

    if (arg0 & 8)
    {
        prev = D_8012FD90;
        D_8012FD90 = D_800FE3F8;
        D_800FE3F8 = prev;
    }
    f1 = MIN(D_801ACBE4, MIN(D_80168CA0, MIN(D_80138814, D_80118154)));
    if (f1 < -32760.0f)
    {
        i = f1 - (-32760.0f);
        i = ((i + 0xFFF) & ~0xFFF);
        D_801ACBE4 += i;
        D_80168CA0 += i;
        D_80138814 += i;
        D_80118154 += i;
    }
    f1 = MAX(D_801ACBE4, MAX(D_80168CA0, MAX(D_80138814, D_80118154)));
    if (f1 > 32760.0f)
    {
        i = f1 - 32760.0f;
        i = ((i + 0xFFF) & ~0xFFF);
        D_801ACBE4 -= i;
        D_80168CA0 -= i;
        D_80138814 -= i;
        D_80118154 -= i;
    }
}

/*800211D0*/
static void func_800211D0(s32 arg0)
{
    f32 f1, prev;
    s32 i;

    if (arg0 & 8)
    {
        prev = D_8012FD90;
        D_8012FD90 = D_800FE3F8;
        D_800FE3F8 = prev;
    }
    f1 = MIN(D_801ACBE4, D_80168CA0);
    if (f1 < -32760.0f)
    {
        i = klabs(f1) - 32760.0f;
        i = ((i + 0xFFF) & ~0xFFF);
        D_801ACBE4 += i;
        D_80168CA0 += i;
        D_80138814 += i;
        D_80118154 += i;
    }
    f1 = MAX(D_801ACBE4, D_80168CA0);
    if (f1 > 32760.0f)
    {
        i = f1 - 32760.0f;
        i = ((i + 0xFFF) & ~0xFFF);
        D_801ACBE4 -= i;
        D_80168CA0 -= i;
        D_80138814 -= i;
        D_80118154 -= i;
    }
}

/*800213B8*/
u8 func_800213B8(s32 sectnum, s32 wallnum)
{
    s16 nextsector;
    u16 stat;
    s32 ret;

    stat = gpSector[sectnum].floorstat;
    nextsector = gpWall[wallnum].nextsector;
    stat |= gpSector[sectnum].ceilingstat;
    if (nextsector != -1)
    {
        stat |= gpSector[nextsector].floorstat;
        stat |= gpSector[nextsector].ceilingstat;
    }

    if (!(stat & 2))
        ret = func_80022C30(sectnum, wallnum);
    else
        ret = func_80021464(sectnum, wallnum);

    return ret;
}

/*80021464*/
INCLUDE_ASM("nonmatchings/src/code0/21500", func_80021464);

/*800226C0*/
INCLUDE_ASM("nonmatchings/src/code0/21500", func_800226C0);

/*80022C30*/
INCLUDE_ASM("nonmatchings/src/code0/21500", func_80022C30);
