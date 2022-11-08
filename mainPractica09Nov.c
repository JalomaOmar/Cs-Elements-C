#include <stdio.h>
#include <stdlib.h>

typedef struct complex{
	float real;
	float imag;
}complex;

typedef struct ComplexMatrix{
	int nrens;
	int ncols;
	complex** ptr;
}ComplexMatrix;

typedef struct ComplexVector{
	int dim;
	complex* pt;
} ComplexVector;

ComplexVector CreateCVector(int);
void FreeCVector(ComplexVector);
ComplexMatrix CreateCMatrix(int, int);
void FreeCMatrix(ComplexMatrix);
void FillCMatrixR(ComplexMatrix);
void PrintCMatrix(ComplexMatrix);
void DCMatrix(FILE*, ComplexMatrix);
ComplexMatrix ReadCMatrix(FILE*);
void FillCVectorR(ComplexVector);
void PrintCVector(ComplexVector);

int main(int argc, char *argv[]) {
	/*FILE* fd;
	char dir[]="C:\\Users\\ACER\\Documents\\CMat.txt";
	fd=fopen(dir, "wt");
	ComplexMatrix A;
	A=CreateCMatrix(3, 1);
	FillCMatrixR(A);
	DCMatrix(fd, A);
	//A=ReadCMatrix(fd);
	PrintCMatrix(A);
	FreeCMatrix(A);
	fclose(fd);*/
	ComplexVector B;
	B=CreateCVector(5);
	FillCVectorR(B);
	PrintCVector(B);
	FreeCVector(B);
	return 0;
}

ComplexMatrix CreateCMatrix(int m, int n){
	int i=1;
	ComplexMatrix r;
	r.nrens=m;
	r.ncols=n;
	r.ptr=(complex**)malloc(m*sizeof(complex*));
	if(r.ptr==NULL){
		printf("Error de memoria 1");
		exit(1);
	}
	r.ptr[0]=(complex*)malloc(m*n*sizeof(complex));
	if(r.ptr[0]==NULL){
		printf("Error de memoria 2");
		exit(1);
	}
	for(i; i<m; i++){
		r.ptr[i]=r.ptr[0]+(n*i);
	}
	return r;
}

void FreeCMatrix(ComplexMatrix M){
	free(M.ptr[0]);
	free(M.ptr);
}

void FillCMatrixR(ComplexMatrix M){
	int i=0, j=0, p, q;
	srand(time(NULL));
	for(i; i<M.nrens; i++){
		for(j; j<M.ncols; j++){
			p=rand();
			q=rand();
			M.ptr[i][j].real=(float)rand()/(float)p;
			M.ptr[i][j].imag=(float)rand()/(float)p;
			if(p%2==0){
				M.ptr[i][j].real*=(-1);
			}
			if(q%2==0){
				M.ptr[i][j].imag*=(-1);
			}
		}
		j=0;
	}	
}

void PrintCMatrix(ComplexMatrix M){
	int i=0, j=0;
	for(i; i<M.nrens; i++){
		for(j; j<M.ncols; j++){
			if(j==0){
				printf("|\t");
			}
			printf("%f", M.ptr[i][j].real);
			if(M.ptr[i][j].imag>0){
			printf("+");
		    }
			printf("%fi \t", M.ptr[i][j].imag);
			if(j==M.ncols-1){
				printf("|\n");
			}
		}
		j=0;
	}
}

void DCMatrix(FILE* f, ComplexMatrix M){
	int i=0, j=0;
	fprintf(f, "%d ", M.nrens);
	fprintf(f, "%d\n", M.ncols);
	for(i; i<M.nrens; i++){
		for(j; j<M.ncols; j++){
			fprintf(f, "%f", M.ptr[i][j].real);
			if(M.ptr[i][j].imag>0){
				fprintf(f, "+");
			}
			fprintf(f, "%fi \t", M.ptr[i][j].imag);
			if(j==M.ncols-1){
				fprintf(f, "\n");
			}
		}
		j=0;
	}
}

ComplexMatrix ReadCMatrix(FILE* f){
	ComplexMatrix M;
	int i=0, j=0;
	fscanf(f, "%d", &M.nrens);
	fscanf(f, "%d", &M.ncols);
	M=CreateCMatrix(M.nrens, M.ncols);
	for(i; i< M.nrens; i++){
		for(j; j<M.ncols; j++){
			fscanf(f, "%f", &M.ptr[i][j].real);
			
			fscanf(f, "%f", &M.ptr[i][j].imag);
		}
		j=0;
	}
	return M;
}

ComplexVector CreateCVector(int n){
	ComplexVector R;
	R.dim=n;
	R.pt=(complex*)malloc(n*sizeof(complex));
	if(R.pt==NULL){
		printf("Error de memoria 1v");
		exit(1);
	}
	return R;
}

void FreeCVector(ComplexVector V){
	free(V.pt);
}

void FillCVectorR(ComplexVector V){
	int i=0, p, q;
	srand(time(NULL));
	for(i; i<V.dim; i++){
		p=rand();
		q=rand();
		V.pt[i].real=(float)rand()/(float)rand();
		V.pt[i].imag=(float)rand()/(float)rand();
		if(p%2==0){
			V.pt[i].real*=(-1);
		}
		if(q%2==0){
			V.pt[i].imag*=(-1);
		}
	}
}

void PrintCVector(ComplexVector V){
	int i=0;
	for(i; i<V.dim; i++){
		printf("|\t%f", V.pt[i].real);
		if(V.pt[i].imag>0){
			printf("+");
		}
		printf("%fi \t|\n", V.pt[i].imag);
	}
}
