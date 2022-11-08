#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float polin(float [], float, int);

int main () {
	int g; //grado del polinomio//
	float fis[g+1]; //coeficientes del polinomio//
	float x;
	int i=0;
	printf ("Cual es el grado del polinomio?");
	scanf("%d", &g);
	for (i; i<=g; i++){
		printf ("Cual es el coeficiente para x a la %d: ", i);
		scanf("%f", &fis[i]);
	}
	printf ("En que valor de x quiere evaluar el polinomio?");
	scanf("%f", &x);
	float r;
	r=polin(fis, x, g);
	printf ("El valor del polinomio en ese x es %f", r);
	return 0;
}

float polin(float coef[], float x, int grad){
	float s=0;
	int j=0;
	for (j; j<=grad; j++){
		s=s+((pow(x, j))*(coef[j]));
    }
    return s;
}


