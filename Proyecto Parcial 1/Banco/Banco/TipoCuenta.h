/***********************************************************************
 * Module:  TipoCuenta.h
 * Author: Madely Betancourt, Kevin Caicedo
 * Modified: martes, junio 16, 2020 7:27:33 PM
 * Purpose: Declaration of the class TipoCuenta
 ***********************************************************************/

#if !defined(__Banco_TipoCuenta_h)
#define __Banco_TipoCuenta_h
#include "Cuenta.h"

class Cuenta;

class TipoCuenta
{
public:
    string getNombre(void);
    void setNombre(string newNombre);
    TipoCuenta();
    int getId(void);
    void setId(int newId);
    Cuenta* cuenta;
protected:
private:
    std :: string nombre;
    int id;


};

#endif
