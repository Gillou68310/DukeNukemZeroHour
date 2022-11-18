#include "common.h"
#include "codeseg0/71F0.h"
#include "codeseg0/common0.h"

#define CHUNK_SIZE 0x4000

extern s8 D_800BD618;

/*.text*/

void dmaRead(char* romStart, char* segStart, s32 size) {
    OSIoMesg dmaIOMessageBuf;
    s32 chunkSize;

    osInvalDCache(segStart, size);
    if (size != 0) {
        do {
            chunkSize = size;
            if (size > CHUNK_SIZE) {
                chunkSize = CHUNK_SIZE;
            }
            osPiStartDma(&dmaIOMessageBuf, OS_MESG_PRI_NORMAL, OS_READ, (u32)romStart, segStart, chunkSize, &gDmaMessageQ);
            romStart += chunkSize;
            segStart += chunkSize;
            size -= chunkSize;
            osRecvMesg(&gDmaMessageQ, NULL, 1);
        } while (size != 0);
    }
}

INCLUDE_ASM(s32, "src/codeseg0/71F0", func_800066A8);

INCLUDE_ASM(s32, "src/codeseg0/71F0", func_80006760);

INCLUDE_ASM(s32, "src/codeseg0/71F0", func_800067B4);

INCLUDE_ASM(s32, "src/codeseg0/71F0", func_80006808);

INCLUDE_ASM(s32, "src/codeseg0/71F0", func_80006838);

INCLUDE_ASM(s32, "src/codeseg0/71F0", func_80006938);

INCLUDE_ASM(s32, "src/codeseg0/71F0", func_800069D8);

INCLUDE_ASM(s32, "src/codeseg0/71F0", func_80006BA0);

INCLUDE_ASM(s32, "src/codeseg0/71F0", func_80006CC0);

INCLUDE_ASM(s32, "src/codeseg0/71F0", func_80006E60);

INCLUDE_ASM(s32, "src/codeseg0/71F0", func_80006F08);

INCLUDE_ASM(s32, "src/codeseg0/71F0", func_80007084);

INCLUDE_ASM(s32, "src/codeseg0/71F0", func_80007170);

INCLUDE_ASM(s32, "src/codeseg0/71F0", func_80007218);

INCLUDE_ASM(s32, "src/codeseg0/71F0", func_8000730C);

INCLUDE_ASM(s32, "src/codeseg0/71F0", func_80007418);

INCLUDE_ASM(s32, "src/codeseg0/71F0", func_80007510);

INCLUDE_ASM(s32, "src/codeseg0/71F0", func_800075EC);

INCLUDE_ASM(s32, "src/codeseg0/71F0", func_800077F4);

INCLUDE_ASM(s32, "src/codeseg0/71F0", func_80007820);

INCLUDE_ASM(s32, "src/codeseg0/71F0", func_8000784C);

INCLUDE_ASM(s32, "src/codeseg0/71F0", func_80007A44);

INCLUDE_ASM(s32, "src/codeseg0/71F0", func_80007A80);

INCLUDE_ASM(s32, "src/codeseg0/71F0", func_80007AB8);

INCLUDE_ASM(s32, "src/codeseg0/71F0", func_80007FF4);

INCLUDE_ASM(s32, "src/codeseg0/71F0", func_800080E0);

INCLUDE_ASM(s32, "src/codeseg0/71F0", func_80008574);

INCLUDE_ASM(s32, "src/codeseg0/71F0", func_80008604);

INCLUDE_ASM(s32, "src/codeseg0/71F0", func_800086B0);

INCLUDE_ASM(s32, "src/codeseg0/71F0", func_80008710);
