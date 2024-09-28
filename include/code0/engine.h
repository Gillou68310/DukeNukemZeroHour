#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "common.h"

#define MAXPLAYERS 4

#define MAXSECTORS 657
#define MAXWALLS 3912
#define MAXSPRITES 1500

#define MAXTILES 6144
#define MAXSTATUS 1024

//ceilingstat/floorstat:
//   bit 0: 1 = parallaxing, 0 = not                                 "P"
//   bit 1: 1 = groudraw, 0 = not
//   bit 2: 1 = swap x&y, 0 = not                                    "F"
//   bit 3: 1 = double smooshiness                                   "E"
//   bit 4: 1 = x-flip                                               "F"
//   bit 5: 1 = y-flip                                               "F"
//   bit 6: 1 = Align texture to first wall of sector                "R"
//   bits 7-8:                                                       "T"
//          00 = normal floors
//          01 = masked floors
//          10 = transluscent masked floors
//          11 = reverse transluscent masked floors
//   bits 9-15: reserved
typedef struct
{
    /*0x00*/ s32 ceilingz;
    /*0x04*/ s32 floorz;
    /*0x08*/ s16 wallptr;
    /*0x0A*/ s16 wallnum;
    /*0x0C*/ s16 ceilingstat;
    /*0x0E*/ s16 floorstat;
    /*0x10*/ s16 ceilingpicnum;
    /*0x12*/ s16 ceilingheinum;
    /*0x14*/ s16 floorpicnum;
    /*0x16*/ s16 floorheinum;
    /*0x18*/ s16 unk18; /*lotag?*/
    /*0x1A*/ s16 unk1A; /*hitag?*/
    /*0x1C*/ s16 unk1C; /*extra?*/
    /*0x1E*/ u16 floorvtxptr;
    /*0x20*/ u16 ceilingvtxptr;
    /*0x22*/ u8 ceilingshade;
    /*0x23*/ u8 ceilingpal;
    /*0x24*/ u8 pad[2];
    /*0x26*/ u8 floorshade;
    /*0x27*/ u8 floorpal;
    /*0x28*/ u8 pad2[2];
    /*0x2A*/ u8 unk2A;
    /*0x2B*/ u8 floorvtxnum;
    /*0x2C*/ u8 ceilingvtxnum;
    /*0x2D*/ u8 pad3[3];
} SectorType;

//cstat:
//   bit 0: 1 = Blocking wall (use with clipmove, getzrange)         "B"
//   bit 1: 1 = bottoms of invisible walls swapped, 0 = not          "2"
//   bit 2: 1 = align picture on bottom (for doors), 0 = top         "O"
//   bit 3: 1 = x-flipped, 0 = normal                                "F"
//   bit 4: 1 = masking wall, 0 = not                                "M"
//   bit 5: 1 = 1-way wall, 0 = not                                  "1"
//   bit 6: 1 = Blocking wall (use with hitscan / cliptype 1)        "H"
//   bit 7: 1 = Transluscence, 0 = not                               "T"
//   bit 8: 1 = y-flipped, 0 = normal                                "F"
//   bit 9: 1 = Transluscence reversing, 0 = normal                  "T"
//   bits 10-15: reserved

typedef struct
{
    /*0x00*/ s32 x;
    /*0x04*/ s32 y;
    /*0x08*/ s16 point2;
    /*0x0A*/ s16 nextwall;
    /*0x0C*/ s16 nextsector;
    /*0x0E*/ s16 cstat;
    /*0x10*/ s16 picnum;
    /*0x12*/ s16 overpicnum;
    /*0x14*/ s16 unk14; /*lotag?*/
    /*0x16*/ s16 unk16; /*hitag?*/
    /*0x18*/ s16 unk18; /*extra?*/
    /*0x1A*/ u16 sectnum;
    /*0x1C*/ u8 shade;
    /*0x1D*/ u8 unk1D;
    /*0x1E*/ u8 unk1E;
    /*0x1F*/ u8 unk1F;
    /*0x20*/ u8 unk20;
    /*0x21*/ u8 pal;
    /*0x22*/ u8 xrepeat;
    /*0x23*/ u8 yrepeat;
    /*0x24*/ u8 xpanning;
    /*0x25*/ u8 ypanning;
    /*0x26*/ u8 pad3[2];
} WallType;

