#include <stdio.h>
#include <stdlib.h>

int main() {
	char vc[24];
	unsigned u[]={23, 54, 67, 45, 14, 89};
	unsigned *ptr;
	char *ptrIL;
	int i=0;
	for(i; i<24; i++){
		vc[i]=97+i;
	}
	ptrIL=&vc[0];
	ptr=(unsigned*)ptrIL;
	i=0;
	for(i; i<6; i++){//Caben seis unsigned int's en el espacio de memoria que hay para 24 char, ya que un char tiene tamaño de 1 byte y un unsigned de 4 bytes, lo probé con el debugger// 
		 *ptr=u[i];
		 ptr++;
	}
	return 0;
}
