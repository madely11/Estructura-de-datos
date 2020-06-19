#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
#include <conio.h>
#include <ctype.h>  
#include "Ordenamiento.h"

using namespace std;

bool verificarPalabra(char* palabra) {
	int aux2 = 0;
	//verifica si todas son letras
	for (int i = 0; i < strlen(palabra); i++)
	{
		if (isalpha(*(palabra + i)))
			aux2++;
	}
	if (aux2 == strlen(palabra))
		return false;
	else
		return true;
}

bool verificarNum(char* palabra) {
	int aux = 0;
	//verifica si todos son numeros
	for (int i = 0; i < strlen(palabra); i++)
	{
		if (isdigit(*(palabra + i)))
			aux++;
	}
	if (aux == strlen(palabra))
		return false;
	else
		return true;
}

bool verificarMixto(char* palabra) {
	int aux3 = 0;
	for (int i = 0; i < strlen(palabra); i++)
	{
		//entra si tiene un numero
		if (isalpha(*(palabra + i)) == 0) {
			aux3++;
		}
	}
	if (aux3 > 0)
		return true;
	else
		return false;
}

bool verificar(char* palabra) {
	int aux3 = 0;
	int aux2 = 0;
	int aux = 0;

	for (int i = 0; i < strlen(palabra); i++)
	{
		if (isalpha(*(palabra + i)) == 0) {
			aux3++;
		}
	}
	
	//verifica si todos son numeros
	for (int i = 0; i < strlen(palabra); i++)
	{
		if (isdigit(*(palabra + i)))
			aux++;
	}
	
	//verifica si todas son letras
	for (int i = 0; i < strlen(palabra); i++)
	{
		if (isalpha(*(palabra + i)))
			aux2++;
	}
	if (aux2 == strlen(palabra))
		return false;

	if (aux == strlen(palabra))
		return false;

	if (aux3 > 0)
		return true;
}

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
		if (i == 0) {
			cout << "Ingrese el nombre " << i + 1 << endl;
			cin >> *(arreglo + i);

			while (verificar(*(arreglo + i))){
				cout << "Dato incorrecto, reingrese: " << endl;
				cin >> *(arreglo + i);
			}
		}
		else {
			cout << "Ingrese el nombre " << i + 1 << endl;
			cin >> *(arreglo + i);

			while (verificar(*(arreglo + i))) {
				cout << "Dato incorrecto, reingrese: " << endl;
				cin >> *(arreglo + i);
			}

			if (isalpha(*(*(arreglo + 0) + 0)) && isalpha(*(*(arreglo + i) + 0))){
				while (verificarPalabra(*(arreglo + i)) && verificarMixto(*(arreglo + i))) {
					cout << "Dato incorrecto, reingrese: " << endl;
					cin >> *(arreglo + i);
				}
			}

			if (isdigit(*(*(arreglo + 0) + 0)) && isdigit(*(*(arreglo + i) + 0))){
				while (verificarNum(*(arreglo + i)) && verificarMixto(*(arreglo + i))) {
					cout << "Dato incorrecto, reingrese: " << endl;
					cin >> *(arreglo + i);
				}
			}

			if (isalpha(*(*(arreglo + 0) + 0)) && isdigit(*(*(arreglo + i) + 0))) {
				while (verificarPalabra(*(arreglo + i)) && verificarMixto(*(arreglo + i))) {
					cout << "Dato incorrecto, reingrese: " << endl;
					cin >> *(arreglo + i);
				}
			}
			if (isdigit(*(*(arreglo + 0) + 0)) && isalpha(*(*(arreglo + i) + 0))) {
				while (verificarNum(*(arreglo + i))) {
					cout << "Dato incorrecto, reingrese: " << endl;
					cin >> *(arreglo + i);
				}
			}
		}
	}


	try {
		//isdigit retorna true cuando es un caracter numero
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

