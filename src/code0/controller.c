#include "common.h"
#include "string.h"
#include "code0/7FCE0.h"
#include "code0/controller.h"
#include "code0/code0.h"
#include "code1/code1.h"

/*TODO: include string.h from libkmc instead of libultra*/
s32 strcmp(const char *, const char *);

#define CONTROLLER_EEPROM_LONG_READ 1
#define CONTROLLER_EEPROM_LONG_WRITE 2
#define CONTROLLER_PFS_NUM_FILES 3
#define CONTROLLER_PFS_FREE_BLOCKS 4
#define CONTROLLER_PFS_FILE_STATE 5
#define CONTROLLER_PFS_DELETE_FILE 6
#define CONTROLLER_PFS_INIT_PAK 7
#define CONTROLLER_PFS_REPAIR_ID 8
#define CONTROLLER_PFS_READ_WRITE_FILE 9
#define CONTROLLER_PFS_ALLOCATE_FILE 10
#define CONTROLLER_PFS_FIND_FILE 11
#define CONTROLLER_MOTOR_INIT 12
#define CONTROLLER_GET_STATUS 13

typedef struct {
    /*0x00*/ u32 unk0;
    /*0x04*/ u32 game_code;
    /*0x08*/ u16 company_code;
    /*0x0A*/ char ext_name[4];
    /*0x0E*/ char game_name[18];
} ControllerUnkStruct1;

typedef struct {
    /*0x00*/ u8 unk0;
    /*0x01*/ char unk1[17];
    /*0x12*/ char unk12[5];
} ControllerUnkStruct2;

/*.data*/
/*800E0F60*/ EXTERN_DATA STATIC char D_800E0F60[67];
/*800E0FA4*/ EXTERN_DATA STATIC char D_800E0FA4[30];
/*800E0FC4*/ EXTERN_DATA STATIC char D_800E0FC4[24];
/*800E0FDC*/ EXTERN_DATA STATIC char D_800E0FDC[17];
/*800E0FF0*/ EXTERN_DATA STATIC char D_800E0FF0[13];
/*800E1000*/ EXTERN_DATA STATIC char D_800E1000[28];
/*800E101C*/ EXTERN_DATA STATIC char D_800E101C[7];
/*800E1024*/ EXTERN_DATA STATIC char D_800E1024[8];
/*800E1038*/ EXTERN_DATA STATIC char D_800E1038[8];
/*800E1040*/ EXTERN_DATA STATIC char D_800E1040[10];
/*800E104C*/ EXTERN_DATA STATIC char D_800E104C[26];
/*800E1068*/ EXTERN_DATA STATIC char D_800E1068[21];
/*800E1080*/ EXTERN_DATA STATIC char D_800E1080[24];
/*800E1098*/ EXTERN_DATA STATIC char D_800E1098[14];
/*800E10A8*/ EXTERN_DATA STATIC char D_800E10A8[25];
/*800E10C4*/ EXTERN_DATA STATIC char D_800E10C4[27];
/*800E10E0*/ EXTERN_DATA STATIC char D_800E10E0[15];
/*800E10F0*/ EXTERN_DATA STATIC char D_800E10F0[21];
/*800E1108*/ EXTERN_DATA STATIC char D_800E1108[17];
/*800E111C*/ EXTERN_DATA STATIC char D_800E111C[22];
/*800E11CC*/ EXTERN_DATA STATIC char D_800E11CC[2];
/*800E1134*/ EXTERN_DATA STATIC char D_800E1134[34];
/*800E1158*/ EXTERN_DATA STATIC char D_800E1158[12];
/*800E1164*/ EXTERN_DATA STATIC char D_800E1164[14];
/*800E1174*/ EXTERN_DATA STATIC char D_800E1174[32];
/*800E1194*/ EXTERN_DATA STATIC char D_800E1194[30];
/*800E11B4*/ EXTERN_DATA STATIC char D_800E11B4[21];
/*800E11D0*/ EXTERN_DATA STATIC char D_800E11D0[26];
/*800E11EC*/ EXTERN_DATA STATIC char D_800E11EC[24];
/*800E1204*/ EXTERN_DATA STATIC char D_800E1204[17];
/*800E1218*/ EXTERN_DATA STATIC char D_800E1218[25];
/*800E1234*/ EXTERN_DATA STATIC char D_800E1234[26];
/*800E1250*/ EXTERN_DATA STATIC char D_800E1250[16];
/*800E1260*/ EXTERN_DATA STATIC char D_800E1260[27];
/*800E127C*/ EXTERN_DATA STATIC char D_800E127C[26];
/*800E1298*/ EXTERN_DATA STATIC char D_800E1298[31];
/*800E12B8*/ EXTERN_DATA STATIC char D_800E12B8[20];
/*800E12CC*/ EXTERN_DATA STATIC char D_800E12CC[32];
/*800E12EC*/ EXTERN_DATA STATIC char D_800E12EC[32];
/*800E130C*/ EXTERN_DATA STATIC char D_800E130C[34];
/*800E1330*/ EXTERN_DATA STATIC char D_800E1330[30];
/*800E1350*/ EXTERN_DATA STATIC char D_800E1350[9];
/*800E135C*/ EXTERN_DATA STATIC char D_800E135C[18];
/*800E1370*/ EXTERN_DATA STATIC char D_800E1370[22];
/*800E1388*/ EXTERN_DATA STATIC char D_800E1388[16];
/*800E1398*/ EXTERN_DATA STATIC char D_800E1398[11];
/*800E13A4*/ EXTERN_DATA STATIC char D_800E13A4[25];
/*800E1478*/ EXTERN_DATA STATIC char D_800E1478[27];
/*800E1494*/ EXTERN_DATA STATIC char D_800E1494[33];
/*800E14B8*/ EXTERN_DATA STATIC char D_800E14B8[34];
/*800E14DC*/ EXTERN_DATA STATIC char D_800E14DC[25];
/*800E14F8*/ EXTERN_DATA STATIC char D_800E14F8[24];
/*800E1510*/ EXTERN_DATA STATIC char D_800E1510[35];
/*800E1534*/ EXTERN_DATA STATIC char D_800E1534[14];
/*800E1544*/ EXTERN_DATA STATIC char D_800E1544[35];
/*800E1568*/ EXTERN_DATA STATIC char D_800E1568[33];
/*800E158C*/ EXTERN_DATA STATIC char D_800E158C[6];
/*800E1594*/ EXTERN_DATA STATIC char D_800E1594[14];
/*800E15A4*/ EXTERN_DATA STATIC char D_800E15A4[11];
/*800E15B0*/ EXTERN_DATA STATIC char D_800E15B0[18];
/*800E15C4*/ EXTERN_DATA STATIC char D_800E15C4[18];
/*800E15D8*/ EXTERN_DATA STATIC char D_800E15D8[22];
/*800E15F0*/ EXTERN_DATA STATIC char D_800E15F0[18];
/*800E1604*/ EXTERN_DATA STATIC char D_800E1604[19];
/*800E1618*/ EXTERN_DATA STATIC char D_800E1618[35];
/*800E163C*/ EXTERN_DATA STATIC char D_800E163C[20];
/*800E1650*/ EXTERN_DATA STATIC char D_800E1650[5];
/*800E1658*/ EXTERN_DATA STATIC char D_800E1658[14];
/*800E1668*/ EXTERN_DATA STATIC char D_800E1668[25];
/*800E1680*/ EXTERN_DATA STATIC u8 D_800E1680;
/*800E1681*/ EXTERN_DATA STATIC u8 D_800E1681;
/*800E1682*/ EXTERN_DATA STATIC u8 D_800E1682;
/*800E1683*/ EXTERN_DATA STATIC u8 D_800E1683;
/*800E1684*/ EXTERN_DATA STATIC u8 D_800E1684;
/*800E1685*/ EXTERN_DATA STATIC u8 D_800E1685;
/*800E1686*/ EXTERN_DATA STATIC u8 D_800E1686;
/*800E1688*/ EXTERN_DATA STATIC u8 D_800E1688;
/*800E1689*/ EXTERN_DATA STATIC u8 D_800E1689;
/*800E168A*/ EXTERN_DATA STATIC u8 D_800E168A;
/*800E168B*/ EXTERN_DATA STATIC u8 D_800E168B;
/*800E168C*/ EXTERN_DATA STATIC u8 D_800E168C;
/*800E168D*/ EXTERN_DATA STATIC u8 D_800E168D;
/*800E168E*/ EXTERN_DATA STATIC u8 D_800E168E;
/*800E168F*/ EXTERN_DATA STATIC u8 D_800E168F;
/*800E1690*/ EXTERN_DATA STATIC u8 D_800E1690;
/*800E1691*/ EXTERN_DATA STATIC u8 D_800E1691;

/*.bss*/
/*800F9CE4*/ EXTERN_BSS STATIC s32 D_800F9CE4;
/*800F9CE8*/ EXTERN_BSS STATIC s32 D_800F9CE8;
/*800F9CF8*/ EXTERN_BSS STATIC s32 D_800F9CF8;
/*800F9CFC*/ EXTERN_BSS STATIC u8 D_800F9CFC;
/*800F9D00*/ EXTERN_BSS STATIC s32 D_800F9D00;
/*800F9D04*/ EXTERN_BSS STATIC u8 D_800F9D04[MAXPLAYERS];
/*800F9D10*/ EXTERN_BSS STATIC OSMesgQueue _serialMsgQ;
/*800F9D28*/ EXTERN_BSS STATIC OSMesg _serialMsg;
/*800F9D30*/ EXTERN_BSS STATIC OSContStatus _statusData[MAXPLAYERS];
/*800F9D40*/ EXTERN_BSS STATIC OSContPad D_800F9D40[MAXPLAYERS];
/*800F9D58*/ EXTERN_BSS STATIC OSPfs _contPfs[MAXPLAYERS];
/*800F9EF8*/ EXTERN_BSS STATIC u8 D_800F9EF8[MAXPLAYERS];
/*800F9EFC*/ EXTERN_BSS STATIC u8 D_800F9EFC;
/*800F9EFD*/ EXTERN_BSS STATIC s8 D_800F9EFD;
/*800F9EFE*/ EXTERN_BSS STATIC s8 D_800F9EFE;
/*800F9EFF*/ EXTERN_BSS STATIC s8 _channel;
/*800F9F00*/ EXTERN_BSS STATIC s8 D_800F9F00;
/*800F9F01*/ EXTERN_BSS STATIC s8 D_800F9F01;
/*800F9F02*/ EXTERN_BSS STATIC s8 D_800F9F02;
/*800F9F08*/ EXTERN_BSS STATIC u8 D_800F9F08[16];
/*800F9F18*/ EXTERN_BSS STATIC u8 D_800F9F18[4];
/*800F9F1C*/ EXTERN_BSS STATIC s32 _fileSize;
/*800F9F20*/ EXTERN_BSS STATIC code1UnkStruct3 *_fileBuffer;
/*800F9F28*/ EXTERN_BSS STATIC char D_800F9F28[20];
/*800F9F3C*/ EXTERN_BSS STATIC s32 D_800F9F3C;
/*800F9F40*/ EXTERN_BSS STATIC s32 D_800F9F40;
/*800F9F44*/ EXTERN_BSS STATIC s32 D_800F9F44;
/*800F9F48*/ EXTERN_BSS STATIC s32 D_800F9F48;
/*800F9F50*/ EXTERN_BSS STATIC ControllerUnkStruct1 D_800F9F50[16];
/*800FA150*/ EXTERN_BSS STATIC ControllerUnkStruct2 D_800FA150[16];
/*800FA2C0*/ EXTERN_BSS STATIC s32 _fileNumber;
/*800FA2C4*/ EXTERN_BSS STATIC char D_800FA2C4[5];
/*800FA2C9*/ EXTERN_BSS STATIC u8 D_800FA2C9;
/*800FA2CA*/ EXTERN_BSS STATIC u16 D_800FA2CA[MAXPLAYERS];
/*800FA2D2*/ EXTERN_BSS STATIC s16 D_800FA2D2[MAXPLAYERS];
/*800FA2DA*/ EXTERN_BSS STATIC s16 D_800FA2DA[MAXPLAYERS];
/*800FA2E2*/ EXTERN_BSS STATIC u8 D_800FA2E2[MAXPLAYERS];
/*800FA2E6*/ EXTERN_BSS STATIC u16 D_800FA2E6[MAXPLAYERS];
/*800FA2EE*/ EXTERN_BSS STATIC u16 D_800FA2EE[MAXPLAYERS];
/*800FA2F6*/ EXTERN_BSS STATIC u8 D_800FA2F6;
/*800FA2F7*/ EXTERN_BSS STATIC u8 D_800FA2F7;
/*800FA2F8*/ EXTERN_BSS STATIC u8 D_800FA2F8;
/*800FA2FA*/ EXTERN_BSS STATIC s8 D_800FA2FA;
/*800FA2FB*/ EXTERN_BSS STATIC s8 D_800FA2FB;
/*800FA2FC*/ EXTERN_BSS STATIC u8 D_800FA2FC;
/*800FA300*/ EXTERN_BSS STATIC intptr_t _arg0;
/*800FA304*/ EXTERN_BSS STATIC intptr_t _arg1;
/*800FA308*/ EXTERN_BSS STATIC intptr_t _arg2;
/*800FA30C*/ EXTERN_BSS STATIC intptr_t _arg3;
/*800FA310*/ EXTERN_BSS STATIC intptr_t _arg4;
/*800FA314*/ EXTERN_BSS STATIC intptr_t _arg5;
/*800FA318*/ EXTERN_BSS STATIC intptr_t _arg6;
/*800FA31C*/ EXTERN_BSS STATIC s32 D_800FA31C;
/*800FA320*/ EXTERN_BSS STATIC s32 D_800FA320;
/*800FA328*/ EXTERN_BSS STATIC char D_800FA328[64];
/*800FA368*/ EXTERN_BSS STATIC char D_800FA368[72];

