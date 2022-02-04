.text
.global main
main:
	li a0, 0x500FE800
    li t0, 'P'
    sb t0, 0(a0)
    li t0, 'o'
    sb t0, 1(a0)
    li t0, 'k'
    sb t0, 2(a0)
    li t0, 'e'
    sb t0, 3(a0)
    li t0, 'm'
    sb t0, 4(a0)
    li t0, 'o'
    sb t0, 5(a0)
    li t0, 'n'
    sb t0, 6(a0)
    li t0, '!'
    sb t0, 7(a0)
end:
    j end
