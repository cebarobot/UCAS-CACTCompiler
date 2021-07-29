	.text
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp, sp, -32
	sd	ra, 24(sp)
	sd	s0, 16(sp)
	addi	s0, sp, 32
	li	t4, 0
	sw	t4, -20(s0)
	li	t4, 2
	sw	t4, -24(s0)
	lw	t5, -20(s0)
	li	t6, 1
	beq	t5, t6, .Label2
	j	.Label3
.Label3:
	lw	t5, -20(s0)
	li	t6, 0
	beq	t5, t6, .Label4
	j	.Label1
.Label4:
	lw	t5, -24(s0)
	li	t6, 2
	beq	t5, t6, .Label2
	j	.Label1
.Label2:
	lw	a0, -24(s0)
	call	print_int
	j	.Label1
.Label1:
	lw	a0, -20(s0)
	call	print_int
	li	a0, 0
	j	.END_main
.END_main:
	ld	ra, 24(sp)
	ld	s0, 16(sp)
	addi	sp, sp, 32
	jr	ra
