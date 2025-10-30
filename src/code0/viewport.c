#include "common.h"
#include "code0/main.h"
#include "code0/9410.h"
#include "code0/code0.h"

#define TRANS1(A, B) (((A / 2) + B) * 2)
#define TRANS2(A, B) (((A - B) + (A / 2)) * 2)

/*.data*/
/*800DCB10*/ Vp gViewport[8] = {
    {{.vscale = { SCREEN_WIDTH*2, SCREEN_HEIGHT*2, G_MAXZ/2, 0 },
      .vtrans = { SCREEN_WIDTH*2, SCREEN_HEIGHT*2, G_MAXZ/2, 0 } }},
    {{.vscale = { SCREEN_WIDTH, SCREEN_HEIGHT, G_MAXZ/2, 0 },
      .vtrans = { TRANS1(SCREEN_WIDTH,BORDER_SIZE), TRANS1(SCREEN_HEIGHT,BORDER_SIZE), G_MAXZ/2, 0 } }},
    {{.vscale = { SCREEN_WIDTH, SCREEN_HEIGHT, G_MAXZ/2, 0 },
      .vtrans = { TRANS2(SCREEN_WIDTH,BORDER_SIZE), TRANS1(SCREEN_HEIGHT,BORDER_SIZE), G_MAXZ/2, 0 } }},
    {{.vscale = { SCREEN_WIDTH, SCREEN_HEIGHT, G_MAXZ/2, 0 },
      .vtrans = { TRANS1(SCREEN_WIDTH,BORDER_SIZE), TRANS2(SCREEN_HEIGHT,BORDER_SIZE), G_MAXZ/2, 0 } }},
    {{.vscale = { SCREEN_WIDTH, SCREEN_HEIGHT, G_MAXZ/2, 0 },
      .vtrans = { TRANS2(SCREEN_WIDTH,BORDER_SIZE), TRANS2(SCREEN_HEIGHT,BORDER_SIZE), G_MAXZ/2, 0 } }},
    {{.vscale = { SCREEN_WIDTH*2, SCREEN_HEIGHT, G_MAXZ/2, 0 },
      .vtrans = { SCREEN_WIDTH*2, TRANS1(SCREEN_HEIGHT,BORDER_SIZE), G_MAXZ/2, 0 } }},
    {{.vscale = { SCREEN_WIDTH*2, SCREEN_HEIGHT, G_MAXZ/2, 0 },
      .vtrans = { SCREEN_WIDTH*2, TRANS2(SCREEN_HEIGHT,BORDER_SIZE), G_MAXZ/2, 0 } }},
    {{.vscale = { SCREEN_WIDTH*2, SCREEN_HEIGHT*2, G_MAXZ/2, 0 },
      .vtrans = { SCREEN_WIDTH*2, SCREEN_HEIGHT*2, G_MAXZ/2, 0 } }}
};

/*800DCB90*/
static s16 _scissor[8][4] = {
    { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT },
    { BORDER_SIZE, BORDER_SIZE, (SCREEN_WIDTH/2)-1, (SCREEN_HEIGHT/2)-1 },
    { (SCREEN_WIDTH/2)+1, BORDER_SIZE, SCREEN_WIDTH-BORDER_SIZE, (SCREEN_HEIGHT/2)-1 },
    { BORDER_SIZE, (SCREEN_HEIGHT/2)+1, (SCREEN_WIDTH/2)-1, SCREEN_HEIGHT-BORDER_SIZE },
    { (SCREEN_WIDTH/2)+1, (SCREEN_HEIGHT/2)+1, SCREEN_WIDTH-BORDER_SIZE, SCREEN_HEIGHT-BORDER_SIZE },
    { BORDER_SIZE, BORDER_SIZE, SCREEN_WIDTH-BORDER_SIZE, (SCREEN_HEIGHT/2)-1 },
    { BORDER_SIZE, (SCREEN_HEIGHT/2)+1, SCREEN_WIDTH-BORDER_SIZE, SCREEN_HEIGHT-BORDER_SIZE },
    { BORDER_SIZE, BORDER_SIZE, SCREEN_WIDTH-BORDER_SIZE, SCREEN_HEIGHT-BORDER_SIZE },
};

