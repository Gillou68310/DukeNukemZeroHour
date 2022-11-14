#ifndef _COMMON0_H_
#define _COMMON0_H_

#include "common.h"
#include "PR/sched.h"

extern s32 D_800FE3F4;                                      /*800FE3F4*/
extern s16 D_800FE416;                                      /*800FE416*/
extern s64 D_800FE9E0;                                      /*800FE9E0*/
extern void *gFramebuffer[3];                               /*800FF530*/
extern ProcPointer D_800FF53C;                              /*800FF53C*/
extern typesUnkStruct5 D_800FF540[2048];                    /*800FF540*/
extern u8 D_80106D30[4];                                    /*80106D30*/
extern s16 D_80106D50[1500];                                /*80106D50*/
extern s32 D_8010A938;                                      /*8010A938*/
extern typesUnkStruct2 D_8010A940[4];                       /*8010A940*/
extern typesUnkStruct1 D_80117ED8[4];                       /*80117ED8*/
extern u8 D_80118148;                                       /*80118148*/
extern s32 D_80118160;                                      /*80118160*/   /*gfx debug time*/
extern s32 D_80119A5C;                                      /*80119A5C*/
extern OSMesgQueue D_80119A78;                              /*80119A78*/
extern Dynamic gDynamic[GFX_TASKS];                         /*8011BC60*/
extern Gfx* D_801297E0[8];                                  /*801297E0*/
extern s16 D_8012C470;                                      /*8012C470*/
extern OSViMode *D_8012E158;                                /*8012E158*/
extern s32 D_8012FC90;                                      /*8012FC90*/
extern Gfx *gDisplaylist[GFX_TASKS];                        /*8012FD78*/
extern char *gStaticSegment;                                /*80138684*/
extern OSTime D_80138688;                                   /*80138688*/
extern void *gDepthBuffer;                                  /*80138864*/
extern s16 D_80168D0C;                                      /*80168D0C*/
extern s32 D_80168D18;                                      /*80168D18*/
extern Vtx *gpVertex;                                       /*8016D170*/
extern u8 D_8016D174[4];                                    /*8016D174*/
extern Vtx *gVertex[GFX_TASKS];                             /*8016D184*/
extern OSMesgQueue dmaMessageQ;                             /*80197D58*/
extern s32 D_80197DE0;                                      /*80197DE0*/
extern s32 D_80199524;                                      /*80199524*/
extern typesUnkStruct3 D_8019B940[150];                     /*8019B940*/
extern typesUnkStruct4 D_801A1958;                          /*801A1958*/
extern s32 D_801A1970;                                      /*801A1970*/
extern u8 D_801A19EC;                                       /*801A19EC*/
extern u64 gfxYieldBuf[OS_YIELD_DATA_SIZE / sizeof(u64)];   /*801A1A20*/
extern OSSched D_801A6AF8;                                  /*801A6AF8*/
extern OSMesgQueue gfxFrameMsgQ;                            /*801AC8B8*/
extern OSScTask gGfxTask[GFX_TASKS];                        /*801ACB00*/
extern u8 D_801AD470;                                       /*801AD470*/
extern s64 D_801AE498;                                      /*801AE498*/
extern s32 D_801AE528;                                      /*801AE528*/
extern s32 D_801AE8B8;                                      /*801AE8B8*/
extern s32 D_801AE8FC;                                      /*801AE8FC*/
extern s32 D_801AE914;                                      /*801AE914*/
extern u64 gDramStack[SP_DRAM_STACK_SIZE64];                /*801AEA40*/
extern Gfx *gpDisplaylist;                                  /*801B0808*/
extern u64 gOutputBuffer[OUTPUT_BUFFER_SIZE / sizeof(u64)]; /*801B0D40*/
extern Dynamic *gpDynamic;                                  /*801C0D60*/

#endif