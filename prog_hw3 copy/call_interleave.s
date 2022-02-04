.data

inputArr1:
    .word 1, 2, 3, 4
inputArr2:
    .word 5, 6, 7, 8
outputArr:
    # Repeat `.word -1` eight times.
    .rept 8
    .word -1
    .endr
arrlen:
    .word 4

.text
.global main
main:
    lui a0, %hi(inputArr1)
    addi a0, a0, %lo(inputArr1)
    lui a1, %hi(inputArr2)
    addi a1, a1, %lo(inputArr2)
    lui a2, %hi(outputArr)
    addi a2, a2, %lo(outputArr)
    lui a3, %hi(arrlen)
    addi a3, a3, %lo(arrlen)
    jal ra, interleave
end:
    j end
