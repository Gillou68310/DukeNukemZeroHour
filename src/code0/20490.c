#include "common.h"
#include "code0/main.h"
#include "code0/9410.h"
#include "code0/code0.h"

/*.data*/
/*800DCB10*/ Vp D_800DCB10[8] = {
    {{ { 0x280, 0x1E0, 0x1FF, 0 }, { 0x280, 0x1E0, 0x1FF, 0 } }},
    {{ { 0x140, 0x0F0, 0x1FF, 0 }, { 0x158, 0x108, 0x1FF, 0 } }},
    {{ { 0x140, 0x0F0, 0x1FF, 0 }, { 0x3A8, 0x108, 0x1FF, 0 } }},
    {{ { 0x140, 0x0F0, 0x1FF, 0 }, { 0x158, 0x2B8, 0x1FF, 0 } }},
    {{ { 0x140, 0x0F0, 0x1FF, 0 }, { 0x3A8, 0x2B8, 0x1FF, 0 } }},
    {{ { 0x280, 0x0F0, 0x1FF, 0 }, { 0x280, 0x108, 0x1FF, 0 } }},
    {{ { 0x280, 0x0F0, 0x1FF, 0 }, { 0x280, 0x2B8, 0x1FF, 0 } }},
    {{ { 0x280, 0x1E0, 0x1FF, 0 }, { 0x280, 0x1E0, 0x1FF, 0 } }}
};

/*800DCB90*/
static s16 D_800DCB90[8][4] = {
    { 0, 0, 0x140, 0xF0 }, { 0xC, 0xC, 0x9F, 0x77 },
    { 0xA1, 0xC, 0x134, 0x77 }, { 0xC, 0x79, 0x9F, 0xE4 },
    { 0xA1, 0x79, 0x134, 0xE4 }, { 0xC, 0xC, 0x134, 0x77 },
    { 0xC, 0x79, 0x134, 0xE4 }, { 0xC, 0xC, 0x134, 0xE4 },
};

/*800DCBD0*/ static s16 D_800DCBD0 = 0;
/*800DCBD2*/ static s16 D_800DCBD2 = 0;
/*800DCBD4*/ u8 D_800DCBD4 = 0;
/*800DCBD5*/ u8 D_800DCBD5 = 1;

/*.comm*/
/*801995B8*/ Vp D_801995B8[4][2];

/*.text*/

/*8001F890*/
static void func_8001F890(Vp *arg0)
{
    D_80199110 = (arg0->vp.vscale[0] / 4);
    D_801A1980 = (arg0->vp.vscale[1] / 4);
    D_80168C9C = (arg0->vp.vtrans[0] / 4);
    D_801A2684 = (arg0->vp.vtrans[1] / 4);
}

