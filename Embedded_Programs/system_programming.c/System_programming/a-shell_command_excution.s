	.file	"shell_command_excution.c"
	.text
	.section	.rodata
.LC0:
	.string	"Eneter the string"
.LC1:
	.string	"%[^\n]"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$208, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -208(%rbp)
	movl	$0, -204(%rbp)
.L6:
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movq	stdin(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__fpurge@PLT
	leaq	-112(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	leaq	-112(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -196(%rbp)
	movl	$0, -200(%rbp)
	jmp	.L2
.L5:
	movl	-200(%rbp), %eax
	cltq
	movzbl	-112(%rbp,%rax), %eax
	cmpb	$32, %al
	je	.L3
	movl	-200(%rbp), %eax
	cmpl	-196(%rbp), %eax
	jne	.L4
.L3:
	movl	-200(%rbp), %eax
	cltq
	movb	$0, -112(%rbp,%rax)
	movl	-208(%rbp), %eax
	cltq
	leaq	-112(%rbp), %rdx
	addq	%rax, %rdx
	movl	-204(%rbp), %eax
	cltq
	movq	%rdx, -192(%rbp,%rax,8)
	movl	-200(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -208(%rbp)
	addl	$1, -204(%rbp)
.L4:
	addl	$1, -200(%rbp)
.L2:
	movl	-200(%rbp), %eax
	cmpl	-196(%rbp), %eax
	jle	.L5
	movq	-192(%rbp), %rax
	leaq	-192(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	execvp@PLT
	jmp	.L6
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
