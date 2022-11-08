#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pareador(char [], int tam);
double SigmaGauss(unsigned int, unsigned int);
double Sigma(char[], unsigned int, unsigned int );

int main(int argc, char *argv[]) {
	char ef[23];
	strcpy(ef, "Hola");
	printf("%s", ef);
	return 0;
}

double SigmaGauss(unsigned int i, unsigned int n){
	double r=0;
	for(i; i<=n; i++){
		r+=i;
	}
	return r;
}

double Sigma(char ex[], unsigned int i, unsigned int n){
	if(pareador(ex, strlen(ex))!=0){
		exit(1);
	}
}

int pareador(char ex[], int tam){
	int i=0, d=0;
	for(i; i<tam; i++){
		if(ex[i]=='('){
			d++;
		}
		if(ex[i]==')'){
			d--;
		}
	}
	return d;
}
