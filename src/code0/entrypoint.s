#include <regdef.h>
#include <sys/asm.h>

.set noreorder
.text
LEAF(start)
    la         t0, code0_BSS_START
    lui        t1, %hi(code0_BSS_SIZE)
    addiu      t1, %lo(code0_BSS_SIZE)
.loop:
    sw         zero, 0x0(t0)
    sw         zero, 0x4(t0)
    addi       t0, t0, 0x8
    addi       t1, t1, -0x8
    bnez       t1, .loop
    nop
    la         t2, boot
    lui        sp, %hi(bootStackAddress)
    jr         t2
    addiu      sp, sp, %lo(bootStackAddress)
    nop
    nop
END(start)