#include "common.h"
#include "ctype.h"
#include "code0/main.h"
#include "code0/9410.h"
#include "code0/1A7C0.h"
#include "code0/24610.h"
#include "code0/41940.h"
#include "code0/graphics.h"
#include "code0/pragmas.h"
#include "code0/code0.h"
#include "code1/EB300.h"

/*.data*/
/*800DCA00*/ EXTERN_DATA STATIC s16 D_800DCA00;

/*.comm*/
/*80105548*/ s32 D_80105548; /*vz*/
/*8010570C*/ s32 D_8010570C;
/*80105714*/ s32 D_80105714;
/*8012EB44*/ s16 D_8012EB44;
/*8012F910*/ s32 D_8012F910; /*vx*/
/*8013860C*/ s32 D_8013860C;
/*8013867C*/ u8 D_8013867C;
/*801387C0*/ f32 D_801387C0;
/*8013F954*/ f32 D_8013F954;
/*80168CFC*/ u8 D_80168CFC;
/*80197DD8*/ s32 D_80197DD8; /*vy*/
/*801A1990*/ f32 D_801A1990;
/*801ACBDC*/ f32 D_801ACBDC;
/*801AE90C*/ u8 D_801AE90C;
/*801AE91C*/ s16 D_801AE91C;
/*801B0D34*/ s16 D_801B0D34;

/*.text*/
STATIC void func_8001A8EC(s16, s16, s32 tileid, s16, u8);
static void func_8001BFB0(code0unkStruct12 *);
static void func_8001C490(s16);

/*FIXME: This breaks sky*/
#ifdef NON_EQUIVALENT
/*80019BC0*/
void func_80019BC0(void)
{
    s16 i;
    code0unkStruct12 *ptr;
    code0unkStruct12 *ptr2;
    s16 nexti;

    i = gHeadSpriteStat[104];
    D_8012EB44 = -1;
    D_801AE91C = -1;
    D_801AE90C = 0;
    D_8012FC40 = 1;
    gSkyTopR = gpMapInfo[gMapNum].unk30;
    gSkyBottomR = gpMapInfo[gMapNum].unk3C;
    gSkyTopG = gpMapInfo[gMapNum].unk34;
    gSkyBottomG = gpMapInfo[gMapNum].unk40;
    gSkyTopB = gpMapInfo[gMapNum].unk38;
    gSkyBottomB = gpMapInfo[gMapNum].unk44;
    D_8012FC48[0].unk10 = 0x400;
    D_8012FC48[0].unk14 = 0x800;
    D_8012FC48[1].unk10 = 0x400;
    D_8012FC48[1].unk14 = 0x800;
    D_8012FC48[0].unk18 = -1;
    D_8012FC48[1].unk18 = -1;

    while (i >= 0)
    {
        nexti = gNextSpriteStat[i];
        switch (gpSprite[i].picnum)
        {
        case 18:
            gSkyTopR = gpSprite[i].unk18;
            gSkyTopG = gpSprite[i].unk1A;
            gSkyTopB = gpSprite[i].unk1C;
            break;
        case 19:
            gSkyBottomR = gpSprite[i].unk18;
            gSkyBottomG = gpSprite[i].unk1A;
            gSkyBottomB = gpSprite[i].unk1C;
            break;
        case 20:
            if (gpSprite[i].cstat & 8)
                ptr = &D_8012FC48[1];
            else
                ptr = &D_8012FC48[0];

            ptr->fog.r = gpSprite[i].unk18;
            ptr->fog.g = gpSprite[i].unk1A;
            ptr->fog.b = gpSprite[i].unk1C;
            break;
        case 21:
            if (gpSprite[i].cstat & 8)
            {
                D_801AE904[1] = gpSprite[i].ang;
                D_800FE9C8[1] = gpSprite[i].unk18;
                ptr2 = &D_8012FC48[1];
            }
            else
            {
                D_801AE904[0] = gpSprite[i].ang;
                D_800FE9C8[0] = gpSprite[i].unk18;
                ptr2 = &D_8012FC48[0];
            }

            ptr2->unk18 = gpSprite[i].unk1E;
            ptr2->unk8 = ((-cosf((gpSprite[i].ang * 0.0030679615757714844)) * gpSprite[i].unk18) / 50.0f);
            ptr2->unkC = ((-sinf((gpSprite[i].ang * 0.0030679615757714844)) * gpSprite[i].unk18) / 50.0f);
            ptr2->unk0 = gpSprite[i].unk20 * 10;

            if (gpSprite[i].unk25 == 0)
                ptr2->unk0 = -ptr2->unk0;
            break;
        case 24:
            D_8012EB44 = gpSprite[i].unk1E;
            D_80199942 = gpSprite[i].unk20;
            break;
        case 25:
            D_801AE91C = gpSprite[i].unk1E;
            D_801AE90C = gpSprite[i].unk25 == 0;
            D_80105714 = (cosf((gpSprite[i].ang * 0.0030679615757714844)) * 10240.0f);
            D_8010570C = (sinf((gpSprite[i].ang * 0.0030679615757714844)) * 10240.0f);
            D_8013860C = (tanf((gpSprite[i].unk20 * 0.0030679615757714844)) * 10240.0f * -16.0f);
            break;
        }
        deleteSprite(i);
        i = nexti;
    }
}
#else
/*80019BC0*/
INCLUDE_ASM("nonmatchings/src/code0/1A7C0", func_80019BC0);
#endif

