#include "common.h"
#include "code0/main.h"
#include "code0/9410.h"
#include "code0/code0.h"

/*.data*/
/*800DCB10*/ Vp D_800DCB10 = {{ { 0x280, 0x1E0, 0x1FF, 0 }, { 0x280, 0x1E0, 0x1FF, 0 } }};
/*800DCB20*/ static Vp D_800DCB20 = {{ { 0x140, 0xF0, 0x1FF, 0 }, { 0x158, 0x108, 0x1FF, 0 } }};
/*800DCB30*/ static Vp D_800DCB30 = {{ { 0x140, 0xF0, 0x1FF, 0 }, { 0x3A8, 0x108, 0x1FF, 0 } }};
/*800DCB40*/ static Vp D_800DCB40 = {{ { 0x140, 0xF0, 0x1FF, 0 }, { 0x158, 0x2B8, 0x1FF, 0 } }};
/*800DCB50*/ static Vp D_800DCB50 = {{ { 0x140, 0xF0, 0x1FF, 0 }, { 0x3A8, 0x2B8, 0x1FF, 0 } }};
/*800DCB60*/ static Vp D_800DCB60 = {{ { 0x280, 0xF0, 0x1FF, 0 }, { 0x280, 0x108, 0x1FF, 0 } }};
/*800DCB70*/ static Vp D_800DCB70 = {{ { 0x280, 0xF0, 0x1FF, 0 }, { 0x280, 0x2B8, 0x1FF, 0 } }};
/*800DCB80*/ static Vp D_800DCB80 = {{ { 0x280, 0x1E0, 0x1FF, 0 }, { 0x280, 0x1E0, 0x1FF, 0 } }};

/*800DCB90*/
static Vp D_800DCB90[4] = {
    { { { 0, 0, 0x140, 0xF0 }, { 0xC, 0xC, 0x9F, 0x77 } } },
    { { { 0xA1, 0xC, 0x134, 0x77 }, { 0xC, 0x79, 0x9F, 0xE4 } } },
    { { { 0xA1, 0x79, 0x134, 0xE4 }, { 0xC, 0xC, 0x134, 0x77 } } },
    { { { 0xC, 0x79, 0x134, 0xE4 }, { 0xC, 0xC, 0x134, 0xE4 } } },
};

/*800DCBD0*/ static s16 D_800DCBD0 = 0;
/*800DCBD2*/ static s16 D_800DCBD2 = 0;
/*800DCBD4*/ u8 D_800DCBD4 = 0;
/*800DCBD5*/ u8 D_800DCBD5 = 1;

/*.text*/

/*8001F890*/
static void func_8001F890(Vp *arg0)
{
    D_80199110 = (arg0->vp.vscale[0] / 4);
    D_801A1980 = (arg0->vp.vscale[1] / 4);
    D_80168C9C = (arg0->vp.vtrans[0] / 4);
    D_801A2684 = (arg0->vp.vtrans[1] / 4);
}

INCLUDE_ASM("nonmatchings/src/code0/20490", func_8001F928);

INCLUDE_ASM("nonmatchings/src/code0/20490", func_8001FD60);

/*80020350*/
static void func_80020350(s16 arg0, s16 arg1, s16 arg2, s16 arg3)
{
    arg0 = CLAMP_MIN(MIN(gScreenWidth, arg0 + D_800DCBD0), 0);
    arg2 = CLAMP_MIN(MIN(gScreenWidth, arg2 + D_800DCBD0), 0);
    arg1 = CLAMP_MIN(MIN(gScreenHeight, arg1 + D_800DCBD2), 0);
    arg3 = CLAMP_MIN(MIN(gScreenHeight, arg3 + D_800DCBD2), 0);

    gSPTextureRectangle(gpDisplayList++, arg0*4, arg1*4, arg2*4, arg3*4, 0, 0, 0, 1024, 1024);
}

/*80020510*/
void func_80020510(void)
{
    func_8000A070();
    gDPSetScissor(gpDisplayList++, G_SC_NON_INTERLACE, 0, 0, gScreenWidth, gScreenHeight);
    gDPSetRenderMode(gpDisplayList++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineMode(gpDisplayList++, G_CC_PRIMITIVE, G_CC_PASS2);
    gDPSetPrimColor(gpDisplayList++, 0, 0, 0x00, 0x00, 0x00, 0xFF);

    func_80020350(0, (D_800DCB90[3].vp.vtrans[1] - 1), (gScreenWidth - 1), D_800DCB90[3].vp.vtrans[1]);
    func_80020350(0, D_800DCB90[3].vp.vtrans[3], (gScreenWidth - 1), (D_800DCB90[3].vp.vtrans[3] + 1));
    func_80020350((D_800DCB90[3].vp.vtrans[0] - 1), 0, D_800DCB90[3].vp.vtrans[0], gScreenHeight);
    func_80020350(D_800DCB90[3].vp.vtrans[2], 0, (D_800DCB90[3].vp.vtrans[2] + 1), gScreenHeight);

    gDPSetPrimColor(gpDisplayList++, 0, 0, 0xFF, 0x00, 0xFF, 0x00);

    func_80020350(0, D_800DCB90[3].vp.vtrans[1], (gScreenWidth - 1), (D_800DCB90[3].vp.vtrans[1] + 1));
    func_80020350(0, (D_800DCB90[3].vp.vtrans[3] - 1), (gScreenWidth - 1), D_800DCB90[3].vp.vtrans[3]);
    func_80020350(D_800DCB90[3].vp.vtrans[0], 0, (D_800DCB90[3].vp.vtrans[0] + 1), gScreenHeight);
    func_80020350((D_800DCB90[3].vp.vtrans[2] - 1), 0, D_800DCB90[3].vp.vtrans[2], gScreenHeight);

    if (D_800DCBD4 != 0)
    {
        if (D_8012C470 >= 2)
            func_80020350(0, (D_800DCB90[2].vp.vtrans[3] - 1), (gScreenWidth - 1), (D_800DCB90[3].vp.vscale[1] + 1));
        if (D_8012C470 >= 3)
            func_80020350((D_800DCB90[0].vp.vtrans[2] - 1), 0, (D_800DCB90[1].vp.vscale[0] + 1), gScreenHeight);
    }
    else
    {
        if (D_8012C470 >= 2)
            func_80020350((D_800DCB90[0].vp.vtrans[2] - 1), 0, (D_800DCB90[1].vp.vscale[0] + 1), gScreenHeight);
        if (D_8012C470 >= 3)
            func_80020350(0, (D_800DCB90[0].vp.vtrans[3] - 1), (gScreenWidth - 1), (D_800DCB90[1].vp.vtrans[1] + 1));
    }
}
