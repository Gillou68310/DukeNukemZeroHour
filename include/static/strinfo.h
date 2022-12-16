#ifndef _STRINFO_H_
#define _STRINFO_H_

#include "common.h"

typedef struct
{
    s16 count;
    char **addr;
} MsgStrInfo;

extern char *gWeaponStrInfo[0x7D];
extern s16 gWeaponStrInfoCount;
extern char **gKeyStrInfo[0x18];
extern MsgStrInfo gMsgStrInfo[0x18];
extern char *gMapStrInfo[0x18];
extern char *gActionStrInfo[0x11];
extern s16 gActionStrInfoCount;
extern char *gLicenceStrInfo[0x23];
extern s16 gLicenceStrInfoCount;
extern char *gCreditStrInfo[0xF8];
extern s16 gCreditStrInfoCount;

#endif
