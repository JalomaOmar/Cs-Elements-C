#include <stdio.h>
#include <stdlib.h>

typedef struct MATRIX{
	int nrens;
	int ncols;
	float **ptr;
} matrix;

matrix CreateMatrix(int, int);
void FreeMatrix(matrix);

int main(int argc, char *argv[]) {
	matrix a;
	a=CreateMatrix(3, 3);
	a.ptr[2][3]=24;
	printf("%f\n", *(*(a.ptr+2)+3));
	*(*(a.ptr)+1)=13;
	printf("%f", a.ptr[0][1]);
	FreeMatrix(a);
	return 0;
}

matrix CreateMatrix(int r, int c){
	matrix reg;
	int i=0;
	reg.ncols=c;
	reg.nrens=r;
	reg.ptr=(float**)malloc(r*sizeof(float*));
	if(reg.ptr==0){
		printf("Error de memoria 1");
		exit(1);
	}
	for(i; i<r; i++){
		*(reg.ptr+i)=(float*)malloc(c*sizeof(float));
		if(*(reg.ptr+i)==NULL){
			printf("Error de memoria 2");
			exit(1);
		}
	}
	return reg;
}

void FreeMatrix(matrix a){
	int i=0, j=0;
	for(i; i<a.nrens; i++){
		free(*(a.ptr+i));
	}
	free(a.ptr);
}

