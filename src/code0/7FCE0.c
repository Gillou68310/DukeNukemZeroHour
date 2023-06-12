#include "common.h"
#include "code0/main.h"
#include "code0/4600.h"
#include "code0/7F6A0.h"
#include "code0/7FCE0.h"
#include "code0/82480.h"
#include "code0/edl.h"
#include "code0/code0.h"
#include "code1/code1.h"
#include "code1/EB300.h"

typedef struct {
    /*0x00*/ code0UnkStruct15 *unk0;
    /*0x04*/ s8 *unk4;
    /*0x08*/ s8 *unk8;
    /*0x0C*/ s8 *unkC;
} _7FCE0UnkStruct1;

/*.data*/
/*800DFA40*/ EXTERN_DATA code0UnkStruct15 D_800DFA40[2];
/*800DFA68*/ EXTERN_DATA code0UnkStruct15 D_800DFA68[2];
/*800DFA90*/ EXTERN_DATA code0UnkStruct15 D_800DFA90[2];
/*800DFAB8*/ EXTERN_DATA code0UnkStruct15 D_800DFAB8[2];
/*800DFAE0*/ EXTERN_DATA code0UnkStruct15 D_800DFAE0[2];
/*800DFB08*/ EXTERN_DATA code0UnkStruct15 D_800DFB08[61];
/*800DFFCC*/ EXTERN_DATA code0UnkStruct15 D_800DFFCC[54];
/*800E0404*/ EXTERN_DATA code0UnkStruct15 D_800E0404[4];
/*800E0454*/ EXTERN_DATA code0UnkStruct15 D_800E0454[2];
/*800E047C*/ EXTERN_DATA code0UnkStruct15 D_800E047C[23];
/*800E064C*/ EXTERN_DATA code0UnkStruct15 D_800E064C[15];
/*800E0778*/ EXTERN_DATA code0UnkStruct15 D_800E0778[3];
/*800E07B4*/ EXTERN_DATA code0UnkStruct15 D_800E07B4[2];
/*800E07DC*/ EXTERN_DATA code0UnkStruct15 D_800E07DC[2];
/*800E0804*/ EXTERN_DATA code0UnkStruct15 D_800E0804[8];
/*800E08B0*/ EXTERN_DATA STATIC u8 D_800E08B0[62];
/*800E0990*/ EXTERN_DATA STATIC s32 D_800E0990;
/*800E0B14*/ EXTERN_DATA STATIC _7FCE0UnkStruct1 D_800E0B14[2];

/*.comm*/
/*80199980*/ s32 D_80199980;

/*.text*/
STATIC void func_8007F7E8(void *, s32, s32, s32, f32);