/*.comm*/
/*800FE408*/ s32 D_800FE408;
/*8010A93C*/ u8 D_8010A93C;
/*80119A70*/ u8 D_80119A70;
/*8012BBC8*/ u8 D_8012BBC8[MAXPLAYERS];
/*8013F928*/ u8 D_8013F928[8]; /*MAXPLAYERS?*/
/*80197D44*/ u8 D_80197D44[MAXPLAYERS];
/*8019956D*/ u8 D_8019956D[11]; /*MAXPLAYERS?*/
/*801A68A8*/ Controller gController[MAXPLAYERS] ALIGNED(8);
/*801A6D82*/ s8 D_801A6D82;

/*.text*/
STATIC s8 func_80089F14(s32, s32);
static u8 func_8008A370(u8, intptr_t, intptr_t, intptr_t,
                        intptr_t, intptr_t, intptr_t, intptr_t);
static u8 func_8008B8B0(void);
static s32 func_8008C0C8(void);
static u16 func_8008A2FC(u8 *, s32);

/*80087A90*/
static void func_80087A90(u8 contnum)
{
    if (__osMotorAccess(&_contPfs[contnum], 1) == 0)
        D_8019956D[contnum] |= 3;
}

/*80087B00*/
static void func_80087B00(u8 contnum)
{
    s32 i;

    for (i = 0; i < 3; i++)
        __osMotorAccess(&_contPfs[contnum], 0);

    D_8019956D[contnum] &= ~1;
}

/*80087B9C*/
static void func_80087B9C(u8 contnum)
{
    s32 i;

    if (osMotorInit(&_serialMsgQ, &_contPfs[contnum], contnum) == 0)
    {
        for (i = 0; i < 3; i++)
            __osMotorAccess(&_contPfs[contnum], 0);

        D_8019956D[contnum] &= 0xFC;
    }
    else
        D_80197D44[contnum] = 0;
}

/*80087C64*/
static u8 func_80087C64(void)
{
    s32 i, j;

    for (i = 0, j = 1; i < MAXPLAYERS; i++)
    {
        if (D_8016D174[i] != 0)
            j = (D_80197D44[i] != 0) ? j : 0;
    }
    return j;
}

/*80087CB0*/
static u8 func_80087CB0(void)
{
    s32 i;

    for (i = 0; i < MAXPLAYERS; i++)
    {
        if ((D_800FA2F8 == 0) || (i == D_801A6D82))
        {
            if (D_8016D174[i])
            {
                if (gController[i].button2 & CONT_START)
                    return 1;
            }
        }
    }
    return 0;
}

/*80087D24*/
static u8 func_80087D24(void)
{
    s32 ret;

    ret = 0;
    switch (D_800E1680)
    {
    case 0:
        func_8007FF94(D_800E11CC, 0xFF);
        func_8007FF94(D_800E1218, 0xFF);
        D_800E1680 = 1;
        break;
    case 1:
        if (func_80087CB0())
        {
            MusStartEffect(747);
            D_800E1680 = 2;
        }
        break;
    case 2:
        D_800E1680 = 0;
        ret = 1;
        break;
    }
    return ret;
}

/*80087DF4*/
static s8 func_80087DF4(void)
{

    if (gController[D_801A6D82].button2 & CONT_A)
        return 0;
    else
        return (gController[D_801A6D82].button2 & CONT_B) ? 1 : -1;
}

/*80087E30*/
static s8 func_80087E30(void)
{
    if (gController[D_801A6D82].button2 & CONT_A)
        return 0;
    else
    {
        if (gController[D_801A6D82].button2 & CONT_B)
            return 1;
        else
            return (gController[D_801A6D82].button2 & CONT_G) ? 2 : -1;
    }
}

/*80087E78*/
static void func_80087E78(char *arg0, u8 *arg1, u8 arg2)
{
    char *ptr;
    char space;

    arg0[arg2] = 0;

    if (arg2 != 0)
    {
        space = ' ';
        ptr = arg0;
        do
        {
            *ptr = space;
            ptr++;
        } while ((intptr_t)ptr < (arg2+(intptr_t)arg0));
    }

    ptr = arg0;
    if (arg2 != 0)
    {
        do
        {
            if (*arg1 != 0)
            {
                if (*arg1 < ARRAY_COUNT(D_800E0F60)-1)
                    *arg0 = D_800E0F60[*arg1];
                else
                    *arg0 = ' ';

                arg0++;
                arg1++;
            }
            else
                break;
        } while ((intptr_t)arg0 < (arg2+(intptr_t)ptr));
    }
}

/*80087EF4*/
static void func_80087EF4(char *arg0, u8 *arg1, u8 arg2)
{
    char *ptr;
    char space;

    arg0[arg2] = 0;

    if (*arg1 >= ARRAY_COUNT(D_800E0F60)-1)
    {
        sprintf(arg0, "%s", D_800E163C, &arg0[arg2]);
        return;
    }

    if (arg2 != 0)
    {
        space = ' ';
        ptr = arg0;
        do
        {
            *ptr = space;
            ptr++;
        } while ((intptr_t)ptr < arg2+(intptr_t)arg0);
    }

    ptr = arg0;
    if (arg2 != 0)
    {
        do
        {
            if (*arg1 != 0)
            {
                *arg0++ = D_800E0F60[*arg1];
                arg1++;
            }
            else
                break;

        } while ((intptr_t)arg0 < (arg2+(intptr_t)ptr));
    }
}

/*80087FA4*/
static void func_80087FA4(u8 *arg0, char *arg1, u8 arg2)
{
    u8 *ptr;
    u32 i;

    ptr = arg0;
    if (arg2 != 0)
    {
        do
        {
            if (*arg1 != 0)
            {
                for (i = 0; i < ARRAY_COUNT(D_800E0F60)-1; i++)
                {
                    if (D_800E0F60[i] == *arg1)
                        break;
                }

                if (i >= ARRAY_COUNT(D_800E0F60)-1)
                    i = 15;

                if (*arg1 == ' ')
                    i = 15;

                *arg0 = i;
                arg1++;
            }
            else
            {
                *arg0 = 15;
            }
            arg0++;
        } while ((intptr_t)arg0 < arg2+(intptr_t)ptr);
    }
}

/*8008802C*/
static void func_8008802C(void)
{
    D_800FA320 = 0;
}

/*8008803C*/
static void func_8008803C(char *arg0, s32 arg1)
{
    char car1;
    char car2;

    car1 = ' ';
    car2 = ' ';
    if (D_800FA320 == _fileNumber)
    {
        car2 = '>';
        car1 = '<';
    }
    sprintf(D_800FA328, "%c %s %c", car2, arg0, car1);
    if (car2 != '>')
    {
        if (arg1 != 0)
            func_8007FEDC(D_800FA328, 140);
        else
            func_8007FF94(D_800FA328, 140);
    }
    else if (arg1 != 0)
        func_8007FEDC(D_800FA328, 0xFF);
    else
        func_8007FF94(D_800FA328, 0xFF);

    D_800FA320++;
}

/*80088120*/
static void func_80088120(void)
{
    s32 i;

    func_8007FF94(D_800E11CC, 0xFF);
    func_8007FEDC(D_800E1134, 0xFF);
    func_8008802C();

    for (i = 0; i < ARRAY_COUNT(D_800FA150); i++)
    {
        if (D_800FA150[i].unk0 != 0)
        {
            sprintf(D_800FA368, "%2d: %16.16s.%4.4s %3d", i+1,
                    D_800FA150[i].unk1, D_800FA150[i].unk12,
                    D_800F9F50[i].unk0 / 256);
        }
        else
            sprintf(D_800FA368, "%2d: %s %4.4s    ",
                    i+1, D_800E1204, " ");

        func_8008803C(D_800FA368, 1);
    }
}

/*80088250*/
static u8 func_80088250(void)
{
    s32 ret;

    ret = 0;

    switch (D_800E1681)
    {
    case 0:
        D_800F9F02 = 0;
        D_8013F928[_channel] = 0;
        D_80197D44[_channel] = 0;
        D_800FA2FA = 0;
        func_8008A370(CONTROLLER_MOTOR_INIT, (intptr_t)&_contPfs[_channel], _channel, 0, 0, 0, 0, 0);
        D_800E1681 = 1;
        break;
    case 1:
        if (D_80119A70 == 0)
        {
            if (D_800FE408 != 0)
            {
                func_8008A370(CONTROLLER_PFS_INIT_PAK, (intptr_t)&_contPfs[_channel], _channel, 0, 0, 0, 0, 0);
                D_800E1681 = 2;
            }
            else
            {
                D_80197D44[_channel] = 1;
                D_800FA2FA = 1;
                D_800E1681 = 3;
            }
        }
        break;
    case 2:
        if (D_80119A70 == 0)
        {
            if (D_800FE408 == 0)
            {
                D_8013F928[_channel] = 1;
            }
            else
            {
                switch (D_800FE408)
                {
                case 2:
                    D_8013F928[_channel] = 1;
                    D_800F9F02 = 1;
                    D_800E1681 = 0;
                    break;
                case 10:
                    D_8013F928[_channel] = 1;
                    if (D_800F9EFE < 0)
                        D_800F9EFE = _channel;

                    D_800E1681 = 3;
                }
            }
            D_800E1681 = 3;
        }
        break;
    case 3:
        ret = 1;
        D_800E1681 = 0;
        break;
    }
    return ret;
}

/*800884C4*/
static u8 func_800884C4(void)
{
    s32 ret;

    D_800F9EFD = 0;

    ret = 0;
    switch (D_800E1682)
    {
    case 0:
        func_8008A370(CONTROLLER_PFS_INIT_PAK, (intptr_t)&_contPfs[_channel], _channel, 0, 0, 0, 0, 0);
        D_800E1682 = 1;
        break;
    case 1:
        if (D_80119A70 == 0)
            D_800E1682 = 2;
        break;
    case 2:
        D_800E1682 = 0;
        ret = 1;
        break;

    }

    return ret;
}

