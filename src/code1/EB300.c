#include "common.h"
#include "code0/main.h"
#include "code0/cache1d.h"
#include "code0/audio.h"
#include "code0/edl.h"
#include "code0/debug.h"
#include "code0/6ACA0.h"
#include "code0/7F6A0.h"
#include "code0/7FCE0.h"
#include "code0/82480.h"
#include "code0/84490.h"
#include "code0/controller.h"
#include "code0/8E670.h"
#include "code1/EB300.h"
#include "code0/code0.h"
#include "code1/code1.h"
#include "static/mapinfo.h"

typedef struct {
    /*0x00*/ ProcPointer unk0;
    /*0x04*/ u8 unk4;
    /*0x06*/ u16 unk6[11];
} _EB300UnkStruct2;

/*.data*/
/*801CA144*/ EXTERN_DATA f32 D_801CA144;
/*801CA14C*/ EXTERN_DATA _EB300UnkStruct1 D_801CA14C[MAP_NUM+1];
/*801CA310*/ EXTERN_DATA STATIC _119280UnkStruct1 D_801CA310[8];
/*801CA360*/ EXTERN_DATA STATIC _119280UnkStruct1 D_801CA360[4];
/*801CA388*/ EXTERN_DATA STATIC _119280UnkStruct1 D_801CA388[3];
/*801CA3A8*/ EXTERN_DATA STATIC _119280UnkStruct1 D_801CA3A8;
/*801CA3B8*/ EXTERN_DATA STATIC Lights1 D_801CA3B8;
/*801CA3D4*/ EXTERN_DATA STATIC s32 D_801CA3D4;
/*801CA3D8*/ EXTERN_DATA STATIC code1UnkStruct5 D_801CA3D8[5];
/*801CA464*/ EXTERN_DATA STATIC code1UnkStruct6 D_801CA464;
/*801CA474*/ EXTERN_DATA STATIC code1UnkStruct5 D_801CA474[3];
/*801CA4C8*/ EXTERN_DATA STATIC code1UnkStruct6 D_801CA4C8;
/*801CA4D8*/ EXTERN_DATA STATIC code1UnkStruct5 D_801CA4D8[11];
/*801CA60C*/ EXTERN_DATA STATIC code1UnkStruct6 D_801CA60C;
/*801CA61C*/ EXTERN_DATA STATIC code1UnkStruct5 D_801CA61C[3];
/*801CA670*/ EXTERN_DATA STATIC code1UnkStruct6 D_801CA670;
/*801CA680*/ EXTERN_DATA STATIC code1UnkStruct5 D_801CA680[8];
/*801CA760*/ EXTERN_DATA STATIC code1UnkStruct6 D_801CA760;
/*801CA770*/ EXTERN_DATA STATIC code1UnkStruct5 D_801CA770[2];
/*801CA7A8*/ EXTERN_DATA STATIC code1UnkStruct6 D_801CA7A8;
/*801CA7B8*/ EXTERN_DATA STATIC code1UnkStruct5 D_801CA7B8[2];
/*801CA7F0*/ EXTERN_DATA STATIC code1UnkStruct6 D_801CA7F0;
/*801CA800*/ EXTERN_DATA STATIC code1UnkStruct5 D_801CA800[2];
/*801CA838*/ EXTERN_DATA STATIC code1UnkStruct6 D_801CA838;
/*801CA848*/ EXTERN_DATA STATIC code1UnkStruct5 D_801CA848[2];
/*801CA880*/ EXTERN_DATA STATIC code1UnkStruct6 D_801CA880;
/*801CA890*/ EXTERN_DATA STATIC code1UnkStruct5 D_801CA890[8];
/*801CA970*/ EXTERN_DATA STATIC code1UnkStruct6 D_801CA970;
/*801CA980*/ EXTERN_DATA STATIC code1UnkStruct5 D_801CA980[3];
/*801CA9D4*/ EXTERN_DATA STATIC code1UnkStruct6 D_801CA9D4;
/*801CA9E4*/ EXTERN_DATA STATIC code1UnkStruct5 D_801CA9E4[2];
/*801CAA1C*/ EXTERN_DATA STATIC code1UnkStruct6 D_801CAA1C;
/*801CAA2C*/ EXTERN_DATA STATIC code1UnkStruct5 D_801CAA2C[5];
/*801CAAB8*/ EXTERN_DATA STATIC code1UnkStruct6 D_801CAAB8;
/*801CAAC8*/ EXTERN_DATA STATIC code1UnkStruct5 D_801CAAC8[4];
/*801CAB38*/ EXTERN_DATA STATIC code1UnkStruct6 D_801CAB38;
/*801CAB48*/ EXTERN_DATA STATIC code1UnkStruct5 D_801CAB48[8];
/*801CAC28*/ EXTERN_DATA STATIC code1UnkStruct6 D_801CAC28;
/*801CAC38*/ EXTERN_DATA STATIC code1UnkStruct5 D_801CAC38[12];
/*801CAD88*/ EXTERN_DATA STATIC code1UnkStruct6 D_801CAD88;
/*801CAD98*/ EXTERN_DATA STATIC code1UnkStruct5 D_801CAD98[8];
/*801CAE78*/ EXTERN_DATA STATIC code1UnkStruct6 D_801CAE78;
/*801CAE88*/ EXTERN_DATA STATIC code1UnkStruct5 D_801CAE88[6];
/*801CAF30*/ EXTERN_DATA STATIC code1UnkStruct6 D_801CAF30;
/*801CAF40*/ EXTERN_DATA STATIC code1UnkStruct5 D_801CAF40[9];
/*801CB03C*/ EXTERN_DATA STATIC code1UnkStruct6 D_801CB03C;
/*801CB04C*/ EXTERN_DATA STATIC code1UnkStruct5 D_801CB04C[4];
/*801CB0BC*/ EXTERN_DATA STATIC code1UnkStruct6 D_801CB0BC;
/*801CB0CC*/ EXTERN_DATA STATIC code1UnkStruct5 D_801CB0CC[4];
/*801CB13C*/ EXTERN_DATA STATIC code1UnkStruct6 D_801CB13C;
/*801CB14C*/ EXTERN_DATA STATIC code1UnkStruct5 D_801CB14C[12];
/*801CB29C*/ EXTERN_DATA STATIC code1UnkStruct6 D_801CB29C;
/*801CB2AC*/ EXTERN_DATA STATIC code1UnkStruct5 D_801CB2AC[4];
/*801CB31C*/ EXTERN_DATA STATIC code1UnkStruct6 D_801CB31C;
/*801CB32C*/ EXTERN_DATA STATIC code1UnkStruct5 D_801CB32C[7];
/*801CB3F0*/ EXTERN_DATA STATIC code1UnkStruct6 D_801CB3F0;
/*801CB400*/ EXTERN_DATA STATIC code1UnkStruct5 D_801CB400[5];
/*801CB48C*/ EXTERN_DATA STATIC code1UnkStruct6 D_801CB48C;
/*801CB49C*/ EXTERN_DATA STATIC code1UnkStruct5 D_801CB49C[5]; /*TODO: Size=4 ?*/
/*801CB528*/ EXTERN_DATA STATIC code1UnkStruct6 D_801CB528;
/*801CB538*/ EXTERN_DATA code1UnkStruct5 D_801CB538[9];
/*801CB634*/ EXTERN_DATA STATIC code1UnkStruct6 D_801CB634;
/*801CB644*/ EXTERN_DATA STATIC code1UnkStruct5 D_801CB644[3];
/*801CB698*/ EXTERN_DATA STATIC code1UnkStruct6 D_801CB698;
/*801CB6A8*/ EXTERN_DATA STATIC code1UnkStruct5 D_801CB6A8[2];
/*801CB6E0*/ EXTERN_DATA code1UnkStruct6 D_801CB6E0;
/*801CB6F0*/ EXTERN_DATA STATIC code1UnkStruct5 D_801CB6F0[2];
/*801CB728*/ EXTERN_DATA STATIC code1UnkStruct6 D_801CB728;
/*801CB738*/ EXTERN_DATA STATIC code1UnkStruct5 D_801CB738[3];
/*801CB78C*/ EXTERN_DATA STATIC code1UnkStruct6 D_801CB78C;
/*801CB79C*/ EXTERN_DATA STATIC code1UnkStruct5 D_801CB79C[3];
/*801CB7F0*/ EXTERN_DATA STATIC code1UnkStruct6 D_801CB7F0;
/*801CB800*/ EXTERN_DATA STATIC code1UnkStruct5 D_801CB800[4];
/*801CB870*/ EXTERN_DATA code1UnkStruct6 D_801CB870;
/*801CB880*/ EXTERN_DATA STATIC code1UnkStruct5 D_801CB880[4];
/*801CB8F0*/ EXTERN_DATA code1UnkStruct6 D_801CB8F0;
/*801CB900*/ EXTERN_DATA STATIC code1UnkStruct5 D_801CB900[2];
/*801CB938*/ EXTERN_DATA STATIC code1UnkStruct6 D_801CB938;
/*801CB948*/ EXTERN_DATA STATIC s32 D_801CB948[6];
/*801CB960*/ EXTERN_DATA STATIC char *D_801CB960[4];
/*801CB970*/ EXTERN_DATA STATIC char *D_801CB970[4];
/*801CB980*/ EXTERN_DATA STATIC char *D_801CB980[2];
/*801CB988*/ EXTERN_DATA STATIC char *D_801CB988[4];
/*801CB998*/ EXTERN_DATA STATIC _EB300UnkStruct2 D_801CB998[28];
/*801CBCA8*/ EXTERN_DATA STATIC char *D_801CBCA8[16];
/*801CBCE8*/ EXTERN_DATA STATIC u8 *D_801CBCE8[12];
/*801CBD18*/ EXTERN_DATA STATIC u32 D_801CBD18;

/*.comm*/
/*801CC7F0*/ u8 *D_801CC7F0;
/*801CC800*/ code0UnkStruct16 *D_801CC800[34] ALIGNED(8);
/*801CC890*/ code0UnkStruct16 *D_801CC890;
/*801CC8B0*/ code0UnkStruct16 *D_801CC8B0;
/*801CC8BC*/ s32 D_801CC8BC;
/*801CC8C0*/ s32 D_801CC8C0;
/*801CC8C4*/ s32 D_801CC8C4;
/*801CC8D0*/ code0UnkStruct16 *D_801CC8D0[16] ALIGNED(8);
/*801CC910*/ s32 D_801CC910;
/*801CC918*/ u16 D_801CC918;
/*801CD970*/ s32 D_801CD970;
/*801CD974*/ s32 D_801CD974;
/*801CD97C*/ s16 D_801CD97C;
/*801CD990*/ code0UnkStruct16 *D_801CD990[36] ALIGNED(8);
/*801CDA20*/ code0UnkStruct16 *D_801CDA20;
/*801CDA28*/ code0UnkStruct16 *D_801CDA28[22] ALIGNED(8);
/*801CDA88*/ s32 D_801CDA88;
/*801CDA8C*/ s32 D_801CDA8C;
/*801CDA90*/ u16 D_801CDA90; /*musHandle*/
/*801CDA94*/ u8 *D_801CDA94; /*edlHandle*/
/*801CDAA0*/ code1UnkStruct6 *D_801CDAA0[10] ALIGNED(8);
/*801CDAC8*/ s32 D_801CDAC8;
/*801CDAD4*/ u16 D_801CDAD4[22] ALIGNED(8);
/*801CDB04*/ s32 D_801CDB04;
/*801CDB0C*/ u16 D_801CDB0C;
/*801CDB20*/ s32 D_801CDB20;
/*801CDB28*/ u8 D_801CDB28[28] ALIGNED(8);
/*801CDB50*/ _EB300UnkStruct1 *D_801CDB50;
/*801CDB54*/ s32 D_801CDB54;
#if defined (MODERN) || defined (NON_MATCHING)
char D_801CDB58[6][16] ALIGNED(8); /*Fix out of bound access in func_801C764C*/
#else
/*801CDB58*/ char D_801CDB58[5][16] ALIGNED(8);
#endif
/*801CDBA8*/ s32 D_801CDBA8;
/*801CDBB0*/ char D_801CDBB0[20] ALIGNED(8);
/*801CDBD0*/ code0UnkStruct16 *D_801CDBD0[6] ALIGNED(8);
/*801CDBF8*/ code0UnkStruct16 *D_801CDBF8;
/*801CDBFC*/ code0UnkStruct16 *D_801CDBFC;
/*801CE474*/ s32 D_801CE474;
/*801CE488*/ s32 D_801CE488;
/*801CE490*/ s32 D_801CE490;
/*801CE494*/ s32 D_801CE494;
/*801CE558*/ code0UnkStruct16 *D_801CE558[16] ALIGNED(8);
/*801CE59C*/ s32 D_801CE59C;
/*801CE5A8*/ code1UnkStruct6 *D_801CE5A8;
/*801CE5DC*/ s32 D_801CE5DC;
/*801CF62C*/ Gfx *D_801CF62C;
/*801CF630*/ s32 D_801CF630;
/*801CF638*/ u8 *D_801CF638; /*edlHandle*/
/*801CF63C*/ s32 D_801CF63C;
/*801CF640*/ s16 D_801CF640;
/*801CF648*/ char D_801CF648[30][5] ALIGNED(8);
/*801CF6E0*/ code0UnkStruct16 *D_801CF6E0[8] ALIGNED(8);
/*801CF708*/ u16 D_801CF708;
/*801CF70C*/ code0UnkStruct16 *D_801CF70C;
/*801CF710*/ s16 D_801CF710;

/*.text*/
static void func_801C3608(void);
static void func_801C37B8(void);
STATIC void func_801C38DC(void);
static void func_801C3A88(s32);
static s16 func_801C53E8(s16);
static void func_801C5C68(void);
static void func_801C7108(void);
static void func_801C73A0(void);
static void func_801C7574(void);
static void func_801C8650(void);
static void func_801C90E4(void);
static void func_801C948C(void);
static void func_801C959C(void);
static void func_801C9B08(void);

INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBD20);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBD28);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBD34);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBD44);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBD50);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBD5C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBD64);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBD70);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBD7C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBD88);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBD90);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBD98);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBDA0);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBDAC);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBDB8);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBDC0);

extern const char D_801CBDC8[]; /*TODO: mutualized rodata?*/
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBDC8);

INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBDD4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBDE4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBDF8);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBE04);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBE10);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBE1C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBE2C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBE40);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBE5C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBE6C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBE80);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBE90);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBEA0);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBEAC);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBEB8);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBEC4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBED0);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBED8);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBEE4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBEF4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBF08);

/*801C0D80*/
static u16 func_801C0D80(void)
{
    s32 i;
    u16 j;

    j = 0;
    for (i = 0; i < D_801CDC64.unk1; i++)
        j |= D_801CD986[i];

    return j;
}

/*801C0DCC*/
static void func_801C0DCC(s32 arg0)
{
    s32 i;
    for (i = 0; i < D_801CDC64.unk1; i++)
        D_801CD986[i] &= ~arg0;
}

/*801C0E1C*/
static void func_801C0E1C(s32 arg0)
{
    s32 i;
    for (i = 0; i < D_801CDC64.unk1; i++)
        D_801CD986[i] |= arg0;
}

/*801C0E68*/
static u16 func_801C0E68(void)
{
    s32 i;
    u16 j;

    if (D_800BD3F9 == 5)
        return func_801C0D80();

    j = 0;
    for (i = 0; i < D_801CC8CA; i++)
        j |= D_801CD986[i];

    return j;
}

/*801C0EDC*/
static void func_801C0EDC(s32 arg0)
{
    s32 i;

    for (i = 0; i < D_801CC8CA; i++)
        D_801CD986[i] &= ~arg0;
}

/*801C0F28*/
static void func_801C0F28(s32 arg0)
{
    s32 i;

    for (i = 0; i < D_801CC8CA; i++)
        D_801CD986[i] |= arg0;
}

/*801C0F70*/
static void func_801C0F70(void)
{
    D_801CE5D8 = 0x25252525;
}

/*801C0F88*/
static u32 func_801C0F88(void)
{
    s32 i;

    i = D_801CE5D8;
    i *= 2;

    if ((D_801CE5D8 ^ i) < 0)
        i |= 1;

    i *= 31055;
    D_801CE5D8 = i;
    return i;
}

/*801C0FDC*/
s32 func_801C0FDC(s16 arg0)
{
    return ((func_801C0F88() >> 16) * arg0) >> 16; /*TODO?*/
}

/*801C1024*/
f32 tanf(f32 angle)
{
    f32 sin;
    f32 cos;

    cos = cosf(angle);
    sin = sinf(angle);

    if (cos == 0.0f)
        return 100000000.0;
    else
        return sin / cos;
}

/*801C1088*/
STATIC f32 func_801C1088(s32 x1, s32 x2, s32 y1, s32 y2)
{
    return ((f32)getAngle(x2 - x1, y2 - y1) * (3.1415926/1024.0));
}

/*801C10C8*/
void func_801C10C8(void)
{
    alloCache(&D_801CD96C, EDL_FILE_MAX_SIZE, gCacheLock);
    func_8007EB24();
    D_801CE5D8 = 0x25252525;
}

/*801C1114*/
static void func_801C1114(void)
{
    code0UnkStruct16 *ptr;

    ptr = func_8007EC10(3);
    D_8011BC40 = ptr;
    ptr->unk10 = 0;
    D_801CC88C = 0;
    ptr->unk3C = -10239.0;
}

/*801C1158*/
static void func_801C1158(u8 r, u8 g, u8 b, u8 a)
{
    D_8011BC40->unk68.r = r;
    D_8011BC40->unk68.g = g;
    D_8011BC40->unk68.b = b;
    D_8011BC40->unk10 = a;
}

/*801C118C*/
static void func_801C118C(void)
{
    if (D_801CC88C != 0)
    {
        if (D_801CC88C < 0)
        {
            D_8011BC40->unk10 -= 16;
            if (D_8011BC40->unk10 <= 16)
            {
                D_8011BC40->unk10 = 0;
                D_801CC88C = 0;
            }
        }
        else
        {
            D_8011BC40->unk10 += 16;
            if (D_8011BC40->unk10 >= (255-16))
            {
                D_8011BC40->unk10 = 0xFF;
                D_801CC88C = 0;
            }
        }
    }
}

/*801C1218*/
void setCameraPosition(f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp, f32 yUp, f32 zUp)
{
    gPosition.xEye = xEye;
    gPosition.yEye = yEye;
    gPosition.zEye = zEye;
    gPosition.xAt = xAt;
    gPosition.yAt = yAt;
    gPosition.zAt = zAt;
    gPosition.xUp = xUp;
    gPosition.yUp = yUp;
    gPosition.zUp = zUp;
}

/*801C127C*/
static void func_801C127C(void)
{
    s32 i, j, cond;

    cond = 1;
    for (i = 0; i < D_801CC8CA; i++)
    {
        if (D_800BD3F9 == 3)
            cond = D_801AE914 != 0;

        if (cond != 0)
        {
            if (D_8013A43C[i] > 60)
                D_8012F6FC[i] |= 0x800;

            if (D_8013A43C[i] < -60)
                D_8012F6FC[i] |= 0x400;

            if (D_8011A670[i] > 60)
                D_8012F6FC[i] |= 0x100;

            if (D_8011A670[i] < -60)
                D_8012F6FC[i] |= 0x200;
        }

        for (j = 0; j < 16; j++)
        {
            if (!((D_801CDAD4[i] >> j) & 1))
            {
                if ((D_8012F6FC[i] >> j) & 1)
                {
                    D_801CD986[i] |= 1 << j;
                    D_801CDAD4[i] |= 1 << j;
                }
            }
            if ((D_801CDAD4[i] >> j) & 1)
            {
                if (!((D_8012F6FC[i] >> j) & 1))
                {
                    D_801CD986[i] &= ~(1 << j);
                    D_801CDAD4[i] &= ~(1 << j);
                }
            }
        }
    }
}

/*801C146C*/
void func_801C146C(void)
{
    D_801CE5D8 += D_801CC910;
    D_801CC910++;
    func_801C127C();
}

/*801C14B4*/
static void func_801C14B4(code0UnkStruct16 *arg0, u8 r, u8 g, u8 b)
{
    arg0->unk68.r = r;
    arg0->unk68.g = g;
    arg0->unk68.b = b;
}

/*801C14C4*/
static void func_801C14C4(code0UnkStruct16 *arg0, u8 r, u8 g, u8 b)
{
    arg0->unk6B.r = r;
    arg0->unk6B.g = g;
    arg0->unk6B.b = b;
}

/*801C14D4*/
void func_801C14D4(void)
{
    s32 i;

    D_801CD96C = gDepthBuffer - 746000;
    func_8007EB24();
    setCameraPosition(0.0f, 0.0f, -90.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    edl_80081688(&D_801CDB08, 20);
    edl_80081688(&D_801CC888, 21);
    edl_80081688(&D_801CDBC8, 23);
    edl_80081688(&D_801CDA98, 22);
    D_800E0F58 = 0;

    for (i = 0; i < ARRAY_COUNT(D_01022510); i++)
        func_80083200(&D_801CE5E8[i], 0);

    D_800E0F58 = 1;
}

/*801C15CC*/
void func_801C15CC(void)
{
    s32 i;

    D_801CE5D8 = 0x25252525;
    allocMemory(SCREEN_WIDTH, SCREEN_HEIGHT*2, DISPLAY_LIST_SIZE*2, 0);
    setCameraPosition(0.0f, 0.0f, -500.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    func_801C10C8();
    func_8007FD8C(D_800DFA40, 0);
    D_801CDA94 = D_8010A938;
    func_8007FD8C(D_800DFB08, 11);
    func_8007FD8C(D_800E0778, 5);
    D_801CDA20 = func_8007FC08(D_800DFA40, 0, 0, 0, 500);
    edl_80081688(&D_801CF638, 16);
    edl_80081688(&D_801CC91C, 17);
    edl_80081688(&D_801CC920, 19);
    edl_80081688(&D_801CDB1C, 18);
    D_801CF70C = func_8008372C(0, &D_801CA310[1], 0x9080, &D_801CA3B8, 0);
    D_801CF62C = D_801ACBD4;
    gSPTexture(D_801ACBD4, 0x05BC, 0x05BC, 0, G_TX_RENDERTILE, G_ON);
    D_801CC890 = func_8008372C(0, &D_801CA310[2], 0, &D_801CA3B8, 0);
    D_801CC890->unk64 -= 30.0f;
    func_801C14B4(D_801CC890, 0, 0, 0xFF);
    D_801CF70C->unk3C = -1920.0f;
    D_801CDBFC = func_8008372C(0, &D_801CA310[3], 0x9080, &D_801CA3B8, 0);
    D_801CDBFC->unk12 = 80;
    D_801CDBFC->unk3C = 400.0f;
    func_801C14B4(D_801CDBFC, 0, 0, 0xFF);
    D_801CDB04 = 0;
    D_801CF630 = 0xFF;

    for (i = 0; i < ARRAY_COUNT(D_801CA360); i++)
        func_80083700(0, &D_801CA360[i], 0, 0);

    for (i = 0; i < ARRAY_COUNT(D_801CA388); i++)
        func_80083700(0, &D_801CA388[i], 0x1000, 0);

    func_80083700(0, &D_801CA310[0], 128, 0);
    main_80002390();
    main_80000610();
    func_801C1114();
    func_801C1158(0, 0, 0, 0xFF);
    D_801CC88C = -1;
    func_801C73A0();
    D_801CF640 = 0;
    D_801CC918 = 0;
    playSfx(1059);

    if ((gMusicHandle == 0) || (MusHandleAsk(gMusicHandle) == 0) || (gMusicNum != 2))
        playMusic(2);

    D_800BD3F9 = 1;
    D_801CD974 = 0;
}

/*801C1950*/
INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C1950);

INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBFA8);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBFB8);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBFC8);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBFDC);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CBFF0);

/*801C2BE8*/
void func_801C2BE8(code1UnkStruct6 *arg0)
{
    code1UnkStruct5 *ptr;
    s32 i;
    s16 j;

    ptr = arg0->unk4;
    D_801CE490 = 0;

    for (i = 0; i < arg0->unk0; i++, ptr++)
    {
        j = ptr->unk2;

        if (j == -1)
            j = gScreenWidth / 2;
        else if (gScreenWidth == 512)
            j += 96;

        D_801CD990[D_801CE490] = func_800802C0(ptr->unk8, j, arg0->unk8 + (i * arg0->unkA), 200, ptr->unk0);

        if (ptr->unk4 & 1)
        {
            func_801C14C4(D_801CD990[D_801CE490], 32, 0xFF, 32);
            D_801CD990[D_801CE490]->unk3C -= 100.0f;
        }
        else
            func_801C14C4(D_801CD990[D_801CE490], 140, 140, 165);

        if (ptr->unk4 & 2)
            D_801CD990[D_801CE490]->unk12 = 150;

        D_801CE490++;
        if (ptr->unk14 != NULL)
        {
            j = ptr->unk14->unk4[ptr->unk18[0]].unk2;

            if (j == -1)
                j = gScreenWidth / 2;
            else if (gScreenWidth == 512)
                j += 96;

            D_801CD990[D_801CE490-1]->unk7C = (intptr_t)func_800802C0(ptr->unk14->unk4[ptr->unk18[0]].unk8,
                                                                      j,
                                                                      arg0->unk8 + (i * arg0->unkA),
                                                                      200,
                                                                      ptr->unk14->unk4[ptr->unk18[0]].unk0);

            if ((ptr->unk14 == &D_801CA970) && ((ptr->unk18[0] != 0)))
                func_801C14C4((code0UnkStruct16 *)D_801CD990[D_801CE490-1]->unk7C, 0xFF, 0xFF, 0xFF);
            else
                func_801C14C4((code0UnkStruct16 *)D_801CD990[D_801CE490-1]->unk7C, 0, 200, 200);

            if (ptr->unk14->unk4->unk4 & 2)
                ((code0UnkStruct16 *)D_801CD990[D_801CE490-1]->unk7C)->unk12 = 150;
        }
    }
    D_801CE5A8 = arg0;
}

/*801C2F1C*/
static void func_801C2F1C(void)
{
    s32 i;

    for (i = 0; i < D_801CE490; i++)
    {
        if (D_801CD990[i]->unk7C != 0)
            func_8007ECC8((code0UnkStruct16 *)D_801CD990[i]->unk7C);

        func_8007ECC8(D_801CD990[i]);
    }
}

/*801C2F98*/
STATIC void func_801C2F98(void)
{
    code1UnkStruct6 *ptr;

    func_801C2F1C();
    D_801CE498.unk3 = 8;
    D_801CE498.unk5 = 1;
    D_801CDAA0[D_801CD980] = D_801CE5A8;
    D_801CD980++;
    *D_801CE5A8->unkC = D_801CE5A0;
    ptr = D_801CE5A8->unk4[D_801CE5A0].unk10;
    D_801CE5A8 = ptr;
    func_801C3A88(*ptr->unkC);
    func_801C2BE8(D_801CE5A8);
}

/*801C305C*/
STATIC void func_801C305C(void)
{
    code1UnkStruct6 *ptr;

    if (D_801CD980 != 0)
    {
        func_801C2F1C();
        D_801CD980--;
        *D_801CE5A8->unkC = D_801CE5A0;
        ptr = D_801CDAA0[D_801CD980];
        D_801CE5A8 = ptr;
        D_801CE5A0 = *ptr->unkC;
        func_801C2BE8(ptr);
    }
}

/*801C30EC*/
static void func_801C30EC(void)
{
    s32 i;
    s64 prev;

    prev = D_800FE9E0;
    while (prev == D_800FE9E0);

    cache1d_8002AAEC();
    edl_80081688(&D_801CDB08, 20);
    edl_80081688(&D_801CC888, 21);
    edl_80081688(&D_801CDBC8, 23);
    edl_80081688(&D_801CDA98, 22);
    func_8007FD8C(D_800DFAE0, 4);
    D_800E0F58 = 0;

    for (i = 0; i < ARRAY_COUNT(D_01022510); i++)
        func_80083700(1, &D_801CE5E8[i], 0, 0);

    D_800E0F58 = 1;
    func_8007F050();
    D_801CDA20 = func_8007FC08(D_800DFAE0, 0, 0, 0, 500);
    func_801C1114();
    func_801C1158(0, 0, 0, 0xFF);
    D_801CC88C = -1;
    func_801C2BE8(&D_801CA464);
    D_801CC8C0 = 0;
    D_800BD3F9 = 13;
    D_801CA144 = 1.8f;
}

