#include "common.h"
#include "code0/code0.h"
#include "static/strinfo.h"

#if defined(VERSION_US) || defined(VERSION_EU) || defined(VERSION_PROTO)
/*.data*/

/*01021560*/
char *gWeaponStrInfo[125] = {
    "M-80 BLASTER",
    NULL,
    "BLASTER CELLS",
    NULL,
    NULL,
    "CLAW-12 SHOTGUN",
    NULL,
    "CLAW-12 SHELLS",
    NULL,
    NULL,
    "CLAW-12 AUTOLOADER",
    "MP-10 SMG",
    NULL,
    "SMG CLIPS",
    NULL,
    NULL,
    "AGL-9 GRENADE LAUNCHER",
    NULL,
    "GRENADES",
    NULL,
    NULL,
    "RADIUM CYANIDE GRENADES",
    NULL,
    NULL,
    "PIPEBOMB",
    NULL,
    "PIPEBOMBS",
    NULL,
    "FREEZETHROWER",
    NULL,
    "CRYOGENIC CRYSTALS",
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    "GAMMA CANNON",
    NULL,
    "GAMMA CRYSTAL",
    NULL,
    NULL,
    "HAVOC MULTILAUNCHER",
    NULL,
    "MULTILAUNCHER ROCKETS",
    NULL,
    NULL,
    "HEATSEEKING ROCKETS",
    NULL,
    "CTX-2000 TRIPBOMB",
    NULL,
    NULL,
    "MAGNAVOLT TRIPBOMB",
    NULL,
    "BMF THUNDERSTRIKE",
    NULL,
    "BMF COILS",
    NULL,
    NULL,
    NULL,
    "PEACEKEEPER .45",
    NULL,
    ".45 SLUGS",
    NULL,
    NULL,
    ".45 MAGNUM ROUNDS",
    "SAWED-OFF SHOTGUN",
    NULL,
    "SHOTGUN SHELLS",
    NULL,
    NULL,
    "VOLT CANNON",
    NULL,
    "VOLT BOX",
    NULL,
    NULL,
    "DYNAMITE",
    NULL,
    "CRATE OF DYNAMITE",
    NULL,
    "BOMB",
    NULL,
    "BOX OF BOMBS",
    NULL,
    "TIME VORTEX",
    NULL,
    NULL,
    ".30-30 RIFLE",
    NULL,
    "RIFLE BULLETS",
    NULL,
    NULL,
    "GATLING GUN",
    NULL,
    "GATLING GUN BULLETS",
    NULL,
    NULL,
    "HEALTH +10",
    "HEALTH +30",
    "HEALTH +30",
    "HEALTH +30",
    "MEDKIT",
    "DOCTOR'S BAG",
    "DOCTOR'S BAG",
    "PROTECTIVE BOOTS",
    "ARMOR",
    NULL,
    "BOILER PLATE ARMOR",
    NULL,
    "BREASTPLATE",
    NULL,
    "VITAMIN X",
    "NIGHT-VISION GOGGLES",
    "GASMASK",
    "SCUBA GEAR",
    "DIVING HELMET",
    "SUPER-CRYO CRYSTALS",
    "CTX-2000 TRIPBOMBS",
    ".50 SNIPER RIFLE",
    ".50 RIFLE ROUNDS",
    "ARMOR PIERCING ROUNDS",
    "TELESCOPIC SIGHT",
    "RADIUM CYANIDE LAUNCHER",
    "BEAR TRAP",
    "ATOMIC HEALTH",
};

/*01021754*/
s16 gWeaponStrInfoCount = ARRAY_COUNT(gWeaponStrInfo);

/*01021758*/
static char *_keyStrTable1[MAXKEYS-1] = {
    "TRANSTEK CODE CARD",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
};

/*01021798*/
static char *_keyStrTable2[MAXKEYS-1] = {
    "CONTROL KEY",
    "SERVICE ELEVATOR PASS",
    "PUMPING STATION KEY",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
};

/*010217D8*/
static char *_keyStrTable3[MAXKEYS-1] = {
    "POWER CELL ALPHA",
    "POWER CELL BETA",
    "POWER CELL DELTA",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
};

/*01021818*/
static char *_keyStrTable4[MAXKEYS-1] = {
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
};

