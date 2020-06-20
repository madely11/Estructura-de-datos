/***********************************************************************
 * Module:  TipoCuenta.h
 * Author: Madely Betancourt, Kevin Caicedo
 * Modified: martes, junio 16, 2020 7:27:33 PM
 * Purpose: Declaration of the class TipoCuenta
 ***********************************************************************/



#if !defined(__Banco_TipoCuenta_h)
#define __Banco_TipoCuenta_h


using namespace std;

//class Cuenta;

class TipoCuenta
{
public:
    string getNombre(void);
    void setNombre(string newNombre);
    TipoCuenta(int num);
    int getId(void);
    void setId(int newId);

protected:

private:
    string nombre;
    int id;
};


inline string TipoCuenta::getNombre(void)
{
    return nombre;
}

inline void TipoCuenta::setNombre(string newNombre)
{
    this->nombre = newNombre;
}

TipoCuenta::TipoCuenta(int num) {
    if (num == 1) {
        this -> nombre = "Ahorros";
        this -> id = 1;
    }
    else {
        this ->nombre = "Credito";
        this -> id = 2;
    }
}

inline int TipoCuenta::getId(void)
{
    return id;
}

inline void TipoCuenta::setId(int newId)
{
    this->id = newId;
}

#endif
