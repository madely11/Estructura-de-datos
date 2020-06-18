/***********************************************************************
 * Module:  Cliente.h
 * Author:  Madely Betancourt, Kevin Caicedo
 * Modified: martes, junio 16, 2020 7:06:58 PM
 * Purpose: Declaration of the class Cliente
 ***********************************************************************/

#if !defined(__Banco_Cliente_h)
#define __Banco_Cliente_h

class Cuenta;

#include "Cuenta.h"

class Cliente
{
public:
    std::string getNombre();
    std::string getId(void);
    void setNombre(std::string nombre);
    void setId(std::string id);

    //Cuenta** cuenta;

protected:
private:
    std::string nombre;
    std::string cedula;
    std::string email;
    std::string direccion;
    //Cuenta cuenta;
};

#endif