/*01021858*/
static char *_keyStrTable5[MAXKEYS-1] = {
    "LABORATORY KEY",
    "ARMORY KEY",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
};

/*01021898*/
static char *_keyStrTable6[MAXKEYS-1] = {
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
};

/*010218D8*/
static char *_keyStrTable7[MAXKEYS-1] = {
    "GUARD TOWER KEY",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
};

/*01021918*/
static char *_keyStrTable8[MAXKEYS-1] = {
    "HOTEL KEY",
    "SALOON KEY",
    "ALIEN PLANS",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
};

/*01021958*/
static char *_keyStrTable9[MAXKEYS-1] = {
    "",
    "EAST WING KEY",
    "NORTH WING KEY",
    "A HELPING HAND",
    "SOUTH WING KEY",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
};

/*01021998*/
static char *_keyStrTable10[MAXKEYS-1] = {
    "LEVEL 1 SECURITY PASS",
    "LEVEL 2 SECURITY PASS",
    "BACKSTAGE KEY",
    "LEVEL 3 SECURITY PASS",
    "LEVEL 4 SECURITY PASS",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
};

/*010219D8*/
static char *_keyStrTable11[MAXKEYS-1] = {
    "GUARD TOWER KEY",
    "BARRACKS KEY",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
};

/*01021A18*/
static char *_keyStrTable12[MAXKEYS-1] = {
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
};

/*01021A58*/
static char *_keyStrTable13[MAXKEYS-1] = {
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
};

/*01021A98*/
static char *_keyStrTable14[MAXKEYS-1] = {
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
};

/*01021AD8*/
static char *_keyStrTable15[MAXKEYS-1] = {
    "CRYPT KEY",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
};

/*01021B18*/
static char *_keyStrTable16[MAXKEYS-1] = {
    "SKELETON KEY",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
};

/*01021B58*/
static char *_keyStrTable17[MAXKEYS-1] = {
    "3RD CLASS KEY",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
};

/*01021B98*/
static char *_keyStrTable18[MAXKEYS-1] = {
    "COURTYARD KEY",
    "GREAT HALL KEY",
    "CATAPULT ROCK",
    "CYBORG HEAD",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
};

/*01021BD8*/
static char *_keyStrTable19[MAXKEYS-1] = {
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
};

/*01021C18*/
static char *_keyStrTable20[MAXKEYS-1] = {
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
};

/*01021C58*/
static char *_keyStrTable21[MAXKEYS-1] = {
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
};

/*01021C98*/
static char *_keyStrTable22[MAXKEYS-1] = {
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
};

/*01021CD8*/
static char *_keyStrTable23[MAXKEYS-1] = {
    "CYBORG HEAD",
    "BIO-EMITTER",
    "CYBORG HEAD",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
};

/*01021D18*/
static char *_keyStrTable24[MAXKEYS-1] = {
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
};

/*01021D58*/
char **gKeyStrInfo[MAP_COUNT] = {
    _keyStrTable1,
    _keyStrTable2,
    _keyStrTable3,
    _keyStrTable7,
    _keyStrTable4,
    _keyStrTable5,
    _keyStrTable6,
    _keyStrTable8,
    _keyStrTable9,
    _keyStrTable10,
    _keyStrTable11,
    _keyStrTable12,
    _keyStrTable13,
    _keyStrTable14,
    _keyStrTable15,
    _keyStrTable16,
    _keyStrTable18,
    _keyStrTable17,
    _keyStrTable19,
    _keyStrTable21,
    _keyStrTable23,
    _keyStrTable24,
    _keyStrTable24,
    _keyStrTable24,
};

/*01021DB8*/
static char *_objectiveStrTable1[5] = {
    "FIND A WAY TO APPROACH THE STATUE OF LIBERTY",
    "LOCATE AND QUESTION SURVIVING SOLDIERS",
    "RETURN TO PARKING LOT TO RENDEZVOUS WITH REINFORCEMENTS",
    "LOCATE ELECTRICAL SUBSTATION AND DEACTIVATE POWER TO SUBWAY STATION",
    "GET TO SUBWAY STATION AND LOCATE UNDERGROUND ACCESS TUNNEL"};

