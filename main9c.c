#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TM 2 //Tamaño del arreglo//

float media(int[]);
int suma(int[]);
float var (int []);

int main() {
	int a[TM];
	int i=0;
	float va;
	for (i;i<TM;i++){
		a[i]=rand();
		printf ("%d \n", a[i]);
	}
	va=var(a);
	printf ("%f", va);
	return 0;
}

float media(int vec[]){
	float s;
	s=(float)sumav(vec)/(float)TM;
	return s;
}

int sumav(int vec[]){
	int j=0, s=0, r=0;
	for (j;j<TM;j++){
		s=vec[j];
		r=r+s;
	}
	return r;
}


float var(int vec[]){
	int k=0;
	float r=0,s, s2, v;
	for (k;k<TM;k++){
		s2= vec[k]- media(vec);
		s= pow(s2,2);
		r=r+s;
		v= s/(float)TM;
	}
	v= r/(float)TM;
	return v;
}

