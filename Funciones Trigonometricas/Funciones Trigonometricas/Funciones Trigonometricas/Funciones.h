/***********************************************************************
 * Module:  Funciones.h
 * Author:  Kevin Caicedo, Madely Betancourt
 * Modified: sabado, junio 06, 2020  AM
 * Purpose: Funciones Trigonometricas
 ***********************************************************************/


#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include <iostream>
#define PI 3.14159265
using namespace std;
class Funciones {
public:
	float convierte(float);
	double miSeno(float);
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
	conversion = (PI * angulo) / 180;
	return conversion;
}

double Funciones::miSeno(float angulo) {
	int gradPol = 20;
	double seno = 0;
	float num = 0;
	float den = 0;
	int signo = 0;

	for (int i = 0; i < gradPol; i++) {
		signo = potencia(-1, i);
		num = potencia(convierte(angulo), 2 * i + 1); //numerador de la serie de Taylor
		den = factorial(2 * i + 1);//denominador de la serie de Taylor
		seno += (num * signo) / den;
	}
	return seno;
}
