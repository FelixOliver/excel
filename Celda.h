#ifndef CELDA_H
#define CELDA_H
#include <string>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "Nodo.h"
using namespace std;
class Celda : public Nodo
{
    public:
        Celda(string);
        void set_contenido(string);
        int get_fila();
        int get_columna();
        string contenido();
    private:
        int fila;
        int columna;
        string *pCadena;
};

#endif // CELDA_H
