#include "common.h"
#include "code0/main.h"
#include "code0/audio.h"
#include "code0/graphics.h"
#include "code0/9410.h"
#include "code0/1E7A0.h"
#include "code0/41940.h"
#include "code0/7BA50.h"
#include "code0/code0.h"

typedef struct {
    /*0x00*/ s32 x[3];
    /*0x0C*/ s32 y[3];
    /*0x18*/ s32 z[3];
} _8EFE0UnkStruct2;

typedef struct {
    /*0x00*/ u8 unk0;
    /*0x02*/ u16 unk2;
    /*0x04*/ _8EFE0UnkStruct2 unk4;
    /*0x28*/ s32 unk28;
    /*0x2C*/ s32 unk2C;
} _8EFE0UnkStruct1;

/*.data*/
/*800E1750*/ EXTERN_DATA STATIC u8 D_800E1750[16];
/*800E1760*/ EXTERN_DATA STATIC s32 D_800E1760;

/*.comm*/
/*80106730*/ _8EFE0UnkStruct1 D_80106730[32] ALIGNED(16);
/*80139870*/ s32 D_80139870;
/*80197D20*/ _8EFE0UnkStruct2 D_80197D20 ALIGNED(8);
/*801A19F8*/ _8EFE0UnkStruct2 D_801A19F8 ALIGNED(8);

/*.text*/

