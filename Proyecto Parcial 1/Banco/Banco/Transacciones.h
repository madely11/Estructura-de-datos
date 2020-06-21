/***********************************************************************
 * Module:  Transacciones.h
 * Author:  Madely Betancourt, Kevin Caicedo
 * Modified: martes, junio 16, 2020 7:17:41 PM
 * Purpose: Declaration of the class Transacciones
 ***********************************************************************/

#if !defined(__Banco_Transacciones_h)
#define __Banco_Transacciones_h

#include "Fecha.h"

class Transacciones
{
public:
    void datosTransaccion();
    int depositar(int);
    int retirar(int);
    bool verificarSaldo(void);

protected:
private:
    Fecha fecha;
};

void Transacciones :: datosTransaccion()
{
    
}

int Transacciones::depositar(int monto) {
    int deposito;
    cout << "Ingrese la cantidad de dinero a depositar: " << endl;
    cin >> deposito;
    monto += deposito;
    return monto;
}

int Transacciones::retirar(int monto) {
    int retiro;
    cout << "Ingrese la cantidad de dinero a retirar: " << endl;
    cin >> retiro;
    if (monto > retiro)
        monto -= retiro;
    else {
        cout << "Saldo insuficiente" << endl;
        Sleep(1000);
    }
    return monto;
}
#endif