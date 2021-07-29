	.text
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp, sp, -32
	sd	ra, 24(sp)
	sd	s0, 16(sp)
	addi	s0, sp, 32
	li	t4, 1
	sw	t4, -20(s0)
	lw	a0, -20(s0)
	call	print_bool
	li	a0, 0
	j	.END_main
.END_main:
	ld	ra, 24(sp)
	ld	s0, 16(sp)
	addi	sp, sp, 32
	jr	ra