/*8008E3E0*/
s32 func_8008E3E0(s32 x, s32 y, s32 z, s32 sectnum, s32 arg4, s32 arg5)
{
    SpriteType *spr;
    SpriteType *spr2;
    f32 fx1, fy1, fx2, fy2, fx3, fy3, f1;
    s16 spritenum;
    s32 i, j, k, l, m, n;
    s32 x1, y1, z1;

    i = 310;
    switch (arg4)
    {
    case 58:
        if (D_8012C470 == 1)
            i = 50;
        break;
    case 8:
    case 50:
    case 52:
    case 64:
    case 74:
        i = 50;
        break;
    case 30:
    case 41:
        i = 311;
        break;
    }

    if ((D_801AC9F4 > 0x100) && (i == 310))
        return -1;

    spritenum = func_80058934(x, y, z, sectnum, i);
    if (spritenum == -1)
        return -1;

    if (i == 310)
        D_801AC9F4++;

    spr = &gpSprite[spritenum];
    spr->xrepeat = 32;
    spr->yrepeat = 32;
    spr->cstat = 0;
    spr->unk16 = arg4;
    spr->picnum = 0;
    spr->unk25 = 0;
    D_800E1760 = spritenum;
    switch (arg4)
    {
    case 8:
        if (spr->unk25 != 0)
            spr->unk18 = spr->unk24;
        else
            spr->unk18 = D_800DCA40[spr->lotag].unkE;

        spr->unk1A = 0;
        spr->unk22 = -1;
        break;
    case 28:
        spr->unk25 = 2;
        spr->cstat = 0x800;
        spr->picnum = 5754;
        spr->xrepeat = 32;
        spr->yrepeat = 32;
        break;
    case 2:
        spr->unk25 = 2;
        spr->cstat = 0x800;
        spr->picnum = 5769;
        spr->unk1C = 656;
        spr->unk18 = 0;
        spr->unk1A = 0;
        spr->xrepeat = 64;
        spr->yrepeat = 64;
        break;
    case 50:
        spr->picnum = 4939;
        spr->xrepeat = 8;
        spr->yrepeat = 16;
        spr->cstat = 0x800;
        spr->unk25 = 2;
        spr->unk18 = 100;
        spr->unk1A = 0;
        n = func_80058934(spr->x, spr->y, spr->z, spr->sectnum, 110);
        if (n >= 0)
        {
            gpSprite[n].picnum = 5;
            gpSprite[n].unk1A = 2000;
            gpSprite[n].unk25 = 0xFF;
            gpSprite[n].lotag = 75;
            gpSprite[n].unk18 = 0;
            gpSprite[n].cstat = 0x8000;
        }
        break;
    case 55:
        spr->unk1C = -((krand() & 0x1FF) + 3000);
        spr->unk18 = (krand() & 0x3F) + 100;
        spr->xrepeat = 64;
        spr->yrepeat = 64;
        spr->picnum = arg5;
        spr->unk1A = spr->unk18;
        spr->unk22 = spr->unk1C;
        spr->cstat |= 0x1000;
        spr->unk2A = (krand() & 0x40) - 0x1F;
        spr->unk2B = 0;
        spr->ang = (krand() & 0x7FF);

        if ((krand() & 0xFF) > 196)
        {
            spr->ang = getAngle(gPlayer[0].xpos - spr->x, gPlayer[0].ypos - spr->y);
            spr->ang += (krand() & 0x7F) - 0x3F;
        }

        if (arg5 == 2130)
        {
            spr->unk1C = -((krand() & 0x1FF) + 1000);
            spr->unk18 = (krand() & 0x1F) + 30;
            spr->picnum = (krand() & 3) + 2130;
            spr->xrepeat = (krand() & 0x1F) + 64;
        }
        break;
    case 56:
        spr->xrepeat = 16;
        spr->picnum = 0;
        spr->unk18 = 4;
        spr->unk22 = 0;
        spr->cstat |= 0x8000;
        break;
    case 20:
    case 31:
    case 46:
    case 48:
    case 65:
        spr->picnum = 5736;
        spr->cstat = 0xC80;
        spr->unk18 = 0;
        spr->xrepeat = 0;
        spr->yrepeat = 0;

        if (arg4 == 46)
            spr->unk25 = 11;
        else if (arg4 == 48)
            spr->unk25 = 18;
        else if (arg4 == 65)
            spr->unk25 = 0;
        else
            spr->unk25 = 31;

        if (arg4 == 20)
            D_8013B2D0[spritenum].unk2 = (krand() & 0xFF) + 384;
        else
            D_8013B2D0[spritenum].unk2 = 0x200;

        if (arg5 == 0)
            spr->z -= 0x400;
        else if (arg5 == 1)
            spr->z += 0x1000;
        break;
    case 53:
    case 72:
        if ((krand() & 0xFF) >= 0x80)
            spr->picnum = 5655;
        else
            spr->picnum = 5657;

        spr->cstat = 0xC80;
        spr->unk18 = 0;
        spr->unk25 = arg5;
        spr->ang = (krand() & 0x7FF);
        D_8013B2D0[spritenum].unk2 = krand() & 0x3FF;
        if (arg4 != 72)
        {
            spr->xrepeat = 0xFF;
            spr->yrepeat = 0xFF;
            D_8013B2D0[spritenum].unk6 = 0xFF;
        }
        else
        {
            spr->xrepeat = 0;
            spr->yrepeat = 0;
        }
        break;
    case 75:
        spr->picnum = 5746;
        spr->cstat = 0x8B0;
        spr->xrepeat = 16;
        spr->yrepeat = 16;
        spr->unk25 = arg5;
        break;
    case 52:
    case 68:
    case 79:
        spr->picnum = 5746;
        spr->cstat = 0x8B0;
        spr->unk1A = 0;
        spr->unk18 = 0;
        spr->xrepeat = 16;
        spr->yrepeat = 16;
        spr->unk25 = arg5;
        break;
    case 54:
        x1 = spr->x;
        y1 = spr->y;
        z1 = spr->z;
        spr->picnum = 5771;
        spr->unk25 = arg5;
        spr->cstat = 0x8000;
        spr->unk2A = func_8007AE50();
        spr->ang = krand() & 0x7FF;
        fx1 = spr->x;
        spr->x = fx1 + (cosf(spr->ang * (PI/1024)) * 8191.0f);
        fy1 = spr->y;
        spr->y = fy1 + (sinf(spr->ang * (PI/1024)) * 8191.0f);
        spr->z = spr->z + (((krand() & 0x1FFF) - 0x1000) * 16);
        spr->unk18 = (x1 - spr->x) / 8;
        spr->unk1A = (y1 - spr->y) / 8;
        spr->unk1C = (z1 - spr->z) / 8;
        spr->unk2B = 8;
        break;
    case 69:
        fx2 = spr->x;
        spr->unk25 = 20;
        spr->picnum = 0x168B;
        spr->cstat = 0x8000;
        x1 = fx2 + (cosf(spr->ang * (PI/1024)) * 8191.0f);
        fy2 = spr->y;
        y1 = fy2 + (sinf(spr->ang * (PI/1024)) * 8191.0f);
        z1 = spr->z + (((krand() & 0x1FFF) - 0x1000) * 16);
        spr->unk2A = func_8007AE50();
        spr->ang = (krand() & 0x7FF);
        spr->unk18 = (x1 - spr->x) / 8;
        spr->unk1A = (y1 - spr->y) / 8;
        spr->unk1C = (z1 - spr->z) / 8;
        spr->unk2B = 8;
        break;
    case 57:
        i = func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 63, 0);
        if (i >= 0)
            gpSprite[i].unk22 = spritenum;

        i = func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 58, 0x100);
        if (i >= 0)
            gpSprite[i].unk22 = spritenum;

        i = func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 58, 0x100);
        if (i >= 0)
        {
            gpSprite[i].unk22 = spritenum;
            gpSprite[i].cstat |= 4;
        }

        i = func_8008E3E0(spr->x, spr->y, spr->z, spr->sectnum, 58, 0x100);
        if (i >= 0)
        {
            gpSprite[i].unk22 = spritenum;
            gpSprite[i].cstat |= 8;
        }
    case 63:
        spr->picnum = 5753;
        spr->cstat = 0x8B0;
        spr->xrepeat = 48;
        spr->yrepeat = 48;
        spr->unk25 = 36;
        break;
    case 58:
        spr->picnum = 5746;
        spr->cstat = 0x8B0;
        spr->xrepeat = 8;
        spr->yrepeat = 8;
        spr->unk25 = 0x24;
        spr->ang = krand() & 0x7FF;
        fx3 = spr->x;
        f1 = arg5;
        spr->x = fx3 + (f1 * cosf(spr->ang * (PI/1024)));
        fy3 = spr->y;
        spr->y = fy3 + (f1 * sinf(spr->ang * (PI/1024)));
        spr->unk1C = arg5;
        spr->unk2A = func_8007AE50();
        break;
    case 78:
        spr->picnum = 5733;
        spr->cstat = 0x8A0;
        spr->unk18 = 0;
        if (arg5 == 0)
        {
            spr->xrepeat = 80;
            spr->yrepeat = 80;
            spr->unk25 = 8;
        }
        else
        {
            spr->xrepeat = 40;
            spr->yrepeat = 40;
            spr->unk25 = 13;
        }
        break;
    case 61:
        spr->picnum = 5736;
        spr->cstat = 0x4880;

        if (arg5 == 0)
            spr->cstat |= 0x20;
        else
            spr->cstat |= 0x10;

        spr->xrepeat = 4;
        spr->yrepeat = 4;
        spr->unk25 = 30;
        spr->ang = krand() & 0x7FF;
        break;
    case 64:
        spr->picnum = 5746;
        spr->cstat = 0x8000;
        spr->ang = krand() & 0x7FF;
        spr->unk1C = 0x200;
        spr->unk1A = arg5;
        spr->unk25 = 18;
        break;
    case 74:
        spr->picnum = 5746;
        spr->cstat = 0x8000;
        spr->ang = krand() & 0x7FF;
        spr->unk18 = 100;
        spr->unk1C = 0x200;
        spr->unk25 = 21;
        spr->unk1A = arg5;
        gpSector[sectnum].floorstat |= 0x2000;
        break;
    case 73:
        spr->picnum = 6116;
        spr->cstat = 0x4820;

        if (arg5 != 0)
            spr->cstat |= 4;

        spr->unk25 = 7;
        spr->unk18 = 0;
        spr->xrepeat = 32;
        spr->yrepeat = 32;
        spr->z = getFlorzOfSlope(spr->sectnum, spr->x, spr->y);
        break;
    case 30:
        spr->picnum = 5746;
        spr->cstat = 0x880;
        spr->xrepeat = 1;
        spr->yrepeat = 1;
        spr->unk1A = 0;
        spr->unk18 = 0;
        spr->unk25 = 31;
        break;
    case 26:
        spr->picnum = 1919;
        spr->cstat = 0x1800;
        spr->unk18 = 0;
        spr->xrepeat = 0;
        spr->yrepeat = 0;
        spr->unk25 = 0;
        if (arg5 != 0)
            D_8013B2D0[spritenum].unk0 = 0x400;
        break;
    case 80:
        spr->picnum = 2134;
        spr->cstat = 0x1800;
        spr->unk18 = 0;
        spr->xrepeat = 8;
        spr->yrepeat = 8;
        spr->ang = krand() & 0x7FF;
        spr->unk25 = arg5;
        break;
    case 67:
        spr->picnum = 1919;
        spr->cstat = 0x1800;
        spr->unk18 = 0;
        spr->xrepeat = 180;
        spr->yrepeat = 180;
        spr->ang = krand() & 0x7FF;
        spr->unk25 = 21;
        if (arg5 != 0)
            D_8013B2D0[spritenum].unk0 = 0x400;
        break;
    case 59:
        spr->picnum = 1919;
        spr->cstat = 0x1800;
        spr->unk18 = 0;
        spr->xrepeat = 180;
        spr->yrepeat = 180;
        spr->ang = krand() & 0x7FF;
        spr->unk25 = 0x1F;
        spr->unk2B = arg5;
        if (arg5 != 0)
        {
            D_8013B2D0[spritenum].unk6 = 240;
            spr->xrepeat = 120;
            spr->yrepeat = 120;
        }
        break;
    case 60:
        spr->picnum = arg5 + 2116;
        spr->cstat = 0x1000;
        spr->yrepeat = 200;
        spr->xrepeat = 200;
        spr->unk1C = -4000;
        spr->unk18 = (krand() & 0x3FF) - 0x200;
        spr->unk1A = (krand() & 0x3FF) - 0x200;
        spr->unk22 = (krand() & 0xF) - 8;
        spr->unk2B = 60;
        break;
    case 21:
        spr->picnum = 3658;
        spr->unk25 = 0;
        spr->cstat = 0x8000;
        spr->unk18 = 0;
        spr->unk1A = func_8007AE50();
        spr->unk1C = 0;
        spr->xrepeat = 16;
        spr->yrepeat = 16;
        break;
    case 25:
        spr->unk25 = arg5;
        spr->picnum = 5749;
        spr->xrepeat = 64;
        spr->yrepeat = 32;
        spr->unk18 = 0;
        spr->unk1A = 0;
        spr->unk1C = 0;
        spr->cstat |= 0x4898;
        if (spr->unk25 == 254)
        {
            spr->unk25 = 9;
            spr->cstat &= ~0x4010;
        }
        break;
    case 0:
        spr->picnum = 3658;
        spr->unk25 = 7;
        spr->cstat = 0x800;
        spr->unk1C = krand() & 0x7FF;
        spr->unk1A = 140;
        spr->unk18 = 0;
        spr->unk22 = arg5;
        spr->xrepeat = gpSprite[arg5].ang / 24;
        spr->yrepeat = gpSprite[arg5].ang / 24;
        break;
    case 38:
        spr->unk22 = arg5;
    case 23:
        spr->picnum = 5700;
        spr->unk25 = 0;
        spr->cstat = 0x800;
        spr->xrepeat = (krand() & 0xF) + 0x1F;
        spr->yrepeat = (krand() & 0xF) + 0x1F;
        break;
    case 4:
    case 24:
    case 32:
    case 82:
        k = krand() & 1;
        k += (krand() & 1);
        spr->picnum = k + 5542;
        if (arg4 == 4)
        {
            spr->xrepeat = 8;
            spr->yrepeat = 8;
            spr->unk25 = 19;
        }
        else
        {
            spr->xrepeat = 16;
            spr->yrepeat = 16;
            spr->unk25 = arg5;
        }
        spr->cstat = 0x8B0;
        spr->unk18 = 0;
        spr->unk1A = (krand() & 0x3F) - 32;
        break;
    case 33:
        spr->unk25 = 21;
        spr->picnum = 5733;
        spr->cstat = 0x880;
        spr->xrepeat = 32;
        spr->yrepeat = 32;
        break;
    case 3:
        spr->unk25 = 2;
        spr->picnum = 5733;
        spr->cstat = 0x4820;
        spr->xrepeat = 0;
        spr->yrepeat = 0;
        spr->unk22 = 4 - arg5;
        break;
    case 18:
        spr->unk25 = 4;
        spr->picnum = 5744;
        spr->cstat = 0x820;
        spr->xrepeat = 0;
        spr->yrepeat = 0;
        break;
    case 22:
        spr->unk25 = 4;
        spr->picnum = 5744;
        spr->cstat = 0x820;
        spr->xrepeat = 0;
        spr->yrepeat = 0;
        break;
    case 16:
        spr->picnum = 1955;
        spr->cstat = 0x1800;
        spr->xrepeat = 0;
        spr->yrepeat = 0;
        spr->unk18 = 0;
        spr->unk1C = ((krand() & 3) - 1) * 16;
        break;
    case 17:
        spr->picnum = 5656;
        spr->cstat = 0x880;
        spr->unk25 = 0;
        D_8013B2D0[spritenum].unk6 = 0;
        spr->xrepeat = 1;
        spr->yrepeat = 1;
        spr->unk18 = 0;
        spr->unk1A = 0;
        break;
    case 19:
        if (arg5 == 18)
            spr->picnum = 5746;
        else
            spr->picnum = 5656;

        spr->cstat = 0x880;
        spr->unk25 = arg5;
        D_8013B2D0[spritenum].unk6 = 0;
        spr->xrepeat = 1;
        spr->yrepeat = 1;
        spr->unk18 = 0;
        spr->unk1A = 0;
        break;
    case 10:
        spr->picnum = 1890;
        spr->cstat = 0x880;
        D_8013B2D0[spritenum].unk6 = 64;
        spr->xrepeat = 64;
        spr->yrepeat = 64;
        break;
    case 1:
        spr->cstat = 0x800;
        spr->picnum = 5732;
        spr->xrepeat = (krand() & 7) + 4;
        spr->yrepeat = (krand() & 7) + 4;
        spr->unk25 = 18;
        spr->unk18 = krand() & 0x7FF;
        spr->unk1C = 16;
        spr->unk1A = (krand() & 0xF) + 8;
        spr->unk22 = 0;
        D_8013B2D0[spritenum].unk6 = 0;
        break;
    case 51:
        spr->cstat = 0x880;
        spr->picnum = 5870;
        spr->unk25 = 8;
        spr->unk18 = 1;
        spr->xrepeat = 28;
        spr->yrepeat = 28;
        break;
    case 15:
    case 35:
    case 76:
        spr->cstat = 0x880;
        spr->picnum = 5535;
        spr->unk25 = arg5;
        spr->unk18 = (krand() & 0xF) + 10;
        spr->unk1A = 0;
        spr->unk22 = (krand() & 0xFF) + 260;
        spr->ang = krand() & 0x7FF;
        if (arg4 == 35)
        {
            spr->xrepeat = 40;
            spr->yrepeat = 40;
        }
        else
        {
            spr->xrepeat = 8;
            spr->yrepeat = 8;
        }

        if (arg4 == 76)
        {
            spr->unk22 = (-0x100 - (krand() & 0x7FF));
            spr->unk18 = krand() & 0x7F;
        }
        break;
    case 34:
        spr->cstat = 0x800;
        spr->picnum = 5550;
        spr->xrepeat = 16;
        spr->yrepeat = 16;
        spr->unk25 = arg5;
        spr->unk1A = 0;
        spr->unk22 = 120;
        break;
    case 7:
        if (arg5 != 0)
        {
            l = krand() & 1;
            m = krand() & 1;
            l <<= 2;
            m <<= 3;
            spr->picnum = (krand() & 1) + (krand() & 1) + 5573;
            spr->cstat |= (0x48D0 | (l | m));
            spr->unk25 = 7;
        }
        else
        {
            spr->picnum = 5534;
            spr->cstat |= 0x40D0;
        }
        spr->xrepeat = 8;
        spr->yrepeat = 8;
        break;
    case 6:
    case 27:
        if (arg4 == 27)
        {
            spr->unk25 = 18;
            spr->xrepeat = 16;
            spr->yrepeat = 16;
        }
        else
        {
            spr->unk25 = 19;
            spr->xrepeat = 8;
            spr->yrepeat = 8;
        }

        spr->unk18 = 0;
        if (arg5 == 1)
            spr->unk1A = -12;
        else
            spr->unk1A = 0;

        k = krand() & 1;
        k += (krand() & 1);
        spr->picnum = k + 5542;
        spr->cstat = 0x8B0;
        break;
    case 14:
        spr->cstat = 0x880;
        spr->picnum = 5587;
        spr->unk25 = 9;
        spr->xrepeat = 24;
        spr->yrepeat = 24;
        break;
    case 11:
    case 36:
        spr->cstat = 0x4820;
        spr->xrepeat = 0;
        spr->yrepeat = 0;
        setSprite(spritenum, x, y, getFlorzOfSlope(spr->sectnum, spr->x, spr->y));
        spr->picnum = 5748;
        spr->unk18 = 0;
        spr->unk1A = 0;
        if (arg4 == 11)
            spr->unk25 = 20;
        else
            spr->unk25 = 9;
        break;
    case 12:
        spr->cstat = 0x1800;
        spr->picnum = 1707;
        spr->unk25 = 0;
        spr->ang = krand() & 0x7FF;
        spr->xrepeat = 0;
        spr->yrepeat = 0;
        break;
    case 40:
        spr->cstat = 0x800;
        spr->picnum = 5746;
        spr->unk25 = 1;
        spr->cstat = 0x880;
        D_8013B2D0[spritenum].unk6 = 0;
        spr->xrepeat = 220;
        spr->yrepeat = 220;
        spr->unk18 = 0;
        spr->unk1A = 0;
        break;
    case 39:
        spr->cstat = 0x8000;
    case 47:
    case 81:
        spr->unk22 = 0;
        break;
    case 41:
        spr->unk22 = 0;
        spr->unk18 = arg5;
        break;
    case 42:
        spr->cstat = 0x880;
        spr->picnum = 5748;
        spr->xrepeat = 16;
        spr->yrepeat = 16;
        spr->unk25 = arg5;
        D_8013B2D0[spritenum].unk6 = 30;
        break;
    case 43:
        spr->picnum = 2323;
        spr->cstat = 0x1800;
        spr->unk25 = 12;
        spr->xrepeat = 0;
        spr->unk2B = 0;
        D_8013B2D0[spritenum].unk6 = 0xFF;
        break;
    case 44:
        spr->unk22 = 6;
        spr->unk18 = arg5;
        switch (arg5 & 0x7F)
        {
        case 0:
            audio_800077F4(571, spritenum);
            break;
        case 1:
            audio_800077F4(323, spritenum);
            break;
        case 2:
            audio_800077F4(803, spritenum);
            break;
        case 5:
            audio_800077F4(571, spritenum);
            break;
        case 6:
            audio_800077F4(567, spritenum);
            break;
        case 7:
            spr->unk22 = 2;
        case 4:
            audio_800077F4(322, spritenum);
            break;
        }
        break;

    case 13:
        spr->ang = krand() & 0x7FF;
        spr->picnum = (krand() % 5) + 1505;
        spr->cstat = 0x1000;
        spr->xrepeat = (krand() & 0x3F) + 8;
        spr->unk1C = -2000;
        spr->unk18 = 40;
        spr->unk22 = 30;
        spr->xrepeat = (krand() & 0xF) + 16;
        D_8013B2D0[spritenum].unk2 = krand() & 0x7FF;
        D_8013B2D0[spritenum].unk0 = krand() & 0x7FF;
        break;
    case 49:
        spr->picnum = 5535;
        spr->xrepeat = 8;
        spr->yrepeat = 8;
        spr->unk25 = 2;
        spr->cstat |= 0x800;
        spr->ang = krand() & 0x7FF;
        spr->unk1C = -((krand() & 0x1FF) + 500);
        spr->unk18 = (krand() & 0xF) + 8;
        spr->unk22 = 15;
        spr->unk1A = krand() & 0x7F;
        break;
    case 45:
        spr->unk18 = 40;
        spr2 = &gpSprite[arg5];
        switch (spr2->unk18 & 0x7F)
        {
        case 0:
            spr->picnum = (krand() & 1) + 2384;
            spr->cstat = 0x1800;
            spr->unk25 = spr2->unk25;
            spr->xrepeat = (krand() & 0x3F) + 8;
            break;
        case 1:
            spr->picnum = (krand() % 3) + 2386;
            spr->cstat = 0x1000;
            spr->xrepeat = (krand() & 0x3F) + 8;
            break;
        case 2:
            spr->picnum = (krand() & 3) + 2389;
            spr->cstat = 0x1000;
            spr->xrepeat = (krand() & 0x3F) + 8;
            break;
        case 3:
            spr->picnum = (krand() & 1) + 2384;
            spr->cstat = 0x1800;
            spr->unk25 = 29;
            spr->unk18 = 90;
            spr->z += ((krand() & 0x1FFF) - 0x1000);
            spr->xrepeat = (krand() & 0x3F) + 8;
            break;
        case 4:
            spr->picnum = 1690;
            spr->cstat = 0x1000;
            spr->xrepeat = (krand() & 0xF) + 8;
            break;
        case 5:
            spr->picnum = (krand() & 1) + 2384;
            spr->cstat = 0x1800;
            spr->unk25 = spr2->unk25;
            spr->xrepeat = (krand() & 7) + 8;
            break;
        case 6:
            spr->picnum = 5550;
            spr->cstat = 0x800;
            spr->unk25 = spr2->unk25;
            spr->xrepeat = (krand() & 0x3F) + 2;
            break;
        case 7:
            spr->picnum = 1690;
            spr->cstat = 0x1000;
            spr->xrepeat = (krand() & 3) + 2;
            break;
        }

        if (spr2->unk18 & 0x80)
            spr->ang = spr2->ang + ((krand() & 0xFF) - 0x7F);
        else
            spr->ang = krand() & 0x7FF;

        spr->unk1C = -2000;
        spr->unk22 = 30;
        D_8013B2D0[spritenum].unk2 = krand() & 0x7FF;
        D_8013B2D0[spritenum].unk0 = krand() & 0x7FF;
        break;
    case 77:
        spr->cstat = 0x8B0;
        spr->picnum = 5550;
        spr->unk25 = arg5;
        spr->unk18 = 0;
        spr->xrepeat = 96;
        spr->yrepeat = 96;
        D_8013B2D0[spritenum].unk0 = krand() & 0x7FF;
        break;
    case 66:
        spr->cstat = 0x8B0;
        spr->picnum = 5550;
        spr->unk25 = arg5;
        spr->unk18 = 0;
        spr->xrepeat = 48;
        spr->yrepeat = 48;
        D_8013B2D0[spritenum].unk0 = krand() & 0x7FF;
        break;
    case 70:
        spr->cstat = 0x8B0;
        spr->picnum = 5550;
        spr->unk25 = D_800E1750[krand() & 0xF];
        spr->xrepeat = 96;
        spr->yrepeat = 96;
        spr->unk22 = (krand() & 0x3F) + 30;
        spr->unk18 = 0;
        spr->unk1A = 0;
        spr->unk1C = 0;
        spr->unk2A = func_8007AE50();

        if ((krand() & 0x7FFF) < 10000)
            playSfx((krand() % 3) + 1674);

        break;
    case 83:
        spr->cstat = 0x8B0;
        spr->picnum = 5550;
        spr->xrepeat = 96;
        spr->yrepeat = 96;
        spr->unk25 = arg5;
        spr->unk22 = 60;
        if ((krand() & 0x7FFF) < 20000)
        {
            j = 0x3FF;
            i = 0x200;
        }
        else
        {
            j = 0x1FF;
            i = 0x100;
        }
        spr->unk18 = (krand() & j) - i;
        spr->unk1A = (krand() & j) - i;
        spr->unk1C = ((krand() & j) - i) * 16;
        break;
    }

    return spritenum;
}

