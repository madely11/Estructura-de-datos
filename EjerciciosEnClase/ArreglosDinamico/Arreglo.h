#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <ctype.h>
//#define E 5
//typedef int entero;
using namespace std;
class Arreglo {
	public:
int *v;

public:
Arreglo();
void encerar();
void ingresar();
void proceso();
void impresion();
};

Arreglo::Arreglo (){
	v=(int*)malloc(4*sizeof(int));
}

//desarrollo de la funsión encerar
void Arreglo::ingresar(){
	//cout << "Hola" << endl;
	for(int i=0;i<10;i++){
		cout<<"Valor "<<i+1<<endl;
		//scanf("%d",*(&v)+i);
		cin>>*(v+i);
	}
}
void Arreglo::encerar(){
	for(int i=0;i<10;*(v+i)=0,i++);
}

void Arreglo::proceso(){
	for(int i=0;i<10;i++){
  		*v=((*(*(&v)))*2);
  		impresion();
  		*(v++);
		//v[i]=v[i]*E;
	}
}

void Arreglo::impresion(){
	for(int i=0;i<10;i++){
		printf("%d, ",(*(&(*v))));
		*(v++);
	}
	cout<< endl;
	//cout<<v[i]<<", ";
}	

