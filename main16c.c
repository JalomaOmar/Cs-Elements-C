#include <stdio.h>
#include <stdlib.h>

int main() {
	double a=0;
	int b=0;
	float arr[]={0,0,0,0,0,0,0,0,0,0};
	
	int *ptrb;
	double *ptra;
	float *ptrarr0;
	
	ptrb=&b;
	*ptrb=2;
	printf("%d", b);
	
	getchar ();
	
    ptra=&a;
    *ptra=654.48;
    printf("%g", a);
    
    getchar();
    
   ptrarr0=&arr[0];
   *ptrarr0=2.32;
   printf("%f", arr[0]);
	
	
	return 0;
}
