#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	int i=2,s=0;
	printf ("El siguiente programa calcula la suma de todos los numeros naturales pares de 2 hasta 5504");
	getchar ();
	for (i; i<=5504; i+=2){
	s=i+s;
}
	printf ("La suma de todos los naturales pares de 2 hasta 5504 es: %d", s);
	return 0;
}
