	.file	"arithmetic_operation.c"
	.text
.globl arith
	.type	arith, @function
arith:
	pushl	%ebp
	movl	%esp, %ebp
	movl	16(%ebp), %eax
	leal	(%eax,%eax,2), %eax
	sall	$4, %eax
	movl	12(%ebp), %edx
	addl	8(%ebp), %edx
	andl	$65535, %edx
	imull	%edx, %eax
	popl	%ebp
	ret
	.size	arith, .-arith
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"calculation result is %d\n"
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
	movl	$9, 8(%esp)
	movl	$8, 4(%esp)
	movl	$7, (%esp)
	call	arith
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
