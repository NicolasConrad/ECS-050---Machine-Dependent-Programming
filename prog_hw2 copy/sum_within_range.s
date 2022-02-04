.text

.global main
main:
	li x11, 0   
	lw x4, arrlen	
	lw x5, low
	lw x6, high
	li x10, 0

	lui x7, %hi(arr)
	addi x7, x7, %lo(arr)

loop:
	bge x11, x4, afterLoop
	slli x8, x11, 2
	add x8, x8, x7
	lw x9, 0(x8)
	blt x9, x5, outsideRange
	bgt x9, x6, outsideRange
	add x10, x10, x9

outsideRange:
	addi x11, x11, 1
	j loop

afterLoop:
	lui x6, %hi(sum)
	addi x6, x6, %lo(sum)
	sw x10, 0(x6)

	# YOU SHOULD NOT ADD ANY CODE PAST THIS POINT.
end:
	j end
	.end
