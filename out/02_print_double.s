	.text
	.globl	value1
	.section	.rodata
	.align	3
	.type	value1, @object
	.size	value1, 8
value1:
	.double	3.4
	.text
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp, sp, -32
	sd	ra, 24(sp)
	sd	s0, 16(sp)
	addi	s0, sp, 32
	lui	t1, %hi(value1)
	fld	ft5, %lo(value1)(t1)
	fsd	ft5, -24(s0)
	fld	fa0, -24(s0)
	call	print_double
	li	a0, 0
	j	__end_main
__end_main:
	ld	ra, 24(sp)
	ld	s0, 16(sp)
	addi	sp, sp, 32
	jr	ra