/*8001F928*/
void func_8001F928(s32 arg0, s32 arg1)
{
    s32 i, j;
    s16 k, l, m, n;

    i = (arg0 * 12) / SCREEN_WIDTH;
    l = ((arg0 / 2) + i) * 2;
    k = ((arg0 - i) + (arg0 / 2)) * 2;

    j = arg1 / 20;
    n = ((arg1 / 2) + j) * 2;
    m = ((arg1 - j) + (arg1 / 2)) * 2;

    D_800DCB10[0].vp.vscale[0] = arg0 * 2;
    D_800DCB10[0].vp.vtrans[0] = arg0 * 2;
    D_800DCB10[1].vp.vscale[0] = arg0;
    D_800DCB10[2].vp.vscale[0] = arg0;
    D_800DCB10[1].vp.vtrans[0] = l;
    D_800DCB10[2].vp.vtrans[0] = k;

    if ((D_8012C470 == 3) && (D_800DCBD5 != 0))
    {
        D_800DCB10[3].vp.vscale[0] = arg0 * 2;
        D_800DCB10[3].vp.vtrans[0] = arg0 * 2;
    }
    else
    {
        D_800DCB10[3].vp.vscale[0] = arg0;
        D_800DCB10[3].vp.vtrans[0] = l;
    }

    D_800DCB10[4].vp.vscale[0] = arg0;
    D_800DCB10[4].vp.vtrans[0] = k;

    if (D_800DCBD4 != 0)
    {
        D_800DCB10[5].vp.vscale[0] = arg0 * 2;
        D_800DCB10[5].vp.vtrans[0] = arg0 * 2;
        D_800DCB10[6].vp.vscale[0] = arg0 * 2;
        D_800DCB10[6].vp.vtrans[0] = arg0 * 2;
    }
    else
    {
        D_800DCB10[5].vp.vscale[0] = arg0;
        D_800DCB10[5].vp.vtrans[0] = l;
        D_800DCB10[6].vp.vscale[0] = arg0;
        D_800DCB10[6].vp.vtrans[0] = k;
    }

    D_800DCB10[7].vp.vscale[0] = arg0 * 2;
    D_800DCB10[7].vp.vtrans[0] = arg0 * 2;
    D_800DCB10[0].vp.vscale[1] = arg1 * 2;
    D_800DCB10[0].vp.vtrans[1] = arg1 * 2;
    D_800DCB10[1].vp.vscale[1] = arg1;
    D_800DCB10[1].vp.vtrans[1] = n;
    D_800DCB10[2].vp.vscale[1] = arg1;
    D_800DCB10[2].vp.vtrans[1] = n;
    D_800DCB10[3].vp.vscale[1] = arg1;
    D_800DCB10[3].vp.vtrans[1] = m;
    D_800DCB10[4].vp.vscale[1] = arg1;
    D_800DCB10[4].vp.vtrans[1] = m;

    if (D_800DCBD4 != 0)
    {
        D_800DCB10[5].vp.vscale[1] = arg1;
        D_800DCB10[5].vp.vtrans[1] = n;
        D_800DCB10[6].vp.vscale[1] = arg1;
        D_800DCB10[6].vp.vtrans[1] = m;
    }
    else
    {
        D_800DCB10[5].vp.vscale[1] = arg1 * 2;
        D_800DCB10[5].vp.vtrans[1] = arg1 * 2;
        D_800DCB10[6].vp.vscale[1] = arg1 * 2;
        D_800DCB10[6].vp.vtrans[1] = arg1 * 2;
    }
    D_800DCB10[7].vp.vscale[1] = arg1 * 2;
    D_800DCB10[7].vp.vtrans[1] = arg1 * 2;
    D_800DCB90[1][2] = (arg0 / 2) - 1;
    D_800DCB90[2][0] = (arg0 / 2) + 1;
    D_800DCB90[0][2] = arg0;
    D_800DCB90[1][0] = i;
    D_800DCB90[2][2] = arg0 - i;

    if ((D_8012C470 == 3) && (D_800DCBD5 != 0))
    {
        D_800DCB90[3][0] = i;
        D_800DCB90[3][2] = arg0 - i;
    }
    else
    {
        D_800DCB90[3][0] = i;
        D_800DCB90[3][2] = (arg0 / 2) - 1;
    }

    D_800DCB90[4][0] = (arg0 / 2) + 1;
    D_800DCB90[4][2] = arg0 - i;

    if (D_800DCBD4 != 0)
    {
        D_800DCB90[5][0] = i;
        D_800DCB90[5][2] = arg0 - i;
        D_800DCB90[6][0] = i;
        D_800DCB90[6][2] = arg0 - i;
    }
    else
    {
        D_800DCB90[5][0] = i;
        D_800DCB90[5][2] = (arg0 / 2) - 1;
        D_800DCB90[6][0] = (arg0 / 2) + 1;
        D_800DCB90[6][2] = arg0 - i;
    }

    D_800DCB90[7][2] = arg0 - i;
    D_800DCB90[7][0] = i;
    D_800DCB90[0][3] = arg1;
    D_800DCB90[1][1] = j;
    D_800DCB90[1][3] = (arg1 / 2) - 1;

    D_800DCB90[2][1] = j;
    D_800DCB90[2][3] = (arg1 / 2) - 1;
    D_800DCB90[3][1] = (arg1 / 2) + 1;
    D_800DCB90[3][3] = arg1 - j;
    D_800DCB90[4][1] = (arg1 / 2) + 1;
    D_800DCB90[4][3] = arg1 - j;

    if (D_800DCBD4 != 0)
    {
        D_800DCB90[5][1] = j;
        D_800DCB90[5][3] = (arg1 / 2) - 1;
        D_800DCB90[6][1] = (arg1 / 2) + 1;
        D_800DCB90[6][3] = arg1 - j;
    }
    else
    {
        D_800DCB90[5][1] = j;
        D_800DCB90[5][3] = arg1 - j;
        D_800DCB90[6][1] = j;
        D_800DCB90[6][3] = arg1 - j;
    }

    D_800DCB90[7][1] = j;
    D_800DCB90[7][3] = arg1 - j;
}

