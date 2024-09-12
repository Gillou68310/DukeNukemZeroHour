#include "common.h"
#include "code0/main.h"
#include "code0/audio.h"
#include "code0/engine.h"
#include "code0/pragmas.h"
#include "code0/4600.h"
#include "code0/9410.h"
#include "code0/16DF0.h"
#include "code0/17B30.h"
#include "code0/37090.h"
#include "code0/3FAD0.h"
#include "code0/41940.h"
#include "code0/609D0.h"
#include "code0/64530.h"
#include "code0/6ACA0.h"
#include "code0/6D9E0.h"
#include "code0/7BA50.h"
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

/*.bss*/
/*800F9CC0*/ static s16 _tempWallPtr;

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
static void _spawn(s16 spritenum)
{
    s16 hitsprite;
    s32 hitx, hity;
    SectorType *sec;
    SpriteType *spr;
    s32 i, j, k;
    s32 z;
    s16 l;
    u8 cond;
    u8 unk24, unk25;

    spr = &gpSprite[spritenum];
    sec = &gpSector[spr->sectnum];

    if ((spr->x < -0x10000) || (spr->x > 0x10000) || (spr->y < -0x10000) || (spr->y > 0x10000))
    {
        deleteSprite(spritenum);
        return;
    }

    z = ((spr->cstat & 2)) ? 0xC0 : 0xFF;
    if (spr->cstat & 0x200)
        z = 0x80;

    D_8013B2D0[spritenum].unk6 = 0xFF - z;

    if ((spr->picnum > 48) && (spr->lotag == 66))
        spr->cstat |= 0x100;

    func_800539A8(spr->picnum, spritenum);
    func_800533C4(spr->picnum, spritenum);

    if (spr->picnum == 1688)
        spr->z -= 8000;

    if (spr->statnum == 303)
    {
        spr->cstat = 0x8000;
        spr->unk2B = 0;
    }
    else if (spr->statnum == 301)
    {
        spr->unk2B = 0;
        spr->unk22 = 0;
        spr->unk18 = 0;

        if ((spr->picnum == 2326) && (spr->unk25 & 1))
        {
            spr->unk18 = 1;
            D_8013B2D0[spritenum].unk2 = 500;
        }

        if ((spr->picnum >= 2367) && (spr->picnum < 2373))
        {
            spr->unk18 = 0;
            spr->unk1A = spr->unk24;
            if (spr->unk25 == 0)
            {
                spr->cstat |= 0x8000;
                spr->z += 23000;
            }
        }

        if (spr->picnum == 1960)
            spr->z -= 8700;
    }
    else if (spr->statnum == 302)
    {
        spr->unk2B = 0;
        if ((spr->picnum >= 2367) && (spr->picnum < 2373))
            spr->unk1A = spr->unk24;

        switch (spr->picnum)
        {
        case 36:
            spr->cstat = 0x8000;
            spr->x += ((gpSinTable[(spr->ang + 0x200) & 0x7FF] * 15) >> 13);
            spr->y += ((gpSinTable[spr->ang & 0x7FF] * 15) >> 13);
            setSprite(spritenum, spr->x, spr->y, spr->z);
            func_80058A14(spritenum, &hitsprite, &hitx, &hity);
            i = func_80058934(spr->x, spr->y, spr->z - 0x300, spr->sectnum, 4);
            spr->unk22 = i;
            D_80106D50[i] = func_8004BE90();
            gpSprite[i].lotag = 101;
            gpSprite[i].hitag = spritenum;
            gpSprite[i].cstat = 0x8000;
            gpSprite[i].unk25 = 1;
            gpSprite[i].unk18 = func_8007AE50();
            gpSprite[i].unk22 = 0;
            D_8019B940[D_80106D50[i]].unk44 = hitx;
            D_8019B940[D_80106D50[i]].unk48 = hity;
            D_8019B940[D_80106D50[i]].unk4C = spr->x;
            D_8019B940[D_80106D50[i]].unk50 = spr->y;
            D_8019B940[D_80106D50[i]].unkC = 0;
            break;
        case 2432:
        case 1527:
            spr->unk1A = 0;
            spr->unk22 = 0;
            spr->xrepeat = 0x60;
            break;
        case 2311:
            spr->unk1A = 0;
            spr->unk22 = 0;
            break;
        case 1405:
            j = func_8004BC64(spr->x + (-(gpSinTable[(spr->ang + 0x100) & 0x7FF] * 700) >> 14),
                                      spr->y + (-(gpSinTable[(spr->ang - 0x100) & 0x7FF] * 700) >> 14),
                                      spr->z, spr->sectnum, ENFORCER, 0, 0);
            gpSprite[j].unk25 = 7;
            gpSprite[j].hitag = spr->hitag;
            break;
        case TANK:
        case 1672:
            spr->unk22 = 0;
            spr->unk18 = 0;
            break;
        case MARINE:
        case SERGEANT:
            spr->unk22 = 0;
            if ((spr->unk25 & 0x7F) == 2)
                spr->unk2B = 10;

            if ((spr->unk25 & 0x7F) == 3)
                spr->unk2B = 20;

            if ((spr->unk25 & 0x7F) == 20)
                spr->unk2B = 40;

            spr->lotag = 1;
            spr->unk2A = 0;
            break;
        case 2282:
            spr->z -= 2500;
            break;
        case 2533:
            spr->unk22 = 0;
            spr->unk18 = 0;
            spr->z -= 37500;
            break;
        }
    }

    switch (spr->picnum)
    {
    case 1:
        changeSpriteStat(spritenum, 3);
        switch (spr->lotag)
        {
        case 0:
            if (spr->hitag != 0)
            {
                for (i = 0; i < gNumSprites; i++)
                {
                    if (gpSprite[i].picnum == 1)
                    {
                        if ((gpSprite[i].lotag == gpSprite[i].picnum) && (gpSprite[i].hitag == spr->hitag))
                        {
                            spr->x = gpSprite[i].x;
                            spr->y = gpSprite[i].y;
                        }
                    }
                }
            }
            moveSectAdd(spr->sectnum, spr->x, spr->y);
            spr->unk18 = 1;
            spr->unk16 = _tempWallPtr;

            if (spr->ang > 0x400)
                spr->unk18 = -1;

            spr->ang = 0;
            for (i = sec->wallptr; i < (sec->wallptr + sec->wallnum); i++)
            {
                func_8005FE84(i);
                gOriginsX[_tempWallPtr] = gpWall[i].x - spr->x;
                gOriginsY[_tempWallPtr] = gpWall[i].y - spr->y;
                _tempWallPtr++;
            }
            break;
        case 4:
            spr->unk1A = sec->unk26;
            spr->unk1C = sec->unk27;
            break;
        case 12:
            spr->clipdist = 0;
            if (spr->ang < 0x400)
            {
                unk25 = spr->unk25;
                unk24 = spr->unk24;
                spr->unk25 = sec->unk27;
                spr->unk24 = sec->unk26;
                sec->unk27 = unk25;
                sec->unk26 = unk24;
                spr->clipdist = 1;
            }
            spr->unk1A = sec->unk26;
            spr->unk1C = sec->unk27;
            func_80064DE0(sec, sec->unk26, sec->unk27);
            spr->unk2B = 0;
            break;
        case 13:
            z = sec->floorz;
            spr->unk18 = (z >> 0x10);
            spr->unk1A = z;
            z = sec->ceilingz;
            spr->unk1C = (z >> 0x10);
            spr->unk22 = z;
            sec->floorz = sec->ceilingz = spr->z;
            spr->ang = sec->floorheinum;
            spr->unk16 = sec->ceilingheinum;
            sec->floorheinum = 0;
            sec->ceilingheinum = 0;
            spr->unk25 = 0;

            for (i = sec->wallptr; i < (sec->wallptr + sec->wallnum); i++)
                func_8005FE84(i);

            break;
        case 7:
            for (i = 0; i < gNumSprites; i++)
            {
                if ((i != spritenum) && (gpSprite[i].picnum == 1) &&
                    ((gpSprite[i].lotag == 7) || (gpSprite[i].lotag == 23)))
                {
                    if (gpSprite[i].hitag == spr->hitag)
                    {
                        spr->unk16 = i;
                        break;
                    }
                }
            }
            spr->unk22 = 0;
            changeSpriteStat(spritenum, 9);
            break;
        case 8:
            spr->clipdist = 0;
            spr->unk1A = sec->unk26;
            spr->unk1C = sec->unk27;
            func_80064DE0(sec, sec->unk26, sec->unk27);
            spr->unk2B = 0;
            break;
        case 10:
            spr->unk1A = spr->hitag;
            spr->hitag = 0;
            break;
        case 29:
            if ((sec->unk18 == 3) && !(spr->cstat & 4))
                z = func_80036490(spr->sectnum);
            else if (spr->cstat & 8)
                z = sec->ceilingz;
            else
                z = sec->floorz;

            for (i = sec->wallptr; i < (sec->wallptr + sec->wallnum); i++)
                func_8005FE84(i);

            spr->z = (spr->z + z) / 2;
            spr->unk18 = klabs((z-(spr->z))) / 4;
            break;
        case 30:
            if (spr->cstat & 8)
            {
                z = spr->z;
                spr->z = sec->ceilingz;
                sec->ceilingz = z;
            }
            z = sec->ceilingz;
            spr->unk1C = 0;
            spr->unk2B = 0;
            spr->unk18 = (z >> 0x10);
            spr->unk1A = z;
            break;
        case 40:
        case 41:
            k = gpSector[nextSectorNeighborZ(spr->sectnum, sec->floorz, 1, 0)].floorz;
            spr->unk1C = 0;
            spr->unk2B = 0;
            spr->z = k;

            for (i = sec->wallptr; i < (sec->wallptr + sec->wallnum); i++)
                func_8005FE84(i);
            break;
        case 42:
            if (spr->cstat & 8)
            {
                z = spr->z;
                spr->z = sec->floorz;
                sec->floorz = z;
            }
            z = sec->floorz;
            spr->unk1C = 0;
            spr->unk2B = 0;
            spr->unk18 = (z >> 0x10);
            spr->unk1A = z;

            for (i = sec->wallptr; i < (sec->wallptr + sec->wallnum); i++)
                func_8005FE84(i);
            break;
        case 43:
            for (i = 0; i < gNumSprites; i++)
            {
                if ((i != spritenum) && (gpSprite[i].picnum == 1) && (gpSprite[i].lotag == 43))
                {
                    if (gpSprite[i].hitag == spr->hitag)
                    {
                        spr->unk16 = i;
                        break;
                    }
                }
            }
            if (spr->unk25 == 0)
            {
                z = sec->floorz;
                spr->z = gpSector[gpSprite[i].sectnum].floorz;
            }
            else
            {
                spr->z = sec->floorz;
                z = gpSector[gpSprite[i].sectnum].floorz;
            }
            spr->unk18 = (z >> 0x10);
            spr->unk1A = z;
            spr->unk1C = 0;
            spr->unk2B = 0;

            for (i = sec->wallptr; i < (sec->wallptr + sec->wallnum); i++)
                func_8005FE84(i);
            break;
        case 44:
        case 46:
            spr->unk1C = 0;
            spr->unk2B = 0;
            spr->unk16 = -1;
            i = gHeadSpriteSect[spr->sectnum];
            while (i >= 0)
            {
                if (gpSprite[i].picnum > 48)
                {
                    if ((gpSprite[i].lotag == 44) && ((spr->picnum < 0x500) || ((gModelListCount + 0x500) < spr->picnum)))
                        spr->unk16 = i;
                }
                i = gNextSpriteSect[i];
            }

            if (spr->unk16 != -1)
            {
                z = gpSprite[spr->unk16].z;
                spr->unk18 = (z >> 0x10);
                spr->unk1A = z;
                if (spr->cstat & 8)
                {
                    i = gHeadSpriteSect[spr->sectnum];
                    while (i >= 0)
                    {
                        if (gpSprite[i].picnum > 48)
                        {
                            if (z >= gpSprite[i].z)
                            {
                                /*TODO*/
                                if ((*(s32 *)&gpSprite[i].cstat & 0x40300000) != 0x40100000)
                                    gpSprite[i].z += (spr->z - z);
                            }
                        }
                        i = gNextSpriteSect[i];
                    }
                }
            }
            else
                deleteSprite(spritenum);

            break;
        case 45:
            for (i = 0; i < gNumSprites; i++)
            {
                if ((i != spritenum) && (gpSprite[i].picnum == 1) && (gpSprite[i].lotag == 45))
                {
                    if (gpSprite[i].hitag == spr->hitag)
                    {
                        spr->unk16 = i;
                        break;
                    }
                }
            }

            if (spritenum < i)
                spr->unk25 = 1;
            else
                spr->unk25 = 0;

            spr->unk18 = 0;
            spr->unk2B = 0;
            spr->unk24 = CLAMP_MIN(spr->unk24, 2);
            break;
        case 50:
        case 51:
        case 52:
            if (spr->lotag != 50)
                spr->z = gpSector[nextSectorNeighborZ(spr->sectnum, sec->floorz, 1, 1)].floorz;
            else
                spr->z = gpSector[nextSectorNeighborZ(spr->sectnum, sec->ceilingz, 0, 0)].ceilingz;

            spr->unk1C = 0;

            if (spr->unk25 == 0)
                func_8005FDD0(sec, spr->hitag);

            for (i = sec->wallptr; i < (sec->wallptr + sec->wallnum); i++)
                func_8005FE84(i);
            break;
        case 53:
            if (spr->hitag != 0)
            {
                for (i = 0; i < gNumSprites; i++)
                {
                    if (gpSprite[i].picnum == 1)
                    {
                        if ((gpSprite[i].lotag == gpSprite[i].picnum) && (gpSprite[i].hitag == spr->hitag))
                        {
                            spr->x = gpSprite[i].x;
                            spr->y = gpSprite[i].y;
                        }
                    }
                }
            }
            moveSectAdd(spr->sectnum, spr->x, spr->y);
            spr->unk18 = 0;
            spr->unk16 = _tempWallPtr;
            spr->clipdist = 0;

            if (spr->ang > 0x400)
            {
                spr->unk1C = 1;
                spr->unk1A = 0;
            }
            else
            {
                spr->unk1C = -1;
                spr->unk1A = 0x200;
            }
            spr->ang = 0;

            for (i = sec->wallptr; i < (sec->wallptr + sec->wallnum); i++)
            {
                func_8005FE84(i);
                gOriginsX[_tempWallPtr] = gpWall[i].x - spr->x;
                gOriginsY[_tempWallPtr] = gpWall[i].y - spr->y;
                _tempWallPtr++;
            }
            if (spr->unk25 == 0)
                func_8005FDD0(sec, spr->hitag);

            spr->unk25 = 0;
            break;
        case 54:
            moveSectAdd(spr->sectnum, spr->x, spr->y);
            spr->unk18 = 0;
            spr->unk1A = 0;
            spr->unk1C = 0;
            spr->unk16 = _tempWallPtr;
            spr->clipdist = 0;
            for (i = sec->wallptr; i < (sec->wallptr + sec->wallnum); i++)
            {
                func_8005FE84(i);
                z = findDistance2D(gpWall[i].x - gpWall[gpWall[i].point2].x,
                                   gpWall[i].y - gpWall[gpWall[i].point2].y);
                spr->unk1C = MAX(spr->unk1C, z);
                gOriginsX[_tempWallPtr] = gpWall[i].x - spr->x;
                gOriginsY[_tempWallPtr] = gpWall[i].y - spr->y;
                _tempWallPtr++;
            }

            for (i = 0; i < gNumSprites; i++)
            {
                if ((gpSprite[i].picnum == 10) && (gpSprite[i].sectnum == spr->sectnum) && (gpSprite[i].cstat & 8))
                {
                    spr->unk1C = gpSprite[i].lotag;
                    deleteSprite(i);
                    break;
                }
            }

            if (spr->unk25 == 0)
                func_8005FDD0(sec, spr->hitag);

            spr->unk25 = 0;
            break;
        case 60:
            if (gMapNum != MAP_GOING_DOWN_THE_RACK)
            {
                z = 0xC0000000;
                if (spr->unk25 != 0)
                {
                    i = gHeadSpriteStat[102];
                    while (i >= 0)
                    {
                        if (gpSprite[i].hitag == spr->hitag)
                            z = MAX(z, gpSector[gpSprite[i].sectnum].floorz);

                        i = gNextSpriteStat[i];
                    }

                    i = gHeadSpriteStat[102];
                    while (i >= 0)
                    {
                        if (gpSprite[i].hitag == spr->hitag)
                            gpSprite[i].z = (z + 0x400);

                        i = gNextSpriteStat[i];
                    }
                }

                z = func_80036490(spr->sectnum);
                spr->unk18 = (z >> 0x10);
                spr->unk1A = z;
                spr->unk1C = 0;

                if (spr->z < z)
                    spr->unk25 = 0;
                else
                    spr->unk25 = 1;

                spr->unk2B = 0;
            }
            break;
        case 24:
            spr->unk2B = 1;
            break;
        }
        break;
    case 5:
    case 37:
        changeSpriteStat(spritenum, 110);
        D_8013B2D0[spritenum].handle = 0;
        spr->unk1A = spr->hitag;

        if (spr->unk1A == 0)
            spr->unk1A = 0x4000;

        spr->hitag = 0;
        spr->unk25 = ~spr->unk25;

        if ((spr->picnum == 37) && (spr->unk24 == 0))
            spr->unk24 = 1;

        break;
    case 28:
    case 29:
        changeSpriteStat(spritenum, 111);
        D_8013B2D0[spritenum].handle = 0;
        break;
    case 2:
    case 8:
        spr->unk2B = 0;
        spr->unk25 = 0;
    case 9:
    case 4:
        changeSpriteStat(spritenum, 106);
        break;
    case 3:
        changeSpriteStat(spritenum, 105);
        spr->ang = spr->unk24;
        spr->unk24 = 0;
        break;
    case 17:
        sec->unk2A = spr->lotag;
        deleteSprite(spritenum);
        break;
    case 22:
        if (D_80107908 < 0x20)
        {
            D_8012F708[D_80107908].unk0 = spr->x;
            D_8012F708[D_80107908].unk4 = spr->y;
            D_8012F708[D_80107908].unk8 = spr->z;
            D_8012F708[D_80107908].unkC = spr->ang;
            D_8012F708[D_80107908].unkE = spr->sectnum;
            D_80107908++;
        }
        deleteSprite(spritenum);
        break;
    case 27:
        sec->unk27 = spr->unk25;
        sec->unk23 = spr->unk25;

        for (i = sec->wallptr; i < (sec->wallptr + sec->wallnum); i++)
            gpWall[i].unk21 = spr->unk25;

        deleteSprite(spritenum);
        break;
    case 30:
        spr->unk2A = spr->statnum;
        changeSpriteStat(spritenum, 666);
        spr->unk1A = 0;
        spr->unk1C = 0;
        spr->unk2B = 0;
        spr->unk18 = spr->unk25;
        spr->unk22 = spr->hitag;
        spr->hitag = 0;
        break;
    case 31:
        spr->unk2A = spr->statnum;
        changeSpriteStat(spritenum, 666);
        spr->unk1A = 0;
        spr->unk1C = 1;
        spr->unk2B = 0;
        spr->unk18 = spr->unk25;
        spr->unk22 = spr->hitag;
        spr->hitag = 0;
        break;
    case 34:
        if ((spr->cstat & 8) || (spr->hitag != 0))
        {
            spr->cstat |= 0x8000;
            changeSpriteStat(spritenum, 118);
        }
        else
        {
            if (spr->unk25 != 0)
                sec->floorstat |= 0x1000;
            else
                sec->floorstat |= 0x80;

            spr->picnum = 2253;
            spr->cstat |= 0x800;
            changeSpriteStat(spritenum, 120);
        }
        break;
    case 35:
        sec->floorstat |= 0x100;
        deleteSprite(spritenum);
        D_801A1958.secrets_total++;
        break;
    case 39:
        switch (spr->lotag)
        {
        case 0:
            sec->floorstat |= 0x200;
            break;
        case 1:
            sec->floorstat |= 0x400;
            break;
        case 2:
            sec->floorstat |= 0x800;
            break;
        case 3:
            sec->floorstat |= 0x2000;
            break;
        case 4:
            sec->floorstat |= 0x4000;
            break;
        case 5:
            sec->floorstat |= 0x8000;
            break;
        }

        if (spr->lotag == 4)
        {
            changeSpriteStat(spritenum, 121);
            break;
        }

        if (spr->lotag == 5)
        {
            changeSpriteStat(spritenum, 0);
            break;
        }
        deleteSprite(spritenum);
        break;
    case 546:
    case 547:
    case 548:
    case 549:
        if ((spr->picnum == 546) || (spr->picnum == 547))
            spr->picnum = 6083;

        if ((spr->picnum == 548) || (spr->picnum == 549))
            spr->picnum = 6084;
    case 6083:
    case 6084:
        spr->cstat |= 0x4100;
        changeSpriteStat(spritenum, 58);
        break;
    case 40:
        for (i = 0; i < gNumSprites; i++)
        {
            if (i != spritenum)
            {
                if ((spr->x == gpSprite[i].x) && (spr->y == gpSprite[i].y))
                {
                    gpSprite[i].x = (spr->x + (spr->lotag * cosf((spr->ang * (PI/1024)))));
                    gpSprite[i].y = (gpSprite[i].y + (spr->lotag * sinf((spr->ang * (PI/1024)))));
                    gpSprite[i].z = (gpSprite[i].z + (spr->hitag * 16));
                }
            }
        }
        deleteSprite(spritenum);
        break;
    case 1247:
        spr->cstat |= 0x8000;
        changeSpriteStat(spritenum, 112);
        spr->unk2B = 0;
        break;
    case 6:
        spr->cstat = 0x8000;
        spr->unk24 = 0;
        changeSpriteStat(spritenum, 122);
        break;
    case 12:
        spr->picnum = 5655;
        spr->xrepeat = 0;
        break;
    case 43:
        spr->cstat |= 0x8000;
        spr->unk16 = (s8)spr->unk24;
        changeSpriteStat(spritenum, 116);
        break;
    case 45:
        spr->cstat |= 0x8000;
        changeSpriteStat(spritenum, 117);
        break;
    case 2304:
    case 2305:
    case 2306:
    case 2307:
    case 2308:
    case 2452:
    case 2453:
    case 2454:
    case 2455:
    case 2456:
    case 2457:
    case 2458:
    case 2459:
    case 2460:
    case 2461:
    case 2242:
    case 2243:
    case 2244:
    case 2245:
    case 2246:
    case 2247:
    case 2248:
        changeSpriteStat(spritenum, 130);
        spr->hitag = 1;
        D_801A1958.babes_total++;
        break;
    case 2365:
        changeSpriteStat(spritenum, 108);
        spr->unk18 = 4;
        break;
    case 2496:
    case 2597:
        spr->z += 0x2600;
        break;
    case 5772:
        if (gMapNum == MAP_THE_RACK)
        {
            spr->cstat |= 0x8000;
            changeSpriteStat(spritenum, 123);
        }
        else
        {
            i = func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 52, spr->unk25);
            if (i >= 0)
            {
                gpSprite[i].hitag = spr->hitag;
                if (spr->cstat & 0x202)
                    gpSprite[i].cstat |= 4;
            }
            deleteSprite(spritenum);
        }
        break;
    case 5773:
        if (D_8012C470 == 1)
            func_8008E3E0(spr->x, spr->y, gpSector[spr->sectnum].floorz, spr->sectnum, 64, 358);

        deleteSprite(spritenum);
        break;
    case 5774:
        if (D_8012C470 == 1)
            func_8008E3E0(spr->x, spr->y, gpSector[spr->sectnum].floorz, spr->sectnum, 74, 358);

        deleteSprite(spritenum);
        break;
    case 2591:
    case 2592:
        changeSpriteStat(spritenum, 120);
        break;
    }

    switch (spr->picnum)
    {
    case 3824:
    case 5658:
    case 5700:
        spr->unk2B = 1;
        break;
    case 2553:
    case 2581:
        spr->cstat |= 0x800;
        break;
    }

    if (spr->picnum == 1405)
        spr->unk22 = 0;

    if ((spr->picnum >= 1792) && (spr->picnum < 1916) && (spr->statnum != 4))
    {
        spr->lotag = 80;
        if (spr->statnum != 152)
        {
            changeSpriteStat(spritenum, 150);
            spr->unk18 = -1;
        }
        else
            spr->cstat |= 0x8000;

        spr->cstat &= ~0x101;

        if ((spr->picnum >= 1897) && (spr->picnum < 1903))
            spr->unk22 = 100;

        if (gMapChapter[gMapNum].chapter == DUKEMATCH)
        {
            switch (spr->picnum)
            {
            case 1894:
            case 1895:
                spr->picnum = 1893;
                break;
            case 1899:
            case 1901:
                spr->picnum = 1897;
                break;
            case 1907:
                spr->picnum = 1906;
                break;
            }
        }
    }

    if (spr->picnum == 1916)
    {
        spr->cstat = 0x8000;
        if (spr->statnum != 152)
        {
            l = func_8008E3E0(spr->x, spr->y, spr->z - 4800, spr->sectnum, 57, 0);

            if (l >= 0)
                gpSprite[l].unk22 = spritenum;

            changeSpriteStat(spritenum, 150);
        }
        spr->unk18 = -1;
    }

    if ((spr->picnum >= 2469) && (spr->picnum < 2483))
    {
        changeSpriteStat(spritenum, 150);
        spr->unk18 = -1;
        spr->cstat &= ~0x101;
    }

    if (spr->statnum == 114)
    {
        spr->unk18 = 0;
        spr->unk22 = 0x100;
        spr->unk2A = spr->lotag;
        spr->lotag = 0;
        spr->unk2B = 0;
    }

    if (spr->statnum == 119)
        spr->lotag = 1;

    if ((spr->picnum >= MODELLIST) && ((gModelListCount + MODELLIST) >= spr->picnum))
    {
        if (spr->statnum != 4)
        {
            cond = 1;
            spr->cstat |= 0x1101;

            if ((spr->statnum == 150) || ((spr->statnum >= 20) && (spr->statnum < 23)))
                spr->cstat &= ~0x101;

            if ((spr->picnum == 2200) || (spr->picnum == 2253) ||
                (spr->picnum == 2231) || (spr->picnum == 2487) ||
                (spr->picnum == 2488) || (spr->picnum == 2262) || (spr->picnum == 2263))
            {
                spr->cstat &= ~0x101;
            }

            switch (spr->statnum)
            {
            case 1:
            case 2:
            case 20:
            case 21:
            case 22:
            case 52:
            case 76:
                cond = 0;
                break;
            }

            switch (spr->picnum)
            {
            case SERGEANT:
            case TANK:
            case BOSSZERO:
            case 1527:
            case MARINE:
            case 2254:
            case 2432:
            case 2310:
            case 2311:
            case 2312:
            case 2313:
            case 2314:
                cond = 0;
                break;
            }

            if (cond != 0)
            {
                if (spr->lotag == 0)
                    spr->xrepeat = 0x40;
                else
                    spr->xrepeat = CLAMP_MAX(spr->lotag, 0xFF);

                spr->lotag = 0;
            }

            switch (spr->picnum)
            {
            case 2191:
            case 2433:
            case 2434:
            case 2435:
            case 2467:
            case 2489:
            case 2490:
            case 2491:
                changeSpriteStat(spritenum, 115);
                break;
            }

            spr->yrepeat = spr->xrepeat;
        }
    }

    if (spr->lotag == 66)
        spr->unk1A = 0;

    if (spr->statnum == 0xA0)
        spr->cstat &= ~0x101;

    if (spr->picnum == 2484)
    {
        changeSpriteStat(spritenum, 0);
        spr->lotag = 1;
    }

    if (((spr->picnum == 1462) || (spr->picnum == 1466) || (spr->picnum == 2266)) && (spr->lotag == 0))
        spr->lotag = 1;

    if ((spr->picnum >= 1520) && (spr->picnum < 1523) && (spr->lotag == 0))
        spr->lotag = 1;

    if (spr->picnum == 4870)
    {
        spr->picnum = 4857;
        spr->ang = (spr->ang + 0x400) & 0x7FF;
    }

    if (spr->picnum == 4871)
    {
        spr->picnum = 4858;
        spr->ang = (spr->ang + 0x400) & 0x7FF;
    }

    if ((spr->picnum == 1417) && (gMapNum == MAP_THE_RACK))
    {
        spr->cstat = (spr->cstat & 0xFEFE) | 0x8000;
        changeSpriteStat(spritenum, 123);
    }
}

