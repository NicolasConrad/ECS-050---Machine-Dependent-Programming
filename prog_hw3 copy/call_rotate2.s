.data

arr:
    .word 0xAAAAAAAA
    .word 0xBBBBBBBB
    .word 0xCCCCCCCC
    .word 0xDDDDDDDD

.text
.global main
main:
    lui a0, %hi(arr)
    addi a0, a0, %lo(arr)
    li a1, 4
    jal ra, rotate
    jal ra, rotate
end:
    j end
