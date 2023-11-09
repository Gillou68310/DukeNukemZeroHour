#include "common.h"
#include "code0/pragmas.h"
#include "code0/audio.h"
#include "code0/2ABE0.h"
#include "code0/37090.h"
#include "code0/41940.h"
#include "code1/code1.h"

/*.comm*/
/*800FE40C*/ f32 D_800FE40C;
/*800FF4E8*/ f32 D_800FF4E8;

/*.text*/

/*8003EED0*/
static f32 func_8003EED0(f32 arg0, f32 arg1)
{
    s16 hitsect, hitwall, hitsprite;
    s32 hitx, hity, hitz;
    s32 x, y, z;

    f32 fx, fy, fz;
    f32 f1, f2;

    f1 = D_800FE40C + arg0;
    f2 = D_800FF4E8 + arg1;
    fx = -cosf(f1);
    fy = -sinf(f1);
    fz = -sinf(f2);
    fz = (fz / cosf(f2));
    x = fx * 16384.0f;
    y = fy * 16384.0f;
    z = fz * 16384.0f;

    hitScan(D_801A2790[D_801B0820].unk0,
            D_801A2790[D_801B0820].unk4,
            D_801A2790[D_801B0820].unk8,
            D_801A2790[D_801B0820].unk10,
            x,
            y,
            z * 16,
            &hitsect, &hitwall, &hitsprite, &hitx, &hity, &hitz, 0x10001);

    if ((gpSector[hitsect].unk18 == 3) && (D_801A2790[D_801B0820].unk8 != hitz))
    {
        z = func_80036490(hitsect);
        if (gPlayer[D_801B0820].unk54 == 0)
        {
            if (z < hitz)
            {
                fz = (f32)(z - hitz) / (D_801A2790[D_801B0820].unk8 - hitz);
                hitz = z;
                hitx = (((D_801A2790[D_801B0820].unk0 - hitx) * fz) + hitx);
                hity = (((D_801A2790[D_801B0820].unk4 - hity) * fz) + hity);
            }
        }
        else
        {
            if (hitz < z)
            {
                fz = (f32)(z - hitz) / (D_801A2790[D_801B0820].unk8 - hitz);
                hitz = z;
                hitx = (((D_801A2790[D_801B0820].unk0 - hitx) * fz) + hitx);
                hity = (((D_801A2790[D_801B0820].unk4 - hity) * fz) + hity);
            }
        }
    }
    fx = hitx - D_801A2790[D_801B0820].unk0;
    fy = hity - D_801A2790[D_801B0820].unk4;
    fz = (hitz - D_801A2790[D_801B0820].unk8) / 16.0;
    return CLAMP_MIN((sqrtf((fx * fx) + (fy * fy) + (fz * fz)) - 64.0), 0.0);
}

/*8003F29C*/
static s16 func_8003F29C(void)
{
    s16 max;

    if (D_800DEE88 != 0)
    {
        max = CLAMP_MIN((D_800DEE8C * 2), 4);
        return ((krand() % max) - (max / 2));
    }
    else
        return 0;
}

/*8003F340*/
INCLUDE_ASM("nonmatchings/src/code0/3FAD0", func_8003F340);

