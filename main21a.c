#include <stdio.h>
#include <stdlib.h>

typedef struct matrix{
	int nrens;
	int ncols;
	float** ptr;
} matrix;

matrix CreateMatrix(int, int);
void FreeMatrix(matrix);
void PrintMatrix(matrix);
void LlenaMat(float, matrix);
matrix LeerMatriz(FILE*);

int main(int argc, char *argv[]) {
	matrix M;
	FILE *f;
	char c[]="C:\\Users\\ACER\\Documents\\h.txt";
	f=fopen(c, "r");
	M=LeerMatriz(f);
	PrintMatrix(M);
	fclose(f);
	FreeMatrix(M);
	
	return 0;
}

matrix CreateMatrix(int m, int n){
	int i=1;
	matrix r;
	r.nrens=m;
	r.ncols=n;
	r.ptr=(float**)malloc(m*sizeof(float*));
	if(r.ptr==NULL){
		printf("Error de memoria 1");
	}
	r.ptr[0]=(float*)malloc(n*m*sizeof(float));
	if(r.ptr[0]==NULL){
		printf("Error de memoria 2");
	}
	for(i; i<m; i++){
		r.ptr[i]=r.ptr[0]+(n*i);
	}
    
	return r;
}

void FreeMatrix(matrix M){
    free(M.ptr[0]);
	free(M.ptr);
}

void PrintMatrix(matrix M){
	int i=0, j=0;
	for(i; i<M.nrens; i++){
		for(j; j<M.ncols; j++){
			if(j==0){
				printf("| ");
			}
			printf("%f ", M.ptr[i][j]);
			if(j==M.ncols-1){
				printf("|\n");
			}
		}
		j=0;
	}
}

void LlenaMat(float c, matrix M){
	int i=0, j=0;
	for(i; i<M.nrens; i++){
		for(j; j<M.ncols; j++){
			M.ptr[i][j]=c;
		}
		j=0;
	}
}

matrix LeerMatriz(FILE *f){
	matrix r;
	if(f==NULL){
		printf("no se encontro el archivo");
		exit(1);
	}
	fscanf(f, "%d", &r.nrens);
	fscanf(f, "%d", &r.ncols);
	r=CreateMatrix(r.nrens, r.ncols);
	int i=0, j=0;
	for(i; i<r.nrens; i++){
		for(j; j<r.ncols; j++){
			fscanf(f, "%f", &r.ptr[i][j]);
		}
		j=0;
	}
	return r;
}
