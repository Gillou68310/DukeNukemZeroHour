#ifndef _STRINFO_H_
#define _STRINFO_H_

#include "common.h"

#define MAP_STRINFO_NUM 24
#define KEY_STRINFO_NUM 16

typedef struct
{
    s16 count;
    char **addr;
} MsgStrInfo;

extern char *gWeaponStrInfo[0x7D];
extern s16 gWeaponStrInfoCount;
extern char **gKeyStrInfo[MAP_STRINFO_NUM];
extern MsgStrInfo gMsgStrInfo[MAP_STRINFO_NUM];
extern char *gMapStrInfo[MAP_STRINFO_NUM];
extern char *gActionStrInfo[0x11];
extern s16 gActionStrInfoCount;
extern char *gLicenceStrInfo[0x23];
extern s16 gLicenceStrInfoCount;
extern char *gCreditStrInfo[0xF8];
extern s16 gCreditStrInfoCount;

#endif
