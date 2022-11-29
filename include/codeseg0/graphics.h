#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include "common.h"

void grPerspectiveF(float mf[4][4], u16 *perspNorm, float fovy, float aspect, float near, float far, float scale);

void grPerspective(Mtx *m, u16 *perspNorm, float fovy, float aspect, float near, float far, float scale);

void grNormalize(float *x, float *y, float *z);

void grTranslateF(float mf[4][4], float x, float y, float z);

void grTranslate(Mtx *m, float x, float y, float z);

void grScaleF(float mf[4][4], float x, float y, float z);

void grScale(Mtx *m, float x, float y, float z);

void grMtxCatL(Mtx *m, Mtx *n, Mtx *res);

void grMtxCatF(float mf[4][4], float nf[4][4], float res[4][4]);

void grMtxXFMF(float mf[4][4], float x, float y, float z, float *ox, float *oy, float *oz);

void grMtxF2L(float mf[4][4], Mtx *m);

void grMtxL2F(float mf[4][4], Mtx *m);

void grMtxIdentF(float mf[4][4]);

void grLookAtF(float mf[4][4], float xEye, float yEye, float zEye,
               float xAt, float yAt, float zAt,
               float xUp, float yUp, float zUp);

void grLookAtReflectF(float mf[4][4], LookAt *l,
                      float xEye, float yEye, float zEye,
                      float xAt, float yAt, float zAt,
                      float xUp, float yUp, float zUp);

void grLookAtReflect(Mtx *m, LookAt *l, float xEye, float yEye, float zEye,
                     float xAt, float yAt, float zAt,
                     float xUp, float yUp, float zUp);

#endif