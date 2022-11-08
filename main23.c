#include <stdio.h>
#include <stdlib.h>

typedef struct matrix{
	int nrens;
	int ncols;
	float** ptr;
} matrix;

typedef struct vector{
	int dim;
	float* pt;
} vector;

matrix CreateMatrix(int, int);
vector CreateVector(int);
void FreeMatrix(matrix);
void FreeVector(vector);
matrix ReadMatrix(FILE *);
void PrintMatrix(matrix);
vector ReadVector(FILE*);
void PrintVector(vector);
vector GaussJordan(matrix, vector);
void STR(matrix, vector);

int main() {
	/*FILE *fv, *fm;
	char dirv[]="C:\\Users\\ACER\\Documents\\Proof\\VecR.txt";
	char dirm[]="C:\\Users\\ACER\\Documents\\Proof\\AM.txt";
	fv=fopen(dirv, "r");
	fm=fopen(dirm, "r");
	matrix C;
	C=ReadMatrix(fm);
	PrintMatrix(C);
	vector B;
	B=ReadVector(fv);
	PrintVector(B);
	vector SOL;
	SOL=GaussJordan(C, B);
	PrintMatrix(C);
	PrintVector(B);
	PrintVector(SOL);
	FreeVector(SOL);
	fclose(fv);
	fclose(fm);
	FreeVector(B);
	FreeMatrix(C);*/

	/*matrix Mt;
	Mt=CreateMatrix(4, 3);
	PrintMatrix(Mt);
	FreeMatrix(Mt);*/
	
	int a, b;
    int* arr;
    arr=(int*)malloc(sizeof(int));
    int i=0;
	for(i; i<100; i++){
        arr[i]=rand();
    }
    printf("%d", arr[2]);
    free(arr);
    printf("%d", arr[2]);
	return 0;
}

matrix CreateMatrix(int m, int n){
	matrix M;
	M.nrens=m;
	M.ncols=n;
	int i=1;
	M.ptr=(float**)malloc(m*sizeof(float*));
	if(M.ptr==NULL){
		printf("Error de memoria 1");
		exit(1);
	}
	M.ptr[0]=(float*)malloc(m*n*sizeof(float));
	if(M.ptr[0]==NULL){
		printf("Error de memoria 2");
		exit(1);
	}
	for(i; i<m; i++){
		M.ptr[i]=M.ptr[0]+(n*i);
	}
	return M;
}

vector CreateVector(int n){
	vector r;
	r.dim=n;
	r.pt=(float*)malloc(n*sizeof(float));
	return r;
}

void FreeMatrix(matrix M){
	free(M.ptr[0]);
	free(M.ptr);
}

void FreeVector(vector v){
	free(v.pt);
}

void PrintMatrix(matrix M){
	int i=0, j=0;
	int m=M.nrens;
	int n=M.ncols;
	for(i; i<m; i++){
		for(j; j<n; j++){
			if(j==0){
				printf("|\t");
			}
			printf("%f\t", M.ptr[i][j]);
			if(j==n-1){
				printf("|\n");
			}
		}
		j=0;
	}
	printf("\n");
}

matrix ReadMatrix(FILE *f){
	int m, n, i=0, j=0;
	fscanf(f, "%d", &m);
	fscanf(f, "%d", &n);
	matrix M;
	M=CreateMatrix(m, n);
	for(i; i<m; i++){
		for(j; j<n; j++){
			fscanf(f, "%f\t", &M.ptr[i][j]);
		}
		j=0;
	}
	return M;
}

vector ReadVector(FILE *f){
	int n, i=0;
	vector v;
	fscanf(f, "%d", &n);
	v=CreateVector(n);
	for(i; i<n; i++){
		fscanf(f, "%f", &v.pt[i]);
	}
	return v;
}

void PrintVector(vector v){
	int n, i=0;
	n=v.dim;
	for(i; i<n; i++){
		printf("|\t%f\t|\n", v.pt[i]);
	}
	printf("\n");
}

vector GaussJordan(matrix A, vector S){
	int i=0, j=0, c=0, k=1;
	float p;
	vector R;
	R=CreateVector(A.nrens);
	for(i; i<A.nrens; i++){
	    if(A.ptr[i][i]==0.0000){
	    	c++;
		}
	}
	i=0;
	if(A.nrens!=S.dim||A.ncols!=S.dim){
	 printf("Error con las dimensiones de la matriz");
	 exit(1);
	}else if(c!=0){
		printf("Error, existen %c elementos de la diagonal que son cero", c);
		exit(1);
	}else{
        STR(A, S);
		i=1, j=1;
		float z=0;		
		for(i; i<=A.nrens; i++){
			R.pt[A.ncols-i]=(S.pt[S.dim-i]-z)/A.ptr[A.nrens-i][A.ncols-i];
		    if(i==A.nrens){
		    	break;
			}
			for(j; j<=i; j++){
				z+=(A.ptr[A.nrens-i-1][A.ncols-j]*R.pt[R.dim-j]);
			}
			j=1;
		}
	}
	return R;
}

void STR(matrix A, vector S){
	int i=0, j=0, k=1;
	float p;
	for(i; i<A.nrens-1; i++){
			for(k; k<A.nrens-i; k++){
				p=(A.ptr[i+k][i])/(A.ptr[i][i]);
				for(j; j<A.ncols; j++){
					A.ptr[i+k][j]-=(p*A.ptr[i][j]);
				}
				j=0;
				S.pt[i+k]-=p*(S.pt[i]);
			}
			k=1;
		}
}
