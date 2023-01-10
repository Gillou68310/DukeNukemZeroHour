#include "common.h"
#include "code0/pragmas.h"
#include "code0/engine.h"
#include "code0/35D90.h"

#define klabs(A) (((A) > 0) ? (A) : -(A))

#define MAXCLIPNUM 512
#define MAXCLIPDIST 1024

typedef struct { long x1, y1, x2, y2; } LineType;

/*.data*/
/*800DD440*/ EXTERN_DATA STATIC s16 _editstatus;

/*.bss*/
/*800F70A0*/ EXTERN_BSS STATIC s16 D_800F70A0;
/*800F70A2*/ EXTERN_BSS STATIC s16 _clipnum;
/*800F70B0*/ EXTERN_BSS STATIC LineType _clipit[MAXCLIPNUM];
/*800F90B0*/ EXTERN_BSS STATIC s16 _clipsectorlist[MAXCLIPNUM];
/*800F94B0*/ EXTERN_BSS STATIC s16 _clipsectnum;

/*.comm*/
/*800FE420*/ s16 gHeadSpriteSect[MAXSECTORS+1] ALIGNED(16);
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
/*80197DE0*/ s32 gTotalClockLock;
/*80199950*/ s32 D_80199950;
/*801A197C*/ s16 *gpSinTable;
/*801A2624*/ s32 D_801A2624;
/*801A2830*/ WallType *gpWall;
/*801AC9F4*/ s32 D_801AC9F4;

/*.text*/

static s32 insertSpriteStat(s16 statnum);
static s32 insertSpriteSect(s16 sectnum);
static s16 lastWall(s16 point);

/*8002B680*/
void func_8002B680(void)
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
    func_80033044(newx, newy, newz, &tempsectnum);
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
INCLUDE_ASM(s32, "src/code0/engine", insertSprite);

/*8002C0A8*/
static s32 insertSpriteSect(s16 sectnum)
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
static s32 insertSpriteStat(s16 statnum)
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
INCLUDE_ASM(s32, "src/code0/engine", deleteSprite);

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

    _clipsectorlist[0] = sect1; danum = 1;
    for (dacnt = 0; dacnt<danum; dacnt++)
    {
        dasectnum = _clipsectorlist[dacnt]; sec = &gpSector[dasectnum];
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

            for (i = danum-1; i>=0; i--) if (_clipsectorlist[i] == nexts) break;
            if (i < 0) _clipsectorlist[danum++] = nexts;
        }
    }
    for (i = danum-1; i>=0; i--) if (_clipsectorlist[i] == sect2) return(1);
    return(0);
}

/*8002CBEC*/
INCLUDE_ASM(s32, "src/code0/engine", hitScan);

/*8002F1B4*/
INCLUDE_ASM(s32, "src/code0/engine", nearTag);

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

/*80030070*/
INCLUDE_ASM(s32, "src/code0/engine", clipMove);

/*80032410*/
static void keepAway(s32 *x, s32 *y, s32 w)
{
    s32 dx, dy, ox, oy, x1, y1;
    u8 first;

    x1 = _clipit[w].x1; dx = _clipit[w].x2-x1;
    y1 = _clipit[w].y1; dy = _clipit[w].y2-y1;
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
STATIC s32 rayTrace(s32 x3, s32 y3, s32 *x4, s32 *y4);
INCLUDE_ASM(s32, "src/code0/engine", rayTrace);

/*8003283C*/
INCLUDE_ASM(s32, "src/code0/engine", pushMove);

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

INCLUDE_ASM(s32, "src/code0/engine", func_80032F38);

INCLUDE_ASM(s32, "src/code0/engine", func_80033044);

/*800331A4*/
s32 rotatePoint(s32 xpivot, s32 ypivot, s32 x, s32 y, s16 daang, s32 *x2, s32 *y2)
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
INCLUDE_ASM(s32, "src/code0/engine", getzRange);

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

INCLUDE_ASM(s32, "src/code0/engine", func_800350A8);

INCLUDE_ASM(s32, "src/code0/engine", func_80035110);
