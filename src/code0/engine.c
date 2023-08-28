#include "common.h"
#include "code0/pragmas.h"
#include "code0/engine.h"
#include "code0/35D90.h"
#include "code0/41940.h"
#include "code0/code0.h"
#include "static/mapinfo.h"

#define MAXCLIPNUM 512
#define MAXCLIPDIST 1024

typedef struct { s32 x1, y1, x2, y2; } LineType;

/*.data*/
/*800DD440*/ EXTERN_DATA STATIC s16 _editStatus;
/*800DD444*/ EXTERN_DATA STATIC s32 _clipMoveBoxTraceNum;
/*800DD448*/ EXTERN_DATA u8 D_800DD448;

/*.bss*/
/*800F7060*/ EXTERN_BSS STATIC s32 _rxi[8];
/*800F7080*/ EXTERN_BSS STATIC s32 _ryi[8];
/*800F70A0*/ EXTERN_BSS STATIC s16 D_800F70A0;
/*800F70A2*/ EXTERN_BSS STATIC s16 _clipNum;
/*800F70A4*/ EXTERN_BSS STATIC s16 _hitWalls[4];
/*800F70B0*/ EXTERN_BSS STATIC LineType _clipIt[MAXCLIPNUM];
/*800F90B0*/ EXTERN_BSS STATIC s16 _clipSectorList[MAXCLIPNUM];
/*800F94B0*/ EXTERN_BSS STATIC s16 _clipSectNum;
/*800F94C0*/ EXTERN_BSS STATIC s32 _clipObjectVal[MAXCLIPNUM];

/*.comm*/
/*800FE420*/ s16 gHeadSpriteSect[MAXSECTORS+1] ALIGNED(16);
/*8010571A*/ s16 gNumWalls;
/*8012EEE0*/ s16 gHeadSpriteStat[MAXSTATUS+1] ALIGNED(16);
/*80139880*/ s16 gPrevSpriteSect[MAXSPRITES] ALIGNED(16);
/*80119AB0*/ s16 gPrevSpriteStat[MAXSPRITES] ALIGNED(16);
/*8012D340*/ s16 gNextSpriteSect[MAXSPRITES] ALIGNED(16);
/*8013A650*/ s16 gNextSpriteStat[MAXSPRITES] ALIGNED(16);
/*8012D33C*/ s16 *gpRadaRang;
/*8012F90C*/ s16 gNumSectors;
/*8012FC98*/ s32 gRandomSeed;
/*8012FCA8*/ SpriteType *gpSprite;
/*8013A64C*/ SectorType *gpSector;
/*80169578*/ s16 gNumSprites;
/*80197DE0*/ s32 gTotalClockLock;
/*80199950*/ s32 D_80199950;
/*801A197C*/ s16 *gpSinTable;
/*801A2624*/ s32 D_801A2624;
/*801A2830*/ WallType *gpWall;
/*801AC9F4*/ s32 D_801AC9F4;

/*.text*/

static s16 insertSpriteStat(s16 statnum);
static s16 insertSpriteSect(s16 sectnum);
static s32 deleteSpriteStat(s16 deleteme);
static s32 deleteSpriteSect(s16 deleteme);
static s16 lastWall(s16 point);
static s32 lIntersect(s32 x1, s32 y1, s32 z1, s32 x2, s32 y2, s32 z2, s32 x3,
                      s32 y3, s32 x4, s32 y4, s32 *intx, s32 *inty, s32 *intz);
static s32 rayTrace(s32 x3, s32 y3, s32 *x4, s32 *y4);
static void keepAway(s32 *x, s32 *y, s32 w);

/*8002B680*/
void engine_8002B680(void)
{
    D_800F70A0 = -1;
    gTotalClockLock = 0;
}

/*8002B69C*/
s32 clipInsideBox(s32 x, s32 y, s16 wallnum, s32 walldist)
{
    WallType *wal;
    s32 x1, y1, x2, y2, r;

    r = (walldist<<1);
    wal = &gpWall[wallnum];     x1 = wal->x+walldist-x; y1 = wal->y+walldist-y;
    wal = &gpWall[wal->point2]; x2 = wal->x+walldist-x; y2 = wal->y+walldist-y;

    if ((x1 < 0) && (x2 < 0)) return(0);
    if ((y1 < 0) && (y2 < 0)) return(0);
    if ((x1 >= r) && (x2 >= r)) return(0);
    if ((y1 >= r) && (y2 >= r)) return(0);

    x2 -= x1; y2 -= y1;
    if (x2*(walldist-y1) >= y2*(walldist-x1))  //Front
    {
        if (x2 > 0) x2 *= (0-y1); else x2 *= (r-y1);
        if (y2 > 0) y2 *= (r-x1); else y2 *= (0-x1);
        return(x2 < y2);
    }
    if (x2 > 0) x2 *= (r-y1); else x2 *= (0-y1);
    if (y2 > 0) y2 *= (0-x1); else y2 *= (r-x1);
    return((x2 >= y2)<<1);
}

/*8002B83C*/
static s32 clipInsideBoxLine(s32 x, s32 y, s32 x1, s32 y1, s32 x2, s32 y2, s32 walldist)
{
    s32 r;

    r = (walldist<<1);

    x1 += walldist-x; x2 += walldist-x;
    if ((x1 < 0) && (x2 < 0)) return(0);
    if ((x1 >= r) && (x2 >= r)) return(0);

    y1 += walldist-y; y2 += walldist-y;
    if ((y1 < 0) && (y2 < 0)) return(0);
    if ((y1 >= r) && (y2 >= r)) return(0);

    x2 -= x1; y2 -= y1;
    if (x2*(walldist-y1) >= y2*(walldist-x1))  //Front
    {
        if (x2 > 0) x2 *= (0-y1); else x2 *= (r-y1);
        if (y2 > 0) y2 *= (r-x1); else y2 *= (0-x1);
        return(x2 < y2);
    }
    if (x2 > 0) x2 *= (r-y1); else x2 *= (0-y1);
    if (y2 > 0) y2 *= (0-x1); else y2 *= (r-x1);
    return((x2 >= y2)<<1);
}

/*8002B99C*/
static s32 inside(s32 x, s32 y, s16 sectnum)
{
    WallType *wal;
    s32 i, x1, y1, x2, y2;
    u32 cnt;

    if ((sectnum < 0) || (sectnum >= gNumSectors)) return(-1);

    cnt = 0;
    wal = &gpWall[gpSector[sectnum].wallptr];
    i = gpSector[sectnum].wallnum;
    do
    {
        y1 = wal->y-y; y2 = gpWall[wal->point2].y-y;
        if ((y1^y2) < 0)
        {
            x1 = wal->x-x; x2 = gpWall[wal->point2].x-x;
            if ((x1^x2) >= 0) cnt ^= x1; else cnt ^= (x1*y2-x2*y1)^y2;
        }
        wal++; i--;
    } while (i);
    return(cnt>>31);
}

/*8002BAA8*/
s32 getAngle(s32 xvect, s32 yvect)
{
    if ((xvect|yvect) == 0) return(0);
    if (xvect == 0) return(512+((yvect<0)<<10));
    if (yvect == 0) return(((xvect<0)<<10));
    if (xvect == yvect) return(256+((xvect<0)<<10));
    if (xvect == -yvect) return(768+((xvect>0)<<10));
    if (klabs(xvect) > klabs(yvect))
        return(((gpRadaRang[640+scale(160, yvect, xvect)]>>6)+((xvect<0)<<10))&2047);
    return(((gpRadaRang[640-scale(160, xvect, yvect)]>>6)+512+((yvect<0)<<10))&2047);
}

/*8002BBE0*/
s32 setSprite(s16 spritenum, s32 newx, s32 newy, s32 newz)
{
    s16 bad, j, tempsectnum;

    gpSprite[spritenum].x = newx;
    gpSprite[spritenum].y = newy;
    gpSprite[spritenum].z = newz;

    tempsectnum = gpSprite[spritenum].sectnum;
    updateSectorZ(newx, newy, newz, &tempsectnum);
    if (tempsectnum < 0)
    {
        updateSector(newx, newy, &tempsectnum);
        if (tempsectnum < 0)
            return(-1);
    }

    if (tempsectnum != gpSprite[spritenum].sectnum)
        changeSpriteSect(spritenum, tempsectnum);

    return(0);
}

/*8002BCE0*/
s32 animateOffs(s16 tileid, s16 fakevar)
{
    s32 i, k, offs;

    offs = 0;
    i = (gTotalClockLock>>((getTilePicanm(tileid)>>24)&15));
    if ((getTilePicanm(tileid)&63) > 0)
    {
        switch (getTilePicanm(tileid)&192)
        {
        case 64:
            k = (i%((getTilePicanm(tileid)&63)<<1));
            if (k < (getTilePicanm(tileid)&63))
                offs = k;
            else
                offs = (((getTilePicanm(tileid)&63)<<1)-k);
            break;
        case 128:
            offs = (i%((getTilePicanm(tileid)&63)+1));
            break;
        case 192:
            offs = -(i%((getTilePicanm(tileid)&63)+1));
        }
    }
    return(offs);
}

/*8002BE98*/
void initSpriteLists(void)
{
    s32 i;

    D_801AC9F4 = 0;
    D_801A2624 = 0;
    D_80199950 = 0;

    for (i = 0; i<MAXSECTORS; i++)     //Init doubly-linked sprite sector lists
        gHeadSpriteSect[i] = -1;
    gHeadSpriteSect[MAXSECTORS] = 0;
    for (i = 0; i<MAXSPRITES; i++)
    {
        gPrevSpriteSect[i] = i-1;
        gNextSpriteSect[i] = i+1;
        gpSprite[i].sectnum = MAXSECTORS;
    }
    gPrevSpriteSect[0] = -1;
    gNextSpriteSect[MAXSPRITES-1] = -1;


    for (i = 0; i<MAXSTATUS; i++)      //Init doubly-linked sprite status lists
        gHeadSpriteStat[i] = -1;
    gHeadSpriteStat[MAXSTATUS] = 0;
    for (i = 0; i<MAXSPRITES; i++)
    {
        gPrevSpriteStat[i] = i-1;
        gNextSpriteStat[i] = i+1;
        gpSprite[i].statnum = MAXSTATUS;
    }
    gPrevSpriteStat[0] = -1;
    gNextSpriteStat[MAXSPRITES-1] = -1;
}

