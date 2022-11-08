#include <stdio.h>
#include <stdlib.h>

#define M 3
#define N 3
 
void llenaleatoriosmatriz(float [] [N], int, int);
void lahacetranspuesta(float [][N], int, int);

int main() {
	float matrix[M][N];
	llenaleatoriosmatriz(matrix, M, N);
	lahacetranspuesta (matrix, M, N);
	getchar();
	return 0;
}

void llenaleatoriosmatriz(float mat[][N], int Rens, int Cols){
		int j=0, k=0;
	for (j; j<Rens; j++){
		for(k; k<Cols; k++){
			mat[j][k]=((float)rand())/100.0;
		}
		k=0;
	}
}

void lahacetranspuesta(float matr[][N], int Rens, int Cols){
	int i=0, j;
	float temp;
	for(i; i<Rens; i++){
		j=i;
		 for (j; j<Cols; j++){
		 	 temp= matr[i][j];
			 matr[i][j]= matr[j][i];
			 matr[j][i]=temp;
		 }
	}
	
}
