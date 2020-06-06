/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* LIBRERIA DE FUNCIONES PARA CALCULAR SENO, COSENO Y TANGENTE     *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 01/06/20									  *
* FECHA DE MODIFICACIÓN: 03/06/20								  *
******************************************************************/


#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include <iostream>
#define PI 3.14159265
using namespace std;
class Funciones {
public:
	float convierte(float);
	float miSeno(float);
	float miCoseno(float);
	int factorial(int);
	float potencia(float, int);

};
float Funciones::potencia(float num_base, int exp) {
	if (exp < 0) {
		exp *= -1;
		return 1 / (num_base * potencia(num_base, exp - 1));
	}

	if (exp == 0) {
		return 1;
	}
	else {
		return num_base * potencia(num_base, exp - 1);
	}
}

int Funciones::factorial(int num) {
	if (num == 0)
		return 1;
	else
		return num * factorial(num - 1);
}

float Funciones::convierte(float angulo) {
	float conversion;
	if (angulo == 360)
		return 0;
	else 
		conversion = angulo * (float)PI / 180;
	return conversion;
}

float Funciones::miSeno(float angulo) {
	int gradPol = 7;
	float seno = 0;
	float num = 0;
	float den = 0;
	int signo = 0;
	angulo = convierte(angulo);

	for (int i = 0; i < gradPol; i++) {
		//signo = potencia(-1, i);
		num = (float)potencia(angulo, 2 * i + 1); //numerador de la serie de Taylor
		den = (float)factorial(2 * i + 1);//denominador de la serie de Taylor
		if (i % 2 == 0)
			seno += (num / den);
		else
			seno -= (num / den);
		//cout << seno << endl;
	}
	return seno;
}

float Funciones::miCoseno(float angulo) {
	int gradPol = 7;
	float coseno = 0;
	float num = 0;
	float den = 0;
	//int signo = 0;
	angulo = convierte(angulo);

	for (int i = 0; i <= gradPol-1; i++) {
		//signo =(double) potencia(-1, i);
		num = (float)potencia(angulo, 2 * i); //numerador de la serie de Taylor
		den = (float)factorial(2 * i);//denominador de la serie de Taylor
		if (i % 2 == 0)
			coseno += (num / den);
		else
			coseno -= (num / den);
		//cout << coseno << endl;
	}
	return coseno;
}