#include "common.h"
#include "code0/controller.h"
#include "code0/code0.h"

/*.text*/

/*80003990*/
void func_80003990(u8 playernum)
{
    D_8012F6FC[playernum] = gController[playernum].button;
    D_8011A670[playernum] = gController[playernum].stick_x;
    D_8013A43C[playernum] = gController[playernum].stick_y;
}