/*8001A1A4*/
INCLUDE_ASM("nonmatchings/src/code0/1A7C0", func_8001A1A4);

/*8001A8EC*/
INCLUDE_ASM("nonmatchings/src/code0/1A7C0", func_8001A8EC);

/*8001AAEC*/
static void func_8001AAEC(void)
{
    u8 cond;
    u16 cstat;
    s16 hitsect, hitwall, hitsprite;
    s32 hitx, hity, hitz;

    cond = 0;
    if ((klabs(D_801A1990) < 200.0f) && (klabs(D_801387C0) < 200.0f))
    {
        cstat = gpSprite[gPlayer[D_801B0820].unk4A].cstat;

        if ((gPlayer[D_801B0820].unk6A < 255) || (gPlayer[D_801B0820].unk60 == 0))
            gpSprite[gPlayer[D_801B0820].unk4A].cstat = cstat & 0xFEFE;

        hitScan(D_801A6D84,
                D_800FE3F0,
                D_80199640,
                D_8012F6F4,
                D_8012F910,
                D_80197DD8,
                D_80105548,
                &hitsect,
                &hitwall,
                &hitsprite,
                &hitx,
                &hity,
                &hitz,
                0x01000040);

        gpSprite[gPlayer[D_801B0820].unk4A].cstat = cstat;

        if ((hitwall == -1) && (hitsprite == -1))
        {
            if (gpSector[hitsect].ceilingstat & 1)
                cond = 1;
            if (gpSector[hitsect].floorstat & 1)
                cond = 1;
        }
        if ((hitwall != -1) && (hitz < gpSector[gpWall[hitwall].nextsector].floorz) && (gpWall[hitwall].cstat & 0x400))
            cond = 1;
    }

    if (D_80168CFC != 0)
    {
        if (cond)
            D_800DCA00 = CLAMP_MAX(D_800DCA00+32, 256);
        else
            D_800DCA00 = CLAMP_MIN(D_800DCA00-32, 0);
    }
    else if (canSee(D_801A6D84,
        D_800FE3F0,
        D_80199640,
        D_8012F6F4,
        D_8012F910,
        D_80197DD8,
        D_80105548,
        D_801B0D34) == 0)
    {
        D_800DCA00 = 0;
    }

    if (D_800DCA00 > 0)
    {
        func_8000A070();
        func_80028F04(255, 255, 255, 255, 128, 0);
        func_8001A8EC(328, 1, 5539, 128, 0);
        func_8001A8EC(292, 1, 5539, 128, 0);
        func_8001A8EC(99, 3, 5539, 196, 1);
        func_8001A8EC(64, 2, 5539, 128, 2);
        func_8001A8EC(-99, 1, 5539, 128, 3);
        func_8001A8EC(-139, 2, 5539, 128, 1);
        func_8001A8EC(-222, 3, 5539, 196, 0);
        func_8001A8EC(-412, 4, 5539, 128, 2);
        func_8001A8EC(-496, 4, 5548, 128, 3);

        if ((D_8013867C != 0) && (D_801AE914 == 0))
        {
            hitx = ((klabs(D_801A1990) + klabs(D_801387C0)) * 200.0f) / 100.0f;
            hitx = 200 - hitx;
            hitx = (hitx * D_800DCA00) / 256;

            if (hitx > 0)
            {
                hitx = CLAMP_MAX(hitx, 255);
                func_8000EA0C(D_801B0820, 255, 255, 255, hitx);
            }
        }
    }
}

