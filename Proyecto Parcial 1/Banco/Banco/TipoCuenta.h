/***********************************************************************
 * Module:  TipoCuenta.h
 * Author: Madely Betancourt, Kevin Caicedo
 * Modified: martes, junio 16, 2020 7:27:33 PM
 * Purpose: Declaration of the class TipoCuenta
 ***********************************************************************/



#if !defined(__Banco_TipoCuenta_h)
#define __Banco_TipoCuenta_h
#include "Cuenta.h"
#include <string>

using namespace std;

//class Cuenta;

class TipoCuenta
{
public:
    string getNombre(void);
    void setNombre(string newNombre);
    TipoCuenta(int num);
    TipoCuenta();
    int getId(void);
    void setId(int newId);
    //Cuenta* cuenta;

protected:

private:
    string nombre;
    int id;
};

inline TipoCuenta::TipoCuenta() {
    TipoCuenta::nombre = "";
    TipoCuenta::id = 0;
}

inline TipoCuenta::TipoCuenta(int num) {
    if (num == 1) {
        TipoCuenta::nombre = "Ahorros";
        TipoCuenta::id = 1;
    }
    else {
        TipoCuenta::nombre = "Credito";
        TipoCuenta::id = 2;
    }
}

#endif
