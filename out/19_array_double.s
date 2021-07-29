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
	.globl	.Value16
	.section	.rodata
	.align	3
	.type	.Value16, @object
	.size	.Value16, 48
.Value16:
	.zero	48
	.text
	.align	1
	.globl	double_array_add
	.type	double_array_add, @function
double_array_add:
	addi	sp, sp, -160
	sd	ra, 152(sp)
	sd	s0, 144(sp)
	addi	s0, sp, 160
	li	t5, 8
	li	t6, 6
	mul	t4, t5, t6
	sw	t4, -68(s0)
.Label1:
	lw	t5, -68(s0)
	li	t6, 8
	sub	t4, t5, t6
	sw	t4, -68(s0)
	lui	t5, %hi(.Value16)
	addi	t5, t5, %lo(.Value16)
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
	lw	t5, -68(s0)
	bgtz	t5, .Label1
	li	t4, 0
	sw	t4, -84(s0)
.Label2:
	lw	t5, -84(s0)
	li	t6, 6
	blt	t5, t6, .Label4
	j	.Label3
.Label4:
	li	t5, 8
	lw	t6, -84(s0)
	mul	t4, t5, t6
	sw	t4, -88(s0)
	li	t5, 8
	lw	t6, -84(s0)
	mul	t4, t5, t6
	sw	t4, -92(s0)
	lui	t5, %hi(double_array_a)
	addi	t5, t5, %lo(double_array_a)
	lw	t6, -92(s0)
	add	t5, t5, t6
	fld	ft4, 0(t5)
	fsd	ft4, -104(s0)
	li	t5, 8
	lw	t6, -84(s0)
	mul	t4, t5, t6
	sw	t4, -108(s0)
	lui	t5, %hi(double_array_b)
	addi	t5, t5, %lo(double_array_b)
	lw	t6, -108(s0)
	add	t5, t5, t6
	fld	ft4, 0(t5)
	fsd	ft4, -120(s0)
	fld	ft5, -104(s0)
	fld	ft6, -120(s0)
	fadd.d	ft4, ft5, ft6
	fsd	ft4, -128(s0)
	fld	ft4, -128(s0)
	li	t5, -64
	add	t5, t5, s0
	lw	t6, -88(s0)
	add	t5, t5, t6
	fsd	ft4, 0(t5)
	li	t5, 8
	lw	t6, -84(s0)
	mul	t4, t5, t6
	sw	t4, -132(s0)
	li	t5, -64
	add	t5, t5, s0
	lw	t6, -132(s0)
	add	t5, t5, t6
	fld	ft4, 0(t5)
	fsd	ft4, -144(s0)
	fld	fa0, -144(s0)
	call	print_double
	lw	t5, -84(s0)
	li	t6, 1
	add	t4, t5, t6
	sw	t4, -148(s0)
	lw	t4, -148(s0)
	sw	t4, -84(s0)
	j	.Label2
.Label3:
	j	.END_double_array_add
.END_double_array_add:
	ld	ra, 152(sp)
	ld	s0, 144(sp)
	addi	sp, sp, 160
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
	call	double_array_add
	li	a0, 0
	j	.END_main
.END_main:
	ld	ra, 8(sp)
	ld	s0, 0(sp)
	addi	sp, sp, 16
	jr	ra