/*8001B0E0*/
static void func_8001B0E0(s32 x, s32 y, s32 z, f32 *fx, f32 *fy)
{
    f32 fx_, fy_, fz_, f1, f2, f3;

    fx_ = x / 4.0;
    fy_ = y / 4.0;
    fz_ = z / 64.0;

    f1 = ((D_8012B948[0][0] * fx_) +
          (D_8012B948[1][0] * fy_) +
          (D_8012B948[2][0] * fz_) +
           D_8012B948[3][0]);

    f2 = ((D_8012B948[0][1] * fx_) +
          (D_8012B948[1][1] * fy_) +
          (D_8012B948[2][1] * fz_) +
           D_8012B948[3][1]);

    f3 = ((D_8012B948[0][3] * fx_) +
          (D_8012B948[1][3] * fy_) +
          (D_8012B948[2][3] * fz_) +
           D_8012B948[3][3]);

    if (f3 > 0.0f)
    {
        fx_ = f1 / f3;
        fy_ = f2 / f3;

        if ((fx_ < -2.0f) || (fx_ > 2.0f) || (fy_ < -2.0f) || (fy_ > 2.0f))
        {
            fx_ = 9999.0f;
            fy_ = 9999.0f;
        }
        else
        {
            fx_ *= D_80199110;
            fy_ *= -D_801A1980;
        }
    }
    else
    {
        fx_ = 9999.0f;
        fy_ = 9999.0f;
    }

    *fx = fx_;
    *fy = fy_;
}

/*8001B2D0*/
void func_8001B2D0(void)
{
    s16 i;
    f32 f1;
    s32 x1, x2, x3;
    s32 y1, y2, y3;
    s32 z1, z2, z3;

    if ((D_8012C470 < 2) && (D_800DEEA0 != 0))
    {
        if ((D_801AE90C != 0) && (D_8012FC40 == 0))
        {
            D_80168CFC = 1;
            D_8013867C = 1;
            D_801A1990 = D_8013F954;
            D_801387C0 = D_801ACBDC;
            D_8012F910 = D_80105714;
            D_80197DD8 = D_8010570C;
            D_80105548 = D_8013860C;
            func_8001AAEC();
        }

        i = gHeadSpriteStat[4];
        D_80168CFC = 0;
        D_8013867C = 0;
        f1 = D_800DCA00;

        while (i >= 0)
        {
            if (gpSprite[i].lotag == 21)
            {
                x1 = gpSprite[i].x;
                y1 = gpSprite[i].y;
                z1 = gpSprite[i].z;
                D_8012F910 = x1;
                D_80197DD8 = y1;
                D_80105548 = z1;
                func_8001B0E0(x1, y1, z1, &D_801A1990, &D_801387C0);
                D_800DCA00 = 256;
                D_801B0D34 = gpSprite[i].sectnum;
                if (D_801A1990 != 9999.0f)
                    func_8001AAEC();
            }
            i = gNextSpriteStat[i];
        }

        i = gHeadSpriteStat[50];
        while (i >= 0)
        {
            if (gpSprite[i].unk16 == 52)
            {
                x2 = gpSprite[i].x;
                y2 = gpSprite[i].y;
                z2 = gpSprite[i].z;
                D_8012F910 = x2;
                D_80197DD8 = y2;
                D_80105548 = z2;
                func_8001B0E0(x2, y2, z2, &D_801A1990, &D_801387C0);
                D_801B0D34 = gpSprite[i].sectnum;
                D_800DCA00 = CLAMP_MAX((gpSprite[i].xrepeat * 2), 256);
                if (D_801A1990 != 9999.0f)
                    func_8001AAEC();
            }
            i = gNextSpriteStat[i];
        }

        i = gHeadSpriteStat[310];
        while (i >= 0)
        {
            if ((gpSprite[i].unk16 == 79) || (gpSprite[i].unk16 == 68))
            {
                x3 = gpSprite[i].x;
                y3 = gpSprite[i].y;
                z3 = gpSprite[i].z;
                D_8012F910 = x3;
                D_80197DD8 = y3;
                D_80105548 = z3;
                func_8001B0E0(x3, y3, z3, &D_801A1990, &D_801387C0);
                D_801B0D34 = gpSprite[i].sectnum;
                D_800DCA00 = 256 - D_8013B2D0[i].unk6;
                if (D_801A1990 != 9999.0f)
                    func_8001AAEC();
            }
            i = gNextSpriteStat[i];
        }
        D_800DCA00 = f1;
    }
}

