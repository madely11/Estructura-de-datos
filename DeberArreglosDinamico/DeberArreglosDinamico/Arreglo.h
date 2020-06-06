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


////////////////////////////////////////////////////////////////////////
/** Name:       Arreglo::getArreglo()*/
/** Purpose:    Getter de arreglo*/
/** Return:     int**/
////////////////////////////////////////////////////////////////////////

int* Arreglo::getArreglo(void)
{
	return arreglo;
}

////////////////////////////////////////////////////////////////////////
/** Name:       Arreglo::setArreglo(int* newArreglo)*/
/** Purpose:    Setter de arreglo*/
/** Parameters:*/
/** - newArreglo*/
/** Return:     void*/
////////////////////////////////////////////////////////////////////////

void Arreglo::setArreglo(int* newArreglo)
{
	arreglo = newArreglo;
}

////////////////////////////////////////////////////////////////////////
/** Name:       Arreglo::encerar(int arreglo)*/
/** Purpose:    Llenar con 0 cad aposicion del arreglo*/
/** Parameters:*/
/** - arreglo*/
/** Return:     void*/
////////////////////////////////////////////////////////////////////////

void Arreglo::encerar()
{
	for (int i = 0; i < longitud; i++)
	{
		*(arreglo + i) = 0;
	}
	
}

////////////////////////////////////////////////////////////////////////
/** Name:       Arreglo::ingresar(int arreglo)*/
/** Purpose:    Aumentar la longitud cada que ingresa un valor y guardar*/ 
/**             ese valor en la posicion correspondiente*/
/** Parameters:*/
/** - arreglo*/
/** Return:     void*/
////////////////////////////////////////////////////////////////////////

void Arreglo::ingresar(int valor)
{
	longitud++;
	arreglo = (int*)realloc(arreglo, longitud * sizeof(int));
	*(arreglo + (longitud-1)) = valor;
}

////////////////////////////////////////////////////////////////////////
/** Name:       Arreglo::imprimir(int arreglo)*/
/** Purpose:    Funcion para imprimir*/
/** Parameters:*/
/** - arreglo*/
/** Return:     void*/
////////////////////////////////////////////////////////////////////////

void Arreglo::imprimir()
{
	for (int i = 0; i < longitud; i++)
	{
		cout << *(arreglo + i) << " ";
	}
	cout << endl;
}


////////////////////////////////////////////////////////////////////////
/** Name:       Arreglo::getLongitud()*/
/** Purpose:    Getter de longitud*/
/** Return:     int*/
////////////////////////////////////////////////////////////////////////

int Arreglo::getLongitud(void)
{
	return longitud;
}

////////////////////////////////////////////////////////////////////////
/** Name:       Arreglo::setLongitud(int newLongitud)*/
/** Purpose:   Setter de longitud*/
/** Parameters:*/
/** - newLongitud*/
/** Return:     void*/
////////////////////////////////////////////////////////////////////////

void Arreglo::setLongitud(int newLongitud)
{
	longitud = newLongitud;
}

////////////////////////////////////////////////////////////////////////
/** Name:       Arreglo::Arreglo()*/
/** Purpose:    Constrcutor que inicializar longitud y arreglo con malloc.*/
/** Return:     */
////////////////////////////////////////////////////////////////////////

Arreglo::Arreglo()
{
	longitud = 0;
	arreglo = (int*) malloc(longitud * sizeof(int));
}

#endif
