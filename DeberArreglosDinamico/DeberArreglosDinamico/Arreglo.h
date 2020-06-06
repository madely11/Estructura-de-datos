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

#if !defined(__UML_Class_Diagram_3_Arreglo_h)
#define __UML_Class_Diagram_3_Arreglo_h

#include<iostream>
using namespace std;

class Arreglo
{
public:
	int* getArreglo(void);
	void setArreglo(int* newArreglo);
	int getLongitud(void);
	void setLongitud(int newLongitud);
	void encerar();
	void ingresar(int valor);
	void imprimir();
	Arreglo();

protected:
private:
	int* arreglo;
	int longitud;

};


/**
	@brief Funcion get del Arreglo
	@param void
	@returns arreglo
*/

int* Arreglo::getArreglo(void)
{
	return arreglo;
}

/**
	@brief Funcion ser de arreglo
	@param entero puntero arreglo
	@returns arreglo que contiene el nuevo arreglo
*/

void Arreglo::setArreglo(int* newArreglo)
{
	arreglo = newArreglo;
}

/**
	@brief Funcion encerar
*/

void Arreglo::encerar()
{
	for (int i = 0; i < longitud; i++)
	{
		*(arreglo + i) = 0;
	}
	
}

/**
	@brief Funcion ingresar
	@param valor que representa la cantidad de memoria sseparada para el arreglo
*/

void Arreglo::ingresar(int valor)
{
	longitud++;
	arreglo = (int*)realloc(arreglo, longitud * sizeof(int));
	*(arreglo + (longitud-1)) = valor;
}

/**
	@brief Funcion imprimir
*/

void Arreglo::imprimir()
{
	for (int i = 0; i < longitud; i++)
	{
		cout << *(arreglo + i) << " ";
	}
	cout << endl;
}


/**
	@brief Funcion get de longitud
	@returns longitud
*/

int Arreglo::getLongitud(void)
{
	return longitud;
}

/**
	@brief Funcion ser para longitud
	@param entero longitud
*/

void Arreglo::setLongitud(int newLongitud)
{
	longitud = newLongitud;
}

/**
	@brief Funcion constrcutor de arreglo
*/

Arreglo::Arreglo()
{
	longitud = 0;
	arreglo = (int*) malloc(longitud * sizeof(int));
}

#endif