/*8002BFF8*/
s32 insertSprite(s16 sectnum, s16 statnum)
{
    s16 stat;
    s16 sect;
    s32 temp;

    stat = insertSpriteStat(statnum);
    sect = insertSpriteSect(sectnum);

    if (((stat == -1) || (sect == -1)) == 0)
    {
        if (stat == sect)
        {
            temp = D_80199950;
            D_801A2624++;
            if (temp < D_801A2624)
            {
                temp = D_801A2624;
            }
            D_80199950 = temp;
        }
    }
    return sect;
}

/*8002C0A8*/
static s16 insertSpriteSect(s16 sectnum)
{
    s16 blanktouse;

    if ((sectnum >= MAXSECTORS) || (gHeadSpriteSect[MAXSECTORS] == -1))
        return(-1);  //list full

    blanktouse = gHeadSpriteSect[MAXSECTORS];

    gHeadSpriteSect[MAXSECTORS] = gNextSpriteSect[blanktouse];
    if (gHeadSpriteSect[MAXSECTORS] >= 0)
        gPrevSpriteSect[gHeadSpriteSect[MAXSECTORS]] = -1;

    gPrevSpriteSect[blanktouse] = -1;
    gNextSpriteSect[blanktouse] = gHeadSpriteSect[sectnum];
    if (gHeadSpriteSect[sectnum] >= 0)
        gPrevSpriteSect[gHeadSpriteSect[sectnum]] = blanktouse;
    gHeadSpriteSect[sectnum] = blanktouse;

    gpSprite[blanktouse].sectnum = sectnum;

    return(blanktouse);
}

/*8002C18C*/
static s16 insertSpriteStat(s16 statnum)
{
    s16 blanktouse;

    if ((statnum >= MAXSTATUS) || (gHeadSpriteStat[MAXSTATUS] == -1))
        return(-1);  //list full

    blanktouse = gHeadSpriteStat[MAXSTATUS];

    gHeadSpriteStat[MAXSTATUS] = gNextSpriteStat[blanktouse];
    if (gHeadSpriteStat[MAXSTATUS] >= 0)
        gPrevSpriteStat[gHeadSpriteStat[MAXSTATUS]] = -1;

    gPrevSpriteStat[blanktouse] = -1;
    gNextSpriteStat[blanktouse] = gHeadSpriteStat[statnum];
    if (gHeadSpriteStat[statnum] >= 0)
        gPrevSpriteStat[gHeadSpriteStat[statnum]] = blanktouse;
    gHeadSpriteStat[statnum] = blanktouse;

    gpSprite[blanktouse].statnum = statnum;

    return(blanktouse);
}

/*8002C270*/
s32 deleteSprite(s16 spritenum)
{
    s32 stat;
    s32 sect;
    s32 statnum;

    MusHandleStop(D_8013B2D0[spritenum].handle, 0);
    D_8013B2D0[spritenum].handle = 0;
    statnum = gpSprite[spritenum].statnum;

    stat = deleteSpriteStat(spritenum);
    sect = deleteSpriteSect(spritenum);

    if (((stat == -1) || (sect == -1)) == 0)
    {
        D_801A2624--;
        if (statnum == 0x136)
        {
            if (D_801AC9F4 != 0)
                D_801AC9F4--;
        }
    }
    return sect;
}

/*8002C35C*/
static s32 deleteSpriteSect(s16 deleteme)
{
    if (gpSprite[deleteme].sectnum == MAXSECTORS)
        return(-1);

    if (gHeadSpriteSect[gpSprite[deleteme].sectnum] == deleteme)
        gHeadSpriteSect[gpSprite[deleteme].sectnum] = gNextSpriteSect[deleteme];

    if (gPrevSpriteSect[deleteme] >= 0) gNextSpriteSect[gPrevSpriteSect[deleteme]] = gNextSpriteSect[deleteme];
    if (gNextSpriteSect[deleteme] >= 0) gPrevSpriteSect[gNextSpriteSect[deleteme]] = gPrevSpriteSect[deleteme];

    if (gHeadSpriteSect[MAXSECTORS] >= 0) gPrevSpriteSect[gHeadSpriteSect[MAXSECTORS]] = deleteme;
    gPrevSpriteSect[deleteme] = -1;
    gNextSpriteSect[deleteme] = gHeadSpriteSect[MAXSECTORS];
    gHeadSpriteSect[MAXSECTORS] = deleteme;

    gpSprite[deleteme].sectnum = MAXSECTORS;
    return(0);
}

/*8002C474*/
static s32 deleteSpriteStat(s16 deleteme)
{
    if (gpSprite[deleteme].statnum == MAXSTATUS)
        return(-1);

    if (gHeadSpriteStat[gpSprite[deleteme].statnum] == deleteme)
        gHeadSpriteStat[gpSprite[deleteme].statnum] = gNextSpriteStat[deleteme];

    if (gPrevSpriteStat[deleteme] >= 0) gNextSpriteStat[gPrevSpriteStat[deleteme]] = gNextSpriteStat[deleteme];
    if (gNextSpriteStat[deleteme] >= 0) gPrevSpriteStat[gNextSpriteStat[deleteme]] = gPrevSpriteStat[deleteme];

    if (gHeadSpriteStat[MAXSTATUS] >= 0) gPrevSpriteStat[gHeadSpriteStat[MAXSTATUS]] = deleteme;
    gPrevSpriteStat[deleteme] = -1;
    gNextSpriteStat[deleteme] = gHeadSpriteStat[MAXSTATUS];
    gHeadSpriteStat[MAXSTATUS] = deleteme;

    gpSprite[deleteme].statnum = MAXSTATUS;
    return(0);
}

/*8002C58C*/
s32 changeSpriteSect(s16 spritenum, s16 newsectnum)
{
    if ((newsectnum < 0) || (newsectnum > MAXSECTORS)) return(-1);
    if (gpSprite[spritenum].sectnum == newsectnum) return(0);
    if (gpSprite[spritenum].sectnum == MAXSECTORS) return(-1);
    if (deleteSpriteSect(spritenum) < 0) return(-1);
    insertSpriteSect(newsectnum);
    return(0);
}

/*8002C628*/
s32 changeSpriteStat(s16 spritenum, s16 newstatnum)
{
    if ((newstatnum < 0) || (newstatnum > MAXSTATUS)) return(-1);
    if (gpSprite[spritenum].statnum == newstatnum) return(0);
    if (gpSprite[spritenum].statnum == MAXSTATUS) return(-1);
    if (deleteSpriteStat(spritenum) < 0) return(-1);
    insertSpriteStat(newstatnum);
    return(0);
}

/*8002C6C4*/
s32 nextSectorNeighborZ(s16 sectnum, s32 thez, s16 topbottom, s16 direction)
{
    WallType *wal;
    s32 i, testz, nextz;
    s16 sectortouse;

    if (direction == 1) nextz = 0x7fffffff; else nextz = 0x80000000;

    sectortouse = sectnum;

    wal = &gpWall[gpSector[sectnum].wallptr];
    i = gpSector[sectnum].wallnum;
    do
    {
        if (wal->nextsector >= 0)
        {
            if (topbottom == 1)
            {
                testz = gpSector[wal->nextsector].floorz;
                if (direction == 1)
                {
                    if ((testz > thez) && (testz < nextz))
                    {
                        nextz = testz;
                        sectortouse = wal->nextsector;
                    }
                }
                else
                {
                    if ((testz < thez) && (testz > nextz))
                    {
                        nextz = testz;
                        sectortouse = wal->nextsector;
                    }
                }
            }
            else
            {
                testz = gpSector[wal->nextsector].ceilingz;
                if (direction == 1)
                {
                    if ((testz > thez) && (testz < nextz))
                    {
                        nextz = testz;
                        sectortouse = wal->nextsector;
                    }
                }
                else
                {
                    if ((testz < thez) && (testz > nextz))
                    {
                        nextz = testz;
                        sectortouse = wal->nextsector;
                    }
                }
            }
        }
        wal++;
        i--;
    } while (i != 0);

    return(sectortouse);
}

/*8002C7D0*/
s32 canSee(s32 x1, s32 y1, s32 z1, s16 sect1, s32 x2, s32 y2, s32 z2, s16 sect2)
{
    SectorType *sec;
    WallType *wal, *wal2;
    s32 i, cnt, nexts, x, y, z, cz, fz, dasectnum, dacnt, danum;
    s32 x21, y21, z21, x31, y31, x34, y34, bot, t;

    if ((x1 == x2) && (y1 == y2)) return(sect1 == sect2);

    x21 = x2-x1; y21 = y2-y1; z21 = z2-z1;

    _clipSectorList[0] = sect1; danum = 1;
    for (dacnt = 0; dacnt<danum; dacnt++)
    {
        dasectnum = _clipSectorList[dacnt]; sec = &gpSector[dasectnum];
        for (cnt = sec->wallnum, wal = &gpWall[sec->wallptr]; cnt>0; cnt--, wal++)
        {
            wal2 = &gpWall[wal->point2];
            x31 = wal->x-x1; x34 = wal->x-wal2->x;
            y31 = wal->y-y1; y34 = wal->y-wal2->y;

            bot = y21*x34-x21*y34; if (bot <= 0) continue;
            t = y21*x31-x21*y31;
            if ((t < 0) || t >= bot) continue;
            t = y31*x34-x31*y34;
            if ((t < 0) || t >= bot) continue;

            nexts = wal->nextsector;
            if ((nexts < 0) || (wal->cstat&32)) return(0);

            t = divscale24(t, bot);
            x = x1 + mulscale24(x21, t);
            y = y1 + mulscale24(y21, t);
            z = z1 + mulscale24(z21, t);

            getzsOfSlope((s16)dasectnum, x, y, &cz, &fz);
            if ((z <= cz) || (z >= fz)) return(0);
            getzsOfSlope((s16)nexts, x, y, &cz, &fz);
            if ((z <= cz) || (z >= fz)) return(0);

            for (i = danum-1; i>=0; i--) if (_clipSectorList[i] == nexts) break;
            if (i < 0) _clipSectorList[danum++] = nexts;
        }
    }
    for (i = danum-1; i>=0; i--) if (_clipSectorList[i] == sect2) return(1);
    return(0);
}

