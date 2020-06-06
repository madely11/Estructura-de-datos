/***********************************************************************
 *	UNIVERSIDA DE LAS FUERZAS ARMADAS ESPE
 *	Module:  Funciones Trigonometricas
 *  Author:  Kevin Caicedo, Madely Betancourt
 *	Modified: sabado, junio 06, 2020
 ***********************************************************************/




#include <iostream>
#include "Funciones.h"
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

int main()
{
	float temporal=0;
	Funciones funcion;
	printf("Ingrese un angulo en grados: \n");
	scanf_s("%f", &temporal);
	printf("\nEl seno es: %d", funcion.miSeno(temporal));
	
	system("pause");
	return 0;
}

