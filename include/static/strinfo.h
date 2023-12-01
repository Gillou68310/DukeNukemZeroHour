#ifndef _STRINFO_H_
#define _STRINFO_H_

#include "common.h"
#include "static/mapinfo.h"

typedef struct
{
    s16 count;
    char **addr;
} ObjectiveStrInfo;

extern char *gWeaponStrInfo[125];
extern s16 gWeaponStrInfoCount;
extern char **gKeyStrInfo[MAP_COUNT];
extern ObjectiveStrInfo gObjectiveStrInfo[MAP_COUNT];
extern char *gMapStrInfo[MAP_COUNT];
extern char *gActionStrInfo[17];
extern s16 gActionStrInfoCount;
extern char *gLicenceStrInfo[35];
extern s16 gLicenceStrInfoCount;
extern char *gCreditStrInfo[248];
extern s16 gCreditStrInfoCount;

#endif
