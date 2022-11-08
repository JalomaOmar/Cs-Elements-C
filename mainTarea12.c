#include <stdio.h>
#include <stdlib.h>

int loncad(char []);

int main() {
	char a[]="";
	printf("Existen %d elementos en la cadena", loncad(a));
	return 0;
}

int loncad(char vec []){
	int j=0;
	for (j; j>=0; j++){
		if (vec[j]==0){
			break;
		}
	}
	return j;
}
