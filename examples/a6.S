.section .text
.global asmfloat
asmfloat:
	# float asmfloat(float *a, int *b, float *c)
	# fa0 asmfloat(a0, a1, a2)
	
	flw	fa0, 0(a0)


	ret