/*800885B0*/
static u8 func_800885B0(void)
{
    s32 ret;

    ret = 0;
    switch (D_800E1683)
    {
    case 0:
        func_800800A8(6);
        func_8007FF94(D_800E10F0, 0xFF);
        func_8007FF94(D_800E1108, 0xFF);
        sprintf(D_800FA368, "%d%s", D_800F9F3C, D_800E111C);
        func_8007FF94(D_800FA368, 0xFF);
        func_8007FF94(D_800E1510, 0xFF);
        func_8007FF94(D_800E11CC, 0xFF);
        func_8007FF94(D_800E15F0, 0xFF);
        func_8007FF94(D_800E1604, 0xFF);
        func_8007FF94(D_800E11CC, 0xFF);
        func_8007FF94(D_800E1618, 0xFF);
        D_800E1683 = 1;
        break;
    case 1:
        D_800F9CE4 = func_80087DF4();
        if (D_800F9CE4 >= 0)
        {
            MusStartEffect(747);
            if (D_800F9CE4 != 0)
            {
                D_800FE408 = -1;
                D_800E1683 = 3;
            }
            else
                D_800E1683 = 2;
        }
        break;
    case 2:
        if (func_8008B8B0())
            D_800E1683 = 3;
        break;
    case 3:
        func_80080060();
        D_800E1683 = 0;
        ret = 1;
        break;
    case 4:
        if (func_80087CB0())
            D_800E1683 = 3;
        break;
    }
    return ret;
}

/*80088760*/
static u8 func_80088760(void)
{
    s32 ret;

    ret = 0;
    switch (D_800E1684)
    {
    case 0:
        func_800800A8(6);
        func_8007FF94(D_800E10F0, 0xFF);
        func_8007FF94(D_800E1108, 0xFF);
        sprintf(D_800FA368, "%d%s", D_800F9F3C, D_800E111C);
        func_8007FF94(D_800FA368, 0xFF);
        func_8007FF94(D_800E1510, 0xFF);
        func_8007FF94(D_800E11CC, 0xFF);
        func_8007FF94(D_800E15F0, 0xFF);
        func_8007FF94(D_800E1604, 0xFF);
        func_8007FF94(D_800E11CC, 0xFF);
        func_8007FF94(D_800E1618, 0xFF);
        D_800E1684 = 1;
        break;
    case 1:
        D_800F9CE8 = func_80087DF4();
        if (D_800F9CE8 >= 0)
        {
            MusStartEffect(747);
            if (D_800F9CE8 != 0)
            {
                D_800FE408 = -1;
                D_800E1684 = 3;
            }
            else
                D_800E1684 = 2;
        }
        break;
    case 2:
        if (func_8008C0C8())
            D_800E1684 = 3;

        break;
    case 3:
        func_80080060();
        D_800E1684 = 0;
        ret = 1;
        break;
    case 4:
        if (func_80087CB0())
            D_800E1684 = 3;

        break;
    }
    return ret;
}

/*80088910*/
static u8 func_80088910(void)
{
    s32 ret;
    s8 i;

    ret = 0;
    switch (D_800E1685)
    {
    case 0:
        func_800800A8(8);
        switch (D_800FE408)
        {
        case 1:
            D_8013F928[_channel] = 0;
            D_80197D44[_channel] = 0;
            func_8007FF94(D_800E10A8, 0xFF);
            func_8007FF94(D_800E10C4, 0xFF);
            func_8007FF94(D_800E10E0, 0xFF);
            D_800E1685 = 1;
            break;
        case 2:
            func_8007FF94(D_800E104C, 0xFF);
            D_800E1685 = 1;
            break;
        case 7:
        case 8:
            D_800E1685 = 10;
            break;
        case 11:
            D_800E1685 = 40;
            break;
        case 3:
        case 4:
        case 5:
        case 6:
        case 9:
            D_800E1685 = 3;
            break;
        case 10:
            D_800E1685 = 3;
            break;
        default:
            D_800E1685 = 2;
            break;
        }
        break;
    case 1:
        if (func_80087D24())
            D_800E1685 = 2;
        break;
    case 2:
        ret = 1;
        func_80080060();
        D_800E1685 = 0;
        break;
    case 3:
        func_800800A8(6);
        func_8007FF94(D_800E12CC, 0xFF);
        func_8007FF94(D_800E12EC, 0xFF);
        func_8007FF94(D_800E130C, 0xFF);
        func_8007FF94(D_800E1000, 0xFF);
        func_8007FF94(D_800E1038, 0xFF);
        func_8007FF94(D_800E1040, 0xFF);
        D_800E1685 = 4;
        break;
    case 4:
        i = func_80087E30();
        if (i >= 0)
        {
            MusStartEffect(747);
            func_800800A8(6);
            if (i == 2)
                D_800E1685 = 36;

            else if (i == 0)
                D_800E1685 = 37;
            else
                D_800E1685 = 34;
        }
        break;
    case 5:
        if (D_80119A70 == 0)
        {
            if (D_800FE408 != 0)
            {
                func_8007FF94(D_800E1330, 0xFF);
                func_8007FF94(D_800E1350, 0xFF);
                D_800E1685 = 8;
            }
            else
            {
                func_8007FF94(D_800E135C, 0xFF);
                D_800E1685 = 1;
            }
        }
        break;
    case 8:
        func_8007FF94(D_800E1494, 0xFF);
        func_8007FF94(D_800E14B8, 0xFF);
        func_8007FF94(D_800E14DC, 0xFF);
        D_800E1685 = 11;
        break;
    case 11:
        if (func_80087CB0())
        {
            MusStartEffect(747);
            D_800E1685 = 2;
        }
        break;
    case 9:
        if (func_80088250())
        {
            if (D_800FE408 == 0)
                D_800E1685 = 2;
            else
                D_800E1685 = 0;
        }
        break;
    case 6:
        if (func_80088250())
        {
            if (D_800FA2FA == 0)
                D_800E1685 = 3;
            else
            {
                D_800FE408 = 1;
                D_800E1685 = 0;
            }
        }
        break;
    case 10:
        if (func_80088760())
            D_800E1685 = 2;
        break;
    case 34:
        if (func_800884C4())
        {
            if (D_800FE408 != 0xA)
            {
                if (((D_800FE408 ^ 2) == 0) | (D_800FE408 == 0))
                    D_800F9EFD = 1;
                D_800E1685 = 35;
            }
            else
            {
                func_8007FF94(D_800E1398, 0xFF);
                func_8007FF94(D_800E11CC, 0xFF);
                func_8008A370(CONTROLLER_PFS_REPAIR_ID, (intptr_t)&_contPfs[_channel], 0, 0, 0, 0, 0, 0);
                D_800E1685 = 5;
            }
        }
        break;
    case 35:
        if (func_80088250())
        {
            if (D_800FA2FA == 0)
            {
                if (D_800F9EFD != 0)
                    D_800FE408 = 2;

                D_800E1685 = 0;
            }
            else
                D_800E1685 = 2;
        }
        break;
    case 36:
        if (func_800884C4())
        {
            if (D_800FE408 == 10)
                D_800E1685 = 3;
            else
            {
                if (((D_800FE408 ^ 2) == 0) | (D_800FE408 == 0))
                    D_800F9EFD = 1;

                D_800E1685 = 35;
            }
        }
        break;
    case 37:
        if (func_800884C4())
        {
            if (D_800FE408 == 10)
                D_800E1685 = 2;
            else
            {
                if (D_800FE408 == 2)
                    D_800F9EFD = 1;

                D_800E1685 = 35;
            }
        }
        break;
    case 40:
        func_800800A8(6);
        func_8007FF94(D_800E1298, 0xFF);
        func_8007FF94(D_800E12B8, 0xFF);
        func_8007FF94(D_800E12CC, 0xFF);
        func_8007FF94(D_800E12EC, 0xFF);
        func_8007FF94(D_800E130C, 0xFF);
        func_8007FF94(D_800E1000, 0xFF);
        func_8007FF94(D_800E1038, 0xFF);
        func_8007FF94(D_800E1040, 0xFF);
        D_800E1685 = 41;
        break;
    case 41:
        i = func_80087E30();
        if (i >= 0)
        {
            MusStartEffect(747);
            func_800800A8(6);
            if (i == 2)
                D_800E1685 = 45;
            else if (i == 0)
                D_800E1685 = 43;
            else
                D_800E1685 = 44;
        }
        break;
    case 42:
        if (D_80119A70 == 0)
        {
            if (D_800FE408 != 0)
            {
                func_8007FF94(D_800E1330, 0xFF);
                func_8007FF94(D_800E1350, 0xFF);
                D_800E1685 = 8;
            }
            else
            {
                func_8007FF94(D_800E135C, 0xFF);
                D_800E1685 = 1;
            }
        }
        break;
    case 43:
        if (func_800884C4())
        {
            if (D_800FE408 == 11)
                D_800E1685 = 2;
            else
            {
                if (D_800FE408 == 2)
                    D_800F9EFD = 1;

                D_800E1685 = 35;
            }
        }
        break;
    case 44:
        if (func_800884C4())
        {
            if (D_800FE408 != 11)
            {
                if (((D_800FE408 ^ 2) == 0) | (D_800FE408 == 0))
                    D_800F9EFD = 1;

                D_800E1685 = 35;
            }
            else
            {
                func_8007FF94(D_800E1398, 0xFF);
                func_8007FF94(D_800E11CC, 0xFF);
                func_8008A370(CONTROLLER_PFS_REPAIR_ID, (intptr_t)&_contPfs[_channel], 0, 0, 0, 0, 0, 0);
                D_800E1685 = 5;
            }
        }
        break;
    case 45:
        if (func_800884C4())
        {
            if (D_800FE408 == 11)
                D_800E1685 = 40;
            else
            {
                if (((D_800FE408 ^ 2) == 0) | (D_800FE408 == 0))
                    D_800F9EFD = 1;

                D_800E1685 = 35;
            }
        }
        break;
    }
    return ret;
}

