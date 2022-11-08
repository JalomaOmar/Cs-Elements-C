#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <math.h>

#define RE 25
#define CO 81

typedef struct coordenada{
 	int x;
 	int y;
} coor;
 
typedef struct BARCO{
 	coor* cd;
 	int tam;
} barco;


barco* F1;//Aquí declaro a las dos flotas de barcos (ie. un vector de estructuras barco) que serán utilizadas a lo largo del juego, la del usuario y la computadora, respectivamente.
barco* F2;

void Reglas();
void Turn();
void mensaje(char []);
void borrM();
void GotoXY(int, int);
void PrintSt(FILE*);
void borrador();
void Start();
void Menu();
void Jugar();
void BattleShip();
char GetCh();
barco* Sailor();
barco* FlotaEnem();
void FreeFlota(barco*);

int main(int argc, char *argv[]) {
    BattleShip();
	return 0;
}

void GotoXY(int x, int y){//La gunción GotoXY sirve para tener acceso a las coordenadas de la pantalla.
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void PrintSt(FILE *f){//Esta función sirve para trasladar un archivo de texto a la consola
	char c;
	while(c!=EOF){
		c=getc(f);
		printf("%c", c);
	}
}

void borrM(){//Cuando se está en la partido "BorrM" sirve para borrar, únicamente los mensajes de la parte superior derecha
	int i=0, j=0;
	for(i; i<10; i++){
		for(j; j<35; j++){
			GotoXY(81+j, 1+i);
			printf(" ");
		}
		j=0;
	}
}

void mensaje(char msj[]){//Con esta función, se mandan mensajes al usuario en  la parte superior derecha, cuando se está en juego.
	borrM();
	int t=strlen(msj);
	if(t<35){
		GotoXY(81, 1);
		printf("%s", msj);
	}else{
		int i=0, j=0;
		while(msj[i]!='\0'){
		  if(i%35==0){
		  	j++;
		  	GotoXY(81, 0+j);
		  }
		  printf("%c", msj[i]);
		  i++;
		}
	}
}

void borrador(){//borrador tiene como única función borrar todo lo que esté en el momento en consola y volver a la coordenada (0, 0), se utiliza un archivo de texto y se transporta con la función PrintSt, el archivo está en la carpeta que se subió, se llama "Borrador.txt"
	GotoXY(0,0);
    char dir[]="C:\\Users\\ACER\\Documents\\1er Semestre Lic. Matemáticas\\Elementos de Ciencias de la Computación\\C Files\\Ejercicios del Curso\\Proyecto Final\\Borrador.txt";
    FILE* fd;
    fd=fopen(dir, "r");
    if(fd==NULL){
    	printf("Error de borrador");
    	exit(1);
	}
    PrintSt(fd);
    fclose(fd);
    GotoXY(0, 0);
}

void Start(){//"Start" Es simplemente una función ornamental que sirve para presentar el logo del juego al inicio, funciona con la función PrintSt y el archivo de texto se subió en la misma corpeta, este se llama "Logo.txt"
	FILE *fd;
	int c;
	char dir[]="C:\\Users\\ACER\\Documents\\1er Semestre Lic. Matemáticas\\Elementos de Ciencias de la Computación\\C Files\\Ejercicios del Curso\\Proyecto Final\\Logo.txt";
	fd=fopen(dir, "r");
	if(fd==NULL){
		printf("Error al encontrar el archivo");
		exit(1);
	}
	PrintSt(fd);
	printf("\n(Presione Enter para iniciar)");
	getchar();
	fclose(fd);
}

void Menu(){//"Menu" Es la función que permite al usuario, antes de iniciar a jugar, poder leer un instructivo de juego o salir si es que éste lo desea y por supuesto la opcón de comenzar a jugar. 
	int g;
	borrador();
	printf("\tMenu de Opciones.\n\tJugar. (1)\n\tLeer Reglas. (2)\n\tSalir. (3)\n\nIndique la opcion que desea: ");
	scanf("%d", &g);
	switch (g){
		case 1: Jugar();
		break;
		case 2: Reglas();
		break;
		case 3: exit(1);
	}
	getchar();
}

void Jugar(){//Ésta es la función base del juego, con ella y la ayuda de "PrintSt" se carga el escenario de juego, que es un archivo de texto y se llama "Stage.txt". Esta función contiene a otras muy importantes descritas más abajo. Además, es de vital importancia notar que se hace siempre el free de las flotas para las cuales pedimos memoria en con la función contenida "FreeFlota". 
	borrador();
	FILE *f;
	char dir[]="C:\\Users\\ACER\\Documents\\1er Semestre Lic. Matemáticas\\Elementos de Ciencias de la Computación\\C Files\\Ejercicios del Curso\\Proyecto Final\\Stage.txt";
	f=fopen(dir, "rt");
	if(f==NULL){
		printf("Error al encontrar el archivo de juego");
		exit(1);
	}
	PrintSt(f);
	fclose(f);	
	F1=Sailor();
	F2=FlotaEnem();
	Turn();
	FreeFlota(F1);
	FreeFlota(F2);
}

CHAR GetCh (VOID)//Esta función es muy importante, ya que con ella se procesan los movimientos y el lanzamiento de bombas en el teclado por parte del usuario, su funcionamiento consiste en leer datos del teclado y no mostrarlos a pantalla.
{
  HANDLE hStdin = GetStdHandle (STD_INPUT_HANDLE);
  INPUT_RECORD irInputRecord;
  DWORD dwEventsRead;
  CHAR cChar;

  while(ReadConsoleInputA (hStdin, &irInputRecord, 1, &dwEventsRead)) /* Read key press */
    if (irInputRecord.EventType == KEY_EVENT
	&&irInputRecord.Event.KeyEvent.wVirtualKeyCode != VK_SHIFT
	&&irInputRecord.Event.KeyEvent.wVirtualKeyCode != VK_MENU
	&&irInputRecord.Event.KeyEvent.wVirtualKeyCode != VK_CONTROL)
    {
      cChar = irInputRecord.Event.KeyEvent.uChar.AsciiChar;
	ReadConsoleInputA (hStdin, &irInputRecord , 1, &dwEventsRead); /* Read key release */
	return cChar;
    }
  return EOF;
}

barco* Sailor(){//Sailor es la función que le permite, al inicio de la  partida, acomodar su flota al usuario. Ésta regresa un vector de objetos barcos (flota) por la izquierda.
	char c;
	int x=20, y=12;
	barco* vecB;
	vecB=(barco*)malloc(5*sizeof(barco));
	if(vecB==NULL){
		printf("No hay barcos disponibles");
		exit(1);
	}
	vecB[0].tam=5;
	vecB[1].tam=4;
	vecB[2].tam=3;
	vecB[3].tam=3;
	vecB[4].tam=2;
	int i=0, j=0, s=0;
	for(i; i<5; i++){
		vecB[i].cd=(coor*)malloc(vecB[i].tam*sizeof(coor));
		if(vecB[i].cd==NULL){
			printf("Error de memoria en coordenada");
			exit(1);
		}
	}
	i=0;
	for(i; i<5; i++){
		if(i==0){
			mensaje("Coloca tu portaaviones de 5 casillas");
		}else if(i==1){
			mensaje("Coloca tu acorazado de 4 casillas");
		}else if(i==2){
			mensaje("Coloca tu buque de 3 casillas");
		}else if(i==3){
			mensaje("Coloca tu otro buque de 3 casillas");
		}else{
			mensaje("Coloca tu lancha de 2 casillas");
		}
		GotoXY(x, y);
	   for(j; j<vecB[i].tam; j++){
	   	  s=0;
	       while(c=GetCh()){
	    	   if(c=='j'||c=='i'||c=='k'||c=='l'){
		           if(c=='j' && x>1){
		    	      x--;
		           }else if(c=='l' && x<39){
			         x++;
		           }else if(c=='i' && y>1){
			         y--;
		           }else{
		   	         if(y<23){
				         y++;
		 	         }
		           }

		          GotoXY(x,y);
		          
	           }else if(c==32){
	           	 if((j==0 || (fabs((vecB[i].cd[j-1].x)-x)==1 && vecB[i].cd[j-1].y==y) || (fabs((vecB[i].cd[j-1].y)-y)==1 && vecB[i].cd[j-1].x==x)) && (x<39)){
			         printf("#");
			         vecB[i].cd[j].x=x;
			         vecB[i].cd[j].y=y;
			         x++;
			         s++;
			       }else{
			       	 mensaje("Tienes que seguir con la estructura de tu barco");
			       	 GotoXY(x, y);
				   }
			   }
			   if(s!=0){
			   	break;
			   }
	       }
	    }
	    j=0;
    } 
    return vecB;
}

barco* FlotaEnem(){//FlotaEnem sirve para que la computadora acomode su flota aleatoriamente. En el código se dejan como comentario un GotoXY y un printf, para que el lector del código verifique en el ejecutable que la flota se acomoda en el escenario correctamente y de manera aleatoria. 
	srand(time(NULL));
	int vh, i=0, j=1, t, u;
	barco* vecB2;
	vecB2=(barco*)malloc(5*sizeof(barco));
	if(vecB2==NULL){
		printf("Error de memoria en la flota enemiga");
		exit(1);
	}
	vecB2[0].tam=5;
	vecB2[1].tam=4;
	vecB2[2].tam=3;
	vecB2[3].tam=3;
	vecB2[4].tam=2;
	for(i; i<5; i++){
		vecB2[i].cd=(coor*)malloc(vecB2[i].tam*sizeof(coor));
		if(vecB2[i].cd==NULL){
			printf("Error de memoria en coordenada (flota enemiga)");
			exit(1);
		}
	}
	i=0;	
	for(i; i<5; i++){
		vh=rand()%2;
		if(vh==1){
			t=41+(rand()%(39-vecB2[i].tam));
			vecB2[i].cd[0].x=t;
			u=1+rand()%23;
			vecB2[i].cd[0].y=u;
			//GotoXY(t, u);
			//printf("#");
			for(j; j<vecB2[i].tam; j++){
				t++;
				vecB2[i].cd[j].x=t;
				vecB2[i].cd[j].y=u;
				//GotoXY(t, u);
				//printf("#");
			}
			j=1;
		}else{
			u=1+rand()%(23-vecB2[i].tam);
			vecB2[i].cd[0].y=u;
			t=41+(rand()%39);
			vecB2[i].cd[0].x=t;
			//GotoXY(t, u);
			//printf("#");
			for(j; j<vecB2[i].tam; j++){
				u++;
				vecB2[i].cd[j].y=u;
				vecB2[i].cd[j].x=t;
				//GotoXY(t, u);
				//printf("#");
			}
			j=1;
		}
	}
	return vecB2;
}

void Turn(){//Turn es la función principal, ya que regula los turnos entre el usuario y la computadora y con la información del juego determina quién es el ganador y el perdedor, a demás de ciertos mensajes importantes durante el juego. Aquí reside la estrategia de la computadora para tirar bombas, que es puramente aleatoria.
	int s=1, x=45, y=12, i=0, j=0, aux=0, con=0;
	char c;
	while(s!=0){
		if(s%2==1){
	     while(c=GetCh()){
	    	   if(c=='j'||c=='i'||c=='k'||c=='l'){
		           if(c=='j' && x>41){
		    	      x--;
		           }else if(c=='l' && x<79){
			         x++;
		           }else if(c=='i' && y>1){
			         y--;
		           }else{
		   	         if(y<23){
				         y++;
		 	         }
		           }

		          GotoXY(x,y);
		          
	           }else if(c==32){
	           	 for(i; i<5; i++){
	           	 	for(j; j<F2[i].tam; j++){
	           	 		if(F2[i].cd[j].x==x && F2[i].cd[j].y==y){
	           	 			GotoXY(x, y);
	           	 			printf("x");
	           	 			mensaje("¡Has dado en el blanco!");
	           	 			getchar();
	           	 			GotoXY(x, y);
	           	 			con++;
	           	 			aux=1;
							}
						}
						j=0;
					}
					if(aux==1){
						aux=0;
						i=0;
						break;
					}else{
						GotoXY(x, y);
						printf("o");
						mensaje("Has fallado");
						getchar();
						GotoXY(x, y);
						i=0;
						break;
					}
			   }else if(c==27){
			   	s=-1;
			   	break;
			   }else{
			   	GotoXY(x,y);
			   }
		}
		s++;
		if(con==17){
			s=0;
			mensaje("¡Has ganado!");
			getchar();
			break;
		}
		
	 }else{
			srand(time(NULL));
			int h, k, con2=0, aux2=0;
			h=1+(rand()%39);
			k=1+(rand()%23);
			for(i; i<5; i++){
				for(j; j<F1[i].tam; j++){
					if(h==F1[i].cd[j].x && k==F1[i].cd[j].y){
						GotoXY(h, k);
						printf("x");
						mensaje("¡Te han dado!");
						con2++;
						aux2=1;
					}
				}
				j=0;
			}
			if(aux2==1){
				aux2=0;
				i=0;
				if(con2==17){
					mensaje("¡Han hundido toda tu flota! Has perdido");
					getchar();
					s=0;
				}
			}else{
				GotoXY(h, k);
				printf("o");
				mensaje("El enemigo ha fallado");	
				i=0;
				GotoXY(x, y);
			}
			s++;
		}
  }
  borrM();
  borrador();
  printf("El juego ha terminado. (Presione Enter)");
  getchar();
}

void Reglas(){//La función "Reglas", ramificada del menú, sólo llama a borrador y a printf para explicar al usuario como jugar Battleship.
	borrador();
	printf("\t¿Como jugar?\n\tI)Para moverse por la pantalla se utilizan las teclas: \"i\" para moverse\n\thacia arriba, \"k\" para moverse hacia abajo, \"j\" para moverse hacia la\n\tizquierda y \"l\" para moverse hacia la derecha.\n\tII)\n\tPara comenzar, el usuario debe acomodar sus barcos, el jugador\n\ttendra 5 barcos; un portaaviones de 5 casillas de largo, un acorazado de\n\t4 casillas de largo, dos buques de 3 casillas de largo cada uno y una lancha\n\tde 2 casillas de largo; que tendra que acomodar en el espacio izquierdo\n\tde la pantalla con las teclas de movimiento del inciso *I) y la tecla space para posicionar\n\tuna parte del barco actual.\n\tIII)\n\tUna vez posicionados los barcos el jugador recorrera el escenario enemigo\n\tcon las mismas teclas de movimiento del inciso *I). Para soltar una bomba en una casilla\n\tel usuario debera presionar \"Enter\" y si es que en la casilla aparece una \"x\" entonces\n\tla bomba ha destruido una de las casillas de un barco enemigo, de lo contrario en la\n\tcasilla aparecera un \"o\" que indica que la bomba no acerto en algun barco enemigo.\n\tEl juego termina cuando una de las dos flotas haya sido totalmente destruida. \n\tIV)\n\tSi el usuario desea salir del juego, presione la tecla \"Esc\".\n(Presione Enter para volver a Menu)");
    getchar();
    getchar();
	borrador();
	Menu();
}

void FreeFlota(barco* vecB1){//La función Freeflota libera la memoria que hemos pedido para nuestros vectores de barcos (flotas), Los cuáles son variables globales, y además libera la memoria que hemos pedido para sus coordenadas.
	int i=0;
	for(i; i<5; i++){
		free(vecB1[i].cd);
	}
	free(vecB1);
}

void BattleShip(){//Esta es la función generalizadora, que sólo contiene a menú y start, esta es la única función a la que se llama en el main.
	Start();
	Menu();
}
