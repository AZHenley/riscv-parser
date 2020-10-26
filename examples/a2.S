.section .rodata
prompt: .asciz "Enter: "
scan: .asciz "%s"
output: .asciz "%d\n"

.section .text
.global getasm
getasm:
	# void (a0 s[], a1 size, a2 value)

	li	t0, 0
1:
	bge	t0, a1, 1f

	slli	t1, t0, 2
	add	t2, t1, a0

	lw	t3, 0(t2)
	mul	t3, t3, a2
	sw	t3, 0(t2)

	addi	t0, t0, 1
	j	1b

1:

	ret

.global getasm2
getasm2:
	# void (a0 s[], a1 size)

	addi	sp, sp, -8
	sd	ra, 0(sp)

	li	t0, 0   # result
	li	t1, 0	# i

1:
	bge	t1, a1, 1f

	slli	t2, t1, 2
	add	t2, a0, t2

	lw	t3, 0(t2)
	add	t0, t0, t3  # result = result + s[i]

	addi	t1, t1, 1
	j	1b
1:
	la	a0, output
	mv	a1, t0
	call	printf
	
	ld	ra, 0(sp)
	addi	sp, sp, 8
	ret


.global getasm3
getasm3:
	# int getasm(char s[])
	# a0 getasm(a0)

	addi	sp, sp, -16
	sd	ra, 0(sp)
	sd	s0, 8(sp)

	mv	s0, a0

	la	a0, prompt
	call	printf

	la	a0, scan
	mv	a1, s0
	call	scanf

	mv	a0, s0
	call	strlen		


	ld	ra, 0(sp)
	ld	s0, 8(sp)
	addi	sp, sp, 16
	ret
