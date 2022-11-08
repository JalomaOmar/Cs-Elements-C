#include <stdio.h>
#include <stdlib.h>

int mystrcmp(char [], char []);
int loncad(char []);

int main() {
	char a[]="Soy Pancha";
	char b[]="Soy Panch";
	if (mystrcmp(a,b)==0){
		printf ("Las cadenas son iguales");
	} else {
		printf("Las cadenas son diferentes");
	}
	printf ("%d", mystrcmp(a,b));
	return 0;
}

int mystrcmp(char cad1[], char cad2[]){
	int j=0;
	int d;
	if((loncad(cad1) < loncad(cad2))||( loncad(cad1) > loncad(cad2))){
		return -1;
	}else {
		int s=0;
		for(j;j<loncad(cad1); j++){
			d=( ((int)cad1[j])-((int)cad2[j]));
			s=s+d;
		}
		 return s;
	}
	
}

int loncad(char vec[]){
	int i=0;
	for (i;i>=0;i++){
		if (vec[i]==0){
			return i;
		}
	}
}
