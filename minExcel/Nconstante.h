#ifndef NCONSTANTE_H
#define NCONSTANTE_H
#include "Nodo.h"
#include <string.h>

template <typename T>
class Nconstante:public Nodo
{
    public:
        Nconstante();
        virtual ~Nconstante();
        virtual T eval();
    protected:
    private:
};

#endif // NCONSTANTE_H
