#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <ctype.h>
#define E 5
typedef int entero;
using namespace std;
class Arreglo{
	public: 
	int v[10];
	public:
	void encerar();
	void ingresar();
	void procesar();
	void imprimir();
};

//desarrollo de la funsión encerar
void Arreglo :: ingresar(){
	entero val;
	for(entero i=0;i<10;i++){
		cout<<"Valor "<<i+1<<endl;
		cin>>v[i];
	}
}
void Arreglo :: encerar(){
	for(entero i=0;i<10;v[i]=0,i++);
}
void Arreglo :: procesar(){
	for(entero i=0;i<10;i++){
  		v[i]*=E;
		//v[i]=v[i]*E;
	}
}
void Arreglo :: imprimir(){
	for(entero i=0;i<10;i++)
	cout<<v[i]<<", ";
}
