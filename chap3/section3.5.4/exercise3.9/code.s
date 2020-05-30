	.file	"code.c"
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
	popl	%ecx
	popl	%ebp
	leal	-4(%ecx), %esp
	ret
	.size	main, .-main
.globl arith
	.type	arith, @function
arith:
	pushl	%ebp
	movl	%esp, %ebp
	movl	12(%ebp), %eax
	xorl	8(%ebp), %eax
	sarl	$3, %eax
	notl	%eax
	subl	16(%ebp), %eax
	popl	%ebp
	ret
	.size	arith, .-arith
	.ident	"GCC: (Ubuntu 4.3.2-1ubuntu11) 4.3.2"
	.section	.note.GNU-stack,"",@progbits