/*8007F0E0*/
void func_8007F0E0(void)
{
    if (D_8012FD8C->unk10 != 0)
    {
        gDPPipeSync(gpDisplayList++);
        gDPSetCycleType(gpDisplayList++, G_CYC_1CYCLE);

        if (D_8012FD8C->unk10 >= 255)
        {
            gDPSetRenderMode(gpDisplayList++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
        }
        else
        {
            gDPSetRenderMode(gpDisplayList++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
        }

        gDPSetCombineMode(gpDisplayList++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        gDPSetPrimColor(gpDisplayList++, 0, 0, D_8012FD8C->unk68.r, D_8012FD8C->unk68.g, D_8012FD8C->unk68.b, D_8012FD8C->unk10);
        gDPSetTextureFilter(gpDisplayList++, G_TF_POINT);
        gDPSetTexturePersp(gpDisplayList++, G_TP_NONE);
        gDPPipeSync(gpDisplayList++);
        gSPClearGeometryMode(gpDisplayList++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
        gSPSetGeometryMode(gpDisplayList++, G_SHADE | G_SHADING_SMOOTH);
        gDPPipeSync(gpDisplayList++);

        gDPLoadTextureBlock(gpDisplayList++, D_800E08B0, G_IM_FMT_CI, G_IM_SIZ_8b,
                            8, 8, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                            0, 0, 0, 0);

        gDPLoadTLUT_pal256(gpDisplayList++, D_80138778);

        gDPFillRectangle(gpDisplayList++, 0, 0, gScreenWidth, gScreenHeight);
        gDPPipeSync(gpDisplayList++);

        gDPSetRenderMode(gpDisplayList++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineMode(gpDisplayList++, G_CC_MODULATEIA, G_CC_MODULATEIA);
        gDPSetTextureFilter(gpDisplayList++, G_TF_BILERP);
        gDPSetTexturePersp(gpDisplayList++, G_TP_PERSP);
        gDPPipeSync(gpDisplayList++);
        gSPSetGeometryMode(gpDisplayList++, G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
    }
}

/*8007F540*/
static void func_8007F540(s32 arg0, u8 arg1, u8 arg2, s8 arg3)
{
    gDPPipeSync(gpDisplayList++);
    gDPSetCycleType(gpDisplayList++, G_CYC_1CYCLE);
    gDPSetRenderMode(gpDisplayList++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineMode(gpDisplayList++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);

    if (arg0 & 0x8000000)
    {
        gDPSetPrimColor(gpDisplayList++, 0, 0, 0x20, 0xFF, 0x20, arg1);
    }
    else if (arg0 & 0x4000000)
    {
        gDPSetPrimColor(gpDisplayList++, 0, 0, 0xFF, 0x00, 0x00, arg1);
    }
    else
    {
        gDPSetPrimColor(gpDisplayList++, 0, 0, arg2, arg2, arg2, arg1);
    }

    D_80199980 = 0;
    gDPSetTextureLUT(gpDisplayList++, G_TT_RGBA16);
    gDPSetTextureFilter(gpDisplayList++, G_TF_POINT);
    gDPSetTexturePersp(gpDisplayList++, G_TP_NONE);
    gSPClearGeometryMode(gpDisplayList++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gSPSetGeometryMode(gpDisplayList++, G_SHADE | G_SHADING_SMOOTH);
    gSPSetGeometryMode(gpDisplayList++, G_ZBUFFER);
}

/*8007F71C*/
static void func_8007F71C(void)
{
    gDPPipeSync(gpDisplayList++);
    gDPSetTextureLUT(gpDisplayList++, G_TT_RGBA16);
    gDPSetTexturePersp(gpDisplayList++, G_TP_PERSP);
    gDPSetTextureFilter(gpDisplayList++, G_TF_BILERP);
    gDPSetCombineMode(gpDisplayList++, G_CC_MODULATEIA, G_CC_MODULATEIA);
    gSPSetGeometryMode(gpDisplayList++, G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
}

/*8007F7E8*/
INCLUDE_ASM("nonmatchings/src/code0/7FCE0", func_8007F7E8);

/*8007FC08*/
code0UnkStruct16 *func_8007FC08(code0UnkStruct15 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    code0UnkStruct16 *ptr;

    ptr = func_8007EC10(1);
    ptr->unk34 = arg2;
    ptr->unk38 = arg3;
    ptr->unk11 = 0xFF;
    ptr->unk70 = (intptr_t)arg0;
    ptr->unk3C = arg4;
    if (arg0 != NULL)
    {
        if (arg1 != 0)
            ptr->unk74 = arg1;
        else
            ptr->unk74 = arg0->unk4;
    }
    ptr->unk78 = 0;
    return ptr;
}

/*8007FCC8*/
STATIC void func_8007FCC8(void)
{
    f32 unk34, unk38, unk40;

    unk40 = D_8012FD8C->unk40;
    unk34 = D_8012FD8C->unk34;
    unk38 = D_8012FD8C->unk38;

    if (!(unk40 <= 0.1) && (D_8012FD8C->unk70 != NULL))
    {
        func_8007F540(D_8012FD8C->unkC, D_8012FD8C->unk10, D_8012FD8C->unk11, D_8012FD8C->unk78);
        func_8007F7E8((void *)D_8012FD8C->unk70, D_8012FD8C->unk74, unk34, unk38, unk40);
        func_8007F71C();
    }
}

/*8007FD8C*/
void func_8007FD8C(code0UnkStruct15 *arg0, s32 arg1)
{
    edl_80081688(&D_8010A938, arg1);
    for (; arg0->unk0 != -1; arg0++)
    {
        arg0->unk0 = arg0->unk8 + (intptr_t)D_8010A938;
        arg0->unk4 = arg0->unkC + (intptr_t)D_8010A938;
    }
}

/*8007FE04*/
void func_8007FE04(s32 unused, s32 id, void *dst)
{
    edl_80081760(&D_8010A938, id, dst);
}

/*8007FE2C*/
code0UnkStruct16 *func_8007FE2C(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5)
{
    code0UnkStruct16 *ptr;

    ptr = func_8007EC10(4);
    ptr->unk34 = arg1;
    ptr->unk38 = arg2;
    ptr->unk3C = arg3;
    ptr->unk70 = (intptr_t)arg0;
    ptr->unk11 = 0xFF;
    ptr->unk14 = 0;
    ptr->unk74 = arg4;
    ptr->unk78 = arg5;
    return ptr;
}

/*8007FEDC*/
void func_8007FEDC(void *src, u8 arg1)
{
    Bmemcpy((D_800E0990 * 50) + D_80118260, src, 50);
    func_8007FE2C((D_800E0990 * 50) + D_80118260, 24, (D_800E0990 * 17) + 48, 64, 0, 0)->unk11 = arg1;
    D_800E0990++;
}

/*8007FF94*/
void func_8007FF94(void *src, u8 arg1)
{
    Bmemcpy((D_800E0990 * 50) + D_80118260, src, 50);
    func_8007FE2C((D_800E0990 * 50) + D_80118260, gScreenWidth / 2, (D_800E0990 * 17) + 48, 64, 1, 0)->unk11 = arg1;
    D_800E0990++;
}

/*80080060*/
void func_80080060(void)
{
    D_800E0990 = 0;
    func_8007F050();
    func_8007FC08(D_800DFA90, 0, 0, 0, 500);
}

/*800800A8*/
void func_800800A8(s32 arg0)
{
    func_80080060();
    D_800E0990 = arg0;
}

/*800800D8*/
STATIC s32 func_800800D8(u8 *arg0, s32 arg1)
{
    s32 ret;
    u8 i;
    s8 *ptr;

    ret = 0;
    ptr = D_800E0B14[arg1].unkC;

    for (i = *arg0++; i != 0; i = *arg0++)
        ret += ptr[i-32]-1;

    return ret;
}

/*8008011C*/
STATIC void func_8008011C(void)
{
    code0UnkStruct15 *ptr;
    s8 *ptr2;
    s8 *ptr3;
    u8 *unk70;
    s32 unk34, unk38, unk4;
    u8 i;

    unk34 = D_8012FD8C->unk34;
    ptr = D_800E0B14[D_8012FD8C->unk78].unk0;
    ptr2 = D_800E0B14[D_8012FD8C->unk78].unk8;
    ptr3 = D_800E0B14[D_8012FD8C->unk78].unkC;

    if (D_8012FD8C->unk74 & 1)
        unk34 -= (func_800800D8((void *)D_8012FD8C->unk70, D_8012FD8C->unk78) / 2);

    if (D_8012FD8C->unk74 & 2)
        unk34 -= func_800800D8((void *)D_8012FD8C->unk70, D_8012FD8C->unk78);

    unk38 = D_8012FD8C->unk38;
    func_8007F540(D_8012FD8C->unkC, D_8012FD8C->unk10, D_8012FD8C->unk11, 0);

    unk70 = (u8 *)D_8012FD8C->unk70;
    for (i = *unk70++; i != 0; i = *unk70++)
    {
        i -= 32;
        if (ptr2[i] != -1)
        {
            unk4 = ptr[ptr2[i]].unk4;
            func_8007F7E8(&ptr[ptr2[i]], unk4, unk34, unk38, D_8012FD8C->unk40);
        }
        unk34 += ptr3[i]-1;
    }
    func_8007F71C();
}

/*800802C0*/
code0UnkStruct16 *func_800802C0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    code0UnkStruct16 *ptr;

    ptr = func_8007EC10(5);
    ptr->unk34 = arg1;
    ptr->unk38 = arg2;
    ptr->unk3C = arg3;
    ptr->unk70 = (intptr_t)arg0;
    ptr->unk11 = 0xFF;
    ptr->unk6B.b = 0xFF;
    ptr->unk6B.g = 0xFF;
    ptr->unk6B.r = 0xFF;
    ptr->unk14 = 0;
    ptr->unk74 = arg4;
    return ptr;
}

/*8008036C*/
void func_8008036C(void)
{
    code0UnkStruct16 copy;
    code0UnkStruct16 *ptr;
    Mtx mtx1, mtx2, mtx3;
    s32 value;
    f32 unk34;
    u8 *unk70;
    s8 *ptr2;
    s8 *ptr3;
    u8 i;

    gDPPipeSync(gpDisplayList++);
    gSPMatrix(gpDisplayList++, &gpDynamic->projection, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gpDisplayList++, &gpDynamic->viewing, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
    gSPPerspNormalize(gpDisplayList++, gPerspNorm);
    gDPSetColorDither(gpDisplayList++, G_CD_BAYER);
    gDPSetCombineMode(gpDisplayList++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetEnvColor(gpDisplayList++, D_8012FD8C->unk68.r, D_8012FD8C->unk68.g, D_8012FD8C->unk68.b, 0x00);
    gDPSetPrimColor(gpDisplayList++, 0, 0, D_8012FD8C->unk6B.r, D_8012FD8C->unk6B.g, D_8012FD8C->unk6B.b, D_8012FD8C->unk12);
    gDPSetRenderMode(gpDisplayList++, G_RM_XLU_SURF, G_RM_XLU_SURF2);

    Bmemcpy(&copy, D_8012FD8C, sizeof(code0UnkStruct16));

    ptr = D_8012FD8C;
    ptr2 = D_800E0B14[1].unk8;
    ptr3 = D_800E0B14[1].unkC;
    unk34 = D_8012FD8C->unk34;

    if (D_8012FD8C->unk74 & 2)
        unk34 -= (func_800800D8((void *)D_8012FD8C->unk70, 1) * ptr->unk40);

    if (D_8012FD8C->unk74 & 1)
        unk34 -= (func_800800D8((void *)D_8012FD8C->unk70, 1) * ptr->unk40) / 2.0f;

    unk70 = (u8 *)D_8012FD8C->unk70;
    for (i = *unk70++, D_8012FD8C = &copy; i != 0; i = *unk70++)
    {
        i -= 32;
        value = ((ptr3[i]-1) * ptr->unk40);
        if (ptr2[i] != -1)
        {
            D_8012FD8C->unk34 = unk34 - (gScreenWidth / 2) + (value / 2);
            D_8012FD8C->unk38 = -ptr->unk38 + 120.0f;
            D_8012FD8C->unk3C = ptr->unk3C;
            guTranslate(&mtx1, -D_8012FD8C->unk34 / 4.0f, D_8012FD8C->unk38 / 4.0f, D_8012FD8C->unk3C / 4.0f);
            guScale(&mtx3, D_8012FD8C->unk40, D_8012FD8C->unk40, D_8012FD8C->unk40);
            func_80082410(&mtx2, -D_8012FD8C->unk4C, D_801CA144, -D_8012FD8C->unk54);
            guMtxCatL(&mtx1, &gpDynamic->identity, &gpDynamic->mtx5[D_801AE528]);
            guMtxCatL(&mtx3, &gpDynamic->mtx5[D_801AE528], &gpDynamic->mtx5[D_801AE528]);
            guMtxCatL(&mtx2, &gpDynamic->mtx5[D_801AE528], &gpDynamic->mtx5[D_801AE528]);
            guMtxCatL(&gpDynamic->scale, &gpDynamic->mtx5[D_801AE528], &gpDynamic->mtx5[D_801AE528]);
            gSPMatrix(gpDisplayList++, &gpDynamic->mtx5[D_801AE528], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            D_801AE528++;
            gSPDisplayList(gpDisplayList++, D_8012C478[D_801CE5E8[ptr2[i]].unk0]);
        }
        unk34 += value;
    }
    D_8012FD8C = ptr;
}
