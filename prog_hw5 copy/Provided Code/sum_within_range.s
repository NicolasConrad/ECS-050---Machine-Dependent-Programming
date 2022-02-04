.data

formatStr:
	.string "Sum: %d\n"

.text

.global main
main:
	# TODO: Your code goes here.
	mov $0, %edx			#loop var
	mov $arr, %r8			#start address arr
	mov arrlen, %eax		#array length
	mov low, %ebx			#low
	mov high, %ecx			#high
	mov $0, %esi			#sum var

loop:
	cmp %eax, %edx
	jge afterLoop
	mov (%r8, %rdx, 4), %rdi
	cmp %ebx, %edi
	jl increment
	cmp %ecx, %edi
	jg increment
	add %edi, %esi

increment:
	add $1, %edx
	jmp loop

afterLoop:
    # The RSI register must contain the final sum by
    # the time this part is reached.
	# I recommend that you do NOT modify the below.
	mov $formatStr, %rdi
	mov $0, %eax
	call printf
	ret
