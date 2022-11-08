#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

typedef struct CABALLO{
	int ren;
	int col;
	char fig[10];
} cab;

typedef struct CARRERA{
	int ColSalida;
	int ColFin;
	int RenIniCab;
	int RenFinCab;
} carrera;

void inicializacarrera(carrera, cab[], int);
void DibujaCaballos(cab [], int);
void dibujapista(carrera);
void GotoXY (int, int);
void dibujauncaballo(cab);

int main() {
	carrera car;
	cab horse, horse2, horse3;
	car.ColSalida=1;
	car.ColFin=80;
	car.RenIniCab=2;
	car.RenFinCab=20;
	horse.col=2;
	horse.ren=3;
	strcpy(horse.fig, "/(z)P");
	horse2.col=2;
	horse2.ren=8;
	strcpy(horse2.fig, "/()P");
	horse3.col=2;
	horse3.ren=14;
	strcpy(horse3.fig, "/(o)P"); 
	
	cab horses[]={horse, horse3, horse2};
	
	inicializacarrera(car, horses, 3);
	dibujapista(car);
	DibujaCaballos(horses, 3);
	GotoXY(79, 23);
	getchar();
	return 0;
}

void GotoXY (int x, int y){
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void dibujapista(carrera c){
	GotoXY(c.ColSalida, c.RenIniCab);
	int j=0;
	for(j; j<=(c.RenFinCab-c.RenIniCab); j++){
		GotoXY(c.ColSalida, c.RenIniCab+j);
		printf("|");
	} 
	j=0;
	for(j; j<=(c.RenFinCab-c.RenIniCab); j++){
		GotoXY(c.ColFin, c.RenIniCab+j);
		printf("|");
	}
}

void dibujauncaballo(cab h){
	GotoXY(h.col, h.ren);
	printf("%s", h.fig);
}

void DibujaCaballos(cab hs[], int NCABS){
	int i=0;
	for(i; i<NCABS; i++){
		dibujauncaballo(hs[i]);
	}
}

void inicializacarrera(carrera carr,cab eqs[], int NCABS){
	int k=0;
	for (k; k<NCABS; k++){
		eqs[k].col=(carr.ColSalida + 1);
	}
	k=0;
	for(k; k<NCABS; k++){
		int par;
		par= (carr.RenFinCab - carr.RenIniCab)/NCABS;
		eqs[k].ren=carr.RenIniCab + (k*par);
	}
	
}
