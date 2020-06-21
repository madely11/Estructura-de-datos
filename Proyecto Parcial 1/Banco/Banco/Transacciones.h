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
    float depositar(string, float);
    float retirar(string, float);
    bool verificarSaldo(void);

protected:
private:
    Fecha fecha;
};

void Transacciones :: datosTransaccion()
{
    
}

float Transacciones::depositar(string mensaje, float monto) {
    float deposito;
    cout << "Ingrese la cantidad de dinero a depositar: " << endl;
    cin >> deposito;
    monto += deposito;
    return monto;
    //hacer que monto se guarde en archivo
}

float Transacciones::retirar(string mensaje, float monto) {
    float retiro;
    cout << "Ingrese la cantidad de dinero a retirar: " << endl;
    cin >> retiro;
    if (monto > retiro)
        monto -= retiro;
    else {
        cout << "Saldo insuficiente" << endl;
        Sleep(1000);
    }
}
#endif