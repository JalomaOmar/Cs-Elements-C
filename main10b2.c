#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void dsv(int, int, int);
void GotoXY( int, int);
void borrador();

int main() {
	int c, in, fin;
	printf ("Ingrese la columna: ");
	scanf ("%d", &c);
	printf ("Ingrese el renglon inicial: ");
	scanf ("%d", &in);
	printf ("Ingrese el renglon final: ");
	scanf ("%d", &fin);
	dsv(c, in, fin);
	getchar ();
	return 0;
}

void dsv(int col, int ri, int rf){
	int l;
	char r='|';
	borrador();
	for (l; l<=(rf-ri); l++){
	  GotoXY(col, ri+l);
	  printf("%c", r);	
	}
	getchar ();
}

void GotoXY(int x, int y){
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void borrador(){
    int k=0;
    for (k; k<4; k++){
    	int j=0;
    	GotoXY(0,k);
    	for (j; j<120; j++){
    	printf (" ");
        }
	}
}
