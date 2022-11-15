#include "common.h"
#include "codeseg0/common0.h"
#include "libultra/src/os/osint.h"
#include "libultra/src/io/controller.h"
#include "libultra/src/io/piint.h"
#include "libkmc/include/errno.h"
#include "libmus/src/aud_thread.h"
#include "libmus/src/player_fx.h"

/*libultra*/
extern OSThread __osThreadSave;
extern OSPiHandle __Dom1SpeedParam;
extern OSPiHandle __Dom2SpeedParam;
extern __OSInode __osPfsInodeCache;
extern u32 __osFinalrom;
extern OSMesgQueue __osSiAccessQueue;

/*libmus*/
extern unsigned long __muscontrol_flag;
extern OSPiHandle *diskrom_handle;

/*.text*/
