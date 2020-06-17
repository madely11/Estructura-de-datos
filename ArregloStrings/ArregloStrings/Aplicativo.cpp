#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>  
#define longitud 10
#define longitud2 15
using namespace std;

//ordena strings de numeros
void ordenarNum(int i, int j, char* aux, char** arreglo) {
	if (i < longitud) {
		/* indice j es para explorar la sublista a[i-1]..a[0] buscando la posicion correcta del elemento destino */
		j = i;
		aux = *(arreglo + i);
		// se localiza el punto de inserción explorando hacia abajo
		while (j > 0 && atoll(aux) < atoll(*(arreglo + (j - 1))))
		{
			// desplazar elementos hacia arriba para hacer espacio
			*(arreglo + j) = *(arreglo + (j - 1));
			j--;
		}
		*(arreglo + j) = aux;
		i++;
		ordenarNum(i, j, aux, arreglo);
	}
}

//ordena string de palabras
void ordenar(int i, int j, char *aux, char **arreglo) {
	if (i < longitud) {
		/* indice j es para explorar la sublista a[i-1]..a[0] buscando la posicion correcta del elemento destino */
		j = i;
		aux = *(arreglo + i);
		// se localiza el punto de inserción explorando hacia abajo
		while (j > 0 && strcmp(aux, *(arreglo + (j - 1))) < 0)
		{
			// desplazar elementos hacia arriba para hacer espacio
			*(arreglo + j) = *(arreglo + (j - 1));
			j--;
		}
		*(arreglo + j) = aux;
		i++;
		ordenar(i, j, aux, arreglo);
	}
}

int main() {
	char** arreglo = NULL;
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
		cout << "Ingrese el valor " << i + 1 << endl;
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
			ordenarNum(i, j, aux, arreglo);
		}
	}

	catch (int e) {
		int i = 1;
		int j = 0;
		char* aux = NULL;
		ordenar(i, j, aux, arreglo);
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