/*01021DCC*/
static char *_objectiveStrTable2[6] = {
    "FIND AND DESTROY THE ALIEN HEADQUARTERS",
    "PROCEED INSIDE THE STATUE",
    "LOCATE OVERFLOW CONTROL KEY",
    "USE PUMPING STATION TO FLOOD ACCESS TUNNEL",
    "USE SERVICE ELEVATOR TO ACCESS VISITOR CENTER",
    "OVERRIDE ELEVATOR LOCKDOWN AND ASCEND TO HEAD OF STATUE",
};

/*01021DE4*/
static char *_objectiveStrTable3[7] = {
    "RE-ESTABLISH CONTACT WITH HQ",
    "FIND SIGNS OF LIFE",
    "LOCATE POWER CELL ALPHA",
    "LOCATE POWER CELL BETA",
    "LOCATE POWER CELL DELTA",
    "POWER UP SIGNAL BEACON",
    "WAIT FOR HELICOPTER",
};

/*01021E00*/
static char *_objectiveStrTable4[1] = {
    "FIND THE BALLOON TO ESCAPE THE MAN-MADE ATOLL"
};

/*01021E04*/
static char *_objectiveStrTable5[4] = {
    "REACH MILITARY BASE",
    "EXPLORE SURROUNDING AREA",
    "DISABLE ALIEN FORCE-FIELD GENERATOR",
    "PROCEED TOWARDS BASE"
};

/*01021E14*/
static char *_objectiveStrTable6[5] = {
    "GAIN ACCESS TO BASE AND PROTECT SURVIVORS",
    "PROCEED TO MAIN ENTRANCE",
    "GET TO MEDICAL AND POWER UP DOOR TO TEMPORAL LABS",
    "ACCESS SIDE DOOR IN TIME MACHINE CHAMBER",
    "ACTIVATE SENTRY GUN DEFENSE SYSTEM"
};

/*01021E28*/
static char *_objectiveStrTable7[1] = {
    "DEFEAT BOSS HOG"
};

/*01021E2C*/
static char *_objectiveStrTable8[6] = {
    "BLOW OPEN THE SAFE IN THE TOWN BANK TO STEAL THE ALIEN PLANS",
    "LOCATE THE PLUNGER DETONATOR",
    "USE THE HOTEL KEY TO GAIN ACCESS TO THE FUSE WIRE",
    "FIND THE SALOON KEY AND OPEN MINER 69'ER",
    "FIND THE TNT",
    "BLOW OPEN THE SAFE IN THE BANK",
};

/*01021E44*/
static char *_objectiveStrTable9[4] = {
    "ESCAPE FROM JAIL",
    "FIND A HELPING HAND TO ESCAPE",
    "FIND A WAY TO BREAK OUT",
    "DISCOVER ORIGIN OF NEW CYBORG SOLDIERS"
};

/*01021E54*/
static char *_objectiveStrTable10[4] = {
    "CLEAR OUT THE ALIEN WAR FACTORY",
    "BOARD THE RIVERBOAT",
    "LOCATE AN EXIT",
    "TELEPORT TO FORT ROSWELL"
};

/*01021E64*/
static char *_objectiveStrTable11[5] = {
    "LOCATE THE ALIEN BOMB",
    "SURVIVE THE CANNON FIRE AND REACH THE FORT",
    "AVOID THE BOOBY TRAPS IN AND AROUND THE FORT",
    "KILL THE TRAITOR GENERAL CUSTER",
    "FIND THE ENTRANCE TO THE MINES"
};

/*01021E78*/
static char *_objectiveStrTable12[5] = {
    "CHASE THE ALIEN BOMB AND DEFUSE THE EXPLOSIVE SITUATION",
    "FIND A MINE CART TO TAKE YOU DEEPER",
    "RIDE THE MINE CART (REMEMBER TO USE JUMP AND CROUCH)",
    "MOVE THE TURNTABLE TO GET YOUR NEXT RIDE",
    "HEAD FOR THE CENTER OF THE EARTH"
};

/*01021E8C*/
static char *_objectiveStrTable13[1] = {
    "DEFEAT THE CYBORG SCORPION"
};

