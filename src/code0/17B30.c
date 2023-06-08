#include "common.h"
#include "code0/main.h"
#include "code0/cache1d.h"
#include "code0/edl.h"
#include "code0/4600.h"
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
void func_80016F7C(code0unkStruct7 *arg0)
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
        arg0->unk1C = (u16 *)(arg0->ramaddr + (arg0->unk14 * 6));
    }
}

/*80017090*/
static void func_80017090(code0unkStruct8 *arg0, code0unkStruct7 *arg1, s16 arg2)
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
static void func_800170E0(code0unkStruct8 *arg0, code0unkStruct7 *arg1, s16 arg2)
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
static void func_80017134(code0unkStruct8 *arg0, code0unkStruct7 *arg1, s16 arg2)
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
static void func_80017180(code0unkStruct8 *arg0, code0unkStruct7 *arg1, s16 arg2)
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
void func_800171D0(code0unkStruct8 *arg0, code0unkStruct7 *arg1, s16 arg2)
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
INCLUDE_ASM("nonmatchings/src/code0/17B30", func_800195DC);