/*801C328C*/
STATIC void func_801C328C(void)
{
    D_801CDC64.unk2 = D_801CE5A0;
    main_80000624(func_801C8650);
}

/*801C32C4*/
static void func_801C32C4(void)
{
    if (D_801CE498.unk1C == 0)
    {
        main_80000624(func_801C9B08);
    }
    else
    {
        func_801C30EC();
        D_801CDAC8 = 0;
    }
}

/*801C3310*/
static void func_801C3310(void)
{
    if ((gLoadMapNum == MAP_THE_END) || (D_801CE498.unk1C == 0))
        main_80000624(func_801C9B08);
    else
    {
        func_801C30EC();
        D_801CDAC8 = 0;
    }
}

/*801C3370*/
void func_801C3370(void)
{
    s32 prev;
    func_801C118C();

    if (D_801CC8C0 == 1)
    {
        if (D_801CA144 > -1.8)
        {
            D_801CA144 -= 0.2;
            if (D_801CA144 < -1.8)
            {
                prev = D_801CC8C0;
                D_801CC8C0 = 0;
                D_80199524 = prev;
                D_801CA144 = 1.8f;

                switch (D_801CDAC8)
                {
                case 0:
                    main_80000624(func_801C9B08);
                    break;

                case 1:
                    func_801C3608();
                    break;
                }
                return;
            }
        }
    }
    if (D_801CC8C0 == 0)
    {
        if (D_801CA144 > 0.0f)
        {
            D_801CA144 -= 0.2;
            if (D_801CA144 < 0.0f)
                D_801CA144 = 0.0f;
        }
        if ((func_801C0D80() & 0x8000) || (func_801C0D80() & 0x1000))
        {
            func_801C0DCC(0x8000);
            func_801C0DCC(0x1000);
            playSfx(747);
            D_801CC8C0 = 1;
            D_801CC88C = 1;
        }
    }
}

INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC020);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC024);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC028);

extern const char D_801CC02C[]; /*TODO: mutualized rodata?*/
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC02C);

INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC034);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC038);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC03C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC040);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC044);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC048);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC04C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC050);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC054);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC058);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC060);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC068);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC070);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC074);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC07C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC084);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC08C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC094);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC09C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC0A4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC0AC);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC0B0);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC0B4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC0BC);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC0C4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC0CC);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC0D4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC0DC);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC0E4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC0F0);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC0FC);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC104);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC10C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC114);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC11C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC120);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC128);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC130);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC138);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC140);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC150);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC15C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC164);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC170);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC188);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC198);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC1A4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC1B4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC1C0);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC1CC);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC1D4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC1E0);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC1EC);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC1F4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC204);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC210);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC218);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC21C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC220);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC224);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC228);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC22C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC230);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC234);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC238);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC23C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC240);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC244);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC254);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC268);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC27C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC288);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC29C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC2A4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC2B4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC2C0);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC2CC);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC2D4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC2E0);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC2EC);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC2F4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC308);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC310);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC324);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC334);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC344);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC34C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC35C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC36C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC378);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC384);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC38C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC394);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC3A0);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC3A8);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC3B0);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC3B8);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC3BC);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC3C8);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC3D8);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC3E8);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC3F8);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC404);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC40C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC414);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC424);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC434);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC43C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC448);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC450);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC458);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC464);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC470);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC47C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC480);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC484);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC490);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC4A0);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC4B0);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC4C4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC4D4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC4E0);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC4E8);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC4F4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC50C);

/*801C3524*/
void func_801C3524(void)
{
    if (MusHandleAsk(D_801CDA90) == 0)
    {
        MusStop(2, 30);
        *D_801CE5A8->unkC = D_801CE5A0;
        func_801C37B8();
        func_801C32C4();
    }
}

/*801C3580*/
STATIC void func_801C3580(void)
{
    D_801CDC64.unk1 = D_801CE498.unk2A + 2;

    if (D_801CDC64.unk1 < 3)
        D_801CAE88[5].unk4 = 2;
    else
        D_801CAE88[5].unk4 = 0;

    func_801C2F98();
}

/*801C35DC*/
STATIC void func_801C35DC(void)
{
    func_8007F07C();
    D_800BD3F9 = 17;
}

/*801C3608*/
static void func_801C3608(void)
{
    D_801CDC64.unk0 = 1;
    main_80000624(main_80001F40);
}

/*801C363C*/
void func_801C363C(u8 playernum, u16 arg1, u8 arg2)
{
    if (D_8012FC90 == 0)
    {
        if (gPlayer[playernum].unk45 == 0)
        {
            if (D_801CE498.unk1C != 0)
                controller_8008A4C4(playernum, arg1, ((arg2 * D_801CE498.unk1C) / 7));
        }
    }
}

/*801C36E4*/
STATIC void func_801C36E4(void)
{
    D_801CDACC = D_801CE5A0;
    D_801CA9E4[1].unk18 = &D_801CE498.unk2E[D_801CE5A0];
    D_801CAA2C[2].unk18 = &D_801CE498.unk36[D_801CE5A0];
    D_801CAA2C[3].unk18 = &D_801CE498.unk3E[D_801CE5A0];
    D_801CAA2C[4].unk18 = &D_801CE498.unk46[D_801CE5A0];
    func_801C2F98();
}

/*801C375C*/
static void func_801C375C(void)
{
    D_801CA9E4[1].unk18 = D_801CE498.unk2E;
    D_801CAA2C[2].unk18 = D_801CE498.unk36;
    D_801CDACC = 0;
    D_801CAA2C[3].unk18 = D_801CE498.unk3E;
    D_801CAA2C[4].unk18 = D_801CE498.unk46;
    func_801C2F98();
}

/*801C37B8*/
static void func_801C37B8(void)
{
    s16 i;

    D_800FE3FC = 0;
    D_801CDC64.unk0 = 0;
    D_801CDC64.unk1 = 1;
    gLoadMapNum = 0;
    memset(&D_801CE5F0, 0, sizeof(D_801CE5F0));

    for (i = 0; D_801CA14C[gLoadMapNum].unk0 != 10; i++)
        gLoadMapNum++;

    gTimeMachinePart = 0;
    D_8010554C = D_801CC8CC;
}

/*801C3874*/
STATIC void func_801C3874(void)
{
    func_8008E01C(30, 0);
    D_801AE914 = 0;
    func_8007F050();
}

/*801C38A8*/
STATIC void func_801C38A8(void)
{
    D_801AE914 = 0;
    func_8007F050();
    D_80199524 = 1;
}

/*801C38DC*/
STATIC void func_801C38DC(void)
{
    D_801A1994 = 1;
    D_801AE914 = 0;
    func_8007F050();
    D_800BD3E8 = 1;
    func_8008E01C(30, 2);
}

/*801C392C*/
STATIC void func_801C392C(void)
{
    D_801A1994 = 0;
    D_801AE914 = 0;
    func_8007F050();
    D_800BD3E8 = 1;
    func_8008E01C(30, 2);
}

/*801C3974*/
STATIC void func_801C3974(void)
{
    D_800DF585 = 0;
    func_801C38DC();
}

/*801C399C*/
STATIC void func_801C399C(void)
{
    D_800DF585 = 0;
    func_801C392C();
}

/*801C39C4*/
STATIC void func_801C39C4(void)
{
    func_8007F07C();
    D_801CDBA8 = 0;
    D_801CDA8C = 0;
    if (D_800FE3FC == 0)
    {
        gLoadMapNum = func_801C53E8(gMapNum);
        if (D_801CA14C[gLoadMapNum].unk0 == 99)
            gLoadMapNum = 0;
    }
    D_801CC88C = 1;
}

/*801C3A4C*/
STATIC void func_801C3A4C(void)
{
    func_8007F07C();
    D_801CDBA8 = 1;
    D_801CDA8C = 0;
    D_801CC88C = 1;
}

/*801C3A88*/
static void func_801C3A88(s32 arg0)
{
    D_801CE5A0 = arg0;
    while (1)
    {
        if (D_801CE5A8->unk4[D_801CE5A0].unk4 != 0)
            D_801CE5A0++;
        else
            break;
    }
}

