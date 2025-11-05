#include "common.h"
#include "code0/pragmas.h"
#include "code0/audio.h"
#include "code0/graphics.h"
#include "code0/4590.h"
#include "code0/getangle.h"
#include "code0/37090.h"
#include "code0/41940.h"
#include "code1/code1.h"

/*.data*/
/*800DEE70*/ s16 D_800DEE70 = 0;

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

    hitScan(D_801A2790[gPlayerNum].x,
            D_801A2790[gPlayerNum].y,
            D_801A2790[gPlayerNum].z,
            D_801A2790[gPlayerNum].cursectnum,
            x,
            y,
            z * 16,
            &hitsect, &hitwall, &hitsprite, &hitx, &hity, &hitz, 0x10001);

    if ((gpSector[hitsect].unk18 == 3) && (D_801A2790[gPlayerNum].z != hitz))
    {
        z = func_80036490(hitsect);
        if (gPlayer[gPlayerNum].unk54 == 0)
        {
            if (z < hitz)
            {
                fz = (f32)(z - hitz) / (D_801A2790[gPlayerNum].z - hitz);
                hitz = z;
                hitx = (((D_801A2790[gPlayerNum].x - hitx) * fz) + hitx);
                hity = (((D_801A2790[gPlayerNum].y - hity) * fz) + hity);
            }
        }
        else
        {
            if (hitz < z)
            {
                fz = (f32)(z - hitz) / (D_801A2790[gPlayerNum].z - hitz);
                hitz = z;
                hitx = (((D_801A2790[gPlayerNum].x - hitx) * fz) + hitx);
                hity = (((D_801A2790[gPlayerNum].y - hity) * fz) + hity);
            }
        }
    }
    fx = hitx - D_801A2790[gPlayerNum].x;
    fy = hity - D_801A2790[gPlayerNum].y;
    fz = (hitz - D_801A2790[gPlayerNum].z) / 16.0;
    return CLAMP_MIN((sqrtf(SQ(fx) + SQ(fy) + SQ(fz)) - 64.0), 0.0);
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
void func_8003F340(void)
{
    f32 sp10[4];
    f32 sp20;
    f32 sp24;
    f32 sp28;
    f32 f1, f2;
    s16 i;
    s32 j;
    u16 cstat;

    if (gPlayer[gPlayerNum].unk52 == -1)
    {
        D_801A2790[gPlayerNum].x = gPlayer[gPlayerNum].xpos;
        D_801A2790[gPlayerNum].y = gPlayer[gPlayerNum].ypos;
        D_801A2790[gPlayerNum].z = gPlayer[gPlayerNum].zpos;
        D_801A2790[gPlayerNum].cursectnum = gPlayer[gPlayerNum].cursectnum;
        i = gPlayer[gPlayerNum].unk4A;
    }
    else
    {
        s32 a;
        a = gPlayer[gPlayerNum].unk52 & 0x7FF;
        D_801A2790[gPlayerNum].x = gpSprite[a].x;
        D_801A2790[gPlayerNum].y = gpSprite[a].y;
        D_801A2790[gPlayerNum].z = gpSprite[a].z;

        if (gpSprite[a].picnum != 46)
            D_801A2790[gPlayerNum].z += 4965;

        D_801A2790[gPlayerNum].cursectnum = gpSprite[a].sectnum;
        gPlayer[gPlayerNum].unk68 = gpSprite[a].sectnum;
        gPlayer[gPlayerNum].unk55 = func_8004EFB4(a);
        return;
    }

    if (gPlayer[gPlayerNum].unk54 == 0)
    {
        if ((gPlayer[gPlayerNum].unk59 != 0) || (gPlayer[gPlayerNum].unk56 != 0))
            D_801A2790[gPlayerNum].unkC += (-D_801A2790[gPlayerNum].unkC / 2);
        else
        {
            if (gPlayer[gPlayerNum].unk44 != 0)
            {
                if (gPlayer[gPlayerNum].zvect > 0)
                    D_801A2790[gPlayerNum].unkC = MAX(-((gPlayer[gPlayerNum].unk40 - 0x400) / 2), D_801A2790[gPlayerNum].unkC - 0x100);

                if (gPlayer[gPlayerNum].zvect < 0)
                    D_801A2790[gPlayerNum].unkC = MIN((gPlayer[gPlayerNum].unk40 - 0x400) / 2, D_801A2790[gPlayerNum].unkC + 0x100);
            }
        }
    }
    else
        D_801A2790[gPlayerNum].unkC += (-D_801A2790[gPlayerNum].unkC / 2);

    if (!gPlayer[gPlayerNum].third_person)
    {
        gPlayer[gPlayerNum].unk68 = gPlayer[gPlayerNum].cursectnum;
        gPlayer[gPlayerNum].unk55 = gPlayer[gPlayerNum].unk54;
    }
    else
    {
        D_801A2790[gPlayerNum].z += D_801A2790[gPlayerNum].unkC;
        j = (D_801A2790[gPlayerNum].unk1C - 0x200);
        D_800FE40C = (D_801A2790[gPlayerNum].unk16 + j);
        D_800FF4E8 = (D_801A2790[gPlayerNum].unk18 + D_801A2790[gPlayerNum].unk1E);

        D_800FE40C *= PI/1024;
        D_800FF4E8 = ((D_800FF4E8 * (PI/1024)) + (PI/24));
        sp20 = -cosf(D_800FE40C);
        sp24 = -sinf(D_800FE40C);
        sp28 = -sinf(D_800FF4E8) / cosf(D_800FF4E8);
        grNormalize(&sp20, &sp24, &sp28);
        cstat = gpSprite[i].cstat;
        gpSprite[i].cstat = cstat & ~0x101;
        f1 = func_8003EED0(0.0f, 0.0f);
        sp10[0] = func_8003EED0((PI/24), 0.0f);
        sp10[1] = func_8003EED0(-(PI/24), 0.0f);
        sp10[2] = func_8003EED0(0.0f, (PI/24));
        sp10[3] = func_8003EED0(0.0f, -(PI/24));
        gpSprite[i].cstat = cstat;

        if (D_80119A30[gPlayerNum] != 0)
            D_801A2790[gPlayerNum].unk24 = (gpSinTable[(D_8012FD88 * 136) & 0x7FF] / 256) + 0x800;
        else
            D_801A2790[gPlayerNum].unk24 += ((1524 - D_801A2790[gPlayerNum].unk24) / 8);

        f2 = MIN(sp10[0], sp10[1]);
        f2 = MIN(f2, sp10[2]);
        f2 = MIN(f2, sp10[3]);
        f2 = MIN(f2, D_801A2790[gPlayerNum].unk24);

        gPlayer[gPlayerNum].unk64 = (gPlayer[gPlayerNum].unk64 + ((f2 - gPlayer[gPlayerNum].unk64) / 4.0));
        gPlayer[gPlayerNum].unk64 = MIN(gPlayer[gPlayerNum].unk64, f1);
        D_801A2790[gPlayerNum].x += (gPlayer[gPlayerNum].unk64 * sp20);
        D_801A2790[gPlayerNum].y += (gPlayer[gPlayerNum].unk64 * sp24);
        D_801A2790[gPlayerNum].z += (gPlayer[gPlayerNum].unk64 * sp28 * 16.0f);
        updateSectorZ(D_801A2790[gPlayerNum].x, D_801A2790[gPlayerNum].y, D_801A2790[gPlayerNum].z, &gPlayer[gPlayerNum].unk68);

        i = gPlayer[gPlayerNum].unk68;
        if (gPlayer[gPlayerNum].unk68 == -1)
        {
            updateSector(D_801A2790[gPlayerNum].x, D_801A2790[gPlayerNum].y, &gPlayer[gPlayerNum].unk68);
            if (gPlayer[gPlayerNum].unk68 == i)
                gPlayer[gPlayerNum].unk68 = gPlayer[gPlayerNum].cursectnum;
        }
        gPlayer[gPlayerNum].unk55 = 0;

        if (gpSector[gPlayer[gPlayerNum].unk68].unk18 == 2)
            gPlayer[gPlayerNum].unk55 = 1;
        else  if ((gpSector[gPlayer[gPlayerNum].unk68].unk18 == 3) && (D_801A2790[gPlayerNum].z > func_80036490(gPlayer[gPlayerNum].unk68)))
        {
            D_801A19EC = D_8012D338;
            gPlayer[gPlayerNum].unk55 = 1;
        }

        j = (s16)((gPlayer[gPlayerNum].unk64 * 512.0f) / 1524.0) - gPlayer[gPlayerNum].unk6A;
        gPlayer[gPlayerNum].unk6A += j / 4;
    }
}