/*8002CBEC*/
INCLUDE_ASM("nonmatchings/src/code0/engine", hitScan);

/*8002F1B4*/
s32 nearTag(s32 xs, s32 ys, s32 zs, s16 sectnum, s16 ange, s16 *neartagsector, s16 *neartagwall, s16 *neartagsprite, s32 *neartaghitdist, s32 neartagrange, u8 tagsearch)
{
    ModelInfo *ptr;
    WallType *wal2;
    WallType *wall;
    SpriteType *spr;

    s32 z, zz;
    s32 intx, inty, intz;
    s32 x3, y3;
    s32 xe, ye, ze;
    s32 x1, y1;
    s32 x2, y2;

    s16 tempshortcnt;
    s16 tempshortnum;
    s16 dasector;
    s16 endwall;
    s16 startwall;
    s16 nextsector;
    s16 good;

    s32 i, j, k, l, m;
    s32 z1, z2;
    s32 neartagrange2;
    s32 neartagrange1;

    *neartagsector = -1;
    *neartagwall = -1;
    *neartagsprite = -1;
    *neartaghitdist = 0;

    if (sectnum < 0)
        return 0;

    if ((tagsearch < 1) || (tagsearch > 3))
        return 0;

    xe = xs + mulscale14(gpSinTable[(ange + 0xA00) & 0x7FF], neartagrange);
    ye = ys + mulscale14(gpSinTable[(ange + 0x800) & 0x7FF], neartagrange);
    ze = 0;
    tempshortcnt = 0;
    _clipSectorList[0] = sectnum;
    tempshortnum = 1;

    do
    {
        dasector = _clipSectorList[tempshortcnt];
        startwall = gpSector[dasector].wallptr;
        endwall = (startwall + gpSector[dasector].wallnum) - 1;

        for (z = startwall, wall = &gpWall[z]; endwall >= z; z++, wall++)
        {
            wal2 = &gpWall[wall->point2];
            x1 = wall->x;
            y1 = wall->y;
            x2 = wal2->x;
            y2 = wal2->y;
            nextsector = wall->nextsector;

            good = 0;
            if ((tagsearch&1) && (wall->unk14 >= 11))
                good |= 2;

            if ((good == 0) && (nextsector < 0))
                continue;

            if ((x1-xs)*(y2-ys) < (x2-xs)*(y1-ys))
                continue;

            if (lIntersect(xs, ys, zs, xe, ye, ze, x1, y1, x2, y2, &intx, &inty, &intz) == 1)
            {
                if (good != 0)
                {
                    if (good & 1)
                        *neartagsector = nextsector;
                    if (good & 2)
                        *neartagwall = z;

                    *neartaghitdist = dmulscale14((intx - xs), gpSinTable[(ange + 0xA00) & 0x7FF],
                                                  (inty - ys), gpSinTable[((ange + 0x800) & 0x7FF)]);
                    xe = intx;
                    ye = inty;
                    ze = intz;
                }

                if (nextsector >= 0)
                {
                    for (zz = tempshortnum-1; zz>=0; zz--)
                    {
                        if (_clipSectorList[zz] == nextsector)
                            break;
                    }

                    if (zz < 0)
                        _clipSectorList[tempshortnum++] = nextsector;
                }
            }
        }

        neartagrange1 = neartagrange;
        for (z = gHeadSpriteSect[dasector]; z >= 0; z = gNextSpriteSect[z])
        {
            spr = &gpSprite[z];
            if (spr->picnum < 0x31)
                continue;

            if (spr->cstat & 0x8000)
                continue;

            if (spr->statnum == 1)
                continue;

            if (spr->statnum == 0x136)
                continue;

            good = 0;
            if ((tagsearch&1) && spr->lotag)
                good |= 1;

            if ((tagsearch&2) && spr->hitag)
                good |= 1;

            if (good != 0)
            {
                neartagrange2 = func_80040D40(spr->x, spr->y, xs, ys);
                if (spr->cstat & 0x1000)
                {
                    ptr = D_800D52E0[spr->picnum-1280];
                    if (ptr == NULL)
                        continue;

                    i = ((ptr->unk2A - ptr->unk24) * spr->xrepeat) / 16;
                    j = ((ptr->unk2C - ptr->unk26) * spr->xrepeat) / 16;
                    k = (i + j) / 4;
                    neartagrange2 = CLAMP_MIN((neartagrange2 - k), 0);
                }

                if (neartagrange2 < neartagrange1)
                {
                    if (spr->cstat & 0x1000)
                    {
                        l = (ptr->unk2E * (spr->yrepeat << 6)) / 64;
                        z1 = spr->z - l;
                        m = (ptr->unk28 * (spr->yrepeat << 6)) / 64;
                        z2 = spr->z - m;
                    }
                    else
                    {
                        z1 = spr->z - (getTileSizeY(spr->picnum) * spr->yrepeat * 2);
                        z2 = spr->z;
                    }
                    if ((z2 >= (zs - 0x3900)) && (zs >= z1))
                    {
                        rotatePoint(0, 0, spr->x - xs, spr->y - ys, (0x800 - ange), &x3, &y3);
                        if (klabs(y3) < x3)
                        {
                            *neartagsprite = z;
                            neartagrange1 = neartagrange2;
                            *neartaghitdist = dmulscale14((spr->x - xs), gpSinTable[(ange + 0xA00) & 0x7FF],
                                                          (spr->y - ys), gpSinTable[(ange + 0x800) & 0x7FF]);
                        }
                    }
                }
            }
        }
        tempshortcnt++;
    } while (tempshortcnt < tempshortnum);

    return 0;
}

/*8002F994*/
static s32 lIntersect(s32 x1, s32 y1, s32 z1, s32 x2, s32 y2, s32 z2, s32 x3,
                      s32 y3, s32 x4, s32 y4, s32 *intx, s32 *inty, s32 *intz)
{     //p1 to p2 is a line segment
    s32 x21, y21, x34, y34, x31, y31, bot, topt, topu, t;

    x21 = x2-x1; x34 = x3-x4;
    y21 = y2-y1; y34 = y3-y4;
    bot = x21*y34 - y21*x34;
    if (bot >= 0)
    {
        if (bot == 0) return(0);
        x31 = x3-x1; y31 = y3-y1;
        topt = x31*y34 - y31*x34; if ((topt < 0) || (topt >= bot)) return(0);
        topu = x21*y31 - y21*x31; if ((topu < 0) || (topu >= bot)) return(0);
    }
    else
    {
        x31 = x3-x1; y31 = y3-y1;
        topt = x31*y34 - y31*x34; if ((topt > 0) || (topt <= bot)) return(0);
        topu = x21*y31 - y21*x31; if ((topu > 0) || (topu <= bot)) return(0);
    }
    t = divscale24(topt, bot);
    *intx = x1 + mulscale24(x21, t);
    *inty = y1 + mulscale24(y21, t);
    *intz = z1 + mulscale24(z2-z1, t);
    return(1);
}

/*8002FBF0*/
static s32 rIntersect(s32 x1, s32 y1, s32 z1, s32 vx, s32 vy, s32 vz, s32 x3,
                      s32 y3, s32 x4, s32 y4, s32 *intx, s32 *inty, s32 *intz)
{     //p1 towards p2 is a ray
    s32 x34, y34, x31, y31, bot, topt, topu, t;

    x34 = x3-x4; y34 = y3-y4;
    bot = vx*y34 - vy*x34;
    if (bot >= 0)
    {
        if (bot == 0) return(0);
        x31 = x3-x1; y31 = y3-y1;
        topt = x31*y34 - y31*x34; if (topt < 0) return(0);
        topu = vx*y31 - vy*x31; if ((topu < 0) || (topu >= bot)) return(0);
    }
    else
    {
        x31 = x3-x1; y31 = y3-y1;
        topt = x31*y34 - y31*x34; if (topt > 0) return(0);
        topu = vx*y31 - vy*x31; if ((topu > 0) || (topu <= bot)) return(0);
    }
    t = divscale16(topt, bot);
    *intx = x1 + mulscale16(vx, t);
    *inty = y1 + mulscale16(vy, t);
    *intz = z1 + mulscale16(vz, t);
    return(1);
}

/*8002FE24*/
void dragPoint(s16 pointhighlight, s32 dax, s32 day)
{
    s16 cnt, tempshort;

    gpWall[pointhighlight].x = dax;
    gpWall[pointhighlight].y = day;

    cnt = MAXWALLS;
    tempshort = pointhighlight;    //search points CCW
    do
    {
        if (gpWall[tempshort].nextwall >= 0)
        {
            tempshort = gpWall[gpWall[tempshort].nextwall].point2;
            gpWall[tempshort].x = dax;
            gpWall[tempshort].y = day;
        }
        else
        {
            tempshort = pointhighlight;    //search points CW if not searched all the way around
            do
            {
                if (gpWall[lastWall(tempshort)].nextwall >= 0)
                {
                    tempshort = gpWall[lastWall(tempshort)].nextwall;
                    gpWall[tempshort].x = dax;
                    gpWall[tempshort].y = day;
                }
                else
                {
                    break;
                }
                cnt--;
            } while ((tempshort != pointhighlight) && (cnt > 0));
            break;
        }
        cnt--;
    } while ((tempshort != pointhighlight) && (cnt > 0));
}

