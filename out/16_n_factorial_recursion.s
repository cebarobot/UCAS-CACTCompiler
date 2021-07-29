	.text
	.align	1
	.globl	factorial
	.type	factorial, @function
factorial:
	addi	sp, sp, -32
	sd	ra, 24(sp)
	sd	s0, 16(sp)
	addi	s0, sp, 32
	sw	a0, -20(s0)
	lw	t5, -20(s0)
	li	t6, 1
	beq	t5, t6, .Label2
	j	.Label3
.Label2:
	lw	a0, -20(s0)
	j	.END_factorial
.Label3:
	lw	t5, -20(s0)
	li	t6, 1
	sub	t4, t5, t6
	sw	t4, -24(s0)
	lw	a0, -24(s0)
	call	factorial
	sw	a0, -28(s0)
	lw	t5, -20(s0)
	lw	t6, -28(s0)
	mul	t4, t5, t6
	sw	t4, -32(s0)
	lw	a0, -32(s0)
	j	.END_factorial
.Label1:
.END_factorial:
	ld	ra, 24(sp)
	ld	s0, 16(sp)
	addi	sp, sp, 32
	jr	ra
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
	li	t4, 0
	sw	t4, -24(s0)
	call	get_int
	sw	a0, -28(s0)
	lw	t4, -28(s0)
	sw	t4, -20(s0)
	lw	t5, -20(s0)
	li	t6, 1
	bgt	t5, t6, .Label5
	j	.Label6
.Label5:
	lw	a0, -20(s0)
	call	factorial
	sw	a0, -32(s0)
	lw	t4, -32(s0)
	sw	t4, -24(s0)
	j	.Label4
.Label6:
	li	t4, 1
	sw	t4, -24(s0)
	j	.Label4
.Label4:
	lw	a0, -24(s0)
	call	print_int
	li	a0, 0
	j	.END_main
.END_main:
	ld	ra, 24(sp)
	ld	s0, 16(sp)
	addi	sp, sp, 32
	jr	ra
