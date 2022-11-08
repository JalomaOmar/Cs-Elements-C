#include <stdio.h>
#include <stdlib.h>

#define TM 6

typedef struct VECTOR{
	int n;
	float* pt;
} vector;

void FreeVec(vector);
vector CreateVec(int);
float PrIn(vector, vector);

int main() {
	vector A;
	A=CreateVec(TM);
	vector B;
	B=CreateVec(TM);
	int i=0;
	for(i; i<TM; i++){
		*(A.pt+i)=2;
		*(B.pt+i)=3;
	}
	float re;
	re=PrIn(A, B);
	printf("%f", re);
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

float PrIn (vector A, vector B){
	if(A.n!=B.n){
		printf("Los vectores no tienen las mismas dimensiones");
		exit(1);
	}
	int i=0;
	float r=0;
	for(i; i<A.n; i++){
		r=r+((*(A.pt+i))*(*(B.pt+i)));
	}
	return r;
}
