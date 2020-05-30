	.file	"code.c"
	.text
.globl sum
	.type	sum, @function
sum:
	pushl	%ebp
	movl	%esp, %ebp
	movl	12(%ebp), %eax
	addl	8(%ebp), %eax
	addl	%eax, accnum
	popl	%ebp
	ret
	.size	sum, .-sum
.globl accnum
	.bss
	.align 4
	.type	accnum, @object
	.size	accnum, 4
accnum:
	.zero	4
	.ident	"GCC: (Ubuntu 4.3.2-1ubuntu11) 4.3.2"
	.section	.note.GNU-stack,"",@progbits
