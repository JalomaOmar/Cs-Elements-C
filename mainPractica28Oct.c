#include <stdio.h>
#include <stdlib.h>

typedef struct Complex{
	float r;
	float i;
} complex;

typedef struct ComplexMatrix{
	int nrens;
	int ncols;
	complex** ptc;
} CM;

CM CreateCM(int, int);
void FreeCM(CM);
CM transpuestaconjugada(CM);

int main() {
	CM A;
	A=CreateCM(2, 3);
	A.ptc[1][2].i=3;
	A.ptc[1][2].r=1;
	CM B;
	B=transpuestaconjugada(A);
	printf("%f +", B.ptc[2][1].r);
	printf("%fi", B.ptc[2][1].i);
	FreeCM(A);
	FreeCM(B);
	return 0;
}

CM CreateCM(int m, int n){
	CM r; 
	r.nrens=m;
	r.ncols=n;
	int i=0;
	r.ptc=(complex**)malloc(m*sizeof(complex*));
	for(i; i<m; i++){
		r.ptc[i]=(complex*)malloc(n*sizeof(complex));
	}
	return r;
}

void FreeCM(CM M){
	int i=0;
	for(i; i<M.nrens; i++){
		free(M.ptc[i]);
	}
	free(M.ptc);
}

CM transpuestaconjugada(CM M){
	CM r;
	r=CreateCM(M.ncols, M.nrens);
	int i=0, j=0;
	for(i; i<M.nrens; i++){
		for(j; j<M.ncols; j++){
			r.ptc[j][i]=M.ptc[i][j];
		}
		j=0;
	}
	i=0;
	
	for(i; i<M.ncols; i++){
		for(j; j<M.nrens; j++){
			r.ptc[i][j].i=(r.ptc[i][j].i)*-1;
		}
		j=0;
	}
	return r;
}
