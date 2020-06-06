/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* LIBRERIA PARA INGRESAR UN VALOR                                 *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 01/06/20									  *
* FECHA DE MODIFICACIÓN: 03/06/20								  *
******************************************************************/

#include <iostream>
#include "Validacion.h"

using namespace std;

class Ingreso {

public:
	string leer(string, int);
};

////////////////////////////////////////////////////////////////////////
/** Name:       Ingreso::leer(string mensage, int tipo) */
/** Purpose:    Funcion para leer valor y enviarlo a validar*/
/** Parameters:*/
/** + mensage*/
/** + tipo*/
/** Return:     string*/
////////////////////////////////////////////////////////////////////////

string Ingreso::leer(string mensage, int tipo) {
	Validacion validacion;
	string entrada;
	cout << mensage << endl;
	cin >> entrada;
	while (validacion.validar(entrada, tipo)) {
		cout << "Valor no valido reingrese" << endl;
		cin >> entrada;
	}
	return entrada;
}

