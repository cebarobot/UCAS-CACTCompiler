	.text
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp, sp, -48
	sd	ra, 40(sp)
	sd	s0, 32(sp)
	addi	s0, sp, 48
	li	t4, 0
	sw	t4, -20(s0)
	li	t4, 2
	sw	t4, -24(s0)
	call	get_int
	sw	a0, -28(s0)
	lw	t4, -28(s0)
	sw	t4, -20(s0)
	lw	t5, -20(s0)
	li	t6, 0
	beq	t5, t6, .Label2
	j	.Label3
.Label2:
	li	t4, 4
	sw	t4, -32(s0)
	lw	t4, -32(s0)
	sw	t4, -24(s0)
	lw	a0, -24(s0)
	call	print_int
	j	.Label1
.Label3:
	li	t4, 2
	sw	t4, -36(s0)
	lw	t4, -36(s0)
	sw	t4, -20(s0)
	lw	a0, -20(s0)
	call	print_int
	j	.Label1
.Label1:
	li	a0, 0
	j	.END_main
.END_main:
	ld	ra, 40(sp)
	ld	s0, 32(sp)
	addi	sp, sp, 48
	jr	ra
