.text
.global main
main:
	# TODO: Insert your code here.
	
	.equ CARTRIDGE_STATUS, 0x4000001C
	lui s0, %hi(CARTRIDGE_STATUS)
	addi s0, s0, %lo(CARTRIDGE_STATUS)
    li a0, 0x500FE800
    li t0, ' '
    li a1, 0
    li a2, 0x500FE800
    li a3, 2304

clearScreen:
    bge a1, a3, loop
    sb t0, 0(a2)
    addi a1, a1, 1
    addi a2, a2, 1
    j clearScreen
	
loop:
	lw a0, 0(s0)
	.equ INSERTED, 0x1
	andi a1, a0, INSERTED
	addi a0, a0, -1
	bnez a1, cartridge
	j loop

cartridge:
	jalr ra, 0(a0)
	j loop

end:
    j end
