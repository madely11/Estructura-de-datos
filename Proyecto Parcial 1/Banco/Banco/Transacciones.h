/***********************************************************************
 * Module:  Transacciones.h
 * Author:  Madely Betancourt, Kevin Caicedo
 * Modified: martes, junio 16, 2020 7:17:41 PM
 * Purpose: Declaration of the class Transacciones
 ***********************************************************************/

#if !defined(__Banco_Transacciones_h)
#define __Banco_Transacciones_h

class Cuenta;

#include "Fecha.h"
#include "Cuenta.h"

class Transacciones
{
public:
    void deposito(Cuenta cuenta, long monto);
    bool verificarSaldo(void);

    Cuenta** cuenta;

protected:
private:
    Fecha fecha;


};

#endif