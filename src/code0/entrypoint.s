#include <regdef.h>
#include <sys/asm.h>

#define BSS_SIZE 0xD6680

.set noreorder
.text
LEAF(start)
    la         t0, code0SegmentBssStart
    lui        t1, (BSS_SIZE >> 16)
    addiu      t1, (BSS_SIZE & 0xFFFF)
.loop:
    sw         zero, 0x0(t0)
    sw         zero, 0x4(t0)
    addi       t0, t0, 0x8
    addi       t1, t1, -0x8
    bnez       t1, .loop
    nop
    la         t2, boot
    lui        sp, %hi(bootStack)
    jr         t2
    addiu      sp, sp, %lo(bootStack)
    nop
END(start)