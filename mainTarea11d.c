#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

#define PI 3.141592
#define es 10
#define part 2000

void GotoXY(int, int);
void circle();

int main() {
    circle();
    getchar();
	return 0;
}

void GotoXY(int x, int y){
	COORD coord;
	coord.X= x;
	coord.Y= y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void circle(){
	int i=0;
	float m=((2*PI)/part), r;
	GotoXY(40, 12);
	for (i;i<=part; i++){
		r=i*m;
		GotoXY(round(40+es*2*(cos(r))), round(12+es*(sin(r))));
		printf("o");
	}
}


