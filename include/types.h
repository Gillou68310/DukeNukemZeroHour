#ifndef _TYPES_H_
#define _TYPES_H_

#include "common.h"

#ifndef bool
typedef u8 bool;
#endif 
typedef f32 Matrix4f[4][4];
typedef f32 Vec4f[4];
typedef u8 Addr[];
typedef void (*ProcPointer)(void);

typedef struct {
    u8 r, g, b;
} Color;

typedef struct {
    s16 ob[3];	/* x, y, z */
    s16 tc[2];	/* texture coord */
} VertexC;

typedef struct {
    s16 ob[3];	/* x, y, z */
    s16 tc[2];	/* texture coord */
    u8	cn[4];	/* color & alpha */
} VertexV;

typedef struct {
    s16 ob[3];	/* x, y, z */
    s16 tc[2];	/* texture coord */
    s8  n[3];	/* normal */
    u8  a;      /* alpha  */
} VertexN;

typedef union {
    VertexV v;  /* Use this one for colors  */
    VertexN n;  /* Use this one for normals */
} Vertex;

#endif
