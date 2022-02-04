.text

.global main
main:
	li x11, 0            #loop variable
	lw x4, arrlen	 	 #array length
	li x5, 0			 #temporarily hold count
	lw x8, target		 #target

	lui x6, %hi(arr)
	addi x6, x6, %lo(arr)

loop:
	bge x11, x4, afterLoop
	slli x7, x11, 2
	add x7, x7, x6
	lw x9, 0(x7)
	bne x9, x8, afterIncrementCount
	addi x5, x5, 1

afterIncrementCount:
	addi x11, x11, 1
	j loop


afterLoop:
	lui x11, %hi(count)
	addi x11, x11, %lo(count)
	sw x5, 0(x11)
	# YOU SHOULD NOT ADD ANY CODE PAST THIS POINT.
end:
	j end
	.end