/*01021E90*/
static char *_objectiveStrTable14[5] = {
    "DESTROY ALIEN VIRUS AND FIND ANOTHER TIME MACHINE",
    "LOCATE THE ENTRANCE TO THE SEWERS",
    "LOCATE THE WAY UP TO WHITECHAPEL",
    "FIND AND KILL GIANT PARAPSYCHE",
    "EVACUATE AREA"
};

/*01021EA4*/
static char *_objectiveStrTable15[4] = {
    "PROCEED TO AIRFIELD TO TAKE AIRSHIP TO CASTLE",
    "EXPLORE THE GRAVEYARD AND LOCATE CANAL ENTRANCE",
    "FOLLOW CANALS TO AIRFIELD",
    "CATCH A RIDE ON THE AIRSHIP"
};

/*01021EB4*/
static char *_objectiveStrTable16[4] = {
    "USE THE AIRSHIP'S PLANE TO ESCAPE TO CASTLE",
    "BREAK OUT FROM LUGGAGE HOLD",
    "FIND THE SKELETON KEY",
    "GAIN ACCESS TO THE AIRPLANE"
};

/*01021EC4*/
static char *_objectiveStrTable17[5] = {
    "STOP THE SHIP FROM REACHING ITS DESTINATION",
    "EXPLORE THE SHIP AND FIND A WAY TO REACH THE BOTTOM OF THE HOLD",
    "SINK THE SHIP IN ANY WAY POSSIBLE",
    "ABANDON SHIP AND ESCAPE THROUGH TIME PORTAL",
    "DESTROY ALL EGGS TO BE SURE THE ALIEN MENACE DOESN'T SPREAD"
};

/*01021ED8*/
static char *_objectiveStrTable18[3] = {
    "LOCATE THE ALIEN MASTERMIND",
    "LOCATE AN ENTRANCE TO THE CASTLE",
    "EXPLORE THE CASTLE AND FIND THE LOCATION OF THE ALIEN BRAIN"
};

/*01021EE4*/
static char *_objectiveStrTable19[2] = {
    "KILL THE BRAIN IN A VAT",
    "DEACTIVATE ALL LIFE SUPPORT MACHINES"
};

/*01021EEC*/
static char *_objectiveStrTable20[3] = {
    "HIJACK SHUTTLE TO BOARD MOTHERSHIP",
    "DEFEAT EVIL DUKES",
    "LOCATE ALIEN SHUTTLECRAFT"
};

/*01021EF8*/
static char *_objectiveStrTable21[5] = {
    "DESTROY THE ALIEN SPACECRAFT",
    "LOCATE COMPATIBLE KEY TO ESCAPE SHUTTLE BAY",
    "FIND A WAY TO DEACTIVATE BIO-SENSITIVE FORCEFIELDS",
    "DEACTIVATE GENERATORS TO DESTROY CRAFT",
    "ACCESS NEST AND DESTROY ALL EGGS"
};

/*01021F0C*/
static char *_objectiveStrTable22[1] = {
    "KILL ZERO"
};

/*01021F10*/
static char *_objectiveStrTable23[1] = {
    "WATCH END SEQUENCE"
};

/*01021F14*/
static char *_objectiveStrTable24[7] = {
    "PROCEED TO THE HANGAR AND BOARD THE WAITING HELICOPTER",
    "JUMP, CLIMB, CRAWL AND SWIM ACROSS THE ASSAULT COURSE",
    "DESTROY TARGETS TO ACCESS NEXT SECTION OF RANGE",
    "DESTROY TARGETS TO ACCESS NEXT SECTION OF RANGE",
    "DESTROY TARGETS TO ACCESS NEXT SECTION OF RANGE",
    "DESTROY TARGETS TO COMPLETE RANGE PRACTICE",
    "PRACTICE USING GAS MASK IN TEST CHAMBER",
};

