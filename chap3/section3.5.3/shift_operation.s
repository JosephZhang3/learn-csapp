	.file	"shift_operation.c"
	.text
.globl shift_left2_rightn
	.type	shift_left2_rightn, @function
shift_left2_rightn:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	sall	$2, %eax
	movl	12(%ebp), %ecx
	sarl	%cl, %eax
	popl	%ebp
	ret
	.size	shift_left2_rightn, .-shift_left2_rightn
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"result is %d\n"
	.text
.globl main
	.type	main, @function
main:
	leal	4(%esp), %ecx
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ecx
	subl	$20, %esp
	movl	$3, 4(%esp)
	movl	$8, (%esp)
	call	shift_left2_rightn
	movl	%eax, 8(%esp)
	movl	$.LC0, 4(%esp)
	movl	$1, (%esp)
	call	__printf_chk
	addl	$20, %esp
	popl	%ecx
	popl	%ebp
	leal	-4(%ecx), %esp
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.3.2-1ubuntu11) 4.3.2"
	.section	.note.GNU-stack,"",@progbits
