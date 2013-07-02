#ifndef NOPER_H
#define NOPER_H
#include "Nodo.h"
#include <string>
using namespace std;
//class Noper{};

template <typename T>

class Noper : public Nodo<T>
{
    public:
        Noper();
        virtual ~Noper();
        virtual T eval(Nodo &A,Nodo &B);

    protected:

    private:

};



#endif // NOPER_H
