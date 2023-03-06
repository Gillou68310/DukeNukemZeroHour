#include "common.h"
#include "code0/main.h"
#include "code0/9410.h"

/*.text*/

/*80035190*/
s16 getTileSizeX(u16 tileid)
{
    if ((getTileNum(tileid)) != 1)
        return gpTileInfo[getTileNum(tileid)].sizex;
    else
        return 0;
}

/*800351F4*/
s16 getTileSizeY(u16 tileid)
{
    if ((getTileNum(tileid)) != 1)
        return gpTileInfo[getTileNum(tileid)].sizey;
    else
        return 0;
}

/*80035258*/
s32 getTilePicanm(u16 tileid)
{
    return gpTileInfo[getTileNum(tileid)].picanm;
}
