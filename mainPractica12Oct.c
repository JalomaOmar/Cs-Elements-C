#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cuad(int, int, int, float*, float*);

int main() {
	int A, B, C, r;
	float x1, x2;
	float *ptr1, *ptr2;
	ptr1=&x1;
	ptr2=&x2;
    A=1;
    B=1;
    C=-6;
    r=cuad(A, B, C, ptr1, ptr2);
    printf(" ");
	return 0;
}
int cuad(int a, int b, int c, float*x1, float*x2){
	float r1, r2;
    r1=(-(float)b+sqrt((pow(b,2))-(4*a*c)))/(float)(2*a);
	r2= (-(float)b-sqrt((pow(b,2))-(4*a*c)))/(float)(2*a);
	if (((pow(b,2))-(4*a*c))<0){
		return 0;
	} else {
		*x1=r1;
		*x2=r2;
		if(r1==r2){
			return 1;
		}else{
			return 2;
		}
	}
}
