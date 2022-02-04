.data

arr:
    .word 10, 20, 30, 40, 50

.text
.global main
main:
    lui a0, %hi(arr)
    addi a0, a0, %lo(arr)
    li a1, 5
    jal ra, rotate
end:
    j end