#ifdef NON_MATCHING
/*80062300*/
void func_80062300(void)
{
    s32 i, j, k, l;
    u8 pad[2]; /*FAKE*/

    (void)pad;
    func_8004F31C();
    func_80016F30();
    _tempWallPtr = 0;
    D_80107908 = 0;
    D_800DEE98 = 0;
    D_800DEE80 = -1;

    for (i = 0; i < gNumSprites; i++)
        _spawn(i);

    i = gHeadSpriteStat[3];
    while (i >= 0)
    {
        if (gpSprite[i].lotag != 8)
        {
            if (gpSprite[i].lotag == 43)
            {
                if (gpSprite[i].unk25 != 0)
                {
                    j = gpSector[gpSprite[gpSprite[i].unk16].sectnum].floorz - gpSector[gpSprite[i].sectnum].floorz;
                    gpSector[gpSprite[i].sectnum].floorz = gpSector[gpSprite[gpSprite[i].unk16].sectnum].floorz;
                    gpSector[gpSprite[i].sectnum].ceilingz += j;
                }
            }
        }
        else
        {
            gpSprite[i].unk16 = -1;
            j = gHeadSpriteStat[3];
            while (j >= 0)
            {
                if (((gpSprite[j].lotag >= 50) && (gpSprite[j].lotag < 55)) && (gpSprite[j].hitag == gpSprite[i].hitag))
                {
                    gpSprite[i].unk16 = j;
                    l = 0;
                    switch (gpSprite[j].lotag)
                    {
                    case 50:
                    case 51:
                    case 52:
                        k = gpSector[gpSprite[j].sectnum].floorz - gpSprite[j].z;
                        l = klabs(k);
                        break;
                    case 53:
                        l = 0x200;
                        break;
                    case 54:
                        l = gpSprite[j].unk1C;
                        break;
                    default:
                        break;
                    }
                    gpSprite[i].z = l;
                    break;
                }
                j = gNextSpriteStat[j];
            }
        }
        i = gNextSpriteStat[i];
    }

    i = gHeadSpriteStat[106];
    while (i >= 0)
    {
        if (gpSprite[i].picnum == 4)
        {
            if (gpSprite[i].unk25 == 0)
            {
                j = gHeadSpriteSect[gpSprite[i].sectnum];
                while (j >= 0)
                {
                    l = gpSprite[j].picnum; /*FAKE*/

                    if ((l == 1) || (l == 3) || (l == 28))
                        gpSprite[j].cstat |= 0x8000;

                    j = gNextSpriteSect[j];
                }
            }
        }
        i = gNextSpriteStat[i];
    }

    for (i = 0; i < D_8012C470; i++)
        func_80062950(i, 1);

    func_80016218();
}
#else
/*80062300*/
INCLUDE_ASM("src/code0/609D0", func_80062300);
#endif

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
        gPlayer[playernum].ang = D_8012F708[i].unkC;
        gPlayer[playernum].cursectnum = D_8012F708[i].unkE;
    }

    D_80138610[playernum] = 0;
    D_801AE480[playernum] = 0;
    D_8012F914[playernum] = -1;
    D_8011814A[playernum] = 600;
    func_80062888();

    if (arg1)
    {
        spritenum = insertSprite(gPlayer[playernum].cursectnum, 10);
        gPlayer[playernum].unk4A = spritenum;
        gpSprite[spritenum].unk16 = playernum;
        D_80106D50[spritenum] = func_8004BE90();
    }
    else
    {
        spritenum = gPlayer[playernum].unk4A;
        changeSpriteSect(gPlayer[playernum].unk4A, gPlayer[playernum].cursectnum);
    }

    if (D_8012C470 >= 2)
    {
        if (arg1)
            gpSprite[spritenum].picnum = playernum + VICTORIANDUKE;
    }
    else
    {
        switch (gMapChapter[gMapNum].chapter)
        {
        default:
        case 0:
        case PRESENT_DAY:
        case FINAL:
            if (gMapNum >= MAP_NUCLEAR_WINTER && gMapNum < MAP_DRY_TOWN)
                gpSprite[spritenum].picnum = APOCALYPSEDUKE;
            else
                gpSprite[spritenum].picnum = DUKENUKEM;
            break;
        case WESTERN:
            gpSprite[spritenum].picnum = COWBOYDUKE;
            break;
        case VICTORIAN:
            gpSprite[spritenum].picnum = VICTORIANDUKE;
            break;
        }
    }

    gpSprite[spritenum].cstat = 0x1101;
    gpSprite[spritenum].xrepeat = 64;
    gpSprite[spritenum].yrepeat = 64;
    gpSprite[spritenum].unk24 = gpSector[gPlayer[playernum].cursectnum].unk26;
    setSprite(spritenum, gPlayer[playernum].xpos, gPlayer[playernum].ypos, gPlayer[playernum].zpos + gPlayer[playernum].unk40);
    gpSprite[spritenum].ang = gPlayer[playernum].ang;
    gpSprite[spritenum].unk25 = 0;

    if ((!(D_8012C470 < 2)) && !(arg1))
    {
        func_8008E3E0(gPlayer[playernum].xpos,
                      gPlayer[playernum].ypos,
                      gPlayer[playernum].zpos + gPlayer[playernum].unk40,
                      gPlayer[playernum].cursectnum, 43, 0);

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
        if (gMapChapter[gMapNum].chapter == WESTERN)
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
        spritenum = insertSprite(gPlayer[playernum].cursectnum, 0);
        D_8012FCA0[playernum] = spritenum;
    }
    else
        spritenum = D_8012FCA0[playernum];

    setSprite(spritenum,
              gPlayer[playernum].xpos,
              gPlayer[playernum].ypos,
              getFlorzOfSlope(gPlayer[playernum].cursectnum, gPlayer[playernum].xpos, gPlayer[playernum].ypos));

    gpSprite[spritenum].picnum = 5615;
    gpSprite[spritenum].unk16 = playernum;
    gpSprite[spritenum].cstat = 0x4820;
    gpSprite[spritenum].xrepeat = 64;
    gpSprite[spritenum].yrepeat = 64;
    gpSprite[spritenum].unk25 = 7;
    D_8013B2D0[spritenum].unk6 = 0;

    if ((D_8012C470 >= 2) || (gCheatFirstPersonConfig != CONFIG_OFF))
    {
        gPlayer[playernum].unk61 = 0;
        gPlayer[playernum].third_person = FALSE;
    }
    else
    {
        gPlayer[playernum].unk61 = 1;
        gPlayer[playernum].third_person = TRUE;
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
    gPlayer[playernum].keys[0] = 1;
    gPlayer[playernum].unk57 = gPlayer[playernum].unk54;

    for (i = 1; i < ARRAY_COUNT(gPlayer[playernum].keys); i++)
        gPlayer[playernum].keys[i] = 0;

    gPlayer[playernum].unk52 = -1;
    gPlayer[playernum].unk6E = 0x100;
    gPlayer[playernum].unk6A = 0x100;
    gPlayer[playernum].unk6C = 0;
    gPlayer[playernum].unk3C = 0;
    gPlayer[playernum].unk3E = 0;
    gPlayer[playernum].xvect = 0;
    gPlayer[playernum].yvect = 0;
    gPlayer[playernum].zvect = 0;
    D_800DEF1C = -1;
    func_8000EB90(playernum & 0xFF, 0, 0, 0, 0);
    D_80106D30[playernum] = 0;

    if ((D_8012C470 >= 2) || (gCheatSelectSkinConfig != CONFIG_OFF))
    {
        if (arg1 != 0)
        {
            if (D_8010554C != 0)
            {
                gpSprite[gPlayer[playernum].unk4A].cstat |= 0x8000;
                gpSprite[gPlayer[playernum].unk4A].cstat &= ~0x101;
                D_80106D30[playernum] = 1;
                gPlayer[playernum].skin = playernum;
            }
        }

        gpSprite[gPlayer[playernum].unk4A].picnum = D_8012F6E4[gPlayer[playernum].skin].picnum;
        D_80138858[playernum] = 0;
    }
    else
        gPlayer[playernum].skin = 0;

    gPlayer[playernum].unk4E = 0;
    gPlayer[playernum].unk68 = gPlayer[playernum].cursectnum;
    gPlayer[playernum].unk64 = 1524.0f;
    Bmemset(&D_801A2790[playernum], 0, sizeof(code0UnkStruct17));
    D_801A2790[playernum].unk16 = gPlayer[playernum].ang;
    D_801A2790[playernum].unk24 = 1524;
    D_801B0820 = playernum;
    func_8003F340();
    func_8003FD5C();
}

/*hack for wrong rodata aligment*/
static const f64 _force_rodata_alignment = 0;
