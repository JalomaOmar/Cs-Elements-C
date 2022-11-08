#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define v 15
void patron();
void GotoXY(int, int);

int main() {
	getchar ();
	patron ();
	return 0;
}

void GotoXY(int x, int y){
	COORD coord;
	coord.X= x;
	coord.Y= y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void patron (){
	int i=0, l=1, r;
	for (i; i<=v; i++){
		r=i%4;
		if ((r==0)||(r==2)){
			int j=0;
			for (j; j<90; j++){
				printf("-");
			}
		}
		else if (r==1){
			int j=1;
			GotoXY(90, l);
			for (j; j<3; j++){
				GotoXY(90, l+j);
				printf ("|");
			}
			l=l+8;
			printf ("\n");
		}
		else if (r==3){
			int j=0;
			for (j; j<=3; j++){
				printf ("|\n");
			}
		}
	}
}

