#include <stdio.h>
#include <stdlib.h>

#define TM 10


int main(){ //No entendi, no pud� gg, que sad, hagan paro d�ganme como se hace, quiero entender este �ltimo, estuve intentado toda la tarde//
	float a[TM];
	int i=0, r;
	float m;
	for (i; i<TM; i++){
		m= (float)(rand()%100)/100.0;
		printf ("%.2f \n", m);
		m=a[i];
	} 
	scanf ("%d", &r);
	printf ("%.2f", a[TM]); 
	return 0;
}


