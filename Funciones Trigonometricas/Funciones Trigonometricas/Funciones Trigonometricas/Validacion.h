/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* LIBRERIA PARA VALIDAR UN VALOR NUMERICO INGRESADO               *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACI�N: 06/06/20									  *
* FECHA DE MODIFICACI�N: 07/06/20								  *
******************************************************************/


#include <iostream>
#include <ctype.h>
#include <string.h>

using namespace std;

class Validacion {
public:
	bool validar(string, int);
};



////////////////////////////////////////////////////////////////////////
/** Name:       Validacion::validar(string entrada, int tipo)*/
/** Purpose:    Definir como entero (1), flotante (2)*/
/** Parameters:*/
/** + entrada*/
/** = tipo*/
/** Return:     bool*/
////////////////////////////////////////////////////////////////////////

bool Validacion::validar(string entrada, int tipo) {
	int contador = 0;

	try {
		for (int i = 0; i < entrada.length(); i++) {
			if (isalpha(entrada[i])) {
				throw 1;
			}
			if (!isdigit(entrada[i]) && tipo == 1) {
				throw 1;
			}
			if (entrada[i] == '.') {
				contador++;
			}
			if ((isdigit(entrada[i]) == 0 && entrada[i] != '.' && entrada[i] != '-') || (contador > 1)) {
				throw 1;
			}
		}
	}
	catch (int e) {
		return true;
	}
	return false;
}



