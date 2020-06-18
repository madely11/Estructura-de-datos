/***********************************************************************
 * Module:  Cuenta.h
 * Author:  Madely Betancourt, Kevin Caicedo
 * Modified: martes, junio 16, 2020 7:27:33 PM
 * Purpose: Declaration of the class Cuenta
 ***********************************************************************/

#if !defined(__Banco_Cuenta_h)
#define __Banco_Cuenta_h

#include "Transacciones.h"
#include "TipoCuenta.h"
#include "Cliente.h"

class Cuenta
{
public:
    int getNumc(void);
    Cliente getPersona(void);
    double getMonto(void);
    void setNumc(int numC);
    void setPersona(Cliente persona);
    double setMonto(double monto);
    void crearCuenta(void);
    void cerrarCuenta(void);
    void depositar(void);
    void transferir(int numCuenta, double monto);

protected:
private:
    double monto;
    long int numeroCuenta;
    Transacciones transaccion;
    //TipoCuenta t();


};

#endif
