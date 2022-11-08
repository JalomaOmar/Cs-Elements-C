#include <stdio.h>
#include <stdlib.h>

typedef struct VECTOR{
	int n;
	float* pt;
} vector;

typedef struct MATRIX{
	int nrens;
	int ncols;
	float **ptr;
} matrix;

matrix CreateMatrix(int, int);
void FreeMatrix(matrix);
void FreeVec(vector);
vector CreateVec(int);
vector EsVec(float, vector);
vector SV(vector, vector);
vector PrMV(matrix, vector);
void LlenarVec(vector, float);
void LlenarMat(matrix, float);
void EsVecM(float, vector);
void SVM(vector, vector);

int main(int argc, char *argv[]) {
    matrix M;
    vector A;
    vector R;
    M=CreateMatrix(2, 3);
    A=CreateVec(3);
    LlenarMat(M, 3);
    LlenarVec(A, 2);
    R=PrMV(M, A);
    FreeMatrix(M);
    FreeVec(A);
    FreeVec(R);
	return 0;
}

vector CreateVec(int m){
	vector r;
	r.n=m;
	r.pt=(float*)malloc(m*sizeof(float));
	return r;
}

void FreeVec(vector A){
	free(A.pt);
}

vector EsVec(float c, vector A){
	int i=0;
	vector r;
	r=CreateVec(A.n);
	for(i; i<A.n; i++){
		*(r.pt+i)=((*(A.pt+i))*c);
	}
	return r;
}

vector SV(vector A, vector B){
	int i=0;
	vector r;
	if(A.n!=B.n){
		printf("Los vectores no tienen las mismas dimensiones");
		exit(1);
	}
	r=CreateVec(A.n);
	for(i; i<A.n; i++){
		*(r.pt+i)=*(A.pt+i)+*(B.pt+i);
	}
	return r;
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

void LlenarVec(vector A, float c){
	int i=0;
	for(i; i<A.n; i++){
		*(A.pt+i)=c;
	}
}

void LlenarMat(matrix M, float c){
	int i=0, j=0;
	for(i; i<M.nrens; i++){
		for(j;j<M.ncols;j++){
			*(*(M.ptr+i)+j)=c;
		}
		j=0;
	}
}
void EsVecM(float c, vector A){
	int i=0;
	for(i; i<A.n; i++){
		*(A.pt+i)=((*(A.pt+i))*c);
	}
}

void SVM(vector A, vector B){
	int i=0;
	if(A.n!=B.n){
		printf("Los vectores no tienen las mismas dimensiones");
		exit(1);
	}
	for(i; i<A.n; i++){
		*(A.pt+i)=*(A.pt+i)+*(B.pt+i);
	}
}

vector PrMV(matrix M, vector A){
	int i=0, j=0;
	if(M.ncols!=A.n){
		printf("Las dimensiones no permiten el calculo");
		exit(1);
	}
	vector vr;
	vr=CreateVec(M.nrens);
	LlenarVec(vr, 0);
	vector vp;
	vp=CreateVec(M.nrens);
    for(i; i<M.ncols; i++){
    	for(j; j<M.nrens; j++){
			*(vp.pt+ i)=*(*(M.ptr+i)+j);//Aquí me marca segmentation fault, no sé qué está mal//
		}
		j=0;
		EsVecM(*(A.pt+i), vp);//Creé una función que calcula el producto de un escalar con un vector y lo deja en el mismo vector//
		SVM(vr, vp);//Creé una función que suma dos vectores y se queda en la misma dirección de memoria del primer vector//
	}
	return vr;
}