/*01021F30*/
ObjectiveStrInfo gObjectiveStrInfo[MAP_COUNT] = {
    { ARRAY_COUNT(_objectiveStrTable1), _objectiveStrTable1 },
    { ARRAY_COUNT(_objectiveStrTable2), _objectiveStrTable2 },
    { ARRAY_COUNT(_objectiveStrTable3), _objectiveStrTable3 },
    { ARRAY_COUNT(_objectiveStrTable4), _objectiveStrTable4 },
    { ARRAY_COUNT(_objectiveStrTable5), _objectiveStrTable5 },
    { ARRAY_COUNT(_objectiveStrTable6), _objectiveStrTable6 },
    { ARRAY_COUNT(_objectiveStrTable7), _objectiveStrTable7 },
    { ARRAY_COUNT(_objectiveStrTable8), _objectiveStrTable8 },
    { ARRAY_COUNT(_objectiveStrTable9), _objectiveStrTable9 },
    { ARRAY_COUNT(_objectiveStrTable10), _objectiveStrTable10 },
    { ARRAY_COUNT(_objectiveStrTable11), _objectiveStrTable11 },
    { ARRAY_COUNT(_objectiveStrTable12), _objectiveStrTable12 },
    { ARRAY_COUNT(_objectiveStrTable13), _objectiveStrTable13 },
    { ARRAY_COUNT(_objectiveStrTable14), _objectiveStrTable14 },
    { ARRAY_COUNT(_objectiveStrTable15), _objectiveStrTable15 },
    { ARRAY_COUNT(_objectiveStrTable16), _objectiveStrTable16 },
    { ARRAY_COUNT(_objectiveStrTable18), _objectiveStrTable18 },
    { ARRAY_COUNT(_objectiveStrTable17), _objectiveStrTable17 },
    { ARRAY_COUNT(_objectiveStrTable19), _objectiveStrTable19 },
    { ARRAY_COUNT(_objectiveStrTable20), _objectiveStrTable20 },
    { ARRAY_COUNT(_objectiveStrTable21), _objectiveStrTable21 },
    { ARRAY_COUNT(_objectiveStrTable22), _objectiveStrTable22 },
    { ARRAY_COUNT(_objectiveStrTable23), _objectiveStrTable23 },
    { ARRAY_COUNT(_objectiveStrTable24), _objectiveStrTable24 },
};

/*01021FF0*/
char *gMapStrInfo[MAP_COUNT] = {
    "NEW YORK CITY.\nPRESENT DAY.",
    "LIBERTY ISLAND.\nPRESENT DAY.",
    "RUINS OF NEW YORK.\nPOST-APOCALYPSE.\nTHE FUTURE.",
    "MAN MADE ATOLL.\nSOMEWHERE IN THE ATLANTIC OCEAN.\nPOST-APOCALYPSE.\nTHE FUTURE.",
    "EAST COAST BADLANDS.\nPOST-APOCALYPSE. \nTHE FUTURE.",
    "U.S. SPECIAL FORCES BASE.\nEAST COAST BADLANDS.\nPOST-APOCALYPSE. \nTHE FUTURE.",
    "U.S. SPECIAL FORCES BASE.\nEAST COAST BADLANDS.\nPOST-APOCALYPSE. \nTHE FUTURE.",
    "DRY TOWN.\nCALIFORNIA.\n1848.",
    "FEDERAL JAIL.\nNEW MEXICO.\n1848.",
    "CAPTURED PADDLE STEAMER.\nPECOS RIVER, NEW MEXICO.\n1848.",
    "FORT ROSWELL.\nNEW MEXICO.\n1848.",
    "COPPER MINE.\nNEW MEXICO.\n1848.",
    "EARTH'S CORE.\n1848.",
    "WHITECHAPEL.\nLONDON, ENGLAND.\n1888.",
    "HIGHGRAVE CEMETERY.\nLONDON, ENGLAND.\n1888.",
    "AIRSHIP D-LZ129.\nDESTINATION SCOTLAND.\n1888.",
    "DUNROAMIN CASTLE.\nSCOTTISH HIGHLANDS.\n1888.",
    "R.M.S. TITANIC.\nSOMEWHERE ON THE\nATLANTIC OCEAN.\n1912.",
    "DUNROAMIN CASTLE.\nSCOTTISH HIGHLANDS.\n1888.",
    "NEW YORK CITY.\nALTERNATIVE PRESENT.",
    "ALIEN MOTHERSHIP.\nHOVERING ABOVE NEW YORK CITY.\nALTERNATIVE PRESENT.",
    "ROOFTOPS OF NEW YORK CITY.\nALTERNATIVE PRESENT.",
    "",
    "U.S. SPECIAL FORCES BASE.\nSOMEWHERE ON THE\nEASTERN SEABOARD.\nPRESENT DAY.",
};

