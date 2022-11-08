#include <stdio.h>
#include <stdlib.h>

typedef struct COMPLEX{
	float real;
	float imag;
} complex;

complex sumc(complex, complex);
complex resc(complex, complex);
complex prox(complex, complex);

int main(int argc, char *argv[]) {
	complex a, b, c, d, e;
	a.real=3;
	a.imag=2;
	b.real=2;
	b.imag=1;
	c=sumc(a, b);
	d=resc(a, b);
	e=prox(a, b);
	return 0;
}

complex sumc(complex p, complex q){
	complex sum;
	sum.real= p.real + q.real;
	sum.imag=p.imag + q.imag;
	return sum;
}

complex resc(complex r, complex s){
	complex res;
	res.real= r.real - s.real;
	res.imag= r.imag - s.imag;
	return res;
}

complex prox(complex m, complex n){
	complex prod;
	prod.real= (m.real*n.real)+(-(m.imag*n.imag));
	prod.imag=(m.imag*n.real)+(m.real*n.imag);
	return prod;
}