/*8002FFDC*/
static s16 lastWall(s16 point)
{
    s32 i, j, cnt;

    if ((point > 0) && (gpWall[point-1].point2 == point)) return(point-1);
    i = point;
    cnt = MAXWALLS;
    do
    {
        j = gpWall[i].point2;
        if (j == point) return(i);
        i = j;
        cnt--;
    } while (cnt > 0);
    return(point);
}

#define addclipline(dax1, day1, dax2, day2, daoval)             \
{                                                               \
	_clipIt[_clipNum].x1 = dax1; _clipIt[_clipNum].y1 = day1;   \
	_clipIt[_clipNum].x2 = dax2; _clipIt[_clipNum].y2 = day2;   \
	_clipObjectVal[_clipNum] = daoval;                          \
	_clipNum++;                                                 \
}                                                               

/*80030070*/
s32 clipMove(s32 *x, s32 *y, s32 *z, s16 *sectnum, s32 xvect,
             s32 yvect, s32 walldist, s32 ceildist, s32 flordist, u32 cliptype)
{
    ModelInfo *ptr;
    WallType *wal, *wal2;
    SpriteType *spr;
    SectorType *sec, *sec2;
    long i, j, templong1, templong2;
    long oxvect, oyvect, goalx, goaly, intx, inty, lx, ly, retval;
    long k, l, clipsectcnt, startwall, endwall, cstat, dasect;
    long x1, y1, x2, y2, cx, cy, rad, xmin, ymin, xmax, ymax, daz, daz2;
    long bsz, dax, day, xoff, yoff, xspan, yspan, cosang, sinang, tilenum;
    long xrepeat, yrepeat, gx, gy, dx, dy, dasprclipmask, dawalclipmask;
    long hitwall, cnt, clipyou;
    s32 x1_, x2_, x3_, x4_, x5_;
    s32 y1_, y2_, y3_, y4_, y5_;
    s32 a, b, c, d, e, f;
    s16 daang, m;

    if (((xvect | yvect) == 0) || (*sectnum < 0))
        return 0;

    retval = 0;
    oxvect = xvect;
    oyvect = yvect;

    goalx = *x + (xvect >> 14);
    goaly = *y + (yvect >> 14);

    _clipNum = 0;

    cx = (*x + goalx) >> 1;
    cy = (*y + goaly) >> 1;

    gx = goalx - *x;
    gy = goaly - *y;

    rad = nsqrtasm(gx*gx + gy*gy) + MAXCLIPDIST + walldist + 8;
    xmin = cx - rad;
    ymin = cy - rad;
    xmax = cx + rad;
    ymax = cy + rad;

    dawalclipmask = cliptype & 0xFFFF;
    dasprclipmask = cliptype >> 0x10;

    _clipSectorList[0] = *sectnum;
    clipsectcnt = 0;
    _clipSectNum = 1;

    m = gHeadSpriteStat[305];
    if (m >= 0)
    {
        _clipSectNum = 2;
        _clipSectorList[1] = gpSprite[m].sectnum;
    }

    if (gMapNum == MAP_DAWN_OF_THE_DUKE)
    {
        m = gHeadSpriteStat[302];
        while (m >= 0)
        {
            if ((gpSprite[m].picnum >= 2310) && (gpSprite[m].picnum < 2315))
            {
                _clipSectorList[_clipSectNum++] = gpSprite[m].sectnum;
                break;
            }
            m = gNextSpriteStat[m];
        }
    }

    do
    {
        dasect = _clipSectorList[clipsectcnt++];
        sec = &gpSector[dasect];
        startwall = sec->wallptr;
        endwall = startwall + sec->wallnum;

        for (j = startwall, wal = &gpWall[startwall]; j < endwall; j++, wal++)
        {
            wal2 = &gpWall[wal->point2];

            if ((wal->x < xmin) && (wal2->x < xmin)) continue;
            if ((wal->x > xmax) && (wal2->x > xmax)) continue;
            if ((wal->y < ymin) && (wal2->y < ymin)) continue;
            if ((wal->y > ymax) && (wal2->y > ymax)) continue;

            x1 = wal->x; y1 = wal->y; x2 = wal2->x; y2 = wal2->y;

            dx = x2-x1; dy = y2-y1;
            if (dx*((*y)-y1) < ((*x)-x1)*dy) continue;  //If wall's not facing you

            if (dx > 0) dax = dx*(ymin-y1); else dax = dx*(ymax-y1);
            if (dy > 0) day = dy*(xmax-x1); else day = dy*(xmin-x1);
            if (dax >= day) continue;

            clipyou = 0;
            if ((wal->nextsector < 0) || (wal->cstat&dawalclipmask)) clipyou = 1;
            else if (_editStatus == 0)
            {
                if (rIntersect(*x, *y, 0, gx, gy, 0, x1, y1, x2, y2, &dax, &day, &daz) == 0)
                    dax = *x, day = *y;
                daz = getFlorzOfSlope((s16)dasect, dax, day);
                daz2 = getFlorzOfSlope(wal->nextsector, dax, day);

                if (daz2 < daz-(1<<8))
                {
                    if ((*z) >= daz2-(flordist-1)) clipyou = 1;
                }

                if (clipyou == 0)
                {
                    daz = getCeilzOfSlope((s16)dasect, dax, day);
                    daz2 = getCeilzOfSlope(wal->nextsector, dax, day);
                    if (daz2 > daz+(1<<8))
                    {
                        if ((*z) <= daz2+(ceildist-1)) clipyou = 1;
                    }
                }
            }

            if (clipyou)
            {
                //Add 2 boxes at endpoints
                bsz = walldist; if (gx < 0) bsz = -bsz;
                addclipline(x1-bsz, y1-bsz, x1-bsz, y1+bsz, (s16)j+32768);
                addclipline(x2-bsz, y2-bsz, x2-bsz, y2+bsz, (s16)j+32768);
                bsz = walldist; if (gy < 0) bsz = -bsz;
                addclipline(x1+bsz, y1-bsz, x1-bsz, y1-bsz, (s16)j+32768);
                addclipline(x2+bsz, y2-bsz, x2-bsz, y2-bsz, (s16)j+32768);

                dax = walldist; if (dy > 0) dax = -dax;
                day = walldist; if (dx < 0) day = -day;
                addclipline(x1+dax, y1+day, x2+dax, y2+day, (s16)j+32768);
            }
            else
            {
                for (i = _clipSectNum-1; i>=0; i--)
                {
                    if (wal->nextsector == _clipSectorList[i]) break;
                }
                if (i < 0) _clipSectorList[_clipSectNum++] = wal->nextsector;
            }
        }

        for (j = gHeadSpriteSect[dasect]; j >= 0; j = gNextSpriteSect[j])
        {
            spr = &gpSprite[j];
            cstat = spr->cstat;

            if ((cstat&dasprclipmask) == 0)
                continue;

            x1 = spr->x;
            y1 = spr->y;
            if (cstat & 0x1000)
            {
                ptr = D_800D52E0[spr->picnum-1280];
                if (ptr != NULL)
                {
                    a = (ptr->unk28 * (spr->yrepeat << 6)) / 64;
                    daz = spr->z - a;
                    b = (ptr->unk2E * (spr->yrepeat << 6)) / 64;
                    daz += ceildist;
                    daz2 = spr->z - b;
                    daz2 -= flordist;

                    if ((*z < daz) && (daz2 < *z))
                    {
                        c = (ptr->unk24 * (spr->xrepeat << 2)) / 64;
                        x1_ = (spr->x + c) - walldist;
                        d = (ptr->unk2A * (spr->xrepeat << 2)) / 64;
                        x3_ = spr->x + d + walldist;
                        e = (ptr->unk26 * (spr->xrepeat << 2)) / 64;
                        y1_ = (spr->y - e) + walldist;
                        f = (ptr->unk2C * (spr->xrepeat << 2)) / 64;
                        y3_ = (spr->y - f) - walldist;

                        x2_ = x3_;
                        y2_ = y1_;
                        x4_ = x1_;
                        y4_ = y3_;

                        if ((spr->statnum != 1) & (spr->statnum != 10))
                        {
                            daang = (spr->ang + 0x600) & 0x7FF;
                            rotatePoint(spr->x, spr->y, x1_, y1_, daang, &x5_, &y5_);
                            x1_ = x5_;
                            y1_ = y5_;
                            rotatePoint(spr->x, spr->y, x3_, y2_, daang, &x5_, &y5_);
                            x2_ = x5_;
                            y2_ = y5_;
                            rotatePoint(spr->x, spr->y, x3_, y4_, daang, &x5_, &y5_);
                            x3_ = x5_;
                            y3_ = y5_;
                            rotatePoint(spr->x, spr->y, x4_, y4_, daang, &x5_, &y5_);
                            x4_ = x5_;
                            y4_ = y5_;
                        }

                        addclipline(x1_, y1_, x2_, y2_, (s16)j+0xC000);
                        addclipline(x2_, y2_, x3_, y3_, (s16)j+0xC000);
                        addclipline(x3_, y3_, x4_, y4_, (s16)j+0xC000);
                        addclipline(x4_, y4_, x1_, y1_, (s16)j+0xC000);
                    }
                }
            }
            else
            {
                switch (cstat & 0x30)
                {
                case 0:
                case 48:
                    if ((x1 >= xmin) && (x1 <= xmax) && (y1 >= ymin) && (y1 <= ymax))
                    {
                        k = ((getTileSizeY(spr->picnum)*spr->yrepeat)<<2);
                        if (cstat&128) daz = spr->z+(k>>1); else daz = spr->z;

                        if (getTilePicanm(spr->picnum)&0x00ff0000)
                            daz -= ((s32)((s8)((getTilePicanm(spr->picnum)>>16)&255))*spr->yrepeat<<2);

                        if (((*z) < daz+ceildist) && ((*z) > daz-k-flordist))
                        {
                            bsz = (spr->clipdist<<2)+walldist; if (gx < 0) bsz = -bsz;
                            addclipline(x1-bsz, y1-bsz, x1-bsz, y1+bsz, (s16)j+49152);
                            bsz = (spr->clipdist<<2)+walldist; if (gy < 0) bsz = -bsz;
                            addclipline(x1+bsz, y1-bsz, x1-bsz, y1-bsz, (s16)j+49152);
                        }
                    }
                    break;
                case 16:
                    k = ((getTileSizeY(spr->picnum)*spr->yrepeat)<<2);
                    if (cstat&128) daz = spr->z+(k>>1); else daz = spr->z;

                    if (getTilePicanm(spr->picnum)&0x00ff0000)
                        daz -= ((s32)((s8)((getTilePicanm(spr->picnum)>>16)&255))*spr->yrepeat<<2);

                    daz2 = daz-k;
                    daz += ceildist; daz2 -= flordist;
                    if (((*z) < daz) && ((*z) > daz2))
                    {
                        //These lines get the 2 points of the rotated sprite
                        //Given: (x1, y1) starts out as the center point
                        tilenum = spr->picnum;
                        xoff = (s32)((s8)((getTilePicanm(tilenum)>>8)&255));
                        if ((cstat&4) > 0) xoff = -xoff;
                        k = spr->ang; l = spr->xrepeat;
                        dax = gpSinTable[k&2047]*l; day = gpSinTable[(k+1536)&2047]*l;
                        l = getTileSizeX(tilenum); k = (l>>1)+xoff;
                        x1 -= mulscale16(dax, k); x2 = x1+mulscale16(dax, l);
                        y1 -= mulscale16(day, k); y2 = y1+mulscale16(day, l);
                        if (clipInsideBoxLine(cx, cy, x1, y1, x2, y2, rad) != 0)
                        {
                            dax = mulscale14(gpSinTable[(spr->ang+256+512)&2047], walldist);
                            day = mulscale14(gpSinTable[(spr->ang+256)&2047], walldist);

                            if ((x1-(*x))*(y2-(*y)) >= (x2-(*x))*(y1-(*y)))   //Front
                            {
                                addclipline(x1+dax, y1+day, x2+day, y2-dax, (s16)j+49152);
                            }
                            else
                            {
                                if ((cstat&64) != 0) continue;
                                addclipline(x2-dax, y2-day, x1-day, y1+dax, (s16)j+49152);
                            }

                            //Side blocker
                            if ((x2-x1)*((*x)-x1) + (y2-y1)*((*y)-y1) < 0)
                            {
                                addclipline(x1-day, y1+dax, x1+dax, y1+day, (s16)j+49152);
                            }
                            else if ((x1-x2)*((*x)-x2) + (y1-y2)*((*y)-y2) < 0)
                            {
                                addclipline(x2+day, y2-dax, x2-dax, y2-day, (s16)j+49152);
                            }
                        }
                    }
                    break;
                case 32:
                    daz = spr->z+ceildist;
                    daz2 = spr->z-flordist;
                    if (((*z) < daz) && ((*z) > daz2))
                    {
                        if ((cstat&64) != 0)
                        {
                            if (((*z) > spr->z) == ((cstat&8)==0))
                                continue;
                        }

                        tilenum = spr->picnum;
                        xoff = (s32)((s8)((getTilePicanm(tilenum)>>8)&255));
                        yoff = (s32)((s8)((getTilePicanm(tilenum)>>16)&255));
                        if ((cstat&4) > 0) xoff = -xoff;
                        if ((cstat&8) > 0) yoff = -yoff;

                        k = spr->ang;
                        cosang = gpSinTable[(k+512)&2047]; sinang = gpSinTable[k];
                        xspan = getTileSizeX(tilenum); xrepeat = spr->xrepeat;
                        yspan = getTileSizeY(tilenum); yrepeat = spr->yrepeat;

                        dax = ((xspan>>1)+xoff)*xrepeat; day = ((yspan>>1)+yoff)*yrepeat;
                        _rxi[0] = x1 + dmulscale16(sinang, dax, cosang, day);
                        _ryi[0] = y1 + dmulscale16(sinang, day, -cosang, dax);
                        l = xspan*xrepeat;
                        _rxi[1] = _rxi[0] - mulscale16(sinang, l);
                        _ryi[1] = _ryi[0] + mulscale16(cosang, l);
                        l = yspan*yrepeat;
                        k = -mulscale16(cosang, l); _rxi[2] = _rxi[1]+k; _rxi[3] = _rxi[0]+k;
                        k = -mulscale16(sinang, l); _ryi[2] = _ryi[1]+k; _ryi[3] = _ryi[0]+k;

                        dax = mulscale14(gpSinTable[(spr->ang-256+512)&2047], walldist);
                        day = mulscale14(gpSinTable[(spr->ang-256)&2047], walldist);

                        if ((_rxi[0]-(*x))*(_ryi[1]-(*y)) < (_rxi[1]-(*x))*(_ryi[0]-(*y)))
                        {
                            if (clipInsideBoxLine(cx, cy, _rxi[1], _ryi[1], _rxi[0], _ryi[0], rad) != 0)
                                addclipline(_rxi[1]-day, _ryi[1]+dax, _rxi[0]+dax, _ryi[0]+day, (s16)j+49152);
                        }
                        else if ((_rxi[2]-(*x))*(_ryi[3]-(*y)) < (_rxi[3]-(*x))*(_ryi[2]-(*y)))
                        {
                            if (clipInsideBoxLine(cx, cy, _rxi[3], _ryi[3], _rxi[2], _ryi[2], rad) != 0)
                                addclipline(_rxi[3]+day, _ryi[3]-dax, _rxi[2]-dax, _ryi[2]-day, (s16)j+49152);
                        }

                        if ((_rxi[1]-(*x))*(_ryi[2]-(*y)) < (_rxi[2]-(*x))*(_ryi[1]-(*y)))
                        {
                            if (clipInsideBoxLine(cx, cy, _rxi[2], _ryi[2], _rxi[1], _ryi[1], rad) != 0)
                                addclipline(_rxi[2]-dax, _ryi[2]-day, _rxi[1]-day, _ryi[1]+dax, (s16)j+49152);
                        }
                        else if ((_rxi[3]-(*x))*(_ryi[0]-(*y)) < (_rxi[0]-(*x))*(_ryi[3]-(*y)))
                        {
                            if (clipInsideBoxLine(cx, cy, _rxi[0], _ryi[0], _rxi[3], _ryi[3], rad) != 0)
                                addclipline(_rxi[0]+dax, _ryi[0]+day, _rxi[3]+day, _ryi[3]-dax, (s16)j+49152);
                        }
                    }
                    break;
                }
            }
        }
    } while (clipsectcnt < _clipSectNum);

    hitwall = 0;
    cnt = _clipMoveBoxTraceNum;
    do
    {
        intx = goalx; inty = goaly;
        if ((hitwall = rayTrace(*x, *y, &intx, &inty)) >= 0)
        {
            lx = _clipIt[hitwall].x2-_clipIt[hitwall].x1;
            ly = _clipIt[hitwall].y2-_clipIt[hitwall].y1;
            templong2 = lx*lx + ly*ly;
            if (templong2 > 0)
            {
                templong1 = (goalx-intx)*lx + (goaly-inty)*ly;

                if ((klabs(templong1)>>11) < templong2)
                    i = divscale20(templong1, templong2);
                else
                    i = 0;
                goalx = mulscale20(lx, i)+intx;
                goaly = mulscale20(ly, i)+inty;
            }

            templong1 = dmulscale6(lx, oxvect, ly, oyvect);
            for (i = cnt+1; i <= _clipMoveBoxTraceNum; i++)
            {
                j = _hitWalls[i];
                templong2 = dmulscale6(_clipIt[j].x2-_clipIt[j].x1, oxvect, _clipIt[j].y2-_clipIt[j].y1, oyvect);
                if ((templong1^templong2) < 0)
                {
                    updateSector(*x, *y, sectnum);
                    return retval;
                }
            }

            keepAway(&goalx, &goaly, hitwall);
            xvect = ((goalx-intx)<<14);
            yvect = ((goaly-inty)<<14);

            if (cnt == _clipMoveBoxTraceNum) retval = _clipObjectVal[hitwall];
            _hitWalls[cnt] = hitwall;
        }
        cnt--;

        *x = intx;
        *y = inty;
    } while (((xvect|yvect) != 0) && (hitwall >= 0) && (cnt > 0));

    for (j = 0; j < _clipSectNum; j++)
    {
        if (inside(*x, *y, _clipSectorList[j]) == 1)
        {
            *sectnum = _clipSectorList[j];
            return retval;
        }
    }

    *sectnum = -1; templong1 = 0x7fffffff;
    for (j = gNumSectors-1; j >= 0; j--)
    {
        if (inside(*x, *y, j) == 1)
        {
            if (gpSector[j].ceilingstat&2)
                templong2 = (getCeilzOfSlope((s16)j, *x, *y)-(*z));
            else
                templong2 = (gpSector[j].ceilingz-(*z));

            if (templong2 > 0)
            {
                if (templong2 < templong1)
                {
                    *sectnum = j; templong1 = templong2;
                }
            }
            else
            {
                if (gpSector[j].floorstat&2)
                    templong2 = ((*z)-getFlorzOfSlope((s16)j, *x, *y));
                else
                    templong2 = ((*z)-gpSector[j].floorz);

                if (templong2 <= 0)
                {
                    *sectnum = j;
                    return retval;
                }
                if (templong2 < templong1)
                {
                    *sectnum = j; templong1 = templong2;
                }
            }
        }
    }

    return retval;
}

