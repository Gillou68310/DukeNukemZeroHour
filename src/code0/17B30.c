#include "common.h"
#include "ld_symbols.h"
#include "code0/main.h"
#include "code0/cache1d.h"
#include "code0/audio.h"
#include "code0/data/D8D20.h"
#include "code0/edl.h"
#include "code0/4600.h"
#include "code0/41940.h"
#include "code0/59D40.h"
#include "code0/6ACA0.h"
#include "code0/6D9E0.h"
#include "code0/8EFE0.h"
#include "code0/code0.h"
#include "code1/EB300.h"

/*.text*/

/*80016F30*/
void func_80016F30(void)
{
    s16 i;

    for (i = 0; i < MAXACTORS; i++)
    {
        D_80197E40[i].unk8 = D_80197E40[i].unk4 = NULL;
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
        size = arg0->dsize;
        alloCache(&arg0->ramaddr, ((size + 1) & ~1), (u8 *)&arg0->lock);
        D_80169520 = 200;
        size = arg0->csize;
        alloCache(&D_80138854, size, &D_80169520);
        romaddr = blks_ROM_START;
        romaddr += arg0->fileoff;
        readRom(D_80138854, romaddr, (size + 1) & ~1);

        if (decompressEDL(D_80138854, arg0->ramaddr) != 0)
            Bmemcpy(arg0->ramaddr, D_80138854, size);

        suckCache(&D_80138854);
        arg0->unk18 = (_D8D20UnkStruct3 *)arg0->ramaddr;
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
void func_80017268(s16 spritenum)
{
    code0unkStruct8 *ptr;

    _D8D20UnkStruct2 *ptr2;
    _D8D20UnkStruct2 *ptr3;
    _D8D20UnkStruct2 *ptr4;
    _D8D20UnkStruct2 *ptr7;
    _D8D20UnkStruct2 *ptr5;

#ifdef AVOID_UB
    _D8D20UnkStruct2 *ptr6 = NULL;
#else
    _D8D20UnkStruct2 *ptr6;
#endif

    s32 r;
    s16 i, j, k;
    u8 cond1, cond2, cond3, cond4;
    u8 m;

#ifdef AVOID_UB
    if (gActorSpriteMap[spritenum] < 0)
        return;
#endif

    m = 0;
    ptr = &D_80197E40[gActorSpriteMap[spritenum]];
    i = gpSprite[spritenum].unk16;
    j = gActor[gActorSpriteMap[spritenum]].unk99;
    cond1 = (gActor[gActorSpriteMap[spritenum]].flag&0xFF) >> 7;

    if (gpSprite[spritenum].statnum == 10)
    {
        if (D_8011A680[i][j][0] & 2)
            cond1 = 1;
    }
    else
        i = -1;

    /*FAKEMATCH*/
    do
    {
        do
        {
            if ((gActorSpriteMap[spritenum] == -1) || (gActor[gActorSpriteMap[spritenum]].flag & 0x40))
                return;
        } while (0);
    } while (0);

    if (ptr->unk8 == NULL)
    {
        ptr->unk14 = -1;
        ptr->unk16 = -1;
        ptr->unk2 = 0;
        ptr->unk0 = 0;

        if ((gpSprite[spritenum].picnum == CERBERUSTURRETS) || (gpSprite[spritenum].picnum == GORGONTURRETS) ||
            (gpSprite[spritenum].picnum == SHIP1) || (gpSprite[spritenum].picnum == SHIP2))
            return;

        func_800171D0(ptr, &D_800D81D4, 0);
        if (gpSprite[spritenum].picnum == PARAPSYCHE)
            func_800171D0(ptr, &D_800D8120, 0);

        if (gpSprite[spritenum].picnum == BROODLING)
            func_800171D0(ptr, &D_800D8480, 0);

        if ((gpSprite[spritenum].picnum >= ZOMBIE1 && gpSprite[spritenum].picnum <= 1305) ||
            (gpSprite[spritenum].picnum >= ZOMBIE3 && gpSprite[spritenum].picnum <= ZOMBIE7))
            func_800171D0(ptr, &D_800D84EC, 0);

        if (gpSprite[spritenum].picnum == CHIMERA)
            func_800171D0(ptr, &D_800D8654, 0);

        if (gpSprite[spritenum].picnum == CYBORGENFORCER)
            func_800171D0(ptr, &D_800D884C, 0);

        if (gpSprite[spritenum].picnum == BOSSCYBORGSCORPION)
            func_800171D0(ptr, &D_800D8F54, 0);

        if (gpSprite[spritenum].picnum == MARINE)
            func_800171D0(ptr, &D_800D96C8, 0);

        if (gpSprite[spritenum].picnum == 2356)
            func_800171D0(ptr, &D_800D8BF4, 0);

        if (gpSprite[spritenum].picnum == BOSSZERO)
            func_800171D0(ptr, &D_800D8CF0, 0);

        if (gpSprite[spritenum].picnum == BOSSGIANTHOG)
            func_800171D0(ptr, &D_800D8DEC, 0);

        if (gpSprite[spritenum].picnum == BROODMOTHER)
            func_800171D0(ptr, &D_800D97A0, 0);

        if (gpSprite[spritenum].picnum == BOSSBRAINSTORM)
            func_800171D0(ptr, &D_800D9A94, 0);

        ptr->unk14 = -1;
        ptr->unk16 = -1;
    }

    if (ptr->unkE > 0)
    {
        ptr->unkE--;
        if (ptr->unkE == 0)
            ptr->unk16 = -1;
    }

    if (ptr->unkC > 0)
    {
        ptr->unkC--;
        if (ptr->unkC == 0)
            ptr->unk14 = -1;
    }

    if (gpSprite[spritenum].statnum != 10)
    {
        k = gActor[gActorSpriteMap[spritenum]].unk86;
        if (k & 0x8000)
        {
            k -= 0x8000;
            gActor[gActorSpriteMap[spritenum]].unk86 = k;
            switch (k)
            {
            case 0x0:
            default:
                ptr2 = &D_800D82D0;
                ptr3 = &D_800D82D0;
                break;
            case 0xE:
                ptr2 = &D_800D82D0;
                ptr3 = &D_800D818C;
                break;
            case 0x2:
                ptr2 = &D_800D82D0;
                ptr3 = &D_800D9830;
                break;
            case 0xF:
                ptr2 = &D_800D821C;
                ptr3 = &D_800D89D8;
                break;
            case 0x9:
                ptr2 = &D_800D821C;
                ptr3 = &D_800D81B0;
                break;
            case 0x88:
                ptr2 = &D_800D821C;
                ptr3 = &D_800D89FC;
                break;
            case 0x5:
                ptr3 = &D_800D8120;
                ptr2 = &D_800D8120;
                break;
            case 0x6:
                ptr3 = &D_800D8168;
                ptr2 = &D_800D8168;
                break;
            case 0x3:
                ptr3 = &D_800D83CC;
                ptr2 = &D_800D83CC;
                break;
            case 0x4:
                ptr3 = &D_800D83F0;
                ptr2 = &D_800D83F0;
                break;
            case 0xA:
                ptr3 = &D_800D84EC;
                ptr2 = &D_800D84EC;
                break;
            case 0xD:
                ptr3 = &D_800D8510;
                ptr2 = &D_800D8510;
                break;
            case 0xB:
                ptr3 = &D_800D8480;
                ptr2 = &D_800D8480;
                break;
            case 0xC:
                ptr2 = &D_800D82D0;
                ptr3 = &D_800D9998;
                break;
            case 0x10:
                ptr3 = &D_800D8144;
                ptr2 = &D_800D8144;
                break;
            case 0x11:
                ptr3 = &D_800D8438;
                ptr2 = &D_800D8438;
                break;
            case 0x12:
                ptr3 = &D_800D8414;
                ptr2 = &D_800D8414;
                break;
            case 0x13:
                ptr2 = &D_800D82D0;
                ptr3 = &D_800D8534;
                break;
            case 0x14:
                ptr3 = &D_800D845C;
                ptr2 = &D_800D845C;
                break;
            case 0x15:
                ptr3 = &D_800D84A4;
                ptr2 = &D_800D84A4;
                break;
            case 0x16:
                ptr3 = &D_800D8558;
                ptr2 = &D_800D8558;
                break;
            case 0x17:
                ptr3 = &D_800D8654;
                ptr2 = &D_800D8654;
                break;
            case 0x18:
                ptr3 = &D_800D86C0;
                ptr2 = &D_800D86C0;
                break;
            case 0x19:
                ptr3 = &D_800D86E4;
                ptr2 = &D_800D86E4;
                break;
            case 0x1A:
                ptr3 = &D_800D8708;
                ptr2 = &D_800D8708;
                break;
            case 0x1B:
                ptr3 = &D_800D872C;
                ptr2 = &D_800D872C;
                break;
            case 0x1C:
                ptr3 = &D_800D8750;
                ptr2 = &D_800D8750;
                break;
            case 0x1D:
                ptr3 = &D_800D8774;
                ptr2 = &D_800D8774;
                break;
            case 0x1E:
                ptr3 = &D_800D8798;
                ptr2 = &D_800D8798;
                break;
            case 0x1F:
                ptr3 = &D_800D8804;
                ptr2 = &D_800D8804;
                break;
            case 0x20:
                ptr3 = &D_800D8828;
                ptr2 = &D_800D8828;
                break;
            case 0x22:
                ptr3 = &D_800D884C;
                ptr2 = &D_800D884C;
                break;
            case 0x23:
                ptr3 = &D_800D8870;
                ptr2 = &D_800D8870;
                break;
            case 0x24:
                ptr3 = &D_800D8894;
                ptr2 = &D_800D8894;
                break;
            case 0x25:
                ptr3 = &D_800D88B8;
                ptr2 = &D_800D88B8;
                break;
            case 0x26:
                ptr3 = &D_800D88DC;
                ptr2 = &D_800D88DC;
                break;
            case 0x27:
                ptr3 = &D_800D8900;
                ptr2 = &D_800D8900;
                break;
            case 0x28:
                ptr3 = &D_800D8924;
                ptr2 = &D_800D8924;
                break;
            case 0x29:
                ptr3 = &D_800D8948;
                ptr2 = &D_800D8948;
                break;
            case 0x2A:
                ptr3 = &D_800D896C;
                ptr2 = &D_800D896C;
                break;
            case 0x7:
            case 0x8:
            case 0x2B:
                ptr3 = &D_800D8990;
                ptr2 = &D_800D8990;
                break;
            case 0x2C:
                ptr3 = &D_800D89B4;
                ptr2 = &D_800D89B4;
                break;
            case 0x2D:
                ptr2 = &D_800D82D0;
                ptr3 = &D_800D8630;
                break;
            case 0x2E:
                ptr3 = &D_800D8A68;
                ptr2 = &D_800D8A68;
                break;
            case 0x2F:
                ptr3 = &D_800D8A8C;
                ptr2 = &D_800D8A8C;
                break;
            case 0x30:
                ptr3 = &D_800D8AB0;
                ptr2 = &D_800D8AB0;
                break;
            case 0x31:
                ptr3 = &D_800D8AD4;
                ptr2 = &D_800D8AD4;
                break;
            case 0x32:
                ptr3 = &D_800D8AF8;
                ptr2 = &D_800D8AF8;
                break;
            case 0x33:
                ptr3 = &D_800D8B1C;
                ptr2 = &D_800D8B1C;
                break;
            case 0x34:
                ptr3 = &D_800D8B40;
                ptr2 = &D_800D8B40;
                break;
            case 0x35:
                ptr3 = &D_800D8B64;
                ptr2 = &D_800D8B64;
                break;
            case 0x36:
                ptr3 = &D_800D8B88;
                ptr2 = &D_800D8B88;
                break;
            case 0x37:
                ptr3 = &D_800D8BAC;
                ptr2 = &D_800D8BAC;
                break;
            case 0x38:
                ptr3 = &D_800D8BD0;
                ptr2 = &D_800D8BD0;
                break;
            case 0x39:
                ptr3 = &D_800D8BF4;
                ptr2 = &D_800D8BF4;
                break;
            case 0x3A:
                ptr3 = &D_800D8C18;
                ptr2 = &D_800D8C18;
                break;
            case 0x3B:
                ptr3 = &D_800D8C3C;
                ptr2 = &D_800D8C3C;
                break;
            case 0x3D:
                ptr3 = &D_800D8C60;
                ptr2 = &D_800D8C60;
                break;
            case 0x3E:
                ptr3 = &D_800D8C84;
                ptr2 = &D_800D8C84;
                break;
            case 0x3F:
                ptr3 = &D_800D8CA8;
                ptr2 = &D_800D8CA8;
                break;
            case 0x40:
                ptr3 = &D_800D8CCC;
                ptr2 = &D_800D8CCC;
                break;
            case 0x41:
                ptr3 = &D_800D8D14;
                ptr2 = &D_800D8D14;
                break;
            case 0x42:
                ptr3 = &D_800D8D38;
                ptr2 = &D_800D8D38;
                break;
            case 0x43:
                ptr3 = &D_800D8D5C;
                ptr2 = &D_800D8D5C;
                break;
            case 0x44:
                ptr3 = &D_800D8D80;
                ptr2 = &D_800D8D80;
                break;
            case 0x45:
                ptr3 = &D_800D8DA4;
                ptr2 = &D_800D8DA4;
                break;
            case 0x46:
                ptr3 = &D_800D8DC8;
                ptr2 = &D_800D8DC8;
                break;
            case 0x47:
                ptr3 = &D_800D8DEC;
                ptr2 = &D_800D8DEC;
                break;
            case 0x48:
                ptr3 = &D_800D8E10;
                ptr2 = &D_800D8E10;
                break;
            case 0x49:
                ptr3 = &D_800D8E34;
                ptr2 = &D_800D8E34;
                break;
            case 0x4A:
                ptr3 = &D_800D8E58;
                ptr2 = &D_800D8E58;
                break;
            case 0x4B:
                ptr3 = &D_800D8CF0;
                ptr2 = &D_800D8CF0;
                break;
            case 0x4C:
                ptr3 = &D_800D8E7C;
                ptr2 = &D_800D8E7C;
                break;
            case 0x4D:
                ptr3 = &D_800D8EA0;
                ptr2 = &D_800D8EA0;
                break;
            case 0x4E:
                ptr3 = &D_800D8EC4;
                ptr2 = &D_800D8EC4;
                break;
            case 0x50:
                ptr3 = &D_800D8F30;
                ptr2 = &D_800D8F30;
                break;
            case 0x51:
                ptr3 = &D_800D8F0C;
                ptr2 = &D_800D8F0C;
                break;
            case 0x52:
                ptr3 = &D_800D8EE8;
                ptr2 = &D_800D8EE8;
                break;
            case 0x53:
                ptr3 = &D_800D8F54;
                ptr2 = &D_800D8F54;
                break;
            case 0x54:
                ptr3 = &D_800D8F78;
                ptr2 = &D_800D8F78;
                break;
            case 0x55:
                ptr3 = &D_800D8F9C;
                ptr2 = &D_800D8F9C;
                break;
            case 0x57:
                ptr3 = &D_800D8FC0;
                ptr2 = &D_800D8FC0;
                break;
            case 0x58:
                ptr3 = &D_800D8FE4;
                ptr2 = &D_800D8FE4;
                break;
            case 0x59:
                ptr3 = &D_800D9008;
                ptr2 = &D_800D9008;
                break;
            case 0x5A:
                ptr3 = &D_800D902C;
                ptr2 = &D_800D902C;
                break;
            case 0x5E:
                ptr3 = &D_800D914C;
                ptr2 = &D_800D914C;
                break;
            case 0x5F:
                ptr3 = &D_800D9170;
                ptr2 = &D_800D9170;
                break;
            case 0x5B:
                ptr3 = &D_800D90E0;
                ptr2 = &D_800D90E0;
                break;
            case 0x5C:
                ptr3 = &D_800D9104;
                ptr2 = &D_800D9104;
                break;
            case 0x5D:
                ptr3 = &D_800D9128;
                ptr2 = &D_800D9128;
                break;
            case 0x60:
                ptr3 = &D_800D9194;
                ptr2 = &D_800D9194;
                break;
            case 0x61:
                ptr3 = &D_800D91B8;
                ptr2 = &D_800D91B8;
                break;
            case 0x63:
                ptr3 = &D_800D91DC;
                ptr2 = &D_800D91DC;
                break;
            case 0x64:
                ptr3 = &D_800D9200;
                ptr2 = &D_800D9200;
                break;
            case 0x65:
                ptr3 = &D_800D9224;
                ptr2 = &D_800D9224;
                break;
            case 0x66:
                ptr3 = &D_800D9248;
                ptr2 = &D_800D9248;
                break;
            case 0x67:
                ptr3 = &D_800D926C;
                ptr2 = &D_800D926C;
                break;
            case 0x68:
                ptr3 = &D_800D9290;
                ptr2 = &D_800D9290;
                break;
            case 0x69:
                ptr3 = &D_800D92B4;
                ptr2 = &D_800D92B4;
                break;
            case 0x6A:
                ptr3 = &D_800D92D8;
                ptr2 = &D_800D92D8;
                break;
            case 0x6B:
                ptr3 = &D_800D92FC;
                ptr2 = &D_800D92FC;
                break;
            case 0x6C:
                ptr3 = &D_800D9320;
                ptr2 = &D_800D9320;
                break;
            case 0x7F:
                ptr3 = &D_800D9368;
                ptr2 = &D_800D9368;
                break;
            case 0x80:
                ptr3 = &D_800D938C;
                ptr2 = &D_800D938C;
                break;
            case 0x6D:
                ptr3 = &D_800D93B0;
                ptr2 = &D_800D93B0;
                break;
            case 0x6E:
                ptr3 = &D_800D93D4;
                ptr2 = &D_800D93D4;
                break;
            case 0x6F:
                ptr3 = &D_800D93F8;
                ptr2 = &D_800D93F8;
                break;
            case 0x70:
                ptr3 = &D_800D941C;
                ptr2 = &D_800D941C;
                break;
            case 0x71:
                ptr3 = &D_800D9440;
                ptr2 = &D_800D9440;
                break;
            case 0x72:
                ptr3 = &D_800D9464;
                ptr2 = &D_800D9464;
                break;
            case 0x73:
                ptr3 = &D_800D9488;
                ptr2 = &D_800D9488;
                break;
            case 0x74:
                ptr3 = &D_800D94AC;
                ptr2 = &D_800D94AC;
                break;
            case 0x75:
                ptr3 = &D_800D94D0;
                ptr2 = &D_800D94D0;
                break;
            case 0x76:
                ptr3 = &D_800D94F4;
                ptr2 = &D_800D94F4;
                break;
            case 0x77:
                ptr3 = &D_800D9518;
                ptr2 = &D_800D9518;
                break;
            case 0x78:
                ptr3 = &D_800D953C;
                ptr2 = &D_800D953C;
                break;
            case 0x79:
                ptr3 = &D_800D9560;
                ptr2 = &D_800D9560;
                break;
            case 0x7A:
                ptr3 = &D_800D9584;
                ptr2 = &D_800D9584;
                break;
            case 0x7B:
                ptr3 = &D_800D95A8;
                ptr2 = &D_800D95A8;
                break;
            case 0x7C:
                ptr3 = &D_800D95CC;
                ptr2 = &D_800D95CC;
                break;
            case 0x7D:
                ptr3 = &D_800D95F0;
                ptr2 = &D_800D95F0;
                break;
            case 0x7E:
                ptr3 = &D_800D9614;
                ptr2 = &D_800D9614;
                break;
            case 0x81:
                ptr3 = &D_800D9638;
                ptr2 = &D_800D9638;
                break;
            case 0x82:
                ptr3 = &D_800D965C;
                ptr2 = &D_800D965C;
                break;
            case 0x83:
                ptr3 = &D_800D9680;
                ptr2 = &D_800D9680;
                break;
            case 0x84:
                ptr3 = &D_800D96A4;
                ptr2 = &D_800D96A4;
                break;
            case 0x85:
                ptr3 = &D_800D96C8;
                ptr2 = &D_800D96C8;
                break;
            case 0x86:
                ptr3 = &D_800D96EC;
                ptr2 = &D_800D96EC;
                break;
            case 0x87:
                ptr3 = &D_800D9710;
                ptr2 = &D_800D9710;
                break;
            case 0x1:
                ptr3 = &D_800D821C;
                ptr2 = &D_800D821C;
                break;
            case 0x89:
                ptr3 = &D_800D9734;
                ptr2 = &D_800D9734;
                break;
            case 0x8A:
                ptr3 = &D_800D9758;
                ptr2 = &D_800D9758;
                break;
            case 0x8B:
                ptr3 = &D_800D977C;
                ptr2 = &D_800D977C;
                break;
            case 0x8C:
                ptr3 = &D_800D97A0;
                ptr2 = &D_800D97A0;
                break;
            case 0x8D:
                ptr3 = &D_800D97C4;
                ptr2 = &D_800D97C4;
                break;
            case 0x8E:
                ptr3 = &D_800D97E8;
                ptr2 = &D_800D97E8;
                break;
            case 0x8F:
                ptr3 = &D_800D9854;
                ptr2 = &D_800D9854;
                break;
            case 0x90:
                ptr3 = &D_800D9878;
                ptr2 = &D_800D9878;
                break;
            case 0x91:
                ptr2 = &D_800D821C;
                ptr3 = &D_800D8288;
                break;
            case 0x92:
                ptr2 = &D_800D93F8;
                ptr3 = &D_800D938C;
                break;
            case 0x93:
                ptr2 = &D_800D93F8;
                ptr3 = &D_800D82D0;
                break;
            case 0x94:
                ptr3 = &D_800D989C;
                ptr2 = &D_800D989C;
                break;
            case 0x95:
                ptr3 = &D_800D98C0;
                ptr2 = &D_800D98C0;
                break;
            case 0x96:
                ptr3 = &D_800D98E4;
                ptr2 = &D_800D98E4;
                break;
            case 0x97:
                ptr3 = &D_800D9908;
                ptr2 = &D_800D9908;
                break;
            case 0x98:
                ptr3 = &D_800D992C;
                ptr2 = &D_800D992C;
                break;
            case 0x99:
                ptr3 = &D_800D9950;
                ptr2 = &D_800D9950;
                break;
            case 0x9A:
                ptr3 = &D_800D9974;
                ptr2 = &D_800D9974;
                break;
            case 0x9B:
                ptr3 = &D_800D9A04;
                ptr2 = &D_800D9A04;
                break;
            case 0x9C:
                ptr3 = &D_800D9A28;
                ptr2 = &D_800D9A28;
                break;
            case 0x9D:
                ptr3 = &D_800D9A4C;
                ptr2 = &D_800D9A4C;
                break;
            case 0x9E:
                ptr3 = &D_800D9A70;
                ptr2 = &D_800D9A70;
                break;
            case 0x9F:
                ptr3 = &D_800D9A94;
                ptr2 = &D_800D9A94;
                break;
            case 0xA0:
                ptr3 = &D_800D81D4;
                ptr2 = &D_800D81D4;
                break;
            case 0xA1:
                ptr3 = &D_800D9AB8;
                ptr2 = &D_800D9AB8;
                break;
            case 0xA2:
                ptr3 = &D_800D9ADC;
                ptr2 = &D_800D9ADC;
                break;
            case 0xA3:
                ptr3 = &D_800D9B00;
                ptr2 = &D_800D9B00;
                break;
            case 0xA4:
                ptr3 = &D_800D9B24;
                ptr2 = &D_800D9B24;
                break;
            case 0xA5:
                ptr3 = &D_800D9B48;
                ptr2 = &D_800D9B48;
                break;
            case 0xA6:
                ptr3 = &D_800D9B6C;
                ptr2 = &D_800D9B6C;
                break;
            }
            func_80017180(ptr, ptr2, 10);
            func_80017090(ptr, ptr3, 10);
        }
    }
    else if (gActor[gActorSpriteMap[spritenum]].unk8 <= 0)
    {
        if (gPlayer[i].unk45 == 1)
        {
            gPlayer[i].unk45 = 2;
            if ((gPlayer[i].unk54 != 0) || (gPlayer[i].unk56 != 0))
                ptr4 = &D_800D8E58;
            else
            {
                switch (gActor[gActorSpriteMap[gPlayer[i].unk4A]].unk9E)
                {
                case 0xFD:
                    ptr4 = &D_800D8E34;
                    break;
                case 0xFE:
                    ptr4 = &D_800D980C;
                    break;
                case 0x9:
                    ptr4 = &D_800D8D14;
                    break;
                case 0xFF:
                    ptr4 = &D_800D8168;
                    break;
                default:
                    switch (random(7))
                    {
                    case 0:
                    default:
                        ptr4 = &D_800D8168;
                        break;
                    case 1:
                        ptr4 = &D_800D8A44;
                        break;
                    case 2:
                        ptr4 = &D_800D8990;
                        break;
                    case 3:
                        ptr4 = &D_800D8A68;
                        break;
                    case 4:
                        ptr4 = &D_800D8B88;
                        break;
                    case 5:
                        ptr4 = &D_800D8C3C;
                        break;
                    case 6:
                        ptr4 = &D_800D8BAC;
                        break;
                    }
                    break;
                }
            }
            func_800171D0(ptr, ptr4, 10);
        }
        else if ((gPlayer[i].unk54 != 0) || ((gPlayer[i].unk56 != 0)))
        {
            if (ptr->unk8 != &D_800D8E58)
                func_800171D0(ptr, &D_800D8E58, 10);
        }
    }
    else
    {
        if (gPlayer[i].unk59 == 0)
            D_80119A30[i] &= ~0xC;

        if ((j == 0) || (j == 13) || (j == 12) || (j == 14) || (j == 10) || (j == 11))
        {
            if (gPlayer[i].unk54 != 0)
            {
                ptr5 = &D_800D8144;
                ptr6 = &D_800D8144;
                ptr7 = &D_800D8144;
            }
            else
            {
                ptr7 = &D_800D82D0;
                if (D_80119A30[i] & 1)
                    ptr6 = &D_800D821C;

                if (D_80119A30[i] & 2)
                    ptr6 = &D_800D82AC;

                if (D_80119A30[i] & 4)
                    ptr6 = &D_800D8360;

                if (D_80119A30[i] & 8)
                    ptr6 = &D_800D833C;

                if (j == 0)
                    ptr5 = &D_800D8C18;
                else if (j == 11)
                    ptr5 = &D_800D8CCC;
                else if (j == 14)
                    ptr5 = &D_800D9344;
                else
                    ptr5 = &D_800D8534;
            }

            if (gPlayer[i].unk56 != 0)
            {
                ptr6 = &D_800D99BC;
                ptr7 = &D_800D85C4;
            }
        }
        else
        {
            if ((j == 2) || (j == 3) || (j == 6))
            {
                if (gPlayer[i].unk54 != 0)
                {
                    ptr5 = &D_800D87BC;
                    ptr6 = &D_800D87BC;
                    ptr7 = ptr5;
                }
                else
                {
                    if (gPlayer[i].unk56 != 0)
                        D_80119A30[i] = 0;

                    if (cond1)
                    {
                        if (D_80119A30[i] & 1)
                        {
                            ptr5 = &D_800D81B0;
                            m = 2;
                        }
                        else
                            ptr5 = &D_800D9830;
                    }
                    else
                    {
                        if (D_80119A30[i] != 0)
                        {
                            ptr5 = &D_800D89D8;
                            if (D_80119A30[i] & 3)
                                m = 2;
                        }
                        else
                        {
                            switch (j)
                            {
                            case 2:
                                ptr5 = &D_800D818C;
                                break;
                            case 3:
                                ptr5 = &D_800D869C;
                                break;
                            case 4:
                            default:
                                ptr5 = &D_800D8678;
                                break;
                            }
                        }
                    }

                    if (D_80119A30[i] & 1)
                    {
                        if (cond1)
                            ptr6 = &D_800D8264;
                        else
                            ptr6 = &D_800D8240;
                    }

                    if (D_80119A30[i] & 2)
                        ptr6 = &D_800D82AC;

                    if (D_80119A30[i] & 4)
                    {
                        ptr5 = &D_800D83F0;
                        ptr6 = &D_800D83F0;
                        if (cond1)
                        {
                            ptr5 = &D_800D83A8;
                            ptr6 = &D_800D83A8;
                        }
                    }
                    if (D_80119A30[i] & 8)
                    {
                        ptr5 = &D_800D83CC;
                        ptr6 = &D_800D83CC;
                        if (cond1)
                        {
                            ptr5 = &D_800D8384;
                            ptr6 = &D_800D8384;
                        }
                    }
                    if (D_8016A154[i] != 0)
                    {
                        if (cond1)
                        {
                            if (j == 3)
                                ptr5 = &D_800D938C;
                            else
                                ptr5 = &D_800D9320;
                        }
                        else
                        {
                            if (j == 3)
                                ptr5 = &D_800D9368;
                            else
                                ptr5 = &D_800D92FC;
                        }
                        D_800FE9D8[i] = 1;
                    }
                    if (cond1)
                        ptr7 = &D_800D8318;
                    else
                        ptr7 = &D_800D82F4;
                }
            }
            else
            {
                if (gPlayer[i].unk54 != 0)
                {
                    ptr5 = &D_800D8414;
                    ptr6 = &D_800D8414;
                    ptr7 = ptr5;
                }
                else
                {
                    if (gPlayer[i].unk56 != 0)
                        D_80119A30[i] = 0;

                    ptr5 = &D_800D81D4;
                    if (D_80119A30[i] & 1)
                    {
                        ptr5 = &D_800D89FC;
                        ptr6 = &D_800D89FC;
                    }

                    if (D_80119A30[i] & 2)
                    {
                        ptr6 = &D_800D82AC;
                        ptr5 = &D_800D89FC;
                    }

                    if (D_80119A30[i] & 4)
                    {
                        ptr5 = &D_800D83F0;
                        ptr6 = &D_800D83F0;
                    }
                    if (D_80119A30[i] & 8)
                    {
                        ptr5 = &D_800D83CC;
                        ptr6 = &D_800D83CC;
                    }

                    if (j == 4)
                    {
                        if (!(D_8011A680[i][4][0] & 4))
                        {
                            ptr5 = &D_800D84C8;
                            if (D_80119A30[i] & 4)
                                ptr5 = &D_800D9074;

                            if (D_80119A30[i] & 8)
                                ptr5 = &D_800D9050;

                            if (ptr->unk4 == &D_800D84C8)
                                m = 1;
                            else if (ptr->unk4 == &D_800D9074)
                                m = 1;
                            else if (ptr->unk4 == &D_800D9050)
                                m = 1;
                        }
                    }
                    else if (j == 7)
                    {
                        if (D_80119A30[i] & 4)
                            ptr5 = &D_800D90BC;
                        else
                            ptr5 = &D_800D8630;

                        if (D_80119A30[i] & 8)
                            ptr5 = &D_800D9098;

                        if (ptr->unk4 == &D_800D8630)
                            m = 1;
                        else if (ptr->unk4 == &D_800D90BC)
                            m = 1;
                        else if (ptr->unk4 == &D_800D9098)
                            m = 1;
                    }
                    else if (D_80119A30[i] & 3)
                        m = 2;

                    ptr7 = &D_800D81D4;
                }
            }

            if (gPlayer[i].unk56 != 0)
            {
                ptr6 = &D_800D99E0;
                ptr7 = &D_800D87E0;
            }
        }

        if (gPlayer[i].unk5B == 0)
        {
            if (gPlayer[i].unk56 == 0)
            {
                if ((ptr->unk8 == &D_800D860C) || (ptr->unk8 == &D_800D8558) || (ptr->unk8 == &D_800D81F8))
                {
                    ptr6 = ptr7 = ptr->unk8;
                }
                else if ((gPlayer[i].unk59 == 0) && (gPlayer[i].zvect > 0xA00))
                {
                    ptr7 = &D_800D860C;
                    ptr6 = &D_800D860C;
                }
                if (ptr->unk8 == &D_800D857C)
                {
                    if ((ptr->unk2 < (D_800D857C.unk14 - 5)))
                    {
                        ptr7 = &D_800D857C;
                        ptr6 = &D_800D857C;

                        if ((gPlayerCount == 1))
                        {
                            gPlayer[i].yvect = 0;
                            gPlayer[i].xvect = 0;
                        }
                    }
                }
            }
        }
        else if (gPlayer[i].unk54 == 0)
        {
            ptr7 = &D_800D95F0;
            ptr6 = &D_800D95F0;
        }

        if (gPlayer[i].unk58 != 0)
        {
            ptr7 = &D_800D84A4;
            ptr6 = &D_800D84A4;
        }
        if (gPlayer[i].unk5A != 0)
        {
            ptr7 = &D_800D8E10;
            ptr6 = &D_800D8E10;
        }
        if (D_801A6AD4[i] != 0)
        {
            ptr6 = &D_800D8558;
            ptr7 = &D_800D81F8;
        }
        if (gPlayer[i].unk84 > 0)
        {
            ptr7 = &D_800D8C84;
            ptr6 = &D_800D8C84;
        }
        if (D_800DEEB8 == 1)
        {
            ptr7 = &D_800D9A04;
            ptr6 = &D_800D9A04;
            gActor[gActorSpriteMap[spritenum]].unk99 = 0;
        }
        if (D_800DEEB8 == 2)
        {
            ptr7 = &D_800D9A28;
            ptr6 = &D_800D9A28;
        }
        if (gPlayer[i].unk50 >= 0)
        {
            ptr7 = &D_800D8E10;
            ptr6 = &D_800D8E10;
        }
        if (D_800DEEBC != -1)
        {
            ptr7 = &D_800D9710;
            ptr6 = &D_800D9710;

            gActor[gActorSpriteMap[spritenum]].unk99 = 5;
            if (D_8012FD88 >= (D_800DEEBC + 705))
            {
                ptr7 = &D_800D9974;
                ptr6 = &D_800D9974;
            }

            if (D_8012FD88 >= (D_800DEEBC + 725))
            {
                if (D_8012FD88 == (D_800DEEBC + 725))
                {
                    func_8005EC88(0, 0);
                    D_801A1958.enemies_killed++;
                    gpSprite[spritenum].ang = (gpSprite[spritenum].ang + 0x400) & 0x7FF;
                    func_8006D3B8(spritenum, 5, 0, 0, 0);
                    audio_800077F4(786, spritenum);
                    gpSprite[spritenum].ang = (gpSprite[spritenum].ang + 0x400) & 0x7FF;
                }
                ptr7 = &D_800D9ADC;
                ptr6 = &D_800D9ADC;
            }
        }

        if (gPlayer[i].unk4E >= 450)
        {
            if ((gPlayer[i].unk54 == 0) && (gPlayer[i].unk56 == 0) && (gPlayer[i].unk58 == 0))
            {
                if (gPlayer[i].unk4E == 450)
                    func_800171D0(ptr, &D_800D8804, 10);

                if (ptr->unk8 == &D_800D896C)
                {
                    if (ptr->unk2 == 10)
                        playSfx(1434);
                    if (ptr->unk2 >= (ptr->unk8->unk14 - 10))
                        func_800171D0(ptr, &D_800D8804, 10);
                }
                else
                {
                    if (!(D_8012FD88 & 0x3F))
                    {
                        r = krand() & 0x7FF;
                        if (r < 0x40)
                            func_800171D0(ptr, &D_800D896C, 10);
                        else if (r < 0x240)
                            func_800171D0(ptr, &D_800D8804, 10);
                        else if (r < 0x340)
                            func_800171D0(ptr, ptr7, 10);
                    }
                }
            }
        }
        else if (D_80119A30[i] != 0)
        {
            if (ptr->unk8 != ptr6)
                func_80017180(ptr, ptr6, 10);

            if (D_800FE9D8[i] == 0)
            {
                if (ptr->unk4 != ptr6)
                    func_800170E0(ptr, ptr6, 10);
            }
        }
        else
        {
            if (ptr->unk8 != ptr7)
                func_80017180(ptr, ptr7, 10);

            if (D_800FE9D8[i] == 0)
            {
                if (ptr->unk4 != ptr7)
                    func_800170E0(ptr, ptr7, 10);
            }
        }

        if (gPlayer[i].unk58 != 0)
        {
            if (D_80119A30[i] == 0)
                return;
        }
        else
        {
            cond2 = (ptr->unk2 >= (ptr->unk8->unk14 - 1));
            if ((((gPlayer[i].unk59 != 0) && (D_8012F914[i] == -1)) ||
                (cond2 != 0)) && ((ptr->unk8 == &D_800D8558) || (ptr->unk8 == &D_800D81F8)))
            {
                if ((gPlayer[i].unk59 != 0) && (D_8012F914[i] == -1))
                {
                    if (D_800FE9D8[i] == 0)
                        func_80017090(ptr, &D_800D857C, 10);

                    func_80017180(ptr, &D_800D857C, 10);
                    if (gPlayerCount == 1)
                    {
                        gPlayer[i].yvect = 0;
                        gPlayer[i].xvect = 0;
                    }
                }
                else
                    func_80017180(ptr, &D_800D860C, 10);
            }
            else
            {
                if ((gPlayer[i].unk59 != 0) && (ptr->unk8 == &D_800D860C))
                {
                    if (D_800FE9D8[i] == 0)
                        func_80017090(ptr, &D_800D857C, 10);

                    func_80017180(ptr, &D_800D857C, 10);
                    if (gPlayerCount == 1)
                    {
                        gPlayer[i].yvect = 0;
                        gPlayer[i].xvect = 0;
                    }
                }
                else if ((cond2 != 0) && (ptr->unk8 == &D_800D857C))
                {
                    if (D_80119A30[i] != 0)
                    {
                        if (D_800FE9D8[i] == 0)
                            func_80017090(ptr, ptr6, 10);

                        func_80017180(ptr, ptr6, 10);
                    }
                    else
                    {
                        if (D_800FE9D8[i] == 0)
                            func_80017090(ptr, ptr7, 10);

                        func_80017180(ptr, ptr7, 10);
                    }
                }
            }

            if (ptr5 != NULL)
            {
                if (D_800FE9D8[i] != 0)
                {
                    if (ptr->unk4 != ptr5)
                    {
                        switch (m)
                        {
                        case 1:
                            func_80017134(ptr, ptr5, 10);
                            break;
                        case 2:
                            func_800170E0(ptr, ptr5, 10);
                            break;
                        case 0:
                            func_80017090(ptr, ptr5, 10);
                            break;
                        }
                    }
                }
                if (D_800FE9D8[i] == 0)
                {
                    if (ptr->unk4 == ptr5)
                    {
                        if (ptr->unk8 != ptr5)
                            func_800170E0(ptr, ptr->unk8, 10);
                    }
                }
            }
        }
    }

    cond3 = 0;
    cond4 = 0;
    if ((i >= 0) && (gPlayer[i].unk58 != 0) && (D_80119A30[i] == 2))
    {
        cond4 = 1;
        cond3 = 1;
    }

    if (ptr->unk8 == &D_800D82AC)
        cond3 = 1;

    if (ptr->unk4 == &D_800D82AC)
        cond4 = 1;

    if (!(ptr->unk8->unk20 & 1) || (ptr->unk2 < (ptr->unk8->unk14 - 1)))
    {
        if (cond3 == 0)
        {
            ptr->unk2++;
            if (ptr->unk2 >= ptr->unk8->unk14)
                ptr->unk2 = 0;
        }
        else
        {
            ptr->unk2--;
            if (ptr->unk2 < 0)
                ptr->unk2 = ptr->unk8->unk14 - 1;
        }
    }

    if (!(ptr->unk4->unk20 & 1) || (ptr->unk0 < (ptr->unk4->unk14 - 1)))
    {
        if (cond4 == 0)
        {
            ptr->unk0++;
            if (ptr->unk0 >= ptr->unk4->unk14)
                ptr->unk0 = 0;
        }
        else
        {
            ptr->unk0--;
            if (ptr->unk0 < 0)
                ptr->unk0 = ptr->unk4->unk14 - 1;
        }
    }

    if ((ptr->unk16 != -1) && (((ptr->unk1C->unk20 & 1) == 0) || (ptr->unk16 < (ptr->unk1C->unk14 - 1))))
    {
        ptr->unk16++;
        if (ptr->unk16 >= ptr->unk1C->unk14)
            ptr->unk16 = 0;
    }

    if ((ptr->unk14 != -1) && (((ptr->unk18->unk20 & 1) == 0) || (ptr->unk14 < (ptr->unk18->unk14 - 1))))
    {
        ptr->unk14++;
        if (ptr->unk14 >= ptr->unk18->unk14)
            ptr->unk14 = 0;
    }
}

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