/*8001FD60*/
void func_8001FD60(u8 arg0, u8 arg1)
{
    f32 f1;
    s16 i;
    s16 ulx, uly;
    s16 lrx, lry;
    s32 j;

    if (D_8012C470 == 1)
        j = 7;
    else if (D_8012C470 == 2)
        j = arg0 + 5;
    else
        j = arg0 + 1;

    for (i = 0; i < ARRAY_COUNT(D_801995B8); i++)
    {
        D_801995B8[arg0][arg1].vp.vscale[i] = D_800DCB10[j].vp.vscale[i];
        D_801995B8[arg0][arg1].vp.vtrans[i] = D_800DCB10[j].vp.vtrans[i];
    }

    if (!arg1)
    {
        if (gPlayer[arg0].unk82 != 0)
        {
            f1 = 0.0018310547f;
            if (gPlayer[arg0].unk82 < 30)
                f1 = (gPlayer[arg0].unk82 * f1) / 30.0f;

            D_801995B8[arg0][0].vp.vscale[0] += 2.0f * ((gpSinTable[D_801A2790[arg0].unk12] + 0x4000) * f1);
            D_801995B8[arg0][0].vp.vscale[1] += (gpSinTable[(D_801A2790[arg0].unk12 + 0x2AB) & 0x7FF] + 0x4000) * f1;
        }
        else if (gPlayer[arg0].unk55 != 0)
        {
            D_801995B8[arg0][0].vp.vscale[0] += ((gpSinTable[D_801A2790[arg0].unk12] + 0x4000) * 20.0) / 16384.0;
            D_801995B8[arg0][0].vp.vscale[1] += ((gpSinTable[(D_801A2790[arg0].unk12 + 0x2AB) & 0x7FF] + 0x4000) * 10.0) / 16384.0;
        }
    }

    D_801995B8[arg0][arg1].vp.vtrans[0] += (D_800DCBD0 * 4);
    D_801995B8[arg0][arg1].vp.vtrans[1] += (D_800DCBD2 * 4);
    gSPViewport(gpDisplayList++, &D_801995B8[arg0][arg1]);

    ulx = CLAMP_MIN(MIN(gScreenWidth, (D_800DCB90[j][0] + D_800DCBD0)), 0);
    lrx = CLAMP_MIN(MIN(gScreenWidth, (D_800DCB90[j][2] + D_800DCBD0)), 0);
    uly = CLAMP_MIN(MIN(gScreenHeight, (D_800DCB90[j][1] + D_800DCBD2)), 0);
    lry = CLAMP_MIN(MIN(gScreenHeight, (D_800DCB90[j][3] + D_800DCBD2)), 0);

    gDPSetScissor(gpDisplayList++, G_SC_NON_INTERLACE, ulx, uly, lrx, lry);
    func_8001F890(&D_801995B8[arg0][arg1]);
}

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

    func_80020350(0, (D_800DCB90[7][1] - 1), (gScreenWidth - 1), D_800DCB90[7][1]);
    func_80020350(0, D_800DCB90[7][3], (gScreenWidth - 1), (D_800DCB90[7][3] + 1));
    func_80020350((D_800DCB90[7][0] - 1), 0, D_800DCB90[7][0], gScreenHeight);
    func_80020350(D_800DCB90[7][2], 0, (D_800DCB90[7][2] + 1), gScreenHeight);

    gDPSetPrimColor(gpDisplayList++, 0, 0, 0xFF, 0x00, 0xFF, 0x00);

    func_80020350(0, D_800DCB90[7][1], (gScreenWidth - 1), (D_800DCB90[7][1] + 1));
    func_80020350(0, (D_800DCB90[7][3] - 1), (gScreenWidth - 1), D_800DCB90[7][3]);
    func_80020350(D_800DCB90[7][0], 0, (D_800DCB90[7][0] + 1), gScreenHeight);
    func_80020350((D_800DCB90[7][2] - 1), 0, D_800DCB90[7][2], gScreenHeight);

    if (D_800DCBD4 != 0)
    {
        if (D_8012C470 >= 2)
            func_80020350(0, (D_800DCB90[5][3] - 1), (gScreenWidth - 1), (D_800DCB90[6][1] + 1));
        if (D_8012C470 >= 3)
            func_80020350((D_800DCB90[1][2] - 1), 0, (D_800DCB90[2][0] + 1), gScreenHeight);
    }
    else
    {
        if (D_8012C470 >= 2)
            func_80020350((D_800DCB90[1][2] - 1), 0, (D_800DCB90[2][0] + 1), gScreenHeight);
        if (D_8012C470 >= 3)
            func_80020350(0, (D_800DCB90[1][3] - 1), (gScreenWidth - 1), (D_800DCB90[3][1] + 1));
    }
}
