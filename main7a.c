#include <stdio.h>
#include <stdlib.h>
int main() {
	int a, b;
	a=1-7+2*2/2; //Podríamos suponer que este resultado es "-5" sin embargo, por la precedencia de los operadores el resultado es "-4"//
	printf ("%d \n", a);
	if ((1-7+2*2/2>=-5) && (a>=3) || (a>0)){
		printf("s");
		
	}
	if ((1-7+2*2/2>=-5) || (a>=3) && (a>0)){
		printf ("q");
	} //Por la precedencia de los operadores, podemos notar que sólo se cumple la segunda proposición como verdad y por ello se imprime q//
	
	return 0;
}
