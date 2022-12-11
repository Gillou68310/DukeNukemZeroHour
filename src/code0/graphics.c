#include "common.h"
#include "code0/graphics.h"

/*.text*/

void grPositionF(float mf[4][4], float r, float p, float h, float s,
               float x, float y, float z)
{
    static float dtor = 3.1415926 / 180.0;
    float sinr, sinp, sinh;
    float cosr, cosp, cosh;

    r *= dtor;
    p *= dtor;
    h *= dtor;
    sinr = sinf(r);
    cosr = cosf(r);
    sinp = sinf(p);
    cosp = cosf(p);
    sinh = sinf(h);
    cosh = cosf(h);

    mf[0][0] = (cosp * cosh) * s;
    mf[0][1] = (cosp * sinh) * s;
    mf[0][2] = (-sinp) * s;
    mf[0][3] = 0.0;

    mf[1][0] = (sinr * sinp * cosh - cosr * sinh) * s;
    mf[1][1] = (sinr * sinp * sinh + cosr * cosh) * s;
    mf[1][2] = (sinr * cosp) * s;
    mf[1][3] = 0.0;

    mf[2][0] = (cosr * sinp * cosh + sinr * sinh) * s;
    mf[2][1] = (cosr * sinp * sinh - sinr * cosh) * s;
    mf[2][2] = (cosr * cosp) * s;
    mf[2][3] = 0.0;

    mf[3][0] = x;
    mf[3][1] = y;
    mf[3][2] = z;
    mf[3][3] = 1.0;
}

void grPosition(Mtx *m, float r, float p, float h, float s,
              float x, float y, float z)
{
    float mf[4][4];

    grPositionF(mf, r, p, h, s, x, y, z);
    grMtxF2L(mf, m);
}

void grPerspectiveF(float mf[4][4], u16 *perspNorm, float fovy, float aspect, float near, float far, float scale)
{
    float cot;
    int i, j;

    grMtxIdentF(mf);

    fovy *= 3.1415926 / 180.0;
    cot = cosf(fovy / 2) / sinf(fovy / 2);

    mf[0][0] = cot / aspect;
    mf[1][1] = cot;
    mf[2][2] = (near + far) / (near - far);
    mf[2][3] = -1;
    mf[3][2] = (2 * near * far) / (near - far);
    mf[3][3] = 0;

    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            mf[i][j] *= scale;

    if (perspNorm != (u16 *)NULL)
    {
        if (near + far <= 2.0)
        {
            *perspNorm = (u16)0xFFFF;
        }
        else
        {
            *perspNorm = (u16)((2.0 * 65536.0) / (near + far));
            if (*perspNorm <= 0)
                *perspNorm = (u16)0x0001;
        }
    }
}

void grPerspective(Mtx *m, u16 *perspNorm, float fovy, float aspect, float near, float far, float scale)
{
    Matrix4f mf;

    grPerspectiveF(mf, perspNorm, fovy, aspect, near, far, scale);
    grMtxF2L(mf, m);
}

void grNormalize(float *x, float *y, float *z)
{
    float m;

    m = 1 / sqrtf((*x) * (*x) + (*y) * (*y) + (*z) * (*z));
    *x *= m;
    *y *= m;
    *z *= m;
}

void grTranslateF(float mf[4][4], float x, float y, float z)
{
    grMtxIdentF(mf);

    mf[3][0] = x;
    mf[3][1] = y;
    mf[3][2] = z;
}

void grTranslate(Mtx *m, float x, float y, float z)
{
    Matrix4f mf;

    grTranslateF(mf, x, y, z);
    grMtxF2L(mf, m);
}

void grScaleF(float mf[4][4], float x, float y, float z)
{
    grMtxIdentF(mf);

    mf[0][0] = x;
    mf[1][1] = y;
    mf[2][2] = z;
    mf[3][3] = 1;
}

void grScale(Mtx *m, float x, float y, float z)
{
    Matrix4f mf;

    grScaleF(mf, x, y, z);
    grMtxF2L(mf, m);
}

void grMtxCatL(Mtx *m, Mtx *n, Mtx *res)
{
    float mf[4][4], nf[4][4], resf[4][4];

    grMtxL2F(mf, m);
    grMtxL2F(nf, n);
    grMtxCatF(mf, nf, resf);
    grMtxF2L(resf, res);
}

