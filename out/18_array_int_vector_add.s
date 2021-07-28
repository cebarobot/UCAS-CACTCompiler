	.text
	.globl	int_array_a
	.data
	.align	3
	.type	int_array_a, @object
	.size	int_array_a, 24
int_array_a:
	.word	1
	.word	2
	.word	3
	.word	4
	.word	5
	.word	6
	.text
	.globl	int_array_b
	.data
	.align	3
	.type	int_array_b, @object
	.size	int_array_b, 24
int_array_b:
	.word	7
	.word	8
	.word	9
	.word	10
	.word	11
	.word	12
	.text
	.globl	value16
	.section	.rodata
	.align	3
	.type	value16, @object
	.size	value16, 24
value16:
	.zero	24
	.text
	.align	1
	.globl	int_array_vector_add
	.type	int_array_vector_add, @function
int_array_vector_add:
	addi	sp, sp, -80
	sd	ra, 72(sp)
	sd	s0, 64(sp)
	addi	s0, sp, 80
	li	t5, 4
	li	t6, 6
	mul	t4, t5, t6
	sw	t4, -44(s0)
label1:
	lw	t5, -44(s0)
	li	t6, 4
	sub	t4, t5, t6
	sw	t4, -44(s0)
	lui	t5, %hi(value16)
	addi	t5, t5, %lo(value16)
	lw	t6, -44(s0)
	add	t5, t5, t6
	lw	t4, 0(t5)
	sw	t4, -48(s0)
	lw	t4, -48(s0)
	li	t5, -40
	add	t5, t5, s0
	lw	t6, -44(s0)
	add	t5, t5, t6
	sw	t4, 0(t5)
	li	t5, 4
	li	t6, 6
	mul	t4, t5, t6
	sw	t4, -52(s0)
label2:
	lw	t5, -52(s0)
	li	t6, 4
	sub	t4, t5, t6
	sw	t4, -52(s0)
	lui	t5, %hi(int_array_a)
	addi	t5, t5, %lo(int_array_a)
	lw	t6, -52(s0)
	add	t5, t5, t6
	lw	t4, 0(t5)
	sw	t4, -56(s0)
	lui	t5, %hi(int_array_b)
	addi	t5, t5, %lo(int_array_b)
	lw	t6, -52(s0)
	add	t5, t5, t6
	lw	t4, 0(t5)
	sw	t4, -60(s0)
	lw	t5, -56(s0)
	lw	t6, -60(s0)
	add	t4, t5, t6
	sw	t4, -64(s0)
	lw	t4, -64(s0)
	li	t5, -40
	add	t5, t5, s0
	lw	t6, -52(s0)
	add	t5, t5, t6
	sw	t4, 0(t5)
	li	t5, 4
	li	t6, 5
	mul	t4, t5, t6
	sw	t4, -68(s0)
	li	t5, -40
	add	t5, t5, s0
	lw	t6, -68(s0)
	add	t5, t5, t6
	lw	t4, 0(t5)
	sw	t4, -72(s0)
	lw	a0, -72(s0)
	call	print_int
	j	__end_int_array_vector_add
__end_int_array_vector_add:
	ld	ra, 72(sp)
	ld	s0, 64(sp)
	addi	sp, sp, 80
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
	call	int_array_vector_add
	li	a0, 0
	j	__end_main
__end_main:
	ld	ra, 8(sp)
	ld	s0, 0(sp)
	addi	sp, sp, 16
	jr	ra