/*8001B740*/
static void func_8001B740(void)
{
    f32 fx, fy, fz, f1, f2, f3, f4, f5;

    if ((D_801AE91C != -1) && (D_8012C470 < 2) && (D_8012FC40 == 0))
    {
        fx = D_801A6D84 + D_80105714;
        fy = D_800FE3F0 + D_8010570C;
        fz = D_80199640 + D_8013860C;
        fx = fx / 4.0;
        fy = fy / 4.0;
        fz = fz / 64.0;

        f1 = ((D_8012B948[0][0] * fx) +
              (D_8012B948[1][0] * fy) +
              (D_8012B948[2][0] * fz) +
               D_8012B948[3][0]);

        f2 = ((D_8012B948[0][1] * fx) +
              (D_8012B948[1][1] * fy) +
              (D_8012B948[2][1] * fz) +
               D_8012B948[3][1]);

        f3 = ((D_8012B948[0][3] * fx) +
              (D_8012B948[1][3] * fy) +
              (D_8012B948[2][3] * fz) +
               D_8012B948[3][3]);

        D_801ACBDC = -12345.0f;
        D_8013F954 = -12345.0f;

        if (f3 > 0.0f)
        {
            f4 = f2 / f3;
            f5 = f1 / f3;

            if ((f4 < -2.0f) || (f4 > 2.0f) || (f5 < -2.0f) || (f5 > 2.0f))
                return;

            func_8000A070();
            if (D_801AE90C)
                func_80028F04(255, 255, 255, 255, 128, 0);
            else
                func_80028F04(255, 255, 255, 255, 255, 255);

            D_8013F954 = f5 * D_80199110;
            D_801ACBDC = -f4 * D_801A1980;
            fy = ((gPlayer[D_801B0820].unk6E * 2) * D_80199110) / 40960.0;
            fx = ((gPlayer[D_801B0820].unk6E * 2) * D_801A1980) / 30720.0;

            if (gMapNum == MAP_ZERO_HOUR)
            {
                fy *= 2.0f;
                fx *= 2.0f;
            }
            func_80027C18(D_8013F954 + D_80168C9C, D_801ACBDC + D_801A2684, fy, fx, getTileNum(D_801AE91C), 0);
        }
    }
}

