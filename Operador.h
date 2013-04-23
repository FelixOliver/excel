#ifndef OPERADOR_H
#define OPERADOR_H
#include "Nodo.h"
class Operador : public Nodo
{
    public:
        Operador(char);
        int orden_operacion();
        float resultado(int,int,int);
    private:
        char simbolo;
};

#endif // OPERADOR_H
