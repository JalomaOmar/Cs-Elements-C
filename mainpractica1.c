#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	int n, v=1, r;
	printf ("Este programa, dado un numero entero mayor o igual que cero y menor o igual a catorce, determinara su factorial");
	getchar ();
	printf ("Ingrese un numero con las especificaciones anteriores: ");
	scanf ("%d", &n);
	for (n; ((2<=n)&&(n<=14)); n-=2){
		r=n*(n-1);
		v=r*v;
	}
	if (n<0){
		printf ("La operacion factorial no esta definida para numeros negativos");
	}
	 else if (n>14){
		printf ("El numero es mayor que catorce, no cumple con las caracteristicas pedidas");
	}
	else {
	printf ("El factorial del numero ingresado es: %d", v);
}

	return 0;
}
