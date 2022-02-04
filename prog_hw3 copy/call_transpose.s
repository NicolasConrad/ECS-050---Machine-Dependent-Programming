.data

input:
    .word 1
    .word 2
    .word 3
    .word 4
    .word 5
    .word 6

output:
    .rept 6
    .word 0
    .endr

.text
.global main
main:
    lui a0, %hi(input)
    addi a0, a0, %lo(input)
    li a1, 3
    li a2, 2
    lui a3, %hi(output)
    addi a3, a3, %lo(output)
    jal transpose
end:
    j end
