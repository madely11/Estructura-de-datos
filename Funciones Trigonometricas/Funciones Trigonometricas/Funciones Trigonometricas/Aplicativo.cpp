/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* PROGRAMA PARA CALCULAR EL MCM Y MCD DE UN ARREGLO DINÁMICO      *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 01/06/20									  *
* FECHA DE MODIFICACIÓN: 03/06/20								  *
******************************************************************/


#include <iostream>
#include <sstream>
#include "Funciones.h"
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "Ingreso.h"
using namespace std;

int main()
{
	Ingreso ingreso;
	string dim;
	Funciones funcion;
	float temporal=0;

	dim = ingreso.leer("Ingrese el angulo en grados: ", 1);
	istringstream(dim) >> temporal;
	temporal = (float)temporal;
	printf("\nEl seno es: %f ", funcion.miSeno(temporal));
	printf("\nEl coseno es: %f\n", funcion.miCoseno(temporal));
	if(funcion.miTangente(temporal) != 0)
		printf("\nLa tangente es: %f\n", funcion.miTangente(temporal));
	system("pause");
	return 0;
}

