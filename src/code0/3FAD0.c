#include "common.h"
#include "code0/37090.h"
#include "code0/41940.h"

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

INCLUDE_ASM("nonmatchings/src/code0/3FAD0", func_8003F340);

INCLUDE_ASM("nonmatchings/src/code0/3FAD0", func_8003FD5C);

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