/*80088FEC*/
static u8 func_80088FEC(void)
{
    s32 ret;
    s32 i;

    ret = 0;
    switch (D_800E1686)
    {
    case 0:
        func_800800A8(8);
        switch (D_800FE408)
        {
        case 1:
            func_8007FF94(D_800E1478, 0xFF);
            func_8007FF94(D_800E1494, 0xFF);
            func_8007FF94(D_800E14B8, 0xFF);
            func_8007FF94(D_800E14DC, 0xFF);
            D_800FE408 = -1;
            D_800E1686 = 9;
            break;
        case 2:
            func_8007FF94(D_800E104C, 0xFF);
            D_800FE408 = 0;
            D_800E1686 = 1;
            break;
        case 11:
            D_800E1686 = 40;
            break;
        case 7:
        case 8:
            D_800E1686 = 10;
            break;
        case 9:
            D_800E1686 = 2;
            break;
        case 3:
        case 4:
        case 5:
        case 6:
            func_8007FF94(D_800E14F8, 0xFF);
            func_8007FF94(D_800E1494, 0xFF);
            func_8007FF94(D_800E14B8, 0xFF);
            func_8007FF94(D_800E14DC, 0xFF);
            D_800FE408 = -1;
            D_800E1686 = 9;
            break;
        case 10:
            D_800E1686 = 3;
            break;
        default:
            D_800E1686 = 2;
            break;
        }
        break;
    case 1:
        if (func_80087D24())
            D_800E1686 = 2;
        break;
    case 2:
        ret = 1;
        func_80080060();
        D_800E1686 = 0;
        break;
    case 3:
        if (func_80088250())
        {
            if (D_800FA2FA == 0)
            {
                func_800800A8(6);
                func_8007FF94(D_800E12CC, 0xFF);
                func_8007FF94(D_800E12EC, 0xFF);
                func_8007FF94(D_800E130C, 0xFF);
                func_8007FF94(D_800E1000, 0xFF);
                func_8007FF94(D_800E1038, 0xFF);
                func_8007FF94(D_800E1040, 0xFF);
                D_800E1686 = 4;
            }
            else
                D_800E1686 = 2;
        }
        break;
    case 4:
        i = func_80087E30();
        if (i >= 0)
        {
            MusStartEffect(747);
            func_800800A8(6);
            if (i == 2)
                D_800E1686 = 36;
            else if (i == 0)
                D_800E1686 = 37;
            else
                D_800E1686 = 34;
        }
        break;
    case 5:
        if (D_80119A70 == 0)
        {
            if (D_800FE408 != 0)
            {
                func_8007FF94(D_800E1330, 0xFF);
                func_8007FF94(D_800E1350, 0xFF);
                D_800E1686 = 8;
            }
            else
            {
                func_8007FF94(D_800E135C, 0xFF);
                D_800FE408 = 0;
                D_800E1686 = 1;
            }
        }
        break;
    case 8:
        func_8007FF94(D_800E1494, 0xFF);
        func_8007FF94(D_800E14B8, 0xFF);
        func_8007FF94(D_800E14DC, 0xFF);
        D_800FE408 = -1;
        D_800E1686 = 9;
        break;
    case 9:
        if (func_80087CB0())
        {
            MusStartEffect(747);
            D_800E1686 = 2;
        }
        break;
    case 6:
        if (func_80088250())
        {
            if (D_800FE408 == 0)
                D_800E1686 = 2;
            else
                D_800E1686 = 0;
        }
        break;
    case 10:
        if (func_800885B0())
            D_800E1686 = 2;
        break;
    case 34:
        if (func_800884C4())
        {
            if (D_800FE408 != 0xA)
            {
                if (((D_800FE408 ^ 2) == 0) | (D_800FE408 == 0))
                    D_800F9EFD = 1;

                D_800E1686 = 35;
            }
            else
            {
                func_8007FF94(D_800E1398, 0xFF);
                func_8007FF94(D_800E11CC, 0xFF);
                func_8008A370(CONTROLLER_PFS_REPAIR_ID, (intptr_t)&_contPfs[_channel], 0, 0, 0, 0, 0, 0);
                D_800E1686 = 5;
            }
        }
        break;
    case 35:
        if (func_80088250())
        {
            if (D_800FA2FA == 0)
            {
                if (D_800F9EFD != 0)
                    D_800FE408 = 2;

                D_800E1686 = 0;
            }
            else
                D_800E1686 = 2;
        }
        break;
    case 36:
        if (func_800884C4())
        {
            if (D_800FE408 == 10)
                D_800E1686 = 3;
            else
            {
                if (((D_800FE408 ^ 2) == 0) | (D_800FE408 == 0))
                    D_800F9EFD = 1;

                D_800E1686 = 35;
            }
        }
        break;
    case 37:
        if (func_800884C4())
        {
            if (D_800FE408 == 10)
                D_800E1686 = 2;
            else
            {
                if (D_800FE408 == 2)
                    D_800F9EFD = 1;

                D_800E1686 = 35;
            }
        }
        break;
    case 40:
        func_800800A8(6);
        func_8007FF94(D_800E1298, 0xFF);
        func_8007FF94(D_800E12B8, 0xFF);
        func_8007FF94(D_800E12CC, 0xFF);
        func_8007FF94(D_800E12EC, 0xFF);
        func_8007FF94(D_800E130C, 0xFF);
        func_8007FF94(D_800E1000, 0xFF);
        func_8007FF94(D_800E1038, 0xFF);
        func_8007FF94(D_800E1040, 0xFF);
        D_800E1686 = 41;
        break;
    case 41:
        i = func_80087E30();
        if (i >= 0)
        {
            MusStartEffect(747);
            func_800800A8(6);
            if (i == 2)
                D_800E1686 = 45;
            else if (i == 0)
                D_800E1686 = 43;
            else
                D_800E1686 = 44;
        }
        break;
    case 42:
        if (D_80119A70 == 0)
        {
            if (D_800FE408 != 0)
            {
                func_8007FF94(D_800E1330, 0xFF);
                func_8007FF94(D_800E1350, 0xFF);
                D_800E1686 = 8;
            }
            else
            {
                func_8007FF94(D_800E135C, 0xFF);
                D_800E1686 = 1;
            }
        }
        break;
    case 43:
        if (func_800884C4())
        {
            if (D_800FE408 == 11)
                D_800E1686 = 2;
            else
            {
                if (D_800FE408 == 2)
                    D_800F9EFD = 1;

                D_800E1686 = 35;
            }
        }
        break;
    case 44:
        if (func_800884C4())
        {
            if (D_800FE408 != 11)
            {
                if (((D_800FE408 ^ 2) == 0) | (D_800FE408 == 0))
                    D_800F9EFD = 1;

                D_800E1686 = 35;
            }
            else
            {
                func_8007FF94(D_800E1398, 0xFF);
                func_8007FF94(D_800E11CC, 0xFF);
                func_8008A370(CONTROLLER_PFS_REPAIR_ID, (intptr_t)&_contPfs[_channel], 0, 0, 0, 0, 0, 0);
                D_800E1686 = 5;
            }
        }
        break;
    case 45:
        if (func_800884C4())
        {
            if (D_800FE408 == 11)
                D_800E1686 = 40;
            else
            {
                if (((D_800FE408 ^ 2) == 0) | (D_800FE408 == 0))
                    D_800F9EFD = 1;

                D_800E1686 = 35;
            }
        }
        break;
    }
    return ret;
}

extern const char D_800E93B4[];
INCLUDE_RODATA("nonmatchings/src/code0/controller", D_800E93B4); /*TODO: mutualized rodata*/

STATIC u8 func_80089724(void);
INCLUDE_ASM("nonmatchings/src/code0/controller", func_80089724);

/*80089CF4*/
static s32 func_80089CF4(s32 arg0)
{
    if (D_800FA150[arg0].unk0 == 0)
        return 0;

    if (D_800F9F50[arg0].game_code != 0x4E445A45) /*NDZE*/
        return 0;

    if (D_800F9F50[arg0].company_code != 0x3458) /*4X*/
        return 0;

    if (D_800FA2C9 != 0)
        return 1;

    if (strcmp(D_800FA150[arg0].unk1, D_800F9F28) == 0)
    {
        if (strcmp(D_800FA150[arg0].unk12, D_800E93B4) == 0)
            return 1;
    }

    return 0;
}

/*80089DCC*/
static u8 func_80089DCC(void)
{
    s32 ret;

    ret = 0;
    switch (D_800E1688)
    {
    case 0:
        func_8008A370(CONTROLLER_PFS_READ_WRITE_FILE,
                      (intptr_t)&_contPfs[_channel],
                      _fileNumber,
                      0,
                      0,
                      _fileSize,
                      (intptr_t)_fileBuffer,
                      0);
        D_800E1688 = 1;
        break;
    case 1:
        if (D_80119A70 == 0)
        {
            if (D_800FE408 == 0)
            {
                if ((func_8008A2FC((u8 *)&_fileBuffer->unk2, _fileSize-2)) != _fileBuffer->unk0)
                    D_800FE408 = -1;

            }
            D_800E1688 = 2;
        }
        break;
    case 2:
        D_800E1688 = 0;
        ret = 1;
        break;
    }

    return ret;
}

INCLUDE_ASM("nonmatchings/src/code0/controller", func_80089F14);

/*8008A070*/
u8 controller_8008A070(void)
{
    u8 ret;

    ret = 0;
    switch (D_800E1689)
    {
    case 0:
        D_800F9F01 = 0;
        func_8008A370(CONTROLLER_GET_STATUS, 0, 0, 0, 0, 0, 0, 0);
        D_800E1689 = 1;
        break;
    case 1:
        if (D_80119A70 == 0)
        {
            D_800F9F00 = -1;
            _channel = 0;
            D_800F9CF8 = -1;
            D_800F9EFE = -1;
            D_800E1689 = 2;
        }
        break;
    case 2:
        D_8012BBC8[_channel] = D_8013F928[_channel] = D_80197D44[_channel] = 0;

        if ((_statusData[_channel].errno == 0) &&
           ((_statusData[_channel].type & 5) == 5) &&
           ((_statusData[_channel].status & 4) == 0))
        {
            D_8012BBC8[_channel] = 1;
            if (_statusData[_channel].status & 1)
            {
                D_800E1689 = 3;
                break;
            }
        }
        D_800E1689 = 4;
        break;
    case 3:
        if (func_80088250())
        {
            if (D_800FA2FA == 0)
            {
                if (D_800F9CF8 < 0)
                {
                    D_800F9CF8 = _channel;
                    if (D_800F9F02 != 0)
                        D_800F9F01 = 1;
                }
            }
            else if (D_800F9F00 < 0)
                D_800F9F00 = _channel;

            D_800E1689 = 4;
        }
        break;
    case 4:
        _channel++;
        if (_channel < 4)
            D_800E1689 = 2;
        else
        {
            ret = 1;
            D_800E1689 = 0;
            _channel = D_800F9CF8;
        }
    }
    return ret;
}

/*8008A2FC*/
static u16 func_8008A2FC(u8 *arg0, s32 arg1)
{
    u32 i, j, k;

    if (arg1 == 0)
        return 0;

    for (j = 0xFFFF; arg1 != 0; arg1--)
    {
        for (i = 0, k = *arg0++; i < 8; i++)
        {
            if ((j & 1) != (k & 1))
                j = (j >> 1) ^ 0x8408;
            else
                j >>= 1;
            k >>= 1;
        }
    }
    j = ~j;
    j = ((j << 8) | ((j >> 8) & 0xFF));
    return j;
}

/*8008A370*/
static u8 func_8008A370(u8 arg0, intptr_t arg1, intptr_t arg2, intptr_t arg3,
                        intptr_t arg4, intptr_t arg5, intptr_t arg6, intptr_t arg7)
{
    if (D_80119A70 == 0)
    {
        _arg0 = arg1;
        _arg1 = arg2;
        _arg2 = arg3;
        _arg3 = arg4;
        _arg4 = arg5;
        _arg5 = arg6;
        _arg6 = arg7;
        D_800FE408 = 0;
        D_80119A70 = arg0;
        D_800FA2FC = arg0;
        return 1;
    }
    return 0;
}

/*8008A3EC*/
void controller_8008A3EC(char *arg0, code1UnkStruct3 *arg1, s32 arg2)
{
    u8 buf[32];
    char *ptr;
    s32 i;

    _fileBuffer = arg1;
    i = arg2 + 0xFF;

    if (i < 0)
        i = arg2 + 0x1FE;

    i >>= 8;
    i <<= 8;
    _fileSize = i;
    D_800F9F3C = i / 256;
    sprintf(D_800F9F28, "%s", arg0);
    D_800FA2C9 = 0;
    ptr = strchr(D_800F9F28, '.');
    if (ptr != NULL)
    {
        *ptr = 0;
        D_800FA2C9 = 1;
    }
    func_80087FA4(buf, D_800F9F28, 16);
    func_80087E78(D_800F9F28, buf, 16);
}

/*8008A4AC*/
static void func_8008A4AC(u8 arg0, u8 arg1)
{
    D_800F9EF8[arg0] = arg1;
}

/*8008A4C4*/
void controller_8008A4C4(u8 playernum, u16 arg1, u8 arg2)
{
    if (playernum < 4)
    {
        if ((D_80197D44[playernum] != 0) && (D_800FA2EE[playernum] == 0))
        {
            D_800FA2E2[playernum] = arg2;
            D_800FA2CA[playernum] = arg1;
            D_800FA2DA[playernum] = 0;
            D_800FA2E6[playernum] = 0;
        }
    }
}

/*8008A534*/
static void func_8008A534(u8 playernum, u16 arg1, u8 arg2)
{
    if ((playernum < 4) && (D_80197D44[playernum] != 0) && (D_800FA2EE[playernum] == 0))
    {
        if (arg2)
            D_800FA2E2[playernum] = arg2;

        if (arg1)
            D_800FA2CA[playernum] = arg1;
    }
}

/*8008A59C*/
static void func_8008A59C(u8 playernum)
{
    if ((playernum < 4) && (D_80197D44[playernum] != 0))
    {
        D_800FA2CA[playernum] = 0;
        D_800FA2E6[playernum] = 0;
    }
}