/*8008FE88*/
INCLUDE_ASM("nonmatchings/src/code0/8EFE0", func_8008FE88);

/*80093450*/
static s32 func_80093450(s32 x, s32 y, s32 z, s32 sectnum, _8EFE0UnkStruct2 *arg4)
{
    _8EFE0UnkStruct1 *ptr;
    s32 i, j, spritenum;

    ptr = D_80106730;
    for (i = 0; i < ARRAY_COUNT(D_80106730); i++, ptr++)
    {
        if (!ptr->unk0)
        {
            spritenum = func_80058934(x, y, z, sectnum, 300);
            if (spritenum != -1)
            {
                for (j = 0, ptr->unk0 = 1; j < 3; j++)
                {
                    ptr->unk4.x[j] = (arg4->x[j] - x);
                    ptr->unk4.y[j] = (arg4->y[j] - y);
                    ptr->unk4.z[j] = (arg4->z[j] - z);
                }
                ptr->unk2 = 100;
                gpSprite[spritenum].unk22 = i;
                gpSprite[spritenum].unk18 = ((krand() & 0x7F) * gpSinTable[D_80139870]) >> 14;
                gpSprite[spritenum].unk1A = ((krand() & 0x7F) * gpSinTable[(D_80139870 + 512) & 0x7FF]) >> 14;
                ptr->unk28 = (krand() & 0x3F) - 0x20;
                ptr->unk2C = (krand() & 0x3F) - 0x20;
                gpSprite[spritenum].unk1C = 0;
                gpSprite[spritenum].ang = 0;
                gpSprite[spritenum].cstat = 0x8000;
                D_8013B2D0[spritenum].unk0 = 0;
                return spritenum;
            }
            break;
        }
    }
    return -1;
}

