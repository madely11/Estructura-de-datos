#include "CProceso.h"
CProceso::CProceso(int nume,int deno)
{
	this->num=nume;
	this->den=deno;
}
void CProceso::_setnum(int nume)
{
	num=nume;
}
int CProceso::_getnum()
{
	return num;
}
void CProceso::_setden(int deno)
{
	den=deno;
}
int CProceso::_getden()
{
	return den;
}
CProceso CProceso::racional(CProceso obj1, CProceso obj2)
{
	int a,b,c,d;
	a=obj1._getnum();
	b=obj1._getden();
	c=obj2._getnum();
	d=obj2._getden();
	this->_setnum((a*d)+(b*c));
	this->_setden(b*d);
	return *this;
}
void CProceso::imprimeObj(CProceso Obj)
{
	cout<<Obj._getnum()<<"/"<<Obj._getden()<<endl;
}
int main(void)
{
	int a=18,b=3;
	CProceso *obj1 = new CProceso(a,b);
	CProceso *obj2 = new CProceso(15,5);
	CProceso *obj3 = new CProceso(0,0);
	obj3->racional(*obj1,*obj2);
	obj1->imprimeObj(*obj1);
	obj2->imprimeObj(*obj2);
	obj3->imprimeObj(*obj3);
	system("pause");
	return 0;
}
