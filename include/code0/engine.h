#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "common.h"

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
    /*0x10*/ s16 unk10; //ceilingpicnum?
    /*0x12*/ s16 ceilingheinum;

    /*0x14*/ s16 unk14; //floorpicnum?
    /*0x16*/ s16 floorheinum;

    /*0x16*/ s16 unk18;
    /*0x1A*/ s16 unk1A;
    /*0x1C*/ s16 unk1C;
    /*0x1E*/ u16 vtxptr;
    /*0x20*/ u8 pad[6];
    /*0x26*/ u8 unk26;
    /*0x27*/ u8 unk27;
    /*0x28*/ u8 pad2[3];
    /*0x2B*/ u8 unk2B;  //vtxnum?
    /*0x2C*/ u8 unk2C;
    /*0x2D*/ u8 pad3[3];

    //signed char ceilingshade;
    //char ceilingpal;
    //char ceilingxpanning;
    //char ceilingypanning;
    //signed char floorshade;
    //char floorpal;
    //char floorxpanning;
    //char floorypanning;
    //char visibility;
    //char filler;
    //s16 lotag;
    //s16 hitag;
    //s16 extra;
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

    /*0x10*/ u8 pad[22];

    //s16 picnum;
    //s16 overpicnum;
    //s8 shade;
    //char pal;
    //char xrepeat;
    //char yrepeat;
    //char xpanning;
    //char ypanning;
    //s16 lotag;
    //s16 hitag;
    //s16 extra;
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

    /*0x16*/ u8 pad[16];
    /*0x26*/ u8 clipdist;
    /*0x27*/ u8 xrepeat;
    /*0x28*/ u8 yrepeat;
    /*0x28*/ u8 pad1[3];

    //s8 shade;
    //char pal;
    //char clipdist;
    //char filler;
    //s8 xoffset;
    //s8 yoffset;
    //s16 owner;
    //s16 xvel;
    //s16 yvel;
    //s16 zvel;
    //s16 lotag
    //s16 hitag;
    //s16 extra;
} SpriteType;

typedef struct {
    s16 ob[3];	/* x, y, z */
    s16 tc[2];	/* texture coord */
    u8	cn[4];	/* color & alpha */
} VertexV;

typedef struct {
    s16 ob[3];	/* x, y, z */
    s16 tc[2];	/* texture coord */
    s8  n[3];	/* normal */
    u8  a;      /* alpha  */
} VertexN;

typedef union {
    VertexV v;  /* Use this one for colors  */
    VertexN n;  /* Use this one for normals */
} VertexType;

void func_8002B680(void);
s32 clipInsideBox(s32 x, s32 y, s16 wallnum, s32 walldist);
s32 getAngle(s32 xvect, s32 yvect);
s32 setSprite(s16 spritenum, s32 newx, s32 newy, s32 newz);
s32 animateOffs(s16 tileid, s16 fakevar);
void initSpriteLists(void);
s32 insertSprite(s16 sectnum, s16 statnum);
s32 deleteSprite(s16 spritenum);
s32 changeSpriteSect(s16 spritenum, s16 newsectnum);
s32 changeSpriteStat(s16 spritenum, s16 newstatnum);
s32 nextSectorNeighborZ(s16 sectnum, s32 thez, s16 topbottom, s16 direction);
s32 canSee(s32 x1, s32 y1, s32 z1, s16 sect1, s32 x2, s32 y2, s32 z2, s16 sect2);
s32 hitScan(s32 xs, s32 ys, s32 zs, s16 sectnum, s32 vx, s32 vy, s32 vz,
            s16 *hitsect, s16 *hitwall, s16 *hitsprite,
            s32 *hitx, s32 *hity, s32 *hitz, u32 cliptype);
s32 nearTag(s32 xs, s32 ys, s32 zs, s16 sectnum, s16 ange, s16 *neartagsector,
            s16 *neartagwall, s16 *neartagsprite, s32 *neartaghitdist,
            s32 neartagrange, u8 tagsearch);
void dragPoint(s16 pointhighlight, s32 dax, s32 day);
s32 clipMove(s32 *x, s32 *y, s32 *z, s16 *sectnum,
             s32 xvect, s32 yvect,
             s32 walldist, s32 ceildist, s32 flordist, u32 cliptype);
s32 pushMove(s32 *x, s32 *y, s32 *z, s16 *sectnum,
             s32 walldist, s32 ceildist, s32 flordist, u32 cliptype);
void updateSector(s32 x, s32 y, s16 *sectnum);
void updateSectorZ(s32 x, s32 y, s32 z, s16 *sectnum);
s32 rotatePoint(s32 xpivot, s32 ypivot, s32 x, s32 y, s16 daang, s32 *x2, s32 *y2);
s32 krand(void);

void getzRange(s32 x, s32 y, s32 z, s16 sectnum,
               s32 *ceilz, s32 *ceilhit, s32 *florz, s32 *florhit,
               s32 walldist, u32 cliptype);
s32 getCeilzOfSlope(s16 sectnum, s32 dax, s32 day);
s32 getFlorzOfSlope(s16 sectnum, s32 dax, s32 day);
void getzsOfSlope(s16 sectnum, s32 dax, s32 day, s32 *ceilz, s32 *florz);
void alignFlorSlope(s16 dasect, s32 x, s32 y, s32 z);
void alignCeilSlope(s16 dasect, s32 x, s32 y, s32 z);
s32 findDistance2D(s32 dx, s32 dy);
s32 findDistance3D(s32 dx, s32 dy, s32 dz);

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

#endif
