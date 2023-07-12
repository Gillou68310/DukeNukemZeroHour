#include "common.h"
#include "code0/7F6A0.h"
#include "code0/7FCE0.h"
#include "code0/82480.h"
#include "code0/code0.h"

/*.data*/
/*800DF9A0*/
static ProcPointer D_800DF9A0[12] = {
    NULL,
    NULL,
    func_8008383C,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

/*800DF9D0*/
static ProcPointer D_800DF9D0[16] = {
    NULL,
    func_8007FCC8,
    func_80082448,
    func_8007F0E0,
    func_8008011C,
    func_8008036C,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

/*800DFA10*/
static ProcPointer D_800DFA10[12] = {
    NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL
};

/*.comm*/
/*80138870*/ s16 D_80138870[2048] ALIGNED(16);
/*8016D17C*/ s32 D_8016D17C;
/*80199990*/ s16 D_80199990[2048+2] ALIGNED(16);
/*801A6D90*/ code0UnkStruct16 D_801A6D90[128] ALIGNED(16);

/*.text*/

/*8007EAA0*/
void memset(void *dst, s32 value, s32 size)
{
    s32 i;
    s32 val;
    u8 *ptr;

    ptr = dst;
    val = (value << 24) | (value << 16) | (value << 8) | value;

    if (((intptr_t)dst & 3) || (size & 3))
    {
        for (i = 0; i < size; i++)
            *ptr++ = value;
    }
    else
    {
        for (i = 0; i < (size >> 2); i++)
        {
            *(s32 *)dst = val;
            dst = (void *)(((s32 *)dst) + 1);
        }
    }
}

/*8007EB24*/
void func_8007EB24(void)
{
    memset(D_801A6D90, 0, sizeof(D_801A6D90));
    D_8016D17C = 0;
}

/*8007EB58*/
static void func_8007EB58(void)
{
    s32 i;
    code0UnkStruct16 *ptr;

    ptr = &D_801A6D90[0];
    for (i = 0; i < ARRAY_COUNT(D_801A6D90); i++)
    {
        if (ptr->unk0 != 0)
            func_8007ECC8(ptr);
        ptr++;
    }
}

/*8007EBB0*/
static code0UnkStruct16 *func_8007EBB0(void)
{
    s32 i;
    code0UnkStruct16 *ptr;

    ptr = &D_801A6D90[0];
    for (i = 0; i < ARRAY_COUNT(D_801A6D90); i++)
    {
        if (ptr->unk0 == 0)
        {
            memset(ptr, 0, sizeof(code0UnkStruct16));
            return ptr;
        }
        ptr++;
    }
    return NULL;
}

/*8007EC10*/
code0UnkStruct16 *func_8007EC10(s32 arg0)
{
    code0UnkStruct16 *ptr;

    ptr = func_8007EBB0();
    ptr->unkC = 1;
    ptr->unk8 = arg0;
    D_8016D17C++;
    ptr->unk0 = 1;
    ptr->unk12 = 0xFF;
    ptr->unk10 = 0xFF;
    ptr->unk40 = 1.0f;
    return ptr;
}

/*8007EC7C*/
void func_8007EC7C(code0UnkStruct16 *arg0)
{
    memset(arg0, 0, sizeof(code0UnkStruct16));
    arg0->unk12 = 0xFF;
    arg0->unk10 = 0xFF;
    arg0->unk40 = 1.0f;
}

/*8007ECC8*/
void func_8007ECC8(code0UnkStruct16 *arg0)
{
    ProcPointer proc;

    if (arg0 != NULL)
    {
        proc = D_800DFA10[arg0->unk8];
        D_8012FD8C = arg0;

        if (proc != NULL)
            proc();

        arg0->unk0 = 0;
        D_8016D17C--;
    }
}

/*8007ED34*/
static s32 func_8007ED34(void)
{
    code0UnkStruct16 *ptr;
    s32 i, ret;
    s16 j;

    ret = 0;
    memset(&D_80199990, 0, sizeof(D_80199990));

    ptr = D_801A6D90;
    for (i = 0; i < ARRAY_COUNT(D_801A6D90); i++)
    {
        if (ptr->unk0 != 0)
        {
            ptr->unk4 = 1024 - ((s32)(ptr->unk3C + ptr->unk64) / 10);
            if (ptr->unk4 < 0)
                ptr->unk4 = 0;
            else if (ptr->unk4 >= ARRAY_COUNT(D_80199990)-2)
                ptr->unk4 = ARRAY_COUNT(D_80199990)-2;

            D_80199990[ptr->unk4]++;
        }
        ptr++;
    }

    for (i = 0; i < ARRAY_COUNT(D_80199990)-2; i++)
        D_80199990[i+1] += D_80199990[i];

    ptr = D_801A6D90;
    for (i = 0; i < ARRAY_COUNT(D_801A6D90); i++)
    {
        if (ptr->unk0 != 0)
        {
            j = D_80199990[ptr->unk4];
            ret++;
            D_80199990[ptr->unk4] = j-1;
            D_80138870[j-1] = i;
        }
        ptr++;
    }

    return ret;
}

/*8007EEC4*/
void func_8007EEC4(void)
{
    ProcPointer proc;
    s32 i;

    D_8012FD8C = D_801A6D90;
    for (i = 0; i < ARRAY_COUNT(D_801A6D90); i++)
    {
        if ((D_8012FD8C->unk0 != 0) && (D_8012FD8C->unkC & 1))
        {
            proc = D_800DF9A0[D_8012FD8C->unk8];
            if (proc != NULL)
                proc();
        }
        D_8012FD8C++;
    }
}

/*8007EF70*/
void func_8007EF70(void)
{
    code0UnkStruct16 *ptr;
    ProcPointer proc;
    s32 i, j;

    func_8007EEC4();
    j = func_8007ED34();

    for (i = 0; i < j; i++)
    {
        ptr = &D_801A6D90[D_80138870[i]];
        D_8012FD8C = ptr;
        if (D_8012FD8C->unkC & 1)
        {
            proc = D_800DF9D0[D_8012FD8C->unk8];
            if (proc != NULL)
            {
                proc();
                D_8012FD8C = ptr;
            }
        }
    }
}

/*8007F050*/
void func_8007F050(void)
{
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_801A6D90); i++)
        D_801A6D90[i].unk0 = 0;

    D_8016D17C = 0;
}

/*8007F07C*/
void func_8007F07C(void)
{
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_801A6D90); i++)
    {
        if ((D_801A6D90[i].unk8 - 4) < 2)
        {
            D_801A6D90[i].unk0 = 0;
            D_8016D17C--;
        }
    }
}