/*01022050*/
char *gActionStrInfo[17] = {
    "'ACTIVATE' TO USE VIEWSCREEN",
    "'ACTIVATE' TO OPEN DOOR",
    "JUMP HERE",
    "PUSH FORWARD TO CLIMB UP",
    "SHOOT THE GRATING",
    "CROUCH HERE",
    "JUMP IN AND SWIM",
    "ACID BURNS",
    "STEP INTO THE TELEPORT",
    "'ACTIVATE' THE SWITCH TO OPEN DOOR",
    "'B' TO DUCK",
    "USE 'B' TO DUCK",
    "RIDE THE ELEVATOR",
    "FIRE AND CROUCH",
    "DESTROY HYDRANT FOR HEALTH",
    "DESTROY PUMP FOR HEALTH",
    "DESTROY TOILET FOR HEALTH",
};

/*01022094*/
s16 gActionStrInfoCount = ARRAY_COUNT(gActionStrInfo);

/*01022098*/
s32 D_01022098 = 0x20000000;

/*0102209C*/
char *gLicenceStrInfo[35] = {
#if VERSION_PROTO
    "DUKE NUKEM@ ZERO HOUR@ (C)1998",
#else
    "DUKE NUKEM^ ZERO HOUR^ (C)1999",
#endif
    "3D REALMS ENTERTAINMENT.",
    "ALL RIGHTS RESERVED.",
    (char *)&D_01022098,
    "DEVELOPED BY",
    "EUROCOM DEVELOPMENTS, LTD.",
    "UNDER SUBLICENSE FROM GT",
    "INTERACTIVE SOFTWARE CORP.",
    "UNDER LICENSE FROM",
    "3D REALMS ENTERTAINMENT.",
    (char *)&D_01022098,
    "PUBLISHED AND DISTRIBUTED BY",
    "GT INTERACTIVE SOFTWARE CORP.",
    "GT AND THE GT GAMES LOGO ARE",
    "TRADEMARKS AND THE GT LOGO IS A",
    "REGISTERED TRADEMARK OF GT",
    "INTERACTIVE SOFTWARE CORP.",
    "3D REALMS LOGO IS A REGISTERED",
    "TRADEMARK OF 3D REALMS",
    "ENTERTAINMENT. EUROCOM AND THE",
    "EUROCOM LOGO ARE TRADEMARKS OF",
    "EUROCOM DEVELOPMENTS, LTD.",
    (char *)&D_01022098,
    "NINTENDO, THE OFFICIAL SEAL,",
    "NINTENDO 64 AND THE 3-D \"N\" LOGO",
    "ARE TRADEMARKS OF NINTENDO OF",
    "AMERICA, INC.",
    "(C)1996 NINTENDO OF AMERICA, INC.",
    (char *)&D_01022098,
    "ALL OTHER TRADEMARKS ARE THE",
    "PROPERTY OF THEIR RESPECTIVE",
    "COMPANIES.",
    (char *)&D_01022098,
    "LICENSED BY NINTENDO",
    NULL
};

/*01022128*/
s16 gLicenceStrInfoCount = ARRAY_COUNT(gLicenceStrInfo) - 1;

