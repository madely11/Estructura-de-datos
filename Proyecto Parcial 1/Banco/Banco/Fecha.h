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
    Fecha();

private:
    string hora;
    string fecha;
};

Fecha::Fecha() {
    struct tm pt1;
    __time64_t tSac = time(NULL);
    errno_t err;
    _time64(&tSac);
    err = _localtime64_s(&pt1, &tSac);
    hora = to_string(pt1.tm_hour) + ":" + to_string(pt1.tm_min) + ":" + to_string(pt1.tm_sec);
    fecha = to_string(pt1.tm_mday) + "/" + to_string(pt1.tm_mon + 1) + "/" + to_string(pt1.tm_year + 1900);
}



#endif
