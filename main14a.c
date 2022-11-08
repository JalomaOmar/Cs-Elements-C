#include <stdio.h>
#include <stdlib.h>

void quit(char []);
int loncad(char []);

int main() {
	char a[]="anita lava la tina, con jabon";
    quit(a);
	return 0;
}

int loncad (char vec[]){
	int i=0;
	for (i; i>=0; i++){
		if (vec[i]==0){
			break;
		}
	}
	return i;
}

void quit (char cad[]){
	int l=loncad(cad);
	int j=0;
	for(j; j<l; j++){
		if ((cad[j]==32)||(cad[j]==44)){
			int k=0;
			for (k; k<(l-j); k++){
				cad[j+k]=cad[j+k+1];
			}
			j--;
		}
	}
	
}