/*801C3AD8*/
static void func_801C3AD8(void)
{
    s32 i;

    D_801CE5D8 = 0x25252525;
    D_800DF98C = 1;
    D_800BD3E8 = 1;
    D_801CC8C4 = 0;
    func_801C0EDC(0xD000);
    setCameraPosition(0.0f, 0.0f, -90.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    edl_80081688(&D_801CDB08, 20);
    edl_80081688(&D_801CC888, 21);
    edl_80081688(&D_801CDBC8, 23);
    edl_80081688(&D_801CDA98, 22);
    func_8007FD8C(D_800DFB08, 11);
    func_8007FD8C(D_800DFAB8, 3);
    D_800E0F58 = 0;

    for (i = 0; i < ARRAY_COUNT(D_01022510); i++)
        func_80083700(1, &D_801CE5E8[i], 0, 0);

    D_800E0F58 = 1;
    func_8007F050();
    D_801CDA20 = func_8007FC08(D_800DFAB8, 0, 0, 0, 500);
    func_801C1114();
    func_801C1158(0, 0, 0, 0xFF);
    D_801CC88C = -1;

    if ((D_800E16BC != 0) || (D_801CE470 != 0))
        D_801CE498.unk50 = 1;

    if (D_801CE498.unk50 == 0)
        D_801CB528.unk0 = 4;
    else
        D_801CB528.unk0 = 5;

    D_801CD980 = 0;
    func_801C2BE8(&D_801CB528);
    func_801C3A88(*D_801CE5A8->unkC);

    D_801CA144 = 1.8f;
    i = D_801CC8CA;
    D_801CAB38.unk0 = i;

    if (i == 1)
    {
        D_801CAB48[6].unkC = func_801C375C;
        D_801CAB48[6].unk10 = &D_801CAAB8;
        D_801CB49C[1].unk10 = &D_801CB0BC;
    }

    if (i == 2)
        D_801CDC64.unk1 = 2;

    D_801CE498.unk2A = i - 2;
    D_801CA4C8.unk0 = i - 1;
    D_8010554C = 0;

    if (osMemSize == 0x400000)
    {
        D_801CAB48[5].unk4 = 2;
        D_801CA980[0].unk4 = 2;
        D_801CA980[1].unk4 = 2;
    }

    if ((gMusicHandle == 0) || (MusHandleAsk(gMusicHandle) == 0) || (gMusicNum != 2))
        playMusic(2);

    MusStop(1, 0);
    D_801CDA90 = 0;
    func_801C7108();
    D_800BD3F9 = 2;
}

/*801C3E08*/
void func_801C3E08(void)
{
    cache1d_8002AAC0();
    allocMemory(SCREEN_WIDTH, SCREEN_HEIGHT*2, DISPLAY_LIST_SIZE*2, 0);
    func_801C10C8();
    func_801C3AD8();
    main_80002390();
    main_80000610();
}

/*801C3E5C*/
static void func_801C3E5C(void)
{
    code1UnkStruct5 *ptr1;
    code1UnkStruct5 *ptr2;
    code0UnkStruct16 *ptr3;


    ptr1 = &D_801CE5A8->unk4[D_801CE5A0];
    if (func_801C0E68() & 0x800)
    {
        func_801C0EDC(0x800);
        playSfx(746);
        func_801C14C4(D_801CD990[D_801CE5A0], 140, 140, 165);
        do
        {
            if (D_801CE5A0 == 0)
                D_801CE5A0 = D_801CE5A8->unk0 - 1;
            else
                D_801CE5A0--;
        } while (D_801CE5A8->unk4[D_801CE5A0].unk4 != 0);
    }
    else if (func_801C0E68() & 0x400)
    {
        func_801C0EDC(0x400);
        playSfx(746);
        func_801C14C4(D_801CD990[D_801CE5A0], 140, 140, 165);

        do
        {
            if (D_801CE5A0 == (D_801CE5A8->unk0 - 1))
                func_801C3A88(0);
            else
                D_801CE5A0++;
        } while (D_801CE5A8->unk4[D_801CE5A0].unk4 != 0);
    }
    else
    {
        if (func_801C0E68() & 0x1000)
        {
            func_801C0EDC(0x1000);
            func_801C0F28(0x8000);
        }
        if (func_801C0E68() & 0x8000)
        {
            func_801C0EDC(0x8000);
            if (ptr1->unkC != NULL)
            {
                if (D_801CE5A8 != &D_801CB0BC)
                    playSfx(747);
                else
                {
                    D_801CE498.difficulty = D_801CE5A0 - 1;
                    switch (D_801CE498.difficulty)
                    {
                    case 0:
                        D_801CDA90 = playSfx(915);
                        break;

                    case 1:
                        D_801CDA90 = playSfx(951);
                        break;

                    case 2:
                        D_801CDA90 = playSfx(943);
                        break;

                    }
                }
                D_801CC8C0 = 1;
            }
        }
        else if (func_801C0E68() & 0x4000)
        {
            func_801C0EDC(0x4000);
            if (D_801CD980 != 0)
            {
                D_801CC8C0 = -1;
                playSfx(748);
            }
        }
        else if (ptr1->unk14 != NULL)
        {
            if (func_801C0E68() & 0x200)
            {
                func_801C0EDC(0x200);
                playSfx(746);

                if (ptr1->unk18[0] == 0)
                    ptr1->unk18[0] = ptr1->unk14->unk0 - 1;
                else
                    ptr1->unk18[0]--;

                if (D_801CE5A8 == &D_801CB03C)
                {
                    if (D_801CE5A0 == 2)
                    {
                        ptr2 = &D_801CB03C.unk4[3];
                        if (ptr1->unk18[0] == 0)
                        {
                            if (*ptr2->unk18 == 0)
                            {
                                *ptr2->unk18 = 1;
                                ptr3 = (code0UnkStruct16 *)D_801CD990[3]->unk7C;
                                ptr3->unk70 = (intptr_t)ptr2->unk14[0].unk4[*ptr2->unk18].unk8;
                            }
                        }
                    }
                    else if (D_801CE5A0 == 3)
                    {
                        ptr2 = &D_801CB03C.unk4[2];
                        if (ptr1->unk18[0] == 0)
                        {
                            if (*ptr2->unk18 == 0)
                            {
                                *ptr2->unk18 = 1;
                                ptr3 = (code0UnkStruct16 *)D_801CD990[2]->unk7C;
                                ptr3->unk70 = (intptr_t)ptr2->unk14[0].unk4[*ptr2->unk18].unk8;
                            }
                        }
                    }
                }

                if ((ptr1->unk18 == &D_801CE498.musicvol) || (ptr1->unk18 == (&D_801CE498.mastervol)))
                    setVolume((D_801CE498.musicvol * 100) / 7, (D_801CE498.mastervol * 100) / 7);

                ptr3 = (code0UnkStruct16 *)D_801CD990[D_801CE5A0]->unk7C;
                ptr3->unk70 = (intptr_t)ptr1->unk14->unk4[ptr1->unk18[0]].unk8;
                if (ptr1->unk14 == &D_801CA970)
                {
                    if (ptr1->unk18[0] == 0)
                        func_801C14C4(ptr3, 0, 200, 200);
                    else
                        func_801C14C4(ptr3, 0xFF, 0xFF, 0xFF);
                }
            }
            if (func_801C0E68() & 0x100)
            {
                func_801C0EDC(0x100);
                playSfx(746);

                if ((ptr1->unk18[0]) != (ptr1->unk14->unk0 - 1))
                    ptr1->unk18[0]++;
                else
                    ptr1->unk18[0] = 0;

                if (D_801CE5A8 == &D_801CB03C)
                {
                    if (D_801CE5A0 == 2)
                    {
                        ptr2 = &D_801CB03C.unk4[3];
                        if (ptr1->unk18[0] == 0)
                        {
                            if (*ptr2->unk18 == 0)
                            {
                                *ptr2->unk18 = 1;
                                ptr3 = (code0UnkStruct16 *)D_801CD990[3]->unk7C;
                                ptr3->unk70 = (intptr_t)ptr2->unk14[0].unk4[*ptr2->unk18].unk8;
                            }
                        }
                    }
                    else if (D_801CE5A0 == 3)
                    {
                        ptr2 = &D_801CB03C.unk4[2];
                        if (ptr1->unk18[0] == 0)
                        {
                            if (*ptr2->unk18 == 0)
                            {
                                *ptr2->unk18 = 1;
                                ptr3 = (code0UnkStruct16 *)D_801CD990[2]->unk7C;
                                ptr3->unk70 = (intptr_t)ptr2->unk14[0].unk4[*ptr2->unk18].unk8;
                            }
                        }
                    }
                }

                if ((ptr1->unk18 == &D_801CE498.musicvol) || (ptr1->unk18 == (&D_801CE498.mastervol)))
                    setVolume((D_801CE498.musicvol * 100) / 7, (D_801CE498.mastervol * 100) / 7);

                ptr3 = (code0UnkStruct16 *)D_801CD990[D_801CE5A0]->unk7C;
                ptr3->unk70 = (intptr_t)ptr1->unk14->unk4[ptr1->unk18[0]].unk8;
                if (ptr1->unk14 == &D_801CA970)
                {
                    if (ptr1->unk18[0] == 0)
                        func_801C14C4(ptr3, 0, 200, 200);
                    else
                        func_801C14C4(ptr3, 0xFF, 0xFF, 0xFF);
                }
            }
        }
    }
}

/*801C45C0*/
static void func_801C45C0(void)
{
    code1UnkStruct5 *ptr;
    code0UnkStruct16 *ptr2;

    ptr = &D_801CE5A8->unk4[D_801CE5A0];
    if (D_801CD986[D_801CDACC] & 0x800)
    {
        D_801CD986[D_801CDACC] &= 0xF7FF;
        playSfx(746);
        func_801C14C4(D_801CD990[D_801CE5A0], 140, 140, 165);
        do
        {
            if (D_801CE5A0 == 0)
                D_801CE5A0 = D_801CE5A8->unk0 - 1;
            else
                D_801CE5A0--;

        } while (D_801CE5A8->unk4[D_801CE5A0].unk4 != 0);
    }
    else if (D_801CD986[D_801CDACC] & 0x400)
    {
        D_801CD986[D_801CDACC] &= 0xFBFF;
        playSfx(746);
        func_801C14C4(D_801CD990[D_801CE5A0], 140, 140, 165);
        do
        {
            if (D_801CE5A0 == (D_801CE5A8->unk0 - 1))
                func_801C3A88(0);
            else
                D_801CE5A0++;

        } while (D_801CE5A8->unk4[D_801CE5A0].unk4 != 0);
    }
    else
    {
        if ((D_801CD986[D_801CDACC] & 0x1000) || (D_801CD986[D_801CDACC] & 0x8000))
        {
            D_801CD986[D_801CDACC] &= 0xEFFF;
            if (ptr->unkC != NULL)
            {
                playSfx(747);
                D_801CC8C0 = 1;
            }
        }
        else if (D_801CD986[D_801CDACC] & 0x4000)
        {
            D_801CD986[D_801CDACC] &= 0xBFFF;
            if (D_801CD980 != 0)
            {
                playSfx(748);
                D_801CC8C0 = -1;
                return;
            }
            if ((D_801CE5A8 == &D_801CB870) || (D_801CE5A8 == &D_801CB8F0))
            {
                playSfx(748);
                func_801C14C4(D_801CD990[D_801CE5A0], 140, 140, 165);
                func_801C3A88(0);
                D_801CC8C0 = 1;
            }
        }
        else if (ptr->unk14 != NULL)
        {
            if (D_801CD986[D_801CDACC] & 0x200)
            {
                D_801CD986[D_801CDACC] &= 0xFDFF;
                playSfx(746);
                if (ptr->unk18[0] == 0)
                    ptr->unk18[0] = ptr->unk14->unk0 - 1;
                else
                    ptr->unk18[0]--;

                if ((ptr->unk18 == &D_801CE498.musicvol) || (ptr->unk18 == &D_801CE498.mastervol))
                    setVolume((D_801CE498.musicvol * 100) / 7, (D_801CE498.mastervol * 100) / 7);

                ptr2 = (code0UnkStruct16 *)D_801CD990[D_801CE5A0]->unk7C;
                ptr2->unk70 = (intptr_t)ptr->unk14->unk4[*ptr->unk18].unk8;
                if (ptr->unk14 == &D_801CA970)
                {
                    if (*ptr->unk18 == 0)
                        func_801C14C4(ptr2, 0, 200, 200);
                    else
                        func_801C14C4(ptr2, 0xFF, 0xFF, 0xFF);
                }
            }

            if (D_801CD986[D_801CDACC] & 0x100)
            {
                D_801CD986[D_801CDACC] &= 0xFEFF;
                playSfx(746);
                if (ptr->unk18[0] != (ptr->unk14->unk0 - 1))
                    ptr->unk18[0]++;
                else
                    ptr->unk18[0] = 0;

                if ((ptr->unk18 == &D_801CE498.musicvol) || (ptr->unk18 == &D_801CE498.mastervol))
                    setVolume((D_801CE498.musicvol * 100) / 7, (D_801CE498.mastervol * 100) / 7);

                ptr2 = (code0UnkStruct16 *)D_801CD990[D_801CE5A0]->unk7C;
                ptr2->unk70 = (intptr_t)ptr->unk14->unk4[*ptr->unk18].unk8;
                if (ptr->unk14 == &D_801CA970)
                {
                    if (*ptr->unk18 == 0)
                        func_801C14C4(ptr2, 0, 200, 200);
                    else
                        func_801C14C4(ptr2, 0xFF, 0xFF, 0xFF);
                }
            }
        }
    }
}

/*801C4B34*/
void func_801C4B34(void)
{
    code0UnkStruct16 *ptr;
    code1UnkStruct5 *ptr2;
    u8 c;
    s16 sin;

    ptr2 = &D_801CE5A8->unk4[D_801CE5A0];
    if (D_801AE914 == 0)
        func_801C118C();

    sin = sins(D_801CC910 << 13);
    ptr = D_801CD990[D_801CE5A0];
    c = ((sin*3) >> 11) - 49;
    ptr->unk6B.b = c;
    ptr->unk6B.g = c;
    ptr->unk6B.r = c;

    if (gMusicVolume == 0)
    {
        MusHandleStop(gMusicHandle, 0);
        gMusicHandle = 0;
    }
    else if (gMusicHandle == 0)
    {
        playMusic(gMusicNum);
    }

    if ((D_801AE914 == 0) && (D_801CE5A8 == &D_801CB528))
    {
        D_801CC8C4++;
        if (func_801C0E68())
            D_801CC8C4 = 0;

        if (D_801CC8C4 >= 451)
        {
            main_80000624(func_801C15CC);
            return;
        }
    }

    if (D_801CC8C0 == 1)
    {
        if (D_801CA144 > -1.8)
        {
            D_801CA144 -= 0.2;
            if (D_801CA144 < -1.8)
            {
                D_801CC8C0 = 0;
                D_801CA144 = 1.8f;
                if (ptr2->unkC != NULL)
                    ptr2->unkC();
            }
        }
    }
    if (D_801CC8C0 == -1)
    {
        if (D_801CA144 > -1.8)
        {
            D_801CA144 -= 0.2;
            if (D_801CA144 < -1.8)
            {
                D_801CC8C0 = 0;
                D_801CA144 = 1.8f;
                func_801C305C();
            }
        }
    }
    if (D_801CC8C0 == 0)
    {
        if (D_801CA144 > 0.0f)
        {
            D_801CA144 -= 0.2;
            if (D_801CA144 < 0.0f)
                D_801CA144 = 0.0f;
        }
        if (D_801CA144 == 0.0f)
        {
            if (D_801AE914 == 0)
                func_801C3E5C();
            else
                func_801C45C0();
        }
    }
}

/*801C4E90*/
STATIC void func_801C4E90(void)
{
    D_801CDBC6 = 0;
    D_801CDBC4 = 0;
    D_801CC8CC = 0;
    D_801CC926 = 0;
    D_801CDBCC = 0;
    D_801CC7F4 = 0;
    D_801CC8C8 = 0;
    D_801CC8A8 = 0;
    D_801CE48C = 0;
    D_801CC924 = 0;
    D_801CDB48 = 0;
    D_801CE4EC = 0;
    D_801CF634 = 0;
    D_801CE478 = 0;
    D_801CDA80 = 0;
    D_801CC8B8 = 0;
    D_801CDB14 = 0;
    D_801CDB16 = 0;
    D_801CD984 = 0;
    D_801CE480 = 0;
}

/*801C4F38*/
void func_801C4F38(void)
{
    memset(&D_801CE5F0, 0, sizeof(D_801CE5F0));
    memset(&D_801CE498, 0, sizeof(D_801CE498));
    D_801CE5AC = 0;
    D_801CE5F0.unk103A = 0;
    D_801CE498.unk20 = 1;
    D_801CE498.unk22 = 0;
    D_801CE498.unk1E = 1;
    D_801CE498.unk28 = 0;
    D_801CE498.mastervol = 7;
    D_801CE498.musicvol = 3;
    D_801CE498.unk8 = 2;
    D_801CE498.unk1C = 7;
    D_801CE498.unk16 = 1;
    D_801CE498.difficulty = 1;

    if (osMemSize > 0x400000)
        D_801CE5AC = 2;

    D_801CE498.unk36[0] = 0;
    D_801CE498.unk36[1] = 0;
    D_801CE498.unk36[2] = 0;
    D_801CE498.unk36[3] = 0;
    D_801CE498.unk3E[0] = 2;
    D_801CE498.unk3E[1] = 2;
    D_801CE498.unk3E[2] = 2;
    D_801CE498.unk3E[3] = 2;
    D_801AE914 = 0;
    D_801A1994 = 0;
    D_80199524 = 0;
    D_800FE3FC = 0;
    D_801CE470 = 0;
    D_800E16BC = 0;
    func_801C4E90();
    sprintf(D_801CDBB0, D_801CBDC8); /*TODO: mutualized rodata?*/
}

/*801C509C*/
static void func_801C509C(void)
{
    f32 f1, f2, f3;
    s32 i;

    D_801A1994 = 0;

    if (D_801A1958.enemies_total == 0)
        f1 = 1.0f;
    else
        f1 = (f32)D_801A1958.enemies_killed / (f32)D_801A1958.enemies_total;

    if (D_801A1958.babes_total == 0)
        f2 = 1.0f;
    else
        f2 = (f32)D_801A1958.babes_saved / (f32)D_801A1958.babes_total;

    if (D_801A1958.secrets_total == 0)
        f3 = 1.0f;
    else
        f3 = (f32)D_801A1958.secrets_found / (f32)D_801A1958.secrets_total;

    f1 *= 2.0f;
    f2 *= 2.0f;

    D_801A1958.unk10 = (s32)(((f1 + f2 + f3) / 5.0) * 100.0);
    if (D_801CDC64.unk0 == 1)
    {
        func_801C5C68();
        return;
    }

    D_801CDB54 = func_8008DA70(gMapNum);
    allocMemory(SCREEN_WIDTH, SCREEN_HEIGHT*2, DISPLAY_LIST_SIZE*2, 0);
    D_800BD3E8 = 1;
    func_801C10C8();
    setCameraPosition(0.0f, 0.0f, -90.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    edl_80081688(&D_801CDB08, 20);
    edl_80081688(&D_801CC888, 21);
    edl_80081688(&D_801CDBC8, 23);
    edl_80081688(&D_801CDA98, 22);
    func_8007FD8C(D_800DFB08, 11);
    func_8007FD8C(D_800E0454, D_801CB948[D_801CA14C[gMapNum].unk0]);
    func_8007FD8C(D_800DFA90, 2);
    D_800E0F58 = 0;

    for (i = 0; i < ARRAY_COUNT(D_01022510); i++)
        func_80083700(1, &D_801CE5E8[i], 0, 0);

    D_800E0F58 = 1;
    main_80002390();
    main_80000610();
    D_801CDB04 = 0;

    if (D_801CA14C[gLoadMapNum].unk0 == 10)
    {
        gLoadMapNum = 0;
        main_80000624(func_801C9B08);
        return;
    }

    if (D_800FE3FC == 0)
        func_801C90E4();

    D_801CDBA8 = 0;
    D_800BD3F9 = 5;
    D_800DF585 = 0;
}

/*801C53E8*/
static s16 func_801C53E8(s16 mapnum)
{
    if (D_800FEA90 == 0)
    {
        if (mapnum+1 != MAP_WETWORLD)
        {
            if (mapnum+1 != MAP_GOING_DOWN_THE_RACK)
                return mapnum+1;
            else
                return mapnum+2;
        }
        else
            return mapnum+2;
    }
    else
        return mapnum+1;
}

/*801C542C*/
void func_801C542C(void)
{
    code1UnkStruct2 *ptr;
    s32 i, j;

    switch (D_801CDB04)
    {
    case 0:
        func_801C53E8(gMapNum);
        func_801C0EDC(0x9000);
        func_8007F050();
        D_801CDA20 = func_8007FC08(D_800E0454, 0, 0, 0, 500);
        func_801C1114();
        func_801C1158(0, 0, 0, 0xFF);
        D_801CC88C = -1;
        D_801CF6E0[0] = func_800802C0(D_801CA14C[gMapNum].mapname, gScreenWidth / 2, -12, 180, 1);
        func_801C14C4(D_801CF6E0[0], 32, 0xFF, 32);
        D_801CF6E0[1] = func_800802C0((void *)"TIME TAKEN:", 0, 65, 200, 0);
        D_801CF6E0[2] = func_800802C0((void *)"KILLS:", 0, 87, 200, 0);
        D_801CF6E0[3] = func_800802C0((void *)"BABES:", 0, 109, 200, 0);
        D_801CF6E0[4] = func_800802C0((void *)"SECRETS:", 0, 131, 200, 0);
        D_801CF6E0[5] = func_800802C0((void *)"OVERALL RATING:", 0, 153, 200, 0);
        D_801CD980 = 0;
        func_801C2BE8(&D_801CB938);

        if (D_80138620 != 0)
            D_801CE5A0 = 1;
        else
            D_801CE5A0 = 0;

        sprintf(D_801CDB58[0], "%d : %02d", D_801A1958.unkC / 1800U,
                (D_801A1958.unkC / 30U) - ((D_801A1958.unkC / 1800U) * 60));
        D_801CDBD0[0] = func_800802C0(D_801CDB58[0], gScreenWidth, 65, 200, 2);
        sprintf(D_801CDB58[1], "%d / %d", D_801A1958.enemies_killed, D_801A1958.enemies_total);
        D_801CDBD0[1] = func_800802C0(D_801CDB58[1], gScreenWidth, 87, 200, 2);
        sprintf(D_801CDB58[2], "%d / %d", D_801A1958.babes_saved, D_801A1958.babes_total);
        D_801CDBD0[2] = func_800802C0(D_801CDB58[2], gScreenWidth, 109, 200, 2);
        sprintf(D_801CDB58[3], "%d / %d", D_801A1958.secrets_found, D_801A1958.secrets_total);
        D_801CDBD0[3] = func_800802C0(D_801CDB58[3], gScreenWidth, 131, 200, 2);
        sprintf(D_801CDB58[4], "%d%%", D_801A1958.unk10);
        D_801CDBD0[4] = func_800802C0(D_801CDB58[4], gScreenWidth, 153, 200, 2);

        for (i = 0; i < ARRAY_COUNT(D_801CDBD0)-1; i++)
            func_801C14C4(D_801CDBD0[i], 0, 200, 200);

        D_801CA144 = 0.0f;
        D_801CE59C = 0;

        if (D_801CDB54 != 0)
            D_801CF6E0[6] = func_8007FE2C("CHEAT AWARDED", gScreenWidth/2, 128, 200, 1, 0);

        if ((((gMapNum == MAP_WETWORLD) || (gMapNum == MAP_BOSS_HOG)) == 0) &&
            (((gMapNum == MAP_CYBORG_SCORPION) || ((gMapNum >= MAP_THE_RACK))) == 0))
        {
            if (gTimeMachinePart & (1 << gMapNum))
            {
                D_801CE59C = 1;
                D_801CF6E0[7] = func_8007FE2C("TIME MACHINE PART FOUND",
                                              gScreenWidth / 2, (gScreenHeight / 2) + 96, 200, 1, 0);
            }
            else
            {
                D_801CF6E0[7] = func_8007FE2C("TIME MACHINE PART NOT FOUND",
                                              gScreenWidth / 2, (gScreenHeight / 2) + 96, 200, 1, 0);
                D_801CF6E0[7]->unkC |= 0x04000000;
            }
        }
        D_801CDB04++;
        break;
    case 1:
        j = D_801CC88C;
        if (j == D_801CDB04)
        {
            if (D_8011BC40->unk10 == 0xFF)
            {
                if (D_801CDA8C == 0)
                    func_8007F050();

                D_801CDA8C++;
                if (D_801CDA8C >= 11)
                {
                    if (D_801CDBA8 == j)
                    {
                        func_801C90E4();
                        ptr = &D_801CE5F0.unk4[gMapNum];
                        ptr->unk182 = D_801A1958.unk10;
                        ptr->unk172 = D_801A1958.unkC;
                        ptr->unk178 = D_801A1958.babes_saved;
                        ptr->unk180 = D_801A1958.secrets_found;
                        ptr->unk176 = D_801A1958.enemies_killed;
                        ptr->unk164 = D_801A1958.enemies_total;
                        ptr->unk166 = D_801A1958.babes_total;
                        ptr->unk168 = D_801A1958.secrets_total;
                        func_801C948C();
                        D_801CDB04 = 2;
                    }
                    else if (D_800FE3FC == 0)
                        func_801C3310();
                    else
                        main_80000624(func_801C7574);
                }
            }
            else
            {
                D_8011BC40->unk10 += 16;
                if (D_8011BC40->unk10 >= 0xEF)
                    D_8011BC40->unk10 = 0xFF;
            }
        }
        else
        {
            func_801C118C();
            func_801C4B34();
            if (D_801CA144 > 0.0f)
            {
                D_801CA144 -= 0.2;
                if (D_801CA144 < 0.0f)
                    D_801CA144 = 0.0f;
            }
            if (D_801CDB54 != 0)
            {
                if ((D_801CC910 & 0xF) < 7)
                    D_801CF6E0[6]->unkC &= ~1;
                else
                    D_801CF6E0[6]->unkC |= 1;
            }
            if (D_801CE59C != 0)
            {
                if ((D_801CC910 & 0xF) < 7)
                    D_801CF6E0[7]->unkC &= ~1;
                else
                    D_801CF6E0[7]->unkC |= 1;
            }
        }
        break;
    case 2:
        if (controller_8008C8DC())
            D_801CDB04 = 0;
        break;
    }
}

INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC5F0);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC600);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC610);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC620);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC630);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC634);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC63C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC648);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC654);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC660);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC66C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC670);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC674);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC678);

