#ifndef _FRAC_H
#define _FRAC_H

typedef struct {
	int num, den;
} frac;

// Fraction Creator
frac   fnew(int num, int den);

// Fraction Changers
frac   i2f(int i);
char*  f2s(frac f);
double f2d(frac f);

// Fraction Boolean Operators
int    feq(frac f1, frac f2);
int    fneq(frac f1, frac f2);
int    fmor(frac f1, frac f2);
int    fles(frac f1, frac f2);
int    feqm(frac f1, frac f2);
int    feql(frac f1, frac f2);

// Fraction Arithmetic
frac   fadd(frac f1, frac f2);
frac   fsub(frac f1, frac f2);
frac   fmul(frac f1, frac f2);
frac   fdiv(frac f1, frac f2);

#endif