/*8008A5E0*/
static void func_8008A5E0(void)
{
    u8 i;

    for (i = 0; i < MAXPLAYERS; i++)
    {
        D_800FA2D2[i] = D_800FA2CA[i];
        func_8008A59C(i);
    }
}

/*8008A654*/
void controller_8008A654(void)
{
    u8 i;

    for (i = 0; i < MAXPLAYERS; i++)
    {
        if (D_80197D44[i] != 0)
        {
            D_800FA2CA[i] = 0;
            D_800FA2E6[i] = 0;
            D_800FA2EE[i] = 0;
            D_8019956D[i] = 2;
        }
    }
}

/*8008A6CC*/
static void func_8008A6CC(void)
{
    u8 i;

    for (i = 0; i < MAXPLAYERS; i++)
    {
        if (D_80197D44[i] != 0)
            D_800FA2CA[i] = D_800FA2D2[i];
    }
}

/*8008A724*/
void controller_8008A724(void)
{
    s32 i;

    if (D_800FA2F6 != 0)
    {
        osRecvMesg(&_serialMsgQ, NULL, 1);
        osContGetReadData(D_800F9D40);

        for (i = 0; i < MAXPLAYERS; i++)
        {
            gController[i].stick_x = D_800F9D40[i].stick_x;
            gController[i].stick_y = D_800F9D40[i].stick_y;

            if ((D_800F9EF8[i] != 0) || (D_800F9EFC != 0))
            {
                if (gController[i].stick_x < -30)
                    D_800F9D40[i].button |= CONT_LEFT;

                if (gController[i].stick_x > 30)
                    D_800F9D40[i].button |= CONT_RIGHT;

                if (gController[i].stick_y < -31)
                    D_800F9D40[i].button |= CONT_DOWN;

                if (gController[i].stick_y > 31)
                    D_800F9D40[i].button |= CONT_UP;

            }

            if ((D_800F9D40[i].button & (CONT_LEFT|CONT_RIGHT)) == (CONT_LEFT|CONT_RIGHT))
                D_800F9D40[i].button ^= (CONT_LEFT|CONT_RIGHT);

            if ((D_800F9D40[i].button & (CONT_DOWN|CONT_UP)) == (CONT_DOWN|CONT_UP))
                D_800F9D40[i].button ^= (CONT_DOWN|CONT_UP);


            gController[i].button2 = D_800F9D40[i].button & (gController[i].button ^ D_800F9D40[i].button);
            gController[i].button = D_800F9D40[i].button;

            if (D_80197D44[i] != 0)
            {
                if (D_800FA2EE[i] != 0)
                    D_800FA2EE[i]--;

                if (D_800FA2CA[i] == 0)
                {
                    if (D_8019956D[i] & 2)
                        func_80087B9C(i);
                }
                else
                {
                    D_800FA2E6[i]++;
                    if (D_800FA2E6[i] >= 600)
                    {
                        func_8008A59C(i);
                        D_800FA2EE[i] = 60;
                    }
                    else
                    {
                        D_800FA2CA[i]--;
                        D_800FA2DA[i] -= D_800FA2E2[i];
                        if (D_800FA2DA[i] < 0)
                        {
                            D_800FA2DA[i] += 256;
                            if (!(D_8019956D[i] & 1))
                                func_80087A90(i);
                        }
                        else
                        {
                            if (D_8019956D[i] & 1)
                                func_80087B00(i);
                        }
                    }
                }
            }
        }

        switch (D_80119A70)
        {
        case CONTROLLER_EEPROM_LONG_READ:
            osEepromLongRead(&_serialMsgQ,
                             _arg0,
                             (u8 *)_arg1,
                             _arg2);
            break;
        case CONTROLLER_EEPROM_LONG_WRITE:
            osEepromLongWrite(&_serialMsgQ,
                              _arg0,
                              (u8 *)_arg1,
                              _arg2);
            break;
        case CONTROLLER_PFS_NUM_FILES:
            D_800FE408 = osPfsNumFiles((OSPfs *)_arg0,
                                       (s32 *)_arg1,
                                       (s32 *)_arg2);
            break;
        case CONTROLLER_PFS_FREE_BLOCKS:
            D_800FE408 = osPfsFreeBlocks((OSPfs *)_arg0,
                                         (s32 *)_arg1);
            break;
        case CONTROLLER_PFS_FILE_STATE:
            D_800FE408 = osPfsFileState((OSPfs *)_arg0,
                                        _arg1,
                                        (OSPfsState *)_arg2);
            break;
        case CONTROLLER_PFS_DELETE_FILE:
            D_800FE408 = osPfsDeleteFile((OSPfs *)_arg0,
                                         _arg1,
                                         (u32)_arg2,
                                         (u8 *)_arg3,
                                         (u8 *)_arg4);
            break;
        case CONTROLLER_PFS_INIT_PAK:
            D_800FE408 = osPfsInitPak(&_serialMsgQ,
                                      (OSPfs *)_arg0,
                                      _arg1);
            break;
        case CONTROLLER_PFS_REPAIR_ID:
            D_800FE408 = osPfsRepairId((OSPfs *)_arg0);
            break;
        case CONTROLLER_PFS_READ_WRITE_FILE:
            D_800FE408 = osPfsReadWriteFile((OSPfs *)_arg0,
                                            _arg1,
                                            _arg2,
                                            _arg3,
                                            _arg4,
                                            (u8 *)_arg5);
            break;
        case CONTROLLER_PFS_ALLOCATE_FILE:
            D_800FE408 = osPfsAllocateFile((OSPfs *)_arg0,
                                           _arg1,
                                           (u32)_arg2,
                                           (u8 *)_arg3,
                                           (u8 *)_arg4,
                                           (s32)_arg5,
                                           (s32 *)_arg6);
            break;
        case CONTROLLER_PFS_FIND_FILE:
            D_800FE408 = osPfsFindFile((OSPfs *)_arg0,
                                       _arg1,
                                       (u32)_arg2,
                                       (u8 *)_arg3,
                                       (u8 *)_arg4,
                                       (s32 *)_arg5);
            break;
        case CONTROLLER_MOTOR_INIT:
            D_800FE408 = osMotorInit(&_serialMsgQ,
                                     (OSPfs *)_arg0,
                                     _arg1);
            break;
        case CONTROLLER_GET_STATUS:
            D_800FE408 = osContStartQuery(&_serialMsgQ);
            osRecvMesg(&_serialMsgQ, NULL, 1);
            osContGetQuery(_statusData);
            break;
        }
        D_80119A70 = 0;
        osContStartReadData(&_serialMsgQ);
    }
}

/*8008AD94*/
u8 controller_8008AD94(void)
{
    u8 pattern;
    s32 i;

    i = 0;
    D_800FA2F6 = 0;
    D_80138620 = 0;
    D_800FA2F8 = 0;
    D_80119A70 = 0;
    D_801A6D82 = 0;
    _fileSize = 0;

    for (i = 0; i < MAXPLAYERS; i++)
    {
        D_800F9EF8[i] = 0;
        D_800F9EFC = 0;
        D_80197D44[i] = 0;
        D_800FA2CA[i] = 0;
        D_800FA2E6[i] = 0;
        D_800FA2EE[i] = 0;
        D_8019956D[i] = 2;
    }
    osCreateMesgQueue(&_serialMsgQ, &_serialMsg, 1);
    osSetEventMesg(OS_EVENT_SI, &_serialMsgQ, (OSMesg)1);
    D_800FA2FB = osContInit(&_serialMsgQ, &pattern, _statusData);
    D_8010A93C = osEepromProbe(&_serialMsgQ);
    osContStartReadData(&_serialMsgQ);
    D_800FA2F6 = 1;
    controller_8008A724();
    D_800FA2F7 = 0;

    if (gController[0].button & CONT_START)
        D_800FA2F7 = 1;

    return pattern;
}

/*8008AEF0*/
u8 controller_8008AEF0(void)
{
    u8 ret;

    ret = 0;
    switch (D_800E168A)
    {
    case 0:
        if (D_800FA2FB != 0)
        {
            func_800800A8(6);
            func_8007FF94(D_800E1080, 0xFF);
            D_800E168A = 2;
        }
        else
        {
            if (D_801B0815 == 0)
            {
                if ((gController[0].button & (CONT_R|CONT_L|CONT_A|CONT_B|CONT_G)) != (CONT_R|CONT_L|CONT_A|CONT_B|CONT_G))
                {
                    func_800800A8(9);
                    func_8007FF94(D_800E11D0, 0xFF);
                    func_8007FF94(D_800E11EC, 0xFF);
                    D_800E168A = 2;
                }
                else
                    D_800E168A = 1;
            }
            else
                D_800E168A = 1;
        }
        break;
    case 1:
        if (controller_8008A070())
        {
            for (D_800F9D00 = 0; D_800F9D00 < MAXPLAYERS; D_800F9D00++)
                D_8016D174[D_800F9D00] = D_8012BBC8[D_800F9D00];

            if (D_8016D174[0] == 0)
            {
                func_800800A8(10);
                func_8007FF94(D_800E1098, 0xFF);
                func_8007FF94(D_800E11CC, 0xFF);
                D_800E168A = 2;
            }
            else if (_fileSize != 0)
            {
                if (_channel < 0)
                {
                    func_800800A8(6);
                    func_8007FF94(D_800E1478, 0xFF);
                    func_8007FF94(D_800E1494, 0xFF);
                    func_8007FF94(D_800E14B8, 0xFF);
                    func_8007FF94(D_800E14DC, 0xFF);
                    D_800FA31C = 7200;
                    D_800E168A = 4;
                    D_800F9CFC = 3;
                }
                else
                    D_800E168A = 14;
            }
            else
                D_800E168A = 3;
        }
        break;
    case 3:
        D_800E168A = 15;
        break;
    case 15:
        D_800E168A = 16;
        break;
    case 16:
        D_800FA2F8 = 1;
        D_800E168A = 0;
        ret = 1;
        break;
    case 4:
        if (func_80087CB0() || (D_800FA31C <= 0))
        {
            func_800800A8(6);
            D_800E168A = D_800F9CFC;
        }
        break;
    case 5:
        if (D_800FA2F7 == 0)
            D_800E168A = 8;
        else
            D_800E168A = 6;
        break;
    case 6:
        if (func_8008B8B0())
            D_800E168A = 7;
        break;
    case 7:
        if (D_800FA2FA == 0)
        {
            if (D_800FE408 == 0)
                D_800E168A = 8;
            else
                D_800E168A = 3;
        }
        else
            D_800E168A = 3;
        break;
    case 8:
        if (func_80089724())
        {
            if (D_800FE408 != 0)
                D_800E168A = 3;
            else
                D_800E168A = 9;
        }
        break;
    case 9:
        if (D_800F9F44 < D_800F9F40)
        {
            if (D_800F9F48 >= _fileSize)
                D_800E168A = 3;
            else
                D_800E168A = 20;
        }
        else
            D_800E168A = 20;
        break;
    case 20:
        if (func_800885B0())
        {
            if (D_800FE408 == 0)
                D_800E168A = 8;
            else
                D_800E168A = 3;
        }
        break;
    case 21:
        D_800E168A = 3;
        break;
    case 14:
        func_8008A370(CONTROLLER_PFS_INIT_PAK, (intptr_t)&_contPfs[_channel], _channel, 0, 0, 0, 0, 0);
        D_800E168A = 11;
        break;
    case 11:
        if (D_80119A70 == 0)
        {
            if (D_800FE408 == 0)
                D_800E168A = 5;
            else
                D_800E168A = 12;
        }
        break;
    case 12:
        if (func_80088FEC())
        {
            if (D_800FE408 == 0)
                D_800E168A = 1;
            else
                D_800E168A = 3;
        }
        break;
    case 13:
        if (func_80089DCC())
        {
            if (D_800FE408 == 0)
                D_80138620 = 1;

            D_800E168A = 9;
        }
        break;
    }
    D_800FA31C -= 1;
    return ret;
}