/*801C5C68*/
static void func_801C5C68(void)
{
    code0UnkStruct16 *sp28[2];
    code0UnkStruct16 *ptr;
    s32 i, j, k, l, m, n, o;

    allocMemory(SCREEN_WIDTH, SCREEN_HEIGHT*2, DISPLAY_LIST_SIZE*2, 0);
    func_801C10C8();
    setCameraPosition(0.0f, 0.0f, -90.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    edl_80081688(&D_801CDB08, 20);
    edl_80081688(&D_801CC888, 21);
    edl_80081688(&D_801CDBC8, 23);
    edl_80081688(&D_801CDA98, 22);
    func_8007FD8C(D_800DFB08, 11);
    func_8007FD8C(D_800E0454, D_801CB948[D_801CA14C[gMapNum].unk0]);
    D_800E0F58 = 0;

    for (i = 0; i < 64; i++)
        func_80083700(1, &D_801CE5E8[i], 0, 0);

    D_800E0F58 = 1;
    func_801C1114();
    D_801CDA20 = func_8007FC08(D_800E0454, 0, 0, 0, 500);
    func_801C1158(0, 0, 0, 0xFF);
    D_801CC88C = -1;
    D_801CF6E0[0] = func_800802C0(D_801CA14C[gMapNum].mapname, gScreenWidth / 2, 24, 200, 1);
    func_801C14C4(D_801CF6E0[0], 32, 0xFF, 32);
    D_801CF6E0[1] = func_800802C0("PRESS START TO ENTER", gScreenWidth/2, 186, 200, 1);
    D_801CF6E0[2] = func_800802C0(D_801CA14C[gMapNum + 1].mapname, gScreenWidth / 2, 208, 200, 1);

    if (D_801CDC64.unk2 == 5)
    {

        m = (gScreenWidth / 2) - 72;
        k = 0;
        for (i = 0; i < 2; i++)
        {
            sp28[i] = func_800802C0(D_801CB980[i], 104, m+i*28, 200, 0);

            for (l = 0; l < D_801CDC64.unk1; l++)
            {
                if (D_800E16A0[l] == i)
                    break;
            }

            o = CLAMP_MAX((D_800FF4F0[l].unk0 - D_800FF4F0[l].unk2), 9999);

            sprintf(D_801CF648[k], "%4d", o);
            func_800802C0(D_801CF648[k], 170, m+i*28, 200, 0);
            k++;
        }

        sp28[0]->unk6B.r = 0;
        sp28[0]->unk6B.g = 0xFF;
        sp28[0]->unk6B.b = 0xFF;
        sp28[1]->unk6B.r = 0xFF;
        sp28[1]->unk6B.g = 0x32;
        sp28[1]->unk6B.b = 0x32;
    }
    else if (D_801CDC64.unk2 == 3)
    {
        n = -1;
        for (i = 0; i < D_801CDC64.unk1; i++)
        {
            if (gPlayer[i].unk45 == 0)
            {
                n = i;
                break;
            }
        }

        if (n != -1)
            D_801CF6E0[3] = func_800802C0(D_801CB960[n], gScreenWidth/2, 102, 200, 1);
        else
            D_801CF6E0[3] = func_800802C0("DRAW", gScreenWidth/2, 102, 200, 1);
    }
    else
    {
        m = (gScreenWidth / 2) + 40;
        ptr = func_8007FE2C("TOTAL", (D_801CDC64.unk1 * 40) + 118, (gScreenWidth / 2) + 20, 64, 1, 0);
        ptr->unkC |= 0x08000000;

        k = 0;
        for (i = 0; i < D_801CDC64.unk1; i++)
        {

            ptr = func_8007FE2C(D_801CB970[i], 24, m+i*20, 64, 0, 0);
            ptr->unkC |= 0x08000000;
            ptr = func_8007FE2C(D_801CB988[i], 126 + i*40, m - 20, 64, 2, 0);
            ptr->unkC |= 0x08000000;

            for (j = 0; j < D_801CDC64.unk1; j++)
            {
                o = MIN(D_800FF4F0[i].unk4[j], 9999);
                sprintf(D_801CF648[k], "%d", o);
                func_8007FE2C(D_801CF648[k], 118+j*40, m+i*20, 64, 1, 0);
                k++;
            }

            o = CLAMP_MAX((D_800FF4F0[i].unk0 - D_800FF4F0[i].unk2), 9999);
            sprintf(D_801CF648[k], "%d", o);
            func_8007FE2C(D_801CF648[k], (D_801CDC64.unk1 * 40) + 118, m+i*20, 64, 1, 0);
            k++;

        }
    }
    D_801CA144 = 0.0f;
    D_800BD3F9 = 4;
    main_80002390();
    main_80000610();
}

/*801C63CC*/
void func_801C63CC(void)
{

    if (D_801CC88C == 1)
    {
        if (D_8011BC40->unk10 == 0xFF)
        {
            if (D_801CDA8C == 0)
                func_8007F050();

            D_801CDA8C++;
            if (D_801CDA8C >= 11)
                main_80000624(main_80001F40);
        }
        else
        {
            D_8011BC40->unk10 += 0x10;
            if (D_8011BC40->unk10 >= 0xEF)
                D_8011BC40->unk10 = 0xFF;
        }
    }
    else
    {
        func_801C118C();
        if ((func_801C0E68() & 0x8000) || (func_801C0E68() & 0x1000))
        {
            func_801C0EDC(0x8000);
            func_801C0EDC(0x1000);
            playSfx(747);
            gLoadMapNum++;
            if (D_801CA14C[gLoadMapNum].unk0 == 99)
            {
                for (gLoadMapNum = 0; D_801CA14C[gLoadMapNum].unk0 != 5; gLoadMapNum++)
                    ;
            }
            D_801CDA8C = 0;
            D_801CC88C = 1;
        }
    }
}

/*801C6560*/
void func_801C6560(void)
{
    s32 i;

    allocMemory(SCREEN_WIDTH, SCREEN_HEIGHT*2, DISPLAY_LIST_SIZE*4, 0);
    func_801C10C8();
    setCameraPosition(0.0f, 0.0f, -500.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    func_8007FD8C(D_800DFB08, 11);
    func_8007FD8C(D_800E0404, 13);

    for (i = 0; gpLicenceStrInfo[i]; i++)
        func_8007FE2C(gpLicenceStrInfo[i], gScreenWidth / 2, (46 + i * 12), 64, 1, 0);

    func_801C1114();
    func_801C1158(0, 0, 0, 0xFF);
    D_801CC88C = -1;
    main_80002390();
    main_80000610();
    D_800BD3F9 = 8;
    D_801CDB04 = 100;
    D_801CE494 = 0;
    D_800BD3E8 = 1;
}

/*801C66D8*/
void func_801C66D8(void)
{
    s32 i;

    switch (D_801CE494)
    {
    case 0:
        i = D_801CC88C;
        if (i == 1)
        {
            if (D_8011BC40->unk10 == 0xFF)
            {
                if (D_801CDA8C == 0)
                    func_8007F050();

                D_801CDA8C++;
                if (D_801CDA8C >= 5)
                {
                    if (osMemSize > 0x400000)
                    {
                        edl_80081688(&D_801CC7F0, 24);
                        edl_80081688(&D_801CDB10, 25);
                        edl_80081688(&D_801CDB44, 27);
                        edl_80081688(&D_801CDB18, 26);
                        func_8007F050();
                        D_801CDBF8 = func_8008372C(2, &D_801CA3A8, 0x9080, &D_801CA3B8, 0);
                        D_801CDBF8->unk3C = 100.0f;
                        func_801C1114();
                        func_801C1158(0, 0, 0, 0xFF);
                        D_801CC88C = -1;
                        func_8007FE2C("EXPANSION PAK FOUND", gScreenWidth / 2, (gScreenHeight / 2) + 150, 0, i, 0);
                    }
                    else
                    {
                        D_801CE494++;
                        cache1d_8002AAC0();
                        allocMemory(SCREEN_WIDTH, SCREEN_HEIGHT, DISPLAY_LIST_SIZE*2, 0);
                        func_801C10C8();
                        func_8007FD8C(D_800DFB08, 11);
                        func_8007FD8C(&D_800E0404[0], 13);
                        D_800BD3F8 = 1;
                        func_801C1114();
                        func_8007FC08(&D_800E0404[0], 0, 0, 0, 500);
                        func_801C1158(0, 0, 0, 0xFF);
                        D_801CC88C = -1;
                        main_80002390();
                        main_80000610();
                    }
                    D_801CDB04 = 100;
                    D_801CE494++;
                }
            }
            else
            {
                D_8011BC40->unk10 += 0x10;
                if (D_8011BC40->unk10 >= 0xEF)
                    D_8011BC40->unk10 = 0xFF;
            }
            return;
        }
        if (D_801CDB04 != 0)
        {
            D_801CDB04--;
            if (D_801CDB04 == 0)
                break;
        }
        goto block_39;
    case 1:
        if (D_801CC88C == 1)
        {
            if (D_8011BC40->unk10 == 0xFF)
            {
                if (D_801CDA8C == 0)
                    func_8007F050();

                D_801CDA8C++;
                if (D_801CDA8C >= 5)
                {
                    cache1d_8002AAC0();
                    allocMemory(SCREEN_WIDTH, SCREEN_HEIGHT, DISPLAY_LIST_SIZE*2, 0);
                    func_801C10C8();
                    func_8007FD8C(D_800DFB08, 11);
                    func_8007FD8C(&D_800E0404[0], 13);
                    D_800BD3F8 = 1;
                    func_801C1114();
                    func_8007FC08(&D_800E0404[0], 0, 0, 0, 500);
                    func_801C1158(0, 0, 0, 0xFF);
                    D_801CC88C = -1;
                    main_80002390();
                    main_80000610();
                    D_801CDB04 = 100;
                    D_801CE494++;
                }
            }
            else
            {
                D_801CDBF8->unk4C += 0.02;
                D_801CDBF8->unk50 += 0.03;
                D_8011BC40->unk10 += 0x10;
                if (D_8011BC40->unk10 >= 0xEF)
                    D_8011BC40->unk10 = 0xFF;
            }
            return;
        }
        if (D_801CDB04 != 0)
        {
            D_801CDBF8->unk4C += 0.02;
            D_801CDBF8->unk50 += 0.03;
        }
        if (D_801CDB04 != 0)
        {
            D_801CDB04--;
            if (D_801CDB04 == 0)
                break;
        }
        goto block_39;
    case 2:
        if (D_801CC88C == 1)
        {
            if (D_8011BC40->unk10 == 0xFF)
            {
                func_8007F050();
                func_801C1114();
                func_8007FC08(&D_800E0404[1], 0, 0, 0, 500);
                func_801C1158(0, 0, 0, 0xFF);
                D_801CC88C = -1;
                D_801CDB04 = 100;
                D_801CE494++;
            }
            else
            {
                D_8011BC40->unk10 += 0x10;
                if (D_8011BC40->unk10 >= 0xEF)
                    D_8011BC40->unk10 = 0xFF;
            }
            return;
        }
        if (D_801CDB04 != 0)
        {
            D_801CDB04--;
            if (D_801CDB04 == 0)
                break;
        }
        goto block_39;
    case 3:
        if (D_801CC88C == 1)
        {
            if (D_8011BC40->unk10 == 0xFF)
            {
                func_8007F050();
                func_801C1114();
                func_8007FC08(&D_800E0404[2], 0, 0, 0, 500);
                func_801C1158(0, 0, 0, 0xFF);
                D_801CC88C = -1;
                D_801CDB04 = 100;
                D_801CE494++;
            }
            else
            {
                D_8011BC40->unk10 += 0x10;
                if (D_8011BC40->unk10 >= 0xEF)
                    D_8011BC40->unk10 = 0xFF;
            }
            return;
        }
        if (D_801CDB04 != 0)
        {
            D_801CDB04--;
            if (D_801CDB04 == 0)
                break;
        }
        goto block_39;
    case 4:
        if (D_801CC88C == 1)
        {
            if (D_8011BC40->unk10 == 0xFF)
            {
                if (D_801CDA8C == 0)
                    func_8007F050();

                D_801CDA8C++;
                if (D_801CDA8C >= 5)
                {
                    cache1d_8002AAC0();
                    func_801C15CC();
                }
            }
            else
            {
                D_8011BC40->unk10 += 0x10;
                if (D_8011BC40->unk10 >= 0xEF)
                    D_8011BC40->unk10 = 0xFF;
            }
            return;
        }
        if (D_801CDB04 != 0)
        {
            D_801CDB04--;
            if (D_801CDB04 == 0)
                break;
        }
        goto block_39;
    default:
    block_39:
        if (*D_801CD986 & 0x1000)
        {
            *D_801CD986 &= 0xEFFF;
            if (D_801CE494 > 0)
                D_801CDB04 = 1;
        }
        func_801C118C();
        return;
    }

    func_801C1158(0, 0, 0, 0);
    D_801CC88C = 1;
    D_801CDA8C = 0;
}

/*801C6CA4*/
STATIC void func_801C6CA4(void)
{
    D_800E16C0 |= 0x1C000000;
}

/*801C6CC4*/
STATIC void func_801C6CC4(void)
{
    D_800E16C0 |= 0x03FC0000;
}

/*801C6CE4*/
STATIC void func_801C6CE4(void)
{
    D_800E16C0 |= 0x70;
}

/*801C6D00*/
STATIC void func_801C6D00(void)
{
    D_800E16C0 |= 0x3E000;
}

/*801C6D24*/
STATIC void func_801C6D24(void)
{
    D_800E16C0 |= 0x1C80;
}

/*801C6D40*/
STATIC void func_801C6D40(void)
{
    D_800E16C0 |= 0x300;
}

/*801C6D5C*/
STATIC void func_801C6D5C(void)
{
    D_801CDBC6 = 1;
    D_800E16BC |= 1;
}

/*801C6D84*/
STATIC void func_801C6D84(void)
{
    D_801CC926 = 1;
    D_800E16BC |= 2;
}

/*801C6DAC*/
STATIC void func_801C6DAC(void)
{
    D_801CDBCC = 1;
    D_800E16BC |= 4;
}

/*801C6DD4*/
STATIC void func_801C6DD4(void)
{
    D_801CC7F4 = 1;
    D_800E16BC |= 8;
}

/*801C6DFC*/
STATIC void func_801C6DFC(void)
{
    D_801CC8C8 = 1;
    D_800E16BC |= 0x10;
}

/*801C6E24*/
STATIC void func_801C6E24(void)
{
    D_801CC8A8 = 1;
    D_800E16BC |= 0x20;
}

/*801C6E4C*/
STATIC void func_801C6E4C(void)
{
    D_801CDBC4 = 1;
    D_800E16BC |= 0x40;
}

/*801C6E74*/
STATIC void func_801C6E74(void)
{
    D_801CC8CC = 1;
    D_800E16BC |= 0x80;
}

/*801C6E9C*/
STATIC void func_801C6E9C(void)
{
    D_801CE48C = 1;
    D_800E16BC |= 0x100;
}

/*801C6EC4*/
STATIC void func_801C6EC4(void)
{
    D_801CC924 = 1;
    D_801CE470 |= 1;
}

/*801C6EEC*/
STATIC void func_801C6EEC(void)
{
    D_801CDB48 = 1;
    D_801CE470 |= 2;
}

/*801C6F14*/
STATIC void func_801C6F14(void)
{
    D_801CE4EC = 1;
    D_801CE470 |= 4;
}

/*801C6F3C*/
STATIC void func_801C6F3C(void)
{
    D_801CF634 = 1;
    D_801CE470 |= 8;
}

/*801C6F64*/
STATIC void func_801C6F64(void)
{
    D_801CE478 = 1;
    D_801CE470 |= 0x10;
}

/*801C6F8C*/
STATIC void func_801C6F8C(void)
{
    D_801CDA80 = 1;
    D_801CE470 |= 0x20;
}

/*801C6FB4*/
STATIC void func_801C6FB4(void)
{
    D_801CC8B8 = 1;
    D_801CE470 |= 0x40;
}

/*801C6FDC*/
STATIC void func_801C6FDC(void)
{
    D_801CDB14 = 1;
    D_801CE470 |= 0x80;
}

/*801C7004*/
STATIC void func_801C7004(void)
{
    D_801CDB16 = 1;
    D_801CE470 |= 0x100;
}

/*801C702C*/
STATIC void func_801C702C(void)
{
    D_801CD984 = 1;
    D_801CE470 |= 0x200;
}

/*801C7054*/
STATIC void func_801C7054(void)
{
    D_801CE480 = 1;
    D_801CE470 |= 0x400;
}

/*801C707C*/
STATIC void func_801C707C(void)
{
    func_801C6EC4();
    func_801C6EEC();
    func_801C6F14();
    func_801C6F3C();
    func_801C6F64();
    func_801C6F8C();
    func_801C6FB4();
    func_801C6FDC();
    func_801C7004();
    func_801C702C();
    func_801C7054();
}

/*801C70EC*/
STATIC void func_801C70EC(void)
{
    D_800DF990 = D_800DF990 == 0;
}

/*801C7108*/
static void func_801C7108(void)
{
    s32 i, j, k;

    for (i = 0; i < ARRAY_COUNT(D_801CB32C)-1; i++)
        D_801CB32C[i].unk4 = 2;
    for (j = 0; j < ARRAY_COUNT(D_801CB2AC)-1; j++)
        D_801CB2AC[j].unk4 = 2;
    for (k = 0; k < ARRAY_COUNT(D_801CB14C)-1; k++)
        D_801CB14C[k].unk4 = 2;
    if (D_800E16BC & 2)
        D_801CB32C[0].unk4 = 0;
    if (D_800E16BC & 4)
        D_801CB32C[1].unk4 = 0;
    if (D_800E16BC & 8)
        D_801CB32C[2].unk4 = 0;
    if (D_800E16BC & 0x10)
        D_801CB32C[3].unk4 = 0;
    if (D_800E16BC & 0x20)
        D_801CB32C[4].unk4 = 0;
    if (D_800E16BC & 0x100)
        D_801CB32C[5].unk4 = 0;
    if (D_800E16BC & 1)
        D_801CB2AC[0].unk4 = 0;
    if (D_800E16BC & 0x40)
        D_801CB2AC[1].unk4 = 0;
    if (D_800E16BC & 0x80)
        D_801CB2AC[2].unk4 = 0;
    if (D_801CE470 & 1)
        D_801CB14C[0].unk4 = 0;
    if (D_801CE470 & 2)
        D_801CB14C[1].unk4 = 0;
    if (D_801CE470 & 4)
        D_801CB14C[2].unk4 = 0;
    if (D_801CE470 & 8)
        D_801CB14C[3].unk4 = 0;
    if (D_801CE470 & 0x10)
        D_801CB14C[4].unk4 = 0;
    if (D_801CE470 & 0x20)
        D_801CB14C[5].unk4 = 0;
    if (D_801CE470 & 0x40)
        D_801CB14C[6].unk4 = 0;
    if (D_801CE470 & 0x80)
        D_801CB14C[7].unk4 = 0;
    if (D_801CE470 & 0x100)
        D_801CB14C[8].unk4 = 0;
    if (D_801CE470 & 0x200)
        D_801CB14C[9].unk4 = 0;
    if (D_801CE470 & 0x400)
        D_801CB14C[10].unk4 = 0;
}

/*801C73A0*/
static void func_801C73A0(void)
{
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_801CDB28); i++)
        D_801CDB28[i] = 0;

    D_801CC8BC = 0;
}

