#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#define longitud 10
#define longitud2 15
using namespace std;

template<typename T,typename T2> class Ordenamiento;
template<typename T, typename T2> ostream& operator<< (ostream& salida, Ordenamiento<T,T2>& z);
template<class T,class T2>
class Ordenamiento
{
public:
	void ordenarNum(int i, int j, T* aux, T2** arreglo);
	void ordenar(int i, int j, T* aux, T2** arreglo);



};

template<typename T, typename T2>
void Ordenamiento<T,T2>::ordenarNum(int i, int j, T* aux, T2** arreglo) {
	if (i < longitud) {
		/* indice j es para explorar la sublista a[i-1]..a[0] buscando la posicion correcta del elemento destino */
		j = i;
		aux = *(arreglo + i);
		// se localiza el punto de inserción explorando hacia abajo
		while (j > 0 && atoll(aux) < atoll(*(arreglo + (j - 1))))
		{
			// desplazar elementos hacia arriba para hacer espacio
			*(arreglo + j) = *(arreglo + (j - 1));
			j--;
		}
		*(arreglo + j) = aux;
		i++;
		ordenarNum(i, j, aux, arreglo);
	}
}

//ordena string de palabras
template<typename T, typename T2>
void  Ordenamiento<T, T2>::ordenar(int i, int j, T* aux, T2** arreglo) {
	if (i < longitud) {
		/* indice j es para explorar la sublista a[i-1]..a[0] buscando la posicion correcta del elemento destino */
		j = i;
		aux = *(arreglo + i);
		// se localiza el punto de inserción explorando hacia abajo
		while (j > 0 && strcmp(aux, *(arreglo + (j - 1))) < 0)
		{
			// desplazar elementos hacia arriba para hacer espacio
			*(arreglo + j) = *(arreglo + (j - 1));
			j--;
		}
		*(arreglo + j) = aux;
		i++;
		ordenar(i, j, aux, arreglo);
	}
}
