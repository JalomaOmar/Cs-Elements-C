#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int divide(int b);
int primo(int a);

int divide(int b){
	int r, i=201;
	for(i;i<334;i++){
	r= (b%i);
	if (r==0){
		return 1; 
	} else {
		return 0;
	}
  }
}

int primo(int a){
	if ( ((a%2)==0) || ((a%11)==0) || ((a%34)==0) || ((divide(a)))){
	return 0;
} else {
	return 1;
}

}
int main() {
	int g, h;
	printf ("Ingrese un numero y se determinara con no mucha certeza si es primo o no");
	scanf ("%i", &g);
	h=primo(g);
	if (h==0){
		printf ("El numero no es primo \n");
	} else {
		printf ("El numero es primo");
	}
	return 0;
}