/*801C73CC*/
static void func_801C73CC(void)
{
    _EB300UnkStruct2 *ptr;
    s32 i;

    for (i = 0; i < 16; i++)
    {
        if (!((D_801CC918 >> i) & 1))
        {
            if ((D_8012F6FC[0] >> i) & 1)
            {
                D_801CC918 = 1 << i;
                D_801CC8BC = 1 << i;
                D_801CF640 = D_801CF640 | (1 << i);
            }
        }
        if (((D_801CC918 >> i) & 1))
        {
            if (!((D_8012F6FC[0] >> i) & 1))
            {
                D_801CF640 = D_801CF640 & (~(1 << i));
                D_801CC918 = D_801CC918 & (~(1 << i));
            }
        }
    }

    if (D_801CC8BC != 0)
    {
        ptr = D_801CB998;
        for (i = 0; i < ARRAY_COUNT(D_801CDB28); i++, ptr++)
        {
            if (D_801CC8BC == ptr->unk6[D_801CDB28[i]])
            {
                D_801CDB28[i]++;
                if ((D_801CDB28[i]) == ptr->unk4)
                {
                    playSfx(46);
                    D_801CE498.unk50 = 1;
                    ptr->unk0();
                    func_801C73A0();
                }
            }
            else
                D_801CDB28[i] = 0;
        }
        D_801CC8BC = 0;
    }
}

