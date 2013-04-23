#ifndef CONSTANTE_H
#define CONSTANTE_H
#include <cstdlib>
#include <iostream>
#include <sstream>
#include "Nodo.h"
using namespace std;
typedef int tipoNum;

class Constante : public Nodo
{
    public:
        Constante();
        void set_numero(tipoNum);
        tipoNum get_numero();
        void set_cadena(string);
        string get_cadena();
    private:
        tipoNum numero;
};

#endif // CONSTANTE_H
