#include "common.h"
#include "code0/code0.h"

/*.text*/

/*80003990*/
void func_80003990(u8 playernum)
{
    D_8012F6FC[playernum] = D_801A68A8[playernum].unk0;
    D_8011A670[playernum] = D_801A68A8[playernum].unk4;
    D_8013A43C[playernum] = D_801A68A8[playernum].unk6;
}