/*80032410*/
static void keepAway(s32 *x, s32 *y, s32 w)
{
    s32 dx, dy, ox, oy, x1, y1;
    u8 first;

    x1 = _clipIt[w].x1; dx = _clipIt[w].x2-x1;
    y1 = _clipIt[w].y1; dy = _clipIt[w].y2-y1;
    ox = ksgn(-dy); oy = ksgn(dx);
    first = (klabs(dx) <= klabs(dy));
    while (1)
    {
        if (dx*(*y-y1) > (*x-x1)*dy) return;
        if (first == 0) *x += ox; else *y += oy;
        first ^= 1;
    }
}

/*80032538*/
static s32 rayTrace(s32 x3, s32 y3, s32 *x4, s32 *y4)
{
    s32 x1, y1, x2, y2, t, bot, topu, nintx, ninty, cnt, z, hitwall;
    s32 x21, y21, x43, y43;

    hitwall = -1;
    for (z = _clipNum-1; z>=0; z--)
    {
        x1 = _clipIt[z].x1; x2 = _clipIt[z].x2; x21 = x2-x1;
        y1 = _clipIt[z].y1; y2 = _clipIt[z].y2; y21 = y2-y1;

        topu = x21*(y3-y1) - (x3-x1)*y21; if (topu <= 0) continue;
        if (x21*(*y4-y1) > (*x4-x1)*y21) continue;
        x43 = *x4-x3; y43 = *y4-y3;
        if (x43*(y1-y3) > (x1-x3)*y43) continue;
        if (x43*(y2-y3) <= (x2-x3)*y43) continue;
        bot = x43*y21 - x21*y43; if (bot == 0) continue;

        cnt = 256;
        do
        {
            cnt--; if (cnt < 0) { *x4 = x3; *y4 = y3; return(z); }
            nintx = x3 + scale(x43, topu, bot);
            ninty = y3 + scale(y43, topu, bot);
            topu--;
        } while (x21*(ninty-y1) <= (nintx-x1)*y21);

        if (klabs(x3-nintx)+klabs(y3-ninty) < klabs(x3-*x4)+klabs(y3-*y4))
        {
            *x4 = nintx; *y4 = ninty; hitwall = z;
        }
    }
    return(hitwall);
}

