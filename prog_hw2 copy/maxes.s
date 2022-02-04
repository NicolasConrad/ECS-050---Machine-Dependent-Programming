.text

.global main
main:
	lw x4, arrlen 
	li x11, 0 
	li x12, 1

	lui x6, %hi(arr)
	addi x6, x6, %lo(arr)

	lh x7, 0(x6)    #temprarily hold even max
	lh x8, 2(x6)	#temporarily hold odd max

evenLoop:
	bge x11, x4, oddLoop
	slli x5, x11, 1
	add x5, x5, x6
	lh x9, 0(x5)
	ble x9, x7, afterEvenLoop
	#have to set x7 equal to x9
	mv x7, x9

afterEvenLoop:
	addi x11, x11, 2
	j evenLoop

oddLoop:
	bge x12, x4, afterLoops
	slli x5, x12, 1
	add x5, x5, x6
	lh x9, 0(x5)
	ble x9, x8, afterOddLoop
	#have to set x7 equal to x9
	mv x8, x9

afterOddLoop:
	addi x12, x12, 2
	j oddLoop

afterLoops:
	lui x11, %hi(evenMax)
	addi x11, x11, %lo(evenMax)
	sh x7, 0(x11)

	lui x12, %hi(oddMax)
	addi x12, x12, %lo(oddMax)
	sh x8, 0(x12)

	# YOU SHOULD NOT ADD ANY CODE PAST THIS POINT.
end:
	j end
	.end
