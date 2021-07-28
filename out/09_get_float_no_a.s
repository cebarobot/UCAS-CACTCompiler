	.text
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp, sp, -32
	sd	ra, 24(sp)
	sd	s0, 16(sp)
	addi	s0, sp, 32
	call	get_float
	fsw	fa0, -20(s0)
	flw	fa0, -20(s0)
	call	print_float
	li	a0, 0
	j	__end_main
__end_main:
	ld	ra, 24(sp)
	ld	s0, 16(sp)
	addi	sp, sp, 32
	jr	ra
