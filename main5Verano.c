#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct complex{
	double real;
	double imag;
} complex;

complex* Roots(double, double, double);
void PrintRoots(complex*);

int main(int argc, char *argv[]) {
	complex* rts1;
	rts1=Roots(1, 1, 1);
	PrintRoots(rts1);
	free(rts1);
	return 0;
}

complex* Roots(double a, double b, double c){
	complex* rts;
	rts=(complex*)malloc(2*sizeof(complex));
	if(rts==NULL){
		exit(1);
	}
	int i=0;
	double dis;
	dis=(pow(b, 2))-(4*a*c);
	if(dis==0){
		for(i; i<2; i++){
		 rts[i].real=((-b)/(2*a));
		 rts[i].imag=0;
	    }
	}else if(dis>0){
		rts[0].real=((-b)+sqrt(dis))/(2*a);
		rts[1].real=((-b)-sqrt(dis))/(2*a);
		rts[0].imag=0;
		rts[1].imag=0;
	}else {
		rts[0].real=(-b)/(2*a);
		rts[0].imag=(sqrt(fabs(dis)))/(2*a);
		rts[1].real=(-b)/(2*a);
		rts[1].imag=-(sqrt(fabs(dis)))/(2*a);
	}
	return rts;
}

void PrintRoots(complex* rts){
	int i=0;
	for(i; i<2; i++){
		if(rts[i].imag!=0){
			if(rts[i].real==0){
				if(rts[i].imag<0){
					printf("(x+%gi)", fabs(rts[i].imag));
				}else{
					printf("(x-%gi)", fabs(rts[i].imag));
				}
			}else{
				if(rts[i].real>0 && rts[i].imag>0){
					printf("(x-%g-%gi)", fabs(rts[i].real), fabs(rts[i].imag));
				}else if(rts[i].real>0 && rts[i].imag<0){
					printf("(x-%g+%gi)", fabs(rts[i].real), fabs(rts[i].imag));
				}else if (rts[i].real<0 && rts[i].imag>0){
					printf("(x+%g-%gi)", fabs(rts[i].real), fabs(rts[i].imag));
				}else if (rts[i].real<0 && rts[i].imag<0){
					printf("(x+%g+%gi)", fabs(rts[i].real), fabs(rts[i].imag));
				}
			}
		}else{
			if(rts[i].real<0){
				printf("(x+%g)", fabs(rts[i].real));
			}else{
				printf("(x-%g)", fabs(rts[i].real));
			}
		}
	}
}
