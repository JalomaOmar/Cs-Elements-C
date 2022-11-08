#include <stdio.h>
#include <stdlib.h>

#define TM 1000

int main() {
	int i=0, m, r;
	int a1[TM];
	for (i;i<=TM; i++){
		m=rand()%TM;
		a1[i]=m;
	}
	scanf ("%d", &r);
	printf ("%d", a1[r]);
	return 0;
}
