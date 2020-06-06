/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* PROGRAMA PARA CALCULAR EL MCM Y MCD DE UN ARREGLO DINÁMICO      *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 01/06/20									  *
* FECHA DE MODIFICACIÓN: 06/06/20								  *
******************************************************************/

/**
	@file Operaciones.h
	@brief Libreria que contiene las funciones para calcular MCM y MCD 
	@author Madely Betancourt y Kevin Caicedo
	@date 6/2020
*/

#if !defined(__UML_Class_Diagram_3_Operaciones_h)
#define __UML_Class_Diagram_3_Operaciones_h

class Operaciones
{
public:
	int calcularMCM(int* arreglo, int longitud);
	int calcularMCD(int* arreglo, int longitud);
	int MCD(int a, int b);

protected:
private:

};

/**
	@brief Funcion calcular MCM de un arreglo
	@param arreglo guarda numeros de un arreglo ingresado, longitud dato que guarda la longitud del arreglo
	@returns a que representa el valor dell MCM
*/
int Operaciones::calcularMCM(int* arreglo, int longitud)
{
	int a, b, mcd;
	a = *(arreglo);
	b = *(arreglo + 1);

	mcd= MCD(a, b);
	a = (a * b) / mcd;

	for (int i = 2; i < longitud; i++)
	{
		b = *(arreglo + i);;
		mcd = MCD(a, b);
		a = (a * b) / mcd;
	}
	
	return a;
}

/**
	@brief Funcion calcular MCD de un arreglo
	@param arreglo guarda numeros de un arreglo ingresado, longitud dato que guarda la longitud del arreglo
	@returns a que representa el valor dell MCD
*/

int Operaciones::calcularMCD(int* arreglo, int longitud)
{
	int a, b;
	a = *(arreglo);
	b = *(arreglo + 1);

	a = MCD(a, b);


	for (int i = 2; i < longitud; i++)
	{
		b = *(arreglo + i);
		a = MCD(a, b);
	}
	return a;
}

/**
	@brief Funcion calcular MCM entre dos numeros
	@param entero a que representa el primer numero, entero b que es el segundo numero, estos 
	numeros son tomaods del arreglo.
	@returns a que representa el valor dell MCD entre estos dos numeros
*/

int Operaciones::MCD(int a, int b)
{
	int residuo = 1;
	int cociente;

	while (residuo != 0) {
		cociente = a / b;
		residuo = a % b;
		a = b;
		b = residuo;
	}
	return a;
}
#endif
