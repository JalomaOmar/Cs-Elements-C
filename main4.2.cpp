#include <stdio.h>
#include <stdlib.h>

#define MAY(A,B) (A>B? A:B)
#define NN 9

int main() {
	//Código Original
	/*int a, b, c; 
	printf ("Este programa determinara entre tres numeros enteros, cual es el mayor \"Los numeros ingresados deben ser forzosamente enteros\" \n");
	getchar ();
	printf ("Introduzca el primero numero: ");
	scanf ("%d", &a);
	printf ("Introduzca el segundo numero: ");
	scanf ("%d", &b);
	getchar ();
	printf ("Introduzca el tercer numero: ");
	scanf ("%d", &c);
	
	if ((a>=b)&&(b>=c)){
		printf ("El mayor es %d \n", a);
	}	else if ((a>=c)&&(c>=b)){
		printf ("El mayor es %d\n", a);
	}   else if ((b>=a)&&(a>=c)){
		printf ("El mayor es %d\n", b);
	}   else if ((b>=c)&&(c>=a)){
		printf ("El mayor es %d\n", b);
	}   else if ((c>=a)&&(a>=b)){
		printf ("El mayor es %d\n", c);
	}   else if ((c>=b)&&(b>=a)){
		printf ("El mayor es %d\n", c);
	}
	*/
	//Modificación
	printf ("Este programa determinara entre %d numeros enteros, cual es el mayor \"Los numeros ingresados deben ser forzosamente enteros\" \n", NN);
	int i=0, m;
	int a[NN];
	for(i; i<NN; i++){
		if(i==0){
			printf("Introduzca el primer numero: ");
		}else{
			printf("Introduzca el siguiente número: ");
		}
		scanf("%i", &a[i]);
		printf("\n");
	}
	i=0;
	m=a[0];
	for(i; i<NN; i++){
		if(m<a[i]){
			m=a[i];
		}
	}
	printf("El mayor es %d", m);
	return 0;
}
