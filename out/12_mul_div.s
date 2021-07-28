	.text
	.globl	value7
	.section	.rodata
	.align	3
	.type	value7, @object
	.size	value7, 4
value7:
	.zero	4
	.text
	.globl	value8
	.section	.rodata
	.align	3
	.type	value8, @object
	.size	value8, 4
value8:
	.zero	4
	.text
	.globl	value9
	.section	.rodata
	.align	3
	.type	value9, @object
	.size	value9, 4
value9:
	.zero	4
	.text
	.globl	value10
	.section	.rodata
	.align	3
	.type	value10, @object
	.size	value10, 4
value10:
	.zero	4
	.text
	.globl	value11
	.section	.rodata
	.align	3
	.type	value11, @object
	.size	value11, 4
value11:
	.float	3.2
	.text
	.globl	value12
	.section	.rodata
	.align	3
	.type	value12, @object
	.size	value12, 4
value12:
	.float	1.6
	.text
	.globl	value13
	.section	.rodata
	.align	3
	.type	value13, @object
	.size	value13, 8
value13:
	.zero	8
	.text
	.globl	value14
	.section	.rodata
	.align	3
	.type	value14, @object
	.size	value14, 8
value14:
	.zero	8
	.text
	.globl	value15
	.section	.rodata
	.align	3
	.type	value15, @object
	.size	value15, 8
value15:
	.zero	8
	.text
	.globl	value16
	.section	.rodata
	.align	3
	.type	value16, @object
	.size	value16, 8
value16:
	.zero	8
	.text
	.globl	value17
	.section	.rodata
	.align	3
	.type	value17, @object
	.size	value17, 8
value17:
	.double	3.4
	.text
	.globl	value18
	.section	.rodata
	.align	3
	.type	value18, @object
	.size	value18, 8
value18:
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
	lui	t1, %hi(value7)
	flw	ft4, %lo(value7)(t1)
	fsw	ft4, -52(s0)
	lui	t1, %hi(value8)
	flw	ft4, %lo(value8)(t1)
	fsw	ft4, -56(s0)
	lui	t1, %hi(value9)
	flw	ft4, %lo(value9)(t1)
	fsw	ft4, -60(s0)
	lui	t1, %hi(value10)
	flw	ft4, %lo(value10)(t1)
	fsw	ft4, -64(s0)
	call	get_float
	fsw	fa0, -68(s0)
	flw	ft4, -68(s0)
	fsw	ft4, -52(s0)
	flw	ft5, -52(s0)
	lui	t1, %hi(value11)
	flw	ft6, %lo(value11)(t1)
	fmul.s	ft4, ft5, ft6
	fsw	ft4, -72(s0)
	flw	ft4, -72(s0)
	fsw	ft4, -56(s0)
	call	get_float
	fsw	fa0, -76(s0)
	flw	ft4, -76(s0)
	fsw	ft4, -60(s0)
	flw	ft5, -60(s0)
	lui	t1, %hi(value12)
	flw	ft6, %lo(value12)(t1)
	fdiv.s	ft4, ft5, ft6
	fsw	ft4, -80(s0)
	flw	ft4, -80(s0)
	fsw	ft4, -64(s0)
	flw	fa0, -56(s0)
	call	print_float
	flw	fa0, -64(s0)
	call	print_float
	lui	t1, %hi(value13)
	fld	ft4, %lo(value13)(t1)
	fsd	ft4, -88(s0)
	lui	t1, %hi(value14)
	fld	ft4, %lo(value14)(t1)
	fsd	ft4, -96(s0)
	lui	t1, %hi(value15)
	fld	ft4, %lo(value15)(t1)
	fsd	ft4, -104(s0)
	lui	t1, %hi(value16)
	fld	ft4, %lo(value16)(t1)
	fsd	ft4, -112(s0)
	call	get_double
	fsd	fa0, -120(s0)
	fld	ft4, -120(s0)
	fsd	ft4, -88(s0)
	fld	ft5, -88(s0)
	lui	t1, %hi(value17)
	fld	ft6, %lo(value17)(t1)
	fmul.d	ft4, ft5, ft6
	fsd	ft4, -128(s0)
	fld	ft4, -128(s0)
	fsd	ft4, -96(s0)
	call	get_double
	fsd	fa0, -136(s0)
	fld	ft4, -136(s0)
	fsd	ft4, -104(s0)
	fld	ft5, -104(s0)
	lui	t1, %hi(value18)
	fld	ft6, %lo(value18)(t1)
	fdiv.d	ft4, ft5, ft6
	fsd	ft4, -144(s0)
	fld	ft4, -144(s0)
	fsd	ft4, -112(s0)
	fld	fa0, -96(s0)
	call	print_double
	fld	fa0, -112(s0)
	call	print_double
	li	a0, 0
	j	__end_main
__end_main:
	ld	ra, 136(sp)
	ld	s0, 128(sp)
	addi	sp, sp, 144
	jr	ra
