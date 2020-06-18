#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define TAM 10
using namespace std;
class Elemento{
	public:
	int A[TAM];
	int i;
	public:
	void leer();
	float buscarElemento(int);
};

void Elemento::leer(){
	for(i=0;i< TAM;i++){
		std::cout<<"Ingrese el valor "<<i+1<<std::endl;
		std::cin>>A[i];
	}
}

float Elemento ::buscarElemento(int x){
	int i, p=0,sw=0;
	float n;
	n=(float)TAM;
	for(i=0;i< TAM;i++){
		if(A[i]==x){
			p=i;
			sw=1;
			break;
		}
	}
	if(sw==0){
		cout<<"dato no encontrado"<<endl;
		p=TAM;
	}
	n=(float)p*(p+1)/(2*p);
	return n;
}

