#include <stdio.h>
#include <stdlib.h>

#define AS 5;

typedef struct Matrix{
	int nrens;
	int ncols;
	float **ptr;
}matrix;

matrix CreateMatrix(int, int);
void FreeMatrix(matrix);
matrix PM(matrix, matrix);
void PrintMatrix(matrix);
void RFillMatrix(matrix);
void LlenarMat(float, matrix);

int main() {
	matrix A;
	A=CreateMatrix(2,3);
	LlenarMat(1, A);
	#ifdef AS
	A.ptr[0][0]=1;
	A.ptr[0][1]=0;
	A.ptr[0][2]=1;
	A.ptr[1][0]=0;
	A.ptr[1][1]=1;
	A.ptr[1][2]=2;
	#endif
	PrintMatrix(A);
	matrix B;
	B=CreateMatrix(3, 2);
	LlenarMat(2, B);
	#ifdef AS
	B.ptr[0][0]=3;
	B.ptr[1][0]=-1;
	B.ptr[2][0]=2;
	B.ptr[0][1]=5;
	B.ptr[1][1]=0;
	B.ptr[2][1]=-1;
	#endif 
	PrintMatrix(B);
	matrix C;
	C=PM(A, B);
	PrintMatrix(C);
	FreeMatrix(A);
	FreeMatrix(B);
	FreeMatrix(C);
	return 0;
}

matrix CreateMatrix(int m, int n){
	int i=0;
	matrix r;
	r.nrens=m;
	r.ncols=n;
	r.ptr=(float**)malloc(m*sizeof(float*));
	for(i; i<m; i++){
		r.ptr[i]=(float*)malloc(n*sizeof(float));
	}
	return r;
}

void FreeMatrix(matrix M){
	int i=0;
	int m;
	m=M.nrens;
	for(i; i<m; i++){
		free(M.ptr[i]);
	}
	free(M.ptr);
}

void PrintMatrix(matrix M){
	int i=0, j=0, m, n;
	m=M.nrens;
	n=M.ncols;
	for(i; i<m; i++){
		for(j; j<n; j++){
			if(j==0){
				printf("|\t");
			}
			printf("%f\t", M.ptr[i][j]);
			if(j==n-1){
				printf("|\n");
			}
		}
		j=0;
	}
	printf("\n");
}

void RFillMatrix(matrix M){
	int i=0, j=0, m, n;
	m=M.nrens;
	n=M.ncols;
	for(i; i<m; i++){
		for(j; j<n; j++){
			M.ptr[i][j]=(float)rand()/100.0;
		}
		j=0;
	}
}

void LlenarMat(float c, matrix M){
	int i=0, j=0, m, n;
	m=M.nrens;
	n=M.ncols;
	for(i; i<m; i++){
		for(j; j<n; j++){
			M.ptr[i][j]=c;
		}
		j=0;
	}
}

matrix PM(matrix M, matrix X){
	matrix R;
	R=CreateMatrix(M.nrens, X.ncols);
	int  i=0, j=0, m, n, k=0;
	m=M.nrens;
	n=M.ncols;
	LlenarMat(0, R);
	for(i; i<m; i++){
		for(k; k<m; k++){
		  for(j; j<n; j++){
		     R.ptr[i][k]+=M.ptr[i][j]*(X.ptr[j][k]);
		   }
		 j=0;
	    }
	    k=0;
	}
	return R;
}
