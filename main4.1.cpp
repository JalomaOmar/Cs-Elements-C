#include <stdio.h>

int main(void) {
	float MN, USD, CD;
	printf ("Introduzca el monto de dinero en pesos mexicanos, que desea convertir: ");
	scanf ("%f", &MN);
	USD= (MN/(18.78));
	CD= (MN/(14.43));
	printf ("La cantidad que usted ingreso en moneda nacional es de %f dolares americanos \n", USD );
	printf ("Y esa misma cantidad es %f dolares canadienses", CD );
	
	return 0;
}