/*800DCBD0*/ static s16 D_800DCBD0 = 0;
/*800DCBD2*/ static s16 D_800DCBD2 = 0;
/*800DCBD4*/ bool g2pSplitHorz = FALSE;
/*800DCBD5*/ bool g3pSplitFull = TRUE;

/*.comm*/
/*801995B8*/ Vp _playerViewport[MAXPLAYERS][2];

/*.text*/

/*8001F890*/
static void _updateScaleTrans(Vp *viewport)
{
    gViewportScaleX = (viewport->vp.vscale[0] / 4);
    gViewportScaleY = (viewport->vp.vscale[1] / 4);
    gViewportTransX = (viewport->vp.vtrans[0] / 4);
    gViewportTransY = (viewport->vp.vtrans[1] / 4);
}

/*8001F928*/
void updateViewport(s32 width, s32 height)
{
    s32 i, j;
    s16 k, l, m, n;

    i = (width * BORDER_SIZE) / SCREEN_WIDTH;
    l = TRANS1(width, i);
    k = TRANS2(width, i);

    j = (height * BORDER_SIZE) / SCREEN_HEIGHT;
    n = TRANS1(height, j);
    m = TRANS2(height, j);

    gViewport[0].vp.vscale[0] = width * 2;
    gViewport[0].vp.vtrans[0] = width * 2;
    gViewport[1].vp.vscale[0] = width;
    gViewport[2].vp.vscale[0] = width;
    gViewport[1].vp.vtrans[0] = l;
    gViewport[2].vp.vtrans[0] = k;

    if ((gPlayerCount == 3) && (g3pSplitFull != 0))
    {
        gViewport[3].vp.vscale[0] = width * 2;
        gViewport[3].vp.vtrans[0] = width * 2;
    }
    else
    {
        gViewport[3].vp.vscale[0] = width;
        gViewport[3].vp.vtrans[0] = l;
    }

    gViewport[4].vp.vscale[0] = width;
    gViewport[4].vp.vtrans[0] = k;

    if (g2pSplitHorz != 0)
    {
        gViewport[5].vp.vscale[0] = width * 2;
        gViewport[5].vp.vtrans[0] = width * 2;
        gViewport[6].vp.vscale[0] = width * 2;
        gViewport[6].vp.vtrans[0] = width * 2;
    }
    else
    {
        gViewport[5].vp.vscale[0] = width;
        gViewport[5].vp.vtrans[0] = l;
        gViewport[6].vp.vscale[0] = width;
        gViewport[6].vp.vtrans[0] = k;
    }

    gViewport[7].vp.vscale[0] = width * 2;
    gViewport[7].vp.vtrans[0] = width * 2;
    gViewport[0].vp.vscale[1] = height * 2;
    gViewport[0].vp.vtrans[1] = height * 2;
    gViewport[1].vp.vscale[1] = height;
    gViewport[1].vp.vtrans[1] = n;
    gViewport[2].vp.vscale[1] = height;
    gViewport[2].vp.vtrans[1] = n;
    gViewport[3].vp.vscale[1] = height;
    gViewport[3].vp.vtrans[1] = m;
    gViewport[4].vp.vscale[1] = height;
    gViewport[4].vp.vtrans[1] = m;

    if (g2pSplitHorz != 0)
    {
        gViewport[5].vp.vscale[1] = height;
        gViewport[5].vp.vtrans[1] = n;
        gViewport[6].vp.vscale[1] = height;
        gViewport[6].vp.vtrans[1] = m;
    }
    else
    {
        gViewport[5].vp.vscale[1] = height * 2;
        gViewport[5].vp.vtrans[1] = height * 2;
        gViewport[6].vp.vscale[1] = height * 2;
        gViewport[6].vp.vtrans[1] = height * 2;
    }
    gViewport[7].vp.vscale[1] = height * 2;
    gViewport[7].vp.vtrans[1] = height * 2;
    _scissor[1][2] = (width / 2) - 1;
    _scissor[2][0] = (width / 2) + 1;
    _scissor[0][2] = width;
    _scissor[1][0] = i;
    _scissor[2][2] = width - i;

    if ((gPlayerCount == 3) && (g3pSplitFull != 0))
    {
        _scissor[3][0] = i;
        _scissor[3][2] = width - i;
    }
    else
    {
        _scissor[3][0] = i;
        _scissor[3][2] = (width / 2) - 1;
    }

    _scissor[4][0] = (width / 2) + 1;
    _scissor[4][2] = width - i;

    if (g2pSplitHorz != 0)
    {
        _scissor[5][0] = i;
        _scissor[5][2] = width - i;
        _scissor[6][0] = i;
        _scissor[6][2] = width - i;
    }
    else
    {
        _scissor[5][0] = i;
        _scissor[5][2] = (width / 2) - 1;
        _scissor[6][0] = (width / 2) + 1;
        _scissor[6][2] = width - i;
    }

    _scissor[7][2] = width - i;
    _scissor[7][0] = i;
    _scissor[0][3] = height;
    _scissor[1][1] = j;
    _scissor[1][3] = (height / 2) - 1;

    _scissor[2][1] = j;
    _scissor[2][3] = (height / 2) - 1;
    _scissor[3][1] = (height / 2) + 1;
    _scissor[3][3] = height - j;
    _scissor[4][1] = (height / 2) + 1;
    _scissor[4][3] = height - j;

    if (g2pSplitHorz != 0)
    {
        _scissor[5][1] = j;
        _scissor[5][3] = (height / 2) - 1;
        _scissor[6][1] = (height / 2) + 1;
        _scissor[6][3] = height - j;
    }
    else
    {
        _scissor[5][1] = j;
        _scissor[5][3] = height - j;
        _scissor[6][1] = j;
        _scissor[6][3] = height - j;
    }

    _scissor[7][1] = j;
    _scissor[7][3] = height - j;
}