//cstat:
//   bit 0: 1 = Blocking sprite (use with clipmove, getzrange)       "B"
//   bit 1: 1 = transluscence, 0 = normal                            "T"
//   bit 2: 1 = x-flipped, 0 = normal                                "F"
//   bit 3: 1 = y-flipped, 0 = normal                                "F"
//   bits 5-4: 00 = FACE sprite (default)                            "R"
//             01 = WALL sprite (like masked walls)
//             10 = FLOOR sprite (parallel to ceilings&floors)
//   bit 6: 1 = 1-sided sprite, 0 = normal                           "1"
//   bit 7: 1 = Real centered centering, 0 = foot center             "C"
//   bit 8: 1 = Blocking sprite (use with hitscan / cliptype 1)      "H"
//   bit 9: 1 = Transluscence reversing, 0 = normal                  "T"
//   bits 10-14: reserved
//   bit 15: 1 = Invisible sprite, 0 = not invisible

typedef struct
{
    /*0x00*/ s32 x;
    /*0x04*/ s32 y;
    /*0x08*/ s32 z;
    /*0x0C*/ s16 cstat;
    /*0x0E*/ s16 picnum;
    /*0x10*/ s16 sectnum;
    /*0x12*/ s16 statnum;
    /*0x14*/ s16 ang;
    /*0x16*/ s16 unk16; /*owner?*/
    /*0x18*/ s16 unk18; /*xvel?*/
    /*0x1A*/ s16 unk1A; /*yvel?*/
    /*0x1C*/ s16 unk1C; /*zvel?*/
    /*0x1E*/ s16 lotag;
    /*0x20*/ s16 hitag;
    /*0x22*/ s16 unk22; /*extra?*/
    /*0x24*/ u8 unk24;
    /*0x25*/ u8 unk25;
    /*0x26*/ u8 clipdist;
    /*0x27*/ u8 xrepeat;
    /*0x28*/ u8 yrepeat;
    /*0x29*/ u8 unk29;
    /*0x2A*/ u8 unk2A;
    /*0x2B*/ u8 unk2B;
} SpriteType;

/*clipinsidebox(long x, long y, short wallnum, long walldist)
    Returns TRUE only if the given line (wallnum) intersects the square with
    center (x,y) and radius, walldist.*/
s32 clipInsideBox(s32 x, s32 y, s16 wallnum, s32 walldist);

/*getangle(long xvect, long yvect)
    Gets the angle of a vector (xvect,yvect)
    These are 2048 possible angles starting from the right, going clockwise*/
s32 getAngle(s32 xvect, s32 yvect);

/*setsprite(short spritenum, long newx, long newy, long newz);
    This function simply sets the sprite's position to a specified
    coordinate (newx, newy, newz) without any checking to see
    whether the position is valid or not.  You could directly
    modify the sprite[].x, sprite[].y, and sprite[].z values, but
    if you use my function, the sprite is guaranteed to be in the
    right sector.*/
s32 setSprite(s16 spritenum, s32 newx, s32 newy, s32 newz);

/*insertsprite(short sectnum, short statnum);   //returns (short)spritenum;
    Whenever you insert a sprite, you must pass it the sector
    number, and a status number (statnum).  The status number can be any
    number from 0 to MAXSTATUS-1.  Insertsprite works like a memory
    allocation function and returns the sprite number.*/

s16 insertSprite(s16 sectnum, s16 statnum);

/*deletesprite(short spritenum);
    Deletes the sprite.*/
