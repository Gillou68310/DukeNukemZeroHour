#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include "common.h"

void grPositionF(f32 mf[4][4], f32 r, f32 p, f32 h, f32 s,
                 f32 x, f32 y, f32 z);

void grPosition(Mtx *m, f32 r, f32 p, f32 h, f32 s,
                f32 x, f32 y, f32 z);

void grPerspectiveF(f32 mf[4][4], u16 *perspNorm, f32 fovy, f32 aspect, f32 near, f32 far, f32 scale);

void grPerspective(Mtx *m, u16 *perspNorm, f32 fovy, f32 aspect, f32 near, f32 far, f32 scale);

void grNormalize(f32 *x, f32 *y, f32 *z);

void grTranslateF(f32 mf[4][4], f32 x, f32 y, f32 z);

void grTranslate(Mtx *m, f32 x, f32 y, f32 z);

void grScaleF(f32 mf[4][4], f32 x, f32 y, f32 z);

void grScale(Mtx *m, f32 x, f32 y, f32 z);

void grMtxCatL(Mtx *m, Mtx *n, Mtx *res);

void grMtxCatF(f32 mf[4][4], f32 nf[4][4], f32 res[4][4]);

void grMtxXFMF(f32 mf[4][4], f32 x, f32 y, f32 z, f32 *ox, f32 *oy, f32 *oz);

void grMtxF2L(f32 mf[4][4], Mtx *m);

void grMtxL2F(f32 mf[4][4], Mtx *m);

void grMtxIdentF(f32 mf[4][4]);

void grLookAtF(f32 mf[4][4], f32 xEye, f32 yEye, f32 zEye,
               f32 xAt, f32 yAt, f32 zAt,
               f32 xUp, f32 yUp, f32 zUp);

void grLookAtReflectF(f32 mf[4][4], LookAt *l,
                      f32 xEye, f32 yEye, f32 zEye,
                      f32 xAt, f32 yAt, f32 zAt,
                      f32 xUp, f32 yUp, f32 zUp);

void grLookAtReflect(Mtx *m, LookAt *l, f32 xEye, f32 yEye, f32 zEye,
                     f32 xAt, f32 yAt, f32 zAt,
                     f32 xUp, f32 yUp, f32 zUp);

#endif
