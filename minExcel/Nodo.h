#ifndef NODO_H
#define NODO_H
#include <string>


using namespace std;
typedef string Str;

template <typename T>
class Nodo
{
    public:
        Nodo();
        virtual ~Nodo();
        virtual T eval()=0;
    protected:
    private:
        Str dato;
};



#endif // NODO_H
