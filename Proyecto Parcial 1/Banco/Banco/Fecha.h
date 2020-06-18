/***********************************************************************
 * Module:  Fecha.h
 * Author: Madely Betancourt, Kevin Caicedo
 * Modified: martes, junio 16, 2020 7:16:22 PM
 * Purpose: Declaration of the class Fecha
 ***********************************************************************/

#if !defined(__Banco_Fecha_h)
#define __Banco_Fecha_h

class Transacciones;

class Fecha
{
public:
    int getDia(void);
    void setDia(int newDia);
    int getMes(void);
    void setMes(int newMes);
    int getAnio(void);
    void setAnio(int newAnio);

    Transacciones** transacciones;

protected:
private:
    int dia;
    int mes;
    int anio;


};

#endif
