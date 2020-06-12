/*#include <iostream>

using namespace std;

class Pareja {
public:
	int a, b;
public:
	Pareja operator+ (const Pareja& a, const Pareja& b);
	Pareja () : a(0), b(0){
	}

	Pareja(const int a, const int b);

	Pareja(const Pareja&);
};

Pareja::Pareja(const int a, const int b) {
	this->a = a;
	this->b = b;
}

Pareja::Pareja(const Pareja& p)
{
	*this = p;
}

Pareja& operator+ (const Pareja &A, const Pareja &B) {
	Pareja C;
	C.a = A.a + B.a;
	C.b = A.b + A.b;
}*/

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
using namespace std;
class Pareja {

public:
    int a, b;

public:
    // constructor base
    Pareja() : a(0), b(0) {}

    // constructor parametrizado
    Pareja(const int a, const int b) {
        this->a = a;
        this->b = b;
    }

    // constructor de copia
    Pareja(const Pareja&);

    // operadores miembros
    Pareja& operator + (const Pareja& p);
    Pareja& operator - (const Pareja& p);
    Pareja& operator * (const Pareja& p);
    Pareja& operator / (const Pareja& p);
    Pareja& operator = (const Pareja& p);
    Pareja& operator ++();
    bool    operator ==(const Pareja& p) const;
    bool operator > (const Pareja& p) const ;
    bool operator < (const Pareja& p)const;
    bool operator % (const Pareja& p)const;
    bool operator !=  (const Pareja& p)const;
    bool operator >=  (const Pareja& p)const; 
    bool operator <=  (const Pareja& p)const;
    Pareja& operator --();
    Pareja& operator %=(const Pareja& p);
    // operadores no miembros
    friend ostream& operator << (ostream& o, const Pareja& p);
    friend istream& operator >> (istream& o, const Pareja& p);
};

// implementacion de los operadores para la clase Pareja
//....................................
Pareja::Pareja(const Pareja& p)
{
    *this = p;
}
//....................................
Pareja& Pareja::operator + (const Pareja& p)
{
    this->a += p.a;
    this->b += p.b;
    return *this;
}
//....................................
Pareja& Pareja::operator - (const Pareja& p)
{
    this->a -= p.a;
    this->b -= p.b;
    return *this;
}
//....................................
Pareja& Pareja::operator * (const Pareja& p)
{
    this->a *= p.a;
    this->b *= p.b;
    return *this;
}
//....................................
Pareja& Pareja::operator / (const Pareja& p)
{
    if (p.a != 0) this->a /= p.a;
    if (p.b != 0) this->b /= p.b;
    return *this;
}
//....................................
Pareja& Pareja::operator = (const Pareja& p)
{
    if (this != &p) { //Comprueba que no se esté intentanod igualar un objeto a sí mismo
        if (p.a != 0) this->a = p.a;
        if (p.b != 0) this->b = p.b;
    }
    return *this;
}

//....................................
Pareja& Pareja::operator ++ ()
{
    this->a++;
    this->b++;
    return *this;
}

//....................................
bool Pareja::operator == (const Pareja& p) const
{
    return this->a == p.a && this->b == p.b;
}
// sobrecarga de operados mayor que
bool Pareja::operator > (const Pareja& p) const {    // sobrecarga operador >
    return this->a > p.a && this->b > p.b;
}
// sobrecarga de operados menor que
bool Pareja::operator < (const Pareja& p) const {
    return this->a<p.a&& this->b>p.b;
}

// sobrecarga de operados menor que
bool Pareja::operator % (const Pareja& p) const {
    if (((this->a % p.a) == 0) && ((this->b % p.b) == 0))
        return 1;
    else
        return 0;
}
// sobrecarga del operador diferente de
bool Pareja::operator!=(const Pareja& p) const
{
    return this->a != p.a && this->b != p.b;
}
//Sobrecarga del operador mayor o igual que
bool Pareja::operator>=(const Pareja& p) const
{
    return this->a >= p.a && this->b >=p.b;
}
//Sobrecarga del operador menor o igual que
bool Pareja::operator<=(const Pareja& p) const
{
    return this->a <= p.a && this->b <= p.b;
}

Pareja& Pareja::operator -- ()
{
    this->a--;
    this->b--;
    return *this;
}
//Sobrecarga del operador %=
Pareja& Pareja::operator%=(const Pareja& p)
{
    this->a %=p.a;
    this->b %= p.b;
    return *this;
}

// implemetaci¢n de operadores no miembros
ostream& operator << (ostream& o, const Pareja& p)
{
    o << "(" << p.a << ", " << p.b << ")";
    return o;
}

istream& operator >> (istream& i, Pareja& p)
{
    cout << "Introducir valores para ( a, b) :";
    i >> p.a >> p.b;
    i.ignore();
    return i;
}
int main(int argc, char** argv) {
    Pareja A(150, 75);
    Pareja B(100, 15);
    Pareja C;
    cout << "A = " << A << "\n";
    cout << "B = " << B << "\n";
    cout << "........................." << endl;
    C = C + A;
    C = C + B;
    cout << "Suma C = " << C << endl;
    cout << "........................." << endl;
    C = A ;
    C = C - B;
    //cout << "A = " << A << "\n";
    cout << "Resta C = " << C << endl;
    cout << "........................." << endl;
    C = A;
    C = C * B;
    //cout << "A = " << A << "\n";
    cout << "Multiplicacion C = " << C << endl;
    cout << "........................." << endl;
    C = A;
    C = C / B;
    //cout << "A = " << A << "\n";
    cout << "Division C = " << C << endl;
    cout << "........................." << endl;
    /*C = A / B;
    //cout << "A = " << A << "\n";
    cout << "C = " << C << endl;
    cout << "........................." << endl;*/
    ++C;
    cout << "Mas Mas C = " << C << endl;
    cout << "........................." << endl;
    --C;
    cout << "Menos Menos C = " << C << endl;
    cout << "........................." << endl;
    cout << "A == B " << ((A == B) ? "  True \n" : "  False  \n");
    cout << "........................." << endl;
    C = A;
    cout << "A > B " << ((A > B) ? "  True \n" : "  False  \n");
    cout << "........................." << endl;
    cout << "A < B " << ((A < B) ? "  True \n" : "  False  \n");
    cout << "........................." << endl;
    cout << "A es divisible para B -->" << ((A % B) ? "  True \n" : "  False  \n");
    cout << "........................." << endl;
    cout << "A != B " << ((A != B) ? "  True \n" : "  False  \n");
    cout << "........................." << endl;
    cout << "A >= B " << ((A >= B) ? "  True \n" : "  False  \n");
    cout << "........................." << endl;
    cout << "........................." << endl;
    cout << "A <= B " << ((A <= B) ? "  True \n" : "  False  \n");
    cout << "........................." << endl;
    A %= B;
    cout << "A %=B:" << A << endl;
    cout << "........................." << endl;
    C = A = B = ++C;
    cout << "A = " << A << "\n";
    cout << "B = " << B << "\n";
    cout << "C = " << C << endl;
    cout << "........................." << endl;
    return 0;
}




/*int main() {
	Pareja* A = new Pareja(100, 100);
	Pareja* B = new Pareja(50, 50);
	Pareja* C;
	C = A + B;
}*/