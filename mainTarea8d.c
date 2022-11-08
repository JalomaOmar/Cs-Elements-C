#include <stdio.h>
#include <stdlib.h>

#define FININT 15
#define ININT 5
#define TM 1000
int main() {
	int a[TM];
	int i=0, m, r;
	for (i; i<=TM; i++){
		m=(rand ()%((FININT-ININT)+1) )+ 5;
		a[i]=m;		
	}
	scanf ("%d", &r);
	printf ("%d", a[r]);
	return 0;
}
