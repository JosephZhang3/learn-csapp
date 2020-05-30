	.file	"decode1.c"
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
.globl decode1
	.type	decode1, @function
decode1:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$12, %esp
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%edi, 8(%esp)
	movl	8(%ebp), %edi
	movl	12(%ebp), %edx
	movl	16(%ebp), %ecx
	movl	(%edx), %ebx
	movl	(%ecx), %esi
	movl	(%edi), %eax
	movl	%eax, (%edx)
	movl	%ebx, (%ecx)
	movl	%esi, (%edi)
	movl	(%esp), %ebx
	movl	4(%esp), %esi
	movl	8(%esp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.size	decode1, .-decode1
	.ident	"GCC: (Ubuntu 4.3.2-1ubuntu11) 4.3.2"
	.section	.note.GNU-stack,"",@progbits
