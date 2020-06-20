/***********************************************************************
 * Module:  Cliente.h
 * Author:  Madely Betancourt, Kevin Caicedo
 * Modified: martes, junio 16, 2020 7:06:58 PM
 * Purpose: Declaration of the class Cliente
 ***********************************************************************/

#if !defined(__Banco_Cliente_h)
#define __Banco_Cliente_h

#include <string>
#include "Cuenta.h"
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

protected:
private:
    std::string nombre;
    std::string cedula;
    std::string email;
    std::string direccion;
    Cuenta *cuenta;
    string dato;
};

void Cliente :: pedirDatos(int num) {
    cout << "Ingrese el nombre del titular: " << endl;
    getline(cin,nombre);
    cout << "Ingrese la cedula del titular: " << endl;
    getline(cin, cedula);
    cout << "Ingrese el e-mail del titular: " << endl;
    getline(cin, email);
    cout << "Ingrese la direccion del titular: " << endl;
    getline(cin, direccion);

    cuenta = new Cuenta(num, cedula);
    hacerString();
    FileManager fileM ("cliente.txt");
    fileM.agregarLinea(dato);
}

void Cliente::hacerString() {
    dato = nombre + "," + cedula + "," + email + "," + direccion;
}
#endif