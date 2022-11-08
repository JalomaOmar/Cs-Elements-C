#include <stdio.h>
#include <stdlib.h>

int main() {
	char cad[]={'a','b','c','\0'};
	char *ptr, *ptr2;
	ptr=&cad[0];
	ptr++;
	*ptr='z';
	printf("%c", cad[1]);
	ptr=ptr+1;
	*ptr=65;
	printf("%c", cad[2]);
	ptr=ptr-1;
	*ptr=100;
	printf("%c", cad[1]);
	ptr--;
	*ptr=98;
	printf("%c\n", cad[0]);
	ptr2=&cad[1];
	if (ptr>ptr2){
		printf("Verdad\n");
	} else{
		printf("Falso\n");
	}
	ptr2--;
	if(ptr==ptr2){
		printf("Posición correcta\n");
	}
	ptr++;
	if(ptr!=ptr2){
		printf("Sí");
	}
	return 0;
}
