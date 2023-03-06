#include "common.h"
#include "code0/modelinfo.h"

/*.text*/

/*800161F0*/
void func_800161F0(ModelInfo *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6)
{
    arg0->unk24 = arg1;
    arg0->unk26 = arg2;
    arg0->unk28 = arg3;
    arg0->unk2A = arg4;
    arg0->unk2C = arg5;
    arg0->unk2E = arg6;
}

/*80016218*/
void func_80016218()
{
    func_800161F0(&D_800C1DD4, -80, -80, -80, 80, 80, 80);
    func_800161F0(&D_800CB3E0, -312, -182, -134, 310, 344, 632);
    func_800161F0(&D_800CAA44, -200, -240, -280, 200, 160, 140);
    func_800161F0(&D_800BD97C, -100, -100, -100, 100, 100, 100);
    func_800161F0(&D_800D43B0, -80, -80, -277, 80, 80, 0);
}

/*8001630C*/
void func_8001630C()
{
    func_800161F0(&D_800C9784, 0, 0, 0, 0, 0, 0);
    func_800161F0(&D_800C97C0, 0, 0, 0, 0, 0, 0);
}

/*8001636C*/
void func_8001636C()
{
    func_800161F0(&D_800C9784, -336, -967, -4, 336, 1013, 435);
    func_800161F0(&D_800C97C0, -1008, -1049, -3, 1131, 1085, 89);
}