/*8001FD60*/
void setPlayerViewport(u8 playernum, u8 index)
{
    f32 f1;
    s16 i;
    s16 ulx, uly;
    s16 lrx, lry;
    s32 j;

    if (gPlayerCount == 1)
        j = 7;
    else if (gPlayerCount == 2)
        j = playernum + 5;
    else
        j = playernum + 1;

    for (i = 0; i < 4; i++)
    {
        _playerViewport[playernum][index].vp.vscale[i] = gViewport[j].vp.vscale[i];
        _playerViewport[playernum][index].vp.vtrans[i] = gViewport[j].vp.vtrans[i];
    }

    if (index == 0)
    {
        if (gPlayer[playernum].unk82 != 0)
        {
            f1 = 0.0018310547f;
            if (gPlayer[playernum].unk82 < 30)
                f1 = (gPlayer[playernum].unk82 * f1) / 30.0f;

            _playerViewport[playernum][0].vp.vscale[0] += 2.0f * ((gpSinTable[D_801A2790[playernum].unk12] + 0x4000) * f1);
            _playerViewport[playernum][0].vp.vscale[1] += (gpSinTable[(D_801A2790[playernum].unk12 + 0x2AB) & 0x7FF] + 0x4000) * f1;
        }
        else if (gPlayer[playernum].unk55 != 0)
        {
            _playerViewport[playernum][0].vp.vscale[0] += ((gpSinTable[D_801A2790[playernum].unk12] + 0x4000) * 20.0) / 16384.0;
            _playerViewport[playernum][0].vp.vscale[1] += ((gpSinTable[(D_801A2790[playernum].unk12 + 0x2AB) & 0x7FF] + 0x4000) * 10.0) / 16384.0;
        }
    }

    _playerViewport[playernum][index].vp.vtrans[0] += (D_800DCBD0 * 4);
    _playerViewport[playernum][index].vp.vtrans[1] += (D_800DCBD2 * 4);
    gSPViewport(gpDisplayList++, &_playerViewport[playernum][index]);

    ulx = CLAMP_MIN(MIN(gScreenWidth, (_scissor[j][0] + D_800DCBD0)), 0);
    lrx = CLAMP_MIN(MIN(gScreenWidth, (_scissor[j][2] + D_800DCBD0)), 0);
    uly = CLAMP_MIN(MIN(gScreenHeight, (_scissor[j][1] + D_800DCBD2)), 0);
    lry = CLAMP_MIN(MIN(gScreenHeight, (_scissor[j][3] + D_800DCBD2)), 0);

    gDPSetScissor(gpDisplayList++, G_SC_NON_INTERLACE, ulx, uly, lrx, lry);
    _updateScaleTrans(&_playerViewport[playernum][index]);
}

