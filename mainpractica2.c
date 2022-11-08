#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, i=1, r, p;
	printf ("Este programa construye el triangulo de Floyd respectivo segun el usuario de el numero de pisos");
	getchar ();
	printf ("Ingrese el numero de pisos deseado: ");
	scanf ("%d", &n);
	for (i; i<=n; i++){
	    r=i%2;
	    if (r==1){
	    	int j=1;
	    	for (j;j<=i;j++){
	    		p=j%2;
	    		printf ("%d", p);
			}
		} else {
			int j=0;
			for (j;j<i;j++){
				p=j%2;
				printf ("%d", p);
			}
		}
		printf (" \n");
	}
		
	return 0;
}
