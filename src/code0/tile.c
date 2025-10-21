#include "common.h"
#include "code0/main.h"
#include "code0/9410.h"

/*.text*/

/*80035190*/
s16 getTileSizeX(u16 tilenum)
{
    if ((getTileId(tilenum)) != 1)
        return gpTileInfo[getTileId(tilenum)].sizex;
    else
        return 0;
}

/*800351F4*/
s16 getTileSizeY(u16 tilenum)
{
    if ((getTileId(tilenum)) != 1)
        return gpTileInfo[getTileId(tilenum)].sizey;
    else
        return 0;
}

/*80035258*/
s32 getTilePicanm(u16 tilenum)
{
    return gpTileInfo[getTileId(tilenum)].picanm;
}