/*8001BB1C*/
void func_8001BB1C(void)
{
    if (D_8012FC40 == 0)
    {
        func_8000A070();
        func_80028F04(gSkyBottomR,
                      gSkyBottomG,
                      gSkyBottomB,
                      gSkyTopR,
                      gSkyTopG,
                      gSkyTopB);

        gDPSetRenderMode(gpDisplayList++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
        func_8000BDB0(5946);
        gSPTextureRectangle(gpDisplayList++, 0, 0, gScreenWidth*4, gScreenHeight*4,
                            G_TX_RENDERTILE, 0, 0, 0, (16384/gScreenHeight));
        func_8001B740();
    }
}

/*8001BC74*/
static u8 func_8001BC74(s16 arg0, s16 arg1)
{
    if (((arg0 == 0) || (arg0 == 4) || (arg1 == 0) || (arg1 == 4)))
        return 0;
    else
        return ((arg0 == 2) && (arg1 == 2)) ? 0xFF : 0xC8;
}

/*8001BCDC*/
void func_8001BCDC(void)
{
    Mtx mtx1;
    Mtx mtx2;

    if ((D_8012C470 < 2) && (D_8012FC40 == 0)
        && ((D_8012FC48[0].unk18 != -1) || (D_8012FC48[1].unk18 != D_8012FC48[0].unk18) || (D_8012EB44 != D_8012FC48[1].unk18)))
    {

        D_8012FC48[0].unk0 += D_8012FC48[0].unk8;
        D_8012FC48[0].unk0 &= 0x7FF;
        D_8012FC48[0].unk4 += D_8012FC48[0].unkC;
        D_8012FC48[0].unk4 &= 0x7FF;
        D_8012FC48[1].unk0 += D_8012FC48[1].unk8;
        D_8012FC48[1].unk0 &= 0x7FF;
        D_8012FC48[1].unk4 += D_8012FC48[1].unkC;
        D_8012FC48[1].unk4 &= 0x7FF;

        grScale(&mtx2, 8.0f, 8.0f, 0.5f);
        grTranslate(&mtx1, (D_801A6D84 / 4.0), (D_800FE3F0 / 4.0), (D_80199640 / 64.0));
        grMtxCatL(&mtx2, &mtx1, &gpDynamic->mtx4);
        gSPMatrix(gpDisplayList++, OS_K0_TO_PHYSICAL(&gpDynamic->mtx4), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gDPSetAlphaCompare(gpDisplayList++, G_AC_NONE);
        gDPSetAlphaDither(gpDisplayList++, G_AD_NOISE);
        gDPSetColorDither(gpDisplayList++, G_CD_NOISE);
        gDPSetTextureLUT(gpDisplayList++, G_TT_NONE);
        gDPSetRenderMode(gpDisplayList++, G_RM_FOG_SHADE_A, G_RM_AA_XLU_SURF2);
        gDPSetCombineMode(gpDisplayList++, G_CC_MODULATEIA, G_CC_MODULATEIA2);
        gSPClearGeometryMode(gpDisplayList++, G_CULL_BOTH | G_FOG);

        func_8001BFB0(&D_8012FC48[0]);
        func_8001BFB0(&D_8012FC48[1]);
        func_8001C490(D_8012EB44);
    }
}

/*8001BFB0*/
static void func_8001BFB0(code0unkStruct12 *arg0)
{
    f32 x1, x2, x3, x4;
    s32 tc1, tc2, tc3, tc4;
    u8 alpha;
    s16 i, j;

    if (arg0->unk18 != -1)
    {
        func_8000C76C();
        func_8000BDB0(arg0->unk18);
        gDPSetFogColor(gpDisplayList++, arg0->fog.r, arg0->fog.g, arg0->fog.b, 0xFF);

        for (i = 0; i < 4; i++)
        {
            tc1 = (i * arg0->unk10) + arg0->unk0;
            tc2 = tc1 + arg0->unk10;
            tc1 &= 0x7FFF;
            tc2 &= 0x7FFF;
            x1 = (i - 2) << 10;
            x2 = x1 + 1024.0f;

            for (j = 0; j < 4; j++)
            {
                x3 = j; /*FAKEMATCH*/
                tc3 = (j * arg0->unk14) + arg0->unk4;
                tc4 = tc3 + arg0->unk14;
                x3 = ((j - 2) << 10);
                x4 = x3 + 1024.0f;

                alpha = func_8001BC74(i, j);
                gpVertexN64->v.ob[0] = x1;
                gpVertexN64->v.ob[1] = x3;
                gpVertexN64->v.ob[2] = ((arg0->unk1C / 32.0) * alpha) / 256.0;
                gpVertexN64->v.tc[0] = tc1;
                gpVertexN64->v.tc[1] = tc3 & 0x7FFF;
                gpVertexN64->v.cn[0] = arg0->fog.r;
                gpVertexN64->v.cn[1] = arg0->fog.g;
                gpVertexN64->v.cn[2] = arg0->fog.b;
                gpVertexN64->v.cn[3] = alpha;
                gpVertexN64++;

                alpha = func_8001BC74(i+1, j);
                gpVertexN64->v.ob[0] = x2;
                gpVertexN64->v.ob[1] = x3;
                gpVertexN64->v.ob[2] = ((arg0->unk1C / 32.0) * alpha) / 256.0;
                gpVertexN64->v.tc[0] = tc2;
                gpVertexN64->v.tc[1] = tc3 & 0x7FFF;
                gpVertexN64->v.cn[0] = arg0->fog.r;
                gpVertexN64->v.cn[1] = arg0->fog.g;
                gpVertexN64->v.cn[2] = arg0->fog.b;
                gpVertexN64->v.cn[3] = alpha;
                gpVertexN64++;

                alpha = func_8001BC74(i+1, j+1);
                gpVertexN64->v.ob[0] = x2;
                gpVertexN64->v.ob[1] = x4;
                gpVertexN64->v.ob[2] = ((arg0->unk1C / 32.0) * alpha) / 256.0;
                gpVertexN64->v.tc[0] = tc2;
                gpVertexN64->v.tc[1] = tc4 & 0x7FFF;
                gpVertexN64->v.cn[0] = arg0->fog.r;
                gpVertexN64->v.cn[1] = arg0->fog.g;
                gpVertexN64->v.cn[2] = arg0->fog.b;
                gpVertexN64->v.cn[3] = alpha;
                gpVertexN64++;

                alpha = func_8001BC74(i, j+1);
                gpVertexN64->v.ob[0] = x1;
                gpVertexN64->v.ob[1] = x4;
                gpVertexN64->v.ob[2] = ((arg0->unk1C / 32.0) * alpha) / 256.0;
                gpVertexN64->v.tc[0] = tc1;
                gpVertexN64->v.tc[1] = tc4 & 0x7FFF;
                gpVertexN64->v.cn[0] = arg0->fog.r;
                gpVertexN64->v.cn[1] = arg0->fog.g;
                gpVertexN64->v.cn[2] = arg0->fog.b;
                gpVertexN64->v.cn[3] = alpha;
                gpVertexN64++;
                func_8000B6A8(1);
            }
        }
    }
}

/*8001C490*/
static void func_8001C490(s16 tileid)
{
    FogColor *color;
    f32 f1, f2, x1, x2, y1, y2;
    s16 i;

    color = &gFog[D_801B0820].color[0];

    if ((tileid != -1) && (D_8012C470 < 2) && (D_8012FC40 == 0))
    {
        gDPSetRenderMode(gpDisplayList++, G_RM_FOG_PRIM_A, G_RM_AA_XLU_SURF2);
        gDPSetFogColor(gpDisplayList++, color->r, color->g, color->b, D_80199942);
        gDPSetCombineMode(gpDisplayList++, G_CC_MODULATEIDECALA, G_CC_PASS2);
        gDPSetTextureLUT(gpDisplayList++, G_TT_RGBA16);
        func_8000C76C();
        D_8012DEFC = 0xFFFF;

        for (i = 0; i < 16; i++)
        {
            func_8000C0D0(getTileNum(tileid+i));
            f1 = (360 * i / 16) * 0.0174532925199444439;
            f2 = (360 * (i+1) / 16) * 0.0174532925199444439;
            x1 = cosf(f1) * 1024.0f;
            x2 = cosf(f2) * 1024.0f;
            y1 = sinf(f1) * 1024.0f;
            y2 = sinf(f2);

            gpVertexN64->v.ob[0] = x1;
            gpVertexN64->v.ob[1] = y1;
            gpVertexN64->v.ob[2] = 0;
            gpVertexN64->v.tc[0] = 0;
            gpVertexN64->v.tc[1] = 0x7FF;
            gpVertexN64->v.cn[0] = 0xFF;
            gpVertexN64->v.cn[1] = 0xFF;
            gpVertexN64->v.cn[2] = 0xFF;
            gpVertexN64->v.cn[3] = 0xFF;
            gpVertexN64++;

            gpVertexN64->v.ob[0] = x2;
            gpVertexN64->v.ob[1] = (y2 * 1024.0f);
            gpVertexN64->v.ob[2] = 0;
            gpVertexN64->v.tc[0] = 0x7FF;
            gpVertexN64->v.tc[1] = 0x7FF;
            gpVertexN64->v.cn[0] = 0xFF;
            gpVertexN64->v.cn[1] = 0xFF;
            gpVertexN64->v.cn[2] = 0xFF;
            gpVertexN64->v.cn[3] = 0xFF;
            gpVertexN64++;

            gpVertexN64->v.ob[0] = x2;
            gpVertexN64->v.ob[1] = (y2 * 1024.0f);
            gpVertexN64->v.ob[2] = -0x2000;
            gpVertexN64->v.tc[0] = 0x7FF;
            gpVertexN64->v.tc[1] = 0;
            gpVertexN64->v.cn[0] = 0xFF;
            gpVertexN64->v.cn[1] = 0xFF;
            gpVertexN64->v.cn[2] = 0xFF;
            gpVertexN64->v.cn[3] = 0xFF;
            gpVertexN64++;

            gpVertexN64->v.ob[0] = x1;
            gpVertexN64->v.ob[1] = y1;
            gpVertexN64->v.ob[2] = -0x2000;
            gpVertexN64->v.tc[0] = 0;
            gpVertexN64->v.tc[1] = 0;
            gpVertexN64->v.cn[0] = 0xFF;
            gpVertexN64->v.cn[1] = 0xFF;
            gpVertexN64->v.cn[2] = 0xFF;
            gpVertexN64->v.cn[3] = 0xFF;
            gpVertexN64++;

            func_8000B6A8(1);
        }
    }
}

/*8001C8A0*/
void displayDebug(s16 x, s16 y, char *string)
{
    s32 x_, y_;
    s16 i;
    char *ptr;

    x_ = x;
    y_ = y;

    if (x_ == -1)
    {
        for (ptr = string, i = 0; ((*ptr != 0) && (*ptr != '\n') && (*ptr != '\r')); ptr++)
        {
            if (*ptr == ' ')
                i += 4;
            else
                i += 9;
        }
        x_ = (SCREEN_WIDTH / 2) - i / 2;
    }

    for (; ((*string != 0) && (*string != '\n') && (*string != '\r')); string++)
    {
        func_8001D238(x_, y_, *string + (2822 - '!'));
        if (*string == ' ')
            x_ += 4;
        else
            x_ += 9;
    }
}

/*8001C9E4*/
void displayNumbers(s16 x, s16 y, char *string)
{
    f32 f1, f2;
    s32 x_, y_;
    s16 tileid;
    char *ptr;

    x_ = x;
    y_ = y;
    D_801A2688 = 1;

    if ((D_8012C470 == 1) || (D_801B0820 == D_8012C470))
        f1 = 1.0f;
    else
        f1 = 1.5f;

    if (x == -1)
    {
        for (ptr = string, x = 0; *ptr != 0; ptr++)
            x += f1 * 11.0f;

        x_ = (SCREEN_WIDTH / 2) - x / 2;
    }

    for (; (*string != 0); string++)
    {
        f2 = 11.0f;
        if (*string != ' ')
        {
            tileid = *string;
            if (tileid == ':')
                tileid = 6134;
            else if (tileid == '-')
                tileid = 3951;
            else
                tileid += (5682 - '0');
            func_8001D238(x_, y_, tileid);
            x_ += f1 * f2;
        }
        else
            x_ += f1 * f2;
    }
}

/*8001CBAC*/
void displayMessage1(s16 x, s16 y, char *string)
{
    f32 f1, f2;
    s32 x_, y_;
    s16 tileid;
    char *ptr;
    s16 i;

    x_ = x;
    y_ = y;
    D_801A2688 = 1;

    if ((D_8012C470 == 1) || (D_801B0820 == D_8012C470))
        f1 = 1.0f;
    else
        f1 = 1.5f;

    if (x == -1)
    {
        for (ptr = string, x = 0; *ptr != 0; ptr++)
        {
            *ptr = toupper(*ptr);
            if (*ptr == ' ')
            {
                i = 7;
            }
            else
            {
                switch (*ptr)
                {
                case 'M':
                case 'W':
                    i = 12;
                    break;
                case 'I':
                    i = 4;
                    break;
                case '!':
                case '"':
                case '\'':
                case ',':
                case '.':
                case ':':
                    i = 3;
                    break;
                default:
                    i = 9;
                    break;
                }
            }
            x += i * f1;
        }
        x_ = (SCREEN_WIDTH / 2) - x / 2;
    }

    for (; (*string != 0); string++)
    {
        if (*string == ' ')
        {
            x_ += 7;
        }
        else
        {
            tileid = toupper(*string);
            switch (tileid)
            {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                tileid += 6117 - '0';
                break;
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
            case 'G':
            case 'H':
            case 'I':
            case 'J':
            case 'K':
            case 'L':
            case 'M':
            case 'N':
            case 'O':
            case 'P':
            case 'Q':
            case 'R':
            case 'S':
            case 'T':
            case 'U':
            case 'V':
            case 'W':
            case 'X':
            case 'Y':
            case 'Z':
                tileid += 6087 - 'A';
                break;
            case '.':
                tileid = 6127;
                break;
            case ':':
                tileid = 6128;
                break;
            case '\'':
                tileid = 6129;
                break;
            case '!':
                tileid = 6130;
                break;
            case '?':
                tileid = 6131;
                break;
            case ',':
                tileid = 6132;
                break;
            case '"':
                tileid = 6133;
                break;
            case '-':
                tileid = 6135;
                break;
            case '+':
                tileid = 6136;
                break;
            default:
                tileid = -1;
                break;
            }

            if (tileid != -1)
                func_8001D238(x_, y_, tileid);

            switch (*string)
            {
            case 'M':
            case 'W':
                i = 12;
                break;
            case 'I':
                i = 4;
                break;
            case '!':
            case '"':
            case '\'':
            case ',':
            case '.':
            case ':':
                i = 3;
                break;
            default:
                i = 9;
                break;
            }
            x_ += i * f1;
        }
    }
}

/*8001CEA4*/
void displayMessage2(s16 x, s16 y, char *string)
{
    f32 f1, f2;
    s32 x_, y_;
    s16 tileid;
    char *ptr;
    s16 i;

    x_ = x;
    y_ = y;
    D_801A2688 = 1;

    if ((D_8012C470 == 1) || (D_801B0820 == D_8012C470))
        f1 = 1.0f;
    else
        f1 = 1.5f;

    if (x == -1)
    {
        for (ptr = string, x = 0; *ptr != 0; ptr++)
        {
            *ptr = toupper(*ptr);
            x += f1 * 3.0f;
        }
        x_ = (SCREEN_WIDTH / 2) - x / 2;
    }

    for (; (*string != 0); string++)
    {
        if (*string == ' ')
        {
            x_ += 3;
        }
        else
        {
            tileid = toupper(*string);
            switch (tileid)
            {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                tileid += 3856 - '0';
                break;
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
            case 'G':
            case 'H':
            case 'I':
            case 'J':
            case 'K':
            case 'L':
            case 'M':
            case 'N':
            case 'O':
            case 'P':
            case 'Q':
            case 'R':
            case 'S':
            case 'T':
            case 'U':
            case 'V':
            case 'W':
            case 'X':
            case 'Y':
            case 'Z':
                tileid += 3866 - 'A';
                break;
            case '.':
                tileid = 3896;
                break;
            case ':':
                tileid = 3895;
                break;
            case ',':
                tileid = 3894;
                break;
            case ')':
                tileid = 3893;
                break;
            case '(':
                tileid = 3892;
                break;
            case '\'':
                tileid = 3982;
                break;
            default:
                tileid = -1;
                break;
            }

            if (tileid != -1)
                func_8001D238(x_, y_, tileid);

            switch (*string)
            {
            case 'M':
            case 'W':
                i = 7;
                break;
            case '\'':
            case '1':
            case ':':
            case 'I':
                i = 3;
                break;
            default:
                i = 6;
                break;
            }
            x_ += i * f1;
        }
    }
}

/*8001D128*/
void func_8001D128(s32 *x, s32 *y)
{
    s32 x_, y_;

    x_ = *x;
    x_ -= (SCREEN_WIDTH / 2);
    x_ *= (D_80199110 / (SCREEN_WIDTH / 2));
    y_ = *y;
    y_ -= (SCREEN_HEIGHT / 2);
    y_ *= (D_801A1980 / (SCREEN_HEIGHT / 2));
    x_ += (gScreenWidth / 2);
    y_ += (gScreenHeight / 2);
    x_ += (D_80168C9C - (gScreenWidth / 2));
    y_ += (D_801A2684 - (gScreenHeight / 2));

    *x = x_;
    *y = y_;
}

/*8001D238*/
INCLUDE_ASM("nonmatchings/src/code0/1A7C0", func_8001D238);
