	.text
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp, sp, -16
	sd	ra, 8(sp)
	sd	s0, 0(sp)
	addi	s0, sp, 16
	li	t5, 0
	bgtz	t5, .Label2
	j	.Label3
.Label3:
	li	t5, 0
	bgtz	t5, .Label2
	j	.Label1
.Label2:
	li	a0, 1
	call	print_int
	j	.Label1
.Label1:
	li	t5, 0
	bgtz	t5, .Label5
	j	.Label6
.Label6:
	li	t5, 1
	bgtz	t5, .Label5
	j	.Label4
.Label5:
	li	a0, 2
	call	print_int
	j	.Label4
.Label4:
	li	t5, 1
	bgtz	t5, .Label8
	j	.Label9
.Label9:
	li	t5, 0
	bgtz	t5, .Label8
	j	.Label7
.Label8:
	li	a0, 3
	call	print_int
	j	.Label7
.Label7:
	li	t5, 1
	bgtz	t5, .Label11
	j	.Label12
.Label12:
	li	t5, 1
	bgtz	t5, .Label11
	j	.Label10
.Label11:
	li	a0, 4
	call	print_int
	j	.Label10
.Label10:
	li	a0, 0
	j	.END_main
.END_main:
	ld	ra, 8(sp)
	ld	s0, 0(sp)
	addi	sp, sp, 16
	jr	ra
