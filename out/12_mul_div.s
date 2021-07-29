	.text
	.globl	.Val7
	.section	.rodata
	.align	3
	.type	.Val7, @object
	.size	.Val7, 4
.Val7:
	.zero	4
	.text
	.globl	.Val8
	.section	.rodata
	.align	3
	.type	.Val8, @object
	.size	.Val8, 4
.Val8:
	.zero	4
	.text
	.globl	.Val9
	.section	.rodata
	.align	3
	.type	.Val9, @object
	.size	.Val9, 4
.Val9:
	.zero	4
	.text
	.globl	.Val10
	.section	.rodata
	.align	3
	.type	.Val10, @object
	.size	.Val10, 4
.Val10:
	.zero	4
	.text
	.globl	.Val11
	.section	.rodata
	.align	3
	.type	.Val11, @object
	.size	.Val11, 4
.Val11:
	.float	3.2
	.text
	.globl	.Val12
	.section	.rodata
	.align	3
	.type	.Val12, @object
	.size	.Val12, 4
.Val12:
	.float	1.6
	.text
	.globl	.Val13
	.section	.rodata
	.align	3
	.type	.Val13, @object
	.size	.Val13, 8
.Val13:
	.zero	8
	.text
	.globl	.Val14
	.section	.rodata
	.align	3
	.type	.Val14, @object
	.size	.Val14, 8
.Val14:
	.zero	8
	.text
	.globl	.Val15
	.section	.rodata
	.align	3
	.type	.Val15, @object
	.size	.Val15, 8
.Val15:
	.zero	8
	.text
	.globl	.Val16
	.section	.rodata
	.align	3
	.type	.Val16, @object
	.size	.Val16, 8
.Val16:
	.zero	8
	.text
	.globl	.Val17
	.section	.rodata
	.align	3
	.type	.Val17, @object
	.size	.Val17, 8
.Val17:
	.double	3.4
	.text
	.globl	.Val18
	.section	.rodata
	.align	3
	.type	.Val18, @object
	.size	.Val18, 8
.Val18:
	.double	2.5
	.text
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp, sp, -144
	sd	ra, 136(sp)
	sd	s0, 128(sp)
	addi	s0, sp, 144
	li	t4, 0
	sw	t4, -20(s0)
	li	t4, 0
	sw	t4, -24(s0)
	li	t4, 0
	sw	t4, -28(s0)
	li	t4, 0
	sw	t4, -32(s0)
	call	get_int
	sw	a0, -36(s0)
	lw	t4, -36(s0)
	sw	t4, -20(s0)
	lw	t5, -20(s0)
	li	t6, 3
	mul	t4, t5, t6
	sw	t4, -40(s0)
	lw	t4, -40(s0)
	sw	t4, -24(s0)
	call	get_int
	sw	a0, -44(s0)
	lw	t4, -44(s0)
	sw	t4, -28(s0)
	lw	t5, -28(s0)
	li	t6, 2
	div	t4, t5, t6
	sw	t4, -48(s0)
	lw	t4, -48(s0)
	sw	t4, -32(s0)
	lw	a0, -24(s0)
	call	print_int
	lw	a0, -32(s0)
	call	print_int
	lui	t1, %hi(.Val7)
	flw	ft4, %lo(.Val7)(t1)
	fsw	ft4, -52(s0)
	lui	t1, %hi(.Val8)
	flw	ft4, %lo(.Val8)(t1)
	fsw	ft4, -56(s0)
	lui	t1, %hi(.Val9)
	flw	ft4, %lo(.Val9)(t1)
	fsw	ft4, -60(s0)
	lui	t1, %hi(.Val10)
	flw	ft4, %lo(.Val10)(t1)
	fsw	ft4, -64(s0)
	call	get_float
	fsw	fa0, -68(s0)
	flw	ft4, -68(s0)
	fsw	ft4, -52(s0)
	flw	ft5, -52(s0)
	lui	t1, %hi(.Val11)
	flw	ft6, %lo(.Val11)(t1)
	fmul.s	ft4, ft5, ft6
	fsw	ft4, -72(s0)
	flw	ft4, -72(s0)
	fsw	ft4, -56(s0)
	call	get_float
	fsw	fa0, -76(s0)
	flw	ft4, -76(s0)
	fsw	ft4, -60(s0)
	flw	ft5, -60(s0)
	lui	t1, %hi(.Val12)
	flw	ft6, %lo(.Val12)(t1)
	fdiv.s	ft4, ft5, ft6
	fsw	ft4, -80(s0)
	flw	ft4, -80(s0)
	fsw	ft4, -64(s0)
	flw	fa0, -56(s0)
	call	print_float
	flw	fa0, -64(s0)
	call	print_float
	lui	t1, %hi(.Val13)
	fld	ft4, %lo(.Val13)(t1)
	fsd	ft4, -88(s0)
	lui	t1, %hi(.Val14)
	fld	ft4, %lo(.Val14)(t1)
	fsd	ft4, -96(s0)
	lui	t1, %hi(.Val15)
	fld	ft4, %lo(.Val15)(t1)
	fsd	ft4, -104(s0)
	lui	t1, %hi(.Val16)
	fld	ft4, %lo(.Val16)(t1)
	fsd	ft4, -112(s0)
	call	get_double
	fsd	fa0, -120(s0)
	fld	ft4, -120(s0)
	fsd	ft4, -88(s0)
	fld	ft5, -88(s0)
	lui	t1, %hi(.Val17)
	fld	ft6, %lo(.Val17)(t1)
	fmul.d	ft4, ft5, ft6
	fsd	ft4, -128(s0)
	fld	ft4, -128(s0)
	fsd	ft4, -96(s0)
	call	get_double
	fsd	fa0, -136(s0)
	fld	ft4, -136(s0)
	fsd	ft4, -104(s0)
	fld	ft5, -104(s0)
	lui	t1, %hi(.Val18)
	fld	ft6, %lo(.Val18)(t1)
	fdiv.d	ft4, ft5, ft6
	fsd	ft4, -144(s0)
	fld	ft4, -144(s0)
	fsd	ft4, -112(s0)
	fld	fa0, -96(s0)
	call	print_double
	fld	fa0, -112(s0)
	call	print_double
	li	a0, 0
	j	.END_main
.END_main:
	ld	ra, 136(sp)
	ld	s0, 128(sp)
	addi	sp, sp, 144
	jr	ra
