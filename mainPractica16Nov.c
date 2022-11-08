#include <stdio.h>
#include <stdlib.h>

int Fibonacci (unsigned int n);

int main(int argc, char *argv[]) {
	printf("%d\n", Fibonacci(9));
	return 0;
}

int Fibonacci(unsigned int n){
	if(n>20){
		("El número es demasiado grande");
		exit(1);
	}
	if(n==0){
		return 0;
	}
	if(n==1){
		return 1;
	}
	return Fibonacci(n-1)+Fibonacci(n-2);
}
