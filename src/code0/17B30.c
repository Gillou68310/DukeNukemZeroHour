#include "common.h"
#include "code0/main.h"
#include "code0/cache1d.h"
#include "code0/D8D20.h"
#include "code0/edl.h"
#include "code0/4600.h"
#include "code0/8EFE0.h"
#include "code0/code0.h"

extern u8 files_blks_ROM_START[];

/*.text*/

/*80016F30*/
void func_80016F30(void)
{
    s16 i;

    for (i = 0; i < ARRAY_COUNT(D_80197E40); i++)
    {
        (&D_80197E40[i])->unk4 = NULL; /*FAKEMATCH*/
        D_80197E40[i].unk8 = NULL;
    }
}

/*80016F7C*/
void func_80016F7C(_D8D20UnkStruct2 *arg0)
{
    u8 *romaddr;
    s32 size;

    arg0->lock = -126;
    if (arg0->ramaddr == NULL)
    {
        size = arg0->unkC;
        alloCache(&arg0->ramaddr, (size + 1) & ~1, (u8 *)&arg0->lock);
        D_80169520 = 200;
        size = arg0->unk10;
        alloCache(&D_80138854, size, &D_80169520);
        romaddr = files_blks_ROM_START;
        romaddr += arg0->fileoff;
        readRom(D_80138854, romaddr, (size + 1) & ~1);

        if (decompressEDL(D_80138854, arg0->ramaddr) != 0)
            Bmemcpy(arg0->ramaddr, D_80138854, size);

        suckCache(&D_80138854);
        arg0->unk18 = (u16 *)arg0->ramaddr;
        arg0->unk1C = &((_D8D20UnkStruct1 *)arg0->ramaddr)[arg0->unk14];
    }
}

/*80017090*/
static void func_80017090(code0unkStruct8 *arg0, _D8D20UnkStruct2 *arg1, s16 arg2)
{
    if (arg0->unkC < (arg0->unk10 / 2))
    {
        arg0->unk14 = arg0->unk0;
        arg0->unk18 = arg0->unk4;
    }
    arg0->unkC = arg2;
    arg0->unk10 = arg2;
    arg0->unk0 = 0;
    arg0->unk4 = arg1;
}

/*800170E0*/
static void func_800170E0(code0unkStruct8 *arg0, _D8D20UnkStruct2 *arg1, s16 arg2)
{
    if (arg0->unkC < (arg0->unk10 / 2))
    {
        arg0->unk14 = arg0->unk0;
        arg0->unk18 = arg0->unk4;
    }
    arg0->unkC = arg2;
    arg0->unk10 = arg2;
    arg0->unk4 = arg1;
    arg0->unk0 = arg0->unk2;
}

/*80017134*/
static void func_80017134(code0unkStruct8 *arg0, _D8D20UnkStruct2 *arg1, s16 arg2)
{
    if (arg0->unkC < (arg0->unk10 / 2))
    {
        arg0->unk14 = arg0->unk0;
        arg0->unk18 = arg0->unk4;
    }
    arg0->unkC = arg2;
    arg0->unk10 = arg2;
    arg0->unk4 = arg1;
}

/*80017180*/
static void func_80017180(code0unkStruct8 *arg0, _D8D20UnkStruct2 *arg1, s16 arg2)
{
    if (arg0->unkE < (arg0->unk12 / 2))
    {
        arg0->unk16 = arg0->unk2;
        arg0->unk1C = arg0->unk8;
    }
    arg0->unkE = arg2;
    arg0->unk12 = arg2;
    arg0->unk2 = 0;
    arg0->unk8 = arg1;
}

/*800171D0*/
void func_800171D0(code0unkStruct8 *arg0, _D8D20UnkStruct2 *arg1, s16 arg2)
{
    if (arg0->unkC < (arg0->unk10 / 2))
    {
        arg0->unk14 = arg0->unk0;
        arg0->unk18 = arg0->unk4;
    }
    if (arg0->unkE < (arg0->unk12 / 2))
    {
        arg0->unk16 = arg0->unk2;
        arg0->unk1C = arg0->unk8;
    }
    arg0->unkC = arg2;
    arg0->unk10 = arg2;
    arg0->unkE = arg2;
    arg0->unk12 = arg2;
    arg0->unk0 = 0;
    arg0->unk4 = arg1;
    arg0->unk2 = 0;
    arg0->unk8 = arg1;
}

/*80017268*/
INCLUDE_ASM("nonmatchings/src/code0/17B30", func_80017268);

