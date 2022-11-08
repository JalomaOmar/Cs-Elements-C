#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IN   1  
#define F   1987


int ad();


int ad(){
	int h, j=1, t, a=IN, b=F;
	int r; 
	t=(log2((F-IN)+1))+1; 
	printf ("Este programa adivinara en menos de %d intentos un número entre %d y %d, el programa arrojara un candidato, si el numero que usted esta pensando es menor, presione la tecla \"0\", si es mayor presione \"1\", y si es el numero que usted penso presione \"2\" ", t, IN, F );
	getchar ();
	h=((IN+F)/2);
	do{
	 printf ("%d \n", h);
	 scanf ("%d", &r);
	   if (r==2){
	   	return j;
	   }
	   else if (r==0){
	   	b=h-1;
	   	h=(((h-a)/2)+a);
	   	j=j+1;
	   } 
	    else{
	   	a=h+1;
	   	h=((b+h+1)/2);
	   	j=j+1;
	   } 
    } while (r!=2);
 }

int main() {
	int m;  
	m= ad();
	printf ("Se adivino el numero en %d intentos", m);
	return 0;
}