/*8003FD5C*/
void func_8003FD5C(void)
{
    s16 spritenum;
    s32 x, y, z;
    s16 ang;
    s32 i, j, k, l, m, n;
    s32 temp;

    if (gPlayer[D_801B0820].unk45 == 0)
    {
        if ((D_8012F6FC[D_801B0820] != 0) ||
            (klabs(D_8011A670[D_801B0820]) >= 4) ||
            (klabs(D_8013A43C[D_801B0820]) >= 4))
        {
            gPlayer[D_801B0820].unk4E = 0;
            D_801A2790[D_801B0820].unk20 = 0;
        }
    }

    if ((gPlayer[D_801B0820].unk52 < 0x800) || (gPlayer[D_801B0820].unk45 != 0))
        gPlayer[D_801B0820].unk4E++;
    else
        gPlayer[D_801B0820].unk4E = 0;

    if (D_8019B940[D_80106D50[gPlayer[D_801B0820].unk4A]].unk9E == 253)
        gPlayer[D_801B0820].unk4E += 3;

    if ((gPlayer[D_801B0820].unk45 != 0) && (gPlayer[D_801B0820].unk4E > 1000))
        gPlayer[D_801B0820].unk4E = 1000;

    if (D_801A2790[D_801B0820].unk20 == 0)
    {
        if (D_801CE498.unk46[D_801B0820] != 0)
        {
            if (gPlayer[D_801B0820].unk4E > 150)
                gPlayer[D_801B0820].unk3E /= 2;
        }

        if ((gPlayer[D_801B0820].unk4E > 1200) && (gPlayer[D_801B0820].unk45 == 0))
        {
            gPlayer[D_801B0820].unk4E = 0;
            D_801A2790[D_801B0820].unk20 = 1;
            if (gPlayer[D_801B0820].unk52 < 0x800)
                audio_800080E0(D_801B0820, 1);
        }
    }
    else
    {
        if ((gPlayer[D_801B0820].unk45 == 0) && !(gPlayer[D_801B0820].unk4E & 0x3FF))
        {
            if (gPlayer[D_801B0820].unk52 < 0x800)
                audio_800080E0(D_801B0820, 1);
        }
    }

    spritenum = gPlayer[D_801B0820].unk52;
    if (spritenum >= 0)
    {
        spritenum &= 0x7FF;
        if (D_800DEF1C >= 0)
        {
            x = gpSprite[D_800DEF1C].x - gpSprite[spritenum].x;
            y = gpSprite[D_800DEF1C].y - gpSprite[spritenum].y;
            ang = (D_8013B2D0[spritenum].unk4 + getAngle(x, y)) & 0x7FF;
            D_801A2790[D_801B0820].unk16 = (ang + 512) & 0x7FF;
            z = (gpSprite[D_800DEF1C].z - gpSprite[spritenum].z) / 16;
            ang = (func_80029FE0(z, findDistance2D(x, y)) * 325.9493234521802);
            D_801A2790[D_801B0820].unk18 = (ang + D_8013B2D0[spritenum].unk2) & 0x7FF;
            D_801A2790[D_801B0820].unk1A = 0;
        }
        else
        {
            D_801A2790[D_801B0820].unk16 = (gpSprite[spritenum].ang + 512) & 0x7FF;
            D_801A2790[D_801B0820].unk18 = -gpSprite[spritenum].unk16;
            D_801A2790[D_801B0820].unk1A = 0;
        }
    }
    else if (gPlayer[D_801B0820].unk60 != 0)
    {
        if (D_801A2790[D_801B0820].unk20 != 0)
        {
            gPlayer[D_801B0820].unk3E /= 2;
            temp = (gPlayer[D_801B0820].unk4E * 2) + 512;
            i = (gPlayer[D_801B0820].unk38 + temp) & 0x7FF;
        }
        else
            i = (gPlayer[D_801B0820].unk38 + 512) & 0x7FF;

        i = i -  D_801A2790[D_801B0820].unk16;

        if (i > 0x400)
            i -= 0x800;

        if (i < -0x400)
            i += 0x800;

        D_801A2790[D_801B0820].unk16 += (i / 4);
        D_801A2790[D_801B0820].unk16 = (D_801A2790[D_801B0820].unk16 + func_8003F29C()) & 0x7FF;

        j = gPlayer[D_801B0820].unk3E - D_801A2790[D_801B0820].unk18;

        if (gPlayer[D_801B0820].unk45 != 0)
            j += 0x80;

        if (j > 0x400)
            j -= 0x800;

        if (j < -0x400)
            j += 0x800;

        D_801A2790[D_801B0820].unk18 += (j / 4);
        D_801A2790[D_801B0820].unk18 = (D_801A2790[D_801B0820].unk18 + func_8003F29C()) & 0x7FF;

        if (D_801A2790[D_801B0820].unk18 > 0x400)
        {
            D_801A2790[D_801B0820].unk18 -= 0x800;
        }

        k = gPlayer[D_801B0820].unk3C - D_801A2790[D_801B0820].unk1A;

        if (k > 0x400)
            k -= 0x800;

        if (k < -0x400)
            k += 0x800;

        D_801A2790[D_801B0820].unk1A += (k / 4);
        D_801A2790[D_801B0820].unk1A = (D_801A2790[D_801B0820].unk1A + func_8003F29C()) & 0x7FF;
    }
    else
    {
        temp = 512; /*FAKEMATCH*/
        D_801A2790[D_801B0820].unk16 = (gPlayer[D_801B0820].unk38 + (func_8003F29C() + temp)) & 0x7FF;
        D_801A2790[D_801B0820].unk18 = (gPlayer[D_801B0820].unk3E + func_8003F29C()) & 0x7FF;

        l = gPlayer[D_801B0820].unk3C - D_801A2790[D_801B0820].unk1A;

        if (l > 0x400)
            l -= 0x800;

        if (l < -0x400)
            l += 0x800;

        D_801A2790[D_801B0820].unk1A = (D_801A2790[D_801B0820].unk1A + (func_8003F29C() + (l / 4))) & 0x7FF;
    }

    m = 0;
    n = (D_800DEE98 != 0) ? 7 : 0;

    if (gPlayer[D_801B0820].unk55 != 0)
    {
        n = 5;
        m = 17;
    }

    if (gPlayer[D_801B0820].unk82 != 0)
    {
        n = 15;
        m = 23;
    }

    if (n == 0)
        D_801A2790[D_801B0820].unk14 = 0;
    else
        D_801A2790[D_801B0820].unk14 += n;

    if (m == 0)
        D_801A2790[D_801B0820].unk12 = 0;
    else
        D_801A2790[D_801B0820].unk12 += m;


    D_801A2790[D_801B0820].unk14 &= 0x7FF;
    D_801A2790[D_801B0820].unk12 &= 0x7FF;
}

