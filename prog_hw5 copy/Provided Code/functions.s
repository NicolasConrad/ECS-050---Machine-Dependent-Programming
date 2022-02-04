.data

siScanfFormatStr:
	.string "%d"

.text

.global add
add:
	# TODO: Your code goes here.
	
	add %edi, %esi
	mov %esi, %eax
	ret

.global sumInputs
sumInputs:
	# TODO: Your code goes here.
	mov $0, %r14d		#loop var
	mov $0, %rax		#sum 

sumInputsLoop:
	cmp %edi, %r14d
	jge afterSumInputsLoop
	
	push %rsi
	push %rdi
	push %rax

	#call scanf
	mov $siScanfFormatStr, %rdi
	add $-16, %rsp
	mov %rsp, %rsi
	call scanf

	#retreive register values
	mov 0(%rsp), %rcx
	add $16, %rsp
	pop %rax
	pop %rdi
	pop %rsi

	#check if input = targetVal
	cmp %ecx, %esi
	je afterSumInputsLoop

	#add input to sum if not equal to targetval
	add %ecx, %eax

increment:
	add $1, %r14d
	jmp sumInputsLoop

afterSumInputsLoop:
	ret





	







