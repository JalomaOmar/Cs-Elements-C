#include <stdio.h>
#include <stdlib.h>

#define TM 1000 //Tamaño del arreglo//

int oso(int []);

int main() {
	int i=0, s;
	int a[TM];
	for (i;i<TM;i++){
		a[i]=(rand()%26)+97;
	}
    s=oso(a);
    printf ("%d", s);
	
	return 0;
}

int oso(int vec[]){
	int k=0;
		for (k;k<TM;k++){
		if ((vec[k]==111)&&(vec[k+1]==115)&&(vec[k+2]==111)){
			return 1;
		}
	}
	return 0;
}