/*8008B354*/
static s32 func_8008B354(void)
{
    while (1)
    {
        if (D_80119A70 != 0)
            controller_8008A724();
        else
            break;
    }

    return D_800FE408;
}

/*8008B394*/
static u8 func_8008B394(s32 arg0)
{
    u8 i, j;
    s32 ret, k;

    if (arg0 == 0)
        return 1;

    ret = 0;
    switch (D_800E168B)
    {
    case 0:
        if (controller_8008A070())
            D_800E168B = 1;
        break;
    case 1:
        j = 0;
        i = 0;
        for (i = 0; i < MAXPLAYERS; i++)
        {
            if (D_80197D44[i] != D_800F9D04[i])
                j = 1;

            D_800F9D04[i] = D_80197D44[i];
        }

        if (D_800E168C == 0)
        {
            D_800E168C = 1;
            j = 1;
        }

        if (j != 0)
        {
            func_800800A8(6);
            func_8007FF94(D_800E0FA4, 0xFF);
            func_8007FF94(D_800E0FC4, 0xFF);
            func_8007FF94(D_800E0FDC, 0xFF);
            func_8007FF94(D_800E11CC, 0xFF);
            func_8007FF94(D_800E1218, 0xFF);
            D_800E168B = 2;
        }
        else
            D_800E168B = 3;
        break;
    case 2:
        i = D_800FA2F8;
        D_800FA2F8 = 0;
        k = func_80087CB0();
        D_800FA2F8 = i;
        if (k != 0)
        {
            MusStartEffect(747);
            D_800E168B = 3;
        }
        break;
    case 3:
        ret = 1;
        func_80080060();
        D_800E168B = 0;
        break;
    }
    return ret;
}

/*8008B574*/
static u8 func_8008B574(void)
{
    s32 ret;

    ret = 0;
    switch (D_800E168D)
    {
    case 0:
        func_80087FA4(D_800F9F08, D_800F9F28, 16);
        func_80087FA4(D_800F9F18, D_800FA2C4, 4);
        *((s16 *)_fileBuffer) = func_8008A2FC((u8 *)&_fileBuffer->unk2, _fileSize - 2); /*FAKEMATCH?*/

        if (D_800FA150[_fileNumber].unk0 != 0)
        {
            func_8008A370(CONTROLLER_PFS_READ_WRITE_FILE,
                          (intptr_t)&_contPfs[_channel],
                          _fileNumber,
                          1,
                          0,
                          _fileSize,
                          (intptr_t)_fileBuffer,
                          0);
            D_800E168D = 5;
        }
        else
            D_800E168D = 2;
        break;
    case 2:
        func_8008A370(CONTROLLER_PFS_ALLOCATE_FILE,
                      (intptr_t)&_contPfs[_channel],
                      0x3458,
                      0x4E445A45,
                      (intptr_t)&D_800F9F08,
                      (intptr_t)&D_800F9F18,
                      _fileSize,
                      (intptr_t)&_fileNumber);
        D_800E168D = 3;
        break;
    case 3:
        if (D_80119A70 == 0)
        {
            if (D_800FE408 != 0)
                D_800E168D = 8;
            else
            {
                func_8008A370(CONTROLLER_PFS_READ_WRITE_FILE,
                              (intptr_t)&_contPfs[_channel],
                              _fileNumber,
                              1,
                              0,
                              _fileSize,
                              (intptr_t)_fileBuffer,
                              0);
                D_800E168D = 4;
            }
        }
        break;
    case 4:
        if (D_80119A70 == 0)
        {
            if (D_800FE408 != 0)
                D_800E168D = 8;
            else
            {
                func_8008A370(CONTROLLER_PFS_FIND_FILE,
                              (intptr_t)&_contPfs[_channel],
                              0x3458,
                              0x4E445A45,
                              (intptr_t)&D_800F9F08,
                              (intptr_t)&D_800F9F18,
                              (intptr_t)&_fileNumber,
                              0);
                D_800E168D = 5;
            }
        }
        break;
    case 5:
        if (D_80119A70 == 0)
        {
            if (D_800FE408 == 0)
                D_800E168D = 6;
            else
                D_800E168D = 8;
        }
        break;
    case 6:
        if (func_80089DCC())
        {
            if (D_800FE408 == 0)
            {
                D_80138620 = 1;
                D_800E168D = 7;
            }
            else
                D_800E168D = 8;
        }
        break;
    case 7:
        D_800E168D = 0;
        ret = 1;
        break;
    case 8:
        D_800E168D = 7;
        break;
    }
    return ret;
}

/*8008B8B0*/
static u8 func_8008B8B0(void)
{
    s32 ret, i;

    ret = 0;
    switch (D_800E168E)
    {
    case 0:
        func_80080060();
        D_80138620 = 0;
        _fileNumber = 0;
        D_800F9EFC = 1;

        if (_channel < 0)
            D_800E168E = 1;
        else
            D_800E168E = 33;
        break;
    case 1:
        if (controller_8008A070())
        {
            if (D_800F9EFE >= 0)
            {
                _channel = D_800F9EFE;
                func_800800A8(6);
                func_8007FF94(D_800E12CC, 0xFF);
                func_8007FF94(D_800E12EC, 0xFF);
                func_8007FF94(D_800E130C, 0xFF);
                func_8007FF94(D_800E1000, 0xFF);
                func_8007FF94(D_800E1038, 0xFF);
                func_8007FF94(D_800E1040, 0xFF);
                D_800E168E = 8;
            }
            else if (_channel < 0)
            {
                func_800800A8(7);
                func_8007FF94(D_800E1260, 0xFF);
                func_8007FF94(D_800E127C, 0xFF);
                func_8007FF94(D_800E10C4, 0xFF);
                func_8007FF94(D_800E10E0, 0xFF);
                D_800E168E = 4;
            }
            else if (D_800F9F01 != 0)
            {
                func_8007FF94(D_800E104C, 0xFF);
                D_800E168E = 0;
            }
            else
                D_800E168E = 2;
        }
        break;
    case 2:
        if (func_80089724())
        {
            if (D_800FE408 == 0)
            {
                _fileNumber = 16;
                D_800E168E = 3;
            }
            else
                D_800E168E = 5;
        }
        break;
    case 3:
        func_80080060();
        func_8007FF94(D_800E15D8, 0xFF);
        func_80088120();
        func_8007FF94(D_800E11CC, 0xFF);
        func_8008803C(D_800E1650, 0);
        sprintf(D_800FA368, "%s%3d   %s%3d", D_800E1158, (D_800F9F48 / 256), D_800E1164, D_800F9F3C);
        func_8007FEDC(D_800FA368, 0xFF);
        func_8007FF94(D_800E1174, 0xFF);
        D_800E168E = 20;
        break;
    case 4:
        if (func_80087D24() != 0)
            D_800E168E = 5;
        break;
    case 5:
        ret = 1;
        func_80080060();
        D_800F9EFC = 0;
        D_800E168E = 0;
        break;
    case 6:
        if (func_80088910() != 0)
            D_800E168E = 5;
        break;
    case 7:
        if (D_800FA31C-- == 0)
            D_800E168E = 6;
        break;
    case 8:
        i = func_80087E30();
        if (i >= 0)
        {
            MusStartEffect(747);
            if (i != 2)
            {
                func_800800A8(6);
                if (i == 0)
                {
                    func_8007FF94(D_800E1370, 0xFF);
                    func_8007FF94(D_800E1388, 0xFF);
                    D_800E168E = 4;
                }
                else
                {
                    func_8007FF94(D_800E1398, 0xFF);
                    func_8007FF94(D_800E11CC, 0xFF);
                    func_8008A370(CONTROLLER_PFS_REPAIR_ID, (intptr_t)&_contPfs[_channel], 0, 0, 0, 0, 0, 0);
                    D_800E168E = 9;
                }
            }
            else
                D_800E168E = 0;
        }
        break;
    case 9:
        if (D_80119A70 == 0)
        {
            if (D_800FE408 != 0)
            {
                func_8007FF94(D_800E1330, 0xFF);
                func_8007FF94(D_800E1350, 0xFF);
            }
            else
                func_8007FF94(D_800E135C, 0xFF);

            D_800E168E = 4;
        }
        break;
    case 10:
        if (func_80087D24())
            D_800E168E = 0;

        break;
    case 11:
        if (func_80087CB0())
        {
            MusStartEffect(747);
            D_800E168E = 5;
        }
        break;
    case 20:
        if (func_80087CB0())
        {
            MusStartEffect(747);
            D_800E168E = 5;
            break;
        }
        if (gController[D_801A6D82].button2 & CONT_UP)
        {
            if (func_80089F14(-1, 2) != 0)
                MusStartEffect(746);

            D_800E168E = 3;
        }
        else if (gController[D_801A6D82].button2 & CONT_DOWN)
        {
            if (func_80089F14(1, 2) != 0)
                MusStartEffect(746);

            D_800E168E = 3;
        }
        else if (gController[D_801A6D82].button2 & CONT_A)
        {
            if (_fileNumber != 16)
            {
                if (D_800FA150[_fileNumber].unk0 != 0)
                {
                    MusStartEffect(747);
                    func_800800A8(9);
                    func_8007FF94(D_800E0FF0, 0xFF);
                    func_8007FF94(D_800E101C, 0xFF);
                    func_8007FF94(D_800E1024, 0xFF);
                    D_800E168E = 21;
                }
            }
            else
            {
                MusStartEffect(747);
                D_800E168E = 5;
            }
        }
        break;
    case 21:
        D_800FA2FA = func_80087DF4();
        if (D_800FA2FA >= 0)
        {
            if (D_800FA2FA != 0)
            {
                MusStartEffect(747);
                func_800800A8(6);
                D_800E168E = 34;
            }
            else
                D_800E168E = 3;
        }
        break;
    case 22:
        if (D_80119A70 == 0)
        {
            if (D_800FE408 != 0)
            {
                if (D_800FE408 == 2)
                {
                    func_800800A8(8);
                    func_8007FF94(D_800E104C, 0xFF);
                    D_800E168E = 10;
                }
                else
                    D_800E168E = 6;
            }
            else
            {
                func_800800A8(8);
                func_8007FF94(D_800E1534, 0xFF);
                D_800E168E = 10;
            }
        }
        break;
    case 33:
        if (func_800884C4())
        {
            if (D_800FE408 == 0)
                D_800E168E = 2;
            else if (D_800FE408 == 10)
                D_800E168E = 36;
            else
            {
                if (D_800FE408 == 2)
                    D_800F9EFD = 1;

                D_800E168E = 35;
            }
        }
        break;
    case 34:
        if (func_800884C4())
        {
            if (D_800FE408 == 0)
            {
                func_8008A370(CONTROLLER_PFS_DELETE_FILE,
                    (intptr_t)&_contPfs[_channel],
                    D_800F9F50[_fileNumber].company_code,
                    D_800F9F50[_fileNumber].game_code,
                    (intptr_t)&D_800F9F50[_fileNumber].game_name,
                    (intptr_t)&D_800F9F50[_fileNumber].ext_name,
                    0,
                    0);

                D_800E168E = 22;
            }
            else
            {
                if (D_800FE408 == 2)
                    D_800F9EFD = 1;

                D_800E168E = 35;
            }
        }
        break;
    case 35:
        if (func_80088250())
        {
            if (D_800FA2FA != 0)
            {
                func_8007FF94(D_800E1478, 0xFF);
                func_8007FF94(D_800E1494, 0xFF);
                func_8007FF94(D_800E14B8, 0xFF);
                func_8007FF94(D_800E14DC, 0xFF);
                D_800FE408 = -1;
                D_800E168E = 11;
            }
            else
            {
                if (D_800F9EFD != 0)
                    D_800FE408 = 2;

                D_800E168E = 36;
            }
        }
        break;
    case 36:
        if (func_80088FEC())
        {
            if (D_800FE408 == 0)
                D_800E168E = 0;
            else
                D_800E168E = 5;
        }
        break;
    }
    return ret;
}

