/***********************************************************************
 * Module:  Fecha.h
 * Author: Madely Betancourt, Kevin Caicedo
 * Modified: martes, junio 16, 2020 7:16:22 PM
 * Purpose: Declaration of the class Fecha
 ***********************************************************************/

#if !defined(__Banco_Fecha_h)
#define __Banco_Fecha_h

#include <iostream>
#include <string.h>
using namespace std;
#include <ctime>

class Fecha
{
public:
    int getHora(void);
    void setHora(int newHora);
    int getFecha(void);
    void setFecha(int newFecha);
    Fecha();

protected:
private:
    string hora;
    string fecha;
};

Fecha::Fecha() {
    time_t tSac = time(NULL);  // instante actual
    struct tm* pt1 = localtime(&tSac);
    hora = to_string(pt1->tm_hour) + ":" + to_string(pt1->tm_min) + ":" + to_string(pt1->tm_sec);
    fecha = to_string(pt1->tm_mday) + "/" + to_string(pt1->tm_mon) + ":" + to_string(pt1->tm_year + 1900);
}


#endif
