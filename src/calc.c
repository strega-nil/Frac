#include <stdio.h>
#include "frac.h"

int main()
{
	int n, m;
	frac f1, f2, f;
	char ch;

	printf("Which: ");
	scanf("%c", &ch);

	printf("Fraction 1: ");
	scanf("%d/%d", &n, &m);
	f1 = fnew(n, m);

	printf("Fraction 2: ");
	scanf("%d/%d", &n, &m);
	f2 = fnew(n, m);

	if(ch == 'a'){
		f = fadd(f1, f2);
	} else if(ch == 's'){
		f = fsub(f1, f2);
	} else if(ch == 'm'){
		f = fmul(f1, f2);
	} else if(ch == 'd'){
		f = fdiv(f1, f2);
	} else {
		printf("Fuck you.\n");
		return 0;
	}

	printf("%s\n", f2s(f));

	return 0;
}
