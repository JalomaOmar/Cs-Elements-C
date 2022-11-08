#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define LONG 14 //Este parámentro define que tan largo es el rebote//
void GotoXY(int, int);
void borrador();

int main() {
	int col, ren, re;
	borrador();
	while (1){
	 for (col=0; col<80; col+=2*LONG){
	   for (ren=0; ren<LONG; ren++){
	   	GotoXY (col+ren, ren);
	   	printf ("o");
	   	getchar ();
	   	GotoXY (col+ren, ren);
	   	printf (" ");
	   }
	   for (re=0; re<LONG; re++){
	   	GotoXY (re+LONG+col, LONG-re);
	   	printf ("o");
	   	getchar ();
	   	GotoXY (col+re+LONG, LONG-re);
	   	printf (" ");
	   }
     }
    }
	return 0;
}

void GotoXY(int x, int y){
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void borrador (){
	int col=0, ren;
	GotoXY(1,1);
	for (col; col<70;col++){
		printf (" ");
     }
    GotoXY (1,1);
}
