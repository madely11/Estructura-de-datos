/***********************************************************************
 * Module:  Cliente.h
 * Author:  Madely Betancourt, Kevin Caicedo
 * Modified: martes, junio 16, 2020 7:06:58 PM
 * Purpose: Declaration of the class Cliente
 ***********************************************************************/

#if !defined(__Banco_Cliente_h)
#define __Banco_Cliente_h

#include <string.h>
#include "Cuenta.h"
#include "Validacion.h"
//#include "FileManager.h"
#include <iostream>

using namespace std;

class Cliente
{
public:
    string getNombre();
    string getId(void);
    void setNombre(std::string nombre);
    void setId(std::string id);
    void pedirDatos(int);
    void hacerString();
    string stringConsola();

protected:
private:
    std::string nombre;
    std::string cedula;
    std::string email;
    std::string direccion;
    Validacion validar;
    Cuenta *cuenta=NULL;
    string dato;
};

void Cliente :: pedirDatos(int num) {
    cout << "Ingrese el nombre del titular: " << endl;
    getline(cin,nombre);
    cout << "Ingrese la cedula del titular: " << endl;
    getline(cin, cedula);
    while (!validar.cedula(cedula)) {
        cout << "Ingrese la cedula del titular: " << endl;
        getline(cin, cedula);
    }
    cout << "Ingrese el e-mail del titular: " << endl;
    getline(cin, email);
    cout << "Ingrese la direccion del titular: " << endl;
    getline(cin, direccion);
    cuenta = new Cuenta(num, cedula);
    hacerString();
    FileManager fileM ("cliente.txt");
    fileM.agregarLinea(dato);
}

string Cliente::stringConsola() {
    string salida;
    salida = "Nombre: " + nombre +
        "\nCedula: " + cedula +
        "\nEmail: " + email +
        "\nDireccion: " + direccion +
        "\nNumero de cuenta: " + to_string(cuenta->getNumc())+
        "\nMonto: "+ to_string(cuenta->getMonto())+
        "\nTipo de cuenta: "+ cuenta->tipo->getNombre();
    return salida;
}


void Cliente::hacerString() {
    dato = nombre + "," + cedula + "," + email + "," + direccion;
}
#endif