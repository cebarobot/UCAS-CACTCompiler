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
	.globl	.Value16
	.section	.rodata
	.align	3
	.type	.Value16, @object
	.size	.Value16, 24
.Value16:
	.zero	24
	.text
	.align	1
	.globl	int_array_add
	.type	int_array_add, @function
int_array_add:
	addi	sp, sp, -96
	sd	ra, 88(sp)
	sd	s0, 80(sp)
	addi	s0, sp, 96
	li	t5, 4
	li	t6, 6
	mul	t4, t5, t6
	sw	t4, -44(s0)
.Label1:
	lw	t5, -44(s0)
	li	t6, 4
	sub	t4, t5, t6
	sw	t4, -44(s0)
	lui	t5, %hi(.Value16)
	addi	t5, t5, %lo(.Value16)
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
	lw	t5, -44(s0)
	bgtz	t5, .Label1
	li	t4, 0
	sw	t4, -52(s0)
.Label2:
	lw	t5, -52(s0)
	li	t6, 6
	blt	t5, t6, .Label4
	j	.Label3
.Label4:
	li	t5, 4
	lw	t6, -52(s0)
	mul	t4, t5, t6
	sw	t4, -56(s0)
	li	t5, 4
	lw	t6, -52(s0)
	mul	t4, t5, t6
	sw	t4, -60(s0)
	lui	t5, %hi(int_array_a)
	addi	t5, t5, %lo(int_array_a)
	lw	t6, -60(s0)
	add	t5, t5, t6
	lw	t4, 0(t5)
	sw	t4, -64(s0)
	li	t5, 4
	lw	t6, -52(s0)
	mul	t4, t5, t6
	sw	t4, -68(s0)
	lui	t5, %hi(int_array_b)
	addi	t5, t5, %lo(int_array_b)
	lw	t6, -68(s0)
	add	t5, t5, t6
	lw	t4, 0(t5)
	sw	t4, -72(s0)
	lw	t5, -64(s0)
	lw	t6, -72(s0)
	add	t4, t5, t6
	sw	t4, -76(s0)
	lw	t4, -76(s0)
	li	t5, -40
	add	t5, t5, s0
	lw	t6, -56(s0)
	add	t5, t5, t6
	sw	t4, 0(t5)
	li	t5, 4
	lw	t6, -52(s0)
	mul	t4, t5, t6
	sw	t4, -80(s0)
	li	t5, -40
	add	t5, t5, s0
	lw	t6, -80(s0)
	add	t5, t5, t6
	lw	t4, 0(t5)
	sw	t4, -84(s0)
	lw	a0, -84(s0)
	call	print_int
	lw	t5, -52(s0)
	li	t6, 1
	add	t4, t5, t6
	sw	t4, -88(s0)
	lw	t4, -88(s0)
	sw	t4, -52(s0)
	j	.Label2
.Label3:
	j	.END_int_array_add
.END_int_array_add:
	ld	ra, 88(sp)
	ld	s0, 80(sp)
	addi	sp, sp, 96
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
	call	int_array_add
	li	a0, 0
	j	.END_main
.END_main:
	ld	ra, 8(sp)
	ld	s0, 0(sp)
	addi	sp, sp, 16
	jr	ra
