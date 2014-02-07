#include <stdio.h>
#include "frac.h"

int main()
{
	frac f1 = fnew(1,2);
	frac f2 = fnew(2,1);

	printf("doubles: f1: %lf, f2: %lf\n\n", f2d(f1), f2d(f2));

	printf("i2f test: %s\n\n", f2s(i2f(7)));

	printf("f1: %s, f2: %s\nf1 + f2 = %s\nf1 - f2 = %s\nf1 * f2 = %s\nf1 / f2 = %s\n", f2s(f1), f2s(f2), f2s(fadd(f1, f2)), f2s(fsub(f1,f2)), f2s(fmul(f1, f2)), f2s(fdiv(f1,f2)));

	return 0;
}
