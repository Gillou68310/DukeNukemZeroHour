#include "common.h"
#include "static/strinfo.h"

/*.data*/

/*01021560*/
char *gWeaponStrInfo[125] = {
    "BLASTER M-80",
    NULL,
    "MUNITIONS BLASTER",
    NULL,
    NULL,
    "FUSIL A POMPE CAL. 12",
    NULL,
    "CARTOUCHES",
    NULL,
    NULL,
    "CHARGEUR AUTOMATIQUE",
    "FUSIL MITRAILLEUR MP-10",
    NULL,
    "CHARGEUR MP-10",
    NULL,
    NULL,
    "LANCE-GRENADES AGL-9",
    NULL,
    "GRENADES",
    NULL,
    NULL,
    "GRENADES AU CYANURE",
    NULL,
    NULL,
    "GRENADE TELECOMM.",
    NULL,
    "GRENADES TELECOMM.",
    NULL,
    "BLASTER CRYOGENIQUE",
    NULL,
    "CRISTAUX CRYOGENIQUES",
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    "CANON GAMMA",
    NULL,
    "CRISTAL GAMMA",
    NULL,
    NULL,
    "LANCE-MISSILES DEVAST.",
    NULL,
    "MISSILE DEVASTATEUR",
    NULL,
    NULL,
    "ROQUETTES TETE CHERCH.",
    NULL,
    "BOMBE LASER CTX-2000",
    NULL,
    NULL,
    "BOMBE LASER",
    NULL,
    "CANON A PLASMA BMF",
    NULL,
    "MUNITIONS BMF",
    NULL,
    NULL,
    NULL,
    "PACIFICATEUR .45",
    NULL,
    "MUNITIONS .45",
    NULL,
    NULL,
    "ULTRA MAGNUMS .45",
    "FUSIL A CANON SCIE",
    NULL,
    "CARTOUCHES",
    NULL,
    NULL,
    "CANON ELECTRIQUE",
    NULL,
    "BATTERIE",
    NULL,
    NULL,
    "DYNAMITE",
    NULL,
    "CAISSE DE DYNAMITE",
    NULL,
    "EXPLOSIFS",
    NULL,
    "CAISSE D'EXPLOSIFS",
    NULL,
    "TIME VORTEX",
    NULL,
    NULL,
    "FUSIL 30-30",
    NULL,
    "CARTOUCHES DU FUSIL",
    NULL,
    NULL,
    "MITRAILLEUSE GATTLING",
    NULL,
    "MUNITIONS MITRAIL.",
    NULL,
    NULL,
    "POINTS DE VIE : + 10",
    "POINTS DE VIE : + 30",
    "POINTS DE VIE : + 30",
    "POINTS DE VIE : + 30",
    "KIT DE PREMIER SECOURS",
    "TROUSSE DE SOINS",
    "TROUSSE DE SOINS",
    "PROTECTIVE BOOTS",
    "ARMURE",
    NULL,
    "ARMURE DE CUIR",
    NULL,
    "ARMURE",
    NULL,
    "VITAMINE X",
    "LUNETTES A INFRAROUGE",
    "MASQUE A GAZ",
    "TUBA",
    "CASQUE DE SCAPHANDRE",
    "SUPER-CRYO CRYSTALS",
    "BOMBES LASER",
    "FUSIL DE SNIPER .50",
    "MUNITIONS POUR .50",
    "BALLES ANTI-ARMURE ",
    "TELESCOPIC SIGHT",
    "LANCE-GREN. CYANURE",
    "PIEGE A OURS",
    "PECHE D'ENFER",
};

/*01021754*/
s16 gWeaponStrInfoCount = ARRAY_COUNT(gWeaponStrInfo);