/*80093670*/
static s32 func_80093670(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    _8EFE0UnkStruct2 *ptr;

    ptr = &D_801A19F8;
    if ((krand() & 0xFFF) < 0x800)
    {
        *ptr = D_80197D20;

        ptr->x[0] = (D_80197D20.x[0] + D_80197D20.x[1]) / 2;
        ptr->y[0] = (D_80197D20.y[0] + D_80197D20.y[1]) / 2;
        ptr->z[0] = (D_80197D20.z[0] + D_80197D20.z[1]) / 2;

        func_80093450((ptr->x[0] + ptr->x[1] + ptr->x[2]) / 3,
                      (ptr->y[0] + ptr->y[1] + ptr->y[2]) / 3,
                      (ptr->z[0] + ptr->z[1] + ptr->z[2]) / 3,
                      arg3, ptr);

        *ptr = D_80197D20;

        ptr->x[1] = (D_80197D20.x[0] + D_80197D20.x[1]) / 2;
        ptr->y[1] = (D_80197D20.y[0] + D_80197D20.y[1]) / 2;
        ptr->z[1] = (D_80197D20.z[0] + D_80197D20.z[1]) / 2;

        return func_80093450((ptr->x[0] + ptr->x[1] + ptr->x[2]) / 3,
                             (ptr->y[0] + ptr->y[1] + ptr->y[2]) / 3,
                             (ptr->z[0] + ptr->z[1] + ptr->z[2]) / 3,
                             arg3, ptr);
    }
    else
    {
        *ptr = D_80197D20;

        ptr->x[1] = (D_80197D20.x[1] + D_80197D20.x[2]) / 2;
        ptr->y[1] = (D_80197D20.y[1] + D_80197D20.y[2]) / 2;
        ptr->z[1] = (D_80197D20.z[1] + D_80197D20.z[2]) / 2;

        func_80093450((ptr->x[0] + ptr->x[1] + ptr->x[2]) / 3,
                      (ptr->y[0] + ptr->y[1] + ptr->y[2]) / 3,
                      (ptr->z[0] + ptr->z[1] + ptr->z[2]) / 3,
                      arg3, ptr);

        *ptr = D_80197D20;

        ptr->x[2] = (D_80197D20.x[1] + D_80197D20.x[2]) / 2;
        ptr->y[2] = (D_80197D20.y[1] + D_80197D20.y[2]) / 2;
        ptr->z[2] = (D_80197D20.z[1] + D_80197D20.z[2]) / 2;

        return func_80093450((ptr->x[0] + ptr->x[1] + ptr->x[2]) / 3,
                             (ptr->y[0] + ptr->y[1] + ptr->y[2]) / 3,
                             (ptr->z[0] + ptr->z[1] + ptr->z[2]) / 3,
                             arg3, ptr);
    }
}