void grMtxCatF(float mf[4][4], float nf[4][4], float res[4][4])
{
    int i, j, k;
    float temp[4][4];

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            temp[i][j] = 0.0;
            for (k = 0; k < 4; k++)
            {
                temp[i][j] += mf[i][k] * nf[k][j];
            }
        }
    }

    /* make sure we handle case where result is an input */
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            res[i][j] = temp[i][j];
        }
    }
}

void grMtxXFMF(float mf[4][4], float x, float y, float z, float *ox, float *oy, float *oz)
{
    *ox = mf[0][0] * x + mf[1][0] * y + mf[2][0] * z + mf[3][0];
    *oy = mf[0][1] * x + mf[1][1] * y + mf[2][1] * z + mf[3][1];
    *oz = mf[0][2] * x + mf[1][2] * y + mf[2][2] * z + mf[3][2];
}

void grMtxF2L(float mf[4][4], Mtx *m)
{
    int i, j;
    int e1, e2;
    int *ai, *af;

    ai = (int *)&m->m[0][0];
    af = (int *)&m->m[2][0];

    for (i = 0; i < 4; i++)
        for (j = 0; j < 2; j++)
        {
            e1 = FTOFIX32(mf[i][j * 2]);
            e2 = FTOFIX32(mf[i][j * 2 + 1]);
            *(ai++) = (e1 & 0xffff0000) | ((e2 >> 16) & 0xffff);
            *(af++) = ((e1 << 16) & 0xffff0000) | (e2 & 0xffff);
        }
}

void grMtxL2F(float mf[4][4], Mtx *m)
{
    int i, j;
    unsigned int e1, e2;
    unsigned int *ai, *af;
    int q1, q2;

    ai = (unsigned int *)&m->m[0][0];
    af = (unsigned int *)&m->m[2][0];

    for (i = 0; i < 4; i++)
        for (j = 0; j < 2; j++)
        {
            e1 = (*ai & 0xffff0000) | ((*af >> 16) & 0xffff);
            e2 = ((*(ai++) << 16) & 0xffff0000) | (*(af++) & 0xffff);
            q1 = *((int *)&e1);
            q2 = *((int *)&e2);

            mf[i][j * 2] = FIX32TOF(q1);
            mf[i][j * 2 + 1] = FIX32TOF(q2);
        }
}

void grMtxIdentF(float mf[4][4])
{
    int i, j;

    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            if (i == j)
                mf[i][j] = 1.0;
            else
                mf[i][j] = 0.0;
}

void grLookAtF(float mf[4][4], float xEye, float yEye, float zEye,
             float xAt, float yAt, float zAt,
             float xUp, float yUp, float zUp)
{
    float len, xLook, yLook, zLook, xRight, yRight, zRight;

    grMtxIdentF(mf);

    xLook = xAt - xEye;
    yLook = yAt - yEye;
    zLook = zAt - zEye;

    /* Negate because positive Z is behind us: */
    len = -1.0 / sqrtf(xLook * xLook + yLook * yLook + zLook * zLook);
    xLook *= len;
    yLook *= len;
    zLook *= len;

    /* Right = Up x Look */

    xRight = yUp * zLook - zUp * yLook;
    yRight = zUp * xLook - xUp * zLook;
    zRight = xUp * yLook - yUp * xLook;
    len = 1.0 / sqrtf(xRight * xRight + yRight * yRight + zRight * zRight);
    xRight *= len;
    yRight *= len;
    zRight *= len;

    /* Up = Look x Right */

    xUp = yLook * zRight - zLook * yRight;
    yUp = zLook * xRight - xLook * zRight;
    zUp = xLook * yRight - yLook * xRight;
    len = 1.0 / sqrtf(xUp * xUp + yUp * yUp + zUp * zUp);
    xUp *= len;
    yUp *= len;
    zUp *= len;

    mf[0][0] = xRight;
    mf[1][0] = yRight;
    mf[2][0] = zRight;
    mf[3][0] = -(xEye * xRight + yEye * yRight + zEye * zRight);

    mf[0][1] = xUp;
    mf[1][1] = yUp;
    mf[2][1] = zUp;
    mf[3][1] = -(xEye * xUp + yEye * yUp + zEye * zUp);

    mf[0][2] = xLook;
    mf[1][2] = yLook;
    mf[2][2] = zLook;
    mf[3][2] = -(xEye * xLook + yEye * yLook + zEye * zLook);

    mf[0][3] = 0;
    mf[1][3] = 0;
    mf[2][3] = 0;
    mf[3][3] = 1;
}