/*01021758*/
static char *_keyStrTable1[KEY_STRINFO_NUM] = {
    "CARTE A CODE TRANSTEK",
    "",
    "",
    "",
    "",
    "",
    "",
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
static char *_keyStrTable2[KEY_STRINFO_NUM] = {
    "CLE DE COMMANDE",
    "PASSE ASCENSEUR DE SERVICE",
    "CLE DE LA STATION DE POMPAGE",
    "",
    "",
    "",
    "",
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
static char *_keyStrTable3[KEY_STRINFO_NUM] = {
    "BATTERIE ALPHA",
    "BATTERIE BETA",
    "BATTERIE DELTA",
    "",
    "",
    "",
    "",
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
static char *_keyStrTable4[KEY_STRINFO_NUM] = {
    "",
    "",
    "",
    "",
    "",
    "",
    "",
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
static char *_keyStrTable5[KEY_STRINFO_NUM] = {
    "LABORATORY KEY",
    "CLE DE L'ARMURERIE",
    "",
    "",
    "",
    "",
    "",
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
static char *_keyStrTable6[KEY_STRINFO_NUM] = {
    "",
    "",
    "",
    "",
    "",
    "",
    "",
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
static char *_keyStrTable7[KEY_STRINFO_NUM] = {
    "CLE DE LA TOUR DE GARDE",
    "",
    "",
    "",
    "",
    "",
    "",
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
static char *_keyStrTable8[KEY_STRINFO_NUM] = {
    "CLE DE L'HOTEL",
    "CLE DU SALOON",
    "PLANS EXTRATERRESTRES",
    "",
    "",
    "",
    "",
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
static char *_keyStrTable9[KEY_STRINFO_NUM] = {
    "",
    "CLE DU BLOC EST",
    "CLE DU BLOC NORD",
    "UN COUP DE MAIN",
    "CLE DU BLOC SUD ",
    "",
    "",
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
static char *_keyStrTable10[KEY_STRINFO_NUM] = {
    "PASSE DE SECURITE NIVEAU 1",
    "PASSE DE SECURITE NIVEAU 2",
    "CLE DES COULISSES",
    "PASSE DE SECURITE NIVEAU 3",
    "PASSE DE SECURITE NIVEAU 4",
    "",
    "",
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
static char *_keyStrTable11[KEY_STRINFO_NUM] = {
    "CLE DE LA TOUR DE GARDE",
    "CLE DE LA CASERNE",
    "",
    "",
    "",
    "",
    "",
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
static char *_keyStrTable12[KEY_STRINFO_NUM] = {
    "",
    "",
    "",
    "",
    "",
    "",
    "",
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
static char *_keyStrTable13[KEY_STRINFO_NUM] = {
    "",
    "",
    "",
    "",
    "",
    "",
    "",
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
static char *_keyStrTable14[KEY_STRINFO_NUM] = {
    "",
    "",
    "",
    "",
    "",
    "",
    "",
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
static char *_keyStrTable15[KEY_STRINFO_NUM] = {
    "CLE DE LA CRYPTE",
    "",
    "",
    "",
    "",
    "",
    "",
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
static char *_keyStrTable16[KEY_STRINFO_NUM] = {
    "PASSE-PARTOUT",
    "",
    "",
    "",
    "",
    "",
    "",
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
static char *_keyStrTable17[KEY_STRINFO_NUM] = {
    "CLE DU PONT 3EME CLASSE",
    "",
    "",
    "",
    "",
    "",
    "",
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
static char *_keyStrTable18[KEY_STRINFO_NUM] = {
    "CLE DE LA COUR",
    "CLE DU GRAND HALL",
    "PIERRE DE CATAPULTE",
    "TETE D'EXECUTEUR CYBORG",
    "",
    "",
    "",
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
static char *_keyStrTable19[KEY_STRINFO_NUM] = {
    "",
    "",
    "",
    "",
    "",
    "",
    "",
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
static char *_keyStrTable20[KEY_STRINFO_NUM] = {
    "",
    "",
    "",
    "",
    "",
    "",
    "",
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
static char *_keyStrTable21[KEY_STRINFO_NUM] = {
    "",
    "",
    "",
    "",
    "",
    "",
    "",
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
static char *_keyStrTable22[KEY_STRINFO_NUM] = {
    "",
    "",
    "",
    "",
    "",
    "",
    "",
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
static char *_keyStrTable23[KEY_STRINFO_NUM] = {
    "TETE D'EXECUTEUR CYBORG",
    "BIO-EMETTEUR",
    "TETE D'EXECUTEUR CYBORG",
    "",
    "",
    "",
    "",
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
static char *_keyStrTable24[KEY_STRINFO_NUM] = {
    "",
    "",
    "",
    "",
    "",
    "",
    "",
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
    "TROUVEZ UN MOYEN D'ATTEINDRE LA STATUE DE LA LIBERTE",
    "TROUVEZ DES SURVIVANTS PARMI LES SOLDATS ET FAITES-LES PARLER",
    "RETOURNEZ AU PARKING OU VOUS AVEZ RENDEZ-VOUS AVEC DES RENFORTS",
    "TROUVEZ LA CENTRALE ELECTRIQUE ET COUPEZ LE COURANT DANS LA STATION DE METRO",
    "ALLEZ A LA STATION DE METRO ET TROUVEZ LE TUNNEL D'ACCES SOUTERRAIN",
};

/*01021DCC*/
static char *_objectiveStrTable2[6] = {
    "TROUVEZ LE QG DES ALIENS ET DETRUISEZ-LE",
    "ENTREZ DANS LA STATUE",
    "TROUVEZ LA CLE DE COMMANDE DU DEVERSOIR",
    "INONDEZ LE TUNNEL D'ACCES A L'AIDE DE LA STATION DE POMPAGE",
    "PRENEZ L'ASCENSEUR DE SERVICE POUR ACCEDER AU CENTRE DES VISITEURS",
    "REACTIVEZ L'ASCENSEUR ET MONTEZ DANS LA TETE DE LA STATUE.",
};

/*01021DE4*/
static char *_objectiveStrTable3[7] = {
    "RETABLISSEZ LE CONTACT AVEC LE QG",
    "TROUVEZ DES SIGNES DE VIE",
    "TROUVEZ LA BATTERIE ALPHA",
    "TROUVEZ LA BATTERIE BETA",
    "TROUVEZ LA BATTERIE DELTA",
    "ALLUMEZ LE PHARE",
    "ATTENDEZ L'HELICOPTERE",
};

/*01021E00*/
static char *_objectiveStrTable4[1] = {
    "TROUVEZ LA MONTGOLFIERE POUR FUIR L'ATOLL ARTIFICIEL"
};

/*01021E04*/
static char *_objectiveStrTable5[4] = {
    "ALLEZ A LA BASE MILITAIRE",
    "EXPLOREZ LES ENVIRONS",
    "DESACTIVEZ LE LE GENERATEUR DE CHAMP MAGNETIQUE DES ALIENS",
    "DIRIGEZ-VOUS VERS LA BASE",
};

/*01021E14*/
static char *_objectiveStrTable6[5] = {
    "ACCEDEZ A LA BASE ET PROTEGEZ LES SURVIVANTS",
    "ALLEZ A L'ENTREE PRINCIPALE",
    "RENDEZ-VOUS AU CENTRE MEDICAL ET ACTIVEZ LA PORTE DES LABORATOIRES TEMPORELS",
    "EMPRUNTEZ LA PORTE LATERALE DE LA SALLE DE LA MACHINE A REMONTER LE TEMPS",
    "ACTIVEZ LE SYSTEME DE DEFENSE ARME DES SENTINELLES",
};

/*01021E28*/
static char *_objectiveStrTable7[1] = {
    "ANEANTISSEZ LE SEIGNEUR DES PORCOFLICS"
};

/*01021E2C*/
static char *_objectiveStrTable8[6] = {
    "FAITES SAUTER LE COFFRE DE LA BANQUE POUR DEROBER LES PLANS DES ALIENS",
    "TROUVEZ LE DETONATEUR ",
    "UTILISEZ LA CLE DE L'HOTEL POUR ACCEDER AU FUSIBLE",
    "TROUVEZ LA CLE DU SALOON ET OUVREZ LA 69 MINE",
    "TROUVEZ LA DYNAMITE",
    "FAITES SAUTER LE COFFRE DE LA BANQUE\n",
};

/*01021E44*/
static char *_objectiveStrTable9[4] = {
    "EVADEZ-VOUS DE PRISON",
    "TROUVEZ UNE AME SECOURABLE POUR VOUS AIDER A FUIR",
    "TROUVEZ UN MOYEN DE SORTIR",
    "DECOUVREZ D'OU VIENNENT LES NOUVEAUX SOLDATS CYBORGS",
};

/*01021E54*/
static char *_objectiveStrTable10[4] = {
    "DEMOLISSEZ  L'USINE DE GUERRE DES ALIENS",
    "EMBARQUEZ SUR LE BATEAU",
    "RECHERCHEZ UNE SORTIE",
    "TELEPORT VERS LE FORT ROSWELL",
};

/*01021E64*/
static char *_objectiveStrTable11[5] = {
    "TROUVEZ LA BOMBE DES ALIENS",
    "EVITEZ LES TIRS DES CANONS ET RENDEZ-VOUS AU FORT",
    "ATTENTION AUX PIEGES A L'INTERIEUR ET AUTOUR DU FORT",
    "ELIMINEZ CE TRAITRE DE GENERAL CUSTER",
    "TROUVEZ L'ENTREE DES MINES",
};

/*01021E78*/
static char *_objectiveStrTable12[5] = {
    "RECHERCHEZ LA BOMBE DES ALIENS ET DESAMORCEZ-LA",
    "CHERCHEZ UN WAGONNET POUR DESCENDRE PLUS PROFONDÉMENT",
    "MONTEZ DANS LE WAGONNET (N'OUBLIEZ PAS DE SAUTER ET RAMPER)",
    "DÉPLACEZ LA PLAQUE TOURNANTE POUR POURSUIVRE VOTRE TRAJET",
    "DIRIGEZ-VOUS VERS LE CENTRE DE LA TERRE",
};

/*01021E8C*/
static char *_objectiveStrTable13[1] = {
    "ANEANTISSEZ LE CYBER-SCORPION"
};

/*01021E90*/
static char *_objectiveStrTable14[5] = {
    "DETRUISEZ LE VIRUS EXTRATERRESTRE ET TROUVEZ UNE AUTRE MACHINE A REMONTER LE TEMPS",
    "TROUVEZ L'ENTREE DES EGOUTS",
    "TROUVEZ LE CHEMIN POUR MONTER A WHITECHAPEL",
    "TROUVEZ LE PSYCHOPARASITE GEANT ET TUEZ-LE",
    "EVACUEZ LES ENVIRONS",
};

/*01021EA4*/
static char *_objectiveStrTable15[4] = {
    "ALLEZ A L'AERODROME ET PRENEZ LE DIRIGEABLE POUR VOUS RENDRE AU CHATEAU",
    "EXPLOREZ LE CIMETIERE ET TROUVEZ L'ENTREE DU CANAL",
    "SUIVEZ LES CANAUX POUR VOUS RENDRE A L'AERODROME",
    "FAITES UN TOUR DE DIRIGEABLE",
};

/*01021EB4*/
static char *_objectiveStrTable16[4] = {
    "PRENEZ L'AVION DU DIRIGEABLE POUR REJOINDRE LE CHATEAU",
    "ECHAPPEZ-VOUS DE LA SOUTE A BAGAGES.",
    "TROUVEZ LA CLE DU SQUELETTE",
    "TROUVEZ LE MOYEN D'ACCEDER A L'AVION",
};

/*01021EC4*/
static char *_objectiveStrTable17[5] = {
    "EMPECHEZ LE BATEAU D'ATTEINDRE SA DESTINATION",
    "EXPLOREZ LE BATEAU ET TROUVEZ UN MOYEN D'ATTEINDRE LE FOND DE LA CALE",
    "TROUVEZ UN MOYEN DE COULER LE BATEAU",
    "ABANDONNEZ LE BATEAU ET FUYEZ PAR LE PORTAIL DU TEMPS",
    "DETRUISEZ TOUS LES ŒUFS POUR EMPECHER LA PROLIFERATION DES ALIENS"
};

/*01021ED8*/
static char *_objectiveStrTable18[3] = {
    "TROUVEZ LE CERVEAU DES ALIENS",
    "TROUVEZ UN MOYEN D'ENTRER DANS LE CHATEAU",
    "EXPLOREZ LE CHATEAU ET TROUVEZ LE CERVEAU DES ALIENS",
};

/*01021EE4*/
static char *_objectiveStrTable19[2] = {
    "TUEZ LE CERVEAU",
    "DEBRANCHEZ TOUS LES APPAREILS QUI LE MAINTIENNENT EN VIE",
};

/*01021EEC*/
static char *_objectiveStrTable20[3] = {
    "PRENEZ LE CONTROLE DE LA NAVETTE ET MONTEZ A BORD DU VAISSEAU MERE",
    "ANEANTISSEZ LES MECHANTS DUKES",
    "TROUVEZ LA NAVETTE DES ALIENS",
};

/*01021EF8*/
static char *_objectiveStrTable21[5] = {
    "DETRUISEZ LE VAISSEAU EXTRATERRESTRE",
    "TROUVEZ UNE CLE COMPATIBLE POUR SORTIR DE LA NAVETTE",
    "TROUVEZ LE MOYEN DE DESACTIVER LES CHAMPS DE FORCE BIO-SENSIBLES",
    "DESACTIVEZ LES GENERATEURS POUR DETRUIRE LE VAISSEAU",
    "ACCEDEZ AU NID ET DETRUISEZ TOUS LES OEUFS",
};

/*01021F0C*/
static char *_objectiveStrTable22[1] = {
    "TUEZ ZERO"
};

/*01021F10*/
static char *_objectiveStrTable23[1] = {
    "SURVEILLEZ LA SEQUENCE DE FIN"
};

/*01021F14*/
static char *_objectiveStrTable24[7] = {
    "DIRIGEZ-VOUS VERS LE HANGAR ET MONTEZ DANS L'HELICOPTERE QUI VOUS ATTEND",
    "PARCOURS DU COMBATTANT : SAUTEZ, ESCALADEZ, RAMPEZ ET NAGEZ",
    "DETRUISEZ LES CIBLES POUR PASSER A LA PROCHAINE SERIE DE TIRS",
    "DETRUISEZ LES CIBLES POUR PASSER A LA PROCHAINE SERIE DE TIRS",
    "DETRUISEZ LES CIBLES POUR PASSER A LA PROCHAINE SERIE DE TIRS",
    "DETRUISEZ LES CIBLES POUR ACHEVER VOTRE ENTRAINEMENT AU TIR",
    "APPRENEZ A UTILISER LE MASQUE A GAZ DANS LA SALLE D'ENTRAINEMENT",
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
    "VILLE DE NEW YORK.\nDE NOS JOURS.",
    "LIBERTY ISLAND.\nDE NOS JOURS.",
    "LES RUINES DE NEW YORK.\nAPRES L'APOCALYPSE.\nDANS LE FUTUR.",
    "UN ATOLL ARTIFICIEL.\nQUELQUE PART DANS L'ATLANTIQUE.\nAPRES L'APOCALYPSE.\nDANS LE FUTUR.",
    "LES BADLANDS DE LA COTE EST.\nAPRES L'APOCALYPSE. \nDANS LE FUTUR.",
    "BASE DES FORCES SPECIALES U.S.\nLES BADLANDS DE LA COTE EST.\nAPRES L'APOCALYPSE. \nDANS LE FUTUR.",
    "BASE DES FORCES SPECIALES U.S.\nLES BADLANDS DE LA COTE EST.\nAPRES L'APOCALYPSE. \nDANS LE FUTUR.",
    "VILLE FANTOME.\nCALIFORNIE.\n1848.",
    "PRISON FEDERALE.\nNOUVEAU MEXIQUE.\n1848.",
    "VAPEUR A AUBES CAPTURE.\nFLEUVE PECOS, NOUVEAU MEXIQUE.\n1848.",
    "FORT ROSWELL.\nNOUVEAU MEXIQUE.\n1848.",
    "MINE DE CUIVRE.\nNOUVEAU MEXIQUE.\n1848.",
    "AU CENTRE DE LA TERRE.\n1848.",
    "WHITECHAPEL.\nLONDRES, ANGLETERRE.\n1888.",
    "CIMETIERE DE HIGHGRAVE.\nLONDRES, ANGLETERRE.\n1888.",
    "AVION D-LZ129.\nDESTINATIUON ECOSSE.\n1888.",
    "DUNROAMIN CASTLE.\nHIGHLANDS ECOSSAISES.\n1888.",
    "R.M.S. TITANIC.\nQUELQUE PART SUR\nL'OCEAN ATLANTIQUE.\n1912.",
    "DUNROAMIN CASTLE.\nHIGHLANDS ECOSSAISES.\n1888.",
    "VILLE DE NEW YORK.\nUN AUTRE PRESENT.",
    "VAISSEAU AMIRAL EXTRATERRESTRE.\nEN SURVOL DE NEW YORK.\nUN AUTRE PRESENT.",
    "LES TOITS DE NEW YORK.\nUN AUTRE PRESENT.",
    "",
    "BASE DES FORCES SPECIALES U.S.\nQUELQUE PART SUR\nLA COTE EST.\nDE NOS JOURS.",
};

/*01022050*/
char *gActionStrInfo[17] = {
    "'ACTIVER' POUR UTILISER L'ECRAN DE VISION",
    "'ACTIVER' POUR OUVRIR LA PORTE",
    "SAUTEZ ICI",
    "EN AVANT POUR MONTER",
    "TIREZ SUR LA GRILLE",
    "RAMPEZ PAR ICI",
    "SAUTEZ ET NAGEZ",
    "L'ACIDE BRULE",
    "ENTREZ DANS LE TELEPORT",
    "ACTIVER INTER. - OUVRIR LA PORTE",
    "'B' POUR PLONGER",
    "TOUCHE 'B' POUR PLONGER",
    "PRENEZ L'ASCENSEUR",
    "TIREZ ET RAMPEZ",
    "DETRUISEZ LA BOUCHE D'INCENDIE",
    "DETRUISEZ LA POMPE",
    "DETRUISEZ LES TOILETTES",
};

/*01022094*/
s16 gActionStrInfoCount = ARRAY_COUNT(gActionStrInfo);

/*01022098*/
s32 D_01022098 = 0x20000000;

/*0102209C*/
char *gLicenceStrInfo[35] = {
    "DUKE NUKEM^ ZERO HOUR^ (C)1999",
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
    "DUKE NUKEM: AU-DELA DU TEMPS",
    "DEVELOPPE PAR",
    "EUROCOM ENTERTAINMENT SOFTWARE",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "PROGRAMMATION",
    (char *)&D_01022098,
    "SIMON MILLS",
    "STEF WALKER",
    "KEV GRANTHAM",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "PROGRAMMATION DES UTILITAIRES",
    (char *)&D_01022098,
    "ANDY MITCHELL",
    "DAVE ARNOLD",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "PROGRAMMATION COMPLEMENTAIRE",
    (char *)&D_01022098,
    "PAUL BATES",
    "ASHLEY FINNEY",
    "TIM ROGERS",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "CONCEPTION DES NIVEAUX",
    (char *)&D_01022098,
    "BILL BEACHAM",
    "ROB CRAVEN",
    "KEV HARVEY",
    "AARON JENKINS",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "GRAPHIQUES 2D",
    (char *)&D_01022098,
    "LEE AMES",
    "ANDY BEE",
    "ROB BENTON",
    "PAUL ROBINSON",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "GRAPHIQUES 3D",
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
    "CONCEPTION ARTISTIQUE",
    (char *)&D_01022098,
    "ROB BENTON",
    "NICK DRY",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "DIRECTEUR ASSURANCE QUALITE",
    (char *)&D_01022098,
    "MIKE BOTHAM",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "ASSURANCE QUALITE",
    (char *)&D_01022098,
    "PHIL BAKER",
    "JOHN BARKER",
    "ANDY COLLINS",
    "PHIL BENNETT",
    "J.D. BUXTON",
    "MIKE ROBINSON",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "GESTION DE PROJET",
    (char *)&D_01022098,
    "BILL BEACHAM",
    "HUGH BINNS",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "REMERCIEMENTS A",
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
    "DUKE NUKEM LICENCE PAR CREES",
    "PAR",
    "3D REALMS ENTERTAINMENT",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "CONTROLE DE QUALITE,",
    "APPROBATION ET MISE EN CONFORMITE",
    (char *)&D_01022098,
    "GEORGE BROUSSARD",
    "KEITH SCHULER",
    "SCOTT MILLER",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "MONTAGE DES VOIX",
    (char *)&D_01022098,
    "LEE JACKSON",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "VOIX DE",
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
    "PRODUCTION",
    (char *)&D_01022098,
    "RICK RAYMO",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "PRODUCTION ASSOCIEE",
    (char *)&D_01022098,
    "MARIANNE AROTZARENA",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "PRODUCTION GRANDE-BRETAGNE PRECEDENTE",
    (char *)&D_01022098,
    "CRAIG LEIGH",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "DIRECTION DES TESTS GT",
    (char *)&D_01022098,
    "STEVE KNOPF",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "CHEF DES TESTS GT",
    (char *)&D_01022098,
    "JIM DUNN",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "TESTUERS",
    (char *)&D_01022098,
    "JON MARQUETTE",
    "YUME GREGERSON",
    "CHRIS DUNN",
    "JOE ORR",
    "JOSH GALLOWAY",
    "ARLO EVANS",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "RESPONSABLE LOCALISATION",
    (char *)&D_01022098,
    "NEIL MCKENNA",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "COORDINATION DE LOCALISATION",
    (char *)&D_01022098,
    "ALEX BUSH",
    (char *)&D_01022098,
    (char *)&D_01022098,
    "REMERCIEMENTS PARTICULIERS A :",
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
