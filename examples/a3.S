.section .text
.global doasm
doasm:
	# void doasm(MyStruct s[], int size)
	# void doasm(a0, a1)

	li	t0, 0   # i
1:
	bge	t0, a1, 1f

	slli	t1, t0, 3
	add	t1, t1, a0

	lb	t2, 0(t1)  # s[i].a
	lb	t3, 1(t1)  # s[i].b

	add	t3, t2, t3
	sw	t3, 4(t1)  # s[i].c = s[i].a + s[i].b


	addi	t0, t0, 1
	j	1b
1:

	ret
