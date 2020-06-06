/***********************************************************************
 * Module:  Matriz.h
 * Author:  Kevin Caicedo, Madely Betancourt
 * Modified: martes, junio 02, 2020 8:09:21 AM
 * Purpose: Declaration of the class Matriz
 ***********************************************************************/
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

class Matriz
{
public:
	int getDimension(void);
	void setDimension(int nuevaDimension);
	int** getMatriz(void);
	void setMatriz(int** nuevaMatriz);
	void encerar(int** mat, int dimension);
	void igualar(int** mat1, int** mat2, int dimension);
	int** instanciar(int dimension);
	void imprimir(Matriz mat1);
	void ingresar(Matriz mat);
	Matriz(int** matriz, int dimension);
	Matriz();
	void elevar(Matriz mat1, Matriz mat2, int exponente);

protected:
private:
	int** matriz;
	int dimension;


};
//Obten dimension
int Matriz::getDimension(void)
{
	return dimension;
}
//Cambia dimension
void Matriz::setDimension(int newDimension)
{
	dimension = newDimension;
}
//Obtener matriz 
int** Matriz::getMatriz(void)
{
	return matriz;
}
//Cambiar matriz
void Matriz::setMatriz(int** newMatriz)
{
	matriz = newMatriz;
}
// LLenar matriz
void Matriz::encerar(int** mat, int dimension)
{
	int i, j;
	for (i = 0; i < dimension; i++)
		for (j = 0; j < dimension; j++)
			*(*(mat + i) + j) = 0;
	return;
}
//Iguala matriz
void Matriz::igualar(int** mat1, int** mat2, int dimension)
{
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++)
		{
			*(*(mat1 + i) + j) = *(*(mat2 + i) + j);
		}

	}
}
// Instanciar matriz
int** Matriz::instanciar(int dimension)
{
	int** m, j;
	m = (int**)malloc(dimension * sizeof(int*));
	for (j = 0; j < dimension; j++)
		*(m + j) = (int*)malloc(dimension * sizeof(int));
	return m;
}
//Imprimir la matriz
void Matriz::imprimir(Matriz mat1)
{
	for (int i = 0; i < mat1.dimension; i++) {
		for (int j = 0; j < mat1.dimension; j++)
		{
			printf("%d", *(*(mat1.matriz + i) + j));
			printf("%*s", j + 5, "");
		}
		printf("\n");
	}
}
//Ingrese los datos de la matriz 
void Matriz::ingresar(Matriz mat)
{
	for (int i = 0; i < mat.dimension; i++)
		for (int j = 0; j < mat.dimension; j++)
			scanf_s("%d", &(*(*(mat.matriz + i) + j)));
}

//Constructor
inline Matriz::Matriz(int** _matriz, int _dimension)
{
	_matriz = instanciar(_dimension);
	Matriz::matriz = _matriz;
	Matriz::dimension = _dimension;

}
//Constructor
inline Matriz::Matriz()
{
}
//Funcion para elevar la matriz 
void Matriz::elevar(Matriz mat, Matriz matr, int exponente)
{

	int** mat2;
	mat2 = instanciar(mat.dimension);
	encerar(mat2, mat.dimension);
	igualar(mat2, mat.matriz, mat.dimension);

	for (int l = 0; l < exponente - 1; l++)
	{
		encerar(matr.matriz, mat.dimension);
		for (int i = 0; i < mat.dimension; i++) {
			for (int j = 0; j < mat.dimension; j++) {
				for (int h = 0; h < mat.dimension; h++) {
					*(*(matr.matriz + i) + j) = *(*(matr.matriz + i) + j) + (*(*(mat.matriz + i) + h)) * (*(*(mat2 + h) + j));
				}
			}
		}encerar(mat2, mat.dimension);
		igualar(mat2, matr.matriz, mat.dimension);

	}
}

