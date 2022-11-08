#include <stdio.h>
#include <stdlib.h>

#define TM 10


int ndb(int []);

int main() {
	int m, p;
	int a[TM];
    int i=0;
	for (i; i<TM; i++){
		m= rand();
		a[i]=m;
	}
	p=ndb(a);
	printf ("%d", p);
	return 0;
}

int ndb(int vec[]){
	int j=1,k=0, p, temp;
	for (k; k<=TM; k++){
	   for (j; j<TM; j++){
		if (vec[j]>vec[j-1]){
			temp=vec[j-1];
			vec[j-1]=vec[j];
			vec[j]=temp;
		    }
	    }
	    j=1;
    }
	p=vec[TM-2];
	return p;
}
