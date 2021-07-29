	.text
	.globl	.Val1
	.section	.rodata
	.align	3
	.type	.Val1, @object
	.size	.Val1, 8
.Val1:
	.zero	8
	.text
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp, sp, -32
	sd	ra, 24(sp)
	sd	s0, 16(sp)
	addi	s0, sp, 32
	lui	t1, %hi(.Val1)
	fld	ft4, %lo(.Val1)(t1)
	fsd	ft4, -24(s0)
	call	get_double
	fsd	fa0, -32(s0)
	fld	ft4, -32(s0)
	fsd	ft4, -24(s0)
	fld	fa0, -24(s0)
	call	print_double
	li	a0, 0
	j	.END_main
.END_main:
	ld	ra, 24(sp)
	ld	s0, 16(sp)
	addi	sp, sp, 32
	jr	ra