/*80040890*/
void func_80040890(void)
{
    s16 i;
    SpriteType *spr;

    if (D_800DEE70 > 0)
    {
        D_800DEE70--;
        if (D_800DEE70 == 0)
        {
            gPlayer[0].unk52 = -1;
            D_800DEE80 = -1;
        }
    }

    i = gHeadSpriteStat[113];
    while (i >= 0)
    {
        if (gpSprite[i].picnum >= 2497)
        {
            if (gpSprite[i].picnum < 2501)
            {
                gpSprite[i].picnum++;
                if (gpSprite[i].picnum >= 2501)
                    gpSprite[i].picnum = 2497;
            }
            else
            {
                if (gpSprite[i].picnum < 2505)
                {
                    gpSprite[i].picnum++;
                    if (gpSprite[i].picnum >= 2505)
                        gpSprite[i].picnum = 2501;
                }
            }
        }
        i = gNextSpriteStat[i];
    }

    i = gHeadSpriteStat[114];
    while (i >= 0)
    {
        spr = &gpSprite[i];
        if (spr->unk2A == 81)
        {
            if (spr->unk1A >= 5)
            {
                if (spr->unk2B != 0)
                {
                    spr->ang += 4;
                    spr->unk18 += 4;
                    if (spr->unk18 >= spr->unk1A)
                        spr->unk2B = 0;
                }
                else
                {
                    spr->ang -= 4;
                    spr->unk18 -= 4;
                    if (spr->unk18 <= (-spr->unk1A))
                        spr->unk2B = 1;
                }
                spr->ang &= 0x7FF;
            }
        }
        i = gNextSpriteStat[i];
    }
}