/*8008C0C8*/
static s32 func_8008C0C8(void)
{
    s32 ret, i;

    ret = 0;
    switch (D_800E168F)
    {
    case 0:
        func_80080060();
        D_80138620 = 0;
        _fileNumber = 0;
        D_800F9EFC = 1;
        if (_channel < 0)
            D_800E168F = 1;
        else
            D_800E168F = 33;
        break;
    case 1:
        if (controller_8008A070())
        {
            if (D_800F9EFE >= 0)
            {
                _channel = D_800F9EFE;
                func_800800A8(6);
                func_8007FF94(D_800E12CC, 0xFF);
                func_8007FF94(D_800E12EC, 0xFF);
                func_8007FF94(D_800E130C, 0xFF);
                func_8007FF94(D_800E1000, 0xFF);
                func_8007FF94(D_800E1038, 0xFF);
                func_8007FF94(D_800E1040, 0xFF);
                D_800E168F = 8;
            }
            else if (_channel < 0)
            {
                func_800800A8(7);
                func_8007FF94(D_800E1260, 0xFF);
                func_8007FF94(D_800E127C, 0xFF);
                func_8007FF94(D_800E10C4, 0xFF);
                func_8007FF94(D_800E10E0, 0xFF);
                D_800E168F = 4;
            }
            else if (D_800F9F01 != 0)
            {
                func_800800A8(8);
                func_8007FF94(D_800E104C, 0xFF);
                D_800E168F = 0;
            }
            else
                D_800E168F = 2;
        }
        break;
    case 2:
        if (func_80089724())
        {
            if (D_800FE408 == 0)
            {
                _fileNumber = 16;
                D_800E168F = 3;
            }
            else
                D_800E168F = 5;
        }
        break;
    case 3:
        func_80080060();
        func_8007FF94(D_800E15D8, 0xFF);
        func_80088120();
        func_8007FF94(D_800E11CC, 0xFF);
        func_8008803C(D_800E1650, 0);
        sprintf(D_800FA368, "%s%3d   %s%3d", D_800E1158, (D_800F9F48 / 256), D_800E1164, D_800F9F3C);
        func_8007FEDC(D_800FA368, 0xFF);
        func_8007FF94(D_800E1174, 0xFF);
        D_800E168F = 20;
        break;
    case 4:
        if (func_80087D24() != 0)
            D_800E168F = 5;
        break;
    case 5:
        ret = 1;
        func_80080060();
        D_800F9EFC = 0;
        D_800E168F = 0;
        break;
    case 6:
        if (func_80088910() != 0)
            D_800E168F = 5;
        break;
    case 7:
        if (D_800FA31C-- == 0)
            D_800E168F = 6;
        break;
    case 8:
        i = func_80087E30();
        if (i >= 0)
        {
            MusStartEffect(747);
            if (i != 2)
            {
                func_800800A8(6);
                if (i == 0)
                {
                    func_8007FF94(D_800E1370, 0xFF);
                    func_8007FF94(D_800E1388, 0xFF);
                    D_800E168F = 4;
                }
                else
                {
                    func_8007FF94(D_800E1398, 0xFF);
                    func_8007FF94(D_800E11CC, 0xFF);
                    func_8008A370(CONTROLLER_PFS_REPAIR_ID, (intptr_t)&_contPfs[_channel], 0, 0, 0, 0, 0, 0);
                    D_800E168F = 9;
                }
            }
            else
                D_800E168F = 0;
        }
        break;
    case 9:
        if (D_80119A70 == 0)
        {
            if (D_800FE408 != 0)
            {
                func_8007FF94(D_800E1330, 0xFF);
                func_8007FF94(D_800E1350, 0xFF);
            }
            else
                func_8007FF94(D_800E135C, 0xFF);
            D_800E168F = 4;
        }
        break;
    case 10:
        if (func_80087D24())
            D_800E168F = 0;
        break;
    case 20:
        if (func_80087CB0())
        {
            MusStartEffect(747);
            D_800E168F = 5;
            break;
        }
        if (gController[D_801A6D82].button2 & CONT_UP)
        {
            if (func_80089F14(-1, 2) != 0)
                MusStartEffect(746);

            D_800E168F = 3;
        }
        else if (gController[D_801A6D82].button2 & CONT_DOWN)
        {
            if (func_80089F14(1, 2) != 0)
                MusStartEffect(746);

            D_800E168F = 3;
        }
        else if (gController[D_801A6D82].button2 & CONT_A)
        {
            if (_fileNumber != 16)
            {
                if (D_800FA150[_fileNumber].unk0 != 0)
                {
                    MusStartEffect(747);
                    func_800800A8(9);
                    func_8007FF94(D_800E0FF0, 0xFF);
                    func_8007FF94(D_800E101C, 0xFF);
                    func_8007FF94(D_800E1024, 0xFF);
                    D_800E168F = 21;
                }
            }
            else
            {
                MusStartEffect(747);
                D_800E168F = 5;
            }
        }
        break;
    case 21:
        D_800FA2FA = func_80087DF4();
        if (D_800FA2FA >= 0)
        {
            if (D_800FA2FA != 0)
            {
                MusStartEffect(747);
                func_800800A8(6);
                D_800E168F = 34;
            }
            else
                D_800E168F = 3;
        }
        break;
    case 22:
        if (D_80119A70 == 0)
        {
            if (D_800FE408 != 0)
            {
                if (D_800FE408 == 2)
                {
                    func_800800A8(8);
                    func_8007FF94(D_800E104C, 0xFF);
                    D_800E168F = 10;
                }
                else
                    D_800E168F = 6;
            }
            else
            {
                func_800800A8(8);
                func_8007FF94(D_800E1534, 0xFF);
                D_800E168F = 10;
            }
        }
        break;
    case 33:
        if (func_800884C4())
        {
            if (D_800FE408 == 0)
                D_800E168F = 2;
            else if (D_800FE408 == 10)
                D_800E168F = 36;
            else
            {
                if (D_800FE408 == 2)
                    D_800F9EFD = 1;

                D_800E168F = 35;
            }
        }
        break;
    case 34:
        if (func_800884C4())
        {
            if (D_800FE408 == 0)
            {
                func_8008A370(CONTROLLER_PFS_DELETE_FILE,
                    (intptr_t)&_contPfs[_channel],
                    D_800F9F50[_fileNumber].company_code,
                    D_800F9F50[_fileNumber].game_code,
                    (intptr_t)&D_800F9F50[_fileNumber].game_name,
                    (intptr_t)&D_800F9F50[_fileNumber].ext_name,
                    0,
                    0);

                D_800E168F = 22;
            }
            else
            {
                if (D_800FE408 == 2)
                    D_800F9EFD = 1;

                D_800E168F = 35;
            }
        }
        break;
    case 35:
        if (func_80088250())
        {
            if (D_800FA2FA != 0)
            {
                func_800800A8(7);
                func_8007FF94(D_800E1260, 0xFF);
                func_8007FF94(D_800E127C, 0xFF);
                func_8007FF94(D_800E10C4, 0xFF);
                func_8007FF94(D_800E10E0, 0xFF);
                D_800FE408 = -1;
                D_800E168F = 4;
            }
            else
            {
                if (D_800F9EFD != 0)
                    D_800FE408 = 2;
                D_800E168F = 36;
            }
        }
        break;
    case 36:
        if (func_80088910())
        {
            if (D_800FE408 == 0)
                D_800E168F = 0;
            else
                D_800E168F = 5;
        }
        break;
    }
    return ret;
}

