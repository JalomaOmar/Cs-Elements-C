#include <stdio.h>
#include <stdlib.h>

#define TM 10000 //Tamaño de la primera cadena//
#define TM2 10000 //Tamaño de la segunda cadena//
int buscap(char [], char[]);

int main() {
	char word [TM], sentence [TM2];
	int m, i=0;
	printf ("Escriba la palabra que quiere buscar: \n");
	for (i; i>=0; i++){
		scanf ("%c", &word[i]);
		if ((int)word[i]==10){
			i=0;
			break;
		}
	}
	printf ("\n Escriba el texto en el que quiera buscar la palabra: \n");
	for (i; i>=0; i++){
		scanf("%c", &sentence[i]);
		if ((int)sentence[i]==10){
			break;
		}
	}
	m=buscap(word, sentence);
	printf ("%d", m);
	return 0;
}

int buscap(char pal[],char fras[]){
	int lp, lf, i=0;
	char p, f;
	lp=loncad(pal);
	lf=loncad(fras);
	if (lp>lf){
		printf ("La palabra es mas grande que el texto \n");
		return 0;
	} else{
		for (i; i<lf; i++){
			if (fras[i]==pal[0]){
				int j=1, k=1;
				for (j;j<=lp;j++){
					if (pal[j]==fras[i+j]){
						k=k+1;
					}
				}
				if (k==lp){
						return 1;
					}
			}
		}
		return 0;
	}
}

int loncad (char cad[]){
	int i=0;
	char r;
	for (i; i>=0; i++){
		r=cad[i];
		if (r==10){
			return i;
		}
	}
}
