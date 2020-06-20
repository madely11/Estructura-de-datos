/***********************************************************************
 * Module:  Cuenta.h
 * Author:  Madely Betancourt, Kevin Caicedo
 * Modified: martes, junio 16, 2020 7:27:33 PM
 * Purpose: Declaration of the class Cuenta
 ***********************************************************************/

#if !defined(__Banco_Cuenta_h)
#define __Banco_Cuenta_h

#include "TipoCuenta.h"
#include "FileManager.h"

class Cuenta
{
public:
    int getNumc(void);
    double getMonto(void);
    void setNumc(int numC);
    double setMonto(double monto);
    void crearCuenta(void);
    void cerrarCuenta(void);
    void depositar(void);
    void transferir(int numCuenta, double monto);
    void hacerString();
    Cuenta(int, string);

protected:
private:
    double monto;
    int numeroCuenta;
    string idCliente;
    string dato;
    //Transacciones transaccion;
    TipoCuenta* tipo;
};


Cuenta::Cuenta(int num, string id) {
    tipo = new TipoCuenta(num);
    this->idCliente = id;
    this->numeroCuenta = 1;
    this->monto = 5;
    hacerString();
    FileManager fileM("cuenta.txt");
    fileM.agregarLinea(dato);

}

void Cuenta::hacerString() {
    dato =idCliente + "," + to_string(numeroCuenta) + "," + to_string(monto) + "," + to_string(tipo->getId());
}

#endif
