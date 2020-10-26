.section .text
.global floatadd
floatadd:
	# float floatadd(float a, float *b, double c, double *d);
	# fa0  floatadd(fa0, a0, fa1, a1)

	flw	fa2, 0(a0)
	fld	fa3, 0(a1)

	fcvt.s.d	fa1, fa1
	fcvt.s.d	fa3, fa3

	fadd.s	fa1, fa1, fa3
	fadd.s	fa0, fa0, fa2
	fadd.s	fa0, fa0, fa1

	ret
