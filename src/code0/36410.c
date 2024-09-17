#include "common.h"
#include "code0/audio.h"
#include "code0/data/DE050.h"
#include "code0/code0.h"

typedef struct {
    u16 sfxnum;
    u16 unk2;
} _36410UnkStruct1;

/*.comm*/
/*8011BC54*/ Actor *_pActor1;

/*.text*/

/*80035810*/
void func_80035810(s32 spritenum, s32 arg1)
{
    u16 *ptr;
    s32 i, j, unk84;

    _pActor1 = &gActor[gActorSpriteMap[spritenum]];
    unk84 = _pActor1->unk84;
    if (unk84 != -1)
    {
        if ((intptr_t)D_800DD450[unk84] != -1)
        {
            ptr = D_800DD450[unk84][0];
            i = ptr[1];
            j = ptr[0];
            i = (krand() % i);
            if ((krand() % 11) < j)
                audio_80007A44(((_36410UnkStruct1 *)&ptr[2])[i].sfxnum, spritenum, ((_36410UnkStruct1 *)&ptr[2])[i].unk2);
        }
    }
}

/*80035954*/
void func_80035954(s32 spritenum, s32 arg1)
{
    u16 *ptr;
    s32 i, j, unk84;

    _pActor1 = &gActor[gActorSpriteMap[spritenum]];
    unk84 = _pActor1->unk84;
    if (unk84 != -1)
    {
        if ((intptr_t)D_800DD450[unk84] != -1)
        {
            ptr = D_800DD450[unk84][2];
            i = ptr[1];
            j = ptr[0];
            i = (krand() % i);
            if ((krand() % 11) < j)
                audio_80007A44(((_36410UnkStruct1 *)&ptr[2])[i].sfxnum, spritenum, ((_36410UnkStruct1 *)&ptr[2])[i].unk2);
        }
    }
}

/*80035A98*/
void func_80035A98(s32 spritenum, s32 arg1)
{
    u16 *ptr;
    s32 j, unk84;

    _pActor1 = &gActor[gActorSpriteMap[spritenum]];
    unk84 = _pActor1->unk84;
    if (unk84 != -1)
    {
        if ((intptr_t)D_800DD450[unk84] != -1)
        {
            ptr = D_800DD450[unk84][4];
            j = ptr[1];
            j = (krand() % j);
            audio_80007A44(((_36410UnkStruct1 *)&ptr[2])[j].sfxnum, spritenum, ((_36410UnkStruct1 *)&ptr[2])[j].unk2);
        }
    }
}

/*80035B88*/
void func_80035B88(s32 spritenum)
{
    u16 *ptr;
    s32 i, j, unk84;

    _pActor1 = &gActor[gActorSpriteMap[spritenum]];
    unk84 = _pActor1->unk84;
    if (unk84 != -1)
    {
        if ((intptr_t)D_800DD450[unk84] != -1)
        {
            ptr = D_800DD450[unk84][8];
            j = ptr[0];

            if ((krand() % 11) < j)
            {
                i = ptr[1];
                i = krand() % i;
                if (_pActor1->unk9E == 17)
                    audio_80007A44((krand() % 3 + 1369), spritenum, ((_36410UnkStruct1 *)&ptr[2])[i].unk2);
                else if (_pActor1->unk9E == 20)
                    audio_80007A44((krand() % 3 + 1372), spritenum, ((_36410UnkStruct1 *)&ptr[2])[i].unk2);
                else
                    audio_80007A44(((_36410UnkStruct1 *)&ptr[2])[i].sfxnum, spritenum, ((_36410UnkStruct1 *)&ptr[2])[i].unk2);

            }
        }
    }
}

/*80035D90*/
void func_80035D90(s32 spritenum, s32 arg1)
{
    u16 *ptr;
    s32 j, unk84;

    _pActor1 = &gActor[gActorSpriteMap[spritenum]];
    unk84 = _pActor1->unk84;
    if (unk84 != -1)
    {
        if ((intptr_t)D_800DD450[unk84] != -1)
        {
            ptr = D_800DD450[unk84][5];
            j = ptr[1];
            j = (krand() % j);
            audio_80007A44(((_36410UnkStruct1 *)&ptr[2])[j].sfxnum, spritenum, ((_36410UnkStruct1 *)&ptr[2])[j].unk2);
        }
    }
}