/*8003283C*/
s32 pushMove(s32 *x, s32 *y, s32 *z, s16 *sectnum,
             s32 walldist, s32 ceildist, s32 flordist, u32 cliptype)
{
    SectorType *sec, *sec2;
    WallType *wal, *wal2;
    SpriteType *spr;
    s32 i, j, k, t, dx, dy, dax, day, daz, daz2, bad, dir;
    s32 dasprclipmask, dawalclipmask;
    s16 startwall, endwall, clipsectcnt;
    char bad2;

    if ((*sectnum) < 0) return(-1);

    dawalclipmask = (cliptype&65535);
    dasprclipmask = (cliptype>>16);

    k = 32;
    dir = 1;
    do
    {
        bad = 0;

        _clipSectorList[0] = *sectnum;
        clipsectcnt = 0; _clipSectNum = 1;
        do
        {
            /*Push FACE sprites
            for(i=headspritesect[clipsectorlist[clipsectcnt]];i>=0;i=nextspritesect[i])
            {
                spr = &sprite[i];
                if (((spr->cstat&48) != 0) && ((spr->cstat&48) != 48)) continue;
                if ((spr->cstat&dasprclipmask) == 0) continue;

                dax = (*x)-spr->x; day = (*y)-spr->y;
                t = (spr->clipdist<<2)+walldist;
                if ((klabs(dax) < t) && (klabs(day) < t))
                {
                    t = ((tilesizy[spr->picnum]*spr->yrepeat)<<2);
                    if (spr->cstat&128) daz = spr->z+(t>>1); else daz = spr->z;
                    if (picanm[spr->picnum]&0x00ff0000) daz -= ((s32)((s8)((picanm[spr->picnum]>>16)&255))*spr->yrepeat<<2);
                    if (((*z) < daz+ceildist) && ((*z) > daz-t-flordist))
                    {
                        t = (spr->clipdist<<2)+walldist;

                        j = getangle(dax,day);
                        dx = (sintable[(j+512)&2047]>>11);
                        dy = (sintable[(j)&2047]>>11);
                        bad2 = 16;
                        do
                        {
                            *x = (*x) + dx; *y = (*y) + dy;
                            bad2--; if (bad2 == 0) break;
                        } while ((klabs((*x)-spr->x) < t) && (klabs((*y)-spr->y) < t));
                        bad = -1;
                        k--; if (k <= 0) return(bad);
                        updatesector(*x,*y,sectnum);
                    }
                }
            }*/

            sec = &gpSector[_clipSectorList[clipsectcnt]];
            if (dir > 0)
                startwall = sec->wallptr, endwall = startwall + sec->wallnum;
            else
                endwall = sec->wallptr, startwall = endwall + sec->wallnum;

            for (i = startwall, wal = &gpWall[startwall]; i!=endwall; i += dir, wal += dir)
                if (clipInsideBox(*x, *y, i, walldist-4) == 1)
                {
                    j = 0;
                    if (wal->nextsector < 0) j = 1;
                    if (wal->cstat&dawalclipmask) j = 1;
                    if (j == 0)
                    {
                        sec2 = &gpSector[wal->nextsector];


                        //Find closest point on wall (dax, day) to (*x, *y)
                        dax = gpWall[wal->point2].x-wal->x;
                        day = gpWall[wal->point2].y-wal->y;
                        daz = dax*((*x)-wal->x) + day*((*y)-wal->y);
                        if (daz <= 0)
                            t = 0;
                        else
                        {
                            daz2 = dax*dax+day*day;
                            if (daz >= daz2) t = (1<<30); else t = divscale30(daz, daz2);
                        }
                        dax = wal->x + mulscale30(dax, t);
                        day = wal->y + mulscale30(day, t);


                        daz = getFlorzOfSlope(_clipSectorList[clipsectcnt], dax, day);
                        daz2 = getFlorzOfSlope(wal->nextsector, dax, day);
                        if ((daz2 < daz-(1<<8)) && ((sec2->floorstat&1) == 0))
                            if (*z >= daz2-(flordist-1)) j = 1;

                        daz = getCeilzOfSlope(_clipSectorList[clipsectcnt], dax, day);
                        daz2 = getCeilzOfSlope(wal->nextsector, dax, day);
                        if ((daz2 > daz+(1<<8)) && ((sec2->ceilingstat&1) == 0))
                            if (*z <= daz2+(ceildist-1)) j = 1;
                    }
                    if (j != 0)
                    {
                        j = getAngle(gpWall[wal->point2].x-wal->x, gpWall[wal->point2].y-wal->y);
                        dx = (gpSinTable[(j+1024)&2047]>>11);
                        dy = (gpSinTable[(j+512)&2047]>>11);
                        bad2 = 16;
                        do
                        {
                            *x = (*x) + dx; *y = (*y) + dy;
                            bad2--; if (bad2 == 0) break;
                        } while (clipInsideBox(*x, *y, i, walldist-4) != 0);
                        bad = -1;
                        k--; if (k <= 0) return(bad);
                        updateSector(*x, *y, sectnum);
                    }
                    else
                    {
                        for (j = _clipSectNum-1; j>=0; j--)
                            if (wal->nextsector == _clipSectorList[j]) break;
                        if (j < 0) _clipSectorList[_clipSectNum++] = wal->nextsector;
                    }
                }

            clipsectcnt++;
        } while (clipsectcnt < _clipSectNum);
        dir = -dir;
    } while (bad != 0);

    return(bad);
}

/*80032DF8*/
void updateSector(s32 x, s32 y, s16 *sectnum)
{
    WallType *wal;
    s32 i, j;

    if (inside(x, y, *sectnum) == 1) return;

    if ((*sectnum >= 0) && (*sectnum < gNumSectors))
    {
        wal = &gpWall[gpSector[*sectnum].wallptr];
        j = gpSector[*sectnum].wallnum;
        do
        {
            i = wal->nextsector;
            if (i >= 0)
                if (inside(x, y, (s16)i) == 1)
                {
                    *sectnum = i;
                    return;
                }
            wal++;
            j--;
        } while (j != 0);
    }

    for (i = gNumSectors-1; i>=0; i--)
        if (inside(x, y, (s16)i) == 1)
        {
            *sectnum = i;
            return;
        }

    *sectnum = -1;
}

/*80032F38*/
static u8 engine_80032F38(s32 x, s32 y, s32 z, s16 sectnum)
{
    s32 ceilz;
    s32 florz;
    s16 fz;

    fz = ((gpSector[sectnum].unk18 == 1) ? 0x2600 : 0) + 8;
    if (gpSector[sectnum].unk18 == 4)
    {
        fz += 0x1000;
    }
    if (gpSector[sectnum].unk18 == 5)
    {
        fz += 0x2600;
    }
    if (gpSector[sectnum].unk18 == 6)
    {
        fz += 0x1000;
    }
    getzsOfSlope(sectnum, x, y, &ceilz, &florz);
    if ((z > (florz + fz)) || (z < (ceilz - 8)))
        return 0;
    else
        return inside(x, y, sectnum);
}

