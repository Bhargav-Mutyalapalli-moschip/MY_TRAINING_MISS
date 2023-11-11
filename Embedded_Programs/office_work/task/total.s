	.file	"total.c"
	.text
	.section	.rodata
	.align 8
.LC0:
	.string	"SELECT THE OPTION\n 2.Bitwise operator\n 1.Arthimetic operator\n 3.Swapping technique\n 4.Ascii conversions\n 5.Fabnoc series\n 6.Goto program\n 7.Macros"
.LC1:
	.string	"%d"
	.align 8
.LC2:
	.string	"Select the option:\n a.Reverse a number\n b.Sum of digits\n e.Count the digits\n d.Palindrome number\n c.Decimal to binary\n f.Binary to decimal\n g.Even or odd"
.LC3:
	.string	"%c"
	.align 8
.LC4:
	.string	"Enter the value to be reversed:\n "
.LC5:
	.string	"The Reversed number:%d\n"
	.align 8
.LC6:
	.string	"Enter the number for sum of digits: "
.LC7:
	.string	"The output is: %d\n"
.LC8:
	.string	"Enter the decimal value: "
.LC9:
	.string	"The binary number is: %d\n"
.LC10:
	.string	"invalid option"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
.L11:
	movl	$1, -20(%rbp)
	movl	$6, -16(%rbp)
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	leaq	-28(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movq	stdin(%rip), %rax
	movq	%rax, %rdi
	call	__fpurge@PLT
	movl	-28(%rbp), %eax
	testl	%eax, %eax
	je	.L2
	cmpl	$1, %eax
	je	.L3
	jmp	.L4
.L2:
	movl	$0, %edi
	call	exit@PLT
.L3:
	leaq	.LC2(%rip), %rdi
	call	puts@PLT
	leaq	-29(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movq	stdin(%rip), %rax
	movq	%rax, %rdi
	call	__fpurge@PLT
	movzbl	-29(%rbp), %eax
	movsbl	%al, %eax
	cmpl	$101, %eax
	je	.L5
	cmpl	$101, %eax
	jg	.L6
	cmpl	$98, %eax
	je	.L7
	cmpl	$98, %eax
	jg	.L6
	testl	%eax, %eax
	je	.L8
	cmpl	$97, %eax
	je	.L9
	jmp	.L6
.L8:
	movl	$0, %edi
	call	exit@PLT
.L9:
	leaq	.LC4(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-24(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-24(%rbp), %eax
	movl	%eax, %edi
	call	reverse_num@PLT
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC5(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L10
.L7:
	leaq	.LC6(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-24(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-24(%rbp), %eax
	movl	%eax, %edi
	call	sum_digit@PLT
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC7(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L10
.L5:
	leaq	.LC8(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-24(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-24(%rbp), %eax
	movl	%eax, %edi
	call	decimal_binary@PLT
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC9(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L10
.L6:
	leaq	.LC10(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L13
.L10:
.L13:
	nop
.L4:
	jmp	.L11
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