/*801C7574*/
static void func_801C7574(void)
{
    D_801CE5D8 = 0x25252525;
    allocMemory(SCREEN_WIDTH, SCREEN_HEIGHT*2, DISPLAY_LIST_SIZE*2, 0);
    setCameraPosition(0.0f, 0.0f, -90.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    func_801C10C8();
    D_800BD3E8 = 1;
    func_8007FD8C(D_800DFA90, 2);
    func_8007FD8C(D_800DFB08, 11);
    D_800BD3F9 = 10;
    main_80002390();
    main_80000610();
    D_801CDB04 = 0;
    D_801CE494 = 0;
}

/*801C764C*/
void func_801C764C(void)
{
    code1UnkStruct2 *temp_s3;
    s32 i, j, k, l;

    l = D_801CE5F0.unkFD5;
    l = MIN(l, 21);
    func_801C118C();

    if ((D_800FE3FC != 0) && (D_801CDB04 == 0))
    {
        D_800BD3E8 = 1;
        func_8007F050();
        func_801C1114();
        func_801C1158(0, 0, 0, 0xFF);
        D_801CC88C = -1;
        D_801CDB04++;
    }

    switch (D_801CDB04)
    {
    case 0:
        if (controller_8008D354())
        {
            if (D_80138620 != 0)
            {
                func_801C959C();
                D_800BD3E8 = 1;
                func_8007F050();
                if (D_801CE5F0.unkFD5 != 0)
                {
                    D_801CDB04++;
                    main_80000450();
                }
                else
                    main_80000624(func_801C3E08);
            }
            else
            {
                func_8007F050();
                main_80000624(func_801C3E08);
            }
        }
        break;
    case 1:
        D_801CE494++;
        if (D_801CE494 >= 11)
            D_801CDB04 = 2;
        break;
    case 2:
        cache1d_8002AAC0();
        allocMemory(SCREEN_WIDTH, SCREEN_HEIGHT*2, DISPLAY_LIST_SIZE, 0);
        setCameraPosition(0.0f, 0.0f, -90.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
        func_801C10C8();
        D_800BD3E8 = 1;
        func_801C0EDC(0xFFFF);
        edl_80081688(&D_801CDB08, 20);
        edl_80081688(&D_801CC888, 21);
        edl_80081688(&D_801CDBC8, 23);
        edl_80081688(&D_801CDA98, 22);
        D_800E0F58 = 0;

        for (i = 0; i < 64; i++)
            func_80083700(1, &D_801CE5E8[i], 0, 0);

        D_800E0F58 = 1;
        func_8007FD8C(D_800DFB08, 11);
        func_8007FD8C(&D_800E047C[0], 14);
        func_800802C0("SELECT LEVEL", gScreenWidth/2, 24, 64, 1);
        D_801CA144 = 0.0f;

        if (D_800FE3FC == 0)
            D_801CE5DC = l;
        else
            D_801CE5DC = gLoadMapNum;

        for (i = 0; i < (l + 1); i++)
        {
            D_801CDA28[i] = func_8007FC08(&D_800E047C[i], 0, 0, (gScreenHeight / 2) - 88, 500);
            k = D_801CE5DC * 256;
            D_801CDA88 = ((D_801CE5DC * 16384) + k) * 2;
            D_801CDA28[i]->unk34 = ((gScreenWidth / 2) - 60 + (i * 130) - (D_801CDA88 >> 8));

            if ((D_801CDA28[i]->unk34 < (gScreenWidth + 80)) && (D_801CDA28[i]->unk34 > -130.0f))
                D_801CDA28[i]->unkC |= 1;
            else
                D_801CDA28[i]->unkC &= ~1;
        }

        D_801CDB20 = 0;
        D_801CA3D4 = gScreenHeight/2 + 100;
        D_801CC8B0 = func_8007FE2C(D_801CA14C[D_801CE5DC].mapname, gScreenWidth / 2, D_801CA3D4, 64, 1, 0);
        D_801CA3D4 += 12;
        D_801CF6E0[1] = func_8007FE2C("TIME TAKEN:", 48, D_801CA3D4 + 12, 64, 0, 0);
        D_801CF6E0[2] = func_8007FE2C("KILLS:", 48, D_801CA3D4 + 24, 64, 0, 0);
        D_801CF6E0[3] = func_8007FE2C("BABES:", 48, D_801CA3D4 + 36, 64, 0, 0);
        D_801CF6E0[4] = func_8007FE2C("SECRETS:", 48, D_801CA3D4 + 48, 64, 0, 0);
        D_801CF6E0[6] = func_8007FE2C("TIME MACHINE PARTS:", 48, D_801CA3D4 + 60, 64, 0, 0);
        D_801CF6E0[5] = func_8007FE2C("OVERALL RATING:", 48, D_801CA3D4 + 72, 64, 0, 0);

        temp_s3 = &D_801CE5F0.unk4[D_801CE5DC];

        sprintf(D_801CDB58[0], "%d : %02d", (temp_s3->unk172 / 1800U),
                (temp_s3->unk172 / 30U) - ((temp_s3->unk172 / 1800U) * 60));
        D_801CDBD0[0] = func_8007FE2C(D_801CDB58[0], gScreenWidth - 48, D_801CA3D4 + 12, 64, 2, 0);
        sprintf(D_801CDB58[1], "%d / %d", temp_s3->unk176, temp_s3->unk164);
        D_801CDBD0[1] = func_8007FE2C(D_801CDB58[1], gScreenWidth - 48, D_801CA3D4 + 24, 64, 2, 0);
        sprintf(D_801CDB58[2], "%d / %d", temp_s3->unk178, temp_s3->unk166);
        D_801CDBD0[2] = func_8007FE2C(D_801CDB58[2], gScreenWidth - 48, D_801CA3D4 + 36, 64, 2, 0);
        sprintf(D_801CDB58[3], "%d / %d", temp_s3->unk180, temp_s3->unk168);
        D_801CDBD0[3] = func_8007FE2C(D_801CDB58[3], gScreenWidth - 48, D_801CA3D4 + 48, 64, 2, 0);
        sprintf(D_801CDB58[4], "%d%%", temp_s3->unk182);
        D_801CDBD0[4] = func_8007FE2C(D_801CDB58[4], gScreenWidth - 48, D_801CA3D4 + 72, 64, 2, 0);

        if ((D_801CE5DC == MAP_WETWORLD) || (D_801CE5DC == MAP_BOSS_HOG) ||
            (D_801CE5DC == MAP_CYBORG_SCORPION) || (D_801CE5DC >= MAP_THE_RACK))
            sprintf(D_801CDB58[5], D_801CC02C);
        else if (D_801CE5F0.unkFE4 & (1 << D_801CE5DC))
            sprintf(D_801CDB58[5], "1 / 1");
        else
            sprintf(D_801CDB58[5], "0 / 1");

        D_801CDBD0[5] = func_8007FE2C(D_801CDB58[5], (gScreenWidth - 48), (D_801CA3D4 + 60), 64, 2, 0);

        if ((D_801CE5DC == MAP_WETWORLD) || (D_801CE5DC == MAP_BOSS_HOG) ||
            (D_801CE5DC == MAP_CYBORG_SCORPION) || (D_801CE5DC >= MAP_THE_RACK))
            D_801CDBD0[5]->unkC |= 0x04000000;
        else
            D_801CDBD0[5]->unkC &= ~0x04000000;

        for (i = 0; i < ARRAY_COUNT(D_801CDBD0); i++)
        {
            D_801CF6E0[i+1]->unkC &= ~1;
            D_801CDBD0[i]->unkC &= ~1;
        }

        func_801C1114();
        func_801C1158(0, 0, 0, 0xFF);
        D_801CC88C = -1;
        main_80002390();
        main_80000610();
        D_801CDB04++;
        break;
    case 3:
        if (D_801CDB04 != 3)
            break;

        for (i = 0; i < (l + 1); i++)
        {
            D_801CDA28[i]->unk34 = ((gScreenWidth / 2) - 60 + (i * 130) - (D_801CDA88 >> 8));
            if ((D_801CDA28[i]->unk34 < (gScreenWidth + 80)) && (D_801CDA28[i]->unk34 > -130.0f))
                D_801CDA28[i]->unkC |= 1;
            else
                D_801CDA28[i]->unkC &= ~1;
        }

        j = D_801CE5DC * 256;
        j = ((((D_801CE5DC * 16384) + j) * 2) - D_801CDA88) >> 1;
        D_801CDA88 += j;

        if (!(func_801C0E68() & 0x300))
            j = 0;

        if ((j > -300) && (j < 300))
        {
            for (i = 0; i < (l + 1); i++)
                D_801CDA28[i]->unk10 = 110;

            D_801CDA28[D_801CE5DC]->unk10 = 0xFF;
            D_801CC8B0->unk70 = (intptr_t)D_801CA14C[D_801CE5DC].mapname;
            temp_s3 = &D_801CE5F0.unk4[D_801CE5DC];
            sprintf(D_801CDB58[0], "%d : %02d", (temp_s3->unk172 / 1800U),
                                                (temp_s3->unk172 / 30U) - ((temp_s3->unk172 / 1800U) * 60));
            sprintf(D_801CDB58[1], "%d / %d", temp_s3->unk176, temp_s3->unk164);
            sprintf(D_801CDB58[2], "%d / %d", temp_s3->unk178, temp_s3->unk166);
            sprintf(D_801CDB58[3], "%d / %d", temp_s3->unk180, temp_s3->unk168);
            sprintf(D_801CDB58[4], "%d%%", temp_s3->unk182);

            if (D_801CE5DC == D_801CE5F0.unkFD5)
            {
                for (i = 0; i < ARRAY_COUNT(D_801CDBD0); i++)
                {
                    D_801CF6E0[i+1]->unkC &= ~1;
                    D_801CDBD0[i]->unkC &= ~1;
                }
            }
            else
            {
                for (i = 0; i < ARRAY_COUNT(D_801CDBD0); i++)
                {
                    D_801CF6E0[i+1]->unkC |= 1;
                    D_801CDBD0[i]->unkC |= 1;
                }

                if ((D_801CE5DC == MAP_WETWORLD) || (D_801CE5DC == MAP_BOSS_HOG) ||
                    (D_801CE5DC == MAP_CYBORG_SCORPION) || (D_801CE5DC >= MAP_THE_RACK))
                {
                    sprintf(D_801CDB58[5], D_801CC02C);
                    D_801CDBD0[5]->unkC |= 0x04000000;
                }
                else if (D_801CE5F0.unkFE4 & (1 << D_801CE5DC))
                {
                    sprintf(D_801CDB58[5], "1 / 1");
                    D_801CDBD0[5]->unkC &= ~0x04000000;
                }
                else
                {
                    sprintf(D_801CDB58[5], "0 / 1");
                    D_801CDBD0[5]->unkC &= ~0x04000000;
                }
            }
            D_801CDB20 = 0;
        }
        if (D_801CDB20 == 0)
        {
            if (func_801C0E68() & 0x200)
            {
                if (D_801CE5DC != 0)
                {
                    playSfx(746);
                    D_801CE5DC--;

                    if ((D_801CE5DC == 3) && (D_801CE5F0.unkFD6 == 0))
                        D_801CE5DC--;

                    if ((D_801CE5DC == 17) && (D_801CE5F0.unkFD7 == 0))
                        D_801CE5DC = 16;
                }
                D_801CDB20 = 1;
            }
            if (func_801C0E68() & 0x100)
            {
                if (D_801CE5DC != l)
                {
                    playSfx(746);
                    D_801CE5DC++;

                    if ((D_801CE5DC == 3) && (D_801CE5F0.unkFD6 == 0))
                        D_801CE5DC++;

                    if ((D_801CE5DC == 17) && (D_801CE5F0.unkFD7 == 0))
                        D_801CE5DC = 18;
                }
                D_801CDB20 = 1;
            }
        }
        if (func_801C0E68() & 0x8000)
        {
            playSfx(747);
            func_801C0EDC(0x8000);
            gMapNum = gLoadMapNum = D_801CE5DC;

            if (D_801CE5DC != l)
                D_800FE3FC = 1;
            else
                D_800FE3FC = 0;

            D_801A1994 = 0;
            D_801CDC64.unk0 = 0;
            D_801CDC64.unk1 = 1;
            gLoadMapNum = gMapNum;

            if (D_801CE498.unk1C == 0)
                main_80000624(main_80001F40);
            else
            {
                func_801C30EC();
                D_801CDAC8 = 0;
            }
        }
        if (func_801C0E68() & 0x4000)
        {
            playSfx(748);
            func_801C0EDC(0x4000);
            func_8007F050();
            main_80000624(func_801C3E08);
        }
        break;
    }
}

/*801C8650*/
static void func_801C8650(void)
{
    s32 i;

    D_801CE5D8 = 0x25252525;
    allocMemory(SCREEN_WIDTH, SCREEN_HEIGHT*2, DISPLAY_LIST_SIZE*2, 0);
    setCameraPosition(0.0f, 0.0f, -90.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    func_801C10C8();
    D_800BD3E8 = 1;

    for (i = 0; D_801CA14C[i].unk0 != 5; i++);

    D_801CDB50 = &D_801CA14C[i];
    func_8007F050();
    setCameraPosition(0.0f, 0.0f, -90.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    func_8007FD8C(D_800E064C, 15);
    func_8007FD8C(D_800DFB08, 11);
    edl_80081688(&D_801CDB08, 20);
    edl_80081688(&D_801CC888, 21);
    edl_80081688(&D_801CDBC8, 23);
    edl_80081688(&D_801CDA98, 22);
    func_801C1114();
    func_801C1158(0, 0, 0, 0xFF);
    D_801CC88C = -1;
    D_800E0F58 = 0;

    for (i = 0; i < ARRAY_COUNT(D_01022510); i++)
        func_80083700(1, &D_801CE5E8[i], 0, 0);

    D_800E0F58 = 1;
    func_800802C0((void *)"SELECT LEVEL", (gScreenWidth / 2), 24, 64, 1);
    D_801CA144 = 0.0f;

    for (i = 0; i < ARRAY_COUNT(D_800E064C)-1; i++)
    {
        D_801CDA28[i] = func_8007FC08(&D_800E064C[i], 0, (gScreenWidth / 2) - 60 + (i * 130), (gScreenHeight / 2) - 88, 500);
        D_801CDA28[i]->unkC &= ~1;
    }

    D_800BD3F9 = 11;
    main_80002390();
    main_80000610();
    D_801CE5DC = 0;
    D_801CDA88 = 0;
    D_801CDB20 = 0;
    D_801CC8B0 = func_8007FE2C(D_801CDB50->mapname, gScreenWidth / 2, (gScreenHeight / 2) + 100, 64, 1, 0);
    D_8010554C = 1;
}

/*801C899C*/
void func_801C899C(void)
{
    s32 i, j;
    s64 prev;

    func_801C118C();

    for (i = 0; i < 14; i++)
    {
        D_801CDA28[i]->unk34 = ((gScreenWidth / 2) - 60 + (i * 130) - (D_801CDA88 >> 8));
        if ((D_801CDA28[i]->unk34 < (gScreenWidth + 80)) && (D_801CDA28[i]->unk34 > -130.0f))
            D_801CDA28[i]->unkC |= 1;
        else
            D_801CDA28[i]->unkC &= ~1;
    }

    j = D_801CE5DC * 256;
    j = ((((D_801CE5DC * 16384) + j) * 2) - D_801CDA88) >> 1;
    D_801CDA88 += j;

    if (!(func_801C0E68() & 0x300))
        j = 0;

    if ((j > -300) && (j < 300))
    {

        for (i = 0; i < 14; i++)
            D_801CDA28[i]->unk10 = 110;

        D_801CDA28[D_801CE5DC]->unk10 = 0xFF;
        D_801CDB20 = 0;
        D_801CC8B0->unk70 = (intptr_t)D_801CDB50[D_801CE5DC].mapname;
    }

    if (D_801CDB20 == 0)
    {
        if (func_801C0E68() & 0x200)
        {
            if (D_801CE5DC != 0)
            {
                playSfx(746);
                D_801CE5DC--;
            }
            D_801CDB20 = 1;
        }
        if (func_801C0E68() & 0x100)
        {
            if (D_801CE5DC != 13)
            {
                playSfx(746);
                D_801CE5DC++;
            }
            D_801CDB20 = 1;
        }
    }
    if (func_801C0E68() & 0x8000)
    {
        func_801C0EDC(0x8000);
        playSfx(747);
        for (gLoadMapNum = 0; D_801CA14C[gLoadMapNum].unk0 != 5; gLoadMapNum++);
        gLoadMapNum += D_801CE5DC;
        if (D_801CE498.unk1C == 0)
        {
            func_801C3608();
            return;
        }
        func_801C30EC();
        D_801CDAC8 = 1;
    }

    if (func_801C0E68() & 0x4000)
    {
        playSfx(748);
        func_801C0EDC(0x4000);

        prev = D_800FE9E0;
        while (prev == D_800FE9E0);

        func_8007F050();
        cache1d_8002AAEC();
        func_801C3AD8();
        func_801C2F1C();
        D_801CDAA0[D_801CD980++] = &D_801CB528;
        D_801CDAA0[D_801CD980++] = &D_801CB13C;
        D_801CDAA0[D_801CD980++] = &D_801CB03C;
        func_801C2BE8(&D_801CAF30);
        func_801C3A88(*D_801CE5A8->unkC);
    }
}

INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC72C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC73C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC74C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC758);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC764);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC770);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC778);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC780);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC788);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC794);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC79C);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC7A8);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC7B4);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC7C0);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC7D0);
INCLUDE_RODATA("nonmatchings/src/code1/EB300", D_801CC7DC);

