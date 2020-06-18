#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
class Vector
{

	private:
	int *vector;
	public:
		int* getVector();
		Vector();
		void ingresarV(int *, int);
		void imprimirV( int  *, int );
		void procesar(Vector , int);
		Vector(int *ptr);
};

int* Vector::getVector(){
	return vector;
}

void Vector::procesar(Vector vec, int dim){
	for(int i=0; i<dim; i++)
	{
		*(vector+i)= *(vec.vector+i) *5;
	}
}
void Vector::ingresarV(int *vector, int dim)
{
	for(int i=0; i<dim; i++)
	{
		printf("\nINGRESE UN DATO:\t");
		scanf("%d",(vector+i));
		//cin>>*(vector+i);
	}
	this->vector=vector;
}
void Vector::imprimirV(  int *vector, int dim)
{
	printf("\nDATOS GUARDADOS:\n");
	for(int i=0; i<dim; i++)
	{
	
		printf("%d,",*(vector+i));
	}
}
Vector::Vector(){

	
}


