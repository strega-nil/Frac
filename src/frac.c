#include <stdio.h>
#include <malloc.h>
#include "frac.h"

#define TRUE 1
#define FALSE 0


/* Internal Functions */

int ilen(int n)
{
	 int i;
	 for(i = 1; n >= 10; i++){
		 n = n / 10;
	 }
	 return i;
}

void equalDen(frac * f1, frac * f2)
{
	if(f1->den == f2->den){
		return;
	}
	
	int d1 = f1->den;
	int d2 = f2->den;

	f1->num = f1->num * d2;
	f1->den = f1->den * d2;

	f2->num = f2->num * d1;
	f2->den = f2->den * d1;
}

void simp(frac * f)
{
	if(f->num == 0){
		return;
	}

	int lpcf; // largest possible common factor

	if(f->num == f->den){
		f->num = 1;
		f->den = 1;
		return;
	} else if(f->num > f->den){
		lpcf = f->den;
	} else {
		lpcf = f->num;
	}

	for(int i = 1; i < lpcf; i++){
		if((f->num % i == 0) && (f->den % i == 0)){
			f->num = f->num / i;
			f->den = f->den / i;
		}
	}
}

/* External Functions */

// Fraction Creator
frac fnew(int num, int den)
{
	frac f = {num, den};
	return f;
}

// Fraction Casters
frac i2f(int n)
{
	frac f;
	f.num = n;
	f.den = 1;
	return f;
}

char* f2s(frac f)
{
	char* str;

	if(f.den == 1){
		str = malloc(sizeof(char) * (ilen(f.num) + 1));
		sprintf(str, "%d", f.num);
	} else {
		str = malloc(sizeof(char) * (ilen(f.num) + ilen(f.den) + 2));
		sprintf(str, "%d/%d", f.num, f.den);
	}

	return str;
}

double f2d(frac f)
{
	return (double)f.num / f.den;
}

// Fraction Boolean Operators
int feq(frac f1, frac f2)
{
	equalDen(&f1, &f2);
	if(f1.num == f2.num){
		return TRUE;
	} else {
		return FALSE;
	}
}

int fneq(frac f1, frac f2)
{
	return !(feq(f1, f2));
}

int fmor(frac f1, frac f2)
{
	equalDen(&f1, &f2);

	if(f1.num > f2.num){
		return TRUE;
	} else {
		return FALSE;
	}
}

int fles(frac f1, frac f2)
{
	return fmor(f2, f1);
}

int feqm(frac f1, frac f2)
{
	return !(fmor(f2, f1));
}

int feql(frac f1, frac f2)
{
	return !(fmor(f1, f2));
}


// Fraction Arithmetic
frac fadd(frac f1, frac f2)
{
	equalDen(&f1, &f2);

	f1.num = f1.num + f2.num;

	simp(&f1);

	return f1;
}

frac fsub(frac f1, frac f2)
{
	equalDen(&f1, &f2);

	f1.num = f1.num - f2.num;

	simp(&f1);

	return f1;
}

frac fmul(frac f1, frac f2)
{
	f1.num = f1.num * f2.num;
	f1.den = f1.den * f2.den;

	simp(&f1);

	return f1;
}

frac fdiv(frac f1, frac f2)
{
	f1.num = f1.num * f2.den;
	f1.den = f1.den * f2.num;

	simp(&f1);

	return f1;
}