/*801C8DE0*/
STATIC void func_801C8DE0(void)
{
    s32 i, j;

    func_801C2F98();
    j = -110;
    for (i = 0; i < ARRAY_COUNT(D_801CE558); i++)
    {
        D_801CE558[i] = func_8007FE2C(D_801CBCA8[i], (gScreenWidth / 2) - 136,
                                      (gScreenHeight / 2) + (j + (i * 14)), 64, 0, 0);
        D_801CE558[i]->unk10 = 0;
    }
    j = -110;
    for (i = 0; i < ARRAY_COUNT(D_801CC8D0); i++)
    {
        D_801CC8D0[i] = func_8007FE2C(gpControlPreset[D_801CE498.unk2E[D_801CDACC]].mapping[i],
                                      (gScreenWidth / 2) + 136, (gScreenHeight / 2) + (j + (i * 14)), 64, 2, 0);
        D_801CC8D0[i]->unk10 = 0;
    }
    D_800BD3F9 = 12;
}

/*801C8F54*/
void func_801C8F54(void)
{
    s32 i;

    func_801C4B34();
    if (D_801CC8C0 == -1)
    {
        for (i = 0; i < ARRAY_COUNT(D_801CC8D0); i++)
        {
            if (D_801CC8D0[i] != NULL)
            {
                if (D_801CC8D0[i]->unk10 >= 49)
                    D_801CC8D0[i]->unk10 -= 32;
                else
                {
                    func_8007ECC8(D_801CC8D0[i]);
                    D_801CC8D0[i] = NULL;
                }
            }
            if (D_801CE558[i] != NULL)
            {
                if (D_801CE558[i]->unk10 >= 49)
                    D_801CE558[i]->unk10 -= 32;
                else
                {
                    func_8007ECC8(D_801CE558[i]);
                    D_801CE558[i] = NULL;
                }
            }
        }
    }
    else
    {
        for (i = 0; i < ARRAY_COUNT(D_801CC8D0); i++)
        {
            if (D_801CC8D0[i] != NULL)
            {
                if (D_801CC8D0[i]->unk10 < 207)
                    D_801CC8D0[i]->unk10 += 32;
                else
                    D_801CC8D0[i]->unk10 = 0xFF;

                D_801CC8D0[i]->unk70 = (intptr_t)gpControlPreset[D_801CE498.unk2E[D_801CDACC]].mapping[i];
            }
            if (D_801CE558[i] != NULL)
            {
                if (D_801CE558[i]->unk10 < 207)
                    D_801CE558[i]->unk10 += 32;
                else
                    D_801CE558[i]->unk10 = 0xFF;
            }
        }
    }
}

/*801C90E4*/
static void func_801C90E4(void)
{
    code1UnkStruct3 *ptr;
    code1UnkStruct2 *ptr2;
    s16 ret;
    s32 i;

    ptr = &D_801CE5F0;
    ptr->unk103A = 1;
    ptr->unk2 = 31;
    ptr->unkFE8 = D_801CE498;

    ret = func_801C53E8(gMapNum);
    if (ptr->unkFD5 < ret)
        ptr->unkFD5 = ret;

    if (ret == 3)
        ptr->unkFD6 = 1;

    if (ret == 17)
        ptr->unkFD7 = 1;

    ptr2 = &ptr->unk4[gMapNum];
    if (D_800FE3FC == 0)
    {
        ptr2->unk182 = D_801A1958.unk10;
        ptr2->unk172 = D_801A1958.unkC;
        ptr2->unk178 = D_801A1958.babes_saved;
        ptr2->unk180 = D_801A1958.secrets_found;
        ptr2->unk176 = D_801A1958.enemies_killed;
        ptr2->unk164 = D_801A1958.enemies_total;
        ptr2->unk166 = D_801A1958.babes_total;
        ptr2->unk168 = D_801A1958.secrets_total;
        ptr2->unk0 = gPlayer[0].unk46;
        ptr2->unk2 = gPlayer[0].unk70;

        for (i = 0; i < ARRAY_COUNT(D_8011A680[0]); i++)
        {
            ptr2->unk4[i][0] = D_8011A680[0][i][0];
            ptr2->unk4[i][1] = D_8011A680[0][i][1];
            ptr2->unk4[i][2] = D_8011A680[0][i][7];
        }

        for (i = 0; i < ARRAY_COUNT(D_8010A940[0].unkA); i++)
            ptr2->unk148[i] = D_8010A940[0].unkA[i];
    }

    ptr->unkFD8 = D_800E16C0;
    ptr->unkFDC = D_800E16BC;
    ptr->unkFE0 = D_801CE470;
    ptr->unkFE4 = gTimeMachinePart;
}

/*801C936C*/
void func_801C936C(void)
{
    code1UnkStruct2 *ptr;
    code1UnkStruct3 *ptr2;
    s32 i;

    i = 1;
    ptr2 = &D_801CE5F0;
    if (gMapNum)
    {
        if (gMapNum == MAP_FALLOUT)
            i += (ptr2->unkFD6 == 0);

        if (gMapNum == MAP_BRAINSTORM)
            i += ptr2->unkFD7 == 0;

        ptr = &ptr2->unk4[gMapNum - i];
        gPlayer[0].unk46 = ptr->unk0;
        gPlayer[0].unk70 = ptr->unk2;

        for (i = 0; i < ARRAY_COUNT(D_8011A680[0]); i++)
        {
            D_8011A680[0][i][0] = ptr->unk4[i][0];
            D_8011A680[0][i][1] = ptr->unk4[i][1];
            D_8011A680[0][i][7] = ptr->unk4[i][2];
        }

        D_8010A940[0].unk0 = 0;
        for (i = 0; i < ARRAY_COUNT(D_8010A940[0].unk2); i++)
        {
            D_8010A940[0].unk2[i] = 0;
            D_8010A940[0].unkA[i] = ptr->unk148[i];
        }
    }
}


/*801C948C*/
static void func_801C948C(void)
{
    code1UnkStruct3 *ptr;
    ptr = &D_801CE5F0;
    ptr->unk2 = 31;
    ptr->unkFE8 = D_801CE498;
    D_801CC930 = *ptr;
}

/*801C959C*/
static void func_801C959C(void)
{
    code1UnkStruct3 *ptr;
    code1UnkStruct3 *ptr2;

    ptr2 = &D_801CC930;
    ptr = &D_801CE5F0;

    if (ptr2->unk2 == 31)
        D_801CE498 = ptr2->unkFE8;

    *ptr = *ptr2;

    setVolume((D_801CE498.musicvol * 100) / 7, (D_801CE498.mastervol * 100) / 7);
    D_800E16C0 |= ptr->unkFD8;
    D_800E16BC |= ptr->unkFDC;
    D_801CE470 |= ptr->unkFE0;
    gTimeMachinePart = ptr->unkFE4;
}

/*801C97A8*/
STATIC void func_801C97A8(void)
{
    *D_801CE5A8->unkC = D_801CE5A0;
    D_800FE3FC = 0;
    cache1d_8002AAC0();
    func_801C7574();
}

/*801C97F0*/
void func_801C97F0(void)
{
}

/*801C97F8*/
void func_801C97F8(void)
{
    s32 i;

    cache1d_8002AAC0();
    allocMemory(SCREEN_WIDTH, SCREEN_HEIGHT*2, DISPLAY_LIST_SIZE*2, 0);
    func_801C10C8();
    D_800BD3E8 = 1;
    func_801C0EDC(0xD000);
    func_8007FD8C(D_800DFB08, 11);
    func_8007FD8C(D_800E07DC, 28);
    func_8007F050();
    D_801CDA20 = func_8007FC08(D_800E07DC, 0, 0, 0, 500);
    main_80002390();
    main_80000610();
    func_801C1114();
    func_801C1158(0, 0, 0, 0xFF);

    D_801CC88C = -1;
    for (i = 0; i < ARRAY_COUNT(D_801CC800); i++)
        D_801CC800[i] = 0;

    D_801CD970 = 0;
    D_801CE474 = 0;
    D_801CE488 = 0;
    D_801CF63C = 0;
    playMusic(2);
    D_800BD3F9 = 14;
}

/*801C9924*/
void func_801C9924(void)
{
    s32 i;

    func_801C118C();
    if ((D_801CF63C != 0) && (D_801CC88C == 0))
    {
        main_80000624(func_801C3E08);
        return;
    }

    if (D_801CE488 >= 15)
    {
        D_801CE488 = 0;
        if (D_801CC800[D_801CD970] != NULL)
        {
            D_801CC800[D_801CD970]->unk38 = 484.0f;
            D_801CC800[D_801CD970]->unk70 = (intptr_t)gpCreditStrInfo[D_801CE474];
        }
        else
            D_801CC800[D_801CD970] = func_8007FE2C(gpCreditStrInfo[D_801CE474],
                                                   gScreenWidth / 2, 484, 64, 1, 0);

        D_801CD970++;
        if (D_801CD970 == ARRAY_COUNT(D_801CC800)-1)
            D_801CD970 = 0;

        D_801CE474++;
        if (gpCreditStrInfo[D_801CE474] == NULL)
        {
            D_801CC88C = 1;
            D_801CF63C = 1;
        }
    }
    for (i = 0; i < ARRAY_COUNT(D_801CC800)-1; i++)
    {
        if (D_801CC800[i] != NULL)
            D_801CC800[i]->unk38 -= 1.0f;
    }
    D_801CE488++;
}

/*801C9B08*/
static void func_801C9B08(void)
{
    main_80001F40();
}

/*801C9B28*/
void func_801C9B28(void)
{
    func_801C509C();
}

/*801C9B48*/
void func_801C9B48(void)
{
    s32 i;

    D_801CDC68 = D_801CDC70;
    i = D_801CBD18 % 5;
    readRom((u8 *)D_801CDC70, D_801CBCE8[i], 2048);
    D_801CDB0C = 0;
    D_8012FC90 = 1;
    gRandomSeed = 0;
    D_801CBD18++;
    gLoadMapNum = *D_801CDC68++;
    D_800DF98C = 0;
}

/*801C9C18*/
static void func_801C9C18(void)
{
    u8 i;

    i = *D_801CDC68;
    if ((i == 0) || (gPlayer[0].unk45 != 0))
    {
        func_8008E01C(0x1E, 5);
        D_8012FC90 = 0;
        return;
    }

    switch (i & 3)
    {
    case 2:
        D_801CDC68++;
        D_8011A670[0] = *D_801CDC68++;
        D_8013A43C[0] = *D_801CDC68++;
        break;
    case 3:
        D_801CDC68++;
        D_8012F6FC[0] = *D_801CDC68++ << 8;
        D_8012F6FC[0] += *D_801CDC68++;
        D_8012F6FC[0] &= 0xEFFF;
        i = *D_801CDC68;
        if ((i & 3) == 2)
        {
            D_801CDC68++;
            D_8011A670[0] = *D_801CDC68++;
            D_8013A43C[0] = *D_801CDC68++;
        }
        break;
    }
}

/*801C9D68*/
INCLUDE_ASM("nonmatchings/src/code1/EB300", func_801C9D68);

/*801C9E7C*/
void func_801C9E7C(void)
{
    D_801CDB4C = 1;
    D_801CDC68 = D_801CDC70;
    D_801CF708 = 0;
    D_801CF710 = 0;
    D_801CD97C = 0;
    D_801CDB0C = 0;
    gRandomSeed = 0;
    D_801CDC68 = &D_801CDC70[1];
    D_801CDC70[0] = gLoadMapNum;
}

/*801C9EDC*/
static void func_801C9EDC(void)
{
    if (D_801CDB0C != 0)
    {
        if (D_801CDB0C < 64)
        {
            *D_801CDC68++ = (D_801CDB0C & 0x3F) * 4;
        }
        else
        {
            *D_801CDC68++ = ((D_801CDB0C & 0x3F) * 4) + 1;
            *D_801CDC68++ = D_801CDB0C >> 6;
        }
        D_801CDB0C = 0;
    }
}

/*801C9F74*/
void func_801C9F74(void)
{
    s32 cond;

    if ((D_801CDC70 + 2040) < D_801CDC68)
    {
        main_80003940();
        return;
    }
    cond = 0;

    if (D_801CF708 != *D_8012F6FC)
    {
        D_801CF708 = *D_8012F6FC;
        func_801C9EDC();
        *D_801CDC68++ = 3;
        *D_801CDC68++ = *D_8012F6FC >> 8;
        *D_801CDC68++ = *D_8012F6FC;
        cond = 1;
    }

    if ((D_801CF710 != *D_8011A670) || (D_801CD97C != *D_8013A43C))
    {
        D_801CF710 = *D_8011A670;
        D_801CD97C = *D_8013A43C;
        func_801C9EDC();
        *D_801CDC68++ = 2;
        *D_801CDC68++ = *D_8011A670;
        *D_801CDC68++ = *D_8013A43C;
        cond = 1;
    }

    if (cond == 0)
        D_801CDB0C++;
}