/*0102212C*/
char *gCreditStrInfo[248] = {
    "DUKE NUKEM: ZERO HOUR",
    "DEVELOPED BY",
    "EUROCOM ENTERTAINMENT SOFTWARE",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "PROGRAMMING",
    (char *)&D_01022098,
    "SIMON MILLS",
    "STEF WALKER",
    "KEV GRANTHAM",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "TOOLS PROGRAMMING",
    (char *)&D_01022098,
    "ANDY MITCHELL",
    "DAVE ARNOLD",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "ADDITIONAL PROGRAMMING",
    (char *)&D_01022098,
    "PAUL BATES",
    "ASHLEY FINNEY",
    "TIM ROGERS",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "LEVEL DESIGN",
    (char *)&D_01022098,
    "BILL BEACHAM",
    "ROB CRAVEN",
    "KEV HARVEY",
    "AARON JENKINS",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "2D GRAPHICS",
    (char *)&D_01022098,
    "LEE AMES",
    "ANDY BEE",
    "ROB BENTON",
    "PAUL ROBINSON",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "3D GRAPHICS",
    (char *)&D_01022098,
    "ANDY BEE",
    "NIGEL BENTLEY",
    "ROB BENTON",
    "CHRIS BOYLE",
    "MATT ELSE",
    "DARREN HYLAND",
    "ADRIAN MANNION",
    "PAUL ROBINSON",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "ANIMATION",
    (char *)&D_01022098,
    "DARREN HYLAND",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "AUDIO",
    (char *)&D_01022098,
    "NEIL BALDWIN",
    "GUY COCKCROFT",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "CONCEPT ART",
    (char *)&D_01022098,
    "ROB BENTON",
    "NICK DRY",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "QUALITY ASSURANCE MANAGER",
    (char *)&D_01022098,
    "MIKE BOTHAM",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "QUALITY ASSURANCE",
    (char *)&D_01022098,
    "PHIL BAKER",
    "JOHN BARKER",
    "ANDY COLLINS",
    "PHIL BENNETT",
    "J.D. BUXTON",
    "MIKE ROBINSON",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "PROJECT MANAGEMENT",
    (char *)&D_01022098,
    "BILL BEACHAM",
    "HUGH BINNS",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "THANKS",
    (char *)&D_01022098,
    "PAUL WRIGHT",
    "MAT SNEAP",
    "ANDY COLLINS",
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    "DUKE NUKEM CREATED AND",
    "LICENSED BY",
    "3D REALMS ENTERTAINMENT",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "QUALITY REVIEW,",
    "AND DESIGN TWEAKS !",
    (char *)&D_01022098,
    "GEORGE BROUSSARD",
    "KEITH SCHULER",
    "SCOTT MILLER",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "SPEECH EDITING",
    (char *)&D_01022098,
    "LEE JACKSON",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "VOICE TALENT",
    (char *)&D_01022098,
    "JON ST. JOHN AS DUKE NUKEM",
    "LANI MINELLA AS FEMALE COMMANDER",
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    "GT INTERACTIVE",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "SENIOR PRODUCER",
    (char *)&D_01022098,
    "RICK RAYMO",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "ASSOC. PRODUCER",
    (char *)&D_01022098,
    "MARIANNE AROTZARENA",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "FORMER UK PRODUCER",
    (char *)&D_01022098,
    "CRAIG LEIGH",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "GT TEST MANAGER",
    (char *)&D_01022098,
    "STEVE KNOPF",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "GT TEST LEAD",
    (char *)&D_01022098,
    "JIM DUNN",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "TESTERS",
    (char *)&D_01022098,
    "JON MARQUETTE",
    "YUME GREGERSON",
    "CHRIS DUNN",
    "JOE ORR",
    "JOSH GALLOWAY",
    "ARLO EVANS",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "LOCALISATION MANAGER",
    (char *)&D_01022098,
    "NEIL MCKENNA",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "LOCALISATION CO-ORDINATOR",
    (char *)&D_01022098,
    "ALEX BUSH",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "SPECIAL THANKS :",
    (char *)&D_01022098,
    "MIKE RYDER",
    "RICH ROBINSON",
    "MARY STEER",
    "HEH-KYU SINCOCK",
    "DAN HARNETT",
    "TONY KEE",
    "MARTIN CURRIE",
    "MARC SWALLOW",
    "GRAEME BOXALL",
    "PAUL FOX",
    "KEN LOBB",
    "LEE KIRTON",
    "GREG WILLIAMS",
    "TREVOR BARNES",
    "MARY GERADI",
    "DEAN GLOSTER",
    "GLEN BRODERICK",
    "PETE STERN",
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    "THE MARIO CLUB",
    (char *)&D_01022098,
    "DEREK WHIPPLE",
    "TIM WALKER",
    (char *)&D_01022098,
    "STEVE BOLENDER",
    "TODD GARDINER",
    "JON HAMAKER",
    "ELAINE HUTCHISON",
    "PHILL SANDHOP",
    "CALVIN SMITH",
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    (char *)&D_01022098,
    NULL
};

/*0102250C*/
s16 gCreditStrInfoCount = ARRAY_COUNT(gCreditStrInfo) - 1;

/*.text*/
#endif
