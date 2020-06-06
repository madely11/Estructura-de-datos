/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* PROGRAMA PARA CALCULAR LA POTENCIA DE UNA MATRIZ NXN            *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 01/06/20									  *
* FECHA DE MODIFICACIÓN: 03/06/20								  *
******************************************************************/

#include <iostream>
#include "Matriz.h"

int main()
{
	int dimension, exponente;
	int** matriz, ** matriz2;
	Matriz mat1, matr;
	matriz = 0;
	matriz2 = 0;
	printf("\nIngrese la dimension de la matriz: ");
	scanf_s("%d", &dimension);
	printf("\nIngrese el exponente de la matriz:");
	scanf_s("%d", &exponente);
	mat1 = Matriz::Matriz(matriz, dimension);
	matr = Matriz::Matriz(matriz2, dimension);
	printf("\nIngrese los numeros de la matriz:");
	mat1.ingresar(mat1);
	mat1.imprimir(mat1);
	printf("\n");
	printf("\n");
	mat1.elevar(mat1, matr, exponente);
	matr.imprimir(matr);
	system("pause");
	return 0;
}