void grLookAtReflectF(float mf[4][4], LookAt *l,
                    float xEye, float yEye, float zEye,
                    float xAt, float yAt, float zAt,
                    float xUp, float yUp, float zUp)
{
    float len, xLook, yLook, zLook, xRight, yRight, zRight;

    grMtxIdentF(mf);

    xLook = xAt - xEye;
    yLook = yAt - yEye;
    zLook = zAt - zEye;

    /* Negate because positive Z is behind us: */
    len = -1.0 / sqrtf(xLook * xLook + yLook * yLook + zLook * zLook);
    xLook *= len;
    yLook *= len;
    zLook *= len;

    /* Right = Up x Look */

    xRight = yUp * zLook - zUp * yLook;
    yRight = zUp * xLook - xUp * zLook;
    zRight = xUp * yLook - yUp * xLook;
    len = 1.0 / sqrtf(xRight * xRight + yRight * yRight + zRight * zRight);
    xRight *= len;
    yRight *= len;
    zRight *= len;

    /* Up = Look x Right */

    xUp = yLook * zRight - zLook * yRight;
    yUp = zLook * xRight - xLook * zRight;
    zUp = xLook * yRight - yLook * xRight;
    len = 1.0 / sqrtf(xUp * xUp + yUp * yUp + zUp * zUp);
    xUp *= len;
    yUp *= len;
    zUp *= len;

    /* reflectance vectors = Up and Right */

    l->l[0].l.dir[0] = FTOFRAC8(xRight);
    l->l[0].l.dir[1] = FTOFRAC8(yRight);
    l->l[0].l.dir[2] = FTOFRAC8(zRight);
    l->l[1].l.dir[0] = FTOFRAC8(xUp);
    l->l[1].l.dir[1] = FTOFRAC8(yUp);
    l->l[1].l.dir[2] = FTOFRAC8(zUp);
    l->l[0].l.col[0] = 0x00;
    l->l[0].l.col[1] = 0x00;
    l->l[0].l.col[2] = 0x00;
    l->l[0].l.pad1 = 0x00;
    l->l[0].l.colc[0] = 0x00;
    l->l[0].l.colc[1] = 0x00;
    l->l[0].l.colc[2] = 0x00;
    l->l[0].l.pad2 = 0x00;
    l->l[1].l.col[0] = 0x00;
    l->l[1].l.col[1] = 0x80;
    l->l[1].l.col[2] = 0x00;
    l->l[1].l.pad1 = 0x00;
    l->l[1].l.colc[0] = 0x00;
    l->l[1].l.colc[1] = 0x80;
    l->l[1].l.colc[2] = 0x00;
    l->l[1].l.pad2 = 0x00;

    mf[0][0] = xRight;
    mf[1][0] = yRight;
    mf[2][0] = zRight;
    mf[3][0] = -(xEye * xRight + yEye * yRight + zEye * zRight);

    mf[0][1] = xUp;
    mf[1][1] = yUp;
    mf[2][1] = zUp;
    mf[3][1] = -(xEye * xUp + yEye * yUp + zEye * zUp);

    mf[0][2] = xLook;
    mf[1][2] = yLook;
    mf[2][2] = zLook;
    mf[3][2] = -(xEye * xLook + yEye * yLook + zEye * zLook);

    mf[0][3] = 0;
    mf[1][3] = 0;
    mf[2][3] = 0;
    mf[3][3] = 1;
}

void grLookAtReflect(Mtx *m, LookAt *l, float xEye, float yEye, float zEye,
                   float xAt, float yAt, float zAt,
                   float xUp, float yUp, float zUp)
{
    float mf[4][4];

    grLookAtReflectF(mf, l, xEye, yEye, zEye, xAt, yAt, zAt,
                   xUp, yUp, zUp);

    grMtxF2L(mf, m);
}
