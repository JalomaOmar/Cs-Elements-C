#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void GotoXY(int , int);
void ds(int, int, int);
void borrador();

int main() {
	int t, ini, fin;
	printf ("Ingrese el renglon: ");
	scanf ("%d", &t);
	printf ("Ingrese la columna inicial: ");
	scanf ("%d", &ini);
	printf("Ingrese la columna final: ");
	scanf ("%d", &fin);
	getchar ();
	borrador();
	ds(t, ini, fin);
	getchar ();
	return 0;
}

void ds(int l, int in, int f){
	int i=0, m;
	char r='-';
	m=f-in;
    for (i; i<= m ; i++){
	 GotoXY(in+i, l);
	 printf ("%c", r);
    }
	
}

void GotoXY (int x, int y){
	COORD coord;
	coord.X= x;
	coord.Y= y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void borrador (){
	int k=0;
	for (k; k<4; k++){
	 int j=0;
	 GotoXY(0, k);
	      for(j; j<120;j++){
	     printf (" ");
         }
  }
}