/*80033044*/
void updateSectorZ(s32 x, s32 y, s32 z, s16 *sectnum)
{
    WallType *wal;
    s32 i, j, cz, fz;

    if (engine_80032F38(x, y, z, *sectnum) == 1)
        return;

    if ((*sectnum >= 0) && (*sectnum < gNumSectors))
    {
        wal = &gpWall[gpSector[*sectnum].wallptr];
        j = gpSector[*sectnum].wallnum;
        do
        {
            i = wal->nextsector;
            if (i >= 0)
            {
                if (engine_80032F38(x, y, z, i) == 1)
                {
                    *sectnum = i;
                    return;
                }
            }
            wal++; j--;
        } while (j != 0);
    }

    for (i = gNumSectors-1; i>=0; i--)
    {
        if (engine_80032F38(x, y, z, i) == 1)
        {
            *sectnum = i;
            return;
        }
    }

    *sectnum = -1;
}

/*800331A4*/
void rotatePoint(s32 xpivot, s32 ypivot, s32 x, s32 y, s16 daang, s32 *x2, s32 *y2)
{
    s32 dacos, dasin;

    dacos = gpSinTable[(daang+2560)&2047];
    dasin = gpSinTable[(daang+2048)&2047];
    x -= xpivot;
    y -= ypivot;
    *x2 = dmulscale14(x, dacos, -y, dasin) + xpivot;
    *y2 = dmulscale14(y, dacos, x, dasin) + ypivot;
}

/*800332E8*/
s32 krand(void)
{
    gRandomSeed = (gRandomSeed*27584621)+1;
    return(((u32)gRandomSeed)>>16);
}

/*8003331C*/
void getzRange(s32 x, s32 y, s32 z, s16 sectnum, s32 *ceilz, s32 *ceilhit, s32 *florz, s32 *florhit, s32 walldist, u32 cliptype)
{
    ModelInfo *ptr;
    SectorType *sec;
    WallType *wall, *wal2;
    SpriteType *spr;
    s32 clipsectcnt, startwall, endwall, tilenum, xoff, yoff, dax, day;
    s32 xmin, ymin, xmax, ymax, i, j, k, l, daz, daz2, dx, dy;
    s32 x1, y1, x2, y2, x3, y3, x4, y4, ang, cosang, sinang;
    s32 xspan, yspan, xrepeat, yrepeat, dasprclipmask, dawalclipmask;
    s16 cstat;
    u8 clipyou;
    s16 m;
    s32 n, o, p, q, r, s, t, u;

    if (sectnum < 0)
    {
        *ceilz = 0x80000000;
        *ceilhit = -1;
        *florz = 0x7FFFFFFF;
        *florhit = -1;
        return;
    }

    i = walldist + MAXCLIPDIST+1;
    getzsOfSlope(sectnum, x, y, ceilz, florz);
    *ceilhit = sectnum + 0x4000;
    *florhit = sectnum + 0x4000;
    xmin = x - i;
    ymin = y - i;
    xmax = x + i;
    ymax = y + i;

    dawalclipmask = cliptype & 0xFFFF;
    dasprclipmask = cliptype >> 0x10;

    _clipSectorList[0] = sectnum;
    _clipSectNum = 1;
    clipsectcnt = 0;

    m = gHeadSpriteStat[305];
    if (m >= 0)
    {
        _clipSectNum = 2;
        _clipSectorList[1] = gpSprite[m].sectnum;
    }

    if (gMapNum == MAP_DAWN_OF_THE_DUKE)
    {
        m = gHeadSpriteStat[302];
        while (m >= 0)
        {
            if ((gpSprite[m].picnum >= 2310) && (gpSprite[m].picnum < 2315))
            {
                _clipSectorList[_clipSectNum++] = gpSprite[m].sectnum;
                break;
            }
            m = gNextSpriteStat[m];
        }
    }

    do
    {
        sec = &gpSector[_clipSectorList[clipsectcnt]];
        startwall = sec->wallptr;
        endwall = startwall + sec->wallnum;
        for (j = startwall, wall = &gpWall[startwall]; j < endwall; j++, wall++)
        {
            k = wall->nextsector;
            if (k >= 0)
            {
                wal2 = &gpWall[wall->point2];
                x1 = wall->x; x2 = wal2->x;
                if ((x1 < xmin) && (x2 < xmin)) continue;
                if ((x1 > xmax) && (x2 > xmax)) continue;
                y1 = wall->y; y2 = wal2->y;
                if ((y1 < ymin) && (y2 < ymin)) continue;
                if ((y1 > ymax) && (y2 > ymax)) continue;

                dx = x2-x1; dy = y2-y1;
                if (dx*(y-y1) < (x-x1)*dy) continue; //back
                if (dx > 0) dax = dx*(ymin-y1); else dax = dx*(ymax-y1);
                if (dy > 0) day = dy*(xmax-x1); else day = dy*(xmin-x1);
                if (dax >= day) continue;

                if (wall->cstat&dawalclipmask) continue;

                sec = &gpSector[k];
                if (_editStatus == 0)
                {
                    if (z <= sec->ceilingz+(3<<8)) continue;
                    if (z >= sec->floorz-(3<<8)) continue;
                }

                for (i = _clipSectNum-1; i>=0; i--)
                {
                    if (_clipSectorList[i] == k)
                        break;
                }

                if (i < 0)
                    _clipSectorList[_clipSectNum++] = k;

                if ((x1 < xmin+MAXCLIPDIST) && (x2 < xmin+MAXCLIPDIST)) continue;
                if ((x1 > xmax-MAXCLIPDIST) && (x2 > xmax-MAXCLIPDIST)) continue;
                if ((y1 < ymin+MAXCLIPDIST) && (y2 < ymin+MAXCLIPDIST)) continue;
                if ((y1 > ymax-MAXCLIPDIST) && (y2 > ymax-MAXCLIPDIST)) continue;
                if (dx > 0) dax += dx*MAXCLIPDIST; else dax -= dx*MAXCLIPDIST;
                if (dy > 0) day -= dy*MAXCLIPDIST; else day += dy*MAXCLIPDIST;
                if (dax >= day) continue;

                getzsOfSlope(k, x, y, &daz, &daz2);

                if (daz > *ceilz)
                {
                    *ceilz = daz;
                    *ceilhit = k+16384;
                }

                if (daz2 < *florz)
                {
                    *florz = daz2;
                    *florhit = k+16384;
                }
            }
        }
        clipsectcnt++;
    } while (clipsectcnt < _clipSectNum);


    for (i = 0; i<_clipSectNum; i++)
    {
        for (j = gHeadSpriteSect[_clipSectorList[i]]; j>=0; j = gNextSpriteSect[j])
        {
            spr = &gpSprite[j];

            if ((D_800DD448 != 0) && (spr->statnum == 1)) continue;
            if ((D_800DD448 != 0) && (spr->statnum == 10)) continue;
            if ((D_800DD448 != 0) && (spr->statnum == 52)) continue;
            if ((D_800DD448 != 0) && (spr->statnum == 305)) continue;

            if (spr->picnum == 1295) continue;
            if (spr->picnum == 1688) continue;

            cstat = spr->cstat;
            if (cstat & dasprclipmask)
            {
                x1 = spr->x;
                y1 = spr->y;
                clipyou = 0;
                if (cstat & 0x1000)
                {
                    ptr = D_800D52E0[spr->picnum-1280];
                    if (ptr != NULL)
                    {
                        s32 x_[4];
                        s32 y_[4];

                        n = (ptr->unk24 * (spr->xrepeat << 2)) / 64;
                        x_[0] = (x1 + n) - 164;
                        q = (ptr->unk2A * (spr->xrepeat << 2)) / 64;
                        x_[2] = spr->x + q + 164;
                        r = (ptr->unk26 * (spr->xrepeat << 2)) / 64;
                        y_[0] = (spr->y - r) + 164;
                        o = ptr->unk2C * (spr->xrepeat << 2) / 64;
                        y_[2] = (spr->y - o) - 164;

                        x_[1] = x_[2];
                        y_[1] = y_[0];
                        x_[3] = x_[0];
                        y_[3] = y_[2];

                        if ((spr->statnum != 1) & (spr->statnum != 0xA))
                        {
                            rotatePoint(spr->x, spr->y, x_[0], y_[0], ((spr->ang + 0x600) & 0x7FF), &t, &u);
                            x_[0] = t; y_[0] = u;
                            rotatePoint(spr->x, spr->y, x_[1], y_[1], ((spr->ang + 0x600) & 0x7FF), &t, &u);
                            x_[1] = t; y_[1] = u;
                            rotatePoint(spr->x, spr->y, x_[2], y_[2], ((spr->ang + 0x600) & 0x7FF), &t, &u);
                            x_[2] = t; y_[2] = u;
                            rotatePoint(spr->x, spr->y, x_[3], y_[3], ((spr->ang + 0x600) & 0x7FF), &t, &u);
                            x_[3] = t; y_[3] = u;
                        }
                        s = (ptr->unk28 * (spr->yrepeat << 6)) / 64;
                        daz = spr->z - s;
                        p = (ptr->unk2E * (spr->yrepeat << 6)) / 64;
                        daz2 = spr->z - p;

                        for (k = 0; k < 4; k++)
                        {
                            x_[k] -= x;
                            y_[k] -= y;
                        }

                        if ((y_[0]^y_[1]) < 0)
                        {
                            if ((x_[0]^x_[1]) < 0) clipyou ^= (x_[0]*y_[1]<x_[1]*y_[0])^(y_[0]<y_[1]);
                            else if (x_[0] >= 0) clipyou ^= 1;
                        }
                        if ((y_[1]^y_[2]) < 0)
                        {
                            if ((x_[1]^x_[2]) < 0) clipyou ^= (x_[1]*y_[2]<x_[2]*y_[1])^(y_[1]<y_[2]);
                            else if (x_[1] >= 0) clipyou ^= 1;
                        }
                        if ((y_[2]^y_[3]) < 0)
                        {
                            if ((x_[2]^x_[3]) < 0) clipyou ^= (x_[2]*y_[3]<x_[3]*y_[2])^(y_[2]<y_[3]);
                            else if (x_[2] >= 0) clipyou ^= 1;
                        }
                        if ((y_[3]^y_[0]) < 0)
                        {
                            if ((x_[3]^x_[0]) < 0) clipyou ^= (x_[3]*y_[0]<x_[0]*y_[3])^(y_[3]<y_[0]);
                            else if (x_[3] >= 0) clipyou ^= 1;
                        }
                    }
                }
                else
                {
                    switch (cstat & 0x30)
                    {
                    case 0:
                    case 48:
                        k = walldist + (spr->clipdist * 4) + 1;
                        if ((klabs(x1-x) <= k) && (klabs(y1-y) <= k))
                        {
                            daz = spr->z;
                            k = (getTileSizeY(spr->picnum) * spr->yrepeat) << 1;
                            if (cstat&128) daz += k;
                            if (getTilePicanm(spr->picnum) & 0x00FF0000)
                                daz -= ((s32)((s8)((getTilePicanm(spr->picnum)>>16)&255))*spr->yrepeat<<2);
                            daz2 = daz-(k<<1);
                            clipyou = 1;
                        }
                        break;
                    case 16:
                        tilenum = spr->picnum;
                        xoff = (s32)((s8)((getTilePicanm(tilenum)>>8)&255));
                        if ((cstat & 4) > 0) xoff = -xoff;

                        k = spr->ang;
                        l = spr->xrepeat;
                        dax = gpSinTable[k & 0x7FF] * l;
                        day = gpSinTable[(k + 0x600) & 0x7FF] * l;
                        l = getTileSizeX(tilenum);
                        k = (l>>1) + xoff;
                        x1 -= mulscale16(dax, k);
                        x2 = x1 + mulscale16(dax, l);
                        y1 -= mulscale16(day, k);
                        y2 = y1 + mulscale16(day, l);
                        if (clipInsideBoxLine(x, y, x1, y1, x2, y2, walldist + 1) != 0)
                        {
                            daz = spr->z;
                            k = (getTileSizeY(spr->picnum) * spr->yrepeat) << 1;
                            if (cstat&128) daz += k;
                            if (getTilePicanm(spr->picnum) & 0x00FF0000)
                                daz -= ((s32)((s8)((getTilePicanm(spr->picnum)>>16)&255))*spr->yrepeat<<2);
                            daz2 = daz-(k<<1);
                            clipyou = 1;
                        }
                        break;
                    case 32:
                        daz = spr->z;
                        daz2 = daz;

                        if ((cstat&64) != 0)
                            if ((z > daz) == ((cstat&8)==0))
                                continue;

                        tilenum = spr->picnum;
                        xoff = (s32)((s8)((getTilePicanm(tilenum)>>8)&255));
                        yoff = (s32)((s8)((getTilePicanm(tilenum)>>16)&255));

                        if ((cstat & 4) > 0) xoff = -xoff;
                        if ((cstat & 8) > 0) yoff = -yoff;

                        ang = spr->ang;
                        cosang = gpSinTable[(ang + 0x200) & 0x7FF];
                        sinang = gpSinTable[ang];

                        xspan = getTileSizeX(tilenum);
                        xrepeat = spr->xrepeat;
                        yspan = getTileSizeY(tilenum);
                        yrepeat = spr->yrepeat;

                        dax = ((xspan >> 1) + xoff) * xrepeat;
                        day = ((yspan >> 1) + yoff) * yrepeat;
                        x1 += (dmulscale16(sinang, dax, cosang, day) - x);
                        y1 += (dmulscale16(sinang, day, -cosang, dax) - y);
                        l = xspan * xrepeat;
                        x2 = x1 - mulscale16(sinang, l);
                        y2 = y1 + mulscale16(cosang, l);
                        l = yspan * yrepeat;
                        k = -mulscale16(cosang, l); x3 = x2+k; x4 = x1+k;
                        k = -mulscale16(sinang, l); y3 = y2+k; y4 = y1+k;

                        dax = mulscale14(gpSinTable[(spr->ang-256+512)&2047], walldist+4);
                        day = mulscale14(gpSinTable[(spr->ang-256)&2047], walldist+4);
                        x1 += dax; x2 -= day; x3 -= dax; x4 += day;
                        y1 += day; y2 += dax; y3 -= day; y4 -= dax;

                        if ((y1^y2) < 0)
                        {
                            if ((x1^x2) < 0) clipyou ^= (x1*y2<x2*y1)^(y1<y2);
                            else if (x1 >= 0) clipyou ^= 1;
                        }
                        if ((y2^y3) < 0)
                        {
                            if ((x2^x3) < 0) clipyou ^= (x2*y3<x3*y2)^(y2<y3);
                            else if (x2 >= 0) clipyou ^= 1;
                        }
                        if ((y3^y4) < 0)
                        {
                            if ((x3^x4) < 0) clipyou ^= (x3*y4<x4*y3)^(y3<y4);
                            else if (x3 >= 0) clipyou ^= 1;
                        }
                        if ((y4^y1) < 0)
                        {
                            if ((x4^x1) < 0) clipyou ^= (x4*y1<x1*y4)^(y4<y1);
                            else if (x4 >= 0) clipyou ^= 1;
                        }

                        break;
                    }
                }

                if (clipyou != 0)
                {
                    if ((daz < z) && (*ceilz < daz))
                    {
                        *ceilz = daz;
                        *ceilhit = j + 0xC000;
                    }
                    if ((z < daz2) && (daz2 < *florz))
                    {
                        *florz = daz2;
                        *florhit = j + 0xC000;
                    }
                }
            }
        }
    }
}

