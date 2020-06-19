#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
#include <conio.h>
#include <ctype.h>  
#include "Ordenamiento.h"

using namespace std;

int main() {
	char** arreglo = NULL;
	Ordenamiento<char,char> ordenar;
	arreglo = (char**)malloc(longitud * sizeof(char*));
	
	if (!arreglo) {
		cout << "No hay espacio" << endl;
		exit(1);
	}

	//Definir dimension de palabras
	for (int j = 0; j < longitud; j++)
		*(arreglo + j) = (char*)malloc(longitud2 * sizeof(char*));


	//ingresar
	for (int i = 0; i < longitud; i++)
	{
		cout << "Ingrese el nombre " << i + 1 << endl;
		cin >> *(arreglo + i);
	}


	try {
		//comprueba si la primera posicion de la matriz es un caracter numerico
		if (isdigit(*(*(arreglo + 0) + 0)) == 0) 
			throw 1;

		else {
			int i = 1;
			int j = 0;
			char* aux = NULL;
			ordenar.ordenarNum(i, j, aux, arreglo);
		}
	}

	catch (int e) {
		int i = 1;
		int j = 0;
		char* aux = NULL;
		ordenar.ordenar(i, j, aux, arreglo);
	}


	//imprimir
	for (int i = 0; i < longitud; i++)
	{
		if (i != longitud - 1)
			cout << *(arreglo + i) << ", ";
		else
			cout << *(arreglo + i) << endl;
	}


	free (arreglo);
	return 0;
}

