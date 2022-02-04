.section .init, "ax"

# I put some garbage here in order to make the entry address of this cartridge not be obvious.
abcdefg:
    j abcdefg
abcdefg2:
    j abcdefg2
abcdefg3:
    j abcdefg3
    lw t0, 0(s0)
    lw t0, 0(s0)
    lw t0, 0(s0)
    lw t0, 0(s0)
    lw t0, 0(s0)
    lw t0, 0(s0)
    lw t0, 0(s0)

.global _start
_start:
    .cfi_startproc
    .cfi_undefined ra
    .option push
    .option norelax
    la gp, __global_pointer$
    .option pop
    la sp, __stack_top
    add s0, sp, zero
    jal ra, init
    nop
    jal zero, main
    .cfi_endproc
    .end
