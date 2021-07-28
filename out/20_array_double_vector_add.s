	.text
	.globl	double_array_a
	.data
	.align	3
	.type	double_array_a, @object
	.size	double_array_a, 48
double_array_a:
	.double	1.2
	.double	2.3
	.double	3.4
	.double	4.5
	.double	5.6
	.double	6.7
	.text
	.globl	double_array_b
	.data
	.align	3
	.type	double_array_b, @object
	.size	double_array_b, 48
double_array_b:
	.double	7.8
	.double	8.9
	.double	9.1
	.double	10.2
	.double	11.3
	.double	12.4
	.text
	.globl	value16
	.section	.rodata
	.align	3
	.type	value16, @object
	.size	value16, 48
value16:
	.zero	48
	.text
	.align	1
	.globl	double_array_vector_add
	.type	double_array_vector_add, @function
double_array_vector_add:
	addi	sp, sp, -128
	sd	ra, 120(sp)
	sd	s0, 112(sp)
	addi	s0, sp, 128
	li	t5, 8
	li	t6, 6
	mul	t4, t5, t6
	sw	t4, -68(s0)
label1:
	lw	t5, -68(s0)
	li	t6, 8
	sub	t4, t5, t6
	sw	t4, -68(s0)
	lui	t5, %hi(value16)
	addi	t5, t5, %lo(value16)
	lw	t6, -68(s0)
	add	t5, t5, t6
	fld	ft4, 0(t5)
	fsd	ft4, -80(s0)
	fld	ft4, -80(s0)
	li	t5, -64
	add	t5, t5, s0
	lw	t6, -68(s0)
	add	t5, t5, t6
	fsd	ft4, 0(t5)
	li	t5, 8
	li	t6, 6
	mul	t4, t5, t6
	sw	t4, -84(s0)
label2:
	lw	t5, -84(s0)
	li	t6, 8
	sub	t4, t5, t6
	sw	t4, -84(s0)
	lui	t5, %hi(double_array_a)
	addi	t5, t5, %lo(double_array_a)
	lw	t6, -84(s0)
	add	t5, t5, t6
	fld	ft4, 0(t5)
	fsd	ft4, -96(s0)
	lui	t5, %hi(double_array_b)
	addi	t5, t5, %lo(double_array_b)
	lw	t6, -84(s0)
	add	t5, t5, t6
	fld	ft4, 0(t5)
	fsd	ft4, -104(s0)
	fld	ft5, -96(s0)
	fld	ft6, -104(s0)
	fadd.d	ft4, ft5, ft6
	fsd	ft4, -112(s0)
	fld	ft4, -112(s0)
	li	t5, -64
	add	t5, t5, s0
	lw	t6, -84(s0)
	add	t5, t5, t6
	fsd	ft4, 0(t5)
	li	t5, 8
	li	t6, 5
	mul	t4, t5, t6
	sw	t4, -116(s0)
	li	t5, -64
	add	t5, t5, s0
	lw	t6, -116(s0)
	add	t5, t5, t6
	fld	ft4, 0(t5)
	fsd	ft4, -128(s0)
	fld	fa0, -128(s0)
	call	print_double
	j	__end_double_array_vector_add
__end_double_array_vector_add:
	ld	ra, 120(sp)
	ld	s0, 112(sp)
	addi	sp, sp, 128
	jr	ra
	.text
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp, sp, -16
	sd	ra, 8(sp)
	sd	s0, 0(sp)
	addi	s0, sp, 16
	call	double_array_vector_add
	li	a0, 0
	j	__end_main
__end_main:
	ld	ra, 8(sp)
	ld	s0, 0(sp)
	addi	sp, sp, 16
	jr	ra
