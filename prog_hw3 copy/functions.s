.text

#ROTATE FUNCTION

.global rotate
rotate:
	li x4, 0 #loop variable
	li x5, 0 #hold previous index value
	li x6, 0
	li x13, 0
	li x12, 0 #first element loop variable
	mv x9, a1
	addi x9, x9, -1

firstElement:
	bge x12, x9, setFirstElement
	addi x13, x13, 4
	addi x12, x12, 1
	j firstElement

setFirstElement:
	add x13, x13, a0
	lw x5, 0(x13)

rotateLoop:
	bge x4, a1, afterRotateLoop

	slli x6, x4, 2
	add x6, x6, a0

	lw x8, 0(x6)   #temp hold current value
	sw x5, 0(x6)   #val of x5(previous index val),placed in current ind
	mv x5, x8

	addi x4, x4, 1

	j rotateLoop

afterRotateLoop:
	jalr x0, 0(ra)



#INTERLEAVE FUNCTION

.global interleave
interleave:
	li x4, 0 #loop variable
	lw x15, 0(a3) #array length
interleaveLoop:
	bge x4, x15, afterInterleaveLoop
	slli x5, x4, 2
	add x6, x5, a0		#address of first arr
	add x7, x5, a1		#address of second arr

	lw x8, 0(x6)
	sw x8, 0(a2)

	lw x9, 0(x7)
	sw x9, 4(a2)
	addi a2, a2, 8

	addi x4, x4, 1

	j interleaveLoop

afterInterleaveLoop:
	jalr x0, 0(ra)
    

#TRANSPOSE FUNCTION

.global transpose
transpose:
	addi sp, sp, -4
	lw x4, 0(sp)
	addi sp, sp, -4
	lw x9, 0(sp)
	addi sp, sp, -4
	lw x8, 0(sp)
	addi sp, sp, -4
	lw x6, 0(sp)
	addi sp, sp, -4
	lw x14, 0(sp)
	addi sp, sp, -4
	lw x5, 0(sp)
	addi sp, sp, -4
	lw x7, 0(sp)
	addi sp, sp, -4
	lw x15, 0(sp)

	li x4, 0 	#loop variable
	li x9, 0 	#col loop variable
	li x8, 0
	li x6, 4
	li x14, 0
	mul x5, x6, a2

transposeLoop:
	bge x4, a2, afterTransposeLoop
	
colLoop:
	bge x9, a1, endLoop

	slli x7, x4, 2

#loop through to left shift proper amount

increment:
	bge x8, x9, afterIncrement
	add x14, x14, x5
	addi x8, x8, 1
	j increment

afterIncrement:

	add x7, x7, x14
	add x7, x7, a0

	lw x15, 0(x7)
	sw x15, 0(a3)
	addi a3, a3, 4

	li x8, 0
	li x14, 0
	addi x9, x9, 1
	j colLoop

endLoop:
	li x9, 0 	#reset x9
	addi x4, x4, 1
	j transposeLoop

afterTransposeLoop:
	lw x15, 0(sp)
	addi sp, sp, 4
	lw x7, 0(sp)
	addi sp, sp, 4
	lw x5, 0(sp)
	addi sp, sp, 4
	lw x14, 0(sp)
	addi sp, sp, 4
	lw x6, 0(sp)
	addi sp, sp, 4
	lw x8, 0(sp)
	addi sp, sp, 4
	lw x9, 0(sp)
	addi sp, sp, 4
	lw x4, 0(sp)
	addi sp, sp, 4
	jalr x0, 0(ra)