s32 deleteSprite(s16 spritenum);

/*changespritesect(short spritenum, short newsectnum);
    Changes the sector of sprite (spritenum) to the
    newsector (newsectnum).  This function may become
    internal to the engine in the movesprite function.  But
    this function is necessary since all the sectors have
    their own doubly-linked lists of sprites.*/
s32 changeSpriteSect(s16 spritenum, s16 newsectnum);

/*changespritestat(short spritenum, short newstatnum);
    Changes the status of sprite (spritenum) to status
    (newstatus).  Newstatus can be any number from 0 to MAXSTATUS-1.
    You can use this function to put a monster on a list of active sprites
    when it first sees you.*/
s32 changeSpriteStat(s16 spritenum, s16 newstatnum);

/*nextsectorneighborz(short sectnum, long thez, short topbottom, short direction)
    This function is used to tell where elevators should stop.  It searches
    nearby sectors for the next closest ceilingz or floorz it should stop at.
    sectnum - elevator sector
    thez - current z to start search from
    topbottom - search ceilingz's/floorz's only
    direction - search upwards/downwards*/
s32 nextSectorNeighborZ(s16 sectnum, s32 thez, s16 topbottom, s16 direction);

/*cansee(long x1, long y1, long z1, short sectnum1,
         long x2, long y2, long z2, short sectnum2);  returns 0 or 1
    This function determines whether or not two 3D points can "see" each
    other or not.  All you do is pass it the coordinates of a 3D line defined
    by two 3D points (with their respective sectors)  The function will return
    a 1 if the points can see each other or a 0 if there is something blocking
    the two points from seeing each other.  This is how I determine whether a
    monster can see you or not. Try playing DOOM1.DAT to fully enjoy this
    great function!*/
s32 canSee(s32 x1, s32 y1, s32 z1, s16 sect1, s32 x2, s32 y2, s32 z2, s16 sect2);

/*hitscan(long xstart, long ystart, long zstart, short startsectnum,
          long vectorx, long vectory, long vectorz,
          short *hitsect, short *hitwall, short *hitsprite,
          long *hitx, long *hity, long *hitz);

    Pass the starting 3D position:
          (xstart, ystart, zstart, startsectnum)
    Then pass the 3D angle to shoot (defined as a 3D vector):
          (vectorx, vectory, vectorz)
    Then set up the return values for the object hit:
          (hitsect, hitwall, hitsprite)
    and the exact 3D point where the ray hits:
          (hitx, hity, hitz)

    How to determine what was hit:
        * Hitsect is always equal to the sector that was hit (always >= 0).

        * If the ray hits a sprite then:
              hitsect = thesectornumber
              hitsprite = thespritenumber
              hitwall = -1

         * If the ray hits a wall then:
              hitsect = thesectornumber
              hitsprite = -1
              hitwall = thewallnumber

         * If the ray hits the ceiling of a sector then:
              hitsect = thesectornumber
              hitsprite = -1
              hitwall = -1
              vectorz < 0
              (If vectorz < 0 then you're shooting upward which means
                  that you couldn't have hit a floor)

         * If the ray hits the floor of a sector then:
              hitsect = thesectornumber
              hitsprite = -1
              hitwall = -1
              vectorz > 0
              (If vectorz > 0 then you're shooting downard which means
                  that you couldn't have hit a ceiling)*/
s32 hitScan(s32 xs, s32 ys, s32 zs, s16 sectnum, s32 vx, s32 vy, s32 vz,
            s16 *hitsect, s16 *hitwall, s16 *hitsprite,
            s32 *hitx, s32 *hity, s32 *hitz, u32 cliptype);

