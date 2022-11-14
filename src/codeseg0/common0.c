#include "common.h"
#include "codeseg0/common0.h"
#include "libultra/src/os/osint.h"
#include "libultra/src/io/controller.h"
#include "libultra/src/io/piint.h"

extern OSThread __osThreadSave;
extern OSPiHandle __Dom1SpeedParam;
extern OSPiHandle __Dom2SpeedParam;
extern __OSInode __osPfsInodeCache;
extern u32 __osFinalrom;
extern OSMesgQueue __osSiAccessQueue;

/*.text*/
