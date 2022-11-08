#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100000

double varianza(double*, int);
double media (double*, int);

int main() {
	int i=0;
	double v1, v2, v3;
    double vec[N];
	double *ptr1, *ptr2, *ptr3;
	for(i; i<N; i++){
		vec[i]=(float)rand()/10.00;
	}
	ptr1=&vec[0];
	ptr2=&vec[20000];
	ptr3=&vec[50000];
	v1=varianza(ptr1, 20000);
	v2=varianza(ptr2, 30000);
	v3=varianza(ptr3, 50000);
	printf("%g \n", v1);
	printf("%g \n", v2);
	printf("%g ", v3);
	return 0;
}

double varianza(double *ap, int n){
	double s=0, m, v;
	int j=0;
	m=media(ap, n);
	for(j; j<n; j++){
		s=s+(pow(((*ap)-m), 2));
		ap++;
	}
	v=s/(double)n;
	return v;
}

double media(double *ap, int n){
	double s=0, m;
	int j=0;
	for(j; j<n; j++){
		s=s+*ap;
		ap++;
	}
	m=s/(double)n;
	return m;
}