#ifdef NON_MATCHING
/*80093BB0*/
void func_80093BB0(u16 wallnum)
{
    s32 x1, y1, x2, y2, x3, y3, z1, z2, z3;
    s32 ceilz, floorz1, floorz2;
    s32 i, j;

    D_80139870 = (getAngle(gpWall[wallnum].x - gpWall[gpWall[wallnum].point2].x,
        gpWall[wallnum].y - gpWall[gpWall[wallnum].point2].y) + 1024) & 0x7FF;
    x1 = gpWall[wallnum].x;
    y1 = gpWall[wallnum].y;
    x2 = gpWall[gpWall[wallnum].point2].x;
    y2 = gpWall[gpWall[wallnum].point2].y;
    ceilz = getCeilzOfSlope(gpWall[wallnum].unk1A, x1, y1) >> 4;
    getCeilzOfSlope(gpWall[wallnum].unk1A, x2, y2);
    z1 = getCeilzOfSlope(gpWall[wallnum].nextsector, x1, y1) >> 4;
    getCeilzOfSlope(gpWall[wallnum].nextsector, x2, y2);

    if (ceilz < z1)
        ceilz = z1;

    floorz1 = getFlorzOfSlope(gpWall[wallnum].unk1A, x1, y1) >> 4;
    floorz2 = getFlorzOfSlope(gpWall[wallnum].unk1A, x2, y2) >> 4;
    z1 = getFlorzOfSlope(gpWall[wallnum].nextsector, x1, y1) >> 4;
    z2 = getFlorzOfSlope(gpWall[wallnum].nextsector, x2, y2) >> 4;

    if (z1 < floorz1)
    {
        floorz1 = z1;
        floorz2 = z2;
    }

    if (D_80199638 != 0)
    {
        x3 = D_801AE918;
        y3 = D_8010A9B0;
        z3 = D_8016A150 / 16;
    }
    else
    {
        x3 = (x1 + x2) / 2;
        y3 = (y1 + y2) / 2;
        z3 = (ceilz + floorz2) / 2;
    }

    D_80197D20.x[0] = x1;
    D_80197D20.y[0] = y1;
    D_80197D20.z[0] = ceilz;
    D_80197D20.x[1] = x2;
    D_80197D20.y[1] = y2;
    D_80197D20.z[1] = ceilz;
    D_80197D20.x[2] = x3;
    D_80197D20.y[2] = y3;
    D_80197D20.z[2] = z3;

    func_80093670((x1 + x2 + x3) / 3,
                  (y1 + y2 + y3) / 3,
                  ((ceilz * 2) + z3) / 3,
                  gpWall[wallnum].unk1A);

    D_80197D20.x[0] = x2;
    D_80197D20.y[0] = y2;
    D_80197D20.z[0] = ceilz;
    D_80197D20.x[1] = x2;
    D_80197D20.y[1] = y2;
    D_80197D20.z[1] = floorz1;
    D_80197D20.x[2] = x3;
    D_80197D20.y[2] = y3;
    D_80197D20.z[2] = z3;

    func_80093670(((x2 * 2) + x3) / 3,
                  ((y2 * 2) + y3) / 3,
                  (ceilz + floorz1 + z3) / 3,
                  gpWall[wallnum].unk1A);

    D_80197D20.x[0] = x2;
    D_80197D20.y[0] = y2;
    D_80197D20.z[0] = floorz1;
    D_80197D20.x[1] = x1;
    D_80197D20.y[1] = y1;
    D_80197D20.z[1] = floorz1;
    D_80197D20.x[2] = x3;
    D_80197D20.y[2] = y3;
    D_80197D20.z[2] = z3;

    func_80093670((x1 + x2 + x3) / 3,
                  (y1 + y2 + y3) / 3,
                  ((floorz1 * 2) + z3) / 3,
                  gpWall[wallnum].unk1A);

    D_80197D20.x[0] = x1;
    D_80197D20.y[0] = y1;
    D_80197D20.z[0] = ceilz;
    D_80197D20.x[1] = x1;
    D_80197D20.y[1] = y1;
    D_80197D20.z[1] = floorz1;
    D_80197D20.x[2] = x3;
    D_80197D20.y[2] = y3;
    D_80197D20.z[2] = z3;

    i = func_80093670(((x1 * 2) + x3) / 3,
                      ((y1 * 2) + y3) / 3,
                      (ceilz + floorz1 + z3) / 3,
                      gpWall[wallnum].unk1A);

    j = func_80040D94(x1, y1, ceilz, x2, y2, floorz2);

    if (j < 1024)
        audio_800077F4(((krand() % 3) + 1045), i);
    else if ((j >= 1024) && (j < 2048))
        audio_800077F4(((krand() % 3) + 1039), i);
    else if (j >= 2048)
        audio_800077F4(((krand() % 3) + 1042), i);
}
#else
/*80093BB0*/
INCLUDE_ASM("nonmatchings/src/code0/8EFE0", func_80093BB0);
#endif

