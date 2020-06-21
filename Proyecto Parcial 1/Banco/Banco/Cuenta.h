/***********************************************************************
 * Module:  Cuenta.h
 * Author:  Madely Betancourt, Kevin Caicedo
 * Modified: martes, junio 16, 2020 7:27:33 PM
 * Purpose: Declaration of the class Cuenta
 ***********************************************************************/

#if !defined(__Banco_Cuenta_h)
#define __Banco_Cuenta_h

#include <string>
#include "TipoCuenta.h"
#include "FileManager.h"
#include "Transacciones.h"

class Cuenta
{
public:
    int getNumc(void);
    double getMonto(void);
    void setNumc(int numC);
    double setMonto(double monto);
    bool verificarCuenta(int);
    void retirar(string);
    //void cerrarCuenta(void);
    void depositar(string);
    void hacerString();
    void guardarDatos(string);
    Cuenta();
    Cuenta(int, string);
    TipoCuenta* tipo;
    Transacciones t;
protected:
private:
    float monto;
    int numeroCuenta;
    string idCliente;
    string dato;   
};


Cuenta::Cuenta(int num, string id) {
    tipo = new TipoCuenta(num);
    this->idCliente = id;
    FileManager fileM("cuenta.txt");
    this->numeroCuenta = fileM.contarLineas("cuenta.txt");
    this->monto = 5;
    hacerString();
   fileM.agregarLinea(dato);
}


Cuenta::Cuenta(){

}



bool Cuenta :: verificarCuenta(int num) {
    int id;
    string mensaje;
    cout << "Ingrese el numero de cuenta: " << endl;
    cin >> id;
    FileManager fileM("cuenta.txt");
    mensaje = fileM.buscarCuenta(id);
    if (mensaje._Equal("salir")) {
        cout << "Cuenta no existente" << endl;
        Sleep(1000);
        return false;
    }
    guardarDatos(mensaje);
        if(num == 1)
            monto = t.depositar(mensaje, monto);
        if (num == 2)
            monto = t.retirar(mensaje, monto);
}

void Cuenta :: guardarDatos(string mensaje) { 
        int i = 0;
        string aux_string;
        idCliente = "";
        while (mensaje.at(i) != ',' && i < mensaje.length()) {
            idCliente += mensaje.at(i);
            i++;
        }
        i++;
        while (mensaje.at(i) != ',' && i < mensaje.length()) {
            aux_string += mensaje.at(i);
            i++;
        }
        numeroCuenta = atoi(aux_string.c_str());
        i++;
        aux_string = "";
        while (mensaje.at(i) != ',' && i < mensaje.length()) {
            aux_string += mensaje.at(i);
            i++;
        }
        monto = atof(aux_string.c_str());
        i++;
        aux_string = "";
        while (i < mensaje.length() && mensaje.at(i) != ',') {
            aux_string += mensaje.at(i);
            i++;
        }
        i = atoi(aux_string.c_str());
        //tipo->setId(i);
    }


 



void Cuenta::hacerString() {
    dato =idCliente + "," + to_string(numeroCuenta)+ "," + to_string(monto) + "," + to_string(tipo->getId());
}
int Cuenta::getNumc(void)
{
    return numeroCuenta;
}
inline double Cuenta::getMonto(void)
{
    return monto;
}
inline void Cuenta::setNumc(int numC)
{
    this->numeroCuenta = numC;
        
}
inline double Cuenta::setMonto(double monto)
{
    this->monto = monto;
}

#endif