/*80020350*/
static void _drawRectangle(s16 xl, s16 yl, s16 xh, s16 yh)
{
    xl = CLAMP_MIN(MIN(gScreenWidth, xl + D_800DCBD0), 0);
    xh = CLAMP_MIN(MIN(gScreenWidth, xh + D_800DCBD0), 0);
    yl = CLAMP_MIN(MIN(gScreenHeight, yl + D_800DCBD2), 0);
    yh = CLAMP_MIN(MIN(gScreenHeight, yh + D_800DCBD2), 0);

    gSPTextureRectangle(gpDisplayList++, xl*4, yl*4, xh*4, yh*4, G_TX_RENDERTILE, 0, 0, 1<<10, 1<<10);
}

/*80020510*/
void drawViewportLines(void)
{
    setDrawMode2D();
    gDPSetScissor(gpDisplayList++, G_SC_NON_INTERLACE, 0, 0, gScreenWidth, gScreenHeight);
    gDPSetRenderMode(gpDisplayList++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineMode(gpDisplayList++, G_CC_PRIMITIVE, G_CC_PASS2);
    gDPSetPrimColor(gpDisplayList++, 0, 0, 0x00, 0x00, 0x00, 0xFF);

    _drawRectangle(0, (_scissor[7][1] - 1), (gScreenWidth - 1), _scissor[7][1]);
    _drawRectangle(0, _scissor[7][3], (gScreenWidth - 1), (_scissor[7][3] + 1));
    _drawRectangle((_scissor[7][0] - 1), 0, _scissor[7][0], gScreenHeight);
    _drawRectangle(_scissor[7][2], 0, (_scissor[7][2] + 1), gScreenHeight);

    gDPSetPrimColor(gpDisplayList++, 0, 0, 0xFF, 0x00, 0xFF, 0x00);

    _drawRectangle(0, _scissor[7][1], (gScreenWidth - 1), (_scissor[7][1] + 1));
    _drawRectangle(0, (_scissor[7][3] - 1), (gScreenWidth - 1), _scissor[7][3]);
    _drawRectangle(_scissor[7][0], 0, (_scissor[7][0] + 1), gScreenHeight);
    _drawRectangle((_scissor[7][2] - 1), 0, _scissor[7][2], gScreenHeight);

    if (g2pSplitHorz != 0)
    {
        if (gPlayerCount >= 2)
            _drawRectangle(0, (_scissor[5][3] - 1), (gScreenWidth - 1), (_scissor[6][1] + 1));
        if (gPlayerCount >= 3)
            _drawRectangle((_scissor[1][2] - 1), 0, (_scissor[2][0] + 1), gScreenHeight);
    }
    else
    {
        if (gPlayerCount >= 2)
            _drawRectangle((_scissor[1][2] - 1), 0, (_scissor[2][0] + 1), gScreenHeight);
        if (gPlayerCount >= 3)
            _drawRectangle(0, (_scissor[1][3] - 1), (gScreenWidth - 1), (_scissor[3][1] + 1));
    }
}
