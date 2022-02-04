.data

format_str:
	.string "Count: %d\n"

.text

.global main
main:
	# TODO: Your code goes here.
	mov $0, %eax			#loop variable
	mov arrlen, %ecx		#array length
	mov $arr, %r9			#array start address
	mov $0, %esi			#count
	mov target, %ebx		#target integer

loop:
	cmp %ecx, %eax
	jge afterLoop
	mov (%r9, %rax, 4), %rdx
	cmp %edx, %ebx
	jne increment
	add $1, %esi

increment:
	add $1, %eax
	jmp loop

afterLoop:
    # The RSI register must contain the final count by
    # the time this part is reached.
	# I recommend that you do NOT modify the below.
	mov $format_str, %rdi
	mov $0, %eax
	call printf
	ret
