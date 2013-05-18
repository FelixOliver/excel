#ifndef NODE_H
#define NODE_H
#include "Operations.h"


class Node
{
    public:
        Node();
        Node(expr _contenido):contenido(_contenido){}
        virtual ~Node();
        //virtual value eval(value a,value b)=0;
        virtual value get_value()=0;
    protected:
        expr contenido;

};

#endif // NODE_H
