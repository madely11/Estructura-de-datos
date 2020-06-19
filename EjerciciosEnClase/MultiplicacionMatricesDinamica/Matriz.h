#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

class Matriz{
public:
void ingreso(int **mat, int t);
void imprime(int **mat, int t);
void proceso(int **mat1, int **mat2,int **matr, int t);	
void encerar(int ** m,int d);

int **nmatriz(int d);
};



//FUNCION PARA INGRESAR LOS DATOS DE LA MATRIZ
void Matriz::ingreso(int **mat, int t)
{
	for(int i=0;i<t;i++)
		for(int j=0;j<t;j++)
			scanf("%d",&(*(*(mat+i)+j)));
}

//FUNCION PARA CALCULAR MULTIPLICACION DE MATRICES
void Matriz::proceso(int **mat1, int **mat2,int **matr, int t)
{
	for(int i=0;i<t;i++){
		for(int j=0;j<t;j++){
			for(int h=0;h<t;h++){
				*(*(matr+i)+j)=*(*(matr+i)+j)+(*(*(mat1+i)+h))*(*(*(mat2+h)+j));
			}

		}
	}
}

//FUNCION IMPRESION DATOS DE LA MATRIZ
void Matriz::imprime(int **mat, int t)
{
	for(int i=0;i<t;i++){
		for(int j=0;j<t;j++)
		{
			printf("%d",*(*(mat+i)+j));
			printf("%*s",j+5,"");
		}
	printf("\n");
	}
}

int** Matriz::nmatriz(int d)
{
    int **m , j;
    m =(int **)malloc(d*sizeof(int *));
    for(j=0;j<d;j++)
        *(m+j)=(int *)malloc(d*sizeof(int));
    return m;
}

void Matriz::encerar(int ** m,int d)
{
    int i, j;
    for(i=0;i<d;i++)
        for(j=0;j<d;j++)
            *(*(m+i)+j)=0;
    
}