/*80035E80*/
void func_80035E80(s32 spritenum, s32 arg1)
{
    u16 *ptr;
    u16 **ptr2;
    s32 j, unk84;

    _pActor1 = &gActor[gActorSpriteMap[spritenum]];
    unk84 = _pActor1->unk84;
    if (unk84 != -1)
    {
        ptr2 = D_800DD450[unk84];
        if ((intptr_t)ptr2 != -1)
        {
            if (MusHandleAsk(_pActor1->unk70) == 0)
                _pActor1->unk70 = 0;

            ptr = ptr2[6];
            j = ptr[1];
            j = (krand() % j);

            if (_pActor1->unk70 == 0)
            {
                _pActor1->unk78 = ((_36410UnkStruct1 *)&ptr[2])[j].unk2;
                _pActor1->unk70 = audio_80007A44(((_36410UnkStruct1 *)&ptr[2])[j].sfxnum, spritenum, _pActor1->unk78);
            }
        }
    }
}

/*80035FB0*/
void func_80035FB0(s32 spritenum, s32 arg1)
{
    u16 *ptr;
    s32 j, unk84;

    _pActor1 = &gActor[gActorSpriteMap[spritenum]];
    unk84 = _pActor1->unk84;
    if (unk84 != -1)
    {
        if ((intptr_t)D_800DD450[unk84] != -1)
        {
            ptr = D_800DD450[unk84][7];
            j = ptr[1];
            j = (krand() % j);
            audio_80007A44(((_36410UnkStruct1 *)&ptr[2])[j].sfxnum, spritenum, ((_36410UnkStruct1 *)&ptr[2])[j].unk2);
        }
    }
}

/*800360A0*/
void func_800360A0(s32 spritenum, s32 arg1)
{
    u16 *ptr;
    u16 **ptr2;
    s32 j, unk84;

    _pActor1 = &gActor[gActorSpriteMap[spritenum]];

    if ((_pActor1->flag & 0x8000) == 0)
        func_80035B88(spritenum);

    unk84 = _pActor1->unk84;
    if (unk84 != -1)
    {
        ptr2 = D_800DD450[unk84];
        if ((intptr_t)ptr2 != -1)
        {
            if (MusHandleAsk(_pActor1->unk6C) == 0)
                _pActor1->unk6C = 0;

            ptr = ptr2[3];
            j = ptr[1];
            j = (krand() % j);

            if (_pActor1->unk6C == 0)
            {
                _pActor1->unk6C = audio_80007A44(((_36410UnkStruct1 *)&ptr[2])[j].sfxnum, spritenum, ((_36410UnkStruct1 *)&ptr[2])[j].unk2);
                _pActor1->unk74 = ((_36410UnkStruct1 *)&ptr[2])[j].unk2;
            }
        }
    }
}

/*800361F4*/
void func_800361F4(s32 spritenum, s32 arg1)
{
    u16 *ptr;
    s32 unk84;

    _pActor1 = &gActor[gActorSpriteMap[spritenum]];
    unk84 = _pActor1->unk84;
    if (unk84 != -1)
    {
        if ((intptr_t)D_800DD450[unk84] != -1)
        {
            ptr = D_800DD450[unk84][9];
            audio_80007A44(((_36410UnkStruct1 *)&ptr[1])[0].sfxnum, spritenum, ((_36410UnkStruct1 *)&ptr[1])[0].unk2);
        }
    }
}

/*80036280*/
void func_80036280(s32 spritenum, s32 arg1)
{
    u16 *ptr;
    u16 **ptr2;
    s32 unk84;
    s32 i, j, k, l;

    _pActor1 = &gActor[gActorSpriteMap[spritenum]];
    if (_pActor1->unk90 == 0)
    {
        unk84 = _pActor1->unk84;
        if (unk84 != -1)
        {
            ptr2 = D_800DD450[unk84];
            if ((intptr_t)ptr2 != -1)
            {
                ptr = ptr2[1];
                i = ptr[0];
                j = ptr[1];
                k = ptr[2];

                l = 0;
                if (j != i)
                {
                    l = krand();
                    l %= (j-i);
                }

                l += i;
                _pActor1->unk90 = l;

                if (MusHandleAsk(_pActor1->unk6C) == 0)
                    _pActor1->unk6C = 0;

                if ((krand() % 11) < k)
                {
                    i = ptr[3];
                    i = (krand() % i);
                    if (_pActor1->unk6C == 0)
                    {
                        _pActor1->unk6C = audio_80007A44(((_36410UnkStruct1 *)&ptr[4])[i].sfxnum, spritenum, ((_36410UnkStruct1 *)&ptr[4])[i].unk2);
                        _pActor1->unk74 = ((_36410UnkStruct1 *)&ptr[4])[i].unk2;
                    }
                }
            }
        }
    }
    else
        _pActor1->unk90--;
}
