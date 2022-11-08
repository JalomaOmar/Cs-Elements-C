#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	float x1, x2, y1, y2, r1, r2, d, sr;
	printf ("Este programa determina, dados dos circulos en un plano, si estos se traslapan o no\n");
	getchar ();
	printf ("Introduzca las coordenadas x, y del primer circulo, respectivamente: ");
	scanf ("%f", &x1);
	scanf ("%f", &y1);
	printf ("Introduzca el radio del primer circulo: ");
	scanf ("%f", &r1);
	printf ("Introduzca las coordenadas x, y del segundo circulo, respectivamente: ");
	scanf ("%f", &x2);
	scanf ("%f", &y2);
	printf ("Introduzca el radio del segundo circulo: ");
	scanf ("%f", &r2);
	d= sqrt((pow((x2-x1), 2))+(pow((y2-y1), 2)));
	sr= (r1 + r2);
	if (d>sr){
		printf ("Los circulos no se traslapan");
	} else if (sr>d){
		printf ("Los circulos se traslapan");
	} else {
		printf ("Los circulos son tangentes");
	}
	
	
	
	return 0;
}
