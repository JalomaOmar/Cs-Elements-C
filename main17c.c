#include <stdio.h>
#include <stdlib.h>

int main() {
	int a[]={8, 9, 234, 32, 7546, 93};
	double b[]={98.458, 345.45, 985.234, 795.345567, 790.00};
	char c[]="Ciclopentanoperhidrofenantreno";
	int *ptri;
	double *ptrd;
	char *ptrc;
	ptri=&a[0];
	ptrd=&b[0];
	ptrc=&c[0];
	ptri++;
	ptrd++;
	ptrc++;
	printf("%d, %g, %c\n", *ptri, *ptrd, *ptrc);
	typedef struct COMPLEX{
		float real;
		float imag;
	} complex;
	complex i;
	complex *ptrcom;
	ptrcom=&i;
	printf("%d\n", ptrcom);
	ptrcom++;
	printf("%d", ptrcom);
	return 0;
}