/*80094278*/
void func_80094278(void)
{
    _8EFE0UnkStruct1 *ptr;
    s32 i;

    gSPClearGeometryMode(gpDisplayList++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                                          G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gSPSetGeometryMode(gpDisplayList++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH);
    gDPSetRenderMode(gpDisplayList++, G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2);
    gDPSetTextureLUT(gpDisplayList++, G_TT_NONE);
    gDPSetCombineMode(gpDisplayList++, G_CC_PRIMITIVE, G_CC_PASS2);
    gDPSetPrimColor(gpDisplayList++, 0, 0, 0x00, 0x00, 0x00, 0x80);

    i = gHeadSpriteStat[300];
    while (i >= 0)
    {
        func_8000C76C();
        if (D_801A6D80 < ARRAY_COUNT(gpDynamic->mtx3))
        {
            grPosition(&gpDynamic->mtx3[D_801A6D80+1],
                       0.0f,
                       (D_8013B2D0[i].unk0 * 0.17578125),
                       (gpSprite[i].ang * 0.17578125),
                       0.5,
                       (gpSprite[i].x / 4),
                       (gpSprite[i].y / 4),
                       (gpSprite[i].z / 4.0));

            gSPMatrix(gpDisplayList++, OS_K0_TO_PHYSICAL(&gpDynamic->mtx3[D_801A6D80+1]),
                                       G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

            D_801A6D80++;
            ptr = &D_80106730[gpSprite[i].unk22];

            gpVertexN64->v.ob[0] = (ptr->unk4.x[0] >> 1);
            gpVertexN64->v.ob[1] = (ptr->unk4.y[0] >> 1);
            gpVertexN64->v.ob[2] = (ptr->unk4.z[0] >> 1);
            gpVertexN64->v.tc[0] = 0;
            gpVertexN64->v.tc[1] = 0;
            gpVertexN64->v.cn[0] = 0xFF;
            gpVertexN64->v.cn[1] = 0xFF;
            gpVertexN64->v.cn[2] = 0xFF;
            gpVertexN64->v.cn[3] = 0xFF;
            gpVertexN64++;
            gpVertexN64->v.ob[0] = (ptr->unk4.x[1] >> 1);
            gpVertexN64->v.ob[1] = (ptr->unk4.y[1] >> 1);
            gpVertexN64->v.ob[2] = (ptr->unk4.z[1] >> 1);
            gpVertexN64->v.tc[0] = 0x800;
            gpVertexN64->v.tc[1] = 0;
            gpVertexN64->v.cn[0] = 0xFF;
            gpVertexN64->v.cn[1] = 0xFF;
            gpVertexN64->v.cn[2] = 0xFF;
            gpVertexN64->v.cn[3] = 0xFF;
            gpVertexN64++;
            gpVertexN64->v.ob[0] = (ptr->unk4.x[2] >> 1);
            gpVertexN64->v.ob[1] = (ptr->unk4.y[2] >> 1);
            gpVertexN64->v.ob[2] = (ptr->unk4.z[2] >> 1);
            gpVertexN64->v.tc[0] = 0x800;
            gpVertexN64->v.tc[1] = 0x800;
            gpVertexN64->v.cn[0] = 0xFF;
            gpVertexN64->v.cn[1] = 0xFF;
            gpVertexN64->v.cn[2] = 0xFF;
            gpVertexN64->v.cn[3] = 0xFF;
            gpVertexN64++;
            func_8000B570(1);

            gSPPopMatrix(gpDisplayList++, G_MTX_MODELVIEW);
            i = gNextSpriteStat[i];
        }
        else
            break;
    }
}

/*800946B8*/
void func_800946B8(void)
{
    s16 sectnum;
    s32 i, nexti;
    SpriteType *spr;

    i = gHeadSpriteStat[300];
    while (i >= 0)
    {
        nexti = gNextSpriteStat[i];
        spr = &gpSprite[i];
        spr->x += spr->unk18 >> 3;
        spr->y += spr->unk1A >> 3;
        spr->z += spr->unk1C;
        sectnum = spr->sectnum;

        if (sectnum == -1)
        {
            D_80106730[gpSprite[i].unk22].unk0 = 0;
            deleteSprite(i);
        }
        else if ((getFlorzOfSlope(sectnum, spr->x, spr->y) >> 4) < spr->z)
        {
            D_80106730[gpSprite[i].unk22].unk0 = 0;
            deleteSprite(i);
        }
        else
        {
            if ((D_80106730[gpSprite[i].unk22].unk2 != 0) &&
                (D_80106730[gpSprite[i].unk22].unk2--, D_80106730[gpSprite[i].unk22].unk2) == 0)
            {
                D_80106730[gpSprite[i].unk22].unk0 = 0;
                deleteSprite(i);
            }
            else
            {
                spr->unk1C += 8;
                spr->ang = (spr->ang + D_80106730[gpSprite[i].unk22].unk28) & 0x7FF;
                D_8013B2D0[i].unk0 = (D_8013B2D0[i].unk0 + D_80106730[gpSprite[i].unk22].unk2C) & 0x7FF;
            }
        }
        i = nexti;
    }
}
