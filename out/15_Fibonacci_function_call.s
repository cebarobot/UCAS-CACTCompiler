	.text
	.align	1
	.globl	fibonacci
	.type	fibonacci, @function
fibonacci:
	addi	sp, sp, -48
	sd	ra, 40(sp)
	sd	s0, 32(sp)
	addi	s0, sp, 48
	sw	a0, -20(s0)
	li	t4, 0
	sw	t4, -24(s0)
	li	t4, 1
	sw	t4, -28(s0)
	li	t4, 0
	sw	t4, -32(s0)
	li	t4, 0
	sw	t4, -36(s0)
.Label1:
	lw	t5, -32(s0)
	lw	t6, -20(s0)
	blt	t5, t6, .Label3
	j	.Label2
.Label3:
	lw	t5, -24(s0)
	lw	t6, -28(s0)
	add	t4, t5, t6
	sw	t4, -40(s0)
	lw	t4, -40(s0)
	sw	t4, -36(s0)
	lw	a0, -36(s0)
	call	print_int
	lw	t4, -28(s0)
	sw	t4, -24(s0)
	lw	t4, -36(s0)
	sw	t4, -28(s0)
	lw	t5, -32(s0)
	li	t6, 1
	add	t4, t5, t6
	sw	t4, -44(s0)
	lw	t4, -44(s0)
	sw	t4, -32(s0)
	j	.Label1
.Label2:
	lw	a0, -36(s0)
	j	.END_fibonacci
.END_fibonacci:
	ld	ra, 40(sp)
	ld	s0, 32(sp)
	addi	sp, sp, 48
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
	call	get_int
	sw	a0, -24(s0)
	lw	t4, -24(s0)
	sw	t4, -20(s0)
	lw	a0, -20(s0)
	call	fibonacci
	sw	a0, -28(s0)
	li	a0, 0
	j	.END_main
.END_main:
	ld	ra, 24(sp)
	ld	s0, 16(sp)
	addi	sp, sp, 32
	jr	ra
