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
	lw	t5, -24(s0)
	lw	t6, -28(s0)
	add	t4, t5, t6
	sw	t4, -36(s0)
	lw	t4, -36(s0)
	sw	t4, -32(s0)
	lw	a0, -32(s0)
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
	li	t4, 2
	sw	t4, -20(s0)
	lw	a0, -20(s0)
	call	fibonacci
	sw	a0, -24(s0)
	li	a0, 0
	j	.END_main
.END_main:
	ld	ra, 24(sp)
	ld	s0, 16(sp)
	addi	sp, sp, 32
	jr	ra