/*800195DC*/
void func_800195DC(s16 spritenum)
{
    s16 i;

    switch (gpSprite[spritenum].picnum)
    {
    case 1674:
    case 1675:
    case 2360:
        gpSprite[spritenum].ang = (gpSprite[spritenum].ang + 6) & 0x7FF;
        break;
    case 2359:
        gpSprite[spritenum].ang = (gpSprite[spritenum].ang - 6) & 0x7FF;
        break;
    case 2206:
        gpSprite[spritenum].ang = (gpSprite[spritenum].ang + 1) & 0x7FF;
        break;
    case 2209:
        D_8013B2D0[spritenum].unk0 = (D_8013B2D0[spritenum].unk0 + 65) & 0x7FF;
        break;
    case 2212:
    case 2213:
    case 2214:
    case 2215:
        gpSprite[spritenum].picnum++;
        if (gpSprite[spritenum].picnum >= 2216)
            gpSprite[spritenum].picnum = 2212;
        break;
    case 2484:
        gpSprite[spritenum].ang = (gpSprite[spritenum].ang + 11) & 0x7FF;
        break;
    case 2488:
        gpSprite[spritenum].ang = (gpSprite[spritenum].ang - 5) & 0x7FF;
        if ((D_8012FD88 & 0x1F) >= 17)
            gpSprite[spritenum].cstat |= 0x8000;
        else
            gpSprite[spritenum].cstat &= ~0x8000;
        break;
    case 2487:
        gpSprite[spritenum].ang = (gpSprite[spritenum].ang - 5) & 0x7FF;
        if (gpSprite[spritenum].unk25 == 0x22)
            D_8013B2D0[spritenum].unk6 = (gpSinTable[(D_8012FD88 * 8) & 0x7FF] / 128) + 64;
        else
            D_8013B2D0[spritenum].unk6 = (krand() & 0x7F) + 64;
        break;
    case 2253:
        gpSprite[spritenum].ang = (gpSprite[spritenum].ang + 8) & 0x7FF;
        D_8013B2D0[spritenum].unk6 = (krand() & 0x7F) + 64;
        break;
    case 2422:
    case 2320:
        gpSprite[spritenum].ang = (gpSprite[spritenum].ang + 65) & 0x7FF;
        break;
    case 2505:
    case 2506:
    case 2507:
    case 2508:
    case 2509:
    case 2510:
    case 2511:
    case 2512:
    case 2513:
    case 2514:
    case 2515:
    case 2516:
    case 2517:
    case 2518:
        if (!(D_8012FD88 & 3))
            gpSprite[spritenum].picnum++;

        if (gpSprite[spritenum].picnum >= 2519)
            gpSprite[spritenum].picnum = 2505;
        break;
    case 2520:
    case 2521:
    case 2522:
    case 2523:
    case 2524:
    case 2525:
    case 2526:
    case 2527:
    case 2528:
    case 2529:
        gpSprite[spritenum].picnum++;
        if (gpSprite[spritenum].picnum >= 2530)
            gpSprite[spritenum].picnum = 2520;

        break;
    case 2548:
    case 2549:
    case 2550:
    case 2551:
        if ((krand() & 0xFF) < 64)
        {
            i = func_8008E3E0(gpSprite[spritenum].x, gpSprite[spritenum].y,
                              gpSprite[spritenum].z, gpSprite[spritenum].sectnum, 15, 0);
            if (i >= 0)
            {
                gpSprite[i].unk22 = gpSprite[i].unk22 - (krand() & 0xFFF);
                gpSprite[i].unk18 = krand() & 0x7F;
                gpSprite[i].xrepeat = 16;
                gpSprite[i].yrepeat = 16;

                if (gpSprite[spritenum].picnum == 2548)
                    gpSprite[i].ang = 1792;

                if (gpSprite[spritenum].picnum == 2549)
                    gpSprite[i].ang = 1280;

                if (gpSprite[spritenum].picnum == 2550)
                    gpSprite[i].ang = 256;

                if (gpSprite[spritenum].picnum == 2551)
                    gpSprite[i].ang = 768;

                gpSprite[i].ang += (krand() & 0x7F) - 64;
            }
        }
        break;

    case 2591:
    case 2592:
        if (!(D_8012FD88 & 0xF))
            gpSprite[spritenum].picnum++;

        if (gpSprite[spritenum].picnum >= 2593)
            gpSprite[spritenum].picnum = 2591;
        break;
    }
}
