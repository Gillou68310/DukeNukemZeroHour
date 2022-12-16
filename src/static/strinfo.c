#include "common.h"
#include "static/strinfo.h"

/*.data*/

/*01021560*/
char *gWeaponStrInfo[0x7D] = {
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
s16 gWeaponStrInfoCount = sizeof(gWeaponStrInfo) / sizeof(char *);

/*01021758*/
static char *keyStrTable1[0x10] = {
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
static char *keyStrTable2[0x10] = {
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
static char *keyStrTable3[0x10] = {
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
static char *keyStrTable4[0x10] = {
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
static char *keyStrTable5[0x10] = {
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
static char *keyStrTable6[0x10] = {
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
static char *keyStrTable7[0x10] = {
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
static char *keyStrTable8[0x10] = {
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
static char *keyStrTable9[0x10] = {
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
static char *keyStrTable10[0x10] = {
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
static char *keyStrTable11[0x10] = {
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
static char *keyStrTable12[0x10] = {
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
static char *keyStrTable13[0x10] = {
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
static char *keyStrTable14[0x10] = {
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
static char *keyStrTable15[0x10] = {
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
static char *keyStrTable16[0x10] = {
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
static char *keyStrTable17[0x10] = {
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
static char *keyStrTable18[0x10] = {
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
static char *keyStrTable19[0x10] = {
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
static char *keyStrTable20[0x10] = {
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
static char *keyStrTable21[0x10] = {
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
static char *keyStrTable22[0x10] = {
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
static char *keyStrTable23[0x10] = {
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
static char *keyStrTable24[0x10] = {
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
char **gKeyStrInfo[0x18] = {
    keyStrTable1,
    keyStrTable2,
    keyStrTable3,
    keyStrTable7,
    keyStrTable4,
    keyStrTable5,
    keyStrTable6,
    keyStrTable8,
    keyStrTable9,
    keyStrTable10,
    keyStrTable11,
    keyStrTable12,
    keyStrTable13,
    keyStrTable14,
    keyStrTable15,
    keyStrTable16,
    keyStrTable18,
    keyStrTable17,
    keyStrTable19,
    keyStrTable21,
    keyStrTable23,
    keyStrTable24,
    keyStrTable24,
    keyStrTable24,
};

/*01021DB8*/
static char *msgStrTable1[5] = {
    "FIND A WAY TO APPROACH THE STATUE OF LIBERTY",
    "LOCATE AND QUESTION SURVIVING SOLDIERS",
    "RETURN TO PARKING LOT TO RENDEZVOUS WITH REINFORCEMENTS",
    "LOCATE ELECTRICAL SUBSTATION AND DEACTIVATE POWER TO SUBWAY STATION",
    "GET TO SUBWAY STATION AND LOCATE UNDERGROUND ACCESS TUNNEL"};

/*01021DCC*/
static char *msgStrTable2[6] = {
    "FIND AND DESTROY THE ALIEN HEADQUARTERS",
    "PROCEED INSIDE THE STATUE",
    "LOCATE OVERFLOW CONTROL KEY",
    "USE PUMPING STATION TO FLOOD ACCESS TUNNEL",
    "USE SERVICE ELEVATOR TO ACCESS VISITOR CENTER",
    "OVERRIDE ELEVATOR LOCKDOWN AND ASCEND TO HEAD OF STATUE",
};

/*01021DE4*/
static char *msgStrTable3[7] = {
    "RE-ESTABLISH CONTACT WITH HQ",
    "FIND SIGNS OF LIFE",
    "LOCATE POWER CELL ALPHA",
    "LOCATE POWER CELL BETA",
    "LOCATE POWER CELL DELTA",
    "POWER UP SIGNAL BEACON",
    "WAIT FOR HELICOPTER",
};

/*01021E00*/
static char *msgStrTable4[1] = {
    "FIND THE BALLOON TO ESCAPE THE MAN-MADE ATOLL"
};

/*01021E04*/
static char *msgStrTable5[4] = {
    "REACH MILITARY BASE",
    "EXPLORE SURROUNDING AREA",
    "DISABLE ALIEN FORCE-FIELD GENERATOR",
    "PROCEED TOWARDS BASE"
};

/*01021E14*/
static char *msgStrTable6[5] = {
    "GAIN ACCESS TO BASE AND PROTECT SURVIVORS",
    "PROCEED TO MAIN ENTRANCE",
    "GET TO MEDICAL AND POWER UP DOOR TO TEMPORAL LABS",
    "ACCESS SIDE DOOR IN TIME MACHINE CHAMBER",
    "ACTIVATE SENTRY GUN DEFENSE SYSTEM"
};

/*01021E28*/
static char *msgStrTable7[1] = {
    "DEFEAT BOSS HOG"
};

/*01021E2C*/
static char *msgStrTable8[6] = {
    "BLOW OPEN THE SAFE IN THE TOWN BANK TO STEAL THE ALIEN PLANS",
    "LOCATE THE PLUNGER DETONATOR",
    "USE THE HOTEL KEY TO GAIN ACCESS TO THE FUSE WIRE",
    "FIND THE SALOON KEY AND OPEN MINER 69'ER",
    "FIND THE TNT",
    "BLOW OPEN THE SAFE IN THE BANK",
};

/*01021E44*/
static char *msgStrTable9[4] = {
    "ESCAPE FROM JAIL",
    "FIND A HELPING HAND TO ESCAPE",
    "FIND A WAY TO BREAK OUT",
    "DISCOVER ORIGIN OF NEW CYBORG SOLDIERS"
};

/*01021E54*/
static char *msgStrTable10[4] = {
    "CLEAR OUT THE ALIEN WAR FACTORY",
    "BOARD THE RIVERBOAT",
    "LOCATE AN EXIT",
    "TELEPORT TO FORT ROSWELL"
};

/*01021E64*/
static char *msgStrTable11[5] = {
    "LOCATE THE ALIEN BOMB",
    "SURVIVE THE CANNON FIRE AND REACH THE FORT",
    "AVOID THE BOOBY TRAPS IN AND AROUND THE FORT",
    "KILL THE TRAITOR GENERAL CUSTER",
    "FIND THE ENTRANCE TO THE MINES"
};

/*01021E78*/
static char *msgStrTable12[5] = {
    "CHASE THE ALIEN BOMB AND DEFUSE THE EXPLOSIVE SITUATION",
    "FIND A MINE CART TO TAKE YOU DEEPER",
    "RIDE THE MINE CART (REMEMBER TO USE JUMP AND CROUCH)",
    "MOVE THE TURNTABLE TO GET YOUR NEXT RIDE",
    "HEAD FOR THE CENTER OF THE EARTH"
};

/*01021E8C*/
static char *msgStrTable13[1] = {
    "DEFEAT THE CYBORG SCORPION"
};

/*01021E90*/
static char *msgStrTable14[5] = {
    "DESTROY ALIEN VIRUS AND FIND ANOTHER TIME MACHINE",
    "LOCATE THE ENTRANCE TO THE SEWERS",
    "LOCATE THE WAY UP TO WHITECHAPEL",
    "FIND AND KILL GIANT PARAPSYCHE",
    "EVACUATE AREA"
};

/*01021EA4*/
static char *msgStrTable15[4] = {
    "PROCEED TO AIRFIELD TO TAKE AIRSHIP TO CASTLE",
    "EXPLORE THE GRAVEYARD AND LOCATE CANAL ENTRANCE",
    "FOLLOW CANALS TO AIRFIELD",
    "CATCH A RIDE ON THE AIRSHIP"
};

/*01021EB4*/
static char *msgStrTable16[4] = {
    "USE THE AIRSHIP'S PLANE TO ESCAPE TO CASTLE",
    "BREAK OUT FROM LUGGAGE HOLD",
    "FIND THE SKELETON KEY",
    "GAIN ACCESS TO THE AIRPLANE"
};

/*01021EC4*/
static char *msgStrTable17[5] = {
    "STOP THE SHIP FROM REACHING ITS DESTINATION",
    "EXPLORE THE SHIP AND FIND A WAY TO REACH THE BOTTOM OF THE HOLD",
    "SINK THE SHIP IN ANY WAY POSSIBLE",
    "ABANDON SHIP AND ESCAPE THROUGH TIME PORTAL",
    "DESTROY ALL EGGS TO BE SURE THE ALIEN MENACE DOESN'T SPREAD"
};

/*01021ED8*/
static char *msgStrTable18[3] = {
    "LOCATE THE ALIEN MASTERMIND",
    "LOCATE AN ENTRANCE TO THE CASTLE",
    "EXPLORE THE CASTLE AND FIND THE LOCATION OF THE ALIEN BRAIN"
};

/*01021EE4*/
static char *msgStrTable19[2] = {
    "KILL THE BRAIN IN A VAT",
    "DEACTIVATE ALL LIFE SUPPORT MACHINES"
};

/*01021EEC*/
static char *msgStrTable20[3] = {
    "HIJACK SHUTTLE TO BOARD MOTHERSHIP",
    "DEFEAT EVIL DUKES",
    "LOCATE ALIEN SHUTTLECRAFT"
};

/*01021EF8*/
static char *msgStrTable21[5] = {
    "DESTROY THE ALIEN SPACECRAFT",
    "LOCATE COMPATIBLE KEY TO ESCAPE SHUTTLE BAY",
    "FIND A WAY TO DEACTIVATE BIO-SENSITIVE FORCEFIELDS",
    "DEACTIVATE GENERATORS TO DESTROY CRAFT",
    "ACCESS NEST AND DESTROY ALL EGGS"
};

/*01021F0C*/
static char *msgStrTable22[1] = {
    "KILL ZERO"
};

/*01021F10*/
static char *msgStrTable23[1] = {
    "WATCH END SEQUENCE"
};

/*01021F14*/
static char *msgStrTable24[7] = {
    "PROCEED TO THE HANGAR AND BOARD THE WAITING HELICOPTER",
    "JUMP, CLIMB, CRAWL AND SWIM ACROSS THE ASSAULT COURSE",
    "DESTROY TARGETS TO ACCESS NEXT SECTION OF RANGE",
    "DESTROY TARGETS TO ACCESS NEXT SECTION OF RANGE",
    "DESTROY TARGETS TO ACCESS NEXT SECTION OF RANGE",
    "DESTROY TARGETS TO COMPLETE RANGE PRACTICE",
    "PRACTICE USING GAS MASK IN TEST CHAMBER",
};

/*01021F30*/
MsgStrInfo gMsgStrInfo[0x18] = {
    { sizeof(msgStrTable1) / sizeof(char *), msgStrTable1 },
    { sizeof(msgStrTable2) / sizeof(char *), msgStrTable2 },
    { sizeof(msgStrTable3) / sizeof(char *), msgStrTable3 },
    { sizeof(msgStrTable4) / sizeof(char *), msgStrTable4 },
    { sizeof(msgStrTable5) / sizeof(char *), msgStrTable5 },
    { sizeof(msgStrTable6) / sizeof(char *), msgStrTable6 },
    { sizeof(msgStrTable7) / sizeof(char *), msgStrTable7 },
    { sizeof(msgStrTable8) / sizeof(char *), msgStrTable8 },
    { sizeof(msgStrTable9) / sizeof(char *), msgStrTable9 },
    { sizeof(msgStrTable10) / sizeof(char *), msgStrTable10 },
    { sizeof(msgStrTable11) / sizeof(char *), msgStrTable11 },
    { sizeof(msgStrTable12) / sizeof(char *), msgStrTable12 },
    { sizeof(msgStrTable13) / sizeof(char *), msgStrTable13 },
    { sizeof(msgStrTable14) / sizeof(char *), msgStrTable14 },
    { sizeof(msgStrTable15) / sizeof(char *), msgStrTable15 },
    { sizeof(msgStrTable16) / sizeof(char *), msgStrTable16 },
    { sizeof(msgStrTable18) / sizeof(char *), msgStrTable18 },
    { sizeof(msgStrTable17) / sizeof(char *), msgStrTable17 },
    { sizeof(msgStrTable19) / sizeof(char *), msgStrTable19 },
    { sizeof(msgStrTable20) / sizeof(char *), msgStrTable20 },
    { sizeof(msgStrTable21) / sizeof(char *), msgStrTable21 },
    { sizeof(msgStrTable22) / sizeof(char *), msgStrTable22 },
    { sizeof(msgStrTable23) / sizeof(char *), msgStrTable23 },
    { sizeof(msgStrTable24) / sizeof(char *), msgStrTable24 },
};

/*01021FF0*/
char *gMapStrInfo[0x18] = {
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
char *gActionStrInfo[0x11] = {
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
s16 gActionStrInfoCount = sizeof(gActionStrInfo) / sizeof(char *);

/*01022098*/
s32 D_1022098 = 0x20000000;

/*0102209C*/
char *gLicenceStrInfo[0x23] = {
    "DUKE NUKEM^ ZERO HOUR^ (C)1999",
    "3D REALMS ENTERTAINMENT.",
    "ALL RIGHTS RESERVED.",
    (char *)&D_1022098,
    "DEVELOPED BY",
    "EUROCOM DEVELOPMENTS, LTD.",
    "UNDER SUBLICENSE FROM GT",
    "INTERACTIVE SOFTWARE CORP.",
    "UNDER LICENSE FROM",
    "3D REALMS ENTERTAINMENT.",
    (char *)&D_1022098,
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
    (char *)&D_1022098,
    "NINTENDO, THE OFFICIAL SEAL,",
    "NINTENDO 64 AND THE 3-D \"N\" LOGO",
    "ARE TRADEMARKS OF NINTENDO OF",
    "AMERICA, INC.",
    "(C)1996 NINTENDO OF AMERICA, INC.",
    (char *)&D_1022098,
    "ALL OTHER TRADEMARKS ARE THE",
    "PROPERTY OF THEIR RESPECTIVE",
    "COMPANIES.",
    (char *)&D_1022098,
    "LICENSED BY NINTENDO",
    NULL
};

/*01022128*/
s16 gLicenceStrInfoCount = (sizeof(gLicenceStrInfo) / sizeof(char *)) - 1;

/*0102212C*/
char *gCreditStrInfo[0xF8] = {
    "DUKE NUKEM: ZERO HOUR",
    "DEVELOPED BY",
    "EUROCOM ENTERTAINMENT SOFTWARE",
    (char *)&D_1022098,
    (char *)&D_1022098,
    "PROGRAMMING",
    (char *)&D_1022098,
    "SIMON MILLS",
    "STEF WALKER",
    "KEV GRANTHAM",
    (char *)&D_1022098,
    (char *)&D_1022098,
    "TOOLS PROGRAMMING",
    (char *)&D_1022098,
    "ANDY MITCHELL",
    "DAVE ARNOLD",
    (char *)&D_1022098,
    (char *)&D_1022098,
    "ADDITIONAL PROGRAMMING",
    (char *)&D_1022098,
    "PAUL BATES",
    "ASHLEY FINNEY",
    "TIM ROGERS",
    (char *)&D_1022098,
    (char *)&D_1022098,
    "LEVEL DESIGN",
    (char *)&D_1022098,
    "BILL BEACHAM",
    "ROB CRAVEN",
    "KEV HARVEY",
    "AARON JENKINS",
    (char *)&D_1022098,
    (char *)&D_1022098,
    "2D GRAPHICS",
    (char *)&D_1022098,
    "LEE AMES",
    "ANDY BEE",
    "ROB BENTON",
    "PAUL ROBINSON",
    (char *)&D_1022098,
    (char *)&D_1022098,
    "3D GRAPHICS",
    (char *)&D_1022098,
    "ANDY BEE",
    "NIGEL BENTLEY",
    "ROB BENTON",
    "CHRIS BOYLE",
    "MATT ELSE",
    "DARREN HYLAND",
    "ADRIAN MANNION",
    "PAUL ROBINSON",
    (char *)&D_1022098,
    (char *)&D_1022098,
    "ANIMATION",
    (char *)&D_1022098,
    "DARREN HYLAND",
    (char *)&D_1022098,
    (char *)&D_1022098,
    "AUDIO",
    (char *)&D_1022098,
    "NEIL BALDWIN",
    "GUY COCKCROFT",
    (char *)&D_1022098,
    (char *)&D_1022098,
    "CONCEPT ART",
    (char *)&D_1022098,
    "ROB BENTON",
    "NICK DRY",
    (char *)&D_1022098,
    (char *)&D_1022098,
    "QUALITY ASSURANCE MANAGER",
    (char *)&D_1022098,
    "MIKE BOTHAM",
    (char *)&D_1022098,
    (char *)&D_1022098,
    "QUALITY ASSURANCE",
    (char *)&D_1022098,
    "PHIL BAKER",
    "JOHN BARKER",
    "ANDY COLLINS",
    "PHIL BENNETT",
    "J.D. BUXTON",
    "MIKE ROBINSON",
    (char *)&D_1022098,
    (char *)&D_1022098,
    "PROJECT MANAGEMENT",
    (char *)&D_1022098,
    "BILL BEACHAM",
    "HUGH BINNS",
    (char *)&D_1022098,
    (char *)&D_1022098,
    "THANKS",
    (char *)&D_1022098,
    "PAUL WRIGHT",
    "MAT SNEAP",
    "ANDY COLLINS",
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    "DUKE NUKEM CREATED AND",
    "LICENSED BY",
    "3D REALMS ENTERTAINMENT",
    (char *)&D_1022098,
    (char *)&D_1022098,
    "QUALITY REVIEW,",
    "AND DESIGN TWEAKS !",
    (char *)&D_1022098,
    "GEORGE BROUSSARD",
    "KEITH SCHULER",
    "SCOTT MILLER",
    (char *)&D_1022098,
    (char *)&D_1022098,
    "SPEECH EDITING",
    (char *)&D_1022098,
    "LEE JACKSON",
    (char *)&D_1022098,
    (char *)&D_1022098,
    "VOICE TALENT",
    (char *)&D_1022098,
    "JON ST. JOHN AS DUKE NUKEM",
    "LANI MINELLA AS FEMALE COMMANDER",
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    "GT INTERACTIVE",
    (char *)&D_1022098,
    (char *)&D_1022098,
    "SENIOR PRODUCER",
    (char *)&D_1022098,
    "RICK RAYMO",
    (char *)&D_1022098,
    (char *)&D_1022098,
    "ASSOC. PRODUCER",
    (char *)&D_1022098,
    "MARIANNE AROTZARENA",
    (char *)&D_1022098,
    (char *)&D_1022098,
    "FORMER UK PRODUCER",
    (char *)&D_1022098,
    "CRAIG LEIGH",
    (char *)&D_1022098,
    (char *)&D_1022098,
    "GT TEST MANAGER",
    (char *)&D_1022098,
    "STEVE KNOPF",
    (char *)&D_1022098,
    (char *)&D_1022098,
    "GT TEST LEAD",
    (char *)&D_1022098,
    "JIM DUNN",
    (char *)&D_1022098,
    (char *)&D_1022098,
    "TESTERS",
    (char *)&D_1022098,
    "JON MARQUETTE",
    "YUME GREGERSON",
    "CHRIS DUNN",
    "JOE ORR",
    "JOSH GALLOWAY",
    "ARLO EVANS",
    (char *)&D_1022098,
    (char *)&D_1022098,
    "LOCALISATION MANAGER",
    (char *)&D_1022098,
    "NEIL MCKENNA",
    (char *)&D_1022098,
    (char *)&D_1022098,
    "LOCALISATION CO-ORDINATOR",
    (char *)&D_1022098,
    "ALEX BUSH",
    (char *)&D_1022098,
    (char *)&D_1022098,
    "SPECIAL THANKS :",
    (char *)&D_1022098,
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
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    "THE MARIO CLUB",
    (char *)&D_1022098,
    "DEREK WHIPPLE",
    "TIM WALKER",
    (char *)&D_1022098,
    "STEVE BOLENDER",
    "TODD GARDINER",
    "JON HAMAKER",
    "ELAINE HUTCHISON",
    "PHILL SANDHOP",
    "CALVIN SMITH",
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    (char *)&D_1022098,
    NULL
};

/*0102250C*/
s16 gCreditStrInfoCount = (sizeof(gCreditStrInfo) / sizeof(char *)) - 1;

/*.text*/
