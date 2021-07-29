	.text
	.align	1
	.globl	ppp
	.type	ppp, @function
ppp:
	addi	sp, sp, -16
	sd	ra, 8(sp)
	sd	s0, 0(sp)
	addi	s0, sp, 16
	li	a0, 99999
	call	print_int
	li	a0, 1
	j	.END_ppp
.END_ppp:
	ld	ra, 8(sp)
	ld	s0, 0(sp)
	addi	sp, sp, 16
	jr	ra
	.text
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp, sp, -48
	sd	ra, 40(sp)
	sd	s0, 32(sp)
	addi	s0, sp, 48
	li	t4, 0
	sw	t4, -20(s0)
	lw	t5, -20(s0)
	li	t6, 0
	beq	t5, t6, .Label2
	j	.Label3
.Label3:
	call	ppp
	sw	a0, -24(s0)
	lw	t5, -24(s0)
	bgtz	t5, .Label2
	j	.Label1
.Label2:
	li	a0, 11111
	call	print_int
	j	.Label1
.Label1:
	lw	t5, -20(s0)
	li	t6, 0
	beq	t5, t6, .Label6
	j	.Label5
.Label6:
	call	ppp
	sw	a0, -28(s0)
	lw	t5, -28(s0)
	bgtz	t5, .Label5
	j	.Label4
.Label5:
	li	a0, 22222
	call	print_int
	j	.Label4
.Label4:
	lw	t5, -20(s0)
	li	t6, 0
	beq	t5, t6, .Label9
	j	.Label7
.Label9:
	call	ppp
	sw	a0, -32(s0)
	lw	t5, -32(s0)
	bgtz	t5, .Label8
	j	.Label7
.Label8:
	li	a0, 33333
	call	print_int
	j	.Label7
.Label7:
	lw	t5, -20(s0)
	li	t6, 0
	beq	t5, t6, .Label10
	j	.Label12
.Label12:
	call	ppp
	sw	a0, -36(s0)
	lw	t5, -36(s0)
	bgtz	t5, .Label11
	j	.Label10
.Label11:
	li	a0, 44444
	call	print_int
	j	.Label10
.Label10:
	li	a0, 0
	j	.END_main
.END_main:
	ld	ra, 40(sp)
	ld	s0, 32(sp)
	addi	sp, sp, 48
	jr	ra
