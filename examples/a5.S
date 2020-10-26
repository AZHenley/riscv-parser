.section .text
.global asmfloat
asmfloat:
	# float asmfloat(float a, int b, float c)
	# fa0 asmfloat(fa0, a0, fa1)
	
	fcvt.s.w     fa0, a0

	ret
