#include <stdio.h>
#include <stdlib.h>

typedef struct matrix{
	int nrens;
	int ncols;
	float** ptr;
} matrix;

matrix CreateMatrix(int, int);
void FreeMatrix(matrix);
void WMT(matrix, FILE *);//Ésta es la función
int main(int argc, char *argv[]) {
	FILE *f;
	char c[]="C:\\Users\\ACER\\Documents\\w.txt";
	f=fopen(c, "w");
	matrix A;
	A=CreateMatrix(2, 3);
    WMT(A, f);
	FreeMatrix(A);
	fclose(f);
	return 0;
}

matrix CreateMatrix(int m, int n){
	matrix r;
	r.nrens=m;
	r.ncols=n;
	int i=1;
	r.ptr=(float**)malloc(m*sizeof(float*));
	r.ptr[0]=(float*)malloc(m*n*sizeof(float));
	for(i; i<m; i++){
		r.ptr[i]=r.ptr[0]+(n*i);
	}
	return r;
}

void FreeMatrix(matrix M){
	free(M.ptr[0]);
	free(M.ptr);
}

void WMT(matrix A, FILE *f){
	int i=0, j=0;
	fprintf(f, "%d ", A.nrens);
	fprintf(f, "%d\n", A.ncols);
	for(i; i<A.nrens; i++){
		for(j; j<A.ncols; j++){
			fprintf(f, "%f ", A.ptr[i][j]);
			if(j==A.ncols-1){
				fprintf(f, "\n");
			}
		}
		j=0;
	}
}
