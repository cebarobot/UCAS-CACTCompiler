	.text
	.globl	a
	.data
	.align	3
	.type	a, @object
	.size	a, 40
a:
	.word	100
	.zero	36
	.text
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp, sp, -32
	sd	ra, 24(sp)
	sd	s0, 16(sp)
	addi	s0, sp, 32
	li	t5, 4
	li	t6, 0
	mul	t4, t5, t6
	sw	t4, -20(s0)
	lui	t5, %hi(a)
	addi	t5, t5, %lo(a)
	lw	t6, -20(s0)
	add	t5, t5, t6
	lw	t4, 0(t5)
	sw	t4, -24(s0)
	lw	a0, -24(s0)
	call	print_int
	li	a0, 0
	j	__end_main
__end_main:
	ld	ra, 24(sp)
	ld	s0, 16(sp)
	addi	sp, sp, 32
	jr	ra
