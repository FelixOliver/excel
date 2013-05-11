#ifndef NVARIABLE_H
#define NVARIABLE_H
#include "Nodo.h"
#include <string.h>

using namespace std;

template <typename T>

class Nvariable:public Nodo<T>
{
    public:
        Nvariable();
        virtual ~Nvariable();
        virtual T eval();
    protected:
    private:
};

#endif // NVARIABLE_H