/*800348F8*/
s32 getCeilzOfSlope(s16 sectnum, s32 dax, s32 day)
{
    s32 dx, dy, i, j;
    WallType *wal;

    if (!(gpSector[sectnum].ceilingstat&2)) return(gpSector[sectnum].ceilingz);
    wal = &gpWall[gpSector[sectnum].wallptr];
    dx = gpWall[wal->point2].x-wal->x; dy = gpWall[wal->point2].y-wal->y;
    i = (nsqrtasm(dx*dx+dy*dy)<<5); if (i == 0) return(gpSector[sectnum].ceilingz);
    j = dmulscale3(dx, day-wal->y, -dy, dax-wal->x);
    return(gpSector[sectnum].ceilingz+scale(gpSector[sectnum].ceilingheinum, j, i));
}

/*80034A94*/
s32 getFlorzOfSlope(s16 sectnum, s32 dax, s32 day)
{
    s32 dx, dy, i, j;
    WallType *wal;

    if (!(gpSector[sectnum].floorstat&2)) return(gpSector[sectnum].floorz);
    wal = &gpWall[gpSector[sectnum].wallptr];
    dx = gpWall[wal->point2].x-wal->x; dy = gpWall[wal->point2].y-wal->y;
    i = (nsqrtasm(dx*dx+dy*dy)<<5); if (i == 0) return(gpSector[sectnum].floorz);
    j = dmulscale3(dx, day-wal->y, -dy, dax-wal->x);
    return(gpSector[sectnum].floorz+scale(gpSector[sectnum].floorheinum, j, i));
}

/*80034C30*/
void getzsOfSlope(s16 sectnum, s32 dax, s32 day, s32 *ceilz, s32 *florz)
{
    s32 dx, dy, i, j;
    WallType *wal, *wal2;
    SectorType *sec;

    sec = &gpSector[sectnum];
    *ceilz = sec->ceilingz; *florz = sec->floorz;
    if ((sec->ceilingstat|sec->floorstat)&2)
    {
        wal = &gpWall[sec->wallptr]; wal2 = &gpWall[wal->point2];
        dx = wal2->x-wal->x; dy = wal2->y-wal->y;
        i = (nsqrtasm(dx*dx+dy*dy)<<5); if (i == 0) return;
        j = dmulscale3(dx, day-wal->y, -dy, dax-wal->x);
        if (sec->ceilingstat&2) *ceilz = (*ceilz)+scale(sec->ceilingheinum, j, i);
        if (sec->floorstat&2) *florz = (*florz)+scale(sec->floorheinum, j, i);
    }
}

/*0x80034E00*/
void alignFlorSlope(s16 dasect, s32 x, s32 y, s32 z)
{
    s32 i, dax, day;
    WallType *wal;

    wal = &gpWall[gpSector[dasect].wallptr];
    dax = gpWall[wal->point2].x-wal->x;
    day = gpWall[wal->point2].y-wal->y;

    i = (y-wal->y)*dax - (x-wal->x)*day; if (i == 0) return;
    gpSector[dasect].floorheinum = scale((z-gpSector[dasect].floorz)<<8,
                                                  nsqrtasm(dax*dax+day*day), i);

    if (gpSector[dasect].floorheinum == 0) gpSector[dasect].floorstat &= ~2;
    else gpSector[dasect].floorstat |= 2;
}

/*0x80034F54*/
void alignCeilSlope(s16 dasect, s32 x, s32 y, s32 z)
{
    s32 i, dax, day;
    WallType *wal;

    wal = &gpWall[gpSector[dasect].wallptr];
    dax = gpWall[wal->point2].x-wal->x;
    day = gpWall[wal->point2].y-wal->y;

    i = (y-wal->y)*dax - (x-wal->x)*day; if (i == 0) return;
    gpSector[dasect].ceilingheinum = scale((z-gpSector[dasect].ceilingz)<<8,
                                                     nsqrtasm(dax*dax+day*day), i);

    if (gpSector[dasect].ceilingheinum == 0) gpSector[dasect].ceilingstat &= ~2;
    else gpSector[dasect].ceilingstat |= 2;
}

/*800350A8*/
s32 findDistance2D(s32 dx, s32 dy)
{
    return sqrtf(((f32)dx * (f32)dx) + ((f32)dy * (f32)dy));
}

/*80035110*/
s32 findDistance3D(s32 dx, s32 dy, s32 dz)
{
    return sqrtf(((f32)dx * (f32)dx) + ((f32)dy * (f32)dy) + ((f32)dz * (f32)dz));
}
