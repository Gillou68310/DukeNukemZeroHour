#ifndef _VIEWPORT_H_
#define _VIEWPORT_H_

#include "common.h"

void updateViewport(s32 width, s32 height);
void setPlayerViewport(u8 playernum, u8 index);
void drawViewportLines(void);

extern Vp gViewport[8];
extern bool g2pSplitHorz;
extern bool g3pSplitFull;

#endif