/*neartag(long x, long y, long z, short sectnum, short ang,  //Starting position & angle
          short *neartagsector,   //Returns near sector if sector[].tag != 0
          short *neartagwall,     //Returns near wall if wall[].tag != 0
          short *neartagsprite,   //Returns near sprite if sprite[].tag != 0
          long *neartaghitdist,   //Returns actual distance to object (scale: 1024=largest grid size)
          long neartagrange,      //Choose maximum distance to scan (scale: 1024=largest grid size)
          char tagsearch)         //1-lotag only, 2-hitag only, 3-lotag&hitag
    Neartag works sort of like hitscan, but is optimized to
    scan only close objects and scan only objects with
    tags != 0.  Neartag is perfect for the first line of your space bar code.
    It will tell you what door you want to open or what switch you want to
    flip.*/
s32 nearTag(s32 xs, s32 ys, s32 zs, s16 sectnum, s16 ange, s16 *neartagsector,
            s16 *neartagwall, s16 *neartagsprite, s32 *neartaghitdist,
            s32 neartagrange, u8 tagsearch);

/*dragpoint(short wallnum, long newx, long newy);
    This function will drag a point in the exact same way a point is dragged
    in 2D EDIT MODE using the left mouse button.  Simply pass it which wall
    to drag and then pass the new x and y coordinates for that point.
    Please use this function because if you don't and try to drag points
    yourself, I can guarantee that it won't work as well as mine and you
    will get confused.  Note:  Every wall of course has 2 points.  When you
    pass a wall number to this function, you are actually passing 1 point,
    the left side of the wall (given that you are in the sector of that wall)
    Got it?*/
void dragPoint(s16 pointhighlight, s32 dax, s32 day);

/*clipmove(long *x, long *y, long *z, short *sectnum, long xvect, long yvect,
            long walldist, long ceildist, long flordist, char cliptype)
    Moves any object (x, y, z) in any direction at any velocity and will
    make sure the object will stay a certain distance from walls (walldist)
    Pass the pointers of the starting position (x, y, z).  Then
    pass the starting position's sector number as a pointer also.
    Also these values will be modified accordingly.  Pass the
    direction and velocity by using a vector (xvect, yvect).
    If you don't fully understand these equations, please call me.
        xvect = velocity * cos(angle)
        yvect = velocity * sin(angle)
    Walldist tells how close the object can get to a wall.  I use
    128L as my default.  If you increase walldist all of a sudden
    for a certain object, the object might leak through a wall, so
    don't do that!
    f cliptype is 0, then the clipping is normal (Use 0 to clip you
    and monsters).  If the cliptype is 1, then the object is clipped to
    the same things that hitscan is clipped to (use 1 for all bullets).

    Clipmove can either return 0 (touched nothing)
                               32768+wallnum (wall first touched)
                               49152+spritenum (sprite first touched)*/
s32 clipMove(s32 *x, s32 *y, s32 *z, s16 *sectnum,
             s32 xvect, s32 yvect,
             s32 walldist, s32 ceildist, s32 flordist, u32 cliptype);

/*pushmove (long *x, long *y, long *z, short *sectnum,
             long walldist, long ceildist, long flordist, unsigned long cliptype)
    This function makes sure a player or monster (defined by x, y, z, sectnum)
    is not too close to a wall.  If it is, then it attempts to push it away.
    If after 256 tries, it is unable to push it away, it returns -1, in which
    case the thing should gib.*/
s32 pushMove(s32 *x, s32 *y, s32 *z, s16 *sectnum,
             s32 walldist, s32 ceildist, s32 flordist, u32 cliptype);

/*updatesector(long x, long y, &sectnum);
    This function updates the sector number according to the x and y values
    passed to it.  Be careful when you use this function with sprites because
    remember that the sprite's sector number should not be modified directly.
    If you want to update a sprite's sector, I recomment using the setsprite
    function described below.*/
void updateSector(s32 x, s32 y, s16 *sectnum);
void updateSectorZ(s32 x, s32 y, s32 z, s16 *sectnum);