/*8003FD5C*/
void func_8003FD5C(void)
{
    s16 spritenum;
    s32 x, y, z;
    s16 ang;
    s32 i, j, k, l, m, n;
    s32 temp;

    if (gPlayer[gPlayerNum].unk45 == 0)
    {
        if ((gButton[gPlayerNum] != 0) ||
            (klabs(gStickX[gPlayerNum]) >= 4) ||
            (klabs(gStickY[gPlayerNum]) >= 4))
        {
            gPlayer[gPlayerNum].unk4E = 0;
            D_801A2790[gPlayerNum].unk20 = 0;
        }
    }

    if ((gPlayer[gPlayerNum].unk52 < 0x800) || (gPlayer[gPlayerNum].unk45 != 0))
        gPlayer[gPlayerNum].unk4E++;
    else
        gPlayer[gPlayerNum].unk4E = 0;

    if (gActor[gActorSpriteMap[gPlayer[gPlayerNum].unk4A]].unk9E == 253)
        gPlayer[gPlayerNum].unk4E += 3;

    if ((gPlayer[gPlayerNum].unk45 != 0) && (gPlayer[gPlayerNum].unk4E > 1000))
        gPlayer[gPlayerNum].unk4E = 1000;

    if (D_801A2790[gPlayerNum].unk20 == 0)
    {
        if (gConfig.autocenter[gPlayerNum] != 0)
        {
            if (gPlayer[gPlayerNum].unk4E > 150)
                gPlayer[gPlayerNum].unk3E /= 2;
        }

        if ((gPlayer[gPlayerNum].unk4E > 1200) && (gPlayer[gPlayerNum].unk45 == 0))
        {
            gPlayer[gPlayerNum].unk4E = 0;
            D_801A2790[gPlayerNum].unk20 = 1;
            if (gPlayer[gPlayerNum].unk52 < 0x800)
                audio_800080E0(gPlayerNum, 1);
        }
    }
    else
    {
        if ((gPlayer[gPlayerNum].unk45 == 0) && !(gPlayer[gPlayerNum].unk4E & 0x3FF))
        {
            if (gPlayer[gPlayerNum].unk52 < 0x800)
                audio_800080E0(gPlayerNum, 1);
        }
    }

    spritenum = gPlayer[gPlayerNum].unk52;
    if (spritenum >= 0)
    {
        spritenum &= 0x7FF;
        if (D_800DEF1C >= 0)
        {
            x = gpSprite[D_800DEF1C].x - gpSprite[spritenum].x;
            y = gpSprite[D_800DEF1C].y - gpSprite[spritenum].y;
            ang = (D_8013B2D0[spritenum].unk4 + getAngle(x, y)) & 0x7FF;
            D_801A2790[gPlayerNum].unk16 = (ang + 512) & 0x7FF;
            z = (gpSprite[D_800DEF1C].z - gpSprite[spritenum].z) / 16;
            ang = (getAngleF(z, findDistance2D(x, y)) * (1024.0f/PI));
            D_801A2790[gPlayerNum].unk18 = (ang + D_8013B2D0[spritenum].unk2) & 0x7FF;
            D_801A2790[gPlayerNum].unk1A = 0;
        }
        else
        {
            D_801A2790[gPlayerNum].unk16 = (gpSprite[spritenum].ang + 512) & 0x7FF;
            D_801A2790[gPlayerNum].unk18 = -gpSprite[spritenum].unk16;
            D_801A2790[gPlayerNum].unk1A = 0;
        }
    }
    else if (gPlayer[gPlayerNum].third_person)
    {
        if (D_801A2790[gPlayerNum].unk20 != 0)
        {
            gPlayer[gPlayerNum].unk3E /= 2;
            temp = (gPlayer[gPlayerNum].unk4E * 2) + 512;
            i = (gPlayer[gPlayerNum].ang + temp) & 0x7FF;
        }
        else
            i = (gPlayer[gPlayerNum].ang + 512) & 0x7FF;

        i = i -  D_801A2790[gPlayerNum].unk16;

        if (i > 0x400)
            i -= 0x800;

        if (i < -0x400)
            i += 0x800;

        D_801A2790[gPlayerNum].unk16 += (i / 4);
        D_801A2790[gPlayerNum].unk16 = (D_801A2790[gPlayerNum].unk16 + func_8003F29C()) & 0x7FF;

        j = gPlayer[gPlayerNum].unk3E - D_801A2790[gPlayerNum].unk18;

        if (gPlayer[gPlayerNum].unk45 != 0)
            j += 0x80;

        if (j > 0x400)
            j -= 0x800;

        if (j < -0x400)
            j += 0x800;

        D_801A2790[gPlayerNum].unk18 += (j / 4);
        D_801A2790[gPlayerNum].unk18 = (D_801A2790[gPlayerNum].unk18 + func_8003F29C()) & 0x7FF;

        if (D_801A2790[gPlayerNum].unk18 > 0x400)
        {
            D_801A2790[gPlayerNum].unk18 -= 0x800;
        }

        k = gPlayer[gPlayerNum].unk3C - D_801A2790[gPlayerNum].unk1A;

        if (k > 0x400)
            k -= 0x800;

        if (k < -0x400)
            k += 0x800;

        D_801A2790[gPlayerNum].unk1A += (k / 4);
        D_801A2790[gPlayerNum].unk1A = (D_801A2790[gPlayerNum].unk1A + func_8003F29C()) & 0x7FF;
    }
    else
    {
        temp = 512; /*FAKEMATCH*/
        D_801A2790[gPlayerNum].unk16 = (gPlayer[gPlayerNum].ang + (func_8003F29C() + temp)) & 0x7FF;
        D_801A2790[gPlayerNum].unk18 = (gPlayer[gPlayerNum].unk3E + func_8003F29C()) & 0x7FF;

        l = gPlayer[gPlayerNum].unk3C - D_801A2790[gPlayerNum].unk1A;

        if (l > 0x400)
            l -= 0x800;

        if (l < -0x400)
            l += 0x800;

        D_801A2790[gPlayerNum].unk1A = (D_801A2790[gPlayerNum].unk1A + (func_8003F29C() + (l / 4))) & 0x7FF;
    }

    m = 0;
    n = (D_800DEE98 != 0) ? 7 : 0;

    if (gPlayer[gPlayerNum].unk55 != 0)
    {
        n = 5;
        m = 17;
    }

    if (gPlayer[gPlayerNum].unk82 != 0)
    {
        n = 15;
        m = 23;
    }

    if (n == 0)
        D_801A2790[gPlayerNum].unk14 = 0;
    else
        D_801A2790[gPlayerNum].unk14 += n;

    if (m == 0)
        D_801A2790[gPlayerNum].unk12 = 0;
    else
        D_801A2790[gPlayerNum].unk12 += m;


    D_801A2790[gPlayerNum].unk14 &= 0x7FF;
    D_801A2790[gPlayerNum].unk12 &= 0x7FF;
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
