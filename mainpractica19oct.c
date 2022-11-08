#include <stdio.h>
#include <stdlib.h>
#define TM 3

int main() {
	int *A, *B, *C;
	int i=0;
	srand(time(NULL));
	A=(int*)malloc(TM*sizeof(int));
	B=(int*)malloc(TM*sizeof(int));
	C=(int*)malloc(TM*sizeof(int));
	for (i; i<TM; i++){
		*(A+i)=rand();
		*(B+i)=rand();
		*(C+i)=*(A+i)+*(B+i);
	}
	free(A);
	free(B);
	free(C);
	return 0;
}
