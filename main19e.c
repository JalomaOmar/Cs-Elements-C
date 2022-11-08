#include <stdio.h>
#include <stdlib.h>

typedef struct VECTOR{
	int n;
	float* pt;
} vector;

void FreeVec(vector);
vector CreateVec(int);
vector EsVec(int, vector);

int main() {
	vector A;
	A=CreateVec(9);
	int i=0;
	for(i; i<9; i++){
		*(A.pt+i)=3;
	}
	vector B;
	B=EsVec(3, A);
	FreeVec(A);
	FreeVec(B);
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

vector EsVec(int c, vector A){
	int i=0;
	vector r;
	r=CreateVec(A.n);
	for(i; i<A.n; i++){
		*(r.pt+i)=((*(A.pt+i))*c);
	}
	return r;
}
