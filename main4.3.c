#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float b, B, h, A;
	printf ("Este programa calcula el area en metros cuadrados de cualquier trapecio isosceles\n");
	getchar ();
	printf ("Introduzca la longitud de la base mayor en metros: ");
	scanf ("%f", &B);
	printf ("Introduzca la longitud de la base menor en metros: ");
	scanf ("%f", &b);
	printf ("Introduzca la altura en metros: ");
	scanf ("%f", &h);
	A= ((B+b)*(0.5)*h);
	printf ("El area del trapecio es igual a %f metros cuadrados", A);
	
	return 0;
}
