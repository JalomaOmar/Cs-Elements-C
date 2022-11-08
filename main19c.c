#include <stdio.h>
#include <stdlib.h>

typedef struct MATRIX{
	int nrens;
	int ncols;
	float **ptr;
} matrix;

matrix CreateMatrix(int, int);
void FreeMatrix(matrix);
matrix TransposeM(matrix);

int main(int argc, char *argv[]) {
	matrix a;
	matrix at;
	int i=0, j=0;
	a=CreateMatrix(2, 3);
	a.ptr[0][2]=25;
	at=TransposeM(a);
	printf("%f", at.ptr[2][0]);
	FreeMatrix(a);
	FreeMatrix(at);
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
	int i=0;
	for(i; i<a.nrens; i++){
		free(*(a.ptr+i));
	}
	free(a.ptr);
}

matrix TransposeM(matrix a){
	int i=0, j=0;
	matrix t;
	t=CreateMatrix(a.ncols, a.nrens);
	for(i; i<a.nrens; i++){
		for(j;j<a.ncols; j++){
			t.ptr[j][i]=a.ptr[i][j];
		}
		j=0;
	}
	return t;
}
