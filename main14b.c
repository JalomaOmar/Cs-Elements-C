#include <stdio.h>
#include <stdlib.h>

int loncad (char []);
void quit (char []);
int main() {
	char a[]="adan no catara banana barata con nada";
	pal(a);
	getchar();
	return 0;
}
int pal(char cad[]){
	quit(cad);
	int j=0, r=0;
	int l=loncad(cad);
	for(j; j<(l/2); j++){
		if (cad[j]==cad[l-1-j]){
			r=r+1;
		}
	}
	if(r==(l/2)){
		printf("Es palindromo \n");
	}else{
		printf("No es palindromo \n");
	}
}

void quit (char vec[]){
	int i=0, l, k=0;
	l=loncad(vec);
	for (i; i<l; i++){
		if ((vec[i]==32)||(vec[i]==44)){
			for(k; k<(l-i); k++){
				vec[i+k]=vec[k+i+1];
			}
			i--;
			k=0;
		}
	}
}

int loncad (char cad[]){
	int j=0;
	for (j; j>=0; j++){
		if (cad[j]==0){
			break;
		}
	}
	return j;
	
}
