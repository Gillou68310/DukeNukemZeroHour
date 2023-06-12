#include "common.h"
#include "code0/41940.h"
#include "code0/code0.h"

typedef struct {
    u8 unk0;
    u16 unk2;
    u8 pad[36];
    s32 unk28;
    s32 unk2C;
} _8EFE0UnkStruct1;

/*.comm*/
/*80106730*/ _8EFE0UnkStruct1 D_80106730[32] ALIGNED(16);
/*80139870*/ s32 D_80139870;

/*.text*/

/*8008E3E0*/
INCLUDE_ASM("nonmatchings/src/code0/8EFE0", func_8008E3E0);

/*8008FE88*/
INCLUDE_ASM("nonmatchings/src/code0/8EFE0", func_8008FE88);

/*80093450*/
static s16 func_80093450(s32 x, s32 y, s32 z, s32 sectnum, s32 *arg4)
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
                    ((s32 *)ptr)[j+1] = (arg4[j] - x);
                    ((s32 *)ptr)[j+4] = (arg4[j+3] - y);
                    ((s32 *)ptr)[j+7] = (arg4[j+6] - z);
                }
                ptr->unk2 = 100;
                gpSprite[spritenum].unk22 = i;
                gpSprite[spritenum].unk18 = ((krand() & 0x7F) * gpSinTable[D_80139870]) >> 14;
                gpSprite[spritenum].unk1A = ((krand() & 0x7F) * gpSinTable[(D_80139870 + 512) & 0x7FF]) >> 14;
                ptr->unk28 = (krand() & 0x3F) - 0x20;
                ptr->unk2C = (krand() & 0x3F) - 0x20;
                gpSprite[spritenum].unk1C = 0;
                gpSprite[spritenum].ang = 0;
                gpSprite[spritenum].cstat = -0x8000;
                D_8013B2D0[spritenum].unk0 = 0;
                return spritenum;
            }
            break;
        }
    }
    return -1;
}

/*80093670*/
INCLUDE_ASM("nonmatchings/src/code0/8EFE0", func_80093670);

/*80093BB0*/
INCLUDE_ASM("nonmatchings/src/code0/8EFE0", func_80093BB0);

/*80094278*/
INCLUDE_ASM("nonmatchings/src/code0/8EFE0", func_80094278);

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
