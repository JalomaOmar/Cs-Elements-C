#include <stdio.h>
#include <stdlib.h>

float pr(){
	float n=0, s=0, p;
	float i=0.0;
	
		printf ("Ingrese los numeros, \(despues de ingresar un numero presione \"Enter\" para poder ingresar el siguiente) \n");
	do{
		
		s=s+n;
		p=(s/i);
		i=i+1;
		scanf ("%f", &n);
	
	} while (n>=0);
	
	return p;
}
int main() {
	float h;
	printf ("Este programa calcula el promedio de numeros no negativos introducidos. Para avisar que quieres terminar de ingresar numeros, ingresa un numero negativo, este no se tomara en cuenta para el promedio. \n");
	getchar ();
	h= pr();
	printf ("El promedio es: %f", h);
	return 0;
}
