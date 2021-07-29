	.text
	.globl	.Val1
	.section	.rodata
	.align	3
	.type	.Val1, @object
	.size	.Val1, 4
.Val1:
	.zero	4
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
	flw	ft4, %lo(.Val1)(t1)
	fsw	ft4, -20(s0)
	call	get_float
	fsw	fa0, -24(s0)
	flw	ft4, -24(s0)
	fsw	ft4, -20(s0)
	flw	fa0, -20(s0)
	call	print_float
	li	a0, 0
	j	.END_main
.END_main:
	ld	ra, 24(sp)
	ld	s0, 16(sp)
	addi	sp, sp, 32
	jr	ra