/*rotatepoint(long xpivot, long ypivot, long x, long y,
                short daang, long *x2, long *y2);
    This function is a very convenient and fast math helper function.
    Rotate points easily with this function without having to juggle your
    cosines and sines.  Simply pass it:

         Input:   1. Pivot point     (xpivot,ypivot)
                     2. Original point  (x,y)
                     3. Angle to rotate (0 = nothing, 512 = 90° CW, etc.)
         Output:  4. Rotated point   (*x2,*y2)*/
void rotatePoint(s32 xpivot, s32 ypivot, s32 x, s32 y, s16 daang, s32 *x2, s32 *y2);

/*krand()
    Random number function - returns numbers from 0-65535*/
s32 krand(void);

/*getzrange(long x, long y, long z, short sectnum,
                        long *ceilz, long *ceilhit,
                        long *florz, long *florhit,
                        long walldist, unsigned long cliptype)

    Use this in conjunction with clipmove.  This function will keep the
    player from falling off cliffs when you're too close to the edge.  This
    function finds the highest and lowest z coordinates that your clipping
    BOX can get to.  It must search for all sectors (and sprites) that go
    into your clipping box.  This method is better than using
    sector[cursectnum].ceilingz and sector[cursectnum].floorz because this
    searches the whole clipping box for objects, not just 1 point.
    Pass x, y, z, sector normally.  Walldist can be 128.  Cliptype is
    defined the same way as it is for clipmove.  This function returns the
    z extents in ceilz and florz. It will return the object hit in ceilhit
    and florhit.  Ceilhit and florhit will also be either:
                                            16384+sector (sector first touched) or
                                            49152+spritenum (sprite first touched)*/
void getzRange(s32 x, s32 y, s32 z, s16 sectnum,
               s32 *ceilz, s32 *ceilhit, s32 *florz, s32 *florhit,
               s32 walldist, u32 cliptype);

/*getceilzofslope(short sectnum, long x, long y)
getflorzofslope(short sectnum, long x, long y)
getzsofslope(short sectnum, long x, long y, long *ceilz, long *florz)
    These 3 functions get the height of a ceiling and/or floor in a sector
    at any (x,y) location.  Use getzsofslope only if you need both the ceiling
    and floor.*/
s32 getCeilzOfSlope(s16 sectnum, s32 dax, s32 day);
s32 getFlorzOfSlope(s16 sectnum, s32 dax, s32 day);
void getzsOfSlope(s16 sectnum, s32 dax, s32 day, s32 *ceilz, s32 *florz);

/*alignceilslope(short sectnum, long x, long y, long z)
alignflorslope(short sectnum, long x, long y, long z)
    Given a sector and assuming it's first wall is the pivot wall of the slope,
    this function makes the slope pass through the x,y,z point.  One use of
    this function is used for sin-wave floors.*/
void alignFlorSlope(s16 dasect, s32 x, s32 y, s32 z);
void alignCeilSlope(s16 dasect, s32 x, s32 y, s32 z);

s32 findDistance2D(s32 dx, s32 dy);
s32 findDistance3D(s32 dx, s32 dy, s32 dz);
s32 animateOffs(s16 tilenum, s16 fakevar);
void initSpriteLists(void);
void engine_8002B680(void);

extern s16 gHeadSpriteSect[MAXSECTORS+1];
extern s16 gHeadSpriteStat[MAXSTATUS+1];
extern s16 gNextSpriteSect[MAXSPRITES];
extern s16 gNextSpriteStat[MAXSPRITES];
extern s16 *gpRadaRang;
extern s16 gNumSectors;
extern s16 gNumSprites;
extern s16 gNumWalls;
extern s32 gRandomSeed;
extern SpriteType *gpSprite;
extern SectorType *gpSector;
extern s32 gTotalClockLock;
extern s16 *gpSinTable;
extern WallType *gpWall;
extern s32 D_801AC9F4;
extern u8 D_800DD448;

#endif
