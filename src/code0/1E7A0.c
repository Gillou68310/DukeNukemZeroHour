#include "common.h"
#include "code0/audio.h"
#include "code0/engine.h"
#include "code0/code0.h"
#include "code1/code1.h"

typedef struct
{
    /*0x00*/ u8 unk0;
    /*0x01*/ u8 unk1;
} _1E7A0UnkStruct1;

typedef struct
{
    /*0x00*/ s16 unk0;
    /*0x04*/ f32 unk4;
    /*0x08*/ f32 unk8;
    /*0x0C*/ s16 unkC;
    /*0x0E*/ u8 unkE;
    /*0x0F*/ u8 unkF;
} _1E7A0UnkStruct2;

/*.data*/
/*800DCA30*/ EXTERN_DATA STATIC _1E7A0UnkStruct1 D_800DCA30[8];
/*800DCA40*/ EXTERN_DATA STATIC _1E7A0UnkStruct2 D_800DCA40[13];

/*.text*/

void func_8001DBA0(s16 x, s16 y, s16 z, u8 arg3, u8 arg4, s32 arg5)
{
    code0UnkStruct13 *ptr;
    s16 i;

    if ((krand() & 0x7FFF) >= 9000)
    {
        for (i = 0, ptr = D_801AE538; i < CODE0_MAXUNK2; i++, ptr++)
        {
            if (ptr->unk0 == 0)
            {
                ptr->unk0 = 1;
                ptr->unk1 = arg5;
                ptr->unk2 = x;
                ptr->unk4 = y;
                ptr->unk6 = z;
                ptr->unk10 = D_800DCA40[arg5].unk0;
                ptr->unk14 = D_800DCA40[arg5].unk4;
                ptr->unkA = krand();
                ptr->unk18 = arg3;
                ptr->unk19 = arg4;
                ptr->unk8 = krand() % 4 + 5542;
                break;
            }
        }
    }
}

/*8001DCD0*/
void func_8001DCD0(s16 x, s16 y, s16 z, s16 arg3)
{
    func_8001DBA0(x, y, z, D_800DCA30[arg3].unk0, D_800DCA30[arg3].unk1, 9);
}

/*8001DD30*/
void func_8001DD30(s16 x, s16 y, s16 z)
{
    func_8001DBA0(x, y, z, 11, 11, 1);
}

/*8001DD78*/
void func_8001DD78(s32 x, s32 y, s32 z)
{
    code0UnkStruct14 *ptr;
    s16 i;

    for (ptr = D_8012DF10, i = 0; i < CODE0_MAXUNK3; i++, ptr++)
    {
        if (ptr->unk0 == 0)
        {
            ptr->unk0 = 1;
            ptr->unk4 = x;
            ptr->unk8 = y;
            ptr->unkC = z;
            ptr->unk10 = (krand() & 0x7F) - 64;
            ptr->unk14 = (krand() & 0x7F) - 64;
            ptr->unk18 = (krand() & 0x7F) - 64;
            ptr->unk1E = 100;
            ptr->unk20 = krand() & 0x7FF;
            ptr->unk22 = (krand() & 0xF) - 7;
            krand();
            ptr->unk1C = 5949;
            ptr->unk1F = 0;
            break;
        }
    }
}

/*8001DE5C*/
void func_8001DE5C(void)
{
    s32 i;

    for (i = 0; i < CODE0_MAXUNK2; i++)
        D_801AE538[i].unk0 = 0;
    for (i = 0; i < CODE0_MAXUNK3; i++)
        D_8012DF10[i].unk0 = 0;
}

INCLUDE_ASM("nonmatchings/src/code0/1E7A0", func_8001DE9C);

INCLUDE_ASM("nonmatchings/src/code0/1E7A0", func_8001EB2C);

/*8001F388*/
void func_8001F388(void)
{
    code0UnkStruct14 *ptr;
    s16 i;

    for (ptr = D_8012DF10, i = 0; i < CODE0_MAXUNK3; i++, ptr++)
    {
        if (ptr->unk0 != 0)
        {
            ptr->unk4 += ptr->unk10;
            ptr->unk8 += ptr->unk14;
            ptr->unkC += ptr->unk18;
            ptr->unk20 += ptr->unk22;
            ptr->unk20 &= 0x7FF;

            if (ptr->unk1E < 119)
                ptr->unk1E += 8;
            else
                ptr->unk1E = 127;

            ptr->unk1F++;
            if (ptr->unk1F == 0xF)
                ptr->unk0 = 0;
        }
    }
}

/*8001F44C*/
void func_8001F44C(void)
{
    s16 i, j, k, num, ang;
    f32 f1, f2;

    if (D_801CE5AC == 2)
        k = 2;
    else
        k = 1;

    for (i = 0; i < CODE0_MAXUNK2; i++)
    {
        for (j = 0; j < k; j++)
        {
            if (D_801AE538[i].unk0 != 0)
            {
                D_801AE538[i].unk10 += D_801AE538[i].unk14;
                D_801AE538[i].unk14 -= D_800DCA40[D_801AE538[i].unk1].unk8;

                if (D_800DCA40[D_801AE538[i].unk1].unkF != 0)
                    D_801AE538[i].unk6 -= (D_801AE538[i].unk14 * (D_800DCA40[D_801AE538[i].unk1].unkC / 6));

                if (D_801AE538[i].unk14 <= 0.0f)
                    D_801AE538[i].unk0 = 0;

                num = audio_80007510(D_801AE538[i].unk2 * 2, D_801AE538[i].unk4 * 2);
                if (D_8013871C >= 0x101)
                {
                    ang = getAngle(D_80117ED8[num].xpos - (D_801AE538[i].unk2 * 2), D_80117ED8[num].ypos - (D_801AE538[i].unk4 * 2));
                    f1 = D_801AE538[i].unk2;
                    D_801AE538[i].unk2 = f1 + (cosf(ang * 0.00306796157577148444) * 8.0f);
                    f2 = D_801AE538[i].unk4;
                    D_801AE538[i].unk4 = f2 + (sinf(ang * 0.00306796157577148444) * 8.0f);
                }
            }
        }
    }
}

INCLUDE_ASM("nonmatchings/src/code0/1E7A0", func_8001F7B4);
