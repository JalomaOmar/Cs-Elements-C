#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	float a, b, c, r1, r2, ri1p1, ri1p2;
	printf ("El siguiente programa determinara las raices de una ecuacion cuadratica de la forma \"Ax^2+Bx+C\" \n ");
	getchar ();
	printf ("Introduzca el coeficiente \"A\": ");
	scanf ("%f", &a);
	printf ("Introduzca el coeficiente \"B\": ");
	scanf ("%f", &b);
	printf ("Introduzca el coeficiente \"C\": ");
	scanf ("%f", &c);
	r1=(-b+sqrt((pow(b,2))-(4*a*c)))/(2*a);
	r2= (-b-sqrt((pow(b,2))-(4*a*c)))/(2*a);
	ri1p1=  ((-b)/(2*a)) ;
	ri1p2= ((sqrt(  fabs( (pow(b,2)) - (4*a*c) )))/(2*a));
	if (((pow(b,2))-(4*a*c))<0){
		printf("Las raices del polinomio son complejas, y son %f+%fi y %f-%fi", ri1p1, ri1p2, ri1p1, ri1p2);
	} else {
		printf ("Las raices del polinomio son: %f , %f \n", r1, r2);
	}
	
	return 0;
}
