#include <stdio.h>
#include <stdlib.h>

#define X 81
#define Y 25

typedef struct matrixC{
	int nrens;
	int ncols;
	char** ptr;
} matrixC;

matrixC CreateMatrixC(int, int);
void FreeMatrixC(matrixC);
void PrintMatrixC(matrixC);
matrixC LeerEscenario(FILE *);
void PrintSt(FILE *);

int main(){
	FILE *fd;
	char dir[]="C:\\Users\\ACER\\Documents\\h.txt";
	fd=fopen(dir, "r");
	PrintSt(fd);
	fclose(fd);
	return 0;
}

matrixC CreateMatrixC(int m, int n){
	int i=0;
	matrixC r;
	r.nrens=m;
	r.ncols=n;
	r.ptr=(char**)malloc(m*sizeof(char*));
	if(r.ptr==NULL){
		printf("Error de memoria 1");
		exit(1);
	}
	for(i; i<m; i++){
		r.ptr[i]=(char*)malloc(n);
		if(r.ptr[i]==NULL){
			printf("Error de memoria 2");
			exit(1);
		}
	}
	return r;
}

void FreeMatrixC(matrixC A){
	int i=0;
	for(i; i<A.nrens; i++){
		free(A.ptr[i]);
	}
	free(A.ptr);
}

void PrintMatrixC(matrixC A){
	int i=0, j=0;
	for(i; i<A.nrens; i++){
		for(j; j<A.ncols; j++){
			printf("%c", A.ptr[i][j]);
			if(j==A.ncols-1){
				printf("\n");
			}
		}
		j=0;
	}
}

matrixC LeerEscenario(FILE *f){
	matrixC mundo2D;
	mundo2D=CreateMatrixC(Y, X);
	int i=0, j=0;
	for(i; i<Y; i++){
		for(j; j<X; j++){
			mundo2D.ptr[i][j]=getc(f);
		}
		j=0;
	}
	return mundo2D;
}

void PrintSt(FILE *f){
	matrixC mundo2D;
	mundo2D=LeerEscenario(f);
	PrintMatrixC(mundo2D);
}
