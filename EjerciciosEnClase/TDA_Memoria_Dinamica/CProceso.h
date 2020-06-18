#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;

class CProceso{
private:
	int num,den;

public:
	void _setnum(int);	
	void _setden(int);
	int _getnum();
	int _getden();
	CProceso(int nume, int deno);
	~CProceso();
	CProceso racional(CProceso obj1, CProceso obj2);
	void imprimeObj(CProceso Obj);
	
};
