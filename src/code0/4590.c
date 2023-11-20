#include "common.h"
#include "code0/controller.h"
#include "code0/code0.h"

/*.comm*/
/*8012F6FC*/ volatile u16 gButton[MAXPLAYERS];
/*8011A670*/ volatile s16 gStickX[MAXPLAYERS];
/*8013A43C*/ volatile s16 gStickY[MAXPLAYERS];

/*.text*/

/*80003990*/
void func_80003990(u8 playernum)
{
    gButton[playernum] = gController[playernum].button;
    gStickX[playernum] = gController[playernum].stick_x;
    gStickY[playernum] = gController[playernum].stick_y;
}
