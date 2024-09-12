#ifndef _84490_H_
#define _84490_H_

#include "common.h"
#include "code0/code0.h"

s32 swap32(u8 *);
s32 swap16(u8 *);
void func_80085EBC(Vtx *vtx, s32 vertex_count, Gfx **dlist, s32 dlist_count, s32);
void func_800861F4(code0UnkStruct20 *, f32, f32, f32, f32,
                   f32, s32, Vtx *vtx, s32 vtx_count, Gfx *dlist, s32 dlist_count);

extern s32 D_800E0F58;

#endif