/*8008C8DC*/
u8 controller_8008C8DC(void)
{
    s32 ret, i;

    ret = 0;
    switch (D_800E1690)
    {
    case 0:
        func_80080060();
        D_80138620 = 0;
        _fileNumber = 0;
        D_800F9EFC = 1;
        if (_channel < 0)
            D_800E1690 = 1;
        else
            D_800E1690 = 34;
        break;
    case 1:
        if (controller_8008A070())
        {
            if (D_800F9EFE >= 0)
            {
                _channel = D_800F9EFE;
                func_800800A8(6);
                func_8007FF94(D_800E12CC, 0xFF);
                func_8007FF94(D_800E12EC, 0xFF);
                func_8007FF94(D_800E130C, 0xFF);
                func_8007FF94(D_800E1000, 0xFF);
                func_8007FF94(D_800E1038, 0xFF);
                func_8007FF94(D_800E1040, 0xFF);
                D_800E1690 = 8;
            }
            else if (_channel < 0)
            {
                func_800800A8(7);
                func_8007FF94(D_800E1260, 0xFF);
                func_8007FF94(D_800E127C, 0xFF);
                func_8007FF94(D_800E10C4, 0xFF);
                func_8007FF94(D_800E10E0, 0xFF);
                D_800E1690 = 4;
            }
            else if (D_800F9F01 != 0)
            {
                func_800800A8(8);
                func_8007FF94(D_800E104C, 0xFF);
                D_800E1690 = 0;
            }
            else
                D_800E1690 = 2;
        }
        break;
    case 2:
        if (func_80089724())
        {
            if (D_800FE408 != 0)
                D_800E1690 = 5;
            else
            {
                _fileNumber = 17;
                D_800E1690 = 3;
            }
        }
        break;
    case 3:
        func_80080060();
        func_8007FF94(D_800E15C4, 0xFF);
        func_80088120();
        func_8007FF94(D_800E11CC, 0xFF);
        func_8008803C(D_800E1658, 0);
        func_8008803C(D_800E1668, 0);
        sprintf(D_800FA368, "%s%3d   %s%3d", D_800E1158, (D_800F9F48 / 256), D_800E1164, D_800F9F3C);
        func_8007FEDC(D_800FA368, 0xFF);
        if (_fileNumber < 16)
        {
            if (func_80089CF4(_fileNumber) == 0)
                func_8007FF94(D_800E1174, 0xFF);
            else
                func_8007FF94(D_800E11B4, 0xFF);

            D_800E1690 = 20;
        }
        else
            D_800E1690 = 20;
        break;
    case 4:
        if (func_80087D24())
            D_800E1690 = 5;

        break;
    case 5:
        ret = 1;
        func_80080060();
        D_800F9EFC = 0;
        D_800E1690 = 0;
        break;
    case 6:
        if (func_80088910())
            D_800E1690 = 5;
        break;
    case 7:
        if (D_800FA31C-- == 0)
            D_800E1690 = 6;
        break;
    case 8:
        i = func_80087E30();
        if (i >= 0)
        {
            MusStartEffect(747);
            if (i != 2)
            {
                func_80080060();
                if (i == 0)
                {
                    func_8007FF94(D_800E1370, 0xFF);
                    func_8007FF94(D_800E1388, 0xFF);
                    D_800E1690 = 4;
                }
                else
                {
                    func_8007FF94(D_800E1398, 0xFF);
                    func_8007FF94(D_800E11CC, 0xFF);
                    func_8008A370(CONTROLLER_PFS_REPAIR_ID, (intptr_t)&_contPfs[_channel], 0, 0, 0, 0, 0, 0);
                    D_800E1690 = 9;
                }
            }
            else
                D_800E1690 = 0;
        }
        break;
    case 9:
        if (D_80119A70 == 0)
        {
            if (D_800FE408 != 0)
            {
                func_8007FF94(D_800E1330, 0xFF);
                func_8007FF94(D_800E1350, 0xFF);
            }
            else
                func_8007FF94(D_800E135C, 0xFF);

            D_800E1690 = 4;
        }
        break;
    case 20:
        if (gController[D_801A6D82].button2 & CONT_B)
        {
            MusStartEffect(747);
            D_800E1690 = 5;
        }
        else if (gController[D_801A6D82].button2 & CONT_UP)
        {
            if (func_80089F14(-1, 1) != 0)
            {
                MusStartEffect(746);
                D_800E1690 = 3;
            }
            else
                D_800E1690 = 3;
        }
        else if (gController[D_801A6D82].button2 & CONT_DOWN)
        {
            if (func_80089F14(1, 1) != 0)
            {
                MusStartEffect(746);
                D_800E1690 = 3;
            }
            else
                D_800E1690 = 3;
        }
        else if (gController[D_801A6D82].button2 & CONT_A)
        {
            MusStartEffect(747);
            if (_fileNumber == 16)
            {
                D_800E1690 = 37;
            }
            else if (_fileNumber != 17)
            {
                if (func_80089CF4(_fileNumber) == 0)
                    D_800E1690 = 26;
                else
                    D_800E1690 = 21;
            }
            else
                D_800E1690 = 5;
        }
        break;
    case 21:
        func_800800A8(8);
        func_8007FF94(D_800E1544, 0xFF);
        func_8007FF94(D_800E1568, 0xFF);
        func_8007FF94(D_800E158C, 0xFF);
        func_8007FF94(D_800E11CC, 0xFF);
        func_8007FF94(D_800E1594, 0xFF);
        func_8007FF94(D_800E15A4, 0xFF);
        D_800E1690 = 22;
        break;
    case 22:
        i = func_80087DF4();
        if (i >= 0)
        {
            MusStartEffect(747);
            if (i == 0)
                D_800E1690 = 23;
            else
                D_800E1690 = 0;
        }
        break;
    case 23:
        func_80080060();
        D_800E1690 = 30;
        break;
    case 24:
        if (func_8008B574())
        {
            if (D_800FE408 != 0)
                D_800E1690 = 6;
            else
            {
                D_80138620 = 1;
                func_800800A8(8);
                func_8007FF94(D_800E13A4, 0xFF);
                D_800E1690 = 4;
            }
        }
        break;
    case 25:
        if (func_80088760())
        {
            if (D_800FE408 != 0)
                D_800E1690 = 5;
            else
                D_800E1690 = 0;
        }
        break;
    case 26:
        func_800800A8(9);
        func_8007FF94(D_800E0FF0, 0xFF);
        func_8007FF94(D_800E101C, 0xFF);
        func_8007FF94(D_800E1024, 0xFF);
        D_800E1690 = 27;
        break;
    case 27:
        D_800FA2FA = func_80087DF4();
        if (D_800FA2FA >= 0)
        {
            if (D_800FA2FA != 0)
            {
                MusStartEffect(747);
                func_80080060();
                D_800E1690 = 32;
            }
            else
                D_800E1690 = 3;
        }
        break;
    case 28:
        if (D_80119A70 == 0)
        {
            if (D_800FE408 != 0)
            {
                if (D_800FE408 == 2)
                {
                    func_800800A8(8);
                    func_8007FF94(D_800E104C, 0xFF);
                    D_800E1690 = 29;
                }
                else
                    D_800E1690 = 6;
            }
            else
            {
                func_800800A8(8);
                func_8007FF94(D_800E1534, 0xFF);
                D_800E1690 = 29;
            }
        }
        break;
    case 10:
    case 29:
        if (func_80087D24())
            D_800E1690 = 0;

        break;
    case 30:
        if (func_800884C4())
        {
            if (D_800FE408 == 0)
                D_800E1690 = 24;
            else
            {
                if (D_800FE408 == 2)
                    D_800F9EFD = 1;

                D_800E1690 = 35;
            }
        }
        break;
    case 32:
        if (func_800884C4())
        {
            if (D_800FE408 == 0)
            {
                func_8008A370(CONTROLLER_PFS_DELETE_FILE,
                    (intptr_t)&_contPfs[_channel],
                    D_800F9F50[_fileNumber].company_code,
                    D_800F9F50[_fileNumber].game_code,
                    (intptr_t)&D_800F9F50[_fileNumber].game_name,
                    (intptr_t)&D_800F9F50[_fileNumber].ext_name,
                    0,
                    0);

                D_800E1690 = 28;
            }
            else
            {
                if (D_800FE408 == 2)
                    D_800F9EFD = 1;

                D_800E1690 = 35;
            }
        }
        break;
    case 34:
        if (func_800884C4())
        {
            if (D_800FE408 == 0)
                D_800E1690 = 2;
            else
            {
                if (D_800FE408 == 10)
                    D_800E1690 = 36;
                else
                    D_800E1690 = 35;
            }
        }
        break;
    case 35:
        if (func_80088250())
        {
            if (D_800FA2FA != 0)
            {
                func_800800A8(7);
                func_8007FF94(D_800E1260, 0xFF);
                func_8007FF94(D_800E127C, 0xFF);
                func_8007FF94(D_800E10C4, 0xFF);
                func_8007FF94(D_800E10E0, 0xFF);
                D_800E1690 = 4;
            }
            else
            {
                if (D_800F9EFD != 0)
                    D_800FE408 = 2;
                D_800E1690 = 36;
            }
        }
        break;
    case 36:
        if (func_80088910())
        {
            if (D_800FE408 == 0)
                D_800E1690 = 0;
            else
                D_800E1690 = 5;
        }
        break;
    case 37:
        if (func_800884C4())
        {
            if (D_800FE408 == 0)
            {
                for (_fileNumber = 0; _fileNumber < 16; _fileNumber++)
                {
                    if (D_800FA150[_fileNumber].unk0 == 0)
                        break;
                }

                if ((D_800F9F48 / 256) < D_800F9F3C)
                    _fileNumber = 16;

                if (_fileNumber >= 16)
                    D_800E1690 = 25;
                else
                    D_800E1690 = 23;
            }
            else
            {
                if (D_800FE408 == 2)
                    D_800F9EFD = 1;

                if (D_800FE408 == 10)
                    D_800E1690 = 36;
                else
                    D_800E1690 = 35;
            }
        }
        break;
    }
    return ret;
}

/*8008D354*/
u8 controller_8008D354(void)
{
    s32 ret, i;

    ret = 0;
    switch (D_800E1691)
    {
    case 0:
        func_80080060();
        D_80138620 = 0;
        _fileNumber = 0;
        D_800F9EFC = 1;
        if (_channel < 0)
            D_800E1691 = 1;
        else
            D_800E1691 = 34;
        break;
    case 1:
        if (controller_8008A070())
        {
            if (D_800F9EFE >= 0)
            {
                _channel = D_800F9EFE;
                func_800800A8(6);
                func_8007FF94(D_800E12CC, 0xFF);
                func_8007FF94(D_800E12EC, 0xFF);
                func_8007FF94(D_800E130C, 0xFF);
                func_8007FF94(D_800E1000, 0xFF);
                func_8007FF94(D_800E1038, 0xFF);
                func_8007FF94(D_800E1040, 0xFF);
                D_800E1691 = 8;
            }
            else if (_channel < 0)
            {
                func_800800A8(7);
                func_8007FF94(D_800E1260, 0xFF);
                func_8007FF94(D_800E127C, 0xFF);
                func_8007FF94(D_800E10C4, 0xFF);
                func_8007FF94(D_800E10E0, 0xFF);
                D_800E1691 = 4;
            }
            else if (D_800F9F01 != 0)
            {
                func_800800A8(8);
                func_8007FF94(D_800E104C, 0xFF);
                D_800E1691 = 0;
            }
            else
                D_800E1691 = 2;
        }
        break;
    case 2:
        if (func_80089724())
        {
            if (D_800FE408 == 0)
            {
                _fileNumber = 16;
                D_800E1691 = 3;
            }
            else
                D_800E1691 = 5;
        }
        break;
    case 3:
        func_80080060();
        func_8007FF94(D_800E15B0, 0xFF);
        func_80088120();
        func_8007FF94(D_800E11CC, 0xFF);
        func_8008803C(D_800E1650, 0);
        sprintf(D_800FA368, "%s%3d   %s%3d", D_800E1158, (D_800F9F48 / 256), D_800E1164, D_800F9F3C);
        func_8007FEDC(D_800FA368, 0xFF);
        func_8007FF94(D_800E1194, 0xFF);
        D_800E1691 = 20;
        break;
    case 4:
        if (func_80087D24() != 0)
            D_800E1691 = 5;
        break;
    case 5:
        ret = 1;
        func_80080060();
        D_800F9EFC = 0;
        D_800E1691 = 0;
        break;
    case 6:
        if (func_80088910() != 0)
            D_800E1691 = 5;
        break;
    case 7:
        if (D_800FA31C-- == 0)
            D_800E1691 = 6;
        break;
    case 8:
        i = func_80087E30();
        if (i >= 0)
        {
            MusStartEffect(747);
            if (i != 2)
            {
                func_80080060();
                if (i == 0)
                {
                    func_8007FF94(D_800E1370, 0xFF);
                    func_8007FF94(D_800E1388, 0xFF);
                    D_800E1691 = 4;
                }
                else
                {
                    func_8007FF94(D_800E1398, 0xFF);
                    func_8007FF94(D_800E11CC, 0xFF);
                    func_8008A370(CONTROLLER_PFS_REPAIR_ID, (intptr_t)&_contPfs[_channel], 0, 0, 0, 0, 0, 0);
                    D_800E1691 = 9;
                }
            }
            else
                D_800E1691 = 0;
        }
        break;
    case 9:
        if (D_80119A70 == 0)
        {
            if (D_800FE408 != 0)
            {
                func_8007FF94(D_800E1330, 0xFF);
                func_8007FF94(D_800E1350, 0xFF);
            }
            else
                func_8007FF94(D_800E135C, 0xFF);

            D_800E1691 = 4;
        }
        break;
    case 10:
        if (func_80087D24())
            D_800E1691 = 0;
        break;
    case 20:
        if (gController[D_801A6D82].button2 & CONT_B)
        {
            MusStartEffect(747);
            D_800E1691 = 5;
        }
        else if (gController[D_801A6D82].button2 & CONT_UP)
        {
            if (func_80089F14(-1, 0) != 0)
                MusStartEffect(746);

            D_800E1691 = 3;
        }
        else if (gController[D_801A6D82].button2 & CONT_DOWN)
        {
            if (func_80089F14(1, 0) != 0)
                MusStartEffect(746);

            D_800E1691 = 3;
        }
        else if (gController[D_801A6D82].button2 & CONT_A)
        {
            if (_fileNumber != 16)
            {
                if (D_800FA150[_fileNumber].unk0 != 0)
                {
                    MusStartEffect(747);
                    func_80080060();
                    D_800E1691 = 21;
                }
            }
            else
            {
                MusStartEffect(747);
                D_800E1691 = 5;
            }
        }
        break;
    case 21:
        if (func_800884C4())
        {
            if (D_800FE408 == 0)
                D_800E1691 = 25;
            else
            {
                if (D_800FE408 == 2)
                    D_800F9EFD = 1;

                D_800E1691 = 35;
            }
        }
        break;
    case 25:
        if (func_80089DCC())
        {
            if (D_800FE408 == 0)
            {
                D_80138620 = 1;
                func_800800A8(8);
                func_8007FF94(D_800E1234, 0xFF);
            }
            else if (D_800FE408 == -1)
            {
                func_8007FF94(D_800E1068, 0xFF);
                func_8007FF94(D_800E11CC, 0xFF);
                func_8007FF94(D_800E1250, 0xFF);
            }
            else
            {
                D_800E1691 = 6;
                break;
            }
            D_800E1691 = 4;
        }
        break;
    case 34:
        if (func_800884C4())
        {
            if (D_800FE408 == 0)
                D_800E1691 = 2;
            else
            {
                if (D_800FE408 == 10)
                    D_800E1691 = 36;
                else
                    D_800E1691 = 35;
            }
        }
        break;
    case 35:
        if (func_80088250())
        {
            if (D_800FA2FA != 0)
            {
                func_800800A8(7);
                func_8007FF94(D_800E1260, 0xFF);
                func_8007FF94(D_800E127C, 0xFF);
                func_8007FF94(D_800E10C4, 0xFF);
                func_8007FF94(D_800E10E0, 0xFF);
                D_800E1691 = 4;
            }
            else
            {
                if (D_800F9EFD != 0)
                    D_800FE408 = 2;
                D_800E1691 = 36;
            }
        }
        break;
    case 36:
        if (func_80088910())
        {
            if (D_800FE408 == 0)
                D_800E1691 = 0;
            else
                D_800E1691 = 5;
        }
        break;
    }
    return ret;
}

/*hack for wrong rodata aligment*/
static const f64 _force_rodata_alignment = 0;
